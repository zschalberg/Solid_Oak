Lavender_Cemetary_Map_MapScripts::
	.byte 0

Lavender_Cemetary_Map_EventScript_Dale::
	trainerbattle_single TRAINER_CAMPER_DALE, Lavender_Cemetary_Map_Text_DaleIntro, Lavender_Cemetary_Map_Text_DaleDefeat
	msgbox Lavender_Cemetary_Map_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

@ TODO: [AI-DIALOG] placeholder trainer dialogue, pending final writing
Lavender_Cemetary_Map_Text_DaleIntro::
	.string "Whoa! You scared me half to death\n"
	.string "sneaking up like that!$"

@ TODO: [AI-DIALOG] placeholder trainer dialogue, pending final writing
Lavender_Cemetary_Map_Text_DaleDefeat::
	.string "My Spinda just fell right over...$"

@ TODO: [AI-DIALOG] placeholder trainer dialogue, pending final writing
Lavender_Cemetary_Map_Text_DalePostBattle::
	.string "Camping in a graveyard wasn't my\n"
	.string "best idea, huh?$"
