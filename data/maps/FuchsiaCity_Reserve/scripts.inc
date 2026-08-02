FuchsiaCity_Reserve_MapScripts::
# 20 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_Reserve_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FuchsiaCity_Reserve_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 21 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	map_script_2 VAR_SCENE_FUCHSIA_RESERVE, 0, FuchsiaCity_Reserve_EventScript_CheckIntro
	.2byte 0


FuchsiaCity_Reserve_OnTransition::
# 26 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_FUJI
# 27 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_AGATHA
	end


FuchsiaCity_Reserve_EventScript_CheckIntro::
# 32 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_set FLAG_HIDE_FUCHSIA_FUJI, FuchsiaCity_Reserve_EventScript_CheckIntro_2
	end

FuchsiaCity_Reserve_EventScript_CheckIntro_2:
# 33 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Intro
	end


FuchsiaCity_Reserve_EventScript_Intro::
# 44 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lockall
# 45 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearflag FLAG_HIDE_RESERVE_FUJI
# 46 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearflag FLAG_HIDE_RESERVE_AGATHA
# 48 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 49 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_0
# 53 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 54 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER1, FuchsiaCity_Reserve_JumpInPlace
# 55 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitmovement 0
# 56 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_1
# 60 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 61 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER1, FuchsiaCity_Reserve_FaceRight
# 62 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER2, FuchsiaCity_Reserve_JumpInPlace
# 63 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitmovement 0
# 64 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_2
# 67 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 68 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	applymovement LOCALID_RESERVE_WORKER2, FuchsiaCity_Reserve_FaceLeft
# 69 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitmovement 0
# 70 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 71 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 72 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_3
# 74 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 75 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearmugshot
# 77 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 78 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_4
# 86 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 87 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_5
# 96 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 97 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 98 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 99 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Intro_Text_6
# 100 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 101 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	clearmugshot
# 104 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	giveitem ITEM_RED_PROTOBALL, 2
# 105 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_FUJI
# 106 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_HIDE_RESERVE_AGATHA
# 107 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_SCENE_FUCHSIA_RESERVE, 1
# 108 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setflag FLAG_KRABBY_QUEST_COMPLETE
# 109 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	releaseall
	end


FuchsiaCity_Reserve_EventScript_Worker1::
# 118 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lock
# 119 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 120 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_Reserve_EventScript_Worker1_2
# 128 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1Menu
	end

FuchsiaCity_Reserve_EventScript_Worker1_2:
# 121 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker1_Text_0
# 124 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 125 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end


