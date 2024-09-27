.set LOCALID_RYDEL, 2
.set LOCALID_P_MAN, 3

Route110_SeasideCyclingRoadSouthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadSouthEntrance_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route110_SeasideCyclingRoadSouthEntrance_OnLoad
	.byte 0

Route110_SeasideCyclingRoadSouthEntrance_OnLoad:
	call_if_eq VAR_OLD_GUYS_STATE, 6, Route110_SeasideCyclingRoadSouthEntrance_EventScript_SetMauvilleOldManGfx
	call_if_lt VAR_OLD_GUYS_STATE, 6, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RemoveRydelAndKizuna
	call_if_gt VAR_OLD_GUYS_STATE, 6, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RemoveRydelAndKizuna
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_SetMauvilleOldManGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_HIPSTER
	special SetMauvilleOldManObjEventGfx
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_RemoveRydelAndKizuna::
	removeobject LOCALID_RYDEL
	setflag FLAG_TEMP_12
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

Route110_SeasideCyclingRoadSouthEntrance_OnTransition:
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 3, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 2, Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_RestartChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_Clerk::
	lock
	faceplayer
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad, MSGBOX_DEFAULT
	release
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_BikeCheck::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	call_if_eq VAR_RESULT, 2, Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike
	goto_if_eq VAR_RESULT, 0, Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike
	setflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 1
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_OnMachBike::
	setvar VAR_CYCLING_CHALLENGE_STATE, 1
	return

Route110_SeasideCyclingRoadSouthEntrance_EventScript_NoBike::
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_ClearCyclingRoad::
	lockall
	setvar VAR_CYCLING_CHALLENGE_STATE, 0
	clearflag FLAG_SYS_CYCLING_ROAD
	setvar VAR_TEMP_1, 0
	releaseall
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_KizunaCongrats::
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_KizunaCongrats, MSGBOX_NPC
	end

Route110_SeasideCyclingRoadSouthEntrance_EventScript_RydelRetires::
	lock
	speakername Route110_SeasideCyclingRoadSouthEntrance_Text_NameRydel
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_YouDidIt, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Route110_SeasideCyclingRoadSouthEntrance_Movement_FaceRight
	fadenewbgm MUS_VERDANTURF
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_TimeToRetire, MSGBOX_DEFAULT
	applymovement LOCALID_RYDEL, Route110_SeasideCyclingRoadSouthEntrance_Movement_FaceUp
	applymovement LOCALID_P_MAN, Route110_SeasideCyclingRoadSouthEntrance_Movement_FaceDown
	speakername Route110_SeasideCyclingRoadSouthEntrance_Text_NameKizuna
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_ImReadyAreYou, MSGBOX_DEFAULT
	closemessage
	playse SE_M_MEGA_KICK
	applymovement LOCALID_P_MAN, Route110_SeasideCyclingRoadSouthEntrance_Movement_AbsorbRydel
	waitmovement 0
	removeobject LOCALID_RYDEL
	setflag FLAG_TEMP_12
	setvar VAR_OLD_GUYS_STATE, 7
	playse SE_M_FAINT_ATTACK
	waitse
	fadenewbgm MUS_NONE
	speakername Route110_SeasideCyclingRoadSouthEntrance_Text_NameKizuna
	msgbox Route110_SeasideCyclingRoadSouthEntrance_Text_ThisIsHard, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_P_MAN, Route110_SeasideCyclingRoadSouthEntrance_Movement_KizunaLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	release
	end

Route110_SeasideCyclingRoadSouthEntrance_Movement_FaceRight:
	face_right
	step_end

Route110_SeasideCyclingRoadSouthEntrance_Movement_FaceUp:
	face_up
	step_end

Route110_SeasideCyclingRoadSouthEntrance_Movement_FaceDown:
	face_down
	step_end

Route110_SeasideCyclingRoadSouthEntrance_Movement_AbsorbRydel:
	walk_slow_down
	step_end

Route110_SeasideCyclingRoadSouthEntrance_Movement_KizunaLeave:
	walk_slow_up
	walk_slow_left
	walk_slow_left
	walk_slow_up
	step_end

Route110_SeasideCyclingRoadSouthEntrance_Text_NameRydel:
	.string "Rydel$"

Route110_SeasideCyclingRoadSouthEntrance_Text_NameKizuna:
	.string "Kizuna$"

Route110_SeasideCyclingRoadSouthEntrance_Text_KizunaCongrats:
	.string "congrats$"

Route110_SeasideCyclingRoadSouthEntrance_Text_YouDidIt:
	.string "you did it$"

Route110_SeasideCyclingRoadSouthEntrance_Text_TimeToRetire:
	.string "time to retire$"

Route110_SeasideCyclingRoadSouthEntrance_Text_ImReadyAreYou:
	.string "im ready are u$"

Route110_SeasideCyclingRoadSouthEntrance_Text_ThisIsHard:
	.string "this shit sucks$"

Route110_SeasideCyclingRoadSouthEntrance_Text_GoAllOutOnCyclingRoad:
	.string "On CYCLING ROAD, you can go all out\n"
	.string "and cycle as fast as you'd like.\p"
	.string "It feels great to go that fast, but try\n"
	.string "not to crash into anyone!$"

Route110_SeasideCyclingRoadSouthEntrance_Text_TooDangerousToWalk:
	.string "Sorry, you can't walk on CYCLING\n"
	.string "ROAD. It's too dangerous.\p"
	.string "Please come back with a BIKE.$"

