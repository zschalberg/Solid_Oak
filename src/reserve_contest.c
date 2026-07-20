#include "global.h"
#include "pokemon.h"
#include "event_data.h"
#include "wild_encounter.h"
#include "research_turnin.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "text.h"
#include "rtc.h"
#include "item.h"
#include "coins.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "overworld.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/pokeball.h"
#include "constants/maps.h"
#include "reserve_contest.h"

static EWRAM_DATA u8 sReserveContestCategory = 0;

// Text constants for evaluation formatting
static const u8 sText_EvaluationHeader[] = _("Specimen Evaluation:\n");
static const u8 sText_EvaluationHeight[] = _("Height Percentile: ");
static const u8 sText_EvaluationWeight[] = _("Weight Percentile: ");
static const u8 sText_DotChar[] = _(".");
static const u8 sText_PercentChar[] = _("%\n");
static const u8 sText_PercentPageChar[] = _("%\p");
static const u8 sText_EvaluationRating[] = _("Rating:\n");

static const u8 sText_SizeRecord[] = _("Record Specimen");
static const u8 sText_SizeNotable[] = _("Notable Specimen");
static const u8 sText_SizeUnremarkable[] = _("Unremarkable Specimen");

static const u8 sText_EvaluationVitality[] = _("Vitality (IVs): ");
static const u8 sText_TotalIVs[] = _("Total IVs: ");
static const u8 sText_NewlineChar[] = _("\n");

static const u8 sText_IVGrade_Outstanding[] = _("Outstanding");
static const u8 sText_IVGrade_Good[]        = _("Good");
static const u8 sText_IVGrade_Decent[]      = _("Decent");
static const u8 sText_IVGrade_Poor[]        = _("Poor");

static const u8 sText_EvaluationRarity[] = _("Rarity: ");
static const u8 sText_RarityCommon[] = _("Common");
static const u8 sText_RarityUncommon[] = _("Uncommon");
static const u8 sText_RarityRare[] = _("Rare");
static const u8 sText_RarityLegendary[] = _("Legendary");
static const u8 sText_ShinySuffix[] = _(" (Shiny!)");
static const u8 sText_RarityScore[] = _("Rarity Score: ");

void ResetReserveContestAttempts(void)
{
    VarSet(VAR_RESERVE_CONTEST_ATTEMPTS, 3);
}

void GetReserveContestAttemptsRemaining(void)
{
    gSpecialVar_Result = VarGet(VAR_RESERVE_CONTEST_ATTEMPTS);
}

void CheckCanRegisterReserveContest(void)
{
    if (gPlayerPartyCount == 1)
        gSpecialVar_Result = TRUE;
    else
        gSpecialVar_Result = FALSE;
}

void StartReserveContestSession(void)
{
    sReserveContestCategory = gSpecialVar_0x8004;

    FlagSet(FLAG_RESERVE_CONTEST_ACTIVE);
    FlagClear(FLAG_RESERVE_CONTEST_CAUGHT);

    AddBagItem(ITEM_RESEARCH_BALL, 30);

    {
        u16 attempts = VarGet(VAR_RESERVE_CONTEST_ATTEMPTS);
        if (attempts > 0)
            VarSet(VAR_RESERVE_CONTEST_ATTEMPTS, attempts - 1);
    }

    gSpecialVar_Result = TRUE;
}

void GetReserveContestCatchNicknames(void)
{
    if (gPlayerPartyCount >= 2)
        GetMonNickname(&gPlayerParty[1], gStringVar1);
    if (gPlayerPartyCount >= 3)
        GetMonNickname(&gPlayerParty[2], gStringVar2);
}

#include "field_fadetransition.h"

void OpenReserveContestSpecimenSummary(void)
{
    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
    ShowPokemonSummaryScreen(gPlayerParty, 1, 2, CB2_ReturnToField, PSS_MODE_NORMAL);
}

void ProcessReserveContestSpecimenChoice(void)
{
    // gSpecialVar_0x8004: 0 = Keep Mon 1 (gPlayerParty[1]), 1 = Keep Mon 2 (gPlayerParty[2])
    if (gPlayerPartyCount >= 3)
    {
        if (gSpecialVar_0x8004 == 0) // Keep Mon 1
        {
            GetMonNickname(&gPlayerParty[1], gStringVar1);
            GetMonNickname(&gPlayerParty[2], gStringVar2);

            // Discard Mon 2
            ZeroMonData(&gPlayerParty[2]);
            CompactPartySlots();
            CalculatePlayerPartyCount();
        }
        else // Keep Mon 2
        {
            GetMonNickname(&gPlayerParty[2], gStringVar1);
            GetMonNickname(&gPlayerParty[1], gStringVar2);

            // Move Mon 2 to Mon 1 slot and discard slot 2
            gPlayerParty[1] = gPlayerParty[2];
            ZeroMonData(&gPlayerParty[2]);
            CompactPartySlots();
            CalculatePlayerPartyCount();
        }
    }
}

