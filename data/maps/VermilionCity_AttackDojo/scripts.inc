VermilionCity_AttackDojo_MapScripts::
# 12 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_AttackDojo_OnTransition
	.byte 0


VermilionCity_AttackDojo_OnTransition::
# 19 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
	end


VermilionCity_AttackDojo_EventScript_Sensei::
# 28 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	lock
# 29 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	faceplayer
# 30 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_set FLAG_ZONE_1_RESOLVED, VermilionCity_AttackDojo_EventScript_Sensei_2
# 51 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_Sensei_Text_1
# 55 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	closemessage
# 56 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
	end

VermilionCity_AttackDojo_EventScript_Sensei_2:
# 31 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_set FLAG_DOJO_VERMILION_BLACK_BELT, VermilionCity_AttackDojo_EventScript_Sensei_5
# 40 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_set FLAG_DOJO_VERMILION_BLUE_BELT, VermilionCity_AttackDojo_EventScript_Sensei_8
# 44 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_set FLAG_DOJO_VERMILION_WHITE_BELT, VermilionCity_AttackDojo_EventScript_Sensei_11
# 48 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto VermilionCity_AttackDojo_EventScript_OfferWhiteBelt
	end

VermilionCity_AttackDojo_EventScript_Sensei_5:
# 32 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_Sensei_Text_0
# 36 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	closemessage
# 37 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
	end

VermilionCity_AttackDojo_EventScript_Sensei_8:
# 41 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto VermilionCity_AttackDojo_EventScript_OfferBlackBelt
	end

VermilionCity_AttackDojo_EventScript_Sensei_11:
# 45 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto VermilionCity_AttackDojo_EventScript_OfferBlueBelt
	end


VermilionCity_AttackDojo_EventScript_OfferWhiteBelt::
# 65 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_Text_0, MSGBOX_YESNO
# 69 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_2
# 75 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto VermilionCity_AttackDojo_EventScript_WhiteBeltBattle
	end

VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_2:
# 70 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_Text_1
# 71 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	closemessage
# 72 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
	end


VermilionCity_AttackDojo_EventScript_OfferBlueBelt::
# 84 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_OfferBlueBelt_Text_0, MSGBOX_YESNO
# 90 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_AttackDojo_EventScript_OfferBlueBelt_2
# 96 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 97 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar 0x8008, 3
# 98 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar 0x800A, 3
# 99 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto VermilionCity_AttackDojo_EventScript_BlueBeltBattle
	end

VermilionCity_AttackDojo_EventScript_OfferBlueBelt_2:
# 91 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_Text_1
# 92 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	closemessage
# 93 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
	end


VermilionCity_AttackDojo_EventScript_OfferBlackBelt::
# 108 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_OfferBlackBelt_Text_0, MSGBOX_YESNO
# 116 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VermilionCity_AttackDojo_EventScript_OfferBlackBelt_2
# 122 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 123 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar 0x8008, 3
# 124 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar 0x800A, 3
# 125 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setflag FLAG_MONOTYPE_BATTLE
# 126 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_MONOTYPE_RESTRICTION, TYPE_FIGHTING
# 127 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 128 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
# 129 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto VermilionCity_AttackDojo_EventScript_BlackBeltBattle
	end

VermilionCity_AttackDojo_EventScript_OfferBlackBelt_2:
# 117 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_Text_1
# 118 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	closemessage
# 119 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
	end


VermilionCity_AttackDojo_EventScript_Tutor::
# 140 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	lock
# 141 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	faceplayer
# 142 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_set FLAG_DOJO_VERMILION_WHITE_BELT, VermilionCity_AttackDojo_EventScript_Tutor_2
# 149 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_Tutor_Text_1
# 151 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	closemessage
# 152 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
	end

VermilionCity_AttackDojo_EventScript_Tutor_2:
# 143 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox VermilionCity_AttackDojo_EventScript_Tutor_Text_0
# 145 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	closemessage
# 146 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto VermilionCity_AttackDojo_EventScript_TutorMenu
	end


