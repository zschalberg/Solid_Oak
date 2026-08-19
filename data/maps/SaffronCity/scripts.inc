# 4 "data/maps/SaffronCity/scripts.pory"
SaffronCity_MapScripts::
# 5 "data/maps/SaffronCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
# 6 "data/maps/SaffronCity/scripts.pory"
	.byte 0
# 7 "data/maps/SaffronCity/scripts.pory"

# 8 "data/maps/SaffronCity/scripts.pory"
SaffronCity_OnTransition::
# 9 "data/maps/SaffronCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
# 10 "data/maps/SaffronCity/scripts.pory"
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
# 11 "data/maps/SaffronCity/scripts.pory"
	@ Safety net: the Agatha ambush battle sets FLAG_SCALE_BOSS_BATTLE/
# 12 "data/maps/SaffronCity/scripts.pory"
	@ VAR_SCALE_LEVEL_OFFSET and B_FLAG_NO_WHITEOUT around its trainerbattle
# 13 "data/maps/SaffronCity/scripts.pory"
	@ call and clears them right after. That clear should always run now
# 14 "data/maps/SaffronCity/scripts.pory"
	@ (B_FLAG_NO_WHITEOUT keeps a loss from white-ing out mid-script), but
# 15 "data/maps/SaffronCity/scripts.pory"
	@ this is cheap insurance against a soft reset or other interruption
# 16 "data/maps/SaffronCity/scripts.pory"
	@ mid-fight leaking any of the three into every battle after it. Mirrors
# 17 "data/maps/SaffronCity/scripts.pory"
	@ the same fix used in VermilionCity_Dojo for its scaled fights.
# 18 "data/maps/SaffronCity/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 19 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 20 "data/maps/SaffronCity/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 21 "data/maps/SaffronCity/scripts.pory"
	end
# 22 "data/maps/SaffronCity/scripts.pory"

# 23 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_MoveDoorGuardGrunt::
# 24 "data/maps/SaffronCity/scripts.pory"
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
# 25 "data/maps/SaffronCity/scripts.pory"
	return
# 26 "data/maps/SaffronCity/scripts.pory"

# 27 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt1::
# 28 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
# 29 "data/maps/SaffronCity/scripts.pory"
	end
# 30 "data/maps/SaffronCity/scripts.pory"

# 31 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt2::
# 32 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
# 33 "data/maps/SaffronCity/scripts.pory"
	end
# 34 "data/maps/SaffronCity/scripts.pory"

# 35 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt3::
# 36 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
# 37 "data/maps/SaffronCity/scripts.pory"
	end
# 38 "data/maps/SaffronCity/scripts.pory"

# 39 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt4::
# 40 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
# 41 "data/maps/SaffronCity/scripts.pory"
	end
# 42 "data/maps/SaffronCity/scripts.pory"

# 43 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt5::
# 44 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
# 45 "data/maps/SaffronCity/scripts.pory"
	end
# 46 "data/maps/SaffronCity/scripts.pory"

# 47 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt6::
# 48 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
# 49 "data/maps/SaffronCity/scripts.pory"
	end
# 50 "data/maps/SaffronCity/scripts.pory"

# 51 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_RocketGrunt7::
# 52 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
# 53 "data/maps/SaffronCity/scripts.pory"
	end
# 54 "data/maps/SaffronCity/scripts.pory"

# 55 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_DoorGuardGrunt::
# 56 "data/maps/SaffronCity/scripts.pory"
	lock
# 57 "data/maps/SaffronCity/scripts.pory"
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
# 58 "data/maps/SaffronCity/scripts.pory"
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
# 59 "data/maps/SaffronCity/scripts.pory"
	waitmovement 0
# 60 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_ImASecurityGuard
# 61 "data/maps/SaffronCity/scripts.pory"
	release
# 62 "data/maps/SaffronCity/scripts.pory"
	end
# 63 "data/maps/SaffronCity/scripts.pory"

# 64 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_DoorGuardAsleep::
# 65 "data/maps/SaffronCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 66 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_HesTakingASnooze
# 67 "data/maps/SaffronCity/scripts.pory"
	release
# 68 "data/maps/SaffronCity/scripts.pory"
	end
# 69 "data/maps/SaffronCity/scripts.pory"

# 70 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_WorkerM::
# 71 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
# 72 "data/maps/SaffronCity/scripts.pory"
	end
# 73 "data/maps/SaffronCity/scripts.pory"

# 74 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Youngster::
# 75 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
# 76 "data/maps/SaffronCity/scripts.pory"
	end
# 77 "data/maps/SaffronCity/scripts.pory"

# 78 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Lass::
# 79 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
# 80 "data/maps/SaffronCity/scripts.pory"
	end
# 81 "data/maps/SaffronCity/scripts.pory"

# 82 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Boy::
# 83 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
# 84 "data/maps/SaffronCity/scripts.pory"
	end
# 85 "data/maps/SaffronCity/scripts.pory"

# 86 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Pidgeot::
# 87 "data/maps/SaffronCity/scripts.pory"
	lock
# 88 "data/maps/SaffronCity/scripts.pory"
	faceplayer
# 89 "data/maps/SaffronCity/scripts.pory"
	waitse
# 90 "data/maps/SaffronCity/scripts.pory"
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
# 91 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_Pidgeot
# 92 "data/maps/SaffronCity/scripts.pory"
	waitmoncry
# 93 "data/maps/SaffronCity/scripts.pory"
	release
# 94 "data/maps/SaffronCity/scripts.pory"
	end
# 95 "data/maps/SaffronCity/scripts.pory"

