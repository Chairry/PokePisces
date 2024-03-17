# 1 "data/maps/PacifidlogTown/scripts.pory"

# 2 "data/maps/PacifidlogTown/scripts.pory"
.set LOCALID_PACIFBIRCH, 20
# 3 "data/maps/PacifidlogTown/scripts.pory"

# 4 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_MapScripts::
# 5 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
# 6 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
# 7 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PacifidlogTown_OnFrame
# 8 "data/maps/PacifidlogTown/scripts.pory"
	.byte 0
# 9 "data/maps/PacifidlogTown/scripts.pory"

# 10 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnTransition:
# 11 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
# 12 "data/maps/PacifidlogTown/scripts.pory"
	end
# 13 "data/maps/PacifidlogTown/scripts.pory"

# 14 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnResume:
# 15 "data/maps/PacifidlogTown/scripts.pory"
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
# 16 "data/maps/PacifidlogTown/scripts.pory"
	end
# 17 "data/maps/PacifidlogTown/scripts.pory"

# 18 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnFrame:
# 19 "data/maps/PacifidlogTown/scripts.pory"
	map_script_2 VAR_BIRCH_LAB_STATE, 2, PacifidlogTown_EventScript_TakePlayerToLab
# 20 "data/maps/PacifidlogTown/scripts.pory"
	.2byte 0
# 21 "data/maps/PacifidlogTown/scripts.pory"

# 22 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TakePlayerToLab::
# 23 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 24 "data/maps/PacifidlogTown/scripts.pory"
	playse SE_PIN
# 25 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchNotice
# 26 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerNotice
# 27 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 28 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_GladToSeeYou, MSGBOX_DEFAULT
# 29 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 30 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk1
# 31 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk1
# 32 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 33 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_PacifidlogTownIsNice, MSGBOX_DEFAULT
# 34 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 35 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk2
# 36 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk2
# 37 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 38 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_ResearchingTheLegends, MSGBOX_DEFAULT
# 39 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 40 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk3
# 41 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk3
# 42 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 43 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CouldUseYourHelp, MSGBOX_DEFAULT
# 44 "data/maps/PacifidlogTown/scripts.pory"
	clearflag FLAG_PISCES_A
# 45 "data/maps/PacifidlogTown/scripts.pory"
	clearflag FLAG_PISCES_B
# 46 "data/maps/PacifidlogTown/scripts.pory"
	clearflag FLAG_PISCES_C
# 47 "data/maps/PacifidlogTown/scripts.pory"
	clearflag FLAG_PISCES_D
# 48 "data/maps/PacifidlogTown/scripts.pory"
	clearflag FLAG_PISCES_E
# 49 "data/maps/PacifidlogTown/scripts.pory"
	clearflag FLAG_PISCES_F
# 50 "data/maps/PacifidlogTown/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 51 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_HIDE_LAB_RANGERS
# 52 "data/maps/PacifidlogTown/scripts.pory"
	warp MAP_BIRCH_MARITIME_LAB, 9, 14
# 53 "data/maps/PacifidlogTown/scripts.pory"
	waitstate
# 54 "data/maps/PacifidlogTown/scripts.pory"
	release
# 55 "data/maps/PacifidlogTown/scripts.pory"
	end
# 56 "data/maps/PacifidlogTown/scripts.pory"

# 57 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchNotice:
# 58 "data/maps/PacifidlogTown/scripts.pory"
	emote_exclamation_mark
# 59 "data/maps/PacifidlogTown/scripts.pory"
	jump_in_place_right
# 60 "data/maps/PacifidlogTown/scripts.pory"
	walk_fast_right
# 61 "data/maps/PacifidlogTown/scripts.pory"
	walk_fast_right
# 62 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 63 "data/maps/PacifidlogTown/scripts.pory"

# 64 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerNotice:
# 65 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 66 "data/maps/PacifidlogTown/scripts.pory"
	delay_8
# 67 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 68 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 69 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 70 "data/maps/PacifidlogTown/scripts.pory"

# 71 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk1:
# 72 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 73 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 74 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 75 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 76 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 77 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 78 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 79 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 80 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 81 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 82 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 83 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 84 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 85 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 86 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 87 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 88 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 89 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 90 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 91 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 92 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 93 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 94 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 95 "data/maps/PacifidlogTown/scripts.pory"
	face_right
