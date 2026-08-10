VermilionCity_Dojo_MapScripts::
# 18 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Dojo_OnTransition
# 19 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

VermilionCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 20 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, VermilionCity_Dojo_OnFrame
	.2byte 0


VermilionCity_Dojo_OnTransition::
# 28 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 29 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
	end


VermilionCity_Dojo_OnFrame::
# 38 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_TEMP_0, 1
# 39 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_SEEN_DOJO_INTRO, VermilionCity_Dojo_OnFrame_2
VermilionCity_Dojo_OnFrame_1:
	end

VermilionCity_Dojo_OnFrame_2:
# 40 "data/maps/VermilionCity_Dojo/scripts.pory"
	call Common_EventScript_DojoIntro
	goto VermilionCity_Dojo_OnFrame_1


VermilionCity_Dojo_EventScript_TmBall::
# 47 "data/maps/VermilionCity_Dojo/scripts.pory"
	finditem ITEM_TM08
# 48 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_ITEM_VERMILION_DOJO_TM
	end


VermilionCity_Dojo_EventScript_ChallengeGuy::
# 57 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 58 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 59 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeGuyIntro, MSGBOX_DEFAULT
# 60 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 61 "data/maps/VermilionCity_Dojo/scripts.pory"
	multichoice 0, 0, MULTI_DOJO_CHALLENGE, FALSE
# 62 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_2
# 66 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_5
# 70 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_8
# 74 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq VermilionCity_Dojo_EventScript_ChallengeGuy_11
# 78 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_2:
# 63 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeTraining
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_5:
# 67 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeWhite
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_8:
# 71 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeBlue
	end

VermilionCity_Dojo_EventScript_ChallengeGuy_11:
# 75 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_ChallengeBlack
	end


VermilionCity_Dojo_EventScript_ChallengeTraining::
# 83 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_TRAINING_MODE
# 84 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 1
# 85 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_RYU_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_4
VermilionCity_Dojo_EventScript_ChallengeTraining_1:
# 88 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_RYU_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_13
VermilionCity_Dojo_EventScript_ChallengeTraining_10:
# 91 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeTrainingSet, MSGBOX_AUTOCLOSE
# 92 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeTraining_2:
# 86 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 2
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_3:
# 85 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_JIN_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_7
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_4:
# 85 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_YUKI_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_3
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_7:
# 85 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_2
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_1

VermilionCity_Dojo_EventScript_ChallengeTraining_11:
# 89 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 3
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10

VermilionCity_Dojo_EventScript_ChallengeTraining_12:
# 88 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_JIN_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_16
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10

VermilionCity_Dojo_EventScript_ChallengeTraining_13:
# 88 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_YUKI_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_12
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10

VermilionCity_Dojo_EventScript_ChallengeTraining_16:
# 88 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeTraining_11
	goto VermilionCity_Dojo_EventScript_ChallengeTraining_10


VermilionCity_Dojo_EventScript_ChallengeWhite::
# 97 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 98 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 1
# 99 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeWhiteSet, MSGBOX_AUTOCLOSE
# 100 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_ChallengeBlue::
# 105 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_RYU_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 105 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_YUKI_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 105 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_JIN_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 105 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AKIO_WHITE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlue_2
# 110 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 111 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 2
# 112 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlueSet, MSGBOX_AUTOCLOSE
# 113 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeBlue_2:
# 106 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlueLocked, MSGBOX_AUTOCLOSE
# 107 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_ChallengeBlack::
# 118 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_RYU_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 118 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_YUKI_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 118 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_JIN_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 118 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AKIO_BLUE_DEFEATED, VermilionCity_Dojo_EventScript_ChallengeBlack_2
# 123 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_DOJO_TRAINING_MODE
# 124 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_DOJO_CHALLENGE_TIER, 3
# 125 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlackSet, MSGBOX_AUTOCLOSE
# 126 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_ChallengeBlack_2:
# 119 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ChallengeBlackLocked, MSGBOX_AUTOCLOSE
# 120 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Ryu::
# 135 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 136 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 137 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 138 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_2
# 144 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 145 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 146 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Ryu_5
VermilionCity_Dojo_EventScript_Ryu_4:
# 150 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_8
# 153 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Ryu_11
# 156 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU_WHITE, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat, VermilionCity_Dojo_EventScript_RyuWon
VermilionCity_Dojo_EventScript_Ryu_7:
# 161 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_RyuPost, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Ryu_2:
# 139 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 140 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 141 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Ryu_5:
# 147 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 148 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Ryu_4

