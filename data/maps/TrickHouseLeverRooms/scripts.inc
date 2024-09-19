.set LOCALID_WORKER, 1
.set LOCALID_JUMPSCARER, 2
.set LOCALID_OIL, 3

TrickHouseLeverRooms_MapScripts::
	.byte 0

TrickHouseLeverRooms_EventScript_ScrollA::
	lock
	msgbox TrickHouseLeverRooms_Text_ScrollA, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseLeverRooms_EventScript_ActivateLever1::
	lock
	goto_if_set FLAG_TEMP_18, TrickHouseLeverRooms_EventScript_TurnOnLever1
	playse SE_CLICK
	setflag FLAG_TEMP_18
	setmetatile 29, 25, METATILE_TrickHouseNew_LeverOff, TRUE
	setmetatile 44, 4, METATILE_TrickHouseNew_ShutterOpen, TRUE
	special DrawWholeMapView
	release
	end

TrickHouseLeverRooms_EventScript_TurnOnLever1::
	playse SE_CLICK
	clearflag FLAG_TEMP_18
	setmetatile 29, 25, METATILE_TrickHouseNew_LeverOn, TRUE
	setmetatile 44, 4, METATILE_TrickHouseNew_ShutterClosed, FALSE
	special DrawWholeMapView
	release
	end

TrickHouseLeverRooms_EventScript_ActivateLever2::
	lock
	goto_if_set FLAG_TEMP_16, TrickHouseLeverRooms_EventScript_TurnOffLever2
	playse SE_CLICK
	setflag FLAG_TEMP_16
	setmetatile 46, 9, METATILE_TrickHouseNew_LeverOn, TRUE
	setmetatile 44, 10, METATILE_TrickHouseNew_ShutterClosed, FALSE
	special DrawWholeMapView
	release
	end

TrickHouseLeverRooms_EventScript_TurnOffLever2::
	playse SE_CLICK
	clearflag FLAG_TEMP_16
	setmetatile 46, 9, METATILE_TrickHouseNew_LeverOff, TRUE
	setmetatile 44, 10, METATILE_TrickHouseNew_ShutterOpen, TRUE
	special DrawWholeMapView
	release
	end

TrickHouseLeverRooms_EventScript_ActivateLever3::
	lock
	goto_if_set FLAG_TEMP_17, TrickHouseLeverRooms_EventScript_TurnOffLever3
	playse SE_CLICK
	setflag FLAG_TEMP_17
	setmetatile 32, 4, METATILE_TrickHouseNew_LeverOn, TRUE
	setmetatile 44, 7, METATILE_TrickHouseNew_ShutterClosed, FALSE
	special DrawWholeMapView
	release
	end

TrickHouseLeverRooms_EventScript_TurnOffLever3::
	playse SE_CLICK
	clearflag FLAG_TEMP_17
	setmetatile 32, 4, METATILE_TrickHouseNew_LeverOff, TRUE
	setmetatile 44, 7, METATILE_TrickHouseNew_ShutterOpen, TRUE
	special DrawWholeMapView
	release
	end

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

TrickHouseLeverRooms_EventScript_FaeredReveal::
	lockall
	delay 16
	applymovement VAR_LAST_TALKED, TrickHouseLeverRooms_Movement_FaeredReveal
	delay 32
	setwildbattle SPECIES_FAERED, 30
	playmoncry SPECIES_FAERED, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	removeobject VAR_LAST_TALKED
	releaseall
	end

TrickHouseLeverRooms_Movement_FaeredReveal:
	faered_reveal
	step_end

TrickHouseLeverRooms_EventScript_AdamAndSteve::
    trainerbattle_double TRAINER_P_ADAM_AND_STEVE, TrickHouseLeverRooms_Text_AdamAndSteveIntro, TrickHouseLeverRooms_Text_AdamAndSteveDefeated, TrickHouseLeverRooms_Text_AdamAndSteveNeedTwoMons
    msgbox TrickHouseLeverRooms_Text_AdamAndStevePostBattle, MSGBOX_AUTOCLOSE
    end

TrickHouseLeverRooms_EventScript_David::
    trainerbattle_single TRAINER_P_DAVID, TrickHouseLeverRooms_Text_DavidIntro, TrickHouseLeverRooms_Text_DavidDefeated
    msgbox TrickHouseLeverRooms_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
    end

TrickHouseLeverRooms_EventScript_PathBlocker::
	msgbox TrickHouseLeverRooms_Text_PathBlocker, MSGBOX_NPC
    end

TrickHouseLeverRooms_Text_PathBlocker:
	.string "haha i be blockin u$$"	

TrickHouseLeverRooms_Text_AdamAndSteveIntro:
	.string "intro$"

TrickHouseLeverRooms_Text_AdamAndSteveDefeated:
	.string "defeat$"

TrickHouseLeverRooms_Text_AdamAndStevePostBattle:
	.string "post$"

TrickHouseLeverRooms_Text_AdamAndSteveNeedTwoMons:
	.string "need 2 dood$"

TrickHouseLeverRooms_Text_DavidIntro:
	.string "intro$"

TrickHouseLeverRooms_Text_DavidDefeated:
	.string "defeat$"

TrickHouseLeverRooms_Text_DavidPostBattle:
	.string "post$"

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

TrickHouseLeverRooms_Text_ScrollA:
	.string "(It's a scroll with odd\n"
	.string "handwriting on it...)\p"
	.string "Looking for a number clue\n"
	.string "for the door puzzle?\l"
	.string "At this hour? Mmm.\p"
	.string "Well, I guess I will\n"
	.string "throw you a bone.\p"
	.string "To get this room's number...\p"
	.string "How many humans are in this room?\n"
	.string "How many levers are in this room?\l"
	.string "How many plants are in this room?\p"
	.string "Add the first two numbers together,\n"
	.string "then subtract that with the third.\l"
	.string "The result is this room's digit.\p"
	.string "- Trick Master is cool.$"
