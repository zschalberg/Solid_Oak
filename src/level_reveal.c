#include "global.h"
#include "level_reveal.h"
#include "item.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_size_record.h"
#include "research_turnin.h"
#include "string_util.h"
#include "strings.h"
#include "constants/characters.h"
#include "constants/items.h"

// Research score a species needs to reach each tier past LEVEL_REVEAL_SIZE,
// counted in half points so a sighting can be worth less than a catch.
// Entry i is the score for tier i + 1.
static const u8 sLevelRevealThresholds[LEVEL_REVEAL_FULL] = {2, 6, 12};

#define RESEARCH_SEEN_POINTS    1 // Per battle the species was seen in
#define RESEARCH_CAUGHT_POINTS  2 // Per catch
#define RESEARCH_TURN_IN_BONUS  6 // Once its family is turned in at the Reserve
#define RESEARCH_RAISED_POINTS  1 // Per RAISED_LEVELS_PER_UNIT levels raised in its family

// Raising is measured as current level minus met level, so catching a high
// level Pokemon doesn't count. Stored as a nibble per family, so it caps at
// RAISED_UNITS_MAX units (75 levels).
#define RAISED_LEVELS_PER_UNIT  5
#define RAISED_UNITS_MAX        15

// Catches across all species sharing a type give a floor on the tier of every
// species with that type, even ones never encountered. Entry i is the number
// of catches for tier i + 1.
static const u8 sTypeInsightThresholds[] = {10, 20};

static const u8 sText_SizeXS[] = _("XS");
static const u8 sText_SizeS[]  = _("S");
static const u8 sText_SizeM[]  = _("M");
static const u8 sText_SizeL[]  = _("L");
static const u8 sText_SizeXL[] = _("XL");

static u8 GetFamilyRaisedUnits(u16 nationalNum)
{
    u8 packed = gSaveBlock1Ptr->familyRaisedLevels[nationalNum / 2];
    return (nationalNum % 2) ? (packed >> 4) : (packed & 0xF);
}

static void SetFamilyRaisedUnits(u16 nationalNum, u8 units)
{
    u8 *packed = &gSaveBlock1Ptr->familyRaisedLevels[nationalNum / 2];

    if (nationalNum % 2)
        *packed = (*packed & 0x0F) | (units << 4);
    else
        *packed = (*packed & 0xF0) | units;
}

static u16 GetFamilyNationalNum(u16 species)
{
    u16 nationalNum = SpeciesToNationalPokedexNum(GetFamilyBaseSpecies(species));

    if (nationalNum == NATIONAL_DEX_NONE || nationalNum >= DEX_COUNTS_MAX_SPECIES)
        return NATIONAL_DEX_NONE;
    return nationalNum;
}

// Called whenever a Pokemon's level goes up. Only the player's party counts.
void RecordMonRaised(struct Pokemon *mon)
{
    u16 nationalNum;
    s32 levelsRaised;
    u8 units;

    if (mon < &gPlayerParty[0] || mon >= &gPlayerParty[PARTY_SIZE])
        return;

    nationalNum = GetFamilyNationalNum(GetMonData(mon, MON_DATA_SPECIES));
    if (nationalNum == NATIONAL_DEX_NONE)
        return;

    levelsRaised = GetMonData(mon, MON_DATA_LEVEL) - GetMonData(mon, MON_DATA_MET_LEVEL);
    if (levelsRaised <= 0)
        return;

    units = min(levelsRaised / RAISED_LEVELS_PER_UNIT, RAISED_UNITS_MAX);
    if (units > GetFamilyRaisedUnits(nationalNum))
        SetFamilyRaisedUnits(nationalNum, units);
}

// Total catches of every species sharing either of this species' types.
static u8 GetTypeInsightTier(u16 species)
{
    enum Type type1 = GetSpeciesType(species, 0);
    enum Type type2 = GetSpeciesType(species, 1);
    u32 caught1 = 0, caught2 = 0;
    u32 best;
    u16 nationalNum;
    u8 tier;

    for (nationalNum = 1; nationalNum < DEX_COUNTS_MAX_SPECIES; nationalNum++)
    {
        u8 caught = gSaveBlock1Ptr->pokedexCaught[nationalNum];
        enum Species other;
        enum Type otherType1, otherType2;

        if (caught == 0)
            continue;
        other = NationalPokedexNumToSpecies(nationalNum);
        otherType1 = GetSpeciesType(other, 0);
        otherType2 = GetSpeciesType(other, 1);
        if (otherType1 == type1 || otherType2 == type1)
            caught1 += caught;
        if (type2 != type1 && (otherType1 == type2 || otherType2 == type2))
            caught2 += caught;
    }

    best = max(caught1, caught2);
    for (tier = 0; tier < ARRAY_COUNT(sTypeInsightThresholds); tier++)
    {
        if (best < sTypeInsightThresholds[tier])
            break;
    }
    return tier;
}

