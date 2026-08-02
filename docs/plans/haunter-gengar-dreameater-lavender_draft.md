# Implementation Plan: Lavender Tower Dream Eater Evolution (Haunter $\rightarrow$ Gengar)

## 1. Goal & Player-Facing Outcome

### Goal
Implement a location- and move-specific evolution method for **Haunter** to evolve into **Gengar**. Haunter will track cumulative HP drained using the move **Dream Eater** while battling inside **Lavender Tower** (`MAPSEC_POKEMON_TOWER`). Once a specified HP drain threshold (e.g., 200 HP) is reached, Haunter will evolve into Gengar at the end of the battle (or upon level up).

### Quest Gate Interaction & Replacement
Currently, Gengar's evolution is hard-gated behind `FLAG_QUEST_KNOW_GENGAR_EVO` via [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490). Under this new plan:
- The custom HP drain requirement in Lavender Tower becomes the functional gameplay mechanism for evolving Haunter into Gengar.
- [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490) is updated so that `SPECIES_GENGAR` is unlocked natively once the player has activated the Gengar Research Quest (`FLAG_QUEST_7_ACTIVE`) or unlocked unconditionally via the new evolution condition check.
- When Haunter successfully evolves into Gengar, the game sets `FLAG_QUEST_KNOW_GENGAR_EVO` and `FLAG_QUEST_7_COMPLETED`, updating the Quest Log entry ("GENGAR EVOLUTION") to completed status.

---

## 2. Affected Files and Systems

