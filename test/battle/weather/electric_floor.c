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

SINGLE_BATTLE_TEST("Cloud Nine and Air Lock suppress Electric Floor damage")
{
    u32 species = SPECIES_NONE;
    u32 ability = ABILITY_NONE;

    PARAMETRIZE { species = SPECIES_GOLDUCK;  ability = ABILITY_CLOUD_NINE; }
    PARAMETRIZE { species = SPECIES_RAYQUAZA; ability = ABILITY_AIR_LOCK; }

    GIVEN {
        PLAYER(species) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CHARGED_GROUND); }
    } SCENE {
        NOT MESSAGE("Golduck is hurt by the electric floor!");
        NOT MESSAGE("Rayquaza is hurt by the electric floor!");
        NOT MESSAGE("The opposing Wobbuffet is hurt by the electric floor!");
    }
}

SINGLE_BATTLE_TEST("Rain Dance replaces Electric Floor")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHARGED_GROUND); }
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
    } SCENE {
        MESSAGE("It started to rain!");
        NOT MESSAGE("Wobbuffet is hurt by the electric floor!");
        NOT MESSAGE("The opposing Wobbuffet is hurt by the electric floor!");
    }
}

SINGLE_BATTLE_TEST("Weather Ball is not boosted by Electric Floor", s16 damage)
{
    bool32 floorUp;
    PARAMETRIZE { floorUp = FALSE; }
    PARAMETRIZE { floorUp = TRUE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_WEATHER_BALL) == EFFECT_WEATHER_BALL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        if (floorUp)
            TURN { MOVE(opponent, MOVE_CHARGED_GROUND); MOVE(player, MOVE_WEATHER_BALL); }
        else
            TURN { MOVE(player, MOVE_WEATHER_BALL); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

AI_SINGLE_BATTLE_TEST("AI sets Electric Floor when it benefits, but not into Cloud Nine")
{
    u32 ability;
    PARAMETRIZE { ability = ABILITY_DAMP; }
    PARAMETRIZE { ability = ABILITY_CLOUD_NINE; }

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_CHARGED_GROUND) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_CHARGED_GROUND) == BATTLE_WEATHER_ELECTRIC_FLOOR);
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_TRY_TO_FAINT | AI_FLAG_CHECK_VIABILITY);
        PLAYER(SPECIES_GOLDUCK) { Ability(ability); Moves(MOVE_SCRATCH); }
        OPPONENT(SPECIES_PIKACHU) { Moves(MOVE_CHARGED_GROUND, MOVE_POUND); }
    } WHEN {
        if (ability == ABILITY_CLOUD_NINE)
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_POUND); }
        else
            TURN { MOVE(player, MOVE_SCRATCH); EXPECT_MOVE(opponent, MOVE_CHARGED_GROUND); }
    }
}
