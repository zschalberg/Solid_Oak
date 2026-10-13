# 3 "data/maps/VermilionCity/scripts.pory"
VermilionCity_MapScripts::
# 4 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
# 5 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
# 6 "data/maps/VermilionCity/scripts.pory"
	.byte 0
# 7 "data/maps/VermilionCity/scripts.pory"

# 8 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnFrame::
# 9 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
# 10 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_ACT1_VERMILLION, 0, VermilionCity_EventScript_ArborDockScene
# 11 "data/maps/VermilionCity/scripts.pory"
	.2byte 0
# 12 "data/maps/VermilionCity/scripts.pory"

# 13 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 14 "data/maps/VermilionCity/scripts.pory"
	lockall
# 15 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 16 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 17 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 18 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 19 "data/maps/VermilionCity/scripts.pory"
	end
# 20 "data/maps/VermilionCity/scripts.pory"

# 21 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne::
# 22 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 23 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 24 "data/maps/VermilionCity/scripts.pory"
	step_end
# 25 "data/maps/VermilionCity/scripts.pory"

# 26 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 27 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 28 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 29 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_AGATHA
# 30 "data/maps/VermilionCity/scripts.pory"
	end
# 31 "data/maps/VermilionCity/scripts.pory"

# 32 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 33 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 34 "data/maps/VermilionCity/scripts.pory"
	return
# 35 "data/maps/VermilionCity/scripts.pory"

# 36 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 37 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WomanApricorns, MSGBOX_NPC
# 38 "data/maps/VermilionCity/scripts.pory"
	end
# 39 "data/maps/VermilionCity/scripts.pory"

# 40 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 41 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OldMan1Saffron, MSGBOX_NPC
# 42 "data/maps/VermilionCity/scripts.pory"
	end
# 43 "data/maps/VermilionCity/scripts.pory"

# 44 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 45 "data/maps/VermilionCity/scripts.pory"
	lock
# 46 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 47 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 48 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 49 "data/maps/VermilionCity/scripts.pory"
	release
# 50 "data/maps/VermilionCity/scripts.pory"
	end
# 51 "data/maps/VermilionCity/scripts.pory"

# 52 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 53 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 54 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 55 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 56 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 57 "data/maps/VermilionCity/scripts.pory"
	end
# 58 "data/maps/VermilionCity/scripts.pory"

# 59 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 60 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 61 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 62 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 63 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 64 "data/maps/VermilionCity/scripts.pory"
	end
# 65 "data/maps/VermilionCity/scripts.pory"

# 66 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 67 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 68 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 69 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 70 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 71 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 72 "data/maps/VermilionCity/scripts.pory"
	release
# 73 "data/maps/VermilionCity/scripts.pory"
	end
# 74 "data/maps/VermilionCity/scripts.pory"

# 75 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseFrontierUnlocked::
# 76 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 77 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 78 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 79 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 80 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_SeviiIslands, 0
# 81 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BattleFrontier, 1
# 82 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 83 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddMysticTicket
# 84 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 85 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddAuroraTicket
# 86 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_Cancel, 4
# 87 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, NULL
# 88 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 90 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBattleFrontier
# 91 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToNavelRock
# 92 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_SailToBirthIsland
# 93 "data/maps/VermilionCity/scripts.pory"
	case 4, EventScript_CancelSail
# 94 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 95 "data/maps/VermilionCity/scripts.pory"
	end
# 96 "data/maps/VermilionCity/scripts.pory"

# 97 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddMysticTicket::
# 98 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_NavelRock, 2
# 99 "data/maps/VermilionCity/scripts.pory"
	return
# 100 "data/maps/VermilionCity/scripts.pory"

# 101 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddAuroraTicket::
# 102 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BirthIsland, 3
# 103 "data/maps/VermilionCity/scripts.pory"
	return
# 104 "data/maps/VermilionCity/scripts.pory"

# 105 "data/maps/VermilionCity/scripts.pory"
Seagallop_SeviiIslands::
# 106 "data/maps/VermilionCity/scripts.pory"
	.string "SEVII ISLANDS$"
# 107 "data/maps/VermilionCity/scripts.pory"

# 108 "data/maps/VermilionCity/scripts.pory"
Seagallop_NavelRock::
# 109 "data/maps/VermilionCity/scripts.pory"
	.string "NAVEL ROCK$"
# 110 "data/maps/VermilionCity/scripts.pory"