# 96 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 97 "data/maps/PacifidlogTown/scripts.pory"

# 98 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk1:
# 99 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 100 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 101 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 102 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 103 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 104 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 105 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 106 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 107 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 108 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 109 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 110 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 111 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 112 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 113 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 114 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 115 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 116 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 117 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 118 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 119 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 120 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 121 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 122 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 123 "data/maps/PacifidlogTown/scripts.pory"

# 124 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk2:
# 125 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 126 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 127 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 128 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 129 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 130 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 131 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 132 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 133 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 134 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 135 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 136 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 137 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 138 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 139 "data/maps/PacifidlogTown/scripts.pory"

# 140 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk2:
# 141 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 142 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 143 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 144 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 145 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 146 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 147 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 148 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 149 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 150 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 151 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 152 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 153 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 154 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 155 "data/maps/PacifidlogTown/scripts.pory"

# 156 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk3:
# 157 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 158 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 159 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 160 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 161 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 162 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 163 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 164 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 165 "data/maps/PacifidlogTown/scripts.pory"
	face_down
# 166 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 167 "data/maps/PacifidlogTown/scripts.pory"

# 168 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk3:
# 169 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 170 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 171 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 172 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 173 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 174 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 175 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 176 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 177 "data/maps/PacifidlogTown/scripts.pory"
	face_up
# 178 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 179 "data/maps/PacifidlogTown/scripts.pory"

# 180 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NinjaBoy::
# 181 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
# 182 "data/maps/PacifidlogTown/scripts.pory"
	end
# 183 "data/maps/PacifidlogTown/scripts.pory"

# 184 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Girl::
# 185 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
# 186 "data/maps/PacifidlogTown/scripts.pory"
	end
# 187 "data/maps/PacifidlogTown/scripts.pory"

# 188 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Fisherman::
# 189 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
# 190 "data/maps/PacifidlogTown/scripts.pory"
	end
# 191 "data/maps/PacifidlogTown/scripts.pory"

# 192 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TownSign::
# 193 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
# 194 "data/maps/PacifidlogTown/scripts.pory"
	end
# 195 "data/maps/PacifidlogTown/scripts.pory"

# 196 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_1::
# 197 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 198 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs1
# 199 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 200 "data/maps/PacifidlogTown/scripts.pory"
	end
# 201 "data/maps/PacifidlogTown/scripts.pory"

# 202 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_2::
# 203 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 204 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs2
# 205 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 206 "data/maps/PacifidlogTown/scripts.pory"
	end
# 207 "data/maps/PacifidlogTown/scripts.pory"

# 208 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BetatestingRoadblock::
# 209 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Roadblockdeactivated, MSGBOX_NPC
# 210 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_PACIFIDLOG_ROADBLOCK
# 211 "data/maps/PacifidlogTown/scripts.pory"
	end
# 212 "data/maps/PacifidlogTown/scripts.pory"

# 213 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RestingSailor::
# 214 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RestingSailor, MSGBOX_NPC
# 215 "data/maps/PacifidlogTown/scripts.pory"
	end
# 216 "data/maps/PacifidlogTown/scripts.pory"

# 217 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF1::
# 218 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF1, MSGBOX_NPC
# 219 "data/maps/PacifidlogTown/scripts.pory"
	end
# 220 "data/maps/PacifidlogTown/scripts.pory"

# 221 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF2::
# 222 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF2, MSGBOX_NPC
# 223 "data/maps/PacifidlogTown/scripts.pory"
	end
# 224 "data/maps/PacifidlogTown/scripts.pory"

# 225 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_StockingSailor::
# 226 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_StockingSailor, MSGBOX_NPC
# 227 "data/maps/PacifidlogTown/scripts.pory"
	end
# 228 "data/maps/PacifidlogTown/scripts.pory"

# 229 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Wayfarer::
# 230 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Wayfarer, MSGBOX_NPC
# 231 "data/maps/PacifidlogTown/scripts.pory"
	end
# 232 "data/maps/PacifidlogTown/scripts.pory"

# 233 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller1::
# 234 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 235 "data/maps/PacifidlogTown/scripts.pory"
	faceplayer
