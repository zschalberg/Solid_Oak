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
# 162 "data/maps/HauntedWoods/scripts.pory"
	lock
# 163 "data/maps/HauntedWoods/scripts.pory"
	faceplayer
# 164 "data/maps/HauntedWoods/scripts.pory"
	checkitem ITEM_FLASHLIGHT, 1
# 165 "data/maps/HauntedWoods/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq HauntedWoods_EventScript_FlashlightScientist_3
HauntedWoods_EventScript_FlashlightScientist_1:
# 178 "data/maps/HauntedWoods/scripts.pory"
	message HauntedWoods_Text_ScientistTestPrompt
# 179 "data/maps/HauntedWoods/scripts.pory"
	waitmessage
# 180 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptKeepFlashlight, 0
# 181 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptToggleFlashlight, 1
# 182 "data/maps/HauntedWoods/scripts.pory"
	dynmultipush HauntedWoods_Text_OptGetEscapeRope, 2
# 183 "data/maps/HauntedWoods/scripts.pory"
	dynmultistack 0, 0, FALSE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 184 "data/maps/HauntedWoods/scripts.pory"
	switch VAR_RESULT
# 185 "data/maps/HauntedWoods/scripts.pory"
	case 1, HauntedWoods_EventScript_FlashlightScientist_8
# 187 "data/maps/HauntedWoods/scripts.pory"
	case 2, HauntedWoods_EventScript_FlashlightScientist_9
# 191 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistKeepFlashlight, MSGBOX_DEFAULT
HauntedWoods_EventScript_FlashlightScientist_6:
# 193 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 194 "data/maps/HauntedWoods/scripts.pory"
	release
	end

HauntedWoods_EventScript_FlashlightScientist_2:
# 166 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistIntroNoFlashlight, MSGBOX_DEFAULT
# 167 "data/maps/HauntedWoods/scripts.pory"
	giveitem ITEM_FLASHLIGHT, 1
# 168 "data/maps/HauntedWoods/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE, 1
# 169 "data/maps/HauntedWoods/scripts.pory"
	setflag FLAG_RECEIVED_FLASHLIGHT
# 170 "data/maps/HauntedWoods/scripts.pory"
	clearflag FLAG_FLASHLIGHT_DISABLED
# 171 "data/maps/HauntedWoods/scripts.pory"
	special Special_UpdateMapLightSources
# 172 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistGaveFlashlight, MSGBOX_DEFAULT
# 173 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 174 "data/maps/HauntedWoods/scripts.pory"
	release
	end

HauntedWoods_EventScript_FlashlightScientist_3:
# 165 "data/maps/HauntedWoods/scripts.pory"
	goto_if_unset FLAG_RECEIVED_FLASHLIGHT, HauntedWoods_EventScript_FlashlightScientist_2
	goto HauntedWoods_EventScript_FlashlightScientist_1

HauntedWoods_EventScript_FlashlightScientist_8:
# 186 "data/maps/HauntedWoods/scripts.pory"
	goto HauntedWoods_EventScript_ToggleFlashlightTesting
	goto HauntedWoods_EventScript_FlashlightScientist_6

HauntedWoods_EventScript_FlashlightScientist_9:
# 188 "data/maps/HauntedWoods/scripts.pory"
	giveitem ITEM_ESCAPE_ROPE, 1
# 189 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistGaveEscapeRope, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_FlashlightScientist_6


HauntedWoods_EventScript_ToggleFlashlightTesting::
# 199 "data/maps/HauntedWoods/scripts.pory"
	goto_if_set FLAG_FLASHLIGHT_DISABLED, HauntedWoods_EventScript_ToggleFlashlightTesting_2
# 204 "data/maps/HauntedWoods/scripts.pory"
	setflag FLAG_FLASHLIGHT_DISABLED
# 205 "data/maps/HauntedWoods/scripts.pory"
	special Special_UpdateMapLightSources
# 206 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistRemovedFlashlight, MSGBOX_DEFAULT
HauntedWoods_EventScript_ToggleFlashlightTesting_1:
# 208 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 209 "data/maps/HauntedWoods/scripts.pory"
	release
	end

HauntedWoods_EventScript_ToggleFlashlightTesting_2:
# 200 "data/maps/HauntedWoods/scripts.pory"
	clearflag FLAG_FLASHLIGHT_DISABLED
# 201 "data/maps/HauntedWoods/scripts.pory"
	special Special_UpdateMapLightSources
# 202 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_ScientistReturnedFlashlight, MSGBOX_DEFAULT
	goto HauntedWoods_EventScript_ToggleFlashlightTesting_1


HauntedWoods_EventScript_FlashlightTrainer::
# 280 "data/maps/HauntedWoods/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_2, HauntedWoods_Text_FlashlightTrainerIntro, HauntedWoods_Text_FlashlightTrainerDefeat
# 281 "data/maps/HauntedWoods/scripts.pory"
	msgbox HauntedWoods_Text_FlashlightTrainerPostBattle, MSGBOX_AUTOCLOSE
	end


HauntedWoods_Text_KeeperIntro::
# 85 "data/maps/HauntedWoods/scripts.pory"
	.string "I keep vigil over this spectral flame.\p"
	.string "Would you like to adjust its aura?$"

HauntedWoods_Text_OptToggleLight::
# 90 "data/maps/HauntedWoods/scripts.pory"
	.string "Toggle Light (On/Off)$"

HauntedWoods_Text_OptFlameSize::
# 94 "data/maps/HauntedWoods/scripts.pory"
	.string "Flame Size$"

HauntedWoods_Text_OptToggleMove::
# 98 "data/maps/HauntedWoods/scripts.pory"
	.string "Toggle 2x2 Movement$"

