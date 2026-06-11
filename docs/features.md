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

### S.S. Anne Size Researcher NPC & Specials
A Size Researcher NPC is stationed in the **S.S. Anne 1F Corridor** to evaluate party Pokémon. Using new script specials:
* **`BufferMonPercentiles`**: Formats the selected Pokémon's height percentile (in `gStringVar2`) and weight percentile (in `gStringVar3`).
* **`RemoveSelectedPartyMon`**: Removes the chosen Pokémon from the player's party and compacts the remaining slots (returning `FALSE` if the player attempts to donate their last usable Pokémon).
* If a player donates their Pokémon to science, the researcher rewards them with a **Rare Candy**.
* Script specials **`GetMonHeight`**, **`GetMonWeight`**, **`GetMonHeightPercentile`**, and **`GetMonWeightPercentile`** are exposed to the scripting engine to query individual size details.

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
* **Red Protoball (Level Ball)**: Cannot capture Pokémon above **Level 10**.
* **Blu Protoball (Lure Ball)**: Cannot capture Pokémon above **Level 20**.
* **Grn Protoball (Friend Ball)**: Cannot capture Pokémon above **Level 30**.
* **Blk Protoball (Heavy Ball)**: Cannot capture Pokémon above **Level 40**.

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

---

## 4. Dynamic Level & Boss Scaling

To maintain a challenging gameplay experience, Solid-Oak features dynamic level scaling systems.

### Boss Level Scaling
* When `FLAG_SCALE_BOSS_BATTLE` is set, major trainer battles dynamically adjust their party levels based on the highest level in the player's active team.
* The level offset is determined by `VAR_SCALE_LEVEL_OFFSET`. If the offset is unset, it defaults to **+5**.
* **Anti-Trivialization Clamping**: If the calculated scaled level is lower than the boss's design baseline, it remains at the baseline (i.e. levels will not scale down below their default values if the player is under-leveled).
* **Easy/Hard Modes**: Setting a negative offset (e.g., **-5** for Easy Mode, **-10** for Very Easy Mode) enables down-scaling for players who prefer a lighter difficulty. Levels are clamped between 1 and 100.

### Wild Pokémon Scaling
* When `FLAG_SCALE_WILD_POKEMON` is enabled, wild encounters in the overworld dynamically scale to match the player's team level:
  * The wild level is chosen randomly between `gPlayerParty[MaxLvl] - 10` and `gPlayerParty[MaxLvl]`.
  * Abilities like Hustle, Pressure, or Vital Spirit still apply their normal level-boosting effects.

### Scripted Wild Bosses
* Using the native script call `Script_SetScaledWildBattle`, scripts can trigger boss wild battles (e.g. against a giant Tentacruel) that scale to the player's party level using variables:
  * `gSpecialVar_0x8004`: Species
  * `gSpecialVar_0x8005`: Minimum level floor
  * `gSpecialVar_0x8006`: Level offset
  * `gSpecialVar_0x8007`: Held item

### Vermilion City Tester Sailor
* An NPC Tester Sailor is stationed in Vermilion City to help test these systems. Talking to him brings up a debug menu to:
  * Toggle double battles with a single Pokémon.
  * Toggle wild overworld level scaling.
  * Fight a standard trainer battle.
  * Fight a scaled boss trainer battle with a custom offset (+2, +5, +10, +20, -5, -10).
  * Fight a scaled wild Tentacruel boss.

---

## 5. Workbench Crafting System

A field crafting system has been implemented to allow players to manufacture Protoballs during their journey.

* **Workbench Key Item**: Players use the portable **Workbench** Key Item from their bag to initiate field crafting.
* **Crafting Ingredients**:
  * **Apricorns** (Red, Blue, Green, Black Apricorns found in the world).
  * **Conversion Kits** (Purchasable at Poké Marts for 500 Poké).
* **Crafting Recipes**:
  * $1 \text{ Red Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Red Protoball}$
  * $1 \text{ Blue Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Blu Protoball}$
  * $1 \text{ Green Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Grn Protoball}$
  * $1 \text{ Black Apricorn} + 1 \text{ Conversion Kit} \rightarrow 1 \text{ Blk Protoball}$
