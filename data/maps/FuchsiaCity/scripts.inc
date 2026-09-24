FuchsiaCity_MapScripts::
# 2 "data/maps/FuchsiaCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0


FuchsiaCity_OnTransition::
# 6 "data/maps/FuchsiaCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
# 7 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_OnTransition_2
# 10 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
FuchsiaCity_OnTransition_1:
	end

FuchsiaCity_OnTransition_2:
# 8 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	goto FuchsiaCity_OnTransition_1


FuchsiaCity_EventScript_FujiTalk::
# 19 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_KRABBY_QUEST_COMPLETE, FuchsiaCity_EventScript_FujiTalk_2
# 30 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_KRABBY_QUEST_ACTIVE, FuchsiaCity_EventScript_FujiTalk_5
# 78 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTalk_Text_2, MSGBOX_NPC
	end

FuchsiaCity_EventScript_FujiTalk_2:
# 20 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 21 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 22 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTalk_Text_0
# 26 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 27 "data/maps/FuchsiaCity/scripts.pory"
	release
	end

FuchsiaCity_EventScript_FujiTalk_5:
# 34 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8006, 0
# 35 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, 0
# 36 "data/maps/FuchsiaCity/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 37 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq FuchsiaCity_EventScript_FujiTalk_8
FuchsiaCity_EventScript_FujiTalk_7:
# 40 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, 1
# 41 "data/maps/FuchsiaCity/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 42 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq FuchsiaCity_EventScript_FujiTalk_11
FuchsiaCity_EventScript_FujiTalk_10:
# 45 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, 2
# 46 "data/maps/FuchsiaCity/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 47 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq FuchsiaCity_EventScript_FujiTalk_14
FuchsiaCity_EventScript_FujiTalk_13:
# 50 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, 3
# 51 "data/maps/FuchsiaCity/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 52 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq FuchsiaCity_EventScript_FujiTalk_17
FuchsiaCity_EventScript_FujiTalk_16:
# 55 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, 4
# 56 "data/maps/FuchsiaCity/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 57 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq FuchsiaCity_EventScript_FujiTalk_20
FuchsiaCity_EventScript_FujiTalk_19:
# 60 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, 5
# 61 "data/maps/FuchsiaCity/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 62 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq FuchsiaCity_EventScript_FujiTalk_23
FuchsiaCity_EventScript_FujiTalk_22:
# 65 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_0x8006, 2
	goto_if_lt FuchsiaCity_EventScript_FujiTalk_26
# 75 "data/maps/FuchsiaCity/scripts.pory"
	goto FuchsiaCity_EventScript_FujiTurnIn
	end

FuchsiaCity_EventScript_FujiTalk_8:
# 38 "data/maps/FuchsiaCity/scripts.pory"
	addvar VAR_0x8006, 1
	goto FuchsiaCity_EventScript_FujiTalk_7

FuchsiaCity_EventScript_FujiTalk_11:
# 43 "data/maps/FuchsiaCity/scripts.pory"
	addvar VAR_0x8006, 1
	goto FuchsiaCity_EventScript_FujiTalk_10

FuchsiaCity_EventScript_FujiTalk_14:
# 48 "data/maps/FuchsiaCity/scripts.pory"
	addvar VAR_0x8006, 1
	goto FuchsiaCity_EventScript_FujiTalk_13

FuchsiaCity_EventScript_FujiTalk_17:
# 53 "data/maps/FuchsiaCity/scripts.pory"
	addvar VAR_0x8006, 1
	goto FuchsiaCity_EventScript_FujiTalk_16

FuchsiaCity_EventScript_FujiTalk_20:
# 58 "data/maps/FuchsiaCity/scripts.pory"
	addvar VAR_0x8006, 1
	goto FuchsiaCity_EventScript_FujiTalk_19

FuchsiaCity_EventScript_FujiTalk_23:
# 63 "data/maps/FuchsiaCity/scripts.pory"
	addvar VAR_0x8006, 1
	goto FuchsiaCity_EventScript_FujiTalk_22

