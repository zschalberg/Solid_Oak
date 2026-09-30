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
# 45 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
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
# 67 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 68 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_4
# 78 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 80 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	giveitem ITEM_RESEARCH_BALL, 2
# 81 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
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
	clearmugshot
# 103 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FaceDown
# 104 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 105 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 106 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 107 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_8
# 111 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 112 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 113 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_KRABBY_QUEST_ACTIVE
# 114 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_HIDE_LAVENDER_FUJI
# 120 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_ACT1_FUCHSIA, 0
# 121 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_QUEST_MRFUJI_RESEARCH_COMPLETED
# 122 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	quest_complete_toast LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_9
# 123 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	quest_start_toast LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_10
# 124 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	releaseall
	end


LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
# 129 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 130 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 131 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	compare VAR_ACT1_LAVENDER, 3
	goto_if_eq LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_2
# 141 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	goto_if_set FLAG_KRABBY_QUEST_ACTIVE, LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_5
# 151 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 152 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 153 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_2
# 154 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1:
# 157 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_2:
# 132 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 133 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 134 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_0
# 139 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
	goto LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_5:
# 142 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 143 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 144 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_1
# 149 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
	goto LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_1


LavenderTown_VolunteerPokemonHouse_EventScript_Scientist::
# 162 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	goto_if_unset FLAG_HEARD_LAVENDER_STORAGE_SPEECH, LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_2
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_2:
# 163 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lockall
# 164 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 8, LavenderTown_VolunteerPokemonHouse_Movement_FaceLeft
# 165 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setspeaker LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_Text_0
# 166 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_Text_1
# 176 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 177 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_HEARD_LAVENDER_STORAGE_SPEECH
# 178 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	releaseall
	end


LavenderTown_VolunteerPokemonHouse_OnFrame::
# 193 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_TEMP_0, 1
# 194 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	compare VAR_ACT1_LAVENDER, 2
	goto_if_eq LavenderTown_VolunteerPokemonHouse_OnFrame_2
LavenderTown_VolunteerPokemonHouse_OnFrame_1:
	end

LavenderTown_VolunteerPokemonHouse_OnFrame_2:
# 195 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	call LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn
	goto LavenderTown_VolunteerPokemonHouse_OnFrame_1


LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn::
# 202 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lockall
# 203 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearflag FLAG_HIDE_LAVENDER_FUJI
# 204 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	addobject 1
# 205 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_FaceDown
# 206 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 207 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 208 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 209 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_0
# 210 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 211 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_Player
# 212 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 213 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 214 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 215 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_1
# 218 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 219 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 220 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_RIGHT
# 221 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 222 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_2
# 226 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 227 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 228 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 229 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 230 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_3
# 240 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 241 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 242 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement 1, LavenderTown_VolunteerPokemonHouse_Movement_WalkUp_WalkDown
# 243 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 244 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 245 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 246 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_4
# 258 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 259 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 260 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_FaceDown
# 261 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 262 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 263 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 264 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_5
# 265 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 266 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 267 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_VolunteerPokemonHouse_Movement_FaceUp
# 268 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmovement 0
# 269 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_MR_FUJI, MUGSHOT_LEFT
# 270 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 271 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_6
# 275 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 276 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 277 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_QUEST_FISHING_VILLAGE_COMPLETED
# 278 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setflag FLAG_QUEST_ZONE2_ACTIVE
# 279 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	quest_complete_toast LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_7
# 280 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	quest_start_toast LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_8
# 281 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setvar VAR_ACT1_LAVENDER, 3
# 282 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	releaseall
	return


LavenderTown_VolunteerPokemonHouse_EventScript_Agatha::
# 289 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 290 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 291 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 292 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 293 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Agatha_Text_0
# 294 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 295 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	clearmugshot
# 296 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
# 305 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 306 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 307 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_0
# 308 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 309 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 310 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setrespawn HEAL_LOCATION_LAVENDER_VOLUNTEER_HOUSE
# 311 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_1
# 313 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 314 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
# 319 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy_Text_0, MSGBOX_NPC
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
# 324 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 325 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 326 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	setspeaker LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_0
# 327 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_1
# 331 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 332 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
# 337 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 338 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 339 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitse
# 340 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
# 341 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino_Text_0
# 342 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 343 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmoncry
# 344 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
# 349 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	lock
# 350 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	faceplayer
# 351 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitse
# 352 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 353 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck_Text_0
# 354 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	closemessage
# 355 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	waitmoncry
# 356 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	release
	end


LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
# 361 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine_Text_0, MSGBOX_SIGN
	end


LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
# 367 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	msgbox LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf_Text_0, MSGBOX_SIGN
	end


# 376 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_AgathaExit:
# 377 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 377 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 377 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 377 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 377 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_down
# 378 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	set_invisible
	step_end

