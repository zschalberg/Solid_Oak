PalletTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_PlayersHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_PlayersHouse_2F_OnWarp
	.byte 0

PalletTown_PlayersHouse_2F_OnTransition::
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_EventScript_SetRespawn
	end

PalletTown_PlayersHouse_2F_EventScript_SetRespawn::
	setrespawn HEAL_LOCATION_PALLET_TOWN
	return

PalletTown_PlayersHouse_2F_OnWarp::
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 0, PalletTown_PlayersHouse_2F_FirstWarpIn
	.2byte 0

PalletTown_PlayersHouse_2F_FirstWarpIn::
	turnobject LOCALID_PLAYER, DIR_NORTH
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	end

PalletTown_PlayersHouse_2F_EventScript_NES::
	lockall
	msgbox PalletTown_PlayersHouse_2F_Text_ToggleTestQuests, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_PlayersHouse_2F_EventScript_DoToggleTestQuests
	msgbox PalletTown_PlayersHouse_2F_Text_PlayedWithNES, MSGBOX_SIGN
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_DoToggleTestQuests::
	goto_if_set FLAG_QUEST_MRFUJI_RESEARCH_ACTIVE, PalletTown_PlayersHouse_2F_EventScript_ClearTestQuests
	setflag FLAG_QUEST_MRFUJI_RESEARCH_ACTIVE
	setflag FLAG_QUEST_MRFUJI_RESEARCH_COMPLETED
	setflag FLAG_QUEST_SILPH_TESTING_ACTIVE
	setflag FLAG_QUEST_ATTACK_DOJO_ACTIVE
	setflag FLAG_QUEST_FISHING_VILLAGE_ACTIVE
	setflag FLAG_QUEST_FISHING_VILLAGE_COMPLETED
	setflag FLAG_QUEST_REDPROTOBALL_ACTIVE
	setflag FLAG_QUEST_7_ACTIVE
	msgbox PalletTown_PlayersHouse_2F_Text_TestQuestsActivated, MSGBOX_DEFAULT
	releaseall
	end

PalletTown_PlayersHouse_2F_EventScript_ClearTestQuests::
	clearflag FLAG_QUEST_MRFUJI_RESEARCH_ACTIVE
	clearflag FLAG_QUEST_MRFUJI_RESEARCH_COMPLETED
	clearflag FLAG_QUEST_SILPH_TESTING_ACTIVE
	clearflag FLAG_QUEST_SILPH_TESTING_COMPLETED
	clearflag FLAG_QUEST_ATTACK_DOJO_ACTIVE
	clearflag FLAG_QUEST_ATTACK_DOJO_COMPLETED
	clearflag FLAG_QUEST_FISHING_VILLAGE_ACTIVE
	clearflag FLAG_QUEST_FISHING_VILLAGE_COMPLETED
	clearflag FLAG_QUEST_5_ACTIVE
	clearflag FLAG_QUEST_5_COMPLETED
	clearflag FLAG_QUEST_REDPROTOBALL_ACTIVE
	clearflag FLAG_QUEST_REDPROTOBALL_COMPLETED
	clearflag FLAG_QUEST_7_ACTIVE
	clearflag FLAG_QUEST_7_COMPLETED
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
