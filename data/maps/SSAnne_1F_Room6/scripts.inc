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
# 22 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSMinnow_1F_EventScript_ChoosePokemonCutscene_Text_0
# 35 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 36 "data/maps/SSAnne_1F_Room6/scripts.pory"
	releaseall
	end


SSAnne_1F_Room6_EventScript_FinishStarterSelection::
# 41 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 42 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 44 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_0
# 45 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 46 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 47 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 48 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1
# 51 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 52 "data/maps/SSAnne_1F_Room6/scripts.pory"
	applymovement 6, SSMinnow_1F_Room6_Movement_Agatha_Leaves
# 53 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmovement 0
# 54 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 6
# 55 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 56 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Agatha::
# 61 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 62 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 63 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_RIGHT
# 64 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 65 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Agatha_Text_0
# 66 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 67 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end


SSAnne_1F_Room6_EventScript_Arbor::
# 72 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 73 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 74 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 75 "data/maps/SSAnne_1F_Room6/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 77 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_Arbor_2
# 83 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_1
SSAnne_1F_Room6_EventScript_Arbor_1:
# 85 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 86 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
	end

SSAnne_1F_Room6_EventScript_Arbor_2:
# 79 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_EventScript_Arbor_Text_0
	goto SSAnne_1F_Room6_EventScript_Arbor_1


# 91 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Player:
# 92 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_down
	step_end

# 94 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha:
# 95 "data/maps/SSAnne_1F_Room6/scripts.pory"
	delay_16
# 96 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_right
# 97 "data/maps/SSAnne_1F_Room6/scripts.pory"
	face_down
	step_end

# 99 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSMinnow_1F_Room6_Movement_Agatha_Leaves:
# 100 "data/maps/SSAnne_1F_Room6/scripts.pory"
	walk_up
# 101 "data/maps/SSAnne_1F_Room6/scripts.pory"
	set_invisible
	step_end

# 104 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 105 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Woman::
# 106 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 107 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 108 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
# 109 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
# 110 "data/maps/SSAnne_1F_Room6/scripts.pory"
	closemessage
# 111 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_OutOfCenterPartyHeal
# 112 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
# 113 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 114 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 115 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 116 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHeal::
# 117 "data/maps/SSAnne_1F_Room6/scripts.pory"
	checkplayergender
# 118 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
# 119 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
# 120 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 121 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 122 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 123 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_DeclineHealMale::
# 124 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
# 125 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 126 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 127 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 128 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Growlithe::
# 129 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 130 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 131 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose
# 132 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_GROWLITHE, 10, 3
# 133 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 134 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseGrowlithe, MSGBOX_YESNO
# 135 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 136 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseGrowlithe
# 137 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 138 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 139 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 140 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 141 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose::
# 142 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
# 143 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_GrowlitheFriendly
# 144 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 145 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 146 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 147 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 148 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseGrowlithe::
# 149 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 150 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_GROWLITHE, 5
# 151 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveGrowlitheParty
# 152 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveGrowlithePC
# 153 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 154 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 155 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 156 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlitheParty::
# 157 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 158 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 159 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 160 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 161 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 162 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 163 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 164 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 165 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 166 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 167 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 168 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 169 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 170 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 171 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveGrowlithePC::
# 172 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D7
# 173 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 2
# 174 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 175 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
# 176 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 177 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 178 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
# 179 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 180 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 181 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 182 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
# 183 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 184 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 185 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC::
# 186 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 187 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 188 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 189 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 190 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranM::
# 191 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 192 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 193 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose
# 194 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_NIDORAN_M, 10, 3
# 195 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 196 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseNidoranM, MSGBOX_YESNO
# 197 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 198 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseNidoranM
# 199 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 200 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 201 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 202 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 203 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose::
# 204 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
# 205 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_NidoranMFriendly
# 206 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 207 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 208 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 209 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 210 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseNidoranM::
# 211 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 212 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_NIDORAN_M, 5
# 213 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveNidoranMParty
# 214 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveNidoranMPC
# 215 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 216 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 217 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 218 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMParty::
# 219 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 220 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 221 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 222 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 223 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 224 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 225 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 226 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 227 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 228 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 229 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 230 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 231 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 232 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 233 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveNidoranMPC::
# 234 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D8
# 235 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 3
# 236 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 237 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
# 238 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 239 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 240 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
# 241 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 242 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 243 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 244 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
# 245 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 246 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 247 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC::
# 248 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 249 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 250 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 251 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 252 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_Exeggcute::
# 253 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 254 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 255 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose
# 256 "data/maps/SSAnne_1F_Room6/scripts.pory"
	showmonpic SPECIES_EXEGGCUTE, 10, 3
