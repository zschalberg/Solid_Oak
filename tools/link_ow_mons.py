#!/usr/bin/env python3
import json
import re
import sys
import argparse
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

def load_valid_species():
    species_h = REPO_ROOT / "include" / "constants" / "species.h"
    valid = set()
    if species_h.exists():
        with open(species_h, "r", encoding="utf-8") as f:
            for line in f:
                m = re.search(r"\bSPECIES_([A-Za-z0-9_]+)\b", line)
                if m:
                    valid.add(m.group(1))
    return valid

def normalize_species_name(name, valid_species):
    cleaned = name.upper().strip()
    # Normalize common Showdown/party naming conventions to C constants
    cleaned = cleaned.replace(" ", "_").replace(".", "").replace("'", "").replace("-", "_")
    
    # Specific known fixes if any
    if cleaned in valid_species:
        return cleaned
    if cleaned == "NIDORAN_M" and "NIDORAN_M" in valid_species:
        return "NIDORAN_M"
    if cleaned == "NIDORAN_F" and "NIDORAN_F" in valid_species:
        return "NIDORAN_F"
    if cleaned == "MR_MIME" and "MR_MIME" in valid_species:
        return "MR_MIME"
    if cleaned == "HO_OH" and "HO_OH" in valid_species:
        return "HO_OH"
    if cleaned == "PORYGON_Z" and "PORYGON_Z" in valid_species:
        return "PORYGON_Z"
    
    # Try finding exact match in valid_species case-insensitively
    for v in valid_species:
        if v.upper() == cleaned:
            return v
    return cleaned

def parse_trainers_party(valid_species):
    party_path = REPO_ROOT / "src" / "data" / "trainers.party"
    trainer_parties = {}
    current_trainer = None
    
    with open(party_path, "r", encoding="utf-8") as f:
        lines = f.readlines()
        
    for line in lines:
        line_str = line.strip()
        m_header = re.match(r"^===\s*([A-Za-z0-9_]+)\s*===$", line_str)
        if m_header:
            current_trainer = m_header.group(1)
            trainer_parties[current_trainer] = []
            continue
            
        if not current_trainer:
            continue
        if line_str == "":
            continue
        if line_str.startswith("/*") or line_str.startswith("//") or line_str.endswith("*/"):
            continue
        if any(line_str.startswith(k) for k in [
            "Name:", "Class:", "Pic:", "Gender:", "Music:", "Items:", "Double Battle:", 
            "Battle Type:", "AI:", "Mugshot:", "Tags:", "Level:", "IVs:", "EVs:", 
            "Ability:", "Shiny:", "Ball:", "Friendship:", "Nature:", "Dynamax Level:", 
            "Gigantamax Factor:", "Tera Type:"
        ]):
            continue
        if line_str.startswith("- "): # move line
            continue
            
        # If we got here, this line is a Pokémon species!
        # Could be "Species" or "Species @ Item" or "Nickname (Species)"
        mon_line = line_str
        if "@" in mon_line:
            mon_line = mon_line.split("@")[0].strip()
        m_nick = re.match(r".*\((.+)\)", mon_line)
        if m_nick:
            mon_line = m_nick.group(1).strip()
            
        norm_species = normalize_species_name(mon_line, valid_species)
        trainer_parties[current_trainer].append(norm_species)
        
    return trainer_parties

def parse_script_to_trainer():
    mapping = {}
    trainers_inc = REPO_ROOT / "data" / "scripts" / "trainers.inc"
    if trainers_inc.exists():
        current_script = None
        with open(trainers_inc, "r", encoding="utf-8") as f:
            for line in f:
                m_label = re.match(r"^([A-Za-z0-9_]+)::", line)
                if m_label:
                    current_script = m_label.group(1)
                m_tb = re.search(r"trainerbattle_\w+\s+([A-Za-z0-9_]+)", line)
                if m_tb and current_script:
                    mapping[current_script] = m_tb.group(1)
                    
    maps_dir = REPO_ROOT / "data" / "maps"
    for map_dir in maps_dir.iterdir():
        if not map_dir.is_dir():
            continue
        for sf in ["scripts.inc", "scripts.pory"]:
            sp = map_dir / sf
            if sp.exists():
                current_script = None
                with open(sp, "r", encoding="utf-8", errors="ignore") as f:
                    for line in f:
                        m_label = re.match(r"^(?:script\s+|)([A-Za-z0-9_]+)(?:::|\s*\{)", line)
                        if m_label:
                            current_script = m_label.group(1)
                        m_tb = re.search(r"trainerbattle_\w+\s*(?:\(|\s+)([A-Za-z0-9_]+)", line)
                        if m_tb and current_script:
                            t_val = m_tb.group(1)
                            if t_val.startswith("TRAINER_"):
                                mapping[current_script] = t_val
    return mapping

