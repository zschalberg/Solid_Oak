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
	.2byte 0
# 11 "data/maps/VermilionCity/scripts.pory"

# 12 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 13 "data/maps/VermilionCity/scripts.pory"
	lockall
# 14 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 15 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 16 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 17 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 18 "data/maps/VermilionCity/scripts.pory"
	end
# 19 "data/maps/VermilionCity/scripts.pory"

# 20 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne::
# 21 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 22 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 23 "data/maps/VermilionCity/scripts.pory"
	step_end
# 24 "data/maps/VermilionCity/scripts.pory"

# 25 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 26 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 27 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 28 "data/maps/VermilionCity/scripts.pory"
	end
# 29 "data/maps/VermilionCity/scripts.pory"

# 30 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 31 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 32 "data/maps/VermilionCity/scripts.pory"
	return
# 33 "data/maps/VermilionCity/scripts.pory"

# 34 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 35 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 36 "data/maps/VermilionCity/scripts.pory"
	end
# 37 "data/maps/VermilionCity/scripts.pory"

# 38 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 39 "data/maps/VermilionCity/scripts.pory"
	lock
# 40 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 41 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 42 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 43 "data/maps/VermilionCity/scripts.pory"
	release
# 44 "data/maps/VermilionCity/scripts.pory"
	end
# 45 "data/maps/VermilionCity/scripts.pory"

# 46 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 47 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 48 "data/maps/VermilionCity/scripts.pory"
	release
# 49 "data/maps/VermilionCity/scripts.pory"
	end
# 50 "data/maps/VermilionCity/scripts.pory"

# 51 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 52 "data/maps/VermilionCity/scripts.pory"
	lock
# 53 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 54 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 55 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 56 "data/maps/VermilionCity/scripts.pory"
	release
# 57 "data/maps/VermilionCity/scripts.pory"
	end
# 58 "data/maps/VermilionCity/scripts.pory"

# 59 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 60 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 61 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 62 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 63 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 64 "data/maps/VermilionCity/scripts.pory"
	end
# 65 "data/maps/VermilionCity/scripts.pory"

# 66 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 67 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 68 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 69 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 70 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 71 "data/maps/VermilionCity/scripts.pory"
	end
# 72 "data/maps/VermilionCity/scripts.pory"

# 73 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 74 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 75 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 76 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 77 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 78 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 79 "data/maps/VermilionCity/scripts.pory"
	release
# 80 "data/maps/VermilionCity/scripts.pory"
	end
# 81 "data/maps/VermilionCity/scripts.pory"

# 82 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseFrontierUnlocked::
# 83 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 84 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 85 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 86 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 87 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_SeviiIslands, 0
# 88 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BattleFrontier, 1
# 89 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 90 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddMysticTicket
# 91 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 92 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddAuroraTicket
# 93 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_Cancel, 4
# 94 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, NULL
# 95 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 96 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 97 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBattleFrontier
# 98 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToNavelRock
# 99 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_SailToBirthIsland
# 100 "data/maps/VermilionCity/scripts.pory"
	case 4, EventScript_CancelSail
# 101 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 102 "data/maps/VermilionCity/scripts.pory"
	end
# 103 "data/maps/VermilionCity/scripts.pory"

# 104 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddMysticTicket::
# 105 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_NavelRock, 2
# 106 "data/maps/VermilionCity/scripts.pory"
	return
# 107 "data/maps/VermilionCity/scripts.pory"

# 108 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddAuroraTicket::
# 109 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BirthIsland, 3
# 110 "data/maps/VermilionCity/scripts.pory"
	return
# 111 "data/maps/VermilionCity/scripts.pory"

# 112 "data/maps/VermilionCity/scripts.pory"
Seagallop_SeviiIslands::
# 113 "data/maps/VermilionCity/scripts.pory"
	.string "SEVII ISLANDS$"
# 114 "data/maps/VermilionCity/scripts.pory"

# 115 "data/maps/VermilionCity/scripts.pory"
Seagallop_NavelRock::
# 116 "data/maps/VermilionCity/scripts.pory"
	.string "NAVEL ROCK$"
# 117 "data/maps/VermilionCity/scripts.pory"

