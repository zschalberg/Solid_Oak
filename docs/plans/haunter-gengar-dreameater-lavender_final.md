# Implementation Plan: Lavender Tower Dream Eater Evolution (Haunter $\rightarrow$ Gengar) [Revised]

## 1. Goal & Player-Facing Outcome

### Goal
Implement a custom location- and move-specific evolution method for **Haunter** to evolve into **Gengar**. Haunter will track cumulative HP drained using the move **Dream Eater** (`MOVE_DREAM_EATER`) while battling inside **Lavender Tower** (`MAPSEC_POKEMON_TOWER`). Once a specified threshold of cumulative HP drained (200 HP, defined by `GENGAR_DREAM_EATER_EVO_HP`) is reached, Haunter becomes eligible for evolution and will evolve into Gengar at the end of the battle (or upon leveling up).

### Interaction & Replacement of the Existing Quest Gate
Currently, Gengar's evolution is hard-gated behind `FLAG_QUEST_KNOW_GENGAR_EVO` in [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490). This plan updates the quest gate interaction as follows:
1. **Quest Flow**: The player unlocks Quest 7 ("GENGAR EVOLUTION", `FLAG_QUEST_7_ACTIVE`).
2. **Gate Refactoring**: [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490) is updated to permit evolution evaluation for `SPECIES_GENGAR` when `FLAG_QUEST_7_ACTIVE` or `FLAG_QUEST_KNOW_GENGAR_EVO` is set.
3. **Requirement Enforcement**: Evolution will only occur once Haunter satisfies the new `IF_HP_DRAINED_IN_MAPSEC_GE` condition (draining $\ge 200$ HP in `MAPSEC_POKEMON_TOWER` using `MOVE_DREAM_EATER`). Traditional trade and Linking Cord evolutions for Haunter are replaced by this custom condition in [gen_1_families.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/data/pokemon/species_info/gen_1_families.h#L12145-L12146).
4. **Quest Completion**: Upon successful evolution into Gengar, the evolution scene callback automatically sets `FLAG_QUEST_KNOW_GENGAR_EVO` and `FLAG_QUEST_7_COMPLETED`, cleanly completing the Quest Log entry.

---

## 2. Affected Files and Systems

| File Path | System / Purpose | Key Functions / Structs / Constants |
| :--- | :--- | :--- |
| [include/constants/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/constants/pokemon.h) | Evolution condition enum & threshold constants | `enum EvolutionConditions`, `IF_HP_DRAINED_IN_MAPSEC_GE`, `#define GENGAR_DREAM_EATER_EVO_HP 200` |
| [include/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/pokemon.h) | Mon data declarations & evolution structs | [struct Evolution](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/pokemon.h#L382), [struct EvolutionParam](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/pokemon.h#L374), `MON_DATA_EVOLUTION_TRACKER` |
| [include/battle_util.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/battle_util.h) | Battle utility function prototype | [TryUpdateEvolutionTracker](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/battle_util.h#L417) |
| [src/battle_move_resolution.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c) | Battle move resolution & HP drain calculation | [MoveEndAbsorb](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c#L2198), [SetHealScript](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c#L2180) |
| [src/battle_util.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c) | Evolution tracker updating logic | [TryUpdateEvolutionTracker](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c#L10808) |
| [src/pokemon.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c) | Evolution condition evaluation & species unlocking | [DoesMonMeetAdditionalConditions](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4158), [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490), [GetEvolutionTargetSpecies](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4504) |
| [src/evolution_scene.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/evolution_scene.c) | Evolution completion callback & quest completion | `EvolutionScene`, setting quest flags on Gengar evolution |
| [src/data/pokemon/species_info/gen_1_families.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/data/pokemon/species_info/gen_1_families.h) | Haunter species definition & evolution table | `[SPECIES_HAUNTER].evolutions` (lines 12145–12146) |
| [src/quest_log_menu.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/quest_log_menu.c) | Quest Log entry definition | Quest 7 entry (`GENGAR EVOLUTION`) |
| [data/maps/PokemonTower_2F/scripts.pory](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/data/maps/PokemonTower_2F/scripts.pory) | Poryscript dialogue/quest hint | NPC dialogue hint in Lavender Tower |

---

## 3. Step-by-Step Implementation Approach

### Step 1: Define Evolution Condition & Target Threshold
1. In [include/constants/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/constants/pokemon.h#L325), add a new evolution condition to `enum EvolutionConditions`:
   ```c
   IF_HP_DRAINED_IN_MAPSEC_GE, // Drained at least X HP in a specific map section with move Y
   ```
2. Define the threshold constant in [include/constants/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/constants/pokemon.h):
   ```c
   #define GENGAR_DREAM_EATER_EVO_HP 200
   ```

### Step 2: Track HP Drained During Battle
1. In [src/battle_move_resolution.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c#L2231) inside [MoveEndAbsorb](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c#L2198):
   - Reuse the existing pre-calculated `healAmount` variable (`s32 healAmount = (gBattleStruct->moveDamage[gBattlerTarget] * GetMoveAbsorbPercentage(gCurrentMove) / 100);`) rather than re-computing `drainedHp`.
   - Use `gMapHeader.regionMapSectionId` consistently for mapsec verification.
   - When `GetMoveEffect(gCurrentMove) == EFFECT_DREAM_EATER` and `gMapHeader.regionMapSectionId == MAPSEC_POKEMON_TOWER`:
     ```c
     if (healAmount > 0 && gMapHeader.regionMapSectionId == MAPSEC_POKEMON_TOWER)
     {
         TryUpdateEvolutionTracker(IF_HP_DRAINED_IN_MAPSEC_GE, healAmount, MOVE_DREAM_EATER);
     }
     ```
2. In [src/battle_util.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c#L10841) inside [TryUpdateEvolutionTracker](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c#L10808):
   - Add a case for `IF_HP_DRAINED_IN_MAPSEC_GE` using `gMapHeader.regionMapSectionId` consistently:
     ```c
     case IF_HP_DRAINED_IN_MAPSEC_GE:
         if (gMapHeader.regionMapSectionId == evolutions[i].params[j].arg1
          && usedMove == evolutions[i].params[j].arg2)
         {
             SetMonData(monAtk, MON_DATA_EVOLUTION_TRACKER, &val);
         }
         break;
     ```
   - **Persistence Design**: Unlike `IF_RECOIL_DAMAGE_GE`, `IF_HP_DRAINED_IN_MAPSEC_GE` does **NOT** reset `val` to 0 when the Pokémon faints or switches out. The tracker value accumulates continuously in `BoxPokemonSubstruct1` across turns, battles, and Pokémon Center heals until the 200 HP threshold is hit.

### Step 3: Evaluate Evolution Condition in `pokemon.c`
1. In [src/pokemon.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4428) inside [DoesMonMeetAdditionalConditions](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4158):
   - Add a case for `IF_HP_DRAINED_IN_MAPSEC_GE`:
     ```c
     case IF_HP_DRAINED_IN_MAPSEC_GE:
         // arg1: target mapsec (MAPSEC_POKEMON_TOWER)
         // arg2: move ID (MOVE_DREAM_EATER)
         // arg3: required HP threshold (GENGAR_DREAM_EATER_EVO_HP)
         if (gMapHeader.regionMapSectionId == params[i].arg1
          && evolutionTracker >= params[i].arg3)
         {
             currentCondition = TRUE;
         }
         break;
     ```
   - **Rationale for Combined Condition**: A single combined condition (`IF_HP_DRAINED_IN_MAPSEC_GE`) is chosen over separate `IF_IN_MAPSEC` and generic HP tracker conditions because mapsec validation must occur **during battle** at tracker increment time. If tracking were mapsec-agnostic, HP drained in other routes would count toward evolution, violating the core requirement ("track HP drained while inside Lavender Tower").

### Step 4: Refactor Quest Gate & Quest Log Synchronization
1. Update [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490) in [src/pokemon.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c):
   - Update `SPECIES_GENGAR` to return `TRUE` when `FLAG_QUEST_7_ACTIVE` or `FLAG_QUEST_KNOW_GENGAR_EVO` is set:
     ```c
     case SPECIES_GENGAR:
         return FlagGet(FLAG_QUEST_7_ACTIVE) || FlagGet(FLAG_QUEST_KNOW_GENGAR_EVO);
     ```
2. In [src/evolution_scene.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/evolution_scene.c), when evolution into `SPECIES_GENGAR` completes:
   - Set the quest completion flags:
     ```c
     if (targetSpecies == SPECIES_GENGAR)
     {
         FlagSet(FLAG_QUEST_KNOW_GENGAR_EVO);
         FlagSet(FLAG_QUEST_7_COMPLETED);
     }
     ```

### Step 5: Update Evolution Table Data
1. In [src/data/pokemon/species_info/gen_1_families.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/data/pokemon/species_info/gen_1_families.h#L12145-L12146), replace Haunter's current trade/Linking Cord evolutions:
   ```diff
   -        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GENGAR},
   -                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GENGAR}),
   +        .evolutions = EVOLUTION({EVO_BATTLE_END, 0, SPECIES_GENGAR, 
   +                                CONDITIONS({IF_HP_DRAINED_IN_MAPSEC_GE, MAPSEC_POKEMON_TOWER, MOVE_DREAM_EATER, GENGAR_DREAM_EATER_EVO_HP})},
   +                                {EVO_LEVEL, 1, SPECIES_GENGAR, 
   +                                CONDITIONS({IF_HP_DRAINED_IN_MAPSEC_GE, MAPSEC_POKEMON_TOWER, MOVE_DREAM_EATER, GENGAR_DREAM_EATER_EVO_HP})}),
   ```
   *(Using `EVO_BATTLE_END` allows Haunter to evolve immediately upon winning/finishing the battle where the 200 HP drain threshold is reached, while `EVO_LEVEL` acts as a fallback on level up).*

---

## 4. Data-Driven (JSON) & Poryscript Changes

1. **Quest 7 Mapsec Clarification**:
   - In [src/quest_log_menu.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/quest_log_menu.c#L166), Quest 7 (`GENGAR EVOLUTION`) specifies `.mapsec = MAPSEC_LAVENDER_TOWN`. This is intentional: `.mapsec` in `quest_log_menu.c` designates the Town Map focal point (highlighting Lavender Town on the overworld map when A is pressed on the quest). The evolution mechanic itself checks `MAPSEC_POKEMON_TOWER` (the specific indoor mapsec for Pokémon Tower 1F–7F).
2. **Poryscript Quest Hint**:
   - Add an NPC script in `data/maps/PokemonTower_2F/scripts.pory` giving a hint:
     ```poryscript
     script PokemonTower_2F_EventScript_ChannelerHint {
         msgbox(format("They say Haunter draining the dreams of spirits inside this tower can undergo a mysterious transformation..."), MSGBOX_NPC)
     }
     ```
   - Build via `make firered` to compile `.pory` to `.inc`.

---

## 5. Edge Cases & Risks

1. **Mapsec Stability During Battle**:
   - `gMapHeader.regionMapSectionId` is loaded during overworld map setup (e.g. entering `PokemonTower_3F`) and remains static throughout wild and trainer battles. It is not mutated by battle initialization (`CB2_InitBattle`), animations, or battle transitions. Therefore, `gMapHeader.regionMapSectionId` is stable for mid-battle checks in `MoveEndAbsorb` and post-battle checks in `TryEvolvePokemon`.
2. **10-Bit Evolution Tracker Storage**:
   - `MON_DATA_EVOLUTION_TRACKER` is capped at `1023` in `BoxPokemonSubstruct1`. The threshold of `200` HP fits safely within 10 bits. `min(1023, tracker + upAmount)` prevents bit overflow.
3. **Tracker Persistence Across Faint / Switch / Heals**:
   - `IF_HP_DRAINED_IN_MAPSEC_GE` does not clear progress when Haunter faints or switches. Cumulative drain persists across multiple battles in Pokémon Tower and stays saved in `struct BoxPokemon`.
4. **Overkill Damage vs. Drained HP**:
   - `gBattleStruct->moveDamage[gBattlerTarget]` reflects actual damage dealt to target's remaining HP. Overkill damage beyond the target's current HP does not artificially inflate the drain count.
5. **Evolution Interruption (B-Button Cancel)**:
   - If the player cancels evolution using the B button, `MON_DATA_EVOLUTION_TRACKER` remains at $\ge 200$. The next battle won in Lavender Tower will trigger `EVO_BATTLE_END` again, retrying evolution.

---

## 6. Verification & Testing Plan

### Build Target
Build via WSL:
```bash
make firered -j$(nproc)
```

### In-Game Test Steps
1. **Setup Test State**:
   - Give party a Haunter with move `MOVE_DREAM_EATER` and Hypnosis.
   - Warp player to Pokémon Tower 3F (`MAPSEC_POKEMON_TOWER`).
   - Set `FLAG_QUEST_7_ACTIVE`.
2. **Drain HP & Check Persistence**:
   - Put wild target to sleep and execute Dream Eater.
   - Verify `MON_DATA_EVOLUTION_TRACKER` increments by actual damage dealt (`healAmount`).
   - Allow Haunter to faint or switch out; confirm tracker value is preserved upon healing at Pokémon Center.
3. **Threshold & Evolution Trigger**:
   - Accumulate $\ge 200$ HP drained inside Pokémon Tower.
   - Finish battle. Verify evolution scene triggers immediately post-battle to evolve Haunter into Gengar.
4. **Quest Log Verification**:
   - Open Start Menu $\rightarrow$ POKéDEX $\rightarrow$ Journal $\rightarrow$ RESEARCH tab.
   - Confirm `GENGAR EVOLUTION` quest is marked complete (green) and `FLAG_QUEST_KNOW_GENGAR_EVO` is set.