* **Crafting Interface**: When accessed, a scripted dialogue loop calculates the maximum craftable quantity based on the ingredients in the player's bag, allows quantity selection (1, 5, 10, or Max), and processes the items.

---

## 6. Quest Log & Start Menu Integration

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
6. **Dummy Side Quest** (Side): A test quest toggled by interacting with the NES console in the player's bedroom.
7. **Gengar Evolution** (Research): Study Gengar's evolution.

---

## 7. Dojo Move Tutors & TM Case Restrictions

Movesets and training progression have been overhauled by shifting moves away from direct items to NPC interactions.

* **TM Direct Use Blocks**: TMs can no longer be used directly from the bag or TM Case. Attempting to use a TM displays the message:
  `"TMs cannot be used directly. Learn moves from Dojo Tutors!"`
* **Dojo Move Tutors**: Instead, players learn moves from specialized Dojo Move Tutors. These tutors dynamically populate a list of available moves that unlock as the player defeats specific trainers or achieves in-game milestones.
* **Badge-free HM Overworld Usage**: Players no longer need specific gym badges to use HM moves (Cut, Fly, Surf, Strength, Flash, Rock Smash, Waterfall) in the overworld. The system simply checks if the corresponding HM item is in the player's bag.
* **Fly Map Case Integration**: Using HM02 (Fly) from the TM Case directly opens the overworld Fly Map, allowing the player to warp to visited cities, bypassing the need to navigate the party menu.

---

## 8. Variable Team Preview & 3v3 Battles

A team preview mechanism has been built to support competitive-style battle formats.

* **Pre-Battle Team Preview**: Players can preview the opponent's team (rendered as sprite sheets) before committing to a battle.
* **Variable Selection Limits**: The system supports selection limits (from 1v1 up to 6v6) set via the game variable `gSpecialVar_0x8008` (defaulting to 3v3).
* **Party Reordering and Restoration**: When the player selects their combatants, the engine reorders the party to put the chosen Pokémon at the front, zeroes out the rest of the party slots, and sets the active party size to the selection count. Once the battle ends, the engine automatically restores the full original party, positions, and stats.

---

## 9. S.S. Anne Starter Spawning Cabin

New games no longer start in the player's bedroom in Pallet Town. Instead:
* The player spawns in **S.S. Anne 1F Room 6** (a custom cabin room).
* The player starts with the **S.S. Ticket** in their bag, the Pokédex activated, and standard starter flags already set.
* Starter choices (Growlithe, Nidoran M, Exeggcute) are available in the room, alongside a healing NPC, a test item ball containing Poké Balls, Protoballs, Apricorns, and a Workbench, and a scientist NPC who hosts a crafting station.

---

## 10. Monotype Battle Format

* Implemented support for monotype restricted battles via `FLAG_MONOTYPE_BATTLE` and `VAR_MONOTYPE_RESTRICTION`.
* When active, the player is barred from selecting or switching in any Pokémon that does not share the type specified in the restriction variable.
* Switching a non-eligible Pokémon prints the message:
  `"[NICKNAME] is not a [TYPE]-type Pokémon!"`

---

## 11. Day-Night Window Lighting

* The day-night cycle is enhanced with `UpdateOverworldWindowLights`.
* This updates specific window tile palettes marked with alpha flags in the overworld dynamically as the time of day shifts to night or morning, rendering glowing windows in Pallet Town and other maps during dark hours.

---

## 12. QoL & Miscellaneous Adjustments

* **Help System Removal**: Disables all help system triggers in the main callbacks and removes the "HELP" mode option from the options menu (defaulting to LR buttons).
* **Pokédex Interface Enhancements**:
  * Bypasses the initial habitat menu screen entirely to jump straight to the Kanto/National list.
  * Adds total `Seen:` and `Owned:` counters to the Pokédex list header.
* **Double Battle with 1 Pokémon**:
  * Introduces `FLAG_DOUBLE_BATTLE_WITH_ONE_MON` and an NPC Tester Sailor in Vermilion City to toggle it.
  * Allows players to engage in double battles even if they only have a single usable Pokémon in their party.
