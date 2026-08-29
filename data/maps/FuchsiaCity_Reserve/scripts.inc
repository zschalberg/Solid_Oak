FuchsiaCity_Reserve_MapScripts::
# 20 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_Reserve_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FuchsiaCity_Reserve_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 21 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	map_script_2 VAR_SCENE_FUCHSIA_RESERVE, 0, FuchsiaCity_Reserve_EventScript_CheckIntro
# 22 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition
	.2byte 0


FuchsiaCity_Reserve_OnTransition::
# 27 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_FUJI
# 28 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_AGATHA
	end


FuchsiaCity_Reserve_EventScript_CheckIntro::
# 33 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_set FLAG_HIDE_FUCHSIA_FUJI, FuchsiaCity_Reserve_EventScript_CheckIntro_2
	end

FuchsiaCity_Reserve_EventScript_CheckIntro_2:
# 34 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Intro
	end


FuchsiaCity_Reserve_EventScript_Intro::
# 45 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 46 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearflag FLAG_HIDE_RESERVE_FUJI
# 47 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearflag FLAG_HIDE_RESERVE_AGATHA
# 49 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 50 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_0
# 54 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 55 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER1, FuchsiaCity_Reserve_JumpInPlace
# 56 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitmovement 0
# 57 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_1
# 61 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 62 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER1, FuchsiaCity_Reserve_FaceRight
# 63 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER2, FuchsiaCity_Reserve_JumpInPlace
# 64 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitmovement 0
# 65 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_2
# 68 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 69 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER2, FuchsiaCity_Reserve_FaceLeft
# 70 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitmovement 0
# 71 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 72 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 73 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_3
# 75 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 76 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearmugshot
# 78 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 79 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_4
# 87 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 88 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_5
# 97 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 98 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 99 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 100 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_6
# 101 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 102 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearmugshot
# 103 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_FUJI
# 104 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_AGATHA
# 105 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_SCENE_FUCHSIA_RESERVE, 1
# 106 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_KRABBY_QUEST_COMPLETE
# 107 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_QUEST_FISHING_VILLAGE_ACTIVE
# 108 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	quest_complete_toast FuchsiaCity_Reserve_EventScript_Intro_Text_7
# 109 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	quest_start_toast FuchsiaCity_Reserve_EventScript_Intro_Text_8
# 110 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
	end


FuschiaCity_Reserve_Fuji::
# 119 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 120 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 121 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuschiaCity_Reserve_Fuji_Text_0
	return


FuschiaCity_Reserve_Agatha::
# 129 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 130 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 131 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuschiaCity_Reserve_Agatha_Text_0
	return


FuchsiaCity_Reserve_EventScript_Worker1::
# 141 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lock
# 142 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 143 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_Reserve_EventScript_Worker1_2
# 151 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1Menu
	end

FuchsiaCity_Reserve_EventScript_Worker1_2:
# 144 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker1_Text_0
# 147 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 148 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end


