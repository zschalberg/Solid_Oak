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
	lock
# 25 "data/maps/Fishing_Village_Entrance/scripts.pory"
	faceplayer
# 26 "data/maps/Fishing_Village_Entrance/scripts.pory"
	compare VAR_ACT1_FUCHSIA, 1
	goto_if_ge Fishing_Village_Entrance_Fisherman_2
# 32 "data/maps/Fishing_Village_Entrance/scripts.pory"
	msgbox Fishing_Village_Entrance_Fisherman_Text_1
# 37 "data/maps/Fishing_Village_Entrance/scripts.pory"
	closemessage
Fishing_Village_Entrance_Fisherman_1:
# 39 "data/maps/Fishing_Village_Entrance/scripts.pory"
	release
	end

Fishing_Village_Entrance_Fisherman_2:
# 27 "data/maps/Fishing_Village_Entrance/scripts.pory"
	msgbox Fishing_Village_Entrance_Fisherman_Text_0
# 30 "data/maps/Fishing_Village_Entrance/scripts.pory"
	closemessage
	goto Fishing_Village_Entrance_Fisherman_1


Fishing_Village_Entrance_EventScript_Zone1Intro_Text_0:
# 14 "data/maps/Fishing_Village_Entrance/scripts.pory"
	.string "You're back. Something's in\n"
	.string "the water.\p"
	.string "A big one. We can't get to\n"
	.string "the boats.$"

Fishing_Village_Entrance_Fisherman_Text_0:
# 27 "data/maps/Fishing_Village_Entrance/scripts.pory"
	.string "Something's in the water.\p"
	.string "A big one. We can't get to\n"
	.string "the boats.$"

Fishing_Village_Entrance_Fisherman_Text_1:
# 32 "data/maps/Fishing_Village_Entrance/scripts.pory"
	.string "Heading through to the village?\p"
	.string "Not the best time for fishing.\n"
	.string "The TENTACOOL have been thick\l"
	.string "in the shallows all week.\p"
	.string "Keep your wits about you.$"
