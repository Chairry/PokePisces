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
	setflag FLAG_HIDE_LAB_RANGERS
# 51 "data/maps/PacifidlogTown/scripts.pory"
	warp MAP_BIRCH_MARITIME_LAB, 9, 14
# 52 "data/maps/PacifidlogTown/scripts.pory"
	waitstate
# 53 "data/maps/PacifidlogTown/scripts.pory"
	release
# 54 "data/maps/PacifidlogTown/scripts.pory"
	end
# 55 "data/maps/PacifidlogTown/scripts.pory"

# 56 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchNotice:
# 57 "data/maps/PacifidlogTown/scripts.pory"
	emote_exclamation_mark
# 58 "data/maps/PacifidlogTown/scripts.pory"
	jump_in_place_right
# 59 "data/maps/PacifidlogTown/scripts.pory"
	walk_fast_right
# 60 "data/maps/PacifidlogTown/scripts.pory"
	walk_fast_right
# 61 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 62 "data/maps/PacifidlogTown/scripts.pory"

# 63 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerNotice:
# 64 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 65 "data/maps/PacifidlogTown/scripts.pory"
	delay_8
# 66 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 67 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 68 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 69 "data/maps/PacifidlogTown/scripts.pory"

# 70 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk1:
# 71 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 72 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 73 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
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
	walk_left
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
	face_right
# 95 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 96 "data/maps/PacifidlogTown/scripts.pory"

# 97 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk1:
# 98 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 99 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 100 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 101 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
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
	walk_left
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
	step_end
# 122 "data/maps/PacifidlogTown/scripts.pory"

# 123 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk2:
# 124 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
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
	walk_up
# 136 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 137 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 138 "data/maps/PacifidlogTown/scripts.pory"

# 139 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk2:
# 140 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
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
	face_left
# 153 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 154 "data/maps/PacifidlogTown/scripts.pory"

# 155 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk3:
# 156 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 157 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 158 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 159 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 160 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 161 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 162 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 163 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 164 "data/maps/PacifidlogTown/scripts.pory"
	face_down
# 165 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 166 "data/maps/PacifidlogTown/scripts.pory"

# 167 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk3:
# 168 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 169 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 170 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 171 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 172 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 173 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 174 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 175 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 176 "data/maps/PacifidlogTown/scripts.pory"
	face_up
# 177 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 178 "data/maps/PacifidlogTown/scripts.pory"

# 179 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NinjaBoy::
# 180 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
# 181 "data/maps/PacifidlogTown/scripts.pory"
	end
# 182 "data/maps/PacifidlogTown/scripts.pory"

# 183 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Girl::
# 184 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
# 185 "data/maps/PacifidlogTown/scripts.pory"
	end
# 186 "data/maps/PacifidlogTown/scripts.pory"

# 187 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Fisherman::
# 188 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
# 189 "data/maps/PacifidlogTown/scripts.pory"
	end
# 190 "data/maps/PacifidlogTown/scripts.pory"

# 191 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TownSign::
# 192 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
# 193 "data/maps/PacifidlogTown/scripts.pory"
	end
# 194 "data/maps/PacifidlogTown/scripts.pory"

# 195 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_1::
# 196 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 197 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs1
# 198 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 199 "data/maps/PacifidlogTown/scripts.pory"
	end
# 200 "data/maps/PacifidlogTown/scripts.pory"

# 201 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_2::
# 202 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 203 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs2
# 204 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 205 "data/maps/PacifidlogTown/scripts.pory"
	end
# 206 "data/maps/PacifidlogTown/scripts.pory"

# 207 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BetatestingRoadblock::
# 208 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Roadblockdeactivated, MSGBOX_NPC
# 209 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_PACIFIDLOG_ROADBLOCK
# 210 "data/maps/PacifidlogTown/scripts.pory"
	end
# 211 "data/maps/PacifidlogTown/scripts.pory"

# 212 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RestingSailor::
# 213 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RestingSailor, MSGBOX_NPC
# 214 "data/maps/PacifidlogTown/scripts.pory"
	end
# 215 "data/maps/PacifidlogTown/scripts.pory"

# 216 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF1::
# 217 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF1, MSGBOX_NPC
# 218 "data/maps/PacifidlogTown/scripts.pory"
	end
