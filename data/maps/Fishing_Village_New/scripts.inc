Fishing_Village_New_Boss_Battle::
# 3 "data/maps/Fishing_Village_New/scripts.pory"
	goto_if_unset FLAG_ZONE_1_RESOLVED, Fishing_Village_New_Boss_Battle_2
Fishing_Village_New_Boss_Battle_1:
	end

Fishing_Village_New_Boss_Battle_2:
# 4 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8004, SPECIES_TENTACRUEL
# 5 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8005, 30
# 6 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8006, 5
# 7 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_0x8007, ITEM_NONE
# 8 "data/maps/Fishing_Village_New/scripts.pory"
	callnative Script_SetScaledWildBattle
# 9 "data/maps/Fishing_Village_New/scripts.pory"
	setwildsize 100, 100
# 10 "data/maps/Fishing_Village_New/scripts.pory"
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
# 11 "data/maps/Fishing_Village_New/scripts.pory"
	dowildbattle
# 12 "data/maps/Fishing_Village_New/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 13 "data/maps/Fishing_Village_New/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Fishing_Village_New_Boss_Battle_4
# 13 "data/maps/Fishing_Village_New/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Fishing_Village_New_Boss_Battle_4
	goto Fishing_Village_New_Boss_Battle_1

Fishing_Village_New_Boss_Battle_4:
# 14 "data/maps/Fishing_Village_New/scripts.pory"
	setflag FLAG_ZONE_1_RESOLVED
# 15 "data/maps/Fishing_Village_New/scripts.pory"
	removeobject 4
# 16 "data/maps/Fishing_Village_New/scripts.pory"
	setvar VAR_ACT1_LAVENDER, 2
# 17 "data/maps/Fishing_Village_New/scripts.pory"
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_LEFT
# 18 "data/maps/Fishing_Village_New/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 19 "data/maps/Fishing_Village_New/scripts.pory"
	msgbox Fishing_Village_New_Boss_Battle_Text_0
# 20 "data/maps/Fishing_Village_New/scripts.pory"
	closemessage
	goto Fishing_Village_New_Boss_Battle_1


Fishing_Village_New_Sailor::
# 27 "data/maps/Fishing_Village_New/scripts.pory"
	lockall
# 28 "data/maps/Fishing_Village_New/scripts.pory"
	faceplayer
# 29 "data/maps/Fishing_Village_New/scripts.pory"
	msgbox Fishing_Village_New_Sailor_Text_0
# 33 "data/maps/Fishing_Village_New/scripts.pory"
	releaseall
	end


Fishing_Village_New_Fisherman::
# 37 "data/maps/Fishing_Village_New/scripts.pory"
	lockall
# 38 "data/maps/Fishing_Village_New/scripts.pory"
	faceplayer
# 39 "data/maps/Fishing_Village_New/scripts.pory"
	msgbox Fishing_Village_New_Fisherman_Text_0
# 41 "data/maps/Fishing_Village_New/scripts.pory"
	releaseall
	end


Fishing_Village_New_Old_Man::
# 45 "data/maps/Fishing_Village_New/scripts.pory"
	lockall
# 46 "data/maps/Fishing_Village_New/scripts.pory"
	faceplayer
# 47 "data/maps/Fishing_Village_New/scripts.pory"
	msgbox Fishing_Village_New_Old_Man_Text_0
# 50 "data/maps/Fishing_Village_New/scripts.pory"
	releaseall
	end


Fishing_Village_New_Old_Man_Unresponsive::
# 54 "data/maps/Fishing_Village_New/scripts.pory"
	lockall
# 55 "data/maps/Fishing_Village_New/scripts.pory"
	msgbox Fishing_Village_New_Old_Man_Unresponsive_Text_0
# 56 "data/maps/Fishing_Village_New/scripts.pory"
	releaseall
	end


Fishing_Village_New_MapScripts::
# 64 "data/maps/Fishing_Village_New/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Fishing_Village_New_OnLoad
	.byte 0


Fishing_Village_New_OnLoad::
# 68 "data/maps/Fishing_Village_New/scripts.pory"
	special UpdateFishingVillageTiles
# 73 "data/maps/Fishing_Village_New/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, Fishing_Village_New_OnLoad_2
# 73 "data/maps/Fishing_Village_New/scripts.pory"
	goto_if_set FLAG_ZONE_1_RESOLVED, Fishing_Village_New_OnLoad_2
# 77 "data/maps/Fishing_Village_New/scripts.pory"
	clearflag FLAG_HIDE_FISHING_VILLAGE_BOSS
# 78 "data/maps/Fishing_Village_New/scripts.pory"
	clearflag FLAG_HIDE_FISHING_VILLAGE_OLD_MAN
Fishing_Village_New_OnLoad_1:
	end

Fishing_Village_New_OnLoad_2:
# 74 "data/maps/Fishing_Village_New/scripts.pory"
	setflag FLAG_HIDE_FISHING_VILLAGE_BOSS
# 75 "data/maps/Fishing_Village_New/scripts.pory"
	setflag FLAG_HIDE_FISHING_VILLAGE_OLD_MAN
	goto Fishing_Village_New_OnLoad_1


Fishing_Village_New_Boss_Battle_Text_0:
# 19 "data/maps/Fishing_Village_New/scripts.pory"
	.string "I should let Fuji know about this.$"

Fishing_Village_New_Sailor_Text_0:
# 29 "data/maps/Fishing_Village_New/scripts.pory"
	.string "The TENTACOOL have been gathering.\p"
	.string "They're more of a nuisane than a \n"
	.string "threat. It's the TENTACREUL that \l"
	.string "you need to watch out for.$"

Fishing_Village_New_Fisherman_Text_0:
# 39 "data/maps/Fishing_Village_New/scripts.pory"
	.string "This is the best fishing\n"
	.string "spot in all of Kanto.$"

Fishing_Village_New_Old_Man_Text_0:
# 47 "data/maps/Fishing_Village_New/scripts.pory"
	.string "It's a beautiful day.\p"
	.string "I'm not too worried about the \n"
	.string "TENTACOOL. They don't bother me.$"

Fishing_Village_New_Old_Man_Unresponsive_Text_0:
# 55 "data/maps/Fishing_Village_New/scripts.pory"
	.string "The man is unresponsive.$"
