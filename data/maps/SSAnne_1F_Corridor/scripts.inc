SSAnne_1F_Corridor_MapScripts::
	.byte 0

SSAnne_1F_Corridor_EventScript_WorkerM::
	msgbox SSAnne_1F_Corridor_Text_LeStrongSilentType, MSGBOX_NPC
	end

SSAnne_1F_Corridor_EventScript_Sailor::
	msgbox SSAnne_1F_Corridor_Text_PassengersAreRestless, MSGBOX_NPC
	end

SSAnne_1F_Corridor_EventScript_SizeResearcher::
	lock
	faceplayer
	msgbox SSAnne_1F_Corridor_Text_ResearcherIntro, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SSAnne_1F_Corridor_EventScript_SizeResearcher_Decline
	msgbox SSAnne_1F_Corridor_Text_ChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge SSAnne_1F_Corridor_EventScript_SizeResearcher_Cancel
	
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferspeciesname 0, VAR_RESULT
	
	special BufferMonPercentiles
	
	msgbox SSAnne_1F_Corridor_Text_ShowPercentiles, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SSAnne_1F_Corridor_EventScript_SizeResearcher_DeclineTurnIn
	
	special RemoveSelectedPartyMon
	compare VAR_RESULT, FALSE
	goto_if_eq SSAnne_1F_Corridor_EventScript_SizeResearcher_LastPokemonError
	
	msgbox SSAnne_1F_Corridor_Text_TurnInSuccess, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY, 1
	release
	end

SSAnne_1F_Corridor_EventScript_SizeResearcher_Decline::
	msgbox SSAnne_1F_Corridor_Text_Decline, MSGBOX_DEFAULT
	release
	end

SSAnne_1F_Corridor_EventScript_SizeResearcher_DeclineTurnIn::
	msgbox SSAnne_1F_Corridor_Text_DeclineTurnIn, MSGBOX_DEFAULT
	release
	end

SSAnne_1F_Corridor_EventScript_SizeResearcher_Cancel::
	msgbox SSAnne_1F_Corridor_Text_Cancelled, MSGBOX_DEFAULT
	release
	end

SSAnne_1F_Corridor_EventScript_SizeResearcher_LastPokemonError::
	msgbox SSAnne_1F_Corridor_Text_LastPokemonError, MSGBOX_DEFAULT
	release
	end

SSAnne_1F_Corridor_Text_ResearcherIntro:
	.string "Hi! I'm a size researcher.\n"
	.string "Would you like me to evaluate the\l"
	.string "size percentiles of your Pokémon?$"

SSAnne_1F_Corridor_Text_ChooseMon:
	.string "Please select a Pokémon.$"

SSAnne_1F_Corridor_Text_ShowPercentiles:
	.string "Your {STR_VAR_1}'s percentiles are:\n"
	.string "Height: {STR_VAR_2}% / Weight: {STR_VAR_3}%\p"
	.string "Would you like to turn it in to my\n"
	.string "research lab for a reward?$"

SSAnne_1F_Corridor_Text_TurnInSuccess:
	.string "Excellent! Thank you for donating\n"
	.string "your {STR_VAR_1} to science!\l"
	.string "Here is a reward.$"

SSAnne_1F_Corridor_Text_Decline:
	.string "Let me know if you change your mind.$"

SSAnne_1F_Corridor_Text_DeclineTurnIn:
	.string "I understand. Keep training it!$"

SSAnne_1F_Corridor_Text_Cancelled:
	.string "You didn't select a Pokémon.$"

SSAnne_1F_Corridor_Text_LastPokemonError:
	.string "Wait! That's your last usable Pokémon!\n"
	.string "I cannot take it from you.$"
