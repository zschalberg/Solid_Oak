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
	end
# 30 "data/maps/VermilionCity/scripts.pory"

# 31 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 32 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 33 "data/maps/VermilionCity/scripts.pory"
	return
# 34 "data/maps/VermilionCity/scripts.pory"

# 35 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 36 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WomanApricorns, MSGBOX_NPC
# 37 "data/maps/VermilionCity/scripts.pory"
	end
# 38 "data/maps/VermilionCity/scripts.pory"

# 39 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 40 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OldMan1Saffron, MSGBOX_NPC
# 41 "data/maps/VermilionCity/scripts.pory"
	end
# 42 "data/maps/VermilionCity/scripts.pory"

# 43 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 44 "data/maps/VermilionCity/scripts.pory"
	lock
# 45 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 46 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 47 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 48 "data/maps/VermilionCity/scripts.pory"
	release
# 49 "data/maps/VermilionCity/scripts.pory"
	end
# 50 "data/maps/VermilionCity/scripts.pory"

# 51 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 52 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 53 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 54 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 55 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 56 "data/maps/VermilionCity/scripts.pory"
	end
# 57 "data/maps/VermilionCity/scripts.pory"

# 58 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 59 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 60 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 61 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 62 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 63 "data/maps/VermilionCity/scripts.pory"
	end
# 64 "data/maps/VermilionCity/scripts.pory"

# 65 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 66 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 67 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 68 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 69 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 70 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 71 "data/maps/VermilionCity/scripts.pory"
	release
# 72 "data/maps/VermilionCity/scripts.pory"
	end
# 73 "data/maps/VermilionCity/scripts.pory"

# 74 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseFrontierUnlocked::
# 75 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 76 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 77 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 78 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 79 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_SeviiIslands, 0
# 80 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BattleFrontier, 1
# 81 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 82 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddMysticTicket
# 83 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 84 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddAuroraTicket
# 85 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_Cancel, 4
# 86 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, NULL
# 87 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 88 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 89 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBattleFrontier
# 90 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToNavelRock
# 91 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_SailToBirthIsland
# 92 "data/maps/VermilionCity/scripts.pory"
	case 4, EventScript_CancelSail
# 93 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 94 "data/maps/VermilionCity/scripts.pory"
	end
# 95 "data/maps/VermilionCity/scripts.pory"

# 96 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddMysticTicket::
# 97 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_NavelRock, 2
# 98 "data/maps/VermilionCity/scripts.pory"
	return
# 99 "data/maps/VermilionCity/scripts.pory"

# 100 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddAuroraTicket::
# 101 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BirthIsland, 3
# 102 "data/maps/VermilionCity/scripts.pory"
	return
# 103 "data/maps/VermilionCity/scripts.pory"

# 104 "data/maps/VermilionCity/scripts.pory"
Seagallop_SeviiIslands::
# 105 "data/maps/VermilionCity/scripts.pory"
	.string "SEVII ISLANDS$"
# 106 "data/maps/VermilionCity/scripts.pory"

# 107 "data/maps/VermilionCity/scripts.pory"
Seagallop_NavelRock::
# 108 "data/maps/VermilionCity/scripts.pory"
	.string "NAVEL ROCK$"
# 109 "data/maps/VermilionCity/scripts.pory"

# 110 "data/maps/VermilionCity/scripts.pory"
Seagallop_BirthIsland::
# 111 "data/maps/VermilionCity/scripts.pory"
	.string "BIRTH ISLAND$"
# 112 "data/maps/VermilionCity/scripts.pory"

# 113 "data/maps/VermilionCity/scripts.pory"
Seagallop_BattleFrontier::
# 114 "data/maps/VermilionCity/scripts.pory"
	.string "BATTLE FRONTIER$"
# 115 "data/maps/VermilionCity/scripts.pory"

# 116 "data/maps/VermilionCity/scripts.pory"
Seagallop_Cancel::
# 117 "data/maps/VermilionCity/scripts.pory"
	.string "CANCEL$"
# 118 "data/maps/VermilionCity/scripts.pory"

# 119 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 120 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 121 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 122 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 123 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 124 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 125 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 126 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 127 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 128 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 129 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 130 "data/maps/VermilionCity/scripts.pory"
	end
# 131 "data/maps/VermilionCity/scripts.pory"

# 132 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 133 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 134 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 135 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 136 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 137 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 138 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
# 139 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 140 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 141 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 142 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 143 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 144 "data/maps/VermilionCity/scripts.pory"
	end
# 145 "data/maps/VermilionCity/scripts.pory"

# 146 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 147 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 148 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 149 "data/maps/VermilionCity/scripts.pory"
	return
