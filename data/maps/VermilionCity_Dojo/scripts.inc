VermilionCity_Dojo_MapScripts::
# 22 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Dojo_OnTransition
# 23 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

VermilionCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 24 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, VermilionCity_Dojo_OnFrame
	.2byte 0


VermilionCity_Dojo_OnTransition::
# 46 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 47 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 48 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_RYU_DONE
# 49 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_YUKI_DONE
# 50 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_JIN_DONE
# 51 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_AKIO_DONE
# 52 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 0
	end


VermilionCity_Dojo_OnFrame::
# 66 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_TEMP_0, 1
# 67 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_SEEN_DOJO_INTRO, VermilionCity_Dojo_OnFrame_2
VermilionCity_Dojo_OnFrame_1:
# 70 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_QUEST_ATTACK_DOJO_ACTIVE, VermilionCity_Dojo_OnFrame_5
VermilionCity_Dojo_OnFrame_4:
	end

VermilionCity_Dojo_OnFrame_2:
# 68 "data/maps/VermilionCity_Dojo/scripts.pory"
	call Common_EventScript_DojoIntro
	goto VermilionCity_Dojo_OnFrame_1

VermilionCity_Dojo_OnFrame_5:
# 71 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_QUEST_ATTACK_DOJO_ACTIVE
# 72 "data/maps/VermilionCity_Dojo/scripts.pory"
	quest_start_toast VermilionCity_Dojo_OnFrame_Text_0
	goto VermilionCity_Dojo_OnFrame_4


VermilionCity_Dojo_EventScript_ChallengeGuy::
# 82 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 83 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 86 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_RYU_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeGuy_5
VermilionCity_Dojo_EventScript_ChallengeGuy_3:
# 99 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeGuyIntro, MSGBOX_DEFAULT
# 100 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 101 "data/maps/VermilionCity_Dojo/scripts.pory"
	multichoice 0, 0, MULTI_DOJO_CHALLENGE, FALSE
VermilionCity_Dojo_EventScript_ChallengeGuy_1:
# 103 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_12
# 107 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_18
# 111 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_23
# 115 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_26
# 119 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_2:
# 87 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeGuyIntroGauntlet, MSGBOX_DEFAULT
# 88 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 89 "data/maps/VermilionCity_Dojo/scripts.pory"
	multichoice 0, 0, MULTI_DOJO_CHALLENGE_GAUNTLET, FALSE
# 90 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_15
# 94 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_20
	goto VermilionCity_Dojo_EventScript_ChallengeGuy_1

VermilionCity_Dojo_EventScript_ChallengeGuy_4:
# 86 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_JIN_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeGuy_8
	goto VermilionCity_Dojo_EventScript_ChallengeGuy_3

VermilionCity_Dojo_EventScript_ChallengeGuy_5:
# 86 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_YUKI_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeGuy_4
	goto VermilionCity_Dojo_EventScript_ChallengeGuy_3

VermilionCity_Dojo_EventScript_ChallengeGuy_8:
# 86 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeGuy_2
	goto VermilionCity_Dojo_EventScript_ChallengeGuy_3

VermilionCity_Dojo_EventScript_ChallengeGuy_12:
# 104 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeTraining
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_15:
# 91 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeGauntlet
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_18:
# 108 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeWhite
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_20:
# 95 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_23:
# 112 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeBlue
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_26:
# 116 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeBlack
	end


VermilionCity_Dojo_EventScript_ChallengeTraining::
# 124 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_TRAINING_MODE
# 125 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 1
# 126 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_RYU_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_4
VermilionCity_Dojo_EventScript_ChallengeTraining_1:
# 129 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_RYU_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_13
VermilionCity_Dojo_EventScript_ChallengeTraining_10:
# 132 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeTrainingSet, MSGBOX_AUTOCLOSE
# 133 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeTraining_2:
# 127 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 2
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_3:
# 126 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_JIN_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_7
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_4:
# 126 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_YUKI_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_3
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_7:
# 126 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_2
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_11:
# 130 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 3
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10

VermilionCity_Dojo_EventScript_ChallengeTraining_12:
# 129 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_JIN_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_16
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10

VermilionCity_Dojo_EventScript_ChallengeTraining_13:
# 129 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_YUKI_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_12
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10

