.set LOCALID_P_MAN, 4

NewMauvilleFloor1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauvilleFloor1_OnLoad
	.byte 0

NewMauvilleFloor1_OnLoad:
	call_if_gt VAR_OLD_GUYS_STATE, 0, NewMauvilleFloor1_EventScript_RemovePowerlessMan
	call_if_lt VAR_OLD_GUYS_STATE, 15, NewMauvilleFloor1_EventScript_CloseElevator
	end

NewMauvilleFloor1_EventScript_RemovePowerlessMan::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

NewMauvilleFloor1_EventScript_CloseElevator::
	setmetatile 46, 2, METATILE_Shop_MaintenanceDoorLocked, TRUE
	special DrawWholeMapView
	return

NewMauvilleFloor1_EventScript_PowerlessManTrigger1::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerGetIntoPos1
	goto NewMauvilleFloor1_EventScript_PowerlessManEvent
	releaseall
	end

NewMauvilleFloor1_Movement_PlayerGetIntoPos1:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

NewMauvilleFloor1_EventScript_PowerlessManTrigger2::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerGetIntoPos2
	goto NewMauvilleFloor1_EventScript_PowerlessManEvent
	releaseall
	end

NewMauvilleFloor1_Movement_PlayerGetIntoPos2:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

NewMauvilleFloor1_EventScript_PowerlessManTrigger3::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerGetIntoPos3
	goto NewMauvilleFloor1_EventScript_PowerlessManEvent
	releaseall
	end

NewMauvilleFloor1_Movement_PlayerGetIntoPos3:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

NewMauvilleFloor1_EventScript_PowerlessManEvent::
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManPassby
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManNotice
	waitmovement 0
	msgbox NewMauvilleFloor1_Text_ItsYouFromTheTidal, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, NewMauvilleFloor1_Movement_PlayerJoinUp
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManJoinUp
	speakername NewMauvilleFloor1_Text_NameKizuna
	msgbox NewMauvilleFloor1_Text_AboutWattsonAndMauville, MSGBOX_DEFAULT
	speakername NULL
	closemessage
	applymovement LOCALID_P_MAN, NewMauvilleFloor1_Movement_PManGoToElevator
	waitmovement 0
	playse SE_WARP_OUT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	setvar VAR_OLD_GUYS_STATE, 1
	releaseall
	end

NewMauvilleFloor1_Movement_PManPassby:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewMauvilleFloor1_Movement_PManNotice:
	emote_exclamation_mark
	delay_16
	delay_16
	face_down
	step_end

NewMauvilleFloor1_Movement_PlayerJoinUp:
	walk_up
	step_end

NewMauvilleFloor1_Movement_PManJoinUp:
	walk_right
	walk_down
	walk_down
	step_end

NewMauvilleFloor1_Movement_PManGoToElevator:
	walk_left
	walk_up
	walk_up
	step_end

NewMauvilleFloor1_EventScript_Roy::
    trainerbattle_single TRAINER_P_ROY, NewMauvilleFloor1_Text_RoyIntro, NewMauvilleFloor1_Text_RoyDefeated
    msgbox NewMauvilleFloor1_Text_RoyPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_EventScript_McKayleigh::
    trainerbattle_single TRAINER_P_MCKAYLEIGH, NewMauvilleFloor1_Text_McKayleighIntro, NewMauvilleFloor1_Text_McKayleighDefeated
    msgbox NewMauvilleFloor1_Text_McKayleighPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_EventScript_Aiden::
    trainerbattle_single TRAINER_P_AIDEN, NewMauvilleFloor1_Text_AidenIntro, NewMauvilleFloor1_Text_AidenDefeated
    msgbox NewMauvilleFloor1_Text_AidenPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_Text_NameKizuna:
	.string "Kizuna$"

NewMauvilleFloor1_Text_RoyIntro:
	.string "intro$"

NewMauvilleFloor1_Text_RoyDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_RoyPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_McKayleighIntro:
	.string "intro$"

NewMauvilleFloor1_Text_McKayleighDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_McKayleighPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_AidenIntro:
	.string "intro$"

NewMauvilleFloor1_Text_AidenDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_AidenPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_ItsYouFromTheTidal:
	.string "tidaltext$"

NewMauvilleFloor1_Text_AboutWattsonAndMauville:
	.string "wattstext$"
