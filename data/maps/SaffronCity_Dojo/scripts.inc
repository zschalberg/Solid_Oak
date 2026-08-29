SaffronCity_Dojo_MapScripts::
# 33 "data/maps/SaffronCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_Dojo_OnTransition
# 34 "data/maps/SaffronCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SaffronCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 35 "data/maps/SaffronCity_Dojo/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SaffronCity_Dojo_OnFrame
	.2byte 0


SaffronCity_Dojo_OnTransition::
# 57 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 58 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 59 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_HITOSHI_DONE
# 60 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_HIDEKI_DONE
# 61 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_AARON_DONE
# 62 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_MIKE_DONE
# 63 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_KOICHI_DONE
# 64 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 0
	end


SaffronCity_Dojo_OnFrame::
# 78 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_0, 1
# 79 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_SEEN_DOJO_INTRO, SaffronCity_Dojo_OnFrame_2
SaffronCity_Dojo_OnFrame_1:
# 82 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_QUEST_SPEED_DOJO_ACTIVE, SaffronCity_Dojo_OnFrame_5
SaffronCity_Dojo_OnFrame_4:
	end

SaffronCity_Dojo_OnFrame_2:
# 80 "data/maps/SaffronCity_Dojo/scripts.pory"
	call Common_EventScript_DojoIntro
	goto SaffronCity_Dojo_OnFrame_1

SaffronCity_Dojo_OnFrame_5:
# 83 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_QUEST_SPEED_DOJO_ACTIVE
# 84 "data/maps/SaffronCity_Dojo/scripts.pory"
	quest_start_toast SaffronCity_Dojo_OnFrame_Text_0
	goto SaffronCity_Dojo_OnFrame_4


SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
# 90 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 91 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 92 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterLeft
# 93 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 94 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
	end


SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
# 99 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 100 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 101 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterRight
# 102 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 103 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
	end


SaffronCity_Dojo_EventScript_ChallengeGuy::
# 112 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 113 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 116 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HITOSHI_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeGuy_5
SaffronCity_Dojo_EventScript_ChallengeGuy_3:
# 129 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeGuyIntro, MSGBOX_DEFAULT
# 130 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
# 131 "data/maps/SaffronCity_Dojo/scripts.pory"
	multichoice 0, 0, MULTI_DOJO_CHALLENGE, FALSE
SaffronCity_Dojo_EventScript_ChallengeGuy_1:
# 133 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SaffronCity_Dojo_EventScript_ChallengeGuy_14
# 137 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SaffronCity_Dojo_EventScript_ChallengeGuy_20
# 141 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SaffronCity_Dojo_EventScript_ChallengeGuy_25
# 145 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq SaffronCity_Dojo_EventScript_ChallengeGuy_28
# 149 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_ChallengeGuy_2:
# 117 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeGuyIntroGauntlet, MSGBOX_DEFAULT
# 118 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
# 119 "data/maps/SaffronCity_Dojo/scripts.pory"
	multichoice 0, 0, MULTI_DOJO_CHALLENGE_GAUNTLET, FALSE
# 120 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq SaffronCity_Dojo_EventScript_ChallengeGuy_17
# 124 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq SaffronCity_Dojo_EventScript_ChallengeGuy_22
	goto SaffronCity_Dojo_EventScript_ChallengeGuy_1

SaffronCity_Dojo_EventScript_ChallengeGuy_4:
# 116 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AARON_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeGuy_9
	goto SaffronCity_Dojo_EventScript_ChallengeGuy_3

SaffronCity_Dojo_EventScript_ChallengeGuy_5:
# 116 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HIDEKI_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeGuy_4
	goto SaffronCity_Dojo_EventScript_ChallengeGuy_3

SaffronCity_Dojo_EventScript_ChallengeGuy_8:
# 116 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_KOICHI_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeGuy_2
	goto SaffronCity_Dojo_EventScript_ChallengeGuy_3

SaffronCity_Dojo_EventScript_ChallengeGuy_9:
# 116 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_MIKE_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeGuy_8
	goto SaffronCity_Dojo_EventScript_ChallengeGuy_3

SaffronCity_Dojo_EventScript_ChallengeGuy_14:
# 134 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ChallengeTraining
	end

SaffronCity_Dojo_EventScript_ChallengeGuy_17:
# 121 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ChallengeGauntlet
	end

SaffronCity_Dojo_EventScript_ChallengeGuy_20:
# 138 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ChallengeWhite
	end

SaffronCity_Dojo_EventScript_ChallengeGuy_22:
# 125 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_ChallengeGuy_25:
# 142 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ChallengeBlue
	end

SaffronCity_Dojo_EventScript_ChallengeGuy_28:
# 146 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ChallengeBlack
	end


SaffronCity_Dojo_EventScript_ChallengeTraining::
# 154 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_TRAINING_MODE
# 155 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 1
# 156 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HITOSHI_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_4
SaffronCity_Dojo_EventScript_ChallengeTraining_1:
# 159 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HITOSHI_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_15
SaffronCity_Dojo_EventScript_ChallengeTraining_12:
# 162 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeTrainingSet, MSGBOX_AUTOCLOSE
# 163 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_ChallengeTraining_2:
# 157 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 2
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_1

SaffronCity_Dojo_EventScript_ChallengeTraining_3:
# 156 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AARON_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_8
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_1

SaffronCity_Dojo_EventScript_ChallengeTraining_4:
# 156 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HIDEKI_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_3
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_1

SaffronCity_Dojo_EventScript_ChallengeTraining_7:
# 156 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_KOICHI_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_2
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_1