# 132 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 133 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1Menu::
# 134 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1Welcome, MSGBOX_DEFAULT
# 135 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1MenuLoop::
# 136 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	showcoinsbox 19, 0
# 137 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESEARCH_MAIN, FALSE
# 138 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	switch VAR_RESULT
# 139 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 0, FuchsiaCity_Reserve_EventScript_TurnInMon
# 140 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 1, FuchsiaCity_Reserve_EventScript_ExchangeShop
# 141 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 2, FuchsiaCity_Reserve_EventScript_TransferBall
# 142 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 3, FuchsiaCity_Reserve_EventScript_Worker1Info
# 143 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case 4, FuchsiaCity_Reserve_EventScript_Worker1End
# 144 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	case MULTI_B_PRESSED, FuchsiaCity_Reserve_EventScript_Worker1End
# 145 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 146 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 147 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInMon::
# 148 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 149 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 1
# 150 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_le FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused
# 151 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInPrompt, MSGBOX_DEFAULT
# 152 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 153 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 154 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, 255
# 155 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 156 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonEgg
# 157 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 158 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TurnInEggRefused
# 159 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonResearchBall
# 160 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 161 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_EvaluateMon
# 162 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WarningNotResearchBall, MSGBOX_YESNO
# 163 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
# 164 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 165 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 166 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_EvaluateMon::
# 167 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateSelectedResearchMon
# 168 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_EvaluationResult, MSGBOX_YESNO
# 169 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
# 170 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 171 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonNewFamily
# 172 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 173 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	call_if_eq FuchsiaCity_Reserve_EventScript_ShowNewFamilyText
# 174 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special TurnInSelectedResearchMon
# 175 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	updatecoinsbox 19, 0
# 176 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 177 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInSuccess, MSGBOX_DEFAULT
# 178 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitfanfare
# 179 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 180 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 181 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ShowNewFamilyText::
# 182 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NewFamilyBonusMsg, MSGBOX_DEFAULT
# 183 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	return
# 184 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 185 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInLastMonRefused::
# 186 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg, MSGBOX_DEFAULT
# 187 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 188 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 189 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TurnInEggRefused::
# 190 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg, MSGBOX_DEFAULT
# 191 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 192 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 193 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ── Exchange Shop and Transfer Ball are placeholders: TurnInSelectedResearchMon
# 194 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ already awards Research Coins via AddCoins, but the shop that spends them on
# 195 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ Fuji's box space upgrades / Evolution Stones / research items isn't built
# 196 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ yet. Wire ExchangeShop up to a real shop/buymenu once that item list exists.
# 197 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_ExchangeShop::
# 198 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExchangeShopComingSoon, MSGBOX_DEFAULT
# 199 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 200 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 201 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferBall::
# 202 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	checkcoins VAR_TEMP_1
# 203 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_TEMP_1, 500
# 204 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_lt FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer
# 205 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	getpartysize
# 206 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
# 207 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 208 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferPrompt, MSGBOX_DEFAULT
# 209 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special ChoosePartyMon
# 210 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitstate
# 211 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_0x8004, 255
# 212 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 213 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonEgg
# 214 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, TRUE
# 215 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferEggRefused
# 216 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special IsSelectedMonResearchBall
# 217 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
# 218 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_TransferNotResearchBall
# 219 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	removecoins 500
# 220 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	updatecoinsbox 19, 0
# 221 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special TransferSelectedMonToPokeBall
# 222 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 223 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferSuccess, MSGBOX_DEFAULT
# 224 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	waitfanfare
# 225 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 226 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 227 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferEggRefused::
# 228 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferEggRefusedMsg, MSGBOX_DEFAULT
# 229 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 230 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 231 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_TransferNotResearchBall::
# 232 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg, MSGBOX_DEFAULT
# 233 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 234 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 235 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_NotEnoughCoinsTransfer::
# 236 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg, MSGBOX_DEFAULT
# 237 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 238 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 239 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1Info::
# 240 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1Info, MSGBOX_DEFAULT
# 241 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker1MenuLoop
# 242 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 243 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker1End::
# 244 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	hidecoinsbox 19, 0
# 245 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_Worker1End, MSGBOX_DEFAULT
# 246 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 247 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end

FuchsiaCity_Reserve_EventScript_Worker2::
# 255 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	lock
# 256 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	faceplayer
# 257 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_Reserve_EventScript_Worker2_2
# 264 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_set FLAG_RESERVE_CONTEST_ACTIVE, FuchsiaCity_Reserve_EventScript_Worker2_5
# 268 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_1, MSGBOX_YESNO
# 270 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2_8
# 274 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end

FuchsiaCity_Reserve_EventScript_Worker2_2:
# 258 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2_Text_0
# 260 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 261 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2_5:
# 265 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2ActiveSession
	end

FuchsiaCity_Reserve_EventScript_Worker2_8:
# 271 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Explain
	end


FuchsiaCity_Reserve_EventScript_Worker2Explain::
# 279 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0
# 297 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 298 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Start
	end


FuchsiaCity_Reserve_EventScript_Worker2Start::
# 303 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, GetReserveContestAttemptsRemaining
# 304 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_2
# 312 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	specialvar VAR_RESULT, CheckCanRegisterReserveContest
# 313 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Start_5
# 322 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2
# 324 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 325 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto FuchsiaCity_Reserve_EventScript_Worker2Category
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_2:
# 305 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_0
# 308 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 309 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end

