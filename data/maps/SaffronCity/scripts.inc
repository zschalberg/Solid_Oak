# 6 "data/maps/SaffronCity/scripts.pory"
SaffronCity_MapScripts::
# 7 "data/maps/SaffronCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
# 8 "data/maps/SaffronCity/scripts.pory"
	.byte 0
# 9 "data/maps/SaffronCity/scripts.pory"

# 10 "data/maps/SaffronCity/scripts.pory"
SaffronCity_OnTransition::
# 11 "data/maps/SaffronCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
# 12 "data/maps/SaffronCity/scripts.pory"
	@ Safety net: the Agatha ambush battle sets FLAG_SCALE_BOSS_BATTLE/
# 13 "data/maps/SaffronCity/scripts.pory"
	@ VAR_SCALE_LEVEL_OFFSET and B_FLAG_NO_WHITEOUT around its trainerbattle
# 14 "data/maps/SaffronCity/scripts.pory"
	@ call and clears them right after. That clear should always run now
# 15 "data/maps/SaffronCity/scripts.pory"
	@ (B_FLAG_NO_WHITEOUT keeps a loss from white-ing out mid-script), but
# 16 "data/maps/SaffronCity/scripts.pory"
	@ this is cheap insurance against a soft reset or other interruption
# 17 "data/maps/SaffronCity/scripts.pory"
	@ mid-fight leaking any of the three into every battle after it. Mirrors
# 18 "data/maps/SaffronCity/scripts.pory"
	@ the same fix used in VermilionCity_Dojo for its scaled fights.
# 19 "data/maps/SaffronCity/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 20 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 21 "data/maps/SaffronCity/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 22 "data/maps/SaffronCity/scripts.pory"
	end
# 23 "data/maps/SaffronCity/scripts.pory"

# 24 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt1::
# 25 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
# 26 "data/maps/SaffronCity/scripts.pory"
	end
# 27 "data/maps/SaffronCity/scripts.pory"

# 28 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt2::
# 29 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
# 30 "data/maps/SaffronCity/scripts.pory"
	end
# 31 "data/maps/SaffronCity/scripts.pory"

# 32 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt3::
# 33 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
# 34 "data/maps/SaffronCity/scripts.pory"
	end
# 35 "data/maps/SaffronCity/scripts.pory"

# 36 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt4::
# 37 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
# 38 "data/maps/SaffronCity/scripts.pory"
	end
# 39 "data/maps/SaffronCity/scripts.pory"

# 40 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt5::
# 41 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
# 42 "data/maps/SaffronCity/scripts.pory"
	end
# 43 "data/maps/SaffronCity/scripts.pory"

# 44 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt6::
# 45 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
# 46 "data/maps/SaffronCity/scripts.pory"
	end
# 47 "data/maps/SaffronCity/scripts.pory"

# 48 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt7::
# 49 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
# 50 "data/maps/SaffronCity/scripts.pory"
	end
# 51 "data/maps/SaffronCity/scripts.pory"

# 52 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_WorkerM::
# 53 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
# 54 "data/maps/SaffronCity/scripts.pory"
	end
# 55 "data/maps/SaffronCity/scripts.pory"

# 56 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Youngster::
# 57 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
# 58 "data/maps/SaffronCity/scripts.pory"
	end
# 59 "data/maps/SaffronCity/scripts.pory"

# 60 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Lass::
# 61 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
# 62 "data/maps/SaffronCity/scripts.pory"
	end
# 63 "data/maps/SaffronCity/scripts.pory"

# 64 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Boy::
# 65 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
# 66 "data/maps/SaffronCity/scripts.pory"
	end
# 67 "data/maps/SaffronCity/scripts.pory"

# 68 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Pidgeot::
# 69 "data/maps/SaffronCity/scripts.pory"
	lock
# 70 "data/maps/SaffronCity/scripts.pory"
	faceplayer
# 71 "data/maps/SaffronCity/scripts.pory"
	waitse
# 72 "data/maps/SaffronCity/scripts.pory"
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
# 73 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_Pidgeot
# 74 "data/maps/SaffronCity/scripts.pory"
	waitmoncry
# 75 "data/maps/SaffronCity/scripts.pory"
	release
# 76 "data/maps/SaffronCity/scripts.pory"
	end
# 77 "data/maps/SaffronCity/scripts.pory"

# 78 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Man::
# 79 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
# 80 "data/maps/SaffronCity/scripts.pory"
	end
# 81 "data/maps/SaffronCity/scripts.pory"

# 82 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_CitySign::
# 83 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
# 84 "data/maps/SaffronCity/scripts.pory"
	end
# 85 "data/maps/SaffronCity/scripts.pory"

# 86 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_DojoSign::
# 87 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
# 88 "data/maps/SaffronCity/scripts.pory"
	end
# 89 "data/maps/SaffronCity/scripts.pory"

# 90 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_GymSign::
# 91 "data/maps/SaffronCity/scripts.pory"
	lockall
# 92 "data/maps/SaffronCity/scripts.pory"
	famechecker FAMECHECKER_SABRINA, 0
# 93 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_GymSign
# 94 "data/maps/SaffronCity/scripts.pory"
	releaseall
# 95 "data/maps/SaffronCity/scripts.pory"
	end
# 96 "data/maps/SaffronCity/scripts.pory"

# 97 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_TrainerTips1::
# 98 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
# 99 "data/maps/SaffronCity/scripts.pory"
	end
# 100 "data/maps/SaffronCity/scripts.pory"

