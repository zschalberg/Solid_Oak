EventScript_CourierNPC::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox Text_CourierGreeting, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CourierGoodbye

	checkmoney 500
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CourierNoMoney

	@ Swoop-in animation
	special SpawnCourierBird
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry
	applymovement 0x1F, Movement_CourierBirdFlyIn
	waitmovement 0
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry

EventScript_CourierMainMenu::
	msgbox Text_CourierWhatToDo, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_COURIER_MENU, FALSE
	switch VAR_RESULT
	case 0, EventScript_CourierRetrieve
	case 1, EventScript_CourierSend
	case 2, EventScript_CourierFlyOut
	case MULTI_B_PRESSED, EventScript_CourierFlyOut
	end

EventScript_CourierRetrieve::
	@ Retrieve branch
	goto_if_set FLAG_FUJI_LAB_UPGRADE, EventScript_CourierRetrieveWithUpgrade
	
	msgbox Text_CourierChooseRoom, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_COURIER_ROOM_RANGES_NO_UPGRADE, FALSE
	switch VAR_RESULT
	case 0, EventScript_CourierChooseRooms1_4
	case 1, EventScript_CourierChooseRooms5_8
	case 2, EventScript_CourierMainMenu
	case MULTI_B_PRESSED, EventScript_CourierMainMenu
	end

EventScript_CourierRetrieveWithUpgrade::
	msgbox Text_CourierChooseRoom, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_COURIER_ROOM_RANGES_WITH_UPGRADE, FALSE
	switch VAR_RESULT
	case 0, EventScript_CourierChooseRooms1_4
	case 1, EventScript_CourierChooseRooms5_8
	case 2, EventScript_CourierChooseRooms9_10
	case 3, EventScript_CourierMainMenu
	case MULTI_B_PRESSED, EventScript_CourierMainMenu
	end

EventScript_CourierChooseRooms1_4::
	multichoice 0, 0, MULTI_COURIER_ROOMS_1_4, FALSE
	compare VAR_RESULT, 4 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve
	copyvar VAR_0x8004, VAR_RESULT @ Box ID 0-3
	goto EventScript_CourierSelectMon

EventScript_CourierChooseRooms5_8::
	multichoice 0, 0, MULTI_COURIER_ROOMS_5_8, FALSE
	compare VAR_RESULT, 4 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve
	copyvar VAR_0x8004, VAR_RESULT
	addvar VAR_0x8004, 4 @ Box ID 4-7
	goto EventScript_CourierSelectMon

EventScript_CourierChooseRooms9_10::
	multichoice 0, 0, MULTI_COURIER_ROOMS_9_10, FALSE
	compare VAR_RESULT, 2 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve
	copyvar VAR_0x8004, VAR_RESULT
	addvar VAR_0x8004, 8 @ Box ID 8-9
	goto EventScript_CourierSelectMon

EventScript_CourierSelectMon::
	special FujiLab_BufferRoomMons
	msgbox Text_CourierSelectMon, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_FUJI_ROOM_MONS, FALSE
	compare VAR_RESULT, 6 @ Cancel
	goto_if_eq EventScript_CourierRetrieve
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq EventScript_CourierRetrieve

	copyvar VAR_0x8006, VAR_RESULT @ Selected slot
	special FujiLab_IsSlotEmpty
	compare VAR_RESULT, TRUE
	goto_if_eq EventScript_CourierSlotEmpty

	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, 6
	goto_if_lt EventScript_CourierDoWithdraw
	goto EventScript_CourierDoSwap

EventScript_CourierSlotEmpty::
	msgbox Text_CourierSlotEmpty, MSGBOX_DEFAULT
	goto EventScript_CourierSelectMon

EventScript_CourierDoWithdraw::
	removemoney 500
	updatemoneybox
	fadescreen FADE_TO_BLACK
	special FujiLab_Withdraw
	fadescreen FADE_FROM_BLACK
	playse SE_PC_LOGIN
	msgbox Text_CourierRetrieveSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierFlyOut

