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
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchNotice
# 25 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerNotice
# 26 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 27 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_GladToSeeYou, MSGBOX_DEFAULT
# 28 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 29 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk1
# 30 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk1
# 31 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 32 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_PacifidlogTownIsNice, MSGBOX_DEFAULT
# 33 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 34 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk2
# 35 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk2
# 36 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 37 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_ResearchingTheLegends, MSGBOX_DEFAULT
# 38 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 39 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk3
# 40 "data/maps/PacifidlogTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk3
# 41 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 42 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CouldUseYourHelp, MSGBOX_DEFAULT
# 43 "data/maps/PacifidlogTown/scripts.pory"
	warp MAP_BIRCH_MARITIME_LAB, 9, 14
# 44 "data/maps/PacifidlogTown/scripts.pory"
	waitstate
# 45 "data/maps/PacifidlogTown/scripts.pory"
	release
# 46 "data/maps/PacifidlogTown/scripts.pory"
	end
# 47 "data/maps/PacifidlogTown/scripts.pory"

# 48 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchNotice:
# 49 "data/maps/PacifidlogTown/scripts.pory"
	emote_exclamation_mark
# 50 "data/maps/PacifidlogTown/scripts.pory"
	jump_in_place_right
# 51 "data/maps/PacifidlogTown/scripts.pory"
	walk_fast_right
# 52 "data/maps/PacifidlogTown/scripts.pory"
	walk_fast_right
# 53 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 54 "data/maps/PacifidlogTown/scripts.pory"

# 55 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerNotice:
# 56 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 57 "data/maps/PacifidlogTown/scripts.pory"
	delay_8
# 58 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 59 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 60 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 61 "data/maps/PacifidlogTown/scripts.pory"

# 62 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk1:
# 63 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 64 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 65 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 66 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 67 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 68 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 69 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 70 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 71 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 72 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 73 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 74 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 75 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 76 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 77 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 78 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 79 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 80 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 81 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 82 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 83 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 84 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 85 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 86 "data/maps/PacifidlogTown/scripts.pory"
	face_right
# 87 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 88 "data/maps/PacifidlogTown/scripts.pory"

# 89 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk1:
# 90 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 91 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 92 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 93 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 94 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 95 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 96 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 97 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 98 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 99 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 100 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 101 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 102 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 103 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 104 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 105 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 106 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 107 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 108 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 109 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 110 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 111 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 112 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 113 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 114 "data/maps/PacifidlogTown/scripts.pory"

# 115 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk2:
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
	walk_left
# 123 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 124 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 125 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 126 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 127 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 128 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 129 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 130 "data/maps/PacifidlogTown/scripts.pory"

# 131 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk2:
# 132 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 133 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 134 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 135 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 136 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 137 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 138 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 139 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 140 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 141 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 142 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 143 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 144 "data/maps/PacifidlogTown/scripts.pory"
	face_left
# 145 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 146 "data/maps/PacifidlogTown/scripts.pory"

# 147 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_BirchWalk3:
# 148 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 149 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 150 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 151 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 152 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 153 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 154 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 155 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 156 "data/maps/PacifidlogTown/scripts.pory"
	face_down
# 157 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 158 "data/maps/PacifidlogTown/scripts.pory"

# 159 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Movement_PlayerWalk3:
# 160 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 161 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 162 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 163 "data/maps/PacifidlogTown/scripts.pory"
	walk_up
# 164 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 165 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 166 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 167 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 168 "data/maps/PacifidlogTown/scripts.pory"
	face_up
# 169 "data/maps/PacifidlogTown/scripts.pory"
	step_end
# 170 "data/maps/PacifidlogTown/scripts.pory"

# 171 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NinjaBoy::
# 172 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
# 173 "data/maps/PacifidlogTown/scripts.pory"
	end
# 174 "data/maps/PacifidlogTown/scripts.pory"

# 175 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Girl::
# 176 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
# 177 "data/maps/PacifidlogTown/scripts.pory"
	end
# 178 "data/maps/PacifidlogTown/scripts.pory"

