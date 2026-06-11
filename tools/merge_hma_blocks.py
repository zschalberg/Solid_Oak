#!/usr/bin/env python3
import os
import sys
import struct
import argparse
import glob

def convert_blocks(blocks_path, out_meta, num_blocks):
    """
    Splits the HMA blocks file into the metatiles.bin containing tile data.
    """
    with open(blocks_path, 'rb') as f:
        data = f.read()
    
    expected_size = num_blocks * 18
    if len(data) < expected_size:
        print(f"Warning: blocks file size ({len(data)} bytes) is smaller than expected for {num_blocks} blocks ({expected_size} bytes). Truncating expected blocks.")
        num_blocks = len(data) // 18
        
    tiles_data = data[:num_blocks * 16]
    properties_data = data[num_blocks * 16 : num_blocks * 18]
    
    with open(out_meta, 'wb') as f:
        f.write(tiles_data)
        
    return properties_data

def parse_properties(properties_data, num_blocks):
    """
    Converts 2-byte property data to 4-byte metatile attribute structure.
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
        print(f"Error: Palette file {pal_path} does not exist.")
        return False
        
    with open(pal_path, 'r') as f:
        lines = f.read().splitlines()
        
    if len(lines) < 4 or lines[0] != "JASC-PAL":
        print(f"Warning: {pal_path} is not a valid JASC-PAL file.")
        return False
        
    new_lines = lines[:3]
    for line in lines[3:]:
        parts = line.strip().split()
        if len(parts) >= 3:
            r, g, b = parts[0], parts[1], parts[2]
            # Swap Red and Blue
            new_lines.append(f"{b} {g} {r}")
        else:
            new_lines.append(line)
            
    with open(pal_path, 'w') as f:
        f.write('\n'.join(new_lines) + '\n')
    print(f"Swapped palette channels: {pal_path}")
    return True

def main():
    parser = argparse.ArgumentParser(description="Helper tool for importing HMA custom maps and tilesets into decomp.")
    
    # Blocks & Attributes Merging arguments
    parser.add_argument('--blocks', type=str, help="Path to the HMA exported blocks (.bin) file.")
    parser.add_argument('--stock-attrs', type=str, help="Path to the original/backup metatile_attributes.bin file to preserve stock behaviors.")
    parser.add_argument('--out-meta', type=str, help="Path where the split metatiles.bin file will be written.")
    parser.add_argument('--out-attrs', type=str, help="Path where the final merged metatile_attributes.bin file will be written.")
    parser.add_argument('--num-stock', type=int, help="Number of stock blocks to preserve. If not provided, it is calculated from the size of the stock attributes file.")
    
    # Palette utilities
    parser.add_argument('--swap-palette', type=str, help="Path to a JASC-PAL file or a directory containing .pal files to swap BGR-to-RGB.")
    
    args = parser.parse_args()
    
    if args.swap_palette:
        target = args.swap_palette
        if os.path.isdir(target):
            pal_files = glob.glob(os.path.join(target, "*.pal"))
            if not pal_files:
                print(f"No .pal files found in {target}")
            for pal in pal_files:
                swap_jasc_pal_file(pal)
        else:
            swap_jasc_pal_file(target)
            
    if args.blocks:
        if not args.out_meta or not args.out_attrs:
            print("Error: --out-meta and --out-attrs must be specified when using --blocks.")
            sys.exit(1)
            
        # 1. Determine number of blocks in the HMA export
        hma_size = os.path.getsize(args.blocks)
        num_blocks = hma_size // 18
        print(f"Detected {num_blocks} blocks in {args.blocks}")
        
        # 2. Extract tile mappings to metatiles.bin
        properties_data = convert_blocks(args.blocks, args.out_meta, num_blocks)
        
        # 3. Generate custom attributes
        custom_attrs = parse_properties(properties_data, num_blocks)
        
        # 4. Handle merging with stock attributes if requested
        if args.stock_attrs:
            if not os.path.exists(args.stock_attrs):
                print(f"Error: Stock attributes file {args.stock_attrs} does not exist.")
                sys.exit(1)
                
            stock_size = os.path.getsize(args.stock_attrs)
            detected_stock_blocks = stock_size // 4
            
            num_stock = args.num_stock if args.num_stock is not None else detected_stock_blocks
            print(f"Preserving the first {num_stock} blocks from stock attributes ({args.stock_attrs})")
            
            with open(args.stock_attrs, 'rb') as f:
                stock_attrs_data = f.read(num_stock * 4)
                
            # If the stock attributes file was smaller than expected, warn the user
            if len(stock_attrs_data) < num_stock * 4:
                print(f"Warning: Stock attributes file contains only {len(stock_attrs_data)//4} blocks.")
                num_stock = len(stock_attrs_data) // 4
                
            # Merge: first num_stock * 4 bytes are from stock, the rest are from custom HMA conversion
            split_offset = num_stock * 4
            merged_attrs = stock_attrs_data + custom_attrs[split_offset:]
            
            with open(args.out_attrs, 'wb') as f:
                f.write(merged_attrs)
            print(f"Successfully merged attributes: {len(merged_attrs)} bytes written to {args.out_attrs}")
        else:
            # Write custom attributes directly without merge
            with open(args.out_attrs, 'wb') as f:
                f.write(custom_attrs)
            print(f"Successfully wrote custom attributes directly: {len(custom_attrs)} bytes written to {args.out_attrs}")

if __name__ == '__main__':
    main()
