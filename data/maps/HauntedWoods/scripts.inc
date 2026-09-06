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
	msgbox HauntedWoods_Text_ScientistFlashlight, MSGBOX_DEFAULT
# 165 "data/maps/HauntedWoods/scripts.pory"
	closemessage
# 166 "data/maps/HauntedWoods/scripts.pory"
	release
	end


HauntedWoods_EventScript_FlashlightTrainer::
# 180 "data/maps/HauntedWoods/scripts.pory"
	trainerbattle_single TRAINER_CAMPER_2, HauntedWoods_Text_FlashlightTrainerIntro, HauntedWoods_Text_FlashlightTrainerDefeat
# 181 "data/maps/HauntedWoods/scripts.pory"
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

HauntedWoods_Text_ScientistFlashlight::
# 170 "data/maps/HauntedWoods/scripts.pory"
	.string "Phew! It's pitch-black out here...\p"
	.string "Good thing I fitted my torch with an\n"
	.string "amber lens filter.\p"
	.string "Standard white light scatters too much\n"
	.string "in this spectral mist, but this warm\l"
	.string "beam cuts right through it!$"

HauntedWoods_Text_FlashlightTrainerIntro::
# 185 "data/maps/HauntedWoods/scripts.pory"
	.string "Click!\n"
	.string "Caught you in my flashlight beam!$"

HauntedWoods_Text_FlashlightTrainerDefeat::
# 190 "data/maps/HauntedWoods/scripts.pory"
	.string "Aww! You blinded me with your skill!$"

HauntedWoods_Text_FlashlightTrainerPostBattle::
# 194 "data/maps/HauntedWoods/scripts.pory"
	.string "It's dangerous to explore the woods\n"
	.string "without a light.\p"
	.string "Keep your wits about you!$"
