EventScript_WorkbenchCrafting::
	lockall
	msgbox Text_AccessWorkbench, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_WorkbenchCancel
EventScript_CraftingLoop::
	message Text_CraftingSelectCategory
	waitmessage
	multichoice 0, 0, MULTI_WORKBENCH_MENU, FALSE
	switch VAR_RESULT
	case 0, EventScript_SelectBallUpgrade
	case 1, EventScript_SelectMedicineCrafting
	case 2, EventScript_WorkbenchCancel
	case MULTI_B_PRESSED, EventScript_WorkbenchCancel
	end

EventScript_SelectBallUpgrade::
	message Text_UpgradeSelectSource
	waitmessage
	multichoice 0, 0, MULTI_WORKBENCH_UPGRADE_SOURCE, FALSE
	switch VAR_RESULT
	case 0, EventScript_UpgradeMonBall
	case 1, EventScript_UpgradeBagBall
	case 2, EventScript_CraftingLoop
	case MULTI_B_PRESSED, EventScript_CraftingLoop
	end

@ Result codes below (0/1/2) mirror UPGRADE_RESULT_SUCCESS/NOT_UPGRADEABLE/NEED_APRICORN in include/ball_economy.h.
EventScript_UpgradeMonBall::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EventScript_SelectBallUpgrade
	specialvar VAR_RESULT, GetSelectedMonUpgradeInfo
	goto_if_eq VAR_RESULT, 1, EventScript_UpgradeNotEligible
	checkitem VAR_0x8007, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_UpgradeMonNeedApricorn
	bufferitemname STR_VAR_2, VAR_0x8007
	msgbox Text_ConfirmUpgradeMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_SelectBallUpgrade
	specialvar VAR_RESULT, UpgradeSelectedMonBall
	bufferitemname STR_VAR_2, VAR_0x8007
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_UpgradeSuccessMon
	waitfanfare
	goto EventScript_SelectBallUpgrade

EventScript_UpgradeMonNeedApricorn::
	bufferitemname STR_VAR_2, VAR_0x8007
	msgbox Text_UpgradeNeedApricorn
	goto EventScript_SelectBallUpgrade

EventScript_UpgradeNotEligible::
	msgbox Text_UpgradeNotEligible
	goto EventScript_SelectBallUpgrade

EventScript_UpgradeBagBall::
	message Text_UpgradeSelectBagBall
	waitmessage
	multichoice 0, 0, MULTI_WORKBENCH, FALSE
	switch VAR_RESULT
	case 0, EventScript_UpgradeBagBall_Red
	case 1, EventScript_UpgradeBagBall_Blu
	case 2, EventScript_UpgradeBagBall_Grn
	case 3, EventScript_UpgradeBagBall_Blk
	case 4, EventScript_SelectBallUpgrade
	case MULTI_B_PRESSED, EventScript_SelectBallUpgrade
	end

EventScript_UpgradeBagBall_Red::
	setvar VAR_0x8004, 0
	goto EventScript_DoBagUpgrade

EventScript_UpgradeBagBall_Blu::
	setvar VAR_0x8004, 1
	goto EventScript_DoBagUpgrade

EventScript_UpgradeBagBall_Grn::
	setvar VAR_0x8004, 2
	goto EventScript_DoBagUpgrade

EventScript_UpgradeBagBall_Blk::
	setvar VAR_0x8004, 3
	goto EventScript_DoBagUpgrade

EventScript_DoBagUpgrade::
	specialvar VAR_RESULT, TryUpgradeBagBallTier
	switch VAR_RESULT
	case 0, EventScript_UpgradeBagBallSuccess
	case 2, EventScript_UpgradeMonNeedApricorn
	case 1, EventScript_UpgradeNotEligible
	end

EventScript_UpgradeBagBallSuccess::
	bufferitemname STR_VAR_2, VAR_0x8007
	playfanfare MUS_OBTAIN_ITEM
	msgbox Text_UpgradeSuccessBag
	waitfanfare
	goto EventScript_SelectBallUpgrade

