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
	lockall
# 33 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs1
# 34 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 35 "data/maps/PacifidlogTown/scripts.pory"
	end
# 36 "data/maps/PacifidlogTown/scripts.pory"

# 37 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_2::
# 38 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 39 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs2
# 40 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 41 "data/maps/PacifidlogTown/scripts.pory"
	end
# 42 "data/maps/PacifidlogTown/scripts.pory"

# 43 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BetatestingRoadblock::
# 44 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Roadblockdeactivated, MSGBOX_NPC
# 45 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_PACIFIDLOG_ROADBLOCK
# 46 "data/maps/PacifidlogTown/scripts.pory"
	end
# 47 "data/maps/PacifidlogTown/scripts.pory"

# 48 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RestingSailor::
# 49 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RestingSailor, MSGBOX_NPC
# 50 "data/maps/PacifidlogTown/scripts.pory"
	end
# 51 "data/maps/PacifidlogTown/scripts.pory"

# 52 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF1::
# 53 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF1, MSGBOX_NPC
# 54 "data/maps/PacifidlogTown/scripts.pory"
	end
# 55 "data/maps/PacifidlogTown/scripts.pory"

# 56 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF2::
# 57 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF2, MSGBOX_NPC
# 58 "data/maps/PacifidlogTown/scripts.pory"
	end
# 59 "data/maps/PacifidlogTown/scripts.pory"

# 60 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_StockingSailor::
# 61 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_StockingSailor, MSGBOX_NPC
# 62 "data/maps/PacifidlogTown/scripts.pory"
	end
# 63 "data/maps/PacifidlogTown/scripts.pory"

# 64 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Wayfarer::
# 65 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Wayfarer, MSGBOX_NPC
# 66 "data/maps/PacifidlogTown/scripts.pory"
	end
# 67 "data/maps/PacifidlogTown/scripts.pory"

# 68 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller1::
# 69 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 70 "data/maps/PacifidlogTown/scripts.pory"
	faceplayer
# 71 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_SEASHELL_1, PacifidlogTown_EventScript_GaveShell
# 72 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_HaveThisShell, MSGBOX_DEFAULT
# 73 "data/maps/PacifidlogTown/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 74 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 75 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_RECEIVED_SEASHELL_1
# 76 "data/maps/PacifidlogTown/scripts.pory"
	release
# 77 "data/maps/PacifidlogTown/scripts.pory"
	end
# 78 "data/maps/PacifidlogTown/scripts.pory"

# 79 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GaveShell::
# 80 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller1, MSGBOX_DEFAULT
# 81 "data/maps/PacifidlogTown/scripts.pory"
	release
# 82 "data/maps/PacifidlogTown/scripts.pory"
	end
# 83 "data/maps/PacifidlogTown/scripts.pory"

# 84 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller2::
# 85 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller2, MSGBOX_NPC
# 86 "data/maps/PacifidlogTown/scripts.pory"
	end
# 87 "data/maps/PacifidlogTown/scripts.pory"

# 88 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GiddyWoman::
# 89 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_GiddyWoman, MSGBOX_NPC
# 90 "data/maps/PacifidlogTown/scripts.pory"
	end
# 91 "data/maps/PacifidlogTown/scripts.pory"

# 92 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_ManWorkingOut::
# 93 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_ManWorkingOut, MSGBOX_NPC
# 94 "data/maps/PacifidlogTown/scripts.pory"
	end
# 95 "data/maps/PacifidlogTown/scripts.pory"

# 96 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher1::
# 97 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher1, MSGBOX_NPC
# 98 "data/maps/PacifidlogTown/scripts.pory"
	end
# 99 "data/maps/PacifidlogTown/scripts.pory"

# 100 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher2::
# 101 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher2, MSGBOX_NPC
# 102 "data/maps/PacifidlogTown/scripts.pory"
	end
# 103 "data/maps/PacifidlogTown/scripts.pory"

# 104 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_CoralScientist::
# 105 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CoralScientist, MSGBOX_NPC
# 106 "data/maps/PacifidlogTown/scripts.pory"
	end
# 107 "data/maps/PacifidlogTown/scripts.pory"

# 108 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_FishScientist::
# 109 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FishScientist, MSGBOX_NPC
# 110 "data/maps/PacifidlogTown/scripts.pory"
	end