# 236 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_SEASHELL_1, PacifidlogTown_EventScript_GaveShell
# 237 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_HaveThisShell, MSGBOX_DEFAULT
# 238 "data/maps/PacifidlogTown/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 239 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 240 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_RECEIVED_SEASHELL_1
# 241 "data/maps/PacifidlogTown/scripts.pory"
	release
# 242 "data/maps/PacifidlogTown/scripts.pory"
	end
# 243 "data/maps/PacifidlogTown/scripts.pory"

# 244 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GaveShell::
# 245 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller1, MSGBOX_DEFAULT
# 246 "data/maps/PacifidlogTown/scripts.pory"
	release
# 247 "data/maps/PacifidlogTown/scripts.pory"
	end
# 248 "data/maps/PacifidlogTown/scripts.pory"

# 249 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller2::
# 250 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller2, MSGBOX_NPC
# 251 "data/maps/PacifidlogTown/scripts.pory"
	end
# 252 "data/maps/PacifidlogTown/scripts.pory"

# 253 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GiddyWoman::
# 254 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_GiddyWoman, MSGBOX_NPC
# 255 "data/maps/PacifidlogTown/scripts.pory"
	end
# 256 "data/maps/PacifidlogTown/scripts.pory"

# 257 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_ManWorkingOut::
# 258 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_ManWorkingOut, MSGBOX_NPC
# 259 "data/maps/PacifidlogTown/scripts.pory"
	end
# 260 "data/maps/PacifidlogTown/scripts.pory"

# 261 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher1::
# 262 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher1, MSGBOX_NPC
# 263 "data/maps/PacifidlogTown/scripts.pory"
	end
# 264 "data/maps/PacifidlogTown/scripts.pory"

# 265 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher2::
# 266 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher2, MSGBOX_NPC
# 267 "data/maps/PacifidlogTown/scripts.pory"
	end
# 268 "data/maps/PacifidlogTown/scripts.pory"

# 269 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_CoralScientist::
# 270 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CoralScientist, MSGBOX_NPC
# 271 "data/maps/PacifidlogTown/scripts.pory"
	end
# 272 "data/maps/PacifidlogTown/scripts.pory"

# 273 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_FishScientist::
# 274 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FishScientist, MSGBOX_NPC
# 275 "data/maps/PacifidlogTown/scripts.pory"
	end
# 276 "data/maps/PacifidlogTown/scripts.pory"

# 277 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RunningTuber::
# 278 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RunningTuber, MSGBOX_NPC
# 279 "data/maps/PacifidlogTown/scripts.pory"
	end
# 280 "data/maps/PacifidlogTown/scripts.pory"

# 281 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NorthToSkyPillar::
# 282 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NorthToSkyPillar, MSGBOX_SIGN
# 283 "data/maps/PacifidlogTown/scripts.pory"
	end
# 284 "data/maps/PacifidlogTown/scripts.pory"

# 285 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_EastToFlotshoreTrail::
# 286 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_EastToFlotshoreTrail, MSGBOX_SIGN
# 287 "data/maps/PacifidlogTown/scripts.pory"
	end
# 288 "data/maps/PacifidlogTown/scripts.pory"

# 289 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_LabSign::
# 290 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_LabSign, MSGBOX_SIGN
# 291 "data/maps/PacifidlogTown/scripts.pory"
	end
# 292 "data/maps/PacifidlogTown/scripts.pory"

# 293 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SadFisherHouse::
# 294 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SadFisherHouse, MSGBOX_SIGN
# 295 "data/maps/PacifidlogTown/scripts.pory"
	end
# 296 "data/maps/PacifidlogTown/scripts.pory"

# 297 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_PacifidlogTownSign::
# 298 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_PacifidlogTownSign, MSGBOX_SIGN
# 299 "data/maps/PacifidlogTown/scripts.pory"
	end
# 300 "data/maps/PacifidlogTown/scripts.pory"

# 301 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BigCoral::
# 302 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BigCoral, MSGBOX_SIGN
# 303 "data/maps/PacifidlogTown/scripts.pory"
	end
# 304 "data/maps/PacifidlogTown/scripts.pory"

# 305 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BoxLabel::
# 306 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BoxLabel, MSGBOX_SIGN
# 307 "data/maps/PacifidlogTown/scripts.pory"
	end
# 308 "data/maps/PacifidlogTown/scripts.pory"

