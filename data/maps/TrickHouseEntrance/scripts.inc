.set LOCALID_TRICK_MASTER, 1
.set LOCALID_P_MAN, 2

TrickHouseEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TrickHouseEntrance_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrickHouseEntrance_OnWarp
	.byte 0

TrickHouseEntrance_OnTransition:
	goto_if_lt VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_SetMauvilleOldManGfx
	end

TrickHouseEntrance_OnWarp:
	map_script_2 VAR_OLD_GUYS_STATE, 1, TrickHouseEntrance_EventScript_RemoveTrigger
	map_script_2 VAR_OLD_GUYS_STATE, 2, TrickHouseEntrance_EventScript_SetGiddyHidingSpot
	map_script_2 VAR_OLD_GUYS_STATE, 3, TrickHouseEntrance_EventScript_RemoveTrigger
	map_script_2 VAR_OLD_GUYS_STATE, 4, TrickHouseEntrance_EventScript_SetGiddyHidingSpotPost
	map_script_2 VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_SetGiddyHidingSpotPost
	.2byte 0

TrickHouseEntrance_EventScript_SetMauvilleOldManGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_GIDDY
	special SetMauvilleOldManObjEventGfx
	end

TrickHouseEntrance_EventScript_RemoveTrigger::
	setvar VAR_TEMP_5, 1
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	end

TrickHouseEntrance_EventScript_GiddyHiding::
	lockall
	goto_if_ge VAR_OLD_GUYS_STATE, 4, TrickHouseEntrance_EventScript_GiddyGone
	msgbox TrickHouseEntrance_Text_YoureBeingWatched, MSGBOX_DEFAULT
	releaseall
	dofieldeffectsparkle 10, 1, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	setvar VAR_TEMP_5, 1
	end

TrickHouseEntrance_EventScript_GiddyGone::
	msgbox TrickHouseEntrance_Text_NotBeingWatched, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_5, 1
	releaseall
	end

TrickHouseEntrance_EventScript_SetGiddyHidingSpot::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	goto_if_ge VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_RemoveGiddy
	goto_if_set FLAG_POTTRICIA_DEFEATED, TrickHouseEntrance_EventScript_DefeatedPottricia
	goto TrickHouseEntrance_EventScript_RemoveGiddy
	end

TrickHouseEntrance_EventScript_RemoveGiddy::
	removeobject LOCALID_TRICK_MASTER
	setflag FLAG_TEMP_11
	end

TrickHouseEntrance_EventScript_SetGiddyHidingSpotPost::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	setvar VAR_TEMP_5, 1
	goto_if_ge VAR_OLD_GUYS_STATE, 5, TrickHouseEntrance_EventScript_RemoveGiddy
	goto_if_set FLAG_POTTRICIA_DEFEATED, TrickHouseEntrance_EventScript_DefeatedPottricia
	goto TrickHouseEntrance_EventScript_RemoveGiddy
	end

TrickHouseEntrance_EventScript_DefeatedPottricia::
	clearflag FLAG_TEMP_11
	end

TrickHouseEntrance_EventScript_GiddyFound::
	lockall
	goto_if_le VAR_OLD_GUYS_STATE, 1, TrickHouseEntrance_EventScript_OrdinaryCabinet
	goto_if_ge VAR_OLD_GUYS_STATE, 3, TrickHouseEntrance_EventScript_OrdinaryCabinet
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	msgbox TrickHouseEntrance_Text_ConcealedInCabinet, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLD_GUYS_STATE, 3
	warpsilent MAP_TRICK_HOUSE_ENTRANCE, 6, 2
	waitstate
	releaseall
	end

TrickHouseEntrance_EventScript_OrdinaryCabinet::
	msgbox TrickHouseEntrance_Text_OrdinaryCabinet, MSGBOX_AUTOCLOSE
	releaseall
	end

TrickHouseEntrance_EventScript_Giddy::
	lock
	faceplayer
	goto_if_le VAR_OLD_GUYS_STATE, 1, TrickHouseEntrance_EventScript_GiddyPreQuestStart
	goto_if_set FLAG_POTTRICIA_DEFEATED, TrickHouseEntrance_EventScript_GiddyRetires
	msgbox TrickHouseEntrance_Text_IAmTrickMaster, MSGBOX_DEFAULT
	setvar VAR_OLD_GUYS_STATE, 4
	clearflag FLAG_TEMP_14
	addobject LOCALID_P_MAN
	playse SE_DOOR
	waitse
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_ThisIsOurLead, MSGBOX_DEFAULT
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaWalkIn
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_WhatDoYouNeed, MSGBOX_DEFAULT
	applymovement LOCALID_TRICK_MASTER, TrickHouseEntrance_Movement_FaceLeft
	waitmovement 0
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_NeedAWayIn, MSGBOX_DEFAULT
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_DoMyPuzzle, MSGBOX_DEFAULT
	speakername NULL
	applymovement LOCALID_TRICK_MASTER, TrickHouseEntrance_Movement_GiddyHop
	waitmovement 0
	playse SE_M_FAINT_ATTACK
	removeobject LOCALID_TRICK_MASTER
	setflag FLAG_TEMP_11
	delay 16
	dofieldeffectsparkle 5, 1, 0
	release
	end

TrickHouseEntrance_Movement_KizunaWalkIn:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	face_right
	step_end

TrickHouseEntrance_Movement_FaceLeft:
	face_left
	step_end

