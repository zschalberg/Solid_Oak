# Solid-Oak: Custom Features & Gameplay Mechanics

This document provides a detailed technical and gameplay breakdown of all the custom features, mechanics, and modifications implemented in the **Solid-Oak** branch compared to the base **Pokémon FireRed Extended** game.

Solid-Oak is a story-driven Pokémon ROM hack set in an early version of Kanto, before the events of Red/Blue. The player is a young Samuel (young Professor Oak), working as a research assistant to study Pokémon migration patterns following a recent war. The game focuses on scientific exploration, ecological change, and the origins of modern Pokémon research.

The branch diverges from FireRed Extended at the upstream sync commit `536510dfa` (*Sync/battle engine master*). The codebase contains a series of custom modifications spanning battle mechanics, catch progression, tracking systems, level scaling, and quest logging.

---

## 1. Individual Pokémon Size System & Battle Modifiers

One of the most extensive additions to this fork is a fully integrated individual height/weight system that affects both aesthetics and combat.

### Individual Dimensions & Memo Display
* Pokémon have individual height and weight dimensions calculated using their personality hashes and the translation table `sBigMonSizeTable`.
* The **Trainer Memo** page of the Pokémon Summary Screen prints these individual stats:
  `H: <height> (<percentile>%)   W: <weight> (<percentile>%)`
* Percentiles are calculated linearly (e.g., `84.5%` or `12.1%`) based on where the Pokémon's personality hash falls in the range of `0` to `65535` for height and weight.

### Size-Based Battle Mechanics
Dimensions are no longer purely cosmetic; they directly affect combat stats in the battle engine:
* **Speed Stat Scaling**: A Pokémon's battle speed is adjusted based on how its actual weight compares to its species' base weight. Heavier Pokémon are slowed down (clamped to a minimum speed multiplier floor of `0.2x` for extremely heavy specimens), while lighter ones receive a speed boost:
  $$\text{Speed}_{\text{new}} = \frac{\text{Speed}_{\text{base}} \times (6 \times \text{BaseWeight} - \text{ActualWeight})}{5 \times \text{BaseWeight}}$$
* **Physical Damage Scaling**: The damage dealt by physical moves is scaled based on weight. Heavier Pokémon strike with more force, dealing increased physical damage:
  $$\text{Damage}_{\text{new}} = \frac{\text{Damage}_{\text{base}} \times (4 \times \text{BaseWeight} + \text{ActualWeight})}{5 \times \text{BaseWeight}}$$

### Exceptional Size Capture Notices & Rarity Tiers
When catching a wild Pokémon, the engine evaluates the height and weight category (from 0 to 15, where 8 is the average median):
* **Rarity Categories**:
  * **Average** (Tiers 6-9): No message.
  * **Uncommon** (Tiers 5, 10): Triggers an Uncommon catch notice.
  * **Rare** (Tiers 3, 4, 11, 12): Triggers a Rare catch notice.
  * **Very Rare** (Tiers 0, 1, 2, 13, 14, 15): Triggers a Very Rare catch notice.
* If a Pokémon is exceptionally sized (Uncommon, Rare, or Very Rare), the battle script triggers a message where the exceptional stat is highlighted in **blue**:
  `"The caught [POKéMON] is exceptionally sized! Height %ile: [XX.X]%, Weight %ile: [YY.Y]%"`

### Size Record Page & Linear Sliders
* The Pokédex screen includes a dedicated **Size Record Page** (Page 3) showing the shortest and tallest recorded height, and the lightest and heaviest recorded weight for that species.
* The records are updated automatically upon capture.
* These records are visualized using horizontal linear slider meters, mapping the recorded minimums and maximums across the 16 size categories.

### Size Evaluation & Removal Specials
* Script specials **`BufferMonPercentiles`**, **`RemoveSelectedPartyMon`**, **`GetMonHeight`**, **`GetMonWeight`**, **`GetMonHeightPercentile`**, and **`GetMonWeightPercentile`** are exposed to the scripting engine to query individual size details and facilitate research-based donations.

---

## 2. Seen/Caught Tracking Expansion

The tracking system has been modified to support detailed, scientific data accumulation instead of simple binary flags.

### 8-Bit Seen & Caught Counters
* The Pokédex/Journal is limited to Gen 3 species (first 400 slots, as defined by `DEX_COUNTS_MAX_SPECIES`).
* Rather than registering a simple yes/no flag, the Save Block (`SaveBlock1`) allocates two 8-bit arrays:
  * `pokedexSeen[400]`
  * `pokedexCaught[400]`
* These track the exact number of times a species has been seen or caught, up to a maximum count of **255**. Species indices above 400 fall back to standard binary flags.
* **`GetSpeciesSeenCount`** and **`GetSpeciesCaughtCount`** script specials allow dialogues and events to read these tallies.
* Format: In the Pokédex screen, the counts are printed as `Seen/Caught: X/Y`.