EventScript_NotEnoughMaterials::
	msgbox Text_NotEnoughIngredients
	goto EventScript_CraftingLoop

EventScript_SelectMedicineCrafting::
	checkitem ITEM_BREWING_KIT, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_CraftingNoBrewingKits
	message Text_CraftingSelectMedicine
	waitmessage
	multichoice 0, 0, MULTI_MEDICINE_CRAFTING, FALSE
	switch VAR_RESULT
	case 0, EventScript_CraftPotion
	case 1, EventScript_CraftSuperPotion
	case 2, EventScript_CraftHyperPotion
	case 3, EventScript_CraftFullHeal
	case 4, EventScript_CraftRevive
	case 5, EventScript_CraftingLoop
	case MULTI_B_PRESSED, EventScript_CraftingLoop
	end

EventScript_CraftingNoBrewingKits::
	msgbox Text_NoBrewingKits
	goto EventScript_CraftingLoop

EventScript_CraftPotion::
	setvar VAR_0x8004, 0
	goto EventScript_CheckMaxMedicineQuantity

EventScript_CraftSuperPotion::
	setvar VAR_0x8004, 1
	goto EventScript_CheckMaxMedicineQuantity

EventScript_CraftHyperPotion::
	setvar VAR_0x8004, 2
	goto EventScript_CheckMaxMedicineQuantity

EventScript_CraftFullHeal::
	setvar VAR_0x8004, 3
	goto EventScript_CheckMaxMedicineQuantity

EventScript_CraftRevive::
	setvar VAR_0x8004, 4
	goto EventScript_CheckMaxMedicineQuantity

EventScript_CheckMaxMedicineQuantity::
	specialvar VAR_0x8005, GetMaxMedicineCraftableQuantity
	goto_if_eq VAR_0x8005, 0, EventScript_NoMedicineMaterials
	buffernumberstring STR_VAR_1, VAR_0x8005
	message Text_ChooseQuantity
	waitmessage
	multichoice 0, 0, MULTI_CRAFT_QUANTITY, FALSE
	switch VAR_RESULT
	case 0, EventScript_CraftMedicineOne
	case 1, EventScript_CraftMedicineFive
	case 2, EventScript_CraftMedicineTen
	case 3, EventScript_CraftMedicineMax
	case 4, EventScript_SelectMedicineCrafting
	case MULTI_B_PRESSED, EventScript_SelectMedicineCrafting
	end

EventScript_CraftMedicineOne::
	setvar VAR_0x8006, 1
	goto EventScript_DoMedicineCraft

EventScript_CraftMedicineFive::
	setvar VAR_0x8006, 5
	goto EventScript_DoMedicineCraft

EventScript_CraftMedicineTen::
	setvar VAR_0x8006, 10
	goto EventScript_DoMedicineCraft

EventScript_CraftMedicineMax::
	copyvar VAR_0x8006, VAR_0x8005
	goto EventScript_DoMedicineCraft

EventScript_DoMedicineCraft::
	compare VAR_0x8006, VAR_0x8005
	goto_if_gt EventScript_NotEnoughMaterials

	copyvar VAR_0x8005, VAR_0x8006
	specialvar VAR_RESULT, CraftMedicine
	goto_if_eq VAR_RESULT, FALSE, EventScript_NotEnoughMaterials

	playfanfare MUS_OBTAIN_ITEM
	buffernumberstring STR_VAR_2, VAR_0x8006
	compare VAR_0x8004, 0
	call_if_eq EventScript_BufferEnergyPowderName
	compare VAR_0x8004, 1
	call_if_eq EventScript_BufferEnergyTonicName
	compare VAR_0x8004, 2
	call_if_eq EventScript_BufferEnergyRootName
	compare VAR_0x8004, 3
	call_if_eq EventScript_BufferHealPowderName
	compare VAR_0x8004, 4
	call_if_eq EventScript_BufferRevivalHerbName
	msgbox Text_CraftSuccess
	waitfanfare
	goto EventScript_SelectMedicineCrafting

