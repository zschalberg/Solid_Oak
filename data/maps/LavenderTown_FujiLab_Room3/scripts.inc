LavenderTown_FujiLab_Room3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_FujiLab_Room3_OnTransition
	.byte 0

LavenderTown_FujiLab_Room3_OnTransition:
	setvar VAR_0x8004, 2
	special FujiLab_InitRoomObjects
	end
