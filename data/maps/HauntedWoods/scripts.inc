HauntedWoods_MapScripts::
	.byte 0


HauntedWoods_EventScript_FlameKeeper::
# 4 "data/maps/HauntedWoods/scripts.pory"
	lock
# 5 "data/maps/HauntedWoods/scripts.pory"
	faceplayer
# 6 "data/maps/HauntedWoods/scripts.pory"
	message HauntedWoods_Text_KeeperIntro
# 7 "data/maps/HauntedWoods/scripts.pory"
	waitmessage
# 8 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_KeeperMenu
	return


HauntedWoods_EventScript_KeeperMenu::
# 12 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptToggleLight, 0
# 13 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptFlameSize, 1
# 14 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptToggleMove, 2
# 15 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptExit, 3
# 16 "data/maps/HauntedWoods/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 17 "data/maps/HauntedWoods/scripts.pory"
	switch VAR_RESULT
# 18 "data/maps/HauntedWoods/scripts.pory"
	case 0, HauntedWoods_EventScript_KeeperMenu_2
# 20 "data/maps/HauntedWoods/scripts.pory"
	case 1, HauntedWoods_EventScript_KeeperMenu_3
# 22 "data/maps/HauntedWoods/scripts.pory"
	case 2, HauntedWoods_EventScript_KeeperMenu_4
# 25 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_KeeperExit
	return

HauntedWoods_EventScript_KeeperMenu_2:
# 19 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_ToggleLight
	return

HauntedWoods_EventScript_KeeperMenu_3:
# 21 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_SelectSize
	return

HauntedWoods_EventScript_KeeperMenu_4:
# 23 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_ToggleMove
	return


HauntedWoods_EventScript_ToggleLight::
# 30 "data/maps/HauntedWoods/scripts.pory"
	goto_if_set FLAG_HAUNTED_WOODS_LIGHT_DISABLED, HauntedWoods_EventScript_ToggleLight_2
# 34 "data/maps/HauntedWoods/scripts.pory"
	setflag FLAG_HAUNTED_WOODS_LIGHT_DISABLED
# 35 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_LightTurnedOff, MSGBOX_DEFAULT
HauntedWoods_EventScript_ToggleLight_1:
# 37 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 38 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_KeeperMenu
	return

HauntedWoods_EventScript_ToggleLight_2:
# 31 "data/maps/HauntedWoods/scripts.pory"
	clearflag FLAG_HAUNTED_WOODS_LIGHT_DISABLED
# 32 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_LightTurnedOn, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_ToggleLight_1


HauntedWoods_EventScript_SelectSize::
# 42 "data/maps/HauntedWoods/scripts.pory"
	message HauntedWoods_Text_SelectSizePrompt
# 43 "data/maps/HauntedWoods/scripts.pory"
	waitmessage
# 44 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptSize50, 0
# 45 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptSize100, 1
# 46 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptSize150, 2
# 47 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptBack, 3
# 48 "data/maps/HauntedWoods/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 49 "data/maps/HauntedWoods/scripts.pory"
	switch VAR_RESULT
# 50 "data/maps/HauntedWoods/scripts.pory"
	case 0, HauntedWoods_EventScript_SelectSize_3
# 53 "data/maps/HauntedWoods/scripts.pory"
	case 1, HauntedWoods_EventScript_SelectSize_4
# 56 "data/maps/HauntedWoods/scripts.pory"
	case 2, HauntedWoods_EventScript_SelectSize_5
# 60 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_KeeperMenu
HauntedWoods_EventScript_SelectSize_1:
# 62 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 63 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_KeeperMenu
	return

HauntedWoods_EventScript_SelectSize_3:
# 51 "data/maps/HauntedWoods/scripts.pory"
	setvar VAR_HAUNTED_WOODS_LIGHT_SIZE, 1
# 52 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_SizeSet50, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_SelectSize_1

HauntedWoods_EventScript_SelectSize_4:
# 54 "data/maps/HauntedWoods/scripts.pory"
	setvar VAR_HAUNTED_WOODS_LIGHT_SIZE, 0
