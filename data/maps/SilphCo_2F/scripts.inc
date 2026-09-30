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
	closemessage
# 78 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 79 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_SILPH_TESTING_COMPLETED
# 80 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_REDPROTOBALL_ACTIVE
# 81 "data/maps/SilphCo_2F/scripts.pory"
	quest_complete_toast SilphCoScientist_Give_Protoball_Text_4
# 82 "data/maps/SilphCo_2F/scripts.pory"
	quest_start_toast SilphCoScientist_Give_Protoball_Text_5
# 83 "data/maps/SilphCo_2F/scripts.pory"
	setvar VAR_SCENE_SILPH, 2
# 84 "data/maps/SilphCo_2F/scripts.pory"
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
# 92 "data/maps/SilphCo_2F/scripts.pory"
	specialvar VAR_0x8006, CountRedProtoballCaughtMons
# 94 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_0x8006, 2
	goto_if_lt SilphCoScientist_EventScript_CheckProtoballTurnIn_2
# 108 "data/maps/SilphCo_2F/scripts.pory"
	goto SilphCoScientist_EventScript_ProtoballTurnIn
	end

SilphCoScientist_EventScript_CheckProtoballTurnIn_2:
# 95 "data/maps/SilphCo_2F/scripts.pory"
	lock
# 96 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 97 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 98 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 99 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_CheckProtoballTurnIn_Text_0
# 103 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 104 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 105 "data/maps/SilphCo_2F/scripts.pory"
	release
	end


SilphCoScientist_EventScript_ProtoballTurnIn::
# 114 "data/maps/SilphCo_2F/scripts.pory"
	lockall
# 115 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 116 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 117 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 118 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_0
# 123 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 124 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 125 "data/maps/SilphCo_2F/scripts.pory"
	checkitem ITEM_BLUE_APRICORN, 2
# 126 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_2
# 140 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 141 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 142 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_2
# 144 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 145 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 146 "data/maps/SilphCo_2F/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 147 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, DIR_WEST
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_5
# 150 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_6
# 153 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_RESULT, DIR_EAST
	goto_if_eq SilphCoScientist_EventScript_ProtoballTurnIn_7
# 157 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_ToDoor
# 158 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
SilphCoScientist_EventScript_ProtoballTurnIn_4:
# 160 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement 1
# 161 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 162 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_SILPH_2F_DOOR_1
# 163 "data/maps/SilphCo_2F/scripts.pory"
	call EventScript_Open2FDoor1
# 164 "data/maps/SilphCo_2F/scripts.pory"
	playse SE_UNLOCK
# 165 "data/maps/SilphCo_2F/scripts.pory"
	special DrawWholeMapView
# 166 "data/maps/SilphCo_2F/scripts.pory"
	waitse
# 167 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToWorkbench
# 168 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_PlayerToWorkbench
# 169 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement 1
# 170 "data/maps/SilphCo_2F/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 171 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 172 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 173 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_3
# 176 "data/maps/SilphCo_2F/scripts.pory"
	removeitem ITEM_BLUE_APRICORN, 2
# 177 "data/maps/SilphCo_2F/scripts.pory"
	special UpgradeRedProtoballCaughtMons
# 178 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_4
# 181 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 182 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 184 "data/maps/SilphCo_2F/scripts.pory"
	setvar VAR_SCENE_SILPH, 3
# 185 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_REDPROTOBALL_COMPLETED
# 186 "data/maps/SilphCo_2F/scripts.pory"
	quest_complete_toast
# 187 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_SILPH_FOLLOWUP_ACTIVE
# 188 "data/maps/SilphCo_2F/scripts.pory"
	quest_start_toast
# 189 "data/maps/SilphCo_2F/scripts.pory"
	releaseall
	end

SilphCoScientist_EventScript_ProtoballTurnIn_2:
# 127 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 128 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 129 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_1
# 135 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 136 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 137 "data/maps/SilphCo_2F/scripts.pory"
	release
	end

SilphCoScientist_EventScript_ProtoballTurnIn_5:
# 148 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_FromEast
# 149 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
	goto SilphCoScientist_EventScript_ProtoballTurnIn_4

SilphCoScientist_EventScript_ProtoballTurnIn_6:
# 151 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_FromSouth
# 152 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
	goto SilphCoScientist_EventScript_ProtoballTurnIn_4

SilphCoScientist_EventScript_ProtoballTurnIn_7:
# 154 "data/maps/SilphCo_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SilphCo_Movement_FromWest
# 155 "data/maps/SilphCo_2F/scripts.pory"
	applymovement 1, SilphCo_Movement_ToDoor
	goto SilphCoScientist_EventScript_ProtoballTurnIn_4


# 193 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_ToDoor:
# 194 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 194 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 194 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 195 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 198 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_ToWorkbench:
# 199 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 199 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 199 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 199 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 199 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 199 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 199 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 200 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 200 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 200 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 200 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 200 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 200 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 201 "data/maps/SilphCo_2F/scripts.pory"
	face_down
# 202 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 202 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 202 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 202 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
# 203 "data/maps/SilphCo_2F/scripts.pory"
	face_left
	step_end

# 206 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_FromEast:
# 207 "data/maps/SilphCo_2F/scripts.pory"
	walk_left
# 208 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 208 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 209 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 212 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_FromWest:
# 213 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 214 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 214 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 215 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 218 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_FromSouth:
# 219 "data/maps/SilphCo_2F/scripts.pory"
	slide_left
# 220 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 221 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 222 "data/maps/SilphCo_2F/scripts.pory"
	delay_16
	step_end

# 225 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_Movement_PlayerToWorkbench:
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 226 "data/maps/SilphCo_2F/scripts.pory"
	walk_down
# 227 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 227 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 227 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 227 "data/maps/SilphCo_2F/scripts.pory"
	walk_right
# 227 "data/maps/SilphCo_2F/scripts.pory"
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
# 81 "data/maps/SilphCo_2F/scripts.pory"
	.string "SILPH TESTING$"

SilphCoScientist_Give_Protoball_Text_5:
# 82 "data/maps/SilphCo_2F/scripts.pory"
	.string "PROTOBALL TESTING$"

SilphCoScientist_EventScript_CheckProtoballTurnIn_Text_0:
# 99 "data/maps/SilphCo_2F/scripts.pory"
	.string "Still need two POKéMON caught\n"
	.string "with the PROTOBALLS I gave you.\l"
	.string "Research Balls won't work for\l"
	.string "this test.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_0:
# 118 "data/maps/SilphCo_2F/scripts.pory"
	.string "These the two you caught? \n"
	.string "Perfect, that's all we need.\p"
	.string "The PROTOBALL held up fine out\n"
	.string "there. That's good news for the\l"
	.string "containment side of things.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_1:
# 129 "data/maps/SilphCo_2F/scripts.pory"
	.string "There's something else, though.\p"
	.string "To hold anything stronger we'll\n"
	.string "need a better containment shell -\l"
	.string "two BLUE APRICORNS ought to do it.\p"
	.string "I hear they grow out on ROUTE 8,\n"
	.string "east of here.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_2:
# 142 "data/maps/SilphCo_2F/scripts.pory"
	.string "There's something else, though.\n"
	.string "Come with me.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_3:
# 173 "data/maps/SilphCo_2F/scripts.pory"
	.string "While we've got you here, let's\n"
	.string "upgrade those PROTOBALLS with what\l"
	.string "we learned from the field test.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_4:
# 178 "data/maps/SilphCo_2F/scripts.pory"
	.string "There - those are BLU PROTOBALLS\n"
	.string "now. Should hold up against\l"
	.string "tougher Pokemon.$"