# 155 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 156 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1Menu::
# 157 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1Welcome, MSGBOX_DEFAULT
# 158 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1MenuLoop::
# 159 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	showcoinsbox 19, 0
# 160 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESEARCH_MAIN, FALSE
# 161 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	switch VAR_RESULT
# 162 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 0, FuchsiaCity_Reserve_EventScript_TurnInMon
# 163 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 1, FuchsiaCity_Reserve_EventScript_ExchangeShop
# 164 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 2, FuchsiaCity_Reserve_EventScript_TransferBall
# 165 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 3, FuchsiaCity_Reserve_EventScript_Worker1Info
# 166 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 4, FuchsiaCity_Reserve_EventScript_Worker1End
# 167 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case MULTI_B_PRESSED, FuchsiaCity_Reserve_EventScript_Worker1End
# 168 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 169 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 170 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInMon::
# 171 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 172 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 1
# 173 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_le FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused
# 174 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInPrompt, MSGBOX_DEFAULT
# 175 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 176 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 177 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, 255
# 178 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 179 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonEgg
# 180 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 181 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TurnInEggRefused
# 182 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonResearchBall
# 183 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 184 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_EvaluateMon
# 185 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WarningNotResearchBall, MSGBOX_YESNO
# 186 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
# 187 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 188 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 189 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateMon::
# 190 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateSelectedResearchMon
# 191 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_EvaluationResult, MSGBOX_YESNO
# 192 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
# 193 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 194 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonNewFamily
# 195 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 196 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call_if_eq FuchsiaCity_Reserve_EventScript_ShowNewFamilyText
# 197 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special TurnInSelectedResearchMon
# 198 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
# 199 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused
# 200 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	updatecoinsbox 19, 0
# 201 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 202 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInSuccess, MSGBOX_DEFAULT
# 203 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitfanfare
# 204 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special CheckReserveStageJustAdvanced
# 205 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 206 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_NewPokemonAvailable
# 207 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 208 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 209 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_NewPokemonAvailable::
# 210 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NewPokemonAvailable, MSGBOX_DEFAULT
# 211 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 212 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 213 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ShowNewFamilyText::
# 214 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NewFamilyBonusMsg, MSGBOX_DEFAULT
# 215 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 216 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 217 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused::
# 218 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg, MSGBOX_DEFAULT
# 219 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 220 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 221 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInEggRefused::
# 222 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg, MSGBOX_DEFAULT
# 223 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 224 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 225 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ── Exchange Shop and Transfer Ball are placeholders: TurnInSelectedResearchMon
# 226 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ already awards Research Coins via AddCoins, but the shop that spends them on
# 227 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fuji's box space upgrades / Evolution Stones / research items isn't built
# 228 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ yet. Wire ExchangeShop up to a real shop/buymenu once that item list exists.
# 229 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ExchangeShop::
# 230 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExchangeShopComingSoon, MSGBOX_DEFAULT
# 231 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 232 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 233 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferBall::
# 234 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	checkcoins VAR_TEMP_1
# 235 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_TEMP_1, 500
# 236 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_lt FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer
# 237 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 238 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
# 239 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 240 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferPrompt, MSGBOX_DEFAULT
# 241 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 242 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 243 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, 255
# 244 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 245 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonEgg
# 246 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 247 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferEggRefused
# 248 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonResearchBall
# 249 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
# 250 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferNotResearchBall
# 251 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	removecoins 500
# 252 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	updatecoinsbox 19, 0
# 253 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special TransferSelectedMonToPokeBall
# 254 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 255 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferSuccess, MSGBOX_DEFAULT
# 256 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitfanfare
# 257 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 258 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 259 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferEggRefused::
# 260 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferEggRefusedMsg, MSGBOX_DEFAULT
# 261 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 262 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 263 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferNotResearchBall::
# 264 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg, MSGBOX_DEFAULT
# 265 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 266 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 267 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer::
# 268 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg, MSGBOX_DEFAULT
# 269 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 270 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 271 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1Info::
# 272 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1Info, MSGBOX_DEFAULT
# 273 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 274 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 275 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1End::
# 276 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	hidecoinsbox 19, 0
# 277 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1End, MSGBOX_DEFAULT
# 278 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 279 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end

FuchsiaCity_Reserve_EventScript_Worker2::
# 287 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lock
# 288 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 289 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_Reserve_EventScript_Worker2_2
# 296 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_set FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_Worker2_5
# 300 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_1, MSGBOX_YESNO
# 302 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2_8
# 306 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end

FuchsiaCity_Reserve_EventScript_Worker2_2:
# 290 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_0
# 292 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 293 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2_5:
# 297 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2ActiveSession
	end

FuchsiaCity_Reserve_EventScript_Worker2_8:
# 303 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Explain
	end


FuchsiaCity_Reserve_EventScript_Worker2Explain::
# 311 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0
# 329 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 330 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end


FuchsiaCity_Reserve_EventScript_Worker2Start::
# 335 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, GetReserveContestAttemptsRemaining
# 336 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_2
# 344 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, CheckCanRegisterReserveContest
# 345 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_5
# 354 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2
# 356 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 357 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Category
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_2:
# 337 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_0
# 340 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 341 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_5:
# 346 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1
# 350 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 351 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end


