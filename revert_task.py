import os
import shutil

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

print("=== STARTING REVERT ===")
if not os.path.exists(BACKUP_DIR):
    print(f"Error: Backup directory not found at {BACKUP_DIR}!")
    exit(1)

for target in TARGETS:
    src_path = os.path.join(BACKUP_DIR, target)
    dst_path = os.path.join(WORKSPACE_DIR, target)
    
    if not os.path.exists(src_path):
        print(f"Warning: Backup source not found: {target}")
        continue

    # Remove current file/directory in workspace
    if os.path.isdir(dst_path):
        shutil.rmtree(dst_path)
        shutil.copytree(src_path, dst_path)
        print(f"Restored directory: {target}")
    elif os.path.isfile(dst_path):
        os.remove(dst_path)
        shutil.copy2(src_path, dst_path)
        print(f"Restored file: {target}")
    else:
        # If it didn't exist originally, just copy it back
        if os.path.isdir(src_path):
            shutil.copytree(src_path, dst_path)
        else:
            shutil.copy2(src_path, dst_path)
        print(f"Restored new file/directory: {target}")

print("=== REVERT COMPLETE ===")
