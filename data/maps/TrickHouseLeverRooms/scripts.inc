.set LOCALID_WORKER, 1
.set LOCALID_JUMPSCARER, 2
.set LOCALID_OIL, 3

TrickHouseLeverRooms_MapScripts::
	.byte 0

TrickHouseLeverRooms_EventScript_Oil::
	lock
	removeobject LOCALID_OIL
	setflag FLAG_TEMP_11
	msgbox TrickHouseLeverRooms_Text_YouFoundOil, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseLeverRooms_EventScript_Worker::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_13, TrickHouseLeverRooms_EventScript_YouCanFeelSafeNow
	goto_if_set FLAG_TEMP_12, TrickHouseLeverRooms_EventScript_OhImSorry
	goto_if_set FLAG_TEMP_11, TrickHouseLeverRooms_EventScript_GoOnHitLever
	msgbox TrickHouseLeverRooms_Text_ThisLeverNeedsOil, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseLeverRooms_EventScript_GoOnHitLever::
	msgbox TrickHouseLeverRooms_Text_GoOnHitLever, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseLeverRooms_EventScript_OhImSorry::
	setvar VAR_TEMP_5, 2
	setflag FLAG_TEMP_13
	msgbox TrickHouseLeverRooms_Text_OhImSorry, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseLeverRooms_EventScript_YouCanFeelSafeNow::
	msgbox TrickHouseLeverRooms_Text_YouCanFeelSafeNow, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseLeverRooms_EventScript_ActivateLever4::
	lock
	goto_if_unset FLAG_TEMP_11, TrickHouseLeverRooms_EventScript_LeverJammed
	goto_if_set FLAG_TEMP_14, TrickHouseLeverRooms_EventScript_TurnOffLever4
	playse SE_CLICK
	setflag FLAG_TEMP_14
	call_if_eq VAR_TEMP_5, 0, TrickHouseLeverRooms_EventScript_Lever4SetVar
	setmetatile 4, 6, METATILE_TrickHouseNew_LeverOn, TRUE
	setmetatile 7, 5, METATILE_TrickHouseNew_ShutterClosed, FALSE
	special DrawWholeMapView
	release
	end

TrickHouseLeverRooms_EventScript_TurnOffLever4::
	playse SE_CLICK
	clearflag FLAG_TEMP_14
	setmetatile 4, 6, METATILE_TrickHouseNew_LeverOff, TRUE
	setmetatile 7, 5, METATILE_TrickHouseNew_ShutterOpen, TRUE
	special DrawWholeMapView
	release
	end

TrickHouseLeverRooms_EventScript_Lever4SetVar::
	setvar VAR_TEMP_5, 1
	return

TrickHouseLeverRooms_EventScript_LeverJammed::
	msgbox TrickHouseLeverRooms_Text_LeverJammed, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseLeverRooms_EventScript_WorkerResetLever::
	lock
	applymovement LOCALID_WORKER, TrickHouseLeverRooms_Movement_FaceRight
	waitmovement 0
	playse SE_CLICK
	setmetatile 4, 6, METATILE_TrickHouseNew_LeverOff, TRUE
	setmetatile 7, 5, METATILE_TrickHouseNew_ShutterOpen, TRUE
	special DrawWholeMapView
	setflag FLAG_TEMP_12
	clearflag FLAG_TEMP_14
	setvar VAR_TEMP_5, 0
	applymovement LOCALID_WORKER, TrickHouseLeverRooms_Movement_FaceDown
	waitmovement 0
	release
	end

TrickHouseLeverRooms_Movement_FaceRight:
	face_right
	step_end

TrickHouseLeverRooms_Movement_FaceDown:
	face_down
	step_end

TrickHouseLeverRooms_EventScript_FallIntoPit::
	lock
	applymovement LOCALID_WORKER, TrickHouseLeverRooms_Movement_FaceRight
	waitmovement 0
	playse SE_CLICK
	setmetatile 4, 6, METATILE_TrickHouseNew_LeverOff, TRUE
	setmetatile 7, 5, METATILE_TrickHouseNew_ShutterOpen, FALSE
	special DrawWholeMapView
	applymovement LOCALID_WORKER, TrickHouseLeverRooms_Movement_FaceDown
	waitmovement 0
	delay 16
	delay 16
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseLeverRooms_Movement_AboutToFall
	waitmovement 0
	warphole MAP_TRICK_HOUSE_DARK_ROOM
	waitstate
	release
	end

TrickHouseLeverRooms_Movement_AboutToFall:
	emote_exclamation_mark
	delay_8
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_in_place_fast_up
	step_end

TrickHouseLeverRooms_Text_YouFoundOil:
	.string "found oil$"

TrickHouseLeverRooms_Text_ThisLeverNeedsOil:
	.string "needs oil$"

TrickHouseLeverRooms_Text_GoOnHitLever:
	.string "go on hit it$"

TrickHouseLeverRooms_Text_OhImSorry:
	.string "oh my b$"

TrickHouseLeverRooms_Text_YouCanFeelSafeNow:
	.string "you feel safe now$"

TrickHouseLeverRooms_Text_LeverJammed:
	.string "lever is jammed$"
