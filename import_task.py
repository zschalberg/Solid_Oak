import os
import shutil
import struct

WORKSPACE_DIR = os.getcwd()
DESKTOP_DIR = r"C:\Users\zscha\OneDrive\Desktop"
BACKUP_DIR = os.path.join(DESKTOP_DIR, "Solid_Oak_Backup_Vermilion_Import")

# Target directories and files relative to workspace root
TARGETS = [
    "data/tilesets/primary/general/metatiles.bin",
    "data/tilesets/primary/general/metatile_attributes.bin",
    "data/tilesets/primary/general/tiles.png",
    "data/tilesets/primary/general/palettes",
    "data/tilesets/secondary/vermilion_city/metatiles.bin",
    "data/tilesets/secondary/vermilion_city/metatile_attributes.bin",
    "data/tilesets/secondary/vermilion_city/tiles.png",
    "data/tilesets/secondary/vermilion_city/palettes",
    "data/layouts/VermilionCity/map.bin"
]

print("=== STARTING BACKUP TO DESKTOP ===")
os.makedirs(BACKUP_DIR, exist_ok=True)
for target in TARGETS:
    src_path = os.path.join(WORKSPACE_DIR, target)
    dst_path = os.path.join(BACKUP_DIR, target)
    
    # Create parent directories in backup
    os.makedirs(os.path.dirname(dst_path), exist_ok=True)
    
    if os.path.isdir(src_path):
        if os.path.exists(dst_path):
            shutil.rmtree(dst_path)
        shutil.copytree(src_path, dst_path)
        print(f"Backed up directory: {target} -> Desktop")
    elif os.path.isfile(src_path):
        shutil.copy2(src_path, dst_path)
        print(f"Backed up file: {target} -> Desktop")
    else:
        print(f"Warning: Target not found for backup: {target}")

print("=== BACKUP COMPLETE ===")

print("\n=== STARTING IMPORT ===")

# 1. Copy primary general tileset files
print("Updating General primary tileset...")
shutil.copy2("import_temp/primary_metatiles.bin", "data/tilesets/primary/general/metatiles.bin")
shutil.copy2("import_temp/primary_metatile_attributes.bin", "data/tilesets/primary/general/metatile_attributes.bin")
shutil.copy2("import_temp/Celadon_Primary_Tile.png", "data/tilesets/primary/general/tiles.png")

# Copy primary palettes (00 to 06)
for i in range(7):
    pal_file = f"{i:02d}.pal"
    shutil.copy2(f"import_temp/{pal_file}", f"data/tilesets/primary/general/palettes/{pal_file}")
print("General primary tileset updated.")

# 2. Copy secondary Vermilion City tileset files
print("Updating Vermilion City secondary tileset...")
shutil.copy2("import_temp/vermilion_metatiles.bin", "data/tilesets/secondary/vermilion_city/metatiles.bin")
shutil.copy2("import_temp/vermilion_metatile_attributes.bin", "data/tilesets/secondary/vermilion_city/metatile_attributes.bin")
shutil.copy2("import_temp/Verm/tiles.png", "data/tilesets/secondary/vermilion_city/tiles.png")

# Copy secondary palettes (00 to 15) mapped from hex names to decimal
print("Mapping and copying Vermilion palettes...")
for i in range(16):
    hex_name = f"{i:02X}.pal"
    dec_name = f"{i:02d}.pal"
    src_pal = os.path.join("import_temp/Verm", hex_name)
    dst_pal = os.path.join("data/tilesets/secondary/vermilion_city/palettes", dec_name)
    if os.path.exists(src_pal):
        shutil.copy2(src_pal, dst_pal)
        # Also clean up the pre-compiled .gbapal files so they force compile on build
        gba_pal_path = dst_pal.replace(".pal", ".gbapal")
        if os.path.exists(gba_pal_path):
            os.remove(gba_pal_path)
print("Vermilion City secondary tileset updated.")

# 3. Copy Vermilion City map layout (map.bin)
print("Updating Vermilion City map layout...")
shutil.copy2("import_temp/Verm/Blockset.bin", "data/layouts/VermilionCity/map.bin")
print("Vermilion City map layout updated.")

print("\n=== IMPORT COMPLETE ===")