# 381 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_Player:
# 382 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 382 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 382 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 383 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_left
# 384 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_up
	step_end

# 387 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceRight:
# 388 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_right
	step_end

# 391 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceDown:
# 392 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_down
	step_end

# 395 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceLeft:
# 396 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_left
	step_end

# 398 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_FaceUp:
# 399 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	face_up
	step_end

# 402 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
LavenderTown_VolunteerPokemonHouse_Movement_WalkUp_WalkDown:
# 403 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	walk_up
# 404 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	delay_8
# 405 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	delay_2
# 406 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
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
# 107 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Start with the shallows\n"
	.string "south of FUCHSIA.\p"
	.string "Look for the heaviest ones.\n"
	.string "They'll be the oldest.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_9:
# 122 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "FUJI'S RESEARCH$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiIntro_Text_10:
# 123 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "KRAB FISHING$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_0:
# 134 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I'll meet you in PEWTER CITY.\p"
	.string "I have a colleague at the university\n"
	.string "who may be able to help us\l"
	.string "understand what is happening with\l"
	.string "these POKéMON.$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_1:
# 144 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Have you found any KRABBY yet?\p"
	.string "The shallows south of FUCHSIA\n"
	.string "are your best bet.\p"
	.string "Look for the heaviest ones.\n"
	.string "Those are the ones I want.$"

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji_Text_2:
# 153 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Ah. Come in, please.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_Text_0:
# 165 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Fuji's Aide$"

LavenderTown_VolunteerPokemonHouse_EventScript_Scientist_Text_1:
# 166 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Before you go, if you need to store\n"
	.string "any POKéMON, Mr. Fuji also cares\l"
	.string "for them here in the lab.\p"
	.string "Bring them to me in the back and\n"
	.string "we'll have them ready for you when\l"
	.string "you return.\p"
	.string "You can also use our couriers to\n"
	.string "send POKéMON here and swap them\l"
	.string "out in most major cities for a\l"
	.string "small fee.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_0:
# 209 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Ah, you're back.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_1:
# 216 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I was just going over the data from\n"
	.string "the Krabby you collected.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_2:
# 222 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Professor, TENTACRUEL attacked the\n"
	.string "FISHING VILLAGE. One of them was \l"
	.string "massive, like nothing I've seen.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_3:
# 230 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Hmm. That is troubling. I wonder if\n"
	.string "the KRABBY were retreating from the\l"
	.string "TENTACRUEL. It would explain their\l"
	.string "strange migration.\p"
	.string "But this breeds a new question:\n"
	.string "What is driving the TENTACRUEL to\l"
	.string "the FISHING VILLAGE and to attack?\p"
	.string "TENTACRUEL are known to be\n"
	.string "aggressive but usually only attack\l"
	.string "humans when they feel threatened.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_4:
# 246 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "I have some notes I need to review.\n"
	.string "I have a theory but we will need\l"
	.string "more data to confirm it.\p"
	.string "I heard similar strange reports from\n"
	.string "north of CERULEAN CITY and\l"
	.string "MT. MOON.\p"
	.string "Investigate those areas and see if\n"
	.string "you can find any clues. If you see\l"
	.string "any POKéMON that stand out like the\l"
	.string "giant TENTACRUEL, catch them and \l"
	.string "meet me in PEWTER CITY. I will be\l"
	.string "there consulting with a colleague.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_5:
# 264 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "And Oak...$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_6:
# 271 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Do be careful out there.\p"
	.string "If my theory is correct, these\n"
	.string "POKéMON may be more dangerous than\l"
	.string "we realize.$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_7:
# 279 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "DANGEROUS WATERS$"

LavenderTown_VolunteerPokemonHouse_EventScript_FujiReturn_Text_8:
# 280 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "MIGRATION ZONE 2$"

LavenderTown_VolunteerPokemonHouse_EventScript_Agatha_Text_0:
# 293 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Later.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_0:
# 307 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Here, let's rest your POKéMON.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl_Text_1:
# 311 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "All done!\p"
	.string "Your POKéMON are ready to go.$"

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy_Text_0:
# 319 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "They're nicer than my brother.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_0:
# 326 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Youngster$"

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster_Text_1:
# 327 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "Mr. Fuji says you're a real\n"
	.string "researcher.\p"
	.string "Do researchers get to name\n"
	.string "new POKéMON?$"

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino_Text_0:
# 341 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "NIDO-RI-NO!$"

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck_Text_0:
# 353 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "PSY...$"

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine_Text_0:
# 361 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "A POKéMON fan magazine.\n"
	.string "The pages are well-worn.$"

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf_Text_0:
# 367 "data/maps/LavenderTown_VolunteerPokemonHouse/scripts.pory"
	.string "POKéMON-related books\n"
	.string "line the shelf.$"