SaffronCity_Dojo_EventScript_ChallengeTraining_8:
# 156 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_MIKE_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_7
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_1

SaffronCity_Dojo_EventScript_ChallengeTraining_13:
# 160 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 3
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_12

SaffronCity_Dojo_EventScript_ChallengeTraining_14:
# 159 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AARON_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_19
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_12

SaffronCity_Dojo_EventScript_ChallengeTraining_15:
# 159 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HIDEKI_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_14
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_12

SaffronCity_Dojo_EventScript_ChallengeTraining_18:
# 159 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_KOICHI_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_13
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_12

SaffronCity_Dojo_EventScript_ChallengeTraining_19:
# 159 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_MIKE_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeTraining_18
	goto SaffronCity_Dojo_EventScript_ChallengeTraining_12


SaffronCity_Dojo_EventScript_ChallengeWhite::
# 168 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 169 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 1
# 170 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeWhiteSet, MSGBOX_AUTOCLOSE
# 171 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_ChallengeBlue::
# 176 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_HITOSHI_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlue_2
# 176 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_HIDEKI_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlue_2
# 176 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AARON_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlue_2
# 176 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_MIKE_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlue_2
# 176 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_KOICHI_WHITE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlue_2
# 181 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 182 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 2
# 183 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeBlueSet, MSGBOX_AUTOCLOSE
# 184 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_ChallengeBlue_2:
# 177 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeBlueLocked, MSGBOX_AUTOCLOSE
# 178 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_ChallengeBlack::
# 189 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_HITOSHI_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlack_2
# 189 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_HIDEKI_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlack_2
# 189 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AARON_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlack_2
# 189 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_MIKE_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlack_2
# 189 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_KOICHI_BLUE_DEFEATED, SaffronCity_Dojo_EventScript_ChallengeBlack_2
# 194 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 195 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 3
# 196 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeBlackSet, MSGBOX_AUTOCLOSE
# 197 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_ChallengeBlack_2:
# 190 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeBlackLocked, MSGBOX_AUTOCLOSE
# 191 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_ChallengeGauntlet::
# 206 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 207 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 4
# 208 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_HITOSHI_DONE
# 209 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_HIDEKI_DONE
# 210 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_AARON_DONE
# 211 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_MIKE_DONE
# 212 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_KOICHI_DONE
# 213 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChallengeGauntletSet, MSGBOX_AUTOCLOSE
# 214 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_CheckGauntletComplete::
# 223 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_SPEED_GAUNTLET_CLEARED, SaffronCity_Dojo_EventScript_CheckGauntletComplete_2
# 226 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_HITOSHI_DONE, SaffronCity_Dojo_EventScript_CheckGauntletComplete_7
SaffronCity_Dojo_EventScript_CheckGauntletComplete_4:
	return

SaffronCity_Dojo_EventScript_CheckGauntletComplete_2:
	return

SaffronCity_Dojo_EventScript_CheckGauntletComplete_5:
# 227 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_SPEED_GAUNTLET_CLEARED
# 228 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_GauntletCleared, MSGBOX_DEFAULT
# 229 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
	goto SaffronCity_Dojo_EventScript_CheckGauntletComplete_4

SaffronCity_Dojo_EventScript_CheckGauntletComplete_6:
# 226 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_AARON_DONE, SaffronCity_Dojo_EventScript_CheckGauntletComplete_11
	goto SaffronCity_Dojo_EventScript_CheckGauntletComplete_4

SaffronCity_Dojo_EventScript_CheckGauntletComplete_7:
# 226 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_HIDEKI_DONE, SaffronCity_Dojo_EventScript_CheckGauntletComplete_6
	goto SaffronCity_Dojo_EventScript_CheckGauntletComplete_4

SaffronCity_Dojo_EventScript_CheckGauntletComplete_10:
# 226 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_KOICHI_DONE, SaffronCity_Dojo_EventScript_CheckGauntletComplete_5
	goto SaffronCity_Dojo_EventScript_CheckGauntletComplete_4

SaffronCity_Dojo_EventScript_CheckGauntletComplete_11:
# 226 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_MIKE_DONE, SaffronCity_Dojo_EventScript_CheckGauntletComplete_10
	goto SaffronCity_Dojo_EventScript_CheckGauntletComplete_4


SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete::
# 241 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_QUEST_SPEED_DOJO_COMPLETED, SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_2
# 244 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HITOSHI_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_7
SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_4:
	return

SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_2:
	return

SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_5:
# 245 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_QUEST_SPEED_DOJO_COMPLETED
# 246 "data/maps/SaffronCity_Dojo/scripts.pory"
	quest_complete_toast SaffronCity_Dojo_OnFrame_Text_0
	goto SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_4

SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_6:
# 244 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AARON_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_11
	goto SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_4

SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_7:
# 244 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_HIDEKI_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_6
	goto SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_4

SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_10:
# 244 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_KOICHI_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_5
	goto SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_4

SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_11:
# 244 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_MIKE_BLACK_DEFEATED, SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_10
	goto SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete_4


SaffronCity_Dojo_EventScript_PostBattleCleanup::
# 260 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 261 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 262 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag FLAG_PREVIEW_BATTLE
# 263 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar 0x8008, 0
	return