# 111 "data/maps/PacifidlogTown/scripts.pory"

# 112 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RunningTuber::
# 113 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RunningTuber, MSGBOX_NPC
# 114 "data/maps/PacifidlogTown/scripts.pory"
	end
# 115 "data/maps/PacifidlogTown/scripts.pory"

# 116 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NorthToSkyPillar::
# 117 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NorthToSkyPillar, MSGBOX_SIGN
# 118 "data/maps/PacifidlogTown/scripts.pory"
	end
# 119 "data/maps/PacifidlogTown/scripts.pory"

# 120 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_EastToFlotshoreTrail::
# 121 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_EastToFlotshoreTrail, MSGBOX_SIGN
# 122 "data/maps/PacifidlogTown/scripts.pory"
	end
# 123 "data/maps/PacifidlogTown/scripts.pory"

# 124 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_LabSign::
# 125 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_LabSign, MSGBOX_SIGN
# 126 "data/maps/PacifidlogTown/scripts.pory"
	end
# 127 "data/maps/PacifidlogTown/scripts.pory"

# 128 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SadFisherHouse::
# 129 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SadFisherHouse, MSGBOX_SIGN
# 130 "data/maps/PacifidlogTown/scripts.pory"
	end
# 131 "data/maps/PacifidlogTown/scripts.pory"

# 132 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_PacifidlogTownSign::
# 133 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_PacifidlogTownSign, MSGBOX_SIGN
# 134 "data/maps/PacifidlogTown/scripts.pory"
	end
# 135 "data/maps/PacifidlogTown/scripts.pory"

# 136 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BigCoral::
# 137 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BigCoral, MSGBOX_SIGN
# 138 "data/maps/PacifidlogTown/scripts.pory"
	end
# 139 "data/maps/PacifidlogTown/scripts.pory"

# 140 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BoxLabel::
# 141 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BoxLabel, MSGBOX_SIGN
# 142 "data/maps/PacifidlogTown/scripts.pory"
	end
# 143 "data/maps/PacifidlogTown/scripts.pory"

# 144 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 145 "data/maps/PacifidlogTown/scripts.pory"
	.string "The sea between PACIFIDLOG and\n"
# 146 "data/maps/PacifidlogTown/scripts.pory"
	.string "SLATEPORT has a fast-running tide.\p"
# 147 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you decide to SURF, you could end\n"
# 148 "data/maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 149 "data/maps/PacifidlogTown/scripts.pory"

# 150 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 151 "data/maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 152 "data/maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 153 "data/maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 154 "data/maps/PacifidlogTown/scripts.pory"

# 155 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 156 "data/maps/PacifidlogTown/scripts.pory"
	.string "The SKY PILLAR?\p"
# 157 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 158 "data/maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 159 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 160 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 161 "data/maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in PACIFIDLOG,\n"
# 162 "data/maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 163 "data/maps/PacifidlogTown/scripts.pory"

# 164 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 165 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 166 "data/maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 167 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"
# 168 "data/maps/PacifidlogTown/scripts.pory"

# 169 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs1:
# 170 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 171 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 172 "data/maps/PacifidlogTown/scripts.pory"
	.string "W-What did the boss stuff into\n"
# 173 "data/maps/PacifidlogTown/scripts.pory"
	.string "this box again?\p"
# 174 "data/maps/PacifidlogTown/scripts.pory"
	.string "...200 pounds of fish!? Ridiculous!\p"
# 175 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 176 "data/maps/PacifidlogTown/scripts.pory"

# 177 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs2:
# 178 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 179 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 180 "data/maps/PacifidlogTown/scripts.pory"
	.string "You know, I wish we could just push\n"
# 181 "data/maps/PacifidlogTown/scripts.pory"
	.string "the crate off the dock and let\l"
# 182 "data/maps/PacifidlogTown/scripts.pory"
	.string "the Vangar have at it.\p"
# 183 "data/maps/PacifidlogTown/scripts.pory"
	.string "...But then I'd get fired.\p"
# 184 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 185 "data/maps/PacifidlogTown/scripts.pory"

# 186 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Roadblockdeactivated:
# 187 "data/maps/PacifidlogTown/scripts.pory"
	.string "roadblock off$"
# 188 "data/maps/PacifidlogTown/scripts.pory"

