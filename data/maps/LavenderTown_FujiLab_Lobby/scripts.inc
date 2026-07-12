LavenderTown_FujiLab_Lobby_MapScripts::
	.byte 0

LavenderTown_FujiLab_Lobby_EventScript_Assistant::
	lock
	faceplayer
	msgbox LavenderTown_FujiLab_Lobby_Text_AssistantGreeting, MSGBOX_DEFAULT

LavenderTown_FujiLab_Lobby_EventScript_LoopDeposit::
	msgbox LavenderTown_FujiLab_Lobby_Text_AskDeposit, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_FujiLab_Lobby_EventScript_AskUpgrade

	special ShowPokemonStorageSystemPC_MoveMode
	waitstate
	callnative UpdateFollowingPokemon
	goto LavenderTown_FujiLab_Lobby_EventScript_AskUpgrade

LavenderTown_FujiLab_Lobby_EventScript_AskUpgrade::
	goto_if_set FLAG_FUJI_LAB_UPGRADE, LavenderTown_FujiLab_Lobby_EventScript_Exit
	showmoneybox 0, 0
	msgbox LavenderTown_FujiLab_Lobby_Text_AskUpgrade, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavenderTown_FujiLab_Lobby_EventScript_ExitUpgrade

	checkmoney 50000
	compare VAR_RESULT, FALSE
	goto_if_eq LavenderTown_FujiLab_Lobby_EventScript_NotEnoughMoney

	removemoney 50000
	updatemoneybox
	setflag FLAG_FUJI_LAB_UPGRADE
	playfanfare MUS_LEVEL_UP
	msgbox LavenderTown_FujiLab_Lobby_Text_UpgradeSuccess, MSGBOX_DEFAULT
	waitfanfare
	hidemoneybox
	release
	end

LavenderTown_FujiLab_Lobby_EventScript_NotEnoughMoney::
	msgbox LavenderTown_FujiLab_Lobby_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

LavenderTown_FujiLab_Lobby_EventScript_ExitUpgrade::
	hidemoneybox
	goto LavenderTown_FujiLab_Lobby_EventScript_Exit

LavenderTown_FujiLab_Lobby_EventScript_Exit::
	msgbox LavenderTown_FujiLab_Lobby_Text_Goodbye, MSGBOX_DEFAULT
	release
	end

LavenderTown_FujiLab_Lobby_EventScript_BlockedWorker::
	msgbox LavenderTown_FujiLab_Lobby_Text_BlockedWorker, MSGBOX_NPC
	end

LavenderTown_FujiLab_Lobby_Text_AssistantGreeting:
	.string "Hello! Welcome to MR. FUJI'S\n"
	.string "POKéMON SANCTUARY LAB.$"

LavenderTown_FujiLab_Lobby_Text_AskDeposit:
	.string "Would you like to manage your\n"
	.string "Sanctuary POKéMON?$"

LavenderTown_FujiLab_Lobby_Text_AskUpgrade:
	.string "We are currently looking for a donation\n"
	.string "of ¥50,000 to renovate Rooms 9 and 10.\p"
	.string "Would you like to donate ¥50,000?$"

LavenderTown_FujiLab_Lobby_Text_UpgradeSuccess:
	.string "Thank you so much for your donation!\n"
	.string "We will open Rooms 9 and 10 immediately!$"

LavenderTown_FujiLab_Lobby_Text_NotEnoughMoney:
	.string "Oh… It seems you don't have enough\n"
	.string "money for the donation.$"

LavenderTown_FujiLab_Lobby_Text_Goodbye:
	.string "Please visit the Sanctuary rooms\n"
	.string "to see your POKéMON!$"

LavenderTown_FujiLab_Lobby_Text_BlockedWorker:
	.string "We are currently renovating Rooms 9\n"
	.string "and 10.\p"
	.string "They should be ready soon if we can\n"
	.string "get a donation for the expansion!$"

.global FujiLab_EventScript_InteractRoomMon
FujiLab_EventScript_InteractRoomMon::
	lock
	faceplayer
	copyvar VAR_0x8006, VAR_LAST_TALKED
	subvar VAR_0x8006, 1
	special FujiLab_GetPokemonInfo
	msgbox FujiLab_Text_MonExcitedToSeeYou, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FujiLab_EventScript_EndInteract
	
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, 6
	goto_if_lt FujiLab_EventScript_DoWithdraw
	
	msgbox FujiLab_Text_PartyFullSwapPrompt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FujiLab_EventScript_EndInteract
	
	copyvar VAR_0x8005, VAR_0x8004 @ Save box index
	copyvar VAR_0x8006, VAR_LAST_TALKED @ Save local ID (1-based)
	subvar VAR_0x8006, 1 @ Convert to 0-based slot index
	
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255 @ PARTY_NOTHING_CHOSEN
	goto_if_eq FujiLab_EventScript_EndInteract
	
	fadescreenswapbuffers FADE_TO_BLACK
	special FujiLab_Swap
	special FujiLab_InitRoomObjects
	removeobject VAR_LAST_TALKED
	addobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_PC_LOGIN
	msgbox FujiLab_Text_SwapSuccess, MSGBOX_DEFAULT
	release
	end

FujiLab_EventScript_DoWithdraw::
	fadescreenswapbuffers FADE_TO_BLACK
	special FujiLab_Withdraw
	special FujiLab_InitRoomObjects
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_PC_LOGIN
	msgbox FujiLab_Text_WithdrawSuccess, MSGBOX_DEFAULT
	release
	end


FujiLab_EventScript_EndInteract::
	release
	end

FujiLab_Text_MonExcitedToSeeYou:
	.string "{STR_VAR_1} is excited to see you!\n"
	.string "Do you want to add it to your party?$"

FujiLab_Text_PartyFullSwapPrompt:
	.string "Your party is currently full.\n"
	.string "Would you like to swap a POKéMON\l"
	.string "from your party for {STR_VAR_1}?$"

FujiLab_Text_SwapSuccess:
	.string "Swapped POKéMON successfully!$"

FujiLab_Text_WithdrawSuccess:
	.string "{STR_VAR_1} was added to your party!$"
