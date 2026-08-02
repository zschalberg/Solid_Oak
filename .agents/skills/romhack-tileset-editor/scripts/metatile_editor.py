#!/usr/bin/env python3
import os
import sys
import struct
import json
import re
import hashlib

DEFAULT_BEHAVIOR_H = "include/constants/metatile_behaviors.h"

def parse_behaviors(header_path):
    """
    Parses include/constants/metatile_behaviors.h to map integer values to MB_* strings.
    """
    if not os.path.exists(header_path):
        return {}
    
    with open(header_path, "r", encoding="utf-8") as f:
        content = f.read()
        
    enum_match = re.search(r"enum\s+MetatileBehavior\s*\{(.*?)\};", content, re.DOTALL)
    if not enum_match:
        return {}
        
    enum_body = enum_match.group(1)
    # Strip comments
    enum_body = re.sub(r"//.*", "", enum_body)
    enum_body = re.sub(r"/\*.*?\*/", "", enum_body, flags=re.DOTALL)
    
    behaviors_list = []
    for token in enum_body.split(","):
        token = token.strip()
        if not token:
            continue
        name_match = re.match(r"^([A-Z0-9_]+)", token)
        if name_match:
            behaviors_list.append(name_match.group(1))
            
    # Create bidirectional maps
    int_to_str = {i: name for i, name in enumerate(behaviors_list)}
    str_to_int = {name: i for i, name in enumerate(behaviors_list)}
    return {"to_str": int_to_str, "to_int": str_to_int}

def decode_tile_slot(value):
    return {
        "tile_id": value & 0x03FF,
        "x_flip": (value >> 10) & 1,
        "y_flip": (value >> 11) & 1,
        "palette": (value >> 12) & 0x0F
    }

def encode_tile_slot(slot):
    tile_id = slot.get("tile_id", 0) & 0x03FF
    x_flip = int(slot.get("x_flip", 0)) & 1
    y_flip = int(slot.get("y_flip", 0)) & 1
    palette = int(slot.get("palette", 0)) & 0x0F
    return tile_id | (x_flip << 10) | (y_flip << 11) | (palette << 12)

def read_metatiles(metatiles_path):
    if not os.path.exists(metatiles_path):
        print(f"Error: {metatiles_path} does not exist", file=sys.stderr)
        sys.exit(1)
    with open(metatiles_path, "rb") as f:
        data = f.read()
    
    # 16 bytes per metatile
    num_metatiles = len(data) // 16
    metatiles = []
    for i in range(num_metatiles):
        offset = i * 16
        slots = struct.unpack("<8H", data[offset:offset+16])
        metatiles.append([decode_tile_slot(s) for s in slots])
    return metatiles

def write_metatiles(metatiles_path, metatiles):
    buffer = bytearray()
    for m in metatiles:
        packed = [encode_tile_slot(slot) for slot in m]
        buffer.extend(struct.pack("<8H", *packed))
    with open(metatiles_path, "wb") as f:
        f.write(buffer)

def read_attributes(attrs_path):
    if not os.path.exists(attrs_path):
        print(f"Error: {attrs_path} does not exist", file=sys.stderr)
        sys.exit(1)
    with open(attrs_path, "rb") as f:
        data = f.read()
    
    num_metatiles = len(data) // 4
    attrs = []
    for i in range(num_metatiles):
        offset = i * 4
        val = struct.unpack("<I", data[offset:offset+4])[0]
        attrs.append(val)
    return attrs

def write_attributes(attrs_path, attrs):
    buffer = bytearray()
    for val in attrs:
        buffer.extend(struct.pack("<I", val))
    with open(attrs_path, "wb") as f:
        f.write(buffer)

