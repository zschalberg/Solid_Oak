import sys
from PIL import Image

def analyze_columns(filepath):
    im = Image.open(filepath)
    w, h = im.size
    rgba = im.convert("RGBA")
    data = list(rgba.getdata())
    
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
        
    # Print the local minima of col_counts
    print("X indices where col_counts is 0 or very small (local minima):")
    minima = []
    for x in range(1, w-1):
        if col_counts[x] <= col_counts[x-1] and col_counts[x] <= col_counts[x+1] and col_counts[x] < 10:
            minima.append((x, col_counts[x]))
    print(minima)

if __name__ == '__main__':
    analyze_columns(sys.argv[1])
