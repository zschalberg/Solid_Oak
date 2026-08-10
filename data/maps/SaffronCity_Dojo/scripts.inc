SaffronCity_Dojo_MapScripts::
# 4 "data/maps/SaffronCity_Dojo/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SaffronCity_Dojo_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/SaffronCity_Dojo/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SaffronCity_Dojo_OnFrame
	.2byte 0


SaffronCity_Dojo_OnFrame::
# 14 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_0, 1
# 15 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_unset FLAG_SEEN_DOJO_INTRO, SaffronCity_Dojo_OnFrame_2
SaffronCity_Dojo_OnFrame_1:
	end

SaffronCity_Dojo_OnFrame_2:
# 16 "data/maps/SaffronCity_Dojo/scripts.pory"
	call Common_EventScript_DojoIntro
	goto SaffronCity_Dojo_OnFrame_1


SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
# 22 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 23 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 24 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterLeft
# 25 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 26 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
	end


SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
# 31 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 32 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 33 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterRight
# 34 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 35 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
	end


SaffronCity_Dojo_EventScript_HitmonleeBall::
# 40 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 41 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 42 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_HitmonleeBall_2
SaffronCity_Dojo_EventScript_HitmonleeBall_1:
# 45 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONLEE, 10, 3
# 46 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
# 47 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
# 48 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 49 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 50 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
# 51 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 52 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_HitmonleeBall_5
SaffronCity_Dojo_EventScript_HitmonleeBall_4:
# 55 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 56 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HitmonleeBall_2:
# 43 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_HitmonleeBall_1

SaffronCity_Dojo_EventScript_HitmonleeBall_5:
# 53 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_GiveHitmon
	goto SaffronCity_Dojo_EventScript_HitmonleeBall_4


SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
# 61 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
# 62 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_HitmonchanBall::
# 67 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 68 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 69 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_HitmonchanBall_2
SaffronCity_Dojo_EventScript_HitmonchanBall_1:
# 72 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONCHAN, 10, 3
# 73 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
# 74 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
# 75 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 76 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 77 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
# 78 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 79 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_HitmonchanBall_5
SaffronCity_Dojo_EventScript_HitmonchanBall_4:
# 82 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 83 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall_2:
# 70 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_HitmonchanBall_1

SaffronCity_Dojo_EventScript_HitmonchanBall_5:
# 80 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_GiveHitmon
	goto SaffronCity_Dojo_EventScript_HitmonchanBall_4


SaffronCity_Dojo_EventScript_GiveHitmon::
# 88 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 89 "data/maps/SaffronCity_Dojo/scripts.pory"
	givemon VAR_TEMP_1, 25
# 90 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_2
SaffronCity_Dojo_EventScript_GiveHitmon_1:
# 93 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_5
SaffronCity_Dojo_EventScript_GiveHitmon_4:
# 96 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_8
SaffronCity_Dojo_EventScript_GiveHitmon_7:
# 99 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon_2:
# 91 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto SaffronCity_Dojo_EventScript_GiveHitmon_1

SaffronCity_Dojo_EventScript_GiveHitmon_5:
# 94 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto SaffronCity_Dojo_EventScript_GiveHitmon_4

SaffronCity_Dojo_EventScript_GiveHitmon_8:
# 97 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto EventScript_NoMoreRoomForPokemon
	goto SaffronCity_Dojo_EventScript_GiveHitmon_7


SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
# 104 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 105 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 106 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 107 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 108 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 109 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 110 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 111 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 112 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonParty_2
SaffronCity_Dojo_EventScript_ReceivedHitmonParty_1:
# 115 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 116 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_ChangePokemonNickname
# 117 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty_2:
# 113 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonParty_1


SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
# 122 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 123 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 124 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 125 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 126 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 127 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 128 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 129 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 130 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonPC_2
SaffronCity_Dojo_EventScript_ReceivedHitmonPC_1:
# 133 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 134 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC_2:
# 131 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonPC_1


SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
# 139 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_TransferredToPC
# 140 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end


SaffronCity_Dojo_EventScript_EndGiveMon::
# 145 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_Statue::
# 150 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_LeftScroll::
# 155 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_RightScroll::
# 160 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_Hitoshi::
# 165 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
# 166 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_Hideki::
# 171 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
# 172 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_Aaron::
# 177 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
# 178 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_Mike::
# 183 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
# 184 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_MasterKoichi::
# 189 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
# 190 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichi_2
SaffronCity_Dojo_EventScript_MasterKoichi_1:
# 193 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi_2:
# 191 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_MasterKoichi_1


SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
# 198 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
# 199 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
# 204 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 205 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_Text_MasterKoichiIntro::
# 209 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Grunt!\p"
	.string "I am the KARATE MASTER!\n"
	.string "I am the LEADER here!\p"
	.string "You wish to challenge us?\n"
	.string "Expect no mercy!\p"
	.string "Fwaaa!$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
# 218 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hwa!\n"
	.string "Arrgh! Beaten!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
# 223 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Indeed, I have lost!\p"
	.string "But, I beseech you, do not take\n"
	.string "our emblem as your trophy!\p"
	.string "In return, I will give you a prized\n"
	.string "FIGHTING POKéMON!\p"
	.string "Choose whichever one you like!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
# 232 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Grunt!\n"
	.string "Stay and train at karate with us!$"

SaffronCity_Dojo_Text_MikeIntro::
# 237 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hoargh!\n"
	.string "Take your shoes off!$"

SaffronCity_Dojo_Text_MikeDefeat::
# 242 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "I give up!$"

SaffronCity_Dojo_Text_MikePostBattle::
# 246 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You wait 'til you see our MASTER!\n"
	.string "I'm a small fry compared to him!$"

SaffronCity_Dojo_Text_HidekiIntro::
# 251 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "I hear you're good!\n"
	.string "Show me!$"

SaffronCity_Dojo_Text_HidekiDefeat::
# 256 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Judge!\n"
	.string "One point!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
# 261 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Our MASTER is a pro fighter.\n"
	.string "Be prepared to lose!$"

SaffronCity_Dojo_Text_AaronIntro::
# 266 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hiyah!\n"
	.string "I have no fear for anything tough!\p"
	.string "I shatter boulders for training\n"
	.string "every day!$"

SaffronCity_Dojo_Text_AaronDefeat::
# 273 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Yow!\n"
	.string "Stubbed fingers!$"

SaffronCity_Dojo_Text_AaronPostBattle::
# 278 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "The only thing that frightens us is\n"
	.string "psychic power!$"

SaffronCity_Dojo_Text_HitoshiIntro::
# 283 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hwaah!\p"
	.string "You're trespassing in our\n"
	.string "FIGHTING DOJO!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
# 289 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Oof!\n"
	.string "I give up!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
# 294 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "The prime fighters across the land\n"
	.string "train here.$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
# 299 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You want the hard-kicking\n"
	.string "HITMONLEE?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
# 304 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from the KARATE MASTER.$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
# 309 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You want the piston-punching\n"
	.string "HITMONCHAN?$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
# 314 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Better not get greedy…$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
# 318 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Enemies on every side!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
# 322 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "What goes around comes around.$"

SaffronCity_Dojo_Text_FightingDojo::
# 326 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "FIGHTING DOJO$"
