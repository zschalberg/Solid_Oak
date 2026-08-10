Common_EventScript_DojoIntro::
# 6 "data/scripts/dojo_intro.pory"
	lockall
# 7 "data/scripts/dojo_intro.pory"
	msgbox Common_Text_DojoIntro1, MSGBOX_DEFAULT
# 8 "data/scripts/dojo_intro.pory"
	msgbox Common_Text_DojoIntro2, MSGBOX_DEFAULT
# 9 "data/scripts/dojo_intro.pory"
	msgbox Common_Text_DojoIntro3, MSGBOX_DEFAULT
# 10 "data/scripts/dojo_intro.pory"
	setflag FLAG_SEEN_DOJO_INTRO
# 11 "data/scripts/dojo_intro.pory"
	releaseall
	end


Common_Text_DojoIntro1::
# 15 "data/scripts/dojo_intro.pory"
	.string "Oh, a new face! Welcome to\n"
	.string "the DOJO.\p"
	.string "I'm the CHALLENGE GUY. Every\n"
	.string "DOJO like this one has someone\l"
	.string "like me posted near the door.$"

Common_Text_DojoIntro2::
# 23 "data/scripts/dojo_intro.pory"
	.string "Talk to me and I'll let you\n"
	.string "pick your challenge: WHITE,\l"
	.string "BLUE, or BLACK BELT.\p"
	.string "Clear every fighter at one\n"
	.string "belt before the next opens up.$"

Common_Text_DojoIntro3::
# 31 "data/scripts/dojo_intro.pory"
	.string "If you'd rather just spar,\n"
	.string "pick TRAINING instead. It'll\l"
	.string "match whatever belt you've\n"
	.string "already earned to your own\l"
	.string "level. Good practice, but it\n"
	.string "won't count toward anything.\p"
	.string "Go on, give it a shot!$"
