NavelRock_Base_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Base_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Base_OnResume
	.byte 0

NavelRock_Base_OnTransition::
	call_if_set FLAG_0x2F2, NavelRock_Base_EventScript_HideLugia
	call_if_unset FLAG_0x2F2, NavelRock_Base_EventScript_TryShowLugia
	end

NavelRock_Base_EventScript_HideLugia::
	setflag FLAG_0x09B
	return

NavelRock_Base_EventScript_TryShowLugia::
	goto_if_set FLAG_0x2F5, EventScript_Return
	clearflag FLAG_0x09B
	return

NavelRock_Base_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, NavelRock_Base_EventScript_TryRemoveLugia
	end

NavelRock_Base_EventScript_TryRemoveLugia::
	specialvar VAR_0x800D, GetBattleOutcome
	goto_if_ne VAR_0x800D, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject LOCALID_NAVEL_ROCK_LUGIA
	return

NavelRock_Base_EventScript_Lugia::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	waitse
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 30
	delay 50
	waitse
	playmoncry SPECIES_LUGIA, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_LUGIA, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_0x800D, GetBattleOutcome
	goto_if_eq VAR_0x800D, B_OUTCOME_WON, NavelRock_Base_EventScript_DefeatedLugia
	goto_if_eq VAR_0x800D, B_OUTCOME_RAN, NavelRock_Base_EventScript_RanFromLugia
	goto_if_eq VAR_0x800D, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Base_EventScript_RanFromLugia
	setflag FLAG_0x2F2
	release
	end

NavelRock_Base_EventScript_DefeatedLugia::
	setflag FLAG_0x2F5
	setvar VAR_0x8004, SPECIES_LUGIA
	goto EventScript_MonFlewAway
	end

NavelRock_Base_EventScript_RanFromLugia::
	setvar VAR_0x8004, SPECIES_LUGIA
	goto EventScript_MonFlewAway
	end