### Self-Observation Exclusion
* To preserve scientific accuracy, the Seen counter **does not** increment when the player sends out their own Pokémon in battle. Only wild Pokémon encounters and opponent trainer Pokémon count towards observation tallies.

---

## 3. Custom Poké Balls & Catch Mechanics

The catch formulas and item pools have been modified to introduce progression limits and custom research utilities.

### Protoballs with Level Caps
Standard Poké Balls are styled as **Protoballs** and lose their traditional catch rate modifiers. In their place, they have strict level-based usage caps:
* **Red Protoball**: Cannot capture Pokémon above **Level 10**.
* **Blu Protoball**: Cannot capture Pokémon above **Level 20**.
* **Grn Protoball**: Cannot capture Pokémon above **Level 30**.
* **Blk Protoball**: Cannot capture Pokémon above **Level 40**.

If thrown at a Pokémon exceeding the cap, the Poké Ball fails automatically and displays the message:
`"This Ball doesn't work on a Pokémon that strong!"`

### Research Balls
* Replaces the Cherish Ball as the **Research Ball** (`BALL_RESEARCH`).
* Provides a baseline capture rate multiplier of **1.5x**.
* **Battle Ineligibility**: Pokémon caught in a Research Ball are marked as "Research Specimens" and cannot participate in battles. They are treated similarly to Eggs in party menus:
  * They do not count towards the player's active team member counts.
  * They cannot be opened or sent out in the field or in battle.
  * Attempting to switch them in displays the message: `"[POKéMON] is in a Research Ball and cannot be opened in the field!"`
  * They cannot be placed in the Daycare (except for viewing their Summary).

### In-Battle Berry Throwing & R-Button Quick Throw
* Players can throw **Razz Berries** and **Nanab Berries** in battle to apply catch rate boosts and behavior modifiers:
  * **Razz Berry**: Boosts the catch rate of the next thrown ball.
  * **Nanab Berry**: Calms the Pokémon, reducing movement or erratic behavior.
* **R-Button Quick Throw**: Pressing the **R button** during wild battles quickly throws a Razz or Nanab Berry. After a berry is thrown, the item selector resets back to the last thrown Poké Ball (or the first ball in the bag if none have been thrown yet) to streamline capture attempts.
* **Research Mastery Multipliers**: Active catch rate boosts scale with the player's research mastery level, unlocking higher multipliers.
* **Trainer Card Titles**: A custom Research Title system updates the Trainer Card to display the player's scientific research rank.

---

## 4. Pokémon Research Turn-in System

A dedicated scientific evaluation system has been established at **Prof. Oak's Lab** in Pallet Town, allowing the player to turn in wild specimens captured in **Research Balls** to receive **Research Points** (which utilize the under-the-hood Game Corner Coin system).

### Research Point Evaluation Formula
Points are calculated dynamically upon turning in a Pokémon:
1. **Base Rarity (Catch Rate-Based)**:
   * **Common** (Catch Rate $\ge 150$): **10 points**
   * **Uncommon** (Catch Rate $\ge 75$): **30 points**
   * **Rare** (Catch Rate $\ge 31$): **100 points**
   * **Legendary/Mythical** (Catch Rate $< 31$): **350 points**
2. **Size Outlier Bonus**:
   * **Record Specimen**: If both height and weight categories are outliers ($\le 4$ or $\ge 11$): **+150 points**
   * **Size Outlier**: If only height or weight is an outlier: **+50 points**
3. **Perfect IV Bonus**:
   * **+25 points** for each perfect (31) IV stat (up to **+150 points** for a 6IV Pokémon).
4. **New Family Bonus**:
   * **+250 points** if the turned-in Pokémon is the first recorded specimen from its evolutionary line. Evolutionary base species are tracked dynamically in the save structure `reserveSpeciesTurnedIn`, with baby Pokémon excluded from walking up to parents.
5. **Shiny Multiplier**:
   * If the Pokémon is Shiny, the entire points sum is **doubled**, and a flat **+500 points** bonus is added:
     $$\text{Points}_{\text{shiny}} = (\text{Base} + \text{Size} + \text{IV} + \text{Family}) \times 2 + 500$$

### Points Breakdown Dialog
* The turn-in process triggers a detailed breakdown text summarizing points gained from Rarity, Size, IVs, Family, Shininess, and the Grand Total.

### Research Rewards Shop
Players can exchange Research Points for items and Pokémon:
* **Leaf Stone**: 100 points
* **Rare Candy**: 200 points
* **Fuji Lab Upgrade**: 1500 points (expands storage capacity)
* **Exp. Share**: 1500 points
* **Porygon**: 1500 points (Level 20)
* **Beldum**: 2000 points (Level 20)

