SilphCo_2F_MapScripts::
# 2 "data/maps/SilphCo_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0


SilphCo_2F_OnLoad::
# 6 "data/maps/SilphCo_2F/scripts.pory"
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
# 7 "data/maps/SilphCo_2F/scripts.pory"
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end


SilphCoScientist_Give_Protoball::
# 15 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_SCENE_SILPH, 2
	goto_if_eq SilphCoScientist_Give_Protoball_2
# 29 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_SCENE_SILPH, 1
	goto_if_eq SilphCoScientist_Give_Protoball_5
# 33 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 34 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 35 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_1
# 42 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 43 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 44 "data/maps/SilphCo_2F/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 2
# 45 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 46 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 47 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_2
# 60 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_SILPH_TESTING_COMPLETED
# 61 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_REDPROTOBALL_ACTIVE
# 62 "data/maps/SilphCo_2F/scripts.pory"
	quest_complete_toast SilphCoScientist_Give_Protoball_Text_3
# 63 "data/maps/SilphCo_2F/scripts.pory"
	quest_start_toast SilphCoScientist_Give_Protoball_Text_4
# 64 "data/maps/SilphCo_2F/scripts.pory"
	releaseall
	end

SilphCoScientist_Give_Protoball_2:
# 16 "data/maps/SilphCo_2F/scripts.pory"
	lock
# 17 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 18 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 19 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 20 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_0
# 24 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 25 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 26 "data/maps/SilphCo_2F/scripts.pory"
	release
	end

SilphCoScientist_Give_Protoball_5:
# 30 "data/maps/SilphCo_2F/scripts.pory"
	goto SilphCoScientist_EventScript_CheckProtoballTurnIn
	end


SilphCoScientist_EventScript_CheckProtoballTurnIn::
# 72 "data/maps/SilphCo_2F/scripts.pory"
	specialvar VAR_0x8006, CountRedProtoballCaughtMons
# 74 "data/maps/SilphCo_2F/scripts.pory"
	compare VAR_0x8006, 2
	goto_if_lt SilphCoScientist_EventScript_CheckProtoballTurnIn_2
# 88 "data/maps/SilphCo_2F/scripts.pory"
	goto SilphCoScientist_EventScript_ProtoballTurnIn
	end

SilphCoScientist_EventScript_CheckProtoballTurnIn_2:
# 75 "data/maps/SilphCo_2F/scripts.pory"
	lock
# 76 "data/maps/SilphCo_2F/scripts.pory"
	faceplayer
# 77 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 78 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 79 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_CheckProtoballTurnIn_Text_0
# 83 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 84 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 85 "data/maps/SilphCo_2F/scripts.pory"
	release
	end


SilphCoScientist_EventScript_ProtoballTurnIn::
# 94 "data/maps/SilphCo_2F/scripts.pory"
	lockall
# 95 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 96 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 97 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_EventScript_ProtoballTurnIn_Text_0
# 105 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 106 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 107 "data/maps/SilphCo_2F/scripts.pory"
	setvar VAR_SCENE_SILPH, 2
# 108 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_REDPROTOBALL_COMPLETED
# 109 "data/maps/SilphCo_2F/scripts.pory"
	quest_complete_toast
# 110 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_SILPH_FOLLOWUP_ACTIVE
# 111 "data/maps/SilphCo_2F/scripts.pory"
	quest_start_toast
# 112 "data/maps/SilphCo_2F/scripts.pory"
	releaseall
	end


SilphCoScientist_Give_Protoball_Text_0:
# 20 "data/maps/SilphCo_2F/scripts.pory"
	.string "The data from your PROTOBALLS\n"
	.string "is already proving useful.\p"
	.string "We'll let you know when we need\n"
	.string "more field testing.$"

SilphCoScientist_Give_Protoball_Text_1:
# 35 "data/maps/SilphCo_2F/scripts.pory"
	.string "Ah you must be Oak! \n"
	.string "Great, I could use some help.\p"
	.string "We're working on making containment \n"
	.string "devices for Pokemon. So far the \l"
	.string "science is theoretically sound,\l"
	.string "but we need someone to test it\l"
	.string "in the field.$"

SilphCoScientist_Give_Protoball_Text_2:
# 47 "data/maps/SilphCo_2F/scripts.pory"
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

SilphCoScientist_Give_Protoball_Text_3:
# 62 "data/maps/SilphCo_2F/scripts.pory"
	.string "SILPH TESTING$"

SilphCoScientist_Give_Protoball_Text_4:
# 63 "data/maps/SilphCo_2F/scripts.pory"
	.string "PROTOBALL TESTING$"

SilphCoScientist_EventScript_CheckProtoballTurnIn_Text_0:
# 79 "data/maps/SilphCo_2F/scripts.pory"
	.string "Still need two POKéMON caught\n"
	.string "with the PROTOBALLS I gave you.\l"
	.string "Research Balls won't work for\l"
	.string "this test.$"

SilphCoScientist_EventScript_ProtoballTurnIn_Text_0:
# 97 "data/maps/SilphCo_2F/scripts.pory"
	.string "These the two you caught? \n"
	.string "Perfect, that's all we need.\p"
	.string "The PROTOBALL held up fine out\n"
	.string "there. That's good news for the\l"
	.string "containment side of things.\p"
	.string "There's something else, though.\n"
	.string "Come find me again once you've\l"
	.string "had a chance to settle in.$"
