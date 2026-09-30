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
    cleaned = cleaned.replace(" ", "_").replace(".", "").replace("'", "").replace("-", "_")
    if cleaned in valid_species:
        return cleaned
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
        if line_str.startswith("- "):
            continue
            
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

BACKUP_FILE = REPO_ROOT / "data" / "inactive_trainers_backup.json"

def cleanup_trainers(apply_changes=False):
    valid_species = load_valid_species()
    parties = parse_trainers_party(valid_species)
    script_to_trainer = parse_script_to_trainer()
    
    maps_dir = REPO_ROOT / "data" / "maps"
    modified_maps = {}
    backup_records = []
    
    # Load existing backup if present
    existing_backup = {}
    if BACKUP_FILE.exists():
        try:
            with open(BACKUP_FILE, "r", encoding="utf-8") as f:
                for entry in json.load(f):
                    key = (entry["map"], entry["object_idx"])
                    existing_backup[key] = entry
        except Exception:
            pass
            
    for mdir in sorted(maps_dir.iterdir()):
        mpath = mdir / "map.json"
        if not mpath.exists():
            continue
        try:
            with open(mpath, "r", encoding="utf-8") as f:
                data = json.load(f)
        except Exception:
            continue
            
        objs = data.get("object_events", [])
        map_changed = False
        
        for idx, obj in enumerate(objs):
            ttype = obj.get("trainer_type", "TRAINER_TYPE_NONE")
            if ttype not in ["TRAINER_TYPE_NORMAL", "TRAINER_TYPE_SEE_ALL_DIRECTIONS", "TRAINER_TYPE_BURIED"]:
                continue
                
            sc = obj.get("script", "NULL")
            tid = script_to_trainer.get(sc)
            has_party = (tid in parties) and (len(parties[tid]) > 0)
            
            if not has_party:
                old_sight = obj.get("trainer_sight_or_berry_tree_id", "0")
                backup_key = (mdir.name, idx)
                if backup_key in existing_backup:
                    rec = existing_backup[backup_key]
                else:
                    rec = {
                        "map": mdir.name,
                        "object_idx": idx,
                        "x": obj.get("x", 0),
                        "y": obj.get("y", 0),
                        "script": sc,
                        "trainer_id": tid,
                        "original_trainer_type": ttype,
                        "original_sight": old_sight
                    }
                backup_records.append(rec)
                
                modified_maps.setdefault(mdir.name, []).append({
                    "idx": idx,
                    "pos": (obj.get("x", 0), obj.get("y", 0)),
                    "script": sc,
                    "trainer_id": tid,
                    "old_type": ttype,
                    "old_sight": old_sight
                })
                
                if apply_changes:
                    obj["trainer_type"] = "TRAINER_TYPE_NONE"
                    obj["trainer_sight_or_berry_tree_id"] = "0"
                    map_changed = True
                    
        if apply_changes and map_changed:
            with open(mpath, "w", encoding="utf-8") as f:
                json.dump(data, f, indent=2)
                f.write("\n")
                
    if apply_changes and backup_records:
        with open(BACKUP_FILE, "w", encoding="utf-8") as f:
            json.dump(backup_records, f, indent=2)
            f.write("\n")
            
    return modified_maps

def restore_trainers(apply_changes=False):
    if not BACKUP_FILE.exists():
        print("No backup file found at", BACKUP_FILE)
        return {}
        
    with open(BACKUP_FILE, "r", encoding="utf-8") as f:
        records = json.load(f)
        
    valid_species = load_valid_species()
    parties = parse_trainers_party(valid_species)
    script_to_trainer = parse_script_to_trainer()
    
    restored_maps = {}
    maps_dir = REPO_ROOT / "data" / "maps"
    remaining_backups = []
    
    # Group records by map
    by_map = {}
    for r in records:
        by_map.setdefault(r["map"], []).append(r)
        
    for map_name, map_records in by_map.items():
        mpath = maps_dir / map_name / "map.json"
        if not mpath.exists():
            remaining_backups.extend(map_records)
            continue
            
        with open(mpath, "r", encoding="utf-8") as f:
            data = json.load(f)
            
        objs = data.get("object_events", [])
        map_changed = False
        
        for r in map_records:
            idx = r["object_idx"]
            if idx >= len(objs):
                remaining_backups.append(r)
                continue
                
            obj = objs[idx]
            sc = obj.get("script", r["script"])
            tid = script_to_trainer.get(sc, r.get("trainer_id"))
            has_party = (tid in parties) and (len(parties[tid]) > 0)
            
            if has_party:
                restored_maps.setdefault(map_name, []).append({
                    "idx": idx,
                    "pos": (obj.get("x", 0), obj.get("y", 0)),
                    "script": sc,
                    "trainer_id": tid,
                    "restored_type": r["original_trainer_type"],
                    "restored_sight": r["original_sight"]
                })
                if apply_changes:
                    obj["trainer_type"] = r["original_trainer_type"]
                    obj["trainer_sight_or_berry_tree_id"] = r["original_sight"]
                    map_changed = True
            else:
                remaining_backups.append(r)
                
        if apply_changes and map_changed:
            with open(mpath, "w", encoding="utf-8") as f:
                json.dump(data, f, indent=2)
                f.write("\n")
                
    if apply_changes:
        with open(BACKUP_FILE, "w", encoding="utf-8") as f:
            json.dump(remaining_backups, f, indent=2)
            f.write("\n")
            
    return restored_maps

def main():
    parser = argparse.ArgumentParser(description="Clean up or restore inactive trainers lacking a party")
    parser.add_argument("--apply", action="store_true", help="Apply changes in-place to map.json files")
    parser.add_argument("--restore", action="store_true", help="Restore trainers from backup if they now have a party")
    args = parser.parse_args()
    
    mode_name = "RESTORE TRAINERS" if args.restore else "CLEANUP INACTIVE TRAINERS"
    exec_mode = "APPLY CHANGES" if args.apply else "DRY RUN (Preview Only)"
    
    print(f"\n{'='*90}")
    print(f"{mode_name:^90}")
    print(f"{'Mode: ' + exec_mode:^90}")
    print(f"{'='*90}\n")
    
    if args.restore:
        results = restore_trainers(apply_changes=args.apply)
        action_word = "Restored"
    else:
        results = cleanup_trainers(apply_changes=args.apply)
        action_word = "Disabled (set to TRAINER_TYPE_NONE)"
        
    total_trainers = sum(len(v) for v in results.values())
    print(f"Total maps affected: {len(results)}")
    print(f"Total trainers {action_word}: {total_trainers}\n")
    
    for map_name, trainers in sorted(results.items()):
        print(f"--- {map_name} ({len(trainers)} trainers) ---")
        for t in trainers:
            pos_str = f"({t['pos'][0]}, {t['pos'][1]})"
            t_info = f"{t['script']} ({t.get('trainer_id')})"
            if len(t_info) > 40:
                t_info = t_info[:37] + "..."
            print(f"  Obj #{t['idx']:<2} at {pos_str:<10} | {t_info}")
        print()
        
    print(f"{'='*90}")
    if not args.apply:
        print("Note: Run with --apply to commit these changes to map.json files.")
    print(f"{'='*90}\n")

if __name__ == "__main__":
    main()
