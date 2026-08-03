import json
import random
import re
import struct
import sys
from pathlib import Path

# Mirrors include/constants/metatile_behaviors.h
MB_TALL_GRASS = 2

# Mirrors the METATILE_ATTRIBUTE_BEHAVIOR mask in src/fieldmap.c
METATILE_ATTR_BEHAVIOR_MASK = 0x000001FF

# Mirrors MAPGRID_METATILE_ID_MASK in include/global.fieldmap.h
MAPGRID_METATILE_ID_MASK = 0x03FF

# Mirrors NUM_METATILES_IN_PRIMARY in include/fieldmap.h
NUM_METATILES_IN_PRIMARY = 640

TILESET_INCBIN_PAT = re.compile(
    r'gMetatileAttributes_(\w+)\[\]\s*=\s*INCBIN_U32\("([^"]+)"\)'
)

# "Mowed grass" (plain walkable grass texture variants) has no metatile
# behavior of its own -- it's tagged MB_NORMAL same as pavement, floors,
# etc. -- so unlike tall grass it can't be auto-detected and has to be
# identified by eye per tileset. Found by rendering each tileset's
# metatiles: these are the flat/speckled grass tiles used to break up
# uniform grass fields (as opposed to the tall-grass encounter tiles).
MOWED_GRASS_METATILE_IDS = {
    "General": {1, 8, 9, 16, 17, 19},
    "General_Summer": {1, 8, 9, 16, 17, 19},
    "General_Autumn": {1, 8, 9, 16, 17, 19},
    "General_Winter": {1, 8, 9, 16, 17, 19},
}


def load_tileset_attr_paths(metatiles_header):
    paths = {}
    for line in Path(metatiles_header).read_text().splitlines():
        match = TILESET_INCBIN_PAT.search(line)
        if match:
            paths[match.group(1)] = match.group(2)
    return paths


def load_tall_grass_metatile_ids(attr_path, id_offset):
    data = Path(attr_path).read_bytes()
    values = struct.unpack(f"<{len(data) // 4}I", data)
    return {
        i + id_offset
        for i, value in enumerate(values)
        if (value & METATILE_ATTR_BEHAVIOR_MASK) == MB_TALL_GRASS
    }


def find_layout(layouts_json, layout_name):
    blockdata_filepath = f"data/layouts/{layout_name}/map.bin"
    for layout in layouts_json["layouts"]:
        if layout["blockdata_filepath"] == blockdata_filepath:
            return layout
    sys.exit(f"randomize_grass_tiles.py: no layout found for '{layout_name}'")


def variant_pool(primary_symbol, secondary_symbol, primary_ids, secondary_ids):
    pool = set(primary_ids.get(primary_symbol, ()))
    pool |= {i + NUM_METATILES_IN_PRIMARY for i in secondary_ids.get(secondary_symbol, ())}
    return pool


def main():
    layout_name, map_bin_in, map_bin_out = sys.argv[1:4]

    layouts_json = json.loads(Path("data/layouts/layouts.json").read_text())
    layout = find_layout(layouts_json, layout_name)

    tileset_attr_paths = load_tileset_attr_paths("src/data/tilesets/metatiles.h")
    primary_symbol = layout["primary_tileset"].removeprefix("gTileset_")
    secondary_symbol = layout["secondary_tileset"].removeprefix("gTileset_")

    tall_grass_ids = load_tall_grass_metatile_ids(tileset_attr_paths[primary_symbol], 0)
    tall_grass_ids |= load_tall_grass_metatile_ids(
        tileset_attr_paths[secondary_symbol], NUM_METATILES_IN_PRIMARY
    )

    mowed_grass_ids = variant_pool(
        primary_symbol, secondary_symbol, MOWED_GRASS_METATILE_IDS, MOWED_GRASS_METATILE_IDS
    )

    # Only worth rerolling a group if this map's tileset pair actually has
    # more than one metatile graphic in it to choose between.
    variant_groups = [
        ids for ids in (tall_grass_ids, mowed_grass_ids) if len(ids) > 1
    ]

    data = bytearray(Path(map_bin_in).read_bytes())

    if variant_groups:
        variant_choices = [sorted(ids) for ids in variant_groups]
        for i in range(0, len(data), 2):
            cell = data[i] | (data[i + 1] << 8)
            metatile_id = cell & MAPGRID_METATILE_ID_MASK
            for ids, choices in zip(variant_groups, variant_choices):
                if metatile_id in ids:
                    new_id = random.choice(choices)
                    cell = (cell & ~MAPGRID_METATILE_ID_MASK) | new_id
                    data[i] = cell & 0xFF
                    data[i + 1] = (cell >> 8) & 0xFF
                    break

    Path(map_bin_out).parent.mkdir(parents=True, exist_ok=True)
    Path(map_bin_out).write_bytes(data)


if __name__ == "__main__":
    main()
