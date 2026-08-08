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
    "General": {1, 8, 9, 16, 17},
    "General_Summer": {1, 8, 9, 16, 17},
    "General_Autumn": {1, 8, 9, 16, 17},
    "General_Winter": {1, 8, 9, 16, 17},
}


def find_layout(layouts_json, layout_name):
    blockdata_filepath = f"data/layouts/{layout_name}/map.bin"
    for layout in layouts_json["layouts"]:
        if layout["blockdata_filepath"] == blockdata_filepath:
            return layout
    sys.exit(f"randomize_grass_tiles.py: no layout found for '{layout_name}'")


def load_layout(layout_name, layouts_json_path="data/layouts/layouts.json"):
    layouts_json = json.loads(Path(layouts_json_path).read_text())
    return find_layout(layouts_json, layout_name)


def mowed_grass_ids_for_layout(layout):
    primary_symbol = layout["primary_tileset"].removeprefix("gTileset_")
    secondary_symbol = layout["secondary_tileset"].removeprefix("gTileset_")

    ids = set(MOWED_GRASS_METATILE_IDS.get(primary_symbol, ()))
    ids |= {
        i + NUM_METATILES_IN_PRIMARY
        for i in MOWED_GRASS_METATILE_IDS.get(secondary_symbol, ())
    }
    return ids


def randomize(data, mowed_grass_ids):
    """Returns (new_data, num_mowed_grass_cells, num_changed_cells)."""
    data = bytearray(data)
    total = 0
    changed = 0

    # Only worth rerolling if this map's tileset pair has more than one
    # mowed-grass metatile graphic to choose between.
    if len(mowed_grass_ids) > 1:
        choices = sorted(mowed_grass_ids)
        for i in range(0, len(data), 2):
            cell = data[i] | (data[i + 1] << 8)
            metatile_id = cell & MAPGRID_METATILE_ID_MASK
            if metatile_id in mowed_grass_ids:
                total += 1
                new_id = random.choice(choices)
                if new_id != metatile_id:
                    changed += 1
                cell = (cell & ~MAPGRID_METATILE_ID_MASK) | new_id
                data[i] = cell & 0xFF
                data[i + 1] = (cell >> 8) & 0xFF

    return bytes(data), total, changed


def main():
    layout_name, map_bin_in, map_bin_out = sys.argv[1:4]

    layout = load_layout(layout_name)
    mowed_grass_ids = mowed_grass_ids_for_layout(layout)

    data = Path(map_bin_in).read_bytes()
    new_data, _, _ = randomize(data, mowed_grass_ids)

    Path(map_bin_out).parent.mkdir(parents=True, exist_ok=True)
    Path(map_bin_out).write_bytes(new_data)


if __name__ == "__main__":
    main()