VermilionCity_Dojo_EventScript_ChallengeTraining_16:
# 129 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_11
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10


VermilionCity_Dojo_EventScript_ChallengeWhite::
# 138 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 139 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 1
# 140 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeWhiteSet, MSGBOX_AUTOCLOSE
# 141 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_ChallengeBlue::
# 146 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_RYU_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 146 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_YUKI_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 146 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_JIN_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 146 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AKIO_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 151 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 152 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 2
# 153 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlueSet, MSGBOX_AUTOCLOSE
# 154 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeBlue_2:
# 147 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlueLocked, MSGBOX_AUTOCLOSE
# 148 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_ChallengeBlack::
# 159 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_RYU_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 159 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_YUKI_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 159 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_JIN_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 159 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AKIO_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 164 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 165 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 3
# 166 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlackSet, MSGBOX_AUTOCLOSE
# 167 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeBlack_2:
# 160 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlackLocked, MSGBOX_AUTOCLOSE
# 161 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_ChallengeGauntlet::
# 176 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 177 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 4
# 178 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_RYU_DONE
# 179 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_YUKI_DONE
# 180 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_JIN_DONE
# 181 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_GAUNTLET_AKIO_DONE
# 182 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeGauntletSet, MSGBOX_AUTOCLOSE
# 183 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_CheckGauntletComplete::
# 192 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_CLEARED, VermilionCity_Dojo_EventScript_CheckGauntletComplete_2
# 195 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_RYU_DONE, VermilionCity_Dojo_EventScript_CheckGauntletComplete_7
VermilionCity_Dojo_EventScript_CheckGauntletComplete_4:
	return

VermilionCity_Dojo_EventScript_CheckGauntletComplete_2:
	return

VermilionCity_Dojo_EventScript_CheckGauntletComplete_5:
# 196 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_CLEARED
# 197 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_GauntletCleared, MSGBOX_DEFAULT
# 198 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
	goto VermilionCity_Dojo_EventScript_CheckGauntletComplete_4

VermilionCity_Dojo_EventScript_CheckGauntletComplete_6:
# 195 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_JIN_DONE, VermilionCity_Dojo_EventScript_CheckGauntletComplete_10
	goto VermilionCity_Dojo_EventScript_CheckGauntletComplete_4

VermilionCity_Dojo_EventScript_CheckGauntletComplete_7:
# 195 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_YUKI_DONE, VermilionCity_Dojo_EventScript_CheckGauntletComplete_6
	goto VermilionCity_Dojo_EventScript_CheckGauntletComplete_4

VermilionCity_Dojo_EventScript_CheckGauntletComplete_10:
# 195 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_GAUNTLET_AKIO_DONE, VermilionCity_Dojo_EventScript_CheckGauntletComplete_5
	goto VermilionCity_Dojo_EventScript_CheckGauntletComplete_4


VermilionCity_Dojo_EventScript_CheckAttackDojoComplete::
# 211 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_QUEST_ATTACK_DOJO_COMPLETED, VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_2
# 214 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_RYU_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_7
VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_4:
	return

VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_2:
	return

VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_5:
# 215 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_QUEST_ATTACK_DOJO_COMPLETED
# 216 "data/maps/VermilionCity_Dojo/scripts.pory"
	quest_complete_toast VermilionCity_Dojo_OnFrame_Text_0
	goto VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_4

VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_6:
# 214 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_JIN_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_10
	goto VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_4

VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_7:
# 214 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_YUKI_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_6
	goto VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_4

VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_10:
# 214 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_BLACK_DEFEATED, VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_5
	goto VermilionCity_Dojo_EventScript_CheckAttackDojoComplete_4


VermilionCity_Dojo_EventScript_PostBattleCleanup::
# 230 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 231 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 232 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_PREVIEW_BATTLE
# 233 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 0
	return


