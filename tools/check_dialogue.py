#!/usr/bin/env python3
"""
Checks script text for problems in the field message box.

Every `.string` block in data/ is measured with the real glyph width table from
src/fonts.c (the FRLG message box is 208px wide and shows 2 lines), and
the following are reported:

  CUTOFF       line is wider than the box; the end of it gets clipped
  HIDDEN_LINE  a \\n while already on line 2 draws a 3rd line below the box
               (use \\l to scroll, or \\p for a new box)
  ARROW_CLIP   line before a \\p/\\l is so wide the continue arrow gets clipped
  SCROLL_LINE1 \\l used on line 1, so the first line scrolls away
  TRAILING     text ends in \\p, \\l or \\n (shows an empty box / stray break)

{PLAYER} is measured as the fixed player name read from src/main_menu.c
(the player can't rename). Lines containing {STR_VAR_x}/{RIVAL} use an estimated width and are
reported as warnings (prefixed with "?") since the real width depends on the
value.

.pory files are checked through their generated .inc, so run `make` (or
poryscript) first; a warning is printed when a .pory is newer than its .inc.

Usage:
  python3 tools/check_dialogue.py            # custom text only
  python3 tools/check_dialogue.py --all      # include vanilla/expansion text
  python3 tools/check_dialogue.py data/maps/VermilionCity
Exits with 1 if any non-warning issue was found.
"""
import argparse
import glob
import os
import re
import sys

BOX_WIDTH = 208
ARROW_ROOM = 200
BOX_LINES = 2

# The player can't rename, so {PLAYER} is always sDefaultPlayerName from
# src/main_menu.c and is measured exactly.
DEFAULT_PLAYER_NAME = 'Samuel'

# Estimated pixel widths for runtime placeholders.
PLACEHOLDER_WIDTHS = {
    'RIVAL': 49,    # 7 characters
    'STR_VAR_1': 63,
    'STR_VAR_2': 63,
    'STR_VAR_3': 63,
}
DEFAULT_PLACEHOLDER_WIDTH = 63

# Vanilla/expansion text that is either unused in this game, drawn in a
# different window, or relies on short placeholder values. Skipped unless
# --all is passed.
VANILLA_IGNORE = [
    'data/maps/BattleFrontier_',
    'data/maps/TrainerTower_',
    'data/maps/Route5_PokemonDayCare/',
    'data/maps/Route11_EastEntrance_2F/',
    'data/maps/Route12_FishingHouse/text.inc',
    'data/maps/Route15_WestEntrance_2F/',
    'data/maps/SixIsland_WaterPath_House1/text.inc',
    'data/maps/FuchsiaCity_SafariZone_Entrance/text.inc',
    'data/maps/SaffronCity_CopycatsHouse_2F/',
    'data/mystery_event_msg.s',
    'data/scripts/berry_tree.inc',
    'data/scripts/cable_club.inc',
    'data/scripts/debug.inc',
    'data/text/aide.inc',
    'data/text/apprentice.inc',
    'data/text/competitive_brothers.inc',
    'data/text/help_system.inc',
    'data/text/move_relearner.inc',
    'data/text/new_game_intro.inc',
    'data/text/safari_zone.inc',
    'data/text/seagallop.inc',
    'data/text/tv.inc',
    'data/text/white_out.inc',
]

CONTROL_PREFIXES = (0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE)


def load_glyph_widths(root):
    src = open(os.path.join(root, 'src/fonts.c'), encoding='utf-8').read()
    m = re.search(r'gFontNormalLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};', src, re.S)
    return [int(x) for x in re.findall(r'\d+', m.group(1))]


def load_fixed_placeholders(root):
    src = open(os.path.join(root, 'src/main_menu.c'), encoding='utf-8').read()
    m = re.search(r'sDefaultPlayerName\[\]\s*=\s*_\("((?:[^"\\]|\\.)*)"\)', src)
    return {'PLAYER': m.group(1) if m else DEFAULT_PLAYER_NAME}


def load_charmap(root):
    charmap = {}
    for line in open(os.path.join(root, 'charmap.txt'), encoding='utf-8'):
        line = line.split('@')[0].strip()
        m = re.match(r"^'(.+)'\s*=\s*([0-9A-Fa-f ]+)$", line)
        if not m:
            m = re.match(r'^([A-Z0-9_]+)\s*=\s*([0-9A-Fa-f ]+)$', line)
            if m:
                charmap.setdefault('{' + m.group(1) + '}', [int(b, 16) for b in m.group(2).split()])
            continue
        charmap.setdefault(m.group(1), [int(b, 16) for b in m.group(2).split()])
    return charmap


def tokenize(text):
    """Yields (kind, value) for each character, {brace} code and control."""
    i = 0
    while i < len(text):
        c = text[i]
        if c == '\\' and i + 1 < len(text):
            n = text[i + 1]
            yield ('ctl', n) if n in 'nlp' else ('ch', n)
            i += 2
        elif c == '{':
            j = text.index('}', i)
            yield ('brace', text[i + 1:j])
            i = j + 1
        elif c == '$':
            yield ('end', None)
            return
        else:
            yield ('ch', c)
            i += 1


