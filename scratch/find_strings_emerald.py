with open('src/pokedex_emerald.c', 'r', encoding='utf-8') as f:
    lines = f.readlines()

out_lines = []
for i, line in enumerate(lines):
    if '_("' in line or 'gText_' in line:
        out_lines.append(f"{i+1}: {line.strip()}\n")

with open('scratch/found_strings_emerald.txt', 'w', encoding='utf-8') as out_f:
    out_f.writelines(out_lines)

print(f"Done. Found {len(out_lines)} lines.")