VermilionCity_Dojo_EventScript_Ryu::
# 242 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 243 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 244 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 245 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_2
# 251 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 252 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 253 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Ryu_5
# 257 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 258 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_12
# 258 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_12
# 261 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_20
# 264 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
VermilionCity_Dojo_EventScript_Ryu_4:
# 268 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_9
# 274 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_17
# 283 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_26
# 289 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Ryu_33
VermilionCity_Dojo_EventScript_Ryu_32:
# 292 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU_WHITE, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat, VermilionCity_Dojo_EventScript_RyuWon
VermilionCity_Dojo_EventScript_Ryu_8:
# 298 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 299 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_RyuPost, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Ryu_2:
# 246 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 247 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 248 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Ryu_5:
# 254 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 255 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Ryu_4

VermilionCity_Dojo_EventScript_Ryu_9:
# 271 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_BLACK
# 272 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU_BLACK, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat, VermilionCity_Dojo_EventScript_RyuWon
	goto VermilionCity_Dojo_EventScript_Ryu_8

VermilionCity_Dojo_EventScript_Ryu_12:
# 259 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto VermilionCity_Dojo_EventScript_Ryu_4

VermilionCity_Dojo_EventScript_Ryu_17:
# 278 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Ryu_24
VermilionCity_Dojo_EventScript_Ryu_23:
# 281 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU_BLACK, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat, VermilionCity_Dojo_EventScript_RyuWon
	goto VermilionCity_Dojo_EventScript_Ryu_8

VermilionCity_Dojo_EventScript_Ryu_20:
# 262 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto VermilionCity_Dojo_EventScript_Ryu_4

VermilionCity_Dojo_EventScript_Ryu_24:
# 279 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_BLACK
	goto VermilionCity_Dojo_EventScript_Ryu_23

VermilionCity_Dojo_EventScript_Ryu_26:
# 284 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Ryu_30
VermilionCity_Dojo_EventScript_Ryu_29:
# 287 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU_BLUE, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat, VermilionCity_Dojo_EventScript_RyuWon
	goto VermilionCity_Dojo_EventScript_Ryu_8

VermilionCity_Dojo_EventScript_Ryu_30:
# 285 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_BLUE
	goto VermilionCity_Dojo_EventScript_Ryu_29

VermilionCity_Dojo_EventScript_Ryu_33:
# 290 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_WHITE
	goto VermilionCity_Dojo_EventScript_Ryu_32


VermilionCity_Dojo_EventScript_RyuWon::
# 308 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_RyuWon_2
# 312 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_RyuWon_8
# 320 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_RyuWon_14
# 327 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_RyuWon_20
# 330 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_WHITE
VermilionCity_Dojo_EventScript_RyuWon_1:
# 338 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_RyuWon_6
VermilionCity_Dojo_EventScript_RyuWon_5:
# 341 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 342 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_RyuPost, MSGBOX_AUTOCLOSE
# 343 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_RyuWon_2:
# 309 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_RYU_DONE
# 310 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckGauntletComplete
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_6:
# 339 "data/maps/VermilionCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto VermilionCity_Dojo_EventScript_RyuWon_5

VermilionCity_Dojo_EventScript_RyuWon_8:
# 313 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_RyuWon_11
# 316 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_RYU_BLACK_DEFEATED
# 317 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckAttackDojoComplete
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_11:
# 314 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_BLACK
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_14:
# 321 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_RyuWon_17
# 324 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_BLUE
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_17:
# 322 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_RYU_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_20:
# 328 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_RYU_WHITE_DEFEATED
	goto VermilionCity_Dojo_EventScript_RyuWon_1


VermilionCity_Dojo_EventScript_Yuki::
# 352 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 353 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 354 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 355 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_2
# 361 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 362 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 363 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Yuki_5
# 367 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 368 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_12
# 368 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_12
# 371 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_20
# 374 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
VermilionCity_Dojo_EventScript_Yuki_4:
# 378 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_9
# 382 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_17
# 388 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_26
# 394 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Yuki_33
VermilionCity_Dojo_EventScript_Yuki_32:
# 397 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO_WHITE, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat, VermilionCity_Dojo_EventScript_YukiWon
VermilionCity_Dojo_EventScript_Yuki_8:
# 403 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 404 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_YukiPost, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Yuki_2:
# 356 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 357 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 358 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Yuki_5:
# 364 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 365 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Yuki_4

VermilionCity_Dojo_EventScript_Yuki_9:
# 379 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_BLACK
# 380 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO_BLACK, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat, VermilionCity_Dojo_EventScript_YukiWon
	goto VermilionCity_Dojo_EventScript_Yuki_8