# 55 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_SizeSet100, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_SelectSize_1

HauntedWoods_EventScript_SelectSize_5:
# 57 "data/maps/HauntedWoods/scripts.pory"
	setvar VAR_HAUNTED_WOODS_LIGHT_SIZE, 2
# 58 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_SizeSet150, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_SelectSize_1


HauntedWoods_EventScript_ToggleMove::
# 67 "data/maps/HauntedWoods/scripts.pory"
	goto_if_set FLAG_HAUNTED_WOODS_LIGHT_MOVE, HauntedWoods_EventScript_ToggleMove_2
# 71 "data/maps/HauntedWoods/scripts.pory"
	setflag FLAG_HAUNTED_WOODS_LIGHT_MOVE
# 72 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_MoveStarted, MSGBOX_DEFAULT
HauntedWoods_EventScript_ToggleMove_1:
# 74 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 75 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_KeeperMenu
	return

HauntedWoods_EventScript_ToggleMove_2:
# 68 "data/maps/HauntedWoods/scripts.pory"
	clearflag FLAG_HAUNTED_WOODS_LIGHT_MOVE
# 69 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_MoveStopped, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_ToggleMove_1


HauntedWoods_EventScript_KeeperExit::
# 79 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_KeeperFarewell, MSGBOX_DEFAULT
# 80 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 81 "data/maps/HauntedWoods/scripts.pory"
	release
	end


HauntedWoods_EventScript_FlashlightScientist::
# 165 "data/maps/HauntedWoods/scripts.pory"
	lock
# 166 "data/maps/HauntedWoods/scripts.pory"
	faceplayer
# 167 "data/maps/HauntedWoods/scripts.pory"
	checkitem ITEM_FLASHLIGHT, 1
# 168 "data/maps/HauntedWoods/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HauntedWoods_EventScript_FlashlightScientist_3
HauntedWoods_EventScript_FlashlightScientist_1:
# 181 "data/maps/HauntedWoods/scripts.pory"
	message HauntedWoods_Text_ScientistTestPrompt
# 182 "data/maps/HauntedWoods/scripts.pory"
	waitmessage
# 183 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptKeepFlashlight, 0
# 184 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptToggleFlashlight, 1
# 185 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptGetEscapeRope, 2
# 186 "data/maps/HauntedWoods/scripts.pory"
	dynmultistack 0, 0, FALSE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 187 "data/maps/HauntedWoods/scripts.pory"
	switch VAR_RESULT
# 188 "data/maps/HauntedWoods/scripts.pory"
	case 1, HauntedWoods_EventScript_FlashlightScientist_8
# 190 "data/maps/HauntedWoods/scripts.pory"
	case 2, HauntedWoods_EventScript_FlashlightScientist_9
# 194 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistKeepFlashlight, MSGBOX_DEFAULT
HauntedWoods_EventScript_FlashlightScientist_6:
# 196 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 197 "data/maps/HauntedWoods/scripts.pory"
	release
	end

HauntedWoods_EventScript_FlashlightScientist_2:
# 169 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistIntroNoFlashlight, MSGBOX_DEFAULT
# 170 "data/maps/HauntedWoods/scripts.pory"
	giveitem ITEM_FLASHLIGHT, 1
# 171 "data/maps/HauntedWoods/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE, 1
# 172 "data/maps/HauntedWoods/scripts.pory"
	setflag FLAG_RECEIVED_FLASHLIGHT
# 173 "data/maps/HauntedWoods/scripts.pory"
	clearflag FLAG_FLASHLIGHT_DISABLED
# 174 "data/maps/HauntedWoods/scripts.pory"
	special Special_UpdateMapLightSources
# 175 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistGaveFlashlight, MSGBOX_DEFAULT
# 176 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 177 "data/maps/HauntedWoods/scripts.pory"
	release
	end

HauntedWoods_EventScript_FlashlightScientist_3:
# 168 "data/maps/HauntedWoods/scripts.pory"
	goto_if_unset FLAG_RECEIVED_FLASHLIGHT, HauntedWoods_EventScript_FlashlightScientist_2
	goto HauntedWoods_EventScript_FlashlightScientist_1

