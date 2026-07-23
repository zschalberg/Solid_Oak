Route11_MapScripts::
	.byte 0


Route11_EventScript_DiglettsCaveSign::
# 5 "data/maps/Route11/scripts.pory"
	msgbox Route11_EventScript_DiglettsCaveSign_Text_0
	end


Route11_EventScript_YoungTrainer::
# 13 "data/maps/Route11/scripts.pory"
	lock
# 14 "data/maps/Route11/scripts.pory"
	faceplayer
# 15 "data/maps/Route11/scripts.pory"
	msgbox Route11_EventScript_YoungTrainer_Text_0
# 22 "data/maps/Route11/scripts.pory"
	release
	end


Route11_EventScript_Picnicker::
# 27 "data/maps/Route11/scripts.pory"
	lock
# 28 "data/maps/Route11/scripts.pory"
	faceplayer
# 29 "data/maps/Route11/scripts.pory"
	msgbox Route11_EventScript_Picnicker_Text_0
# 34 "data/maps/Route11/scripts.pory"
	release
	end


Route11_EventScript_DiglettsCaveSign_Text_0:
# 5 "data/maps/Route11/scripts.pory"
	.string "ROUTE 11\n"
	.string "VERMILION CITY is to the west.\p"
	.string "LAVENDER TOWN can be reached\n"
	.string "via ROUTE 12 to the north.$"

Route11_EventScript_YoungTrainer_Text_0:
# 15 "data/maps/Route11/scripts.pory"
	.string "You heading to LAVENDER?\p"
	.string "Keep an eye on the coast once\n"
	.string "you hit ROUTE 12.\p"
	.string "Had a run-in with a TENTACOOL\n"
	.string "school yesterday that was way\l"
	.string "too big for this time of year.\p"
	.string "Probably nothing. Still.$"

Route11_EventScript_Picnicker_Text_0:
# 29 "data/maps/Route11/scripts.pory"
	.string "I used to come here to watch\n"
	.string "the LICKITUNG.\p"
	.string "Haven't seen one in weeks.\n"
	.string "My brother says they moved south.\p"
	.string "Maybe the weather. Who knows.$"
