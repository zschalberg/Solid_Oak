import sys
from PIL import Image

def analyze_rows(filepath):
    im = Image.open(filepath)
    w, h = im.size
    rgba = im.convert("RGBA")
    data = list(rgba.getdata())
    
    def is_bg(r, g, b, a):
        return a == 0 or (r == 255 and g == 255 and b == 255)
        
    row_counts = []
    for y in range(h):
        non_bg_cnt = 0
        for x in range(w):
            idx = y * w + x
            r, g, b, a = data[idx]
            if not is_bg(r, g, b, a):
                non_bg_cnt += 1
        row_counts.append(non_bg_cnt)
        
    print("Row non-bg counts:")
    for y, cnt in enumerate(row_counts):
        if cnt == 0:
            print(f"Y={y}: empty")
        # else:
        #     print(f"Y={y}: {cnt}")

if __name__ == '__main__':
    analyze_rows(sys.argv[1])
