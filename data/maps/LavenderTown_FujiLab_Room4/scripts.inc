LavenderTown_FujiLab_Room4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_FujiLab_Room4_OnTransition
	.byte 0

LavenderTown_FujiLab_Room4_OnTransition:
	setvar VAR_0x8004, 3
	special FujiLab_InitRoomObjects
	end
