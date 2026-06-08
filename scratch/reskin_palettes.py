import glob
import os

# Define complete color mapping (r, g, b) -> (new_r, new_g, new_b)
mapping = {
    # Whites/Grays to Parchment/Cream/Sepia
    (255, 255, 255): (250, 246, 230),
    (249, 249, 249): (245, 238, 215),
    (225, 225, 225): (238, 226, 195),
    (201, 201, 201): (225, 210, 175),
    (189, 189, 189): (220, 206, 172),
    (172, 172, 172): (210, 195, 160),
    (169, 169, 169): (205, 188, 150),
    (164, 164, 164): (200, 182, 145),
    (129, 129, 129): (165, 145, 110),
    (106, 106, 106): (135, 115, 80),
    (98, 98, 115): (140, 100, 65),
    (57, 57, 57): (72, 60, 48),
    (37, 37, 37): (48, 38, 30),
    (32, 32, 32): (40, 32, 24),

    # Reds to Tan/Brown Leathers
    (249, 153, 161): (215, 150, 95),
    (233, 49, 49): (160, 96, 48),
    (255, 32, 32): (160, 96, 48),
    (197, 32, 32): (144, 80, 32),
    (193, 33, 41): (120, 72, 32),
    (145, 17, 33): (80, 40, 16),
    (131, 32, 32): (96, 48, 16),
    (16, 0, 0): (24, 12, 6),
    (74, 32, 32): (56, 36, 20),

    # Blues to Dark Leathers/Wood
    (180, 205, 246): (190, 140, 90),
    (49, 139, 255): (144, 80, 32),
    (52, 66, 162): (96, 64, 36),
    (41, 57, 65): (64, 48, 32),
    (41, 57, 106): (48, 32, 16),
    (0, 0, 41): (32, 16, 8),

    # Golds/Yellows/Olives to Brass/Bronze
    (238, 246, 57): (205, 175, 60),
    (255, 172, 0): (180, 135, 30),
    (194, 181, 66): (165, 130, 50),
    (189, 156, 90): (150, 115, 40),
    (180, 106, 0): (130, 95, 20),
    (123, 115, 74): (115, 96, 64),

    # Greens to Sage/Moss Nature tones
    (141, 251, 184): (150, 180, 140),
    (156, 230, 0): (160, 150, 110),
    (82, 189, 90): (90, 120, 90),
    (49, 213, 74): (80, 110, 80),
    (24, 131, 32): (48, 72, 48),
    (57, 115, 0): (64, 80, 48),
    (41, 115, 0): (56, 72, 40),
    (32, 49, 32): (36, 44, 36),
}

# Find all palette files
pal_files = glob.glob('graphics/pokedex/hgss/*.pal')

modified_count = 0

for pal in pal_files:
    print(f"Processing {pal}...")
    with open(pal, 'r') as f:
        lines = f.readlines()
    
    new_lines = []
    # Keep header
    new_lines.append(lines[0])
    new_lines.append(lines[1])
    new_lines.append(lines[2])
    
    changed = False
    for line in lines[3:]:
        parts = line.strip().split()
        if len(parts) == 3:
            r, g, b = map(int, parts)
            orig_color = (r, g, b)
            if orig_color in mapping:
                new_color = mapping[orig_color]
                new_lines.append(f"{new_color[0]} {new_color[1]} {new_color[2]}\n")
                if new_color != orig_color:
                    changed = True
            else:
                # Keep original color if not in mapping
                new_lines.append(line)
        else:
            new_lines.append(line)
            
    if changed:
        with open(pal, 'w') as f:
            f.writelines(new_lines)
        print(f"  Updated colors in {pal}")
        modified_count += 1
    else:
        print(f"  No changes for {pal}")

print(f"Successfully processed all files. Modified {modified_count} files.")
