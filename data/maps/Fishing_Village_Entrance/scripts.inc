Fishing_Village_Entrance_MapScripts::
# 2 "data/maps/Fishing_Village_Entrance/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Fishing_Village_Entrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Fishing_Village_Entrance_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/Fishing_Village_Entrance/scripts.pory"
	map_script_2 VAR_ACT1_FUCHSIA, 1, Fishing_Village_Entrance_EventScript_Zone1Intro
	.2byte 0


Fishing_Village_Entrance_EventScript_Zone1Intro::
# 12 "data/maps/Fishing_Village_Entrance/scripts.pory"
	lockall
# 13 "data/maps/Fishing_Village_Entrance/scripts.pory"
	setvar VAR_ACT1_FUCHSIA, 2
# 14 "data/maps/Fishing_Village_Entrance/scripts.pory"
	msgbox Fishing_Village_Entrance_EventScript_Zone1Intro_Text_0
# 18 "data/maps/Fishing_Village_Entrance/scripts.pory"
	closemessage
# 19 "data/maps/Fishing_Village_Entrance/scripts.pory"
	releaseall
	end


Fishing_Village_Entrance_Fisherman::
# 24 "data/maps/Fishing_Village_Entrance/scripts.pory"
	lockall
# 25 "data/maps/Fishing_Village_Entrance/scripts.pory"
	faceplayer
# 26 "data/maps/Fishing_Village_Entrance/scripts.pory"
	msgbox Fishing_Village_Entrance_EventScript_Zone1Intro_Text_0
# 30 "data/maps/Fishing_Village_Entrance/scripts.pory"
	releaseall
	end


Fishing_Village_Entrance_EventScript_Zone1Intro_Text_0:
# 14 "data/maps/Fishing_Village_Entrance/scripts.pory"
	.string "You're back. Something's in\n"
	.string "the water.\p"
	.string "A big one. We can't get to\n"
	.string "the boats.$"
