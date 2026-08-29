SilphCo_2F_MapScripts::
# 4 "data/maps/SilphCo_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0


SilphCo_2F_OnLoad::
# 8 "data/maps/SilphCo_2F/scripts.pory"
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	end


SilphCoScientist_Give_Protoball::
# 17 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_SCENE_SILPH, 3
	goto_if_ge SilphCoScientist_Give_Protoball_2
# 31 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_SCENE_SILPH, 2
	goto_if_eq SilphCoScientist_Give_Protoball_5
# 35 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_SCENE_SILPH, 0
	goto_if_eq SilphCoScientist_Give_Protoball_8
# 48 "data/maps/SilphCo_2F/scripts.pory"
	lock
# 49 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 50 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 51 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 52 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_2
# 59 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 60 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 61 "data/maps/SilphCo_2F/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 2
# 62 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 63 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 64 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_3
# 77 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_SILPH_TESTING_COMPLETED
# 78 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_REDPROTOBALL_ACTIVE
# 79 "data/maps/SilphCo_2F/scripts.pory"
	quest_complete_toast SilphCoScientist_Give_Protoball_Text_4
# 80 "data/maps/SilphCo_2F/scripts.pory"
	quest_start_toast SilphCoScientist_Give_Protoball_Text_5
# 81 "data/maps/SilphCo_2F/scripts.pory"
	setvar VAR_SCENE_SILPH, 2
# 82 "data/maps/SilphCo_2F/scripts.pory"
	release
	end

SilphCoScientist_Give_Protoball_2:
# 18 "data/maps/SilphCo_2F/scripts.pory"
	lock
# 19 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 20 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 21 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 22 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_0
# 26 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 27 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 28 "data/maps/SilphCo_2F/scripts.pory"
	release
	end

SilphCoScientist_Give_Protoball_5:
# 32 "data/maps/SilphCo_2F/scripts.pory"
	goto SilphCoScientist_EventScript_CheckProtoballTurnIn
	end

SilphCoScientist_Give_Protoball_8:
# 36 "data/maps/SilphCo_2F/scripts.pory"
	lock
# 37 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 38 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 39 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 40 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_1
# 43 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 44 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 45 "data/maps/SilphCo_2F/scripts.pory"
	release
	end


SilphCoScientist_EventScript_CheckProtoballTurnIn::
# 90 "data/maps/SilphCo_2F/scripts.pory"
	specialvar VAR_0x8006, CountRedProtoballCaughtMons
# 92 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_0x8006, 2
	goto_if_lt SilphCoScientist_EventScript_CheckProtoballTurnIn_2
# 106 "data/maps/SilphCo_2F/scripts.pory"
	goto SilphCoScientist_EventScript_ProtoballTurnIn
	end

SilphCoScientist_EventScript_CheckProtoballTurnIn_2:
# 93 "data/maps/SilphCo_2F/scripts.pory"
	lock
# 94 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 95 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 96 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 97 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_CheckProtoballTurnIn_Text_0
# 101 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 102 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 103 "data/maps/SilphCo_2F/scripts.pory"
	release
	end


SilphCoScientist_EventScript_ProtoballTurnIn::
# 112 "data/maps/SilphCo_2F/scripts.pory"
	lockall
# 113 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 114 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 115 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 116 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_0
# 121 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 122 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 123 "data/maps/SilphCo_2F/scripts.pory"
	checkitem ITEM_BLUE_APRICORN, 2
# 124 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_2
# 138 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 139 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 140 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_2
# 142 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 143 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 144 "data/maps/SilphCo_2F/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 145 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_5
# 148 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_6
# 151 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_7
# 155 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_ToDoor
# 156 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
SilphCoScientist_EventScript_ProtoballTurnIn_4:
# 158 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement 1
# 159 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 160 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_SILPH_2F_DOOR_1
# 161 "data/maps/SilphCo_2F/scripts.pory"
	call EventScript_Open2FDoor1
# 162 "data/maps/SilphCo_2F/scripts.pory"
	playse SE_UNLOCK
# 163 "data/maps/SilphCo_2F/scripts.pory"
	special DrawWholeMapView
# 164 "data/maps/SilphCo_2F/scripts.pory"
	waitse
# 165 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToWorkbench
# 166 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_PlayerToWorkbench
# 167 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement 1
# 168 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 169 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 170 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 171 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_3
# 174 "data/maps/SilphCo_2F/scripts.pory"
	removeitem ITEM_BLUE_APRICORN, 2
# 175 "data/maps/SilphCo_2F/scripts.pory"
	special UpgradeRedProtoballCaughtMons
# 176 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_4
# 179 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 180 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 182 "data/maps/SilphCo_2F/scripts.pory"
	setvar VAR_SCENE_SILPH, 3
# 183 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_REDPROTOBALL_COMPLETED
# 184 "data/maps/SilphCo_2F/scripts.pory"
	quest_complete_toast
# 185 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_SILPH_FOLLOWUP_ACTIVE
# 186 "data/maps/SilphCo_2F/scripts.pory"
	quest_start_toast
# 187 "data/maps/SilphCo_2F/scripts.pory"
	releaseall
	end

