#!/usr/bin/env python3
"""
Audits maps in the Solid-Oak codebase and reports all NPCs/character objects
that are still using their vanilla (unmodified FireRed) scripts.

Groups results by Map -> Building -> Floor (if applicable).
Can omit Pokemon Centers by default (as they are being replaced in Solid-Oak).

Usage:
  python3 tools/report_vanilla_npcs.py                  # Scans Act 1 maps by default
  python3 tools/report_vanilla_npcs.py --act 1          # Explicitly scan Act 1 maps
  python3 tools/report_vanilla_npcs.py VermilionCity Route11
  python3 tools/report_vanilla_npcs.py --all            # Scan all maps in the game
  python3 tools/report_vanilla_npcs.py --output report.md
"""

import os
import sys
import json
import re
import argparse
import subprocess
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

# Base commit where Solid-Oak branched off from upstream pokefirered-expansion
UPSTREAM_COMMIT = "536510dfa"

# Act 1 Map Hierarchy Definition:
# Format:
# Region/Town:
#   Building Name:
#     Floor Name (optional): [map_ids]
ACT_1_HIERARCHY = [
    {
        "area": "S.S. Minnow / S.S. Anne",
        "buildings": [
            {
                "name": "S.S. Minnow (Corridor)",
                "maps": ["SSMinnow_1F"]
            },
            {
                "name": "S.S. Anne (Exterior)",
                "maps": ["SSAnne_Exterior"]
            },
            {
                "name": "Cabin 6 (Arbor's Quarters)",
                "maps": ["SSAnne_1F_Room6"]
            },
        ]
    },
    {
        "area": "Vermilion City",
        "buildings": [
            {
                "name": "Vermilion City (Overworld)",
                "maps": ["VermilionCity"]
            },
            {
                "name": "Pokémon Fan Club",
                "maps": ["VermilionCity_PokemonFanClub"]
            },
            {
                "name": "House 1 (Fishing Guru)",
                "maps": ["VermilionCity_House1"]
            },
            {
                "name": "House 2 (Trade House)",
                "maps": ["VermilionCity_House2"]
            },
            {
                "name": "House 3 (Pidgey Mail)",
                "maps": ["VermilionCity_House3"]
            },
            {
                "name": "Vermilion Mart",
                "maps": ["VermilionCity_Mart"]
            },
            {
                "name": "Vermilion Gym",
                "maps": ["VermilionCity_Gym"]
            },
            {
                "name": "Vermilion Dojo",
                "maps": ["VermilionCity_Dojo"]
            },
        ]
    },
    {
        "area": "Route 11",
        "buildings": [
            {
                "name": "Route 11 (Overworld)",
                "maps": ["Route11"]
            },
            {
                "name": "East Gatehouse",
                "floors": [
                    {"floor": "1F", "maps": ["Route11_EastEntrance_1F"]},
                    {"floor": "2F", "maps": ["Route11_EastEntrance_2F"]},
                ]
            },
        ]
    },
    {
        "area": "Route 12",
        "buildings": [
            {
                "name": "Route 12 (Overworld)",
                "maps": ["Route12"]
            },
            {
                "name": "North Gatehouse",
                "floors": [
                    {"floor": "1F", "maps": ["Route12_NorthEntrance_1F"]},
                    {"floor": "2F", "maps": ["Route12_NorthEntrance_2F"]},
                ]
            },
            {
                "name": "Fishing House (Super Rod Guru)",
                "maps": ["Route12_FishingHouse"]
            },
        ]
    },
    {
        "area": "Fishing Village",
        "buildings": [
            {
                "name": "Village Entrance",
                "maps": ["Fishing_Village_Entrance"]
            },
            {
                "name": "Village Center",
                "maps": ["Fishing_Village_New"]
            },
        ]
    },
    {
        "area": "Lavender Town",
        "buildings": [
            {
                "name": "Lavender Town (Overworld)",
                "maps": ["LavenderTown"]
            },
            {
                "name": "Mr. Fuji's Volunteer Pokémon House",
                "maps": ["LavenderTown_VolunteerPokemonHouse"]
            },
            {
                "name": "House 1 (Cubone's House)",
                "maps": ["LavenderTown_House1"]
            },
            {
                "name": "House 2 (Name Rater)",
                "maps": ["LavenderTown_House2"]
            },
            {
                "name": "Lavender Mart",
                "maps": ["LavenderTown_Mart"]
            },
            {
                "name": "Fuji Lab",
                "floors": [
                    {"floor": "Lobby", "maps": ["LavenderTown_FujiLab_Lobby"]},
                    {"floor": "Rooms 1-10 (Sanctuary)", "maps": [f"LavenderTown_FujiLab_Room{i}" for i in range(1, 11)]},
                ]
            },
            {
                "name": "Pokémon Tower",
                "floors": [
                    {"floor": "1F", "maps": ["PokemonTower_1F"]},
                    {"floor": "2F", "maps": ["PokemonTower_2F"]},
                    {"floor": "3F", "maps": ["PokemonTower_3F"]},
                    {"floor": "4F", "maps": ["PokemonTower_4F"]},
                    {"floor": "5F", "maps": ["PokemonTower_5F"]},
                    {"floor": "6F", "maps": ["PokemonTower_6F"]},
                    {"floor": "7F", "maps": ["PokemonTower_7F"]},
                ]
            },
            {
                "name": "Lavender Cemetery",
                "maps": ["Lavender_Cemetary_Map"]
            },
        ]
    },
    {
        "area": "Fuchsia City",
        "buildings": [
            {
                "name": "Fuchsia City (Overworld)",
                "maps": ["FuchsiaCity"]
            },
            {
                "name": "Fuchsia Reserve",
                "maps": ["FuchsiaCity_Reserve"]
            },
            {
                "name": "House 1 (Bill's Grandfather)",
                "maps": ["FuchsiaCity_House1"]
            },
            {
                "name": "House 2 (Fishing Guru's Brother)",
                "maps": ["FuchsiaCity_House2"]
            },
            {
                "name": "House 3 (Move Deleter)",
                "maps": ["FuchsiaCity_House3"]
            },
            {
                "name": "Fuchsia Mart",
                "maps": ["FuchsiaCity_Mart"]
            },
            {
                "name": "Fuchsia Gym",
                "maps": ["FuchsiaCity_Gym"]
            },
            {
                "name": "Warden's House",
                "maps": ["FuchsiaCity_WardensHouse"]
            },
            {
                "name": "Safari Zone Entrance",
                "maps": ["FuchsiaCity_SafariZone_Entrance"]
            },
            {
                "name": "Safari Zone Office",
                "maps": ["FuchsiaCity_SafariZone_Office"]
            },
        ]
    }
]

