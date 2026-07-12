#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Electric Floor deals 1/16 damage per turn to non-Ground, non-Electric types")
{
    s16 dmg;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARGED_GROUND); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &dmg);
        MESSAGE("The opposing Wobbuffet is hurt by the electric floor!");
    } THEN {
        EXPECT_EQ(dmg, opponent->maxHP / 16);
    }
}

SINGLE_BATTLE_TEST("Electric Floor heals Electric-type Pokémon by 1/16 HP per turn")
{
    s16 dmg;

    GIVEN {
        PLAYER(SPECIES_PIKACHU) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARGED_GROUND); }
    } SCENE {
        HP_BAR(player, captureDamage: &dmg);
        MESSAGE("Pikachu is healed by the electric floor!");
    } THEN {
        EXPECT_EQ(dmg, -(player->maxHP / 16));
    }
}

SINGLE_BATTLE_TEST("Electric Floor damage does not hurt Ground-type Pokémon")
{
    GIVEN {
        PLAYER(SPECIES_SANDSLASH);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARGED_GROUND); }
    } SCENE {
        NOT MESSAGE("Sandslash is hurt by the electric floor!");
    }
}

SINGLE_BATTLE_TEST("Electric/Ground dual type Stunfisk heals under Electric Floor")
{
    s16 dmg;

    GIVEN {
        PLAYER(SPECIES_STUNFISK) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARGED_GROUND); }
    } SCENE {
        HP_BAR(player, captureDamage: &dmg);
        MESSAGE("Stunfisk is healed by the electric floor!");
    } THEN {
        EXPECT_EQ(dmg, -(player->maxHP / 16));
    }
}

SINGLE_BATTLE_TEST("Heal Block suppresses Electric Floor healing")
{
    GIVEN {
        PLAYER(SPECIES_PIKACHU) { HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_HEAL_BLOCK); }
        TURN { MOVE(player, MOVE_CHARGED_GROUND); }
    } SCENE {
        NOT MESSAGE("Pikachu is healed by the electric floor!");
    }
}

SINGLE_BATTLE_TEST("Magic Guard blocks Electric Floor damage")
{
    GIVEN {
        PLAYER(SPECIES_REUNICLUS) { Ability(ABILITY_MAGIC_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARGED_GROUND); }
    } SCENE {
        NOT MESSAGE("Reuniclus is hurt by the electric floor!");
    }
}

SINGLE_BATTLE_TEST("Overcoat and Safety Goggles grant immunity to Electric Floor damage")
{
    u32 ability, item;
    PARAMETRIZE { ability = ABILITY_OVERCOAT; item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_NONE; item = ITEM_SAFETY_GOGGLES; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARGED_GROUND); }
    } SCENE {
        NOT MESSAGE("Wobbuffet is hurt by the electric floor!");
    }
}

SINGLE_BATTLE_TEST("Electric Floor ends after 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARGED_GROUND); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("The ground lost its charge.");
    }
}