### Family Cataloged HP Bar Indicator
* To aid cataloging wild species without duplicate turn-ins, a custom family indicator icon appears on the wild Pokémon's healthbar in battle if a member of that Pokémon's evolutionary family has **already been turned in to the Reserve**. This helps the player identify newly cataloged lines at a glance.

---

## 5. Mr. Fuji's Pokémon Sanctuary & Pidgeot Courier

Since modern PC storage systems do not yet exist, players store their boxed Pokémon in **Mr. Fuji's Pokémon Sanctuary** (representing PC Boxes, termed "Rooms").

### Sanctuary Capacity & Upgrades
* **Default Capacity**: 8 Rooms holding up to 6 Pokémon each (48 total capacity).
* **Sanctuary Expansion**: Purchasing the **Fuji Lab Upgrade** (1500 Research Points) expands the Sanctuary's capacity to **10 Rooms** (60 total capacity).
* **PC Unlock**: Once the conventional PC system is unlocked (`FLAG_SYS_CONVENTIONAL_PC_UNLOCKED`), the capacity expands to the vanilla standard of 14 boxes with 30 Pokémon each.

### Pidgeot Courier Overworld Retrieval
* **Courier Whistle**: A key item (`ITEM_COURIER_WHISTLE`) allows players to summon a Pidgeot Courier anywhere outdoors.
* **Staged Multi-Select Cart**: The courier provides a staged multi-select interface to deposit and retrieve Pokémon from the Sanctuary directly while in the overworld.
* **Upgrade Integration**: Unlocking the Fuji Lab Upgrade dynamically integrates Rooms 9 and 10 into the Courier's retrieval options.

---

## 6. IV Scanner, Advanced IV Scanner & Summary Screen Enhancements

Specialized analytical tools have been added to aid research on wild Pokémon statistics.

### IV/EV Summary Screen Unlock
* The **IV Scanner** Key Item (`ITEM_IV_SCANNER`) dynamically unlocks a detailed IV/EV viewer tab in the Pokémon Summary Screen, exposing exact values.

### In-Battle Scanner Usage
* **L-Button Shortcut**: Pressing the **L button** during a wild battle scans the opposing Pokémon.
* **Dynamic Battle Text Layout**: Displays evaluation text in a 2-paragraph, 4-sentence structure indicating:
  * Overall potential rating (Outstanding, Good, Decent, Poor).
  * The highest individual IV stat name and value.
  * The count of perfect (31) IV stats (this line is completely omitted if the perfect count is 0).
* **Aesthetic Fanfares**:
  * Scanning a Pokémon with perfect IVs plays the `MUS_LEVEL_UP` fanfare in battle.
  * Scanning an "Outstanding" Pokémon (total IVs $\ge 151$) triggers shiny sparkles (`DoShinySparkles`) on the opponent to represent its high IVs, superseding the fanfare.

### Advanced IV Scanner & Chaining
* **Advanced IV Scanner Key Item**: A new key item, the **Advanced IV Scanner** (`ITEM_ADVANCED_IV_SCANNER`), allows players to scan the surrounding overworld for wild Pokémon.
* **Overworld Hotspot Detection**:
  * Scans a $\pm 7$ by $\pm 5$ metatile range around the player.
  * On foot: searches for tall grass or long grass.
  * Surfing: searches for surfable water.
  * If valid metatiles are found, one is randomly selected as an active **Hotspot**. The scanner plays directional audio beeps (`SE_DEX_SEARCH`) and visual overworld arrow/star indicators pointing to it.
* **Visual Metatile Shaking**: When the player approaches within 3 tiles of the active Hotspot, the tile will visually shake (shaking grass, shaking long grass, or surfacing water ripples).
* **Scanner Chaining & IV/Shiny Bonuses**:
  * Stepping onto the Hotspot triggers a wild battle. Defeating or catching the Pokémon increments the Scanner Chain.
  * The chain is preserved as long as the player remains in the same route map section.
  * **IV Guarantees**:
    * Chain $\ge 1$: At least 1 guaranteed perfect (31) IV stat.
    * Chain $\ge 3$: At least 2 guaranteed perfect (31) IV stats.
    * Chain $\ge 6$: At least 3 guaranteed perfect (31) IV stats.
  * **Shiny Hunting**: Every chain count (up to 10) adds 2 extra shiny rolls during personality generation:
    $$\text{Extra Shiny Rolls} = 2 \times \min(\text{Chain}, 10)$$

---

## 7. Speaker Portrait (Mugshot) Dialogue System

NPC dialogue interactions are enhanced by displaying character portraits during conversations.

### Single and Simultaneous Double-Portraits
* Displays 64x64 speaker portraits (mugshots) above the text box.
* Supports **simultaneous double-portraits** (e.g. displaying a speaker on the left side at X=36 and another on the right side at X=204).
* Script commands `showmugshot mugshotId position` and `clearmugshot` manage visibility.

