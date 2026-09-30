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
# 123 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
	end


FuschiaCity_Reserve_Agatha::
# 132 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 133 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 134 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuschiaCity_Reserve_Agatha_Text_0
# 137 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
	end


FuchsiaCity_Reserve_EventScript_Worker1::
# 146 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lock
# 147 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 148 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_Reserve_EventScript_Worker1_2
# 156 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1Menu
	end

FuchsiaCity_Reserve_EventScript_Worker1_2:
# 149 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker1_Text_0
# 152 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 153 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end


# 160 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 161 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1Menu::
# 162 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1Welcome, MSGBOX_DEFAULT
# 163 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1MenuLoop::
# 164 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	showcoinsbox 19, 0
# 165 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESEARCH_MAIN, FALSE
# 166 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	switch VAR_RESULT
# 167 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 0, FuchsiaCity_Reserve_EventScript_TurnInMon
# 168 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 1, FuchsiaCity_Reserve_EventScript_ExchangeShop
# 169 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 2, FuchsiaCity_Reserve_EventScript_TransferBall
# 170 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 3, FuchsiaCity_Reserve_EventScript_Worker1Info
# 171 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 4, FuchsiaCity_Reserve_EventScript_Worker1End
# 172 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case MULTI_B_PRESSED, FuchsiaCity_Reserve_EventScript_Worker1End
# 173 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 174 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 175 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInMon::
# 176 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 177 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 1
# 178 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_le FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused
# 179 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInPrompt, MSGBOX_DEFAULT
# 180 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 181 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 182 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, 255
# 183 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 184 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonEgg
# 185 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 186 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TurnInEggRefused
# 187 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonResearchBall
# 188 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 189 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_EvaluateMon
# 190 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WarningNotResearchBall, MSGBOX_YESNO
# 191 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
# 192 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 193 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 194 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateMon::
# 195 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateSelectedResearchMon
# 196 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_EvaluationResult, MSGBOX_YESNO
# 197 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
# 198 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 199 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonNewFamily
# 200 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 201 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call_if_eq FuchsiaCity_Reserve_EventScript_ShowNewFamilyText
# 202 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special TurnInSelectedResearchMon
# 203 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
# 204 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused
# 205 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	updatecoinsbox 19, 0
# 206 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 207 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInSuccess, MSGBOX_DEFAULT
# 208 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitfanfare
# 209 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call EventScript_WarnIfResearchBallLost
# 210 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special CheckReserveStageJustAdvanced
# 211 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 212 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_NewPokemonAvailable
# 213 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 214 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 215 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_NewPokemonAvailable::
# 216 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NewPokemonAvailable, MSGBOX_DEFAULT
# 217 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 218 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 219 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ShowNewFamilyText::
# 220 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NewFamilyBonusMsg, MSGBOX_DEFAULT
# 221 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 222 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 223 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused::
# 224 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg, MSGBOX_DEFAULT
# 225 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 226 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 227 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInEggRefused::
# 228 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg, MSGBOX_DEFAULT
# 229 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 230 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 231 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ── Exchange Shop and Transfer Ball are placeholders: TurnInSelectedResearchMon
# 232 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ already awards Research Coins via AddCoins, but the shop that spends them on
# 233 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fuji's box space upgrades / Evolution Stones / research items isn't built
# 234 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ yet. Wire ExchangeShop up to a real shop/buymenu once that item list exists.
# 235 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ExchangeShop::
# 236 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExchangeShopComingSoon, MSGBOX_DEFAULT
# 237 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 238 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 239 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferBall::
# 240 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	checkcoins VAR_TEMP_1
# 241 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_TEMP_1, 500
# 242 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_lt FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer
# 243 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 244 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
# 245 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 246 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferPrompt, MSGBOX_DEFAULT
# 247 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 248 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 249 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, 255
# 250 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 251 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonEgg
# 252 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 253 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferEggRefused
# 254 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonResearchBall
# 255 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
# 256 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferNotResearchBall
# 257 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	removecoins 500
# 258 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	updatecoinsbox 19, 0
# 259 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special TransferSelectedMonToPokeBall
# 260 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 261 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferSuccess, MSGBOX_DEFAULT
# 262 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitfanfare
# 263 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 264 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 265 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferEggRefused::
# 266 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferEggRefusedMsg, MSGBOX_DEFAULT
# 267 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 268 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 269 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferNotResearchBall::
# 270 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg, MSGBOX_DEFAULT
# 271 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 272 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 273 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer::
# 274 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg, MSGBOX_DEFAULT
# 275 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 276 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 277 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1Info::
# 278 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1Info, MSGBOX_DEFAULT
# 279 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 280 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 281 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1End::
# 282 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	hidecoinsbox 19, 0
# 283 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1End, MSGBOX_DEFAULT
# 284 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 285 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end

