#include "global.h"
#include "ball_economy.h"
#include "pokemon.h"
#include "item.h"
#include "event_data.h"
#include "string_util.h"
#include "party_menu.h"
#include "constants/items.h"
#include "constants/pokeball.h"

// Central home for the pre-jump Protoball/Research Ball economy: finite,
// reusable ball "slots" instead of craftable/purchasable consumables.
//
// A ball item (e.g. ITEM_LEVEL_BALL) sitting in the bag is an "available"
// ball. Once used to catch a mon, that same item id is recorded forever on
// the mon via MON_DATA_POKEBALL (used for its level cap and, later, its
// friendship/obedience risk) - it is never reset by freeing. Freeing a ball
// (see FreeMonBall) just returns one of that item to the bag; the mon's
// MON_DATA_POKEBALL stays as a historical record.

u8 GetBallLevelCap(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_LEVEL_BALL:  return 10;
    case ITEM_LURE_BALL:   return 20;
    case ITEM_FRIEND_BALL: return 30;
    case ITEM_HEAVY_BALL:  return 40;
    default:               return BALL_CAP_NONE;
    }
}

u8 GetOriginalBallLevelCap(struct Pokemon *mon)
{
    // MON_DATA_POKEBALL is never reset by FreeMonBall, so this keeps working
    // even after the ball itself has been freed back to the bag (e.g. after
    // a trip through storage).
    return GetBallLevelCap(GetMonData(mon, MON_DATA_POKEBALL));
}

bool8 IsReusableBallItem(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_LEVEL_BALL:
    case ITEM_LURE_BALL:
    case ITEM_FRIEND_BALL:
    case ITEM_HEAVY_BALL:
    case ITEM_RESEARCH_BALL:
        return TRUE;
    default:
        return FALSE;
    }
}

// Returns FALSE only if the ball was reusable, not yet freed, and the bag
// had no room for it (all other cases - non-reusable, already freed - are
// "nothing to do" and report success).
static bool8 FreeBallItem(u16 ballItem)
{
    if (IsReusableBallItem(ballItem))
        return AddBagItem(ballItem, 1);
    return TRUE;
}

bool8 FreeMonBall(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_BALL_FREED))
        return TRUE;

    bool8 recovered = FreeBallItem(GetMonData(mon, MON_DATA_POKEBALL));

    u32 freed = TRUE;
    SetMonData(mon, MON_DATA_BALL_FREED, &freed);
    return recovered;
}

bool8 FreeBoxMonBall(struct BoxPokemon *boxMon)
{
    if (GetBoxMonData(boxMon, MON_DATA_BALL_FREED, NULL))
        return TRUE;

    bool8 recovered = FreeBallItem(GetBoxMonData(boxMon, MON_DATA_POKEBALL, NULL));

    u32 freed = TRUE;
    SetBoxMonData(boxMon, MON_DATA_BALL_FREED, &freed);
    return recovered;
}

void MarkMonBallOccupied(struct Pokemon *mon)
{
    u32 freed = FALSE;
    SetMonData(mon, MON_DATA_BALL_FREED, &freed);
}

void GrantBallsOfType(u16 ballItem, u8 quantity)
{
    AddBagItem(ballItem, quantity);
}

// Generic script-facing quest reward special: gSpecialVar_0x8004 = ball item,
// gSpecialVar_0x8005 = quantity. Reusable for any future quest milestone.
void GrantQuestBalls(void)
{
    GrantBallsOfType(gSpecialVar_0x8004, (u8)gSpecialVar_0x8005);
}

u16 GetNextProtoBallTier(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_LEVEL_BALL: return ITEM_LURE_BALL;
    case ITEM_LURE_BALL:  return ITEM_FRIEND_BALL;
    case ITEM_FRIEND_BALL: return ITEM_HEAVY_BALL;
    case ITEM_HEAVY_BALL: // Already the top tier.
    default:
        return ITEM_NONE;
    }
}