### Makefile Compilation Integration
* Raw `.png` files placed in `graphics/mugshots/` are automatically detected and compiled into GBA-compatible `.4bpp` and `.gbapal` files during building using `convert_mugshot.py`.

---

## 8. Dynamic Level & Boss Scaling

To maintain a challenging gameplay experience, Solid-Oak features dynamic level scaling systems.

### Boss Level Scaling
* When `FLAG_SCALE_BOSS_BATTLE` is set, major trainer battles dynamically adjust their party levels based on the highest level in the player's active team.
* The level offset is determined by `VAR_SCALE_LEVEL_OFFSET` (defaults to **+5**).
* **Anti-Trivialization Clamping**: If the calculated scaled level is lower than the boss's design baseline, it remains at the baseline (i.e. levels will not scale down below their default values if the player is under-leveled).
* **Easy/Hard Modes**: Setting a negative offset (e.g., **-5** for Easy Mode, **-10** for Very Easy Mode) enables down-scaling. Levels are clamped between 1 and 100.

### Wild Pokémon Scaling
* When `FLAG_SCALE_WILD_POKEMON` is enabled, wild encounters in the overworld dynamically scale to match the player's team level:
  * The wild level is chosen randomly between `gPlayerParty[MaxLvl] - 10` and `gPlayerParty[MaxLvl]`.

---

## 9. Workbench Crafting System

A field crafting system has been implemented to allow players to manufacture Protoballs and traditional medicines during their journey.

### Crafting Ingredients
* **Apricorns** (Red, Blue, Green, Black Apricorns).
* **Berries** (Razz, Bluk, Nanab, Wepear, Pinap Berries).
* **Conversion Kits** (Purchasable at Poké Marts for 500 Poké).

### Crafting Recipes
* **Protoballs**:
  * $1 \text{ Red Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Red Protoball}$
  * $1 \text{ Blue Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Blu Protoball}$
  * $1 \text{ Green Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Grn Protoball}$
  * $1 \text{ Black Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Blk Protoball}$
* **Traditional Medicine (Bitter Herbs)**:
  * $1 \text{ Razz Berry} \rightarrow 1 \text{ Energy Powder}$ (Heals 50 HP, lowers friendship)
  * $1 \text{ Bluk Berry} \rightarrow 1 \text{ Energy Tonic}$ (Heals 100 HP, custom item, lowers friendship)
  * $1 \text{ Nanab Berry} \rightarrow 1 \text{ Energy Root}$ (Heals 200 HP, friendship penalty)
  * $1 \text{ Wepear Berry} \rightarrow 1 \text{ Heal Powder}$ (Cures status conditions, friendship penalty)
  * $1 \text{ Pinap Berry} \rightarrow 1 \text{ Revival Herb}$ (Fully revives fainted Pokémon, friendship penalty)

---

## 10. Quest Log & Start Menu Integration

A custom Quest Log interface is integrated directly into the player's Start Menu to track story milestones and research objectives.

### Start Menu Access
* Selecting the "POKéDEX" option in the Start Menu opens a custom multi-choice prompt ("Journal"):
  * **POKéDEX**: Opens the standard Pokédex.
  * **QUEST LOG**: Opens the custom Quest Log screen.

### Quest Log Interface & Features
* **Tab Navigation**: The Quest Log is organized into three tabs, navigable using Left/Right on the D-Pad:
  1. **MAIN STORY**
  2. **SIDE QUESTS**
  3. **RESEARCH**
* **Dynamic Color Indicators**: Quests are color-coded dynamically:
  * **Green**: Completed quests.
  * **Dark Gray**: Active/unlocked quests.
  * **Red ("????")**: Locked quests.
* **Details and Icons**: Selecting a quest renders its description, status, and associated sprite icon.
* **Interactive Town Map Tracker**: Pressing the A button on an unlocked quest displays the quest's location directly on the Town Map by overriding the region map's focal point. Returning from the map resumes the Quest Log cleanly.

### Implemented Quests
1. **Oak's Parcel** (Main): Deliver the Viridian Poké Mart parcel to Prof. Oak.
2. **Pokédex Completion** (Research): Complete the Kanto Pokédex.
3. **Pewter Gym Challenge** (Main): Defeat Brock.
4. **Cerulean Gym Challenge** (Main): Defeat Misty.
5. **Pokémon Championship** (Main): Defeat the Elite Four.
6. **Gengar Evolution** (Research): Study Gengar's evolution.

---

## 11. Dojo Move Tutors & TM Case Restrictions

Movesets and training progression have been overhauled by shifting moves away from direct items to NPC interactions.

* **TM Direct Use Blocks**: TMs can no longer be used directly from the bag or TM Case. Attempting to use a TM displays the message:
  `"TMs cannot be used directly. Learn moves from Dojo Tutors!"`
