import os
from PIL import Image

def convert_to_gba_4bpp(input_path, output_path):
    # Open the image
    img = Image.open(input_path)
    
    # Convert to RGB (discarding alpha channel)
    img_rgb = img.convert('RGB')
    
    # Quantize to 16 colors
    # FASTOCTREE is robust and keeps colors close to original
    quantized = img_rgb.quantize(colors=16, method=Image.Quantize.FASTOCTREE)
    
    # Get the top-left pixel index (which represents the background color)
    bg_index = quantized.getpixel((0, 0))
    
    # Get the palette (list of 48 values: R0, G0, B0, R1, G1, B1, ...)
    palette = list(quantized.getpalette()[:48])
    
    # Swap bg_index with index 0 in the palette and pixel data
    if bg_index != 0:
        # Swap palette entries
        r_bg, g_bg, b_bg = palette[bg_index*3 : bg_index*3 + 3]
        r_0, g_0, b_0 = palette[0:3]
        
        palette[0:3] = [r_bg, g_bg, b_bg]
        palette[bg_index*3 : bg_index*3 + 3] = [r_0, g_0, b_0]
        
        # Swap pixel values in the image data
        pixels = list(quantized.getdata())
        new_pixels = []
        for p in pixels:
            if p == 0:
                new_pixels.append(bg_index)
            elif p == bg_index:
                new_pixels.append(0)
            else:
                new_pixels.append(p)
                
        # Put swapped pixels back
        quantized.putdata(new_pixels)
        
    # Apply the swapped palette
    # Pad the palette to 256 colors (768 bytes) as required by PIL for saving P mode images
    final_palette = palette + [0] * (768 - 48)
    quantized.putpalette(final_palette)
    
    # Save the resulting indexed image
    quantized.save(output_path)
    print(f"Successfully converted {input_path} to GBA 4bpp indexed format at {output_path}")

def main():
    agatha_path = "graphics/mugshots/agatha.png"
    prof_oak_path = "graphics/mugshots/prof_oak.png"
    
    if os.path.exists(agatha_path):
        convert_to_gba_4bpp(agatha_path, agatha_path)
        
    if os.path.exists(prof_oak_path):
        convert_to_gba_4bpp(prof_oak_path, prof_oak_path)

if __name__ == "__main__":
    main()
