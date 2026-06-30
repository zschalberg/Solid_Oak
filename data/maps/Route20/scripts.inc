Route20_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route20_OnTransition
	.byte 0

Route20_OnTransition::
	call_if_unset FLAG_0x2D2, Route20_EventScript_ResetSeafoamBouldersForB3F
	call_if_unset FLAG_0x2D3, Route20_EventScript_ResetSeafoamBouldersForB4F
	end

Route20_EventScript_ResetSeafoamBouldersForB3F::
	clearflag FLAG_0x040
	clearflag FLAG_0x041
	setflag FLAG_0x042
	setflag FLAG_0x043
	setflag FLAG_0x044
	setflag FLAG_0x045
	setflag FLAG_0x046
	setflag FLAG_0x047
	return

Route20_EventScript_ResetSeafoamBouldersForB4F::
	clearflag FLAG_0x048
	clearflag FLAG_0x049
	clearflag FLAG_0x04A
	clearflag FLAG_0x04B
	setflag FLAG_0x04C
	setflag FLAG_0x04D
	return

Route20_EventScript_SeafoamIslandsSign::
	msgbox Route20_Text_SeafoamIslands, MSGBOX_SIGN
	end