# 309 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 310 "data/maps/PacifidlogTown/scripts.pory"
	.string "The sea between PACIFIDLOG and\n"
# 311 "data/maps/PacifidlogTown/scripts.pory"
	.string "SLATEPORT has a fast-running tide.\p"
# 312 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you decide to SURF, you could end\n"
# 313 "data/maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 314 "data/maps/PacifidlogTown/scripts.pory"

# 315 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 316 "data/maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 317 "data/maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 318 "data/maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 319 "data/maps/PacifidlogTown/scripts.pory"

# 320 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 321 "data/maps/PacifidlogTown/scripts.pory"
	.string "The SKY PILLAR?\p"
# 322 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 323 "data/maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 324 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 325 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 326 "data/maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in PACIFIDLOG,\n"
# 327 "data/maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 328 "data/maps/PacifidlogTown/scripts.pory"

# 329 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 330 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 331 "data/maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 332 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"
# 333 "data/maps/PacifidlogTown/scripts.pory"

# 334 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_GladToSeeYou:
# 335 "data/maps/PacifidlogTown/scripts.pory"
	.string "Welcome home, kiddo!\p"
# 336 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Your dad looks a bit tired.)\p"
# 337 "data/maps/PacifidlogTown/scripts.pory"
	.string "Your… uh… your vessel was a mighty bit\n"
# 338 "data/maps/PacifidlogTown/scripts.pory"
	.string "off-schedule.\l"
# 339 "data/maps/PacifidlogTown/scripts.pory"
	.string "I've been planted here for a while!\l"
# 340 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's all worth it in the end to see my\l"
# 341 "data/maps/PacifidlogTown/scripts.pory"
	.string "little professor prodigy!\p"
# 342 "data/maps/PacifidlogTown/scripts.pory"
	.string "Listen, I know it's not Littleroot,\n"
# 343 "data/maps/PacifidlogTown/scripts.pory"
	.string "but Pacifidlog is a lovely town that has\l"
# 344 "data/maps/PacifidlogTown/scripts.pory"
	.string "welcomed me with open arms.\l"
# 345 "data/maps/PacifidlogTown/scripts.pory"
	.string "Let's take a quick jog to the lab!$"
# 346 "data/maps/PacifidlogTown/scripts.pory"

# 347 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_PacifidlogTownIsNice:
# 348 "data/maps/PacifidlogTown/scripts.pory"
	.string "Feeling a bit nostalgic, huh?\n"
# 349 "data/maps/PacifidlogTown/scripts.pory"
	.string "Ha, it feels like just yesterday when you\l"
# 350 "data/maps/PacifidlogTown/scripts.pory"
	.string "left the nest to go on your journey!\p"
# 351 "data/maps/PacifidlogTown/scripts.pory"
	.string "(You think about how you\n"
# 352 "data/maps/PacifidlogTown/scripts.pory"
	.string "cut your journey short last time.\l"
# 353 "data/maps/PacifidlogTown/scripts.pory"
	.string "It makes you wistful…)\p"
# 354 "data/maps/PacifidlogTown/scripts.pory"
	.string "Aw, why the frown, {PLAYER}?\n"
# 355 "data/maps/PacifidlogTown/scripts.pory"
	.string "Don't ever think you let your old man down.\l"
# 356 "data/maps/PacifidlogTown/scripts.pory"
	.string "You've done well for yourself.\p"
# 357 "data/maps/PacifidlogTown/scripts.pory"
	.string "…\p"
# 358 "data/maps/PacifidlogTown/scripts.pory"
	.string "…What happened to Norman's kid?\p"
# 359 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hmm…\n"
# 360 "data/maps/PacifidlogTown/scripts.pory"
	.string "good question.\p"
# 361 "data/maps/PacifidlogTown/scripts.pory"
	.string "Shortly into their reign as the\n"
# 362 "data/maps/PacifidlogTown/scripts.pory"
	.string "Champion, they disappeared.\l"
# 363 "data/maps/PacifidlogTown/scripts.pory"
	.string "Their family seems to know what's up,\l"
# 364 "data/maps/PacifidlogTown/scripts.pory"
	.string "but they haven't divulged anything.\l"
# 365 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's been left a mystery.\p"
# 366 "data/maps/PacifidlogTown/scripts.pory"
	.string "…I can see that you\n"
