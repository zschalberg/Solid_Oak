#!/usr/bin/env python3
import os
import sys
from PIL import Image

def get_tileset_dimensions(img):
    width, height = img.size
    if width % 8 != 0 or height % 8 != 0:
        print(f"Warning: Tileset dimensions ({width}x{height}) are not multiples of 8.", file=sys.stderr)
    return width // 8, height // 8

def validate_tileset(img_path):
    if not os.path.exists(img_path):
        print(f"Error: Image {img_path} does not exist", file=sys.stderr)
        sys.exit(1)
        
    img = Image.open(img_path)
    if img.mode != "P":
        print(f"Error: {img_path} is not in indexed color mode ('P'). Mode is {img.mode}", file=sys.stderr)
        sys.exit(1)
        
    cols, rows = get_tileset_dimensions(img)
    pixels = img.load()
    
    errors = 0
    for r in range(rows):
        for c in range(cols):
            tile_indices = set()
            for y in range(r * 8, r * 8 + 8):
                for x in range(c * 8, c * 8 + 8):
                    tile_indices.add(pixels[x, y])
            
            # Check if all indices fall in a single 16-color block [16*k, 16*k + 15]
            blocks = {idx // 16 for idx in tile_indices}
            if len(blocks) > 1:
                tile_idx = r * cols + c
                print(f"Validation Error: Tile {tile_idx} at grid (col={c}, row={r}) uses multiple palette blocks: "
                      f"{sorted(list(tile_indices))} (spans blocks {sorted(list(blocks))})", file=sys.stderr)
                errors += 1
                
    if errors > 0:
        print(f"Validation failed with {errors} errors.", file=sys.stderr)
        sys.exit(1)
    else:
        print("Validation successful! All tiles respect the 16-color block boundary constraint.")

def extract_tile(img_path, tile_index, out_path):
    if not os.path.exists(img_path):
        print(f"Error: Image {img_path} does not exist", file=sys.stderr)
        sys.exit(1)
        
    img = Image.open(img_path)
    cols, rows = get_tileset_dimensions(img)
    
    if tile_index < 0 or tile_index >= cols * rows:
        print(f"Error: Tile index {tile_index} out of range (0 to {cols * rows - 1})", file=sys.stderr)
        sys.exit(1)
        
    c = tile_index % cols
    r = tile_index // cols
    
    # Crop
    box = (c * 8, r * 8, c * 8 + 8, r * 8 + 8)
    tile_img = img.crop(box)
    
    # Save, preserving the palette
    tile_img.save(out_path)
    print(f"Successfully extracted tile {tile_index} to {out_path}.")

def insert_tile(img_path, source_tile_path, tile_index, palette_block):
    if not os.path.exists(img_path):
        print(f"Error: Image {img_path} does not exist", file=sys.stderr)
        sys.exit(1)
    if not os.path.exists(source_tile_path):
        print(f"Error: Source tile {source_tile_path} does not exist", file=sys.stderr)
        sys.exit(1)
        
    img = Image.open(img_path)
    if img.mode != "P":
        print(f"Error: Destination {img_path} is not in indexed color mode ('P').", file=sys.stderr)
        sys.exit(1)
        
    cols, rows = get_tileset_dimensions(img)
    if tile_index < 0 or tile_index >= cols * rows:
        print(f"Error: Tile index {tile_index} out of range (0 to {cols * rows - 1})", file=sys.stderr)
        sys.exit(1)
        
    src = Image.open(source_tile_path)
    if src.width != 8 or src.height != 8:
        print(f"Error: Source tile must be exactly 8x8 pixels. Got {src.width}x{src.height}.", file=sys.stderr)
        sys.exit(1)
        
    # Get palette from target image
    target_palette = img.getpalette() # 768 elements (R, G, B for 256 colors)
    
    # RGB color map for the specified palette block
    # Colors in the block range [16 * palette_block, 16 * palette_block + 15]
    start_color_idx = 16 * palette_block
    color_map = {}
    for idx in range(start_color_idx, start_color_idx + 16):
        r = target_palette[idx * 3]
        g = target_palette[idx * 3 + 1]
        b = target_palette[idx * 3 + 2]
        color_map[idx] = (r, g, b)
        
    # Load source pixels
    src_rgb = src.convert("RGB")
    src_pixels = src_rgb.load()
    
    # Map each pixel to the closest color in the designated block
    mapped_tile = Image.new("P", (8, 8))
    mapped_tile.putpalette(target_palette)
    mapped_pixels = mapped_tile.load()
    
    for y in range(8):
        for x in range(8):
            sr, sg, sb = src_pixels[x, y]
            # Find closest index
            best_idx = start_color_idx
            min_dist = float("inf")
            for idx, color in color_map.items():
                cr, cg, cb = color
                dist = (sr - cr)**2 + (sg - cg)**2 + (sb - cb)**2
                if dist < min_dist:
                    min_dist = dist
                    best_idx = idx
            mapped_pixels[x, y] = best_idx
            
    # Paste mapped tile into destination
    c = tile_index % cols
    r = tile_index // cols
    img.paste(mapped_tile, (c * 8, r * 8))
    
    img.save(img_path)
    print(f"Successfully inserted tile {tile_index} using palette block {palette_block}.")

def main():
    if len(sys.argv) < 2:
        print("Usage: png_tiles_editor.py <command> [args...]")
        print("Commands:")
        print("  validate <tiles.png>")
        print("  extract-tile <tiles.png> <tile_index> <output.png>")
        print("  insert-tile <tiles.png> <source_tile.png> <tile_index> --palette-block K")
        sys.exit(1)
        
    cmd = sys.argv[1]
    
    if cmd == "validate":
        if len(sys.argv) < 3:
            print("Usage: png_tiles_editor.py validate <tiles.png>")
            sys.exit(1)
        validate_tileset(sys.argv[2])
        
    elif cmd == "extract-tile":
        if len(sys.argv) < 5:
            print("Usage: png_tiles_editor.py extract-tile <tiles.png> <tile_index> <output.png>")
            sys.exit(1)
        try:
            tile_idx = int(sys.argv[3], 0)
        except ValueError:
            print(f"Error: Invalid tile index '{sys.argv[3]}'", file=sys.stderr)
            sys.exit(1)
        extract_tile(sys.argv[2], tile_idx, sys.argv[4])
        
    elif cmd == "insert-tile":
        if len(sys.argv) < 5:
            print("Usage: png_tiles_editor.py insert-tile <tiles.png> <source_tile.png> <tile_index> --palette-block K")
            sys.exit(1)
        tiles_path = sys.argv[2]
        src_path = sys.argv[3]
        try:
            tile_idx = int(sys.argv[4], 0)
        except ValueError:
            print(f"Error: Invalid tile index '{sys.argv[4]}'", file=sys.stderr)
            sys.exit(1)
            
        pal_block = 0
        if "--palette-block" in sys.argv:
            pal_pos = sys.argv.index("--palette-block") + 1
            if pal_pos < len(sys.argv):
                try:
                    pal_block = int(sys.argv[pal_pos], 0)
                except ValueError:
                    print(f"Error: Invalid palette block '{sys.argv[pal_pos]}'", file=sys.stderr)
                    sys.exit(1)
                    
        if pal_block < 0 or pal_block > 15:
            print("Error: Palette block must be between 0 and 15 inclusive.", file=sys.stderr)
            sys.exit(1)
            
        insert_tile(tiles_path, src_path, tile_idx, pal_block)
        
    else:
        print(f"Unknown command '{cmd}'", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