# 179 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Fisherman::
# 180 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
# 181 "data/maps/PacifidlogTown/scripts.pory"
	end
# 182 "data/maps/PacifidlogTown/scripts.pory"

# 183 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TownSign::
# 184 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
# 185 "data/maps/PacifidlogTown/scripts.pory"
	end
# 186 "data/maps/PacifidlogTown/scripts.pory"

# 187 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_1::
# 188 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 189 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs1
# 190 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 191 "data/maps/PacifidlogTown/scripts.pory"
	end
# 192 "data/maps/PacifidlogTown/scripts.pory"

# 193 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RoadblockingFisherman_2::
# 194 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 195 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CantGoPastUs2
# 196 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
# 197 "data/maps/PacifidlogTown/scripts.pory"
	end
# 198 "data/maps/PacifidlogTown/scripts.pory"

# 199 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BetatestingRoadblock::
# 200 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Roadblockdeactivated, MSGBOX_NPC
# 201 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_PACIFIDLOG_ROADBLOCK
# 202 "data/maps/PacifidlogTown/scripts.pory"
	end
# 203 "data/maps/PacifidlogTown/scripts.pory"

# 204 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RestingSailor::
# 205 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RestingSailor, MSGBOX_NPC
# 206 "data/maps/PacifidlogTown/scripts.pory"
	end
# 207 "data/maps/PacifidlogTown/scripts.pory"

# 208 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF1::
# 209 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF1, MSGBOX_NPC
# 210 "data/maps/PacifidlogTown/scripts.pory"
	end
# 211 "data/maps/PacifidlogTown/scripts.pory"

# 212 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SwimmerF2::
# 213 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SwimmerF2, MSGBOX_NPC
# 214 "data/maps/PacifidlogTown/scripts.pory"
	end
# 215 "data/maps/PacifidlogTown/scripts.pory"

# 216 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_StockingSailor::
# 217 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_StockingSailor, MSGBOX_NPC
# 218 "data/maps/PacifidlogTown/scripts.pory"
	end
# 219 "data/maps/PacifidlogTown/scripts.pory"

# 220 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Wayfarer::
# 221 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Wayfarer, MSGBOX_NPC
# 222 "data/maps/PacifidlogTown/scripts.pory"
	end
# 223 "data/maps/PacifidlogTown/scripts.pory"

# 224 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller1::
# 225 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 226 "data/maps/PacifidlogTown/scripts.pory"
	faceplayer
# 227 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_SEASHELL_1, PacifidlogTown_EventScript_GaveShell
# 228 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_HaveThisShell, MSGBOX_DEFAULT
# 229 "data/maps/PacifidlogTown/scripts.pory"
	giveitem ITEM_SHOAL_SHELL
# 230 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 231 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_RECEIVED_SEASHELL_1
# 232 "data/maps/PacifidlogTown/scripts.pory"
	release
# 233 "data/maps/PacifidlogTown/scripts.pory"
	end
# 234 "data/maps/PacifidlogTown/scripts.pory"

# 235 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GaveShell::
# 236 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller1, MSGBOX_DEFAULT
# 237 "data/maps/PacifidlogTown/scripts.pory"
	release
# 238 "data/maps/PacifidlogTown/scripts.pory"
	end
# 239 "data/maps/PacifidlogTown/scripts.pory"

# 240 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Seasheller2::
# 241 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_Seasheller2, MSGBOX_NPC
# 242 "data/maps/PacifidlogTown/scripts.pory"
	end
# 243 "data/maps/PacifidlogTown/scripts.pory"

# 244 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_GiddyWoman::
# 245 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_GiddyWoman, MSGBOX_NPC
# 246 "data/maps/PacifidlogTown/scripts.pory"
	end
# 247 "data/maps/PacifidlogTown/scripts.pory"

# 248 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_ManWorkingOut::
# 249 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_ManWorkingOut, MSGBOX_NPC
# 250 "data/maps/PacifidlogTown/scripts.pory"
	end