# 367 "data/maps/PacifidlogTown/scripts.pory"
	.string "probably wanted to reconnect with them,\l"
# 368 "data/maps/PacifidlogTown/scripts.pory"
	.string "kiddo.\p"
# 369 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'll try and pry some more\n"
# 370 "data/maps/PacifidlogTown/scripts.pory"
	.string "with Norman later.$"
# 371 "data/maps/PacifidlogTown/scripts.pory"

# 372 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_ResearchingTheLegends:
# 373 "data/maps/PacifidlogTown/scripts.pory"
	.string "You know…\p"
# 374 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Hoenn has changed a lot since\n"
# 375 "data/maps/PacifidlogTown/scripts.pory"
	.string "last time, {PLAYER}.\l"
# 376 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's practically a new region!\p"
# 377 "data/maps/PacifidlogTown/scripts.pory"
	.string "And, y'know, I think it'd be very\n"
# 378 "data/maps/PacifidlogTown/scripts.pory"
	.string "fulfilling to explore it again!\p"
# 379 "data/maps/PacifidlogTown/scripts.pory"
	.string "(You begin to feel a deep\n"
# 380 "data/maps/PacifidlogTown/scripts.pory"
	.string "resolve brewing…)\p"
# 381 "data/maps/PacifidlogTown/scripts.pory"
	.string "Of course, I'd love to\n"
# 382 "data/maps/PacifidlogTown/scripts.pory"
	.string "have us stay here and have\l"
# 383 "data/maps/PacifidlogTown/scripts.pory"
	.string "a quiet vacation.\l"
# 384 "data/maps/PacifidlogTown/scripts.pory"
	.string "But there's always time to relax and\l"
# 385 "data/maps/PacifidlogTown/scripts.pory"
	.string "catch up.\p"
# 386 "data/maps/PacifidlogTown/scripts.pory"
	.string "I sense that you want a do-over.\n"
# 387 "data/maps/PacifidlogTown/scripts.pory"
	.string "A chance to go above and beyond!\l"
# 388 "data/maps/PacifidlogTown/scripts.pory"
	.string "That's the {PLAYER} I love.$"
# 389 "data/maps/PacifidlogTown/scripts.pory"

# 390 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CouldUseYourHelp:
# 391 "data/maps/PacifidlogTown/scripts.pory"
	.string "(You nod, determined, at your dad.)\p"
# 392 "data/maps/PacifidlogTown/scripts.pory"
	.string "That look in your eye!\n"
# 393 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's tenacious!\p"
# 394 "data/maps/PacifidlogTown/scripts.pory"
	.string "Well, let's get this show on the road.\p"
# 395 "data/maps/PacifidlogTown/scripts.pory"
	.string "Come on in; I'll get you set up.$"
# 396 "data/maps/PacifidlogTown/scripts.pory"

# 397 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs1:
# 398 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 399 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 400 "data/maps/PacifidlogTown/scripts.pory"
	.string "W-What did the boss stuff into\n"
# 401 "data/maps/PacifidlogTown/scripts.pory"
	.string "this box again?\p"
# 402 "data/maps/PacifidlogTown/scripts.pory"
	.string "...200 pounds of fish!? Ridiculous!\p"
# 403 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 404 "data/maps/PacifidlogTown/scripts.pory"

# 405 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs2:
# 406 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 407 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 408 "data/maps/PacifidlogTown/scripts.pory"
	.string "You know, I wish we could just push\n"
# 409 "data/maps/PacifidlogTown/scripts.pory"
	.string "the crate off the dock and let\l"
# 410 "data/maps/PacifidlogTown/scripts.pory"
	.string "the Vangar have at it.\p"
# 411 "data/maps/PacifidlogTown/scripts.pory"
	.string "...But then I'd get fired.\p"
# 412 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 413 "data/maps/PacifidlogTown/scripts.pory"

# 414 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Roadblockdeactivated:
# 415 "data/maps/PacifidlogTown/scripts.pory"
	.string "roadblock off$"
# 416 "data/maps/PacifidlogTown/scripts.pory"

# 417 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RestingSailor:
# 418 "data/maps/PacifidlogTown/scripts.pory"
	.string "Takin' the load off today before\n"
