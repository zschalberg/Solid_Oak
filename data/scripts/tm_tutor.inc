Common_EventScript_TMTutor::
# 2 "data/scripts/tm_tutor.pory"
	lock
# 3 "data/scripts/tm_tutor.pory"
	faceplayer
# 4 "data/scripts/tm_tutor.pory"
	msgbox Common_Text_TMTutorWelcome, MSGBOX_YESNO
# 5 "data/scripts/tm_tutor.pory"
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_TMTutor_2
# 10 "data/scripts/tm_tutor.pory"
	special ChooseTMFromCase
# 11 "data/scripts/tm_tutor.pory"
	waitstate
# 12 "data/scripts/tm_tutor.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_TMTutor_5
# 17 "data/scripts/tm_tutor.pory"
	msgbox Common_Text_TMTutorTaught
# 18 "data/scripts/tm_tutor.pory"
	release
	end

Common_EventScript_TMTutor_2:
# 6 "data/scripts/tm_tutor.pory"
	msgbox Common_Text_TMTutorDeclined
# 7 "data/scripts/tm_tutor.pory"
	release
	end

Common_EventScript_TMTutor_5:
# 13 "data/scripts/tm_tutor.pory"
	msgbox Common_Text_TMTutorDeclined
# 14 "data/scripts/tm_tutor.pory"
	release
	end


Common_Text_TMTutorWelcome::
# 22 "data/scripts/tm_tutor.pory"
	.string "Welcome to the Dojo!\p"
	.string "I can teach your POKéMON any TM move\n"
	.string "that you carry in your TM CASE.\p"
	.string "Would you like me to teach a move?$"

Common_Text_TMTutorDeclined::
# 29 "data/scripts/tm_tutor.pory"
	.string "Come back whenever you wish to train!$"

Common_Text_TMTutorTaught::
# 33 "data/scripts/tm_tutor.pory"
	.string "Your POKéMON has mastered the move!$"
