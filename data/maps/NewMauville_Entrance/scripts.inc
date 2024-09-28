
.set LOCALID_P_MAN, 1

NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_OnLoad:
	call NewMauville_Entrance_EventScript_RemoveKizuna
	call_if_eq VAR_NEW_MAUVILLE_STATE, 0, NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
	return

NewMauville_Entrance_EventScript_RemoveKizuna::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

NewMauville_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	end

NewMauville_Entrance_EventScript_Door::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_NEW_MAUVILLE_STATE, 1
	closemessage
	clearflag FLAG_TEMP_11
	addobject LOCALID_P_MAN
	applymovement OBJ_EVENT_ID_PLAYER, NewMauville_Entrance_Movement_PlayerGetOutOfWay
	applymovement LOCALID_P_MAN, NewMauville_Entrance_Movement_KizunaArrive
	waitmovement 0
	speakername NewMauville_Entrance_Text_NameKizuna
	msgbox NewMauville_Entrance_Text_ThisIsIt, MSGBOX_DEFAULT
	applymovement LOCALID_P_MAN, NewMauville_Entrance_Movement_KizunaGoThroughDoor
	waitmovement 0
	call NewMauville_Entrance_EventScript_RemoveKizuna
	playse SE_EXIT
	setvar VAR_OLD_GUYS_STATE, 17
	releaseall
	end

NewMauville_Entrance_Movement_PlayerGetOutOfWay:
	face_down
	delay_16
	delay_16
	walk_left
	face_right
	step_end

NewMauville_Entrance_Movement_KizunaArrive:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

NewMauville_Entrance_Movement_KizunaGoThroughDoor:
	walk_slow_up
	walk_slow_up
	step_end

NewMauville_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewMauville_Entrance_Text_NameKizuna:
	.string "Kizuna$"

NewMauville_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

NewMauville_Entrance_Text_ThisIsIt:
	.string "this is finally it.$"