FuchsiaCity_EventScript_FujiTalk_26:
# 66 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 67 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 68 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTalk_Text_1
# 71 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 72 "data/maps/FuchsiaCity/scripts.pory"
	release
	end


FuchsiaCity_EventScript_FujiTurnIn::
# 85 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 86 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_ACT1_FUCHSIA, 1
# 87 "data/maps/FuchsiaCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 88 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 89 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_0
# 91 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 92 "data/maps/FuchsiaCity/scripts.pory"
	clearmugshot
# 94 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 95 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_1
# 96 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 97 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_2
# 110 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 111 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_3
# 124 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 125 "data/maps/FuchsiaCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 126 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 127 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_4
# 128 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 129 "data/maps/FuchsiaCity/scripts.pory"
	clearmugshot
# 131 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 132 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_5
# 136 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 137 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_6
# 140 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 141 "data/maps/FuchsiaCity/scripts.pory"
	applymovement LOCALID_FUCHSIA_FUJI, FuchsiaCity_Movement_FujiToDoor
# 142 "data/maps/FuchsiaCity/scripts.pory"
	applymovement LOCALID_FUCHSIA_AGATHA, FuchsiaCity_Movement_AgathaToDoor
# 143 "data/maps/FuchsiaCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, FuchsiaCity_Movement_PlayerToDoor
# 144 "data/maps/FuchsiaCity/scripts.pory"
	waitmovement 0
# 145 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_HIDE_FUCHSIA_AGATHA
# 146 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_HIDE_FUCHSIA_FUJI
# 147 "data/maps/FuchsiaCity/scripts.pory"
	warp MAP_FUCHSIA_CITY_RESERVE, 8, 5
# 148 "data/maps/FuchsiaCity/scripts.pory"
	waitstate
# 149 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
	end


# 158 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_Movement_FujiToDoor:
# 159 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 159 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 160 "data/maps/FuchsiaCity/scripts.pory"
	set_invisible
	step_end

# 163 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_Movement_AgathaToDoor:
# 164 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 164 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 165 "data/maps/FuchsiaCity/scripts.pory"
	set_invisible
	step_end

# 168 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_Movement_PlayerToDoor:
# 169 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 169 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
	step_end

FuchsiaCity_EventScript_Youngster::
# 173 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 174 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 175 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_Youngster_Text_0, MSGBOX_YESNO
# 177 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq FuchsiaCity_EventScript_Youngster_2
# 184 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_Youngster_Text_2, MSGBOX_DEFAULT
# 185 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
FuchsiaCity_EventScript_Youngster_1:
# 187 "data/maps/FuchsiaCity/scripts.pory"
	release
	end

FuchsiaCity_EventScript_Youngster_2:
# 178 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_Youngster_Text_1, MSGBOX_DEFAULT
# 179 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 180 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_QUEST_KNOW_SLOWPOKE_EVOS
# 181 "data/maps/FuchsiaCity/scripts.pory"
	callnative Script_SetShellderTestWildBattle
# 182 "data/maps/FuchsiaCity/scripts.pory"
	dowildbattle
	goto FuchsiaCity_EventScript_Youngster_1


# 191 "data/maps/FuchsiaCity/scripts.pory"

# 192 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LittleBoy::
# 193 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
# 194 "data/maps/FuchsiaCity/scripts.pory"
	end
# 195 "data/maps/FuchsiaCity/scripts.pory"

# 196 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OldMan::
# 197 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
# 198 "data/maps/FuchsiaCity/scripts.pory"
	end
# 199 "data/maps/FuchsiaCity/scripts.pory"

# 200 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Erik::
# 201 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
# 202 "data/maps/FuchsiaCity/scripts.pory"
	end
# 203 "data/maps/FuchsiaCity/scripts.pory"

# 204 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Lass::
# 205 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 206 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 207 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 3
# 208 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
# 209 "data/maps/FuchsiaCity/scripts.pory"
	release