# 257 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 258 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ChooseExeggcute, MSGBOX_YESNO
# 259 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 260 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseExeggcute
# 261 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 262 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 263 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 264 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 265 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose::
# 266 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
# 267 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ExeggcuteFriendly
# 268 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmoncry
# 269 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 270 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 271 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 272 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ChooseExeggcute::
# 273 "data/maps/SSAnne_1F_Room6/scripts.pory"
	hidemonpic
# 274 "data/maps/SSAnne_1F_Room6/scripts.pory"
	givemon SPECIES_EXEGGCUTE, 5
# 275 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveExeggcuteParty
# 276 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveExeggcutePC
# 277 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 278 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 279 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 280 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcuteParty::
# 281 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 282 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 283 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 284 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 285 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 286 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 287 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 288 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 289 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 290 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 291 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_ChangePokemonNickname
# 292 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 293 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 294 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 295 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_GiveExeggcutePC::
# 296 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_0x8D9
# 297 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 4
# 298 "data/maps/SSAnne_1F_Room6/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 299 "data/maps/SSAnne_1F_Room6/scripts.pory"
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
# 300 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitmessage
# 301 "data/maps/SSAnne_1F_Room6/scripts.pory"
	waitfanfare
# 302 "data/maps/SSAnne_1F_Room6/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
# 303 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 304 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 305 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 306 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
# 307 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 308 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 309 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC::
# 310 "data/maps/SSAnne_1F_Room6/scripts.pory"
	call EventScript_TransferredToPC
# 311 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
# 312 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 313 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 314 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 315 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_TestBalls::
# 316 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 317 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 318 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_POKE_BALL, 5
# 319 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_LEVEL_BALL, 5
# 320 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_LURE_BALL, 5
# 321 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_FRIEND_BALL, 5
# 322 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_HEAVY_BALL, 5
# 323 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CHERISH_BALL, 5
# 324 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_WORKBENCH, 1
# 325 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_CONVERSION_KIT, 20
# 326 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_RED_APRICORN, 10
# 327 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLUE_APRICORN, 10
# 328 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_GREEN_APRICORN, 10
# 329 "data/maps/SSAnne_1F_Room6/scripts.pory"
	giveitem ITEM_BLACK_APRICORN, 10
# 330 "data/maps/SSAnne_1F_Room6/scripts.pory"
	setflag FLAG_TEMP_2
# 331 "data/maps/SSAnne_1F_Room6/scripts.pory"
	removeobject 5
# 332 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 333 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 334 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 335 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingNPC::
# 336 "data/maps/SSAnne_1F_Room6/scripts.pory"
	lock
# 337 "data/maps/SSAnne_1F_Room6/scripts.pory"
	faceplayer
# 338 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistIntro, MSGBOX_YESNO
# 339 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_CraftingDecline
# 340 "data/maps/SSAnne_1F_Room6/scripts.pory"
	goto EventScript_CraftingLoop
# 341 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end
# 342 "data/maps/SSAnne_1F_Room6/scripts.pory"

# 343 "data/maps/SSAnne_1F_Room6/scripts.pory"
SSAnne_1F_Room6_EventScript_CraftingDecline::
# 344 "data/maps/SSAnne_1F_Room6/scripts.pory"
	msgbox SSAnne_1F_Room6_Text_ScientistDecline
# 345 "data/maps/SSAnne_1F_Room6/scripts.pory"
	release
# 346 "data/maps/SSAnne_1F_Room6/scripts.pory"
	end

SSMinnow_1F_EventScript_ChoosePokemonCutscene_Text_0:
# 22 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Ah, you're here. Good.\p"
	.string "We'll be arriving in\n"
	.string "Vermilion Harbor soon.\p"
	.string "As you know, Kanto is experiencing a\n"
	.string "strange influx of Pokémon not native\l"
	.string "to the region.\p"
	.string "It's the job of the two of you to\n"
	.string "figure out why that is.\p"
	.string "To do so, you'll need a companion\n"
	.string "Pokémon.\p"
	.string "There are three on the table here.\n"
	.string "Oak, go ahead and pick one to take\l"
	.string "with you.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_0:
# 44 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Alright Agatha, go ahead.$"

SSAnne_1F_Room6_EventScript_FinishStarterSelection_Text_1:
# 48 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Oh, no thanks, Professor. All of\n"
	.string "these ones look a bit too weak for me.\p"
	.string "I'll go out and get one for myself.$"

SSAnne_1F_Room6_EventScript_Agatha_Text_0:
# 65 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Go ahead and pick, Sammy!$"

SSAnne_1F_Room6_EventScript_Arbor_Text_0:
# 79 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Take good care of your new partner!\n"
	.string "They will grow strong if you battle.$"

SSAnne_1F_Room6_EventScript_Arbor_Text_1:
# 83 "data/maps/SSAnne_1F_Room6/scripts.pory"
	.string "Choose your partner Pokémon wisely.$"
