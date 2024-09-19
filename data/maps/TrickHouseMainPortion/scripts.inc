TrickHouseMainPortion_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TrickHouseMainPortion_OnLoad
	.byte 0

TrickHouseMainPortion_OnLoad:
	call_if_set FLAG_DEFEATED_ANTON, TrickHouseMainPortion_EventScript_OpenMountainHole
	call_if_set FLAG_SOLVED_TRICK_HOUSE_CODE, TrickHouseMainPortion_EventScript_OpenFinalDoor
	end

TrickHouseMainPortion_EventScript_OpenMountainHole::
	setmetatile 10, 1, METATILE_TrickHouseNew_OutsideBlastHoleLeft, TRUE
	setmetatile 11, 1, METATILE_TrickHouseNew_OutsideBlastHoleMiddle, FALSE
	setmetatile 12, 1, METATILE_TrickHouseNew_OutsideBlastHoleRight, TRUE
	setmetatile 11, 0, METATILE_TrickHouseNew_OutsideBlastHoleTop, TRUE
	special DrawWholeMapView
	return

TrickHouseMainPortion_EventScript_OpenFinalDoor::
	setmetatile 38, 1, METATILE_TrickHouseNew_TickHouseDoor, TRUE
	special DrawWholeMapView
	return

TrickHouseMainPortion_EventScript_ScrollE::
	lock
	msgbox TrickHouseMainPortion_Text_ScrollE, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseMainPortion_EventScript_FinalDoor::
	lock
	goto_if_unset FLAG_SOLVED_TRICK_HOUSE_CODE, TrickHouseMainPortion_EventScript_FinalDoorNumber1
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorNumber1::
	msgbox TrickHouseMainPortion_Text_PutInFirstNumber, MSGBOX_DEFAULT
	multichoicegrid 20, 1, MULTI_TRICK_HOUSE_FINAL_DOOR, 3, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 1, TrickHouseMainPortion_EventScript_FinalDoorAddVar1
	closemessage
	goto TrickHouseMainPortion_EventScript_FinalDoorNumber2
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorAddVar1::
	addvar VAR_TEMP_7, 1
	goto TrickHouseMainPortion_EventScript_FinalDoorNumber2
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorNumber2::	
	msgbox TrickHouseMainPortion_Text_PutInSecondNumber, MSGBOX_DEFAULT
	multichoicegrid 20, 1, MULTI_TRICK_HOUSE_FINAL_DOOR, 3, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 3, TrickHouseMainPortion_EventScript_FinalDoorAddVar2
	closemessage
	goto TrickHouseMainPortion_EventScript_FinalDoorNumber3
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorAddVar2::
	addvar VAR_TEMP_7, 1
	goto TrickHouseMainPortion_EventScript_FinalDoorNumber3
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorNumber3::	
	msgbox TrickHouseMainPortion_Text_PutInThirdNumber, MSGBOX_DEFAULT
	multichoicegrid 20, 1, MULTI_TRICK_HOUSE_FINAL_DOOR, 3, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 5, TrickHouseMainPortion_EventScript_FinalDoorAddVar3
	closemessage
	goto TrickHouseMainPortion_EventScript_FinalDoorNumber4
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorAddVar3::
	addvar VAR_TEMP_7, 1
	goto TrickHouseMainPortion_EventScript_FinalDoorNumber4
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorNumber4::	
	msgbox TrickHouseMainPortion_Text_PutInFourthNumber, MSGBOX_DEFAULT
	multichoicegrid 20, 1, MULTI_TRICK_HOUSE_FINAL_DOOR, 3, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, TrickHouseMainPortion_EventScript_FinalDoorAddVar4
	closemessage
	goto TrickHouseMainPortion_EventScript_FinalDoorDetermineUnlock
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorAddVar4::
	addvar VAR_TEMP_7, 1
	goto TrickHouseMainPortion_EventScript_FinalDoorDetermineUnlock
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorDetermineUnlock::
	goto_if_eq VAR_TEMP_7, 4, TrickHouseMainPortion_EventScript_FinalDoorOpens
	playse SE_FAILURE
	setvar VAR_TEMP_7, 0
	msgbox TrickHouseMainPortion_Text_CodeIsIncorrect, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseMainPortion_EventScript_FinalDoorOpens::
	playse SE_SUCCESS
	msgbox TrickHouseMainPortion_Text_CodeIsCorrect, MSGBOX_AUTOCLOSE
	playse SE_UNLOCK
	call TrickHouseMainPortion_EventScript_OpenFinalDoor
	setflag FLAG_SOLVED_TRICK_HOUSE_CODE
	release
	end