EventScript_CourierDoSwap::
	msgbox Text_CourierSwapPrompt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CourierSelectMon

	copyvar VAR_0x8005, VAR_0x8004 @ Save box index
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255 @ Cancel
	goto_if_eq EventScript_CourierSelectMon

	removemoney 500
	updatemoneybox
	fadescreen FADE_TO_BLACK
	special FujiLab_Swap
	fadescreen FADE_FROM_BLACK
	playse SE_PC_LOGIN
	msgbox Text_CourierSwapSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierFlyOut

EventScript_CourierSend::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare VAR_RESULT, 1
	goto_if_le EventScript_CourierCantStoreLast

	specialvar VAR_RESULT, IsThereRoomInAnyBoxForMorePokemon
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CourierStorageFull

	msgbox Text_CourierSelectDeposit, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq EventScript_CourierMainMenu

	removemoney 500
	updatemoneybox
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8005, 255 @ Auto deposit
	special FujiLab_Deposit
	fadescreen FADE_FROM_BLACK
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CourierDepositFailed

	playse SE_PC_LOGIN
	msgbox Text_CourierSendSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierFlyOut

EventScript_CourierCantStoreLast::
	msgbox Text_CourierCantStoreLast, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierStorageFull::
	msgbox Text_CourierStorageFull, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierDepositFailed::
	msgbox Text_CourierDepositFailed, MSGBOX_DEFAULT
	goto EventScript_CourierMainMenu

EventScript_CourierFlyOut::
	hidemoneybox
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	waitmoncry
	applymovement 0x1F, Movement_CourierBirdFlyOut
	waitmovement 0
	special RemoveCourierBird
	msgbox Text_CourierFlyAway, MSGBOX_DEFAULT
	release
	end

EventScript_CourierNoMoney::
	hidemoneybox
	msgbox Text_CourierNoMoney, MSGBOX_DEFAULT
	release
	end

EventScript_CourierGoodbye::
	hidemoneybox
	msgbox Text_CourierGoodbye, MSGBOX_DEFAULT
	release
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
	.string "For a fee of ¥500, my PIDGEOT can\n"
	.string "carry POKéMON directly to or from\l"
	.string "MR. FUJI'S LAB.\p"
	.string "Would you like to hire my PIDGEOT?$"

Text_CourierWhatToDo:
	.string "What would you like my PIDGEOT to do?$"

Text_CourierChooseRoom:
	.string "Which Room is your POKéMON in?$"

Text_CourierSelectMon:
	.string "Select which POKéMON to retrieve.$"

Text_CourierSlotEmpty:
	.string "There is no POKéMON in that slot!$"

Text_CourierRetrieveSuccess:
	.string "PIDGEOT successfully delivered your\n"
	.string "POKéMON from the Sanctuary!$"

Text_CourierSwapPrompt:
	.string "Your party is full. Would you like to\n"
	.string "swap a POKéMON from your party?$"

Text_CourierSwapSuccess:
	.string "PIDGEOT successfully swapped your\n"
	.string "POKéMON with the Sanctuary!$"

Text_CourierSelectDeposit:
	.string "Select which POKéMON to send to\n"
	.string "the Sanctuary.$"

Text_CourierSendSuccess:
	.string "PIDGEOT successfully carried your\n"
	.string "POKéMON to the Sanctuary!$"

Text_CourierCantStoreLast:
	.string "You cannot send your last POKéMON!$"

Text_CourierStorageFull:
	.string "Mr. Fuji's Sanctuary is completely full!$"

Text_CourierDepositFailed:
	.string "Failed to deposit POKéMON.$"

Text_CourierFlyAway:
	.string "PIDGEOT flew away into the sky!$"

Text_CourierNoMoney:
	.string "Oh, you don't have enough money.\n"
	.string "Come back when you have ¥500.$"

Text_CourierGoodbye:
	.string "Safe travels!$"