SaffronCity_Dojo_EventScript_Hitoshi::
# 272 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 273 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 274 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HitoshiIntro, MSGBOX_YESNO
# 275 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_Hitoshi_2
# 281 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 282 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 283 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hitoshi_5
# 287 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 288 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Hitoshi_12
# 288 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Hitoshi_12
# 291 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Hitoshi_20
# 294 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
SaffronCity_Dojo_EventScript_Hitoshi_4:
# 298 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Hitoshi_9
# 302 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Hitoshi_17
# 308 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Hitoshi_26
# 314 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hitoshi_33
SaffronCity_Dojo_EventScript_Hitoshi_32:
# 317 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI_WHITE, SaffronCity_Dojo_Text_HitoshiIntroBattle, SaffronCity_Dojo_Text_HitoshiDefeat, SaffronCity_Dojo_EventScript_HitoshiWon
SaffronCity_Dojo_EventScript_Hitoshi_8:
# 323 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 324 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hitoshi_2:
# 276 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ComeBackWhenReady
# 277 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
# 278 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_Hitoshi_5:
# 284 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 285 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto SaffronCity_Dojo_EventScript_Hitoshi_4

SaffronCity_Dojo_EventScript_Hitoshi_9:
# 299 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HITOSHI_BLACK
# 300 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI_BLACK, SaffronCity_Dojo_Text_HitoshiIntroBattle, SaffronCity_Dojo_Text_HitoshiDefeat, SaffronCity_Dojo_EventScript_HitoshiWon
	goto SaffronCity_Dojo_EventScript_Hitoshi_8

SaffronCity_Dojo_EventScript_Hitoshi_12:
# 289 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto SaffronCity_Dojo_EventScript_Hitoshi_4

SaffronCity_Dojo_EventScript_Hitoshi_17:
# 303 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hitoshi_24
SaffronCity_Dojo_EventScript_Hitoshi_23:
# 306 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI_BLACK, SaffronCity_Dojo_Text_HitoshiIntroBattle, SaffronCity_Dojo_Text_HitoshiDefeat, SaffronCity_Dojo_EventScript_HitoshiWon
	goto SaffronCity_Dojo_EventScript_Hitoshi_8

SaffronCity_Dojo_EventScript_Hitoshi_20:
# 292 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto SaffronCity_Dojo_EventScript_Hitoshi_4

SaffronCity_Dojo_EventScript_Hitoshi_24:
# 304 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HITOSHI_BLACK
	goto SaffronCity_Dojo_EventScript_Hitoshi_23

SaffronCity_Dojo_EventScript_Hitoshi_26:
# 309 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hitoshi_30
SaffronCity_Dojo_EventScript_Hitoshi_29:
# 312 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI_BLUE, SaffronCity_Dojo_Text_HitoshiIntroBattle, SaffronCity_Dojo_Text_HitoshiDefeat, SaffronCity_Dojo_EventScript_HitoshiWon
	goto SaffronCity_Dojo_EventScript_Hitoshi_8

SaffronCity_Dojo_EventScript_Hitoshi_30:
# 310 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HITOSHI_BLUE
	goto SaffronCity_Dojo_EventScript_Hitoshi_29

SaffronCity_Dojo_EventScript_Hitoshi_33:
# 315 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HITOSHI_WHITE
	goto SaffronCity_Dojo_EventScript_Hitoshi_32


SaffronCity_Dojo_EventScript_HitoshiWon::
# 333 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_HitoshiWon_2
# 337 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_HitoshiWon_8
# 345 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_HitoshiWon_14
# 352 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HitoshiWon_20
# 355 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HITOSHI_WHITE
SaffronCity_Dojo_EventScript_HitoshiWon_1:
# 363 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HitoshiWon_6
SaffronCity_Dojo_EventScript_HitoshiWon_5:
# 366 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 367 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
# 368 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HitoshiWon_2:
# 334 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_HITOSHI_DONE
# 335 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckGauntletComplete
	goto SaffronCity_Dojo_EventScript_HitoshiWon_1

SaffronCity_Dojo_EventScript_HitoshiWon_6:
# 364 "data/maps/SaffronCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto SaffronCity_Dojo_EventScript_HitoshiWon_5

SaffronCity_Dojo_EventScript_HitoshiWon_8:
# 338 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HitoshiWon_11
# 341 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_HITOSHI_BLACK_DEFEATED
# 342 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete
	goto SaffronCity_Dojo_EventScript_HitoshiWon_1

SaffronCity_Dojo_EventScript_HitoshiWon_11:
# 339 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HITOSHI_BLACK
	goto SaffronCity_Dojo_EventScript_HitoshiWon_1

SaffronCity_Dojo_EventScript_HitoshiWon_14:
# 346 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HitoshiWon_17
# 349 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HITOSHI_BLUE
	goto SaffronCity_Dojo_EventScript_HitoshiWon_1

SaffronCity_Dojo_EventScript_HitoshiWon_17:
# 347 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_HITOSHI_BLUE_DEFEATED
	goto SaffronCity_Dojo_EventScript_HitoshiWon_1

SaffronCity_Dojo_EventScript_HitoshiWon_20:
# 353 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_HITOSHI_WHITE_DEFEATED
	goto SaffronCity_Dojo_EventScript_HitoshiWon_1