# Non-character objects that shouldn't be counted as NPCs
NON_NPC_GFX = {
    "OBJ_EVENT_GFX_ITEM_BALL",
    "OBJ_EVENT_GFX_POKE_BALL",
    "OBJ_EVENT_GFX_CUT_TREE",
    "OBJ_EVENT_GFX_ROCK_SMASH_ROCK",
    "OBJ_EVENT_GFX_PUSHABLE_BOULDER",
    "OBJ_EVENT_GFX_BERRY_TREE",
    "OBJ_EVENT_GFX_BERRY_TREE_EARLY_STAGES",
    "OBJ_EVENT_GFX_BERRY_TREE_LATE_STAGES",
    "OBJ_EVENT_GFX_GYM_SIGN",
    "OBJ_EVENT_GFX_SIGN",
    "OBJ_EVENT_GFX_TRAINER_TIPS",
    "OBJ_EVENT_GFX_CLIPBOARD",
    "OBJ_EVENT_GFX_METEORITE",
    "OBJ_EVENT_GFX_LAPRAS_DOLL",
    "OBJ_EVENT_GFX_SEAGALLOP",
    "OBJ_EVENT_GFX_SS_ANNE",
    "OBJ_EVENT_GFX_SS_TIDAL",
}

# Known Pokémon sprite identifiers
POKEMON_GFX = {
    "OBJ_EVENT_GFX_SPEAROW", "OBJ_EVENT_GFX_CUBONE", "OBJ_EVENT_GFX_POLIWRATH",
    "OBJ_EVENT_GFX_CLEFAIRY", "OBJ_EVENT_GFX_PIDGEOT", "OBJ_EVENT_GFX_JIGGLYPUFF",
    "OBJ_EVENT_GFX_PIDGEY", "OBJ_EVENT_GFX_CHANSEY", "OBJ_EVENT_GFX_OMANYTE",
    "OBJ_EVENT_GFX_KANGASKHAN", "OBJ_EVENT_GFX_PIKACHU", "OBJ_EVENT_GFX_PSYDUCK",
    "OBJ_EVENT_GFX_NIDORAN_F", "OBJ_EVENT_GFX_NIDORAN_M", "OBJ_EVENT_GFX_NIDORINO",
    "OBJ_EVENT_GFX_MEOWTH", "OBJ_EVENT_GFX_SEEL", "OBJ_EVENT_GFX_VOLTORB",
    "OBJ_EVENT_GFX_SLOWPOKE", "OBJ_EVENT_GFX_SLOWBRO", "OBJ_EVENT_GFX_MACHOP",
    "OBJ_EVENT_GFX_WIGGLYTUFF", "OBJ_EVENT_GFX_DODUO", "OBJ_EVENT_GFX_FEAROW",
    "OBJ_EVENT_GFX_MACHOKE", "OBJ_EVENT_GFX_LAPRAS", "OBJ_EVENT_GFX_ZAPDOS",
    "OBJ_EVENT_GFX_MOLTRES", "OBJ_EVENT_GFX_ARTICUNO", "OBJ_EVENT_GFX_MEWTWO",
    "OBJ_EVENT_GFX_MEW", "OBJ_EVENT_GFX_ENTEI", "OBJ_EVENT_GFX_SUICUNE",
    "OBJ_EVENT_GFX_RAIKOU", "OBJ_EVENT_GFX_LUGIA", "OBJ_EVENT_GFX_HO_OH",
    "OBJ_EVENT_GFX_CELEBI", "OBJ_EVENT_GFX_KABUTO", "OBJ_EVENT_GFX_DEOXYS_D",
    "OBJ_EVENT_GFX_DEOXYS_A", "OBJ_EVENT_GFX_DEOXYS_N", "OBJ_EVENT_GFX_OW_MON",
    "OBJ_EVENT_GFX_AZUMARILL", "OBJ_EVENT_GFX_AZURILL", "OBJ_EVENT_GFX_DUSCLOPS",
    "OBJ_EVENT_GFX_KIRLIA", "OBJ_EVENT_GFX_SKITTY", "OBJ_EVENT_GFX_SUDOWOODO",
    "OBJ_EVENT_GFX_WINGULL", "OBJ_EVENT_GFX_ZIGZAGOON_2", "OBJ_EVENT_GFX_TENTACOOL_SWIMMING",
    "OBJ_EVENT_GFX_SNORLAX",
}