# 189 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RestingSailor:
# 190 "data/maps/PacifidlogTown/scripts.pory"
	.string "Takin' the load off today before\n"
# 191 "data/maps/PacifidlogTown/scripts.pory"
	.string "me n' the other sailors\l"
# 192 "data/maps/PacifidlogTown/scripts.pory"
	.string "head out westward.\p"
# 193 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is the perfect lazy town\n"
# 194 "data/maps/PacifidlogTown/scripts.pory"
	.string "to forget about work in, I'd say!$"
# 195 "data/maps/PacifidlogTown/scripts.pory"

# 196 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF1:
# 197 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog's water is a breathtaking\n"
# 198 "data/maps/PacifidlogTown/scripts.pory"
	.string "place to take a dip in!\p"
# 199 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral structures blow my mind!$"
# 200 "data/maps/PacifidlogTown/scripts.pory"

# 201 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF2:
# 202 "data/maps/PacifidlogTown/scripts.pory"
	.string "Last week I stubbed my toe hopping\n"
# 203 "data/maps/PacifidlogTown/scripts.pory"
	.string "into the water on these docks.\l"
# 204 "data/maps/PacifidlogTown/scripts.pory"
	.string "There's untold amounts of jagged\l"
# 205 "data/maps/PacifidlogTown/scripts.pory"
	.string "coral strewn about down there...$"
# 206 "data/maps/PacifidlogTown/scripts.pory"

# 207 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_StockingSailor:
# 208 "data/maps/PacifidlogTown/scripts.pory"
	.string "Dum-dee-dum-dee-dum...\p"
# 209 "data/maps/PacifidlogTown/scripts.pory"
	.string "Oh? Why am I stocking\n"
# 210 "data/maps/PacifidlogTown/scripts.pory"
	.string "lox into this barrel?\p"
# 211 "data/maps/PacifidlogTown/scripts.pory"
	.string "Strict orders from my superior!\n"
# 212 "data/maps/PacifidlogTown/scripts.pory"
	.string "He said it'd be kinda funny.$"
# 213 "data/maps/PacifidlogTown/scripts.pory"

# 214 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Wayfarer:
# 215 "data/maps/PacifidlogTown/scripts.pory"
	.string "Rumor has it that there's a land full\n"
# 216 "data/maps/PacifidlogTown/scripts.pory"
	.string "of really tough battlers due south.\p"
# 217 "data/maps/PacifidlogTown/scripts.pory"
	.string "(You look southward and can make out\n"
# 218 "data/maps/PacifidlogTown/scripts.pory"
	.string "a few islands made of golden rocks.)\p"
# 219 "data/maps/PacifidlogTown/scripts.pory"
	.string "What, are you wanting to check it out\n"
# 220 "data/maps/PacifidlogTown/scripts.pory"
	.string "someday? Be my guest!$"
# 221 "data/maps/PacifidlogTown/scripts.pory"

# 222 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_HaveThisShell:
# 223 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hey! Lookit one of these cool\n"
# 224 "data/maps/PacifidlogTown/scripts.pory"
	.string "seashells I found in the water!\p"
# 225 "data/maps/PacifidlogTown/scripts.pory"
	.string "Do you like collecting shells too?\n"
# 226 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'll let you keep it if you promise\l"
# 227 "data/maps/PacifidlogTown/scripts.pory"
	.string "to take care of it!$"
# 228 "data/maps/PacifidlogTown/scripts.pory"

# 229 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller1:
# 230 "data/maps/PacifidlogTown/scripts.pory"
	.string "I heard from my friend that\n"
# 231 "data/maps/PacifidlogTown/scripts.pory"
	.string "there's a nice lady in Sootopolis\l"
# 232 "data/maps/PacifidlogTown/scripts.pory"
	.string "that makes a special item\l"
# 233 "data/maps/PacifidlogTown/scripts.pory"
	.string "out of sea shells!\p"
# 234 "data/maps/PacifidlogTown/scripts.pory"
	.string "And I think something else, but...\n"
# 235 "data/maps/PacifidlogTown/scripts.pory"
	.string "I forgot that part.$"
# 236 "data/maps/PacifidlogTown/scripts.pory"

# 237 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller2:
# 238 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mom told me to stop runnin' on\n"
# 239 "data/maps/PacifidlogTown/scripts.pory"
	.string "the docks. Hah! No way that I'll get\l"
