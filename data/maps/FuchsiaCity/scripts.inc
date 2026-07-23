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
	goto_if_set FLAG_KRABBY_QUEST_GIVEN, FuchsiaCity_EventScript_FujiTalk_5
# 47 "data/maps/FuchsiaCity/scripts.pory"
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
# 31 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KRABBY
# 32 "data/maps/FuchsiaCity/scripts.pory"
	special GetSpeciesCaughtCount
# 33 "data/maps/FuchsiaCity/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FuchsiaCity_EventScript_FujiTalk_8
# 44 "data/maps/FuchsiaCity/scripts.pory"
	goto FuchsiaCity_EventScript_FujiTurnIn
	end

FuchsiaCity_EventScript_FujiTalk_8:
# 34 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 35 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 36 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTalk_Text_1
# 40 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 41 "data/maps/FuchsiaCity/scripts.pory"
	release
	end


FuchsiaCity_EventScript_FujiTurnIn::
# 54 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 55 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_ACT1_FUCHSIA, 1
# 56 "data/maps/FuchsiaCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 57 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 58 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_0
# 59 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 60 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_1
# 61 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 62 "data/maps/FuchsiaCity/scripts.pory"
	clearmugshot
# 63 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_2
# 64 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 65 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_3
# 78 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 79 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_4
# 92 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 93 "data/maps/FuchsiaCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 94 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 95 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_5
# 96 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 97 "data/maps/FuchsiaCity/scripts.pory"
	clearmugshot
# 98 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_6
# 102 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 103 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_7
# 112 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 113 "data/maps/FuchsiaCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 114 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 115 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_EventScript_FujiTurnIn_Text_8
# 116 "data/maps/FuchsiaCity/scripts.pory"
	closemessage
# 117 "data/maps/FuchsiaCity/scripts.pory"
	clearmugshot
# 118 "data/maps/FuchsiaCity/scripts.pory"
	applymovement LOCALID_FUCHSIA_AGATHA, FuchsiaCity_Movement_AgathaExit
# 119 "data/maps/FuchsiaCity/scripts.pory"
	waitmovement 0
# 120 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_HIDE_FUCHSIA_AGATHA
# 121 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_HIDE_FUCHSIA_FUJI
# 122 "data/maps/FuchsiaCity/scripts.pory"
	setflag FLAG_KRABBY_QUEST_COMPLETE
# 123 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
	end


# 127 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_Movement_AgathaExit:
# 128 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 128 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 128 "data/maps/FuchsiaCity/scripts.pory"
	walk_up
# 129 "data/maps/FuchsiaCity/scripts.pory"
	set_invisible
	step_end

# 132 "data/maps/FuchsiaCity/scripts.pory"

# 133 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LittleBoy::
# 134 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
# 135 "data/maps/FuchsiaCity/scripts.pory"
	end
# 136 "data/maps/FuchsiaCity/scripts.pory"

# 137 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OldMan::
# 138 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
# 139 "data/maps/FuchsiaCity/scripts.pory"
	end
# 140 "data/maps/FuchsiaCity/scripts.pory"

# 141 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Erik::
# 142 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
# 143 "data/maps/FuchsiaCity/scripts.pory"
	end
# 144 "data/maps/FuchsiaCity/scripts.pory"

# 145 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Youngster::
# 146 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
# 147 "data/maps/FuchsiaCity/scripts.pory"
	end
# 148 "data/maps/FuchsiaCity/scripts.pory"

# 149 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Lass::
# 150 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 151 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 152 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 3
# 153 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
# 154 "data/maps/FuchsiaCity/scripts.pory"
	release
# 155 "data/maps/FuchsiaCity/scripts.pory"
	end
# 156 "data/maps/FuchsiaCity/scripts.pory"

# 157 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_CitySign::
# 158 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
# 159 "data/maps/FuchsiaCity/scripts.pory"
	end
# 160 "data/maps/FuchsiaCity/scripts.pory"

# 161 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneSign::
# 162 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
# 163 "data/maps/FuchsiaCity/scripts.pory"
	end
# 164 "data/maps/FuchsiaCity/scripts.pory"