# Cache for upstream files retrieved via git
_git_cache = {}

def get_upstream_file(rel_path):
    if rel_path in _git_cache:
        return _git_cache[rel_path]
    try:
        cmd = ["git", "show", f"{UPSTREAM_COMMIT}:{rel_path}"]
        res = subprocess.run(cmd, cwd=REPO_ROOT, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, check=True)
        _git_cache[rel_path] = res.stdout
        return res.stdout
    except subprocess.CalledProcessError:
        _git_cache[rel_path] = None
        return None

def clean_dialogue(text):
    if not text:
        return ""
    # Strip formatting tags and newlines
    text = re.sub(r'\\p|\\n|\\l', ' ', text)
    text = re.sub(r'\{[A-Za-z0-9_]+\}', '', text)
    text = re.sub(r'\$[A-Za-z0-9_]*', '', text)
    text = re.sub(r'\s+', ' ', text).strip()
    # Strip trailing quotes or dollars
    text = text.rstrip('$').strip().strip('"')
    if len(text) > 85:
        text = text[:82] + "..."
    return text

def extract_text_from_file(file_content, label):
    if not file_content or not label:
        return None
    # Look for label:: followed by .string "..."
    pattern = rf"{re.escape(label)}::\s*(?:\.string\s+\"([^\"]*)\")"
    m = re.search(pattern, file_content)
    if m:
        return m.group(1)
    # Search multi-string blocks
    pattern_multi = rf"{re.escape(label)}::(.*?)(?:^[A-Za-z0-9_]+::|\Z)"
    m_block = re.search(pattern_multi, file_content, re.MULTILINE | re.DOTALL)
    if m_block:
        strings = re.findall(r'\.string\s+\"([^\"]*)\"', m_block.group(1))
        if strings:
            return " ".join(strings)
    return None

