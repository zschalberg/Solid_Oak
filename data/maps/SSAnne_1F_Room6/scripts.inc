SSAnne_1F_Room6_MapScripts::
# 8 "data/maps/SSAnne_1F_Room6/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAnne_1F_Room6_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SSAnne_1F_Room6_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/SSAnne_1F_Room6/scripts.pory"
	map_script_2 VAR_MAP_SCENE_S_S_MINNOW_1F_CORRIDOR, 0, SSMinnow_1F_EventScript_ChoosePokemonCutscene
	.2byte 0


SSMinnow_1F_EventScript_ChoosePokemonCutscene::
# 14 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lockall
# 16 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_MAP_SCENE_S_S_MINNOW_1F_CORRIDOR, 1
# 18 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSMinnow_1F_Room6_Movement_Player
# 19 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSMinnow_1F_Room6_Movement_Agatha
# 20 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 22 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 23 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 24 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSMinnow_1F_EventScript_ChoosePokemonCutscene_Text_0
# 39 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 40 "data/maps/SSAnne_1F_Room6/scripts.pory"
	releaseall
	end


SSAnne_1F_Room6_EventScript_FinishStarterSelection::
# 45 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 46 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 47 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_0
# 51 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 52 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 53 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1
# 54 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 55 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 56 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 57 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_2
# 62 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 63 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 64 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 65 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_3
# 72 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 73 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 74 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 75 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_4
# 79 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 80 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 81 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSAnne_1F_Room6_Movement_Agatha_StepToTable
# 82 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 83 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSAnne_1F_Room6_Movement_Player_FaceUp
# 84 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 85 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_0x8D7, SSAnne_1F_Room6_EventScript_FinishStarterSelection_2
# 103 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_0x8D8, SSAnne_1F_Room6_EventScript_FinishStarterSelection_3
# 122 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 123 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 124 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 125 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_9
# 129 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 130 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 131 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 132 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 133 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_10
# 134 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 135 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 136 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 137 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 138 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
SSAnne_1F_Room6_EventScript_FinishStarterSelection_1:
# 140 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSAnne_1F_Room6_Movement_Agatha_FaceDown
# 141 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 142 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 143 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 144 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_11
# 146 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 147 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 148 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSMinnow_1F_Room6_Movement_Agatha_Leaves
# 149 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 150 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 6
# 151 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 152 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 153 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_12
# 156 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 157 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 158 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 159 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end

SSAnne_1F_Room6_EventScript_FinishStarterSelection_2:
# 86 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 87 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 88 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 89 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_5
# 93 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 94 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 95 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 96 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 97 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_6
# 98 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 99 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 100 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 101 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 102 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection_1

SSAnne_1F_Room6_EventScript_FinishStarterSelection_3:
# 104 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 105 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 106 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 107 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_7
# 111 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 112 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 113 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 114 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 115 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_8
# 116 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 117 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 118 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 119 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 120 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection_1


SSAnne_1F_Room6_EventScript_Agatha::
# 164 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 165 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 166 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_RIGHT
# 167 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 168 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Agatha_Text_0
# 169 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 170 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Arbor::
# 175 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 176 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 177 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 178 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 179 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_Arbor_2
# 183 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_1
SSAnne_1F_Room6_EventScript_Arbor_1:
# 185 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 186 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end

SSAnne_1F_Room6_EventScript_Arbor_2:
# 180 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_0
	goto SSAnne_1F_Room6_EventScript_Arbor_1


# 191 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Player:
# 192 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_down
	step_end

# 194 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha:
# 195 "data/maps/SSAnne_1F_Room6/scripts.pory"
	delay_16
# 196 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_right
# 197 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_down
	step_end

# 199 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_Movement_Agatha_StepToTable:
# 200 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_down
# 201 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_left
	step_end

# 203 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_Movement_Agatha_FaceDown:
# 204 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_down
	step_end

# 206 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_Movement_Player_FaceUp:
# 207 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_up
	step_end

# 209 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha_Leaves:
# 210 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_up
# 210 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_up
# 211 "data/maps/SSAnne_1F_Room6/scripts.pory"
	set_invisible
	step_end

