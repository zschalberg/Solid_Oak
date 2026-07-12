#include "global.h"
#include "test/battle.h"
#include "battle_setup.h"

// Simulates a map script calling `banmovetype`/`banmovecategory` right before
// a scripted battle starts. The staging globals are consumed into
// gBattleStruct the moment the battle engine allocates its resources, so
// calling the setters here (before the battle is created) matches how a real
// script would set them up.

SINGLE_BATTLE_TEST("Battle Rule can ban a move type for the player only")
{
    GIVEN {
        SetBattleRuleBanMoveType(TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER, MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, allowed: FALSE); MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
    }
}

SINGLE_BATTLE_TEST("Battle Rule can ban a move category for the player only")
{
    GIVEN {
        SetBattleRuleBanMoveCategory(DAMAGE_CATEGORY_STATUS);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_GROWL, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_GROWL, MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_GROWL, allowed: FALSE); MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, opponent);
    }
}

SINGLE_BATTLE_TEST("Battle Rule forces Struggle when all of the player's moves are banned")
{
    GIVEN {
        SetBattleRuleBanMoveType(TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, allowed: FALSE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STRUGGLE, player);
    }
}

SINGLE_BATTLE_TEST("Without setting a Battle Rule, no move type/category restriction applies")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER); }
        TURN { MOVE(player, MOVE_GROWL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GROWL, player);
    }
}

SINGLE_BATTLE_TEST("Battle Rule with battleRuleAffectsOpponent bans the opponent too")
{
    GIVEN {
        SetBattleRuleBanMoveType(TYPE_FIRE);
        SetBattleRuleAffectsOpponent(TRUE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER, MOVE_TACKLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, allowed: FALSE); MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_EMBER, allowed: FALSE); MOVE(opponent, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, opponent);
    }
}

SINGLE_BATTLE_TEST("Battle Rule without battleRuleAffectsOpponent leaves the opponent unrestricted")
{
    GIVEN {
        SetBattleRuleBanMoveType(TYPE_FIRE);
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER, MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_EMBER); }
    } WHEN {
        TURN { MOVE(player, MOVE_EMBER, allowed: FALSE); MOVE(player, MOVE_TACKLE); MOVE(opponent, MOVE_EMBER); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
    }
}
