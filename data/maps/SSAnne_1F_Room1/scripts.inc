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
	giveitem ITEM_FIELD_NOTEBOOK, 1
# 13 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitfanfare
# 14 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 15 "data/maps/SSAnne_1F_Room1/scripts.pory"
	special EnableNationalPokedex
# 16 "data/maps/SSAnne_1F_Room1/scripts.pory"
	removeobject 1
# 17 "data/maps/SSAnne_1F_Room1/scripts.pory"
	release
	end


SSAnne_1F_Room1_EventScript_DebugBall::
# 22 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 23 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 5
# 24 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_BLU_PROTOBALL, 5
# 25 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_GRN_PROTOBALL, 5
# 26 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_BLK_PROTOBALL, 5
# 27 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_CHERISH_BALL, 5
# 28 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_IV_SCANNER, 1
# 29 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_SIZE_CHARM, 1
# 30 "data/maps/SSAnne_1F_Room1/scripts.pory"
	giveitem ITEM_COURIER_WHISTLE, 1
	end


SSAnne_1F_Room1_EventScript_DoorTrigger::
# 35 "data/maps/SSAnne_1F_Room1/scripts.pory"
	lockall
# 36 "data/maps/SSAnne_1F_Room1/scripts.pory"
	goto_if_set FLAG_SS_ANNE_ROOM1_AGATHA_SCENE_COMPLETED, SSAnne_1F_Room1_EventScript_DoorTrigger_2
# 40 "data/maps/SSAnne_1F_Room1/scripts.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, SSAnne_1F_Room1_EventScript_DoorTrigger_5
# 49 "data/maps/SSAnne_1F_Room1/scripts.pory"
	clearflag FLAG_HIDE_SS_ANNE_ROOM1_AGATHA
# 50 "data/maps/SSAnne_1F_Room1/scripts.pory"
	addobject 2
# 52 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_1F_Room1_Movement_PlayerPushedSouth
# 53 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement 2, SSAnne_1F_Room1_Movement_AgathaEnter
# 54 "data/maps/SSAnne_1F_Room1/scripts.pory"
	playse SE_DOOR
# 55 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitse
# 56 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitmovement 0
# 58 "data/maps/SSAnne_1F_Room1/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 59 "data/maps/SSAnne_1F_Room1/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 60 "data/maps/SSAnne_1F_Room1/scripts.pory"
	msgbox SSAnne_1F_Room1_EventScript_DoorTrigger_Text_1
# 61 "data/maps/SSAnne_1F_Room1/scripts.pory"
	closemessage
# 62 "data/maps/SSAnne_1F_Room1/scripts.pory"
	clearmugshot
# 64 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement 2, SSAnne_1F_Room1_Movement_AgathaExit
# 65 "data/maps/SSAnne_1F_Room1/scripts.pory"
	playse SE_DOOR
# 66 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitse
# 67 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitmovement 0
# 69 "data/maps/SSAnne_1F_Room1/scripts.pory"
	removeobject 2
# 70 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setflag FLAG_HIDE_SS_ANNE_ROOM1_AGATHA
# 72 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setflag FLAG_SS_ANNE_ROOM1_AGATHA_SCENE_COMPLETED
# 73 "data/maps/SSAnne_1F_Room1/scripts.pory"
	setvar VAR_TEMP_0, 1
SSAnne_1F_Room1_EventScript_DoorTrigger_4:
# 75 "data/maps/SSAnne_1F_Room1/scripts.pory"
	releaseall
	end

SSAnne_1F_Room1_EventScript_DoorTrigger_2:
# 37 "data/maps/SSAnne_1F_Room1/scripts.pory"
	releaseall
	end

SSAnne_1F_Room1_EventScript_DoorTrigger_5:
# 41 "data/maps/SSAnne_1F_Room1/scripts.pory"
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_RIGHT
# 42 "data/maps/SSAnne_1F_Room1/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 43 "data/maps/SSAnne_1F_Room1/scripts.pory"
	msgbox SSAnne_1F_Room1_EventScript_DoorTrigger_Text_0
# 44 "data/maps/SSAnne_1F_Room1/scripts.pory"
	closemessage
# 45 "data/maps/SSAnne_1F_Room1/scripts.pory"
	clearmugshot
# 46 "data/maps/SSAnne_1F_Room1/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_1F_Room1_Movement_PlayerWalkSouth
# 47 "data/maps/SSAnne_1F_Room1/scripts.pory"
	waitmovement 0
	goto SSAnne_1F_Room1_EventScript_DoorTrigger_4


# 79 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_PlayerWalkSouth:
# 80 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_down
	step_end

# 83 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_PlayerPushedSouth:
# 84 "data/maps/SSAnne_1F_Room1/scripts.pory"
	lock_facing_direction
# 85 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_down
# 86 "data/maps/SSAnne_1F_Room1/scripts.pory"
	unlock_facing_direction
	step_end

# 89 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_AgathaEnter:
# 90 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_down
	step_end

# 93 "data/maps/SSAnne_1F_Room1/scripts.pory"
SSAnne_1F_Room1_Movement_AgathaExit:
# 94 "data/maps/SSAnne_1F_Room1/scripts.pory"
	walk_up
	step_end

SSAnne_1F_Room1_EventScript_Journal_Text_0:
# 10 "data/maps/SSAnne_1F_Room1/scripts.pory"
	.string "Obtained the JOURNAL!$"

SSAnne_1F_Room1_EventScript_DoorTrigger_Text_0:
# 43 "data/maps/SSAnne_1F_Room1/scripts.pory"
	.string "I should grab my journal\nbefore I go.$"

SSAnne_1F_Room1_EventScript_DoorTrigger_Text_1:
# 60 "data/maps/SSAnne_1F_Room1/scripts.pory"
	.string "There you are Sammy!\nThe Professor is looking for us!$"