FuchsiaCity_Reserve_EventScript_Worker2::
# 293 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lock
# 294 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 295 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_Reserve_EventScript_Worker2_2
# 302 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_set FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_Worker2_5
# 306 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_1, MSGBOX_YESNO
# 308 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2_8
# 312 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end

FuchsiaCity_Reserve_EventScript_Worker2_2:
# 296 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_0
# 298 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 299 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2_5:
# 303 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2ActiveSession
	end

FuchsiaCity_Reserve_EventScript_Worker2_8:
# 309 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Explain
	end


FuchsiaCity_Reserve_EventScript_Worker2Explain::
# 317 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0
# 335 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 336 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end


FuchsiaCity_Reserve_EventScript_Worker2Start::
# 341 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, GetReserveContestAttemptsRemaining
# 342 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_2
# 350 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, CheckCanRegisterReserveContest
# 351 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_5
# 359 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 360 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_gt FuchsiaCity_Reserve_EventScript_Worker2Start_7
# 367 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 368 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ValidateReserveContestChosenMon
# 369 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FuchsiaCity_Reserve_EventScript_Worker2Start_11
FuchsiaCity_Reserve_EventScript_Worker2Start_10:
# 372 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special SavePlayerPartyForReserveContest
# 373 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_3
# 375 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 376 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Category
	return

FuchsiaCity_Reserve_EventScript_Worker2Start_2:
# 343 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_0
# 346 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 347 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_5:
# 352 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1
# 355 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 356 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_7:
# 361 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2
# 365 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop
	return

FuchsiaCity_Reserve_EventScript_Worker2Start_11:
# 370 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2MonRefused
	goto FuchsiaCity_Reserve_EventScript_Worker2Start_10


FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop::
# 381 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 382 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 383 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_2
FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_1:
# 386 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ValidateReserveContestChosenMon
# 387 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_5
FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_4:
# 390 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special SavePlayerPartyForReserveContest
# 391 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_3
# 393 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 394 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Category
	return

FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_2:
# 384 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Cancelled
	goto FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_1

FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_5:
# 388 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2MonRefused
	goto FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop_4


FuchsiaCity_Reserve_EventScript_Worker2MonRefused::
# 398 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2MonRefused_2
# 402 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2MonRefused_3
# 406 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2MonRefused_4
# 411 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_3
FuchsiaCity_Reserve_EventScript_Worker2MonRefused_1:
# 415 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 416 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_gt FuchsiaCity_Reserve_EventScript_Worker2MonRefused_10
FuchsiaCity_Reserve_EventScript_Worker2MonRefused_9:
# 419 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_2:
# 399 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_0
	goto FuchsiaCity_Reserve_EventScript_Worker2MonRefused_1

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_3:
# 403 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_1
	goto FuchsiaCity_Reserve_EventScript_Worker2MonRefused_1

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_4:
# 407 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_2
	goto FuchsiaCity_Reserve_EventScript_Worker2MonRefused_1

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_10:
# 417 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2ChooseMonLoop
	goto FuchsiaCity_Reserve_EventScript_Worker2MonRefused_9


