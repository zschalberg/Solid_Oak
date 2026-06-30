EventScript_TestSignpostMsg::
	msgbox Test_Text_ThisIsASignpost, MSGBOX_SIGN
	end

Test_Text_ThisIsASignpost::
	.string "テストよう　メッセージです！\n"
	.string "かんばん　です$"

EventScript_TryGetTrainerScript::
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_0x800D, TRUE, EventScript_GotoTrainerScript
	releaseall
	end

EventScript_GotoTrainerScript::
	gotobeatenscript
	releaseall
	end

EventScript_ObjectApproachPlayer::
	lock
	special DoTrainerApproach
	waitstate
	gotonative LoadTrainerObjectScript