HauntedWoods_EventScript_FlashlightScientist_8:
# 189 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_ToggleFlashlightTesting
	goto HauntedWoods_EventScript_FlashlightScientist_6

HauntedWoods_EventScript_FlashlightScientist_9:
# 191 "data/maps/HauntedWoods/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE, 1
# 192 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistGaveEscapeRope, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_FlashlightScientist_6


HauntedWoods_EventScript_ToggleFlashlightTesting::
# 202 "data/maps/HauntedWoods/scripts.pory"
	goto_if_set FLAG_FLASHLIGHT_DISABLED, HauntedWoods_EventScript_ToggleFlashlightTesting_2
# 207 "data/maps/HauntedWoods/scripts.pory"
	setflag FLAG_FLASHLIGHT_DISABLED
# 208 "data/maps/HauntedWoods/scripts.pory"
	special Special_UpdateMapLightSources
# 209 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistRemovedFlashlight, MSGBOX_DEFAULT
HauntedWoods_EventScript_ToggleFlashlightTesting_1:
# 211 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 212 "data/maps/HauntedWoods/scripts.pory"
	release
	end

HauntedWoods_EventScript_ToggleFlashlightTesting_2:
# 203 "data/maps/HauntedWoods/scripts.pory"
	clearflag FLAG_FLASHLIGHT_DISABLED
# 204 "data/maps/HauntedWoods/scripts.pory"
	special Special_UpdateMapLightSources
# 205 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistReturnedFlashlight, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_ToggleFlashlightTesting_1


HauntedWoods_EventScript_FlashlightTrainer::
# 285 "data/maps/HauntedWoods/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_2, HauntedWoods_Text_FlashlightTrainerIntro, HauntedWoods_Text_FlashlightTrainerDefeat
# 286 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_FlashlightTrainerPostBattle, MSGBOX_AUTOCLOSE
	end


HauntedWoods_Text_KeeperIntro::
# 85 "data/maps/HauntedWoods/scripts.pory"
	.string "I keep vigil over this spectral\n"
	.string "flame.\p"
	.string "Would you like to adjust its aura?$"

HauntedWoods_Text_OptToggleLight::
# 91 "data/maps/HauntedWoods/scripts.pory"
	.string "Toggle Light (On/Off)$"

HauntedWoods_Text_OptFlameSize::
# 95 "data/maps/HauntedWoods/scripts.pory"
	.string "Flame Size$"

HauntedWoods_Text_OptToggleMove::
# 99 "data/maps/HauntedWoods/scripts.pory"
	.string "Toggle 2x2 Movement$"

HauntedWoods_Text_OptExit::
# 103 "data/maps/HauntedWoods/scripts.pory"
	.string "Exit$"

HauntedWoods_Text_OptBack::
# 107 "data/maps/HauntedWoods/scripts.pory"
	.string "Back$"

HauntedWoods_Text_LightTurnedOn::
# 111 "data/maps/HauntedWoods/scripts.pory"
	.string "The spectral flame reignites with\n"
	.string "an eerie glow.$"

HauntedWoods_Text_LightTurnedOff::
# 116 "data/maps/HauntedWoods/scripts.pory"
	.string "The spectral flame has been\n"
	.string "extinguished.$"

HauntedWoods_Text_SelectSizePrompt::
# 121 "data/maps/HauntedWoods/scripts.pory"
	.string "Select the flame's intensity:$"

HauntedWoods_Text_OptSize50::
# 125 "data/maps/HauntedWoods/scripts.pory"
	.string "50% Size (Dim)$"

HauntedWoods_Text_OptSize100::
# 129 "data/maps/HauntedWoods/scripts.pory"
	.string "100% Size (Normal)$"

HauntedWoods_Text_OptSize150::
# 133 "data/maps/HauntedWoods/scripts.pory"
	.string "150% Size (Blazing)$"

HauntedWoods_Text_SizeSet50::
# 137 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame shrinks to a faint\n"
	.string "50% glow.$"

HauntedWoods_Text_SizeSet100::
# 142 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame burns at its default 100%.$"

