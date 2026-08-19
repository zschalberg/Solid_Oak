LavenderTown_VolunteerPokemonHouse_MapScripts::
# 10 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_VolunteerPokemonHouse_OnTransition
# 11 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavenderTown_VolunteerPokemonHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LavenderTown_VolunteerPokemonHouse_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	map_script_2 VAR_ACT1_LAVENDER, 0, LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro
# 13 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, LavenderTown_VolunteerPokemonHouse_OnFrame
	.2byte 0


LavenderTown_VolunteerPokemonHouse_OnTransition::
# 18 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setmetatile 11, 2, 0x028, FALSE
	end


LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro::
# 27 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lockall
# 28 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_ACT1_LAVENDER, 1
# 29 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 30 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 31 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 32 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_0
# 36 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 37 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 38 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_Player
# 39 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 40 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 41 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 42 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_1
# 43 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 44 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 46 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 47 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_2
# 53 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 54 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FaceRight
# 55 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 56 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_3
# 64 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 65 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FaceDown
# 66 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 68 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_4
# 78 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 80 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	giveitem ITEM_RESEARCH_BALL, 2
# 82 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 83 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FaceRight
# 84 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 85 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_5
# 86 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 87 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 88 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 89 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_6
# 91 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 92 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 93 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement LOCALID_POKEHOUSE_AGATHA, LavenderTown_VolunteerPokemonHouse_Movement_AgathaExit
# 94 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 95 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	removeobject LOCALID_POKEHOUSE_AGATHA
# 96 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_HIDE_POKEHOUSE_AGATHA
# 97 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_LEFT
# 98 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 99 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_7
# 101 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 102 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FaceDown
# 103 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 105 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 106 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_8
# 110 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 111 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_KRABBY_QUEST_ACTIVE
# 112 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_HIDE_LAVENDER_FUJI
# 118 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_ACT1_FUCHSIA, 0
# 119 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	quest_start_toast LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_9
# 120 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	releaseall
	end


LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
# 125 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 126 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 127 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	compare VAR_ACT1_LAVENDER, 3
	goto_if_eq LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_2
# 136 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	goto_if_set FLAG_KRABBY_QUEST_ACTIVE, LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_5
# 146 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_2
# 147 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1:
# 150 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_2:
# 129 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 130 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_0
# 134 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
	goto LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_5:
# 138 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 139 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_1
# 144 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
	goto LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1


LavenderTown_VolunteerPokemonHouse_EventScript_Scientist::
# 155 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	goto_if_unset FLAG_HEARD_LAVENDER_STORAGE_SPEECH, LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_2
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_2:
# 156 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lockall
# 157 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 8, LavenderTown_VolunteerPokemonHouse_Movement_FaceLeft
# 158 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_Text_0
# 167 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 168 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_HEARD_LAVENDER_STORAGE_SPEECH
# 169 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	releaseall
	end


LavenderTown_VolunteerPokemonHouse_OnFrame::
# 184 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_TEMP_0, 1
# 185 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	compare VAR_ACT1_LAVENDER, 2
	goto_if_eq LavenderTown_VolunteerPokemonHouse_OnFrame_2
LavenderTown_VolunteerPokemonHouse_OnFrame_1:
	end

LavenderTown_VolunteerPokemonHouse_OnFrame_2:
# 186 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	call LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn
	goto LavenderTown_VolunteerPokemonHouse_OnFrame_1


LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn::
# 193 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lockall
# 194 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearflag FLAG_HIDE_LAVENDER_FUJI
# 195 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	addobject 1
# 196 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FaceDown
# 197 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 199 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 200 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_0
# 201 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 202 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_Player
# 203 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 205 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 206 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_1
# 209 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 211 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_RIGHT
# 212 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 213 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_2
# 217 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 218 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 220 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 221 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_3
# 231 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 233 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_WalkUp_WalkDown
# 234 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 236 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 237 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_4
# 248 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 250 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_FaceDown
# 251 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 253 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 254 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_5
# 255 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 257 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_FaceUp
# 258 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 260 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 261 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_6
# 264 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 266 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_QUEST_FISHING_VILLAGE_COMPLETED
# 267 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_QUEST_ZONE2_ACTIVE
# 268 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	quest_complete_toast LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_7
# 269 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	quest_start_toast LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_8
# 270 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_ACT1_LAVENDER, 3
# 271 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	releaseall
	return


LavenderTown_VolunteerPokemonHouse_EventScript_Agatha::
# 278 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 279 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 280 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 281 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 282 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Agatha_Text_0
# 283 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 284 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 285 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
# 294 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 295 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 296 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_0
# 297 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 298 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 299 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setrespawn HEAL_LOCATION_LAVENDER_VOLUNTEER_HOUSE
# 300 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_1
# 302 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 303 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
# 308 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy_Text_0, MSGBOX_NPC
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
# 313 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 314 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 315 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_0
# 319 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 320 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
# 325 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 326 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 327 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitse
# 328 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
# 329 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino_Text_0
# 330 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 331 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmoncry
# 332 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
# 337 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 338 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 339 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitse
# 340 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 341 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck_Text_0
# 342 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 343 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmoncry
# 344 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
# 349 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine_Text_0, MSGBOX_SIGN
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
# 355 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf_Text_0, MSGBOX_SIGN
	end


# 364 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_AgathaExit:
# 365 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 365 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 365 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 365 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 365 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 366 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	set_invisible
	step_end

# 369 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_Player:
# 370 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 370 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 370 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 371 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_left
# 372 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_up
	step_end