HauntedWoods_Text_OptExit::
# 102 "data/maps/HauntedWoods/scripts.pory"
	.string "Exit$"

HauntedWoods_Text_OptBack::
# 106 "data/maps/HauntedWoods/scripts.pory"
	.string "Back$"

HauntedWoods_Text_LightTurnedOn::
# 110 "data/maps/HauntedWoods/scripts.pory"
	.string "The spectral flame reignites with\n"
	.string "an eerie glow.$"

HauntedWoods_Text_LightTurnedOff::
# 115 "data/maps/HauntedWoods/scripts.pory"
	.string "The spectral flame has been\n"
	.string "extinguished.$"

HauntedWoods_Text_SelectSizePrompt::
# 120 "data/maps/HauntedWoods/scripts.pory"
	.string "Select the flame's intensity:$"

HauntedWoods_Text_OptSize50::
# 124 "data/maps/HauntedWoods/scripts.pory"
	.string "50% Size (Dim)$"

HauntedWoods_Text_OptSize100::
# 128 "data/maps/HauntedWoods/scripts.pory"
	.string "100% Size (Normal)$"

HauntedWoods_Text_OptSize150::
# 132 "data/maps/HauntedWoods/scripts.pory"
	.string "150% Size (Blazing)$"

HauntedWoods_Text_SizeSet50::
# 136 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame shrinks to a faint 50% glow.$"

HauntedWoods_Text_SizeSet100::
# 140 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame burns at its default 100%.$"

HauntedWoods_Text_SizeSet150::
# 144 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame blazes outwards to 150%!$"

HauntedWoods_Text_MoveStarted::
# 148 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame begins its 2x2 patrol.$"

HauntedWoods_Text_MoveStopped::
# 152 "data/maps/HauntedWoods/scripts.pory"
	.string "The flame returns to resting in place.$"

HauntedWoods_Text_KeeperFarewell::
# 156 "data/maps/HauntedWoods/scripts.pory"
	.string "May the flame light your passage\n"
	.string "through the dark.$"

HauntedWoods_Text_ScientistIntroNoFlashlight::
# 213 "data/maps/HauntedWoods/scripts.pory"
	.string "Phew! It's pitch-black out here...\p"
	.string "Good thing I fitted my torch with an\n"
	.string "amber lens filter.\p"
	.string "Standard white light scatters too much\n"
	.string "in this spectral mist, but this warm\l"
	.string "beam cuts right through it!\p"
	.string "Wait, you don't even have a flashlight?\n"
	.string "You won't be able to see a single step\l"
	.string "in these haunted woods!\p"
	.string "Here, take this spare Flashlight! And\n"
	.string "take an Escape Rope too, just in case\l"
	.string "you ever lose your bearings.$"

HauntedWoods_Text_ScientistGaveFlashlight::
# 228 "data/maps/HauntedWoods/scripts.pory"
	.string "Click! There you go!\n"
	.string "Your Flashlight is now shining bright.\p"
	.string "If the darkness ever overwhelms you,\n"
	.string "remember you can use your Escape Rope\l"
	.string "to warp safely back out!$"

HauntedWoods_Text_ScientistTestPrompt::
# 236 "data/maps/HauntedWoods/scripts.pory"
	.string "How is that Flashlight treating you?\p"
	.string "I'm running tests on visibility and light\n"
	.string "dispersion in this fog.\p"
	.string "Would you like to adjust your lighting\n"
	.string "for feature testing?$"

HauntedWoods_Text_OptKeepFlashlight::
# 244 "data/maps/HauntedWoods/scripts.pory"
	.string "Keep Flashlight$"

HauntedWoods_Text_OptToggleFlashlight::
# 248 "data/maps/HauntedWoods/scripts.pory"
	.string "Toggle Flashlight (On/Off)$"

HauntedWoods_Text_OptGetEscapeRope::
# 252 "data/maps/HauntedWoods/scripts.pory"
	.string "Extra Escape Rope$"

HauntedWoods_Text_ScientistKeepFlashlight::
# 256 "data/maps/HauntedWoods/scripts.pory"
	.string "Safe travels through the haunted mist!$"

HauntedWoods_Text_ScientistGaveEscapeRope::
# 260 "data/maps/HauntedWoods/scripts.pory"
	.string "Here's another Escape Rope!\n"
	.string "Always keep one handy in the dark.$"

HauntedWoods_Text_ScientistRemovedFlashlight::
# 265 "data/maps/HauntedWoods/scripts.pory"
	.string "Click!\n"
	.string "Flashlight returned and packed away.\p"
	.string "Notice how the woods return to complete\n"
	.string "pitch-black darkness?$"

HauntedWoods_Text_ScientistReturnedFlashlight::
# 272 "data/maps/HauntedWoods/scripts.pory"
	.string "Click!\n"
	.string "Flashlight switched back on!\p"
	.string "Your amber beam cuts right through\n"
	.string "the gloomy mist.$"

HauntedWoods_Text_FlashlightTrainerIntro::
# 285 "data/maps/HauntedWoods/scripts.pory"
	.string "Click!\n"
	.string "Caught you in my flashlight beam!$"

HauntedWoods_Text_FlashlightTrainerDefeat::
# 290 "data/maps/HauntedWoods/scripts.pory"
	.string "Aww! You blinded me with your skill!$"

HauntedWoods_Text_FlashlightTrainerPostBattle::
# 294 "data/maps/HauntedWoods/scripts.pory"
	.string "It's dangerous to explore the woods\n"
	.string "without a light.\p"
	.string "Keep your wits about you!$"
