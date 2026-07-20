SSAnne_1F_Room1_MapScripts::
	.byte 0


SSAnne_1F_Room1_EventScript_Gentleman::
# 4 "data/maps/SSAnne_1F_Room1/scripts.pory"
	msgbox SSAnne_1F_Room1_Text_ImAGlobalPoliceAgent, MSGBOX_NPC
	end


SSAnne_1F_Room1_EventScript_Journal::
# 9 "data/maps/SSAnne_1F_Room1/scripts.pory"
	lock
# 10 "data/maps/SSAnne_1F_Room1/scripts.pory"
	msgbox SSAnne_1F_Room1_EventScript_Journal_Text_0
# 11 "data/maps/SSAnne_1F_Room1/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 12 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitfanfare
# 13 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 14 "data/maps/SSAnne_1F_Room1/scripts.pory"
	removeobject 1
# 15 "data/maps/SSAnne_1F_Room1/scripts.pory"
	release
	end


SSAnne_1F_Room1_EventScript_DoorTrigger::
# 20 "data/maps/SSAnne_1F_Room1/scripts.pory"
	lockall
# 21 "data/maps/SSAnne_1F_Room1/scripts.pory"
	goto_if_set FLAG_SS_ANNE_ROOM1_AGATHA_SCENE_COMPLETED, SSAnne_1F_Room1_EventScript_DoorTrigger_2
# 25 "data/maps/SSAnne_1F_Room1/scripts.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, SSAnne_1F_Room1_EventScript_DoorTrigger_5
# 33 "data/maps/SSAnne_1F_Room1/scripts.pory"
	clearflag FLAG_HIDE_SS_ANNE_ROOM1_AGATHA
# 34 "data/maps/SSAnne_1F_Room1/scripts.pory"
	addobject 2
# 36 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_1F_Room1_Movement_PlayerPushedSouth
# 37 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement 2, SSAnne_1F_Room1_Movement_AgathaEnter
# 38 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitmovement 0
# 40 "data/maps/SSAnne_1F_Room1/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 41 "data/maps/SSAnne_1F_Room1/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 42 "data/maps/SSAnne_1F_Room1/scripts.pory"
	msgbox SSAnne_1F_Room1_EventScript_DoorTrigger_Text_1
# 43 "data/maps/SSAnne_1F_Room1/scripts.pory"
	closemessage
# 45 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement 2, SSAnne_1F_Room1_Movement_AgathaExit
# 46 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitmovement 0
# 48 "data/maps/SSAnne_1F_Room1/scripts.pory"
	removeobject 2
# 49 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setflag FLAG_HIDE_SS_ANNE_ROOM1_AGATHA
# 51 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setflag FLAG_SS_ANNE_ROOM1_AGATHA_SCENE_COMPLETED
# 52 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setvar VAR_TEMP_0, 1
SSAnne_1F_Room1_EventScript_DoorTrigger_4:
# 54 "data/maps/SSAnne_1F_Room1/scripts.pory"
	releaseall
	end

SSAnne_1F_Room1_EventScript_DoorTrigger_2:
# 22 "data/maps/SSAnne_1F_Room1/scripts.pory"
	releaseall
	end

SSAnne_1F_Room1_EventScript_DoorTrigger_5:
# 26 "data/maps/SSAnne_1F_Room1/scripts.pory"
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_RIGHT
# 27 "data/maps/SSAnne_1F_Room1/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 28 "data/maps/SSAnne_1F_Room1/scripts.pory"
	msgbox SSAnne_1F_Room1_EventScript_DoorTrigger_Text_0
# 29 "data/maps/SSAnne_1F_Room1/scripts.pory"
	closemessage
# 30 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_1F_Room1_Movement_PlayerWalkSouth
# 31 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitmovement 0
	goto SSAnne_1F_Room1_EventScript_DoorTrigger_4


# 58 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_PlayerWalkSouth:
# 59 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_down
	step_end

# 62 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_PlayerPushedSouth:
# 63 "data/maps/SSAnne_1F_Room1/scripts.pory"
	lock_facing_direction
# 64 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_down
# 65 "data/maps/SSAnne_1F_Room1/scripts.pory"
	unlock_facing_direction
	step_end

# 68 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_AgathaEnter:
# 69 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_down
	step_end

# 72 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_AgathaExit:
# 73 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_up
	step_end

SSAnne_1F_Room1_EventScript_Journal_Text_0:
# 10 "data/maps/SSAnne_1F_Room1/scripts.pory"
	.string "Obtained the JOURNAL!$"

SSAnne_1F_Room1_EventScript_DoorTrigger_Text_0:
# 28 "data/maps/SSAnne_1F_Room1/scripts.pory"
	.string "I should grab my journal\nbefore I go.$"

SSAnne_1F_Room1_EventScript_DoorTrigger_Text_1:
# 42 "data/maps/SSAnne_1F_Room1/scripts.pory"
	.string "There you are Sammy!\nThe Professor is looking for us!$"
