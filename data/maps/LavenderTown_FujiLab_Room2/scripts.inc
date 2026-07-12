LavenderTown_FujiLab_Room2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_FujiLab_Room2_OnTransition
	.byte 0

LavenderTown_FujiLab_Room2_OnTransition:
	setvar VAR_0x8004, 1
	special FujiLab_InitRoomObjects
	end