VermilionCity_Dojo_EventScript_Yuki_12:
# 369 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto VermilionCity_Dojo_EventScript_Yuki_4

VermilionCity_Dojo_EventScript_Yuki_17:
# 383 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Yuki_24
VermilionCity_Dojo_EventScript_Yuki_23:
# 386 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO_BLACK, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat, VermilionCity_Dojo_EventScript_YukiWon
	goto VermilionCity_Dojo_EventScript_Yuki_8

VermilionCity_Dojo_EventScript_Yuki_20:
# 372 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto VermilionCity_Dojo_EventScript_Yuki_4

VermilionCity_Dojo_EventScript_Yuki_24:
# 384 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_BLACK
	goto VermilionCity_Dojo_EventScript_Yuki_23

VermilionCity_Dojo_EventScript_Yuki_26:
# 389 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Yuki_30
VermilionCity_Dojo_EventScript_Yuki_29:
# 392 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO_BLUE, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat, VermilionCity_Dojo_EventScript_YukiWon
	goto VermilionCity_Dojo_EventScript_Yuki_8

VermilionCity_Dojo_EventScript_Yuki_30:
# 390 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_BLUE
	goto VermilionCity_Dojo_EventScript_Yuki_29

VermilionCity_Dojo_EventScript_Yuki_33:
# 395 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_WHITE
	goto VermilionCity_Dojo_EventScript_Yuki_32


VermilionCity_Dojo_EventScript_YukiWon::
# 409 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_YukiWon_2
# 413 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_YukiWon_8
# 421 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_YukiWon_14
# 428 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_YukiWon_20
# 431 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_WHITE
VermilionCity_Dojo_EventScript_YukiWon_1:
# 439 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_YukiWon_6
VermilionCity_Dojo_EventScript_YukiWon_5:
# 442 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 443 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_YukiPost, MSGBOX_AUTOCLOSE
# 444 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_YukiWon_2:
# 410 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_YUKI_DONE
# 411 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckGauntletComplete
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_6:
# 440 "data/maps/VermilionCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto VermilionCity_Dojo_EventScript_YukiWon_5

VermilionCity_Dojo_EventScript_YukiWon_8:
# 414 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_YukiWon_11
# 417 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_YUKI_BLACK_DEFEATED
# 418 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckAttackDojoComplete
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_11:
# 415 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_BLACK
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_14:
# 422 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_YukiWon_17
# 425 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_BLUE
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_17:
# 423 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_YUKI_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_20:
# 429 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_YUKI_WHITE_DEFEATED
	goto VermilionCity_Dojo_EventScript_YukiWon_1


VermilionCity_Dojo_EventScript_Jin::
# 453 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 454 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 455 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 456 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_2
# 462 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 463 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 464 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Jin_5
# 468 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 469 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_12
# 469 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_12
# 472 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_20
# 475 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
VermilionCity_Dojo_EventScript_Jin_4:
# 479 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_9
# 483 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_17
# 489 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_26
# 495 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Jin_33
VermilionCity_Dojo_EventScript_Jin_32:
# 498 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN_WHITE, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat, VermilionCity_Dojo_EventScript_JinWon
VermilionCity_Dojo_EventScript_Jin_8:
# 504 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 505 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_JinPost, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Jin_2:
# 457 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 458 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 459 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Jin_5:
# 465 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 466 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Jin_4

VermilionCity_Dojo_EventScript_Jin_9:
# 480 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_BLACK
# 481 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN_BLACK, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat, VermilionCity_Dojo_EventScript_JinWon
	goto VermilionCity_Dojo_EventScript_Jin_8

VermilionCity_Dojo_EventScript_Jin_12:
# 470 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto VermilionCity_Dojo_EventScript_Jin_4

VermilionCity_Dojo_EventScript_Jin_17:
# 484 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Jin_24
VermilionCity_Dojo_EventScript_Jin_23:
# 487 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN_BLACK, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat, VermilionCity_Dojo_EventScript_JinWon
	goto VermilionCity_Dojo_EventScript_Jin_8

VermilionCity_Dojo_EventScript_Jin_20:
# 473 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto VermilionCity_Dojo_EventScript_Jin_4

