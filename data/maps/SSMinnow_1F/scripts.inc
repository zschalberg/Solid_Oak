SSMinnow_1F_MapScripts::
# 7 "data/maps/SSMinnow_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSMinnow_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SSMinnow_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/SSMinnow_1F/scripts.pory"
	map_script_2 VAR_MAP_SCENE_S_S_MINNOW_1F_CORRIDOR, 0, SSMinnow_1F_EventScript_AgathaCutscene
	.2byte 0


SSMinnow_1F_EventScript_AgathaCutscene::
# 13 "data/maps/SSMinnow_1F/scripts.pory"
	lockall
# 17 "data/maps/SSMinnow_1F/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
# 18 "data/maps/SSMinnow_1F/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_RIGHT
# 20 "data/maps/SSMinnow_1F/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 22 "data/maps/SSMinnow_1F/scripts.pory"
	msgbox SSMinnow_1F_EventScript_AgathaCutscene_Text_0
# 23 "data/maps/SSMinnow_1F/scripts.pory"
	closemessage
# 25 "data/maps/SSMinnow_1F/scripts.pory"
	opendoor 16, 8
# 26 "data/maps/SSMinnow_1F/scripts.pory"
	waitdooranim
# 28 "data/maps/SSMinnow_1F/scripts.pory"
	applymovement 1, SSMinnow_1F_Movement_AgathaLead
# 29 "data/maps/SSMinnow_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSMinnow_1F_Movement_PlayerFollow
# 30 "data/maps/SSMinnow_1F/scripts.pory"
	waitmovement 0
# 32 "data/maps/SSMinnow_1F/scripts.pory"
	closedoor 16, 8
# 33 "data/maps/SSMinnow_1F/scripts.pory"
	waitdooranim
# 35 "data/maps/SSMinnow_1F/scripts.pory"
	warp MAP_SSANNE_1F_ROOM6, 2, 2
# 36 "data/maps/SSMinnow_1F/scripts.pory"
	setflag FLAG_AGATHA_AND_JOURNAL
# 37 "data/maps/SSMinnow_1F/scripts.pory"
	releaseall
	end


# 41 "data/maps/SSMinnow_1F/scripts.pory"
SSMinnow_1F_Movement_AgathaLead:
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 42 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_down
# 44 "data/maps/SSMinnow_1F/scripts.pory"
	set_invisible
	step_end

# 46 "data/maps/SSMinnow_1F/scripts.pory"
SSMinnow_1F_Movement_PlayerFollow:
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 48 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_down
	step_end

SSMinnow_1F_EventScript_AgathaCutscene_Text_0:
# 22 "data/maps/SSMinnow_1F/scripts.pory"
	.string "Alright Sammy,\nLet's go see what the professor wants.$"