class Measurer:
    def __init__(self, root):
        self.widths = load_glyph_widths(root)
        self.charmap = load_charmap(root)
        self.fixed = load_fixed_placeholders(root)

    def width(self, kind, value):
        """Returns (pixels, is_estimate)."""
        if kind == 'ch':
            codes = self.charmap.get(value)
            if codes is None:
                return 6, False
            return sum(self.widths[b] for b in codes), False
        # {BRACE} codes: text colors, pauses, fonts, etc. take no space
        if ' ' in value:
            return 0, False
        if value in self.fixed:
            return sum(self.width('ch', c)[0] for c in self.fixed[value]), False
        if value in PLACEHOLDER_WIDTHS:
            return PLACEHOLDER_WIDTHS[value], True
        codes = self.charmap.get('{' + value + '}')
        if not codes:
            return 0, False
        if codes[0] == 0xFD:
            return DEFAULT_PLACEHOLDER_WIDTH, True
        if codes[0] in CONTROL_PREFIXES:
            return 0, False
        return sum(self.widths[b] for b in codes), False

    def check(self, text):
        issues = []
        line_no, box_no = 1, 1
        width, shown, estimated = 0, '', False

        def finish_line(next_ctl):
            px = width
            if px > BOX_WIDTH:
                issues.append(('CUTOFF', estimated, box_no, line_no, px, shown))
            elif next_ctl in ('p', 'l') and px > ARROW_ROOM:
                issues.append(('ARROW_CLIP', estimated, box_no, line_no, px, shown))
            if line_no > BOX_LINES:
                issues.append(('HIDDEN_LINE', False, box_no, line_no, px, shown))

        for kind, value in tokenize(text):
            if kind == 'end':
                break
            if kind == 'ctl':
                finish_line(value)
                if value == 'n':
                    line_no += 1
                elif value == 'p':
                    line_no, box_no = 1, box_no + 1
                elif value == 'l' and line_no == 1:
                    issues.append(('SCROLL_LINE1', False, box_no, line_no, 0, shown))
                width, shown, estimated = 0, '', False
                continue
            px, est = self.width(kind, value)
            width += px
            estimated |= est
            shown += value if kind == 'ch' else '{' + value + '}'
        finish_line(None)

        if re.search(r'\\[pln]\$$', text):
            issues.append(('TRAILING', False, box_no, line_no, 0, text[-6:-1]))
        return issues


def parse_strings(path):
    """Yields (label, line number, text) for each `.string` block."""
    label, label_line, buf = None, 0, ''
    for n, line in enumerate(open(path, encoding='utf-8', errors='replace'), 1):
        m = re.match(r'^\s*([A-Za-z0-9_]+)::?\s*$', line)
        if m:
            label, label_line, buf = m.group(1), n, ''
            continue
        m = re.match(r'^\s*\.string\s+"((?:[^"\\]|\\.)*)"', line)
        if m and label:
            buf += m.group(1)
            if buf.endswith('$'):
                yield label, label_line, buf
                buf = ''


def collect_files(root, paths, include_all):
    files = []
    for p in paths:
        full = os.path.join(root, p)
        if os.path.isfile(full):
            files.append(p)
        else:
            files += [os.path.relpath(f, root) for f in glob.glob(os.path.join(full, '**/*.inc'), recursive=True)]
            files += [os.path.relpath(f, root) for f in glob.glob(os.path.join(full, '*.s'))]
    files = sorted(set(f.replace(os.sep, '/') for f in files))
    if not include_all:
        files = [f for f in files if not any(f.startswith(v) for v in VANILLA_IGNORE)]
    return files


def main():
    parser = argparse.ArgumentParser(description='Find dialogue that is cut off or hidden in the message box.')
    parser.add_argument('paths', nargs='*', default=['data'], help='files or directories to check (default: data)')
    parser.add_argument('--all', action='store_true', help='also check vanilla/expansion text')
    args = parser.parse_args()

    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    measurer = Measurer(root)
    errors = warnings = 0

    for path in collect_files(root, args.paths, args.all):
        pory = os.path.join(root, path[:-len('.inc')] + '.pory') if path.endswith('.inc') else None
        if pory and os.path.exists(pory) and os.path.getmtime(pory) > os.path.getmtime(os.path.join(root, path)):
            print(f'warning: {path} may be stale (its .pory is newer); run make first')
        for label, line, text in parse_strings(os.path.join(root, path)):
            for kind, estimated, box, box_line, px, shown in measurer.check(text):
                tag = '?' + kind if estimated else kind
                note = ' [edit the .pory]' if pory and os.path.exists(pory) else ''
                print(f'{path}:{line}: {tag:<13} {label} (box {box}, line {box_line}, {px}px): {shown}{note}')
                if estimated:
                    warnings += 1
                else:
                    errors += 1

    print(f'{errors} issue(s), {warnings} placeholder warning(s)')
    return 1 if errors else 0


if __name__ == '__main__':
    sys.exit(main())