void EvaluateReserveContestCatch(void)
{
    struct Pokemon *mon = &gPlayerParty[1];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    u8 *ptr = gStringVar4;

    GetMonNickname(mon, gStringVar1);

    if (sReserveContestCategory == 0) // Size
    {
        u16 heightPercentile = ((personality & 0xFFFF) * 1000) / 65535;
        u16 weightPercentile = (((personality >> 16) & 0xFFFF) * 1000) / 65535;
        u16 heightDist = (heightPercentile >= 500) ? (heightPercentile - 500) : (500 - heightPercentile);
        u16 weightDist = (weightPercentile >= 500) ? (weightPercentile - 500) : (500 - weightPercentile);
        u16 maxDist = (heightDist >= weightDist) ? heightDist : weightDist;

        ptr = StringCopy(ptr, sText_EvaluationHeight);
        ptr = ConvertIntToDecimalStringN(ptr, heightPercentile / 10, STR_CONV_MODE_LEFT_ALIGN, 3);
        ptr = StringCopy(ptr, sText_DotChar);
        ptr = ConvertIntToDecimalStringN(ptr, heightPercentile % 10, STR_CONV_MODE_LEFT_ALIGN, 1);
        ptr = StringCopy(ptr, sText_PercentChar);

        ptr = StringCopy(ptr, sText_EvaluationWeight);
        ptr = ConvertIntToDecimalStringN(ptr, weightPercentile / 10, STR_CONV_MODE_LEFT_ALIGN, 3);
        ptr = StringCopy(ptr, sText_DotChar);
        ptr = ConvertIntToDecimalStringN(ptr, weightPercentile % 10, STR_CONV_MODE_LEFT_ALIGN, 1);
        ptr = StringCopy(ptr, sText_PercentPageChar);

        ptr = StringCopy(ptr, sText_EvaluationRating);
        if (maxDist >= 450 || (heightDist >= 350 && weightDist >= 350))
            ptr = StringCopy(ptr, sText_SizeRecord);
        else if (maxDist >= 300)
            ptr = StringCopy(ptr, sText_SizeNotable);
        else
            ptr = StringCopy(ptr, sText_SizeUnremarkable);
    }
    else if (sReserveContestCategory == 1) // Vitality (IVs)
    {
        u32 hpIV = GetMonData(mon, MON_DATA_HP_IV);
        u32 atkIV = GetMonData(mon, MON_DATA_ATK_IV);
        u32 defIV = GetMonData(mon, MON_DATA_DEF_IV);
        u32 speedIV = GetMonData(mon, MON_DATA_SPEED_IV);
        u32 spatkIV = GetMonData(mon, MON_DATA_SPATK_IV);
        u32 spdefIV = GetMonData(mon, MON_DATA_SPDEF_IV);
        u32 totalIV = hpIV + atkIV + defIV + speedIV + spatkIV + spdefIV;
        enum IVRatingTier tier = GetIVSumRatingTier(totalIV);
        const u8 *gradeString;

        switch (tier)
        {
            case IV_RATING_OUTSTANDING: gradeString = sText_IVGrade_Outstanding; break;
            case IV_RATING_GOOD:        gradeString = sText_IVGrade_Good; break;
            case IV_RATING_DECENT:      gradeString = sText_IVGrade_Decent; break;
            default:
            case IV_RATING_POOR:        gradeString = sText_IVGrade_Poor; break;
        }

        ptr = StringCopy(ptr, sText_EvaluationVitality);
        ptr = StringCopy(ptr, gradeString);
        ptr = StringCopy(ptr, sText_NewlineChar);
        ptr = StringCopy(ptr, sText_TotalIVs);
        ptr = ConvertIntToDecimalStringN(ptr, totalIV, STR_CONV_MODE_LEFT_ALIGN, 3);
    }
    else // Rarity
    {
        u8 catchRate = gSpeciesInfo[species].catchRate;
        u16 rarityPoints = GetBaseRarityPoints(catchRate);
        bool8 isShiny = GetMonData(mon, MON_DATA_IS_SHINY);
        u16 finalPoints = ApplyShinyBonus(rarityPoints, isShiny);
        const u8 *rarityString;

        if (catchRate >= 150)
            rarityString = sText_RarityCommon;
        else if (catchRate >= 75)
            rarityString = sText_RarityUncommon;
        else if (catchRate >= 31)
            rarityString = sText_RarityRare;
        else
            rarityString = sText_RarityLegendary;

        ptr = StringCopy(ptr, sText_EvaluationRarity);
        ptr = StringCopy(ptr, rarityString);
        if (isShiny)
            ptr = StringCopy(ptr, sText_ShinySuffix);
        ptr = StringCopy(ptr, sText_NewlineChar);
        ptr = StringCopy(ptr, sText_RarityScore);
        ptr = ConvertIntToDecimalStringN(ptr, finalPoints, STR_CONV_MODE_LEFT_ALIGN, 5);
    }
}

void FinalizeReserveContestCatch(void)
{
    // gSpecialVar_0x8004 == 0 (Keep), 1 (Turn-In)
    if (gPlayerPartyCount >= 2)
    {
        GetMonNickname(&gPlayerParty[1], gStringVar1);

        if (gSpecialVar_0x8004 == 0) // Keep
        {
            u16 pokeBall = BALL_POKE;
            SetMonData(&gPlayerParty[1], MON_DATA_POKEBALL, &pokeBall);
            gSpecialVar_Result = TRUE;
        }
        else // Turn-In
        {
            u16 coins = CalculateResearchMonCoins(&gPlayerParty[1]);
            AddCoins(coins);
            ConvertIntToDecimalStringN(gStringVar3, coins, STR_CONV_MODE_LEFT_ALIGN, 5);
            ZeroMonData(&gPlayerParty[1]);
            CompactPartySlots();
            CalculatePlayerPartyCount();
            gSpecialVar_Result = FALSE;
        }
    }

    FlagClear(FLAG_RESERVE_CONTEST_ACTIVE);
    FlagClear(FLAG_RESERVE_CONTEST_CAUGHT);
}
