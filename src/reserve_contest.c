#include "global.h"
#include "pokemon.h"
#include "event_data.h"
#include "wild_encounter.h"
#include "research_turnin.h"
#include "ball_economy.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "text.h"
#include "rtc.h"
#include "item.h"
#include "coins.h"
#include "party_menu.h"
#include "pokemon_storage_system.h"
#include "pokemon_summary_screen.h"
#include "pokemon_size_record.h"
#include "overworld.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/pokeball.h"
#include "constants/maps.h"
#include "reserve_contest.h"


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

static EWRAM_DATA struct Pokemon sReserveContestSavedParty[PARTY_SIZE];
static EWRAM_DATA u8 sReserveContestSavedPartyCount = 0;
static EWRAM_DATA u8 sReserveContestChosenSlot = 0;

static void RestorePlayerParty(bool8 keptSpecimen);

void ResetReserveContestAttempts(void)
{
    VarSet(VAR_RESERVE_CONTEST_ATTEMPTS, 3);
}

u8 GetReserveContestAttemptsRemaining(void)
{
    gSpecialVar_Result = VarGet(VAR_RESERVE_CONTEST_ATTEMPTS);
    return gSpecialVar_Result;
}

bool8 CheckCanRegisterReserveContest(void)
{
    u8 partyCount = CalculatePlayerPartyCount();
    u8 i;
    bool8 hasValidMon = FALSE;

    for (i = 0; i < partyCount; i++)
    {
        if (!GetMonData(&gPlayerParty[i], MON_DATA_IS_EGG)
         && GetMonData(&gPlayerParty[i], MON_DATA_HP) > 0
         && GetMonData(&gPlayerParty[i], MON_DATA_POKEBALL) != BALL_RESEARCH)
        {
            hasValidMon = TRUE;
            break;
        }
    }

    gSpecialVar_Result = hasValidMon;
    return gSpecialVar_Result;
}

void ValidateReserveContestChosenMon(void)
{
    u8 slot = gSpecialVar_0x8004;

    if (slot >= gPlayerPartyCount || slot >= PARTY_SIZE)
    {
        gSpecialVar_Result = 1; // Invalid / cancel
        return;
    }

    if (GetMonData(&gPlayerParty[slot], MON_DATA_IS_EGG))
    {
        gSpecialVar_Result = 2; // Egg
        return;
    }

    if (GetMonData(&gPlayerParty[slot], MON_DATA_HP) == 0)
    {
        gSpecialVar_Result = 3; // Fainted
        return;
    }

    if (GetMonData(&gPlayerParty[slot], MON_DATA_POKEBALL) == BALL_RESEARCH)
    {
        gSpecialVar_Result = 4; // Research Ball
        return;
    }

    gSpecialVar_Result = 0; // Valid
}

void SavePlayerPartyForReserveContest(void)
{
    u8 slot = gSpecialVar_0x8004;
    u8 i;

    if (slot >= gPlayerPartyCount || slot >= PARTY_SIZE)
        slot = 0;

    sReserveContestSavedPartyCount = gPlayerPartyCount;
    sReserveContestChosenSlot = slot;

    for (i = 0; i < PARTY_SIZE; i++)
        sReserveContestSavedParty[i] = gPlayerParty[i];

    // Put chosen mon into slot 0
    gPlayerParty[0] = sReserveContestSavedParty[slot];

    // Zero out remaining slots
    for (i = 1; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);

    gPlayerPartyCount = 1;
    CalculatePlayerPartyCount();
}