SilphCoScientist_EventScript_ProtoballTurnIn_2:
# 125 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 126 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 127 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_1
# 133 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 134 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 135 "data/maps/SilphCo_2F/scripts.pory"
	release
	end

SilphCoScientist_EventScript_ProtoballTurnIn_5:
# 146 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_FromEast
# 147 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
	goto SilphCoScientist_EventScript_ProtoballTurnIn_4

SilphCoScientist_EventScript_ProtoballTurnIn_6:
# 149 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_FromSouth
# 150 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
	goto SilphCoScientist_EventScript_ProtoballTurnIn_4

SilphCoScientist_EventScript_ProtoballTurnIn_7:
# 152 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_FromWest
# 153 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
	goto SilphCoScientist_EventScript_ProtoballTurnIn_4


# 191 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_ToDoor:
# 192 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 192 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 192 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 193 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 196 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_ToWorkbench:
# 197 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 197 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 197 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 197 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 197 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 197 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 197 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 198 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 198 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 198 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 198 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 198 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 198 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 199 "data/maps/SilphCo_2F/scripts.pory"
	face_down
# 200 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 200 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 200 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 200 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 201 "data/maps/SilphCo_2F/scripts.pory"
	face_left
	step_end

# 204 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_FromEast:
# 205 "data/maps/SilphCo_2F/scripts.pory"
	walk_left
# 206 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 206 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 207 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 210 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_FromWest:
# 211 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 212 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 212 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 213 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 216 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_FromSouth:
# 217 "data/maps/SilphCo_2F/scripts.pory"
	slide_left
# 218 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 219 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 220 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 223 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_PlayerToWorkbench:
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 224 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 225 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 225 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 225 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 225 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 225 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
	step_end

SilphCoScientist_Give_Protoball_Text_0:
# 22 "data/maps/SilphCo_2F/scripts.pory"
	.string "The data from your PROTOBALLS\n"
	.string "is already proving useful.\p"
	.string "We'll let you know when we need\n"
	.string "more field testing.$"

SilphCoScientist_Give_Protoball_Text_1:
# 40 "data/maps/SilphCo_2F/scripts.pory"
	.string "We're currently conducting research\n"
	.string "on Pokémon containment devices.\l"
	.string "Check back later!$"

SilphCoScientist_Give_Protoball_Text_2:
# 52 "data/maps/SilphCo_2F/scripts.pory"
	.string "Ah you must be Oak! \n"
	.string "Great, I could use some help.\p"
	.string "We're working on making containment \n"
	.string "devices for Pokemon. So far the \l"
	.string "science is theoretically sound,\l"
	.string "but we need someone to test it\l"
	.string "in the field.$"

SilphCoScientist_Give_Protoball_Text_3:
# 64 "data/maps/SilphCo_2F/scripts.pory"
	.string "These are PROTOBALLS. \p"
	.string "Using the design of Mr. Fuji's\n"
	.string "RESEARCH BALLS as a base we\l"
	.string "were able to create a version\l"
	.string "that allows for Pokemon to be\l"
	.string "released into the field without\l"
	.string "them immediately running away.\p"
	.string "The downside is they only work on \n"
	.string "weaker Pokemon for now, but we're\l"
	.string "working on improving that.\p"
	.string "Go out and catch some Pokemon and \n"
	.string "bring them back here for testing.\p"
	.string "Any 2 Pokemon will do!$"

SilphCoScientist_Give_Protoball_Text_4:
# 79 "data/maps/SilphCo_2F/scripts.pory"
	.string "SILPH TESTING$"

SilphCoScientist_Give_Protoball_Text_5:
# 80 "data/maps/SilphCo_2F/scripts.pory"
	.string "PROTOBALL TESTING$"

SilphCoScientist_EventScript_CheckProtoballTurnIn_Text_0:
# 97 "data/maps/SilphCo_2F/scripts.pory"
	.string "Still need two POKéMON caught\n"
	.string "with the PROTOBALLS I gave you.\l"
	.string "Research Balls won't work for\l"
	.string "this test.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_0:
# 116 "data/maps/SilphCo_2F/scripts.pory"
	.string "These the two you caught? \n"
	.string "Perfect, that's all we need.\p"
	.string "The PROTOBALL held up fine out\n"
	.string "there. That's good news for the\l"
	.string "containment side of things.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_1:
# 127 "data/maps/SilphCo_2F/scripts.pory"
	.string "There's something else, though.\p"
	.string "To hold anything stronger we'll\n"
	.string "need a better containment shell -\l"
	.string "two BLUE APRICORNS ought to do it.\p"
	.string "I hear they grow out on ROUTE 8,\n"
	.string "east of here.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_2:
# 140 "data/maps/SilphCo_2F/scripts.pory"
	.string "There's something else, though.\n"
	.string "Come with me.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_3:
# 171 "data/maps/SilphCo_2F/scripts.pory"
	.string "While we've got you here, let's\n"
	.string "upgrade those PROTOBALLS with what\l"
	.string "we learned from the field test.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_4:
# 176 "data/maps/SilphCo_2F/scripts.pory"
	.string "There - those are BLU PROTOBALLS\n"
	.string "now. Should hold up against\l"
	.string "tougher Pokemon.$"