# 96 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_Man::
# 97 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
# 98 "data/maps/SaffronCity/scripts.pory"
	end
# 99 "data/maps/SaffronCity/scripts.pory"

# 100 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_CitySign::
# 101 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
# 102 "data/maps/SaffronCity/scripts.pory"
	end
# 103 "data/maps/SaffronCity/scripts.pory"

# 104 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_DojoSign::
# 105 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
# 106 "data/maps/SaffronCity/scripts.pory"
	end
# 107 "data/maps/SaffronCity/scripts.pory"

# 108 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_GymSign::
# 109 "data/maps/SaffronCity/scripts.pory"
	lockall
# 110 "data/maps/SaffronCity/scripts.pory"
	famechecker FAMECHECKER_SABRINA, 0
# 111 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_GymSign
# 112 "data/maps/SaffronCity/scripts.pory"
	releaseall
# 113 "data/maps/SaffronCity/scripts.pory"
	end
# 114 "data/maps/SaffronCity/scripts.pory"

# 115 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_TrainerTips1::
# 116 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
# 117 "data/maps/SaffronCity/scripts.pory"
	end
# 118 "data/maps/SaffronCity/scripts.pory"

# 119 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_TrainerTips2::
# 120 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
# 121 "data/maps/SaffronCity/scripts.pory"
	end
# 122 "data/maps/SaffronCity/scripts.pory"

# 123 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_SilphCoSign::
# 124 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
# 125 "data/maps/SaffronCity/scripts.pory"
	end
# 126 "data/maps/SaffronCity/scripts.pory"

# 127 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_MrPsychicsHouseSign::
# 128 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
# 129 "data/maps/SaffronCity/scripts.pory"
	end
# 130 "data/maps/SaffronCity/scripts.pory"

# 131 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_SilphProductSign::
# 132 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
# 133 "data/maps/SaffronCity/scripts.pory"
	end
# 134 "data/maps/SaffronCity/scripts.pory"

# 135 "data/maps/SaffronCity/scripts.pory"
SaffronCity_EventScript_TrainerFanClubSign::
# 136 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 137 "data/maps/SaffronCity/scripts.pory"
	end

SaffronCity_EventScript_AgathaAmbushTrigger::
# 156 "data/maps/SaffronCity/scripts.pory"
	lockall
# 157 "data/maps/SaffronCity/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 158 "data/maps/SaffronCity/scripts.pory"
	clearflag FLAG_HIDE_SAFFRON_AGATHA_AMBUSH
# 159 "data/maps/SaffronCity/scripts.pory"
	addobject 10
# 160 "data/maps/SaffronCity/scripts.pory"
	applymovement 10, SaffronCity_Movement_AgathaAmbushEnter
# 161 "data/maps/SaffronCity/scripts.pory"
	waitmovement 0
# 162 "data/maps/SaffronCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 163 "data/maps/SaffronCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 164 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_AgathaAmbushIntro
# 165 "data/maps/SaffronCity/scripts.pory"
	closemessage
# 166 "data/maps/SaffronCity/scripts.pory"
	clearmugshot
# 167 "data/maps/SaffronCity/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 168 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
# 169 "data/maps/SaffronCity/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 170 "data/maps/SaffronCity/scripts.pory"
	trainerbattle_no_intro TRAINER_AGATHA_SILPH, SaffronCity_Text_AgathaAmbushDefeat
# 171 "data/maps/SaffronCity/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 172 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 173 "data/maps/SaffronCity/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 174 "data/maps/SaffronCity/scripts.pory"
	special HealPlayerParty
# 175 "data/maps/SaffronCity/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 176 "data/maps/SaffronCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 177 "data/maps/SaffronCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 178 "data/maps/SaffronCity/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_ne SaffronCity_EventScript_AgathaAmbushTrigger_2
SaffronCity_EventScript_AgathaAmbushTrigger_1:
# 181 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_AgathaAmbushPostBattle
# 182 "data/maps/SaffronCity/scripts.pory"
	closemessage
# 183 "data/maps/SaffronCity/scripts.pory"
	clearmugshot
# 184 "data/maps/SaffronCity/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 185 "data/maps/SaffronCity/scripts.pory"
	applymovement 10, SaffronCity_Movement_AgathaAmbushExit
# 186 "data/maps/SaffronCity/scripts.pory"
	waitmovement 0
# 187 "data/maps/SaffronCity/scripts.pory"
	removeobject 10
# 188 "data/maps/SaffronCity/scripts.pory"
	setflag FLAG_HIDE_SAFFRON_AGATHA_AMBUSH
# 189 "data/maps/SaffronCity/scripts.pory"
	fadedefaultbgm
# 190 "data/maps/SaffronCity/scripts.pory"
	setvar VAR_SCENE_SILPH, 4
# 191 "data/maps/SaffronCity/scripts.pory"
	releaseall
	end

SaffronCity_EventScript_AgathaAmbushTrigger_2:
# 179 "data/maps/SaffronCity/scripts.pory"
	msgbox SaffronCity_Text_AgathaAmbushVictory
	goto SaffronCity_EventScript_AgathaAmbushTrigger_1


# 195 "data/maps/SaffronCity/scripts.pory"
SaffronCity_Movement_AgathaAmbushEnter:
# 196 "data/maps/SaffronCity/scripts.pory"
	walk_up
	step_end

# 199 "data/maps/SaffronCity/scripts.pory"
SaffronCity_Movement_AgathaAmbushExit:
# 200 "data/maps/SaffronCity/scripts.pory"
	walk_down
	step_end