* **Default Configurations Enabled**:
  * Default 10% chance for wild double battles (`B_DOUBLE_WILD_CHANCE`).
  * Double wild, smart wild AI, and no catching flags registered.
  * Overworld item descriptions set to show always.
  * Berry mutations and immortal berry trees enabled.
  * Time-of-day encounter tables enabled.

---

## Fork Commit Log

The following commits represent the custom features introduced in the `Solid-Oak` branch:

| Commit Hash | Author | Description |
226: | `ae5166074` | Zachary Schalberg | Merge remote-tracking branch 'origin/Solid-Oak' into Solid-Oak |
227: | `4261e72fc` | zschalberg | Merge branch 'cawtds:master' into Solid-Oak |
228: | `eef408546` | Zachary Schalberg | Implement dynamic level scaling for bosses, easy mode, wild overworld, and tester sailor menu options |
229: | `30eaa3e9c` | Zachary Schalberg | Add size/removal scripting specials and size researcher test NPC on S.S. Anne |
230: | `eb1351b45` | Zachary Schalberg | Expand Pokédex seen/caught counters to 8-bit (up to 255) for up to 400 species |
231: | `c7f149d0d` | Zachary Schalberg | Implement GetSpeciesSeenCount and GetSpeciesCaughtCount scripting specials |
232: | `eb0a3d9bc` | Zachary Schalberg | Do not increment Seen count of player's own Pokémon in battle |
233: | `effb5d6ab` | Zachary Schalberg | Format seen/caught count display as Seen/Caught: X/Y |
234: | `7ddb7bc4a` | Zachary Schalberg | Reposition Seen/Owned counts to stats window to prevent description overlap |
235: | `83711c5e4` | Zachary Schalberg | Implement individual seen/caught counts and restrict Pokédex to Gen 3 |
236: | `331d54440` | Zachary Schalberg | Implement size-based battle modifiers, summary screen percentiles, capture notices, and Pokédex linear percentile slider alignment |
237: | `eca1fbe30` | Zachary Schalberg | Implement individual Pokemon height/weight memo display and battle engine scaling |
238: | `20c3bf95f` | Zachary Schalberg | Feature: Implement Dojo Move Tutor mechanics, TM direct use blocks, HM bag checks, overworld Fly Map usage, and remove badge requirements |
239: | `218dbef7c` | Zachary Schalberg | Add workbench crafting item, workbench field use script/specials, and register menus/flags |
240: | `7139bc942` | Zachary Schalberg | Commit outstanding modifications from day-night window, monotype battle, and start room adjustments |
241: | `57a7e35d5` | Zachary Schalberg | Implement variable team preview selector (1v1 to 6v6) and update tester NPC |
242: | `cc719ecc2` | Zachary Schalberg | Bypass Pokédex habitat selection menu, add Seen/Owned to header, and implement 3v3 Pokemon selector |
243: | `b8c49565b` | Zachary Schalberg | Fix preprocessor conditional parser bug to map and enable final evolutions' Gen 2 sprites |
244: | `b660a9a0c` | Zachary Schalberg | Add Vermilion City tester sailor NPC and support for double battles with one Pokémon |
245: | `b0e134ff4` | Zachary Schalberg | Implement quest map location display and fix whiteout crash |
246: | `41698f1df` | Zachary Schalberg | Implement categorized Quest Log screen with dynamic color rendering, tab navigation, and Gengar Research quest |
247: | `96a5ccb63` | Zachary Schalberg | Implement Protoballs & Research Balls, clean up standard Poké Balls, and align whiteout logic |
248: | `cbc3a79b6` | Zachary Schalberg | update toolchain variable |
249: | `46bfdcf56` | Zachary Schalberg | Add runtime grayscale Pokédex sprites toggle (default disabled) |
250: | `ad2cf660e` | Zachary Schalberg | Implement Gen 2 sprites infrastructure and import all 251 front sprites |
251: | `8b0ca6838` | Zachary Schalberg | Disable help system triggers and remove HELP button mode option |
252: | `efe8eed34` | Zachary Schalberg | Updated Makefile |
