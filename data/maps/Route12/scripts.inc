Route12_MapScripts::
# 2 "data/maps/Route12/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
# 3 "data/maps/Route12/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route12_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Route12_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/Route12/scripts.pory"
	map_script_2 VAR_ACT1_FUCHSIA, 1, Route12_EventScript_Zone1Intro
	.2byte 0


Route12_OnTransition::
# 9 "data/maps/Route12/scripts.pory"
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	end


Route12_EventScript_Snorlax::
	end


Route12_EventScript_RouteSign::
# 18 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route12_EventScript_FishingSign::
# 25 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_FishingSign_Text_0, MSGBOX_SIGN
	end


Route12_EventScript_VillageNPC1::
# 34 "data/maps/Route12/scripts.pory"
	lock
# 35 "data/maps/Route12/scripts.pory"
	faceplayer
# 36 "data/maps/Route12/scripts.pory"
	compare VAR_ACT1_FUCHSIA, 1
	goto_if_eq Route12_EventScript_VillageNPC1_2
# 42 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC1_Text_1
# 49 "data/maps/Route12/scripts.pory"
	closemessage
Route12_EventScript_VillageNPC1_1:
# 51 "data/maps/Route12/scripts.pory"
	release
	end

Route12_EventScript_VillageNPC1_2:
# 37 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC1_Text_0
# 40 "data/maps/Route12/scripts.pory"
	closemessage
	goto Route12_EventScript_VillageNPC1_1


Route12_EventScript_VillageNPC2::
# 56 "data/maps/Route12/scripts.pory"
	lock
# 57 "data/maps/Route12/scripts.pory"
	faceplayer
# 58 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC2_Text_0
# 60 "data/maps/Route12/scripts.pory"
	closemessage
# 61 "data/maps/Route12/scripts.pory"
	release
	end


Route12_EventScript_VillageNPC3::
# 66 "data/maps/Route12/scripts.pory"
	lock
# 67 "data/maps/Route12/scripts.pory"
	faceplayer
# 68 "data/maps/Route12/scripts.pory"
	compare VAR_ACT1_FUCHSIA, 1
	goto_if_eq Route12_EventScript_VillageNPC3_2
# 73 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC3_Text_1
# 76 "data/maps/Route12/scripts.pory"
	closemessage
Route12_EventScript_VillageNPC3_1:
# 78 "data/maps/Route12/scripts.pory"
	release
	end

Route12_EventScript_VillageNPC3_2:
# 69 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC3_Text_0
# 71 "data/maps/Route12/scripts.pory"
	closemessage
	goto Route12_EventScript_VillageNPC3_1


Route12_EventScript_Zone1Intro::
# 88 "data/maps/Route12/scripts.pory"
	lockall
# 89 "data/maps/Route12/scripts.pory"
	setvar VAR_ACT1_FUCHSIA, 2
# 90 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_Zone1Intro_Text_0
# 94 "data/maps/Route12/scripts.pory"
	closemessage
# 95 "data/maps/Route12/scripts.pory"
	releaseall
	end


Route12_EventScript_RouteSign_Text_0:
# 18 "data/maps/Route12/scripts.pory"
	.string "ROUTE 12\n"
	.string "LAVENDER TOWN is to the north.\l"
	.string "ROUTE 13 connects to the south.$"

Route12_EventScript_FishingSign_Text_0:
# 25 "data/maps/Route12/scripts.pory"
	.string "ROUTE 12 FISHING RESERVE\n"
	.string "Sport fishing permitted.$"

Route12_EventScript_VillageNPC1_Text_0:
# 37 "data/maps/Route12/scripts.pory"
	.string "It's getting worse.\n"
	.string "Last night we couldn't even\l"
	.string "get a boat out.$"

Route12_EventScript_VillageNPC1_Text_1:
# 42 "data/maps/Route12/scripts.pory"
	.string "You here to fish?\n"
	.string "Not the best time for it.\p"
	.string "The TENTACOOL have been thick\n"
	.string "all week.\p"
	.string "It's not just the count.\n"
	.string "they're moving different.\l"
	.string "More... together.$"

Route12_EventScript_VillageNPC2_Text_0:
# 58 "data/maps/Route12/scripts.pory"
	.string "My husband says it'll pass.\p"
	.string "He said that last week too.$"

Route12_EventScript_VillageNPC3_Text_0:
# 69 "data/maps/Route12/scripts.pory"
	.string "I'm starting to think\n"
	.string "my husband's wrong.$"

Route12_EventScript_VillageNPC3_Text_1:
# 73 "data/maps/Route12/scripts.pory"
	.string "Seen rough seasons before.\p"
	.string "This isn't rough.\n"
	.string "This is something else.$"

Route12_EventScript_Zone1Intro_Text_0:
# 90 "data/maps/Route12/scripts.pory"
	.string "You're back. Something's in\n"
	.string "the water.\p"
	.string "A big one. We can't get to\n"
	.string "the boats.$"
