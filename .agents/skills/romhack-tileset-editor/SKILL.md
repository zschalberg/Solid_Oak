---
name: romhack-tileset-editor
description: Rules and utilities to parse, validate, edit, and create tiles, tilesets, and metatiles in GBA decomp ROM hacks.
---

# ROM Hack Tileset and Metatile Editor Skill

This skill enables the agent to safely edit tilesets, palettes, and metatile attributes/layouts in `pokefirered`-based decompilation projects without corrupting the files or causing build errors.

## Scope and Boundaries

* **Assets Only**: You should only modify tileset images (`tiles.png`), palettes (`palettes/*.pal`), metatiles layout (`metatiles.bin`), and metatile behavior attributes (`metatile_attributes.bin`).
* **No Map Layouts**: Do not touch `map.bin` or map event/warp JSONs. Map layout edits should be performed by the user inside **Porymap**.

---

## GBA Graphics Specifications

### 1. Indexed PNGs & Palette Blocks
* `tiles.png` is an indexed-color PNG.
* GBA uses **4bpp** graphics, meaning each 8x8 pixel tile is drawn using a palette block of **16 colors** (where index 0 is transparent).
* In the main `tiles.png` file, all pixel color indices for a single 8x8 block **must** belong to a single 16-color page (i.e. `[16*k, 16*k + 15]`). If pixel indices span across multiple pages, `gbagfx` will split them incorrectly, causing visual corruption.
* Use `png_tiles_editor.py validate` to verify PNG compliance.

### 2. Metatiles Layout (`metatiles.bin`)
* Each metatile is **16x16 pixels** (formed of four 8x8 tiles on the bottom layer and four on the top layer, totalling 8 tile slots).
* Each slot is a 16-bit word (`u16`) with this structure:
  * **Bits 0-9**: 8x8 Tile index in `tiles.png` (0 - 1023).
  * **Bit 10**: Horizontal flip (1 = flipped).
  * **Bit 11**: Vertical flip (1 = flipped).
  * **Bits 12-15**: Palette index slot to use (0 - 15).
* Total bytes per metatile = `8 * 2 = 16 bytes`.

### 3. Metatile Attributes (`metatile_attributes.bin`)
* Stores behaviors, terrain types, and layers for each metatile.
* Total bytes per metatile = `4 bytes` (1 `u32` value).
* Structure:
  * **Bits 0-15**: Metatile behavior ID (maps to `MB_*` constants in `include/constants/metatile_behaviors.h`).
  * **Bits 16-23**: Terrain/elevation settings.
  * **Bits 24-31**: Layer and encounter type settings.

---

## Python Helper Utilities

Use the following tools in `.agents/skills/romhack-tileset-editor/scripts/`:

### A. Graphics Manipulation (`png_tiles_editor.py`)
This script wraps the compiled `tools/gbagfx/gbagfx` compiler via WSL.

1. **Validate a tileset PNG**:
   ```bash
   python3 .agents/skills/romhack-tileset-editor/scripts/png_tiles_editor.py validate <path/to/tiles.png>
   ```
2. **Insert an 8x8 tile into `tiles.png`**:
   ```bash
   python3 .agents/skills/romhack-tileset-editor/scripts/png_tiles_editor.py insert-tile <path/to/tiles.png> <path/to/source_tile.png> <tile_index>
   ```
3. **Extract an 8x8 tile block**:
   ```bash
   python3 .agents/skills/romhack-tileset-editor/scripts/png_tiles_editor.py extract-tile <path/to/tiles.png> <tile_index> <output_path.png>
   ```

### B. Metatile Layout and Attributes (`metatile_editor.py`)
This script handles mapping bin files to C constants and JSON.

1. **Parse a metatile / print info**:
   ```bash
   python3 .agents/skills/romhack-tileset-editor/scripts/metatile_editor.py parse <path/to/metatiles.bin> <path/to/metatile_attributes.bin> --index <metatile_id>
   ```
2. **Edit a metatile behavior**:
   ```bash
   python3 .agents/skills/romhack-tileset-editor/scripts/metatile_editor.py write-behavior <path/to/metatile_attributes.bin> <metatile_id> <MB_CONSTANT>
   ```
3. **Write metatile layout**:
   ```bash
   python3 .agents/skills/romhack-tileset-editor/scripts/metatile_editor.py write-metatile <path/to/metatiles.bin> <metatile_id> '<json_string>'
   ```
4. **Self-verification test**:
   ```bash
   python3 .agents/skills/romhack-tileset-editor/scripts/metatile_editor.py test-roundtrip <path/to/metatiles.bin> <path/to/metatile_attributes.bin>
   ```