HauntedWoods_Text_SizeSet150::
# 146 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame blazes outwards to 150%!$"

HauntedWoods_Text_MoveStarted::
# 150 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame begins its 2x2 patrol.$"

HauntedWoods_Text_MoveStopped::
# 154 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame returns to resting\n"
	.string "in place.$"

HauntedWoods_Text_KeeperFarewell::
# 159 "data/maps/HauntedWoods/scripts.pory"
	.string "May the flame light your passage\n"
	.string "through the dark.$"

HauntedWoods_Text_ScientistIntroNoFlashlight::
# 216 "data/maps/HauntedWoods/scripts.pory"
	.string "Phew! It's pitch-black out here...\p"
	.string "Good thing I fitted my torch with an\n"
	.string "amber lens filter.\p"
	.string "Standard white light scatters too\n"
	.string "much in this spectral mist, but this\l"
	.string "warm beam cuts right through it!\p"
	.string "Wait, you don't even have a\n"
	.string "flashlight?\p"
	.string "You won't be able to see a single\n"
	.string "step in these haunted woods!\p"
	.string "Here, take this spare Flashlight!\n"
	.string "And take an Escape Rope too, just\l"
	.string "in case you ever lose your bearings.$"

HauntedWoods_Text_ScientistGaveFlashlight::
# 232 "data/maps/HauntedWoods/scripts.pory"
	.string "Click! There you go! Your\n"
	.string "Flashlight is now shining bright.\p"
	.string "If the darkness ever overwhelms you,\n"
	.string "remember you can use your Escape\l"
	.string "Rope to warp safely back out!$"

HauntedWoods_Text_ScientistTestPrompt::
# 240 "data/maps/HauntedWoods/scripts.pory"
	.string "How is that Flashlight treating you?\p"
	.string "I'm running tests on visibility and\n"
	.string "light dispersion in this fog.\p"
	.string "Would you like to adjust your\n"
	.string "lighting for feature testing?$"

HauntedWoods_Text_OptKeepFlashlight::
# 248 "data/maps/HauntedWoods/scripts.pory"
	.string "Keep Flashlight$"

HauntedWoods_Text_OptToggleFlashlight::
# 252 "data/maps/HauntedWoods/scripts.pory"
	.string "Toggle Flashlight (On/Off)$"

HauntedWoods_Text_OptGetEscapeRope::
# 256 "data/maps/HauntedWoods/scripts.pory"
	.string "Extra Escape Rope$"

HauntedWoods_Text_ScientistKeepFlashlight::
# 260 "data/maps/HauntedWoods/scripts.pory"
	.string "Safe travels through the\n"
	.string "haunted mist!$"

HauntedWoods_Text_ScientistGaveEscapeRope::
# 265 "data/maps/HauntedWoods/scripts.pory"
	.string "Here's another Escape Rope!\n"
	.string "Always keep one handy in the dark.$"

HauntedWoods_Text_ScientistRemovedFlashlight::
# 270 "data/maps/HauntedWoods/scripts.pory"
	.string "Click! Flashlight returned\n"
	.string "and packed away.\p"
	.string "Notice how the woods return to\n"
	.string "complete pitch-black darkness?$"

HauntedWoods_Text_ScientistReturnedFlashlight::
# 277 "data/maps/HauntedWoods/scripts.pory"
	.string "Click!\n"
	.string "Flashlight switched back on!\p"
	.string "Your amber beam cuts right through\n"
	.string "the gloomy mist.$"

HauntedWoods_Text_FlashlightTrainerIntro::
# 290 "data/maps/HauntedWoods/scripts.pory"
	.string "Click!\n"
	.string "Caught you in my flashlight beam!$"

HauntedWoods_Text_FlashlightTrainerDefeat::
# 295 "data/maps/HauntedWoods/scripts.pory"
	.string "Aww! You blinded me with your skill!$"

HauntedWoods_Text_FlashlightTrainerPostBattle::
# 299 "data/maps/HauntedWoods/scripts.pory"
	.string "It's dangerous to explore the woods\n"
	.string "without a light.\p"
	.string "Keep your wits about you!$"