# 150 "data/maps/VermilionCity/scripts.pory"

# 151 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 152 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 153 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 154 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 155 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
# 156 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 157 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 158 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 159 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 160 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 161 "data/maps/VermilionCity/scripts.pory"
	end
# 162 "data/maps/VermilionCity/scripts.pory"

# 163 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 164 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 165 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 166 "data/maps/VermilionCity/scripts.pory"
	return
# 167 "data/maps/VermilionCity/scripts.pory"

# 168 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 169 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 170 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 171 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 172 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 173 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
# 174 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 175 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 176 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 177 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 178 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 179 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 180 "data/maps/VermilionCity/scripts.pory"
	end
# 181 "data/maps/VermilionCity/scripts.pory"

# 182 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 183 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 184 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 185 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 186 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 187 "data/maps/VermilionCity/scripts.pory"
	end
# 188 "data/maps/VermilionCity/scripts.pory"

# 189 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 190 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 191 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 192 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 193 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 194 "data/maps/VermilionCity/scripts.pory"
	end
# 195 "data/maps/VermilionCity/scripts.pory"

# 196 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBattleFrontier::
# 197 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 198 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 199 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BATTLE_FRONTIER
# 200 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 201 "data/maps/VermilionCity/scripts.pory"
	end
# 202 "data/maps/VermilionCity/scripts.pory"

# 203 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 204 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 205 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 206 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 207 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
# 208 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 209 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 210 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 211 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 212 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 213 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 214 "data/maps/VermilionCity/scripts.pory"
	end
# 215 "data/maps/VermilionCity/scripts.pory"

# 216 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 217 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 218 "data/maps/VermilionCity/scripts.pory"
	release
# 219 "data/maps/VermilionCity/scripts.pory"
	end
# 220 "data/maps/VermilionCity/scripts.pory"

# 221 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 222 "data/maps/VermilionCity/scripts.pory"
	lockall
# 223 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 224 "data/maps/VermilionCity/scripts.pory"
	end
# 225 "data/maps/VermilionCity/scripts.pory"

# 226 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 227 "data/maps/VermilionCity/scripts.pory"
	lockall
# 228 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 229 "data/maps/VermilionCity/scripts.pory"
	end
# 230 "data/maps/VermilionCity/scripts.pory"

# 231 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 232 "data/maps/VermilionCity/scripts.pory"
	lockall
# 233 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 234 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 235 "data/maps/VermilionCity/scripts.pory"
	end
# 236 "data/maps/VermilionCity/scripts.pory"

# 237 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 238 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 239 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 240 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 241 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 242 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 243 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 244 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 245 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 246 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 247 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 248 "data/maps/VermilionCity/scripts.pory"
	end
# 249 "data/maps/VermilionCity/scripts.pory"

# 250 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 251 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 252 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 253 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 254 "data/maps/VermilionCity/scripts.pory"
	end
# 255 "data/maps/VermilionCity/scripts.pory"

# 256 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 257 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 258 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 259 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 260 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 261 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 262 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 263 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 264 "data/maps/VermilionCity/scripts.pory"
	end
# 265 "data/maps/VermilionCity/scripts.pory"

# 266 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 267 "data/maps/VermilionCity/scripts.pory"
	lock
# 268 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 269 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DojoTrainer1
# 270 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 271 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DojoTrainer2
# 272 "data/maps/VermilionCity/scripts.pory"
	release
# 273 "data/maps/VermilionCity/scripts.pory"
	end
# 274 "data/maps/VermilionCity/scripts.pory"

# 275 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 276 "data/maps/VermilionCity/scripts.pory"
	lock
# 277 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 278 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 279 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 280 "data/maps/VermilionCity/scripts.pory"
	release
# 281 "data/maps/VermilionCity/scripts.pory"
	end
# 282 "data/maps/VermilionCity/scripts.pory"

# 283 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 284 "data/maps/VermilionCity/scripts.pory"
	lock
# 285 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 286 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_OldMan2Seller1
# 287 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 288 "data/maps/VermilionCity/scripts.pory"
	pokemart SHOP_ID_VERMILION_CITY_MART
# 289 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OldMan2Seller2
# 290 "data/maps/VermilionCity/scripts.pory"
	release
# 291 "data/maps/VermilionCity/scripts.pory"
	end
# 292 "data/maps/VermilionCity/scripts.pory"

# 293 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 294 "data/maps/VermilionCity/scripts.pory"
	lock
# 295 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 296 "data/maps/VermilionCity/scripts.pory"
	waitse
# 297 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 298 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 299 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 300 "data/maps/VermilionCity/scripts.pory"
	release
# 301 "data/maps/VermilionCity/scripts.pory"
	end
# 302 "data/maps/VermilionCity/scripts.pory"