TrickHouseMainPortion_EventScript_Geiru::
    trainerbattle_single TRAINER_P_GEIRU, TrickHouseMainPortion_Text_GeiruIntro, TrickHouseMainPortion_Text_GeiruDefeated
    msgbox TrickHouseMainPortion_Text_GeiruPostBattle, MSGBOX_AUTOCLOSE
    end

TrickHouseMainPortion_EventScript_Cotton::
    trainerbattle_single TRAINER_P_COTTON, TrickHouseMainPortion_Text_CottonIntro, TrickHouseMainPortion_Text_CottonDefeated
    msgbox TrickHouseMainPortion_Text_CottonPostBattle, MSGBOX_AUTOCLOSE
    end

TrickHouseMainPortion_EventScript_BillyBob::
    trainerbattle_single TRAINER_P_BILLY_BOB, TrickHouseMainPortion_Text_BillyBobIntro, TrickHouseMainPortion_Text_BillyBobDefeated
    msgbox TrickHouseMainPortion_Text_BillyBobPostBattle, MSGBOX_AUTOCLOSE
    end

TrickHouseMainPortion_Text_GeiruIntro:
	.string "intro$"

TrickHouseMainPortion_Text_GeiruDefeated:
	.string "defeat$"

TrickHouseMainPortion_Text_GeiruPostBattle:
	.string "post$"

TrickHouseMainPortion_Text_CottonIntro:
	.string "intro$"

TrickHouseMainPortion_Text_CottonDefeated:
	.string "defeat$"

TrickHouseMainPortion_Text_CottonPostBattle:
	.string "post$"

TrickHouseMainPortion_Text_BillyBobIntro:
	.string "intro$"

TrickHouseMainPortion_Text_BillyBobDefeated:
	.string "defeat$"

TrickHouseMainPortion_Text_BillyBobPostBattle:
	.string "post$"

TrickHouseMainPortion_Text_PutInFirstNumber:
	.string "(It's a stone door with\n"
	.string "nine buttons on the front.)\p"
	.string "Please put in the first number.$"

TrickHouseMainPortion_Text_PutInSecondNumber:
	.string "Please put in the second number.$"

TrickHouseMainPortion_Text_PutInThirdNumber:
	.string "Please put in the third number.$"

TrickHouseMainPortion_Text_PutInFourthNumber:
	.string "Please put in the fourth number.$"

TrickHouseMainPortion_Text_CodeIsIncorrect:
	.string "That four digit code is incorrect.\p"
	.string "Please think about your clues,\n"
	.string "and try again later.$"

TrickHouseMainPortion_Text_CodeIsCorrect:
	.string "Well done.\n"
	.string "2461 is the correct passcode.\p"
	.string "Please go forward to meet\n"
	.string "with the Trick Master.$"

TrickHouseMainPortion_Text_ScrollE:
	.string "(It's a scroll with odd\n"
	.string "handwriting on it...)\p"
	.string "Ho-ho-ho! Looking to solve\n"
	.string "the mysterious mysteries\l"
	.string "of the Trick House?\l"
	.string "Here's some advice.\p"
	.string "Up ahead is a stone door\n"
	.string "that you will need a 4-digit\l"
	.string "passcode to open.\l"
	.string "There are four more scrolls\l"
	.string "hidden within each of the\l"
	.string "rooms connected by the room\l"
	.string "to the east.\p"
	.string "In order, they are rooms\n"
	.string "A, B, C, and D. Each room's\l"
	.string "scroll has a hint to its number.\p"
	.string "Once you have each digit from\n"
	.string "the four rooms, put them in\l"
	.string "final sequence of D, B, A, C.\p"
	.string "Try writing down each clue as\n"
	.string "you search each room, then put\l"
	.string "your answer together at the end.\p"
	.string "Very good luck to you!\n"
	.string "Have a ball! Or two!\p"
	.string "- Trick Master is my life.$"