SaffronCity_Dojo_EventScript_Hideki::
# 377 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 378 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 379 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HidekiIntro, MSGBOX_YESNO
# 380 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_Hideki_2
# 386 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 387 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 388 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hideki_5
# 392 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 393 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Hideki_12
# 393 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Hideki_12
# 396 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Hideki_20
# 399 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
SaffronCity_Dojo_EventScript_Hideki_4:
# 403 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Hideki_9
# 407 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Hideki_17
# 413 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Hideki_26
# 419 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hideki_33
SaffronCity_Dojo_EventScript_Hideki_32:
# 422 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI_WHITE, SaffronCity_Dojo_Text_HidekiIntroBattle, SaffronCity_Dojo_Text_HidekiDefeat, SaffronCity_Dojo_EventScript_HidekiWon
SaffronCity_Dojo_EventScript_Hideki_8:
# 428 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 429 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki_2:
# 381 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ComeBackWhenReady
# 382 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
# 383 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_Hideki_5:
# 389 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 390 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto SaffronCity_Dojo_EventScript_Hideki_4

SaffronCity_Dojo_EventScript_Hideki_9:
# 404 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HIDEKI_BLACK
# 405 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI_BLACK, SaffronCity_Dojo_Text_HidekiIntroBattle, SaffronCity_Dojo_Text_HidekiDefeat, SaffronCity_Dojo_EventScript_HidekiWon
	goto SaffronCity_Dojo_EventScript_Hideki_8

SaffronCity_Dojo_EventScript_Hideki_12:
# 394 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto SaffronCity_Dojo_EventScript_Hideki_4

SaffronCity_Dojo_EventScript_Hideki_17:
# 408 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hideki_24
SaffronCity_Dojo_EventScript_Hideki_23:
# 411 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI_BLACK, SaffronCity_Dojo_Text_HidekiIntroBattle, SaffronCity_Dojo_Text_HidekiDefeat, SaffronCity_Dojo_EventScript_HidekiWon
	goto SaffronCity_Dojo_EventScript_Hideki_8

SaffronCity_Dojo_EventScript_Hideki_20:
# 397 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto SaffronCity_Dojo_EventScript_Hideki_4

SaffronCity_Dojo_EventScript_Hideki_24:
# 409 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HIDEKI_BLACK
	goto SaffronCity_Dojo_EventScript_Hideki_23

SaffronCity_Dojo_EventScript_Hideki_26:
# 414 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Hideki_30
SaffronCity_Dojo_EventScript_Hideki_29:
# 417 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI_BLUE, SaffronCity_Dojo_Text_HidekiIntroBattle, SaffronCity_Dojo_Text_HidekiDefeat, SaffronCity_Dojo_EventScript_HidekiWon
	goto SaffronCity_Dojo_EventScript_Hideki_8

SaffronCity_Dojo_EventScript_Hideki_30:
# 415 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HIDEKI_BLUE
	goto SaffronCity_Dojo_EventScript_Hideki_29

SaffronCity_Dojo_EventScript_Hideki_33:
# 420 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HIDEKI_WHITE
	goto SaffronCity_Dojo_EventScript_Hideki_32


SaffronCity_Dojo_EventScript_HidekiWon::
# 434 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_HidekiWon_2
# 438 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_HidekiWon_8
# 446 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_HidekiWon_14
# 453 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HidekiWon_20
# 456 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HIDEKI_WHITE
SaffronCity_Dojo_EventScript_HidekiWon_1:
# 461 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HidekiWon_6
SaffronCity_Dojo_EventScript_HidekiWon_5:
# 464 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 465 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
# 466 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HidekiWon_2:
# 435 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_HIDEKI_DONE
# 436 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckGauntletComplete
	goto SaffronCity_Dojo_EventScript_HidekiWon_1

SaffronCity_Dojo_EventScript_HidekiWon_6:
# 462 "data/maps/SaffronCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto SaffronCity_Dojo_EventScript_HidekiWon_5

SaffronCity_Dojo_EventScript_HidekiWon_8:
# 439 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HidekiWon_11
# 442 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_HIDEKI_BLACK_DEFEATED
# 443 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete
	goto SaffronCity_Dojo_EventScript_HidekiWon_1

SaffronCity_Dojo_EventScript_HidekiWon_11:
# 440 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HIDEKI_BLACK
	goto SaffronCity_Dojo_EventScript_HidekiWon_1

SaffronCity_Dojo_EventScript_HidekiWon_14:
# 447 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_HidekiWon_17
# 450 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_HIDEKI_BLUE
	goto SaffronCity_Dojo_EventScript_HidekiWon_1

SaffronCity_Dojo_EventScript_HidekiWon_17:
# 448 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_HIDEKI_BLUE_DEFEATED
	goto SaffronCity_Dojo_EventScript_HidekiWon_1

SaffronCity_Dojo_EventScript_HidekiWon_20:
# 454 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_HIDEKI_WHITE_DEFEATED
	goto SaffronCity_Dojo_EventScript_HidekiWon_1


SaffronCity_Dojo_EventScript_Aaron::
# 475 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 476 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 477 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_AaronIntro, MSGBOX_YESNO
# 478 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_Aaron_2
# 484 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 485 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 486 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Aaron_5
# 490 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 491 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Aaron_12
# 491 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Aaron_12
# 494 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Aaron_20
# 497 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
SaffronCity_Dojo_EventScript_Aaron_4:
# 501 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Aaron_9
# 505 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Aaron_17
# 511 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Aaron_26
# 517 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Aaron_33
SaffronCity_Dojo_EventScript_Aaron_32:
# 520 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_AARON_WHITE, SaffronCity_Dojo_Text_AaronIntroBattle, SaffronCity_Dojo_Text_AaronDefeat, SaffronCity_Dojo_EventScript_AaronWon
SaffronCity_Dojo_EventScript_Aaron_8:
# 526 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 527 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron_2:
# 479 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ComeBackWhenReady
# 480 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
# 481 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_Aaron_5:
# 487 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 488 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto SaffronCity_Dojo_EventScript_Aaron_4

