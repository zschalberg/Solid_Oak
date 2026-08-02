SSAnne_1F_Room6_MapScripts::
# 5 "data/maps/SSAnne_1F_Room6/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAnne_1F_Room6_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SSAnne_1F_Room6_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/SSAnne_1F_Room6/scripts.pory"
	map_script_2 VAR_MAP_SCENE_S_S_MINNOW_1F_CORRIDOR, 0, SSMinnow_1F_EventScript_ChoosePokemonCutscene
	.2byte 0


SSMinnow_1F_EventScript_ChoosePokemonCutscene::
# 11 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lockall
# 13 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setvar VAR_MAP_SCENE_S_S_MINNOW_1F_CORRIDOR, 1
# 15 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SSMinnow_1F_Room6_Movement_Player
# 16 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSMinnow_1F_Room6_Movement_Agatha
# 17 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 19 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 20 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 21 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSMinnow_1F_EventScript_ChoosePokemonCutscene_Text_0
# 36 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 37 "data/maps/SSAnne_1F_Room6/scripts.pory"
	releaseall
	end


SSAnne_1F_Room6_EventScript_FinishStarterSelection::
# 42 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 43 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 44 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_0
# 48 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 49 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 50 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1
# 51 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 52 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 53 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 54 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_2
# 58 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 59 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 60 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 61 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_3
# 62 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 63 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSMinnow_1F_Room6_Movement_Agatha_Leaves
# 64 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 65 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 6
# 66 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 67 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_4
# 70 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 71 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 72 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 73 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Agatha::
# 78 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 79 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 80 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_RIGHT
# 81 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 82 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Agatha_Text_0
# 83 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 84 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Arbor::
# 89 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 90 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 91 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 92 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 93 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_Arbor_2
# 97 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_1
SSAnne_1F_Room6_EventScript_Arbor_1:
# 99 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 100 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end

SSAnne_1F_Room6_EventScript_Arbor_2:
# 94 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_0
	goto SSAnne_1F_Room6_EventScript_Arbor_1


# 105 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Player:
# 106 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_down
	step_end

# 108 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha:
# 109 "data/maps/SSAnne_1F_Room6/scripts.pory"
	delay_16
# 110 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_right
# 111 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_down
	step_end

# 113 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha_Leaves:
# 114 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_up
# 115 "data/maps/SSAnne_1F_Room6/scripts.pory"
	set_invisible
	step_end

# 118 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 119 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Woman::
# 120 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 121 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 122 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
# 123 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
# 124 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 125 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 126 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
# 127 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 128 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 129 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 130 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHeal::
# 131 "data/maps/SSAnne_1F_Room6/scripts.pory"
	checkplayergender
