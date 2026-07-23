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
# 38 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 39 "data/maps/SSAnne_1F_Room6/scripts.pory"
	releaseall
	end


SSAnne_1F_Room6_EventScript_FinishStarterSelection::
# 44 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 45 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 46 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_0
# 50 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 51 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 52 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1
# 53 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 54 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 55 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 56 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_2
# 60 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 61 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 62 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 63 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_3
# 64 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 65 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSMinnow_1F_Room6_Movement_Agatha_Leaves
# 66 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 67 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 6
# 68 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 69 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_4
# 72 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 73 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 74 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 75 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Agatha::
# 80 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 81 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 82 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_RIGHT
# 83 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 84 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Agatha_Text_0
# 85 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 86 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Arbor::
# 91 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 92 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 93 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 94 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 95 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_Arbor_2
# 99 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_1
SSAnne_1F_Room6_EventScript_Arbor_1:
# 101 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 102 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end

SSAnne_1F_Room6_EventScript_Arbor_2:
# 96 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_0
	goto SSAnne_1F_Room6_EventScript_Arbor_1


# 107 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Player:
# 108 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_down
	step_end

# 110 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha:
# 111 "data/maps/SSAnne_1F_Room6/scripts.pory"
	delay_16
# 112 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_right
# 113 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_down
	step_end

# 115 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha_Leaves:
# 116 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_up
# 117 "data/maps/SSAnne_1F_Room6/scripts.pory"
	set_invisible
	step_end

# 120 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 121 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Woman::
# 122 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 123 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 124 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
# 125 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
# 126 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 127 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 128 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
# 129 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 130 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 131 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 132 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHeal::
# 133 "data/maps/SSAnne_1F_Room6/scripts.pory"
	checkplayergender
# 134 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
# 135 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
# 136 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 137 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 138 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 139 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHealMale::
# 140 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
# 141 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 142 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 143 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 144 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Growlithe::
# 145 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 146 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 147 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose
# 148 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 149 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 150 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteGrowlithe, MSGBOX_DEFAULT
# 151 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 152 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_GROWLITHE, 10, 3
# 153 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 154 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseGrowlithe, MSGBOX_YESNO
# 155 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 156 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseGrowlithe
# 157 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 158 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 159 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 160 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 161 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose::
# 162 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 163 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GrowlitheFriendly
# 164 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 165 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 166 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 167 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 168 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseGrowlithe::
# 169 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 170 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_GROWLITHE, 5
# 171 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveGrowlitheParty
# 172 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveGrowlithePC
# 173 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 174 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 175 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 176 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlitheParty::
# 177 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 178 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 179 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 180 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 181 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 182 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 183 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 184 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 185 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 186 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 187 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 188 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 189 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 190 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 191 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlithePC::
# 192 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 193 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 194 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 195 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 196 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 197 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 198 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 199 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 200 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 201 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 202 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 203 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 204 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 205 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC::
# 206 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 207 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 208 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 209 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 210 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranM::
# 211 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 212 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 213 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose
# 214 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 215 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 216 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteNidoranM, MSGBOX_DEFAULT
# 217 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 218 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_NIDORAN_M, 10, 3
# 219 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 220 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseNidoranM, MSGBOX_YESNO
# 221 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 222 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseNidoranM
# 223 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 224 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 225 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 226 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 227 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose::
# 228 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 229 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_NidoranMFriendly
# 230 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 231 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 232 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 233 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 234 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseNidoranM::
# 235 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 236 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_NIDORAN_M, 5
# 237 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveNidoranMParty
# 238 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveNidoranMPC
# 239 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 240 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 241 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 242 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMParty::
# 243 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 244 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 245 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 246 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 247 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 248 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 249 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 250 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 251 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 252 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 253 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 254 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 255 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 256 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 257 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMPC::
# 258 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 259 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 260 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 261 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 262 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 263 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 264 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 265 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 266 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 267 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 268 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 269 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 270 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 271 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC::
# 272 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 273 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 274 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 275 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 276 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Exeggcute::
# 277 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 278 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 279 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose
# 280 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 281 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 282 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ArborNoteExeggcute, MSGBOX_DEFAULT
# 283 "data/maps/SSAnne_1F_Room6/scripts.pory"
	clearmugshot