# 156 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 157 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 158 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ WHITE BELT BATTLE
# 159 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ After winning: gotobeatenscript -> WhiteBeltDefeated (sets flag, shows text).
# 160 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ After losing:  CB2_WhiteOut (player blacks out; script does not continue).
# 161 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 162 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 163 "data/maps/VermilionCity_AttackDojo/scripts.pory"
VermilionCity_AttackDojo_EventScript_WhiteBeltBattle::
# 164 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	trainerbattle_single TRAINER_VERMILION_DOJO_WHITE, AttackDojo_Text_WhiteIntro, AttackDojo_Text_WhiteDefeat, VermilionCity_AttackDojo_EventScript_WhiteBeltDefeated
# 165 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 166 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 167 "data/maps/VermilionCity_AttackDojo/scripts.pory"
VermilionCity_AttackDojo_EventScript_WhiteBeltDefeated::
# 168 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setflag FLAG_DOJO_VERMILION_WHITE_BELT
# 169 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox AttackDojo_Text_WhiteWon, MSGBOX_AUTOCLOSE
# 170 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
# 171 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 172 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 173 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 174 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ BLUE BELT BATTLE
# 175 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ FLAG_PREVIEW_BATTLE is auto-cleared before the battle begins (in scrcmd.c).
# 176 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 177 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 178 "data/maps/VermilionCity_AttackDojo/scripts.pory"
VermilionCity_AttackDojo_EventScript_BlueBeltBattle::
# 179 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	trainerbattle_single TRAINER_VERMILION_DOJO_BLUE, AttackDojo_Text_BlueIntro, AttackDojo_Text_BlueDefeat, VermilionCity_AttackDojo_EventScript_BlueBeltDefeated
# 180 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 181 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 182 "data/maps/VermilionCity_AttackDojo/scripts.pory"
VermilionCity_AttackDojo_EventScript_BlueBeltDefeated::
# 183 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setflag FLAG_DOJO_VERMILION_BLUE_BELT
# 184 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox AttackDojo_Text_BlueWon, MSGBOX_AUTOCLOSE
# 185 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
# 186 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 187 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 188 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 189 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ BLACK BELT BATTLE
# 190 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ FLAG_MONOTYPE_BATTLE is auto-cleared by CB2_EndTrainerBattle.
# 191 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ FLAG_SCALE_BOSS_BATTLE is NOT auto-cleared — we clear it here (win case)
# 192 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ and in MAP_SCRIPT_ON_TRANSITION (loss/blackout case).
# 193 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 194 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 195 "data/maps/VermilionCity_AttackDojo/scripts.pory"
VermilionCity_AttackDojo_EventScript_BlackBeltBattle::
# 196 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	trainerbattle_single TRAINER_VERMILION_DOJO_BLACK, AttackDojo_Text_BlackIntro, AttackDojo_Text_BlackDefeat, VermilionCity_AttackDojo_EventScript_BlackBeltDefeated
# 197 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 198 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 199 "data/maps/VermilionCity_AttackDojo/scripts.pory"
VermilionCity_AttackDojo_EventScript_BlackBeltDefeated::
# 200 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 201 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setflag FLAG_DOJO_VERMILION_BLACK_BELT
# 202 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	giveitem ITEM_PROTEIN, 1
# 203 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox AttackDojo_Text_BlackWon, MSGBOX_AUTOCLOSE
# 204 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
# 205 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 206 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 207 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 208 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ MOVE TUTOR — dynamic menu
# 209 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@
# 210 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ DojoTutor_PushMoveIfFlagSet reads:
# 211 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@   VAR_0x8004 = move constant to push into the menu
# 212 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@   VAR_0x8005 = belt flag; pushes the move only if this flag is SET
# 213 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@
# 214 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ DojoTutor_PrepareMenu appends "Cancel" (id=0xFFFF) and sets VAR_RESULT to
# 215 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@   0    — menu is ready to show
# 216 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@   0xFE — stack was empty (no belts earned)
# 217 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@
# 218 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ _dynmultichoice stores the selected item's id in VAR_RESULT.
# 219 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ Cancel id = 0xFFFF. Move ids = MOVE_* constants.
# 220 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@
# 221 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ buffermovename STR_VAR_1, MOVE_X fills {BUFFER_1} with the move name so
# 222 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ the shared wantTeachingMsg can display it without hardcoding.
# 223 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 224 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 225 "data/maps/VermilionCity_AttackDojo/scripts.pory"
VermilionCity_AttackDojo_EventScript_TutorMenu::
# 226 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_ResetStack
# 227 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	@ White Belt moves (pushed when FLAG_DOJO_VERMILION_WHITE_BELT is set)
# 228 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8004, MOVE_POWER_UP_PUNCH
# 229 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8005, FLAG_DOJO_VERMILION_WHITE_BELT
# 230 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_PushMoveIfFlagSet
# 231 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8004, MOVE_AERIAL_ACE
# 232 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_PushMoveIfFlagSet
# 233 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	@ Blue Belt moves
# 234 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8004, MOVE_BRICK_BREAK
# 235 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8005, FLAG_DOJO_VERMILION_BLUE_BELT
# 236 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_PushMoveIfFlagSet
# 237 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8004, MOVE_ROCK_SLIDE
# 238 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_PushMoveIfFlagSet
# 239 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	@ Black Belt moves
# 240 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8004, MOVE_CLOSE_COMBAT
# 241 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8005, FLAG_DOJO_VERMILION_BLACK_BELT
# 242 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_PushMoveIfFlagSet
# 243 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	setvar VAR_0x8004, MOVE_EARTHQUAKE
# 244 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_PushMoveIfFlagSet
# 245 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	@ Finalize: adds "Cancel" item and checks if stack is non-empty
# 246 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	callnative DojoTutor_PrepareMenu
# 247 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, 0xFE, AttackDojo_EventScript_TutorNoBelts
# 248 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	@ Show the dynamic menu (ignoreBPress=TRUE: must use "Cancel" option)
# 249 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	_dynmultichoice 0, 0, TRUE, 5, FALSE, 0, NULL
# 250 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	@ Dispatch on the selected move id
# 251 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, 0xFFFF, AttackDojo_EventScript_TutorDone
# 252 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, MOVE_POWER_UP_PUNCH, AttackDojo_EventScript_TeachPowerUpPunch
# 253 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, MOVE_AERIAL_ACE, AttackDojo_EventScript_TeachAerialAce
# 254 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, MOVE_BRICK_BREAK, AttackDojo_EventScript_TeachBrickBreak
# 255 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, MOVE_ROCK_SLIDE, AttackDojo_EventScript_TeachRockSlide
# 256 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, MOVE_CLOSE_COMBAT, AttackDojo_EventScript_TeachCloseCombat
# 257 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto_if_eq VAR_RESULT, MOVE_EARTHQUAKE, AttackDojo_EventScript_TeachEarthquake
# 258 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	@ Fallthrough: unknown result — close cleanly
# 259 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	goto AttackDojo_EventScript_TutorDone
# 260 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 261 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TutorNoBelts::
# 262 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox AttackDojo_Text_TutorNoBelts, MSGBOX_AUTOCLOSE
# 263 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
# 264 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 265 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 266 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TutorDone::
# 267 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
# 268 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 269 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 270 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ── move_tutor dispatch ──────────────────────────────────────────────────────
# 271 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ buffermovename fills BUFFER_1 with the move name for use in shared texts.
# 272 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ move_tutor checks the flagId; if already set, jumps directly to TutorTaught
# 273 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ (shows "already learned" behavior). On success sets the flag.
# 274 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 275 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TeachPowerUpPunch::
# 276 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	buffermovename STR_VAR_1, MOVE_POWER_UP_PUNCH
# 277 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	move_tutor MOVE_POWER_UP_PUNCH, AttackDojo_Text_WouldLike, AttackDojo_Text_ForWhich, AttackDojo_EventScript_TutorDeclined, AttackDojo_EventScript_TutorTaught, FLAG_TUTOR_POWER_UP_PUNCH
# 278 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 279 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 280 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TeachAerialAce::
# 281 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	buffermovename STR_VAR_1, MOVE_AERIAL_ACE
# 282 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	move_tutor MOVE_AERIAL_ACE, AttackDojo_Text_WouldLike, AttackDojo_Text_ForWhich, AttackDojo_EventScript_TutorDeclined, AttackDojo_EventScript_TutorTaught, FLAG_TUTOR_AERIAL_ACE
# 283 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 284 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 285 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TeachBrickBreak::
# 286 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	buffermovename STR_VAR_1, MOVE_BRICK_BREAK
# 287 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	move_tutor MOVE_BRICK_BREAK, AttackDojo_Text_WouldLike, AttackDojo_Text_ForWhich, AttackDojo_EventScript_TutorDeclined, AttackDojo_EventScript_TutorTaught, FLAG_TUTOR_BRICK_BREAK
# 288 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 289 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 290 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TeachRockSlide::
# 291 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	buffermovename STR_VAR_1, MOVE_ROCK_SLIDE
# 292 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	move_tutor MOVE_ROCK_SLIDE, AttackDojo_Text_WouldLike, AttackDojo_Text_ForWhich, AttackDojo_EventScript_TutorDeclined, AttackDojo_EventScript_TutorTaught, FLAG_TUTOR_ROCK_SLIDE
# 293 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 294 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 295 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TeachCloseCombat::
# 296 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	buffermovename STR_VAR_1, MOVE_CLOSE_COMBAT
# 297 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	move_tutor MOVE_CLOSE_COMBAT, AttackDojo_Text_WouldLike, AttackDojo_Text_ForWhich, AttackDojo_EventScript_TutorDeclined, AttackDojo_EventScript_TutorTaught, FLAG_TUTOR_CLOSE_COMBAT
# 298 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 299 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 300 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TeachEarthquake::
# 301 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	buffermovename STR_VAR_1, MOVE_EARTHQUAKE
# 302 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	move_tutor MOVE_EARTHQUAKE, AttackDojo_Text_WouldLike, AttackDojo_Text_ForWhich, AttackDojo_EventScript_TutorDeclined, AttackDojo_EventScript_TutorTaught, FLAG_TUTOR_EARTHQUAKE
# 303 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 304 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 305 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TutorDeclined::
# 306 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox AttackDojo_Text_TutorDeclined, MSGBOX_AUTOCLOSE
# 307 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
# 308 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 309 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 310 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_EventScript_TutorTaught::
# 311 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	msgbox AttackDojo_Text_TutorTaught, MSGBOX_AUTOCLOSE
# 312 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	release
# 313 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	end
# 314 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 315 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 316 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ TEXT
# 317 "data/maps/VermilionCity_AttackDojo/scripts.pory"
@ ============================================================================
# 318 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 319 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_WhiteIntro:
# 320 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "White Belt.\n"
# 321 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Come at me clean.$"
# 322 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 323 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_WhiteDefeat:
# 324 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Solid.$"
# 325 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 326 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_WhiteWon:
# 327 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Good.\n"
# 328 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "That's the foundation.\p"
# 329 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Power-Up Punch and Aerial Ace\n"
# 330 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "are now available\l"
# 331 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "from my Tutor.\p"
# 332 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Come back when you're ready\n"
# 333 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "for Blue.$"
# 334 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 335 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_BlueIntro:
# 336 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "You saw my team.\n"
# 337 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "I saw yours.\p"
# 338 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "No excuses.$"
# 339 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 340 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_BlueDefeat:
# 341 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "You read it right.$"
# 342 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 343 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_BlueWon:
# 344 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "You planned well.\p"
# 345 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Brick Break and Rock Slide\n"
# 346 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "are now unlocked.\p"
# 347 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Come back when you're ready\n"
# 348 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "for Black.$"
# 349 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 350 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_BlackIntro:
# 351 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Fighting types only.\p"
# 352 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "I know what you can do.\n"
# 353 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Don't hold anything back.$"
# 354 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 355 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_BlackDefeat:
# 356 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "That's what I was\n"
# 357 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "waiting for.$"
# 358 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 359 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_BlackWon:
# 360 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "You used what you had\n"
# 361 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "and made it work.\p"
# 362 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Close Combat and Earthquake\n"
# 363 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "are now unlocked.\p"
# 364 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "The Black Belt is yours.$"
# 365 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 366 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_TutorNoBelts:
# 367 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Earn a belt first.$"
# 368 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 369 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_WouldLike:
# 370 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Shall I teach\n"
# 371 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "{STR_VAR_1} to your POKeMON?$"
# 372 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 373 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_ForWhich:
# 374 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Which POKeMON should\n"
# 375 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "learn {STR_VAR_1}?$"
# 376 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 377 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_TutorDeclined:
# 378 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Come back when you've\n"
# 379 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "made up your mind.$"
# 380 "data/maps/VermilionCity_AttackDojo/scripts.pory"

