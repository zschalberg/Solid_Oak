EventScript_StartTrainerApproach::
	selectapproachingtrainer
	lockfortrainer
EventScript_TrainerApproach::
	special PlayTrainerEncounterMusic
	special DoTrainerApproach
	waitstate
	goto EventScript_ShowTrainerIntroMsg

EventScript_TryDoNormalTrainerBattle::
	lock
	faceplayer
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_0x800F, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	specialvar VAR_0x800D, GetTrainerFlag
	goto_if_ne VAR_0x800D, FALSE, EventScript_NoTrainerBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	goto EventScript_ShowTrainerIntroMsg

EventScript_NoTrainerBattle::
	gotopostbattlescript

EventScript_TryDoDoubleTrainerBattle::
	lock
	faceplayer
	call EventScript_RevealTrainer
	specialvar VAR_0x800D, GetTrainerFlag
	goto_if_ne VAR_0x800D, FALSE, EventScript_NoDoubleTrainerBattle
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_0x800D, PLAYER_HAS_TWO_USABLE_MONS, EventScript_NotEnoughMonsForDoubleBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	goto EventScript_ShowTrainerIntroMsg

EventScript_NotEnoughMonsForDoubleBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_NoDoubleTrainerBattle::
	gotopostbattlescript

EventScript_DoNoIntroTrainerBattle::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_0x800F, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	special PlayTrainerEncounterMusic
	goto_if_questlog EventScript_EndQuestLogBattle
	dotrainerbattle
	gotopostbattlescript

EventScript_TryDoRematchBattle::
	call EventScript_RevealTrainer
	specialvar VAR_0x800D, IsTrainerReadyForRematch
	goto_if_eq VAR_0x800D, FALSE, EventScript_NoRematchBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	goto_if_questlog EventScript_EndQuestLogRematch
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end

EventScript_NoRematchBattle::
	gotopostbattlescript

EventScript_TryDoDoubleRematchBattle::
	specialvar VAR_0x800D, IsTrainerReadyForRematch
	goto_if_eq VAR_0x800D, FALSE, EventScript_NoDoubleRematchBattle
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_0x800D, PLAYER_HAS_TWO_USABLE_MONS, EventScript_NotEnoughMonsForDoubleRematchBattle
	special PlayTrainerEncounterMusic
	special SetTrainerFacingDirection
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	goto_if_questlog EventScript_EndQuestLogRematch
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end

EventScript_NoDoubleRematchBattle::
	gotopostbattlescript

EventScript_NotEnoughMonsForDoubleRematchBattle::
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_EndQuestLogRematch::
	releaseall
	end

EventScript_RevealTrainer::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	applymovement VAR_0x800F, Movement_RevealTrainer
	waitmovement 0
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	return

Movement_RevealTrainer::
	reveal_trainer
	step_end

EventScript_ShowTrainerIntroMsg::
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special TryPrepareSecondApproachingTrainer
	goto_if_eq VAR_0x800D, TRUE, EventScript_TrainerApproach
	goto EventScript_DoTrainerBattle

EventScript_DoTrainerBattle::
	goto_if_questlog EventScript_EndQuestLogBattle
	dotrainerbattle
	specialvar VAR_0x800D, GetTrainerBattleMode
	goto_if_eq VAR_0x800D, TRAINER_BATTLE_SINGLE, EventScript_EndTrainerBattle
	goto_if_eq VAR_0x800D, TRAINER_BATTLE_CONTINUE_SCRIPT, EventScript_EndTrainerBattleContinueScript
	goto_if_eq VAR_0x800D, TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, EventScript_EndTrainerBattleContinueScript
	goto_if_eq VAR_0x800D, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE, EventScript_EndTrainerBattleContinueScript
	goto_if_eq VAR_0x800D, TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC, EventScript_EndTrainerBattleContinueScript
EventScript_EndTrainerBattle::
	releaseall
	end

EventScript_EndTrainerBattleContinueScript::
	gotobeatenscript

EventScript_EndQuestLogBattle::
	special SetBattledTrainerFlag
	releaseall
	end

Std_MsgboxAutoclose::
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return
