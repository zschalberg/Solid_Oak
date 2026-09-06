@ Shared tail for every path that permanently removes a Pokemon and returns
@ its reusable ball to the bag (Oak's Lab and Reserve research turn-ins, the
@ Reserve Contest turn-in and specimen choice).
@
@ Those specials set VAR_0x8009 to TRUE when FreeMonBall could not put the
@ ball back because the Ball pocket was full. Protoballs and Research Balls
@ are a finite resource, so the player is told rather than losing one
@ silently - this mirrors the party menu's "release Research Ball" flow and
@ the PC's deposit/withdraw messages.
EventScript_WarnIfResearchBallLost::
	compare VAR_0x8009, TRUE
	goto_if_eq EventScript_ResearchBallLostBagFull
	return

EventScript_ResearchBallLostBagFull::
	msgbox Text_ResearchBallLostBagFull, MSGBOX_DEFAULT
	setvar VAR_0x8009, FALSE
	return

Text_ResearchBallLostBagFull:
	.string "There was no room in the Bag for the\n"
	.string "ball, so it couldn't be recovered!$"