* **Dojo Move Tutors**: Instead, players learn moves from specialized Dojo Move Tutors. These tutors dynamically populate a list of available moves that unlock as the player defeats specific trainers or achieves in-game milestones.
* **Badge-free HM Overworld Usage**: Players no longer need specific gym badges to use HM moves (Cut, Fly, Surf, Strength, Flash, Rock Smash, Waterfall) in the overworld. The system simply checks if the corresponding HM item is in the player's bag.
* **Fly Map Case Integration**: Using HM02 (Fly) from the TM Case directly opens the overworld Fly Map, allowing the player to warp to visited cities, bypassing the need to navigate the party menu.

---

## 12. Variable Team Preview & 3v3 Battles

A team preview mechanism has been built to support competitive-style battle formats.

* **Pre-Battle Team Preview**: Players can preview the opponent's team (rendered as sprite sheets) before committing to a battle.
* **Variable Selection Limits**: The system supports selection limits (from 1v1 up to 6v6) set via the game variable `gSpecialVar_0x8008` (defaulting to 3v3).
* **Party Reordering and Restoration**: When the player selects their combatants, the engine reorders the party to put the chosen Pokémon at the front, zeroes out the rest of the party slots, and sets the active party size to the selection count. Once the battle ends, the engine automatically restores the full original party, positions, and stats.
* **Asymmetric Team Selection**: Added support for asymmetric team selection counts for team preview battles.
* **Matchup-Based AI Counter-Selection**: Opponent AI matchups now perform dynamic counter-selections based on typing and stats during preview. Move coverage type advantages are factored into matchup selection.
* **Variable Team Preview Mode**: When `FLAG_VARIABLE_PREVIEW_MODE` is active, selection limits dynamically scale to match the opponent's party size rather than remaining locked to a fixed size limit.

---

## 13. S.S. Anne Spawning Room & Game Intro

New games no longer start in the player's bedroom in Pallet Town. Instead:
* The player spawns in **S.S. Anne 1F Room 6** (a custom cabin room).
* The player starts with the **S.S. Ticket** in their bag, the Pokédex activated, and standard starter flags already set.
* Starter choices (Growlithe, Nidoran M, Exeggcute) are available in the room, where players choose their first partner to begin.
* **Custom BGM (Sea Shanty 2)**: All S.S. Anne maps feature a custom MIDI track of RuneScape's *Sea Shanty 2*. The arrangement includes four custom-rendered 16kHz instruments (Accordion, Flute, Guitar, and Oboe) with looping support.

---

## 14. Monotype Battle Format

* Implemented support for monotype restricted battles via `FLAG_MONOTYPE_BATTLE` and `VAR_MONOTYPE_RESTRICTION`.
* When active, the player is barred from selecting or switching in any Pokémon that does not share the type specified in the restriction variable.
* Switching a non-eligible Pokémon prints the message:
  `"[NICKNAME] is not a [TYPE]-type Pokémon!"`

---

## 15. Day-Night Window Lighting

* The day-night cycle is enhanced with `UpdateOverworldWindowLights`.
* This updates specific window tile palettes marked with alpha flags in the overworld dynamically as the time of day shifts to night or morning, rendering glowing windows in Pallet Town and other maps during dark hours.

---

## 16. Water/Underwater Battles & Dive HM Eligibility Checks

* Added support for underwater/water battles.
* Integrates custom overworld Dive HM eligibility checks and mechanics.

---

## 17. Quest-Gated Evolutions

Specific trade and special evolutions are blocked until their respective story/research quest flags are set:
* **Gengar** evolution is blocked until `FLAG_QUEST_KNOW_GENGAR_EVO` is set.
* **Slowbro / Slowking** evolutions are blocked until `FLAG_QUEST_KNOW_SLOWPOKE_EVOS` is set.

---

## 18. Route 23 Gate Removals

* Traditional badge checkpoints, guards, and gate triggers on Route 23 checking for the player's 8 badges have been completely removed.
* Access to Indigo Plateau and Victory Road is fully open, bypassing the gym badge check scripts.

---

## 19. Progressive Safari Zone Stages

* **Dynamic Wild Encounters**: The wild encounters in all Safari Zone maps (Center, East, North, and West) are split into **5 progressive stages** (Stage 0 to Stage 4), governed by the game variable `VAR_SAFARI_ZONE_STAGE`.
* **Stage-Based Wild Pools**: As the stage variable changes, the game automatically switches the active wild encounter table (header) to pull from different species pools and levels defined in `wild_encounters.json`.
* **Pokédex Area Map Integration**: The Pokédex Area tracking system (`GetSpeciesPokedexAreaMarkers` and the Pokédex Emerald Area screen) dynamically filters Safari Zone map section markers to only display area highlights for a species if it is catchable in the *currently active* Safari Zone stage.
* **Visual map & tileset updates**: Safari Zone layouts and Fuchsia City assets have been updated to support stage-specific visual transitions.

