Route12_MapScripts::
# 2 "data/maps/Route12/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route12_OnTransition
	.byte 0


Route12_OnTransition::
# 6 "data/maps/Route12/scripts.pory"
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	end


Route12_EventScript_Snorlax::
	end


Route12_EventScript_RouteSign::
# 15 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_RouteSign_Text_0, MSGBOX_SIGN
	end


Route12_EventScript_FishingSign::
# 22 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_FishingSign_Text_0, MSGBOX_SIGN
	end


Route12_EventScript_VillageNPC1::
# 31 "data/maps/Route12/scripts.pory"
	lock
# 32 "data/maps/Route12/scripts.pory"
	faceplayer
# 33 "data/maps/Route12/scripts.pory"
	compare VAR_ACT1_FUCHSIA, 1
	goto_if_eq Route12_EventScript_VillageNPC1_2
# 39 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC1_Text_1
# 46 "data/maps/Route12/scripts.pory"
	closemessage
Route12_EventScript_VillageNPC1_1:
# 48 "data/maps/Route12/scripts.pory"
	release
	end

Route12_EventScript_VillageNPC1_2:
# 34 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC1_Text_0
# 37 "data/maps/Route12/scripts.pory"
	closemessage
	goto Route12_EventScript_VillageNPC1_1


Route12_EventScript_VillageNPC2::
# 53 "data/maps/Route12/scripts.pory"
	lock
# 54 "data/maps/Route12/scripts.pory"
	faceplayer
# 55 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC2_Text_0
# 57 "data/maps/Route12/scripts.pory"
	closemessage
# 58 "data/maps/Route12/scripts.pory"
	release
	end


Route12_EventScript_VillageNPC3::
# 63 "data/maps/Route12/scripts.pory"
	lock
# 64 "data/maps/Route12/scripts.pory"
	faceplayer
# 65 "data/maps/Route12/scripts.pory"
	compare VAR_ACT1_FUCHSIA, 1
	goto_if_eq Route12_EventScript_VillageNPC3_2
# 70 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC3_Text_1
# 73 "data/maps/Route12/scripts.pory"
	closemessage
Route12_EventScript_VillageNPC3_1:
# 75 "data/maps/Route12/scripts.pory"
	release
	end

Route12_EventScript_VillageNPC3_2:
# 66 "data/maps/Route12/scripts.pory"
	msgbox Route12_EventScript_VillageNPC3_Text_0
# 68 "data/maps/Route12/scripts.pory"
	closemessage
	goto Route12_EventScript_VillageNPC3_1


Route12_EventScript_RouteSign_Text_0:
# 15 "data/maps/Route12/scripts.pory"
	.string "ROUTE 12\n"
	.string "LAVENDER TOWN is to the north.\l"
	.string "ROUTE 13 connects to the south.$"

Route12_EventScript_FishingSign_Text_0:
# 22 "data/maps/Route12/scripts.pory"
	.string "ROUTE 12 FISHING RESERVE\n"
	.string "Sport fishing permitted.$"

Route12_EventScript_VillageNPC1_Text_0:
# 34 "data/maps/Route12/scripts.pory"
	.string "It's getting worse.\n"
	.string "Last night we couldn't even\l"
	.string "get a boat out.$"

Route12_EventScript_VillageNPC1_Text_1:
# 39 "data/maps/Route12/scripts.pory"
	.string "You here to fish?\n"
	.string "Not the best time for it.\p"
	.string "The TENTACOOL have been thick\n"
	.string "all week.\p"
	.string "It's not just the count.\n"
	.string "they're moving different.\l"
	.string "More... together.$"

Route12_EventScript_VillageNPC2_Text_0:
# 55 "data/maps/Route12/scripts.pory"
	.string "My husband says it'll pass.\p"
	.string "He said that last week too.$"

Route12_EventScript_VillageNPC3_Text_0:
# 66 "data/maps/Route12/scripts.pory"
	.string "I'm starting to think\n"
	.string "my husband's wrong.$"

Route12_EventScript_VillageNPC3_Text_1:
# 70 "data/maps/Route12/scripts.pory"
	.string "Seen rough seasons before.\p"
	.string "This isn't rough.\n"
	.string "This is something else.$"