# 361 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 362 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Category::
# 363 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESERVE_CONTEST_CATEGORY, FALSE
# 364 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
# 365 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 366 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ MULTI_RESERVE_CONTEST_CATEGORY's list is Size(0)/Vitality(1)/Rarity(2)/Cancel(3) -
# 367 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ explicitly picking "Cancel" returns index 3, not MULTI_B_PRESSED, so it must be
# 368 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ checked separately or the session starts anyway with an invalid category.
# 369 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 3
# 370 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 371 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 372 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special StartReserveContestSession
# 373 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionStarted, MSGBOX_DEFAULT
# 374 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 375 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
# 376 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 377 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 378 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 379 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Cancelled::
# 380 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 381 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 382 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 383 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Shared by the manual "check on my expedition" path (Worker2ActiveSession,
# 384 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ talking to Worker 2 directly) and the automatic one (ReturnFromExpedition,
# 385 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ triggered by walking back out of the Safari Zone). Only valid to call once
# 386 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FLAG_RESERVE_CONTEST_CAUGHT is already known set. Always ends the session -
# 387 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FinalizeReserveContestCatch clears FLAG_RESERVE_CONTEST_ACTIVE either way.
# 388 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize::
# 389 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate, MSGBOX_DEFAULT
# 390 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateReserveContestCatch
# 391 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 392 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon, MSGBOX_YESNO
# 393 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep
# 394 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 1
# 395 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 396 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn, MSGBOX_DEFAULT
# 397 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 398 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 399 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep::
# 400 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 401 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 402 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndKept, MSGBOX_DEFAULT
# 403 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 404 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 405 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2ActiveSession::
# 406 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet
# 407 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 408 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 409 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 410 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 411 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet::
# 412 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet, MSGBOX_DEFAULT
# 413 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 414 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 415 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 416 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fires automatically on every entry into this room (see
# 417 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ MAP_SCRIPT_ON_FRAME_TABLE, VAR_TEMP_0 is the standard "run once per map
# 418 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ visit" scratch var, reset on every fresh map load) - if an expedition is
# 419 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ active, that's treated as "coming back", whether the player is walking in
# 420 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ from the Safari Zone exit or just from the city door. The expedition ends
# 421 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ right here, whether or not anything was caught, instead of requiring a
# 422 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ separate trip to talk to Worker 2 again.
# 423 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition::
# 424 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_TEMP_0, 1
# 425 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End
# 426 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 427 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught
# 428 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 429 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 430 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 431 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 432 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught::
# 433 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught, MSGBOX_DEFAULT
# 434 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 435 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 436 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 437 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 438 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 439 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End::
# 440 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 441 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 442 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 443 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ TEXT
# 444 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 445 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 446 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Welcome:
# 447 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Every specimen you bring in gets\n"
# 448 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "logged and turned into Research\l"
# 449 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins.\p"
# 450 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Spend them on box space for\n"
# 451 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Fuji's Sanctuary, Evolution\l"
# 452 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Stones, or other research gear\n"
# 453 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "as we stock it.$"
# 454 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 455 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInPrompt:
# 456 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON are you\n"
# 457 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "turning in?$"
# 458 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 459 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WarningNotResearchBall:
# 460 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one wasn't caught in a\n"
# 461 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "RESEARCH BALL. We can still log\l"
# 462 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "it, but the Pokemon will not be\n"
# 463 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "returned.\p"
# 464 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn it in anyway?$"
# 465 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 466 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_EvaluationResult:
# 467 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "{STR_VAR_3}\p"
# 468 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn in {STR_VAR_1}?$"
# 469 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 470 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewFamilyBonusMsg:
# 471 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "First entry for this family.\n"
# 472 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's worth extra.$"
# 473 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 474 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInSuccess:
# 475 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Logged. {STR_VAR_3} Research\n"
# 476 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins added.$"
# 477 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 478 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewPokemonAvailable:
# 479 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's enough entries to widen\n"
# 480 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "the reserve's range.\p"
# 481 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "New POKéMON should be showing\n"
# 482 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "up out there now.$"
# 483 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 484 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg:
# 485 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Can't take your only POKéMON.\n"
# 486 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'd have nothing to research\l"
# 487 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "with.$"
# 488 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 489 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg:
# 490 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's still an egg. Come back\n"
# 491 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "once it's hatched.$"
# 492 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 493 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExchangeShopComingSoon:
# 494 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "The exchange shop isn't stocked\n"
# 495 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "yet. Check back once we've got\l"
# 496 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "inventory worth selling.$"
# 497 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 498 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferPrompt:
# 499 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON gets a proper\n"
# 500 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL?$"
# 501 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 502 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferEggRefusedMsg:
# 503 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Eggs don't need re-balling.$"
# 504 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 505 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg:
# 506 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one's already in a\n"
# 507 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "standard POKé BALL.$"
# 508 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 509 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferSuccess:
# 510 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Done. Transferred to a\n"
# 511 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL.$"
# 512 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 513 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg:
# 514 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's 500 Research Coins.\n"
# 515 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You're short.$"
# 516 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 517 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Info:
# 518 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Research Balls give a research\n"
# 519 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "bonus when you turn a catch in -\l"
# 520 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "no penalty on the coin count.\p"
# 521 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Standard balls still count, just\n"
# 522 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "at a lower rate.$"
# 523 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 524 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1End:
# 525 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Come back any time.$"
# 526 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 527 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionStarted:
# 528 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Good luck out there.\n"
# 529 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Bring back what you catch.$"
# 530 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 531 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate:
# 532 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Let's see what you brought.$"
# 533 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 534 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon:
# 535 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Want to keep this one, or should\n"
# 536 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "we log it and take it in?$"
# 537 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 538 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn:
# 539 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued and logged.\n"
# 540 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Thank you for this.$"
# 541 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 542 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndKept:
# 543 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued. It's yours to keep.$"
# 544 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 545 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet:
# 546 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Nothing caught on this\n"
# 547 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition yet.$"
# 548 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 549 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught:
# 550 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Back already, and nothing to\n"
# 551 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "show for it.\p"
# 552 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's fine. Come find us again\n"
# 553 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "whenever you're ready for another\l"
# 554 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition.$"

