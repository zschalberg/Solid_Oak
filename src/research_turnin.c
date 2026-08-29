#include "global.h"
#include "pokemon.h"
#include "pokemon_size_record.h"
#include "pokemon_storage_system.h"
#include "party_menu.h"
#include "coins.h"
#include "event_data.h"
#include "string_util.h"
#include "text.h"
#include "constants/items.h"
#include "constants/pokeball.h"
#include "constants/flags.h"
#include "research_turnin.h"
#include "ball_economy.h"
#include "constants/vars.h"
#include "wild_encounter.h"

// Variables to cache evaluation details between specials
static u16 sEvaluatedCoins;
static bool8 sReserveStageJustAdvanced;

#define FAMILY_MEMBERS_MAX 16

// Cumulative species-logged total (see GetFamilyMemberCount) required to reach
// each Reserve stage past 0, unlocking a new wild encounter pool via
// VAR_SAFARI_ZONE_STAGE. Thresholds need not be evenly spaced - entry i is the
// total required to reach stage i + 1. Must have NUM_SAFARI_ZONE_STAGES - 1 entries.
static const u16 sReserveStageThresholds[NUM_SAFARI_ZONE_STAGES - 1] = {10, 20, 30, 40};

static u16 GetReserveStageForTotal(u16 total)
{
    u16 stage;

    for (stage = 0; stage < ARRAY_COUNT(sReserveStageThresholds); stage++)
    {
        if (total < sReserveStageThresholds[stage])
            break;
    }
    return stage;
}

static const u8 sText_RarityCommon[] = _("Common");
static const u8 sText_RarityUncommon[] = _("Uncommon");
static const u8 sText_RarityRare[] = _("Rare");
static const u8 sText_RarityLegendary[] = _("Legendary");

static const u8 sText_BreakdownRarity[] = _("Rarity: ");
static const u8 sText_BreakdownSize[] = _("Size: ");
static const u8 sText_BreakdownShiny[] = _("Shininess: ");
static const u8 sText_BreakdownIVs[] = _("IVs: ");
static const u8 sText_BreakdownFamily[] = _("Family Bonus: ");
static const u8 sText_BreakdownTotal[] = _("Total: ");
static const u8 sText_PointsSuffix[] = _(" points");
static const u8 sText_NewlineChar[] = _("\n");
static const u8 sText_ParagraphChar[] = _("\p");

static bool32 IsSpeciesBabyMon(enum Species species)
{
    const struct SpeciesInfo *info = &gSpeciesInfo[species];
    return info->eggGroups[0] == EGG_GROUP_NO_EGGS_DISCOVERED
        && !info->isRestrictedLegendary
        && !info->isSubLegendary
        && !info->isMythical;
}

static enum Species GetFamilyBaseSpecies(enum Species species)
{
    enum Species baseSpecies = GET_BASE_SPECIES_ID(species);
    enum Species preEvo;
    while ((preEvo = GetSpeciesPreEvolution(baseSpecies)) != SPECIES_NONE)
    {
        if (IsSpeciesBabyMon(preEvo))
            break; // Stop - don't walk past the baby into its parents
        baseSpecies = preEvo;
    }
    return baseSpecies;
}

static bool8 SpeciesInList(enum Species species, const enum Species *list, u8 count)
{
    u8 i;
    for (i = 0; i < count; i++)
    {
        if (list[i] == species)
            return TRUE;
    }
    return FALSE;
}

// Walks the full evolution tree from baseSpecies (including branches, e.g.
// Eevee's eeveelutions) and records every unique species into list.
static void CollectFamilyMembers(enum Species species, enum Species *list, u8 *count)
{
    const struct Evolution *evolutions;
    s32 i;

    if (*count >= FAMILY_MEMBERS_MAX || SpeciesInList(species, list, *count))
        return;

    list[(*count)++] = species;

    evolutions = GetSpeciesEvolutions(species);
    for (i = 0; evolutions[i].method != EVOLUTIONS_END; i++)
    {
        if (evolutions[i].targetSpecies != SPECIES_NONE)
            CollectFamilyMembers(evolutions[i].targetSpecies, list, count);
    }
}

static u16 GetFamilyMemberCount(enum Species baseSpecies)
{
    enum Species members[FAMILY_MEMBERS_MAX];
    u8 count = 0;

    CollectFamilyMembers(baseSpecies, members, &count);
    return count;
}

bool8 IsSelectedMonResearchBall(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 ball = GetMonData(mon, MON_DATA_POKEBALL);
    
    // Write name to gStringVar1 for script dialogs
    GetMonNickname(mon, gStringVar1);
    
    gSpecialVar_Result = (ball == BALL_RESEARCH);
    return gSpecialVar_Result;
}


bool32 IsSpeciesFamilyReserved(enum Species species)
{
    enum Species baseSpecies = GetFamilyBaseSpecies(species);
    u16 nationalNum = SpeciesToNationalPokedexNum(baseSpecies);

    if (nationalNum == NATIONAL_DEX_NONE)
        return FALSE;

    return (gSaveBlock1Ptr->reserveSpeciesTurnedIn[nationalNum / 8] & (1 << (nationalNum % 8))) != 0;
}