# 375 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceRight:
# 376 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_right
	step_end

# 379 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceDown:
# 380 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_down
	step_end

# 383 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceLeft:
# 384 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_left
	step_end

# 386 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceUp:
# 387 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_up
	step_end

# 390 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_WalkUp_WalkDown:
# 391 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 392 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	delay_8
# 393 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	delay_2
# 394 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
	step_end

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_0:
# 32 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Ah. You must be ARBOR's student.\p"
	.string "Come in, come in.\p"
	.string "I've been hoping you'd arrive\n"
	.string "before the week was out.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_1:
# 42 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "We've been waiting.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_2:
# 47 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "My research is focused on POKéMON\n"
	.string "and their habitiats.\p"
	.string "I study the ways in which POKéMON\n"
	.string "populations migrate and change.\p"
	.string "Recently I've noticed POKéMON acting\n"
	.string "in ways I haven't seen before.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_3:
# 57 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "There is a KRABBY population on\n"
	.string "the southern coast.\p"
	.string "Normally they cluster in the\n"
	.string "shallows near LAVENDER.\p"
	.string "This season, they've moved.\n"
	.string "All of them. Same direction.\p"
	.string "No one can explain it.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_4:
# 68 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "These are RESEARCH BALLS.\p"
	.string "I developed them for\n"
	.string "fieldwork like this.\p"
	.string "They can catch anything but\n"
	.string "can only be opened by specialized\l"
	.string "lab equipment.\p"
	.string "Catch a few KRABBY. Note the\n"
	.string "sizes, the weights.\p"
	.string "Bring them to me in FUCHSIA\n"
	.string "and we'll see what we can learn.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_5:
# 85 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I have some for you as well.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_6:
# 89 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Fine.\p"
	.string "But I'm not writing the report.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_7:
# 99 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "She'll find her own way.\p"
	.string "She always does.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_8:
# 106 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Start with the shallows\n"
	.string "south of FUCHSIA.\p"
	.string "Look for the heaviest ones.\n"
	.string "They'll be the oldest.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_9:
# 119 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "KRAB FISHING$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_0:
# 130 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I'll meet you in PEWTER CITY.\p"
	.string "I have a colleague at the university\n"
	.string "who may be able to help us understand\l"
	.string "what is happening with these POKéMON.$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_1:
# 139 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Have you found any KRABBY yet?\p"
	.string "The shallows south of FUCHSIA\n"
	.string "are your best bet.\p"
	.string "Look for the heaviest ones.\n"
	.string "Those are the ones I want.$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_2:
# 146 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Ah. Come in, please.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_Text_0:
# 158 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Before you go, if you need to store\n"
	.string "any POKéMON, Mr. Fuji also cares for\l"
	.string "them here in the lab.\p"
	.string "Bring them to me in the back and\n"
	.string "we'll have them ready for you when\l"
	.string "you return.\p"
	.string "You can also use our couriers to\n"
	.string "send POKéMON here and swap them out\n"
	.string "in most major cities for a small fee.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_0:
# 200 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Ah, you're back.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_1:
# 207 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I was just going over the data from\n"
	.string "the Krabby you collected.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_2:
# 213 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Professor, TENTACRUEL attacked the\n"
	.string "FISHING VILLAGE. One of them was \l"
	.string "massive, like nothing I've seen.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_3:
# 221 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Hmm. That is troubling. I wonder if\n"
	.string "the KRABBY were retreating from the\l"
	.string "TENTACRUEL. It would explain their\l"
	.string "strange migration.\p"
	.string "But this breeds a new question:\n"
	.string "What is driving the TENTACRUEL to\l"
	.string "the FISHING VILLAGE and to attack?\p"
	.string "TENTACRUEL are known to be aggressive\n"
	.string "but usually only attack humans when\l"
	.string "they feel threatened.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_4:
# 237 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I have some notes I need to review.\n"
	.string "I have a theory but we will need more\l"
	.string "data to confirm it. \p"
	.string "I heard similar strange reports from\n"
	.string "north of CERULEAN CITY and MT. MOON.\p"
	.string "Investigate those areas and see if\n"
	.string "you can find any clues. If you see\l"
	.string "any POKéMON that stand out like the\l"
	.string "giant TENTACRUEL, catch them and \l"
	.string "meet me in PEWTER CITY. I will be\l"
	.string "there consulting with a colleague.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_5:
# 254 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "And Oak...$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_6:
# 261 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Do be careful out there.\p"
	.string "If my theory is correct these POKéMON\n"
	.string "may be more dangerous than we realize.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_7:
# 268 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "DANGEROUS WATERS$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_8:
# 269 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "MIGRATION ZONE 2$"

LavenderTown_VolunteerPokemonHouse_EventScript_Agatha_Text_0:
# 282 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Later.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_0:
# 296 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Here, let's rest your POKéMON.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_1:
# 300 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "All done!\p"
	.string "Your POKéMON are ready to go.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy_Text_0:
# 308 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "They're nicer than my brother.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_0:
# 315 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Mr. Fuji says you're a real\n"
	.string "researcher.\p"
	.string "Do researchers get to name\n"
	.string "new POKéMON?$"

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino_Text_0:
# 329 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "NIDO-RI-NO!$"

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck_Text_0:
# 341 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "PSY...$"

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine_Text_0:
# 349 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "A POKéMON fan magazine.\n"
	.string "The pages are well-worn.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf_Text_0:
# 355 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "POKéMON-related books\n"
	.string "line the shelf.$"