def print_metatile(idx, slots, attr_val, behaviors_map):
    behavior_int = attr_val & 0xFFFF
    other_val = attr_val >> 16
    behavior_str = behaviors_map.get("to_str", {}).get(behavior_int, f"0x{behavior_int:04X}")
    
    print(f"Metatile {idx} (0x{idx:03X}):")
    print(f"  Behavior: {behavior_str} (0x{behavior_int:04X}) | Other Attributes: 0x{other_val:04X}")
    
    layers = ["Bottom (BG)", "Top (FG)"]
    positions = ["Top-Left ", "Top-Right", "Bot-Left ", "Bot-Right"]
    
    for l_idx, layer_name in enumerate(layers):
        print(f"  {layer_name} Layer:")
        for pos_idx, pos_name in enumerate(positions):
            slot_idx = l_idx * 4 + pos_idx
            slot = slots[slot_idx]
            flips = []
            if slot["x_flip"]: flips.append("X")
            if slot["y_flip"]: flips.append("Y")
            flip_str = f" [flip {'/'.join(flips)}]" if flips else ""
            print(f"    {pos_name}: Tile={slot['tile_id']:3d}, Palette={slot['palette']:2d}{flip_str}")

def main():
    if len(sys.argv) < 2:
        print("Usage: metatile_editor.py <command> [args...]")
        print("Commands:")
        print("  parse <metatiles.bin> <attributes.bin> [--index N]")
        print("  write-behavior <attributes.bin> <index> <behavior_constant_or_int>")
        print("  write-metatile <metatiles.bin> <index> <json_slots>")
        print("  test-roundtrip <metatiles.bin> <attributes.bin>")
        sys.exit(1)
        
    cmd = sys.argv[1]
    
    # Load behavior mappings
    behaviors = parse_behaviors(DEFAULT_BEHAVIOR_H)
    
    if cmd == "parse":
        if len(sys.argv) < 4:
            print("Usage: metatile_editor.py parse <metatiles.bin> <attributes.bin> [--index N]")
            sys.exit(1)
        metatiles_path = sys.argv[2]
        attrs_path = sys.argv[3]
        
        metatiles = read_metatiles(metatiles_path)
        attrs = read_attributes(attrs_path)
        
        target_idx = None
        if "--index" in sys.argv:
            idx_pos = sys.argv.index("--index") + 1
            if idx_pos < len(sys.argv):
                try:
                    val_str = sys.argv[idx_pos]
                    target_idx = int(val_str, 0) # Support hex and decimal
                except ValueError:
                    print(f"Error: Invalid index '{sys.argv[idx_pos]}'", file=sys.stderr)
                    sys.exit(1)
                    
        if target_idx is not None:
            if target_idx < 0 or target_idx >= len(metatiles):
                print(f"Error: Metatile index {target_idx} out of range (0 to {len(metatiles)-1})", file=sys.stderr)
                sys.exit(1)
            print_metatile(target_idx, metatiles[target_idx], attrs[target_idx], behaviors)
        else:
            for idx in range(len(metatiles)):
                print_metatile(idx, metatiles[idx], attrs[idx], behaviors)
                print("-" * 50)
                
    elif cmd == "write-behavior":
        if len(sys.argv) < 5:
            print("Usage: metatile_editor.py write-behavior <attributes.bin> <index> <behavior_constant_or_int>")
            sys.exit(1)
        attrs_path = sys.argv[2]
        try:
            target_idx = int(sys.argv[3], 0)
        except ValueError:
            print(f"Error: Invalid index '{sys.argv[3]}'", file=sys.stderr)
            sys.exit(1)
            
        behav_arg = sys.argv[4]
        behavior_val = None
        
        # Check map
        if behav_arg in behaviors.get("to_int", {}):
            behavior_val = behaviors["to_int"][behav_arg]
        else:
            try:
                behavior_val = int(behav_arg, 0)
            except ValueError:
                print(f"Error: Unknown behavior constant or integer value '{behav_arg}'", file=sys.stderr)
                sys.exit(1)
                
        attrs = read_attributes(attrs_path)
        if target_idx < 0 or target_idx >= len(attrs):
            print(f"Error: Index {target_idx} out of range (0 to {len(attrs)-1})", file=sys.stderr)
            sys.exit(1)
            
        old_val = attrs[target_idx]
        new_val = (old_val & 0xFFFF0000) | (behavior_val & 0xFFFF)
        attrs[target_idx] = new_val
        
        write_attributes(attrs_path, attrs)
        print(f"Successfully updated metatile {target_idx} behavior to {behav_arg} (0x{behavior_val:04X}).")
        
    elif cmd == "write-metatile":
        if len(sys.argv) < 5:
            print("Usage: metatile_editor.py write-metatile <metatiles.bin> <index> <json_slots>")
            print("JSON Format: An array of 8 objects, each containing: tile_id, x_flip, y_flip, palette")
            sys.exit(1)
            
        metatiles_path = sys.argv[2]
        try:
            target_idx = int(sys.argv[3], 0)
        except ValueError:
            print(f"Error: Invalid index '{sys.argv[3]}'", file=sys.stderr)
            sys.exit(1)
            
        try:
            json_slots = json.loads(sys.argv[4])
        except json.JSONDecodeError as e:
            print(f"Error parsing JSON: {e}", file=sys.stderr)
            sys.exit(1)
            
        if not isinstance(json_slots, list) or len(json_slots) != 8:
            print("Error: JSON must be a list containing exactly 8 tile slot objects.", file=sys.stderr)
            sys.exit(1)
            
        metatiles = read_metatiles(metatiles_path)
        if target_idx < 0 or target_idx >= len(metatiles):
            print(f"Error: Index {target_idx} out of range (0 to {len(metatiles)-1})", file=sys.stderr)
            sys.exit(1)
            
        # Parse and override slots
        for i, s in enumerate(json_slots):
            metatiles[target_idx][i] = {
                "tile_id": s.get("tile_id", 0),
                "x_flip": s.get("x_flip", 0),
                "y_flip": s.get("y_flip", 0),
                "palette": s.get("palette", 0)
            }
            
        write_metatiles(metatiles_path, metatiles)
        print(f"Successfully updated metatile {target_idx} tile layouts.")
        
    elif cmd == "test-roundtrip":
        if len(sys.argv) < 4:
            print("Usage: metatile_editor.py test-roundtrip <metatiles.bin> <attributes.bin>")
            sys.exit(1)
        metatiles_path = sys.argv[2]
        attrs_path = sys.argv[3]
        
        # Read files
        with open(metatiles_path, "rb") as f:
            orig_metatiles_data = f.read()
        with open(attrs_path, "rb") as f:
            orig_attrs_data = f.read()
            
        orig_metatiles_hash = hashlib.sha256(orig_metatiles_data).hexdigest()
        orig_attrs_hash = hashlib.sha256(orig_attrs_data).hexdigest()
        
        # Parse
        metatiles = read_metatiles(metatiles_path)
        attrs = read_attributes(attrs_path)
        
        # Write to temporary files
        temp_metatiles = metatiles_path + ".tmp"
        temp_attrs = attrs_path + ".tmp"
        
        try:
            write_metatiles(temp_metatiles, metatiles)
            write_attributes(temp_attrs, attrs)
            
            with open(temp_metatiles, "rb") as f:
                new_metatiles_data = f.read()
            with open(temp_attrs, "rb") as f:
                new_attrs_data = f.read()
                
            new_metatiles_hash = hashlib.sha256(new_metatiles_data).hexdigest()
            new_attrs_hash = hashlib.sha256(new_attrs_data).hexdigest()
            
            assert orig_metatiles_hash == new_metatiles_hash, "Metatiles hashes do not match!"
            assert orig_attrs_hash == new_attrs_hash, "Attributes hashes do not match!"
            
            print("Round-trip validation: SUCCESS. Hashes are bit-by-bit identical!")
            
        finally:
            if os.path.exists(temp_metatiles):
                os.remove(temp_metatiles)
            if os.path.exists(temp_attrs):
                os.remove(temp_attrs)
    else:
        print(f"Unknown command '{cmd}'", file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()