def is_ow_mon_candidate(obj):
    gfx = obj.get("graphics_id", "")
    script = obj.get("script", "")
    if gfx == "OBJ_EVENT_GFX_OW_MON":
        return True
    if script == "EventScript_OverworldTrainerMon":
        return True
    if gfx.startswith("OBJ_EVENT_GFX_SPECIES"):
        return True
    if gfx in ["OBJ_EVENT_GFX_PIDGEY", "OBJ_EVENT_GFX_ZIGZAGOON_2", "OBJ_EVENT_GFX_TENTACOOL_SWIMMING"]:
        return True
    return False

def is_trainer_candidate(obj):
    ttype = obj.get("trainer_type", "TRAINER_TYPE_NONE")
    script = obj.get("script", "NULL")
    if ttype != "TRAINER_TYPE_NONE":
        return True
    if "EventScript" in script and "Item" not in script and "Sign" not in script and "Tree" not in script:
        return True
    return False

def process_map(map_path, script_to_trainer, trainer_parties, valid_species, apply_changes=False):
    with open(map_path, "r", encoding="utf-8") as f:
        data = json.load(f)
        
    map_id = data.get("id", map_path.parent.name)
    objs = data.get("object_events", [])
    
    # 1. Identify trainers and pokemon candidates
    trainers = []
    pokemon_objs = []
    
    for idx, obj in enumerate(objs):
        if is_ow_mon_candidate(obj):
            pokemon_objs.append((idx, obj))
        elif is_trainer_candidate(obj):
            trainers.append((idx, obj))
            
    if not pokemon_objs or not trainers:
        return []
        
    # Spatial pairing: for each pokemon, find closest trainer
    # Group pairs by trainer to correctly handle double battles / multiple mons
    trainer_to_paired_mons = {t_idx: [] for t_idx, _ in trainers}
    unpaired_mons = []
    
    for p_idx, p_obj in pokemon_objs:
        px, py = p_obj.get("x", 0), p_obj.get("y", 0)
        best_t_idx = None
        best_dist = 999
        
        for t_idx, t_obj in trainers:
            tx, ty = t_obj.get("x", 0), t_obj.get("y", 0)
            dist = abs(px - tx) + abs(py - ty)
            if dist <= 2 and dist < best_dist:
                best_dist = dist
                best_t_idx = t_idx
                
        if best_t_idx is not None:
            trainer_to_paired_mons[best_t_idx].append((p_idx, p_obj, best_dist))
        else:
            unpaired_mons.append((p_idx, p_obj))
            
    # For twin trainers sharing the same trainer ID on the same map (e.g. Eli & Anne, Kiri & Jan),
    # link them together so twin 1 gets mon 0 and twin 2 gets mon 1
    shared_trainer_map = {}
    for t_idx, t_obj in trainers:
        sc = t_obj.get("script", "")
        tid = script_to_trainer.get(sc)
        if tid:
            shared_trainer_map.setdefault(tid, []).append(t_idx)
            
    trainer_party_slot_override = {}
    for tid, t_indices in shared_trainer_map.items():
        if len(t_indices) > 1:
            # Sort twin trainers deterministically by coordinates (x, y)
            t_indices.sort(key=lambda idx: (objs[idx].get("x", 0), objs[idx].get("y", 0)))
            for slot, t_idx in enumerate(t_indices):
                trainer_party_slot_override[t_idx] = slot
                
    changes = []
    
    for t_idx, t_obj in trainers:
        paired = trainer_to_paired_mons[t_idx]
        if not paired:
            continue
            
        t_script = t_obj.get("script", "")
        t_id = script_to_trainer.get(t_script)
        party = trainer_parties.get(t_id, [])
        
        # Sort paired mons by coordinates
        paired.sort(key=lambda item: (item[1].get("x", 0), item[1].get("y", 0)))
        
        start_slot = trainer_party_slot_override.get(t_idx, 0)
        
        for mon_offset, (p_idx, p_obj, dist) in enumerate(paired):
            slot = start_slot + mon_offset
            if slot < len(party):
                target_species = party[slot]
            elif party:
                target_species = party[0] # Fallback to lead mon if party is smaller
            else:
                target_species = None
                
            old_gfx = p_obj.get("graphics_id", "")
            old_elev = p_obj.get("elevation", 0)
            old_script = p_obj.get("script", "")
            
            target_gfx = f"OBJ_EVENT_GFX_SPECIES({target_species})" if target_species else old_gfx
            target_elev = t_obj.get("elevation", old_elev)
            target_script = "EventScript_OverworldTrainerMon"
            
            modified = (old_gfx != target_gfx or old_elev != target_elev or old_script != target_script)
            
            changes.append({
                "map": map_id,
                "map_path": map_path,
                "mon_idx": p_idx,
                "mon_pos": (p_obj.get("x", 0), p_obj.get("y", 0)),
                "trainer_idx": t_idx,
                "trainer_pos": (t_obj.get("x", 0), t_obj.get("y", 0)),
                "trainer_script": t_script,
                "trainer_id": t_id,
                "slot": slot,
                "target_species": target_species,
                "old_gfx": old_gfx,
                "new_gfx": target_gfx,
                "old_elev": old_elev,
                "new_elev": target_elev,
                "old_script": old_script,
                "new_script": target_script,
                "modified": modified
            })
            
            if apply_changes and target_species:
                p_obj["graphics_id"] = target_gfx
                p_obj["elevation"] = target_elev
                p_obj["script"] = target_script
                
    if apply_changes and any(c["modified"] for c in changes):
        with open(map_path, "w", encoding="utf-8") as f:
            json.dump(data, f, indent=2)
            f.write("\n")
            
    return changes

