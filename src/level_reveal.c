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

static const u8 sText_SizeXS[] = _("XS");
static const u8 sText_SizeS[]  = _("S");
static const u8 sText_SizeM[]  = _("M");
static const u8 sText_SizeL[]  = _("L");
static const u8 sText_SizeXL[] = _("XL");

u8 GetLevelRevealTier(u16 species, bool32 isPlayerMon)
{
    u32 score;
    u8 tier;

    if (!CheckBagHasItem(ITEM_FIELD_NOTEBOOK, 1))
        return LEVEL_REVEAL_SIZE;

    // Sightings alone can reveal an exact level, but EXP details need
    // catches or turn-ins.
    score = GET_DEX_SEEN_COUNT(species) * RESEARCH_SEEN_POINTS;
    if (score > sLevelRevealThresholds[LEVEL_REVEAL_EXACT - 1])
        score = sLevelRevealThresholds[LEVEL_REVEAL_EXACT - 1];

    score += GET_DEX_CAUGHT_COUNT(species) * RESEARCH_CAUGHT_POINTS;
    if (IsSpeciesFamilyReserved(species))
        score += RESEARCH_TURN_IN_BONUS;

    for (tier = LEVEL_REVEAL_SIZE; tier < ARRAY_COUNT(sLevelRevealThresholds); tier++)
    {
        if (score < sLevelRevealThresholds[tier])
            break;
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