# 111 "data/maps/VermilionCity/scripts.pory"
Seagallop_BirthIsland::
# 112 "data/maps/VermilionCity/scripts.pory"
	.string "BIRTH ISLAND$"
# 113 "data/maps/VermilionCity/scripts.pory"

# 114 "data/maps/VermilionCity/scripts.pory"
Seagallop_BattleFrontier::
# 115 "data/maps/VermilionCity/scripts.pory"
	.string "BATTLE FRONTIER$"
# 116 "data/maps/VermilionCity/scripts.pory"

# 117 "data/maps/VermilionCity/scripts.pory"
Seagallop_Cancel::
# 118 "data/maps/VermilionCity/scripts.pory"
	.string "CANCEL$"
# 119 "data/maps/VermilionCity/scripts.pory"

# 120 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 121 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 122 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 123 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 124 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 125 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 126 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 127 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 128 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 129 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 130 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 131 "data/maps/VermilionCity/scripts.pory"
	end
# 132 "data/maps/VermilionCity/scripts.pory"

# 133 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 134 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 135 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 136 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 137 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 138 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 139 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
# 140 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 141 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 142 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 143 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 144 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 145 "data/maps/VermilionCity/scripts.pory"
	end
# 146 "data/maps/VermilionCity/scripts.pory"

# 147 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 148 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 149 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 150 "data/maps/VermilionCity/scripts.pory"
	return
# 151 "data/maps/VermilionCity/scripts.pory"

# 152 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 153 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 154 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 155 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 156 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
# 157 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 158 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 159 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 160 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 161 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 162 "data/maps/VermilionCity/scripts.pory"
	end
# 163 "data/maps/VermilionCity/scripts.pory"

# 164 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 165 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 166 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 167 "data/maps/VermilionCity/scripts.pory"
	return
# 168 "data/maps/VermilionCity/scripts.pory"

# 169 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 170 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 171 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 172 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 173 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 174 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
# 175 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 176 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 177 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 178 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 179 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 180 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 181 "data/maps/VermilionCity/scripts.pory"
	end
# 182 "data/maps/VermilionCity/scripts.pory"

# 183 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 184 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 185 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 186 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 187 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 188 "data/maps/VermilionCity/scripts.pory"
	end
# 189 "data/maps/VermilionCity/scripts.pory"

# 190 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 191 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 192 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 193 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 194 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 195 "data/maps/VermilionCity/scripts.pory"
	end
# 196 "data/maps/VermilionCity/scripts.pory"

# 197 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBattleFrontier::
# 198 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 199 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 200 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BATTLE_FRONTIER
# 201 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 202 "data/maps/VermilionCity/scripts.pory"
	end
# 203 "data/maps/VermilionCity/scripts.pory"

# 204 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 205 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 206 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 207 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 208 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
# 209 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 210 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 211 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 212 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 213 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 214 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 215 "data/maps/VermilionCity/scripts.pory"
	end
# 216 "data/maps/VermilionCity/scripts.pory"

# 217 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 218 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 219 "data/maps/VermilionCity/scripts.pory"
	release
# 220 "data/maps/VermilionCity/scripts.pory"
	end
# 221 "data/maps/VermilionCity/scripts.pory"

# 222 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 223 "data/maps/VermilionCity/scripts.pory"
	lockall
# 224 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 225 "data/maps/VermilionCity/scripts.pory"
	end
# 226 "data/maps/VermilionCity/scripts.pory"

# 227 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 228 "data/maps/VermilionCity/scripts.pory"
	lockall
# 229 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 230 "data/maps/VermilionCity/scripts.pory"
	end
# 231 "data/maps/VermilionCity/scripts.pory"

# 232 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 233 "data/maps/VermilionCity/scripts.pory"
	lockall
# 234 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 235 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 236 "data/maps/VermilionCity/scripts.pory"
	end
# 237 "data/maps/VermilionCity/scripts.pory"

# 238 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 239 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 240 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 241 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 242 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 243 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 244 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 245 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 246 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 247 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 248 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 249 "data/maps/VermilionCity/scripts.pory"
	end
# 250 "data/maps/VermilionCity/scripts.pory"

# 251 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 252 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 253 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 254 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 255 "data/maps/VermilionCity/scripts.pory"
	end
# 256 "data/maps/VermilionCity/scripts.pory"

# 257 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 258 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 259 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 260 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 261 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 262 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 263 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 264 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 265 "data/maps/VermilionCity/scripts.pory"
	end