# 210 "data/maps/FuchsiaCity/scripts.pory"
	end
# 211 "data/maps/FuchsiaCity/scripts.pory"

# 212 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_CitySign::
# 213 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
# 214 "data/maps/FuchsiaCity/scripts.pory"
	end
# 215 "data/maps/FuchsiaCity/scripts.pory"

# 216 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneSign::
# 217 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
# 218 "data/maps/FuchsiaCity/scripts.pory"
	end
# 219 "data/maps/FuchsiaCity/scripts.pory"

# 220 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariGameSign::
# 221 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
# 222 "data/maps/FuchsiaCity/scripts.pory"
	end
# 223 "data/maps/FuchsiaCity/scripts.pory"

# 224 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_WardensHomeSign::
# 225 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
# 226 "data/maps/FuchsiaCity/scripts.pory"
	end
# 227 "data/maps/FuchsiaCity/scripts.pory"

# 228 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneOfficeSign::
# 229 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
# 230 "data/maps/FuchsiaCity/scripts.pory"
	end
# 231 "data/maps/FuchsiaCity/scripts.pory"

# 232 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_GymSign::
# 233 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 234 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 0
# 235 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_GymSign
# 236 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 237 "data/maps/FuchsiaCity/scripts.pory"
	end
# 238 "data/maps/FuchsiaCity/scripts.pory"

# 239 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_ChanseySign::
# 240 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 241 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_CHANSEY
# 242 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 243 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_CHANSEY, 10, 3
# 244 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_ChanseySign
# 245 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 246 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 247 "data/maps/FuchsiaCity/scripts.pory"
	end
# 248 "data/maps/FuchsiaCity/scripts.pory"

# 249 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_VoltorbSign::
# 250 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 251 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_VOLTORB
# 252 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 253 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_VOLTORB, 10, 3
# 254 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_VoltorbSign
# 255 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 256 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 257 "data/maps/FuchsiaCity/scripts.pory"
	end
# 258 "data/maps/FuchsiaCity/scripts.pory"

# 259 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_KangaskhanSign::
# 260 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 261 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KANGASKHAN
# 262 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 263 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KANGASKHAN, 10, 3
# 264 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KangaskhanSign
# 265 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 266 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 267 "data/maps/FuchsiaCity/scripts.pory"
	end
# 268 "data/maps/FuchsiaCity/scripts.pory"

# 269 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SlowpokeSign::
# 270 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 271 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_SLOWPOKE
# 272 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 273 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_SLOWPOKE, 10, 3
# 274 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SlowpokeSign
# 275 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 276 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 277 "data/maps/FuchsiaCity/scripts.pory"
	end
# 278 "data/maps/FuchsiaCity/scripts.pory"

# 279 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LaprasSign::
# 280 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 281 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_LAPRAS
# 282 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 283 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_LAPRAS, 10, 3
# 284 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_LaprasSign
# 285 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 286 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 287 "data/maps/FuchsiaCity/scripts.pory"
	end
# 288 "data/maps/FuchsiaCity/scripts.pory"

# 289 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_FossilMonSign::
# 290 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 291 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
# 292 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KABUTO
# 293 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 294 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KABUTO, 10, 3
# 295 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KabutoSign
# 296 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 297 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 298 "data/maps/FuchsiaCity/scripts.pory"
	end
# 299 "data/maps/FuchsiaCity/scripts.pory"

# 300 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OmanyteSign::
# 301 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_OMANYTE
# 302 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 303 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_OMANYTE, 10, 3
# 304 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_OmanyteSign
# 305 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 306 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 307 "data/maps/FuchsiaCity/scripts.pory"
	end
# 308 "data/maps/FuchsiaCity/scripts.pory"

# 309 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Fuji::
# 310 "data/maps/FuchsiaCity/scripts.pory"
	goto FuchsiaCity_EventScript_FujiTalk
# 311 "data/maps/FuchsiaCity/scripts.pory"