VermilionCity_Dojo_EventScript_Ryu_8:
# 151 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU_BLACK, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat, VermilionCity_Dojo_EventScript_RyuWon
	goto VermilionCity_Dojo_EventScript_Ryu_7

VermilionCity_Dojo_EventScript_Ryu_11:
# 154 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU_BLUE, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat, VermilionCity_Dojo_EventScript_RyuWon
	goto VermilionCity_Dojo_EventScript_Ryu_7


VermilionCity_Dojo_EventScript_RyuWon::
# 170 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_RyuWon_2
# 175 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_RyuWon_7
# 182 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_RyuWon_13
# 185 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_WHITE
VermilionCity_Dojo_EventScript_RyuWon_1:
# 189 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_RyuPost, MSGBOX_AUTOCLOSE
# 190 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_RyuWon_2:
# 171 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_RyuWon_5
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_5:
# 172 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_BLACK
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_7:
# 176 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_RyuWon_10
# 179 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_RYU_BLUE
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_10:
# 177 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_RYU_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_RyuWon_1

VermilionCity_Dojo_EventScript_RyuWon_13:
# 183 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_RYU_WHITE_DEFEATED
	goto VermilionCity_Dojo_EventScript_RyuWon_1


VermilionCity_Dojo_EventScript_Yuki::
# 199 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 200 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 201 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 202 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_2
# 208 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 209 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 210 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Yuki_5
VermilionCity_Dojo_EventScript_Yuki_4:
# 214 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_8
# 217 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Yuki_11
# 220 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO_WHITE, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat, VermilionCity_Dojo_EventScript_YukiWon
VermilionCity_Dojo_EventScript_Yuki_7:
# 225 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_YukiPost, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Yuki_2:
# 203 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 204 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 205 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Yuki_5:
# 211 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 212 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Yuki_4

VermilionCity_Dojo_EventScript_Yuki_8:
# 215 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO_BLACK, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat, VermilionCity_Dojo_EventScript_YukiWon
	goto VermilionCity_Dojo_EventScript_Yuki_7

VermilionCity_Dojo_EventScript_Yuki_11:
# 218 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO_BLUE, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat, VermilionCity_Dojo_EventScript_YukiWon
	goto VermilionCity_Dojo_EventScript_Yuki_7


VermilionCity_Dojo_EventScript_YukiWon::
# 230 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_YukiWon_2
# 235 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_YukiWon_7
# 242 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_YukiWon_13
# 245 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_WHITE
VermilionCity_Dojo_EventScript_YukiWon_1:
# 249 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_YukiPost, MSGBOX_AUTOCLOSE
# 250 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_YukiWon_2:
# 231 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_YukiWon_5
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_5:
# 232 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_BLACK
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_7:
# 236 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_YukiWon_10
# 239 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_LASS_YUKI_DOJO_BLUE
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_10:
# 237 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_YUKI_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_YukiWon_1

VermilionCity_Dojo_EventScript_YukiWon_13:
# 243 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_YUKI_WHITE_DEFEATED
	goto VermilionCity_Dojo_EventScript_YukiWon_1


VermilionCity_Dojo_EventScript_Jin::
# 259 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 260 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 261 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 262 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_2
# 268 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 269 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 270 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Jin_5
VermilionCity_Dojo_EventScript_Jin_4:
# 274 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_8
# 277 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Jin_11
# 280 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN_WHITE, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat, VermilionCity_Dojo_EventScript_JinWon
VermilionCity_Dojo_EventScript_Jin_7:
# 285 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_JinPost, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Jin_2:
# 263 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 264 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 265 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Jin_5:
# 271 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 272 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Jin_4

VermilionCity_Dojo_EventScript_Jin_8:
# 275 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN_BLACK, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat, VermilionCity_Dojo_EventScript_JinWon
	goto VermilionCity_Dojo_EventScript_Jin_7

VermilionCity_Dojo_EventScript_Jin_11:
# 278 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN_BLUE, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat, VermilionCity_Dojo_EventScript_JinWon
	goto VermilionCity_Dojo_EventScript_Jin_7