# 419 "data/maps/PacifidlogTown/scripts.pory"
	.string "me n' the other sailors\l"
# 420 "data/maps/PacifidlogTown/scripts.pory"
	.string "head out westward.\p"
# 421 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is the perfect lazy town\n"
# 422 "data/maps/PacifidlogTown/scripts.pory"
	.string "to forget about work in, I'd say!$"
# 423 "data/maps/PacifidlogTown/scripts.pory"

# 424 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF1:
# 425 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog's water is a breathtaking\n"
# 426 "data/maps/PacifidlogTown/scripts.pory"
	.string "place to take a dip in!\p"
# 427 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral structures blow my mind!$"
# 428 "data/maps/PacifidlogTown/scripts.pory"

# 429 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF2:
# 430 "data/maps/PacifidlogTown/scripts.pory"
	.string "Last week I stubbed my toe hopping\n"
# 431 "data/maps/PacifidlogTown/scripts.pory"
	.string "into the water on these docks.\l"
# 432 "data/maps/PacifidlogTown/scripts.pory"
	.string "There's untold amounts of jagged\l"
# 433 "data/maps/PacifidlogTown/scripts.pory"
	.string "coral strewn about down there...$"
# 434 "data/maps/PacifidlogTown/scripts.pory"

# 435 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_StockingSailor:
# 436 "data/maps/PacifidlogTown/scripts.pory"
	.string "Dum-dee-dum-dee-dum...\p"
# 437 "data/maps/PacifidlogTown/scripts.pory"
	.string "Oh? Why am I stocking\n"
# 438 "data/maps/PacifidlogTown/scripts.pory"
	.string "lox into this barrel?\p"
# 439 "data/maps/PacifidlogTown/scripts.pory"
	.string "Strict orders from my superior!\n"
# 440 "data/maps/PacifidlogTown/scripts.pory"
	.string "He said it'd be kinda funny.$"
# 441 "data/maps/PacifidlogTown/scripts.pory"

# 442 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Wayfarer:
# 443 "data/maps/PacifidlogTown/scripts.pory"
	.string "Rumor has it that there's a land full\n"
# 444 "data/maps/PacifidlogTown/scripts.pory"
	.string "of really tough battlers due south.\p"
# 445 "data/maps/PacifidlogTown/scripts.pory"
	.string "(You look southward and can make out\n"
# 446 "data/maps/PacifidlogTown/scripts.pory"
	.string "a few islands made of golden rocks.)\p"
# 447 "data/maps/PacifidlogTown/scripts.pory"
	.string "What, are you wanting to check it out\n"
# 448 "data/maps/PacifidlogTown/scripts.pory"
	.string "someday? Be my guest!$"
# 449 "data/maps/PacifidlogTown/scripts.pory"

# 450 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_HaveThisShell:
# 451 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hey! Lookit one of these cool\n"
# 452 "data/maps/PacifidlogTown/scripts.pory"
	.string "seashells I found in the water!\p"
# 453 "data/maps/PacifidlogTown/scripts.pory"
	.string "Do you like collecting shells too?\n"
# 454 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'll let you keep it if you promise\l"
# 455 "data/maps/PacifidlogTown/scripts.pory"
	.string "to take care of it!$"
# 456 "data/maps/PacifidlogTown/scripts.pory"

# 457 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller1:
# 458 "data/maps/PacifidlogTown/scripts.pory"
	.string "I heard from my friend that\n"
# 459 "data/maps/PacifidlogTown/scripts.pory"
	.string "there's a nice lady in Sootopolis\l"
# 460 "data/maps/PacifidlogTown/scripts.pory"
	.string "that makes a special item\l"
# 461 "data/maps/PacifidlogTown/scripts.pory"
	.string "out of sea shells!\p"
# 462 "data/maps/PacifidlogTown/scripts.pory"
	.string "And I think something else, but...\n"
# 463 "data/maps/PacifidlogTown/scripts.pory"
	.string "I forgot that part.$"
# 464 "data/maps/PacifidlogTown/scripts.pory"

# 465 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller2:
# 466 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mom told me to stop runnin' on\n"
# 467 "data/maps/PacifidlogTown/scripts.pory"
	.string "the docks. Hah! No way that I'll get\l"
# 468 "data/maps/PacifidlogTown/scripts.pory"
	.string "hurt! The wood isn't THAT slippery!\p"