VermilionCity_Dojo_EventScript_Jin_24:
# 485 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_BLACK
	goto VermilionCity_Dojo_EventScript_Jin_23

VermilionCity_Dojo_EventScript_Jin_26:
# 490 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Jin_30
VermilionCity_Dojo_EventScript_Jin_29:
# 493 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN_BLUE, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat, VermilionCity_Dojo_EventScript_JinWon
	goto VermilionCity_Dojo_EventScript_Jin_8

VermilionCity_Dojo_EventScript_Jin_30:
# 491 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_BLUE
	goto VermilionCity_Dojo_EventScript_Jin_29

VermilionCity_Dojo_EventScript_Jin_33:
# 496 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_WHITE
	goto VermilionCity_Dojo_EventScript_Jin_32


VermilionCity_Dojo_EventScript_JinWon::
# 510 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_JinWon_2
# 514 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_JinWon_8
# 522 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_JinWon_14
# 529 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_JinWon_20
# 532 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_WHITE
VermilionCity_Dojo_EventScript_JinWon_1:
# 540 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_JinWon_6
VermilionCity_Dojo_EventScript_JinWon_5:
# 543 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 544 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_JinPost, MSGBOX_AUTOCLOSE
# 545 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_JinWon_2:
# 511 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_JIN_DONE
# 512 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckGauntletComplete
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_6:
# 541 "data/maps/VermilionCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto VermilionCity_Dojo_EventScript_JinWon_5

VermilionCity_Dojo_EventScript_JinWon_8:
# 515 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_JinWon_11
# 518 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_JIN_BLACK_DEFEATED
# 519 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckAttackDojoComplete
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_11:
# 516 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_BLACK
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_14:
# 523 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_JinWon_17
# 526 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_BLUE
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_17:
# 524 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_JIN_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_20:
# 530 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_JIN_WHITE_DEFEATED
	goto VermilionCity_Dojo_EventScript_JinWon_1


VermilionCity_Dojo_EventScript_Akio::
# 554 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 555 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 556 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 557 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_2
# 563 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 564 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 565 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Akio_5
# 569 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 570 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_12
# 570 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_12
# 573 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_20
# 576 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
VermilionCity_Dojo_EventScript_Akio_4:
# 580 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_9
# 584 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_17
# 590 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_26
# 596 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Akio_33
VermilionCity_Dojo_EventScript_Akio_32:
# 599 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO_WHITE, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioWon
VermilionCity_Dojo_EventScript_Akio_8:
# 605 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 606 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Akio_2:
# 558 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 559 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 560 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Akio_5:
# 566 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 567 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Akio_4

VermilionCity_Dojo_EventScript_Akio_9:
# 581 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_BLACK
# 582 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO_BLACK, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioWon
	goto VermilionCity_Dojo_EventScript_Akio_8

VermilionCity_Dojo_EventScript_Akio_12:
# 571 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
	goto VermilionCity_Dojo_EventScript_Akio_4

VermilionCity_Dojo_EventScript_Akio_17:
# 585 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Akio_24
VermilionCity_Dojo_EventScript_Akio_23:
# 588 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO_BLACK, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioWon
	goto VermilionCity_Dojo_EventScript_Akio_8

VermilionCity_Dojo_EventScript_Akio_20:
# 574 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 2
	goto VermilionCity_Dojo_EventScript_Akio_4

VermilionCity_Dojo_EventScript_Akio_24:
# 586 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_BLACK
	goto VermilionCity_Dojo_EventScript_Akio_23

VermilionCity_Dojo_EventScript_Akio_26:
# 591 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Akio_30
VermilionCity_Dojo_EventScript_Akio_29:
# 594 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO_BLUE, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioWon
	goto VermilionCity_Dojo_EventScript_Akio_8

VermilionCity_Dojo_EventScript_Akio_30:
# 592 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_BLUE
	goto VermilionCity_Dojo_EventScript_Akio_29

VermilionCity_Dojo_EventScript_Akio_33:
# 597 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_WHITE
	goto VermilionCity_Dojo_EventScript_Akio_32


VermilionCity_Dojo_EventScript_AkioWon::
# 615 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 4
	goto_if_eq VermilionCity_Dojo_EventScript_AkioWon_2