# 132 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
# 133 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
# 134 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 135 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 136 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 137 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHealMale::
# 138 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
# 139 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 140 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 141 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 142 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Growlithe::
# 143 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 144 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 145 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose
# 146 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 147 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 148 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteGrowlithe, MSGBOX_DEFAULT
# 149 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 150 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_GROWLITHE, 10, 3
# 151 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 152 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseGrowlithe, MSGBOX_YESNO
# 153 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 154 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseGrowlithe
# 155 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 156 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 157 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 158 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 159 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose::
# 160 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 161 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GrowlitheFriendly
# 162 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 163 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 164 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 165 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 166 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseGrowlithe::
# 167 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 168 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_GROWLITHE, 5, ball=ITEM_RED_PROTOBALL
# 169 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveGrowlitheParty
# 170 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveGrowlithePC
# 171 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 172 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 173 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 174 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlitheParty::
# 175 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 176 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 177 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 178 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 179 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 180 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 181 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 182 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 183 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 184 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 185 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 186 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 187 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 188 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 189 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlithePC::
# 190 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 191 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 192 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 193 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 194 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 195 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 196 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 197 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 198 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 199 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 200 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 201 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 202 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 203 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC::
# 204 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 205 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 206 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 207 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 208 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranM::
# 209 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 210 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 211 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose
# 212 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 213 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 214 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteNidoranM, MSGBOX_DEFAULT
# 215 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 216 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_NIDORAN_M, 10, 3
# 217 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 218 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseNidoranM, MSGBOX_YESNO
# 219 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 220 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseNidoranM
# 221 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 222 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 223 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 224 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 225 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose::
# 226 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 227 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_NidoranMFriendly
# 228 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 229 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 230 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 231 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 232 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseNidoranM::
# 233 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 234 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_NIDORAN_M, 5, ball=ITEM_RED_PROTOBALL
# 235 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveNidoranMParty
# 236 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveNidoranMPC
# 237 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 238 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 239 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 240 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMParty::
# 241 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 242 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 243 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 244 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 245 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 246 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 247 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 248 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 249 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 250 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 251 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 252 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 253 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 254 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 255 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMPC::
# 256 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 257 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 258 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 259 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 260 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 261 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 262 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 263 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 264 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 265 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 266 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 267 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 268 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 269 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC::
# 270 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 271 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 272 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 273 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 274 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Exeggcute::
# 275 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 276 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 277 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose
# 278 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 279 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 280 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteExeggcute, MSGBOX_DEFAULT
# 281 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 282 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_EXEGGCUTE, 10, 3
# 283 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 284 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseExeggcute, MSGBOX_YESNO
# 285 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 286 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseExeggcute
# 287 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 288 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 289 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 290 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 291 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose::
# 292 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 293 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ExeggcuteFriendly
# 294 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 295 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 296 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 297 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 298 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseExeggcute::
# 299 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 300 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_EXEGGCUTE, 5, ball=ITEM_RED_PROTOBALL
# 301 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveExeggcuteParty
# 302 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveExeggcutePC
# 303 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 304 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 305 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 306 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcuteParty::
# 307 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 308 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 309 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 310 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 311 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 312 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 313 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 314 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 315 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 316 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 317 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 318 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 319 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 320 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 321 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcutePC::
# 322 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 323 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 324 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 325 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 326 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 327 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 328 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 329 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 330 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 331 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 332 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 333 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 334 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 335 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC::
# 336 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 337 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 338 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 339 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 340 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 341 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_TestBalls::
# 342 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 343 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 344 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 345 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 5
# 346 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLU_PROTOBALL, 5
# 347 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GRN_PROTOBALL, 5
# 348 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLK_PROTOBALL, 5
# 349 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CHERISH_BALL, 5
# 350 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_WORKBENCH, 1
# 351 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CONVERSION_KIT, 20
# 352 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_APRICORN, 10
# 353 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLUE_APRICORN, 10
# 354 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GREEN_APRICORN, 10
# 355 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLACK_APRICORN, 10
# 356 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_TEMP_2
# 357 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 5
# 358 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 359 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 360 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 361 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingNPC::
# 362 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 363 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 364 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistIntro, MSGBOX_YESNO
# 365 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_CraftingDecline
# 366 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto EventScript_CraftingLoop
# 367 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 368 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 369 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingDecline::
# 370 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistDecline
# 371 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 372 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end

SSMinnow_1F_EventScript_ChoosePokemonCutscene_Text_0:
# 21 "data/maps/SSAnne_1F_Room6/scripts.pory"
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
# 44 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Good. Take care of it.\p"
	.string "Whatever you're planning to do out\n"
	.string "there, your partner's condition will\l"
	.string "matter more than you think.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1:
# 50 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Alright, Agatha. Go ahead.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_2:
# 54 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Oh, no thanks, Professor.\p"
	.string "All of these ones look a bit too\n"
	.string "weak for me.\p"
	.string "I'll go out and get one for myself.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_3:
# 61 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Alright, don't take too long.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_4:
# 67 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "She'll be fine. She always is.\p"
	.string "Gather your things. I'll find you\n"
	.string "in the city once you're off the ship.$"

SSAnne_1F_Room6_EventScript_Agatha_Text_0:
# 82 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Go ahead and pick, Sammy!$"

SSAnne_1F_Room6_EventScript_Arbor_Text_0:
# 94 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "The harbor's close now.\n"
	.string "Get your things together.$"

SSAnne_1F_Room6_EventScript_Arbor_Text_1:
# 97 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Take your time. But not too much.$"
