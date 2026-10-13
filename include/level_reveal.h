#ifndef GUARD_LEVEL_REVEAL_H
#define GUARD_LEVEL_REVEAL_H

// How much of a Pokemon's level the player is allowed to see. Nothing past
// LEVEL_REVEAL_SIZE is shown until the player owns ITEM_FIELD_NOTEBOOK; after
// that, each species reveals more as it is caught and turned in for research.
enum LevelRevealTier
{
    LEVEL_REVEAL_SIZE,  // Size class (XS/S/M/L/XL) instead of a level
    LEVEL_REVEAL_RANGE, // Tens digit only, e.g. "Lv1?" for 10-19
    LEVEL_REVEAL_EXACT, // Exact level
    LEVEL_REVEAL_FULL,  // Exact level plus EXP details
};

u8 GetLevelRevealTier(u16 species, bool32 isPlayerMon);
void RecordMonRaised(struct Pokemon *mon);
u8 *BufferRevealedLevel(u8 *dest, u16 species, u32 personality, u8 level, u8 tier, bool32 withLvPrefix);
u8 *BufferStrengthHint(u8 *dest, u8 level, u8 compareLevel);

#endif // GUARD_LEVEL_REVEAL_H
