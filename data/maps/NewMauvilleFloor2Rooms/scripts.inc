.set LOCALID_P_MAN, 1

NewMauvilleFloor2Rooms_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauvilleFloor2Rooms_OnLoad
	.byte 0

NewMauvilleFloor2Rooms_OnLoad:
	call_if_gt VAR_OLD_GUYS_STATE, 1, NewMauvilleFloor2Rooms_EventScript_RemovePowerlessMan
	end

NewMauvilleFloor2Rooms_EventScript_RemovePowerlessMan::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

NewMauvilleFloor2Rooms_EventScript_KizunaMission::
	lock
	faceplayer
	speakername NewMauvilleFloor2Rooms_Text_NameKizuna
	msgbox NewMauvilleFloor2Rooms_Text_HeresOurMission, MSGBOX_DEFAULT
	speakername NULL
	closemessage
	setvar VAR_OLD_GUYS_STATE, 2
	goto_if_eq VAR_FACING, DIR_WEST, NewMauvilleFloor2Rooms_EventScript_WalkAroundPlayer
	applymovement LOCALID_P_MAN, NewMauvilleFloor2Rooms_Movement_LeaveRoom
	waitmovement 0
	playse SE_WARP_OUT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	release
	end

NewMauvilleFloor2Rooms_EventScript_WalkAroundPlayer::
	applymovement LOCALID_P_MAN, NewMauvilleFloor2Rooms_Movement_LeaveRoom2
	waitmovement 0
	playse SE_WARP_OUT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	release
	end

NewMauvilleFloor2Rooms_Movement_LeaveRoom:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

NewMauvilleFloor2Rooms_Movement_LeaveRoom2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

NewMauvilleFloor2Rooms_Text_NameKizuna:
	.string "Kizuna$"

NewMauvilleFloor2Rooms_Text_HeresOurMission:
	.string "mission$"
