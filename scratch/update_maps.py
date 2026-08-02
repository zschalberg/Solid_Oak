import os

def update_maps():
    updated_count = 0
    for root, dirs, files in os.walk('data/maps'):
        for f in files:
            if f == 'map.json' and 'ssanne_' in root.lower():
                path = os.path.join(root, f)
                with open(path, 'r', encoding='utf-8') as file:
                    content = file.read()
                
                # Check for target music definition
                target_str = '"music": "MUS_SS_ANNE"'
                replacement_str = '"music": "MUS_SEA_SHANTY_2"'
                if target_str in content:
                    new_content = content.replace(target_str, replacement_str)
                    with open(path, 'w', encoding='utf-8') as file:
                        file.write(new_content)
                    print(f"Updated: {path}")
                    updated_count += 1
    print(f"Total maps updated: {updated_count}")

if __name__ == '__main__':
    update_maps()
