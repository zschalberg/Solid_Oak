import struct
import sys

def read_png_palette(filepath):
    try:
        with open(filepath, 'rb') as f:
            sig = f.read(8)
            if sig != b'\x89PNG\r\n\x1a\n':
                print(f"Error: {filepath} is not a valid PNG file.")
                return
            while True:
                len_data = f.read(4)
                if not len_data:
                    break
                length = struct.unpack('>I', len_data)[0]
                type_data = f.read(4)
                data = f.read(length)
                f.read(4) # crc
                if type_data == b'PLTE':
                    print("PLTE colors:")
                    colors = [list(data[i:i+3]) for i in range(0, length, 3)]
                    for idx, col in enumerate(colors):
                        print(f"  {idx}: {col}")
                    return
            print("No PLTE chunk found.")
    except Exception as e:
        print(f"Exception: {e}")

if __name__ == '__main__':
    read_png_palette(sys.argv[1])