# 266 "data/maps/VermilionCity/scripts.pory"

# 267 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 268 "data/maps/VermilionCity/scripts.pory"
	lock
# 269 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 270 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DojoTrainer1
# 271 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 272 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DojoTrainer2
# 273 "data/maps/VermilionCity/scripts.pory"
	release
# 274 "data/maps/VermilionCity/scripts.pory"
	end
# 275 "data/maps/VermilionCity/scripts.pory"

# 276 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 277 "data/maps/VermilionCity/scripts.pory"
	lock
# 278 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 279 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 280 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 281 "data/maps/VermilionCity/scripts.pory"
	release
# 282 "data/maps/VermilionCity/scripts.pory"
	end
# 283 "data/maps/VermilionCity/scripts.pory"

# 284 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 285 "data/maps/VermilionCity/scripts.pory"
	lock
# 286 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 287 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_OldMan2Seller1
# 288 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 289 "data/maps/VermilionCity/scripts.pory"
	pokemart SHOP_ID_VERMILION_CITY_MART
# 290 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OldMan2Seller2
# 291 "data/maps/VermilionCity/scripts.pory"
	release
# 292 "data/maps/VermilionCity/scripts.pory"
	end
# 293 "data/maps/VermilionCity/scripts.pory"

# 294 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 295 "data/maps/VermilionCity/scripts.pory"
	lock
# 296 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 297 "data/maps/VermilionCity/scripts.pory"
	waitse
# 298 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 299 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 300 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 301 "data/maps/VermilionCity/scripts.pory"
	release
# 302 "data/maps/VermilionCity/scripts.pory"
	end
# 303 "data/maps/VermilionCity/scripts.pory"

# 304 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 305 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 306 "data/maps/VermilionCity/scripts.pory"
	end
# 307 "data/maps/VermilionCity/scripts.pory"

# 308 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 309 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 310 "data/maps/VermilionCity/scripts.pory"
	end
# 311 "data/maps/VermilionCity/scripts.pory"

# 312 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 313 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 314 "data/maps/VermilionCity/scripts.pory"
	end
# 315 "data/maps/VermilionCity/scripts.pory"

# 316 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 317 "data/maps/VermilionCity/scripts.pory"
	lockall
# 318 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 319 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 320 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 321 "data/maps/VermilionCity/scripts.pory"
	end
# 322 "data/maps/VermilionCity/scripts.pory"

# 323 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 324 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 325 "data/maps/VermilionCity/scripts.pory"
	end
# 326 "data/maps/VermilionCity/scripts.pory"

# 327 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor::
# 328 "data/maps/VermilionCity/scripts.pory"
	lock
# 329 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 330 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOption
# 331 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 332 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 333 "data/maps/VermilionCity/scripts.pory"

# 334 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_Menu::
# 335 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ToggleDoubleFlag, 0
# 336 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_StandardBattle, 1
# 337 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ScaledBossBattle, 2
# 338 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ScaledWildBoss, 3
# 339 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ToggleWildScaling, 4
# 340 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_Close, 5
# 341 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 342 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 343 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_TesterSailor_ToggleDoubleFlag
# 344 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TesterSailor_StandardBattle
# 345 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_TesterSailor_ScaledBossBattle
# 346 "data/maps/VermilionCity/scripts.pory"
	case 3, VermilionCity_EventScript_TesterSailor_ScaledWildBoss
# 347 "data/maps/VermilionCity/scripts.pory"
	case 4, VermilionCity_EventScript_TesterSailor_ToggleWildScaling
# 348 "data/maps/VermilionCity/scripts.pory"
	case 5, VermilionCity_EventScript_TesterSailor_Close
# 349 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, VermilionCity_EventScript_TesterSailor_Close
# 350 "data/maps/VermilionCity/scripts.pory"
	end
# 351 "data/maps/VermilionCity/scripts.pory"

# 352 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ToggleDoubleFlag::
# 353 "data/maps/VermilionCity/scripts.pory"
	checkflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 354 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_DOUBLE_BATTLE_WITH_ONE_MON, VermilionCity_EventScript_TesterSailor_DisableDoubleFlag
# 355 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 356 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_FlagNowEnabled, MSGBOX_DEFAULT
# 357 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 358 "data/maps/VermilionCity/scripts.pory"

# 359 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_DisableDoubleFlag::
# 360 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 361 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_FlagNowDisabled, MSGBOX_DEFAULT
# 362 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 363 "data/maps/VermilionCity/scripts.pory"

