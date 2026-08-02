VermilionCity_Dojo_MapScripts::
# 2 "data/maps/VermilionCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Dojo_OnTransition
	.byte 0


# 5 "data/maps/VermilionCity_Dojo/scripts.pory"

# 6 "data/maps/VermilionCity_Dojo/scripts.pory"
@ Clear FLAG_SCALE_BOSS_BATTLE on every map entry as a safety net.
# 7 "data/maps/VermilionCity_Dojo/scripts.pory"
@ If the player loses the scaled Yuki rematch and blacks out, the flag
# 8 "data/maps/VermilionCity_Dojo/scripts.pory"
@ would otherwise persist until cleared here on re-entry.
# 9 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_OnTransition::
# 10 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 11 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 12 "data/maps/VermilionCity_Dojo/scripts.pory"

# 13 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_TmBall::
# 14 "data/maps/VermilionCity_Dojo/scripts.pory"
	finditem ITEM_TM08
# 15 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_ITEM_VERMILION_DOJO_TM
# 16 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 17 "data/maps/VermilionCity_Dojo/scripts.pory"

# 18 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 19 "data/maps/VermilionCity_Dojo/scripts.pory"
@ STUDENT RYU - Standard singles
# 20 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 21 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Ryu::
# 22 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_RYU, VermilionCity_Dojo_Text_RyuIntro, VermilionCity_Dojo_Text_RyuDefeat
# 23 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_RyuPost, MSGBOX_AUTOCLOSE
# 24 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 25 "data/maps/VermilionCity_Dojo/scripts.pory"

# 26 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 27 "data/maps/VermilionCity_Dojo/scripts.pory"
@ STUDENT YUKI - Preview battle, player picks 3 from party
# 28 "data/maps/VermilionCity_Dojo/scripts.pory"
@ Rematchable: her team scales to the player's best level + 5
# 29 "data/maps/VermilionCity_Dojo/scripts.pory"
@ every time, so she can be fought over and over for training.
# 30 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 31 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Yuki::
# 32 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_PREVIEW_BATTLE
# 33 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar 0x8008, 3
# 34 "data/maps/VermilionCity_Dojo/scripts.pory"
	cleartrainerflag TRAINER_LASS_YUKI_DOJO
# 35 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_SCALE_BOSS_BATTLE
# 36 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_SCALE_LEVEL_OFFSET, 5
# 37 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_LASS_YUKI_DOJO, VermilionCity_Dojo_Text_YukiIntro, VermilionCity_Dojo_Text_YukiDefeat
# 38 "data/maps/VermilionCity_Dojo/scripts.pory"
	clearflag FLAG_SCALE_BOSS_BATTLE
# 39 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_YukiPost, MSGBOX_AUTOCLOSE
# 40 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 41 "data/maps/VermilionCity_Dojo/scripts.pory"

# 42 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 43 "data/maps/VermilionCity_Dojo/scripts.pory"
@ STUDENT JIN - Turn limit battle (15 turns)
# 44 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 45 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Jin::
# 46 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_TURN_LIMIT_BATTLE
# 47 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_TURN_LIMIT, 15
# 48 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_JIN, VermilionCity_Dojo_Text_JinIntro, VermilionCity_Dojo_Text_JinDefeat
# 49 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_JinPost, MSGBOX_AUTOCLOSE
# 50 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 51 "data/maps/VermilionCity_Dojo/scripts.pory"

# 52 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 53 "data/maps/VermilionCity_Dojo/scripts.pory"
@ SENSEI AKIO - Monotype Normal restriction
# 54 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 55 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Akio::
# 56 "data/maps/VermilionCity_Dojo/scripts.pory"
	goto_if_set FLAG_DOJO_AKIO_DEFEATED, VermilionCity_Dojo_EventScript_AkioIdle
# 57 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_MONOTYPE_BATTLE
# 58 "data/maps/VermilionCity_Dojo/scripts.pory"
	setvar VAR_MONOTYPE_RESTRICTION, TYPE_NORMAL
