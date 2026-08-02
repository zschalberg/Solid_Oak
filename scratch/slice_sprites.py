import os
import sys
from PIL import Image

def slice_sprites(filepath, output_dir):
    im = Image.open(filepath)
    w, h = im.size
    rgba = im.convert("RGBA")
    
    # Grid parameters
    left_margin = 8
    top_margin = 12
    cell_w = 56
    cell_h = 56
    cols = 9
    rows = 16
    
    os.makedirs(output_dir, exist_ok=True)
    
    def is_empty(cell_img):
        # Check if all pixels are background (transparent or white)
        data = list(cell_img.getdata())
        for r, g, b, a in data:
            if a != 0 and not (r == 255 and g == 255 and b == 255):
                return False
        return True
        
    non_empty_cells = []
    
    for row in range(rows):
        for col in range(cols):
            x1 = left_margin + col * cell_w
            y1 = top_margin + row * cell_h
            x2 = x1 + cell_w
            y2 = y1 + cell_h
            
            cell_img = rgba.crop((x1, y1, x2, y2))
            
            if not is_empty(cell_img):
                non_empty_cells.append((row, col))
                # Save crop
                cell_img.save(os.path.join(output_dir, f"sprite_{row}_{col}.png"))
                
    print(f"Total non-empty cells: {len(non_empty_cells)}")
    print("Non-empty cells:")
    for r, c in non_empty_cells:
        print(f"  Row {r}, Col {c}")

if __name__ == '__main__':
    slice_sprites(sys.argv[1], sys.argv[2])
