#include "global.h"
#include "test/battle.h"

// The individual size system reads the height hash from the low half of the
// personality and the weight hash from the high half. All personalities used
// here are multiples of 25 so the nature stays Hardy (neutral) across runs.
#define PERSONALITY_LIGHTEST 0x00000000u              // weight hash 0     -> 0.29x base weight
#define PERSONALITY_MEDIAN   ((u32)40000 << 16)       // weight hash 40000 -> 1.00x base weight
#define PERSONALITY_HEAVIEST (((u32)65535 << 16) | 15) // weight hash 65535 -> 1.70x base weight

ASSUMPTIONS
{
    ASSUME(GetSpeciesWeight(SPECIES_WOBBUFFET) == 285);
    ASSUME(GetMoveCategory(MOVE_TACKLE) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_SWIFT) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Individual weight scales Speed: lighter Pokémon outspeed heavier ones at equal stats")
{
    bool32 playerIsLight;
    PARAMETRIZE { playerIsLight = TRUE; }
    PARAMETRIZE { playerIsLight = FALSE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(100); Personality(playerIsLight ? PERSONALITY_LIGHTEST : PERSONALITY_HEAVIEST); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); Personality(playerIsLight ? PERSONALITY_HEAVIEST : PERSONALITY_LIGHTEST); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (playerIsLight) {
            MESSAGE("Wobbuffet used Celebrate!");
            MESSAGE("The opposing Wobbuffet used Celebrate!");
        } else {
            MESSAGE("The opposing Wobbuffet used Celebrate!");
            MESSAGE("Wobbuffet used Celebrate!");
        }
    }
}

SINGLE_BATTLE_TEST("Individual weight scales physical damage from 0.86x to 1.14x", s16 damage)
{
    u32 personality;
    PARAMETRIZE { personality = PERSONALITY_LIGHTEST; }
    PARAMETRIZE { personality = PERSONALITY_MEDIAN; }
    PARAMETRIZE { personality = PERSONALITY_HEAVIEST; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Personality(personality); Attack(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { Defense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        // damage = damage * (4 * baseWeight + actualWeight) / (5 * baseWeight)
        // Lightest: (4 * 285 + 83) / (5 * 285)  = 1223 / 1425 = 0.8582x
        // Heaviest: (4 * 285 + 485) / (5 * 285) = 1625 / 1425 = 1.1404x
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(0.8582), results[0].damage);
        EXPECT_MUL_EQ(results[1].damage, Q_4_12(1.1404), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Individual weight does not scale special damage", s16 damage)
{
    u32 personality;
    PARAMETRIZE { personality = PERSONALITY_LIGHTEST; }
    PARAMETRIZE { personality = PERSONALITY_HEAVIEST; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Personality(personality); SpAttack(100); Speed(100); }
        OPPONENT(SPECIES_WOBBUFFET) { SpDefense(100); Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_SWIFT); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

// Catch-time dex registration (trysetcaughtmondexflags) cannot be exercised
// here: battle tests run as recorded battles, and BattleScript_SuccessBallThrow
// skips dex registration for BATTLE_TYPE_RECORDED. The size-record update it
// performs is covered by the HandleSetPokedexFlag test in test/pokemon_size.c.
