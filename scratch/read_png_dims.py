import struct
import sys

def read_png_dims(filepath):
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
                if type_data == b'IHDR':
                    w, h = struct.unpack('>II', data[0:8])
                    print(f"IHDR: width={w}, height={h}")
                    return
    except Exception as e:
        print(f"Exception: {e}")

if __name__ == '__main__':
    read_png_dims(sys.argv[1])