VermilionCity_Dojo_EventScript_JinWon::
# 290 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_JinWon_2
# 295 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_JinWon_7
# 302 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_JinWon_13
# 305 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_WHITE
VermilionCity_Dojo_EventScript_JinWon_1:
# 309 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_JinPost, MSGBOX_AUTOCLOSE
# 310 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_JinWon_2:
# 291 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_JinWon_5
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_5:
# 292 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_BLACK
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_7:
# 296 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_JinWon_10
# 299 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_BLACK_BELT_JIN_BLUE
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_10:
# 297 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_JIN_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_JinWon_1

VermilionCity_Dojo_EventScript_JinWon_13:
# 303 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_JIN_WHITE_DEFEATED
	goto VermilionCity_Dojo_EventScript_JinWon_1


VermilionCity_Dojo_EventScript_Akio::
# 319 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 320 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 321 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_0, MSGBOX_YESNO
# 322 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_2
# 328 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 329 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 2
# 330 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_Akio_5
VermilionCity_Dojo_EventScript_Akio_4:
# 334 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_8
# 337 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_Akio_11
# 340 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO_WHITE, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioWon
VermilionCity_Dojo_EventScript_Akio_7:
# 345 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Akio_2:
# 323 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_EventScript_Ryu_Text_1
# 324 "data/maps/VermilionCity_Dojo/scripts.pory"
	closemessage
# 325 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_Akio_5:
# 331 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 332 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, -1
	goto VermilionCity_Dojo_EventScript_Akio_4

VermilionCity_Dojo_EventScript_Akio_8:
# 335 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO_BLACK, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioWon
	goto VermilionCity_Dojo_EventScript_Akio_7

VermilionCity_Dojo_EventScript_Akio_11:
# 338 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO_BLUE, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioWon
	goto VermilionCity_Dojo_EventScript_Akio_7


VermilionCity_Dojo_EventScript_AkioWon::
# 354 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 3
	goto_if_eq VermilionCity_Dojo_EventScript_AkioWon_2
# 359 "data/maps/VermilionCity_Dojo/scripts.pory"
	compare VAR_DOJO_CHALLENGE_TIER, 2
	goto_if_eq VermilionCity_Dojo_EventScript_AkioWon_7
# 366 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_AkioWon_13
# 373 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_WHITE
VermilionCity_Dojo_EventScript_AkioWon_1:
# 377 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioPostBattle, MSGBOX_AUTOCLOSE
# 378 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end

VermilionCity_Dojo_EventScript_AkioWon_2:
# 355 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_AkioWon_5
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_5:
# 356 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_BLACK
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_7:
# 360 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_TRAINING_MODE, VermilionCity_Dojo_EventScript_AkioWon_10
# 363 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag TRAINER_FLAGS_START + TRAINER_EXPERT_AKIO_BLUE
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_10:
# 361 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_BLUE_DEFEATED
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_13:
# 367 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_WHITE_DEFEATED
# 368 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_unset FLAG_DOJO_AKIO_DEFEATED, VermilionCity_Dojo_EventScript_AkioWon_16
	goto VermilionCity_Dojo_EventScript_AkioWon_1

VermilionCity_Dojo_EventScript_AkioWon_16:
# 369 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_DEFEATED
# 370 "data/maps/VermilionCity_Dojo/scripts.pory"
	giveitem ITEM_TM34, 1
	goto VermilionCity_Dojo_EventScript_AkioWon_1


VermilionCity_Dojo_EventScript_Machop::
# 387 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 388 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 389 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 390 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Machop, MSGBOX_DEFAULT
# 391 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 392 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Mankey::
# 397 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 398 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 399 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
# 400 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Mankey, MSGBOX_DEFAULT
# 401 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 402 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Hitmonchan::
# 407 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 408 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 409 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_HITMONCHAN, CRY_MODE_NORMAL
# 410 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Hitmonchan, MSGBOX_DEFAULT
# 411 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 412 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_TMTutor::
# 417 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto Common_EventScript_TMTutor
	return


VermilionCity_Dojo_EventScript_Plaque::
# 425 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Plaque, MSGBOX_SIGN
	end


VermilionCity_Dojo_EventScript_ScrollLeft::
# 430 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollLeft, MSGBOX_SIGN
	end


VermilionCity_Dojo_EventScript_ScrollRight::
# 435 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollRight, MSGBOX_SIGN
	end


VermilionCity_Dojo_EventScript_Ryu_Text_0:
# 137 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Are you ready?$"

VermilionCity_Dojo_EventScript_Ryu_Text_1:
# 139 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Come back when you're ready.$"

