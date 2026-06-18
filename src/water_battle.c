#include "global.h"
#include "pokemon.h"
#include "battle_util.h"
#include "constants/abilities.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

// Checks if a mon can participate in a water or underwater battle.
// Eligible if: Water-type, has a water-related ability (active slot only),
// or can learn / currently knows Surf, Waterfall, or Dive.
bool32 CanMonParticipateInWaterBattle(struct Pokemon *mon)
{
    enum Species species = (enum Species)GetMonData(mon, MON_DATA_SPECIES);
    if (species == SPECIES_NONE || GetMonData(mon, MON_DATA_IS_EGG))
        return FALSE;

    if (gSpeciesInfo[species].isWaterBattleBanned)
        return FALSE;

    if (GetSpeciesType(species, 0) == TYPE_WATER || GetSpeciesType(species, 1) == TYPE_WATER)
        return TRUE;

    // Only checks the active ability slot by design, consistent with CanMonParticipateInSkyBattle.
    u32 monAbilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    switch (GetSpeciesAbility(species, monAbilityNum))
    {
    case ABILITY_SWIFT_SWIM:
    case ABILITY_WATER_ABSORB:
    case ABILITY_STORM_DRAIN:
    case ABILITY_HYDRATION:
    case ABILITY_DRIZZLE:
    case ABILITY_WATER_BUBBLE:
    case ABILITY_WATER_COMPACTION:
    case ABILITY_LIQUID_VOICE:
        return TRUE;
    default:
        break;
    }

    if (CanLearnTeachableMove(species, MOVE_SURF)
        || CanLearnTeachableMove(species, MOVE_WATERFALL)
        || CanLearnTeachableMove(species, MOVE_DIVE))
        return TRUE;

    u8 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 move = GetMonData(mon, MON_DATA_MOVE1 + i);
        if (move == MOVE_SURF || move == MOVE_WATERFALL || move == MOVE_DIVE)
            return TRUE;
    }

    return FALSE;
}

