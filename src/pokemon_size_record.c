#include "global.h"
#include "pokemon_size_record.h"
#include "data.h"
#include "event_data.h"
#include "pokedex.h"
#include "pokemon.h"
#include "constants/pokedex.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "random.h"

#define DEFAULT_MAX_SIZE 0 // was 0x8100 in Ruby/Sapphire, 0x8000 in Emerald

struct UnknownStruct
{
    u16 unk0;
    u8 unk2;
    u16 unk4;
};

static const struct UnknownStruct sBigMonSizeTable[] =
{
    {  290,   1,      0 },
    {  300,   1,     10 },
    {  400,   2,    110 },
    {  500,   4,    310 },
    {  600,  20,    710 },
    {  700,  50,   2710 },
    {  800, 100,   7710 },
    {  900, 150,  17710 },
    { 1000, 150,  32710 },
    { 1100, 100,  47710 },
    { 1200,  50,  57710 },
    { 1300,  20,  62710 },
    { 1400,   5,  64710 },
    { 1500,   2,  65210 },
    { 1600,   1,  65410 },
    { 1700,   1,  65510 },
};

static const u8 sGiftRibbonsMonDataIds[] =
{
    MON_DATA_MARINE_RIBBON, MON_DATA_LAND_RIBBON, MON_DATA_SKY_RIBBON,
    MON_DATA_COUNTRY_RIBBON, MON_DATA_NATIONAL_RIBBON, MON_DATA_EARTH_RIBBON,
    MON_DATA_WORLD_RIBBON
};

#define CM_PER_INCH 2.54

static u32 GetMonSizeHash(struct Pokemon *pkmn)
{
    u16 personality = GetMonData(pkmn, MON_DATA_PERSONALITY);
    u16 hpIV = GetMonData(pkmn, MON_DATA_HP_IV) & 0xF;
    u16 attackIV = GetMonData(pkmn, MON_DATA_ATK_IV) & 0xF;
    u16 defenseIV = GetMonData(pkmn, MON_DATA_DEF_IV) & 0xF;
    u16 speedIV = GetMonData(pkmn, MON_DATA_SPEED_IV) & 0xF;
    u16 spAtkIV = GetMonData(pkmn, MON_DATA_SPATK_IV) & 0xF;
    u16 spDefIV = GetMonData(pkmn, MON_DATA_SPDEF_IV) & 0xF;
    u32 hibyte = ((attackIV ^ defenseIV) * hpIV) ^ (personality & 0xFF);
    u32 lobyte = ((spAtkIV ^ spDefIV) * speedIV) ^ (personality >> 8);

    return (hibyte << 8) + lobyte;
}

u8 TranslateBigMonSizeTableIndex(u16 a)
{
    u8 i;

    for (i = 1; i < 15; i++)
    {
        if (a < sBigMonSizeTable[i].unk4)
            return i - 1;
    }
    return i;
}

// Mirrors the height/weight tiering used by Cmd_trysetcaughtmondexflags to
// decide whether a catch is announced as an exceptional size.
static u8 GetSizeCategoryExceptionalTier(u8 category)
{
    switch (category)
    {
    case 0:
    case 1:
    case 2:
    case 13:
    case 14:
    case 15:
        return 3; // Very Rare
    case 3:
    case 4:
    case 11:
    case 12:
        return 2; // Rare
    case 5:
    case 10:
        return 1; // Uncommon
    default:
        return 0; // Average
    }
}

u8 GetPersonalitySizeTier(u32 personality)
{
    u16 heightHash = personality & 0xFFFF;
    u16 weightHash = personality >> 16;
    u8 heightCategory = TranslateBigMonSizeTableIndex(heightHash);
    u8 weightCategory = TranslateBigMonSizeTableIndex(weightHash);
    u8 heightTier = GetSizeCategoryExceptionalTier(heightCategory);
    u8 weightTier = GetSizeCategoryExceptionalTier(weightCategory);

    return (heightTier > weightTier) ? heightTier : weightTier;
}

static u32 GetMonSize(enum Species species, u16 b)
{
    u64 unk2;
    u64 unk4;
    u64 unk0;
    u32 height;
    u32 var;

    height = GetSpeciesHeight(species);
    var = TranslateBigMonSizeTableIndex(b);
    unk0 = sBigMonSizeTable[var].unk0;
    unk2 = sBigMonSizeTable[var].unk2;
    unk4 = sBigMonSizeTable[var].unk4;
    unk0 += (b - unk4) / unk2;
    return height * unk0 / 10;
}

