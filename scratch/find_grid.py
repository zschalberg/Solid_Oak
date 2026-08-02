import sys
from PIL import Image

def find_grid(filepath):
    im = Image.open(filepath)
    w, h = im.size
    print(f"Loaded image: {w}x{h}, mode={im.mode}")
    
    # Let's check which columns are completely blank (either transparent or white/transparent).
    # Since it's a sprite sheet, the background is probably transparent (or index 0).
    # Let's check if the image has an alpha channel or palette.
    print(f"Info: {im.info}")
    
    # We can convert to RGBA to easily analyze transparency/pixels
    rgba = im.convert("RGBA")
    data = list(rgba.getdata())
    
    # Let's count how many non-background pixels are in each column
    # Background is defined as transparent (alpha=0) or white (255, 255, 255, 255)
    def is_bg(r, g, b, a):
        return a == 0 or (r == 255 and g == 255 and b == 255)
        
    col_counts = []
    for x in range(w):
        non_bg_cnt = 0
        for y in range(h):
            idx = y * w + x
            r, g, b, a = data[idx]
            if not is_bg(r, g, b, a):
                non_bg_cnt += 1
        col_counts.append(non_bg_cnt)
        
    row_counts = []
    for y in range(h):
        non_bg_cnt = 0
        for x in range(w):
            idx = y * w + x
            r, g, b, a = data[idx]
            if not is_bg(r, g, b, a):
                non_bg_cnt += 1
        row_counts.append(non_bg_cnt)
        
    print("Col non-bg counts (first 100):")
    print(col_counts[:100])
    
    # Let's find intervals where col_counts is 0 (or very low)
    # to detect vertical lines of grid
    gaps_col = [x for x, val in enumerate(col_counts) if val == 0]
    print(f"Col gaps (X positions where completely empty): {gaps_col[:100]}")
    
    gaps_row = [y for y, val in enumerate(row_counts) if val == 0]
    print(f"Row gaps (Y positions where completely empty): {gaps_row[:100]}")

if __name__ == '__main__':
    find_grid(sys.argv[1])