FuchsiaCity_Reserve_EventScript_Worker2Start_5:
# 314 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1
# 318 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	closemessage
# 319 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
	end


# 329 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 330 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Category::
# 331 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	multichoice 0, 0, MULTI_RESERVE_CONTEST_CATEGORY, FALSE
# 332 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
# 333 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq FuchsiaCity_Reserve_EventScript_Worker2Cancelled
# 334 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 335 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special StartReserveContestSession
# 336 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_ExpeditionStarted, MSGBOX_DEFAULT
# 337 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 338 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 339 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 340 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2Cancelled::
# 341 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 342 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 343 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 344 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2ActiveSession::
# 345 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_unset FLAG_RESERVE_CONTEST_CAUGHT, FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet
# 346 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate, MSGBOX_DEFAULT
# 347 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special EvaluateReserveContestCatch
# 348 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox gStringVar4, MSGBOX_DEFAULT
# 349 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon, MSGBOX_YESNO
# 350 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_Reserve_EventScript_Worker2KeepMon
# 351 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 1
# 352 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 353 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn, MSGBOX_DEFAULT
# 354 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 355 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 356 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 357 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2KeepMon::
# 358 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	setvar VAR_0x8004, 0
# 359 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	special FinalizeReserveContestCatch
# 360 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_CataloguedAndKept, MSGBOX_DEFAULT
# 361 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 362 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 363 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 364 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_EventScript_Worker2NoSpecimenYet::
# 365 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	msgbox FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet, MSGBOX_DEFAULT
# 366 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	release
# 367 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	end
# 368 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 369 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 370 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ TEXT
# 371 "data/maps/FuchsiaCity_Reserve/scripts.pory"
@ ============================================================================
# 372 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 373 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Welcome:
# 374 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Every specimen you bring in gets\n"
# 375 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "logged and turned into Research\l"
# 376 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins.\p"
# 377 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Spend them on box space for\n"
# 378 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Fuji's Sanctuary, Evolution\l"
# 379 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Stones, or other research gear\n"
# 380 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "as we stock it.$"
# 381 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 382 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInPrompt:
# 383 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON are you\n"
# 384 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "turning in?$"
# 385 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 386 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WarningNotResearchBall:
# 387 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one wasn't caught in a\n"
# 388 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "RESEARCH BALL. We can still log\l"
# 389 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "it, but the Pokemon will not be\n"
# 390 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "returned.\p"
# 391 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn it in anyway?$"
# 392 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 393 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_EvaluationResult:
# 394 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "{STR_VAR_3}\p"
# 395 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Turn in {STR_VAR_1}?$"
# 396 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 397 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NewFamilyBonusMsg:
# 398 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "First entry for this family.\n"
# 399 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's worth extra.$"
# 400 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 401 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInSuccess:
# 402 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Logged. {STR_VAR_3} Research\n"
# 403 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Coins added.$"
# 404 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 405 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInLastMonRefusedMsg:
# 406 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Can't take your only POKéMON.\n"
# 407 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'd have nothing to research\l"
# 408 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "with.$"
# 409 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 410 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TurnInEggRefusedMsg:
# 411 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's still an egg. Come back\n"
# 412 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "once it's hatched.$"
# 413 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 414 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExchangeShopComingSoon:
# 415 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "The exchange shop isn't stocked\n"
# 416 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "yet. Check back once we've got\l"
# 417 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "inventory worth selling.$"
# 418 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 419 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferPrompt:
# 420 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Which POKéMON gets a proper\n"
# 421 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL?$"
# 422 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 423 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferEggRefusedMsg:
# 424 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Eggs don't need re-balling.$"
# 425 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 426 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferNotResearchBallMsg:
# 427 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one's already in a\n"
# 428 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "standard POKé BALL.$"
# 429 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 430 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_TransferSuccess:
# 431 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Done. Transferred to a\n"
# 432 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "POKé BALL.$"
# 433 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 434 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NotEnoughCoinsTransferMsg:
# 435 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That's 500 Research Coins.\n"
# 436 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You're short.$"
# 437 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 438 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1Info:
# 439 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Research Balls give a research\n"
# 440 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "bonus when you turn a catch in -\l"
# 441 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "no penalty on the coin count.\p"
# 442 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Standard balls still count, just\n"
# 443 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "at a lower rate.$"
# 444 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 445 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_Worker1End:
# 446 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Come back any time.$"
# 447 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 448 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_ExpeditionStarted:
# 449 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Good luck out there.\n"
# 450 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Bring back what you catch.$"
# 451 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 452 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WelcomeBackLetUsEvaluate:
# 453 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Let's see what you brought.$"
# 454 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 455 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_WouldYouLikeToKeepMon:
# 456 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Want to keep this one, or should\n"
# 457 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "we log it and take it in?$"
# 458 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 459 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndTurnedIn:
# 460 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued and logged.\n"
# 461 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Thank you for this.$"
# 462 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 463 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_CataloguedAndKept:
# 464 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Catalogued. It's yours to keep.$"
# 465 "data/maps/FuchsiaCity_Reserve/scripts.pory"