u16 GetApricornForBallTier(u16 ballItem)
{
    // Returns the apricorn needed to upgrade FROM ballItem to the next tier,
    // reusing the same apricorn-color-to-tier mapping as the (removed)
    // original crafting system (see the old CraftProtoballs in field_specials.c).
    switch (ballItem)
    {
    case ITEM_LEVEL_BALL: return ITEM_BLUE_APRICORN;  // Red -> Blu
    case ITEM_LURE_BALL:  return ITEM_GREEN_APRICORN; // Blu -> Grn
    case ITEM_FRIEND_BALL: return ITEM_BLACK_APRICORN; // Grn -> Blk
    default:
        return ITEM_NONE;
    }
}

// --- Workbench "Upgrade Ball" script specials ---
//
// gSpecialVar_0x8004 selects the target: a party slot index (mon-in-ball
// path) or a Protoball tier index 0-3 (empty bag-ball path). Both paths
// reuse GetNextProtoBallTier/GetApricornForBallTier above rather than a
// separate mapping.

static const u16 sProtoBallTierItems[] = {
    ITEM_LEVEL_BALL, ITEM_LURE_BALL, ITEM_FRIEND_BALL, ITEM_HEAVY_BALL,
};

// Checks whether the selected party mon's ball can be upgraded and, if so,
// buffers its nickname (gStringVar1) and the needed apricorn item
// (gSpecialVar_0x8007) for the confirmation prompt.
u8 GetSelectedMonUpgradeInfo(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 ball = GetMonData(mon, MON_DATA_POKEBALL);
    u16 apricorn = GetApricornForBallTier(ball);

    GetMonNickname(mon, gStringVar1);

    if (apricorn == ITEM_NONE)
        return UPGRADE_RESULT_NOT_UPGRADEABLE;

    gSpecialVar_0x8007 = apricorn;
    return UPGRADE_RESULT_SUCCESS;
}

// Performs the upgrade on the party mon selected via gSpecialVar_0x8004.
// Critical: only MON_DATA_POKEBALL changes - level, moves, friendship, and
// everything else about the mon is left untouched.
u8 UpgradeSelectedMonBall(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 ball = GetMonData(mon, MON_DATA_POKEBALL);
    u16 nextTier = GetNextProtoBallTier(ball);
    u16 apricorn = GetApricornForBallTier(ball);

    if (nextTier == ITEM_NONE || apricorn == ITEM_NONE || !CheckBagHasItem(apricorn, 1))
        return UPGRADE_RESULT_NOT_UPGRADEABLE;

    RemoveBagItem(apricorn, 1);
    SetMonData(mon, MON_DATA_POKEBALL, &nextTier);
    gSpecialVar_0x8007 = nextTier;
    return UPGRADE_RESULT_SUCCESS;
}

// Upgrades an empty ball sitting in the bag (tier index 0-3, from
// gSpecialVar_0x8004) with no mon attached.
u8 TryUpgradeBagBallTier(void)
{
    u16 tierIndex = gSpecialVar_0x8004;
    u16 ball, nextTier, apricorn;

    if (tierIndex >= ARRAY_COUNT(sProtoBallTierItems))
        return UPGRADE_RESULT_NOT_UPGRADEABLE;

    ball = sProtoBallTierItems[tierIndex];
    nextTier = GetNextProtoBallTier(ball);
    apricorn = GetApricornForBallTier(ball);

    if (nextTier == ITEM_NONE || !CheckBagHasItem(ball, 1))
        return UPGRADE_RESULT_NOT_UPGRADEABLE;

    if (!CheckBagHasItem(apricorn, 1))
    {
        gSpecialVar_0x8007 = apricorn;
        return UPGRADE_RESULT_NEED_APRICORN;
    }

    RemoveBagItem(ball, 1);
    RemoveBagItem(apricorn, 1);
    AddBagItem(nextTier, 1);
    gSpecialVar_0x8007 = nextTier;
    return UPGRADE_RESULT_SUCCESS;
}
