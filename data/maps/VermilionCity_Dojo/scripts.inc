VermilionCity_Dojo_MapScripts::
# 9 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Dojo_OnTransition
	.byte 0


VermilionCity_Dojo_OnTransition::
# 16 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
	end


VermilionCity_Dojo_EventScript_TmBall::
# 22 "data/maps/VermilionCity_Dojo/scripts.pory"
	finditem ITEM_TM08
# 23 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_ITEM_VERMILION_DOJO_TM
	end


VermilionCity_Dojo_EventScript_Ryu::
# 32 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat
# 33 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_RyuPost, MSGBOX_AUTOCLOSE
	end


VermilionCity_Dojo_EventScript_Yuki::
# 42 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat
# 43 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_YukiPost, MSGBOX_AUTOCLOSE
	end


VermilionCity_Dojo_EventScript_Jin::
# 52 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat
# 53 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_JinPost, MSGBOX_AUTOCLOSE
	end


VermilionCity_Dojo_EventScript_Akio::
# 62 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 63 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 64 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_DEFEATED, VermilionCity_Dojo_EventScript_Akio_2
VermilionCity_Dojo_EventScript_Akio_1:
# 67 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioFirstDefeat
# 68 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Dojo_EventScript_Akio_2:
# 65 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto VermilionCity_Dojo_EventScript_AkioIdle
	goto VermilionCity_Dojo_EventScript_Akio_1


VermilionCity_Dojo_EventScript_AkioFirstDefeat::
# 73 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_DEFEATED
# 74 "data/maps/VermilionCity_Dojo/scripts.pory"
	giveitem ITEM_TM34, 1
# 75 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_AkioIdle::
# 80 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioIdle, MSGBOX_NPC
# 81 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Machop::
# 90 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 91 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 92 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 93 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Machop, MSGBOX_DEFAULT
# 94 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 95 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Mankey::
# 100 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 101 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 102 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
# 103 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Mankey, MSGBOX_DEFAULT
# 104 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 105 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Hitmonchan::
# 110 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 111 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 112 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_HITMONCHAN, CRY_MODE_NORMAL
# 113 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Hitmonchan, MSGBOX_DEFAULT
# 114 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 115 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
	end


VermilionCity_Dojo_EventScript_Plaque::
# 124 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Plaque, MSGBOX_SIGN
	end


VermilionCity_Dojo_EventScript_ScrollLeft::
# 129 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollLeft, MSGBOX_SIGN
	end


VermilionCity_Dojo_EventScript_ScrollRight::
# 134 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollRight, MSGBOX_SIGN
	end


VermilionCity_Dojo_Text_RyuIntro::
# 142 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Before you reach Sensei,\n"
	.string "you pass through me.\p"
	.string "Show me you belong here.$"

VermilionCity_Dojo_Text_RyuDefeat::
# 148 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You've got something in you.$"

VermilionCity_Dojo_Text_RyuPost::
# 152 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The next two fight differently.\n"
	.string "Pay attention to how they\l"
	.string "come at you.$"

VermilionCity_Dojo_Text_YukiIntro::
# 158 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "I always look before I commit.\p"
	.string "You'll see my whole team.\n"
	.string "I'll see yours.\p"
	.string "Then we decide.$"

VermilionCity_Dojo_Text_YukiDefeat::
# 165 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good picks. That's half\n"
	.string "the battle.$"

VermilionCity_Dojo_Text_YukiPost::
# 170 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Every match starts before\n"
	.string "the first move is made.$"

VermilionCity_Dojo_Text_JinIntro::
# 175 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Fifteen turns.\n"
	.string "That's all you get.\p"
	.string "If you can't close it by\n"
	.string "then, you weren't ready.$"

VermilionCity_Dojo_Text_JinDefeat::
# 182 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Quick and clean.\n"
	.string "You knew what to do.$"

VermilionCity_Dojo_Text_JinPost::
# 187 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Efficiency isn't speed.\n"
	.string "It's not wasting what\l"
	.string "you have.$"

VermilionCity_Dojo_Text_AkioIntro::
# 193 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "NORMAL types.\n"
	.string "Only NORMAL types.\p"
	.string "The most common things in\n"
	.string "this region.\p"
	.string "Show me you understand\n"
	.string "what you already have.$"

VermilionCity_Dojo_Text_AkioDefeat::
# 202 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good. You didn't overcomplicate\n"
	.string "it.$"

VermilionCity_Dojo_Text_AkioPostBattle::
# 207 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "A researcher who ignores\n"
	.string "common POKéMON misses\l"
	.string "half the picture.\p"
	.string "They're everywhere for a\n"
	.string "reason.\p"
	.string "These are for your fieldwork.$"

VermilionCity_Dojo_Text_AkioIdle::
# 216 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Come back when you've seen\n"
	.string "more of Kanto.$"

VermilionCity_Dojo_Text_Plaque::
# 221 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "AKIO'S DOJO\p"
	.string "Observation precedes action.\n"
	.string "Action precedes understanding.$"

VermilionCity_Dojo_Text_ScrollLeft::
# 227 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The untrained eye sees a\n"
	.string "common bird.\l"
	.string "The trained eye sees how\n"
	.string "it holds its wings.$"

VermilionCity_Dojo_Text_ScrollRight::
# 234 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "There is no weak POKéMON.\n"
	.string "There is only the trainer\l"
	.string "who stopped looking.$"

VermilionCity_Dojo_Text_Machop::
# 240 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MACHOP trains here every day.\n"
	.string "It hasn't missed one.$"

VermilionCity_Dojo_Text_Mankey::
# 245 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MANKEY gets worked up\n"
	.string "watching the sparring matches.$"

VermilionCity_Dojo_Text_Hitmonchan::
# 250 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The HITMONCHAN watches every\n"
	.string "match without blinking.\p"
	.string "It's seen every mistake you're\n"
	.string "about to make.$"