SaffronCity_Dojo_EventScript_Aaron_9:
# 502 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_AARON_BLACK
# 503 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_AARON_BLACK, SaffronCity_Dojo_Text_AaronIntroBattle, SaffronCity_Dojo_Text_AaronDefeat, SaffronCity_Dojo_EventScript_AaronWon
	goto SaffronCity_Dojo_EventScript_Aaron_8

SaffronCity_Dojo_EventScript_Aaron_12:
# 492 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto SaffronCity_Dojo_EventScript_Aaron_4

SaffronCity_Dojo_EventScript_Aaron_17:
# 506 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Aaron_24
SaffronCity_Dojo_EventScript_Aaron_23:
# 509 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_AARON_BLACK, SaffronCity_Dojo_Text_AaronIntroBattle, SaffronCity_Dojo_Text_AaronDefeat, SaffronCity_Dojo_EventScript_AaronWon
	goto SaffronCity_Dojo_EventScript_Aaron_8

SaffronCity_Dojo_EventScript_Aaron_20:
# 495 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto SaffronCity_Dojo_EventScript_Aaron_4

SaffronCity_Dojo_EventScript_Aaron_24:
# 507 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_AARON_BLACK
	goto SaffronCity_Dojo_EventScript_Aaron_23

SaffronCity_Dojo_EventScript_Aaron_26:
# 512 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Aaron_30
SaffronCity_Dojo_EventScript_Aaron_29:
# 515 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_AARON_BLUE, SaffronCity_Dojo_Text_AaronIntroBattle, SaffronCity_Dojo_Text_AaronDefeat, SaffronCity_Dojo_EventScript_AaronWon
	goto SaffronCity_Dojo_EventScript_Aaron_8

SaffronCity_Dojo_EventScript_Aaron_30:
# 513 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_AARON_BLUE
	goto SaffronCity_Dojo_EventScript_Aaron_29

SaffronCity_Dojo_EventScript_Aaron_33:
# 518 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_AARON_WHITE
	goto SaffronCity_Dojo_EventScript_Aaron_32


SaffronCity_Dojo_EventScript_AaronWon::
# 532 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_AaronWon_2
# 536 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_AaronWon_8
# 544 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_AaronWon_14
# 551 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_AaronWon_20
# 554 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_AARON_WHITE
SaffronCity_Dojo_EventScript_AaronWon_1:
# 559 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_AaronWon_6
SaffronCity_Dojo_EventScript_AaronWon_5:
# 562 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 563 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
# 564 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_AaronWon_2:
# 533 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_AARON_DONE
# 534 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckGauntletComplete
	goto SaffronCity_Dojo_EventScript_AaronWon_1

SaffronCity_Dojo_EventScript_AaronWon_6:
# 560 "data/maps/SaffronCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto SaffronCity_Dojo_EventScript_AaronWon_5

SaffronCity_Dojo_EventScript_AaronWon_8:
# 537 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_AaronWon_11
# 540 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AARON_BLACK_DEFEATED
# 541 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete
	goto SaffronCity_Dojo_EventScript_AaronWon_1

SaffronCity_Dojo_EventScript_AaronWon_11:
# 538 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_AARON_BLACK
	goto SaffronCity_Dojo_EventScript_AaronWon_1

SaffronCity_Dojo_EventScript_AaronWon_14:
# 545 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_AaronWon_17
# 548 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_AARON_BLUE
	goto SaffronCity_Dojo_EventScript_AaronWon_1

SaffronCity_Dojo_EventScript_AaronWon_17:
# 546 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AARON_BLUE_DEFEATED
	goto SaffronCity_Dojo_EventScript_AaronWon_1

SaffronCity_Dojo_EventScript_AaronWon_20:
# 552 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AARON_WHITE_DEFEATED
	goto SaffronCity_Dojo_EventScript_AaronWon_1


SaffronCity_Dojo_EventScript_Mike::
# 573 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 574 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 575 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MikeIntro, MSGBOX_YESNO
# 576 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_Mike_2
# 582 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 583 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 584 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Mike_5
# 588 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 589 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Mike_12
# 589 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Mike_12
# 592 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Mike_20
# 595 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
SaffronCity_Dojo_EventScript_Mike_4:
# 599 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_Mike_9
# 603 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_Mike_17
# 609 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_Mike_26
# 615 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Mike_33
SaffronCity_Dojo_EventScript_Mike_32:
# 618 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_MIKE_WHITE, SaffronCity_Dojo_Text_MikeIntroBattle, SaffronCity_Dojo_Text_MikeDefeat, SaffronCity_Dojo_EventScript_MikeWon
SaffronCity_Dojo_EventScript_Mike_8:
# 624 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 625 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike_2:
# 577 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ComeBackWhenReady
# 578 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
# 579 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_Mike_5:
# 585 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 586 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto SaffronCity_Dojo_EventScript_Mike_4

SaffronCity_Dojo_EventScript_Mike_9:
# 600 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_MIKE_BLACK
# 601 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_MIKE_BLACK, SaffronCity_Dojo_Text_MikeIntroBattle, SaffronCity_Dojo_Text_MikeDefeat, SaffronCity_Dojo_EventScript_MikeWon
	goto SaffronCity_Dojo_EventScript_Mike_8

SaffronCity_Dojo_EventScript_Mike_12:
# 590 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto SaffronCity_Dojo_EventScript_Mike_4

