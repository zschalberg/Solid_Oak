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
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 205 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 206 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ShowNewFamilyText::
# 207 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NewFamilyBonusMsg, MSGBOX_DEFAULT
# 208 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 209 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 210 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused::
# 211 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg, MSGBOX_DEFAULT
# 212 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 213 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 214 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInEggRefused::
# 215 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg, MSGBOX_DEFAULT
# 216 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 217 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 218 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ── Exchange Shop and Transfer Ball are placeholders: TurnInSelectedResearchMon
# 219 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ already awards Research Coins via AddCoins, but the shop that spends them on
# 220 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fuji's box space upgrades / Evolution Stones / research items isn't built
# 221 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ yet. Wire ExchangeShop up to a real shop/buymenu once that item list exists.
# 222 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ExchangeShop::
# 223 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExchangeShopComingSoon, MSGBOX_DEFAULT
# 224 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 225 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 226 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferBall::
# 227 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	checkcoins VAR_TEMP_1
# 228 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_TEMP_1, 500
# 229 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_lt FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer
# 230 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 231 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
# 232 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 233 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferPrompt, MSGBOX_DEFAULT
# 234 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 235 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 236 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, 255
# 237 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 238 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonEgg
# 239 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 240 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferEggRefused
# 241 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonResearchBall
# 242 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
# 243 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferNotResearchBall
# 244 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	removecoins 500
# 245 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	updatecoinsbox 19, 0
# 246 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special TransferSelectedMonToPokeBall
# 247 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 248 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferSuccess, MSGBOX_DEFAULT
# 249 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitfanfare
# 250 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 251 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 252 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferEggRefused::
# 253 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferEggRefusedMsg, MSGBOX_DEFAULT
# 254 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 255 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 256 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferNotResearchBall::
# 257 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg, MSGBOX_DEFAULT
# 258 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 259 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 260 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer::
# 261 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg, MSGBOX_DEFAULT
# 262 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 263 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 264 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1Info::
# 265 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1Info, MSGBOX_DEFAULT
# 266 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 267 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 268 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1End::
# 269 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	hidecoinsbox 19, 0
# 270 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1End, MSGBOX_DEFAULT
# 271 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 272 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end

FuchsiaCity_Reserve_EventScript_Worker2::
# 280 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lock
# 281 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 282 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_Reserve_EventScript_Worker2_2
# 289 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_set FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_Worker2_5
# 293 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_1, MSGBOX_YESNO
# 295 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2_8
# 299 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end

FuchsiaCity_Reserve_EventScript_Worker2_2:
# 283 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_0
# 285 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 286 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2_5:
# 290 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2ActiveSession
	end

FuchsiaCity_Reserve_EventScript_Worker2_8:
# 296 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Explain
	end


FuchsiaCity_Reserve_EventScript_Worker2Explain::
# 304 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0
# 322 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 323 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end


FuchsiaCity_Reserve_EventScript_Worker2Start::
# 328 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, GetReserveContestAttemptsRemaining
# 329 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_2
# 337 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, CheckCanRegisterReserveContest
# 338 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_5
# 347 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2
# 349 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 350 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Category
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_2:
# 330 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_0
# 333 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 334 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_5:
# 339 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1
# 343 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 344 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end