def find_dialogue_text(map_name, text_label):
    if not text_label:
        return None
    # 1. Check map's text.inc
    map_text_path = REPO_ROOT / f"data/maps/{map_name}/text.inc"
    if map_text_path.exists():
        t = extract_text_from_file(map_text_path.read_text(encoding="utf-8", errors="ignore"), text_label)
        if t:
            return clean_dialogue(t)
    
    # 2. Check map's scripts.inc / scripts.pory
    map_scripts_path = REPO_ROOT / f"data/maps/{map_name}/scripts.inc"
    if map_scripts_path.exists():
        t = extract_text_from_file(map_scripts_path.read_text(encoding="utf-8", errors="ignore"), text_label)
        if t:
            return clean_dialogue(t)

    # 3. Check data/text/*.inc
    for global_text_file in (REPO_ROOT / "data" / "text").glob("*.inc"):
        t = extract_text_from_file(global_text_file.read_text(encoding="utf-8", errors="ignore"), text_label)
        if t:
            return clean_dialogue(t)

    # 4. Check data/scripts/*.inc
    for script_file in (REPO_ROOT / "data" / "scripts").glob("*.inc"):
        t = extract_text_from_file(script_file.read_text(encoding="utf-8", errors="ignore"), text_label)
        if t:
            return clean_dialogue(t)

    return None

def get_script_summary(map_name, script_name):
    """Inspects the script definition and derives a human-readable behavior/dialogue summary."""
    if not script_name or script_name in ("0", "0x0", "NULL"):
        return "Non-interactive / None"
    
    # Check if script is a trainer script in data/scripts/trainers.inc
    trainers_inc_path = REPO_ROOT / "data" / "scripts" / "trainers.inc"
    if trainers_inc_path.exists():
        content = trainers_inc_path.read_text(encoding="utf-8", errors="ignore")
        pattern = rf"{re.escape(script_name)}::(.*?)(?:^[A-Za-z0-9_]+::|\Z)"
        m = re.search(pattern, content, re.MULTILINE | re.DOTALL)
        if m:
            block = m.group(1)
            # Find trainerbattle
            tb = re.search(r'trainerbattle_\w+\s+([A-Za-z0-9_]+),\s*([A-Za-z0-9_]+)', block)
            if tb:
                tr_id = tb.group(1).replace("TRAINER_", "")
                intro_label = tb.group(2)
                dialogue = find_dialogue_text(map_name, intro_label)
                if dialogue:
                    return f"Battle [{tr_id}]: \"{dialogue}\""
                return f"Battle [{tr_id}]"

    # Search in map's scripts.inc
    map_inc_path = REPO_ROOT / f"data/maps/{map_name}/scripts.inc"
    if map_inc_path.exists():
        content = map_inc_path.read_text(encoding="utf-8", errors="ignore")
        pattern = rf"{re.escape(script_name)}::(.*?)(?:^[A-Za-z0-9_]+::|\Z)"
        m = re.search(pattern, content, re.MULTILINE | re.DOTALL)
        if m:
            block = m.group(1)
            # Check for playmoncry
            mc = re.search(r'playmoncry\s+SPECIES_([A-Za-z0-9_]+)', block)
            # Check for msgbox / message
            msg = re.search(r'(?:msgbox|message|msgreceiveditem|giveitem_msg)\s+([A-Za-z0-9_]+)', block)
            # Check for pokemart
            mart = re.search(r'pokemart\s+([A-Za-z0-9_]+)', block)
            # Check for item giveaway
            gi = re.search(r'(?:giveitem|additem)\s+ITEM_([A-Za-z0-9_]+)', block)

            parts = []
            if mc:
                parts.append(f"{mc.group(1)} cry")
            if gi:
                parts.append(f"Gives {gi.group(1)}")
            if mart:
                parts.append("Poké Mart shopkeeper")
            if msg:
                dialogue = find_dialogue_text(map_name, msg.group(1))
                if dialogue:
                    parts.append(f"\"{dialogue}\"")
                else:
                    parts.append(msg.group(1))
            if parts:
                return " | ".join(parts)

    return f"Script: {script_name}"