# 240 "data/maps/PacifidlogTown/scripts.pory"
	.string "hurt! The wood isn't THAT slippery!\p"
# 241 "data/maps/PacifidlogTown/scripts.pory"
	.string "(His ankles and shins are clearly\n"
# 242 "data/maps/PacifidlogTown/scripts.pory"
	.string "bruised all over.)$"
# 243 "data/maps/PacifidlogTown/scripts.pory"

# 244 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_GiddyWoman:
# 245 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm positively BEAMING!\n"
# 246 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is such an underrated,\l"
# 247 "data/maps/PacifidlogTown/scripts.pory"
	.string "beautiful Hoenn locale!$"
# 248 "data/maps/PacifidlogTown/scripts.pory"

# 249 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_ManWorkingOut:
# 250 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral branches can double as\n"
# 251 "data/maps/PacifidlogTown/scripts.pory"
	.string "pull-up bars! I know, I've tried!\p"
# 252 "data/maps/PacifidlogTown/scripts.pory"
	.string "They're surprisingly rock solid.\p"
# 253 "data/maps/PacifidlogTown/scripts.pory"
	.string "Except when they're not. You kinda\n"
# 254 "data/maps/PacifidlogTown/scripts.pory"
	.string "have to figure that out through\l"
# 255 "data/maps/PacifidlogTown/scripts.pory"
	.string "trial and error.$"
# 256 "data/maps/PacifidlogTown/scripts.pory"

# 257 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher1:
# 258 "data/maps/PacifidlogTown/scripts.pory"
	.string "I don't know about you, but I feel like\n"
# 259 "data/maps/PacifidlogTown/scripts.pory"
	.string "I pull better catches the higher up\l"
# 260 "data/maps/PacifidlogTown/scripts.pory"
	.string "my post is.\p"
# 261 "data/maps/PacifidlogTown/scripts.pory"
	.string "I got a long enough rod to pull it off!\p"
# 262 "data/maps/PacifidlogTown/scripts.pory"
	.string "Stop snickering!$"
# 263 "data/maps/PacifidlogTown/scripts.pory"

# 264 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher2:
# 265 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Snelfrend around here are too nice\n"
# 266 "data/maps/PacifidlogTown/scripts.pory"
	.string "for their own good. I want to reel up\l"
# 267 "data/maps/PacifidlogTown/scripts.pory"
	.string "some actual fish, but every time\l"
# 268 "data/maps/PacifidlogTown/scripts.pory"
	.string "I cast out, one of these friendly\l"
# 269 "data/maps/PacifidlogTown/scripts.pory"
	.string "buggers clings to the hook\l"
# 270 "data/maps/PacifidlogTown/scripts.pory"
	.string "and won't let go!$"
# 271 "data/maps/PacifidlogTown/scripts.pory"

# 272 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CoralScientist:
# 273 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hello, {PLAYER}. I've been helping\n"
# 274 "data/maps/PacifidlogTown/scripts.pory"
	.string "your dad with researching the biology\l"
# 275 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the healthy coral deposits in\l"
# 276 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters surrounding Pacifidlog.\p"
# 277 "data/maps/PacifidlogTown/scripts.pory"
	.string "He seems to think that they can\n"
# 278 "data/maps/PacifidlogTown/scripts.pory"
	.string "be used as part of a plan to\l"
# 279 "data/maps/PacifidlogTown/scripts.pory"
	.string "clean up the water pollution\l"
# 280 "data/maps/PacifidlogTown/scripts.pory"
	.string "in the bigger cities, but\l"
# 281 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm not so sure it's that easy...$"
# 282 "data/maps/PacifidlogTown/scripts.pory"

# 283 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FishScientist:
# 284 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Water and Rock type POKéMON\n"
# 285 "data/maps/PacifidlogTown/scripts.pory"
	.string "Marinaroc are likely the cause\l"
# 286 "data/maps/PacifidlogTown/scripts.pory"
	.string "of Pacifidlog Town's extremely\l"
# 287 "data/maps/PacifidlogTown/scripts.pory"
	.string "healthy oceanic habitat.\p"
# 288 "data/maps/PacifidlogTown/scripts.pory"
	.string "You see, {PLAYER}, they are able to\n"
# 289 "data/maps/PacifidlogTown/scripts.pory"
	.string "filter the water they swim through.\l"
