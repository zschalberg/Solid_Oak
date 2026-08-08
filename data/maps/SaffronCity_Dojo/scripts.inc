SaffronCity_Dojo_MapScripts::
	.byte 0


SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
# 6 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 7 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 8 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterLeft
# 9 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 10 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
	end


SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
# 15 "data/maps/SaffronCity_Dojo/scripts.pory"
	lockall
# 16 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 17 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterRight
# 18 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 19 "data/maps/SaffronCity_Dojo/scripts.pory"
	releaseall
	end


SaffronCity_Dojo_EventScript_HitmonleeBall::
# 24 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 25 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 26 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_HitmonleeBall_2
SaffronCity_Dojo_EventScript_HitmonleeBall_1:
# 29 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONLEE, 10, 3
# 30 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
# 31 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
# 32 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 33 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 34 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
# 35 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 36 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_HitmonleeBall_5
SaffronCity_Dojo_EventScript_HitmonleeBall_4:
# 39 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 40 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HitmonleeBall_2:
# 27 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_HitmonleeBall_1

SaffronCity_Dojo_EventScript_HitmonleeBall_5:
# 37 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_GiveHitmon
	goto SaffronCity_Dojo_EventScript_HitmonleeBall_4


SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
# 45 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
# 46 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_HitmonchanBall::
# 51 "data/maps/SaffronCity_Dojo/scripts.pory"
	lock
# 52 "data/maps/SaffronCity_Dojo/scripts.pory"
	faceplayer
# 53 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_HitmonchanBall_2
SaffronCity_Dojo_EventScript_HitmonchanBall_1:
# 56 "data/maps/SaffronCity_Dojo/scripts.pory"
	showmonpic SPECIES_HITMONCHAN, 10, 3
# 57 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
# 58 "data/maps/SaffronCity_Dojo/scripts.pory"
	applymovement 5, Common_Movement_WalkInPlaceFasterUp
# 59 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmovement 0
# 60 "data/maps/SaffronCity_Dojo/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 61 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
# 62 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_RestorePrevTextColor
# 63 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SaffronCity_Dojo_EventScript_HitmonchanBall_5
SaffronCity_Dojo_EventScript_HitmonchanBall_4:
# 66 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 67 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall_2:
# 54 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_HitmonchanBall_1

SaffronCity_Dojo_EventScript_HitmonchanBall_5:
# 64 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_GiveHitmon
	goto SaffronCity_Dojo_EventScript_HitmonchanBall_4


SaffronCity_Dojo_EventScript_GiveHitmon::
# 72 "data/maps/SaffronCity_Dojo/scripts.pory"
	hidemonpic
# 73 "data/maps/SaffronCity_Dojo/scripts.pory"
	givemon VAR_TEMP_1, 25
# 74 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_2
SaffronCity_Dojo_EventScript_GiveHitmon_1:
# 77 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_5
SaffronCity_Dojo_EventScript_GiveHitmon_4:
# 80 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq SaffronCity_Dojo_EventScript_GiveHitmon_8
SaffronCity_Dojo_EventScript_GiveHitmon_7:
# 83 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon_2:
# 75 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto SaffronCity_Dojo_EventScript_GiveHitmon_1

SaffronCity_Dojo_EventScript_GiveHitmon_5:
# 78 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto SaffronCity_Dojo_EventScript_GiveHitmon_4

SaffronCity_Dojo_EventScript_GiveHitmon_8:
# 81 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto EventScript_NoMoreRoomForPokemon
	goto SaffronCity_Dojo_EventScript_GiveHitmon_7


SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
# 88 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 89 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 90 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 91 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 92 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 93 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 94 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 95 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 96 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonParty_2
SaffronCity_Dojo_EventScript_ReceivedHitmonParty_1:
# 99 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 100 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_ChangePokemonNickname
# 101 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty_2:
# 97 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonParty_1


SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
# 106 "data/maps/SaffronCity_Dojo/scripts.pory"
	removeobject VAR_LAST_TALKED
# 107 "data/maps/SaffronCity_Dojo/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
# 108 "data/maps/SaffronCity_Dojo/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 109 "data/maps/SaffronCity_Dojo/scripts.pory"
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
# 110 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitmessage
# 111 "data/maps/SaffronCity_Dojo/scripts.pory"
	waitfanfare
# 112 "data/maps/SaffronCity_Dojo/scripts.pory"
	setflag FLAG_GOT_HITMON_FROM_DOJO
