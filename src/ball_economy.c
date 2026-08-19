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
// A ball item (e.g. ITEM_RED_PROTOBALL) sitting in the bag is an "available"
// ball. Once used to catch a mon, that same item id is recorded forever on
// the mon via MON_DATA_POKEBALL (used for its level cap and, later, its
// friendship/obedience risk) - it is never reset by freeing. Freeing a ball
// (see FreeMonBall) just returns one of that item to the bag; the mon's
// MON_DATA_POKEBALL stays as a historical record.

u8 GetBallLevelCap(u16 ballItem)
{
    switch (ballItem)
    {
    case ITEM_RED_PROTOBALL: return 10;
    case ITEM_BLU_PROTOBALL: return 20;
    case ITEM_GRN_PROTOBALL: return 30;
    case ITEM_BLK_PROTOBALL: return 40;
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
    case ITEM_RED_PROTOBALL:
    case ITEM_BLU_PROTOBALL:
    case ITEM_GRN_PROTOBALL:
    case ITEM_BLK_PROTOBALL:
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

    // Only mark the ball freed if it was actually returned to the bag (or
    // wasn't reusable to begin with, per FreeBallItem) - otherwise a full
    // bag would silently delete a reusable ball from the finite economy
    // instead of just failing the free.
    if (recovered)
    {
        u32 freed = TRUE;
        SetMonData(mon, MON_DATA_BALL_FREED, &freed);
    }
    return recovered;
}

bool8 FreeBoxMonBall(struct BoxPokemon *boxMon)
{
    if (GetBoxMonData(boxMon, MON_DATA_BALL_FREED, NULL))
        return TRUE;

    bool8 recovered = FreeBallItem(GetBoxMonData(boxMon, MON_DATA_POKEBALL, NULL));

    if (recovered)
    {
        u32 freed = TRUE;
        SetBoxMonData(boxMon, MON_DATA_BALL_FREED, &freed);
    }
    return recovered;
}

u16 GetMonBallItem(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_POKEBALL);
}

u16 GetBoxMonBallItem(struct BoxPokemon *boxMon)
{
    return GetBoxMonData(boxMon, MON_DATA_POKEBALL, NULL);
}

bool8 CanFreeMonBall(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_BALL_FREED))
        return TRUE;

    u16 ballItem = GetMonData(mon, MON_DATA_POKEBALL);
    if (!IsReusableBallItem(ballItem))
        return TRUE;

    // FreeMonBall calls AddBagItem, so what actually matters is whether the
    // bag has room to receive one more - not whether the player happens to
    // already own one (that check passed even at zero copies, since it's
    // effectively "0 > 0" once the last copy of that ball has been used).
    return CheckBagHasSpace(ballItem, 1);
}

bool8 CanFreeBoxMonBall(struct BoxPokemon *boxMon)
{
    if (GetBoxMonData(boxMon, MON_DATA_BALL_FREED, NULL))
        return TRUE;

    u16 ballItem = GetBoxMonData(boxMon, MON_DATA_POKEBALL, NULL);
    if (!IsReusableBallItem(ballItem))
        return TRUE;

    return CheckBagHasSpace(ballItem, 1);
}

u16 GetClaimableBallItem(u16 requiredBall)
{
    if (requiredBall == ITEM_NONE || requiredBall == 0)
        requiredBall = ITEM_RED_PROTOBALL;

    if (!IsReusableBallItem(requiredBall))
        return requiredBall;

    if (CheckBagHasItem(requiredBall, 1))
        return requiredBall;

    u16 nextTier = GetNextProtoBallTier(requiredBall);
    while (nextTier != ITEM_NONE)
    {
        if (CheckBagHasItem(nextTier, 1))
            return nextTier;
        nextTier = GetNextProtoBallTier(nextTier);
    }

    return ITEM_NONE;
}

bool8 TryClaimMonBall(struct Pokemon *mon)
{
    if (!GetMonData(mon, MON_DATA_BALL_FREED))
        return TRUE;

    u16 requiredBall = GetMonData(mon, MON_DATA_POKEBALL);
    if (!IsReusableBallItem(requiredBall))
    {
        u32 freed = FALSE;
        SetMonData(mon, MON_DATA_BALL_FREED, &freed);
        return TRUE;
    }

    u16 claimableBall = GetClaimableBallItem(requiredBall);
    if (claimableBall == ITEM_NONE)
        return FALSE;

    RemoveBagItem(claimableBall, 1);
    if (claimableBall != requiredBall)
        SetMonData(mon, MON_DATA_POKEBALL, &claimableBall);

    u32 freed = FALSE;
    SetMonData(mon, MON_DATA_BALL_FREED, &freed);
    return TRUE;
}

bool8 TryClaimBoxMonBall(struct BoxPokemon *boxMon)
{
    if (!GetBoxMonData(boxMon, MON_DATA_BALL_FREED, NULL))
        return TRUE;

    u16 requiredBall = GetBoxMonData(boxMon, MON_DATA_POKEBALL, NULL);
    if (!IsReusableBallItem(requiredBall))
    {
        u32 freed = FALSE;
        SetBoxMonData(boxMon, MON_DATA_BALL_FREED, &freed);
        return TRUE;
    }

    u16 claimableBall = GetClaimableBallItem(requiredBall);
    if (claimableBall == ITEM_NONE)
        return FALSE;

    RemoveBagItem(claimableBall, 1);
    if (claimableBall != requiredBall)
        SetBoxMonData(boxMon, MON_DATA_POKEBALL, &claimableBall);

    u32 freed = FALSE;
    SetBoxMonData(boxMon, MON_DATA_BALL_FREED, &freed);
    return TRUE;
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
    case ITEM_RED_PROTOBALL: return ITEM_BLU_PROTOBALL;
    case ITEM_BLU_PROTOBALL: return ITEM_GRN_PROTOBALL;
    case ITEM_GRN_PROTOBALL: return ITEM_BLK_PROTOBALL;
    case ITEM_BLK_PROTOBALL: // Already the top tier.
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
    case ITEM_RED_PROTOBALL: return ITEM_BLUE_APRICORN;  // Red -> Blu
    case ITEM_BLU_PROTOBALL: return ITEM_GREEN_APRICORN; // Blu -> Grn
    case ITEM_GRN_PROTOBALL: return ITEM_BLACK_APRICORN; // Grn -> Blk
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
    ITEM_RED_PROTOBALL, ITEM_BLU_PROTOBALL, ITEM_GRN_PROTOBALL, ITEM_BLK_PROTOBALL,
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