# 214 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 215 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Woman::
# 216 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 217 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 218 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
# 219 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
# 220 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 221 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 222 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
# 223 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 224 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 225 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 226 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHeal::
# 227 "data/maps/SSAnne_1F_Room6/scripts.pory"
	checkplayergender
# 228 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
# 229 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
# 230 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 231 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 232 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 233 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHealMale::
# 234 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
# 235 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 236 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 237 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 238 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Growlithe::
# 239 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 240 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 241 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose
# 242 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 243 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 244 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteGrowlithe, MSGBOX_DEFAULT
# 245 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 246 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_GROWLITHE, 10, 3
# 247 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 248 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseGrowlithe, MSGBOX_YESNO
# 249 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 250 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseGrowlithe
# 251 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 252 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 253 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 254 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 255 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose::
# 256 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 257 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GrowlitheFriendly
# 258 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 259 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 260 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 261 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 262 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseGrowlithe::
# 263 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 264 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_GROWLITHE, 5, ball=ITEM_RED_PROTOBALL
# 265 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveGrowlitheParty
# 266 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveGrowlithePC
# 267 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 268 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 269 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 270 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlitheParty::
# 271 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 272 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 273 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 274 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 275 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 276 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 277 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 278 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 279 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 280 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 281 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 282 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 283 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 284 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 285 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 286 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlithePC::
# 287 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 0
# 288 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 289 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 290 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 291 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 292 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 293 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 294 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 295 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 296 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 297 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 298 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 299 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 300 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 301 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC::
# 302 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 303 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 304 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 305 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 306 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranM::
# 307 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 308 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 309 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose
# 310 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 311 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 312 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteNidoranM, MSGBOX_DEFAULT
# 313 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 314 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_NIDORAN_M, 10, 3
# 315 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 316 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseNidoranM, MSGBOX_YESNO
# 317 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 318 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseNidoranM
# 319 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 320 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 321 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 322 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 323 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose::
# 324 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 325 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_NidoranMFriendly
# 326 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 327 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 328 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 329 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 330 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseNidoranM::
# 331 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 332 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_NIDORAN_M, 5, ball=ITEM_RED_PROTOBALL
# 333 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveNidoranMParty
# 334 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveNidoranMPC
# 335 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 336 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 337 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 338 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMParty::
# 339 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 340 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 341 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 342 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 343 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 344 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 345 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 346 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 347 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 348 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 349 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 350 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 351 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 352 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 353 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 354 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMPC::
# 355 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 1
# 356 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 357 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 358 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 359 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 360 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 361 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 362 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 363 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 364 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 365 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 366 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 367 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 368 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 369 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC::
# 370 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 371 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 372 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 373 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 374 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Exeggcute::
# 375 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 376 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 377 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose
# 378 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 379 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 380 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteExeggcute, MSGBOX_DEFAULT
# 381 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 382 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_EXEGGCUTE, 10, 3
# 383 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 384 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseExeggcute, MSGBOX_YESNO
# 385 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 386 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseExeggcute
# 387 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 388 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 389 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 390 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 391 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose::
# 392 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 393 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ExeggcuteFriendly
# 394 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 395 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 396 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 397 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 398 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseExeggcute::
# 399 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 400 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_EXEGGCUTE, 5, ball=ITEM_RED_PROTOBALL
# 401 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveExeggcuteParty
# 402 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveExeggcutePC
# 403 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 404 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 405 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 406 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcuteParty::
# 407 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 408 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 409 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 410 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 411 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 412 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 413 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 414 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 415 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 416 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 417 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 418 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 419 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 420 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 421 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 422 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcutePC::
# 423 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_STARTER_MON, 2
# 424 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 425 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 426 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 427 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 428 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 429 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 430 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 431 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 432 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 433 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 434 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 435 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 436 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 437 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC::
# 438 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 439 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 440 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 441 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 442 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 443 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_TestBalls::
# 444 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 445 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 446 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 447 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 5
# 448 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLU_PROTOBALL, 5
# 449 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GRN_PROTOBALL, 5
# 450 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLK_PROTOBALL, 5
# 451 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CHERISH_BALL, 5
# 452 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_WORKBENCH, 1
# 453 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CONVERSION_KIT, 20
# 454 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_APRICORN, 10
# 455 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLUE_APRICORN, 10
# 456 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GREEN_APRICORN, 10
# 457 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLACK_APRICORN, 10
# 458 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_TEMP_2
# 459 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 5
# 460 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 461 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 462 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 463 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingNPC::
# 464 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 465 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 466 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistIntro, MSGBOX_YESNO
# 467 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_CraftingDecline
# 468 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto EventScript_CraftingLoop
# 469 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 470 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 471 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingDecline::
# 472 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistDecline
# 473 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 474 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end