# 251 "data/maps/PacifidlogTown/scripts.pory"

# 252 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher1::
# 253 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher1, MSGBOX_NPC
# 254 "data/maps/PacifidlogTown/scripts.pory"
	end
# 255 "data/maps/PacifidlogTown/scripts.pory"

# 256 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_WaterFisher2::
# 257 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_WaterFisher2, MSGBOX_NPC
# 258 "data/maps/PacifidlogTown/scripts.pory"
	end
# 259 "data/maps/PacifidlogTown/scripts.pory"

# 260 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_CoralScientist::
# 261 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_CoralScientist, MSGBOX_NPC
# 262 "data/maps/PacifidlogTown/scripts.pory"
	end
# 263 "data/maps/PacifidlogTown/scripts.pory"

# 264 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_FishScientist::
# 265 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FishScientist, MSGBOX_NPC
# 266 "data/maps/PacifidlogTown/scripts.pory"
	end
# 267 "data/maps/PacifidlogTown/scripts.pory"

# 268 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_RunningTuber::
# 269 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RunningTuber, MSGBOX_NPC
# 270 "data/maps/PacifidlogTown/scripts.pory"
	end
# 271 "data/maps/PacifidlogTown/scripts.pory"

# 272 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NorthToSkyPillar::
# 273 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NorthToSkyPillar, MSGBOX_SIGN
# 274 "data/maps/PacifidlogTown/scripts.pory"
	end
# 275 "data/maps/PacifidlogTown/scripts.pory"

# 276 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_EastToFlotshoreTrail::
# 277 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_EastToFlotshoreTrail, MSGBOX_SIGN
# 278 "data/maps/PacifidlogTown/scripts.pory"
	end
# 279 "data/maps/PacifidlogTown/scripts.pory"

# 280 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_LabSign::
# 281 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_LabSign, MSGBOX_SIGN
# 282 "data/maps/PacifidlogTown/scripts.pory"
	end
# 283 "data/maps/PacifidlogTown/scripts.pory"

# 284 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_SadFisherHouse::
# 285 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SadFisherHouse, MSGBOX_SIGN
# 286 "data/maps/PacifidlogTown/scripts.pory"
	end
# 287 "data/maps/PacifidlogTown/scripts.pory"

# 288 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_PacifidlogTownSign::
# 289 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_PacifidlogTownSign, MSGBOX_SIGN
# 290 "data/maps/PacifidlogTown/scripts.pory"
	end
# 291 "data/maps/PacifidlogTown/scripts.pory"

# 292 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BigCoral::
# 293 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BigCoral, MSGBOX_SIGN
# 294 "data/maps/PacifidlogTown/scripts.pory"
	end
# 295 "data/maps/PacifidlogTown/scripts.pory"

# 296 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_BoxLabel::
# 297 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_BoxLabel, MSGBOX_SIGN
# 298 "data/maps/PacifidlogTown/scripts.pory"
	end
# 299 "data/maps/PacifidlogTown/scripts.pory"

# 300 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 301 "data/maps/PacifidlogTown/scripts.pory"
	.string "The sea between PACIFIDLOG and\n"
# 302 "data/maps/PacifidlogTown/scripts.pory"
	.string "SLATEPORT has a fast-running tide.\p"
# 303 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you decide to SURF, you could end\n"
# 304 "data/maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 305 "data/maps/PacifidlogTown/scripts.pory"

# 306 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 307 "data/maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 308 "data/maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 309 "data/maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 310 "data/maps/PacifidlogTown/scripts.pory"

# 311 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 312 "data/maps/PacifidlogTown/scripts.pory"
	.string "The SKY PILLAR?\p"
# 313 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 314 "data/maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 315 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 316 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 317 "data/maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in PACIFIDLOG,\n"
# 318 "data/maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 319 "data/maps/PacifidlogTown/scripts.pory"

# 320 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 321 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 322 "data/maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 323 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"
# 324 "data/maps/PacifidlogTown/scripts.pory"