---

## 20. QoL & Miscellaneous Adjustments

* **Help System Removal**: Disables all help system triggers in the main callbacks and removes the "HELP" mode option from the options menu (defaulting to LR buttons).
* **Pokédex Interface Enhancements**:
  * Bypasses the initial habitat menu screen entirely to jump straight to the Kanto/National list.
  * Adds total `Seen:` and `Owned:` counters to the Pokédex list header.
* **Double Battle with 1 Pokémon**:
  * Allows players to engage in double battles even if they only have a single usable Pokémon in their party (enabled via `FLAG_DOUBLE_BATTLE_WITH_ONE_MON`).
* **Repel Auto-Prompt**:
  * Tracks `VAR_LAST_REPEL_LURE_USED` (mapped to `0x403F`) to prompt the player to reuse a Repel or Lure automatically when their current one runs out.
* **Follower Overworld Toggle**:
  * Support for dynamically toggling follow behavior in overworld scripts using flag `0x0C0` (`B_FLAG_FOLLOWERS_DISABLED`).
* **Trainer Card Research Titles**:
  * Updates the trainer card research title based on research milestones.
* **Trainer Rematch Requirements**:
  * Sets badge requirements for rematches (`OW_REMATCH_BADGE_COUNT`) to **0**, allowing immediate rematches.
* **Option Menu BGM Speed Options**:
  * Adds a new "BGM SPEED" setting in the Option Menu. Players can adjust the playback speed of all background music to **NORMAL**, **1/2 (2x SLOW)**, or **1/3 (3x SLOW)**. This configuration is stored persistently in the player's Save Block (`SaveBlock2`) and regulates tempo controls dynamically in the GBA sound engine.
* **Option Menu Layout Fix**:
  * Resolved VRAM block overlapping conflicts in the Option Menu by shifting the top instruction bar's VRAM baseBlock, allowing clean background graphics rendering with the expanded menu height.
* **Default Configurations Enabled**:
  * Default 10% chance for wild double battles (`B_DOUBLE_WILD_CHANCE`).
  * Double wild, smart wild AI, and no catching flags registered.
  * Overworld item descriptions set to show always.
  * Berry mutations and immortal berry trees enabled.
  * Time-of-day encounter tables enabled.

---

## 21. Triple-Layer Metatiles (opt-in, disabled by default)

* **Engine support**: `OW_TRIPLE_LAYER_METATILES` (`include/config/overworld.h`) is a global switch that changes metatiles from 8 tiles/2-layer to 12 tiles/3-layer, letting a single metatile use all 3 real overworld background layers at once instead of only ever 2 (`METATILE_LAYER_TYPE_NORMAL/COVERED/SPLIT`). This unlocks richer terrain stacking (e.g. grass overlapping a ledge overlapping a tree canopy) directly in Porymap.
* **Off by default**: This is a global, all-or-nothing format change — `NUM_TILES_PER_METATILE` is a single compile-time constant used by every tileset, so there's no per-map opt-in. Flipping the flag on requires migrating every existing `data/tilesets/*/metatiles.bin` first.
* **Migration**: Run `tools/migrate_triple_layer_metatiles.py` (supports `--dry-run`) once before enabling the flag — it expands every metatile to 12 tiles, padding in a blank layer wherever the metatile's old layer type left one unused, so existing maps render unchanged until you start repainting the new layer.
* **Porymap**: After migrating and setting `OW_TRIPLE_LAYER_METATILES TRUE`, also set `enable_triple_layer_metatiles=1` in `porymap.project.cfg` so Porymap's metatile editor agrees with the C build on the 12-tiles-per-metatile format.
* **Doors**: Door-open tile animations (`DrawDoorMetatileAt` in `src/field_camera.c`) always use the legacy 2-layer covered-style draw, since door tiles come from a small standalone buffer rather than the tileset's metatile array.

---

## Fork Commit Log

The following commits represent the custom features introduced in the `Solid-Oak` branch:

