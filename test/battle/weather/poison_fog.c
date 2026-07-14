#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Poison Fog poisons eligible Pokémon at the end of the turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIASMA); }
    } SCENE {
        MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
        STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Poison Fog does not poison already-poisoned Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIASMA); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
    }
}

SINGLE_BATTLE_TEST("Poison, Steel, Rock, Ground, and Ghost type Pokémon are immune to Poison Fog")
{
    u32 mon;
    PARAMETRIZE { mon = SPECIES_TOXICROAK; } // Poison
    PARAMETRIZE { mon = SPECIES_REGISTEEL; }  // Steel
    PARAMETRIZE { mon = SPECIES_NOSEPASS; }   // Rock
    PARAMETRIZE { mon = SPECIES_SANDSLASH; }  // Ground
    PARAMETRIZE { mon = SPECIES_DUSCLOPS; }   // Ghost

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(mon);
    } WHEN {
        TURN { MOVE(player, MOVE_MIASMA); }
    } SCENE {
        NONE_OF {
            MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
            MESSAGE("The opposing Toxicroak was poisoned by the poison fog!");
            MESSAGE("The opposing Registeel was poisoned by the poison fog!");
            MESSAGE("The opposing Nosepass was poisoned by the poison fog!");
            MESSAGE("The opposing Sandslash was poisoned by the poison fog!");
            MESSAGE("The opposing Dusclops was poisoned by the poison fog!");
        }
    }
}

SINGLE_BATTLE_TEST("Substitute blocks Poison Fog poisoning")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_MIASMA); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
    }
}

SINGLE_BATTLE_TEST("Overcoat, Safety Goggles, and Immunity ability grant immunity to Poison Fog")
{
    u32 ability, item;
    PARAMETRIZE { ability = ABILITY_OVERCOAT; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_NONE; item = ITEM_SAFETY_GOGGLES; }
    PARAMETRIZE { ability = ABILITY_IMMUNITY; item = ITEM_NONE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); Item(item); }
    } WHEN {
        TURN { MOVE(player, MOVE_MIASMA); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
    }
}

SINGLE_BATTLE_TEST("Safeguard and Misty Terrain block Poison Fog poisoning")
{
    u32 move;
    PARAMETRIZE { move = MOVE_SAFEGUARD; }
    PARAMETRIZE { move = MOVE_MISTY_TERRAIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); MOVE(player, MOVE_MIASMA); }
    } SCENE {
        NOT MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
    }
}

SINGLE_BATTLE_TEST("Poison Fog ends after 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MIASMA); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("The poison fog dissipated.");
    }
}

SINGLE_BATTLE_TEST("Cloud Nine and Air Lock suppress Poison Fog poisoning")
{
    u32 species = SPECIES_NONE;
    u32 ability = ABILITY_NONE;

    PARAMETRIZE { species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIASMA); }
    } SCENE {
        NONE_OF {
            MESSAGE("Golduck was poisoned by the poison fog!");
            MESSAGE("Rayquaza was poisoned by the poison fog!");
            MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI sets Poison Fog against a target that can be poisoned by it")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIASMA) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_MIASMA) == BATTLE_WEATHER_POISON_FOG);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GRIMER) { Moves(MOVE_MIASMA, MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_MIASMA); }
    }
}

AI_SINGLE_BATTLE_TEST("AI does not favor Poison Fog when the target is already immune to it")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MIASMA) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_MIASMA) == BATTLE_WEATHER_POISON_FOG);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_SANDSLASH); // Ground-type: immune to Poison Fog
        OPPONENT(SPECIES_GRIMER) { Moves(MOVE_MIASMA, MOVE_POUND); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_POUND); }
    }
}
