LavenderTown_FujiLab_Room9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_FujiLab_Room9_OnTransition
	.byte 0

LavenderTown_FujiLab_Room9_OnTransition:
	setvar VAR_0x8004, 8
	special FujiLab_InitRoomObjects
	end
