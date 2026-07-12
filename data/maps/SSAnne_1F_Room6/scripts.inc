SSAnne_1F_Room6_MapScripts::
	.byte 0

SSAnne_1F_Room6_EventScript_Woman::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_TakeAShortRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_DeclineHeal
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox SSAnne_1F_Room6_Text_GladEveryoneIsRefreshed
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHeal::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, SSAnne_1F_Room6_EventScript_DeclineHealMale
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMySister
	release
	end

SSAnne_1F_Room6_EventScript_DeclineHealMale::
	msgbox SSAnne_1F_Room6_Text_SorryYouLookLikeMyBrother
	release
	end

SSAnne_1F_Room6_EventScript_Growlithe::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose
	showmonpic SPECIES_GROWLITHE, 10, 3
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room6_Text_ChooseGrowlithe, MSGBOX_YESNO
	waitmoncry
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseGrowlithe
	hidemonpic
	release
	end

SSAnne_1F_Room6_EventScript_GrowlitheAlreadyChose::
	playmoncry SPECIES_GROWLITHE, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room6_Text_GrowlitheFriendly
	waitmoncry
	release
	end

SSAnne_1F_Room6_EventScript_ChooseGrowlithe::
	hidemonpic
	givemon SPECIES_GROWLITHE, 5
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveGrowlitheParty
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveGrowlithePC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	end

SSAnne_1F_Room6_EventScript_GiveGrowlitheParty::
	setflag FLAG_0x8D7
	removeobject 2
	playfanfare MUS_LEVEL_UP
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
	end

SSAnne_1F_Room6_EventScript_GiveGrowlithePC::
	setflag FLAG_0x8D7
	removeobject 2
	playfanfare MUS_LEVEL_UP
	message SSAnne_1F_Room6_Text_ObtainedGrowlithe
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GROWLITHE
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
	call EventScript_NameReceivedBoxMon
	goto SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC
	end

SSAnne_1F_Room6_EventScript_GrowlitheTransferredToPC::
	call EventScript_TransferredToPC
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
	end

SSAnne_1F_Room6_EventScript_NidoranM::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose
	showmonpic SPECIES_NIDORAN_M, 10, 3
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room6_Text_ChooseNidoranM, MSGBOX_YESNO
	waitmoncry
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseNidoranM
	hidemonpic
	release
	end

SSAnne_1F_Room6_EventScript_NidoranMAlreadyChose::
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room6_Text_NidoranMFriendly
	waitmoncry
	release
	end

SSAnne_1F_Room6_EventScript_ChooseNidoranM::
	hidemonpic
	givemon SPECIES_NIDORAN_M, 5
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveNidoranMParty
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveNidoranMPC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	end

SSAnne_1F_Room6_EventScript_GiveNidoranMParty::
	setflag FLAG_0x8D8
	removeobject 3
	playfanfare MUS_LEVEL_UP
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
	end

SSAnne_1F_Room6_EventScript_GiveNidoranMPC::
	setflag FLAG_0x8D8
	removeobject 3
	playfanfare MUS_LEVEL_UP
	message SSAnne_1F_Room6_Text_ObtainedNidoranM
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_NIDORAN_M
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
	call EventScript_NameReceivedBoxMon
	goto SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC
	end

SSAnne_1F_Room6_EventScript_NidoranMTransferredToPC::
	call EventScript_TransferredToPC
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
	end

SSAnne_1F_Room6_EventScript_Exeggcute::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEMON_GET, SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose
	showmonpic SPECIES_EXEGGCUTE, 10, 3
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room6_Text_ChooseExeggcute, MSGBOX_YESNO
	waitmoncry
	goto_if_eq VAR_RESULT, YES, SSAnne_1F_Room6_EventScript_ChooseExeggcute
	hidemonpic
	release
	end

SSAnne_1F_Room6_EventScript_ExeggcuteAlreadyChose::
	playmoncry SPECIES_EXEGGCUTE, CRY_MODE_NORMAL
	msgbox SSAnne_1F_Room6_Text_ExeggcuteFriendly
	waitmoncry
	release
	end

SSAnne_1F_Room6_EventScript_ChooseExeggcute::
	hidemonpic
	givemon SPECIES_EXEGGCUTE, 5
	goto_if_eq VAR_RESULT, 0, SSAnne_1F_Room6_EventScript_GiveExeggcuteParty
	goto_if_eq VAR_RESULT, 1, SSAnne_1F_Room6_EventScript_GiveExeggcutePC
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
	end

SSAnne_1F_Room6_EventScript_GiveExeggcuteParty::
	setflag FLAG_0x8D9
	removeobject 4
	playfanfare MUS_LEVEL_UP
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_FinishStarterSelection
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
	end

SSAnne_1F_Room6_EventScript_GiveExeggcutePC::
	setflag FLAG_0x8D9
	removeobject 4
	playfanfare MUS_LEVEL_UP
	message SSAnne_1F_Room6_Text_ObtainedExeggcute
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EXEGGCUTE
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
	call EventScript_NameReceivedBoxMon
	goto SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC
	end

SSAnne_1F_Room6_EventScript_ExeggcuteTransferredToPC::
	call EventScript_TransferredToPC
	goto SSAnne_1F_Room6_EventScript_FinishStarterSelection
	end

SSAnne_1F_Room6_EventScript_FinishStarterSelection::
	setflag FLAG_SYS_POKEMON_GET
	release
	end

SSAnne_1F_Room6_EventScript_TestBalls::
	lock
	faceplayer
	giveitem ITEM_POKE_BALL, 5
	giveitem ITEM_LEVEL_BALL, 5
	giveitem ITEM_LURE_BALL, 5
	giveitem ITEM_FRIEND_BALL, 5
	giveitem ITEM_HEAVY_BALL, 5
	giveitem ITEM_CHERISH_BALL, 5
	giveitem ITEM_WORKBENCH, 1
	giveitem ITEM_CONVERSION_KIT, 20
	giveitem ITEM_RED_APRICORN, 10
	giveitem ITEM_BLUE_APRICORN, 10
	giveitem ITEM_GREEN_APRICORN, 10
	giveitem ITEM_BLACK_APRICORN, 10
	setflag FLAG_TEMP_2
	removeobject 5
	release
	end

SSAnne_1F_Room6_EventScript_CraftingNPC::
	lock
	faceplayer
	msgbox SSAnne_1F_Room6_Text_ScientistIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SSAnne_1F_Room6_EventScript_CraftingDecline
	goto EventScript_CraftingLoop
	end

SSAnne_1F_Room6_EventScript_CraftingDecline::
	msgbox SSAnne_1F_Room6_Text_ScientistDecline
	release
	end

