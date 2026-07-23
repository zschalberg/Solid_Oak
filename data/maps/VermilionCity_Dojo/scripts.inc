VermilionCity_Dojo_MapScripts::
	.byte 0


# 4 "data/maps/VermilionCity_Dojo/scripts.pory"

# 5 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_TmBall::
# 6 "data/maps/VermilionCity_Dojo/scripts.pory"
	finditem ITEM_TM08
# 7 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_ITEM_VERMILION_DOJO_TM
# 8 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 9 "data/maps/VermilionCity_Dojo/scripts.pory"

# 10 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 11 "data/maps/VermilionCity_Dojo/scripts.pory"
@ STUDENT RYU - Standard singles
# 12 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 13 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Ryu::
# 14 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat
# 15 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_RyuPost, MSGBOX_AUTOCLOSE
# 16 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 17 "data/maps/VermilionCity_Dojo/scripts.pory"

# 18 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 19 "data/maps/VermilionCity_Dojo/scripts.pory"
@ STUDENT YUKI - Preview battle, player picks 3 from party
# 20 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 21 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Yuki::
# 22 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 23 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 3
# 24 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat
# 25 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_YukiPost, MSGBOX_AUTOCLOSE
# 26 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 27 "data/maps/VermilionCity_Dojo/scripts.pory"

# 28 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 29 "data/maps/VermilionCity_Dojo/scripts.pory"
@ STUDENT JIN - Turn limit battle (15 turns)
# 30 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 31 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Jin::
# 32 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_TURN_LIMIT_BATTLE
# 33 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_TURN_LIMIT, 15
# 34 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat
# 35 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_JinPost, MSGBOX_AUTOCLOSE
# 36 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 37 "data/maps/VermilionCity_Dojo/scripts.pory"

# 38 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 39 "data/maps/VermilionCity_Dojo/scripts.pory"
@ SENSEI AKIO - Monotype Normal restriction
# 40 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 41 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Akio::
# 42 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_DEFEATED, VermilionCity_Dojo_EventScript_AkioIdle
# 43 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_MONOTYPE_BATTLE
# 44 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_MONOTYPE_RESTRICTION, TYPE_NORMAL
# 45 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioFirstDefeat
# 46 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioPostBattle, MSGBOX_AUTOCLOSE
# 47 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 48 "data/maps/VermilionCity_Dojo/scripts.pory"

# 49 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_AkioFirstDefeat::
# 50 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_DEFEATED
# 51 "data/maps/VermilionCity_Dojo/scripts.pory"
	giveitem ITEM_TM34, 1
# 52 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
# 53 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 54 "data/maps/VermilionCity_Dojo/scripts.pory"

# 55 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_AkioIdle::
# 56 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 57 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 58 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioIdle, MSGBOX_NPC
# 59 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
# 60 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 61 "data/maps/VermilionCity_Dojo/scripts.pory"

# 62 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 63 "data/maps/VermilionCity_Dojo/scripts.pory"
@ SIGNS
# 64 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 65 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Plaque::
# 66 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Plaque, MSGBOX_SIGN
# 67 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 68 "data/maps/VermilionCity_Dojo/scripts.pory"

# 69 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_ScrollLeft::
# 70 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollLeft, MSGBOX_SIGN
# 71 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 72 "data/maps/VermilionCity_Dojo/scripts.pory"

# 73 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_ScrollRight::
# 74 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollRight, MSGBOX_SIGN
# 75 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 76 "data/maps/VermilionCity_Dojo/scripts.pory"

# 77 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 78 "data/maps/VermilionCity_Dojo/scripts.pory"
@ TEXT
# 79 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 80 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_RyuIntro:
# 81 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Before you reach Sensei,\n"
# 82 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "you pass through me.\p"
# 83 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Show me you belong here.$"
# 84 "data/maps/VermilionCity_Dojo/scripts.pory"

# 85 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_RyuDefeat:
# 86 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You've got something in you.$"
# 87 "data/maps/VermilionCity_Dojo/scripts.pory"

# 88 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_RyuPost:
# 89 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The next two fight differently.\n"
# 90 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Pay attention to how they\l"
# 91 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "come at you.$"
# 92 "data/maps/VermilionCity_Dojo/scripts.pory"

# 93 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_YukiIntro:
# 94 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "I always look before I commit.\p"
# 95 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You'll see my whole team.\n"
# 96 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "I'll see yours.\p"
# 97 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Then we decide.$"
# 98 "data/maps/VermilionCity_Dojo/scripts.pory"

# 99 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_YukiDefeat:
# 100 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good picks. That's half\n"
# 101 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "the battle.$"
# 102 "data/maps/VermilionCity_Dojo/scripts.pory"

# 103 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_YukiPost:
# 104 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Every match starts before\n"
# 105 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "the first move is made.$"
# 106 "data/maps/VermilionCity_Dojo/scripts.pory"

# 107 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_JinIntro:
# 108 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Fifteen turns.\n"
# 109 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "That's all you get.\p"
# 110 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "If you can't close it by\n"
# 111 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "then, you weren't ready.$"
# 112 "data/maps/VermilionCity_Dojo/scripts.pory"

# 113 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_JinDefeat:
# 114 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Quick and clean.\n"
# 115 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You knew what to do.$"
# 116 "data/maps/VermilionCity_Dojo/scripts.pory"

# 117 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_JinPost:
# 118 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Efficiency isn't speed.\n"
# 119 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "It's not wasting what\l"
# 120 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "you have.$"
# 121 "data/maps/VermilionCity_Dojo/scripts.pory"

# 122 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioIntro:
# 123 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "NORMAL types.\n"
# 124 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Only NORMAL types.\p"
# 125 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The most common things in\n"
# 126 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "this region.\p"
# 127 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Show me you understand\n"
# 128 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "what you already have.$"
# 129 "data/maps/VermilionCity_Dojo/scripts.pory"

# 130 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioDefeat:
# 131 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good. You didn't overcomplicate\n"
# 132 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "it.$"
# 133 "data/maps/VermilionCity_Dojo/scripts.pory"

# 134 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioPostBattle:
# 135 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "A researcher who ignores\n"
# 136 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "common POKéMON misses\l"
# 137 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "half the picture.\p"
# 138 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "They're everywhere for a\n"
# 139 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "reason.\p"
# 140 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "These are for your fieldwork.$"
# 141 "data/maps/VermilionCity_Dojo/scripts.pory"

# 142 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioIdle:
# 143 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Come back when you've seen\n"
# 144 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "more of Kanto.$"
# 145 "data/maps/VermilionCity_Dojo/scripts.pory"

# 146 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_Plaque:
# 147 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "AKIO'S DOJO\p"
# 148 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Observation precedes action.\n"
# 149 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Action precedes understanding.$"
# 150 "data/maps/VermilionCity_Dojo/scripts.pory"

# 151 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_ScrollLeft:
# 152 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The untrained eye sees a\n"
# 153 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "common bird.\l"
# 154 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The trained eye sees how\n"
# 155 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "it holds its wings.$"
# 156 "data/maps/VermilionCity_Dojo/scripts.pory"

# 157 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_ScrollRight:
# 158 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "There is no weak POKéMON.\n"
# 159 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "There is only the trainer\l"
# 160 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "who stopped looking.$"
