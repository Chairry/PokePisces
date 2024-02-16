# 1 "data/maps/PacifidlogTown/scripts.pory"

# 2 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_MapScripts::
# 3 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
# 4 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
# 5 "data/maps/PacifidlogTown/scripts.pory"
	.byte 0
# 6 "data/maps/PacifidlogTown/scripts.pory"

# 7 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnTransition:
# 8 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
# 9 "data/maps/PacifidlogTown/scripts.pory"
	end
# 10 "data/maps/PacifidlogTown/scripts.pory"

# 11 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnResume:
# 12 "data/maps/PacifidlogTown/scripts.pory"
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
# 13 "data/maps/PacifidlogTown/scripts.pory"
	end
# 14 "data/maps/PacifidlogTown/scripts.pory"

# 15 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NinjaBoy::
# 16 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
# 17 "data/maps/PacifidlogTown/scripts.pory"
	end
# 18 "data/maps/PacifidlogTown/scripts.pory"

# 19 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Girl::
# 20 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
# 21 "data/maps/PacifidlogTown/scripts.pory"
	end
# 22 "data/maps/PacifidlogTown/scripts.pory"

# 23 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Fisherman::
# 24 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
# 25 "data/maps/PacifidlogTown/scripts.pory"
	end
# 26 "data/maps/PacifidlogTown/scripts.pory"

# 27 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TownSign::
# 28 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
# 29 "data/maps/PacifidlogTown/scripts.pory"
	end
# 30 "data/maps/PacifidlogTown/scripts.pory"

# 31 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_1::
# 32 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs1, MSGBOX_NPC
# 33 "data/maps/PacifidlogTown/scripts.pory"
	end
# 34 "data/maps/PacifidlogTown/scripts.pory"

# 35 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_2::
# 36 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs2, MSGBOX_NPC
# 37 "data/maps/PacifidlogTown/scripts.pory"
	end
# 38 "data/maps/PacifidlogTown/scripts.pory"

# 39 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BetatestingRoadblock::
# 40 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Roadblockdeactivated, MSGBOX_NPC
# 41 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_PACIFIDLOG_ROADBLOCK
# 42 "data/maps/PacifidlogTown/scripts.pory"
	end
# 43 "data/maps/PacifidlogTown/scripts.pory"

# 44 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 45 "data/maps/PacifidlogTown/scripts.pory"
	.string "The sea between PACIFIDLOG and\n"
# 46 "data/maps/PacifidlogTown/scripts.pory"
	.string "SLATEPORT has a fast-running tide.\p"
# 47 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you decide to SURF, you could end\n"
# 48 "data/maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 49 "data/maps/PacifidlogTown/scripts.pory"

# 50 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 51 "data/maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 52 "data/maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 53 "data/maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 54 "data/maps/PacifidlogTown/scripts.pory"

# 55 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 56 "data/maps/PacifidlogTown/scripts.pory"
	.string "The SKY PILLAR?\p"
# 57 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 58 "data/maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 59 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 60 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 61 "data/maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in PACIFIDLOG,\n"
# 62 "data/maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 63 "data/maps/PacifidlogTown/scripts.pory"

# 64 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 65 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 66 "data/maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 67 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"
# 68 "data/maps/PacifidlogTown/scripts.pory"

# 69 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs1:
# 70 "data/maps/PacifidlogTown/scripts.pory"
	.string "Uhhh test text lol\n"
# 71 "data/maps/PacifidlogTown/scripts.pory"
	.string "My mom said its my turn on le toilet\p"
# 72 "data/maps/PacifidlogTown/scripts.pory"
	.string "HOW BOU DAH\p"
# 73 "data/maps/PacifidlogTown/scripts.pory"
	.string "don't try me doooood$"
# 74 "data/maps/PacifidlogTown/scripts.pory"

# 75 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs2:
# 76 "data/maps/PacifidlogTown/scripts.pory"
	.string "Uhhh test text lol\n"
# 77 "data/maps/PacifidlogTown/scripts.pory"
	.string "My mom said its my turn on le toilet\p"
# 78 "data/maps/PacifidlogTown/scripts.pory"
	.string "HOW BOU DAH\p"
# 79 "data/maps/PacifidlogTown/scripts.pory"
	.string "don't try me doooood$"
# 80 "data/maps/PacifidlogTown/scripts.pory"

# 81 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Roadblockdeactivated:
# 82 "data/maps/PacifidlogTown/scripts.pory"
	.string "roadblock off$"

PacifidlogTown_EventScript_TestSign::
# 86 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 87 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_EventScript_TestSign_Text_0
# 88 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
	return


PacifidlogTown_EventScript_TestSign_Text_0:
# 87 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Holy Diver Mod$"