# 325 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_GladToSeeYou:
# 326 "data/maps/PacifidlogTown/scripts.pory"
	.string "test1$"
# 327 "data/maps/PacifidlogTown/scripts.pory"

# 328 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_PacifidlogTownIsNice:
# 329 "data/maps/PacifidlogTown/scripts.pory"
	.string "test2$"
# 330 "data/maps/PacifidlogTown/scripts.pory"

# 331 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_ResearchingTheLegends:
# 332 "data/maps/PacifidlogTown/scripts.pory"
	.string "test3$"
# 333 "data/maps/PacifidlogTown/scripts.pory"

# 334 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CouldUseYourHelp:
# 335 "data/maps/PacifidlogTown/scripts.pory"
	.string "test4$"
# 336 "data/maps/PacifidlogTown/scripts.pory"

# 337 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs1:
# 338 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 339 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 340 "data/maps/PacifidlogTown/scripts.pory"
	.string "W-What did the boss stuff into\n"
# 341 "data/maps/PacifidlogTown/scripts.pory"
	.string "this box again?\p"
# 342 "data/maps/PacifidlogTown/scripts.pory"
	.string "...200 pounds of fish!? Ridiculous!\p"
# 343 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 344 "data/maps/PacifidlogTown/scripts.pory"

# 345 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CantGoPastUs2:
# 346 "data/maps/PacifidlogTown/scripts.pory"
	.string "(There are two men attempting\n"
# 347 "data/maps/PacifidlogTown/scripts.pory"
	.string "to lift a box.)\p"
# 348 "data/maps/PacifidlogTown/scripts.pory"
	.string "You know, I wish we could just push\n"
# 349 "data/maps/PacifidlogTown/scripts.pory"
	.string "the crate off the dock and let\l"
# 350 "data/maps/PacifidlogTown/scripts.pory"
	.string "the Vangar have at it.\p"
# 351 "data/maps/PacifidlogTown/scripts.pory"
	.string "...But then I'd get fired.\p"
# 352 "data/maps/PacifidlogTown/scripts.pory"
	.string "(Perhaps it is best to leave them be.)$"
# 353 "data/maps/PacifidlogTown/scripts.pory"

# 354 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Roadblockdeactivated:
# 355 "data/maps/PacifidlogTown/scripts.pory"
	.string "roadblock off$"
# 356 "data/maps/PacifidlogTown/scripts.pory"

# 357 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RestingSailor:
# 358 "data/maps/PacifidlogTown/scripts.pory"
	.string "Takin' the load off today before\n"
# 359 "data/maps/PacifidlogTown/scripts.pory"
	.string "me n' the other sailors\l"
# 360 "data/maps/PacifidlogTown/scripts.pory"
	.string "head out westward.\p"
# 361 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is the perfect lazy town\n"
# 362 "data/maps/PacifidlogTown/scripts.pory"
	.string "to forget about work in, I'd say!$"
# 363 "data/maps/PacifidlogTown/scripts.pory"

# 364 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF1:
# 365 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog's water is a breathtaking\n"
# 366 "data/maps/PacifidlogTown/scripts.pory"
	.string "place to take a dip in!\p"
# 367 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral structures blow my mind!$"
# 368 "data/maps/PacifidlogTown/scripts.pory"

# 369 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SwimmerF2:
# 370 "data/maps/PacifidlogTown/scripts.pory"
	.string "Last week I stubbed my toe hopping\n"
# 371 "data/maps/PacifidlogTown/scripts.pory"
	.string "into the water on these docks.\l"
# 372 "data/maps/PacifidlogTown/scripts.pory"
	.string "There's untold amounts of jagged\l"
# 373 "data/maps/PacifidlogTown/scripts.pory"
	.string "coral strewn about down there...$"
# 374 "data/maps/PacifidlogTown/scripts.pory"

# 375 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_StockingSailor:
# 376 "data/maps/PacifidlogTown/scripts.pory"
	.string "Dum-dee-dum-dee-dum...\p"