# 469 "data/maps/PacifidlogTown/scripts.pory"
	.string "(His ankles and shins are clearly\n"
# 470 "data/maps/PacifidlogTown/scripts.pory"
	.string "bruised all over.)$"
# 471 "data/maps/PacifidlogTown/scripts.pory"

# 472 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_GiddyWoman:
# 473 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm positively BEAMING!\n"
# 474 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is such an underrated,\l"
# 475 "data/maps/PacifidlogTown/scripts.pory"
	.string "beautiful Hoenn locale!$"
# 476 "data/maps/PacifidlogTown/scripts.pory"

# 477 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_ManWorkingOut:
# 478 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral branches can double as\n"
# 479 "data/maps/PacifidlogTown/scripts.pory"
	.string "pull-up bars! I know, I've tried!\p"
# 480 "data/maps/PacifidlogTown/scripts.pory"
	.string "They're surprisingly rock solid.\p"
# 481 "data/maps/PacifidlogTown/scripts.pory"
	.string "Except when they're not. You kinda\n"
# 482 "data/maps/PacifidlogTown/scripts.pory"
	.string "have to figure that out through\l"
# 483 "data/maps/PacifidlogTown/scripts.pory"
	.string "trial and error.$"
# 484 "data/maps/PacifidlogTown/scripts.pory"

# 485 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher1:
# 486 "data/maps/PacifidlogTown/scripts.pory"
	.string "I don't know about you, but I feel like\n"
# 487 "data/maps/PacifidlogTown/scripts.pory"
	.string "I pull better catches the higher up\l"
# 488 "data/maps/PacifidlogTown/scripts.pory"
	.string "my post is.\p"
# 489 "data/maps/PacifidlogTown/scripts.pory"
	.string "I got a long enough rod to pull it off!\p"
# 490 "data/maps/PacifidlogTown/scripts.pory"
	.string "Stop snickering!$"
# 491 "data/maps/PacifidlogTown/scripts.pory"

# 492 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher2:
# 493 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Snelfrend around here are too nice\n"
# 494 "data/maps/PacifidlogTown/scripts.pory"
	.string "for their own good. I want to reel up\l"
# 495 "data/maps/PacifidlogTown/scripts.pory"
	.string "some actual fish, but every time\l"
# 496 "data/maps/PacifidlogTown/scripts.pory"
	.string "I cast out, one of these friendly\l"
# 497 "data/maps/PacifidlogTown/scripts.pory"
	.string "buggers clings to the hook\l"
# 498 "data/maps/PacifidlogTown/scripts.pory"
	.string "and won't let go!$"
# 499 "data/maps/PacifidlogTown/scripts.pory"

# 500 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CoralScientist:
# 501 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hello, {PLAYER}. I've been helping\n"
# 502 "data/maps/PacifidlogTown/scripts.pory"
	.string "your dad with researching the biology\l"
# 503 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the healthy coral deposits in\l"
# 504 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters surrounding Pacifidlog.\p"
# 505 "data/maps/PacifidlogTown/scripts.pory"
	.string "He seems to think that they can\n"
# 506 "data/maps/PacifidlogTown/scripts.pory"
	.string "be used as part of a plan to\l"
# 507 "data/maps/PacifidlogTown/scripts.pory"
	.string "clean up the water pollution\l"
# 508 "data/maps/PacifidlogTown/scripts.pory"
	.string "in the bigger cities, but\l"
# 509 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm not so sure it's that easy...$"
# 510 "data/maps/PacifidlogTown/scripts.pory"

# 511 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FishScientist:
# 512 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Water and Rock type POKéMON\n"
# 513 "data/maps/PacifidlogTown/scripts.pory"
	.string "Marinaroc are likely the cause\l"
# 514 "data/maps/PacifidlogTown/scripts.pory"
	.string "of Pacifidlog Town's extremely\l"
# 515 "data/maps/PacifidlogTown/scripts.pory"
	.string "healthy oceanic habitat.\p"
# 516 "data/maps/PacifidlogTown/scripts.pory"
	.string "You see, {PLAYER}, they are able to\n"
# 517 "data/maps/PacifidlogTown/scripts.pory"
	.string "filter the water they swim through.\l"
# 518 "data/maps/PacifidlogTown/scripts.pory"
	.string "They love doing their part to\l"