# 557 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_JumpInPlace:
# 558 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	emote_exclamation_mark
# 559 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	jump_in_place_down
	step_end

# 562 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceRight:
# 563 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	face_right
	step_end

# 566 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceLeft:
# 567 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	face_left
	step_end

FuchsiaCity_Reserve_EventScript_Intro_Text_0:
# 50 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "This is the rest of it.\p"
	.string "Two people, most days. It's not\n"
	.string "much, but it's what the funding\l"
	.string "allows.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_1:
# 57 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "This one handles what comes in;\n"
	.string "turn-ins, records, the ledger.\p"
	.string "Talk to her to turn in your\n"
	.string "Krabby and other Pokemon.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_2:
# 65 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one runs the expeditions.\n"
	.string "Catch counts, catalogue entries,\l"
	.string "that sort of thing.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_3:
# 73 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Two people and a building.\n"
	.string "That's the operation?$"

FuchsiaCity_Reserve_EventScript_Intro_Text_4:
# 79 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "For now.\p"
	.string "The biggest issue is the lack\n"
	.string "of proper containment equipment.\p"
	.string "I have a few connections at\n"
	.string "Silph Co. that are working on\n"
	.string "containment issues in SAFFRON.\p"
	.string "When you get time, head there\n"
	.string "and introduce yourself.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_5:
# 88 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "In the meantime...\p"
	.string "There's something happening at\n"
	.string "the fishing village on your way\l"
	.string "back.\p"
	.string "I've had reports for three days.\n"
	.string "I didn't want to say anything\l"
	.string "before you'd seen this first.\p"
	.string "Go back the way you came.\n"
	.string "You'll see it.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_6:
# 100 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Finally.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_7:
# 108 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "KRAB FISHING$"

FuchsiaCity_Reserve_EventScript_Intro_Text_8:
# 109 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "DANGEROUS WATERS$"

FuschiaCity_Reserve_Fuji_Text_0:
# 121 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "The FISHING VILLAGE is your next \nstop.\p$"

FuschiaCity_Reserve_Agatha_Text_0:
# 131 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Seems like a waste of time to\n"
	.string "turn these POKéMON in. Why not keep\n"
	.string "them for your own collection?$"

FuchsiaCity_Reserve_EventScript_Worker1_Text_0:
# 144 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Still getting the ledgers set up.\n"
	.string "Come back once Fuji's shown you\l"
	.string "around properly.$"

FuchsiaCity_Reserve_EventScript_Worker2_Text_0:
# 290 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Expeditions aren't running yet.\n"
	.string "Talk to Fuji first.$"

FuchsiaCity_Reserve_EventScript_Worker2_Text_1:
# 300 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Ever been out on one of our\n"
	.string "expeditions?$"

FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0:
# 311 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "An expedition is simple: you go\n"
	.string "out, you catch what you find, and\l"
	.string "you bring it back so we can\n"
	.string "catalogue it properly.\p"
	.string "Documentation. Every entry helps\l"
	.string "us understand what's moving through\n"
	.string "here and why.\p"
	.string "Here are the categories:\p"
	.string "THE HEAVIEST - we weigh and\n"
	.string "measure everything you bring\l"
	.string "back and judge on the numbers.\p"
	.string "THE BEST IVs - we run it through\n"
	.string "the scanner and grade its\l"
	.string "underlying condition.\p"
	.string "THE RAREST - judged on how\n"
	.string "seldom the species turns up,\l"
	.string "with anything unusual coloring\n"
	.string "counting extra.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_0:
# 337 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You've used up today's\n"
	.string "expedition slots.\p"
	.string "Come back tomorrow.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1:
# 346 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'll need exactly one POKéMON\n"
	.string "in your party before you head\l"
	.string "out. Wouldn't want you catching\n"
	.string "over your limit.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2:
# 354 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Pick what you're cataloguing\n"
	.string "this time.\p$"
