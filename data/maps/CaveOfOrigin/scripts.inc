.set LOCALID_WALLACE, 1

CaveOfOrigin_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveOfOrigin_OnFrame
	.byte 0

CaveOfOrigin_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, CaveOfOrigin_EventScript_GoToRedWater
	.2byte 0

CaveOfOrigin_EventScript_GoToRedWater::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, CaveOfOrigin_Movement_PlayerWalkToWater
	waitmovement 0
	applymovement LOCALID_WALLACE, CaveOfOrigin_Movement_WallaceWalkToWater
	waitmovement 0
	msgbox CaveOfOrigin_Text_AboutTheLegends, MSGBOX_AUTOCLOSE
	applymovement LOCALID_WALLACE, CaveOfOrigin_Movement_WallaceWalkAway
	waitmovement 0
	setvar VAR_NEW_COO_STATE, 2
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	release
	end

CaveOfOrigin_Movement_PlayerWalkToWater:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CaveOfOrigin_Movement_WallaceWalkToWater:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CaveOfOrigin_Movement_WallaceWalkAway:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CaveOfOrigin_Text_AboutTheLegends:
	.string "go get them fish$"