TrickHouseEntrance_Movement_GiddyHop:
	jump_in_place_down
	jump_in_place_down
	step_end

TrickHouseEntrance_EventScript_GiddyPreQuestStart::
	msgbox TrickHouseEntrance_Text_GiddyPreQuestStart, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseEntrance_EventScript_GiddyRetires::
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_YouCompletedMyPuzzle, MSGBOX_DEFAULT
	clearflag FLAG_TEMP_14
	addobject LOCALID_P_MAN
	playse SE_DOOR
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaWalkIn
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_GiveUsInfo, MSGBOX_DEFAULT
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_CanIHaveAMoment, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseEntrance_Movement_StepBack
	waitmovement 0
	applymovement LOCALID_TRICK_MASTER, TrickHouseEntrance_Movement_GiddyFaceDown
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaGoToGiddy
	waitmovement 0
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_YesGiddy, MSGBOX_DEFAULT
	fadenewbgm MUS_VERDANTURF
	speakername TrickHouseEntrance_Text_NameGiddy
	msgbox TrickHouseEntrance_Text_TimeToRetire, MSGBOX_DEFAULT
	closemessage
	playse SE_M_MEGA_KICK
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaAbsorbGiddy
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	setflag FLAG_TEMP_11
	setvar VAR_OLD_GUYS_STATE, 5
	playse SE_M_FAINT_ATTACK
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseEntrance_Movement_WalkDown
	fadenewbgm MUS_NONE
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_MyBodyDidThatOnItsOwn, MSGBOX_DEFAULT
	speakername NULL
	closemessage
	applymovement LOCALID_P_MAN, TrickHouseEntrance_Movement_KizunaLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_14
	release
	end

TrickHouseEntrance_Movement_StepBack:
	walk_right
	walk_right
	walk_up
	face_left
	step_end

TrickHouseEntrance_Movement_GiddyFaceDown:
	face_down
	step_end

TrickHouseEntrance_Movement_KizunaGoToGiddy:
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

TrickHouseEntrance_Movement_KizunaAbsorbGiddy:
	walk_slow_up
	step_end

TrickHouseEntrance_Movement_WalkDown:
	walk_down
	step_end

TrickHouseEntrance_Movement_KizunaLeave:
	walk_slow_down
	walk_slow_left
	walk_slow_down
	walk_slow_down
	step_end

TrickHouseEntrance_EventScript_KizunaIdle::
	lock
	faceplayer
	speakername TrickHouseEntrance_Text_NameKizuna
	msgbox TrickHouseEntrance_Text_MustExplore, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseEntrance_EventScript_EntranceScroll::
	lock
	goto_if_lt VAR_OLD_GUYS_STATE, 4, TrickHouseEntrance_EventScript_Unreadable
	msgbox TrickHouseEntrance_Text_YouCanNowReadScroll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TrickHouseEntrance_EventScript_WarpIn
	release
	end

TrickHouseEntrance_EventScript_WarpIn::
	warp MAP_TRICK_HOUSE_MAIN_PORTION, 3, 15
	waitstate
	release
	end

TrickHouseEntrance_EventScript_Unreadable::
	msgbox TrickHouseEntrance_Text_Unreadable, MSGBOX_AUTOCLOSE
	release
	end	

TrickHouseEntrance_Text_NameKizuna:
	.string "Kizuna$"

TrickHouseEntrance_Text_NameGiddy:
	.string "Giddy$"

TrickHouseEntrance_Text_YoureBeingWatched:
	.string "You're being watched…$"

TrickHouseEntrance_Text_NotBeingWatched:
	.string "Not being watched anymore.$"

TrickHouseEntrance_Text_ConcealedInCabinet:
	.string "Hah? Grrr…\p"
	.string "How did you know I concealed myself\n"
	.string "in this cabinet? You're sharp!\p"
	.string "Let's talk by the table!$"

TrickHouseEntrance_Text_OrdinaryCabinet:
	.string "ordinary cabinet$"

TrickHouseEntrance_Text_GiddyPreQuestStart:
	.string "hey this is var state 1$"

TrickHouseEntrance_Text_IAmTrickMaster:
	.string "im da trick master$"

TrickHouseEntrance_Text_ThisIsOurLead:
	.string "this is our lead$"

TrickHouseEntrance_Text_WhatDoYouNeed:
	.string "whatcha need$"

TrickHouseEntrance_Text_NeedAWayIn:
	.string "need answers bro$"

TrickHouseEntrance_Text_DoMyPuzzle:
	.string "do my puzzle then$"

TrickHouseEntrance_Text_MustExplore:
	.string "must explore$"

TrickHouseEntrance_Text_YouCompletedMyPuzzle:
	.string "you did it!$"

TrickHouseEntrance_Text_GiveUsInfo:
	.string "give us info$"

TrickHouseEntrance_Text_CanIHaveAMoment:
	.string "can i have a moment$"

TrickHouseEntrance_Text_YesGiddy:
	.string "yes giddy$"

TrickHouseEntrance_Text_TimeToRetire:
	.string "time to retire$"

TrickHouseEntrance_Text_MyBodyDidThatOnItsOwn:
	.string "oh shit bro$"

TrickHouseEntrance_Text_Unreadable:
	.string "unreadable$"

TrickHouseEntrance_Text_YouCanNowReadScroll:
	.string "go into trick house?$"
