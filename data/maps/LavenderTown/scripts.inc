LavenderTown_MapScripts::
# 2 "data/maps/LavenderTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0


LavenderTown_OnTransition::
# 6 "data/maps/LavenderTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	end


LavenderTown_EventScript_LittleGirl::
# 12 "data/maps/LavenderTown/scripts.pory"
	lock
# 13 "data/maps/LavenderTown/scripts.pory"
	faceplayer
# 14 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_LittleGirl_Text_0
# 17 "data/maps/LavenderTown/scripts.pory"
	closemessage
# 18 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_LittleGirl_Text_1
# 19 "data/maps/LavenderTown/scripts.pory"
	closemessage
# 20 "data/maps/LavenderTown/scripts.pory"
	release
	end


LavenderTown_EventScript_WorkerM::
# 26 "data/maps/LavenderTown/scripts.pory"
	lock
# 27 "data/maps/LavenderTown/scripts.pory"
	faceplayer
# 28 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_WorkerM_Text_0
# 32 "data/maps/LavenderTown/scripts.pory"
	closemessage
# 33 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_WorkerM_Text_1
# 36 "data/maps/LavenderTown/scripts.pory"
	closemessage
# 37 "data/maps/LavenderTown/scripts.pory"
	release
	end


LavenderTown_EventScript_Boy::
# 43 "data/maps/LavenderTown/scripts.pory"
	lock
# 44 "data/maps/LavenderTown/scripts.pory"
	faceplayer
# 45 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_Boy_Text_0
# 50 "data/maps/LavenderTown/scripts.pory"
	closemessage
# 51 "data/maps/LavenderTown/scripts.pory"
	release
	end


LavenderTown_EventScript_TownSign::
# 57 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_TownSign_Text_0, MSGBOX_SIGN
	end


LavenderTown_EventScript_SilphScopeNotice::
# 62 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_SilphScopeNotice_Text_0, MSGBOX_SIGN
	end


LavenderTown_EventScript_VolunteerHouseSign::
# 68 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_VolunteerHouseSign_Text_0, MSGBOX_SIGN
	end


LavenderTown_EventScript_PokemonTowerSign::
# 74 "data/maps/LavenderTown/scripts.pory"
	msgbox LavenderTown_EventScript_PokemonTowerSign_Text_0, MSGBOX_SIGN
	end


LavenderTown_EventScript_LittleGirl_Text_0:
# 14 "data/maps/LavenderTown/scripts.pory"
	.string "Papa says there's a GASTLY near\n"
	.string "the Tower.\p"
	.string "I want to see it but Mama says no.$"

LavenderTown_EventScript_LittleGirl_Text_1:
# 18 "data/maps/LavenderTown/scripts.pory"
	.string "Are you going to catch it?$"

LavenderTown_EventScript_WorkerM_Text_0:
# 28 "data/maps/LavenderTown/scripts.pory"
	.string "I'd stay away from the Tower for\n"
	.string "now if I were you.\p"
	.string "The Channelers say it's been\n"
	.string "unsettled lately. More than usual.$"

LavenderTown_EventScript_WorkerM_Text_1:
# 33 "data/maps/LavenderTown/scripts.pory"
	.string "I used to think that was just\n"
	.string "something they said.\p"
	.string "Not anymore.$"

LavenderTown_EventScript_Boy_Text_0:
# 45 "data/maps/LavenderTown/scripts.pory"
	.string "Researcher? If you mean Mr. Fuji,\n"
	.string "his office is south, near the base\l"
	.string "of the hill.\p"
	.string "He's been expecting someone\n"
	.string "from the mainland.$"

LavenderTown_EventScript_TownSign_Text_0:
# 57 "data/maps/LavenderTown/scripts.pory"
	.string "LAVENDER TOWN$"

LavenderTown_EventScript_SilphScopeNotice_Text_0:
# 62 "data/maps/LavenderTown/scripts.pory"
	.string "POKéMON TOWER\n"
	.string "Respect the spirits within.$"

LavenderTown_EventScript_VolunteerHouseSign_Text_0:
# 68 "data/maps/LavenderTown/scripts.pory"
	.string "MR. FUJI'S VOLUNTEER\n"
	.string "POKéMON HOUSE$"

LavenderTown_EventScript_PokemonTowerSign_Text_0:
# 74 "data/maps/LavenderTown/scripts.pory"
	.string "POKéMON TOWER\n"
	.string "A place of rest for Pokémon\l"
	.string "and those who loved them.$"
