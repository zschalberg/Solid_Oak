#!/usr/bin/env python3
import os
import sys
import shutil
import json
import struct
import subprocess
import argparse
import glob
import re
from datetime import datetime

def decompress_lz77(data):
    """
    Decompresses GBA LZ77 compressed data.
    """
    if len(data) == 0 or data[0] != 0x10:
        raise ValueError("Not a GBA LZ77 compressed file")
    dest_size = data[1] | (data[2] << 8) | (data[3] << 16)
    dest = bytearray()
    
    src_idx = 4
    while len(dest) < dest_size:
        if src_idx >= len(data):
            break
        flag = data[src_idx]
        src_idx += 1
        
        for i in range(8):
            if len(dest) >= dest_size:
                break
            
            is_compressed = (flag >> (7 - i)) & 1
            if is_compressed:
                if src_idx + 1 >= len(data):
                    break
                b1 = data[src_idx]
                b2 = data[src_idx + 1]
                src_idx += 2
                
                length = (b1 >> 4) + 3
                offset = ((b1 & 0x0F) << 8) | b2
                
                back_idx = len(dest) - offset - 1
                for _ in range(length):
                    if len(dest) >= dest_size:
                        break
                    if back_idx < 0:
                        dest.append(0)
                    else:
                        dest.append(dest[back_idx])
                    back_idx += 1
            else:
                if src_idx >= len(data):
                    break
                dest.append(data[src_idx])
                src_idx += 1
    return bytes(dest)

def convert_blocks(blocks_path, out_meta, num_blocks):
    """
    Splits HMA blocks into metatiles.bin (tile data).
    """
    with open(blocks_path, 'rb') as f:
        data = f.read()
    
    expected_size = num_blocks * 18
    if len(data) < expected_size:
        print(f"Warning: Blocks file size ({len(data)} bytes) is smaller than expected ({expected_size} bytes).")
        num_blocks = len(data) // 18
        
    tiles_data = data[:num_blocks * 16]
    properties_data = data[num_blocks * 16 : num_blocks * 18]
    
    with open(out_meta, 'wb') as f:
        f.write(tiles_data)
        
    return properties_data

def parse_properties(properties_data, num_blocks):
    """
    Converts HMA properties to 4-byte metatile attribute structure.
    """
    attr_bytes = bytearray()
    for i in range(num_blocks):
        prop_bytes = properties_data[i * 2 : (i + 1) * 2]
        if len(prop_bytes) < 2:
            break
        prop = prop_bytes[0] | (prop_bytes[1] << 8)
        
        behavior = prop & 0xff
        layer = (prop >> 8) & 0x03
        
        attr = behavior
        attr |= (layer << 29)
        
        # Map known behavior types to terrain/encounter types
        if behavior in [0x10, 0x11, 0x12, 0x15, 0x50, 0x51, 0x52, 0x53]:
            attr |= (2 << 9)   # TILE_TERRAIN_WATER
            attr |= (2 << 24)  # TILE_ENCOUNTER_WATER
        elif behavior == 0x13:
            attr |= (3 << 9)   # TILE_TERRAIN_WATERFALL
            attr |= (2 << 24)  # TILE_ENCOUNTER_WATER
        elif behavior == 0x02:
            attr |= (1 << 9)   # TILE_TERRAIN_GRASS
            attr |= (1 << 24)  # TILE_ENCOUNTER_LAND
            
        attr_bytes.extend(struct.pack('<I', attr))
    return attr_bytes

def swap_jasc_pal_file(pal_path):
    """
    Swaps Red and Blue channels in a JASC-PAL color palette.
    """
    if not os.path.exists(pal_path):
        return False
        
    with open(pal_path, 'r') as f:
        lines = f.read().splitlines()
        
    if len(lines) < 4 or lines[0] != "JASC-PAL":
        return False
        
    new_lines = lines[:3]
    for line in lines[3:]:
        parts = line.strip().split()
        if len(parts) >= 3:
            r, g, b = parts[0], parts[1], parts[2]
            new_lines.append(f"{b} {g} {r}")
        else:
            new_lines.append(line)
            
    with open(pal_path, 'w') as f:
        f.write('\n'.join(new_lines) + '\n')
    return True

def find_file_case_insensitive(directory, filename):
    """
    Locates a file case-insensitively in a directory.
    """
    for f in os.listdir(directory):
        if f.lower() == filename.lower():
            return os.path.join(directory, f)
    return None

def camel_to_snake(name):
    """
    Converts CamelCase to snake_case.
    """
    name = name.replace("gTileset_", "")
    return re.sub(r'(?<!^)(?=[A-Z])', '_', name).lower()