# 165 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariGameSign::
# 166 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
# 167 "data/maps/FuchsiaCity/scripts.pory"
	end
# 168 "data/maps/FuchsiaCity/scripts.pory"

# 169 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_WardensHomeSign::
# 170 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
# 171 "data/maps/FuchsiaCity/scripts.pory"
	end
# 172 "data/maps/FuchsiaCity/scripts.pory"

# 173 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SafariZoneOfficeSign::
# 174 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
# 175 "data/maps/FuchsiaCity/scripts.pory"
	end
# 176 "data/maps/FuchsiaCity/scripts.pory"

# 177 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_GymSign::
# 178 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 179 "data/maps/FuchsiaCity/scripts.pory"
	famechecker FAMECHECKER_KOGA, 0
# 180 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_GymSign
# 181 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 182 "data/maps/FuchsiaCity/scripts.pory"
	end
# 183 "data/maps/FuchsiaCity/scripts.pory"

# 184 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_ChanseySign::
# 185 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 186 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_CHANSEY
# 187 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 188 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_CHANSEY, 10, 3
# 189 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_ChanseySign
# 190 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 191 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 192 "data/maps/FuchsiaCity/scripts.pory"
	end
# 193 "data/maps/FuchsiaCity/scripts.pory"

# 194 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_VoltorbSign::
# 195 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 196 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_VOLTORB
# 197 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 198 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_VOLTORB, 10, 3
# 199 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_VoltorbSign
# 200 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 201 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 202 "data/maps/FuchsiaCity/scripts.pory"
	end
# 203 "data/maps/FuchsiaCity/scripts.pory"

# 204 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_KangaskhanSign::
# 205 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 206 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KANGASKHAN
# 207 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 208 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KANGASKHAN, 10, 3
# 209 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KangaskhanSign
# 210 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 211 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 212 "data/maps/FuchsiaCity/scripts.pory"
	end
# 213 "data/maps/FuchsiaCity/scripts.pory"

# 214 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_SlowpokeSign::
# 215 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 216 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_SLOWPOKE
# 217 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 218 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_SLOWPOKE, 10, 3
# 219 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_SlowpokeSign
# 220 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 221 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 222 "data/maps/FuchsiaCity/scripts.pory"
	end
# 223 "data/maps/FuchsiaCity/scripts.pory"

# 224 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_LaprasSign::
# 225 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 226 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_LAPRAS
# 227 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 228 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_LAPRAS, 10, 3
# 229 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_LaprasSign
# 230 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 231 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 232 "data/maps/FuchsiaCity/scripts.pory"
	end
# 233 "data/maps/FuchsiaCity/scripts.pory"

# 234 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_FossilMonSign::
# 235 "data/maps/FuchsiaCity/scripts.pory"
	lockall
# 236 "data/maps/FuchsiaCity/scripts.pory"
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
# 237 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_KABUTO
# 238 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 239 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_KABUTO, 10, 3
# 240 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_KabutoSign
# 241 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 242 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 243 "data/maps/FuchsiaCity/scripts.pory"
	end
# 244 "data/maps/FuchsiaCity/scripts.pory"

# 245 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_OmanyteSign::
# 246 "data/maps/FuchsiaCity/scripts.pory"
	setvar VAR_0x8004, SPECIES_OMANYTE
# 247 "data/maps/FuchsiaCity/scripts.pory"
	special SetSeenMon
# 248 "data/maps/FuchsiaCity/scripts.pory"
	showmonpic SPECIES_OMANYTE, 10, 3
# 249 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_OmanyteSign
# 250 "data/maps/FuchsiaCity/scripts.pory"
	hidemonpic
# 251 "data/maps/FuchsiaCity/scripts.pory"
	releaseall
# 252 "data/maps/FuchsiaCity/scripts.pory"
	end
# 253 "data/maps/FuchsiaCity/scripts.pory"

# 254 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Fuji::
# 255 "data/maps/FuchsiaCity/scripts.pory"
	goto FuchsiaCity_EventScript_FujiTalk
# 256 "data/maps/FuchsiaCity/scripts.pory"

# 257 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_EventScript_Agatha::
# 258 "data/maps/FuchsiaCity/scripts.pory"
	lock
