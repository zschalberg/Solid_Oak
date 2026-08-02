import os
import re
import shutil
import sys
from PIL import Image

# Paths
SPECIES_H = "include/constants/species.h"
GEN2_GFX_DIR = "graphics/pokedex_gen2"
SHEET_PNG = "C:/Users/zscha/.gemini/antigravity/brain/a8a863e8-99df-4263-9191-8c0ac3074fbd/media__1783435299854.png"

def parse_sinnoh_species():
    # We only care about species from SPECIES_TURTWIG (387) to SPECIES_ARCEUS (493)
    species_list = []
    with open(SPECIES_H, "r", encoding="utf-8") as f:
        content = f.read()

    enum_match = re.search(r"enum\s+__attribute__\(\(packed\)\)\s+Species\s*\{(.*?)\};", content, re.DOTALL)
    if not enum_match:
        print("Error: Could not find Species enum in species.h")
        sys.exit(1)

    enum_content = enum_match.group(1)
    matches = re.findall(r"\s*(SPECIES_[A-Z0-9_]+)\s*=\s*([0-9]+)\s*,", enum_content)
    
    species_map = {}
    for name, val_str in matches:
        val = int(val_str)
        if 387 <= val <= 493:
            # Skip form aliases (like SPECIES_ARCEUS_NORMAL which equals SPECIES_ARCEUS)
            if val not in species_map or "NORMAL" not in name:
                species_map[val] = name

    # Sort by value
    sorted_values = sorted(list(species_map.keys()))
    for val in sorted_values:
        species_list.append((species_map[val], val))

    print(f"Parsed {len(species_list)} Sinnoh species.")
    return species_list

def extract_palette_and_save(rgba_img, dst_dir):
    os.makedirs(dst_dir, exist_ok=True)
    
    # Transparency color
    bg_color = (205, 205, 172)
    
    # 1. Find all unique non-transparent/non-background colors
    unique_colors = []
    w, h = rgba_img.size
    pixels = rgba_img.load()
    
    for y in range(h):
        for x in range(w):
            r, g, b, a = pixels[x, y]
            # Treat transparency, default background color, and pure white as background
            if a < 128 or (r == 205 and g == 205 and b == 172) or (r == 255 and g == 255 and b == 255):
                continue
            color = (r, g, b)
            if color not in unique_colors:
                unique_colors.append(color)
                
    if len(unique_colors) > 15:
        print(f"Warning: Found {len(unique_colors)} colors in {dst_dir}. Quantizing to 15 colors...")
        unique_colors = unique_colors[:15]
        
    # Build a 16-color palette
    palette_colors = [bg_color] + unique_colors
    while len(palette_colors) < 16:
        palette_colors.append((0, 0, 0))
        
    # Create indexed image (mode 'P')
    indexed_img = Image.new("P", (w, h))
    
    # Flatten palette
    flat_palette = []
    for r, g, b in palette_colors:
        flat_palette.extend([r, g, b])
    indexed_img.putpalette(flat_palette)
    
    # Map pixels to indices
    indexed_pixels = indexed_img.load()
    for y in range(h):
        for x in range(w):
            r, g, b, a = pixels[x, y]
            if a < 128 or (r == 205 and g == 205 and b == 172) or (r == 255 and g == 255 and b == 255):
                indexed_pixels[x, y] = 0
            else:
                # Find closest color in palette_colors[1:]
                best_idx = 1
                min_dist = 999999
                for idx in range(1, len(palette_colors)):
                    pr, pg, pb = palette_colors[idx]
                    dist = (r - pr)**2 + (g - pg)**2 + (b - pb)**2
                    if dist < min_dist:
                        min_dist = dist
                        best_idx = idx
                indexed_pixels[x, y] = best_idx
                
    # Save front.png
    indexed_img.save(os.path.join(dst_dir, "front.png"))
    
    # Save normal.pal
    pal_path = os.path.join(dst_dir, "normal.pal")
    with open(pal_path, "w") as f:
        f.write("JASC-PAL\n")
        f.write("0100\n")
        f.write("16\n")
        for r, g, b in palette_colors:
            f.write(f"{r} {g} {b}\n")
            
    # Save shiny.pal (duplicate normal.pal)
    shutil.copy(pal_path, os.path.join(dst_dir, "shiny.pal"))

