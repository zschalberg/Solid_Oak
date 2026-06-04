EventScript_WorkbenchCrafting::
	lockall
	msgbox Text_AccessWorkbench, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_WorkbenchCancel
EventScript_CraftingLoop::
	checkitem ITEM_CONVERSION_KIT, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_CraftingNoKits
	message Text_CraftingSelectBall
	waitmessage
	multichoice 0, 0, MULTI_WORKBENCH, FALSE
	switch VAR_RESULT
	case 0, EventScript_CraftRedProtoball
	case 1, EventScript_CraftBluProtoball
	case 2, EventScript_CraftGrnProtoball
	case 3, EventScript_CraftBlkProtoball
	case 4, EventScript_WorkbenchCancel
	case MULTI_B_PRESSED, EventScript_WorkbenchCancel
	end

EventScript_CraftRedProtoball::
	setvar VAR_0x8004, 0
	goto EventScript_CheckMaxQuantity

EventScript_CraftBluProtoball::
	setvar VAR_0x8004, 1
	goto EventScript_CheckMaxQuantity

EventScript_CraftGrnProtoball::
	setvar VAR_0x8004, 2
	goto EventScript_CheckMaxQuantity

EventScript_CraftBlkProtoball::
	setvar VAR_0x8004, 3
	goto EventScript_CheckMaxQuantity

EventScript_CheckMaxQuantity::
	specialvar VAR_0x8005, GetMaxCraftableQuantity
	goto_if_eq VAR_0x8005, 0, EventScript_NoMaterials
	buffernumberstring STR_VAR_1, VAR_0x8005
	message Text_ChooseQuantity
	waitmessage
	multichoice 0, 0, MULTI_CRAFT_QUANTITY, FALSE
	switch VAR_RESULT
	case 0, EventScript_CraftOne
	case 1, EventScript_CraftFive
	case 2, EventScript_CraftTen
	case 3, EventScript_CraftMax
	case 4, EventScript_CraftingLoop
	case MULTI_B_PRESSED, EventScript_CraftingLoop
	end

EventScript_CraftOne::
	setvar VAR_0x8006, 1
	goto EventScript_DoCraft

EventScript_CraftFive::
	setvar VAR_0x8006, 5
	goto EventScript_DoCraft

EventScript_CraftTen::
	setvar VAR_0x8006, 10
	goto EventScript_DoCraft

EventScript_CraftMax::
	copyvar VAR_0x8006, VAR_0x8005
	goto EventScript_DoCraft

EventScript_DoCraft::
	compare VAR_0x8006, VAR_0x8005
	goto_if_gt EventScript_NotEnoughMaterials

	copyvar VAR_0x8005, VAR_0x8006
	specialvar VAR_RESULT, CraftProtoballs
	goto_if_eq VAR_RESULT, FALSE, EventScript_NotEnoughMaterials

	playfanfare MUS_OBTAIN_ITEM
	buffernumberstring STR_VAR_2, VAR_0x8006
	compare VAR_0x8004, 0
	call_if_eq EventScript_BufferRedBallName
	compare VAR_0x8004, 1
	call_if_eq EventScript_BufferBluBallName
	compare VAR_0x8004, 2
	call_if_eq EventScript_BufferGrnBallName
	compare VAR_0x8004, 3
	call_if_eq EventScript_BufferBlkBallName
	msgbox Text_CraftSuccess
	waitfanfare
	goto EventScript_CraftingLoop

EventScript_BufferRedBallName::
	bufferitemname STR_VAR_3, ITEM_LEVEL_BALL
	return

EventScript_BufferBluBallName::
	bufferitemname STR_VAR_3, ITEM_LURE_BALL
	return

EventScript_BufferGrnBallName::
	bufferitemname STR_VAR_3, ITEM_FRIEND_BALL
	return

EventScript_BufferBlkBallName::
	bufferitemname STR_VAR_3, ITEM_HEAVY_BALL
	return

EventScript_BufferRedApricornName::
	bufferitemname STR_VAR_2, ITEM_RED_APRICORN
	return

EventScript_BufferBluApricornName::
	bufferitemname STR_VAR_2, ITEM_BLUE_APRICORN
	return

EventScript_BufferGrnApricornName::
	bufferitemname STR_VAR_2, ITEM_GREEN_APRICORN
	return

EventScript_BufferBlkApricornName::
	bufferitemname STR_VAR_2, ITEM_BLACK_APRICORN
	return

EventScript_NoMaterials::
	compare VAR_0x8004, 0
	call_if_eq EventScript_BufferRedApricornName
	compare VAR_0x8004, 1
	call_if_eq EventScript_BufferBluApricornName
	compare VAR_0x8004, 2
	call_if_eq EventScript_BufferGrnApricornName
	compare VAR_0x8004, 3
	call_if_eq EventScript_BufferBlkApricornName
	msgbox Text_NoIngredients
	goto EventScript_CraftingLoop

EventScript_NotEnoughMaterials::
	msgbox Text_NotEnoughIngredients
	goto EventScript_CraftingLoop

EventScript_CraftingNoKits::
	msgbox Text_NoConversionKits
	goto EventScript_WorkbenchCancel

EventScript_WorkbenchCancel::
	msgbox Text_WorkbenchClosed
	releaseall
	end

Text_AccessWorkbench:
	.string "Would you like to use the Workbench?$"

Text_CraftingSelectBall:
	.string "Select which Protoball to craft.$"

Text_ChooseQuantity:
	.string "How many would you like to craft?\n(Max: {STR_VAR_1})$"

Text_CraftSuccess:
	.string "Crafted {STR_VAR_2} {STR_VAR_3}!$"

Text_NoConversionKits:
	.string "You don't have any Conversion Kits.\nThey can be bought at Poke Marts.$"

Text_NoIngredients:
	.string "You don't have the materials!\n"
	.string "You need 1 {STR_VAR_2} and\n"
	.string "1 Conversion Kit.$"

Text_NotEnoughIngredients:
	.string "You don't have enough materials for\n"
	.string "that quantity!$"

Text_WorkbenchClosed:
	.string "Closed the Workbench.$"
