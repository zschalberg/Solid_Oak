import os
import re
import shutil
import sys
from PIL import Image

# Paths
SPECIES_H = "include/constants/species.h"
GEN2_GFX_DIR = "graphics/pokedex_gen2"
SHEET_PNG = "C:/Users/zscha/.gemini/antigravity/brain/a8a863e8-99df-4263-9191-8c0ac3074fbd/media__1781896285643.png"

def parse_hoenn_species():
    # We only care about species from SPECIES_TREECKO (252) to SPECIES_DEOXYS (386)
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
        if 252 <= val <= 386:
            # We want to ignore form aliases (like SPECIES_DEOXYS_NORMAL which equals SPECIES_DEOXYS,
            # or SPECIES_CASTFORM_NORMAL which equals SPECIES_CASTFORM).
            # If the value is already mapped, we skip duplicate names unless it is the canonical one.
            if val not in species_map or "NORMAL" not in name:
                species_map[val] = name

    # Sort by value
    sorted_values = sorted(list(species_map.keys()))
    for val in sorted_values:
        species_list.append((species_map[val], val))

    print(f"Parsed {len(species_list)} Hoenn species.")
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
            # If pixel is transparent or matching the bg color, treat as bg
            if a < 128 or (r == 205 and g == 205 and b == 172) or (r == 255 and g == 255 and b == 255):
                continue
            color = (r, g, b)
            if color not in unique_colors:
                unique_colors.append(color)
                
    if len(unique_colors) > 15:
        # Quantize to 15 colors if there are too many (retro sheets can sometimes have compression artifacts)
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
    species_list = parse_hoenn_species()
    
    sheet = Image.open(SHEET_PNG)
    rgba_sheet = sheet.convert("RGBA")
    
    # Grid parameters
    left_margin = 8
    top_margin = 12
    cell_w = 56
    cell_h = 56
    cols = 9
    rows = 16
    
    species_idx = 0
    total_imported = 0
    
    for row in range(rows):
        for col in range(cols):
            # Skip forms
            # Skip Castform Sunny, Rainy, Snowy (Row 11, Cols 1, 2, 3)
            if row == 11 and col in [1, 2, 3]:
                continue
            # Skip Deoxys Attack, Defense, Speed (Row 15, Cols 3, 4, 5)
            if row == 15 and col in [3, 4, 5]:
                continue
                
            if species_idx >= len(species_list):
                break
                
            species_name, val = species_list[species_idx]
            folder_name = species_name.replace("SPECIES_", "").lower()
            
            # Crop 56x56 cell
            x1 = left_margin + col * cell_w
            y1 = top_margin + row * cell_h
            x2 = x1 + cell_w
            y2 = y1 + cell_h
            
            cell_img = rgba_sheet.crop((x1, y1, x2, y2))
            
            # Center on 64x64 canvas
            canvas = Image.new("RGBA", (64, 64), (205, 205, 172, 255))
            canvas.paste(cell_img, (4, 4), cell_img)
            
            # Stack vertically to 64x128
            double_canvas = Image.new("RGBA", (64, 128), (205, 205, 172, 255))
            double_canvas.paste(canvas, (0, 0))
            double_canvas.paste(canvas, (0, 64))
            
            # Save
            dst_dir = os.path.join(GEN2_GFX_DIR, folder_name)
            extract_palette_and_save(double_canvas, dst_dir)
            
            species_idx += 1
            total_imported += 1
            
    print(f"Successfully imported {total_imported} Hoenn species into {GEN2_GFX_DIR}.")

if __name__ == '__main__':
    main()