# 290 "data/maps/PacifidlogTown/scripts.pory"
	.string "They love doing their part to\l"
# 291 "data/maps/PacifidlogTown/scripts.pory"
	.string "keep the natural coral here healthy.\p"
# 292 "data/maps/PacifidlogTown/scripts.pory"
	.string "They prove very hard to fish\n"
# 293 "data/maps/PacifidlogTown/scripts.pory"
	.string "up because of their weight, too;\l"
# 294 "data/maps/PacifidlogTown/scripts.pory"
	.string "perfect for avoiding trophy hunting\l"
# 295 "data/maps/PacifidlogTown/scripts.pory"
	.string "or a potential overfishing problem!$"
# 296 "data/maps/PacifidlogTown/scripts.pory"

# 297 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RunningTuber:
# 298 "data/maps/PacifidlogTown/scripts.pory"
	.string "VAN-GUARD!\p"
# 299 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The child brandishes a balloon\n"
# 300 "data/maps/PacifidlogTown/scripts.pory"
	.string "cutlass at you.\l"
# 301 "data/maps/PacifidlogTown/scripts.pory"
	.string "You dramatically feign surrender.)\p"
# 302 "data/maps/PacifidlogTown/scripts.pory"
	.string "That's right! I'M the pirate captain!\n"
# 303 "data/maps/PacifidlogTown/scripts.pory"
	.string "YARRR!$"
# 304 "data/maps/PacifidlogTown/scripts.pory"

# 305 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NorthToSkyPillar:
# 306 "data/maps/PacifidlogTown/scripts.pory"
	.string "NORTH: SKY PILLAR\p"
# 307 "data/maps/PacifidlogTown/scripts.pory"
	.string "We ask you to respect this historical\n"
# 308 "data/maps/PacifidlogTown/scripts.pory"
	.string "monument and to keep it clean.$"
# 309 "data/maps/PacifidlogTown/scripts.pory"

# 310 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_EastToFlotshoreTrail:
# 311 "data/maps/PacifidlogTown/scripts.pory"
	.string "EAST: FLOTSHORE TRAIL\p"
# 312 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mondays through Thursdays are\n"
# 313 "data/maps/PacifidlogTown/scripts.pory"
	.string "scheduled bulk-fishing days.\l"
# 314 "data/maps/PacifidlogTown/scripts.pory"
	.string "All recreational fishers and swimmers\l"
# 315 "data/maps/PacifidlogTown/scripts.pory"
	.string "should be respectful and stay out\l"
# 316 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the way on those dates.$"
# 317 "data/maps/PacifidlogTown/scripts.pory"

# 318 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_LabSign:
# 319 "data/maps/PacifidlogTown/scripts.pory"
	.string "PROFESSOR BIRCH'S\n"
# 320 "data/maps/PacifidlogTown/scripts.pory"
	.string "MARITIME POKéMON LAB$"
# 321 "data/maps/PacifidlogTown/scripts.pory"

# 322 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SadFisherHouse:
# 323 "data/maps/PacifidlogTown/scripts.pory"
	.string "See me if you're serious about\n"
# 324 "data/maps/PacifidlogTown/scripts.pory"
	.string "fishing for strong POKéMON.$"
# 325 "data/maps/PacifidlogTown/scripts.pory"

# 326 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_PacifidlogTownSign:
# 327 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 328 "data/maps/PacifidlogTown/scripts.pory"
	.string "Where the morning sun\n"
# 329 "data/maps/PacifidlogTown/scripts.pory"
	.string "smiles upon the waters.$"
# 330 "data/maps/PacifidlogTown/scripts.pory"

# 331 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BigCoral:
# 332 "data/maps/PacifidlogTown/scripts.pory"
	.string "(It's a large natural\n"
# 333 "data/maps/PacifidlogTown/scripts.pory"
	.string "structure made of coral.)$"
# 334 "data/maps/PacifidlogTown/scripts.pory"

# 335 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BoxLabel:
# 336 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The box is labelled...)\p"
# 337 "data/maps/PacifidlogTown/scripts.pory"
	.string "DINNER FOR THREE$"

PacifidlogTown_EventScript_TestSign::
# 341 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 342 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_EventScript_TestSign_Text_0
# 343 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
	return


PacifidlogTown_EventScript_TestSign_Text_0:
# 342 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Holy Diver Mod$"
