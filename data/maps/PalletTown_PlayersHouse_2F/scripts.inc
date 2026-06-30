PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_0x4056, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_0x4056, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_0x4056, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	lockall
	msgbox PalletTown_PlayersHouse_2F_Text_ToggleTestQuests, MSGBOX_YESNO
	compare VAR_0x800D, YES
	goto_if_eq PalletTown_PlayersHouse_2F_EventScript_DoToggleTestQuests
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_DoToggleTestQuests::
	goto_if_set FLAG_0x4C0, PalletTown_PlayersHouse_2F_EventScript_ClearTestQuests
	setflag FLAG_0x4C0
	setflag FLAG_0x4C1
	setflag FLAG_0x4C2
	setflag FLAG_0x4C4
	setflag FLAG_0x4C6
	setflag FLAG_0x4C7
	setflag FLAG_0x4CA
	setflag FLAG_0x4CC
	msgbox PalletTown_PlayersHouse_2F_Text_TestQuestsActivated, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_ClearTestQuests::
	clearflag FLAG_0x4C0
	clearflag FLAG_0x4C1
	clearflag FLAG_0x4C2
	clearflag FLAG_0x4C3
	clearflag FLAG_0x4C4
	clearflag FLAG_0x4C5
	clearflag FLAG_0x4C6
	clearflag FLAG_0x4C7
	clearflag FLAG_0x4C8
	clearflag FLAG_0x4C9
	clearflag FLAG_0x4CA
	clearflag FLAG_0x4CB
	clearflag FLAG_0x4CC
	clearflag FLAG_0x4CD
	msgbox PalletTown_PlayersHouse_2F_Text_TestQuestsCleared, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_Sign::
	lockall
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
	showmugshot MUGSHOT_PROF_OAK, MUGSHOT_RIGHT
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox PalletTown_PlayersHouse_2F_Text_AgathaTest1, MSGBOX_DEFAULT
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PalletTown_PlayersHouse_2F_Text_OakTest1, MSGBOX_DEFAULT
	releaseall
	end


PalletTown_PlayersHouse_2F_EventScript_PC::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	setvar VAR_0x8004, HELPCONTEXT_BEDROOM_PC
	special Script_SetHelpContext
	setvar VAR_0x8004, 1
	special AnimatePcTurnOn
	playse SE_PC_ON
	msgbox Text_PlayerBootedUpPC
	special BedroomPC
	waitstate
	special SetHelpContextForMap
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_ShutDownPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special AnimatePcTurnOff
	special SetHelpContextForMap
	releaseall
	end

PalletTown_PlayersHouse_2F_Text_ToggleTestQuests::
	.string "Would you like to toggle the Quest\nLog test states?$"

PalletTown_PlayersHouse_2F_Text_TestQuestsActivated::
	.string "Quest Log test states activated!\n"
	.string "Main tab populated. Side tab active.\n"
	.string "Research tab populated with Gengar.$"

PalletTown_PlayersHouse_2F_Text_TestQuestsCleared::
	.string "Quest Log test states cleared!\n"
	.string "All quests are now Locked.$"