# 377 "data/maps/PacifidlogTown/scripts.pory"
	.string "Oh? Why am I stocking\n"
# 378 "data/maps/PacifidlogTown/scripts.pory"
	.string "lox into this barrel?\p"
# 379 "data/maps/PacifidlogTown/scripts.pory"
	.string "Strict orders from my superior!\n"
# 380 "data/maps/PacifidlogTown/scripts.pory"
	.string "He said it'd be kinda funny.$"
# 381 "data/maps/PacifidlogTown/scripts.pory"

# 382 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Wayfarer:
# 383 "data/maps/PacifidlogTown/scripts.pory"
	.string "Rumor has it that there's a land full\n"
# 384 "data/maps/PacifidlogTown/scripts.pory"
	.string "of really tough battlers due south.\p"
# 385 "data/maps/PacifidlogTown/scripts.pory"
	.string "(You look southward and can make out\n"
# 386 "data/maps/PacifidlogTown/scripts.pory"
	.string "a few islands made of golden rocks.)\p"
# 387 "data/maps/PacifidlogTown/scripts.pory"
	.string "What, are you wanting to check it out\n"
# 388 "data/maps/PacifidlogTown/scripts.pory"
	.string "someday? Be my guest!$"
# 389 "data/maps/PacifidlogTown/scripts.pory"

# 390 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_HaveThisShell:
# 391 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hey! Lookit one of these cool\n"
# 392 "data/maps/PacifidlogTown/scripts.pory"
	.string "seashells I found in the water!\p"
# 393 "data/maps/PacifidlogTown/scripts.pory"
	.string "Do you like collecting shells too?\n"
# 394 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'll let you keep it if you promise\l"
# 395 "data/maps/PacifidlogTown/scripts.pory"
	.string "to take care of it!$"
# 396 "data/maps/PacifidlogTown/scripts.pory"

# 397 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller1:
# 398 "data/maps/PacifidlogTown/scripts.pory"
	.string "I heard from my friend that\n"
# 399 "data/maps/PacifidlogTown/scripts.pory"
	.string "there's a nice lady in Sootopolis\l"
# 400 "data/maps/PacifidlogTown/scripts.pory"
	.string "that makes a special item\l"
# 401 "data/maps/PacifidlogTown/scripts.pory"
	.string "out of sea shells!\p"
# 402 "data/maps/PacifidlogTown/scripts.pory"
	.string "And I think something else, but...\n"
# 403 "data/maps/PacifidlogTown/scripts.pory"
	.string "I forgot that part.$"
# 404 "data/maps/PacifidlogTown/scripts.pory"

# 405 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_Seasheller2:
# 406 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mom told me to stop runnin' on\n"
# 407 "data/maps/PacifidlogTown/scripts.pory"
	.string "the docks. Hah! No way that I'll get\l"
# 408 "data/maps/PacifidlogTown/scripts.pory"
	.string "hurt! The wood isn't THAT slippery!\p"
# 409 "data/maps/PacifidlogTown/scripts.pory"
	.string "(His ankles and shins are clearly\n"
# 410 "data/maps/PacifidlogTown/scripts.pory"
	.string "bruised all over.)$"
# 411 "data/maps/PacifidlogTown/scripts.pory"

# 412 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_GiddyWoman:
# 413 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm positively BEAMING!\n"
# 414 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog is such an underrated,\l"
# 415 "data/maps/PacifidlogTown/scripts.pory"
	.string "beautiful Hoenn locale!$"
# 416 "data/maps/PacifidlogTown/scripts.pory"

# 417 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_ManWorkingOut:
# 418 "data/maps/PacifidlogTown/scripts.pory"
	.string "These coral branches can double as\n"
# 419 "data/maps/PacifidlogTown/scripts.pory"
	.string "pull-up bars! I know, I've tried!\p"
# 420 "data/maps/PacifidlogTown/scripts.pory"
	.string "They're surprisingly rock solid.\p"
# 421 "data/maps/PacifidlogTown/scripts.pory"
	.string "Except when they're not. You kinda\n"