def is_script_vanilla(map_name, script_name):
    """
    Returns True if the script is identical to upstream vanilla pokefirered.
    """
    if not script_name or script_name in ("0", "0x0", "NULL"):
        return False
    
    # 1. If script is in data/scripts/trainers.inc
    upstream_trainers = get_upstream_file("data/scripts/trainers.inc")
    current_trainers_path = REPO_ROOT / "data" / "scripts" / "trainers.inc"
    if current_trainers_path.exists():
        curr_trainers = current_trainers_path.read_text(encoding="utf-8", errors="ignore")
        if f"{script_name}::" in curr_trainers:
            if upstream_trainers and f"{script_name}::" in upstream_trainers:
                # Compare script block
                pattern = rf"{re.escape(script_name)}::(.*?)(?:^[A-Za-z0-9_]+::|\Z)"
                m_curr = re.search(pattern, curr_trainers, re.MULTILINE | re.DOTALL)
                m_up = re.search(pattern, upstream_trainers, re.MULTILINE | re.DOTALL)
                if m_curr and m_up:
                    return m_curr.group(1).strip() == m_up.group(1).strip()
            return False

    # 2. Check map's scripts.inc against upstream
    upstream_map_inc = get_upstream_file(f"data/maps/{map_name}/scripts.inc")
    current_map_inc_path = REPO_ROOT / f"data/maps/{map_name}/scripts.inc"
    
    # If the map didn't even exist upstream, it's completely new / custom!
    if upstream_map_inc is None:
        return False
    
    if not current_map_inc_path.exists():
        return False
    
    curr_map_inc = current_map_inc_path.read_text(encoding="utf-8", errors="ignore")
    
    # If the script label was not in upstream, it's custom
    if f"{script_name}::" not in upstream_map_inc:
        return False
    
    # If the script label IS in upstream, compare the block!
    pattern = rf"{re.escape(script_name)}::(.*?)(?:^[A-Za-z0-9_]+::|\Z)"
    m_curr = re.search(pattern, curr_map_inc, re.MULTILINE | re.DOTALL)
    m_up = re.search(pattern, upstream_map_inc, re.MULTILINE | re.DOTALL)
    if not m_curr or not m_up:
        return False
    
    curr_block = m_curr.group(1).strip()
    up_block = m_up.group(1).strip()
    
    # Normalize and compare
    def normalize_asm(code):
        lines = []
        for line in code.splitlines():
            line = line.strip()
            if not line or line.startswith("#") or line.startswith("@") or line.startswith("//"):
                continue
            lines.append(line)
        return "\n".join(lines)
    
    norm_curr = normalize_asm(curr_block)
    norm_up = normalize_asm(up_block)
    if norm_curr == norm_up:
        return True

    # If the block was modified, check if it introduced new custom text labels or custom strings
    # Extract all text labels referenced (e.g. msgbox <label>, message <label>, etc.)
    text_refs = re.findall(r'(?:msgbox|message|msgreceiveditem|giveitem_msg)\s+([A-Za-z0-9_]+)', curr_block)
    
    # Check if any inline string was defined inside or directly after
    if '.string "' in curr_block:
        # Check if the string matches an upstream string
        curr_strings = re.findall(r'\.string\s+\"([^\"]*)\"', curr_block)
        up_strings = re.findall(r'\.string\s+\"([^\"]*)\"', up_block)
        if curr_strings and curr_strings != up_strings:
            return False

    upstream_text = get_upstream_file(f"data/maps/{map_name}/text.inc") or ""
    
    # If any referenced text label was NOT in upstream, it is custom
    for ref in text_refs:
        if ref not in upstream_map_inc and ref not in upstream_text:
            return False

    # Also check if custom quest/var flags were introduced (e.g. VAR_ACT1_, FLAG_QUEST_)
    if re.search(r'\b(?:VAR_ACT1_|FLAG_QUEST_|FLAG_KRABBY_QUEST_)\w*', curr_block):
        return False

    return True

