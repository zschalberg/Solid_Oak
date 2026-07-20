#!/usr/bin/env python3
"""
One-time migration for enabling OW_TRIPLE_LAYER_METATILES (include/config/overworld.h).

Expands every data/tilesets/*/*/metatiles.bin from 8 tiles/metatile (2 layers) to
12 tiles/metatile (3 layers), inserting the correct blank tile block in whichever layer
slot the metatile's current METATILE_LAYER_TYPE didn't use, so existing maps
render identically before you start repainting the new middle layer in Porymap.

In FRLG:
- METATILE_LAYER_TYPE_NORMAL (0): old = [middle, top].
  New = [bottom (4x 0x3014), middle, top]
- METATILE_LAYER_TYPE_COVERED (1): old = [bottom, middle].
  New = [bottom, middle, top (4x 0x0000)]
- METATILE_LAYER_TYPE_SPLIT (2): old = [bottom, top].
  New = [bottom, middle (4x 0x0000), top]

Also updates porymap.project.cfg to enable_triple_layer_metatiles=1.
"""
import argparse
import glob
import os
import struct
import sys

TILES_PER_LAYER = 4
OLD_TILES_PER_METATILE = 8
NEW_TILES_PER_METATILE = 12

# Matches METATILE_ATTRIBUTE_LAYER_TYPE bit field (include/fieldmap.c: 2 bits, mask 0x60000000)
LAYER_TYPE_MASK = 0x60000000
LAYER_TYPE_SHIFT = 29

METATILE_LAYER_TYPE_NORMAL = 0   # used middle + top
METATILE_LAYER_TYPE_COVERED = 1  # used bottom + middle
METATILE_LAYER_TYPE_SPLIT = 2    # used bottom + top

BLANK_TRANSPARENT_LAYER = (0,) * TILES_PER_LAYER
BLANK_BACKDROP_LAYER = (0x3014,) * TILES_PER_LAYER


def expand_metatile(old_tiles, layer_type):
    layer0 = tuple(old_tiles[0:4])
    layer1 = tuple(old_tiles[4:8])

    if layer_type == METATILE_LAYER_TYPE_NORMAL:
        # old: [middle][top] -> new: [bottom(0x3014)][middle][top]
        return BLANK_BACKDROP_LAYER + layer0 + layer1
    elif layer_type == METATILE_LAYER_TYPE_COVERED:
        # old: [bottom][middle] -> new: [bottom][middle][top(transparent)]
        return layer0 + layer1 + BLANK_TRANSPARENT_LAYER
    elif layer_type == METATILE_LAYER_TYPE_SPLIT:
        # old: [bottom][top] -> new: [bottom][middle(transparent)][top]
        return layer0 + BLANK_TRANSPARENT_LAYER + layer1
    else:
        return layer0 + layer1 + BLANK_TRANSPARENT_LAYER


def migrate_pair(metatiles_path, attributes_path, dry_run):
    with open(metatiles_path, "rb") as f:
        raw_tiles = f.read()
    with open(attributes_path, "rb") as f:
        raw_attrs = f.read()

    num_attrs = len(raw_attrs) // 4
    expected_8 = num_attrs * OLD_TILES_PER_METATILE * 2
    expected_12 = num_attrs * NEW_TILES_PER_METATILE * 2

    if len(raw_tiles) == expected_12:
        return 0
    elif len(raw_tiles) != expected_8:
        print(f"  SKIP (unexpected file size {len(raw_tiles)}, expected {expected_8}): {metatiles_path}")
        return 0

    num_metatiles = num_attrs
    tiles = struct.unpack(f"<{num_metatiles * OLD_TILES_PER_METATILE}H", raw_tiles)

    out_tiles = []
    for metatile_id in range(num_metatiles):
        old_start = metatile_id * OLD_TILES_PER_METATILE
        old_tiles = tiles[old_start:old_start + OLD_TILES_PER_METATILE]

        attr = struct.unpack_from("<I", raw_attrs, metatile_id * 4)[0]
        layer_type = (attr & LAYER_TYPE_MASK) >> LAYER_TYPE_SHIFT

        out_tiles.extend(expand_metatile(old_tiles, layer_type))

    if not dry_run:
        with open(metatiles_path, "wb") as f:
            f.write(struct.pack(f"<{len(out_tiles)}H", *out_tiles))

    return num_metatiles


def update_porymap_cfg(cfg_path, dry_run):
    if not os.path.isfile(cfg_path):
        return
    with open(cfg_path, "r") as f:
        content = f.read()
    if "enable_triple_layer_metatiles=1" in content:
        return
    lines = content.splitlines()
    new_lines = []
    updated = False
    for line in lines:
        if line.startswith("enable_triple_layer_metatiles="):
            new_lines.append("enable_triple_layer_metatiles=1")
            updated = True
        else:
            new_lines.append(line)
    if not updated:
        new_lines.append("enable_triple_layer_metatiles=1")
    if not dry_run:
        with open(cfg_path, "w") as f:
            f.write("\n".join(new_lines) + "\n")
    print(f"  {'[dry-run] ' if dry_run else ''}Updated {cfg_path} enable_triple_layer_metatiles=1")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--dry-run", action="store_true", help="Report what would change without writing files")
    parser.add_argument("--tilesets-dir", default="data/tilesets", help="Root directory containing primary/ and secondary/ tilesets")
    args = parser.parse_args()

    pairs = []
    for metatiles_path in sorted(glob.glob(os.path.join(args.tilesets_dir, "*", "*", "metatiles.bin"))):
        tileset_dir = os.path.dirname(metatiles_path)
        attributes_path = os.path.join(tileset_dir, "metatile_attributes.bin")
        if not os.path.isfile(attributes_path):
            print(f"WARNING: no metatile_attributes.bin next to {metatiles_path}, skipping")
            continue
        pairs.append((metatiles_path, attributes_path))

    if not pairs:
        print(f"No tilesets found under {args.tilesets_dir}")
        return 1

    total = 0
    migrated_count = 0
    for metatiles_path, attributes_path in pairs:
        count = migrate_pair(metatiles_path, attributes_path, args.dry_run)
        if count:
            print(f"  {'[dry-run] ' if args.dry_run else ''}{metatiles_path}: {count} metatiles -> {NEW_TILES_PER_METATILE} tiles each")
            total += count
            migrated_count += 1

    update_porymap_cfg("porymap.project.cfg", args.dry_run)

    print(f"\n{'Would migrate' if args.dry_run else 'Migrated'} {total} metatiles across {migrated_count} tilesets.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
