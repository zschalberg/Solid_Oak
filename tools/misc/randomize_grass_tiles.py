import json
import sys
import random
from pathlib import Path

# Mirrors MAPGRID_METATILE_ID_MASK in include/global.fieldmap.h
MAPGRID_METATILE_ID_MASK = 0x03FF

# Mirrors NUM_METATILES_IN_PRIMARY in include/fieldmap.h
NUM_METATILES_IN_PRIMARY = 640

# "Mowed grass" (plain walkable grass texture variants) has no metatile
# behavior of its own -- it's tagged MB_NORMAL same as pavement, floors,
# etc. -- so it can't be auto-detected and has to be identified by eye per
# tileset. Found by rendering each tileset's metatiles: these are the
# flat/speckled grass tiles used to break up uniform grass fields (as
# opposed to the tall/long grass encounter tiles, which are left alone).
MOWED_GRASS_METATILE_IDS = {
    "General": {1, 8, 9, 16, 17, 19},
    "General_Summer": {1, 8, 9, 16, 17, 19},
    "General_Autumn": {1, 8, 9, 16, 17, 19},
    "General_Winter": {1, 8, 9, 16, 17, 19},
}


def find_layout(layouts_json, layout_name):
    blockdata_filepath = f"data/layouts/{layout_name}/map.bin"
    for layout in layouts_json["layouts"]:
        if layout["blockdata_filepath"] == blockdata_filepath:
            return layout
    sys.exit(f"randomize_grass_tiles.py: no layout found for '{layout_name}'")


def main():
    layout_name, map_bin_in, map_bin_out = sys.argv[1:4]

    layouts_json = json.loads(Path("data/layouts/layouts.json").read_text())
    layout = find_layout(layouts_json, layout_name)

    primary_symbol = layout["primary_tileset"].removeprefix("gTileset_")
    secondary_symbol = layout["secondary_tileset"].removeprefix("gTileset_")

    mowed_grass_ids = set(MOWED_GRASS_METATILE_IDS.get(primary_symbol, ()))
    mowed_grass_ids |= {
        i + NUM_METATILES_IN_PRIMARY
        for i in MOWED_GRASS_METATILE_IDS.get(secondary_symbol, ())
    }

    data = bytearray(Path(map_bin_in).read_bytes())

    # Only worth rerolling if this map's tileset pair has more than one
    # mowed-grass metatile graphic to choose between.
    if len(mowed_grass_ids) > 1:
        mowed_grass_choices = sorted(mowed_grass_ids)
        for i in range(0, len(data), 2):
            cell = data[i] | (data[i + 1] << 8)
            metatile_id = cell & MAPGRID_METATILE_ID_MASK
            if metatile_id in mowed_grass_ids:
                new_id = random.choice(mowed_grass_choices)
                cell = (cell & ~MAPGRID_METATILE_ID_MASK) | new_id
                data[i] = cell & 0xFF
                data[i + 1] = (cell >> 8) & 0xFF

    Path(map_bin_out).parent.mkdir(parents=True, exist_ok=True)
    Path(map_bin_out).write_bytes(data)


if __name__ == "__main__":
    main()