static void RestorePlayerParty(bool8 keptSpecimen)
{
    u8 i;
    struct Pokemon keptMon;
    bool8 hasKeptMon = FALSE;

    if (sReserveContestSavedPartyCount == 0)
        return;

    if (keptSpecimen && gPlayerPartyCount >= 2 && GetMonData(&gPlayerParty[1], MON_DATA_POKEBALL) == BALL_RESEARCH)
    {
        keptMon = gPlayerParty[1];
        hasKeptMon = TRUE;
    }

    // Preserve any state changes to the chosen partner mon (EXP, HP, status, held item)
    sReserveContestSavedParty[sReserveContestChosenSlot] = gPlayerParty[0];

    // If partner fainted (e.g. whiteout), heal all party members
    if (GetMonData(&gPlayerParty[0], MON_DATA_HP) == 0)
    {
        for (i = 0; i < sReserveContestSavedPartyCount; i++)
            HealPokemon(&sReserveContestSavedParty[i]);
    }

    // Restore saved party
    for (i = 0; i < sReserveContestSavedPartyCount; i++)
        gPlayerParty[i] = sReserveContestSavedParty[i];

    for (i = sReserveContestSavedPartyCount; i < PARTY_SIZE; i++)
        ZeroMonData(&gPlayerParty[i]);

    gPlayerPartyCount = sReserveContestSavedPartyCount;

    if (hasKeptMon)
    {
        if (sReserveContestSavedPartyCount < PARTY_SIZE)
        {
            gPlayerParty[sReserveContestSavedPartyCount] = keptMon;
            gPlayerPartyCount++;
            gSpecialVar_Result = 0; // Kept in party
        }
        else
        {
            u8 pcResult = CopyMonToPC(&keptMon);
            if (pcResult == MON_GIVEN_TO_PC)
            {
                GetMonNickname(&keptMon, gStringVar1);
                StringCopy(gStringVar2, GetBoxNamePtr(VarGet(VAR_PC_BOX_TO_SEND_MON)));
                gSpecialVar_Result = 1; // Sent to PC
            }
            else
            {
                gSpecialVar_Result = 2; // Box full
            }
        }
    }

    CalculatePlayerPartyCount();

    sReserveContestSavedPartyCount = 0;
    sReserveContestChosenSlot = 0;
    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&sReserveContestSavedParty[i]);
}

void RestorePlayerPartyFromReserveContest(void)
{
    RestorePlayerParty(FALSE);
}

void StartReserveContestSession(void)
{
    // Save-backed var, not an EWRAM static - a save/reload mid-session must
    // not lose the chosen category while FLAG_RESERVE_CONTEST_ACTIVE (which
    // is itself save-backed) survives the reload.
    VarSet(VAR_RESERVE_CONTEST_CATEGORY, gSpecialVar_0x8004);

    FlagSet(FLAG_RESERVE_CONTEST_ACTIVE);
    FlagClear(FLAG_RESERVE_CONTEST_CAUGHT);

    // Remember what the player walked in with so EndReserveContestSession can
    // reclaim only the loaned balls and never the player's own stock.
    VarSet(VAR_RESERVE_CONTEST_BALLS_HELD, CountTotalItemQuantityInBag(ITEM_RESEARCH_BALL));

    AddBagItem(ITEM_RESEARCH_BALL, RESERVE_CONTEST_BALL_LOAN);

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
    //
    // Anything else (notably MULTI_B_PRESSED == 127) is not a choice. The
    // caller's multichoice sets ignoreBPress, but discarding a specimen is
    // irreversible, so refuse rather than treat an unknown value as "Mon 2".
    if (gSpecialVar_0x8004 > 1)
    {
        gSpecialVar_Result = FALSE;
        return;
    }

    if (gPlayerPartyCount >= 3)
    {
        u8 keepSlot = (gSpecialVar_0x8004 == 0) ? 1 : 2;
        u8 discardSlot = (gSpecialVar_0x8004 == 0) ? 2 : 1;

        // Safety: NEVER discard a Pokémon that is not caught in a Research Ball!
        if (GetMonData(&gPlayerParty[discardSlot], MON_DATA_POKEBALL) != BALL_RESEARCH)
        {
            gSpecialVar_Result = FALSE;
            return;
        }

        GetMonNickname(&gPlayerParty[keepSlot], gStringVar1);
        GetMonNickname(&gPlayerParty[discardSlot], gStringVar2);

        // Discard mon - ball economy: released for good, ball frees back to the bag.
        gSpecialVar_0x8009 = FreeMonBall(&gPlayerParty[discardSlot]) ? FALSE : TRUE;

        if (discardSlot == 1)
        {
            // Move Mon 2 to Mon 1 slot and discard slot 2
            gPlayerParty[1] = gPlayerParty[2];
        }
        ZeroMonData(&gPlayerParty[2]);
        CompactPartySlots();
        CalculatePlayerPartyCount();

        gSpecialVar_Result = TRUE;
    }
    else
    {
        gSpecialVar_Result = FALSE;
    }
}