| Commit Hash | Author | Description |
| :--- | :--- | :--- |
| `c64975cf9` | Zachary Schalberg | Commit BGM speed option sound wrappers, header declarations, and SaveBlock2 bitfield allocation |
| `6acb75637` | Zachary Schalberg | Fix Option Menu background graphics glitch by shifting top instruction bar baseBlock to 0x1BC to resolve VRAM conflict |
| `df2631016` | Zachary Schalberg | Add Sea Shanty 2 (original MIDI BGM) to S.S. Anne maps with custom looping 16kHz OSRS soundfont instruments |
| `df0a3b296` | Zachary Schalberg | feat: Remove Route 23 badge check gates, triggers, and corresponding scripts |
| `a8fb7c703` | Zachary Schalberg | feat: Declare TryAddFamilyReserveIconToHealthbox for healthbox indicator |
| `04ad0a0c4` | Zachary Schalberg | feat: Implement Variable Team Preview Mode and add menu option to Battle Tester |
| `aeb9e791a` | Zachary Schalberg | Factor move coverage into trainer pool matchup scoring |
| `ed800d36c` | Zachary Schalberg | feat: Add opponent HP bar indicator for family turned in at reserve |
| `4aaf7a699` | Zachary Schalberg | feat: Implement Advanced IV Scanner overworld key item with chaining, water surfing, and visual shake effects |
| `8d10c1dbe` | Zachary Schalberg | Update features documentation table and adjust map layouts and warp configurations for Lavender Town Fuji Lab Lobby and Vermilion Gym |
| `cc7471a0e` | Zachary Schalberg | Revise medicine crafting recipes to use bitter herbs |
| `b4ef257f8` | Zachary Schalberg | Configure repel variables, follower disable flag, and gate Gengar/Slowpoke evolutions behind quests |
| `c911404a9` | Zachary Schalberg | Commit converted mugshot graphics and test script text |
| `65c4f2b9f` | Zachary Schalberg | Update player bedroom signpost script to test text colors with double portraits |
| `36c6daa8f` | Zachary Schalberg | Add support for simultaneous double-portraits during dialogue |
| `d0428b095` | Zachary Schalberg | Summary Screen: Dynamically unlock IV/EV viewer when IV Scanner item is in bag |
| `2ed18735e` | Zachary Schalberg | IV Scanner: Omit perfect stats line entirely if count is 0 |
| `1c5640a9c` | Zachary Schalberg | IV Scanner: Refactor battle text to 2-paragraph 4-sentence layout with perfect stats count |
| `e21e3a5d1` | Zachary Schalberg | IV Scanner: Add DoShinySparkles on Outstanding Pokémon to supersede fanfare |
| `68afcdac6` | Zachary Schalberg | IV Scanner: Replace perfect IV text announcement with MUS_LEVEL_UP fanfare |
| `2e4d3104b` | Zachary Schalberg | IV Scanner: Construct perfect stats count string dynamically to fix nested placeholder issue |
| `42243b89e` | Zachary Schalberg | IV Scanner: Add perfect IV(s) count and status indication |
| `cef17da66` | Zachary Schalberg | Integrate auto-mugshot conversion into Makefile build rules |
| `54ff54cb9` | Zachary Schalberg | Make convert_mugshot.py dynamically scan graphics/mugshots/ |
| `c4fa55f92` | Zachary Schalberg | Implement IV Scanner item and L-button battle shortcut |
| `2c7824c15` | Zachary Schalberg | Add speaker portrait (mugshot) system for NPC dialogues |
| `82e74e563` | Zachary Schalberg | Update Fuchsia & Viridian map layouts, general tilesets, script menu constants, and new game flags |
| `0c95a266f` | Zachary Schalberg | Implement Pokémon Research Turn-in System points breakdown and swap Rotom reward for Beldum |
| `dc099db3f` | Zachary Schalberg | Merge branch 'claude/long-grass-layering-a4s82f' into temp-grass-test |
| `b2f82ad44` | Zachary Schalberg | Import Gen 3 Pokédex sprites in GSC/Gen 2 style & fix type icon palette bug |
| `a7d5d27ee` | Zachary Schalberg | Implement R-button quick throw support for Razz/Nanab Berries. Reset selector to last thrown Poké Ball (or first ball in bag if none thrown yet) after throwing a berry. |
| `f4c107993` | Zachary Schalberg | Implement active berry catch rate boosts, research mastery multipliers, and trainer card research title system. Fix berry throwing freezes and item use null pointer safety. |
| `5b8958db4` | Zachary Schalberg | Add water/underwater battle support, Dive HM, and related eligibility checks |
| `4c4a2bfe9` | Zachary Schalberg | Add MB_LONG_GRASS_SOUTH_EDGE (0x04) to long grass behavior |
| `7c1a3745b` | Zachary Schalberg | Fix long grass: add MB_LONG_GRASS constant and enable metatile checks |
| `5c0fbf247` | Zachary Schalberg | Implement asymmetric team selection counts for team preview battles |
| `a711b5705` | Zachary Schalberg | Fix monotype validation, boss scaling offset, and party preview issues |
| `7afcc79c2` | Zachary Schalberg | Fix Fuji Lab room limit in storage check and apply fadescreenswapbuffers to lobby/room scripts |
| `759ba250d` | Zachary Schalberg | Fix FujiLab_IsSlotEmpty reading slot from wrong variable (gSpecialVar_Result -> gSpecialVar_0x8006) |
| `3e0944077` | Zachary Schalberg | Restore original wild encounter tables and fix glitch pokemon |
| `e27d9a2e2` | Zachary Schalberg | Show money box in Courier Whistle script to prevent window 0 corruption |
| `e19412cdf` | Zachary Schalberg | Add Courier Whistle key item to summon Pidgeot Courier outdoors |
| `175ad4c93` | Zachary Schalberg | Use fadescreenswapbuffers in Courier script to preserve time-of-day/weather palette shading |
| `070f967a0` | Zachary Schalberg | Implement staged multi-select Pidgeot Courier system and fix cart validation return type bug |
| `d8cee565a` | Zachary Schalberg | Implement Mr. Fuji's Pokémon Sanctuary and Pidgeot Courier system, including overworld dynamic follower sprite fix |
| `0de5492b5` | Zachary Schalberg | Import Viridian City layout & custom tilesets, fix palette channel order, and add automated HMA import tools |
| `a244055cf` | Zachary Schalberg | Bypass duplicate species and item checks for team preview choose-mon screen |
| `09573d478` | Zachary Schalberg | Implement opponent AI matchup-based counter-selection and research ball selectability restrictions |
| `ae5166074` | Zachary Schalberg | Merge remote-tracking branch 'origin/Solid-Oak' into Solid-Oak |
| `4261e72fc` | Zachary Schalberg | Merge branch 'cawtds:master' into Solid-Oak |
| `eef408546` | Zachary Schalberg | Implement dynamic level scaling for bosses, easy mode, wild overworld, and tester sailor menu options |
| `30eaa3e9c` | Zachary Schalberg | Add size/removal scripting specials and size researcher NPC |
| `eb1351b45` | Zachary Schalberg | Expand Pokédex seen/caught counters to 8-bit (up to 255) for up to 400 species |
| `c7f149d0d` | Zachary Schalberg | Implement GetSpeciesSeenCount and GetSpeciesCaughtCount scripting specials |
| `eb0a3d9bc` | Zachary Schalberg | Do not increment Seen count of player's own Pokémon in battle |
| `effb5d6ab` | Zachary Schalberg | Format seen/caught count display as Seen/Caught: X/Y |
| `7ddb7bc4a` | Zachary Schalberg | Reposition Seen/Owned counts to stats window to prevent description overlap |
| `83711c5e4` | Zachary Schalberg | Implement individual seen/caught counts and restrict Pokédex to Gen 3 |
| `331d54440` | Zachary Schalberg | Implement size-based battle modifiers, summary screen percentiles, capture notices, and Pokédex linear percentile slider alignment |
| `eca1fbe30` | Zachary Schalberg | Implement individual Pokemon height/weight memo display and battle engine scaling |
| `20c3bf95f` | Zachary Schalberg | Feature: Implement Dojo Move Tutor mechanics, TM direct use blocks, HM bag checks, overworld Fly Map usage, and remove badge requirements |
| `218dbef7c` | Zachary Schalberg | Add workbench crafting item, workbench field use script/specials, and register menus/flags |
| `7139bc942` | Zachary Schalberg | Commit outstanding modifications from day-night window, monotype battle, and start room adjustments |
| `57a7e35d5` | Zachary Schalberg | Implement variable team preview selector (1v1 to 6v6) and update tester NPC |
| `cc719ecc2` | Zachary Schalberg | Bypass Pokédex habitat selection menu, add Seen/Owned to header, and implement 3v3 Pokemon selector |
| `b8c49565b` | Zachary Schalberg | Fix preprocessor conditional parser bug to map and enable final evolutions' Gen 2 sprites |
| `b660a9a0c` | Zachary Schalberg | Add Vermilion City tester sailor NPC and support for double battles with one Pokémon |
| `b0e134ff4` | Zachary Schalberg | Implement quest map location display and fix whiteout crash |
| `41698f1df` | Zachary Schalberg | Implement categorized Quest Log screen with dynamic color rendering, tab navigation, and Gengar Research quest |
| `96a5ccb63` | Zachary Schalberg | Implement Protoballs & Research Balls, clean up standard Poké Balls, and align whiteout logic |
| `cbc3a79b6` | Zachary Schalberg | update toolchain variable |
| `46bfdcf56` | Zachary Schalberg | Add runtime grayscale Pokédex sprites toggle (default disabled) |
| `ad2cf660e` | Zachary Schalberg | Implement Gen 2 sprites infrastructure and import all 251 front sprites |
| `8b0ca6838` | Zachary Schalberg | Disable help system triggers and remove HELP button mode option |
| `70dd14441` | Zachary Schalberg | mega sol fixes |
| `5d6f5ca4c` | Zachary Schalberg | Sync/battle engine final (#185) |
| `15fc26497` | Zachary Schalberg | fix dowsing machine |
| `efe8eed34` | Zachary Schalberg | Updated Makefile |