static void FormatMonSizeRecord(u8 *string, u32 size)
{
    if (UNITS == UNITS_IMPERIAL)
        size = size * 100 / 254;

    string = ConvertIntToDecimalStringN(string, size / 10, STR_CONV_MODE_LEFT_ALIGN, 8);
    string = StringAppend(string, gText_DecimalPoint);
    ConvertIntToDecimalStringN(string, size % 10, STR_CONV_MODE_LEFT_ALIGN, 1);
}

static u8 CompareMonSize(enum Species species, u16 *sizeRecord)
{
    if (gSpecialVar_Result >= PARTY_SIZE)
    {
        return 0;
    }
    else
    {
        struct Pokemon *pkmn = &gPlayerParty[gSpecialVar_Result];

        if (GetMonData(pkmn, MON_DATA_IS_EGG) == TRUE || GetMonData(pkmn, MON_DATA_SPECIES) != species)
        {
            return 1;
        }
        else
        {
            u32 oldSize;
            u32 newSize;
            u16 sizeParams;

            *(&sizeParams) = GetMonSizeHash(pkmn);
            newSize = GetMonSize(species, sizeParams);
            oldSize = GetMonSize(species, *sizeRecord);
            FormatMonSizeRecord(gStringVar3, oldSize);
            FormatMonSizeRecord(gStringVar2, newSize);
            if (newSize == oldSize)
            {
                return 4;
            }
            else if (newSize < oldSize)
            {
                return 2;
            }
            else
            {
                *sizeRecord = sizeParams;
                return 3;
            }
        }
    }
}

// Stores species name in gStringVar1, trainer's name in gStringVar2, and size in gStringVar3
static void GetMonSizeRecordInfo(enum Species species, u16 *sizeRecord)
{
    u32 size = GetMonSize(species, *sizeRecord);

    FormatMonSizeRecord(gStringVar3, size);
    StringCopy(gStringVar1, gSpeciesInfo[species].speciesName);
}

void InitHeracrossSizeRecord(void)
{
    VarSet(VAR_HERACROSS_SIZE_RECORD, DEFAULT_MAX_SIZE);
}

void GetHeracrossSizeRecordInfo(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_HERACROSS_SIZE_RECORD);

    GetMonSizeRecordInfo(SPECIES_HERACROSS, sizeRecord);
}

void CompareHeracrossSize(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_HERACROSS_SIZE_RECORD);

    gSpecialVar_Result = CompareMonSize(SPECIES_HERACROSS, sizeRecord);
}

void InitMagikarpSizeRecord(void)
{
    VarSet(VAR_MAGIKARP_SIZE_RECORD, DEFAULT_MAX_SIZE);
}

void GetMagikarpSizeRecordInfo(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_MAGIKARP_SIZE_RECORD);

    GetMonSizeRecordInfo(SPECIES_MAGIKARP, sizeRecord);
}

void CompareMagikarpSize(void)
{
    u16 *sizeRecord = GetVarPointer(VAR_MAGIKARP_SIZE_RECORD);

    gSpecialVar_Result = CompareMonSize(SPECIES_MAGIKARP, sizeRecord);
}

void GiveGiftRibbonToParty(u8 index, u8 ribbonId)
{
    s32 i;
    bool32 gotRibbon = FALSE;
    u8 data = 1;
    u8 array[8];
    memcpy(array, sGiftRibbonsMonDataIds, sizeof(sGiftRibbonsMonDataIds));

    if (index < 11 && ribbonId < 65)
    {
        gSaveBlock1Ptr->giftRibbons[index] = ribbonId;
        for (i = 0; i < PARTY_SIZE; i++)
        {
            struct Pokemon *mon = &gPlayerParty[i];

            if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(mon, MON_DATA_SANITY_IS_EGG))
            {
                SetMonData(mon, array[index], &data);
                gotRibbon = TRUE;
            }
        }
        if (gotRibbon)
            FlagSet(FLAG_SYS_RIBBON_GET);
    }
}

u32 GetIndividualHeight(enum Species species, u32 personality)
{
    u32 baseHeight = GetSpeciesHeight(species);
    u16 hash = personality & 0xFFFF;
    u32 var = TranslateBigMonSizeTableIndex(hash);
    u32 multiplier = sBigMonSizeTable[var].unk0;
    u32 height = (baseHeight * multiplier + 500) / 1000;
    return height > 0 ? height : 1;
}

