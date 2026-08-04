import struct
from pathlib import Path

from PIL import Image

# Mirrors NUM_TILES_IN_PRIMARY / NUM_METATILES_IN_PRIMARY in include/fieldmap.h
# (both happen to be 640 in this project).
NUM_TILES_IN_PRIMARY = 640
NUM_METATILES_IN_PRIMARY = 640

MAPGRID_METATILE_ID_MASK = 0x03FF


def load_pal(path):
    lines = Path(path).read_text().splitlines()
    n = int(lines[1])
    colors = []
    for line in lines[3 : 3 + n]:
        r, g, b = map(int, line.split())
        colors.append((r, g, b))
    return colors


class Tileset:
    def __init__(self, tileset_dir, tile_id_offset):
        self.tiles_png = Image.open(f"{tileset_dir}/tiles.png").convert("P")
        self.tile_cols = self.tiles_png.width // 8
        self.tile_id_offset = tile_id_offset
        self.metatiles = Path(f"{tileset_dir}/metatiles.bin").read_bytes()
        self.palettes = [
            load_pal(p) for p in sorted(Path(f"{tileset_dir}/palettes").glob("*.pal"))
        ]

    def get_raw_tile(self, local_tile_id):
        tx = local_tile_id % self.tile_cols
        ty = local_tile_id // self.tile_cols
        return self.tiles_png.crop((tx * 8, ty * 8, tx * 8 + 8, ty * 8 + 8))

    def render_metatile(self, metatile_id):
        off = metatile_id * 16
        refs = struct.unpack("<8H", self.metatiles[off : off + 16])
        img = Image.new("RGBA", (16, 16), (0, 0, 0, 0))
        for layer, layer_refs in enumerate([refs[0:4], refs[4:8]]):
            for i, ref in enumerate(layer_refs):
                global_tile_id = ref & 0x3FF
                local_tile_id = global_tile_id - self.tile_id_offset
                if local_tile_id < 0 or local_tile_id >= self.tile_cols * (
                    self.tiles_png.height // 8
                ):
                    continue
                xflip = (ref >> 10) & 1
                yflip = (ref >> 11) & 1
                pal_num = (ref >> 12) & 0xF
                tile = self.get_raw_tile(local_tile_id)
                if xflip:
                    tile = tile.transpose(Image.FLIP_LEFT_RIGHT)
                if yflip:
                    tile = tile.transpose(Image.FLIP_TOP_BOTTOM)
                pal = self.palettes[pal_num] if pal_num < len(self.palettes) else self.palettes[0]
                rgba = Image.new("RGBA", (8, 8))
                px = tile.load()
                rpx = rgba.load()
                for yy in range(8):
                    for xx in range(8):
                        ci = px[xx, yy]
                        if layer == 1 and ci == 0:
                            rpx[xx, yy] = (0, 0, 0, 0)
                        else:
                            r, g, b = pal[ci] if ci < len(pal) else (255, 0, 255)
                            rpx[xx, yy] = (r, g, b, 255)
                dx = (i % 2) * 8
                dy = (i // 2) * 8
                img.alpha_composite(rgba, (dx, dy))
        return img


def render_map(map_bin_bytes, width, height, primary_tileset_dir, secondary_tileset_dir, zoom=2):
    primary = Tileset(primary_tileset_dir, 0)
    secondary = Tileset(secondary_tileset_dir, NUM_TILES_IN_PRIMARY)

    canvas = Image.new("RGB", (width * 16 * zoom, height * 16 * zoom))
    metatile_cache = {}

    def get_metatile_img(metatile_id):
        if metatile_id not in metatile_cache:
            if metatile_id < NUM_METATILES_IN_PRIMARY:
                img = primary.render_metatile(metatile_id)
            else:
                img = secondary.render_metatile(metatile_id - NUM_METATILES_IN_PRIMARY)
            metatile_cache[metatile_id] = img.resize((16 * zoom, 16 * zoom), Image.NEAREST).convert("RGB")
        return metatile_cache[metatile_id]

    for y in range(height):
        for x in range(width):
            i = (y * width + x) * 2
            cell = map_bin_bytes[i] | (map_bin_bytes[i + 1] << 8)
            metatile_id = cell & MAPGRID_METATILE_ID_MASK
            canvas.paste(get_metatile_img(metatile_id), (x * 16 * zoom, y * 16 * zoom))

    return canvas
