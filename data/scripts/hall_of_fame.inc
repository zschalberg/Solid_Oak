EventScript_SetDefeatedEliteFourFlagsVars::
	clearflag FLAG_0x09D
	call EventScript_ResetEliteFour
	special Script_UpdateTrainerFanClubGameClear
	specialvar VAR_0x800D, IsNationalPokedexEnabled
	call_if_eq VAR_0x800D, FALSE, EventScript_SetReadyTryGiveNationalDexScene
	call EventScript_ResetLegendaries
	return

EventScript_SetReadyTryGiveNationalDexScene::
	setvar VAR_0x4050, 2
	return

EventScript_ResetLegendaries::
	clearflag FLAG_0x2F5
	clearflag FLAG_0x2F6
	clearflag FLAG_0x2F7
	return

EventScript_ResetEliteFourEnd::
	call EventScript_ResetEliteFour
	end

EventScript_ResetEliteFour::
	clearflag FLAG_0x4B8
	clearflag FLAG_0x4B9
	clearflag FLAG_0x4BA
	clearflag FLAG_0x4BB
	clearflag FLAG_0x4BC
	cleartrainerflag TRAINER_CHAMPION_FIRST_SQUIRTLE
	cleartrainerflag TRAINER_CHAMPION_FIRST_BULBASAUR
	cleartrainerflag TRAINER_CHAMPION_FIRST_CHARMANDER
	cleartrainerflag TRAINER_CHAMPION_REMATCH_SQUIRTLE
	cleartrainerflag TRAINER_CHAMPION_REMATCH_BULBASAUR
	cleartrainerflag TRAINER_CHAMPION_REMATCH_CHARMANDER
	setvar VAR_0x4068, 0
	return