# 303 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 304 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 305 "data/maps/VermilionCity/scripts.pory"
	end
# 306 "data/maps/VermilionCity/scripts.pory"

# 307 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 308 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 309 "data/maps/VermilionCity/scripts.pory"
	end
# 310 "data/maps/VermilionCity/scripts.pory"

# 311 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 312 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 313 "data/maps/VermilionCity/scripts.pory"
	end
# 314 "data/maps/VermilionCity/scripts.pory"

# 315 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 316 "data/maps/VermilionCity/scripts.pory"
	lockall
# 317 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 318 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 319 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 320 "data/maps/VermilionCity/scripts.pory"
	end
# 321 "data/maps/VermilionCity/scripts.pory"

# 322 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 323 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 324 "data/maps/VermilionCity/scripts.pory"
	end
# 325 "data/maps/VermilionCity/scripts.pory"

# 326 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor::
# 327 "data/maps/VermilionCity/scripts.pory"
	lock
# 328 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 329 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOption
# 330 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 331 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 332 "data/maps/VermilionCity/scripts.pory"

# 333 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_Menu::
# 334 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ToggleDoubleFlag, 0
# 335 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_StandardBattle, 1
# 336 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ScaledBossBattle, 2
# 337 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ScaledWildBoss, 3
# 338 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ToggleWildScaling, 4
# 339 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_Close, 5
# 340 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 341 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 342 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_TesterSailor_ToggleDoubleFlag
# 343 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TesterSailor_StandardBattle
# 344 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_TesterSailor_ScaledBossBattle
# 345 "data/maps/VermilionCity/scripts.pory"
	case 3, VermilionCity_EventScript_TesterSailor_ScaledWildBoss
# 346 "data/maps/VermilionCity/scripts.pory"
	case 4, VermilionCity_EventScript_TesterSailor_ToggleWildScaling
# 347 "data/maps/VermilionCity/scripts.pory"
	case 5, VermilionCity_EventScript_TesterSailor_Close
# 348 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, VermilionCity_EventScript_TesterSailor_Close
# 349 "data/maps/VermilionCity/scripts.pory"
	end
# 350 "data/maps/VermilionCity/scripts.pory"

# 351 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ToggleDoubleFlag::
# 352 "data/maps/VermilionCity/scripts.pory"
	checkflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 353 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_DOUBLE_BATTLE_WITH_ONE_MON, VermilionCity_EventScript_TesterSailor_DisableDoubleFlag
# 354 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 355 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_FlagNowEnabled, MSGBOX_DEFAULT
# 356 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 357 "data/maps/VermilionCity/scripts.pory"

# 358 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_DisableDoubleFlag::
# 359 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 360 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_FlagNowDisabled, MSGBOX_DEFAULT
# 361 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 362 "data/maps/VermilionCity/scripts.pory"

# 363 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ToggleWildScaling::
# 364 "data/maps/VermilionCity/scripts.pory"
	checkflag FLAG_SCALE_WILD_POKEMON
# 365 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_SCALE_WILD_POKEMON, VermilionCity_EventScript_TesterSailor_DisableWildScaling
# 366 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SCALE_WILD_POKEMON
# 367 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_WildScalingNowEnabled, MSGBOX_DEFAULT
# 368 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 369 "data/maps/VermilionCity/scripts.pory"

# 370 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_DisableWildScaling::
# 371 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_SCALE_WILD_POKEMON
# 372 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_WildScalingNowDisabled, MSGBOX_DEFAULT
# 373 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 374 "data/maps/VermilionCity/scripts.pory"

# 375 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_StandardBattle::
# 376 "data/maps/VermilionCity/scripts.pory"
	cleartrainerflag TRAINER_VERMILION_TESTER
# 377 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_double TRAINER_VERMILION_TESTER, VermilionCity_Text_TesterSailorBattleIntro, VermilionCity_Text_TesterSailorBattleDefeat, VermilionCity_Text_TesterSailorNotEnoughMons
# 378 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailorPostBattle, MSGBOX_DEFAULT
# 379 "data/maps/VermilionCity/scripts.pory"
	release
# 380 "data/maps/VermilionCity/scripts.pory"
	end
# 381 "data/maps/VermilionCity/scripts.pory"

# 382 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ScaledBossBattle::
# 383 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOffset
# 384 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 385 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus2, 2
# 386 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus5, 5
# 387 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus10, 10
# 388 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus20, 20
# 389 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus5, -5
# 390 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus10, -10
# 391 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 1, 0, DYN_MULTICHOICE_CB_NONE
# 392 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, VAR_RESULT
# 393 "data/maps/VermilionCity/scripts.pory"
	cleartrainerflag TRAINER_VERMILION_TESTER
