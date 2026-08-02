#include "global.h"
#include "event_data.h"
#include "pokedex.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gSpeciesInfo[SPECIES_CLEFFA].catchRate == 150);
}

WILD_BATTLE_TEST("Capture: Incapacitated catch bonus apply correcly with all gen configs")
{
    u32 expectedOdds;
    u32 recordedOdds;
    u32 status;
    u32 gen;

    PARAMETRIZE(expectedOdds = 100, status = STATUS1_SLEEP, gen = GEN_4);
    PARAMETRIZE(expectedOdds = 100, status = STATUS1_FREEZE, gen = GEN_4);
    PARAMETRIZE(expectedOdds = 125, status = STATUS1_SLEEP, gen = GEN_5);
    PARAMETRIZE(expectedOdds = 125, status = STATUS1_FREEZE, gen = GEN_5);

    GIVEN {
        WITH_CONFIG(B_INCAPACITATED_CATCH_BONUS, gen);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA) {Status1(status);}
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: Low level catch bonus apply correcly with all gen configs")
{
    u32 expectedOdds;
    u32 recordedOdds;
    u32 level;
    u32 gen;

    PARAMETRIZE(expectedOdds = 50, level = 10, gen = GEN_7);
    PARAMETRIZE(expectedOdds = 50, level = 15, gen = GEN_7);
    PARAMETRIZE(expectedOdds = 50, level = 30, gen = GEN_7);
    PARAMETRIZE(expectedOdds = 100, level = 10, gen = GEN_8);
    PARAMETRIZE(expectedOdds = 75, level = 15, gen = GEN_8);
    PARAMETRIZE(expectedOdds = 50, level = 30, gen = GEN_8);
    PARAMETRIZE(expectedOdds = 80, level = 10, gen = GEN_9);
    PARAMETRIZE(expectedOdds = 50, level = 15, gen = GEN_9);
    PARAMETRIZE(expectedOdds = 50, level = 30, gen = GEN_9);

    GIVEN {
        WITH_CONFIG(B_LOW_LEVEL_CATCH_BONUS, gen);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA) {Level(level);}
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

// Solid-Oak drives the missing-badge malus from catchMalusBadgeCount, a
// standalone placeholder counter, rather than real badge flags.
WILD_BATTLE_TEST("Capture: Missing badge malus apply correcly in gen 8")
{
    u32 expectedOdds = 0;
    u32 recordedOdds;
    u32 playerLevel = 0;
    u32 numBadges = 0;

    for (u32 j = 0; j < 8; j++)
    {
        PARAMETRIZE(expectedOdds = 50, playerLevel = 100, numBadges = j);
        PARAMETRIZE(expectedOdds = 5, playerLevel = 99, numBadges = j);
    }
    PARAMETRIZE(expectedOdds = 50, playerLevel = 100, numBadges = 8);
    PARAMETRIZE(expectedOdds = 50, playerLevel = 99, numBadges = 8);
    PARAMETRIZE(expectedOdds = 50, playerLevel = 21, numBadges = 8);

    GIVEN {
        gSaveBlock1Ptr->catchMalusBadgeCount = numBadges;
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_8);
        PLAYER(SPECIES_WOBBUFFET) {Level(playerLevel);}
        OPPONENT(SPECIES_CLEFFA);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

// Solid-Oak drives the missing-badge malus from catchMalusBadgeCount, a
// standalone placeholder counter, rather than real badge flags.
WILD_BATTLE_TEST("Capture: Missing badge malus apply correcly in gen 9")
{
    u32 expectedOdds;
    u32 recordedOdds;
    u32 level = 0;
    u32 numBadges = 0;

    PARAMETRIZE(expectedOdds = 250, level = 100, numBadges = 8);
    PARAMETRIZE(expectedOdds = 200, level = 100, numBadges = 7);
    PARAMETRIZE(expectedOdds = 160, level = 100, numBadges = 6);
    PARAMETRIZE(expectedOdds = 128, level = 100, numBadges = 5);
    PARAMETRIZE(expectedOdds = 250, level = 40, numBadges = 4);
    PARAMETRIZE(expectedOdds = 250, level = 40, numBadges = 3);
    PARAMETRIZE(expectedOdds = 200, level = 40, numBadges = 2);
    PARAMETRIZE(expectedOdds = 160, level = 40, numBadges = 1);
    PARAMETRIZE(expectedOdds = 128, level = 40, numBadges = 0);

    GIVEN {
        gSaveBlock1Ptr->catchMalusBadgeCount = numBadges;
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA)  {Level(level);};
    } WHEN {
        TURN { USE_ITEM(player, ITEM_QUICK_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: when CRITICAL_CAPTURE_IF_OWNED is enabled, capture of owned pokemon always appear critical")
{
    enum Item item;
    bool32 alreadyOwned;
    u32 catchingChance;

    PARAMETRIZE(item = ITEM_POKE_BALL, alreadyOwned = FALSE);
    PARAMETRIZE(item = ITEM_QUICK_BALL, alreadyOwned = FALSE);
    PARAMETRIZE(item = ITEM_MASTER_BALL, alreadyOwned = FALSE);
    PARAMETRIZE(item = ITEM_POKE_BALL, alreadyOwned = TRUE);
    PARAMETRIZE(item = ITEM_QUICK_BALL, alreadyOwned = TRUE);
    PARAMETRIZE(item = ITEM_MASTER_BALL, alreadyOwned = TRUE);

    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_CATERPIE].catchRate > 155);
        if (alreadyOwned)
            GetSetPokedexFlag(NATIONAL_DEX_CATERPIE, FLAG_SET_CAUGHT);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        WITH_CONFIG(B_CRITICAL_CAPTURE_IF_OWNED, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        CATCHING_CHANCE(&catchingChance);
        if (alreadyOwned)
        {
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
        else
        {
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
    } THEN {
        if (item == ITEM_POKE_BALL)
            EXPECT_LT(catchingChance, 255);
        else // Solid-Oak caps computed odds at 255, so boosted odds land on the cap.
            EXPECT_GE(catchingChance, 255);
    }
}

WILD_BATTLE_TEST("Capture: when CRITICAL_CAPTURE_IF_OWNED is enabled, failed capture of owned pokemon does not appear critical")
{
    bool32 success;
    PARAMETRIZE(success = TRUE);
    PARAMETRIZE(success = FALSE);

    GIVEN {
        GetSetPokedexFlag(NATIONAL_DEX_CATERPIE, FLAG_SET_CAUGHT);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        WITH_CONFIG(B_CRITICAL_CAPTURE_IF_OWNED, GEN_9);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, success ? 0 : MAX_u16)); }
    } SCENE {
        if (success)
        {
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
        else
        {
            NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
    }
}

WILD_BATTLE_TEST("Capture: ball data is properly set in captured pokemon")
{
    u32 item = ITEM_NONE;
    for (enum PokeBall ballId = BALL_STRANGE; ballId < POKEBALL_COUNT; ballId++)
    {
        PARAMETRIZE(item = gPokeBalls[ballId].itemId);
    }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        // Level 10 keeps the wild mon under every proto ball's level cap.
        OPPONENT(SPECIES_WOBBUFFET) { Level(10); }
    } WHEN {
        TURN { USE_ITEM(player, item, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        ONE_OF
        {
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
            ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
        }
    } THEN {
        EXPECT_EQ(GetMonData(&gPlayerParty[1], MON_DATA_POKEBALL), GetItemSecondaryId(item));
    }
}

WILD_BATTLE_TEST("Capture: Research Ball has a 1.5x catch multiplier")
{
    u32 ball = ITEM_NONE;
    u32 expectedOdds = 0;
    u32 recordedOdds;

    PARAMETRIZE { ball = ITEM_POKE_BALL;     expectedOdds = 50; }
    PARAMETRIZE { ball = ITEM_RESEARCH_BALL; expectedOdds = 75; }

    GIVEN {
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        WITH_CONFIG(B_LOW_LEVEL_CATCH_BONUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA);
    } WHEN {
        TURN { USE_ITEM(player, ball); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: catch odds scale with the National Dex caught count (research tiers)")
{
    u32 caughtCount = 0;
    u32 expectedOdds = 0;
    u32 recordedOdds;
    u32 dex;

    // Runs are ordered by ascending caught count because dex flags set in
    // one run persist into the next.
    PARAMETRIZE { caughtCount = 0;   expectedOdds = 50; } // no bonus
    PARAMETRIZE { caughtCount = 20;  expectedOdds = 55; } // 1.1x
    PARAMETRIZE { caughtCount = 50;  expectedOdds = 60; } // 1.2x
    PARAMETRIZE { caughtCount = 100; expectedOdds = 75; } // 1.5x

    GIVEN {
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        WITH_CONFIG(B_LOW_LEVEL_CATCH_BONUS, GEN_7);
        for (dex = 0; dex < caughtCount; dex++)
            GetSetPokedexFlag(dex + 1, FLAG_SET_CAUGHT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(expectedOdds, recordedOdds);
    }
}

WILD_BATTLE_TEST("Capture: proto Poké Balls fail outright above their level caps")
{
    u32 ball = ITEM_NONE;
    u32 level = 0;

    PARAMETRIZE { ball = ITEM_RED_PROTOBALL;  level = 11; }
    PARAMETRIZE { ball = ITEM_BLU_PROTOBALL;   level = 21; }
    PARAMETRIZE { ball = ITEM_GRN_PROTOBALL; level = 31; }
    PARAMETRIZE { ball = ITEM_BLK_PROTOBALL;  level = 41; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA) { Level(level); }
    } WHEN {
        TURN { USE_ITEM(player, ball); }
    } SCENE {
        MESSAGE("This Ball doesn't work on a Pokémon that strong!");
    }
}

WILD_BATTLE_TEST("Capture: proto Poké Balls work normally at or below their level caps")
{
    u32 ball = ITEM_NONE;
    u32 level = 0;
    u32 recordedOdds;

    PARAMETRIZE { ball = ITEM_RED_PROTOBALL;  level = 10; }
    PARAMETRIZE { ball = ITEM_BLU_PROTOBALL;   level = 20; }
    PARAMETRIZE { ball = ITEM_GRN_PROTOBALL; level = 30; }
    PARAMETRIZE { ball = ITEM_BLK_PROTOBALL;  level = 40; }

    GIVEN {
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        WITH_CONFIG(B_LOW_LEVEL_CATCH_BONUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA) { Level(level); }
    } WHEN {
        TURN { USE_ITEM(player, ball); }
    } SCENE {
        NOT MESSAGE("This Ball doesn't work on a Pokémon that strong!");
        CATCHING_CHANCE(&recordedOdds);
    } THEN {
        EXPECT_EQ(recordedOdds, 50);
    }
}

WILD_BATTLE_TEST("Capture: Critical Capture stays disabled even at a near-complete Kanto Dex, so it cannot stack with the research-tier catch bonus")
{
    u32 dex;

    GIVEN {
        ASSUME(B_CRITICAL_CAPTURE == FALSE);
        // B_CRITICAL_CAPTURE_IF_OWNED is a separate, per-species "already
        // caught" critical capture trigger unrelated to the caught-count
        // scaling this test targets; disable it so marking species caught
        // below doesn't trip it instead.
        WITH_CONFIG(B_CRITICAL_CAPTURE_IF_OWNED, GEN_8);
        // Well past every Critical Capture caught-count threshold and the
        // research tier's own 100-caught cap. Cleffa itself is left
        // unmarked so FLAG_GET_CAUGHT stays FALSE for the wild mon.
        for (dex = 1; dex <= KANTO_DEX_COUNT; dex++)
        {
            if (dex != SpeciesToNationalPokedexNum(SPECIES_CLEFFA))
                GetSetPokedexFlag(dex, FLAG_SET_CAUGHT);
        }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLEFFA);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_CRITICAL_CAPTURE_THROW);
    }
}