VermilionCity_Dojo_Text_RyuIntro::
# 443 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Before you reach Sensei,\n"
	.string "you pass through me.\p"
	.string "Show me you belong here.$"

VermilionCity_Dojo_Text_RyuDefeat::
# 449 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You've got something in you.$"

VermilionCity_Dojo_Text_RyuPost::
# 453 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The next two fight differently.\n"
	.string "Pay attention to how they\l"
	.string "come at you.$"

VermilionCity_Dojo_Text_YukiIntro::
# 459 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "I always look before I commit.\p"
	.string "You'll see my whole team.\n"
	.string "I'll see yours.\p"
	.string "Then we decide.$"

VermilionCity_Dojo_Text_YukiDefeat::
# 466 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good picks. That's half\n"
	.string "the battle.$"

VermilionCity_Dojo_Text_YukiPost::
# 471 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Every match starts before\n"
	.string "the first move is made.$"

VermilionCity_Dojo_Text_JinIntro::
# 476 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Fifteen turns.\n"
	.string "That's all you get.\p"
	.string "If you can't close it by\n"
	.string "then, you weren't ready.$"

VermilionCity_Dojo_Text_JinDefeat::
# 483 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Quick and clean.\n"
	.string "You knew what to do.$"

VermilionCity_Dojo_Text_JinPost::
# 488 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Efficiency isn't speed.\n"
	.string "It's not wasting what\l"
	.string "you have.$"

VermilionCity_Dojo_Text_AkioIntro::
# 494 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "NORMAL types.\n"
	.string "Only NORMAL types.\p"
	.string "The most common things in\n"
	.string "this region.\p"
	.string "Show me you understand\n"
	.string "what you already have.$"

VermilionCity_Dojo_Text_AkioDefeat::
# 503 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good. You didn't overcomplicate\n"
	.string "it.$"

VermilionCity_Dojo_Text_AkioPostBattle::
# 508 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "A researcher who ignores\n"
	.string "common POKéMON misses\l"
	.string "half the picture.\p"
	.string "They're everywhere for a\n"
	.string "reason.\p"
	.string "These are for your fieldwork.$"

VermilionCity_Dojo_Text_ChallengeGuyIntro::
# 517 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Welcome to the Attack Dojo!\p"
	.string "Pick your challenge.\p"
	.string "TRAINING matches whatever belt\n"
	.string "you've earned, scaled to your\l"
	.string "level. It won't count toward\n"
	.string "unlocking the next belt.$"

VermilionCity_Dojo_Text_ChallengeTrainingSet::
# 526 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Training mode selected.\n"
	.string "Opponents will match your level.$"

VermilionCity_Dojo_Text_ChallengeWhiteSet::
# 531 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "White Belt challenge selected.\n"
	.string "Go find your opponents.$"

VermilionCity_Dojo_Text_ChallengeBlueSet::
# 536 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Blue Belt challenge selected.\n"
	.string "Go find your opponents.$"

VermilionCity_Dojo_Text_ChallengeBlueLocked::
# 541 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Clear White Belt against all\n"
	.string "four of us before you try Blue.$"

VermilionCity_Dojo_Text_ChallengeBlackSet::
# 546 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Black Belt challenge selected.\n"
	.string "Go find your opponents.$"

VermilionCity_Dojo_Text_ChallengeBlackLocked::
# 551 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Clear Blue Belt against all\n"
	.string "four of us before you try Black.$"

VermilionCity_Dojo_Text_Plaque::
# 556 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "AKIO'S DOJO\p"
	.string "Observation precedes action.\n"
	.string "Action precedes understanding.$"

VermilionCity_Dojo_Text_ScrollLeft::
# 562 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The untrained eye sees a\n"
	.string "common bird.\l"
	.string "The trained eye sees how\n"
	.string "it holds its wings.$"

VermilionCity_Dojo_Text_ScrollRight::
# 569 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "There is no weak POKéMON.\n"
	.string "There is only the trainer\l"
	.string "who stopped looking.$"

VermilionCity_Dojo_Text_Machop::
# 575 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MACHOP trains here every day.\n"
	.string "It hasn't missed one.$"

VermilionCity_Dojo_Text_Mankey::
# 580 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MANKEY gets worked up\n"
	.string "watching the sparring matches.$"

VermilionCity_Dojo_Text_Hitmonchan::
# 585 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The HITMONCHAN watches every\n"
	.string "match without blinking.\p"
	.string "It's seen every mistake you're\n"
	.string "about to make.$"