def classify_object(obj):
    gfx = obj.get("graphics_id", "")
    if gfx in POKEMON_GFX or gfx.startswith("OBJ_EVENT_GFX_SPECIES") or "MON" in gfx:
        return "Pokémon"
    tr_type = obj.get("trainer_type", "TRAINER_TYPE_NONE")
    if tr_type != "TRAINER_TYPE_NONE":
        return "Trainer"
    return "Human NPC"

def audit_map(map_name):
    """
    Audits a single map and returns a list of vanilla NPC dicts.
    """
    map_json_path = REPO_ROOT / f"data/maps/{map_name}/map.json"
    if not map_json_path.exists():
        return []
    
    with open(map_json_path, "r", encoding="utf-8") as f:
        data = json.load(f)
    
    object_events = data.get("object_events", [])
    vanilla_npcs = []

    for idx, obj in enumerate(object_events):
        gfx = obj.get("graphics_id", "")
        script = obj.get("script", "")
        
        # Skip items and non-characters
        if gfx in NON_NPC_GFX:
            continue
        if not script or script in ("0", "0x0", "NULL"):
            continue
        
        # Check if script is vanilla
        if is_script_vanilla(map_name, script):
            category = classify_object(obj)
            summary = get_script_summary(map_name, script)
            clean_gfx = gfx.replace("OBJ_EVENT_GFX_", "")
            vanilla_npcs.append({
                "index": idx + 1,
                "local_id": obj.get("local_id", f"Obj {idx + 1}"),
                "graphics_id": gfx,
                "display_name": clean_gfx,
                "category": category,
                "x": obj.get("x"),
                "y": obj.get("y"),
                "script": script,
                "summary": summary
            })
            
    return vanilla_npcs

def build_act1_report(omit_pokemon_centers=True):
    lines = []
    lines.append("# Solid-Oak: Act 1 Vanilla NPC Audit Report")
    lines.append("")
    lines.append("> **Audit Target:** All maps and interiors across the complete Act 1 progression.")
    lines.append("> **Omitted:** Pokémon Center maps (omitted as they will be removed/replaced in Solid-Oak).")
    lines.append("> **Purpose:** Identify all remaining character objects (human NPCs, trainers, and overworld Pokémon) still executing original, unmodified FireRed scripts.")
    lines.append("")
    
    total_vanilla = 0
    total_maps_with_vanilla = 0
    total_maps_scanned = 0
    
    area_reports = []

    for area_info in ACT_1_HIERARCHY:
        area_name = area_info["area"]
        area_blocks = []
        area_vanilla_count = 0

        for bldg in area_info["buildings"]:
            bldg_name = bldg["name"]
            
            # Floor-based or direct
            if "floors" in bldg:
                floor_blocks = []
                for fl in bldg["floors"]:
                    floor_name = fl["floor"]
                    floor_maps = fl["maps"]
                    for m in floor_maps:
                        if omit_pokemon_centers and "PokemonCenter" in m:
                            continue
                        total_maps_scanned += 1
                        npcs = audit_map(m)
                        if npcs:
                            total_vanilla += len(npcs)
                            area_vanilla_count += len(npcs)
                            total_maps_with_vanilla += 1
                            floor_blocks.append((f"{floor_name} (`{m}`)", npcs))
                if floor_blocks:
                    area_blocks.append((bldg_name, floor_blocks, True))
            else:
                bldg_maps = bldg.get("maps", [])
                m_blocks = []
                for m in bldg_maps:
                    if omit_pokemon_centers and "PokemonCenter" in m:
                        continue
                    total_maps_scanned += 1
                    npcs = audit_map(m)
                    if npcs:
                        total_vanilla += len(npcs)
                        area_vanilla_count += len(npcs)
                        total_maps_with_vanilla += 1
                        m_blocks.append((f"`{m}`", npcs))
                if m_blocks:
                    area_blocks.append((bldg_name, m_blocks, False))

        area_reports.append((area_name, area_vanilla_count, area_blocks))

    # Executive Summary
    lines.append("## Executive Summary")
    lines.append("")
    lines.append(f"- **Total Maps Scanned in Act 1 Scope:** {total_maps_scanned}")
    lines.append(f"- **Maps Containing Vanilla NPCs:** {total_maps_with_vanilla}")
    lines.append(f"- **Total Vanilla NPCs Remaining:** **{total_vanilla}**")
    lines.append("")
    lines.append("| Area / Route | Vanilla NPCs Remaining | Status |")
    lines.append("| :--- | :---: | :--- |")
    for area_name, count, _ in area_reports:
        status = "✅ Clean (0 Vanilla)" if count == 0 else f"⚠️ {count} Vanilla NPCs"
        lines.append(f"| **{area_name}** | {count} | {status} |")
    lines.append("")
    lines.append("---")
    lines.append("")

    # Detailed Breakdowns
    for area_name, count, buildings in area_reports:
        lines.append(f"## {area_name}")
        lines.append("")
        if count == 0:
            lines.append("*All NPCs in this area have been replaced with custom Solid-Oak scripts or are clean.*\n")
            continue

        for bldg_name, sub_items, is_floors in buildings:
            lines.append(f"### {bldg_name}")
            lines.append("")
            
            for header_label, npcs in sub_items:
                if is_floors:
                    lines.append(f"#### Floor: {header_label}")
                else:
                    lines.append(f"#### Map: {header_label}")
                lines.append("")
                lines.append("| # | Type | Sprite / Entity | Pos (X,Y) | Current Vanilla Script | Vanilla Behavior / Dialogue Sample |")
                lines.append("| :-: | :---: | :--- | :-: | :--- | :--- |")
                for n in npcs:
                    type_badge = f"`{n['category']}`"
                    lines.append(f"| {n['index']} | {type_badge} | `{n['display_name']}` | ({n['x']},{n['y']}) | `{n['script']}` | {n['summary']} |")
                lines.append("")

    return "\n".join(lines)