# 284 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_EXEGGCUTE, 10, 3
# 285 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 286 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseExeggcute, MSGBOX_YESNO
# 287 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 288 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseExeggcute
# 289 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 290 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 291 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 292 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 293 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose::
# 294 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 295 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ExeggcuteFriendly
# 296 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 297 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 298 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 299 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 300 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseExeggcute::
# 301 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 302 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_EXEGGCUTE, 5
# 303 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveExeggcuteParty
# 304 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveExeggcutePC
# 305 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 306 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 307 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 308 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcuteParty::
# 309 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 310 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 311 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 312 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 313 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 314 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 315 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 316 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 317 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 318 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 319 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 320 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 321 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 322 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 323 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcutePC::
# 324 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 325 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 326 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 327 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 328 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 329 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 330 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 331 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 332 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 333 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 334 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 335 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 336 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 337 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC::
# 338 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 339 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 340 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 341 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 342 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 343 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_TestBalls::
# 344 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 345 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 346 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 347 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_LEVEL_BALL, 5
# 348 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_LURE_BALL, 5
# 349 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_FRIEND_BALL, 5
# 350 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_HEAVY_BALL, 5
# 351 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CHERISH_BALL, 5
# 352 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_WORKBENCH, 1
# 353 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CONVERSION_KIT, 20
# 354 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_APRICORN, 10
# 355 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLUE_APRICORN, 10
# 356 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GREEN_APRICORN, 10
# 357 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLACK_APRICORN, 10
# 358 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_TEMP_2
# 359 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 5
# 360 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 361 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 362 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 363 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingNPC::
# 364 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 365 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 366 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistIntro, MSGBOX_YESNO
# 367 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_CraftingDecline
# 368 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto EventScript_CraftingLoop
# 369 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 370 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 371 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingDecline::
# 372 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistDecline
# 373 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 374 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end

SSMinnow_1F_EventScript_ChoosePokemonCutscene_Text_0:
# 21 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Ah. There you both are.\p"
	.string "We'll be in Vermilion Harbor\n"
	.string "inside the hour. I want you ready.\p"
	.string "Kanto is seeing POKéMON\n"
	.string "in locations\l"
	.string "they have no business being in.\p"
	.string "Migration patterns that don't match\n"
	.string "any model we have.\p"
	.string "Something is moving them\p"
	.string "Your assignment: find out what.\p"
	.string "To do that, you'll need a partner\n"
	.string "Pokémon.\p"
	.string "I've given this some thought.\n"
	.string "There are three on the table.\p"
	.string "I'll let you look them over before\n"
	.string "you decide. Oak, the choice is\l"
	.string "yours first.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_0:
# 46 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Good. Take care of it.\p"
	.string "Whatever you're planning to do out\n"
	.string "there, your partner's condition will\l"
	.string "matter more than you think.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1:
# 52 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Alright, Agatha. Go ahead.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_2:
# 56 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Oh, no thanks, Professor.\p"
	.string "All of these ones look a bit too\n"
	.string "weak for me.\p"
	.string "I'll go out and get one for myself.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_3:
# 63 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Alright. Don't take too long.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_4:
# 69 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "She'll be fine. She always is.\p"
	.string "Gather your things. I'll find you\n"
	.string "in the city once you're off the ship.$"

SSAnne_1F_Room6_EventScript_Agatha_Text_0:
# 84 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Go ahead and pick, Sammy!$"

SSAnne_1F_Room6_EventScript_Arbor_Text_0:
# 96 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "The harbor's close now.\n"
	.string "Get your things together.$"

SSAnne_1F_Room6_EventScript_Arbor_Text_1:
# 99 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Take your time. But not too much.$"