# 423 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 424 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Category::
# 425 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESERVE_CONTEST_CATEGORY, FALSE
# 426 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
# 427 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 428 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ MULTI_RESERVE_CONTEST_CATEGORY's list is Size(0)/Vitality(1)/Rarity(2)/Cancel(3) -
# 429 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ explicitly picking "Cancel" returns index 3, not MULTI_B_PRESSED, so it must be
# 430 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ checked separately or the session starts anyway with an invalid category.
# 431 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 3
# 432 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 433 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 434 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special StartReserveContestSession
# 435 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionStarted, MSGBOX_DEFAULT
# 436 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 437 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
# 438 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 439 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 440 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 441 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Cancelled::
# 442 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special RestorePlayerPartyFromReserveContest
# 443 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker2CancelledMsg, MSGBOX_DEFAULT
# 444 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 445 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 446 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 447 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Shared by the manual "check on my expedition" path (Worker2ActiveSession,
# 448 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ talking to Worker 2 directly) and the automatic one (ReturnFromExpedition,
# 449 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ triggered by walking back out of the Safari Zone). Only valid to call once
# 450 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FLAG_RESERVE_CONTEST_CAUGHT is already known set. Always ends the session -
# 451 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FinalizeReserveContestCatch clears FLAG_RESERVE_CONTEST_ACTIVE either way.
# 452 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize::
# 453 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate, MSGBOX_DEFAULT
# 454 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateReserveContestCatch
# 455 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 456 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon, MSGBOX_YESNO
# 457 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep
# 458 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 1
# 459 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 460 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn, MSGBOX_DEFAULT
# 461 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 462 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 463 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep::
# 464 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 465 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 466 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 1
# 467 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep_PC
# 468 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndKept, MSGBOX_DEFAULT
# 469 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 470 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 471 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep_PC::
# 472 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndSentToPC, MSGBOX_DEFAULT
# 473 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 474 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 475 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2ActiveSession::
# 476 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet
# 477 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 478 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 479 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 480 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 481 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet::
# 482 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet, MSGBOX_DEFAULT
# 483 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 484 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 485 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 486 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fires automatically on every entry into this room (see
# 487 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ MAP_SCRIPT_ON_FRAME_TABLE, VAR_TEMP_0 is the standard "run once per map
# 488 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ visit" scratch var, reset on every fresh map load) - if an expedition is
# 489 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ active, that's treated as "coming back", whether the player is walking in
# 490 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ from the Safari Zone exit or just from the city door. The expedition ends
# 491 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ right here, whether or not anything was caught, instead of requiring a
# 492 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ separate trip to talk to Worker 2 again.
# 493 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition::
# 494 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_TEMP_0, 1
# 495 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End
# 496 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 497 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught
# 498 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 499 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 500 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 501 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 502 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught::
# 503 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught, MSGBOX_DEFAULT
# 504 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 505 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 506 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 507 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 508 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 509 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End::
# 510 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 511 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 512 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 513 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ TEXT
# 514 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 515 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 516 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Welcome:
# 517 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Every specimen you bring in gets\n"
# 518 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "logged and turned into Research\l"
# 519 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins.\p"
# 520 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Spend them on box space for\n"
# 521 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Fuji's Sanctuary, Evolution\l"
# 522 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Stones, or other research gear\l"
# 523 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "as we stock it.$"
# 524 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 525 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInPrompt:
# 526 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON are you\n"
# 527 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "turning in?$"
# 528 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 529 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WarningNotResearchBall:
# 530 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one wasn't caught in a\n"
# 531 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "RESEARCH BALL. We can still log\l"
# 532 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "it, but the Pokemon will not be\l"
# 533 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "returned.\p"
# 534 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn it in anyway?$"
# 535 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 536 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_EvaluationResult:
# 537 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "{STR_VAR_3}\p"
# 538 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn in {STR_VAR_1}?$"
# 539 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 540 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewFamilyBonusMsg:
# 541 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "First entry for this family.\n"
# 542 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's worth extra.$"
# 543 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 544 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInSuccess:
# 545 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Logged. {STR_VAR_3} Research\n"
# 546 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins added.$"
# 547 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 548 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewPokemonAvailable:
# 549 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's enough entries to widen\n"
# 550 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "the reserve's range.\p"
# 551 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "New POKéMON should be showing\n"
# 552 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "up out there now.$"
# 553 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 554 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg:
# 555 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Can't take your only POKéMON.\n"
# 556 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'd have nothing to research\l"
# 557 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "with.$"
# 558 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 559 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg:
# 560 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's still an egg. Come back\n"
# 561 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "once it's hatched.$"
# 562 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 563 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExchangeShopComingSoon:
# 564 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "The exchange shop isn't stocked\n"
# 565 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "yet. Check back once we've got\l"
# 566 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "inventory worth selling.$"
# 567 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 568 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferPrompt:
# 569 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON gets a proper\n"
# 570 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL?$"
# 571 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 572 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferEggRefusedMsg:
# 573 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Eggs don't need re-balling.$"
# 574 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 575 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg:
# 576 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one's already in a\n"
# 577 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "standard POKé BALL.$"
# 578 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 579 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferSuccess:
# 580 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Done. Transferred to a\n"
# 581 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL.$"
# 582 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 583 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg:
# 584 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's 500 Research Coins.\n"
# 585 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You're short.$"
# 586 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 587 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Info:
# 588 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Research Balls give a research\n"
# 589 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "bonus when you turn a catch in -\l"
# 590 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "no penalty on the coin count.\p"
# 591 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Standard balls still count, just\n"
# 592 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "at a lower rate.$"
# 593 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 594 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1End:
# 595 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Come back any time.$"
# 596 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 597 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionStarted:
# 598 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Good luck out there.\n"
# 599 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Bring back what you catch.$"
# 600 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 601 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate:
# 602 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Let's see what you brought.$"
# 603 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 604 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon:
# 605 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Want to keep this one, or should\n"
# 606 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "we log it and take it in?$"
# 607 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 608 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn:
# 609 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued and logged.\n"
# 610 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Thank you for this.$"
# 611 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 612 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndKept:
# 613 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued. It's yours to keep.$"
# 614 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 615 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndSentToPC:
# 616 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued. Your party was full,\n"
# 617 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "so {STR_VAR_1} was sent to\l"
# 618 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "BOX “{STR_VAR_2}”!$"
# 619 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 620 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker2CancelledMsg:
# 621 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Come find us whenever you're\n"
# 622 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "ready for an expedition.$"
# 623 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 624 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet:
# 625 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Nothing caught on this\n"
# 626 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition yet.$"
# 627 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 628 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught:
# 629 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Back already, and nothing to\n"
# 630 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "show for it.\p"
# 631 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's fine. Come find us again\n"
# 632 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "whenever you're ready for another\l"
# 633 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition.$"

