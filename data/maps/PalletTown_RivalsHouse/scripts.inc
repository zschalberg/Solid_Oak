.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap::
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_TestNPC::
	lock
	faceplayer
	goto_if_set FLAG_VARIABLE_PREVIEW_MODE, PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingVariable
	goto_if_unset FLAG_PREVIEW_BATTLE, PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingOff

	copyvar VAR_0x8004, 0x8008
	goto_if_eq VAR_0x8004, 0, PalletTown_RivalsHouse_EventScript_TestNPC_SetPlayerCountDefault3
	buffernumberstring 0, VAR_0x8004
	goto PalletTown_RivalsHouse_EventScript_TestNPC_CheckOpponentCount

PalletTown_RivalsHouse_EventScript_TestNPC_SetPlayerCountDefault3::
	buffernumberstring 0, 3
	goto PalletTown_RivalsHouse_EventScript_TestNPC_CheckOpponentCount

PalletTown_RivalsHouse_EventScript_TestNPC_CheckOpponentCount::
	copyvar VAR_0x8004, 0x800A
	goto_if_eq VAR_0x8004, 0, PalletTown_RivalsHouse_EventScript_TestNPC_SetOpponentCountDefaultMirror
	buffernumberstring 1, VAR_0x8004
	goto PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingOn

PalletTown_RivalsHouse_EventScript_TestNPC_SetOpponentCountDefaultMirror::
	copyvar VAR_0x8004, 0x8008
	goto_if_eq VAR_0x8004, 0, PalletTown_RivalsHouse_EventScript_TestNPC_SetOpponentDefault3
	buffernumberstring 1, VAR_0x8004
	goto PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingOn

PalletTown_RivalsHouse_EventScript_TestNPC_SetOpponentDefault3::
	buffernumberstring 1, 3
	goto PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingOn

PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingOn::
	msgbox PalletTown_RivalsHouse_Text_TestNPC_Greeting_FlagOn
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingOff::
	msgbox PalletTown_RivalsHouse_Text_TestNPC_Greeting_FlagOff
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_ShowGreetingVariable::
	msgbox PalletTown_RivalsHouse_Text_TestNPC_Greeting_FlagVariable
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Menu::
	multichoice 0, 0, MULTI_TEST_NPC_CHOICES, TRUE
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_TestNPC_SelectMode
	case 1, PalletTown_RivalsHouse_EventScript_TestNPC_GetMons
	case 2, PalletTown_RivalsHouse_EventScript_TestNPC_Battle
	case 3, PalletTown_RivalsHouse_EventScript_TestNPC_SetVariable
	case 4, PalletTown_RivalsHouse_EventScript_TestNPC_Exit
	case MULTI_B_PRESSED, PalletTown_RivalsHouse_EventScript_TestNPC_Exit
	end

