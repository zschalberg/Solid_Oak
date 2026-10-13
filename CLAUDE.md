# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**Solid-Oak** is a Pokemon FireRed ROM hack built on the `pokefirered-expansion` framework. The setting is early Kanto before Red/Blue — the player is young Professor Oak studying Pokemon migration. The ROM is compiled to `pokefirered.gba`.

## Build

**Always build via WSL (Ubuntu/Debian)**. The project builds 2x faster than msys2 and 5–6x faster than Cygwin. After making changes, verify the build succeeds before declaring work done. From a Windows shell: `wsl -e bash -lc 'make firered -j$(nproc)'`.

Never commit unless explicitly told to. Follow `pret/pokefirered` formatting conventions and keep existing comments. When a request is ambiguous, ask rather than guess (from `.agents/AGENTS.md`).

### Dialogue & AI Decisions (Placeholders)
- **AI-generated dialogue is strictly placeholder**: Whenever Claude/AI writes, drafts, or makes decisions on dialogue, NPC speech, quest text, flavor text, or storyline elements, treat it purely as a temporary placeholder. Final creative decisions are left to the human developer.
- **Consistent Tagging Pattern**: Flag every AI-authored or AI-decided dialogue line or text block with the exact tag `[AI-DIALOG]`:
  - In Poryscript (`.pory`) and C (`.c`): `// TODO: [AI-DIALOG] <optional context/note>`
  - In ASM (`.inc`, `.s`): `@ TODO: [AI-DIALOG] <optional context/note>`
- **Filterable / Searchable**: Always use the exact tag `[AI-DIALOG]` so placeholders can be reliably filtered across the codebase (e.g. `git grep "\[AI-DIALOG\]"`).
- **Other AI Decisions**: For any other non-dialogue design decisions made by the AI that require human review, flag them with `// TODO: [AI-DECISION] <context>`.

```bash
# Standard build (primary target)
make firered

# Other targets
make leafgreen
make debug       # -g symbols, -Og
make release     # LTO enabled
make check       # headless test suite (mgba-rom-test, tests in test/)
make check TESTS="Spikes"   # run only tests whose name starts with the filter
make clean       # remove build artifacts
make syms        # generate symbol map
```

Output ROM: `pokefirered.gba`  
Build artifacts: `build/firered/`

Supports parallel builds: `make -j$(nproc)`

Required WSL packages: `build-essential binutils-arm-none-eabi libpng-dev python3 python3-pil`

## Architecture

### Build Pipeline
`.c` / `.pory` / `.png` / JSON → preprocessed → compiled (`$GCCARM15` toolchain if set, otherwise the system `arm-none-eabi-gcc`) → linked → `pokefirered.gba`. Separate `.mk` files handle graphics (`graphics_file_rules.mk`), audio (`audio_rules.mk`), trainers, maps, JSON data, and tilesets.

### Script System
Most map scripts are **Poryscript**: every `data/**/*.pory` (mainly `data/maps/<Map>/scripts.pory`) is compiled to a sibling `.inc` by `tools/poryscript/poryscript` with `tools/poryscript/command_config.json`. Both files are tracked: when a `.pory` exists, edit it, never the generated `.inc`. Maps without a `.pory` (e.g. `PalletTown_PlayersHouse_2F`) use hand-written `.inc` assembly. Script macros are defined in `asm/macros/event.inc`. Any `include/constants/*.h` used in scripts must be `#include`d in `data/event_scripts.s`.

### Mugshots (NPC Portraits)
64×64 speaker portraits above dialogue (`src/mugshot.c`). PNG files go in `graphics/mugshots/` and are auto-converted by `scratch/convert_mugshot.py` (requires Pillow) during build. To add one: PNG + `INCBIN` + `sMugshots[]` entry in `src/mugshot.c`, plus a `MUGSHOT_*` constant in `include/constants/mugshots.h`. Script commands: `showmugshot` / `clearmugshot`. Supports simultaneous double-portraits (left @X=36, right @X=204). Portraits use OAM priority 1, which draws them behind BG0, and their bottom edge sits on the dialogue box's top outline. Portraits are cleared when the message box closes.

### Speaker Name Plate
A name plate on the top-left edge of the dialogue box (`src/field_message_box.c`, BG0 window at tile row 13, baseBlock `0x2C0`. BG0 tiles must stay below `0x300`, because BG2's tilemap starts at `0xE000`). Each `sMugshots[]` entry has an `SP_NAME_*` speaker, so `showmugshot` names the speaker automatically (left portrait wins; right portrait only if it's alone). `setspeaker(SP_NAME_*)` or `setspeaker("Text")` overrides that and names NPCs who have no portrait. `SP_NAME_NONE` hides the plate. The name is cleared on `closemessage`/`release`. Presets live in `include/constants/speaker_names.h` and `sSpeakerNamesTable`. `SP_NAME_PLAYER` uses the player's chosen name (the `MUGSHOT_PROF_OAK` portrait is the player).

