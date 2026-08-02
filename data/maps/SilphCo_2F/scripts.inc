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
# 12 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 13 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 14 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_0
# 21 "data/maps/SilphCo_2F/scripts.pory"
	closemessage
# 22 "data/maps/SilphCo_2F/scripts.pory"
	clearmugshot
# 23 "data/maps/SilphCo_2F/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 2
# 24 "data/maps/SilphCo_2F/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 25 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 26 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCoScientist_Give_Protoball_Text_1
# 38 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_QUEST_REDPROTOBALL_ACTIVE
# 39 "data/maps/SilphCo_2F/scripts.pory"
	releaseall
	end


SilphCoScientist_Give_Protoball_Text_0:
# 14 "data/maps/SilphCo_2F/scripts.pory"
	.string "Ah you must be Oak! \n"
	.string "Great, I could use some help.\p"
	.string "We're working on making containment \n"
	.string "devices for Pokemon. So far the \l"
	.string "science is theoretically sound,\l"
	.string "but we need someone to test it\l"
	.string "in the field.$"

SilphCoScientist_Give_Protoball_Text_1:
# 26 "data/maps/SilphCo_2F/scripts.pory"
	.string "These are PROTOBALLS. Using the design\n"
	.string "of Mr. Fuji's RESEARCH BALLS as a \l"
	.string "base we were able to create a \l"
	.string "version that allows for Pokemon\l"
	.string "to be released into the field \l"
	.string "without them running away immediately.\p"
	.string "The downside is they only work on \n"
	.string "weaker Pokemon for now, but we're\l"
	.string "working on improving that.\p"
	.string "Go out and catch some Pokemon and \n"
	.string "bring them back here for testing.\p"
	.string "Any 2 Pokemon will do!$"