# 219 "data/maps/PacifidlogTown/scripts.pory"

# 220 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF2::
# 221 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF2, MSGBOX_NPC
# 222 "data/maps/PacifidlogTown/scripts.pory"
	end
# 223 "data/maps/PacifidlogTown/scripts.pory"

# 224 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_StockingSailor::
# 225 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_StockingSailor, MSGBOX_NPC
# 226 "data/maps/PacifidlogTown/scripts.pory"
	end
# 227 "data/maps/PacifidlogTown/scripts.pory"

# 228 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Wayfarer::
# 229 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Wayfarer, MSGBOX_NPC
# 230 "data/maps/PacifidlogTown/scripts.pory"
	end
# 231 "data/maps/PacifidlogTown/scripts.pory"

# 232 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller1::
# 233 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 234 "data/maps/PacifidlogTown/scripts.pory"
	faceplayer
# 235 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_SEASHELL_1, PacifidlogTown_EventScript_GaveShell
# 236 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_HaveThisShell, MSGBOX_DEFAULT
# 237 "data/maps/PacifidlogTown/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 238 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 239 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_RECEIVED_SEASHELL_1
# 240 "data/maps/PacifidlogTown/scripts.pory"
	release
# 241 "data/maps/PacifidlogTown/scripts.pory"
	end
# 242 "data/maps/PacifidlogTown/scripts.pory"

# 243 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GaveShell::
# 244 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller1, MSGBOX_DEFAULT
# 245 "data/maps/PacifidlogTown/scripts.pory"
	release
# 246 "data/maps/PacifidlogTown/scripts.pory"
	end
# 247 "data/maps/PacifidlogTown/scripts.pory"

# 248 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller2::
# 249 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller2, MSGBOX_NPC
# 250 "data/maps/PacifidlogTown/scripts.pory"
	end
# 251 "data/maps/PacifidlogTown/scripts.pory"

# 252 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GiddyWoman::
# 253 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_GiddyWoman, MSGBOX_NPC
# 254 "data/maps/PacifidlogTown/scripts.pory"
	end
# 255 "data/maps/PacifidlogTown/scripts.pory"

# 256 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_ManWorkingOut::
# 257 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_ManWorkingOut, MSGBOX_NPC
# 258 "data/maps/PacifidlogTown/scripts.pory"
	end
# 259 "data/maps/PacifidlogTown/scripts.pory"

# 260 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher1::
# 261 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher1, MSGBOX_NPC
# 262 "data/maps/PacifidlogTown/scripts.pory"
	end
# 263 "data/maps/PacifidlogTown/scripts.pory"

# 264 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher2::
# 265 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher2, MSGBOX_NPC
# 266 "data/maps/PacifidlogTown/scripts.pory"
	end
# 267 "data/maps/PacifidlogTown/scripts.pory"

# 268 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_CoralScientist::
# 269 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CoralScientist, MSGBOX_NPC
# 270 "data/maps/PacifidlogTown/scripts.pory"
	end
# 271 "data/maps/PacifidlogTown/scripts.pory"

# 272 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_FishScientist::
# 273 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FishScientist, MSGBOX_NPC
# 274 "data/maps/PacifidlogTown/scripts.pory"
	end
# 275 "data/maps/PacifidlogTown/scripts.pory"

# 276 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RunningTuber::
# 277 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RunningTuber, MSGBOX_NPC
# 278 "data/maps/PacifidlogTown/scripts.pory"
	end
# 279 "data/maps/PacifidlogTown/scripts.pory"

# 280 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NorthToSkyPillar::
# 281 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NorthToSkyPillar, MSGBOX_SIGN
# 282 "data/maps/PacifidlogTown/scripts.pory"
	end
# 283 "data/maps/PacifidlogTown/scripts.pory"

# 284 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_EastToFlotshoreTrail::
# 285 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_EastToFlotshoreTrail, MSGBOX_SIGN
# 286 "data/maps/PacifidlogTown/scripts.pory"
	end
# 287 "data/maps/PacifidlogTown/scripts.pory"

# 288 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_LabSign::
# 289 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_LabSign, MSGBOX_SIGN
# 290 "data/maps/PacifidlogTown/scripts.pory"
	end
# 291 "data/maps/PacifidlogTown/scripts.pory"

