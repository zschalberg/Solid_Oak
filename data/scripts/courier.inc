EventScript_CourierNPC::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox Text_CourierGreeting, MSGBOX_YESNO
	compare VAR_0x800D, NO
	goto_if_eq EventScript_CourierGoodbye

	checkmoney 500
	compare VAR_0x800D, FALSE
	goto_if_eq EventScript_CourierNoMoney

	@ Swoop-in animation
	special SpawnCourierBird
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry
	applymovement 0x1F, Movement_CourierBirdFlyIn
	waitmovement 0
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry

	special Courier_ClearCart

EventScript_CourierMainMenu::
	msgbox Text_CourierWhatToDo, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_COURIER_MENU, FALSE
	switch VAR_0x800D
	case 0, EventScript_CourierSend
	case 1, EventScript_CourierRetrieve
	case 2, EventScript_CourierViewCart
	case 3, EventScript_CourierResetCart
	case 4, EventScript_CourierConfirmExchange
	case 5, EventScript_CourierFlyOut
	case MULTI_B_PRESSED, EventScript_CourierFlyOut
	end

EventScript_CourierSend::
	specialvar VAR_0x800D, IsThereRoomInAnyBoxForMorePokemon
	compare VAR_0x800D, FALSE
	goto_if_eq EventScript_CourierStorageFull

	msgbox Text_CourierSelectDeposit, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq EventScript_CourierMainMenu

	special Courier_StageDeposit
	switch VAR_0x800D
	case 0, EventScript_CourierDepositStagedSuccess
	case 1, EventScript_CourierDepositStagedAlready
	case 2, EventScript_CourierDepositStagedInvalid
	case 3, EventScript_CourierDepositStagedEmptyParty
	case 4, EventScript_CourierCartFull
	end

EventScript_CourierDepositStagedSuccess::
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox Text_CourierDepositStagedSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierDepositStagedAlready::
	msgbox Text_CourierDepositStagedAlready, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierDepositStagedInvalid::
	msgbox Text_CourierDepositStagedInvalid, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierDepositStagedEmptyParty::
	msgbox Text_CourierDepositStagedEmptyParty, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierCartFull::
	msgbox Text_CourierCartFull, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierRetrieve::
	goto_if_set FLAG_0x4AB, EventScript_CourierRetrieveWithUpgrade
	msgbox Text_CourierChooseRoom, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_COURIER_ROOM_RANGES_NO_UPGRADE, FALSE
	switch VAR_0x800D
	case 0, EventScript_CourierChooseRooms1_4
	case 1, EventScript_CourierChooseRooms5_8
	case 2, EventScript_CourierMainMenu
	case MULTI_B_PRESSED, EventScript_CourierMainMenu
	end

EventScript_CourierRetrieveWithUpgrade::
	msgbox Text_CourierChooseRoom, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_COURIER_ROOM_RANGES_WITH_UPGRADE, FALSE
	switch VAR_0x800D
	case 0, EventScript_CourierChooseRooms1_4
	case 1, EventScript_CourierChooseRooms5_8
	case 2, EventScript_CourierChooseRooms9_10
	case 3, EventScript_CourierMainMenu
	case MULTI_B_PRESSED, EventScript_CourierMainMenu
	end

EventScript_CourierChooseRooms1_4::
	multichoice 0, 0, MULTI_COURIER_ROOMS_1_4, FALSE
	compare VAR_0x800D, 4 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_0x800D, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve
	copyvar VAR_0x8004, VAR_0x800D @ Box ID 0-3
	goto EventScript_CourierSelectMon

EventScript_CourierChooseRooms5_8::
	multichoice 0, 0, MULTI_COURIER_ROOMS_5_8, FALSE
	compare VAR_0x800D, 4 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_0x800D, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve
	copyvar VAR_0x8004, VAR_0x800D
	addvar VAR_0x8004, 4 @ Box ID 4-7
	goto EventScript_CourierSelectMon

EventScript_CourierChooseRooms9_10::
	multichoice 0, 0, MULTI_COURIER_ROOMS_9_10, FALSE
	compare VAR_0x800D, 2 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_0x800D, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve
	copyvar VAR_0x8004, VAR_0x800D
	addvar VAR_0x8004, 8 @ Box ID 8-9
	goto EventScript_CourierSelectMon

EventScript_CourierSelectMon::
	special FujiLab_BufferRoomMons
	msgbox Text_CourierSelectMon, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FUJI_ROOM_MONS, FALSE
	compare VAR_0x800D, 6 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_0x800D, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve

	copyvar VAR_0x8006, VAR_0x800D @ Selected slot
	special FujiLab_IsSlotEmpty
	compare VAR_0x800D, TRUE
	goto_if_eq EventScript_CourierSlotEmpty

	special Courier_StageWithdraw
	switch VAR_0x800D
	case 0, EventScript_CourierWithdrawStagedSuccess
	case 1, EventScript_CourierWithdrawStagedAlready
	case 2, EventScript_CourierWithdrawStagedTooMany
	case 4, EventScript_CourierCartFull
	end

EventScript_CourierSlotEmpty::
	msgbox Text_CourierSlotEmpty, MSGBOX_DEFAULT
	goto EventScript_CourierSelectMon

