import os
import re
import shutil

# Paths
SPECIES_H = "include/constants/species.h"
GEN1_FAMILIES = "src/data/pokemon/species_info/gen_1_families.h"
GEN2_FAMILIES = "src/data/pokemon/species_info/gen_2_families.h"
POKEMON_GFX_DIR = "graphics/pokemon"
GEN2_GFX_DIR = "graphics/pokedex_gen2"
OUTPUT_H = "src/data/graphics/pokedex_gen2_sprites.h"

# 1. Parse species list from species.h
# We only care about species from SPECIES_BULBASAUR to SPECIES_CELEBI (inclusive)
species_list = []
with open(SPECIES_H, "r", encoding="utf-8") as f:
    content = f.read()

# Find the Species enum
enum_match = re.search(r"enum\s+__attribute__\(\(packed\)\)\s+Species\s*\{(.*?)\};", content, re.DOTALL)
if not enum_match:
    print("Could not find Species enum in species.h")
    exit(1)

enum_content = enum_match.group(1)

# Find all species enums and their integer values
matches = re.findall(r"\s*(SPECIES_[A-Z0-9_]+)\s*=\s*([0-9]+)\s*,", enum_content)
species_map = {}
for name, val_str in matches:
    val = int(val_str)
    if 1 <= val <= 251:
        species_map[name] = val
        species_list.append((name, val))

# Sort by species value
species_list.sort(key=lambda x: x[1])

# 2. Parse families files to map each species to its family macro
species_to_family = {}
def parse_families(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        lines = f.readlines()
    
    current_family = None
    if_stack = []
    
    for line in lines:
        # Check for family macro
        m_if = re.match(r"^\s*#\s*if\s+(P_FAMILY_[A-Z0-9_]+)", line)
        m_elif = re.match(r"^\s*#\s*elif\s+(P_FAMILY_[A-Z0-9_]+)", line)
        m_else = re.match(r"^\s*#\s*else", line)
        m_endif = re.match(r"^\s*#\s*endif", line)
        
        if m_if:
            current_family = m_if.group(1)
            if_stack.append(current_family)
        elif m_elif:
            if if_stack:
                if_stack.pop()
            current_family = m_elif.group(1)
            if_stack.append(current_family)
        elif m_else:
            pass
        elif m_endif:
            if if_stack:
                if_stack.pop()
            current_family = if_stack[-1] if if_stack else None
            
        # Check for species definition
        m_spec = re.search(r"\[(SPECIES_[A-Z0-9_]+)\]\s*=", line)
        if m_spec:
            spec_name = m_spec.group(1)
            if spec_name in species_map:
                species_to_family[spec_name] = current_family

parse_families(GEN1_FAMILIES)
parse_families(GEN2_FAMILIES)

# If any species didn't get a family, default to its own name
for name, val in species_list:
    if name not in species_to_family or species_to_family[name] is None:
        species_to_family[name] = f"P_FAMILY_{name.replace('SPECIES_', '')}"

# 3. Create pokedex_gen2 directories and copy placeholders
os.makedirs(GEN2_GFX_DIR, exist_ok=True)

for name, val in species_list:
    folder_name = name.replace("SPECIES_", "").lower()
    src_dir = os.path.join(POKEMON_GFX_DIR, folder_name)
    dst_dir = os.path.join(GEN2_GFX_DIR, folder_name)
    os.makedirs(dst_dir, exist_ok=True)
    
    # Files to copy:
    # 1. Front Pic (anim_front_gba.png or anim_front.png)
    # 2. Normal Palette (normal_gba.pal or normal.pal)
    # 3. Shiny Palette (shiny_gba.pal or shiny.pal)
    
    front_copied = False
    for filename in ["anim_front_gba.png", "anim_front.png", "front.png"]:
        src_path = os.path.join(src_dir, filename)
        if os.path.exists(src_path):
            shutil.copy(src_path, os.path.join(dst_dir, "front.png"))
            front_copied = True
            break
            
    if not front_copied:
        print(f"Warning: No front pic found for {folder_name}")
        
    pal_copied = False
    for filename in ["normal_gba.pal", "normal.pal"]:
        src_path = os.path.join(src_dir, filename)
        if os.path.exists(src_path):
            shutil.copy(src_path, os.path.join(dst_dir, "normal.pal"))
            pal_copied = True
            break
            
    if not pal_copied:
        print(f"Warning: No normal palette found for {folder_name}")
        
    shiny_copied = False
    for filename in ["shiny_gba.pal", "shiny.pal"]:
        src_path = os.path.join(src_dir, filename)
        if os.path.exists(src_path):
            shutil.copy(src_path, os.path.join(dst_dir, "shiny.pal"))
            shiny_copied = True
            break
            
    if not shiny_copied:
        print(f"Warning: No shiny palette found for {folder_name}")

# Helper to format title case properly for C identifiers
def to_c_title(name):
    # E.g. SPECIES_NIDORAN_F -> NidoranF
    parts = name.replace("SPECIES_", "").split("_")
    return "".join(part.capitalize() for part in parts)

# 4. Generate src/data/graphics/pokedex_gen2_sprites.h
os.makedirs(os.path.dirname(OUTPUT_H), exist_ok=True)
with open(OUTPUT_H, "w", encoding="utf-8") as f:
    f.write("// Auto-generated file. Do not edit directly.\n\n")
    
    # Write INCBIN statements for each species wrapped in its family macro
    for name, val in species_list:
        folder_name = name.replace("SPECIES_", "").lower()
        family = species_to_family[name]
        c_title = to_c_title(name)
        
        f.write(f"#if {family}\n")
        f.write(f"const u32 gPokedexGen2FrontPic_{c_title}[] = INCBIN_U32(\"{GEN2_GFX_DIR}/{folder_name}/front.4bpp.smol\");\n")
        f.write(f"const u16 gPokedexGen2Palette_{c_title}[] = INCBIN_U16(\"{GEN2_GFX_DIR}/{folder_name}/normal.gbapal\");\n")
        f.write(f"const u16 gPokedexGen2ShinyPalette_{c_title}[] = INCBIN_U16(\"{GEN2_GFX_DIR}/{folder_name}/shiny.gbapal\");\n")
        f.write(f"#endif // {family}\n\n")
        
    # Write lookup tables
    f.write("\n// Lookup Tables\n")
    
    f.write("const u32 *const gPokedexGen2FrontPics[NUM_SPECIES] = {\n")
    for name, val in species_list:
        family = species_to_family[name]
        c_title = to_c_title(name)
        f.write(f"#if {family}\n")
        f.write(f"    [{name}] = gPokedexGen2FrontPic_{c_title},\n")
        f.write(f"#endif\n")
    f.write("};\n\n")
    
    f.write("const u16 *const gPokedexGen2Palettes[NUM_SPECIES] = {\n")
    for name, val in species_list:
        family = species_to_family[name]
        c_title = to_c_title(name)
        f.write(f"#if {family}\n")
        f.write(f"    [{name}] = gPokedexGen2Palette_{c_title},\n")
        f.write(f"#endif\n")
    f.write("};\n\n")
    
    f.write("const u16 *const gPokedexGen2ShinyPalettes[NUM_SPECIES] = {\n")
    for name, val in species_list:
        family = species_to_family[name]
        c_title = to_c_title(name)
        f.write(f"#if {family}\n")
        f.write(f"    [{name}] = gPokedexGen2ShinyPalette_{c_title},\n")
        f.write(f"#endif\n")
    f.write("};\n")

print(f"Generated {OUTPUT_H} and directories successfully.")
