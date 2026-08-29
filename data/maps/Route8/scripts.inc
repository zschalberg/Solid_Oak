Route8_MapScripts::
# 2 "data/maps/Route8/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route8_OnLoad
	.byte 0


Route8_OnLoad::
# 10 "data/maps/Route8/scripts.pory"
	goto_if_set FLAG_GOT_BLUE_APRICORN_ROUTE8, Route8_OnLoad_2
# 13 "data/maps/Route8/scripts.pory"
	setflag FLAG_HIDE_ROUTE8_BERRY_PATCH
Route8_OnLoad_1:
	end

Route8_OnLoad_2:
# 11 "data/maps/Route8/scripts.pory"
	clearflag FLAG_HIDE_ROUTE8_BERRY_PATCH
	goto Route8_OnLoad_1


Route8_EventScript_UndergroundPathSign::
# 19 "data/maps/Route8/scripts.pory"
	msgbox Route8_EventScript_UndergroundPathSign_Text_0, MSGBOX_SIGN
	end


Route8_EventScript_ApricornTree::
# 28 "data/maps/Route8/scripts.pory"
	lock
# 29 "data/maps/Route8/scripts.pory"
	faceplayer
# 30 "data/maps/Route8/scripts.pory"
	goto_if_set FLAG_GOT_BLUE_APRICORN_ROUTE8, Route8_EventScript_ApricornTree_2
# 33 "data/maps/Route8/scripts.pory"
	giveitem ITEM_BLUE_APRICORN, 2
# 34 "data/maps/Route8/scripts.pory"
	setflag FLAG_GOT_BLUE_APRICORN_ROUTE8
Route8_EventScript_ApricornTree_1:
# 36 "data/maps/Route8/scripts.pory"
	release
	end

Route8_EventScript_ApricornTree_2:
# 31 "data/maps/Route8/scripts.pory"
	msgbox Route8_EventScript_ApricornTree_Text_0
	goto Route8_EventScript_ApricornTree_1


Route8_EventScript_UndergroundPathSign_Text_0:
# 19 "data/maps/Route8/scripts.pory"
	.string "UNDERGROUND PATH\n"
	.string "CELADON CITY - LAVENDER TOWN$"

Route8_EventScript_ApricornTree_Text_0:
# 31 "data/maps/Route8/scripts.pory"
	.string "The tree looks picked clean.$"