# 59 "data/maps/VermilionCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_EXPERT_AKIO, VermilionCity_Dojo_Text_AkioIntro, VermilionCity_Dojo_Text_AkioDefeat, VermilionCity_Dojo_EventScript_AkioFirstDefeat
# 60 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioPostBattle, MSGBOX_AUTOCLOSE
# 61 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 62 "data/maps/VermilionCity_Dojo/scripts.pory"

# 63 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_AkioFirstDefeat::
# 64 "data/maps/VermilionCity_Dojo/scripts.pory"
	setflag FLAG_DOJO_AKIO_DEFEATED
# 65 "data/maps/VermilionCity_Dojo/scripts.pory"
	giveitem ITEM_TM34, 1
# 66 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
# 67 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 68 "data/maps/VermilionCity_Dojo/scripts.pory"

# 69 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_AkioIdle::
# 70 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 71 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 72 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_AkioIdle, MSGBOX_NPC
# 73 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
# 74 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 75 "data/maps/VermilionCity_Dojo/scripts.pory"

# 76 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 77 "data/maps/VermilionCity_Dojo/scripts.pory"
@ OVERWORLD POKéMON
# 78 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 79 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Machop::
# 80 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 81 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 82 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 83 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Machop, MSGBOX_DEFAULT
# 84 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 85 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
# 86 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 87 "data/maps/VermilionCity_Dojo/scripts.pory"

# 88 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Mankey::
# 89 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 90 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 91 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_MANKEY, CRY_MODE_NORMAL
# 92 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Mankey, MSGBOX_DEFAULT
# 93 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 94 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
# 95 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 96 "data/maps/VermilionCity_Dojo/scripts.pory"

# 97 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Hitmonchan::
# 98 "data/maps/VermilionCity_Dojo/scripts.pory"
	lock
# 99 "data/maps/VermilionCity_Dojo/scripts.pory"
	faceplayer
# 100 "data/maps/VermilionCity_Dojo/scripts.pory"
	playmoncry SPECIES_HITMONCHAN, CRY_MODE_NORMAL
# 101 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Hitmonchan, MSGBOX_DEFAULT
# 102 "data/maps/VermilionCity_Dojo/scripts.pory"
	waitmoncry
# 103 "data/maps/VermilionCity_Dojo/scripts.pory"
	release
# 104 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 105 "data/maps/VermilionCity_Dojo/scripts.pory"

# 106 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 107 "data/maps/VermilionCity_Dojo/scripts.pory"
@ SIGNS
# 108 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 109 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_Plaque::
# 110 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_Plaque, MSGBOX_SIGN
# 111 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 112 "data/maps/VermilionCity_Dojo/scripts.pory"

# 113 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_ScrollLeft::
# 114 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollLeft, MSGBOX_SIGN
# 115 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 116 "data/maps/VermilionCity_Dojo/scripts.pory"

# 117 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_EventScript_ScrollRight::
# 118 "data/maps/VermilionCity_Dojo/scripts.pory"
	msgbox VermilionCity_Dojo_Text_ScrollRight, MSGBOX_SIGN
# 119 "data/maps/VermilionCity_Dojo/scripts.pory"
	end
# 120 "data/maps/VermilionCity_Dojo/scripts.pory"

# 121 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 122 "data/maps/VermilionCity_Dojo/scripts.pory"
@ TEXT
# 123 "data/maps/VermilionCity_Dojo/scripts.pory"
@ ============================================================
# 124 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_RyuIntro:
# 125 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Before you reach Sensei,\n"
# 126 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "you pass through me.\p"
# 127 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Show me you belong here.$"
# 128 "data/maps/VermilionCity_Dojo/scripts.pory"

# 129 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_RyuDefeat:
# 130 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You've got something in you.$"
# 131 "data/maps/VermilionCity_Dojo/scripts.pory"

# 132 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_RyuPost:
# 133 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The next two fight differently.\n"
# 134 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Pay attention to how they\l"
# 135 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "come at you.$"
# 136 "data/maps/VermilionCity_Dojo/scripts.pory"