# 619 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_AkioWon_8
# 627 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_AkioWon_14
# 634 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_AkioWon_20
# 641 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_WHITE
VermilionCity_Dojo_EventScript_AkioWon_1:
# 649 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_AkioWon_6
VermilionCity_Dojo_EventScript_AkioWon_5:
# 652 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_PostBattleCleanup
# 653 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioPostBattle, MSGBOX_AUTOCLOSE
# 654 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_AkioWon_2:
# 616 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_GAUNTLET_AKIO_DONE
# 617 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckGauntletComplete
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_6:
# 650 "data/maps/VermilionCity_Dojo/scripts.pory"
	special HealPlayerParty
	goto VermilionCity_Dojo_EventScript_AkioWon_5

VermilionCity_Dojo_EventScript_AkioWon_8:
# 620 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_AkioWon_11
# 623 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_BLACK_DEFEATED
# 624 "data/maps/VermilionCity_Dojo/scripts.pory"
	call VermilionCity_Dojo_EventScript_CheckAttackDojoComplete
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_11:
# 621 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_BLACK
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_14:
# 628 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_AkioWon_17
# 631 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_BLUE
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_17:
# 629 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_20:
# 635 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_WHITE_DEFEATED
# 636 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AKIO_DEFEATED, VermilionCity_Dojo_EventScript_AkioWon_23
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_23:
# 637 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_DEFEATED
# 638 "data/maps/VermilionCity_Dojo/scripts.pory"
	giveitem ITEM_TM34, 1
	goto VermilionCity_Dojo_EventScript_AkioWon_1


VermilionCity_Dojo_EventScript_Machop::
# 663 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 664 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 665 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 666 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Machop, MSGBOX_DEFAULT
# 667 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 668 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Mankey::
# 673 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 674 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 675 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
# 676 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Mankey, MSGBOX_DEFAULT
# 677 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 678 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Hitmonchan::
# 683 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 684 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 685 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_HITMONCHAN, CRY_MODE_NORMAL
# 686 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Hitmonchan, MSGBOX_DEFAULT
# 687 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 688 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_TMTutor::
# 693 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto Common_EventScript_TMTutor
	return


VermilionCity_Dojo_EventScript_Plaque::
# 701 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Plaque, MSGBOX_SIGN
	end


VermilionCity_Dojo_EventScript_ScrollLeft::
# 706 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollLeft, MSGBOX_SIGN
	end


VermilionCity_Dojo_EventScript_ScrollRight::
# 711 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollRight, MSGBOX_SIGN
	end


VermilionCity_Dojo_OnFrame_Text_0:
# 72 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "ATTACK DOJO CHALLENGE$"

VermilionCity_Dojo_EventScript_Ryu_Text_0:
# 244 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Are you ready?$"

VermilionCity_Dojo_EventScript_Ryu_Text_1:
# 246 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Come back when you're ready.$"

VermilionCity_Dojo_Text_RyuIntro::
# 719 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Before you reach Sensei,\n"
	.string "you pass through me.\p"
	.string "Show me you belong here.$"

VermilionCity_Dojo_Text_RyuDefeat::
# 725 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You've got something in you.$"

VermilionCity_Dojo_Text_RyuPost::
# 729 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The next two fight differently.\n"
	.string "Pay attention to how they\l"
	.string "come at you.$"

VermilionCity_Dojo_Text_YukiIntro::
# 735 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "I always look before I commit.\p"
	.string "You'll see my whole team.\n"
	.string "I'll see yours.\p"
	.string "Then we decide.$"

VermilionCity_Dojo_Text_YukiDefeat::
# 742 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good picks. That's half\n"
	.string "the battle.$"

VermilionCity_Dojo_Text_YukiPost::
# 747 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Every match starts before\n"
	.string "the first move is made.$"

VermilionCity_Dojo_Text_JinIntro::
# 752 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Fifteen turns.\n"
	.string "That's all you get.\p"
	.string "If you can't close it by\n"
	.string "then, you weren't ready.$"

VermilionCity_Dojo_Text_JinDefeat::
# 759 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Quick and clean.\n"
	.string "You knew what to do.$"