SaffronCity_Dojo_EventScript_Mike_17:
# 604 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Mike_24
SaffronCity_Dojo_EventScript_Mike_23:
# 607 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_MIKE_BLACK, SaffronCity_Dojo_Text_MikeIntroBattle, SaffronCity_Dojo_Text_MikeDefeat, SaffronCity_Dojo_EventScript_MikeWon
	goto SaffronCity_Dojo_EventScript_Mike_8

SaffronCity_Dojo_EventScript_Mike_20:
# 593 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto SaffronCity_Dojo_EventScript_Mike_4

SaffronCity_Dojo_EventScript_Mike_24:
# 605 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_MIKE_BLACK
	goto SaffronCity_Dojo_EventScript_Mike_23

SaffronCity_Dojo_EventScript_Mike_26:
# 610 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_Mike_30
SaffronCity_Dojo_EventScript_Mike_29:
# 613 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_MIKE_BLUE, SaffronCity_Dojo_Text_MikeIntroBattle, SaffronCity_Dojo_Text_MikeDefeat, SaffronCity_Dojo_EventScript_MikeWon
	goto SaffronCity_Dojo_EventScript_Mike_8

SaffronCity_Dojo_EventScript_Mike_30:
# 611 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_MIKE_BLUE
	goto SaffronCity_Dojo_EventScript_Mike_29

SaffronCity_Dojo_EventScript_Mike_33:
# 616 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_MIKE_WHITE
	goto SaffronCity_Dojo_EventScript_Mike_32


SaffronCity_Dojo_EventScript_MikeWon::
# 630 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_MikeWon_2
# 634 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_MikeWon_8
# 642 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_MikeWon_14
# 649 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MikeWon_20
# 652 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_MIKE_WHITE
SaffronCity_Dojo_EventScript_MikeWon_1:
# 657 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MikeWon_6
SaffronCity_Dojo_EventScript_MikeWon_5:
# 660 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 661 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 662 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_MikeWon_2:
# 631 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_MIKE_DONE
# 632 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckGauntletComplete
	goto SaffronCity_Dojo_EventScript_MikeWon_1

SaffronCity_Dojo_EventScript_MikeWon_6:
# 658 "data/maps/SaffronCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto SaffronCity_Dojo_EventScript_MikeWon_5

SaffronCity_Dojo_EventScript_MikeWon_8:
# 635 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MikeWon_11
# 638 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_MIKE_BLACK_DEFEATED
# 639 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete
	goto SaffronCity_Dojo_EventScript_MikeWon_1

SaffronCity_Dojo_EventScript_MikeWon_11:
# 636 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_MIKE_BLACK
	goto SaffronCity_Dojo_EventScript_MikeWon_1

SaffronCity_Dojo_EventScript_MikeWon_14:
# 643 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MikeWon_17
# 646 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_MIKE_BLUE
	goto SaffronCity_Dojo_EventScript_MikeWon_1

SaffronCity_Dojo_EventScript_MikeWon_17:
# 644 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_MIKE_BLUE_DEFEATED
	goto SaffronCity_Dojo_EventScript_MikeWon_1

SaffronCity_Dojo_EventScript_MikeWon_20:
# 650 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_MIKE_WHITE_DEFEATED
	goto SaffronCity_Dojo_EventScript_MikeWon_1


SaffronCity_Dojo_EventScript_MasterKoichi::
# 674 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 675 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 676 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MasterKoichiIntro, MSGBOX_YESNO
# 677 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_MasterKoichi_2
# 683 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 684 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 685 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MasterKoichi_5
# 689 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 690 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_MasterKoichi_12
# 690 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_MasterKoichi_12
# 693 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_MasterKoichi_20
# 696 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
SaffronCity_Dojo_EventScript_MasterKoichi_4:
# 700 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_MasterKoichi_9
# 704 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_MasterKoichi_17
# 710 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_MasterKoichi_26
# 716 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MasterKoichi_33
SaffronCity_Dojo_EventScript_MasterKoichi_32:
# 719 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI_WHITE, SaffronCity_Dojo_Text_MasterKoichiIntroBattle, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
SaffronCity_Dojo_EventScript_MasterKoichi_8:
# 725 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 726 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_MasterKoichiPostBattle
	end

SaffronCity_Dojo_EventScript_MasterKoichi_2:
# 678 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ComeBackWhenReady
# 679 "data/maps/SaffronCity_Dojo/scripts.pory"
	closemessage
# 680 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_MasterKoichi_5:
# 686 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 687 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto SaffronCity_Dojo_EventScript_MasterKoichi_4

SaffronCity_Dojo_EventScript_MasterKoichi_9:
# 701 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI_BLACK
# 702 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI_BLACK, SaffronCity_Dojo_Text_MasterKoichiIntroBattle, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto SaffronCity_Dojo_EventScript_MasterKoichi_8

SaffronCity_Dojo_EventScript_MasterKoichi_12:
# 691 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto SaffronCity_Dojo_EventScript_MasterKoichi_4

SaffronCity_Dojo_EventScript_MasterKoichi_17:
# 705 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MasterKoichi_24
SaffronCity_Dojo_EventScript_MasterKoichi_23:
# 708 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI_BLACK, SaffronCity_Dojo_Text_MasterKoichiIntroBattle, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto SaffronCity_Dojo_EventScript_MasterKoichi_8

SaffronCity_Dojo_EventScript_MasterKoichi_20:
# 694 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto SaffronCity_Dojo_EventScript_MasterKoichi_4

SaffronCity_Dojo_EventScript_MasterKoichi_24:
# 706 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI_BLACK
	goto SaffronCity_Dojo_EventScript_MasterKoichi_23

