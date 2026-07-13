#include "global.h"
#include "event_data.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_size_record.h"
#include "test/test.h"

// Script specials from src/prof_pc.c (registered in the specials table, no header).
extern u16 GetSpeciesSeenCount(void);
extern u16 GetSpeciesCaughtCount(void);
extern u16 GetMonHeight(void);
extern u16 GetMonWeight(void);
extern u16 GetMonHeightPercentile(void);
extern u16 GetMonWeightPercentile(void);
extern void RemoveSelectedPartyMon(void);

// The height hash is the low half of the personality, the weight hash the
// high half. Category 8 (multiplier 1000 = 1.0x) covers hashes 32710..47709.
#define MEDIAN_HASH 32710
#define SIZE_PERSONALITY(heightHash, weightHash) (((u32)(weightHash) << 16) | (heightHash))

TEST("Size categories: TranslateBigMonSizeTableIndex maps hash ranges to categories 0-15")
{
    static const struct { u16 hash; u8 category; } sCases[] =
    {
        {     0,  0 }, {     9,  0 },
        {    10,  1 }, {   109,  1 },
        {   110,  2 }, {   309,  2 },
        {   310,  3 }, {   709,  3 },
        {   710,  4 }, {  2709,  4 },
        {  2710,  5 }, {  7709,  5 },
        {  7710,  6 }, { 17709,  6 },
        { 17710,  7 }, { 32709,  7 },
        { 32710,  8 }, { 47709,  8 },
        { 47710,  9 }, { 57709,  9 },
        { 57710, 10 }, { 62709, 10 },
        { 62710, 11 }, { 64709, 11 },
        { 64710, 12 }, { 65209, 12 },
        { 65210, 13 }, { 65409, 13 },
        // The lookup loop stops before the table's last entry, so hashes in
        // 65410..65509 map to category 15 and category 14 is unreachable.
        { 65410, 15 }, { 65509, 15 },
        { 65510, 15 }, { 65535, 15 },
    };
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sCases); i++)
        EXPECT_EQ(TranslateBigMonSizeTableIndex(sCases[i].hash), sCases[i].category);
}

TEST("Size multipliers: GetPokedexSizeMultiplier ranges from 0.29x to 1.7x")
{
    EXPECT_EQ(GetPokedexSizeMultiplier(0), 290);
    EXPECT_EQ(GetPokedexSizeMultiplier(8), 1000);
    EXPECT_EQ(GetPokedexSizeMultiplier(15), 1700);
    // Out-of-range categories fall back to the 1.0x multiplier.
    EXPECT_EQ(GetPokedexSizeMultiplier(16), 1000);
}

TEST("Individual size: median hashes reproduce the species' base height and weight")
{
    u32 personality = SIZE_PERSONALITY(MEDIAN_HASH, MEDIAN_HASH);
    ASSUME(GetSpeciesHeight(SPECIES_WOBBUFFET) == 13);
    ASSUME(GetSpeciesWeight(SPECIES_WOBBUFFET) == 285);
    EXPECT_EQ(GetIndividualHeight(SPECIES_WOBBUFFET, personality), 13);
    EXPECT_EQ(GetIndividualWeight(SPECIES_WOBBUFFET, personality), 285);
}

TEST("Individual size: extreme hashes scale dimensions from 0.29x to 1.7x of the base")
{
    ASSUME(GetSpeciesHeight(SPECIES_WOBBUFFET) == 13);
    ASSUME(GetSpeciesWeight(SPECIES_WOBBUFFET) == 285);
    // Minimum: (base * 290 + 500) / 1000
    EXPECT_EQ(GetIndividualHeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0, 0)), 4);
    EXPECT_EQ(GetIndividualWeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0, 0)), 83);
    // Maximum: (base * 1700 + 500) / 1000
    EXPECT_EQ(GetIndividualHeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0xFFFF, 0xFFFF)), 22);
    EXPECT_EQ(GetIndividualWeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0xFFFF, 0xFFFF)), 485);
}

TEST("Individual size: height uses the low personality half, weight the high half")
{
    ASSUME(GetSpeciesHeight(SPECIES_WOBBUFFET) == 13);
    ASSUME(GetSpeciesWeight(SPECIES_WOBBUFFET) == 285);
    EXPECT_EQ(GetIndividualHeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0xFFFF, 0)), 22);
    EXPECT_EQ(GetIndividualWeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0xFFFF, 0)), 83);
    EXPECT_EQ(GetIndividualHeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0, 0xFFFF)), 4);
    EXPECT_EQ(GetIndividualWeight(SPECIES_WOBBUFFET, SIZE_PERSONALITY(0, 0xFFFF)), 485);
}

