.set LOCALID_BRINEY, 1

RivalRoom_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, RivalRoom_OnFrame
	.byte 0

RivalRoom_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, RivalRoom_EventScript_BrineyOpening
	.2byte 0

RivalRoom_EventScript_BrineyOpening::
	lockall
	applymovement LOCALID_BRINEY, RivalRoom_Movement_BrineyFacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, RivalRoom_Movement_PlayerFaceBriney
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_HIDE_BIRCH_AFTER_STARTER
	clearflag FLAG_HIDE_BIRCH_BEFORE_STARTER
	msgbox RivalRoom_Text_GoTalkToOthers, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

RivalRoom_Movement_BrineyFacePlayer:
	face_right
	step_end

RivalRoom_Movement_PlayerFaceBriney:
	face_left
	step_end

RivalRoom_EventScript_GetOut::
	msgbox RivalRoom_Text_BrineyText, MSGBOX_NPC
	end

RivalRoom_Text_GoTalkToOthers:
	.string "go bestie$"

RivalRoom_Text_BrineyText:
	.string "plz get out$"