def main():
    species_list = parse_sinnoh_species()
    
    sheet = Image.open(SHEET_PNG)
    rgba_sheet = sheet.convert("RGBA")
    
    # Grid parameters (73x73 cells, 1px left margin, 0px top margin)
    cell_w = 73
    cell_h = 73
    left_margin = 1
    top_margin = 0
    cols = 9
    rows = 14
    
    species_idx = 0
    total_imported = 0
    
    # 16 Alternate / Gender forms to skip
    forms_to_skip = {
        (2, 8), # Burmy Sandy
        (3, 0), # Burmy Trash
        (3, 2), # Wormadam Sandy
        (3, 3), # Wormadam Trash
        (4, 3), # Cherrim Sunshine
        (4, 5), # Shellos East Sea
        (4, 7), # Gastrodon East Sea
        (7, 7), # Hippopotas Female
        (8, 0), # Hippowdon Female
        (11, 3), # Rotom Heat
        (11, 4), # Rotom Wash
        (11, 5), # Rotom Frost
        (11, 6), # Rotom Fan
        (11, 7), # Rotom Mow
        (12, 7), # Giratina Origin
        (13, 4), # Shaymin Sky
    }
    
    for row in range(rows):
        for col in range(cols):
            # Skip alternate/gender forms
            if (row, col) in forms_to_skip:
                continue
                
            if species_idx >= len(species_list):
                break
                
            species_name, val = species_list[species_idx]
            folder_name = species_name.replace("SPECIES_", "").lower()
            
            # Crop 73x73 cell
            x1 = left_margin + col * cell_w
            y1 = top_margin + row * cell_h
            x2 = x1 + cell_w
            y2 = y1 + cell_h
            
            cell_img = rgba_sheet.crop((x1, y1, x2, y2))
            
            # Find the bounding box of non-white pixels
            non_white = []
            for cy in range(cell_h):
                for cx in range(cell_w):
                    r, g, b, a = cell_img.getpixel((cx, cy))
                    if a != 0 and not (r == 255 and g == 255 and b == 255):
                        non_white.append((cx, cy))
            
            # Create a 64x64 canvas
            canvas = Image.new("RGBA", (64, 64), (205, 205, 172, 255))
            
            if non_white:
                xs = [p[0] for p in non_white]
                ys = [p[1] for p in non_white]
                bx1, by1 = min(xs), min(ys)
                bx2, by2 = max(xs), max(ys)
                bw, bh = bx2 - bx1 + 1, by2 - by1 + 1
                
                cropped = cell_img.crop((bx1, by1, bx2 + 1, by2 + 1))
                
                # Fit cropped bbox inside 64x64
                if bw > 64:
                    # Crop equal amounts left/right
                    x_offset = (bw - 64) // 2
                    cropped = cropped.crop((x_offset, 0, x_offset + 64, cropped.height))
                    bw = 64
                    px = 0
                else:
                    px = (64 - bw) // 2
                    
                if bh > 64:
                    # Crop from the top, keeping the bottom aligned
                    y_offset = bh - 64
                    cropped = cropped.crop((0, y_offset, cropped.width, bh))
                    bh = 64
                    py = 0
                else:
                    py = (64 - bh) // 2
                    
                canvas.paste(cropped, (px, py), cropped)
            else:
                print(f"Warning: Cell ({row}, {col}) for {folder_name} is empty.")
            
            # Stack vertically to 64x128
            double_canvas = Image.new("RGBA", (64, 128), (205, 205, 172, 255))
            double_canvas.paste(canvas, (0, 0))
            double_canvas.paste(canvas, (0, 64))
            
            # Save
            dst_dir = os.path.join(GEN2_GFX_DIR, folder_name)
            extract_palette_and_save(double_canvas, dst_dir)
            
            species_idx += 1
            total_imported += 1
            
    print(f"Successfully imported {total_imported} Sinnoh species into {GEN2_GFX_DIR}.")

if __name__ == '__main__':
    main()
