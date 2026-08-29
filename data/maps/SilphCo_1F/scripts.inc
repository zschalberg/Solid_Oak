SilphCo_1F_MapScripts::
# 6 "data/maps/SilphCo_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_1F_OnTransition
# 7 "data/maps/SilphCo_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_1F_OnLoad
# 8 "data/maps/SilphCo_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SilphCo_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SilphCo_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/SilphCo_1F/scripts.pory"
	map_script_2 VAR_SCENE_SILPH, 0, SilphCo_1F_EventScript_BallMalfunctionCutscene
	.2byte 0


SilphCo_1F_OnTransition::
# 14 "data/maps/SilphCo_1F/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_SILPH_CO_1F
	end


SilphCo_1F_OnLoad::
# 23 "data/maps/SilphCo_1F/scripts.pory"
	goto_if_set FLAG_SAW_SILPHCO_1F_BALL_MALFUNCTION, SilphCo_1F_OnLoad_2
# 26 "data/maps/SilphCo_1F/scripts.pory"
	setflag FLAG_HIDE_SILPHCO_1F_CONTAINMENT_REVEAL
SilphCo_1F_OnLoad_1:
	end

SilphCo_1F_OnLoad_2:
# 24 "data/maps/SilphCo_1F/scripts.pory"
	clearflag FLAG_HIDE_SILPHCO_1F_CONTAINMENT_REVEAL
	goto SilphCo_1F_OnLoad_1


SilphCo_1F_EventScript_Receptionist::
# 32 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_EventScript_Receptionist_Text_0, MSGBOX_NPC
	end


SilphCo_1F_EventScript_FloorSign::
# 39 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_EventScript_FloorSign_Text_0, MSGBOX_SIGN
	end


SilphCo_1F_EventScript_PrototypeBall::
# 48 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_EventScript_PrototypeBall_Text_0, MSGBOX_SIGN
	end


SilphCo_1F_EventScript_ContainmentFailure::
# 55 "data/maps/SilphCo_1F/scripts.pory"
	lock
# 56 "data/maps/SilphCo_1F/scripts.pory"
	faceplayer
# 57 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_EventScript_ContainmentFailure_Text_0
# 58 "data/maps/SilphCo_1F/scripts.pory"
	closemessage
# 59 "data/maps/SilphCo_1F/scripts.pory"
	release
	end


SilphCo_1F_EventScript_BallMalfunctionCutscene::
# 67 "data/maps/SilphCo_1F/scripts.pory"
	lockall
# 68 "data/maps/SilphCo_1F/scripts.pory"
	setvar VAR_SCENE_SILPH, 1
# 69 "data/maps/SilphCo_1F/scripts.pory"
	setflag FLAG_SAW_SILPHCO_1F_BALL_MALFUNCTION
# 70 "data/maps/SilphCo_1F/scripts.pory"
	applymovement 1, SilphCo_1F_Movement_ReceptionistNotices
# 71 "data/maps/SilphCo_1F/scripts.pory"
	waitmovement 1
# 72 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_EventScript_BallMalfunctionCutscene_Text_0
# 73 "data/maps/SilphCo_1F/scripts.pory"
	closemessage
# 74 "data/maps/SilphCo_1F/scripts.pory"
	removeobject 2
# 75 "data/maps/SilphCo_1F/scripts.pory"
	addobject 3
# 76 "data/maps/SilphCo_1F/scripts.pory"
	playse SE_BALL_OPEN
# 77 "data/maps/SilphCo_1F/scripts.pory"
	applymovement 3, SilphCo_1F_Movement_Burst
# 78 "data/maps/SilphCo_1F/scripts.pory"
	waitmovement 3
# 79 "data/maps/SilphCo_1F/scripts.pory"
	msgbox SilphCo_1F_EventScript_BallMalfunctionCutscene_Text_1
# 83 "data/maps/SilphCo_1F/scripts.pory"
	closemessage
# 84 "data/maps/SilphCo_1F/scripts.pory"
	releaseall
	end


# 88 "data/maps/SilphCo_1F/scripts.pory"
SilphCo_1F_Movement_ReceptionistNotices:
# 89 "data/maps/SilphCo_1F/scripts.pory"
	face_right
	step_end

# 92 "data/maps/SilphCo_1F/scripts.pory"
SilphCo_1F_Movement_Burst:
# 93 "data/maps/SilphCo_1F/scripts.pory"
	burst_from_pokeball
	step_end

SilphCo_1F_EventScript_Receptionist_Text_0:
# 32 "data/maps/SilphCo_1F/scripts.pory"
	.string "Welcome.\p"
	.string "The PRESIDENT is in the boardroom\n"
	.string "on 11F.$"

SilphCo_1F_EventScript_FloorSign_Text_0:
# 39 "data/maps/SilphCo_1F/scripts.pory"
	.string "SILPH CO. HEAD OFFICE\n"
	.string "1F$"

SilphCo_1F_EventScript_PrototypeBall_Text_0:
# 48 "data/maps/SilphCo_1F/scripts.pory"
	.string "A prototype containment ball is\nsitting on display here.$"

SilphCo_1F_EventScript_ContainmentFailure_Text_0:
# 57 "data/maps/SilphCo_1F/scripts.pory"
	.string "The VOLTORB rolls back and forth,\nsizing you up.$"

SilphCo_1F_EventScript_BallMalfunctionCutscene_Text_0:
# 72 "data/maps/SilphCo_1F/scripts.pory"
	.string "Wait, that ball on the display\ncase - it's shaking!$"

SilphCo_1F_EventScript_BallMalfunctionCutscene_Text_1:
# 79 "data/maps/SilphCo_1F/scripts.pory"
	.string "The prototype couldn't hold it!\p"
	.string "That's... that's a VOLTORB standing\nwhere the ball used to be.\p"
	.string "This is exactly the kind of\n"
	.string "containment failure the team\lupstairs has been trying to fix.$"
