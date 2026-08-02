Fishing_Village_New_Boss_Battle::
# 3 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8004, SPECIES_TENTACRUEL
# 4 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8005, 30
# 5 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8006, 5
# 6 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8007, ITEM_NONE
# 7 "data/maps/Fishing_Village_New/scripts.pory"
	callnative Script_SetScaledWildBattle
# 8 "data/maps/Fishing_Village_New/scripts.pory"
	setwildsize 100, 100
# 9 "data/maps/Fishing_Village_New/scripts.pory"
	dowildbattle
# 10 "data/maps/Fishing_Village_New/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 11 "data/maps/Fishing_Village_New/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Fishing_Village_New_Boss_Battle_2
# 11 "data/maps/Fishing_Village_New/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Fishing_Village_New_Boss_Battle_2
Fishing_Village_New_Boss_Battle_1:
	end

Fishing_Village_New_Boss_Battle_2:
# 12 "data/maps/Fishing_Village_New/scripts.pory"
	setflag FLAG_ZONE_1_RESOLVED
	goto Fishing_Village_New_Boss_Battle_1


Fishing_Village_New_MapScripts::
# 24 "data/maps/Fishing_Village_New/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Fishing_Village_New_OnLoad
	.byte 0


Fishing_Village_New_OnLoad::
# 28 "data/maps/Fishing_Village_New/scripts.pory"
	special UpdateFishingVillageTiles
	end