SaffronCity_Dojo_EventScript_MasterKoichi_26:
# 711 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_MasterKoichi_30
SaffronCity_Dojo_EventScript_MasterKoichi_29:
# 714 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI_BLUE, SaffronCity_Dojo_Text_MasterKoichiIntroBattle, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto SaffronCity_Dojo_EventScript_MasterKoichi_8

SaffronCity_Dojo_EventScript_MasterKoichi_30:
# 712 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI_BLUE
	goto SaffronCity_Dojo_EventScript_MasterKoichi_29

SaffronCity_Dojo_EventScript_MasterKoichi_33:
# 717 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI_WHITE
	goto SaffronCity_Dojo_EventScript_MasterKoichi_32


SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
# 731 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_2
# 735 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_8
# 743 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_14
# 750 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_20
# 753 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI_WHITE
SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_1:
# 758 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_6
SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_5:
# 761 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 762 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_PostBattleCleanup
# 763 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_MasterKoichiPostBattle
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_2:
# 732 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_KOICHI_DONE
# 733 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckGauntletComplete
	goto SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_1

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_6:
# 759 "data/maps/SaffronCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_5

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_8:
# 736 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_11
# 739 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_KOICHI_BLACK_DEFEATED
# 740 "data/maps/SaffronCity_Dojo/scripts.pory"
	call SaffronCity_Dojo_EventScript_CheckSpeedDojoComplete
	goto SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_1

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_11:
# 737 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI_BLACK
	goto SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_1

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_14:
# 744 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_17
# 747 "data/maps/SaffronCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_KOICHI_BLUE
	goto SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_1

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_17:
# 745 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_KOICHI_BLUE_DEFEATED
	goto SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_1

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_20:
# 751 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_KOICHI_WHITE_DEFEATED
	goto SaffronCity_Dojo_EventScript_DefeatedMasterKoichi_1


SaffronCity_Dojo_EventScript_MasterKoichiPostBattle::
# 772 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiPostBattle_2
# 777 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
# 778 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_MasterKoichiPostBattle_2:
# 773 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
# 774 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_HitmonleeBall::
# 783 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 784 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 785 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_HitmonleeBall_2
SaffronCity_Dojo_EventScript_HitmonleeBall_1:
# 788 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONLEE, 10, 3
# 789 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
# 790 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
# 791 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 792 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 793 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
# 794 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 795 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_HitmonleeBall_5
SaffronCity_Dojo_EventScript_HitmonleeBall_4:
# 798 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 799 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HitmonleeBall_2:
# 786 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_HitmonleeBall_1

SaffronCity_Dojo_EventScript_HitmonleeBall_5:
# 796 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_GiveHitmon
	goto SaffronCity_Dojo_EventScript_HitmonleeBall_4


SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
# 804 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
# 805 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_HitmonchanBall::
# 810 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 811 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 812 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_HitmonchanBall_2
SaffronCity_Dojo_EventScript_HitmonchanBall_1:
# 815 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONCHAN, 10, 3
# 816 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
# 817 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
# 818 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 819 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 820 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
# 821 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 822 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_HitmonchanBall_5
SaffronCity_Dojo_EventScript_HitmonchanBall_4:
# 825 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 826 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall_2:
# 813 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_HitmonchanBall_1

SaffronCity_Dojo_EventScript_HitmonchanBall_5:
# 823 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_GiveHitmon
	goto SaffronCity_Dojo_EventScript_HitmonchanBall_4


SaffronCity_Dojo_EventScript_GiveHitmon::
# 831 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 832 "data/maps/SaffronCity_Dojo/scripts.pory"
	givemon VAR_TEMP_1, 25
# 833 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_2
SaffronCity_Dojo_EventScript_GiveHitmon_1:
# 836 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_5
SaffronCity_Dojo_EventScript_GiveHitmon_4:
# 839 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_8
SaffronCity_Dojo_EventScript_GiveHitmon_7:
# 842 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon_2:
# 834 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto SaffronCity_Dojo_EventScript_GiveHitmon_1

SaffronCity_Dojo_EventScript_GiveHitmon_5:
# 837 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto SaffronCity_Dojo_EventScript_GiveHitmon_4

SaffronCity_Dojo_EventScript_GiveHitmon_8:
# 840 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto EventScript_NoMoreRoomForPokemon
	goto SaffronCity_Dojo_EventScript_GiveHitmon_7


SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
# 847 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 848 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 849 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 850 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 851 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 852 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 853 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 854 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 855 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonParty_2
SaffronCity_Dojo_EventScript_ReceivedHitmonParty_1:
# 858 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 859 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_ChangePokemonNickname
# 860 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty_2:
# 856 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonParty_1


SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
# 865 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 866 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 867 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 868 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 869 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 870 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 871 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 872 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 873 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonPC_2
SaffronCity_Dojo_EventScript_ReceivedHitmonPC_1:
# 876 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 877 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC_2:
# 874 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonPC_1


SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
# 882 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_TransferredToPC
# 883 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end


SaffronCity_Dojo_EventScript_EndGiveMon::
# 888 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_Statue::
# 893 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_LeftScroll::
# 898 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_RightScroll::
# 903 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end


SaffronCity_Dojo_OnFrame_Text_0:
# 84 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "SPEED DOJO CHALLENGE$"

SaffronCity_Dojo_Text_ChallengeGuyIntro::
# 911 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Welcome to the Speed Dojo!\p"
	.string "Pick your challenge.\p"
	.string "TRAINING matches whatever belt\n"
	.string "you've earned, scaled to your\l"
	.string "level. It won't count toward\n"
	.string "unlocking the next belt.$"

