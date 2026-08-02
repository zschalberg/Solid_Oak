# Implementation Plan: Slowpoke Wild Shellder Evolution Mechanic

## Overview
Slowpoke will evolve into **Slowbro** or **Slowking** during a wild battle against a wild Shellder when a specific move sequence and conditions are satisfied:
1. **Move Sequence**: Slowpoke uses **Tail Whip** (for Slowbro) or **Headbutt** (for Slowking), and at some later point wild Shellder uses **Clamp** on Slowpoke, with nothing breaking the chain in between (see Sequence Semantics below).
2. **Level Requirement**: Slowpoke must be Level 30 or higher (reduced from standard Level 37 requirement).
3. **Survival Requirement**: Slowpoke must survive the Clamp attack (HP > 0).
4. **Target Requirement**: The opponent must be a wild Shellder (not in a trainer's party).
5. **Quest Gate**: The evolution must be unlocked per the existing `IsEvoTargetUnlocked` check (`FLAG_QUEST_KNOW_SLOWPOKE_EVOS`) — see below.

When all conditions are met:
- The Shellder attaches itself to Slowpoke and is effectively removed from the battle (it is not defeated, it does not flee on its own — it becomes part of the evolved Pokemon).
- The evolution is presented in-battle (reusing existing mid-battle evolution presentation where possible), with a `"Huh?"` message beat.
- The battle then ends without granting EXP, money, or a catch prompt — the Shellder isn't fainted or caught, it's just gone.

---

## User Review Required

> [!NOTE]
> - This mechanic only applies to wild Shellder encounters (`BATTLE_TYPE_WILD`), ignoring trainer battles.
> - Using any move other than Tail Whip/Headbutt on Slowpoke, or Shellder using any move other than Clamp, breaks the move sequence chain (see Sequence Semantics).
> - This evolution is still gated by `FLAG_QUEST_KNOW_SLOWPOKE_EVOS`, same as the existing trade/level-up paths to Slowbro/Slowking. It does not bypass that gate.

---

## Sequence Semantics (cross-turn)

The Tail Whip/Headbutt → Clamp sequence is **not** required to happen within a single turn. Slowpoke can use Tail Whip on turn 1, and Shellder can use Clamp on turn 2 (or later), and the chain still counts, provided nothing invalidates it in between.

Tracking is done via a persisted pending-state field (not the existing `gLastMoves` array — see rationale below), stored on `gBattleStruct` so it lives and clears with the rest of battle state:

- `gBattleStruct->slowpokeEvoTarget` (`u16`): `SPECIES_NONE`, `SPECIES_SLOWBRO`, or `SPECIES_SLOWKING`.

**Why not `gLastMoves`:** `gLastMoves[battler]` only holds the single most recent move a battler used — it has no memory of whether something broke the chain in between. Example: Slowpoke uses Tail Whip (turn 1), Shellder uses Tackle (turn 1, should break the chain), then Shellder uses Clamp (turn 2). At the moment Clamp resolves, `gLastMoves[slowpokeBattler]` is still `MOVE_TAIL_WHIP` (Slowpoke hasn't acted since), so a naive check against `gLastMoves` would incorrectly fire even though Shellder's intervening Tackle should have reset it. A persisted, explicitly-managed flag is required.

**Update rules, evaluated whenever the tracked Slowpoke or Shellder battler resolves a move:**
- Slowpoke battler uses Tail Whip → set `slowpokeEvoTarget = SPECIES_SLOWBRO`.
- Slowpoke battler uses Headbutt → set `slowpokeEvoTarget = SPECIES_SLOWKING`.
- Slowpoke battler uses **any other move** → clear `slowpokeEvoTarget = SPECIES_NONE`.
- Shellder battler uses Clamp while `slowpokeEvoTarget != SPECIES_NONE` → evaluate the trigger (see below).
- Shellder battler uses **any other move** → clear `slowpokeEvoTarget = SPECIES_NONE`.
- Also clear on switch-out, fainting, or the tracked battler otherwise leaving the field.

**Repeat-move case:** using the same qualifying move again does not reset the chain — it's a no-op re-arm. E.g. Slowpoke using Tail Whip twice in a row still leaves it armed for Slowbro; this falls out naturally from the rule above (repeating Tail Whip is still Tail Whip, so it's never in the "any other move" branch).

Since this only applies to wild single battles, there are only two battlers to track (no need to handle party-partner interference in doubles).

---

## Battle System Infrastructure

#### [MODIFY] [battle.h](../../include/battle.h)
- Add `u16 slowpokeEvoTarget;` to `struct BattleStruct` (holds `SPECIES_NONE`/`SPECIES_SLOWBRO`/`SPECIES_SLOWKING`).
- No separate `slowpokeEvoBattler` field is needed — the Slowpoke/Shellder battler indices can be resolved directly from `gBattlerAttacker`/`gBattlerTarget` at trigger time, and party slot via the existing `gBattlerPartyIndexes[battler]`.

#### [MODIFY] [battle_string_ids.h](../../include/constants/battle_string_ids.h)
- Add `STRINGID_HUH` to battle string ID constants.

#### [MODIFY] [battle_message.c](../../src/battle_message.c)
- Define `sText_Huh[] = _("Huh?\p");`
- Map `[STRINGID_HUH] = sText_Huh` in `gBattleStringsTable`.

#### [MODIFY] [battle_scripts_1.s](../../data/battle_scripts_1.s)
- Create `BattleScript_SlowpokeEvolution::`, run in-battle (before the battle ends), reusing the existing mid-battle evolution presentation infrastructure (`BS_HandleMidBattleEvolution` / `gBattleStruct->battleEvoTargetSpecies`, see `src/battle_script_commands.c:14445-14485`) for the actual species change and animation, followed by the `"Huh?"` message beat:
  ```assembly
  BattleScript_SlowpokeEvolution::
      printstring STRINGID_HUH
      waitmessage B_WAIT_TIME_LONG
      handlemidbattleevolution   ; reuses existing mid-battle evolution machinery
      waitstate
      end2
  ```
  (Exact command name/ordering to be confirmed against the existing `BS_HandleMidBattleEvolution` calling convention when implemented.)

---

## Move Execution & Sequence Logic

#### [MODIFY] [battle_move_resolution.c](../../src/battle_move_resolution.c) / [battle_script_commands.c](../../src/battle_script_commands.c)
- **Sequence tracking**: implement the update rules described above, hooked into move-resolution completion for the two relevant battlers.
- **Trigger evaluation (when Shellder's Clamp resolves)**:
  - Verify attacker is a wild `SPECIES_SHELLDER` (`!(gBattleTypeFlags & BATTLE_TYPE_TRAINER)`).
  - Verify target is `SPECIES_SLOWPOKE`, level >= 30.
  - Verify `gBattleMons[gBattlerTarget].hp > 0` (survived Clamp).
  - Verify `gBattleStruct->slowpokeEvoTarget` is `SPECIES_SLOWBRO` or `SPECIES_SLOWKING`.
  - Verify `IsEvoTargetUnlocked(gBattleStruct->slowpokeEvoTarget)` equivalent — i.e. `FlagGet(FLAG_QUEST_KNOW_SLOWPOKE_EVOS)` (see `src/pokemon.c:4497-4509`). If not unlocked, do not trigger (Slowpoke just takes the Clamp hit normally).
  - If all conditions pass: set `gBattleStruct->battleEvoTargetSpecies = gBattleStruct->slowpokeEvoTarget`, jump the battle script to `BattleScript_SlowpokeEvolution`.

---

## Ending the Battle

Once the evolution has been presented in-battle, the encounter ends **without** normal victory processing, since the Shellder was never fainted or caught — it left by attaching to Slowpoke.

- Set `gBattleOutcome = B_OUTCOME_MON_FLED` (not `B_OUTCOME_WON`). This routes through the existing `HandleEndTurn_MonFled` path (`src/battle_main.c:450`, set the same way at `src/battle_util.c:700` for a wild Pokemon fleeing), which ends the battle cleanly with no EXP grant, no money, and no catch prompt — matching the fact that nothing was defeated.
- This removes the need for the previously-proposed post-battle detour through `TryEvolvePokemon`/`EvolutionScene` and the extra globals (`gSlowpokeEvolvingTarget`, `gSlowpokeEvolvingPartyId`) — the evolution is fully resolved in-battle before the outcome is set.

---

## Verification Plan

### Automated Tests
- Run build via `wsl make -j8` to verify clean compilation with no syntax errors or symbol link issues.

### Manual Verification
- Test in emulator (mGBA):
  1. With `FLAG_QUEST_KNOW_SLOWPOKE_EVOS` set and a Level 30+ Slowpoke: Tail Whip → Shellder Clamp (same turn) → verify evolution to Slowbro, battle ends cleanly (no EXP/catch prompt).
  2. Headbutt → Shellder Clamp (same turn) → verify evolution to Slowking.
  3. Tail Whip (turn 1), Shellder uses a non-Clamp move (turn 1), Shellder Clamp (turn 2) → verify evolution does NOT trigger (chain broken by the intervening move).
  4. Tail Whip (turn 1), Shellder Clamp (turn 2, nothing else happened in between) → verify evolution DOES trigger (cross-turn chain holds).
  5. Tail Whip, Tail Whip again, then Shellder Clamp → verify evolution DOES trigger for Slowbro (repeat move does not reset the chain).
  6. `FLAG_QUEST_KNOW_SLOWPOKE_EVOS` NOT set → verify evolution does NOT trigger even with a valid sequence.
  7. Slowpoke under Level 30 (e.g. Level 29) → verify evolution does NOT trigger.
  8. Slowpoke faints from Clamp (0 HP) → verify evolution does NOT trigger.
  9. Trainer's Shellder using Clamp → verify evolution does NOT trigger.
  10. Slowpoke uses Tackle after Tail Whip, then Shellder Clamps → verify evolution does NOT trigger (chain broken by Slowpoke's own move).
