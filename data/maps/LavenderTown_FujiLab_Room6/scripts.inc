LavenderTown_FujiLab_Room6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_FujiLab_Room6_OnTransition
	.byte 0

LavenderTown_FujiLab_Room6_OnTransition:
	setvar VAR_0x8004, 5
	special FujiLab_InitRoomObjects
	end