SaffronCity_Dojo_Text_ChallengeTrainingSet::
# 920 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Training mode selected.\n"
	.string "Opponents will match your level.$"

SaffronCity_Dojo_Text_ChallengeWhiteSet::
# 925 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "White Belt challenge selected.\n"
	.string "Go find your opponents.$"

SaffronCity_Dojo_Text_ChallengeBlueSet::
# 930 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Blue Belt challenge selected.\n"
	.string "Go find your opponents.$"

SaffronCity_Dojo_Text_ChallengeBlueLocked::
# 935 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Clear White Belt against all\n"
	.string "five of us before you try Blue.$"

SaffronCity_Dojo_Text_ChallengeBlackSet::
# 940 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Black Belt challenge selected.\n"
	.string "Go find your opponents.$"

SaffronCity_Dojo_Text_ChallengeBlackLocked::
# 945 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Clear Blue Belt against all\n"
	.string "five of us before you try Black.$"

SaffronCity_Dojo_Text_ChallengeGuyIntroGauntlet::
# 950 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Welcome to the Speed Dojo!\p"
	.string "Pick your challenge.\p"
	.string "TRAINING matches whatever belt\n"
	.string "you've earned, scaled to your\l"
	.string "level. It won't count toward\n"
	.string "unlocking the next belt.\p"
	.string "Since you've beaten all of us\n"
	.string "at Black Belt... there's one\l"
	.string "more thing.\p"
	.string "The GAUNTLET. All five of us,\n"
	.string "back to back. No leaving to\l"
	.string "heal. No second chances.$"

SaffronCity_Dojo_Text_ChallengeGauntletSet::
# 965 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Gauntlet selected.\n"
	.string "Don't leave until it's done.$"

SaffronCity_Dojo_Text_GauntletCleared::
# 970 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "...\p"
	.string "All five of us, back to back,\n"
	.string "and you never once walked out\l"
	.string "that door.\p"
	.string "That's the Gauntlet.\n"
	.string "You've earned it.$"

SaffronCity_Dojo_Text_ComeBackWhenReady::
# 979 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Come back when you're ready.$"

SaffronCity_Dojo_Text_MasterKoichiIntro::
# 983 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Grunt!\p"
	.string "I am the KARATE MASTER!\n"
	.string "I am the LEADER here!\p"
	.string "You wish to challenge us?\n"
	.string "Expect no mercy!\p"
	.string "Fwaaa! Are you ready?$"

SaffronCity_Dojo_Text_MasterKoichiIntroBattle::
# 992 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Fwaaa!$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
# 996 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hwa!\n"
	.string "Arrgh! Beaten!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
# 1001 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Indeed, I have lost!\p"
	.string "But, I beseech you, do not take\n"
	.string "our emblem as your trophy!\p"
	.string "In return, I will give you a prized\n"
	.string "FIGHTING POKéMON!\p"
	.string "Choose whichever one you like!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
# 1010 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Grunt!\n"
	.string "Stay and train at karate with us!$"

SaffronCity_Dojo_Text_MikeIntro::
# 1015 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hoargh!\n"
	.string "Take your shoes off! Are you\l"
	.string "ready?$"

SaffronCity_Dojo_Text_MikeIntroBattle::
# 1021 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hoargh!$"

SaffronCity_Dojo_Text_MikeDefeat::
# 1025 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "I give up!$"

SaffronCity_Dojo_Text_MikePostBattle::
# 1029 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You wait 'til you see our MASTER!\n"
	.string "I'm a small fry compared to him!$"

SaffronCity_Dojo_Text_HidekiIntro::
# 1034 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "I hear you're good!\n"
	.string "Show me! Are you ready?$"

SaffronCity_Dojo_Text_HidekiIntroBattle::
# 1039 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Show me!$"

SaffronCity_Dojo_Text_HidekiDefeat::
# 1043 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Judge!\n"
	.string "One point!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
# 1048 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Our MASTER is a pro fighter.\n"
	.string "Be prepared to lose!$"

SaffronCity_Dojo_Text_AaronIntro::
# 1053 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hiyah!\n"
	.string "Blink and you'll miss it!\p"
	.string "Are you ready?$"

SaffronCity_Dojo_Text_AaronIntroBattle::
# 1059 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hiyah!$"

SaffronCity_Dojo_Text_AaronDefeat::
# 1063 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Yow!\n"
	.string "Stubbed fingers!$"

SaffronCity_Dojo_Text_AaronPostBattle::
# 1068 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "The only thing that frightens us is\n"
	.string "psychic power!$"

SaffronCity_Dojo_Text_HitoshiIntro::
# 1073 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hwaah!\p"
	.string "You're trespassing in our\n"
	.string "FIGHTING DOJO! Are you ready?$"

SaffronCity_Dojo_Text_HitoshiIntroBattle::
# 1079 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hwaah!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
# 1083 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Oof!\n"
	.string "I give up!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
# 1088 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "The prime fighters across the land\n"
	.string "train here.$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
# 1093 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You want the hard-kicking\n"
	.string "HITMONLEE?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
# 1098 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from the KARATE MASTER.$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
# 1103 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You want the piston-punching\n"
	.string "HITMONCHAN?$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
# 1108 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Better not get greedy…$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
# 1112 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Enemies on every side!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
# 1116 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "What goes around comes around.$"

SaffronCity_Dojo_Text_FightingDojo::
# 1120 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "FIGHTING DOJO$"