# 113 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 114 "data/maps/SaffronCity_Dojo/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq SaffronCity_Dojo_EventScript_ReceivedHitmonPC_2
SaffronCity_Dojo_EventScript_ReceivedHitmonPC_1:
# 117 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 118 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC_2:
# 115 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	goto SaffronCity_Dojo_EventScript_ReceivedHitmonPC_1


SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
# 123 "data/maps/SaffronCity_Dojo/scripts.pory"
	call EventScript_TransferredToPC
# 124 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end


SaffronCity_Dojo_EventScript_EndGiveMon::
# 129 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_Statue::
# 134 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_LeftScroll::
# 139 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_RightScroll::
# 144 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end


SaffronCity_Dojo_EventScript_Hitoshi::
# 149 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
# 150 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_Hideki::
# 155 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
# 156 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_Aaron::
# 161 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
# 162 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_Mike::
# 167 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
# 168 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end


SaffronCity_Dojo_EventScript_MasterKoichi::
# 173 "data/maps/SaffronCity_Dojo/scripts.pory"
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
# 174 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichi_2
SaffronCity_Dojo_EventScript_MasterKoichi_1:
# 177 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi_2:
# 175 "data/maps/SaffronCity_Dojo/scripts.pory"
	goto SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	goto SaffronCity_Dojo_EventScript_MasterKoichi_1


SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
# 182 "data/maps/SaffronCity_Dojo/scripts.pory"
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
# 183 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
# 188 "data/maps/SaffronCity_Dojo/scripts.pory"
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
# 189 "data/maps/SaffronCity_Dojo/scripts.pory"
	release
	end


SaffronCity_Dojo_Text_MasterKoichiIntro::
# 193 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Grunt!\p"
	.string "I am the KARATE MASTER!\n"
	.string "I am the LEADER here!\p"
	.string "You wish to challenge us?\n"
	.string "Expect no mercy!\p"
	.string "Fwaaa!$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
# 202 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hwa!\n"
	.string "Arrgh! Beaten!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
# 207 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Indeed, I have lost!\p"
	.string "But, I beseech you, do not take\n"
	.string "our emblem as your trophy!\p"
	.string "In return, I will give you a prized\n"
	.string "FIGHTING POKéMON!\p"
	.string "Choose whichever one you like!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
# 216 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Grunt!\n"
	.string "Stay and train at karate with us!$"

SaffronCity_Dojo_Text_MikeIntro::
# 221 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hoargh!\n"
	.string "Take your shoes off!$"

SaffronCity_Dojo_Text_MikeDefeat::
# 226 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "I give up!$"

SaffronCity_Dojo_Text_MikePostBattle::
# 230 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You wait 'til you see our MASTER!\n"
	.string "I'm a small fry compared to him!$"

SaffronCity_Dojo_Text_HidekiIntro::
# 235 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "I hear you're good!\n"
	.string "Show me!$"

SaffronCity_Dojo_Text_HidekiDefeat::
# 240 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Judge!\n"
	.string "One point!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
# 245 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Our MASTER is a pro fighter.\n"
	.string "Be prepared to lose!$"

SaffronCity_Dojo_Text_AaronIntro::
# 250 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hiyah!\n"
	.string "I have no fear for anything tough!\p"
	.string "I shatter boulders for training\n"
	.string "every day!$"

SaffronCity_Dojo_Text_AaronDefeat::
# 257 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Yow!\n"
	.string "Stubbed fingers!$"

SaffronCity_Dojo_Text_AaronPostBattle::
# 262 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "The only thing that frightens us is\n"
	.string "psychic power!$"

SaffronCity_Dojo_Text_HitoshiIntro::
# 267 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Hwaah!\p"
	.string "You're trespassing in our\n"
	.string "FIGHTING DOJO!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
# 273 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Oof!\n"
	.string "I give up!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
# 278 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "The prime fighters across the land\n"
	.string "train here.$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
# 283 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You want the hard-kicking\n"
	.string "HITMONLEE?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
# 288 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from the KARATE MASTER.$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
# 293 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "You want the piston-punching\n"
	.string "HITMONCHAN?$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
# 298 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Better not get greedy…$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
# 302 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "Enemies on every side!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
# 306 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "What goes around comes around.$"

SaffronCity_Dojo_Text_FightingDojo::
# 310 "data/maps/SaffronCity_Dojo/scripts.pory"
	.string "FIGHTING DOJO$"