# 118 "data/maps/VermilionCity/scripts.pory"
Seagallop_BirthIsland::
# 119 "data/maps/VermilionCity/scripts.pory"
	.string "BIRTH ISLAND$"
# 120 "data/maps/VermilionCity/scripts.pory"

# 121 "data/maps/VermilionCity/scripts.pory"
Seagallop_BattleFrontier::
# 122 "data/maps/VermilionCity/scripts.pory"
	.string "BATTLE FRONTIER$"
# 123 "data/maps/VermilionCity/scripts.pory"

# 124 "data/maps/VermilionCity/scripts.pory"
Seagallop_Cancel::
# 125 "data/maps/VermilionCity/scripts.pory"
	.string "CANCEL$"
# 126 "data/maps/VermilionCity/scripts.pory"

# 127 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 128 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 129 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 130 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 131 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 132 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 133 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 134 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 135 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 136 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 137 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 138 "data/maps/VermilionCity/scripts.pory"
	end
# 139 "data/maps/VermilionCity/scripts.pory"

# 140 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 141 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 142 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 143 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 144 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 145 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 146 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
# 147 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 148 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 149 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 150 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 151 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 152 "data/maps/VermilionCity/scripts.pory"
	end
# 153 "data/maps/VermilionCity/scripts.pory"

# 154 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 155 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 156 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 157 "data/maps/VermilionCity/scripts.pory"
	return
# 158 "data/maps/VermilionCity/scripts.pory"

# 159 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 160 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 161 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 162 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 163 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
# 164 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 165 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 166 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 167 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 168 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 169 "data/maps/VermilionCity/scripts.pory"
	end
# 170 "data/maps/VermilionCity/scripts.pory"

# 171 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 172 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 173 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 174 "data/maps/VermilionCity/scripts.pory"
	return
# 175 "data/maps/VermilionCity/scripts.pory"

# 176 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 177 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 178 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 179 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 180 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 181 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
# 182 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 183 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 184 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 185 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 186 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 187 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 188 "data/maps/VermilionCity/scripts.pory"
	end
# 189 "data/maps/VermilionCity/scripts.pory"

# 190 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 191 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 192 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 193 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 194 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 195 "data/maps/VermilionCity/scripts.pory"
	end
# 196 "data/maps/VermilionCity/scripts.pory"

# 197 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 198 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 199 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 200 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 201 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 202 "data/maps/VermilionCity/scripts.pory"
	end
# 203 "data/maps/VermilionCity/scripts.pory"

# 204 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBattleFrontier::
# 205 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 206 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 207 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BATTLE_FRONTIER
# 208 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 209 "data/maps/VermilionCity/scripts.pory"
	end
# 210 "data/maps/VermilionCity/scripts.pory"

# 211 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 212 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 213 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 214 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 215 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
# 216 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 217 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 218 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 219 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 220 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 221 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 222 "data/maps/VermilionCity/scripts.pory"
	end
# 223 "data/maps/VermilionCity/scripts.pory"

# 224 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 225 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 226 "data/maps/VermilionCity/scripts.pory"
	release
# 227 "data/maps/VermilionCity/scripts.pory"
	end
# 228 "data/maps/VermilionCity/scripts.pory"

# 229 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 230 "data/maps/VermilionCity/scripts.pory"
	lockall
# 231 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 232 "data/maps/VermilionCity/scripts.pory"
	end
# 233 "data/maps/VermilionCity/scripts.pory"

# 234 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 235 "data/maps/VermilionCity/scripts.pory"
	lockall
# 236 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 237 "data/maps/VermilionCity/scripts.pory"
	end
# 238 "data/maps/VermilionCity/scripts.pory"

# 239 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 240 "data/maps/VermilionCity/scripts.pory"
	lockall
# 241 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 242 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 243 "data/maps/VermilionCity/scripts.pory"
	end
# 244 "data/maps/VermilionCity/scripts.pory"

# 245 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 246 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 247 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 248 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 249 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 250 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 251 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 252 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 253 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 254 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 255 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 256 "data/maps/VermilionCity/scripts.pory"
	end
# 257 "data/maps/VermilionCity/scripts.pory"

# 258 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 259 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 260 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 261 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 262 "data/maps/VermilionCity/scripts.pory"
	end