# 292 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SadFisherHouse::
# 293 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SadFisherHouse, MSGBOX_SIGN
# 294 "data/maps/PacifidlogTown/scripts.pory"
	end
# 295 "data/maps/PacifidlogTown/scripts.pory"

# 296 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_PacifidlogTownSign::
# 297 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_PacifidlogTownSign, MSGBOX_SIGN
# 298 "data/maps/PacifidlogTown/scripts.pory"
	end
# 299 "data/maps/PacifidlogTown/scripts.pory"

# 300 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BigCoral::
# 301 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BigCoral, MSGBOX_SIGN
# 302 "data/maps/PacifidlogTown/scripts.pory"
	end
# 303 "data/maps/PacifidlogTown/scripts.pory"

# 304 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BoxLabel::
# 305 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BoxLabel, MSGBOX_SIGN
# 306 "data/maps/PacifidlogTown/scripts.pory"
	end
# 307 "data/maps/PacifidlogTown/scripts.pory"

# 308 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 309 "data/maps/PacifidlogTown/scripts.pory"
	.string "The sea between PACIFIDLOG and\n"
# 310 "data/maps/PacifidlogTown/scripts.pory"
	.string "SLATEPORT has a fast-running tide.\p"
# 311 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you decide to SURF, you could end\n"
# 312 "data/maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 313 "data/maps/PacifidlogTown/scripts.pory"

# 314 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 315 "data/maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 316 "data/maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 317 "data/maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 318 "data/maps/PacifidlogTown/scripts.pory"

# 319 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 320 "data/maps/PacifidlogTown/scripts.pory"
	.string "The SKY PILLAR?\p"
# 321 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 322 "data/maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 323 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 324 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 325 "data/maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in PACIFIDLOG,\n"
# 326 "data/maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 327 "data/maps/PacifidlogTown/scripts.pory"

# 328 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 329 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 330 "data/maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 331 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"
# 332 "data/maps/PacifidlogTown/scripts.pory"

# 333 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_GladToSeeYou:
# 334 "data/maps/PacifidlogTown/scripts.pory"
	.string "test1$"
# 335 "data/maps/PacifidlogTown/scripts.pory"

# 336 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_PacifidlogTownIsNice:
# 337 "data/maps/PacifidlogTown/scripts.pory"
	.string "test2$"
# 338 "data/maps/PacifidlogTown/scripts.pory"

# 339 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_ResearchingTheLegends:
# 340 "data/maps/PacifidlogTown/scripts.pory"
	.string "test3$"
# 341 "data/maps/PacifidlogTown/scripts.pory"

# 342 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CouldUseYourHelp:
# 343 "data/maps/PacifidlogTown/scripts.pory"
	.string "test4$"
# 344 "data/maps/PacifidlogTown/scripts.pory"

# 345 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs1:
# 346 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 347 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 348 "data/maps/PacifidlogTown/scripts.pory"
	.string "W-What did the boss stuff into\n"
# 349 "data/maps/PacifidlogTown/scripts.pory"
	.string "this box again?\p"
# 350 "data/maps/PacifidlogTown/scripts.pory"
	.string "...200 pounds of fish!? Ridiculous!\p"
# 351 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 352 "data/maps/PacifidlogTown/scripts.pory"

# 353 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs2:
# 354 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 355 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 356 "data/maps/PacifidlogTown/scripts.pory"
	.string "You know, I wish we could just push\n"
# 357 "data/maps/PacifidlogTown/scripts.pory"
	.string "the crate off the dock and let\l"
# 358 "data/maps/PacifidlogTown/scripts.pory"
	.string "the Vangar have at it.\p"
# 359 "data/maps/PacifidlogTown/scripts.pory"
	.string "...But then I'd get fired.\p"
# 360 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 361 "data/maps/PacifidlogTown/scripts.pory"

# 362 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Roadblockdeactivated:
# 363 "data/maps/PacifidlogTown/scripts.pory"
	.string "roadblock off$"
# 364 "data/maps/PacifidlogTown/scripts.pory"

# 365 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RestingSailor:
# 366 "data/maps/PacifidlogTown/scripts.pory"
	.string "Takin' the load off today before\n"
# 367 "data/maps/PacifidlogTown/scripts.pory"
	.string "me n' the other sailors\l"