# 312 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Agatha::
# 313 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 314 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 315 "data/maps/FuchsiaCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 316 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 317 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_AgathaIdle, MSGBOX_DEFAULT
# 318 "data/maps/FuchsiaCity/scripts.pory"
	clearmugshot
# 319 "data/maps/FuchsiaCity/scripts.pory"
	release
# 320 "data/maps/FuchsiaCity/scripts.pory"
	end
# 321 "data/maps/FuchsiaCity/scripts.pory"

# 322 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_Text_AgathaIdle:
# 323 "data/maps/FuchsiaCity/scripts.pory"
	.string "We have work to do.$"

FuchsiaCity_EventScript_FujiTalk_Text_0:
# 22 "data/maps/FuchsiaCity/scripts.pory"
	.string "Come back when you've had\n"
	.string "more time in the field.\p"
	.string "There's more to document\n"
	.string "out there.$"

FuchsiaCity_EventScript_FujiTalk_Text_1:
# 68 "data/maps/FuchsiaCity/scripts.pory"
	.string "The shallows south of here.\p"
	.string "Bring two KRABBY in your\n"
	.string "party before you come find me.$"

FuchsiaCity_EventScript_FujiTalk_Text_2:
# 78 "data/maps/FuchsiaCity/scripts.pory"
	.string "Good country, this.\n"
	.string "Take your time looking around.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_0:
# 89 "data/maps/FuchsiaCity/scripts.pory"
	.string "You're slow, Sammy.\n"
	.string "I got mine on the way down.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_1:
# 95 "data/maps/FuchsiaCity/scripts.pory"
	.string "Bring both sets over here.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_2:
# 97 "data/maps/FuchsiaCity/scripts.pory"
	.string "See these two? Same species.\n"
	.string "Same location. One is noticeably\l"
	.string "larger than the other.\p"
	.string "That difference isn't arbitrary.\n"
	.string "It affects how they move, how\l"
	.string "hard they hit, how fast they\l"
	.string "recover.\p"
	.string "This is the first thing I need\n"
	.string "you to understand about what\l"
	.string "we're doing here.\p"
	.string "Individual differences in\n"
	.string "POKéMON are real.\l"
	.string "They matter.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_3:
# 111 "data/maps/FuchsiaCity/scripts.pory"
	.string "This land behind us has been\n"
	.string "set aside - a conservation\l"
	.string "agreement I've been working on\l"
	.string "for years.\p"
	.string "The idea is simple: we document\n"
	.string "the POKéMON being displaced,\l"
	.string "and we give them somewhere\l"
	.string "to go.\p"
	.string "It's not much yet.\n"
	.string "But it grows with what we\l"
	.string "contribute.\p"
	.string "These four KRABBY will be\n"
	.string "the first.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_4:
# 127 "data/maps/FuchsiaCity/scripts.pory"
	.string "How do you know they'll stay?$"

FuchsiaCity_EventScript_FujiTurnIn_Text_5:
# 132 "data/maps/FuchsiaCity/scripts.pory"
	.string "They won't all stay.\n"
	.string "That's not the point.\p"
	.string "The point is to give them\n"
	.string "the choice.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_6:
# 137 "data/maps/FuchsiaCity/scripts.pory"
	.string "Come inside for a moment.\p"
	.string "There's two people you should\n"
	.string "meet before you head back out.$"

FuchsiaCity_EventScript_Youngster_Text_0:
# 175 "data/maps/FuchsiaCity/scripts.pory"
	.string "Hey! Want to test the Slowpoke\n"
	.string "evolution? I found a wild Shellder!$"

FuchsiaCity_EventScript_Youngster_Text_1:
# 178 "data/maps/FuchsiaCity/scripts.pory"
	.string "Here it comes!$"

FuchsiaCity_EventScript_Youngster_Text_2:
# 184 "data/maps/FuchsiaCity/scripts.pory"
	.string "Let me know if you change your mind!$"