PalletTown_RivalsHouse_EventScript_TestNPC_SelectMode::
	multichoice 0, 0, MULTI_TEST_NPC_PREVIEW_MODES, TRUE
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_TestNPC_Set1v1
	case 1, PalletTown_RivalsHouse_EventScript_TestNPC_Set2v2
	case 2, PalletTown_RivalsHouse_EventScript_TestNPC_Set3v3
	case 3, PalletTown_RivalsHouse_EventScript_TestNPC_Set4v4
	case 4, PalletTown_RivalsHouse_EventScript_TestNPC_Set5v5
	case 5, PalletTown_RivalsHouse_EventScript_TestNPC_Set6v6
	case 6, PalletTown_RivalsHouse_EventScript_TestNPC_Set2v4
	case 7, PalletTown_RivalsHouse_EventScript_TestNPC_SetDisable
	case MULTI_B_PRESSED, PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Set1v1::
	setflag FLAG_PREVIEW_BATTLE
	setvar 0x8008, 1
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetMode1v1
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Set2v2::
	setflag FLAG_PREVIEW_BATTLE
	setvar 0x8008, 2
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetMode2v2
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Set3v3::
	setflag FLAG_PREVIEW_BATTLE
	setvar 0x8008, 3
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetMode3v3
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Set4v4::
	setflag FLAG_PREVIEW_BATTLE
	setvar 0x8008, 4
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetMode4v4
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Set5v5::
	setflag FLAG_PREVIEW_BATTLE
	setvar 0x8008, 5
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetMode5v5
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Set6v6::
	setflag FLAG_PREVIEW_BATTLE
	setvar 0x8008, 6
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetMode6v6
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Set2v4::
	setflag FLAG_PREVIEW_BATTLE
	setvar 0x8008, 2
	setvar 0x800A, 4
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetMode2v4
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_SetVariable::
	setflag FLAG_VARIABLE_PREVIEW_MODE
	setvar 0x8008, 0
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_SetModeVariable
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_SetDisable::
	clearflag FLAG_PREVIEW_BATTLE
	clearflag FLAG_VARIABLE_PREVIEW_MODE
	setvar 0x8008, 0
	setvar 0x800A, 0
	msgbox PalletTown_RivalsHouse_Text_TestNPC_Disabled
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_GetMons::
	msgbox PalletTown_RivalsHouse_Text_TestNPC_GiveMons
	givemon SPECIES_CHARIZARD, 50
	givemon SPECIES_BLASTOISE, 50
	givemon SPECIES_VENUSAUR, 50
	special HealPlayerParty
	msgbox PalletTown_RivalsHouse_Text_TestNPC_MonsGiven
	goto PalletTown_RivalsHouse_EventScript_TestNPC_Menu
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Battle::
	msgbox PalletTown_RivalsHouse_Text_TestNPC_BattleIntro
	trainerbattle_no_intro TRAINER_TESTER_3V3, PalletTown_RivalsHouse_Text_TestNPC_Defeat
	msgbox PalletTown_RivalsHouse_Text_TestNPC_PostBattle
	release
	end

PalletTown_RivalsHouse_EventScript_TestNPC_Exit::
	msgbox PalletTown_RivalsHouse_Text_TestNPC_Goodbye
	release
	end

EventScript_Abort3v3Battle::
	goto_if_set FLAG_MONOTYPE_BATTLE, EventScript_AbortMonotype3v3Battle
	fadedefaultbgm
	msgbox PalletTown_RivalsHouse_Text_NotEnoughMonsFor3v3, MSGBOX_DEFAULT
	releaseall
	end

EventScript_AbortMonotype3v3Battle::
	fadedefaultbgm
	msgbox PalletTown_RivalsHouse_Text_NotEnoughMonsForMonotype3v3, MSGBOX_DEFAULT
	releaseall
	end

EventScript_AbortMonotypeBattle::
	fadedefaultbgm
	msgbox PalletTown_RivalsHouse_Text_NotEnoughMonsForMonotypeBattle, MSGBOX_DEFAULT
	releaseall
	end


PalletTown_RivalsHouse_EventScript_MonotypeNPC::
	lock
	faceplayer
	goto_if_set FLAG_MONOTYPE_BATTLE, PalletTown_RivalsHouse_EventScript_MonotypeNPC_On
	msgbox PalletTown_RivalsHouse_Text_MonotypeNPC_Greeting_Off, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_RivalsHouse_EventScript_MonotypeNPC_TurnOn
	release
	end

PalletTown_RivalsHouse_EventScript_MonotypeNPC_TurnOn::
	setflag FLAG_MONOTYPE_BATTLE
	setvar VAR_MONOTYPE_RESTRICTION, TYPE_FIRE
	msgbox PalletTown_RivalsHouse_Text_MonotypeNPC_ToggledOn
	release
	end

PalletTown_RivalsHouse_EventScript_MonotypeNPC_On::
	msgbox PalletTown_RivalsHouse_Text_MonotypeNPC_Greeting_On, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PalletTown_RivalsHouse_EventScript_MonotypeNPC_TurnOff
	release
	end

PalletTown_RivalsHouse_EventScript_MonotypeNPC_TurnOff::
	clearflag FLAG_MONOTYPE_BATTLE
	setvar VAR_MONOTYPE_RESTRICTION, TYPE_NONE
	msgbox PalletTown_RivalsHouse_Text_MonotypeNPC_ToggledOff
	release
	end

PalletTown_RivalsHouse_Text_NotEnoughMonsForMonotype3v3::
	.string "You need at least {STR_VAR_2} usable\n"
	.string "{STR_VAR_1}-type Pokémon to battle!$"

