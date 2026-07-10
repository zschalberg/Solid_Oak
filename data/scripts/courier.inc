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

	@ Reset change tracker and open PC screen
	special FujiLab_ResetStorageChangeFlag
	special ShowPokemonStorageSystemPC_MoveMode
	waitstate

	@ Check if changes were made
	specialvar VAR_RESULT, FujiLab_DidStorageChange
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CourierNoChanges

	@ Charge ¥500 and print success
	removemoney 500
	updatemoneybox
	playse SE_PC_LOGIN
	msgbox Text_CourierExchangeSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierFlyOut

EventScript_CourierNoChanges::
	msgbox Text_CourierNoChanges, MSGBOX_DEFAULT
	goto EventScript_CourierFlyOut

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

EventScript_UseCourierWhistle::
	lockall
	playse SE_GLASS_FLUTE
	msgbox Text_CourierWhistleBlew, MSGBOX_DEFAULT
	closemessage
	showmoneybox 0, 0

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

	@ Reset change tracker and open PC screen
	special FujiLab_ResetStorageChangeFlag
	special ShowPokemonStorageSystemPC_MoveMode
	waitstate

	@ Check if changes were made
	specialvar VAR_RESULT, FujiLab_DidStorageChange
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_CourierNoChanges

	@ Charge ¥500 and print success
	removemoney 500
	updatemoneybox
	playse SE_PC_LOGIN
	msgbox Text_CourierExchangeSuccess, MSGBOX_DEFAULT
	goto EventScript_CourierFlyOut

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
	.string "can exchange POKéMON with\l"
	.string "MR. FUJI'S SANCTUARY LAB.\p"
	.string "Would you like to hire my PIDGEOT?$"

Text_CourierExchangeSuccess:
	.string "PIDGEOT successfully exchanged the\n"
	.string "POKéMON with the Sanctuary!$"

Text_CourierNoChanges:
	.string "No changes were made.\n"
	.string "PIDGEOT flew away.$"

Text_CourierFlyAway:
	.string "PIDGEOT flew away into the sky!$"

Text_CourierNoMoney:
	.string "Oh, you don't have enough money.\n"
	.string "Come back when you have ¥500.$"

Text_CourierGoodbye:
	.string "Safe travels!$"

Text_CourierWhistleBlew:
	.string "You blew the COURIER WHISTLE!\p"
	.string "A PIDGEOT flew down from the sky!$"