static bool32 CheckIsNewFamily(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    return !IsSpeciesFamilyReserved(species);
}

bool8 IsSelectedMonNewFamily(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    gSpecialVar_Result = CheckIsNewFamily(mon);
    return gSpecialVar_Result;
}

u16 GetBaseRarityPoints(u8 catchRate)
{
    if (catchRate >= 150)
        return 10;       // Common
    else if (catchRate >= 75)
        return 30;       // Uncommon
    else if (catchRate >= 31)
        return 100;      // Rare
    else
        return 350;      // Legendary/Mythical
}

u16 ApplyShinyBonus(u16 points, bool8 isShiny)
{
    if (isShiny)
    {
        return (points * 2) + 500;
    }
    return points;
}

// Mirrors the "exceptional size caught!" tiering from Cmd_trysetcaughtmondexflags
// (GetSizeCategoryTier), so a mon that was announced as exceptional at catch time
// always qualifies for a size bonus at turn-in. Uncommon (tier 1) mons get half
// the bonus; Rare and Very Rare (tier 2-3) mons get the full bonus.
u16 GetSizeBonusForTier(u8 tier)
{
    if (tier >= 2)
        return 50;
    else if (tier == 1)
        return 25;
    return 0;
}

u16 CalculateResearchMonCoins(struct Pokemon *mon)
{
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u8 catchRate = gSpeciesInfo[species].catchRate;
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    bool8 isShiny = GetMonData(mon, MON_DATA_IS_SHINY);

    u16 baseCoins = 0;
    u16 sizeBonus = 0;
    u16 ivBonus = 0;
    u16 familyBonus = 0;

    baseCoins = GetBaseRarityPoints(catchRate);
    sizeBonus = GetSizeBonusForTier(GetPersonalitySizeTier(personality));

    if (GetMonData(mon, MON_DATA_HP_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_ATK_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_DEF_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPEED_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPATK_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPDEF_IV) == 31) ivBonus += 25;

    if (CheckIsNewFamily(mon))
        familyBonus = 250;

    return ApplyShinyBonus(baseCoins + sizeBonus + ivBonus + familyBonus, isShiny);
}

void EvaluateSelectedResearchMon(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u8 catchRate = gSpeciesInfo[species].catchRate;
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    bool8 isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
    
    u16 baseCoins = GetBaseRarityPoints(catchRate);
    u16 sizeBonus = GetSizeBonusForTier(GetPersonalitySizeTier(personality));
    u16 ivBonus = 0;
    u16 familyBonus = 0;
    u16 totalCoins = 0;

    if (GetMonData(mon, MON_DATA_HP_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_ATK_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_DEF_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPEED_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPATK_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPDEF_IV) == 31) ivBonus += 25;

    if (CheckIsNewFamily(mon))
        familyBonus = 250;

    totalCoins = ApplyShinyBonus(baseCoins + sizeBonus + ivBonus + familyBonus, isShiny);
    sEvaluatedCoins = totalCoins;

    // Set up text buffers for the script dialog
    // gStringVar1: Nickname (already set in IsSelectedMonResearchBall, but set again to be safe)
    GetMonNickname(mon, gStringVar1);
    
    // gStringVar2: Rarity description
    if (catchRate >= 150)
        StringCopy(gStringVar2, sText_RarityCommon);
    else if (catchRate >= 75)
        StringCopy(gStringVar2, sText_RarityUncommon);
    else if (catchRate >= 31)
        StringCopy(gStringVar2, sText_RarityRare);
    else
        StringCopy(gStringVar2, sText_RarityLegendary);

    // gStringVar3: Detailed point breakdown
    {
        u8 *ptr = gStringVar3;
        u8 tempBuffers[6][48];
        u8 numLines = 0;
        u8 i;

        // Line 0: Rarity
        {
            u8 *tPtr = tempBuffers[numLines++];
            tPtr = StringCopy(tPtr, sText_BreakdownRarity);
            tPtr = ConvertIntToDecimalStringN(tPtr, baseCoins, STR_CONV_MODE_LEFT_ALIGN, 5);
            StringCopy(tPtr, sText_PointsSuffix);
        }

        // Line 1: Size
        {
            u8 *tPtr = tempBuffers[numLines++];
            tPtr = StringCopy(tPtr, sText_BreakdownSize);
            tPtr = ConvertIntToDecimalStringN(tPtr, sizeBonus, STR_CONV_MODE_LEFT_ALIGN, 5);
            StringCopy(tPtr, sText_PointsSuffix);
        }

        // Line 2: IVs
        {
            u8 *tPtr = tempBuffers[numLines++];
            tPtr = StringCopy(tPtr, sText_BreakdownIVs);
            tPtr = ConvertIntToDecimalStringN(tPtr, ivBonus, STR_CONV_MODE_LEFT_ALIGN, 5);
            StringCopy(tPtr, sText_PointsSuffix);
        }

        // Line 3 (optional): Family
        if (familyBonus > 0)
        {
            u8 *tPtr = tempBuffers[numLines++];
            tPtr = StringCopy(tPtr, sText_BreakdownFamily);
            tPtr = ConvertIntToDecimalStringN(tPtr, familyBonus, STR_CONV_MODE_LEFT_ALIGN, 5);
            StringCopy(tPtr, sText_PointsSuffix);
        }

        // Line 4 (optional): Shininess
        if (isShiny)
        {
            u8 *tPtr = tempBuffers[numLines++];
            u16 shinyBonus = (baseCoins + sizeBonus + ivBonus + familyBonus) + 500;
            tPtr = StringCopy(tPtr, sText_BreakdownShiny);
            tPtr = ConvertIntToDecimalStringN(tPtr, shinyBonus, STR_CONV_MODE_LEFT_ALIGN, 5);
            StringCopy(tPtr, sText_PointsSuffix);
        }

        // Line 5: Total
        {
            u8 *tPtr = tempBuffers[numLines++];
            tPtr = StringCopy(tPtr, sText_BreakdownTotal);
            tPtr = ConvertIntToDecimalStringN(tPtr, totalCoins, STR_CONV_MODE_LEFT_ALIGN, 5);
            StringCopy(tPtr, sText_PointsSuffix);
        }

        // Concatenate buffers with \n and \p
        for (i = 0; i < numLines; i++)
        {
            ptr = StringCopy(ptr, tempBuffers[i]);
            if (i < numLines - 1)
            {
                if (i == 0)
                {
                    ptr = StringCopy(ptr, sText_ParagraphChar);
                }
                else if (i % 2 == 1)
                {
                    ptr = StringCopy(ptr, sText_NewlineChar);
                }
                else
                {
                    ptr = StringCopy(ptr, sText_ParagraphChar);
                }
            }
        }
    }
}