TEST("Individual size: dimensions are clamped to a minimum of 1")
{
    // Gastly's base weight of 1 (0.1 kg) would round down to 0 at small sizes.
    ASSUME(GetSpeciesWeight(SPECIES_GASTLY) == 1);
    EXPECT_EQ(GetIndividualWeight(SPECIES_GASTLY, SIZE_PERSONALITY(0, 0)), 1);
}

TEST("Size records: first record initializes both min and max, later records extend them")
{
    u16 species = SPECIES_WOBBUFFET;
    // First record: height category 8, weight category 8.
    UpdatePokedexSizeRecordBySpeciesPersonality(species, SIZE_PERSONALITY(MEDIAN_HASH, MEDIAN_HASH));
    EXPECT_EQ(GetPokedexHeightRecord(species, FALSE), 8);
    EXPECT_EQ(GetPokedexHeightRecord(species, TRUE), 8);
    EXPECT_EQ(GetPokedexWeightRecord(species, FALSE), 8);
    EXPECT_EQ(GetPokedexWeightRecord(species, TRUE), 8);

    // Taller (category 15) and lighter (category 1) specimen extends the records.
    UpdatePokedexSizeRecordBySpeciesPersonality(species, SIZE_PERSONALITY(0xFFFF, 10));
    EXPECT_EQ(GetPokedexHeightRecord(species, FALSE), 8);
    EXPECT_EQ(GetPokedexHeightRecord(species, TRUE), 15);
    EXPECT_EQ(GetPokedexWeightRecord(species, FALSE), 1);
    EXPECT_EQ(GetPokedexWeightRecord(species, TRUE), 8);

    // A specimen within the recorded ranges changes nothing.
    UpdatePokedexSizeRecordBySpeciesPersonality(species, SIZE_PERSONALITY(MEDIAN_HASH, MEDIAN_HASH));
    EXPECT_EQ(GetPokedexHeightRecord(species, FALSE), 8);
    EXPECT_EQ(GetPokedexHeightRecord(species, TRUE), 15);
    EXPECT_EQ(GetPokedexWeightRecord(species, FALSE), 1);
    EXPECT_EQ(GetPokedexWeightRecord(species, TRUE), 8);
}

TEST("Size records: species beyond the record table are ignored and read as median")
{
    // POKEDEX_SIZE_RECORDS_COUNT is the table bound; out-of-range reads default to 8.
    u16 species = POKEDEX_SIZE_RECORDS_COUNT;
    UpdatePokedexSizeRecordBySpeciesPersonality(species, SIZE_PERSONALITY(0xFFFF, 0xFFFF));
    EXPECT_EQ(GetPokedexHeightRecord(species, TRUE), 8);
    EXPECT_EQ(GetPokedexWeightRecord(species, TRUE), 8);
}

// A category-0/0 first record is indistinguishable from the empty save state,
// so a later capture overwrites the recorded minimum instead of keeping it.
TEST("Size records: category 0 records survive later updates")
{
    u16 species = SPECIES_WOBBUFFET;
    KNOWN_FAILING;
    UpdatePokedexSizeRecordBySpeciesPersonality(species, SIZE_PERSONALITY(0, 0));
    UpdatePokedexSizeRecordBySpeciesPersonality(species, SIZE_PERSONALITY(0xFFFF, 0xFFFF));
    EXPECT_EQ(GetPokedexHeightRecord(species, FALSE), 0);
    EXPECT_EQ(GetPokedexHeightRecord(species, TRUE), 15);
    EXPECT_EQ(GetPokedexWeightRecord(species, FALSE), 0);
    EXPECT_EQ(GetPokedexWeightRecord(species, TRUE), 15);
}

TEST("Dex counters: seen/caught counts increment and saturate at 255")
{
    u16 natDex = SpeciesToNationalPokedexNum(SPECIES_WOBBUFFET);
    ASSUME(natDex < DEX_COUNTS_MAX_SPECIES);

    EXPECT_EQ(GET_DEX_SEEN_COUNT(SPECIES_WOBBUFFET), 0);
    EXPECT_EQ(GET_DEX_CAUGHT_COUNT(SPECIES_WOBBUFFET), 0);

    INCREMENT_DEX_SEEN_COUNT_BY_NATDEX(natDex);
    INCREMENT_DEX_SEEN_COUNT_BY_NATDEX(natDex);
    INCREMENT_DEX_CAUGHT_COUNT_BY_NATDEX(natDex);
    EXPECT_EQ(GET_DEX_SEEN_COUNT(SPECIES_WOBBUFFET), 2);
    EXPECT_EQ(GET_DEX_CAUGHT_COUNT(SPECIES_WOBBUFFET), 1);

    gSaveBlock1Ptr->pokedexCaught[natDex] = 255;
    INCREMENT_DEX_CAUGHT_COUNT_BY_NATDEX(natDex);
    EXPECT_EQ(GET_DEX_CAUGHT_COUNT(SPECIES_WOBBUFFET), 255);
}

