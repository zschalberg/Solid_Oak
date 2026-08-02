# Project Rules and Guidelines for Solid-Oak

This file provides guidance to agents when working with code in this repository. It is loaded automatically at the start of every session.

## Code Style
- Follow the formatting conventions of `pret/pokefirered`.
- Maintain original comments and docstrings.
- Never commit without being explicitly told to.
- Ask questions if there is ambiguity on a request; it is better to ask and be sure than to guess.

## Project Overview
**Solid-Oak** is a Pokemon FireRed ROM hack built on the `pokefirered-expansion` framework. The setting is early Kanto before Red/Blue — the player is young Professor Oak studying Pokemon migration. The ROM is compiled to `pokefirered.gba`.

## Build Rules & Commands
- **Always build via WSL (Ubuntu/Debian)**. The project builds 2x faster than msys2 and 5–6x faster than Cygwin.
- After making changes, verify the build succeeds before declaring work done.

```bash
# Standard build (primary target)
make firered

# Other targets
make leafgreen
make debug       # -g symbols, -Og
make release     # LTO enabled
make check       # headless test suite
make clean       # remove build artifacts
make syms        # generate symbol map
```

Output ROM: `pokefirered.gba`  
Build artifacts: `build/firered/`

Supports parallel builds: `make -j$(nproc)`

Required WSL packages: `build-essential binutils-arm-none-eabi libpng-dev python3 python3-pil`

## Architecture

### Build Pipeline
`.c` / `.pory` / `.png` / JSON → preprocessed → compiled (ARM GCC 15 via `$GCCARM15`) → linked → `pokefirered.gba`. Separate `.mk` files handle graphics (`graphics_file_rules.mk`), audio (`audio_rules.mk`), trainers, maps, JSON data, and tilesets.

### Script System
Map event scripts are written in **Poryscript** (`.pory` files in `data/scripts/`), compiled to `.inc` via the `poryscript` tool using `command_config.json`. These are not hand-written assembly.

### Mugshots (NPC Portraits)
64×64 speaker portraits above dialogue. PNG files go in `graphics/mugshots/` and are auto-converted by `tools/convert_mugshot.py` (requires Pillow) during build. Script commands: `showmugshot` / `clearmugshot`. Supports simultaneous double-portraits (left @X=36, right @X=204).

### Data-Driven Systems
Many systems are defined in JSON under `src/data/pokemon/` (species info, learnsets, egg moves, special movesets) and compiled via `json_data_rules.mk`. The `tools/learnset_helpers/` Python scripts generate teachable learnsets and TM data from JSON — don't edit those C structs directly.

## Custom Game Systems

### Pokemon Size
Per-Pokemon height/weight derived from personality value + size table. Affects battle speed (lighter = faster, min 0.2×) and physical damage (heavier = stronger). Exceptional sizes show color-highlighted catch messages and are tracked in a Pokedex Size Records page.

### Research & Catch System
- **Protoballs**: Level-capped catch balls (Red≤10, Blu≤20, Grn≤30, Blk≤40) crafted at a Workbench (Apricorn + Conversion Kit)
- **Research Balls**: 1.5× catch rate; caught Pokemon can't battle (treated as eggs)
- **Berry throwing in battle**: R-button quick-throws Razz Berry (catch boost) or Nanab Berry (calm)
- **Research Points**: Turn in Research Balls at Oak's Lab for points redeemable for rewards (Exp. Share, Porygon, etc.). Points scale by rarity, IVs, size records, and shininess

### Pokemon Storage (Mr. Fuji's Sanctuary)
Replaces the PC. "Rooms" system (8 Rooms × 6 Pokemon default, upgrades to 10). **Pidgeot Courier**: key item whistle summons Pidgeot outdoors for deposit/withdraw via a staged multi-select interface.

### Level & Boss Scaling
- `FLAG_SCALE_BOSS_BATTLE`: scales trainer battles to player's max party level + `VAR_SCALE_LEVEL_OFFSET` (default +5, supports negative for Easy Mode)
- `FLAG_SCALE_WILD_POKEMON`: wilds scale to player team level ±10
- Anti-trivialization: levels never scale below baseline

### Quest Log
Accessible from the Start Menu under "POKéDEX → Journal". Three tabs (MAIN STORY / SIDE QUESTS / RESEARCH) navigated with D-pad. Quest colors: green = complete, dark gray = active, red = locked. Pressing A on a quest shows its location on the Town Map.

### TM / HM Restrictions
TMs cannot be used directly from the bag — moves must be learned from Dojo Move Tutors. HM field usage requires only the HM item in bag (no badge check). Fly opens the overworld Fly Map directly from the TM Case.

### IV Scanner
Key item that unlocks an IV/EV viewer tab in the Summary Screen. L-button in wild battles scans the opponent's IVs. Outstanding Pokemon (≥151 total IV) trigger shiny sparkles; perfect IVs trigger `MUS_LEVEL_UP` fanfare.

### Variable Team Preview & 3v3 Battles
Pre-battle team preview with sprite sheets. `gSpecialVar_0x8008` controls selection limit (default 3). Party reordering is allowed during select and restored after battle.

### Expanded Seen/Caught Tracking
Binary seen/caught flags upgraded to 8-bit counters (max 255) for the first 400 species. Player's own Pokemon don't increment Seen count. Exposed via `GetSpeciesSeenCount` / `GetSpeciesCaughtCount` script specials.

### Quest-Gated Evolutions
Gengar and Slowpoke evolutions are blocked until corresponding quest flags are set. See `config/species_enabled.h` and relevant quest flag constants.

## Key File Locations

| System | Location |
|--------|----------|
| Battle mechanics | `src/battle*.c`, `include/battle*.h`, `data/battle_scripts_*.s` |
| Catch / ball logic | `src/ball.c`, `src/battle_controller_player.c` |
| Level scaling | `src/battle_controller_*.c` |
| Mugshot system | `tools/convert_mugshot.py`, `graphics/mugshots/`, `src/field_message_box.c` |
| Quest Log scripts | `data/scripts/` (`.pory` files) |
| Crafting (Workbench) | `data/scripts/workbench*.pory` |
| Size system | `src/battle.c` (scaling), `src/pokedex_plus_hgss.c` (records) |
| Learnset generation | `tools/learnset_helpers/`, `src/data/pokemon/` |
| Constants & flags | `constants/`, `include/constants/` |
| Feature documentation | `docs/features.md` |
