LavenderTown_VolunteerPokemonHouse_MapScripts::
# 4 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_VolunteerPokemonHouse_OnTransition
# 5 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavenderTown_VolunteerPokemonHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LavenderTown_VolunteerPokemonHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	map_script_2 VAR_ACT1_LAVENDER, 0, LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro
	.2byte 0


LavenderTown_VolunteerPokemonHouse_OnTransition::
# 11 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setmetatile 11, 2, 0x028, FALSE
	end


LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro::
# 16 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lockall
# 17 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_ACT1_LAVENDER, 1
# 18 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 20 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 21 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_0
# 25 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 26 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_Player
# 27 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 28 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 29 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 30 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_1
# 31 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 32 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 34 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 35 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_2
# 42 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 44 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_3
# 51 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 53 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	giveitem ITEM_RESEARCH_BALL, 2
# 55 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 56 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FUJI
# 57 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 58 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_4
# 59 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 60 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 61 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 62 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_5
# 64 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 65 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 66 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement LOCALID_POKEHOUSE_AGATHA, LavenderTown_VolunteerPokemonHouse_Movement_AgathaExit
# 67 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 68 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	removeobject LOCALID_POKEHOUSE_AGATHA
# 69 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_HIDE_POKEHOUSE_AGATHA
# 70 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_LEFT
# 71 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 72 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_6
# 74 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 75 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FujiFaceDown
# 76 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 78 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 79 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_7
# 83 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 84 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_KRABBY_QUEST_GIVEN
# 85 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_MET_FUJI
# 86 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_HIDE_LAVENDER_FUJI
# 92 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_ACT1_FUCHSIA, 0
# 93 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	releaseall
	end


LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
# 98 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 99 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 100 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	goto_if_set FLAG_KRABBY_QUEST_COMPLETE, LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_2
# 107 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	goto_if_set FLAG_KRABBY_QUEST_GIVEN, LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_5
# 115 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_2
# 116 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1:
# 119 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_2:
# 101 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_0
# 105 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
	goto LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_5:
# 108 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_1
# 113 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
	goto LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1


LavenderTown_VolunteerPokemonHouse_EventScript_Agatha::
# 124 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 125 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 126 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 127 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 128 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Agatha_Text_0
# 129 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 130 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 131 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
# 136 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 137 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 138 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_0
# 142 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 143 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
# 148 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy_Text_0, MSGBOX_NPC
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
# 153 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 154 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 155 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_0
# 159 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 160 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
# 165 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 166 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 167 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitse
# 168 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
# 169 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino_Text_0
# 170 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 171 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmoncry
# 172 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
# 177 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 178 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 179 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitse
# 180 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 181 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck_Text_0
# 182 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 183 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmoncry
# 184 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
# 189 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine_Text_0, MSGBOX_SIGN
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
# 195 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf_Text_0, MSGBOX_SIGN
	end


# 200 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_AgathaExit:
# 201 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 201 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 201 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 201 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 201 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 202 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	set_invisible
	step_end

# 205 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_Player:
# 206 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 206 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 206 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 207 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_left
# 208 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_up
	step_end

# 211 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FUJI:
# 212 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_right
	step_end

# 215 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FujiFaceDown:
# 216 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_down
	step_end

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_0:
# 21 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Ah. You must be ARBOR's student.\p"
	.string "Come in, come in.\p"
	.string "I've been hoping you'd arrive\n"
	.string "before the week was out.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_1:
# 30 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "We've been waiting.\p$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_2:
# 35 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "There is a KRABBY population on\n"
	.string "the southern coast.\p"
	.string "Normally they cluster in the\n"
	.string "shallows near LAVENDER.\p"
	.string "This season, they've moved.\n"
	.string "All of them. Same direction.\p"
	.string "No one can explain it.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_3:
# 44 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "These are RESEARCH BALLS.\p"
	.string "I developed them for\n"
	.string "fieldwork like this.\p"
	.string "Catch a few KRABBY. Note the\n"
	.string "sizes, the weights.\p"
	.string "Bring them to me and I can\n"
	.string "tell you something useful.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_4:
# 58 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I have some for you as well.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_5:
# 62 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Fine.\p"
	.string "But I'm not writing the report.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_6:
# 72 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "She'll find her own way.\p"
	.string "She always does.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_7:
# 79 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Start with the shallows\n"
	.string "south of the RESERVE.\p"
	.string "Look for the heaviest ones.\n"
	.string "They'll be the oldest.$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_0:
# 101 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Thank you for the survey data.\p"
	.string "This confirms what I suspected.\p"
	.string "I'll have an analysis ready\n"
	.string "for you soon.$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_1:
# 108 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Have you found any KRABBY yet?\p"
	.string "The shallows south of the\n"
	.string "RESERVE are your best bet.\p"
	.string "Look for the heaviest ones.\n"
	.string "Those are the ones I want.$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_2:
# 115 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Ah. Come in, please.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Agatha_Text_0:
# 128 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Later.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_0:
# 138 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Mr. Fuji takes care of all the\n"
	.string "POKéMON nobody wants.\p"
	.string "Mama says he's been doing it\n"
	.string "since before she was born.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy_Text_0:
# 148 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "They're nicer than my brother.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_0:
# 155 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Mr. Fuji says you're a real\n"
	.string "researcher.\p"
	.string "Do researchers get to name\n"
	.string "new POKéMON?$"

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino_Text_0:
# 169 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "NIDO-RI-NO!$"

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck_Text_0:
# 181 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "PSY...$"

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine_Text_0:
# 189 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "A POKéMON fan magazine.\n"
	.string "The pages are well-worn.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf_Text_0:
# 195 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "POKéMON-related books\n"
	.string "line the shelf.$"