EventScript_CourierWithdrawStagedSuccess::
	special Courier_BufferSingleWithdrawName
	msgbox Text_CourierWithdrawStagedSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierWithdrawStagedAlready::
	msgbox Text_CourierWithdrawStagedAlready, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierWithdrawStagedTooMany::
	msgbox Text_CourierWithdrawStagedTooMany, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierViewCart::
	special Courier_BufferCartString
	msgbox Text_CourierCartSummary, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierResetCart::
	special Courier_ClearCart
	msgbox Text_CourierCartReset, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierConfirmExchange::
	specialvar VAR_0x800D, Courier_GetCartSummary
	switch VAR_0x800D
	case 0, EventScript_CourierDoExchange
	case 1, EventScript_CourierExchangeEmptyParty
	case 2, EventScript_CourierExchangeTooMany
	case 3, EventScript_CourierExchangeStorageFull
	case 4, EventScript_CourierExchangeCartEmpty
	end

EventScript_CourierDoExchange::
	removemoney 500
	updatemoneybox
	fadescreenswapbuffers FADE_TO_BLACK
	special Courier_ExecuteCart
	fadescreenswapbuffers FADE_FROM_BLACK
	playse SE_PC_LOGIN
	msgbox Text_CourierExchangeSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierFlyOut

EventScript_CourierExchangeEmptyParty::
	msgbox Text_CourierExchangeEmptyParty, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierExchangeTooMany::
	msgbox Text_CourierExchangeTooMany, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierExchangeStorageFull::
	msgbox Text_CourierExchangeStorageFull, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierStorageFull::
	msgbox Text_CourierStorageFull, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierExchangeCartEmpty::
	msgbox Text_CourierExchangeCartEmpty, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierFlyOut::
	hidemoneybox
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry
	applymovement 0x1F, Movement_CourierBirdFlyOut
	waitmovement 0
	special RemoveCourierBird
	msgbox Text_CourierFlyAway, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CourierNoMoney::
	hidemoneybox
	msgbox Text_CourierNoMoney, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CourierGoodbye::
	hidemoneybox
	msgbox Text_CourierGoodbye, MSGBOX_DEFAULT
	releaseall
	end

@ Movements
Movement_CourierBirdFlyIn::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Movement_CourierBirdFlyOut::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ Texts
Text_CourierGreeting:
	.string "Hello! I am a SANCTUARY COURIER.\p"
	.string "For a single fee of ¥500, my PIDGEOT\n"
	.string "can exchange up to 6 POKéMON at once\l"
	.string "with MR. FUJI'S SANCTUARY LAB.\p"
	.string "Would you like to hire my PIDGEOT?$"

Text_CourierWhatToDo:
	.string "Hire active. What would you like to stage?$"

Text_CourierChooseRoom:
	.string "Which Room is the POKéMON in?$"

Text_CourierSelectMon:
	.string "Select which POKéMON to retrieve.$"

Text_CourierSlotEmpty:
	.string "There is no POKéMON in that slot!$"

Text_CourierDepositStagedSuccess:
	.string "{STR_VAR_1} was staged to send.$"

Text_CourierDepositStagedAlready:
	.string "That POKéMON is already staged!$"

Text_CourierDepositStagedInvalid:
	.string "Invalid selection.$"

Text_CourierDepositStagedEmptyParty:
	.string "You cannot send that POKéMON! Your\n"
	.string "party would become empty.$"

Text_CourierCartFull:
	.string "You cannot stage any more POKéMON!$"

Text_CourierWithdrawStagedSuccess:
	.string "{STR_VAR_1} was staged to retrieve.$"

Text_CourierWithdrawStagedAlready:
	.string "That POKéMON is already staged!$"

Text_CourierWithdrawStagedTooMany:
	.string "You cannot retrieve that POKéMON! Your\n"
	.string "party would exceed 6 POKéMON.\p"
	.string "Please stage a deposit first.$"

Text_CourierCartSummary:
	.string "Current Cart:\n"
	.string "Send: {STR_VAR_1}\l"
	.string "Retrieve: {STR_VAR_2}$"

Text_CourierCartReset:
	.string "Staged choices cleared successfully.$"

Text_CourierExchangeSuccess:
	.string "PIDGEOT successfully exchanged the\n"
	.string "POKéMON with the Sanctuary!$"

Text_CourierExchangeEmptyParty:
	.string "Error: Your party would become empty!$"

Text_CourierExchangeTooMany:
	.string "Error: Your party would exceed 6 POKéMON!$"

Text_CourierExchangeStorageFull:
	.string "Error: Sanctuary rooms have no room for\n"
	.string "your deposits!$"

Text_CourierExchangeCartEmpty:
	.string "You haven't staged any POKéMON to exchange!$"

Text_CourierStorageFull:
	.string "Mr. Fuji's Sanctuary is completely full!$"

Text_CourierSelectDeposit:
	.string "Select which POKéMON to send.$"

Text_CourierFlyAway:
	.string "PIDGEOT flew away into the sky!$"

Text_CourierNoMoney:
	.string "Oh, you don't have enough money.\n"
	.string "Come back when you have ¥500.$"

Text_CourierGoodbye:
	.string "Safe travels!$"

EventScript_UseCourierWhistle::
	lockall
	playse SE_GLASS_FLUTE
	msgbox Text_CourierWhistleBlew, MSGBOX_DEFAULT
	closemessage
	showmoneybox 0, 0

	checkmoney 500
	compare VAR_0x800D, FALSE
	goto_if_eq EventScript_CourierNoMoney

	@ Swoop-in animation
	special SpawnCourierBird
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry
	applymovement 0x1F, Movement_CourierBirdFlyIn
	waitmovement 0
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry

	special Courier_ClearCart
	goto EventScript_CourierMainMenu

Text_CourierWhistleBlew:
	.string "You blew the COURIER WHISTLE!\p"
	.string "A PIDGEOT flew down from the sky!$"