# 354 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 355 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Category::
# 356 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESERVE_CONTEST_CATEGORY, FALSE
# 357 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
# 358 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 359 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ MULTI_RESERVE_CONTEST_CATEGORY's list is Size(0)/Vitality(1)/Rarity(2)/Cancel(3) -
# 360 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ explicitly picking "Cancel" returns index 3, not MULTI_B_PRESSED, so it must be
# 361 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	@ checked separately or the session starts anyway with an invalid category.
# 362 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 3
# 363 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 364 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 365 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special StartReserveContestSession
# 366 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionStarted, MSGBOX_DEFAULT
# 367 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 368 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	warp MAP_SAFARI_ZONE_CENTER, 26, 30
# 369 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 370 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 371 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 372 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Cancelled::
# 373 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 374 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 375 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 376 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Shared by the manual "check on my expedition" path (Worker2ActiveSession,
# 377 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ talking to Worker 2 directly) and the automatic one (ReturnFromExpedition,
# 378 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ triggered by walking back out of the Safari Zone). Only valid to call once
# 379 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FLAG_RESERVE_CONTEST_CAUGHT is already known set. Always ends the session -
# 380 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ FinalizeReserveContestCatch clears FLAG_RESERVE_CONTEST_ACTIVE either way.
# 381 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize::
# 382 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate, MSGBOX_DEFAULT
# 383 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateReserveContestCatch
# 384 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 385 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon, MSGBOX_YESNO
# 386 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep
# 387 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 1
# 388 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 389 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn, MSGBOX_DEFAULT
# 390 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 391 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 392 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize_Keep::
# 393 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 394 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 395 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndKept, MSGBOX_DEFAULT
# 396 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 397 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 398 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2ActiveSession::
# 399 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet
# 400 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 401 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 402 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 403 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 404 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet::
# 405 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet, MSGBOX_DEFAULT
# 406 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 407 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 408 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 409 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fires automatically on every entry into this room (see
# 410 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ MAP_SCRIPT_ON_FRAME_TABLE, VAR_TEMP_0 is the standard "run once per map
# 411 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ visit" scratch var, reset on every fresh map load) - if an expedition is
# 412 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ active, that's treated as "coming back", whether the player is walking in
# 413 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ from the Safari Zone exit or just from the city door. The expedition ends
# 414 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ right here, whether or not anything was caught, instead of requiring a
# 415 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ separate trip to talk to Worker 2 again.
# 416 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition::
# 417 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_TEMP_0, 1
# 418 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End
# 419 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 420 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught
# 421 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call FuchsiaCity_Reserve_EventScript_EvaluateAndFinalize
# 422 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 423 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 424 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 425 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_NothingCaught::
# 426 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught, MSGBOX_DEFAULT
# 427 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 428 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 429 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
# 430 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 431 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 432 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ReturnFromExpedition_End::
# 433 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 434 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 435 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 436 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ TEXT
# 437 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 438 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 439 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Welcome:
# 440 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Every specimen you bring in gets\n"
# 441 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "logged and turned into Research\l"
# 442 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins.\p"
# 443 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Spend them on box space for\n"
# 444 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Fuji's Sanctuary, Evolution\l"
# 445 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Stones, or other research gear\n"
# 446 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "as we stock it.$"
# 447 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 448 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInPrompt:
# 449 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON are you\n"
# 450 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "turning in?$"
# 451 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 452 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WarningNotResearchBall:
# 453 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one wasn't caught in a\n"
# 454 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "RESEARCH BALL. We can still log\l"
# 455 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "it, but the Pokemon will not be\n"
# 456 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "returned.\p"
# 457 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn it in anyway?$"
# 458 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 459 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_EvaluationResult:
# 460 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "{STR_VAR_3}\p"
# 461 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn in {STR_VAR_1}?$"
# 462 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 463 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewFamilyBonusMsg:
# 464 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "First entry for this family.\n"
# 465 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's worth extra.$"
# 466 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 467 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInSuccess:
# 468 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Logged. {STR_VAR_3} Research\n"
# 469 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins added.$"
# 470 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 471 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg:
# 472 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Can't take your only POKéMON.\n"
# 473 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'd have nothing to research\l"
# 474 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "with.$"
# 475 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 476 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg:
# 477 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's still an egg. Come back\n"
# 478 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "once it's hatched.$"
# 479 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 480 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExchangeShopComingSoon:
# 481 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "The exchange shop isn't stocked\n"
# 482 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "yet. Check back once we've got\l"
# 483 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "inventory worth selling.$"
# 484 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 485 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferPrompt:
# 486 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON gets a proper\n"
# 487 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL?$"
# 488 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 489 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferEggRefusedMsg:
# 490 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Eggs don't need re-balling.$"
# 491 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 492 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg:
# 493 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one's already in a\n"
# 494 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "standard POKé BALL.$"
# 495 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 496 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferSuccess:
# 497 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Done. Transferred to a\n"
# 498 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL.$"
# 499 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 500 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg:
# 501 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's 500 Research Coins.\n"
# 502 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You're short.$"
# 503 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 504 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Info:
# 505 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Research Balls give a research\n"
# 506 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "bonus when you turn a catch in -\l"
# 507 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "no penalty on the coin count.\p"
# 508 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Standard balls still count, just\n"
# 509 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "at a lower rate.$"
# 510 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 511 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1End:
# 512 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Come back any time.$"
# 513 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 514 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionStarted:
# 515 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Good luck out there.\n"
# 516 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Bring back what you catch.$"
# 517 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 518 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate:
# 519 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Let's see what you brought.$"
# 520 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 521 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon:
# 522 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Want to keep this one, or should\n"
# 523 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "we log it and take it in?$"
# 524 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 525 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn:
# 526 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued and logged.\n"
# 527 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Thank you for this.$"
# 528 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 529 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndKept:
# 530 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued. It's yours to keep.$"
# 531 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 532 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet:
# 533 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Nothing caught on this\n"
# 534 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition yet.$"
# 535 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 536 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionEndedNothingCaught:
# 537 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Back already, and nothing to\n"
# 538 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "show for it.\p"
# 539 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's fine. Come find us again\n"
# 540 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "whenever you're ready for another\l"
# 541 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition.$"

# 544 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_JumpInPlace:
# 545 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	emote_exclamation_mark
# 546 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	jump_in_place_down
	step_end

# 549 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceRight:
# 550 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	face_right
	step_end

# 553 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceLeft:
# 554 "data/maps/FuchsiaCity_Reserve/scripts.pory"
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
# 283 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Expeditions aren't running yet.\n"
	.string "Talk to Fuji first.$"

FuchsiaCity_Reserve_EventScript_Worker2_Text_1:
# 293 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Ever been out on one of our\n"
	.string "expeditions?$"

FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0:
# 304 "data/maps/FuchsiaCity_Reserve/scripts.pory"
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
# 330 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You've used up today's\n"
	.string "expedition slots.\p"
	.string "Come back tomorrow.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1:
# 339 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'll need exactly one POKéMON\n"
	.string "in your party before you head\l"
	.string "out. Wouldn't want you catching\n"
	.string "over your limit.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2:
# 347 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Pick what you're cataloguing\n"
	.string "this time.\p$"