# 422 "data/maps/PacifidlogTown/scripts.pory"
	.string "have to figure that out through\l"
# 423 "data/maps/PacifidlogTown/scripts.pory"
	.string "trial and error.$"
# 424 "data/maps/PacifidlogTown/scripts.pory"

# 425 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher1:
# 426 "data/maps/PacifidlogTown/scripts.pory"
	.string "I don't know about you, but I feel like\n"
# 427 "data/maps/PacifidlogTown/scripts.pory"
	.string "I pull better catches the higher up\l"
# 428 "data/maps/PacifidlogTown/scripts.pory"
	.string "my post is.\p"
# 429 "data/maps/PacifidlogTown/scripts.pory"
	.string "I got a long enough rod to pull it off!\p"
# 430 "data/maps/PacifidlogTown/scripts.pory"
	.string "Stop snickering!$"
# 431 "data/maps/PacifidlogTown/scripts.pory"

# 432 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_WaterFisher2:
# 433 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Snelfrend around here are too nice\n"
# 434 "data/maps/PacifidlogTown/scripts.pory"
	.string "for their own good. I want to reel up\l"
# 435 "data/maps/PacifidlogTown/scripts.pory"
	.string "some actual fish, but every time\l"
# 436 "data/maps/PacifidlogTown/scripts.pory"
	.string "I cast out, one of these friendly\l"
# 437 "data/maps/PacifidlogTown/scripts.pory"
	.string "buggers clings to the hook\l"
# 438 "data/maps/PacifidlogTown/scripts.pory"
	.string "and won't let go!$"
# 439 "data/maps/PacifidlogTown/scripts.pory"

# 440 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_CoralScientist:
# 441 "data/maps/PacifidlogTown/scripts.pory"
	.string "Hello, {PLAYER}. I've been helping\n"
# 442 "data/maps/PacifidlogTown/scripts.pory"
	.string "your dad with researching the biology\l"
# 443 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the healthy coral deposits in\l"
# 444 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters surrounding Pacifidlog.\p"
# 445 "data/maps/PacifidlogTown/scripts.pory"
	.string "He seems to think that they can\n"
# 446 "data/maps/PacifidlogTown/scripts.pory"
	.string "be used as part of a plan to\l"
# 447 "data/maps/PacifidlogTown/scripts.pory"
	.string "clean up the water pollution\l"
# 448 "data/maps/PacifidlogTown/scripts.pory"
	.string "in the bigger cities, but\l"
# 449 "data/maps/PacifidlogTown/scripts.pory"
	.string "I'm not so sure it's that easy...$"
# 450 "data/maps/PacifidlogTown/scripts.pory"

# 451 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FishScientist:
# 452 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Water and Rock type POKéMON\n"
# 453 "data/maps/PacifidlogTown/scripts.pory"
	.string "Marinaroc are likely the cause\l"
# 454 "data/maps/PacifidlogTown/scripts.pory"
	.string "of Pacifidlog Town's extremely\l"
# 455 "data/maps/PacifidlogTown/scripts.pory"
	.string "healthy oceanic habitat.\p"
# 456 "data/maps/PacifidlogTown/scripts.pory"
	.string "You see, {PLAYER}, they are able to\n"
# 457 "data/maps/PacifidlogTown/scripts.pory"
	.string "filter the water they swim through.\l"
# 458 "data/maps/PacifidlogTown/scripts.pory"
	.string "They love doing their part to\l"
# 459 "data/maps/PacifidlogTown/scripts.pory"
	.string "keep the natural coral here healthy.\p"
# 460 "data/maps/PacifidlogTown/scripts.pory"
	.string "They prove very hard to fish\n"
# 461 "data/maps/PacifidlogTown/scripts.pory"
	.string "up because of their weight, too;\l"
# 462 "data/maps/PacifidlogTown/scripts.pory"
	.string "perfect for avoiding trophy hunting\l"
# 463 "data/maps/PacifidlogTown/scripts.pory"
	.string "or a potential overfishing problem!$"