VermilionCity_Dojo_Text_JinPost::
# 764 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Efficiency isn't speed.\n"
	.string "It's not wasting what\l"
	.string "you have.$"

VermilionCity_Dojo_Text_AkioIntro::
# 770 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "NORMAL types.\n"
	.string "Only NORMAL types.\p"
	.string "The most common things in\n"
	.string "this region.\p"
	.string "Show me you understand\n"
	.string "what you already have.$"

VermilionCity_Dojo_Text_AkioDefeat::
# 779 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good. You didn't overcomplicate\n"
	.string "it.$"

VermilionCity_Dojo_Text_AkioPostBattle::
# 784 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "A researcher who ignores\n"
	.string "common POKéMON misses\l"
	.string "half the picture.\p"
	.string "They're everywhere for a\n"
	.string "reason.\p"
	.string "These are for your fieldwork.$"

VermilionCity_Dojo_Text_ChallengeGuyIntro::
# 793 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Welcome to the Attack Dojo!\p"
	.string "Pick your challenge.\p"
	.string "TRAINING matches whatever belt\n"
	.string "you've earned, scaled to your\l"
	.string "level. It won't count toward\n"
	.string "unlocking the next belt.$"

VermilionCity_Dojo_Text_ChallengeTrainingSet::
# 802 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Training mode selected.\n"
	.string "Opponents will match your level.$"

VermilionCity_Dojo_Text_ChallengeWhiteSet::
# 807 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "White Belt challenge selected.\n"
	.string "Go find your opponents.$"

VermilionCity_Dojo_Text_ChallengeBlueSet::
# 812 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Blue Belt challenge selected.\n"
	.string "Go find your opponents.$"

VermilionCity_Dojo_Text_ChallengeBlueLocked::
# 817 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Clear White Belt against all\n"
	.string "four of us before you try Blue.$"

VermilionCity_Dojo_Text_ChallengeBlackSet::
# 822 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Black Belt challenge selected.\n"
	.string "Go find your opponents.$"

VermilionCity_Dojo_Text_ChallengeBlackLocked::
# 827 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Clear Blue Belt against all\n"
	.string "four of us before you try Black.$"

VermilionCity_Dojo_Text_ChallengeGuyIntroGauntlet::
# 832 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Welcome to the Attack Dojo!\p"
	.string "Pick your challenge.\p"
	.string "TRAINING matches whatever belt\n"
	.string "you've earned, scaled to your\l"
	.string "level. It won't count toward\n"
	.string "unlocking the next belt.\p"
	.string "Since you've beaten all of us\n"
	.string "at Black Belt... there's one\l"
	.string "more thing.\p"
	.string "The GAUNTLET. All four of us,\n"
	.string "back to back. No leaving to\l"
	.string "heal. No second chances.$"

VermilionCity_Dojo_Text_ChallengeGauntletSet::
# 847 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Gauntlet selected.\n"
	.string "Don't leave until it's done.$"

VermilionCity_Dojo_Text_GauntletCleared::
# 852 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "...\p"
	.string "All four of us, back to back,\n"
	.string "and you never once walked out\l"
	.string "that door.\p"
	.string "That's the Gauntlet.\n"
	.string "You've earned it.$"

VermilionCity_Dojo_Text_Plaque::
# 861 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "AKIO'S DOJO\p"
	.string "Observation precedes action.\n"
	.string "Action precedes understanding.$"

VermilionCity_Dojo_Text_ScrollLeft::
# 867 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The untrained eye sees a\n"
	.string "common bird.\l"
	.string "The trained eye sees how\n"
	.string "it holds its wings.$"

VermilionCity_Dojo_Text_ScrollRight::
# 874 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "There is no weak POKéMON.\n"
	.string "There is only the trainer\l"
	.string "who stopped looking.$"

VermilionCity_Dojo_Text_Machop::
# 880 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MACHOP trains here every day.\n"
	.string "It hasn't missed one.$"

VermilionCity_Dojo_Text_Mankey::
# 885 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MANKEY gets worked up\n"
	.string "watching the sparring matches.$"

VermilionCity_Dojo_Text_Hitmonchan::
# 890 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The HITMONCHAN watches every\n"
	.string "match without blinking.\p"
	.string "It's seen every mistake you're\n"
	.string "about to make.$"
