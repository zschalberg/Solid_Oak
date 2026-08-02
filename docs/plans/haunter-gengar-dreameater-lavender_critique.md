# Critique: Haunter -> Gengar Dream Eater Evolution Plan

Overall the draft is solid — I verified the cited functions, structs, and flags against
the actual codebase, and the great majority are real, not invented, and used the way the
plan describes. `TryUpdateEvolutionTracker`, `MON_DATA_EVOLUTION_TRACKER`, the quest flags,
`MoveEndAbsorb`, and `IsEvoTargetUnlocked` all check out exactly as written. A few
corrections and gaps need to be addressed before this is ready to implement.

## 1. Inconsistent mapsec accessor across steps (Step 2 vs Step 3)

Step 2 (battle_move_resolution.c) calls `GetCurrentRegionMapSectionId()`, but the
`TryUpdateEvolutionTracker` case in battle_util.c and the `DoesMonMeetAdditionalConditions`
case in pokemon.c both switch to `gMapHeader.regionMapSectionId` directly. These are not
guaranteed to agree: `GetCurrentRegionMapSectionId()` (src/overworld.c:1342) reads
`gSaveBlock1Ptr->location` (the last saved overworld position), while `gMapHeader` reflects
whatever map is currently loaded. Pick one accessor and use it consistently everywhere HP
drain is checked and everywhere the tracker is evaluated. Given the existing `IF_IN_MAPSEC`
condition (src/pokemon.c:4308-4310) already uses `gMapHeader.regionMapSectionId` directly
and that's the established pattern for evolution conditions specifically, standardize on
`gMapHeader.regionMapSectionId` in Step 2 as well rather than introducing a second accessor.

## 2. Duplicate HP-drain calculation instead of reusing the existing value

Step 2 recomputes `drainedHp` via
`gBattleStruct->moveDamage[gBattlerTarget] * GetMoveAbsorbPercentage(gCurrentMove) / 100`,
but this is the exact same expression `MoveEndAbsorb` already computes into `healAmount`
two lines earlier (src/battle_move_resolution.c:2236) before calling `SetHealScript`. Reuse
`healAmount` instead of recomputing it — cheaper, and avoids the two values silently
drifting apart if the absorb-percentage logic changes later.

## 3. Precedent for a mapsec condition already exists — don't imply this is greenfield

The plan's Section 1 doesn't mention that `IF_IN_MAPSEC` already exists as an evolution
condition (src/pokemon.c:4308). `IF_HP_DRAINED_IN_MAPSEC_GE` is genuinely new (combining a
counter with a location gate), but call out that it's extending an established pattern, not
inventing mapsec-gated evolutions from scratch. This affects the design: consider whether
splitting into two separate condition checks (an existing-style `IF_IN_MAPSEC` gate applied
at evolution-check time, plus `IF_RECOIL_DAMAGE_GE`-style tracker accumulation) fits the
codebase's existing condition style more cleanly than one combined condition. Either is
workable, but the plan should justify the choice instead of presenting the combined
condition as the only option.

## 4. Quest 7's own mapsec doesn't match the trigger location — verify intent

The Quest Log entry for quest 7 (`GENGAR EVOLUTION`, src/quest_log_menu.c:158-167) has
`.mapsec = MAPSEC_LAVENDER_TOWN`, but the evolution trigger as designed checks
`MAPSEC_POKEMON_TOWER` (a distinct, separate mapsec — there is no `MAPSEC_LAVENDER_TOWER`
constant in this codebase). This may be intentional (the quest is "about" Lavender Town
generally, the mechanic happens inside the Tower specifically), but the plan should say so
explicitly rather than leave the mismatch unaddressed, since a reviewer will otherwise flag
it as a bug.

## 5. Unverified: exact current Haunter evolution line/params

The plan cites `gen_1_families.h:12145` for the current `SPECIES_HAUNTER` `.evolutions`
entry but this line was not independently confirmed — only the neighboring Gastly->Haunter
entry was confirmed nearby. Before merging, re-read the actual current Haunter block and
adjust the line reference and diff accordingly; don't assume the plan's guessed line number
is exact.

## 6. gMapHeader reliability during an active battle is asserted, not verified

Item 10 of my verification: there's no existing case in this codebase of a
battle-triggered, location-gated *tracker accumulation* (as opposed to a one-shot
end-of-battle check like `IF_IN_MAPSEC`). `IF_IN_MAPSEC` only runs at evolution-eval time
(after battle), so its reliance on `gMapHeader` mid-or-post-battle already has precedent.
But Step 2 wants to check the mapsec **while still in the battle**, immediately after each
Dream Eater hit, to gate whether the drain even counts toward the tracker. Add an explicit
edge case note (Section 5) confirming `gMapHeader.regionMapSectionId` stays correct and
stable for the whole duration of a battle triggered on a Pokemon Tower floor (i.e. it
doesn't get overwritten by any battle-transition code, cave-in scripts, or the SS Anne /
elevator-style map transitions used elsewhere in this hack). A quick grep for anywhere
`gMapHeader` is mutated during `CB2_InitBattle` or battle setup would settle this.

## 7. Missing: what happens to the tracker if Haunter faints or is switched out mid-tower-visit

`IF_RECOIL_DAMAGE_GE`'s existing tracker resets to 0 on fainting per the verification
report. The plan's Section 5 (Edge Cases) doesn't state whether
`IF_HP_DRAINED_IN_MAPSEC_GE`'s tracker should also reset on fainting, or persist across
multiple battles/tower visits until the threshold is hit. Given the player-facing goal
("cumulative HP drained... while in Lavender Tower"), persisting across battles (not
resetting on faint) seems intended, but the plan should say this explicitly and confirm
`TryUpdateEvolutionTracker`'s new case does NOT include the faint-reset behavior that
`IF_RECOIL_DAMAGE_GE` has, since copying that behavior verbatim would silently break the
cumulative design.

## Minor

- Quest-gate refactor in Step 4 (`FlagGet(FLAG_QUEST_7_ACTIVE) || FlagGet(FLAG_QUEST_KNOW_GENGAR_EVO)`) changes `IsEvoTargetUnlocked`'s behavior for every other path that currently checks `FLAG_QUEST_KNOW_GENGAR_EVO` alone (e.g. trading in a Haunter that's already met the threshold, or any other evolution trigger not gated by the tower mechanic). Confirm this is the *only* remaining path to Gengar before loosening the gate to `FLAG_QUEST_7_ACTIVE`, or the quest's "activate then complete" structure could be trivially skippable.