u32 GetIndividualWeight(enum Species species, u32 personality)
{
    u32 baseWeight = GetSpeciesWeight(species);
    u16 hash = personality >> 16;
    u32 var = TranslateBigMonSizeTableIndex(hash);
    u32 multiplier = sBigMonSizeTable[var].unk0;
    u32 weight = (baseWeight * multiplier + 500) / 1000;
    return weight > 0 ? weight : 1;
}

u8 UpdatePokedexSizeRecordBySpeciesPersonality(u16 species, u32 personality)
{
    u16 heightHash, weightHash;
    u8 heightCategory, weightCategory;
    u8 currentTallest, currentShortest;
    u8 currentHeaviest, currentLightest;
    bool32 hasRecord;
    u8 result = SIZE_RECORD_NONE;

    if (species == SPECIES_NONE || species >= POKEDEX_SIZE_RECORDS_COUNT)
        return SIZE_RECORD_NONE;

    // A stored 0/0 record is ambiguous between "never recorded" and a genuine
    // category-0 specimen, so the caught flag disambiguates: once the species
    // has been caught, 0/0 is a real record. Callers must therefore update
    // records before setting the caught flag.
    hasRecord = GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT);

    heightHash = personality & 0xFFFF;
    weightHash = personality >> 16;

    heightCategory = TranslateBigMonSizeTableIndex(heightHash);
    weightCategory = TranslateBigMonSizeTableIndex(weightHash);

    // Byte 0: Shortest (low 4 bits), Tallest (high 4 bits)
    currentShortest = gSaveBlock1Ptr->pokedexSizes[species][0] & 0xF;
    currentTallest = (gSaveBlock1Ptr->pokedexSizes[species][0] >> 4) & 0xF;

    if (!hasRecord)
    {
        currentShortest = heightCategory;
        currentTallest = heightCategory;
    }
    else
    {
        if (heightCategory > currentTallest)
        {
            if (GetSizeCategoryExceptionalTier(heightCategory) >= 1)
                result |= SIZE_RECORD_TALLEST;
            currentTallest = heightCategory;
        }
        if (heightCategory < currentShortest)
        {
            if (GetSizeCategoryExceptionalTier(heightCategory) >= 1)
                result |= SIZE_RECORD_SHORTEST;
            currentShortest = heightCategory;
        }
    }
    gSaveBlock1Ptr->pokedexSizes[species][0] = currentShortest | (currentTallest << 4);

    // Byte 1: Lightest (low 4 bits), Heaviest (high 4 bits)
    currentLightest = gSaveBlock1Ptr->pokedexSizes[species][1] & 0xF;
    currentHeaviest = (gSaveBlock1Ptr->pokedexSizes[species][1] >> 4) & 0xF;

    if (!hasRecord)
    {
        currentLightest = weightCategory;
        currentHeaviest = weightCategory;
    }
    else
    {
        if (weightCategory > currentHeaviest)
        {
            if (GetSizeCategoryExceptionalTier(weightCategory) >= 1)
                result |= SIZE_RECORD_HEAVIEST;
            currentHeaviest = weightCategory;
        }
        if (weightCategory < currentLightest)
        {
            if (GetSizeCategoryExceptionalTier(weightCategory) >= 1)
                result |= SIZE_RECORD_LIGHTEST;
            currentLightest = weightCategory;
        }
    }
    gSaveBlock1Ptr->pokedexSizes[species][1] = currentLightest | (currentHeaviest << 4);

    return result;
}

u8 UpdatePokedexSizeRecord(struct Pokemon *mon)
{
    if (GetMonData(mon, MON_DATA_IS_EGG))
        return SIZE_RECORD_NONE;
    return UpdatePokedexSizeRecordBySpeciesPersonality(GetMonData(mon, MON_DATA_SPECIES), GetMonData(mon, MON_DATA_PERSONALITY));
}

u8 GetPokedexHeightRecord(u16 species, bool8 isTallest)
{
    if (species >= POKEDEX_SIZE_RECORDS_COUNT)
        return 8; // default to median

    if (isTallest)
        return (gSaveBlock1Ptr->pokedexSizes[species][0] >> 4) & 0xF;
    else
        return gSaveBlock1Ptr->pokedexSizes[species][0] & 0xF;
}