def main():
    parser = argparse.ArgumentParser(description="Automated HMA Import Tool for Pokémon FireRed Decomps.")
    parser.add_argument('--source-dir', required=True, help="Folder containing exported HMA files (Blockmap.bin, Blocks.bin, Tileset.bin, palettes).")
    parser.add_argument('--map-dir', required=True, help="Path to the map directory in your decomp repo (e.g. data/maps/FuchsiaCity).")
    parser.add_argument('--backup-root', default="C:\\Users\\zscha\\OneDrive\\Desktop\\Solid_Oak_Backup_Map_Imports", help="Parent directory for backups.")
    parser.add_argument('--skip-compile', action='store_true', help="Skip compilation step after import.")
    
    args = parser.parse_args()
    
    # Verify input paths
    if not os.path.exists(args.source_dir):
        print(f"Error: Source directory '{args.source_dir}' does not exist.")
        sys.exit(1)
    if not os.path.exists(args.map_dir):
        print(f"Error: Map directory '{args.map_dir}' does not exist.")
        sys.exit(1)
        
    map_name = os.path.basename(os.path.normpath(args.map_dir))
    print(f"=== Starting Import for Map: {map_name} ===")
    
    # 1. Locate HMA files in source folder case-insensitively
    blockmap_path = find_file_case_insensitive(args.source_dir, "Blockmap.bin")
    blocks_path = find_file_case_insensitive(args.source_dir, "Blocks.bin")
    tileset_bin_path = find_file_case_insensitive(args.source_dir, "Tileset.bin")
    if not tileset_bin_path:
        tileset_bin_path = find_file_case_insensitive(args.source_dir, "Tiles.bin")
    palettes = glob.glob(os.path.join(args.source_dir, "*.pal"))
    
    if not blockmap_path:
        print("Error: Could not find 'Blockmap.bin' in source directory.")
        sys.exit(1)
    if not blocks_path:
        print("Error: Could not find 'Blocks.bin' in source directory.")
        sys.exit(1)
    if not tileset_bin_path:
        print("Error: Could not find 'Tileset.bin' in source directory.")
        sys.exit(1)
    if not palettes:
        print("Warning: No '.pal' files found in source directory.")
        
    # 2. Parse map.json and layouts.json to find targets
    map_json_path = os.path.join(args.map_dir, "map.json")
    if not os.path.exists(map_json_path):
        print(f"Error: Could not find '{map_json_path}'.")
        sys.exit(1)
        
    with open(map_json_path, 'r') as f:
        map_config = json.load(f)
        
    layout_id = map_config.get("layout")
    if not layout_id:
        print("Error: Could not resolve 'layout' ID from map.json.")
        sys.exit(1)
        
    layouts_json_path = "data/layouts/layouts.json"
    if not os.path.exists(layouts_json_path):
        print("Error: Could not find data/layouts/layouts.json.")
        sys.exit(1)
        
    with open(layouts_json_path, 'r') as f:
        layouts_config = json.load(f)
        
    layout_info = None
    for layout in layouts_config.get("layouts", []):
        if layout.get("id") == layout_id:
            layout_info = layout
            break
            
    if not layout_info:
        print(f"Error: Could not find layout '{layout_id}' in layouts.json.")
        sys.exit(1)
        
    # Extract destination paths
    blockdata_dest = layout_info.get("blockdata_filepath")
    secondary_tileset_name = layout_info.get("secondary_tileset")
    
    if not blockdata_dest:
        print("Error: blockdata_filepath not specified in layout configuration.")
        sys.exit(1)
    if not secondary_tileset_name:
        print("Error: secondary_tileset not specified in layout configuration.")
        sys.exit(1)
        
    secondary_tileset_folder = camel_to_snake(secondary_tileset_name)
    tileset_dest_dir = os.path.join("data/tilesets/secondary", secondary_tileset_folder)
    
    if not os.path.exists(tileset_dest_dir):
        print(f"Error: Target tileset folder '{tileset_dest_dir}' does not exist.")
        sys.exit(1)
        
    print(f"Layout Blockmap Dest:  {blockdata_dest}")
    print(f"Secondary Tileset Name: {secondary_tileset_name}")
    print(f"Tileset Dest Folder:    {tileset_dest_dir}")
    
    # 3. Create Backup
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    backup_dir = os.path.join(args.backup_root, f"{map_name}_{timestamp}")
    os.makedirs(backup_dir, exist_ok=True)
    print(f"Creating backup in: {backup_dir}")
    
    # Backup blockmap
    if os.path.exists(blockdata_dest):
        shutil.copy2(blockdata_dest, os.path.join(backup_dir, "map.bin"))
    # Backup tileset files
    for f in ["metatiles.bin", "metatile_attributes.bin", "tiles.png"]:
        p = os.path.join(tileset_dest_dir, f)
        if os.path.exists(p):
            shutil.copy2(p, os.path.join(backup_dir, f))
    # Backup palettes
    palettes_dest_dir = os.path.join(tileset_dest_dir, "palettes")
    if os.path.exists(palettes_dest_dir):
        shutil.copytree(palettes_dest_dir, os.path.join(backup_dir, "palettes"))
    # Backup tileset_rules.mk
    shutil.copy2("tileset_rules.mk", os.path.join(backup_dir, "tileset_rules.mk"))
    
    # 4. Copy Layout Blockmap
    print("Copying new map layout grid...")
    shutil.copy2(blockmap_path, blockdata_dest)
    
    # 5. Decompress and Convert Tileset Graphics
    print("Decompressing HMA Tileset.bin...")
    with open(tileset_bin_path, 'rb') as f:
        tiles_compressed_data = f.read()
    tiles_decompressed_data = decompress_lz77(tiles_compressed_data)
    num_tiles = len(tiles_decompressed_data) // 32
    print(f"Successfully decompressed tileset: {num_tiles} tiles found.")
    
    temp_4bpp_path = os.path.join(tileset_dest_dir, "tiles.4bpp")
    with open(temp_4bpp_path, 'wb') as f:
        f.write(tiles_decompressed_data)
        
    # Run gbagfx to convert to PNG
    png_dest_path = os.path.join(tileset_dest_dir, "tiles.png")
    print(f"Converting tiles.4bpp to tiles.png...")
    gbagfx_cmd = ["wsl", "./tools/gbagfx/gbagfx", temp_4bpp_path.replace("\\", "/"), png_dest_path.replace("\\", "/"), "-width", "16"]
    res = subprocess.run(gbagfx_cmd, capture_output=True, text=True)
    
    if os.path.exists(temp_4bpp_path):
        os.remove(temp_4bpp_path)
        
    if res.returncode != 0:
        print(f"Error during PNG conversion: {res.stderr}")
        sys.exit(1)
    print("Tileset graphic conversion complete.")
    
    # 6. Split and Merge Blocks/Attributes
    print("Processing Blocks.bin and merging attributes...")
    blocks_size = os.path.getsize(blocks_path)
    hma_blocks = blocks_size // 18
    print(f"HMA block count: {hma_blocks}")
    
    # Split blocks.bin into metatiles.bin (tile structure)
    properties_data = convert_blocks(blocks_path, os.path.join(tileset_dest_dir, "metatiles.bin"), hma_blocks)
    custom_attrs = parse_properties(properties_data, hma_blocks)
    
    # Merge with stock attributes to preserve interactions
    backup_attrs_path = os.path.join(backup_dir, "metatile_attributes.bin")
    if os.path.exists(backup_attrs_path):
        stock_size = os.path.getsize(backup_attrs_path)
        num_stock = stock_size // 4
        print(f"Merging attributes: Preserving first {num_stock} blocks from stock...")
        
        with open(backup_attrs_path, 'rb') as f:
            stock_attrs_data = f.read(num_stock * 4)
            
        merged_attrs = stock_attrs_data + custom_attrs[num_stock * 4:]
        with open(os.path.join(tileset_dest_dir, "metatile_attributes.bin"), 'wb') as f:
            f.write(merged_attrs)
    else:
        # Write custom attributes directly if there are no stock files (e.g. brand new tileset)
        with open(os.path.join(tileset_dest_dir, "metatile_attributes.bin"), 'wb') as f:
            f.write(custom_attrs)
            
    # 7. Palettes copy and swapper
    if palettes:
        print("Copying and swapping palettes...")
        # Clear existing .gbapal files
        for f in os.listdir(palettes_dest_dir):
            if f.endswith(".gbapal"):
                os.remove(os.path.join(palettes_dest_dir, f))
                
        # Copy and swap
        for pal in palettes:
            basename = os.path.basename(pal)
            dest_pal = os.path.join(palettes_dest_dir, basename)
            shutil.copy2(pal, dest_pal)
            swap_jasc_pal_file(dest_pal)
        print("Palette conversion complete.")
        
    # 8. Update tileset_rules.mk
    print("Updating tileset_rules.mk tile count limit...")
    with open("tileset_rules.mk", 'r') as f:
        rules_content = f.read()
        
    # Match the rule for the target secondary tileset and update the -num_tiles parameter
    pattern = rf"(\$\(TILESETGFXDIR\)/secondary/{secondary_tileset_folder}/tiles\.4bpp:[^\n]*\n\t\$\(GFX\)\s+\$<\s+\$@\s+-num_tiles\s+)\d+"
    
    if re.search(pattern, rules_content):
        updated_content = re.sub(pattern, rf"\g<1>{num_tiles}", rules_content)
        with open("tileset_rules.mk", 'w') as f:
            f.write(updated_content)
        print(f"Updated {secondary_tileset_folder} tile count to {num_tiles} in tileset_rules.mk.")
    else:
        print(f"Warning: Could not locate compilation rule for 'secondary/{secondary_tileset_folder}' in tileset_rules.mk.")
        
    print("\n=== IMPORT COMPLETE ===")
    
    # 9. Verify compilation
    if not args.skip_compile:
        print("\nVerifying build (wsl make -j4)...")
        build_res = subprocess.run(["wsl", "make", "-j4"])
        if build_res.returncode == 0:
            print("\n=== BUILD SUCCESSFUL ===")
        else:
            print("\n=== BUILD FAILED ===")
            sys.exit(1)

if __name__ == '__main__':
    main()