# 364 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ToggleWildScaling::
# 365 "data/maps/VermilionCity/scripts.pory"
	checkflag FLAG_SCALE_WILD_POKEMON
# 366 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_SCALE_WILD_POKEMON, VermilionCity_EventScript_TesterSailor_DisableWildScaling
# 367 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SCALE_WILD_POKEMON
# 368 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_WildScalingNowEnabled, MSGBOX_DEFAULT
# 369 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 370 "data/maps/VermilionCity/scripts.pory"

# 371 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_DisableWildScaling::
# 372 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_SCALE_WILD_POKEMON
# 373 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_WildScalingNowDisabled, MSGBOX_DEFAULT
# 374 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 375 "data/maps/VermilionCity/scripts.pory"

# 376 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_StandardBattle::
# 377 "data/maps/VermilionCity/scripts.pory"
	cleartrainerflag TRAINER_VERMILION_TESTER
# 378 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_double TRAINER_VERMILION_TESTER, VermilionCity_Text_TesterSailorBattleIntro, VermilionCity_Text_TesterSailorBattleDefeat, VermilionCity_Text_TesterSailorNotEnoughMons
# 379 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailorPostBattle, MSGBOX_DEFAULT
# 380 "data/maps/VermilionCity/scripts.pory"
	release
# 381 "data/maps/VermilionCity/scripts.pory"
	end
# 382 "data/maps/VermilionCity/scripts.pory"

# 383 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ScaledBossBattle::
# 384 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOffset
# 385 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 386 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus2, 2
# 387 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus5, 5
# 388 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus10, 10
# 389 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus20, 20
# 390 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus5, -5
# 391 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus10, -10
# 392 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 1, 0, DYN_MULTICHOICE_CB_NONE
# 393 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, VAR_RESULT
# 394 "data/maps/VermilionCity/scripts.pory"
	cleartrainerflag TRAINER_VERMILION_TESTER
# 395 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 396 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_double TRAINER_VERMILION_TESTER, VermilionCity_Text_TesterSailorBattleIntro, VermilionCity_Text_TesterSailorBattleDefeat, VermilionCity_Text_TesterSailorNotEnoughMons
# 397 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 398 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 399 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailorPostBattle, MSGBOX_DEFAULT
# 400 "data/maps/VermilionCity/scripts.pory"
	release
# 401 "data/maps/VermilionCity/scripts.pory"
	end
# 402 "data/maps/VermilionCity/scripts.pory"

# 403 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ScaledWildBoss::
# 404 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOffset
# 405 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 406 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus2, 2
# 407 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus5, 5
# 408 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus10, 10
# 409 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus20, 20
# 410 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus5, -5
# 411 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus10, -10
# 412 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 1, 0, DYN_MULTICHOICE_CB_NONE
# 413 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_TENTACRUEL
# 414 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8005, 20
# 415 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, VAR_RESULT
# 416 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8007, ITEM_NONE
# 417 "data/maps/VermilionCity/scripts.pory"
	callnative Script_SetScaledWildBattle
# 418 "data/maps/VermilionCity/scripts.pory"
	dowildbattle
# 419 "data/maps/VermilionCity/scripts.pory"
	release
# 420 "data/maps/VermilionCity/scripts.pory"
	end
# 421 "data/maps/VermilionCity/scripts.pory"

# 422 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_Close::
# 423 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_NoBattle, MSGBOX_DEFAULT
# 424 "data/maps/VermilionCity/scripts.pory"
	release
# 425 "data/maps/VermilionCity/scripts.pory"
	end
# 426 "data/maps/VermilionCity/scripts.pory"

# 427 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ArborDockScene::
# 428 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, VermilionCity_EventScript_ArborDockScene_NotReady
# 429 "data/maps/VermilionCity/scripts.pory"
	lockall
# 430 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_ACT1_VERMILLION, 1
# 431 "data/maps/VermilionCity/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 432 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 433 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborDock1
# 434 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 435 "data/maps/VermilionCity/scripts.pory"
    faceplayer
# 436 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborDock2
# 437 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 438 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborDock3
# 439 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 440 "data/maps/VermilionCity/scripts.pory"
	clearmugshot
# 441 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_ARBOR
# 442 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_QUEST_MRFUJI_RESEARCH_ACTIVE
# 443 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_QUEST_SILPH_TESTING_ACTIVE
# 444 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCENE_SILPH, 1
# 445 "data/maps/VermilionCity/scripts.pory"
	quest_start_toast
