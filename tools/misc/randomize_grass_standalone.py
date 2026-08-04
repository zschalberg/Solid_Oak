"""
Manually reroll the mowed-grass tile variants for a single map and see a
before/after render, without going through the Makefile build.

Run from the repo root:

    python3 tools/misc/randomize_grass_standalone.py Route1

This overwrites data/layouts/<Map>/map.bin in place (it's git-tracked, so
`git diff`/`git checkout -- data/layouts/<Map>/map.bin` undoes it), and
writes before/after PNG renders next to it for a visual comparison.

Requires Pillow (`pip install pillow`), which the Makefile-driven build
does not otherwise need.
"""

import argparse
import json
import sys
from pathlib import Path

from map_render import render_map
from randomize_grass_tiles import mowed_grass_ids_for_layout, randomize


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("layout_name", help="e.g. Route1, PalletTown")
    parser.add_argument(
        "--out-dir",
        default="build/grass_preview",
        help="Where to write before/after PNGs (default: build/grass_preview, which is gitignored)",
    )
    parser.add_argument(
        "--no-write",
        action="store_true",
        help="Only render before/after images, don't overwrite map.bin",
    )
    args = parser.parse_args()

    layouts_json = json.loads(Path("data/layouts/layouts.json").read_text())
    layout = next(
        (
            l
            for l in layouts_json["layouts"]
            if l["blockdata_filepath"] == f"data/layouts/{args.layout_name}/map.bin"
        ),
        None,
    )
    if layout is None:
        sys.exit(f"No layout named '{args.layout_name}' found in data/layouts/layouts.json")

    map_bin_path = Path(layout["blockdata_filepath"])
    width, height = layout["width"], layout["height"]
    primary_dir = f"data/tilesets/primary/{_tileset_dir_name(layout['primary_tileset'])}"
    secondary_dir = f"data/tilesets/secondary/{_tileset_dir_name(layout['secondary_tileset'])}"

    mowed_grass_ids = mowed_grass_ids_for_layout(layout)
    if len(mowed_grass_ids) <= 1:
        print(
            f"'{args.layout_name}' uses {layout['primary_tileset']}/{layout['secondary_tileset']}, "
            "which has no known mowed-grass variant set (nothing to randomize)."
        )
        return

    before_bytes = map_bin_path.read_bytes()
    after_bytes, total, changed = randomize(before_bytes, mowed_grass_ids)

    print(f"{args.layout_name}: {total} mowed-grass tiles, {changed} rerolled to a different variant")

    out_dir = Path(args.out_dir)
    out_dir.mkdir(parents=True, exist_ok=True)
    before_png = out_dir / f"{args.layout_name}_before.png"
    after_png = out_dir / f"{args.layout_name}_after.png"

    render_map(before_bytes, width, height, primary_dir, secondary_dir).save(before_png)
    render_map(after_bytes, width, height, primary_dir, secondary_dir).save(after_png)
    print(f"wrote {before_png}")
    print(f"wrote {after_png}")

    if not args.no_write:
        map_bin_path.write_bytes(after_bytes)
        print(f"updated {map_bin_path} (git-tracked, `git checkout -- {map_bin_path}` reverts)")


def _tileset_dir_name(tileset_symbol):
    """Look up the on-disk tileset directory for a gTileset_X symbol by
    scanning src/data/tilesets/metatiles.h, the same way the file names
    are declared for the build."""
    import re

    pattern = re.compile(r'gMetatileAttributes_(\w+)\[\]\s*=\s*INCBIN_U32\("data/tilesets/(?:primary|secondary)/([^/]+)/')
    symbol = tileset_symbol.removeprefix("gTileset_")
    for line in Path("src/data/tilesets/metatiles.h").read_text().splitlines():
        match = pattern.search(line)
        if match and match.group(1) == symbol:
            return match.group(2)
    sys.exit(f"Couldn't find tileset directory for {tileset_symbol}")


if __name__ == "__main__":
    main()