u8 GetLevelRevealTier(u16 species, bool32 isPlayerMon)
{
    u32 score;
    u16 familyNum;
    u8 tier;

    if (!CheckBagHasItem(ITEM_FIELD_NOTEBOOK, 1))
        return LEVEL_REVEAL_SIZE;

    // Sightings alone can reveal an exact level, but EXP details need
    // catches, turn-ins or raising.
    score = GET_DEX_SEEN_COUNT(species) * RESEARCH_SEEN_POINTS;
    if (score > sLevelRevealThresholds[LEVEL_REVEAL_EXACT - 1])
        score = sLevelRevealThresholds[LEVEL_REVEAL_EXACT - 1];

    score += GET_DEX_CAUGHT_COUNT(species) * RESEARCH_CAUGHT_POINTS;
    if (IsSpeciesFamilyReserved(species))
        score += RESEARCH_TURN_IN_BONUS;

    familyNum = GetFamilyNationalNum(species);
    if (familyNum != NATIONAL_DEX_NONE)
        score += GetFamilyRaisedUnits(familyNum) * RESEARCH_RAISED_POINTS;

    for (tier = LEVEL_REVEAL_SIZE; tier < ARRAY_COUNT(sLevelRevealThresholds); tier++)
    {
        if (score < sLevelRevealThresholds[tier])
            break;
    }

    // Type knowledge only fills gaps; it never goes past an exact level.
    if (tier < LEVEL_REVEAL_EXACT)
    {
        u8 typeTier = GetTypeInsightTier(species);
        if (typeTier > tier)
            tier = typeTier;
    }

    // The player has handled their own Pokemon up close, so they always
    // know one tier more about them than about wild or trainer Pokemon.
    if (isPlayerMon && tier < LEVEL_REVEAL_FULL)
        tier++;

    return tier;
}

// Height bands follow the same category split as GetSizeCategoryExceptionalTier
// in pokemon_size_record.c: 6-9 are average, 0-2 and 13-15 are very rare.
static const u8 *GetSizeClassText(u32 personality)
{
    u8 category = TranslateBigMonSizeTableIndex(personality & 0xFFFF);

    if (category <= 2)
        return sText_SizeXS;
    if (category <= 5)
        return sText_SizeS;
    if (category <= 9)
        return sText_SizeM;
    if (category <= 12)
        return sText_SizeL;
    return sText_SizeXL;
}

// Writes what the player knows of a level into dest and returns a pointer to
// its EOS. Size classes never carry the "Lv" prefix.
u8 *BufferRevealedLevel(u8 *dest, u16 species, u32 personality, u8 level, u8 tier, bool32 withLvPrefix)
{
    if (tier == LEVEL_REVEAL_SIZE)
        return StringCopy(dest, GetSizeClassText(personality));

    if (withLvPrefix)
        dest = StringCopy(dest, gText_Lv);

    if (tier == LEVEL_REVEAL_RANGE)
    {
        dest = ConvertIntToDecimalStringN(dest, level / 10, STR_CONV_MODE_LEFT_ALIGN, 2);
        *dest++ = CHAR_QUESTION_MARK;
        *dest = EOS;
        return dest;
    }

    return ConvertIntToDecimalStringN(dest, level, STR_CONV_MODE_LEFT_ALIGN, 3);
}

// Level gaps at which the strength hint shows one arrow, then two.
#define STRENGTH_HINT_GAP       4
#define STRENGTH_HINT_GAP_LARGE 10

// Appends an arrow comparing level against compareLevel: up if it is
// stronger, down if weaker, nothing if within STRENGTH_HINT_GAP - 1 levels.
// The arrows only exist in FONT_SMALL. Returns a pointer to the new EOS.
u8 *BufferStrengthHint(u8 *dest, u8 level, u8 compareLevel)
{
    s32 gap = level - compareLevel;
    u8 arrow;

    if (gap >= STRENGTH_HINT_GAP_LARGE)
        arrow = CHAR_STRENGTH_UP_2;
    else if (gap >= STRENGTH_HINT_GAP)
        arrow = CHAR_STRENGTH_UP;
    else if (gap <= -STRENGTH_HINT_GAP_LARGE)
        arrow = CHAR_STRENGTH_DOWN_2;
    else if (gap <= -STRENGTH_HINT_GAP)
        arrow = CHAR_STRENGTH_DOWN;
    else
        return dest;

    *dest++ = CHAR_EXTRA_SYMBOL;
    *dest++ = arrow;
    *dest = EOS;
    return dest;
}