# 446 "data/maps/VermilionCity/scripts.pory"
	quest_start_toast
# 447 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 448 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_ArborDockScene_End
# 449 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ArborDockScene_NotReady::
# 450 "data/maps/VermilionCity/scripts.pory"
	// Bumping the var to 2 stops the on-frame table (VAR_ACT1_VERMILLION, 0)
# 451 "data/maps/VermilionCity/scripts.pory"
	// from re-matching every single frame, which would otherwise starve out
# 452 "data/maps/VermilionCity/scripts.pory"
	// all other field input (see FuchsiaCity's identical fix for why).
# 453 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_ACT1_VERMILLION, 2
# 454 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ArborDockScene_End::
# 455 "data/maps/VermilionCity/scripts.pory"
	end
# 456 "data/maps/VermilionCity/scripts.pory"

# 457 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Arbor::
# 458 "data/maps/VermilionCity/scripts.pory"
	lock
# 459 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 460 "data/maps/VermilionCity/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 461 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 462 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborIdle
# 463 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 464 "data/maps/VermilionCity/scripts.pory"
	clearmugshot
# 465 "data/maps/VermilionCity/scripts.pory"
	release
# 466 "data/maps/VermilionCity/scripts.pory"
	end
# 467 "data/maps/VermilionCity/scripts.pory"

# 468 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PsyduckChild::
# 469 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PsyduckChild, MSGBOX_NPC
# 470 "data/maps/VermilionCity/scripts.pory"
	end
# 471 "data/maps/VermilionCity/scripts.pory"

# 472 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PsyduckNPC::
# 473 "data/maps/VermilionCity/scripts.pory"
	lock
# 474 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 475 "data/maps/VermilionCity/scripts.pory"
	waitse
# 476 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 477 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PsyduckMisc
# 478 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 479 "data/maps/VermilionCity/scripts.pory"
	release
# 480 "data/maps/VermilionCity/scripts.pory"
	end

VermilionCity_EventScript_AgathaTriggerLeft::
# 486 "data/maps/VermilionCity/scripts.pory"
	lockall
# 487 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 488 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_AgathaEncounter
	return


VermilionCity_EventScript_AgathaTriggerMid::
# 492 "data/maps/VermilionCity/scripts.pory"
	lockall
# 493 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 494 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_AgathaEncounter
	return


VermilionCity_EventScript_AgathaTriggerRight::
# 498 "data/maps/VermilionCity/scripts.pory"
	lockall
# 499 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 500 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_AgathaEncounter
	return


VermilionCity_EventScript_AgathaEncounter::
# 504 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, VermilionCity_EventScript_AgathaEncounter_2
# 508 "data/maps/VermilionCity/scripts.pory"
	compare VAR_TEMP_1, 0
	goto_if_eq VermilionCity_EventScript_AgathaEncounter_5
# 510 "data/maps/VermilionCity/scripts.pory"
	compare VAR_TEMP_1, 1
	goto_if_eq VermilionCity_EventScript_AgathaEncounter_6
# 513 "data/maps/VermilionCity/scripts.pory"
	setobjectxy 14, 30, 0
VermilionCity_EventScript_AgathaEncounter_4:
# 515 "data/maps/VermilionCity/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 516 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_HIDE_VERMILION_AGATHA
# 517 "data/maps/VermilionCity/scripts.pory"
	addobject 14
# 518 "data/maps/VermilionCity/scripts.pory"
	applymovement 14, VermilionCity_Movement_AgathaEnter
# 519 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 520 "data/maps/VermilionCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 521 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 522 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_AgathaVermilionIntro
# 523 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 524 "data/maps/VermilionCity/scripts.pory"
	clearmugshot
# 525 "data/maps/VermilionCity/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 526 "data/maps/VermilionCity/scripts.pory"
	compare VAR_STARTER_MON, 0
	goto_if_eq VermilionCity_EventScript_AgathaEncounter_11
# 526 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_0x8D7, VermilionCity_EventScript_AgathaEncounter_11
# 528 "data/maps/VermilionCity/scripts.pory"
	compare VAR_STARTER_MON, 1
	goto_if_eq VermilionCity_EventScript_AgathaEncounter_12