# 263 "data/maps/VermilionCity/scripts.pory"

# 264 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 265 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 266 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 267 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 268 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 269 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 270 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 271 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 272 "data/maps/VermilionCity/scripts.pory"
	end
# 273 "data/maps/VermilionCity/scripts.pory"

# 274 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 275 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 276 "data/maps/VermilionCity/scripts.pory"
	end
# 277 "data/maps/VermilionCity/scripts.pory"

# 278 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 279 "data/maps/VermilionCity/scripts.pory"
	lock
# 280 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 281 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 282 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 283 "data/maps/VermilionCity/scripts.pory"
	release
# 284 "data/maps/VermilionCity/scripts.pory"
	end
# 285 "data/maps/VermilionCity/scripts.pory"

# 286 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 287 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 288 "data/maps/VermilionCity/scripts.pory"
	end
# 289 "data/maps/VermilionCity/scripts.pory"

# 290 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 291 "data/maps/VermilionCity/scripts.pory"
	lock
# 292 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 293 "data/maps/VermilionCity/scripts.pory"
	waitse
# 294 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 295 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 296 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 297 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 298 "data/maps/VermilionCity/scripts.pory"
	release
# 299 "data/maps/VermilionCity/scripts.pory"
	end
# 300 "data/maps/VermilionCity/scripts.pory"

# 301 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 302 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 303 "data/maps/VermilionCity/scripts.pory"
	end
# 304 "data/maps/VermilionCity/scripts.pory"

# 305 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 306 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 307 "data/maps/VermilionCity/scripts.pory"
	end
# 308 "data/maps/VermilionCity/scripts.pory"

# 309 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 310 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 311 "data/maps/VermilionCity/scripts.pory"
	end
# 312 "data/maps/VermilionCity/scripts.pory"

# 313 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 314 "data/maps/VermilionCity/scripts.pory"
	lockall
# 315 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 316 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 317 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 318 "data/maps/VermilionCity/scripts.pory"
	end
# 319 "data/maps/VermilionCity/scripts.pory"

# 320 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 321 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 322 "data/maps/VermilionCity/scripts.pory"
	end
# 323 "data/maps/VermilionCity/scripts.pory"

# 324 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor::
# 325 "data/maps/VermilionCity/scripts.pory"
	lock
# 326 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 327 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOption
# 328 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 329 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 330 "data/maps/VermilionCity/scripts.pory"

# 331 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_Menu::
# 332 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ToggleDoubleFlag, 0
# 333 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_StandardBattle, 1
# 334 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ScaledBossBattle, 2
# 335 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ScaledWildBoss, 3
# 336 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_ToggleWildScaling, 4
# 337 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_Close, 5
# 338 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 339 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 340 "data/maps/VermilionCity/scripts.pory"
	case 0, VermilionCity_EventScript_TesterSailor_ToggleDoubleFlag
# 341 "data/maps/VermilionCity/scripts.pory"
	case 1, VermilionCity_EventScript_TesterSailor_StandardBattle
# 342 "data/maps/VermilionCity/scripts.pory"
	case 2, VermilionCity_EventScript_TesterSailor_ScaledBossBattle
# 343 "data/maps/VermilionCity/scripts.pory"
	case 3, VermilionCity_EventScript_TesterSailor_ScaledWildBoss
# 344 "data/maps/VermilionCity/scripts.pory"
	case 4, VermilionCity_EventScript_TesterSailor_ToggleWildScaling
# 345 "data/maps/VermilionCity/scripts.pory"
	case 5, VermilionCity_EventScript_TesterSailor_Close
# 346 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, VermilionCity_EventScript_TesterSailor_Close
# 347 "data/maps/VermilionCity/scripts.pory"
	end
# 348 "data/maps/VermilionCity/scripts.pory"

# 349 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ToggleDoubleFlag::
# 350 "data/maps/VermilionCity/scripts.pory"
	checkflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 351 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_DOUBLE_BATTLE_WITH_ONE_MON, VermilionCity_EventScript_TesterSailor_DisableDoubleFlag
# 352 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 353 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_FlagNowEnabled, MSGBOX_DEFAULT
# 354 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 355 "data/maps/VermilionCity/scripts.pory"