# 519 "data/maps/PacifidlogTown/scripts.pory"
	.string "keep the natural coral here healthy.\p"
# 520 "data/maps/PacifidlogTown/scripts.pory"
	.string "They prove very hard to fish\n"
# 521 "data/maps/PacifidlogTown/scripts.pory"
	.string "up because of their weight, too;\l"
# 522 "data/maps/PacifidlogTown/scripts.pory"
	.string "perfect for avoiding trophy hunting\l"
# 523 "data/maps/PacifidlogTown/scripts.pory"
	.string "or a potential overfishing problem!$"
# 524 "data/maps/PacifidlogTown/scripts.pory"

# 525 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RunningTuber:
# 526 "data/maps/PacifidlogTown/scripts.pory"
	.string "VAN-GUARD!\p"
# 527 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The child brandishes a balloon\n"
# 528 "data/maps/PacifidlogTown/scripts.pory"
	.string "cutlass at you.\l"
# 529 "data/maps/PacifidlogTown/scripts.pory"
	.string "You dramatically feign surrender.)\p"
# 530 "data/maps/PacifidlogTown/scripts.pory"
	.string "That's right! I'M the pirate captain!\n"
# 531 "data/maps/PacifidlogTown/scripts.pory"
	.string "YARRR!$"
# 532 "data/maps/PacifidlogTown/scripts.pory"

# 533 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NorthToSkyPillar:
# 534 "data/maps/PacifidlogTown/scripts.pory"
	.string "NORTH: SKY PILLAR\p"
# 535 "data/maps/PacifidlogTown/scripts.pory"
	.string "We ask you to respect this historical\n"
# 536 "data/maps/PacifidlogTown/scripts.pory"
	.string "monument and to keep it clean.$"
# 537 "data/maps/PacifidlogTown/scripts.pory"

# 538 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_EastToFlotshoreTrail:
# 539 "data/maps/PacifidlogTown/scripts.pory"
	.string "EAST: FLOTSHORE TRAIL\p"
# 540 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mondays through Thursdays are\n"
# 541 "data/maps/PacifidlogTown/scripts.pory"
	.string "scheduled bulk-fishing days.\l"
# 542 "data/maps/PacifidlogTown/scripts.pory"
	.string "All recreational fishers and swimmers\l"
# 543 "data/maps/PacifidlogTown/scripts.pory"
	.string "should be respectful and stay out\l"
# 544 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the way on those dates.$"
# 545 "data/maps/PacifidlogTown/scripts.pory"

# 546 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_LabSign:
# 547 "data/maps/PacifidlogTown/scripts.pory"
	.string "PROFESSOR BIRCH'S\n"
# 548 "data/maps/PacifidlogTown/scripts.pory"
	.string "MARITIME POKéMON LAB$"
# 549 "data/maps/PacifidlogTown/scripts.pory"

# 550 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SadFisherHouse:
# 551 "data/maps/PacifidlogTown/scripts.pory"
	.string "See me if you're serious about\n"
# 552 "data/maps/PacifidlogTown/scripts.pory"
	.string "fishing for strong POKéMON.$"
# 553 "data/maps/PacifidlogTown/scripts.pory"

# 554 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_PacifidlogTownSign:
# 555 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 556 "data/maps/PacifidlogTown/scripts.pory"
	.string "Where the morning sun\n"
# 557 "data/maps/PacifidlogTown/scripts.pory"
	.string "smiles upon the waters.$"
# 558 "data/maps/PacifidlogTown/scripts.pory"

# 559 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BigCoral:
# 560 "data/maps/PacifidlogTown/scripts.pory"
	.string "(It's a large natural\n"
# 561 "data/maps/PacifidlogTown/scripts.pory"
	.string "structure made of coral.)$"
# 562 "data/maps/PacifidlogTown/scripts.pory"

# 563 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BoxLabel:
# 564 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The box is labelled...)\p"
# 565 "data/maps/PacifidlogTown/scripts.pory"
	.string "DINNER FOR THREE$"

PacifidlogTown_EventScript_TestSign::
# 569 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 570 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_EventScript_TestSign_Text_0
# 571 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
	return


PacifidlogTown_EventScript_TestSign_Text_0:
# 570 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Holy Diver Mod$"