TEST("Dex counters: species above the counter range fall back to binary flags")
{
    u16 natDex = SpeciesToNationalPokedexNum(SPECIES_KRICKETOT);
    ASSUME(natDex >= DEX_COUNTS_MAX_SPECIES);

    EXPECT_EQ(GET_DEX_CAUGHT_COUNT(SPECIES_KRICKETOT), 0);
    GetSetPokedexFlag(natDex, FLAG_SET_CAUGHT);
    EXPECT_EQ(GET_DEX_CAUGHT_COUNT(SPECIES_KRICKETOT), 1);
    // The counter macros must not write out of the array bounds; the count
    // stays pinned to the flag.
    INCREMENT_DEX_CAUGHT_COUNT_BY_NATDEX(natDex);
    EXPECT_EQ(GET_DEX_CAUGHT_COUNT(SPECIES_KRICKETOT), 1);
}

TEST("Dex counters: GetSpeciesSeenCount/GetSpeciesCaughtCount fall back to 1 when only the flag is set")
{
    u16 natDex = SpeciesToNationalPokedexNum(SPECIES_WOBBUFFET);
    ASSUME(natDex < DEX_COUNTS_MAX_SPECIES);

    // Flag set (e.g. by a pre-counter save) but counter still zero.
    GetSetPokedexFlag(natDex, FLAG_SET_SEEN);
    GetSetPokedexFlag(natDex, FLAG_SET_CAUGHT);

    gSpecialVar_0x8004 = SPECIES_WOBBUFFET;
    EXPECT_EQ(GetSpeciesSeenCount(), 1);
    EXPECT_EQ(gSpecialVar_Result, 1);
    EXPECT_EQ(GetSpeciesCaughtCount(), 1);

    // A real count takes precedence over the fallback.
    INCREMENT_DEX_CAUGHT_COUNT_BY_NATDEX(natDex);
    INCREMENT_DEX_CAUGHT_COUNT_BY_NATDEX(natDex);
    EXPECT_EQ(GetSpeciesCaughtCount(), 2);
}

TEST("Size specials: GetMonHeight/GetMonWeight report the party mon's individual size")
{
    u32 personality = SIZE_PERSONALITY(0xFFFF, 0); // Tallest, lightest
    ASSUME(GetSpeciesHeight(SPECIES_WOBBUFFET) == 13);
    ASSUME(GetSpeciesWeight(SPECIES_WOBBUFFET) == 285);
    ZeroPlayerPartyMons();
    CreateMon(&gPlayerParty[0], SPECIES_WOBBUFFET, 50, personality, OTID_STRUCT_PLAYER_ID);

    gSpecialVar_0x8004 = 0;
    EXPECT_EQ(GetMonHeight(), 22);
    EXPECT_EQ(GetMonWeight(), 83);
    // Percentiles are scaled to 0..1000 (one decimal of a percent).
    EXPECT_EQ(GetMonHeightPercentile(), 1000);
    EXPECT_EQ(GetMonWeightPercentile(), 0);

    // Empty party slots report 0.
    gSpecialVar_0x8004 = 1;
    EXPECT_EQ(GetMonHeight(), 0);
    EXPECT_EQ(GetMonWeight(), 0);

    // Out-of-range slots report 0.
    gSpecialVar_0x8004 = PARTY_SIZE;
    EXPECT_EQ(GetMonHeight(), 0);
}

TEST("RemoveSelectedPartyMon refuses to remove the last usable party member")
{
    ZeroPlayerPartyMons();
    CreateMon(&gPlayerParty[0], SPECIES_WOBBUFFET, 50, 0, OTID_STRUCT_PLAYER_ID);
    CalculatePlayerPartyCount();

    gSpecialVar_0x8004 = 0;
    RemoveSelectedPartyMon();
    EXPECT_EQ(gSpecialVar_Result, FALSE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_WOBBUFFET);
}

TEST("RemoveSelectedPartyMon removes a mon and compacts the party")
{
    ZeroPlayerPartyMons();
    CreateMon(&gPlayerParty[0], SPECIES_WOBBUFFET, 50, 0, OTID_STRUCT_PLAYER_ID);
    CreateMon(&gPlayerParty[1], SPECIES_GASTLY, 50, 0, OTID_STRUCT_PLAYER_ID);
    CalculatePlayerPartyCount();

    gSpecialVar_0x8004 = 0;
    RemoveSelectedPartyMon();
    EXPECT_EQ(gSpecialVar_Result, TRUE);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_GASTLY);
    EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_SPECIES), SPECIES_NONE);
    EXPECT_EQ(CalculatePlayerPartyCount(), 1);
}