# 394 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 395 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_double TRAINER_VERMILION_TESTER, VermilionCity_Text_TesterSailorBattleIntro, VermilionCity_Text_TesterSailorBattleDefeat, VermilionCity_Text_TesterSailorNotEnoughMons
# 396 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 397 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 398 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailorPostBattle, MSGBOX_DEFAULT
# 399 "data/maps/VermilionCity/scripts.pory"
	release
# 400 "data/maps/VermilionCity/scripts.pory"
	end
# 401 "data/maps/VermilionCity/scripts.pory"

# 402 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ScaledWildBoss::
# 403 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOffset
# 404 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 405 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus2, 2
# 406 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus5, 5
# 407 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus10, 10
# 408 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus20, 20
# 409 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus5, -5
# 410 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus10, -10
# 411 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 1, 0, DYN_MULTICHOICE_CB_NONE
# 412 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_TENTACRUEL
# 413 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8005, 20
# 414 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, VAR_RESULT
# 415 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8007, ITEM_NONE
# 416 "data/maps/VermilionCity/scripts.pory"
	callnative Script_SetScaledWildBattle
# 417 "data/maps/VermilionCity/scripts.pory"
	dowildbattle
# 418 "data/maps/VermilionCity/scripts.pory"
	release
# 419 "data/maps/VermilionCity/scripts.pory"
	end
# 420 "data/maps/VermilionCity/scripts.pory"

# 421 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_Close::
# 422 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_NoBattle, MSGBOX_DEFAULT
# 423 "data/maps/VermilionCity/scripts.pory"
	release
# 424 "data/maps/VermilionCity/scripts.pory"
	end
# 425 "data/maps/VermilionCity/scripts.pory"

# 426 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ArborDockScene::
# 427 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_SYS_POKEMON_GET, VermilionCity_EventScript_ArborDockScene_NotReady
# 428 "data/maps/VermilionCity/scripts.pory"
	lockall
# 429 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_ACT1_VERMILLION, 1
# 430 "data/maps/VermilionCity/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 431 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 432 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborDock1
# 433 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 434 "data/maps/VermilionCity/scripts.pory"
    faceplayer
# 435 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborDock2
# 436 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 437 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborDock3
# 438 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 439 "data/maps/VermilionCity/scripts.pory"
	clearmugshot
# 440 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_ARBOR
# 441 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_QUEST_MRFUJI_RESEARCH_ACTIVE
# 442 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_QUEST_SILPH_TESTING_ACTIVE
# 443 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCENE_SILPH, 1
# 444 "data/maps/VermilionCity/scripts.pory"
	quest_start_toast
# 445 "data/maps/VermilionCity/scripts.pory"
	quest_start_toast
# 446 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 447 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_ArborDockScene_End
# 448 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ArborDockScene_NotReady::
# 449 "data/maps/VermilionCity/scripts.pory"
	// Bumping the var to 2 stops the on-frame table (VAR_ACT1_VERMILLION, 0)
# 450 "data/maps/VermilionCity/scripts.pory"
	// from re-matching every single frame, which would otherwise starve out
# 451 "data/maps/VermilionCity/scripts.pory"
	// all other field input (see FuchsiaCity's identical fix for why).
# 452 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_ACT1_VERMILLION, 2
# 453 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ArborDockScene_End::
# 454 "data/maps/VermilionCity/scripts.pory"
	end
# 455 "data/maps/VermilionCity/scripts.pory"

# 456 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Arbor::
# 457 "data/maps/VermilionCity/scripts.pory"
	lock
# 458 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 459 "data/maps/VermilionCity/scripts.pory"
	showmugshot MUGSHOT_PROF_ARBOR, MUGSHOT_RIGHT
# 460 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 461 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_ArborIdle
# 462 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 463 "data/maps/VermilionCity/scripts.pory"
	clearmugshot
# 464 "data/maps/VermilionCity/scripts.pory"
	release
# 465 "data/maps/VermilionCity/scripts.pory"
	end
# 466 "data/maps/VermilionCity/scripts.pory"

# 467 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PsyduckChild::
# 468 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PsyduckChild, MSGBOX_NPC
# 469 "data/maps/VermilionCity/scripts.pory"
	end
# 470 "data/maps/VermilionCity/scripts.pory"

# 471 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PsyduckNPC::
# 472 "data/maps/VermilionCity/scripts.pory"
	lock
# 473 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 474 "data/maps/VermilionCity/scripts.pory"
	waitse
# 475 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
# 476 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PsyduckMisc
# 477 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 478 "data/maps/VermilionCity/scripts.pory"
	release
# 479 "data/maps/VermilionCity/scripts.pory"
	end
