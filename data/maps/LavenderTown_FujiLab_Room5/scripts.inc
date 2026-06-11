LavenderTown_FujiLab_Room5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_FujiLab_Room5_OnTransition
	.byte 0

LavenderTown_FujiLab_Room5_OnTransition:
	setvar VAR_0x8004, 4
	special FujiLab_InitRoomObjects
	end