### Data-Driven Systems
Many systems are defined in JSON under `src/data/pokemon/` (species info, learnsets, egg moves, special movesets) and compiled via `json_data_rules.mk`. The `tools/learnset_helpers/` Python scripts generate teachable learnsets and TM data from JSON — don't edit those C structs directly.

## Custom Game Systems

### Pokemon Size
Per-Pokemon height/weight derived from personality value + size table. Affects battle speed (lighter = faster, min 0.2×) and physical damage (heavier = stronger). Exceptional sizes show color-highlighted catch messages and are tracked in a Pokedex Size Records page.

### Research & Catch System
- **Protoballs**: Level-capped catch balls (Red≤10, Blu≤20, Grn≤30, Blk≤40) crafted at a Workbench (Apricorn + Conversion Kit)
- **Research Balls**: 1.5× catch rate; caught Pokemon can't battle (treated as eggs)
- **Berry throwing in battle**: R-button quick-throws Razz Berry (catch boost) or Nanab Berry (calm)
- **Research Points**: Turn in Research Balls at Oak's Lab for points redeemable for rewards (Exp. Share, Porygon, etc.). Points scale by rarity, IVs, size records, and shininess

### Pokemon Storage (Mr. Fuji's Sanctuary)
Replaces the PC. "Rooms" system (8 Rooms × 6 Pokemon default, upgrades to 10). **Pidgeot Courier**: key item whistle summons Pidgeot outdoors for deposit/withdraw via a staged multi-select interface.

### Level & Boss Scaling
- `FLAG_SCALE_BOSS_BATTLE`: scales trainer battles to player's max party level + `VAR_SCALE_LEVEL_OFFSET` (default +5, supports negative for Easy Mode)
- `FLAG_SCALE_WILD_POKEMON`: wilds scale to player team level ±10
- Anti-trivialization: levels never scale below baseline

### Quest Log
Accessible from the Start Menu under "POKéDEX → Journal". Three tabs (MAIN STORY / SIDE QUESTS / RESEARCH) navigated with D-pad. Quest colors: green = complete, dark gray = active, red = locked. Pressing A on a quest shows its location on the Town Map.

### TM / HM Restrictions
TMs cannot be used directly from the bag — moves must be learned from Dojo Move Tutors. HM field usage requires only the HM item in bag (no badge check). Fly opens the overworld Fly Map directly from the TM Case.

### IV Scanner
Key item that unlocks an IV/EV viewer tab in the Summary Screen. L-button in wild battles scans the opponent's IVs. Outstanding Pokemon (≥151 total IV) trigger shiny sparkles; perfect IVs trigger `MUS_LEVEL_UP` fanfare.

### Variable Team Preview & 3v3 Battles
Pre-battle team preview with sprite sheets. `gSpecialVar_0x8008` controls selection limit (default 3). Party reordering is allowed during select and restored after battle.

### Expanded Seen/Caught Tracking
Binary seen/caught flags upgraded to 8-bit counters (max 255) for the first 400 species. Player's own Pokemon don't increment Seen count. Exposed via `GetSpeciesSeenCount` / `GetSpeciesCaughtCount` script specials.

### Quest-Gated Evolutions
Gengar and Slowpoke evolutions are blocked until corresponding quest flags are set. See `include/config/species_enabled.h` and relevant quest flag constants.

## Key File Locations

| System | Location |
|--------|----------|
| Battle mechanics | `src/battle*.c`, `include/battle*.h`, `data/battle_scripts_*.s` |
| Catch / ball logic | `src/ball_economy.c`, `src/battle_controller_player.c`, `src/battle_script_commands.c` |
| Level scaling | `src/battle_main.c` (trainers), `src/wild_encounter.c` (wilds) |
| Mugshots / name plate | `src/mugshot.c`, `src/field_message_box.c`, `graphics/mugshots/` |
| Map scripts | `data/maps/<Map>/scripts.pory` (or `.inc`), shared scripts in `data/scripts/` |
| Crafting (Workbench) | `data/scripts/workbench.inc` |
| Size system | `src/pokemon_size_record.c`, `src/battle_util.c`, `src/pokedex_plus_hgss.c` (records) |
| Research turn-in | `src/research_turnin.c`, `data/scripts/research_ball_return.inc` |
| Learnset generation | `tools/learnset_helpers/`, `src/data/pokemon/` |
| Constants & flags | `constants/`, `include/constants/` |
| Feature documentation | `docs/features.md` |