void EvaluateReserveContestCatch(void)
{
    struct Pokemon *mon = &gPlayerParty[1];
    enum Species species = GetMonData(mon, MON_DATA_SPECIES);
    u32 personality = GetMonData(mon, MON_DATA_PERSONALITY);
    u8 *ptr = gStringVar4;
    u16 reserveContestCategory = VarGet(VAR_RESERVE_CONTEST_CATEGORY);

    GetMonNickname(mon, gStringVar1);

    if (reserveContestCategory == 0) // Size
    {
        u16 heightPercentile = ((personality & 0xFFFF) * 1000) / 65535;
        u16 weightPercentile = (((personality >> 16) & 0xFFFF) * 1000) / 65535;
        // Same categorical tiering used everywhere else size rarity is
        // judged (exceptional-catch messages, the Pokedex Size Records
        // page, wild spawn biasing in wild_encounter.c) - see
        // pokemon_size_record.c. The percentiles above are still a literal
        // percentile of the raw personality hash and are shown as-is for
        // context, but the Record/Notable/Unremarkable rating below used to
        // come from an unrelated linear distance-from-median threshold that
        // didn't match this tiering, so the same catch could be called a
        // "Record Specimen" here while being unremarkable everywhere else.
        u8 sizeTier = GetPersonalitySizeTier(personality);

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
        if (sizeTier >= 3) // Very Rare
            ptr = StringCopy(ptr, sText_SizeRecord);
        else if (sizeTier == 2) // Rare
            ptr = StringCopy(ptr, sText_SizeNotable);
        else
            ptr = StringCopy(ptr, sText_SizeUnremarkable);
    }
    else if (reserveContestCategory == 1) // Vitality (IVs)
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
    // Safety: only operate on slot 1 if it is a Research Ball specimen
    if (gPlayerPartyCount >= 2 && GetMonData(&gPlayerParty[1], MON_DATA_POKEBALL) == BALL_RESEARCH)
    {
        GetMonNickname(&gPlayerParty[1], gStringVar1);

        if (gSpecialVar_0x8004 == 0) // Keep
        {
            // The specimen stays in BALL_RESEARCH! Restore saved party and add specimen (or send to PC)
            RestorePlayerParty(TRUE);
        }
        else // Turn-In
        {
            u16 coins = CalculateResearchMonCoins(&gPlayerParty[1]);

            // Log the family before awarding, exactly as the Oak's Lab /
            // Reserve worker turn-in does. CalculateResearchMonCoins pays a
            // "new family" bonus, so skipping this would re-pay that bonus
            // for the same family on every contest turn-in, and would never
            // advance the Reserve's encounter stages.
            RegisterResearchTurnIn(&gPlayerParty[1]);

            AddCoins(coins);
            ConvertIntToDecimalStringN(gStringVar3, coins, STR_CONV_MODE_LEFT_ALIGN, 5);
            // Ball economy: turned in for good, ball frees back to the bag.
            gSpecialVar_0x8009 = FreeMonBall(&gPlayerParty[1]) ? FALSE : TRUE;
            ZeroMonData(&gPlayerParty[1]);
            CompactPartySlots();
            CalculatePlayerPartyCount();
            RestorePlayerParty(FALSE);
            gSpecialVar_Result = FALSE;
        }
    }
    else
    {
        RestorePlayerParty(FALSE);
    }

    EndReserveContestSession();
}

// Ends a contest session: reclaims the balls the Reserve loaned out (never
// the player's own stock, tracked in VAR_RESERVE_CONTEST_BALLS_HELD) and
// clears the session flags. Safe to call more than once - once the flag is
// clear there is nothing left to reclaim.
void EndReserveContestSession(void)
{
    if (FlagGet(FLAG_RESERVE_CONTEST_ACTIVE))
    {
        u16 held = CountTotalItemQuantityInBag(ITEM_RESEARCH_BALL);
        u16 owned = VarGet(VAR_RESERVE_CONTEST_BALLS_HELD);

        if (held > owned)
            RemoveBagItem(ITEM_RESEARCH_BALL, held - owned);

        // If party backup is still held (e.g. session was abandoned or whited out), restore it
        if (sReserveContestSavedPartyCount > 0)
        {
            RestorePlayerParty(FALSE);
        }
    }

    VarSet(VAR_RESERVE_CONTEST_BALLS_HELD, 0);
    FlagClear(FLAG_RESERVE_CONTEST_ACTIVE);
    FlagClear(FLAG_RESERVE_CONTEST_CAUGHT);
}
