import struct
import sys

def read_gbapal(filepath):
    try:
        with open(filepath, 'rb') as f:
            data = f.read()
            num_colors = len(data) // 2
            colors = struct.unpack(f'<{num_colors}H', data)
            for idx, c in enumerate(colors):
                r = (c & 0x1F) * 8
                g = ((c >> 5) & 0x1F) * 8
                b = ((c >> 10) & 0x1F) * 8
                print(f"{idx:2d}: [{r:3d}, {g:3d}, {b:3d}] (0x{c:04X})")
    except Exception as e:
        print(f"Exception: {e}")

if __name__ == '__main__':
    read_gbapal(sys.argv[1])
