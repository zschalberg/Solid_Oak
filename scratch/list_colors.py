import glob

pal_files = glob.glob('graphics/pokedex/hgss/*.pal')
unique_colors = set()

for pal in pal_files:
    with open(pal, 'r') as f:
        lines = f.readlines()
    # Skip first 3 lines (header)
    for line in lines[3:]:
        parts = line.strip().split()
        if len(parts) == 3:
            r, g, b = map(int, parts)
            unique_colors.add((r, g, b))

print(f"Total unique colors: {len(unique_colors)}")
for c in sorted(unique_colors):
    print(c)
