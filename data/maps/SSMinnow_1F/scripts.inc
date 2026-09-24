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
# 24 "data/maps/SSMinnow_1F/scripts.pory"
	closemessage
# 26 "data/maps/SSMinnow_1F/scripts.pory"
	opendoor 16, 8
# 27 "data/maps/SSMinnow_1F/scripts.pory"
	waitdooranim
# 29 "data/maps/SSMinnow_1F/scripts.pory"
	applymovement 1, SSMinnow_1F_Movement_AgathaLead
# 30 "data/maps/SSMinnow_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSMinnow_1F_Movement_PlayerFollow
# 31 "data/maps/SSMinnow_1F/scripts.pory"
	waitmovement 0
# 33 "data/maps/SSMinnow_1F/scripts.pory"
	closedoor 16, 8
# 34 "data/maps/SSMinnow_1F/scripts.pory"
	waitdooranim
# 36 "data/maps/SSMinnow_1F/scripts.pory"
	warp MAP_SSANNE_1F_ROOM6, 2, 2
# 37 "data/maps/SSMinnow_1F/scripts.pory"
	setflag FLAG_AGATHA_AND_JOURNAL
# 38 "data/maps/SSMinnow_1F/scripts.pory"
	releaseall
	end


# 42 "data/maps/SSMinnow_1F/scripts.pory"
SSMinnow_1F_Movement_AgathaLead:
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 43 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 44 "data/maps/SSMinnow_1F/scripts.pory"
	walk_down
# 45 "data/maps/SSMinnow_1F/scripts.pory"
	set_invisible
	step_end

# 47 "data/maps/SSMinnow_1F/scripts.pory"
SSMinnow_1F_Movement_PlayerFollow:
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 49 "data/maps/SSMinnow_1F/scripts.pory"
	walk_right
# 50 "data/maps/SSMinnow_1F/scripts.pory"
	walk_down
	step_end

SSMinnow_1F_EventScript_AgathaCutscene_Text_0:
# 22 "data/maps/SSMinnow_1F/scripts.pory"
	.string "Alright Sammy, let's go see\n"
	.string "what the professor wants.$"