# 356 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_DisableDoubleFlag::
# 357 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_DOUBLE_BATTLE_WITH_ONE_MON
# 358 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_FlagNowDisabled, MSGBOX_DEFAULT
# 359 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 360 "data/maps/VermilionCity/scripts.pory"

# 361 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ToggleWildScaling::
# 362 "data/maps/VermilionCity/scripts.pory"
	checkflag FLAG_SCALE_WILD_POKEMON
# 363 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_SCALE_WILD_POKEMON, VermilionCity_EventScript_TesterSailor_DisableWildScaling
# 364 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SCALE_WILD_POKEMON
# 365 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_WildScalingNowEnabled, MSGBOX_DEFAULT
# 366 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 367 "data/maps/VermilionCity/scripts.pory"

# 368 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_DisableWildScaling::
# 369 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_SCALE_WILD_POKEMON
# 370 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_WildScalingNowDisabled, MSGBOX_DEFAULT
# 371 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_TesterSailor_Menu
# 372 "data/maps/VermilionCity/scripts.pory"

# 373 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_StandardBattle::
# 374 "data/maps/VermilionCity/scripts.pory"
	cleartrainerflag TRAINER_VERMILION_TESTER
# 375 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_double TRAINER_VERMILION_TESTER, VermilionCity_Text_TesterSailorBattleIntro, VermilionCity_Text_TesterSailorBattleDefeat, VermilionCity_Text_TesterSailorNotEnoughMons
# 376 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailorPostBattle, MSGBOX_DEFAULT
# 377 "data/maps/VermilionCity/scripts.pory"
	release
# 378 "data/maps/VermilionCity/scripts.pory"
	end
# 379 "data/maps/VermilionCity/scripts.pory"

# 380 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ScaledBossBattle::
# 381 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOffset
# 382 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 383 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus2, 2
# 384 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus5, 5
# 385 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus10, 10
# 386 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus20, 20
# 387 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus5, -5
# 388 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus10, -10
# 389 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 1, 0, DYN_MULTICHOICE_CB_NONE
# 390 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, VAR_RESULT
# 391 "data/maps/VermilionCity/scripts.pory"
	cleartrainerflag TRAINER_VERMILION_TESTER
# 392 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 393 "data/maps/VermilionCity/scripts.pory"
	trainerbattle_double TRAINER_VERMILION_TESTER, VermilionCity_Text_TesterSailorBattleIntro, VermilionCity_Text_TesterSailorBattleDefeat, VermilionCity_Text_TesterSailorNotEnoughMons
# 394 "data/maps/VermilionCity/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 395 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 0
# 396 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailorPostBattle, MSGBOX_DEFAULT
# 397 "data/maps/VermilionCity/scripts.pory"
	release
# 398 "data/maps/VermilionCity/scripts.pory"
	end
# 399 "data/maps/VermilionCity/scripts.pory"

# 400 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_ScaledWildBoss::
# 401 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_Tester_ChooseOffset
# 402 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 403 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus2, 2
# 404 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus5, 5
# 405 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus10, 10
# 406 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetPlus20, 20
# 407 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus5, -5
# 408 "data/maps/VermilionCity/scripts.pory"
	dynmultipush VermilionCity_Text_Tester_OffsetMinus10, -10
# 409 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 1, 0, DYN_MULTICHOICE_CB_NONE
# 410 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_TENTACRUEL
# 411 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8005, 20
# 412 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, VAR_RESULT
# 413 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8007, ITEM_NONE
# 414 "data/maps/VermilionCity/scripts.pory"
	callnative Script_SetScaledWildBattle
# 415 "data/maps/VermilionCity/scripts.pory"
	dowildbattle
# 416 "data/maps/VermilionCity/scripts.pory"
	release
# 417 "data/maps/VermilionCity/scripts.pory"
	end
# 418 "data/maps/VermilionCity/scripts.pory"

# 419 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_TesterSailor_Close::
# 420 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TesterSailor_NoBattle, MSGBOX_DEFAULT
# 421 "data/maps/VermilionCity/scripts.pory"
	release
# 422 "data/maps/VermilionCity/scripts.pory"
	end
