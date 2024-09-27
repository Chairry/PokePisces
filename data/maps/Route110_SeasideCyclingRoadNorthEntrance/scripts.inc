.set LOCALID_RYDEL, 2

Route110_SeasideCyclingRoadNorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_SeasideCyclingRoadNorthEntrance_OnLoad
	.byte 0

Route110_SeasideCyclingRoadNorthEntrance_OnLoad:
	call_if_eq VAR_OLD_GUYS_STATE, 6, Route110_SeasideCyclingRoadNorthEntrance_EventScript_SetMauvilleOldManGfx
	call_if_lt VAR_OLD_GUYS_STATE, 6, Route110_SeasideCyclingRoadNorthEntrance_EventScript_RemoveRydel
	call_if_gt VAR_OLD_GUYS_STATE, 6, Route110_SeasideCyclingRoadNorthEntrance_EventScript_RemoveRydel
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_SetMauvilleOldManGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_HIPSTER
	special SetMauvilleOldManObjEventGfx
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_RemoveRydel::
	removeobject LOCALID_RYDEL
	setflag FLAG_TEMP_12
	return

Route110_SeasideCyclingRoadNorthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_Movement_PushPlayerBackFromCounter:
	walk_up
	step_end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_ClearCyclingRoad::
	lockall
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_RydelGoOn::
	msgbox Route110_SeasideCyclingRoadNorthEntrance_Text_RydelGoOn, MSGBOX_NPC
	end

Route110_SeasideCyclingRoadNorthEntrance_Text_RydelGoOn:
	.string "Go on.$"

Route110_SeasideCyclingRoadNorthEntrance_Text_GoAllOutOnCyclingRoad:
	.string "On CYCLING ROAD, you can go all out\n"
	.string "and cycle as fast as you'd like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"

Route110_SeasideCyclingRoadNorthEntrance_Text_TooDangerousToWalk:
	.string "Sorry, you can't walk on CYCLING\n"
	.string "ROAD. It's too dangerous.\p"
	.string "Please come back with a BIKE.$"

