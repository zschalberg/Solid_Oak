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
# 360 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2
# 362 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 363 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Category
	end

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
# 356 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 357 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end


# 367 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 368 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Category::
# 369 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESERVE_CONTEST_CATEGORY, FALSE
# 370 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
# 371 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 372 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ MULTI_RESERVE_CONTEST_CATEGORY's list is Size(0)/Vitality(1)/Rarity(2)/Cancel(3) -
# 373 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ explicitly picking "Cancel" returns index 3, not MULTI_B_PRESSED, so it must be
# 374 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ checked separately or the session starts anyway with an invalid category.
# 375 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 3
# 376 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 377 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 378 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special StartReserveContestSession
# 379 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionStarted, MSGBOX_DEFAULT
# 380 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 381 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
# 382 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 383 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 384 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 385 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Cancelled::
# 386 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 387 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 388 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 389 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Shared by the manual "check on my expedition" path (Worker2ActiveSession,
# 390 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ talking to Worker 2 directly) and the automatic one (ReturnFromExpedition,
# 391 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ triggered by walking back out of the Safari Zone). Only valid to call once
# 392 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FLAG_RESERVE_CONTEST_CAUGHT is already known set. Always ends the session -
# 393 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FinalizeReserveContestCatch clears FLAG_RESERVE_CONTEST_ACTIVE either way.
# 394 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize::
# 395 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate, MSGBOX_DEFAULT
# 396 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateReserveContestCatch
# 397 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 398 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon, MSGBOX_YESNO
# 399 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep
# 400 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 1
# 401 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 402 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn, MSGBOX_DEFAULT
# 403 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 404 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 405 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep::
# 406 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 407 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 408 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndKept, MSGBOX_DEFAULT
# 409 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 410 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 411 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2ActiveSession::
# 412 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet
# 413 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 414 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 415 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 416 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 417 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet::
# 418 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet, MSGBOX_DEFAULT
# 419 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 420 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 421 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 422 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fires automatically on every entry into this room (see
# 423 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ MAP_SCRIPT_ON_FRAME_TABLE, VAR_TEMP_0 is the standard "run once per map
# 424 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ visit" scratch var, reset on every fresh map load) - if an expedition is
# 425 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ active, that's treated as "coming back", whether the player is walking in
# 426 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ from the Safari Zone exit or just from the city door. The expedition ends
# 427 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ right here, whether or not anything was caught, instead of requiring a
# 428 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ separate trip to talk to Worker 2 again.
# 429 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition::
# 430 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_TEMP_0, 1
# 431 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End
# 432 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 433 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught
# 434 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 435 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 436 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 437 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 438 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught::
# 439 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught, MSGBOX_DEFAULT
# 440 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 441 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 442 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 443 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 444 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 445 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End::
# 446 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 447 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 448 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 449 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ TEXT
# 450 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 451 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 452 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Welcome:
# 453 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Every specimen you bring in gets\n"
# 454 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "logged and turned into Research\l"
# 455 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins.\p"
# 456 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Spend them on box space for\n"
# 457 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Fuji's Sanctuary, Evolution\l"
# 458 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Stones, or other research gear\l"
# 459 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "as we stock it.$"
# 460 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 461 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInPrompt:
# 462 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON are you\n"
# 463 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "turning in?$"
# 464 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 465 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WarningNotResearchBall:
# 466 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one wasn't caught in a\n"
# 467 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "RESEARCH BALL. We can still log\l"
# 468 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "it, but the Pokemon will not be\l"
# 469 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "returned.\p"
# 470 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn it in anyway?$"
# 471 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 472 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_EvaluationResult:
# 473 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "{STR_VAR_3}\p"
# 474 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn in {STR_VAR_1}?$"
# 475 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 476 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewFamilyBonusMsg:
# 477 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "First entry for this family.\n"
# 478 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's worth extra.$"
# 479 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 480 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInSuccess:
# 481 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Logged. {STR_VAR_3} Research\n"
# 482 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins added.$"
# 483 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 484 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewPokemonAvailable:
# 485 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's enough entries to widen\n"
# 486 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "the reserve's range.\p"
# 487 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "New POKéMON should be showing\n"
# 488 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "up out there now.$"
# 489 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 490 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg:
# 491 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Can't take your only POKéMON.\n"
# 492 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'd have nothing to research\l"
# 493 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "with.$"
# 494 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 495 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg:
# 496 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's still an egg. Come back\n"
# 497 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "once it's hatched.$"
# 498 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 499 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExchangeShopComingSoon:
# 500 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "The exchange shop isn't stocked\n"
# 501 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "yet. Check back once we've got\l"
# 502 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "inventory worth selling.$"
# 503 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 504 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferPrompt:
# 505 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON gets a proper\n"
# 506 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL?$"
# 507 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 508 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferEggRefusedMsg:
# 509 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Eggs don't need re-balling.$"
# 510 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 511 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg:
# 512 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one's already in a\n"
# 513 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "standard POKé BALL.$"
# 514 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 515 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferSuccess:
# 516 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Done. Transferred to a\n"
# 517 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL.$"
# 518 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 519 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg:
# 520 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's 500 Research Coins.\n"
# 521 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You're short.$"
# 522 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 523 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Info:
# 524 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Research Balls give a research\n"
# 525 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "bonus when you turn a catch in -\l"
# 526 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "no penalty on the coin count.\p"
# 527 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Standard balls still count, just\n"
# 528 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "at a lower rate.$"
# 529 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 530 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1End:
# 531 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Come back any time.$"
# 532 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 533 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionStarted:
# 534 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Good luck out there.\n"
# 535 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Bring back what you catch.$"
# 536 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 537 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate:
# 538 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Let's see what you brought.$"
# 539 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 540 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon:
# 541 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Want to keep this one, or should\n"
# 542 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "we log it and take it in?$"
# 543 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 544 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn:
# 545 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued and logged.\n"
# 546 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Thank you for this.$"
# 547 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 548 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndKept:
# 549 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued. It's yours to keep.$"
# 550 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 551 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet:
# 552 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Nothing caught on this\n"
# 553 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition yet.$"
# 554 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 555 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught:
# 556 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Back already, and nothing to\n"
# 557 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "show for it.\p"
# 558 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's fine. Come find us again\n"
# 559 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "whenever you're ready for another\l"
# 560 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition.$"

# 563 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_JumpInPlace:
# 564 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	emote_exclamation_mark
# 565 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	jump_in_place_down
	step_end

# 568 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceRight:
# 569 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	face_right
	step_end

# 572 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceLeft:
# 573 "data/maps/FuchsiaCity_Reserve/scripts.pory"
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
	.string "You'll need exactly one POKéMON\n"
	.string "in your party before you head\l"
	.string "out. Wouldn't want you catching\l"
	.string "over your limit.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2:
# 360 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Pick what you're cataloguing\n"
	.string "this time.$"
