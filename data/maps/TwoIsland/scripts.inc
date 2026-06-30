TwoIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_OnTransition
	.byte 0

TwoIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_0x2A2
	call TwoIsland_EventScript_SetShopState
	end

TwoIsland_EventScript_SetShopState::
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, TwoIsland_EventScript_SetShopStateAfterHoennLink
	goto_if_set FLAG_SYS_GAME_CLEAR, TwoIsland_EventScript_SetShopStateAfterChampion
	goto_if_set FLAG_0x2A3, TwoIsland_EventScript_SetShopStateAfterLostelleRescue
	goto TwoIsland_EventScript_SetShopStateDefault
	end

TwoIsland_EventScript_SetShopStateAfterHoennLink::
	goto_if_unset FLAG_0x29D, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_0x29E, TwoIsland_EventScript_SetShopExpanded1
	goto_if_unset FLAG_0x29F, TwoIsland_EventScript_SetShopExpanded2
	goto TwoIsland_EventScript_SetShopExpanded3
	end

TwoIsland_EventScript_SetShopStateAfterChampion::
	goto_if_unset FLAG_0x29D, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_0x2A3, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_0x29E, TwoIsland_EventScript_SetShopExpanded1
	goto TwoIsland_EventScript_SetShopExpanded2
	end

TwoIsland_EventScript_SetShopStateAfterLostelleRescue::
	goto_if_unset FLAG_0x29D, TwoIsland_EventScript_SetShopInitial
	goto TwoIsland_EventScript_SetShopExpanded1
	end

TwoIsland_EventScript_SetShopStateDefault::
	goto TwoIsland_EventScript_SetShopInitial
	end

TwoIsland_EventScript_SetShopInitial::
	setvar VAR_0x4078, 1
	return

TwoIsland_EventScript_SetShopExpanded1::
	setvar VAR_0x4078, 2
	clearflag FLAG_0x07B
	return

TwoIsland_EventScript_SetShopExpanded2::
	setvar VAR_0x4078, 3
	clearflag FLAG_0x07C
	return

TwoIsland_EventScript_SetShopExpanded3::
	setvar VAR_0x4078, 4
	clearflag FLAG_0x07D
	return

TwoIsland_EventScript_Clerk::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	goto_if_eq VAR_0x4078, 4, TwoIsland_EventScript_ClerkShopExpanded3
	goto_if_eq VAR_0x4078, 3, TwoIsland_EventScript_ClerkShopExpanded2
	goto_if_eq VAR_0x4078, 2, TwoIsland_EventScript_ClerkShopExpanded1
	goto TwoIsland_EventScript_ClerkShopInitial
	end

TwoIsland_EventScript_ClerkShopExpanded3::
	goto_if_set FLAG_0x2A0, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_0x2A0
	message TwoIsland_Text_BringingItemsFromDistantLands
	waitmessage
	goto TwoIsland_EventScript_ShowShop
	end

TwoIsland_EventScript_ClerkShopExpanded2::
	goto_if_set FLAG_0x29F, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_0x29F
	message TwoIsland_Text_HopeYouGiveItYourBest
	waitmessage
	goto TwoIsland_EventScript_ShowShop
	end

TwoIsland_EventScript_ClerkShopExpanded1::
	goto_if_set FLAG_0x29E, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_0x29E
	message TwoIsland_Text_AddedMerchandiseForLostelle
	waitmessage
	goto TwoIsland_EventScript_ShowShop
	end

TwoIsland_EventScript_ClerkShopInitial::
	goto_if_set FLAG_0x29D, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_0x29D
	message TwoIsland_Text_WelcomeToShopMerchandiseLimited
	waitmessage
	goto TwoIsland_EventScript_ShowShop
	end

TwoIsland_EventScript_ClerkShopSkipIntro::
	message Text_MayIHelpYou
	waitmessage
TwoIsland_EventScript_ShowShop::
	pokemart SHOP_ID_TWO_ISLAND_SHOP
	msgbox Text_PleaseComeAgain
	release
	end

TwoIsland_EventScript_Sailor::
	msgbox TwoIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
	end

TwoIsland_EventScript_Woman::
	msgbox TwoIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
	end

TwoIsland_EventScript_Beauty::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 4
	msgbox TwoIsland_Text_BrunoCameToIslandWhileBack
	release
	end

TwoIsland_EventScript_PokeManiac::
	msgbox TwoIsland_Text_BuyRareItemsHere, MSGBOX_NPC
	end

TwoIsland_EventScript_Boy::
	msgbox TwoIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_EventScript_LittleBoy::
	msgbox TwoIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
	end

TwoIsland_EventScript_IslandSign::
	msgbox TwoIsland_Text_IslandSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_JoyfulGameCornerSign::
	msgbox TwoIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_FastCurrentSign::
	msgbox TwoIsland_Text_DangerFastCurrent, MSGBOX_SIGN
	end