# 101 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_TrainerTips2::
# 102 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
# 103 "data/maps/SaffronCity/scripts.pory"
	end
# 104 "data/maps/SaffronCity/scripts.pory"

# 105 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_SilphCoSign::
# 106 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
# 107 "data/maps/SaffronCity/scripts.pory"
	end
# 108 "data/maps/SaffronCity/scripts.pory"

# 109 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_MrPsychicsHouseSign::
# 110 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
# 111 "data/maps/SaffronCity/scripts.pory"
	end
# 112 "data/maps/SaffronCity/scripts.pory"

# 113 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_SilphProductSign::
# 114 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
# 115 "data/maps/SaffronCity/scripts.pory"
	end
# 116 "data/maps/SaffronCity/scripts.pory"

# 117 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_TrainerFanClubSign::
# 118 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 119 "data/maps/SaffronCity/scripts.pory"
	end

SaffronCity_EventScript_AgathaAmbushTrigger::
# 138 "data/maps/SaffronCity/scripts.pory"
	lockall
# 139 "data/maps/SaffronCity/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 140 "data/maps/SaffronCity/scripts.pory"
	clearflag FLAG_HIDE_SAFFRON_AGATHA_AMBUSH
# 141 "data/maps/SaffronCity/scripts.pory"
	addobject 9
# 142 "data/maps/SaffronCity/scripts.pory"
	applymovement 9, SaffronCity_Movement_AgathaAmbushEnter
# 143 "data/maps/SaffronCity/scripts.pory"
	waitmovement 0
# 144 "data/maps/SaffronCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 145 "data/maps/SaffronCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 146 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_AgathaAmbushIntro
# 147 "data/maps/SaffronCity/scripts.pory"
	closemessage
# 148 "data/maps/SaffronCity/scripts.pory"
	clearmugshot
# 149 "data/maps/SaffronCity/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 150 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
# 151 "data/maps/SaffronCity/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 152 "data/maps/SaffronCity/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq SaffronCity_EventScript_AgathaAmbushTrigger_2
# 152 "data/maps/SaffronCity/scripts.pory"
	goto_if_set FLAG_0x8D7, SaffronCity_EventScript_AgathaAmbushTrigger_2
# 154 "data/maps/SaffronCity/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq SaffronCity_EventScript_AgathaAmbushTrigger_3
# 154 "data/maps/SaffronCity/scripts.pory"
	goto_if_set FLAG_0x8D8, SaffronCity_EventScript_AgathaAmbushTrigger_3
# 157 "data/maps/SaffronCity/scripts.pory"
	trainerbattle_no_intro TRAINER_AGATHA_SILPH_GROWLITHE, SaffronCity_Text_AgathaAmbushDefeat
SaffronCity_EventScript_AgathaAmbushTrigger_1:
# 159 "data/maps/SaffronCity/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 160 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 161 "data/maps/SaffronCity/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 162 "data/maps/SaffronCity/scripts.pory"
	special HealPlayerParty
# 163 "data/maps/SaffronCity/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 164 "data/maps/SaffronCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 165 "data/maps/SaffronCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 166 "data/maps/SaffronCity/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_ne SaffronCity_EventScript_AgathaAmbushTrigger_12
SaffronCity_EventScript_AgathaAmbushTrigger_11:
# 169 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_AgathaAmbushPostBattle
# 170 "data/maps/SaffronCity/scripts.pory"
	closemessage
# 171 "data/maps/SaffronCity/scripts.pory"
	clearmugshot
# 172 "data/maps/SaffronCity/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 173 "data/maps/SaffronCity/scripts.pory"
	applymovement 9, SaffronCity_Movement_AgathaAmbushExit
# 174 "data/maps/SaffronCity/scripts.pory"
	waitmovement 0
# 175 "data/maps/SaffronCity/scripts.pory"
	removeobject 9
# 176 "data/maps/SaffronCity/scripts.pory"
	setflag FLAG_HIDE_SAFFRON_AGATHA_AMBUSH
# 177 "data/maps/SaffronCity/scripts.pory"
	fadedefaultbgm
# 178 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCENE_SILPH, 4
# 179 "data/maps/SaffronCity/scripts.pory"
	releaseall
	end

SaffronCity_EventScript_AgathaAmbushTrigger_2:
# 153 "data/maps/SaffronCity/scripts.pory"
	trainerbattle_no_intro TRAINER_AGATHA_SILPH_NIDORAN, SaffronCity_Text_AgathaAmbushDefeat
	goto SaffronCity_EventScript_AgathaAmbushTrigger_1

SaffronCity_EventScript_AgathaAmbushTrigger_3:
# 155 "data/maps/SaffronCity/scripts.pory"
	trainerbattle_no_intro TRAINER_AGATHA_SILPH_EXEGGCUTE, SaffronCity_Text_AgathaAmbushDefeat
	goto SaffronCity_EventScript_AgathaAmbushTrigger_1

SaffronCity_EventScript_AgathaAmbushTrigger_12:
# 167 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_AgathaAmbushVictory
	goto SaffronCity_EventScript_AgathaAmbushTrigger_11


# 183 "data/maps/SaffronCity/scripts.pory"
SaffronCity_Movement_AgathaAmbushEnter:
# 184 "data/maps/SaffronCity/scripts.pory"
	walk_up
	step_end

# 187 "data/maps/SaffronCity/scripts.pory"
SaffronCity_Movement_AgathaAmbushExit:
# 188 "data/maps/SaffronCity/scripts.pory"
	walk_down
	step_end