void TurnInSelectedResearchMon(void)
{
    // Double-check party count safety to prevent empty party crashes. Every
    // current caller already gates on getpartysize before letting the
    // player pick a mon, so this shouldn't trip in practice - but if it
    // ever does (a future caller skips that gate), fail loudly via
    // gSpecialVar_Result instead of silently doing nothing while still
    // reporting the coin total as if the turn-in succeeded.
    if (gPlayerPartyCount <= 1)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    enum Species baseSpecies = GetFamilyBaseSpecies(species);
    u16 nationalNum = SpeciesToNationalPokedexNum(baseSpecies);
    bool32 isNewFamily = CheckIsNewFamily(mon);

    // Mark the family as turned in
    if (nationalNum != NATIONAL_DEX_NONE)
    {
        gSaveBlock1Ptr->reserveSpeciesTurnedIn[nationalNum / 8] |= (1 << (nationalNum % 8));
    }

    // A newly-logged family counts every member toward the Reserve's
    // wild encounter progression, e.g. a first Cubone turn-in counts for
    // both Cubone and Marowak.
    if (isNewFamily)
    {
        u16 total = VarGet(VAR_RESERVE_SPECIES_LOGGED_TOTAL) + GetFamilyMemberCount(baseSpecies);
        u16 newStage = GetReserveStageForTotal(total);

        VarSet(VAR_RESERVE_SPECIES_LOGGED_TOTAL, total);

        if (newStage > VarGet(VAR_SAFARI_ZONE_STAGE))
        {
            VarSet(VAR_SAFARI_ZONE_STAGE, newStage);
            sReserveStageJustAdvanced = TRUE;
        }
    }

    // Award the coins using native AddCoins (handles limit and overflow protection)
    AddCoins(sEvaluatedCoins);

    // Ball economy: the mon is gone for good, so its ball frees back to the bag.
    FreeMonBall(mon);

    // Remove the selected mon from the party
    ZeroMonData(mon);
    CompactPartySlots();
    CalculatePlayerPartyCount();

    // Overwrite gStringVar3 with just the final total coins for use in the success msgbox
    ConvertIntToDecimalStringN(gStringVar3, sEvaluatedCoins, STR_CONV_MODE_LEFT_ALIGN, 5);
    gSpecialVar_Result = TRUE;
}

void TransferSelectedMonToPokeBall(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 ball = BALL_POKE;
    
    // Set the nickname for use in the script success message
    GetMonNickname(mon, gStringVar1);
    
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
}

// Checked by the turn-in script right after TurnInSelectedResearchMon;
// TRUE the one time a turn-in pushes VAR_RESERVE_SPECIES_LOGGED_TOTAL past
// a RESERVE_SPECIES_PER_STAGE threshold, so the worker can mention that new
// Pokemon are now available at the Reserve. Consumes the flag once read.
bool8 CheckReserveStageJustAdvanced(void)
{
    gSpecialVar_Result = sReserveStageJustAdvanced;
    sReserveStageJustAdvanced = FALSE;
    return gSpecialVar_Result;
}