# 464 "data/maps/PacifidlogTown/scripts.pory"

# 465 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_RunningTuber:
# 466 "data/maps/PacifidlogTown/scripts.pory"
	.string "VAN-GUARD!\p"
# 467 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The child brandishes a balloon\n"
# 468 "data/maps/PacifidlogTown/scripts.pory"
	.string "cutlass at you.\l"
# 469 "data/maps/PacifidlogTown/scripts.pory"
	.string "You dramatically feign surrender.)\p"
# 470 "data/maps/PacifidlogTown/scripts.pory"
	.string "That's right! I'M the pirate captain!\n"
# 471 "data/maps/PacifidlogTown/scripts.pory"
	.string "YARRR!$"
# 472 "data/maps/PacifidlogTown/scripts.pory"

# 473 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NorthToSkyPillar:
# 474 "data/maps/PacifidlogTown/scripts.pory"
	.string "NORTH: SKY PILLAR\p"
# 475 "data/maps/PacifidlogTown/scripts.pory"
	.string "We ask you to respect this historical\n"
# 476 "data/maps/PacifidlogTown/scripts.pory"
	.string "monument and to keep it clean.$"
# 477 "data/maps/PacifidlogTown/scripts.pory"

# 478 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_EastToFlotshoreTrail:
# 479 "data/maps/PacifidlogTown/scripts.pory"
	.string "EAST: FLOTSHORE TRAIL\p"
# 480 "data/maps/PacifidlogTown/scripts.pory"
	.string "Mondays through Thursdays are\n"
# 481 "data/maps/PacifidlogTown/scripts.pory"
	.string "scheduled bulk-fishing days.\l"
# 482 "data/maps/PacifidlogTown/scripts.pory"
	.string "All recreational fishers and swimmers\l"
# 483 "data/maps/PacifidlogTown/scripts.pory"
	.string "should be respectful and stay out\l"
# 484 "data/maps/PacifidlogTown/scripts.pory"
	.string "of the way on those dates.$"
# 485 "data/maps/PacifidlogTown/scripts.pory"

# 486 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_LabSign:
# 487 "data/maps/PacifidlogTown/scripts.pory"
	.string "PROFESSOR BIRCH'S\n"
# 488 "data/maps/PacifidlogTown/scripts.pory"
	.string "MARITIME POKéMON LAB$"
# 489 "data/maps/PacifidlogTown/scripts.pory"

# 490 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SadFisherHouse:
# 491 "data/maps/PacifidlogTown/scripts.pory"
	.string "See me if you're serious about\n"
# 492 "data/maps/PacifidlogTown/scripts.pory"
	.string "fishing for strong POKéMON.$"
# 493 "data/maps/PacifidlogTown/scripts.pory"

# 494 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_PacifidlogTownSign:
# 495 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 496 "data/maps/PacifidlogTown/scripts.pory"
	.string "Where the morning sun\n"
# 497 "data/maps/PacifidlogTown/scripts.pory"
	.string "smiles upon the waters.$"
# 498 "data/maps/PacifidlogTown/scripts.pory"

# 499 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BigCoral:
# 500 "data/maps/PacifidlogTown/scripts.pory"
	.string "(It's a large natural\n"
# 501 "data/maps/PacifidlogTown/scripts.pory"
	.string "structure made of coral.)$"
# 502 "data/maps/PacifidlogTown/scripts.pory"

# 503 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_BoxLabel:
# 504 "data/maps/PacifidlogTown/scripts.pory"
	.string "(The box is labelled...)\p"
# 505 "data/maps/PacifidlogTown/scripts.pory"
	.string "DINNER FOR THREE$"

PacifidlogTown_EventScript_TestSign::
# 509 "data/maps/PacifidlogTown/scripts.pory"
	lockall
# 510 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_EventScript_TestSign_Text_0
# 511 "data/maps/PacifidlogTown/scripts.pory"
	releaseall
	return


PacifidlogTown_EventScript_TestSign_Text_0:
# 510 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Holy Diver Mod$"