# 381 "data/maps/VermilionCity_AttackDojo/scripts.pory"
AttackDojo_Text_TutorTaught:
# 382 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "That's it.\n"
# 383 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Make the most of it.$"

VermilionCity_AttackDojo_EventScript_Sensei_Text_0:
# 32 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "You've earned everything I\n"
	.string "have to give.\p"
	.string "Come back any time.\n"
	.string "The door is open.$"

VermilionCity_AttackDojo_EventScript_Sensei_Text_1:
# 51 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "The coast is still unsettled.\p"
	.string "Come back when the situation\n"
	.string "around Zone 1 has resolved.\p"
	.string "The Dojo will still be here.$"

VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_Text_0:
# 65 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "White Belt.\n"
	.string "Standard. No conditions.\p"
	.string "Show me your basics.\p"
	.string "Are you ready?$"

VermilionCity_AttackDojo_EventScript_OfferWhiteBelt_Text_1:
# 70 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Come back when you're ready.$"

VermilionCity_AttackDojo_EventScript_OfferBlueBelt_Text_0:
# 84 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Blue Belt.\p"
	.string "You'll see my team.\n"
	.string "I'll see yours.\p"
	.string "We each pick three.\n"
	.string "No surprises.\p"
	.string "Are you ready?$"

VermilionCity_AttackDojo_EventScript_OfferBlackBelt_Text_0:
# 108 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Black Belt.\p"
	.string "Fighting types only,\n"
	.string "on your side.\p"
	.string "Team preview. We each pick\n"
	.string "three. And I will be above\l"
	.string "your level.\p"
	.string "That is deliberate.\p"
	.string "Are you ready?$"

VermilionCity_AttackDojo_EventScript_Tutor_Text_0:
# 143 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Which move would you like\n"
	.string "to learn?$"

VermilionCity_AttackDojo_EventScript_Tutor_Text_1:
# 149 "data/maps/VermilionCity_AttackDojo/scripts.pory"
	.string "Earn a belt first.\n"
	.string "The Sensei is over there.$"