def main():
    parser = argparse.ArgumentParser(description="Audit maps for NPCs still using vanilla scripts.")
    parser.add_argument("maps", nargs="*", help="Specific map names to audit (e.g. VermilionCity Route11)")
    parser.add_argument("--act", type=int, choices=[1], default=1, help="Act preset to audit (default: 1)")
    parser.add_argument("--all", action="store_true", help="Audit all maps in data/maps/")
    parser.add_argument("--include-pokemon-centers", action="store_true", help="Include Pokémon Center maps")
    parser.add_argument("--output", "-o", help="Write report to a markdown file")
    
    args = parser.parse_args()
    
    omit_pkmn_centers = not args.include_pokemon_centers
    
    if args.maps:
        print(f"Auditing {len(args.maps)} custom specified map(s)...")
        results = []
        for m in args.maps:
            npcs = audit_map(m)
            print(f"Map {m}: {len(npcs)} vanilla NPCs found")
            for n in npcs:
                print(f"  [{n['category']}] ({n['x']},{n['y']}) {n['display_name']} -> {n['script']}: {n['summary']}")
        return

    if args.all:
        print("Auditing ALL maps in data/maps/...")
        all_maps = sorted([p.name for p in (REPO_ROOT / "data" / "maps").iterdir() if p.is_dir() and (p / "map.json").exists()])
        total = 0
        for m in all_maps:
            if omit_pkmn_centers and "PokemonCenter" in m:
                continue
            npcs = audit_map(m)
            if npcs:
                total += len(npcs)
                print(f"{m}: {len(npcs)} vanilla NPCs")
        print(f"Total vanilla NPCs across all scanned maps: {total}")
        return

    # Default: Generate Act 1 report
    report_content = build_act1_report(omit_pokemon_centers=omit_pkmn_centers)
    
    if args.output:
        out_path = Path(args.output).resolve()
        out_path.write_text(report_content, encoding="utf-8")
        print(f"Report written to {out_path}")
    else:
        print(report_content)

if __name__ == "__main__":
    main()