# 368 "data/maps/PacifidlogTown/scripts.pory"
	.string "head out westward.\p"
# 369 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is the perfect lazy town\n"
# 370 "data/maps/PacifidlogTown/scripts.pory"
	.string "to forget about work in, I'd say!$"
# 371 "data/maps/PacifidlogTown/scripts.pory"

# 372 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF1:
# 373 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog's water is a breathtaking\n"
# 374 "data/maps/PacifidlogTown/scripts.pory"
	.string "place to take a dip in!\p"
# 375 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral structures blow my mind!$"
# 376 "data/maps/PacifidlogTown/scripts.pory"

# 377 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF2:
# 378 "data/maps/PacifidlogTown/scripts.pory"
	.string "Last week I stubbed my toe hopping\n"
# 379 "data/maps/PacifidlogTown/scripts.pory"
	.string "into the water on these docks.\l"
# 380 "data/maps/PacifidlogTown/scripts.pory"
	.string "There's untold amounts of jagged\l"
# 381 "data/maps/PacifidlogTown/scripts.pory"
	.string "coral strewn about down there...$"
# 382 "data/maps/PacifidlogTown/scripts.pory"

# 383 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_StockingSailor:
# 384 "data/maps/PacifidlogTown/scripts.pory"
	.string "Dum-dee-dum-dee-dum...\p"
# 385 "data/maps/PacifidlogTown/scripts.pory"
	.string "Oh? Why am I stocking\n"
# 386 "data/maps/PacifidlogTown/scripts.pory"
	.string "lox into this barrel?\p"
# 387 "data/maps/PacifidlogTown/scripts.pory"
	.string "Strict orders from my superior!\n"
# 388 "data/maps/PacifidlogTown/scripts.pory"
	.string "He said it'd be kinda funny.$"
# 389 "data/maps/PacifidlogTown/scripts.pory"

# 390 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Wayfarer:
# 391 "data/maps/PacifidlogTown/scripts.pory"
	.string "Rumor has it that there's a land full\n"
# 392 "data/maps/PacifidlogTown/scripts.pory"
	.string "of really tough battlers due south.\p"
# 393 "data/maps/PacifidlogTown/scripts.pory"
	.string "(You look southward and can make out\n"
# 394 "data/maps/PacifidlogTown/scripts.pory"
	.string "a few islands made of golden rocks.)\p"
# 395 "data/maps/PacifidlogTown/scripts.pory"
	.string "What, are you wanting to check it out\n"
# 396 "data/maps/PacifidlogTown/scripts.pory"
	.string "someday? Be my guest!$"
# 397 "data/maps/PacifidlogTown/scripts.pory"

# 398 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_HaveThisShell:
# 399 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hey! Lookit one of these cool\n"
# 400 "data/maps/PacifidlogTown/scripts.pory"
	.string "seashells I found in the water!\p"
# 401 "data/maps/PacifidlogTown/scripts.pory"
	.string "Do you like collecting shells too?\n"
# 402 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'll let you keep it if you promise\l"
# 403 "data/maps/PacifidlogTown/scripts.pory"
	.string "to take care of it!$"
# 404 "data/maps/PacifidlogTown/scripts.pory"

# 405 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller1:
# 406 "data/maps/PacifidlogTown/scripts.pory"
	.string "I heard from my friend that\n"
# 407 "data/maps/PacifidlogTown/scripts.pory"
	.string "there's a nice lady in Sootopolis\l"
# 408 "data/maps/PacifidlogTown/scripts.pory"
	.string "that makes a special item\l"
# 409 "data/maps/PacifidlogTown/scripts.pory"
	.string "out of sea shells!\p"
# 410 "data/maps/PacifidlogTown/scripts.pory"
	.string "And I think something else, but...\n"
# 411 "data/maps/PacifidlogTown/scripts.pory"
	.string "I forgot that part.$"
# 412 "data/maps/PacifidlogTown/scripts.pory"

# 413 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller2:
# 414 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mom told me to stop runnin' on\n"
# 415 "data/maps/PacifidlogTown/scripts.pory"
	.string "the docks. Hah! No way that I'll get\l"
# 416 "data/maps/PacifidlogTown/scripts.pory"
	.string "hurt! The wood isn't THAT slippery!\p"
