PowerPlant_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PowerPlant_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, PowerPlant_OnTransition
	.byte 0

PowerPlant_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, PowerPlant_EventScript_TryRemoveStaticMon
	end

PowerPlant_EventScript_TryRemoveStaticMon::
	specialvar VAR_0x800D, GetBattleOutcome
	goto_if_ne VAR_0x800D, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_0x800F
	return

PowerPlant_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POWER_PLANT
	call_if_unset FLAG_0x2BF, PowerPlant_EventScript_ShowZapdos
	call_if_unset FLAG_0x2D0, PowerPlant_EventScript_ShowElectrode1
	call_if_unset FLAG_0x2D1, PowerPlant_EventScript_ShowElectrode2
	end

PowerPlant_EventScript_ShowZapdos::
	clearflag FLAG_0x05D
	return

PowerPlant_EventScript_ShowElectrode1::
	clearflag FLAG_0x085
	return

PowerPlant_EventScript_ShowElectrode2::
	clearflag FLAG_0x086
	return

PowerPlant_EventScript_Zapdos::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	setwildbattle SPECIES_ZAPDOS, 50
	waitse
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	message Text_Gyaoo
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_0x800D, GetBattleOutcome
	goto_if_eq VAR_0x800D, B_OUTCOME_WON, PowerPlant_EventScript_DefeatedZapdos
	goto_if_eq VAR_0x800D, B_OUTCOME_RAN, PowerPlant_EventScript_RanFromZapdos
	goto_if_eq VAR_0x800D, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_RanFromZapdos
	setflag FLAG_0x2BF
	release
	end

PowerPlant_EventScript_DefeatedZapdos::
	setflag FLAG_0x2BF
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_RanFromZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto EventScript_MonFlewAway
	end

PowerPlant_EventScript_Electrode1::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special QuestLog_CutRecording
	specialvar VAR_0x800D, GetBattleOutcome
	goto_if_eq VAR_0x800D, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_0x800D, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode1
	goto_if_eq VAR_0x800D, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode1
	setflag FLAG_0x2D0
	release
	end

PowerPlant_EventScript_FoughtElectrode1::
	setflag FLAG_0x2D0
	goto EventScript_RemoveStaticMon
	end

PowerPlant_EventScript_Electrode2::
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 34
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special QuestLog_CutRecording
	specialvar VAR_0x800D, GetBattleOutcome
	goto_if_eq VAR_0x800D, B_OUTCOME_WON, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_0x800D, B_OUTCOME_RAN, PowerPlant_EventScript_FoughtElectrode2
	goto_if_eq VAR_0x800D, B_OUTCOME_PLAYER_TELEPORTED, PowerPlant_EventScript_FoughtElectrode2
	setflag FLAG_0x2D1
	release
	end

PowerPlant_EventScript_FoughtElectrode2::
	setflag FLAG_0x2D1
	goto EventScript_RemoveStaticMon
	end
