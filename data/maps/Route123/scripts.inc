.set LOCALID_BREAD, 1

Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition:
	call_if_gt VAR_BREADWINNER_STATE, 1, Route123_EventScript_SetTempFlags
	end

Route123_EventScript_SetTempFlags::
	setflag FLAG_TEMP_11
	removeobject LOCALID_BREAD
	return

Route123_EventScript_BreadPos1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route123_Movement_PlayerMoveIntoPos
	waitmovement 0
	goto Route123_EventScript_BreadwinnerEncounter
	release
	end

Route123_Movement_PlayerMoveIntoPos:
	walk_right
	face_up
	step_end

Route123_EventScript_BreadwinnerEncounter::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route123_Movement_PlayerWalkUpStairs
	applymovement LOCALID_BREAD, Route123_Movement_BreadEnc
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_BREAD, Route123_Movement_BreadBackUp
	waitmovement 0
	trainerbattle_single TRAINER_P_PANDOU_1, Route123_Text_BreadwinnerIntro, Route123_Text_BreadwinnerDefeat, Route123_EventScript_BreadRun
	release
	end

Route123_Movement_PlayerWalkUpStairs:
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route123_Movement_BreadEnc:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route123_Movement_BreadBackUp:
	walk_right
	face_left
	step_end

Route123_EventScript_BreadRun::
	setvar VAR_BREADWINNER_STATE, 2
	msgbox Route123_Text_BreadwinnerRunAway, MSGBOX_DEFAULT
	closemessage
	playse SE_FLEE
	applymovement LOCALID_BREAD, Route123_Movement_BreadEscape
	waitmovement 0
	setflag FLAG_TEMP_11
	removeobject LOCALID_BREAD
	release
	end

Route123_Movement_BreadEscape:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route123_Text_BreadwinnerIntro:
	.string "bread intro$"

Route123_Text_BreadwinnerDefeat:
	.string "bread defeat$"

Route123_Text_BreadwinnerRunAway:
	.string "runnin outta here$"