# 259 "data/maps/FuchsiaCity/scripts.pory"
	faceplayer
# 260 "data/maps/FuchsiaCity/scripts.pory"
	showmugshot MUGSHOT_AGATHA, MUGSHOT_LEFT
# 261 "data/maps/FuchsiaCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 262 "data/maps/FuchsiaCity/scripts.pory"
	msgbox FuchsiaCity_Text_AgathaIdle, MSGBOX_DEFAULT
# 263 "data/maps/FuchsiaCity/scripts.pory"
	clearmugshot
# 264 "data/maps/FuchsiaCity/scripts.pory"
	release
# 265 "data/maps/FuchsiaCity/scripts.pory"
	end
# 266 "data/maps/FuchsiaCity/scripts.pory"

# 267 "data/maps/FuchsiaCity/scripts.pory"
FuchsiaCity_Text_AgathaIdle:
# 268 "data/maps/FuchsiaCity/scripts.pory"
	.string "We have work to do.$"

FuchsiaCity_EventScript_FujiTalk_Text_0:
# 22 "data/maps/FuchsiaCity/scripts.pory"
	.string "Come back when you've had\n"
	.string "more time in the field.\p"
	.string "There's more to document\n"
	.string "out there.$"

FuchsiaCity_EventScript_FujiTalk_Text_1:
# 36 "data/maps/FuchsiaCity/scripts.pory"
	.string "The shallows south of here.\p"
	.string "Catch a few KRABBY with the\n"
	.string "RESEARCH BALLs I gave you.\p"
	.string "Then come find me.$"

FuchsiaCity_EventScript_FujiTalk_Text_2:
# 47 "data/maps/FuchsiaCity/scripts.pory"
	.string "Good country, this.\n"
	.string "Take your time looking around.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_0:
# 58 "data/maps/FuchsiaCity/scripts.pory"
	.string "You're slow, Sammy.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_1:
# 60 "data/maps/FuchsiaCity/scripts.pory"
	.string "I got mine on the way down.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_2:
# 63 "data/maps/FuchsiaCity/scripts.pory"
	.string "Bring both sets over here.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_3:
# 65 "data/maps/FuchsiaCity/scripts.pory"
	.string "See these two? Same species.\n"
	.string "Same location. One is noticeably\l"
	.string "larger than the other.\p"
	.string "That difference isn't random.\n"
	.string "It affects how they move, how\l"
	.string "hard they hit, how fast they\l"
	.string "recover.\p"
	.string "This is the first thing I need\n"
	.string "you to understand about what\l"
	.string "we're doing here.\p"
	.string "Individual differences in\n"
	.string "POKéMON are real.\n"
	.string "They matter.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_4:
# 79 "data/maps/FuchsiaCity/scripts.pory"
	.string "This land behind us has been\n"
	.string "set aside - a conservation\l"
	.string "agreement I've been working on\n"
	.string "for years.\p"
	.string "The idea is simple: we document\n"
	.string "the POKéMON being displaced,\l"
	.string "and we give them somewhere\n"
	.string "to go.\p"
	.string "It's not much yet.\n"
	.string "But it grows with what we\l"
	.string "contribute.\p"
	.string "These four KRABBY will be\n"
	.string "the first.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_5:
# 95 "data/maps/FuchsiaCity/scripts.pory"
	.string "How do you know they'll stay?$"

FuchsiaCity_EventScript_FujiTurnIn_Text_6:
# 98 "data/maps/FuchsiaCity/scripts.pory"
	.string "They won't all stay.\n"
	.string "That's not the point.\p"
	.string "The point is to give them\n"
	.string "the choice.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_7:
# 103 "data/maps/FuchsiaCity/scripts.pory"
	.string "There's something happening at\n"
	.string "the fishing village on your\l"
	.string "way back.\p"
	.string "I've had reports for three\n"
	.string "days.\p"
	.string "I didn't want to say anything\n"
	.string "before you'd seen this first.\p"
	.string "Go back the way you came.\n"
	.string "You'll see it.$"

FuchsiaCity_EventScript_FujiTurnIn_Text_8:
# 115 "data/maps/FuchsiaCity/scripts.pory"
	.string "Finally.$"
