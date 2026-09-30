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
	clearmugshot
# 64 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSMinnow_1F_Room6_Movement_Agatha_Leaves
# 65 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 66 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 6
# 67 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 68 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_4
# 71 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 72 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 73 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 74 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Agatha::
# 79 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 80 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 81 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_RIGHT
# 82 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 83 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Agatha_Text_0
# 84 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 85 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Arbor::
# 90 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 91 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 92 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 93 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 94 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_Arbor_2
# 98 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_1
SSAnne_1F_Room6_EventScript_Arbor_1:
# 100 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 101 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end

SSAnne_1F_Room6_EventScript_Arbor_2:
# 95 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_0
	goto SSAnne_1F_Room6_EventScript_Arbor_1


# 106 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Player:
# 107 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_down
	step_end

# 109 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha:
# 110 "data/maps/SSAnne_1F_Room6/scripts.pory"
	delay_16
# 111 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_right
# 112 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_down
	step_end

# 114 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha_Leaves:
# 115 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_up
# 116 "data/maps/SSAnne_1F_Room6/scripts.pory"
	set_invisible
	step_end

# 119 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 120 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Woman::
# 121 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 122 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 123 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
# 124 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
# 125 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 126 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 127 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
# 128 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 129 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 130 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 131 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHeal::
# 132 "data/maps/SSAnne_1F_Room6/scripts.pory"
	checkplayergender
# 133 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
# 134 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
# 135 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 136 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 137 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 138 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHealMale::
# 139 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
# 140 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 141 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 142 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 143 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Growlithe::
# 144 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 145 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 146 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose
# 147 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 148 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 149 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteGrowlithe, MSGBOX_DEFAULT
# 150 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 151 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_GROWLITHE, 10, 3
# 152 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 153 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseGrowlithe, MSGBOX_YESNO
# 154 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 155 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseGrowlithe
# 156 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 157 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 158 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 159 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 160 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose::
# 161 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 162 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GrowlitheFriendly
# 163 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 164 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 165 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 166 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 167 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseGrowlithe::
# 168 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 169 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_GROWLITHE, 5, ball=ITEM_RED_PROTOBALL
# 170 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveGrowlitheParty
# 171 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveGrowlithePC
# 172 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 173 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 174 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 175 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlitheParty::
# 176 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 177 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 178 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 179 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 180 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 181 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 182 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 183 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 184 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 185 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 186 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 187 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 188 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 189 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 190 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlithePC::
# 191 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 192 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 193 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 194 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 195 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 196 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 197 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 198 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 199 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 200 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 201 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 202 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 203 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 204 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC::
# 205 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 206 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 207 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 208 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 209 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranM::
# 210 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 211 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 212 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose
# 213 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 214 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 215 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteNidoranM, MSGBOX_DEFAULT
# 216 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 217 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_NIDORAN_M, 10, 3
# 218 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 219 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseNidoranM, MSGBOX_YESNO
# 220 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 221 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseNidoranM
# 222 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 223 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 224 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 225 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 226 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose::
# 227 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 228 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_NidoranMFriendly
# 229 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 230 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 231 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 232 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 233 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseNidoranM::
# 234 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 235 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_NIDORAN_M, 5, ball=ITEM_RED_PROTOBALL
# 236 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveNidoranMParty
# 237 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveNidoranMPC
# 238 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 239 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 240 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 241 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMParty::
# 242 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 243 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 244 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 245 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 246 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 247 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 248 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 249 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 250 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 251 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 252 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 253 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 254 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 255 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 256 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMPC::
# 257 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 258 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 259 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 260 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 261 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 262 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 263 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 264 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 265 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 266 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 267 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 268 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 269 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 270 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC::
# 271 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 272 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 273 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 274 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 275 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Exeggcute::
# 276 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 277 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 278 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose
# 279 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 280 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 281 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteExeggcute, MSGBOX_DEFAULT
# 282 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 283 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_EXEGGCUTE, 10, 3
# 284 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 285 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseExeggcute, MSGBOX_YESNO
# 286 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 287 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseExeggcute
# 288 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 289 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 290 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 291 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 292 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose::
# 293 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 294 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ExeggcuteFriendly
# 295 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 296 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 297 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 298 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 299 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseExeggcute::
# 300 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 301 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_EXEGGCUTE, 5, ball=ITEM_RED_PROTOBALL
# 302 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveExeggcuteParty
# 303 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveExeggcutePC
# 304 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 305 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 306 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 307 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcuteParty::
# 308 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 309 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 310 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 311 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 312 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 313 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 314 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 315 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 316 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 317 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 318 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 319 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 320 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 321 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 322 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcutePC::
# 323 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 324 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 325 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 326 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 327 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 328 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 329 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 330 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 331 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 332 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 333 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 334 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 335 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 336 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC::
# 337 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 338 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 339 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 340 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 341 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 342 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_TestBalls::
# 343 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 344 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 345 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 346 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 5
# 347 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLU_PROTOBALL, 5
# 348 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GRN_PROTOBALL, 5
# 349 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLK_PROTOBALL, 5
# 350 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CHERISH_BALL, 5
# 351 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_WORKBENCH, 1
# 352 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CONVERSION_KIT, 20
# 353 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_APRICORN, 10
# 354 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLUE_APRICORN, 10
# 355 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GREEN_APRICORN, 10
# 356 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLACK_APRICORN, 10
# 357 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_TEMP_2
# 358 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 5
# 359 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 360 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 361 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 362 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingNPC::
# 363 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 364 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 365 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistIntro, MSGBOX_YESNO
# 366 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_CraftingDecline
# 367 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto EventScript_CraftingLoop
# 368 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 369 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 370 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingDecline::
# 371 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistDecline
# 372 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 373 "data/maps/SSAnne_1F_Room6/scripts.pory"
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
# 68 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "She'll be fine. She always is.\p"
	.string "Gather your things. I'll find you\n"
	.string "in the city once you're off the ship.$"

SSAnne_1F_Room6_EventScript_Agatha_Text_0:
# 83 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Go ahead and pick, Sammy!$"

SSAnne_1F_Room6_EventScript_Arbor_Text_0:
# 95 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "The harbor's close now.\n"
	.string "Get your things together.$"

SSAnne_1F_Room6_EventScript_Arbor_Text_1:
# 98 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Take your time. But not too much.$"