u8 GetPokedexWeightRecord(u16 species, bool8 isHeaviest)
{
    if (species >= POKEDEX_SIZE_RECORDS_COUNT)
        return 8; // default to median

    if (isHeaviest)
        return (gSaveBlock1Ptr->pokedexSizes[species][1] >> 4) & 0xF;
    else
        return gSaveBlock1Ptr->pokedexSizes[species][1] & 0xF;
}

u32 GetPokedexSizeMultiplier(u8 category)
{
    if (category >= 16)
        return 1000;
    return sBigMonSizeTable[category].unk0;
}

static void GetHashBoundsForSizeVal(u16 val, u16 currentHash, u16 *minHash, u16 *maxHash)
{
    if (val <= 15)
    {
        *minHash = sBigMonSizeTable[val].unk4;
        *maxHash = (val < 15) ? (sBigMonSizeTable[val + 1].unk4 - 1) : 65535;
    }
    else if (val <= 100)
    {
        if (val == 100)
        {
            *minHash = 64879; // Top 1% (99.0% - 100.0%)
            *maxHash = 65535;
        }
        else if (val == 0)
        {
            *minHash = 0;
            *maxHash = 655;
        }
        else
        {
            *minHash = (u32)(val - 1) * 65535 / 100;
            *maxHash = (u32)val * 65535 / 100;
        }
    }
    else
    {
        *minHash = currentHash;
        *maxHash = currentHash;
    }
}


void SetMonSizeTierOrPercentile(struct Pokemon *mon, u16 heightVal, u16 weightVal)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES);
    u32 oldPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 oldHeightHash = oldPersonality & 0xFFFF;
    u16 oldWeightHash = (oldPersonality >> 16) & 0xFFFF;
    u16 minH, maxH, minW, maxW;
    u32 bestPID, i;
    u8 oldNature, oldGender, oldAbility;
    bool8 oldShiny;
    u32 oldMod24;

    if (species == SPECIES_NONE)
        return;

    if (heightVal > 100 && weightVal > 100)
        return; // nothing to change

    GetHashBoundsForSizeVal(heightVal, oldHeightHash, &minH, &maxH);
    GetHashBoundsForSizeVal(weightVal, oldWeightHash, &minW, &maxW);

    oldNature = GetNature(mon);
    oldGender = GetMonGender(mon);
    oldAbility = GetMonData(mon, MON_DATA_ABILITY_NUM);
    oldShiny = IsMonShiny(mon);
    oldMod24 = oldPersonality % 24;

    bestPID = 0;

    // Pass 1: Try to preserve mod24, nature, gender, ability, and shininess
    for (i = 0; i < 1000; i++)
    {
        u16 h = minH + (Random() % (maxH - minH + 1));
        u16 w = minW + (Random() % (maxW - minW + 1));
        u32 candidate = ((u32)w << 16) | h;

        if ((candidate % 24) == oldMod24
         && GetNatureFromPersonality(candidate) == oldNature
         && GetGenderFromSpeciesAndPersonality(species, candidate) == oldGender
         && (u8)(candidate & 1) == oldAbility)
        {
            u32 otId = GetMonData(mon, MON_DATA_OT_ID);
            u32 shinyVal = GET_SHINY_VALUE(otId, candidate);
            bool8 candidateShiny = (shinyVal < SHINY_ODDS);

            if (candidateShiny == oldShiny)
            {
                bestPID = candidate;
                break;
            }
        }
    }

    // Pass 2: Fallback to preserving mod24 and size bounds
    if (bestPID == 0)
    {
        for (i = 0; i < 1000; i++)
        {
            u16 h = minH + (Random() % (maxH - minH + 1));
            u16 w = minW + (Random() % (maxW - minW + 1));
            u32 candidate = ((u32)w << 16) | h;

            if ((candidate % 24) == oldMod24)
            {
                bestPID = candidate;
                break;
            }
        }
    }

    // Pass 3: Ultimate fallback guaranteeing exact mod24 alignment
    if (bestPID == 0)
    {
        u16 h = maxH;
        u16 w = maxW;
        u32 candidate = ((u32)w << 16) | h;
        u32 rem = candidate % 24;
        s32 diff = (s32)oldMod24 - (s32)rem;
        if (diff < 0) diff += 24;
        candidate += diff;
        bestPID = candidate;
    }

    SetMonPersonalitySafe(mon, bestPID);
}