# 417 "data/maps/PacifidlogTown/scripts.pory"
	.string "(His ankles and shins are clearly\n"
# 418 "data/maps/PacifidlogTown/scripts.pory"
	.string "bruised all over.)$"
# 419 "data/maps/PacifidlogTown/scripts.pory"

# 420 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_GiddyWoman:
# 421 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm positively BEAMING!\n"
# 422 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is such an underrated,\l"
# 423 "data/maps/PacifidlogTown/scripts.pory"
	.string "beautiful Hoenn locale!$"
# 424 "data/maps/PacifidlogTown/scripts.pory"

# 425 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_ManWorkingOut:
# 426 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral branches can double as\n"
# 427 "data/maps/PacifidlogTown/scripts.pory"
	.string "pull-up bars! I know, I've tried!\p"
# 428 "data/maps/PacifidlogTown/scripts.pory"
	.string "They're surprisingly rock solid.\p"
# 429 "data/maps/PacifidlogTown/scripts.pory"
	.string "Except when they're not. You kinda\n"
# 430 "data/maps/PacifidlogTown/scripts.pory"
	.string "have to figure that out through\l"
# 431 "data/maps/PacifidlogTown/scripts.pory"
	.string "trial and error.$"
# 432 "data/maps/PacifidlogTown/scripts.pory"

# 433 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher1:
# 434 "data/maps/PacifidlogTown/scripts.pory"
	.string "I don't know about you, but I feel like\n"
# 435 "data/maps/PacifidlogTown/scripts.pory"
	.string "I pull better catches the higher up\l"
# 436 "data/maps/PacifidlogTown/scripts.pory"
	.string "my post is.\p"
# 437 "data/maps/PacifidlogTown/scripts.pory"
	.string "I got a long enough rod to pull it off!\p"
# 438 "data/maps/PacifidlogTown/scripts.pory"
	.string "Stop snickering!$"
# 439 "data/maps/PacifidlogTown/scripts.pory"

# 440 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher2:
# 441 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Snelfrend around here are too nice\n"
# 442 "data/maps/PacifidlogTown/scripts.pory"
	.string "for their own good. I want to reel up\l"
# 443 "data/maps/PacifidlogTown/scripts.pory"
	.string "some actual fish, but every time\l"
# 444 "data/maps/PacifidlogTown/scripts.pory"
	.string "I cast out, one of these friendly\l"
# 445 "data/maps/PacifidlogTown/scripts.pory"
	.string "buggers clings to the hook\l"
# 446 "data/maps/PacifidlogTown/scripts.pory"
	.string "and won't let go!$"
# 447 "data/maps/PacifidlogTown/scripts.pory"

# 448 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CoralScientist:
# 449 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hello, {PLAYER}. I've been helping\n"
# 450 "data/maps/PacifidlogTown/scripts.pory"
	.string "your dad with researching the biology\l"
# 451 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the healthy coral deposits in\l"
# 452 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters surrounding Pacifidlog.\p"
# 453 "data/maps/PacifidlogTown/scripts.pory"
	.string "He seems to think that they can\n"
# 454 "data/maps/PacifidlogTown/scripts.pory"
	.string "be used as part of a plan to\l"
# 455 "data/maps/PacifidlogTown/scripts.pory"
	.string "clean up the water pollution\l"
# 456 "data/maps/PacifidlogTown/scripts.pory"
	.string "in the bigger cities, but\l"
# 457 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm not so sure it's that easy...$"
# 458 "data/maps/PacifidlogTown/scripts.pory"

# 459 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FishScientist:
# 460 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Water and Rock type POKéMON\n"
# 461 "data/maps/PacifidlogTown/scripts.pory"
	.string "Marinaroc are likely the cause\l"
# 462 "data/maps/PacifidlogTown/scripts.pory"
	.string "of Pacifidlog Town's extremely\l"
# 463 "data/maps/PacifidlogTown/scripts.pory"
	.string "healthy oceanic habitat.\p"
# 464 "data/maps/PacifidlogTown/scripts.pory"
	.string "You see, {PLAYER}, they are able to\n"
# 465 "data/maps/PacifidlogTown/scripts.pory"
	.string "filter the water they swim through.\l"
# 466 "data/maps/PacifidlogTown/scripts.pory"
	.string "They love doing their part to\l"
