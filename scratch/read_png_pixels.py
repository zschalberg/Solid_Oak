import struct
import zlib
import sys

def read_png_pixels(filepath):
    try:
        with open(filepath, 'rb') as f:
            sig = f.read(8)
            if sig != b'\x89PNG\r\n\x1a\n':
                print("Not a PNG")
                return
            
            ihdr = None
            idat_data = b""
            plte_data = b""
            
            while True:
                len_data = f.read(4)
                if not len_data:
                    break
                length = struct.unpack('>I', len_data)[0]
                chunk_type = f.read(4)
                chunk_data = f.read(length)
                f.read(4) # crc
                
                if chunk_type == b'IHDR':
                    ihdr = struct.unpack('>IIBBBBB', chunk_data)
                elif chunk_type == b'PLTE':
                    plte_data = chunk_data
                elif chunk_type == b'IDAT':
                    idat_data += chunk_data
                elif chunk_type == b'IEND':
                    break
            
            if not ihdr:
                print("No IHDR")
                return
            
            width, height, bit_depth, color_type, compression, filter_method, interlace = ihdr
            print(f"Dimensions: {width}x{height}, Bit Depth: {bit_depth}, Color Type: {color_type}")
            
            decompressed = zlib.decompress(idat_data)
            
            # Since bit_depth is likely 8 (indexed color) or 4, let's print unique values:
            unique_indices = set()
            
            # Reconstruct filtered scanlines
            # GBA PNGs are usually 8-bit indexed or 4-bit indexed.
            # Assuming 8-bit indexed, each scanline has 1 filter byte followed by width bytes.
            bytes_per_pixel = 1 # for indexed color
            stride = width * bytes_per_pixel
            
            recon = bytearray()
            pos = 0
            
            for r in range(height):
                filter_type = decompressed[pos]
                pos += 1
                scanline = decompressed[pos:pos+stride]
                pos += stride
                
                # Reconstruct scanline based on filter type
                recon_line = bytearray(stride)
                for c in range(stride):
                    val = scanline[c]
                    if filter_type == 0: # None
                        recon_line[c] = val
                    elif filter_type == 1: # Sub
                        left = recon_line[c - bytes_per_pixel] if c >= bytes_per_pixel else 0
                        recon_line[c] = (val + left) & 0xFF
                    elif filter_type == 2: # Up
                        up = recon[(r - 1) * stride + c] if r > 0 else 0
                        recon_line[c] = (val + up) & 0xFF
                    elif filter_type == 3: # Average
                        left = recon_line[c - bytes_per_pixel] if c >= bytes_per_pixel else 0
                        up = recon[(r - 1) * stride + c] if r > 0 else 0
                        recon_line[c] = (val + (left + up) // 2) & 0xFF
                    elif filter_type == 4: # Paeth
                        left = recon_line[c - bytes_per_pixel] if c >= bytes_per_pixel else 0
                        up = recon[(r - 1) * stride + c] if r > 0 else 0
                        upper_left = recon[(r - 1) * stride + c - bytes_per_pixel] if (r > 0 and c >= bytes_per_pixel) else 0
                        
                        p = left + up - upper_left
                        pa = abs(p - left)
                        pb = abs(p - up)
                        pc = abs(p - upper_left)
                        if pa <= pb and pa <= pc:
                            recon_val = left
                        elif pb <= pc:
                            recon_val = up
                        else:
                            recon_val = upper_left
                        recon_line[c] = (val + recon_val) & 0xFF
                recon.extend(recon_line)
                
            # Print the grid of pixel indices
            print("Pixel Indices:")
            for r in range(height):
                line = [recon[r * stride + c] for c in range(width)]
                print(" ".join(f"{v:2d}" for v in line))
                for v in line:
                    unique_indices.add(v)
            print("Unique indices in image:", sorted(list(unique_indices)))
            
    except Exception as e:
        print(f"Exception: {e}")

if __name__ == '__main__':
    read_png_pixels(sys.argv[1])