| File Path | System / Purpose | Key Functions / Structs / Constants |
| :--- | :--- | :--- |
| [include/constants/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/constants/pokemon.h) | Evolution condition enum & threshold constants | `enum EvolutionConditions`, `IF_HP_DRAINED_IN_MAPSEC_GE`, `GENGAR_DREAM_EATER_EVO_HP` |
| [include/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/pokemon.h) | Mon data declarations & evolution structs | [struct Evolution](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/pokemon.h#L382), [struct EvolutionParam](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/pokemon.h#L374), `MON_DATA_EVOLUTION_TRACKER` |
| [include/battle_util.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/battle_util.h) | Battle utility function prototype | [TryUpdateEvolutionTracker](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/battle_util.h#L417) |
| [src/battle_move_resolution.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c) | Battle move resolution for HP drain | [MoveEndAbsorb](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c#L2198), [SetHealScript](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c#L2180) |
| [src/battle_util.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c) | Evolution tracker updating logic | [TryUpdateEvolutionTracker](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c#L10808) |
| [src/pokemon.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c) | Evolution condition evaluation & species unlocking | [DoesMonMeetAdditionalConditions](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4158), [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490), [GetEvolutionTargetSpecies](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4504) |
| [src/evolution_scene.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/evolution_scene.c) | Evolution completion callback & quest completion | `EvolutionScene`, setting quest flags on Gengar evolution |
| [src/data/pokemon/species_info/gen_1_families.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/data/pokemon/species_info/gen_1_families.h) | Haunter species definition & evolution table | `[SPECIES_HAUNTER].evolutions` |
| [data/maps/PokemonTower_2F/scripts.pory](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/data/maps/PokemonTower_2F/scripts.pory) | Poryscript dialogue/quest hint | NPC dialogue hint in Lavender Tower |

---

## 3. Step-by-Step Implementation Approach

### Step 1: Define Evolution Condition & Target Threshold
1. In [include/constants/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/constants/pokemon.h#L325), add a new evolution condition to `enum EvolutionConditions`:
   ```c
   IF_HP_DRAINED_IN_MAPSEC_GE, // Drained at least X HP in a specific map section with move Y
   ```
2. Define the threshold constant (e.g. 200 HP) in [include/constants/pokemon.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/constants/pokemon.h):
   ```c
   #define GENGAR_DREAM_EATER_EVO_HP 200
   ```

### Step 2: Track HP Drained During Battle
1. In [src/battle_move_resolution.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_move_resolution.c#L2231) inside `MoveEndAbsorb()`:
   - Check if `GetMoveEffect(gCurrentMove) == EFFECT_DREAM_EATER` (or `gCurrentMove == MOVE_DREAM_EATER`).
   - Check if the current region map section is `MAPSEC_POKEMON_TOWER` via `GetCurrentRegionMapSectionId() == MAPSEC_POKEMON_TOWER`.
   - Calculate the actual HP drained: `s32 drainedHp = gBattleStruct->moveDamage[gBattlerTarget] * GetMoveAbsorbPercentage(gCurrentMove) / 100;`.
   - Call [TryUpdateEvolutionTracker](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/include/battle_util.h#L417):
     ```c
     if (drainedHp > 0 && GetCurrentRegionMapSectionId() == MAPSEC_POKEMON_TOWER)
     {
         TryUpdateEvolutionTracker(IF_HP_DRAINED_IN_MAPSEC_GE, drainedHp, MOVE_DREAM_EATER);
     }
     ```
2. In [src/battle_util.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c#L10841) inside [TryUpdateEvolutionTracker](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/battle_util.c#L10808):
   - Add a case for `IF_HP_DRAINED_IN_MAPSEC_GE`:
     ```c
     case IF_HP_DRAINED_IN_MAPSEC_GE:
         if (gMapHeader.regionMapSectionId == evolutions[i].params[j].arg1
          && usedMove == evolutions[i].params[j].arg2)
         {
             SetMonData(monAtk, MON_DATA_EVOLUTION_TRACKER, &val);
         }
         break;
     ```
   *(Note: `MON_DATA_EVOLUTION_TRACKER` uses 10 bits in `BoxPokemonSubstruct1`, storing up to 1023 HP, which comfortably accommodates 200 HP).*

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

### Step 4: Refactor Quest Gate & Quest Log Synchronization
1. Update [IsEvoTargetUnlocked](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c#L4490) in [src/pokemon.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/pokemon.c):
   - Allow `SPECIES_GENGAR` to return `TRUE` whenever `FLAG_QUEST_7_ACTIVE` is set or unconditionally, enabling the custom `IF_HP_DRAINED_IN_MAPSEC_GE` condition to manage evolution eligibility:
     ```c
     case SPECIES_GENGAR:
         return FlagGet(FLAG_QUEST_7_ACTIVE) || FlagGet(FLAG_QUEST_KNOW_GENGAR_EVO);
     ```
2. In [src/evolution_scene.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/evolution_scene.c), when an evolution into `SPECIES_GENGAR` completes:
   - Set the quest flags:
     ```c
     if (targetSpecies == SPECIES_GENGAR)
     {
         FlagSet(FLAG_QUEST_KNOW_GENGAR_EVO);
         FlagSet(FLAG_QUEST_7_COMPLETED);
     }
     ```

### Step 5: Update Evolution Table Data
1. In [src/data/pokemon/species_info/gen_1_families.h](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/data/pokemon/species_info/gen_1_families.h#L12145), update `[SPECIES_HAUNTER].evolutions`:
   ```c
   .evolutions = EVOLUTION({EVO_BATTLE_END, 0, SPECIES_GENGAR, 
                           CONDITIONS({IF_HP_DRAINED_IN_MAPSEC_GE, MAPSEC_POKEMON_TOWER, MOVE_DREAM_EATER, GENGAR_DREAM_EATER_EVO_HP})},
                           {EVO_LEVEL, 1, SPECIES_GENGAR, 
                           CONDITIONS({IF_HP_DRAINED_IN_MAPSEC_GE, MAPSEC_POKEMON_TOWER, MOVE_DREAM_EATER, GENGAR_DREAM_EATER_EVO_HP})}),
   ```
   *(Using `EVO_BATTLE_END` allows Haunter to evolve immediately upon winning/finishing the battle where the 200 HP drain threshold is reached, while `EVO_LEVEL` acts as a fallback on level up).*

---

## 4. Data-Driven (JSON) & Poryscript Changes

1. **Poryscript Quest Hint**:
   - Add/update a NPC script in `data/maps/PokemonTower_2F/scripts.pory` (or `PokemonTower_3F/scripts.pory`) to introduce or hint at the mechanic:
     ```poryscript
     script PokemonTower_2F_EventScript_ChannelerHint {
         msgbox(format("They say Haunter absorbing the dreams of spirits inside this tower can undergo a mysterious transformation..."), MSGBOX_NPC)
     }
     ```
   - Compile `.pory` to `.inc` using the build pipeline (`make firered`).

2. **Quest Log Text Alignment**:
   - [src/quest_log_menu.c](file:///C:/Users/zscha/OneDrive/Documents/Decomps/Solid-Oak/Solid-Oak/src/quest_log_menu.c#L158-L167) already contains entry 7 (`GENGAR EVOLUTION`). Update description text if needed to specify:
     `"Use Dream Eater in Lavender Tower to accumulate 200 HP drained and unlock Gengar's evolution."`

---

## 5. Edge Cases & Risks

1. **10-Bit Evolution Tracker Limit**:
   - `MON_DATA_EVOLUTION_TRACKER` is capped at `1023` in `BoxPokemonSubstruct1`. A threshold of `200` HP fits safely within 10 bits. `min(1023, tracker + upAmount)` prevents bit overflow.
2. **Battler Identification & Move Target**:
   - Ensure `TryUpdateEvolutionTracker` is only invoked when the attacker is Haunter owned by the player (`IsOnPlayerSide(gBattlerAttacker)`).
3. **Overkill Damage vs. Drained HP**:
   - `gBattleStruct->moveDamage[gBattlerTarget]` reflects actual damage dealt to target's remaining HP. Overkill damage beyond the target's current HP must not artificially inflate the drain count.
4. **Liquid Ooze & Substitute Interactions**:
   - If target has `ABILITY_LIQUID_OOZE`, HP is still drained/damaged from opponent before recoil damage is applied to user. The tracker should register the damage dealt to the target.
5. **Evolution Interruption (B-Button Cancel)**:
   - If the player cancels the evolution using the B button, `MON_DATA_EVOLUTION_TRACKER` remains at $\ge 200$. The next battle won in Lavender Tower will trigger `EVO_BATTLE_END` again, retrying evolution.

---

## 6. Verification & Testing Plan

### Build Target
Always build via WSL:
```bash
make firered -j$(nproc)
```

### In-Game Test Steps
1. **Setup Test State**:
   - Give party a Haunter with move `MOVE_DREAM_EATER` and Hypnosis/Yawn.
   - Warp player to Pokémon Tower 3F (`MAPSEC_POKEMON_TOWER`).
   - Set `FLAG_QUEST_7_ACTIVE`.
2. **Drain HP**:
   - Engage wild Pokémon or Channeler trainers inside Lavender Tower.
   - Put target to sleep and use Dream Eater.
   - Verify in debug build / breakpoints that `MON_DATA_EVOLUTION_TRACKER` increments by the damage dealt.
3. **Threshold Trigger**:
   - Accumulate $\ge 200$ HP drained.
   - Finish battle. Verify evolution scene triggers immediately post-battle to evolve Haunter into Gengar.
4. **Quest Completion Check**:
   - Open Start Menu $\rightarrow$ POKéDEX $\rightarrow$ Journal $\rightarrow$ RESEARCH tab.
   - Confirm `GENGAR EVOLUTION` quest is marked complete (green).