EventScript_BufferEnergyPowderName::
	bufferitemname STR_VAR_3, ITEM_ENERGY_POWDER
	return

EventScript_BufferEnergyTonicName::
	bufferitemname STR_VAR_3, ITEM_ENERGY_TONIC
	return

EventScript_BufferEnergyRootName::
	bufferitemname STR_VAR_3, ITEM_ENERGY_ROOT
	return

EventScript_BufferHealPowderName::
	bufferitemname STR_VAR_3, ITEM_HEAL_POWDER
	return

EventScript_BufferRevivalHerbName::
	bufferitemname STR_VAR_3, ITEM_REVIVAL_HERB
	return

EventScript_BufferRazzBerryName::
	bufferitemname STR_VAR_2, ITEM_RAZZ_BERRY
	return

EventScript_BufferBlukBerryName::
	bufferitemname STR_VAR_2, ITEM_BLUK_BERRY
	return

EventScript_BufferNanabBerryName::
	bufferitemname STR_VAR_2, ITEM_NANAB_BERRY
	return

EventScript_BufferWepearBerryName::
	bufferitemname STR_VAR_2, ITEM_WEPEAR_BERRY
	return

EventScript_BufferPinapBerryName::
	bufferitemname STR_VAR_2, ITEM_PINAP_BERRY
	return

EventScript_NoMedicineMaterials::
	compare VAR_0x8004, 0
	call_if_eq EventScript_BufferRazzBerryName
	compare VAR_0x8004, 1
	call_if_eq EventScript_BufferBlukBerryName
	compare VAR_0x8004, 2
	call_if_eq EventScript_BufferNanabBerryName
	compare VAR_0x8004, 3
	call_if_eq EventScript_BufferWepearBerryName
	compare VAR_0x8004, 4
	call_if_eq EventScript_BufferPinapBerryName
	msgbox Text_NoMedicineIngredients
	goto EventScript_SelectMedicineCrafting

EventScript_WorkbenchCancel::
	msgbox Text_WorkbenchClosed
	releaseall
	end

Text_AccessWorkbench:
	.string "Would you like to use the Workbench?$"

Text_CraftingSelectCategory:
	.string "Select a crafting category.$"

Text_UpgradeSelectSource:
	.string "Would you like to upgrade a Pokémon's\n"
	.string "ball, or an empty ball from your Bag?$"

Text_UpgradeSelectBagBall:
	.string "Select which Protoball in your Bag\n"
	.string "to upgrade.$"

Text_ConfirmUpgradeMon:
	.string "Upgrade {STR_VAR_1}'s ball using\n"
	.string "1 {STR_VAR_2}?$"

Text_UpgradeSuccessMon:
	.string "Upgraded {STR_VAR_1}'s ball into a\n"
	.string "{STR_VAR_2}!$"

Text_UpgradeSuccessBag:
	.string "Upgraded the ball into a {STR_VAR_2}!$"

Text_UpgradeNeedApricorn:
	.string "You need 1 {STR_VAR_2} to upgrade\n"
	.string "that ball.$"

Text_UpgradeNotEligible:
	.string "That ball can't be upgraded any\n"
	.string "further, or isn't a Protoball.$"

Text_CraftingSelectMedicine:
	.string "Select which medicine to craft.$"

Text_ChooseQuantity:
	.string "How many would you like to craft?\n(Max: {STR_VAR_1})$"

Text_CraftSuccess:
	.string "Crafted {STR_VAR_2} {STR_VAR_3}!$"

Text_NoBrewingKits:
	.string "You don't have any Brewing Kits.\nThey can be bought at Poke Marts.$"

Text_NoMedicineIngredients:
	.string "You don't have the materials!\n"
	.string "You need 1 {STR_VAR_2} and\n"
	.string "1 Brewing Kit.$"

Text_NotEnoughIngredients:
	.string "You don't have enough materials for\n"
	.string "that quantity!$"

Text_WorkbenchClosed:
	.string "Closed the Workbench.$"