# 137 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_YukiIntro:
# 138 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "I always look before I commit.\p"
# 139 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You'll see my whole team.\n"
# 140 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "I'll see yours.\p"
# 141 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Then we decide.$"
# 142 "data/maps/VermilionCity_Dojo/scripts.pory"

# 143 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_YukiDefeat:
# 144 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good picks. That's half\n"
# 145 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "the battle.$"
# 146 "data/maps/VermilionCity_Dojo/scripts.pory"

# 147 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_YukiPost:
# 148 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Every match starts before\n"
# 149 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "the first move is made.$"
# 150 "data/maps/VermilionCity_Dojo/scripts.pory"

# 151 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_JinIntro:
# 152 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Fifteen turns.\n"
# 153 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "That's all you get.\p"
# 154 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "If you can't close it by\n"
# 155 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "then, you weren't ready.$"
# 156 "data/maps/VermilionCity_Dojo/scripts.pory"

# 157 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_JinDefeat:
# 158 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Quick and clean.\n"
# 159 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "You knew what to do.$"
# 160 "data/maps/VermilionCity_Dojo/scripts.pory"

# 161 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_JinPost:
# 162 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Efficiency isn't speed.\n"
# 163 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "It's not wasting what\l"
# 164 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "you have.$"
# 165 "data/maps/VermilionCity_Dojo/scripts.pory"

# 166 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioIntro:
# 167 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "NORMAL types.\n"
# 168 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Only NORMAL types.\p"
# 169 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The most common things in\n"
# 170 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "this region.\p"
# 171 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Show me you understand\n"
# 172 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "what you already have.$"
# 173 "data/maps/VermilionCity_Dojo/scripts.pory"

# 174 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioDefeat:
# 175 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Good. You didn't overcomplicate\n"
# 176 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "it.$"
# 177 "data/maps/VermilionCity_Dojo/scripts.pory"

# 178 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioPostBattle:
# 179 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "A researcher who ignores\n"
# 180 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "common POKéMON misses\l"
# 181 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "half the picture.\p"
# 182 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "They're everywhere for a\n"
# 183 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "reason.\p"
# 184 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "These are for your fieldwork.$"
# 185 "data/maps/VermilionCity_Dojo/scripts.pory"

# 186 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_AkioIdle:
# 187 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Come back when you've seen\n"
# 188 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "more of Kanto.$"
# 189 "data/maps/VermilionCity_Dojo/scripts.pory"

# 190 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_Plaque:
# 191 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "AKIO'S DOJO\p"
# 192 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Observation precedes action.\n"
# 193 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "Action precedes understanding.$"
# 194 "data/maps/VermilionCity_Dojo/scripts.pory"

# 195 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_ScrollLeft:
# 196 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The untrained eye sees a\n"
# 197 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "common bird.\l"
# 198 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The trained eye sees how\n"
# 199 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "it holds its wings.$"
# 200 "data/maps/VermilionCity_Dojo/scripts.pory"

# 201 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_ScrollRight:
# 202 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "There is no weak POKéMON.\n"
# 203 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "There is only the trainer\l"
# 204 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "who stopped looking.$"
# 205 "data/maps/VermilionCity_Dojo/scripts.pory"

# 206 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_Machop:
# 207 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MACHOP trains here every day.\n"
# 208 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "It hasn't missed one.$"
# 209 "data/maps/VermilionCity_Dojo/scripts.pory"

# 210 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_Mankey:
# 211 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The MANKEY gets worked up\n"
# 212 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "watching the sparring matches.$"
# 213 "data/maps/VermilionCity_Dojo/scripts.pory"

# 214 "data/maps/VermilionCity_Dojo/scripts.pory"
VermilionCity_Dojo_Text_Hitmonchan:
# 215 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "The HITMONCHAN watches every\n"
# 216 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "match without blinking.\p"
# 217 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "It's seen every mistake you're\n"
# 218 "data/maps/VermilionCity_Dojo/scripts.pory"
	.string "about to make.$"
