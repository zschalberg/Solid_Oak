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

// Variables to cache evaluation details between specials
static u16 sEvaluatedCoins;

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

void EvaluateSelectedResearchMon(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u8 catchRate = gSpeciesInfo[species].catchRate;
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    bool8 isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
    
    u16 baseCoins = 0;
    u16 sizeBonus = 0;
    u16 ivBonus = 0;
    u16 familyBonus = 0;
    u16 totalCoins = 0;
    
    u8 heightCategory = TranslateBigMonSizeTableIndex(personality & 0xFFFF);
    u8 weightCategory = TranslateBigMonSizeTableIndex(personality >> 16);
    bool32 heightOutlier = (heightCategory <= 4 || heightCategory >= 11);
    bool32 weightOutlier = (weightCategory <= 4 || weightCategory >= 11);
    
    // 1. Base Rarity based on catch rate
    if (catchRate >= 150)
        baseCoins = 10;       // Common
    else if (catchRate >= 75)
        baseCoins = 30;       // Uncommon
    else if (catchRate >= 31)
        baseCoins = 100;      // Rare
    else
        baseCoins = 350;      // Legendary/Mythical

    // 2. Size Outlier Bonus
    if (heightOutlier && weightOutlier)
        sizeBonus = 150;      // Record Specimen Bonus
    else if (heightOutlier || weightOutlier)
        sizeBonus = 50;       // Size Outlier Bonus

    // 3. Perfect IVs Bonus
    if (GetMonData(mon, MON_DATA_HP_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_ATK_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_DEF_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPEED_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPATK_IV) == 31) ivBonus += 25;
    if (GetMonData(mon, MON_DATA_SPDEF_IV) == 31) ivBonus += 25;

    // 4. New Family Bonus
    if (CheckIsNewFamily(mon))
        familyBonus = 250;

    // 5. Calculate Final Coins with Shiny Multiplier
    // Formula: Final Coins = (Base + Outlier + IVs + Family) * (isShiny ? 2 : 1) + (isShiny ? 500 : 0)
    totalCoins = baseCoins + sizeBonus + ivBonus + familyBonus;
    if (isShiny)
    {
        totalCoins = (totalCoins * 2) + 500;
    }
    
    // Cache the coins for the TurnIn special
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
    // Double-check party count safety to prevent empty party crashes
    if (gPlayerPartyCount > 1)
    {
        struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
        enum Species species = GetMonData(mon, MON_DATA_SPECIES);
        enum Species baseSpecies = GetFamilyBaseSpecies(species);
        u16 nationalNum = SpeciesToNationalPokedexNum(baseSpecies);
        
        // Mark the family as turned in
        if (nationalNum != NATIONAL_DEX_NONE)
        {
            gSaveBlock1Ptr->reserveSpeciesTurnedIn[nationalNum / 8] |= (1 << (nationalNum % 8));
        }

        // Award the coins using native AddCoins (handles limit and overflow protection)
        AddCoins(sEvaluatedCoins);

        // Remove the selected mon from the party
        ZeroMonData(mon);
        CompactPartySlots();
        CalculatePlayerPartyCount();
    }

    // Overwrite gStringVar3 with just the final total coins for use in the success msgbox
    ConvertIntToDecimalStringN(gStringVar3, sEvaluatedCoins, STR_CONV_MODE_LEFT_ALIGN, 5);
}

void TransferSelectedMonToPokeBall(void)
{
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u16 ball = BALL_POKE;
    
    // Set the nickname for use in the script success message
    GetMonNickname(mon, gStringVar1);
    
    SetMonData(mon, MON_DATA_POKEBALL, &ball);
}