SSMinnow_1F_EventScript_ChoosePokemonCutscene_Text_0:
# 24 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Ah. There you both are.\p"
	.string "We'll be in Vermilion Harbor\n"
	.string "inside the hour. I want you ready.\p"
	.string "Silph brought us here to help\n"
	.string "in their research of Pokémon\l"
	.string "containment devices. \p"
	.string "To do that, you'll need a partner\n"
	.string "Pokémon.\p"
	.string "I've given this some thought.\n"
	.string "There are three on the table.\p"
	.string "I'll let you look them over before\n"
	.string "you decide. Oak, the choice is\l"
	.string "yours first.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_0:
# 47 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Good. Take care of it.\p"
	.string "Whatever you're planning to do out\n"
	.string "there, your partner's condition will\l"
	.string "matter more than you think.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1:
# 53 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Alright, Agatha. Go ahead.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_2:
# 57 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Oh, no thanks, Professor.\p"
	.string "All of these ones look a bit too\n"
	.string "weak for me.\p"
	.string "I'll go out and catch one\n"
	.string "for myself.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_3:
# 65 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Now, Agatha, don't be reckless.\p"
	.string "The wilds outside are dangerous,\n"
	.string "and Silph expects both of my\l"
	.string "assistants to carry a partner for\l"
	.string "the field tests.\p"
	.string "You are not setting foot off this\n"
	.string "ship empty-handed. Take one.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_4:
# 75 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "...Tch. Fine, if you're going to\n"
	.string "insist, Professor.\p"
	.string "I suppose I can take one off your\n"
	.string "hands.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_5:
# 89 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Sammy took the GROWLITHE, huh?\p"
	.string "Fine, then I'll take this NIDORAN♂.\n"
	.string "At least it looks like it has\l"
	.string "some venom in it.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_6:
# 97 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Agatha received NIDORAN♂\nfrom PROFESSOR ARBOR!$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_7:
# 107 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Sammy went with NIDORAN♂, huh?\p"
	.string "Fine, then I'll take EXEGGCUTE.\n"
	.string "Odd little thing, but I'll make\l"
	.string "sure it learns how to fight.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_8:
# 115 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Agatha received EXEGGCUTE\nfrom PROFESSOR ARBOR!$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_9:
# 125 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Sammy picked EXEGGCUTE, huh?\p"
	.string "Fine, then I'll take GROWLITHE.\n"
	.string "It looks fiery enough to keep\l"
	.string "up with me.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_10:
# 133 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Agatha received GROWLITHE\nfrom PROFESSOR ARBOR!$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_11:
# 144 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Don't fall behind out there, Sammy!\n"
	.string "I'll see you in Vermilion!$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_12:
# 153 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "She'll be fine. She always is.\p"
	.string "Gather your things. I'll find you\n"
	.string "in the city once you're off the ship.$"

SSAnne_1F_Room6_EventScript_Agatha_Text_0:
# 168 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Go ahead and pick, Sammy!$"

SSAnne_1F_Room6_EventScript_Arbor_Text_0:
# 180 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "The harbor's close now.\n"
	.string "Get your things together.$"

SSAnne_1F_Room6_EventScript_Arbor_Text_1:
# 183 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Take your time. But not too much.$"
