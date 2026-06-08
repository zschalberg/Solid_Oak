# Define color mapping for standard Kanto pokedex
mapping = {
    # Whites/Creams/Grays to Parchment/Sepia
    (255, 255, 255): (248, 244, 228),
    (246, 246, 238): (240, 232, 212),
    (238, 246, 246): (240, 232, 212),
    (255, 246, 238): (248, 240, 220),
    (238, 238, 230): (232, 220, 195),
    (230, 222, 197): (225, 212, 182),
    (213, 213, 213): (130, 95, 60),
    (213, 213, 205): (130, 95, 60),
    (156, 156, 156): (90, 56, 24),
    (98, 98, 98):    (64, 32, 8),

    # Gold/Tan Highlights
    (213, 197, 164): (215, 198, 165),
    (197, 180, 139): (205, 188, 150),
    (164, 148, 98):  (160, 130, 50),
    (123, 98, 57):   (135, 110, 45),
    (255, 255, 0):   (215, 185, 75),

    # Red/Orange casing (The plastic housing) to Tan/Brown Leathers & Brass
    (205, 65, 57):   (144, 80, 32),
    (230, 8, 8):     (120, 60, 24),
    (255, 139, 57):  (180, 135, 30),
    (255, 189, 115): (210, 165, 110),

    # Other Interface Details (greens, blues to sage/browns)
    (32, 156, 8):    (48, 72, 48),
    (148, 246, 148): (150, 180, 140),
    (49, 82, 205):   (96, 64, 36),
    (164, 197, 246): (190, 140, 90),
    (172, 197, 24):  (140, 150, 100),
}

pal_files = ['graphics/pokedex/kanto_dex_bgpals.pal', 'graphics/pokedex/national_dex_bgpals.pal']

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
                new_lines.append(line)
        else:
            new_lines.append(line)
            
    if changed:
        with open(pal, 'w') as f:
            f.writelines(new_lines)
        print(f"  Updated colors in {pal}")
    else:
        print(f"  No changes for {pal}")

print("Done.")