# 636 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_JumpInPlace:
# 637 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	emote_exclamation_mark
# 638 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	jump_in_place_down
	step_end

# 641 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceRight:
# 642 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	face_right
	step_end

# 645 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceLeft:
# 646 "data/maps/FuchsiaCity_Reserve/scripts.pory"
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
	.string "Silph Co. that are working on\l"
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
	.string "The FISHING VILLAGE is your next\n"
	.string "stop.$"

FuschiaCity_Reserve_Agatha_Text_0:
# 134 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Seems like a waste of time to\n"
	.string "turn these POKéMON in. Why not keep\l"
	.string "them for your own collection?$"

FuchsiaCity_Reserve_EventScript_Worker1_Text_0:
# 149 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Still getting the ledgers set up.\n"
	.string "Come back once Fuji's shown you\l"
	.string "around properly.$"

FuchsiaCity_Reserve_EventScript_Worker2_Text_0:
# 296 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Expeditions aren't running yet.\n"
	.string "Talk to Fuji first.$"

FuchsiaCity_Reserve_EventScript_Worker2_Text_1:
# 306 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Ever been out on one of our\n"
	.string "expeditions?$"

FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0:
# 317 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "An expedition is simple: you go\n"
	.string "out, you catch what you find, and\l"
	.string "you bring it back so we can\l"
	.string "catalogue it properly.\p"
	.string "Documentation. Every entry helps\n"
	.string "us understand what's moving through\l"
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
	.string "with anything unusual coloring\l"
	.string "counting extra.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_0:
# 343 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You've used up today's\n"
	.string "expedition slots.\p"
	.string "Come back tomorrow.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1:
# 352 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You don't have any eligible\n"
	.string "POKéMON to take on an\l"
	.string "expedition right now.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2:
# 361 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Choose one POKéMON to take\n"
	.string "with you on the expedition.\p"
	.string "The rest will be safely looked\n"
	.string "after here.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_3:
# 373 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Pick what you're cataloguing\n"
	.string "this time.$"

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_0:
# 399 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "An EGG cannot be taken on an\n"
	.string "expedition.\p"
	.string "Please choose a different POKéMON.$"

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_1:
# 403 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That POKéMON doesn't have the\n"
	.string "energy to battle!\p"
	.string "Please choose a different POKéMON.$"

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_2:
# 407 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "A POKéMON in a RESEARCH BALL\n"
	.string "cannot lead an expedition!\p"
	.string "Please choose a different POKéMON.$"

FuchsiaCity_Reserve_EventScript_Worker2MonRefused_Text_3:
# 411 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That POKéMON cannot be taken on\n"
	.string "an expedition.\p"
	.string "Please choose a different POKéMON.$"
