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
        NOT MESSAGE("The opposing Wobbuffet was poisoned by the poison fog!");
        NOT MESSAGE("The opposing Toxicroak was poisoned by the poison fog!");
        NOT MESSAGE("The opposing Registeel was poisoned by the poison fog!");
        NOT MESSAGE("The opposing Nosepass was poisoned by the poison fog!");
        NOT MESSAGE("The opposing Sandslash was poisoned by the poison fog!");
        NOT MESSAGE("The opposing Dusclops was poisoned by the poison fog!");
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
