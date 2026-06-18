import sys

def check_gfx():
    try:
        with open('graphics/types/move_types.4bpp', 'rb') as f:
            move_types = f.read()
        with open('graphics/types/normal.4bpp', 'rb') as f:
            normal = f.read()
        
        offset = 256
        chunk = move_types[offset:offset+256]
        
        if chunk == normal:
            print("Yes! normal.4bpp is correctly concatenated at offset 256 in move_types.4bpp.")
        else:
            print("No! normal.4bpp does not match the data in move_types.4bpp at offset 256.")
            print(f"normal.4bpp start: {list(normal[:16])}")
            print(f"move_types.4bpp start at 256: {list(chunk[:16])}")
            
    except Exception as e:
        print(f"Exception: {e}")

if __name__ == '__main__':
    check_gfx()