# 528 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_0x8D8, VermilionCity_EventScript_AgathaEncounter_12
# 531 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_no_intro TRAINER_AGATHA_VERMILION_GROWLITHE, VermilionCity_Text_AgathaVermilionDefeat
VermilionCity_EventScript_AgathaEncounter_10:
# 533 "data/maps/VermilionCity/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 534 "data/maps/VermilionCity/scripts.pory"
	special HealPlayerParty
# 535 "data/maps/VermilionCity/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 536 "data/maps/VermilionCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 537 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 538 "data/maps/VermilionCity/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_ne VermilionCity_EventScript_AgathaEncounter_21
VermilionCity_EventScript_AgathaEncounter_20:
# 541 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_AgathaVermilionPostBattle
# 542 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 543 "data/maps/VermilionCity/scripts.pory"
	clearmugshot
# 544 "data/maps/VermilionCity/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 545 "data/maps/VermilionCity/scripts.pory"
	applymovement 14, VermilionCity_Movement_AgathaExit
# 546 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 547 "data/maps/VermilionCity/scripts.pory"
	removeobject 14
# 548 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_AGATHA
# 549 "data/maps/VermilionCity/scripts.pory"
	fadedefaultbgm
# 550 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_AGATHA_STATE, 1
# 551 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_DEFEATED_AGATHA_VERMILION
# 552 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end

VermilionCity_EventScript_AgathaEncounter_2:
# 505 "data/maps/VermilionCity/scripts.pory"
	releaseall
	end

VermilionCity_EventScript_AgathaEncounter_5:
# 509 "data/maps/VermilionCity/scripts.pory"
	setobjectxy 14, 28, 0
	goto VermilionCity_EventScript_AgathaEncounter_4

VermilionCity_EventScript_AgathaEncounter_6:
# 511 "data/maps/VermilionCity/scripts.pory"
	setobjectxy 14, 29, 0
	goto VermilionCity_EventScript_AgathaEncounter_4

VermilionCity_EventScript_AgathaEncounter_11:
# 527 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_no_intro TRAINER_AGATHA_VERMILION_NIDORAN, VermilionCity_Text_AgathaVermilionDefeat
	goto VermilionCity_EventScript_AgathaEncounter_10

VermilionCity_EventScript_AgathaEncounter_12:
# 529 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_no_intro TRAINER_AGATHA_VERMILION_EXEGGCUTE, VermilionCity_Text_AgathaVermilionDefeat
	goto VermilionCity_EventScript_AgathaEncounter_10

VermilionCity_EventScript_AgathaEncounter_21:
# 539 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_AgathaVermilionVictory
	goto VermilionCity_EventScript_AgathaEncounter_20


# 556 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_AgathaEnter:
# 557 "data/maps/VermilionCity/scripts.pory"
	walk_down
# 557 "data/maps/VermilionCity/scripts.pory"
	walk_down
	step_end

# 560 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_AgathaExit:
# 561 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 561 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 561 "data/maps/VermilionCity/scripts.pory"
	walk_up
	step_end

VermilionCity_Text_AgathaVermilionIntro::
# 564 "data/maps/VermilionCity/scripts.pory"
	.string "Sammy! There you are!\p"
	.string "I was waiting for you to finish\n"
	.string "fussing around with the Professor.\p"
	.string "I took this POKéMON just like Arbor\n"
	.string "wanted, but I'm not carrying it\l"
	.string "around as a pet.\p"
	.string "If it's going to travel with me,\n"
	.string "it needs to know how to fight!\p"
	.string "Come on, Sammy!\n"
	.string "Let's see what you've got!$"

VermilionCity_Text_AgathaVermilionDefeat::
# 577 "data/maps/VermilionCity/scripts.pory"
	.string "Hmph! Not bad for your\n"
	.string "first try.$"

VermilionCity_Text_AgathaVermilionVictory::
# 582 "data/maps/VermilionCity/scripts.pory"
	.string "Ha! Looks like my POKéMON has\n"
	.string "more spirit than yours, Sammy!$"

VermilionCity_Text_AgathaVermilionPostBattle::
# 587 "data/maps/VermilionCity/scripts.pory"
	.string "You're not half bad, Sammy.\p"
	.string "Though you still have plenty\n"
	.string "to learn if you want to keep\l"
	.string "up with me.\p"
	.string "I'm heading north to Saffron.\n"
	.string "Word is, there are stronger\l"
	.string "trainers up that way.\p"
	.string "Don't fall behind, Sammy!\n"
	.string "See you in Saffron!$"