# 467 "data/maps/PacifidlogTown/scripts.pory"
	.string "keep the natural coral here healthy.\p"
# 468 "data/maps/PacifidlogTown/scripts.pory"
	.string "They prove very hard to fish\n"
# 469 "data/maps/PacifidlogTown/scripts.pory"
	.string "up because of their weight, too;\l"
# 470 "data/maps/PacifidlogTown/scripts.pory"
	.string "perfect for avoiding trophy hunting\l"
# 471 "data/maps/PacifidlogTown/scripts.pory"
	.string "or a potential overfishing problem!$"
# 472 "data/maps/PacifidlogTown/scripts.pory"

# 473 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RunningTuber:
# 474 "data/maps/PacifidlogTown/scripts.pory"
	.string "VAN-GUARD!\p"
# 475 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The child brandishes a balloon\n"
# 476 "data/maps/PacifidlogTown/scripts.pory"
	.string "cutlass at you.\l"
# 477 "data/maps/PacifidlogTown/scripts.pory"
	.string "You dramatically feign surrender.)\p"
# 478 "data/maps/PacifidlogTown/scripts.pory"
	.string "That's right! I'M the pirate captain!\n"
# 479 "data/maps/PacifidlogTown/scripts.pory"
	.string "YARRR!$"
# 480 "data/maps/PacifidlogTown/scripts.pory"

# 481 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NorthToSkyPillar:
# 482 "data/maps/PacifidlogTown/scripts.pory"
	.string "NORTH: SKY PILLAR\p"
# 483 "data/maps/PacifidlogTown/scripts.pory"
	.string "We ask you to respect this historical\n"
# 484 "data/maps/PacifidlogTown/scripts.pory"
	.string "monument and to keep it clean.$"
# 485 "data/maps/PacifidlogTown/scripts.pory"

# 486 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_EastToFlotshoreTrail:
# 487 "data/maps/PacifidlogTown/scripts.pory"
	.string "EAST: FLOTSHORE TRAIL\p"
# 488 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mondays through Thursdays are\n"
# 489 "data/maps/PacifidlogTown/scripts.pory"
	.string "scheduled bulk-fishing days.\l"
# 490 "data/maps/PacifidlogTown/scripts.pory"
	.string "All recreational fishers and swimmers\l"
# 491 "data/maps/PacifidlogTown/scripts.pory"
	.string "should be respectful and stay out\l"
# 492 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the way on those dates.$"
# 493 "data/maps/PacifidlogTown/scripts.pory"

# 494 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_LabSign:
# 495 "data/maps/PacifidlogTown/scripts.pory"
	.string "PROFESSOR BIRCH'S\n"
# 496 "data/maps/PacifidlogTown/scripts.pory"
	.string "MARITIME POKéMON LAB$"
# 497 "data/maps/PacifidlogTown/scripts.pory"

# 498 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SadFisherHouse:
# 499 "data/maps/PacifidlogTown/scripts.pory"
	.string "See me if you're serious about\n"
# 500 "data/maps/PacifidlogTown/scripts.pory"
	.string "fishing for strong POKéMON.$"
# 501 "data/maps/PacifidlogTown/scripts.pory"

# 502 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_PacifidlogTownSign:
# 503 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 504 "data/maps/PacifidlogTown/scripts.pory"
	.string "Where the morning sun\n"
# 505 "data/maps/PacifidlogTown/scripts.pory"
	.string "smiles upon the waters.$"
# 506 "data/maps/PacifidlogTown/scripts.pory"

# 507 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BigCoral:
# 508 "data/maps/PacifidlogTown/scripts.pory"
	.string "(It's a large natural\n"
# 509 "data/maps/PacifidlogTown/scripts.pory"
	.string "structure made of coral.)$"
# 510 "data/maps/PacifidlogTown/scripts.pory"

# 511 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BoxLabel:
# 512 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The box is labelled...)\p"
# 513 "data/maps/PacifidlogTown/scripts.pory"
	.string "DINNER FOR THREE$"

PacifidlogTown_EventScript_TestSign::
# 517 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 518 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_EventScript_TestSign_Text_0
# 519 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
	return


PacifidlogTown_EventScript_TestSign_Text_0:
# 518 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Holy Diver Mod$"