# 466 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_Text_NoSpecimenCaughtYet:
# 467 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Nothing caught on this\n"
# 468 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "expedition yet.$"

# 471 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_JumpInPlace:
# 472 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	emote_exclamation_mark
# 473 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	jump_in_place_down
	step_end

# 476 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceRight:
# 477 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	face_right
	step_end

# 480 "data/maps/FuchsiaCity_Reserve/scripts.pory"
FuchsiaCity_Reserve_FaceLeft:
# 481 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	face_left
	step_end

FuchsiaCity_Reserve_EventScript_Intro_Text_0:
# 49 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "This is the rest of it.\p"
	.string "Two people, most days. It's not\n"
	.string "much, but it's what the funding\l"
	.string "allows.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_1:
# 56 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "This one handles what comes in -\n"
	.string "turn-ins, records, the ledger.\p"
	.string "Talk to her to turn in your\n"
	.string "Krabby and other Pokemon.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_2:
# 64 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "That one runs the expeditions.\n"
	.string "Catch counts, catalogue entries,\l"
	.string "that sort of thing.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_3:
# 72 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Two people and a building.\n"
	.string "That's the operation?$"

FuchsiaCity_Reserve_EventScript_Intro_Text_4:
# 78 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "For now.\p"
	.string "The biggest issue is the lack\n"
	.string "of proper containment equipment.\p"
	.string "I have a few connections at\n"
	.string "Silph Co. that are working on\n"
	.string "containment issues in SAFFRON.\p"
	.string "When you get time, head there\n"
	.string "and introduce yourself.$"

FuchsiaCity_Reserve_EventScript_Intro_Text_5:
# 87 "data/maps/FuchsiaCity_Reserve/scripts.pory"
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
# 99 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Finally.$"

FuchsiaCity_Reserve_EventScript_Worker1_Text_0:
# 121 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Still getting the ledgers set up.\n"
	.string "Come back once Fuji's shown you\l"
	.string "around properly.$"

FuchsiaCity_Reserve_EventScript_Worker2_Text_0:
# 258 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Expeditions aren't running yet.\n"
	.string "Talk to Fuji first.$"

FuchsiaCity_Reserve_EventScript_Worker2_Text_1:
# 268 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Ever been out on one of our\n"
	.string "expeditions?$"

FuchsiaCity_Reserve_EventScript_Worker2Explain_Text_0:
# 279 "data/maps/FuchsiaCity_Reserve/scripts.pory"
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
# 305 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You've used up today's\n"
	.string "expedition slots.\p"
	.string "Come back tomorrow.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_1:
# 314 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "You'll need exactly one POKéMON\n"
	.string "in your party before you head\l"
	.string "out. Wouldn't want you catching\n"
	.string "over your limit.$"

FuchsiaCity_Reserve_EventScript_Worker2Start_Text_2:
# 322 "data/maps/FuchsiaCity_Reserve/scripts.pory"
	.string "Pick what you're cataloguing\n"
	.string "this time.\p$"