def main():
    parser = argparse.ArgumentParser(description="Link overworld Pokemon to adjacent trainers lead Pokemon")
    parser.add_argument("--apply", action="store_true", help="Apply changes in-place to map.json files")
    parser.add_argument("--maps", nargs="*", help="Specific map names/folders to process (default: all target routes)")
    args = parser.parse_args()
    
    valid_species = load_valid_species()
    trainer_parties = parse_trainers_party(valid_species)
    script_to_trainer = parse_script_to_trainer()
    
    if args.maps:
        target_map_names = args.maps
    else:
        target_map_names = [
            "Route6", "Route8", "Route11", "Route12", "Route13", "Route14", "Route15",
            "HauntedWoods", "Lavender_Cemetary_Map", "VermilionCity_Dojo"
        ]
        
    all_changes = []
    
    for map_name in target_map_names:
        mpath = REPO_ROOT / "data" / "maps" / map_name / "map.json"
        if not mpath.exists():
            continue
        changes = process_map(mpath, script_to_trainer, trainer_parties, valid_species, apply_changes=args.apply)
        all_changes.extend(changes)
        
    print(f"\n{'='*95}")
    print(f"{'OVERWORLD POKÉMON LINKING REPORT':^95}")
    print(f"{'Mode: ' + ('APPLY CHANGES' if args.apply else 'DRY RUN (Preview Only)'):^95}")
    print(f"{'='*95}")
    
    current_map = None
    for c in all_changes:
        if c["map"] != current_map:
            current_map = c["map"]
            print(f"\n--- {current_map} ---")
            print(f"{'Mon Pos':<10} | {'Trainer & Script':<36} | {'Slot':<4} | {'Old GFX':<24} -> {'New GFX'}")
            print(f"{'-'*10}-+-{'-'*36}-+-{'-'*4}-+-{'-'*24}----+{'-'*25}")
            
        mpos = f"({c['mon_pos'][0]}, {c['mon_pos'][1]})"
        t_info = f"{c['trainer_script']} ({c['trainer_id']})"
        if len(t_info) > 36:
            t_info = t_info[:33] + "..."
        slot_str = f"#{c['slot'] + 1}"
        old_g = c['old_gfx']
        if len(old_g) > 24:
            old_g = old_g[:21] + "..."
        print(f"{mpos:<10} | {t_info:<36} | {slot_str:<4} | {old_g:<24} -> {c['new_gfx']}")
        
    print(f"\n{'='*95}")
    total_mods = sum(1 for c in all_changes if c["modified"])
    print(f"Total overworld Pokémon processed: {len(all_changes)} (Modified: {total_mods})")
    if not args.apply:
        print("Note: Run with --apply to write these changes to map.json files.")
    print(f"{'='*95}\n")

if __name__ == "__main__":
    main()