PalletTown_RivalsHouse_Text_NotEnoughMonsForMonotypeBattle::
	.string "You have POKéMON that are not\n"
	.string "allowed in this battle!\p"
	.string "This battle is restricted to\n"
	.string "{STR_VAR_1}-type POKéMON.$"

PalletTown_RivalsHouse_Text_MonotypeNPC_Greeting_Off::
	.string "Hi! I can set up a FIRE-type\n"
	.string "monotype battle restriction.\p"
	.string "Would you like to turn it ON?$"

PalletTown_RivalsHouse_Text_MonotypeNPC_Greeting_On::
	.string "The FIRE-type monotype battle\n"
	.string "restriction is currently ON.\p"
	.string "Would you like to turn it OFF?$"

PalletTown_RivalsHouse_Text_MonotypeNPC_ToggledOn::
	.string "Toggled the FIRE-type monotype\n"
	.string "battle restriction to ON.$"

PalletTown_RivalsHouse_Text_MonotypeNPC_ToggledOff::
	.string "Toggled the monotype restriction to OFF.$"

PalletTown_RivalsHouse_Text_NotEnoughMonsFor3v3::
	.string "You need at least {STR_VAR_1} usable Pokémon\n"
	.string "to battle!$"

PalletTown_RivalsHouse_Text_TestNPC_Greeting_FlagOff::
	.string "Hi! I am the preview tester.\n"
	.string "Currently, the preview flag is OFF.\p"
	.string "What would you like to do?$"

PalletTown_RivalsHouse_Text_TestNPC_Greeting_FlagOn::
	.string "Hi! I am the preview tester.\n"
	.string "Currently, the preview flag is ON\l"
	.string "for a {STR_VAR_1}v{STR_VAR_2} battle.\p"
	.string "What would you like to do?$"

PalletTown_RivalsHouse_Text_TestNPC_Greeting_FlagVariable::
	.string "Hi! I am the preview tester.\n"
	.string "Currently, variable preview mode\l"
	.string "is ON. Every battle will match\l"
	.string "the opponent's party size.\p"
	.string "What would you like to do?$"

PalletTown_RivalsHouse_Text_TestNPC_SetMode1v1::
	.string "Set preview to 1v1 mode.$"

PalletTown_RivalsHouse_Text_TestNPC_SetMode2v2::
	.string "Set preview to 2v2 mode.$"

PalletTown_RivalsHouse_Text_TestNPC_SetMode3v3::
	.string "Set preview to 3v3 mode.$"

PalletTown_RivalsHouse_Text_TestNPC_SetMode4v4::
	.string "Set preview to 4v4 mode.$"

PalletTown_RivalsHouse_Text_TestNPC_SetMode5v5::
	.string "Set preview to 5v5 mode.$"

PalletTown_RivalsHouse_Text_TestNPC_SetMode6v6::
	.string "Set preview to 6v6 mode.$"

PalletTown_RivalsHouse_Text_TestNPC_SetMode2v4::
	.string "Set preview to 2v4 mode.\n"
	.string "You pick 2, opponent uses 4.$"

PalletTown_RivalsHouse_Text_TestNPC_SetModeVariable::
	.string "Set variable preview mode ON.\n"
	.string "Every battle will now match the\l"
	.string "opponent's party size until you\l"
	.string "disable it.$"

PalletTown_RivalsHouse_Text_TestNPC_Disabled::
	.string "Disabled the team preview.$"

PalletTown_RivalsHouse_Text_TestNPC_GiveMons::
	.string "Here, take these starter Pokémon\n"
	.string "to fill out your party!$"

PalletTown_RivalsHouse_Text_TestNPC_MonsGiven::
	.string "Added Charizard, Blastoise, and\n"
	.string "Venusaur. Your party is healed!$"

PalletTown_RivalsHouse_Text_TestNPC_BattleIntro::
	.string "Let's battle!$"

PalletTown_RivalsHouse_Text_TestNPC_Defeat::
	.string "Good game!$"

PalletTown_RivalsHouse_Text_TestNPC_PostBattle::
	.string "Hope that helped you test!$"

PalletTown_RivalsHouse_Text_TestNPC_Goodbye::
	.string "Come back anytime!$"
