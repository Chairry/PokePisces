.set LOCALID_MERAL1, 9
.set LOCALID_MERAL2, 8
.set LOCALID_MERAL3, 4
.set LOCALID_MERAL4, 10
.set LOCALID_MERAL5, 7
.set LOCALID_MERAL6, 6
.set LOCALID_MERAL7, 5
.set LOCALID_MERAL8, 1
.set LOCALID_MERAL9, 2
.set LOCALID_MERAL10, 3
.set LOCALID_MERAL11, 13
.set LOCALID_MERAL12, 12
.set LOCALID_MERAL13, 11
.set LOCALID_MERAL14, 18
.set LOCALID_MERAL15, 17
.set LOCALID_MERAL16, 16
.set LOCALID_MERAL17, 14
.set LOCALID_MERAL18, 15
.set LOCALID_MERAL19, 20
.set LOCALID_MERAL20, 19
.set LOCALID_ELECTRICIAN, 22
.set LOCALID_TABITHA, 29
.set LOCALID_TMBALL, 30

TheColdMines_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheColdMines_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TheColdMines_OnFrame
	.byte 0

TheColdMines_OnFrame:
	map_script_2 VAR_TEMP_4, 69, TheColdMines_EventScript_CheckMeralSetFlags
	.2byte 0

TheColdMines_OnLoad:
	call_if_gt VAR_OZONE_ADMINS_STATE, 3, TheColdMines_EventScript_ReplaceSouthSnow
	call_if_gt VAR_OZONE_ADMINS_STATE, 4, TheColdMines_EventScript_ReplaceNorthSnow
	call_if_eq VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_SetupMeralcorePuzzle1
	call_if_gt VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_RemoveMeralcorePuzzle1
	call_if_lt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_SetupMeralcorePuzzle2
	call_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_RemoveMeralcorePuzzle2
	call_if_lt VAR_MINES_MERALCORE_STATE, 4, TheColdMines_EventScript_SetupMeralcorePuzzle3
	call_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_RemoveMeralcorePuzzle3
	end

TheColdMines_EventScript_SetupMeralcorePuzzle1::
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_8
	removeobject LOCALID_MERAL2
	removeobject LOCALID_MERAL4
	return

TheColdMines_EventScript_SetupMeralcorePuzzle2::
	setflag FLAG_TEMP_B
	setflag FLAG_TEMP_E
	removeobject LOCALID_MERAL7
	removeobject LOCALID_MERAL9
	return

TheColdMines_EventScript_SetupMeralcorePuzzle3::
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_19
	setflag FLAG_ITEM_TM_ZING_ZAP
	removeobject LOCALID_TMBALL
	removeobject LOCALID_MERAL16
	removeobject LOCALID_MERAL17
	removeobject LOCALID_MERAL19
	return

TheColdMines_EventScript_ReplaceSouthSnow::
	setflag FLAG_TEMP_1D
	removeobject LOCALID_TABITHA
	setmetatile 48, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 52, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 52, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 52, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 53, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 53, 35, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	return

TheColdMines_EventScript_ReplaceNorthSnow::
	setmetatile 41, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 15, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 15, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 17, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 17, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 18, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 18, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 19, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 19, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 12, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 12, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 12, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 12, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 15, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 15, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 12, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 12, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 13, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 14, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 11, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	return

TheColdMines_EventScript_RemoveMeralcorePuzzle1::
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	setflag FLAG_TEMP_9
	removeobject LOCALID_MERAL1
	removeobject LOCALID_MERAL2
	removeobject LOCALID_MERAL3
	removeobject LOCALID_MERAL4
	removeobject LOCALID_MERAL5
	setmetatile 50, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 31, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 36, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	return

TheColdMines_EventScript_RemoveMeralcorePuzzle2::
	setflag FLAG_TEMP_A
	setflag FLAG_TEMP_B
	setflag FLAG_TEMP_C
	setflag FLAG_TEMP_D
	setflag FLAG_TEMP_E
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	removeobject LOCALID_MERAL6
	removeobject LOCALID_MERAL7
	removeobject LOCALID_MERAL8
	removeobject LOCALID_MERAL9
	removeobject LOCALID_MERAL10
	removeobject LOCALID_MERAL11
	removeobject LOCALID_MERAL12
	removeobject LOCALID_MERAL13
	setmetatile 33, 22, METATILE_Snow_MeralSnow, FALSE
	setmetatile 33, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 34, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 22, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 28, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 26, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 28, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 21, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 21, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 22, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 20, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 19, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 19, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 18, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 20, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 17, 31, METATILE_Snow_MeralSnow, FALSE
	setmetatile 17, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 16, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 18, 32, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	return

TheColdMines_EventScript_RemoveMeralcorePuzzle3::
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	removeobject LOCALID_MERAL14
	removeobject LOCALID_MERAL15
	removeobject LOCALID_MERAL16
	removeobject LOCALID_MERAL17
	removeobject LOCALID_MERAL18
	removeobject LOCALID_MERAL19
	removeobject LOCALID_MERAL20
	setmetatile 40, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 36, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 4, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 10, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	return

TheColdMines_EventScript_CheckMeralSetFlags::
	lock
	goto_if_eq VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_CheckPuzzle1SetFlags
	goto_if_eq VAR_MINES_MERALCORE_STATE, 1, TheColdMines_EventScript_CheckPuzzle2SetFlags
	goto_if_eq VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_CheckPuzzle2Part2SetFlags
	goto_if_eq VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_CheckPuzzle3SetFlags
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckPuzzle1SetFlags::
	goto_if_set FLAG_TEMP_5, TheColdMines_EventScript_CheckTemp6
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp6::
	goto_if_set FLAG_TEMP_6, TheColdMines_EventScript_CheckTemp7
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp7::
	goto_if_set FLAG_TEMP_7, TheColdMines_EventScript_CheckTemp8
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp8::
	goto_if_set FLAG_TEMP_8, TheColdMines_EventScript_CheckTemp9
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp9::
	goto_if_set FLAG_TEMP_9, TheColdMines_EventScript_ClearedPuzzle1
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_ClearedPuzzle1::
	setmetatile 50, 29, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 50, 30, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 49, 30, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 51, 30, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 49, 31, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 49, 32, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 48, 32, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 50, 32, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 46, 32, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 46, 33, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 47, 33, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 45, 33, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 45, 34, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 45, 35, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 44, 35, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 46, 35, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 47, 35, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 47, 36, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 46, 36, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 48, 36, METATILE_Snow_MeralBuriedRight1, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 50, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 30, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 49, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 31, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 32, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 48, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 33, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 47, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 35, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 44, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 36, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 46, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 36, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 50, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 51, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 31, METATILE_Snow_MeralSnow, FALSE
	setmetatile 49, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 50, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 33, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 34, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 35, METATILE_Snow_MeralSnow, FALSE
	setmetatile 47, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 46, 36, METATILE_Snow_MeralSnow, FALSE
	setmetatile 48, 36, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setvar VAR_MINES_MERALCORE_STATE, 1
	setvar VAR_TEMP_4, 0
	playse SE_SUCCESS
	release
	end

TheColdMines_EventScript_M1FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M1Interact
	release
	end

TheColdMines_EventScript_CantFlash::
	msgbox TheColdMines_Text_NoFlash, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_OnceWasMeralcore::
	msgbox TheColdMines_Text_OnceWasMeralcore, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_M1Interact::
	goto_if_set FLAG_TEMP_5, TheColdMines_EventScript_M1TurnOn
	goto_if_unset FLAG_TEMP_5, TheColdMines_EventScript_M1TurnOff
	release
	end

TheColdMines_EventScript_M1TurnOn::
	clearflag FLAG_TEMP_5
	addobject LOCALID_MERAL1
	goto TheColdMines_EventScript_M1SetSurround1
	release
	end

TheColdMines_EventScript_M1TurnOff::
	setflag FLAG_TEMP_5
	removeobject LOCALID_MERAL1
	goto TheColdMines_EventScript_M1SetSurround1
	release
	end

TheColdMines_EventScript_M1SetSurround1::
	goto_if_set FLAG_TEMP_6, TheColdMines_EventScript_M1SetOnM2
	goto_if_unset FLAG_TEMP_6, TheColdMines_EventScript_M1SetOffM2
	release
	end

TheColdMines_EventScript_M1SetOnM2::
	clearflag FLAG_TEMP_6
	addobject LOCALID_MERAL2
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M1SetOffM2::
	setflag FLAG_TEMP_6
	removeobject LOCALID_MERAL2
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M2FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M2Interact
	release
	end

TheColdMines_EventScript_M2Interact::
	goto_if_set FLAG_TEMP_6, TheColdMines_EventScript_M2TurnOn
	goto_if_unset FLAG_TEMP_6, TheColdMines_EventScript_M2TurnOff
	release
	end

TheColdMines_EventScript_M2TurnOn::
	clearflag FLAG_TEMP_6
	addobject LOCALID_MERAL2
	goto TheColdMines_EventScript_M2SetSurround1
	release
	end

TheColdMines_EventScript_M2TurnOff::
	setflag FLAG_TEMP_6
	removeobject LOCALID_MERAL2
	goto TheColdMines_EventScript_M2SetSurround1
	release
	end

TheColdMines_EventScript_M2SetSurround1::
	goto_if_set FLAG_TEMP_7, TheColdMines_EventScript_M2SetOnM3
	goto_if_unset FLAG_TEMP_7, TheColdMines_EventScript_M2SetOffM3
	release
	end

TheColdMines_EventScript_M2SetOnM3::
	clearflag FLAG_TEMP_7
	addobject LOCALID_MERAL3
	goto TheColdMines_EventScript_M2SetSurround2
	release
	end

TheColdMines_EventScript_M2SetOffM3::
	setflag FLAG_TEMP_7
	removeobject LOCALID_MERAL3
	goto TheColdMines_EventScript_M2SetSurround2
	release
	end

TheColdMines_EventScript_M2SetSurround2::
	goto_if_set FLAG_TEMP_5, TheColdMines_EventScript_M2SetOnM1
	goto_if_unset FLAG_TEMP_5, TheColdMines_EventScript_M2SetOffM1
	release
	end

TheColdMines_EventScript_M2SetOnM1::
	clearflag FLAG_TEMP_5
	addobject LOCALID_MERAL1
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M2SetOffM1::
	setflag FLAG_TEMP_5
	removeobject LOCALID_MERAL1
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M3FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M3Interact
	release
	end

TheColdMines_EventScript_M3Interact::
	goto_if_set FLAG_TEMP_7, TheColdMines_EventScript_M3TurnOn
	goto_if_unset FLAG_TEMP_7, TheColdMines_EventScript_M3TurnOff
	release
	end

TheColdMines_EventScript_M3TurnOn::
	clearflag FLAG_TEMP_7
	addobject LOCALID_MERAL3
	goto TheColdMines_EventScript_M3SetSurround1
	release
	end

TheColdMines_EventScript_M3TurnOff::
	setflag FLAG_TEMP_7
	removeobject LOCALID_MERAL3
	goto TheColdMines_EventScript_M3SetSurround1
	release
	end

TheColdMines_EventScript_M3SetSurround1::
	goto_if_set FLAG_TEMP_8, TheColdMines_EventScript_M3SetOnM4
	goto_if_unset FLAG_TEMP_8, TheColdMines_EventScript_M3SetOffM4
	release
	end

TheColdMines_EventScript_M3SetOnM4::
	clearflag FLAG_TEMP_8
	addobject LOCALID_MERAL4
	goto TheColdMines_EventScript_M3SetSurround2
	release
	end

TheColdMines_EventScript_M3SetOffM4::
	setflag FLAG_TEMP_8
	removeobject LOCALID_MERAL4
	goto TheColdMines_EventScript_M3SetSurround2
	release
	end

TheColdMines_EventScript_M3SetSurround2::
	goto_if_set FLAG_TEMP_6, TheColdMines_EventScript_M3SetOnM2
	goto_if_unset FLAG_TEMP_6, TheColdMines_EventScript_M3SetOffM2
	release
	end

TheColdMines_EventScript_M3SetOnM2::
	clearflag FLAG_TEMP_6
	addobject LOCALID_MERAL2
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M3SetOffM2::
	setflag FLAG_TEMP_6
	removeobject LOCALID_MERAL2
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M4FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M4Interact
	release
	end

TheColdMines_EventScript_M4Interact::
	goto_if_set FLAG_TEMP_8, TheColdMines_EventScript_M4TurnOn
	goto_if_unset FLAG_TEMP_8, TheColdMines_EventScript_M4TurnOff
	release
	end

TheColdMines_EventScript_M4TurnOn::
	clearflag FLAG_TEMP_8
	addobject LOCALID_MERAL4
	goto TheColdMines_EventScript_M4SetSurround1
	release
	end

TheColdMines_EventScript_M4TurnOff::
	setflag FLAG_TEMP_8
	removeobject LOCALID_MERAL4
	goto TheColdMines_EventScript_M4SetSurround1
	release
	end

TheColdMines_EventScript_M4SetSurround1::
	goto_if_set FLAG_TEMP_9, TheColdMines_EventScript_M4SetOnM5
	goto_if_unset FLAG_TEMP_9, TheColdMines_EventScript_M4SetOffM5
	release
	end

TheColdMines_EventScript_M4SetOnM5::
	clearflag FLAG_TEMP_9
	addobject LOCALID_MERAL5
	goto TheColdMines_EventScript_M4SetSurround2
	release
	end

TheColdMines_EventScript_M4SetOffM5::
	setflag FLAG_TEMP_9
	removeobject LOCALID_MERAL5
	goto TheColdMines_EventScript_M4SetSurround2
	release
	end

TheColdMines_EventScript_M4SetSurround2::
	goto_if_set FLAG_TEMP_7, TheColdMines_EventScript_M4SetOnM3
	goto_if_unset FLAG_TEMP_7, TheColdMines_EventScript_M4SetOffM3
	release
	end

TheColdMines_EventScript_M4SetOnM3::
	clearflag FLAG_TEMP_7
	addobject LOCALID_MERAL3
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M4SetOffM3::
	setflag FLAG_TEMP_7
	removeobject LOCALID_MERAL3
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M5FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M5Interact
	release
	end

TheColdMines_EventScript_M5Interact::
	goto_if_set FLAG_TEMP_9, TheColdMines_EventScript_M5TurnOn
	goto_if_unset FLAG_TEMP_9, TheColdMines_EventScript_M5TurnOff
	release
	end

TheColdMines_EventScript_M5TurnOn::
	clearflag FLAG_TEMP_9
	addobject LOCALID_MERAL5
	goto TheColdMines_EventScript_M5SetSurround1
	release
	end

TheColdMines_EventScript_M5TurnOff::
	setflag FLAG_TEMP_9
	removeobject LOCALID_MERAL5
	goto TheColdMines_EventScript_M5SetSurround1
	release
	end

TheColdMines_EventScript_M5SetSurround1::
	goto_if_set FLAG_TEMP_8, TheColdMines_EventScript_M5SetOnM4
	goto_if_unset FLAG_TEMP_8, TheColdMines_EventScript_M5SetOffM4
	release
	end

TheColdMines_EventScript_M5SetOnM4::
	clearflag FLAG_TEMP_8
	addobject LOCALID_MERAL4
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M5SetOffM4::
	setflag FLAG_TEMP_8
	removeobject LOCALID_MERAL4
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_CheckPuzzle2SetFlags::
	goto_if_set FLAG_TEMP_A, TheColdMines_EventScript_CheckTempB
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTempB::
	goto_if_set FLAG_TEMP_B, TheColdMines_EventScript_CheckTempC
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTempC::
	goto_if_set FLAG_TEMP_C, TheColdMines_EventScript_CheckTempD
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTempD::
	goto_if_set FLAG_TEMP_D, TheColdMines_EventScript_CheckTempE
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTempE::
	goto_if_set FLAG_TEMP_E, TheColdMines_EventScript_ClearedPuzzle2Part1
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_ClearedPuzzle2Part1::
	setmetatile 29, 26, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 29, 27, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 28, 27, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 30, 27, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 31, 27, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 31, 28, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 30, 28, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 32, 28, METATILE_Snow_MeralBuriedRight1, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 29, 26, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 27, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 28, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 28, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 30, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 28, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 29, 26, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 28, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 27, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 28, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setvar VAR_TEMP_4, 0
	playse SE_SUCCESS
	release
	end

TheColdMines_EventScript_CheckPuzzle2Part2SetFlags::
	goto_if_set FLAG_TEMP_C, TheColdMines_EventScript_CheckTempD2
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTempD2::
	goto_if_set FLAG_TEMP_D, TheColdMines_EventScript_CheckTempE2
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTempE2::
	goto_if_set FLAG_TEMP_E, TheColdMines_EventScript_CheckTemp11
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp11::
	goto_if_set FLAG_TEMP_11, TheColdMines_EventScript_CheckTemp12
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp12::
	goto_if_set FLAG_TEMP_12, TheColdMines_EventScript_CheckTemp13
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp13::
	goto_if_set FLAG_TEMP_13, TheColdMines_EventScript_ClearedPuzzle2Part2
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_ClearedPuzzle2Part2::
	setmetatile 33, 22, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 33, 23, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 34, 23, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 31, 22, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 31, 23, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 30, 23, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 29, 23, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 29, 24, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 28, 24, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 30, 24, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 21, 28, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 21, 29, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 22, 29, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 20, 29, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 19, 29, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 19, 30, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 18, 30, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 20, 30, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 17, 31, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 17, 32, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 16, 32, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 18, 32, METATILE_Snow_MeralBuriedRight1, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 33, 22, METATILE_Snow_MeralSnow, FALSE
	setmetatile 33, 23, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 34, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 22, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 23, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 30, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 24, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 28, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 21, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 21, 29, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 22, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 20, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 19, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 19, 30, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 18, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 20, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 17, 31, METATILE_Snow_MeralSnow, FALSE
	setmetatile 17, 32, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 16, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 18, 32, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 33, 22, METATILE_Snow_MeralSnow, FALSE
	setmetatile 33, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 34, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 22, METATILE_Snow_MeralSnow, FALSE
	setmetatile 31, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 32, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 23, METATILE_Snow_MeralSnow, FALSE
	setmetatile 29, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 28, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 30, 24, METATILE_Snow_MeralSnow, FALSE
	setmetatile 21, 28, METATILE_Snow_MeralSnow, FALSE
	setmetatile 21, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 22, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 20, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 19, 29, METATILE_Snow_MeralSnow, FALSE
	setmetatile 19, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 18, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 20, 30, METATILE_Snow_MeralSnow, FALSE
	setmetatile 17, 31, METATILE_Snow_MeralSnow, FALSE
	setmetatile 17, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 16, 32, METATILE_Snow_MeralSnow, FALSE
	setmetatile 18, 32, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setvar VAR_MINES_MERALCORE_STATE, 3
	setvar VAR_TEMP_4, 0
	playse SE_SUCCESS
	release
	end

TheColdMines_EventScript_M6FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 1, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M6Interact
	release
	end

TheColdMines_EventScript_M6Interact::
	goto_if_set FLAG_TEMP_A, TheColdMines_EventScript_M6TurnOn
	goto_if_unset FLAG_TEMP_A, TheColdMines_EventScript_M6TurnOff
	release
	end

TheColdMines_EventScript_M6TurnOn::
	clearflag FLAG_TEMP_A
	addobject LOCALID_MERAL6
	goto TheColdMines_EventScript_M6SetSurround1
	release
	end

TheColdMines_EventScript_M6TurnOff::
	setflag FLAG_TEMP_A
	removeobject LOCALID_MERAL6
	goto TheColdMines_EventScript_M6SetSurround1
	release
	end

TheColdMines_EventScript_M6SetSurround1::
	goto_if_set FLAG_TEMP_B, TheColdMines_EventScript_M6SetOnM7
	goto_if_unset FLAG_TEMP_B, TheColdMines_EventScript_M6SetOffM7
	release
	end

TheColdMines_EventScript_M6SetOnM7::
	clearflag FLAG_TEMP_B
	addobject LOCALID_MERAL7
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M6SetOffM7::
	setflag FLAG_TEMP_B
	removeobject LOCALID_MERAL7
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M7FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 1, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M7Interact
	release
	end

TheColdMines_EventScript_M7Interact::
	goto_if_set FLAG_TEMP_B, TheColdMines_EventScript_M7TurnOn
	goto_if_unset FLAG_TEMP_B, TheColdMines_EventScript_M7TurnOff
	release
	end

TheColdMines_EventScript_M7TurnOn::
	clearflag FLAG_TEMP_B
	addobject LOCALID_MERAL7
	goto TheColdMines_EventScript_M7SetSurround1
	release
	end

TheColdMines_EventScript_M7TurnOff::
	setflag FLAG_TEMP_B
	removeobject LOCALID_MERAL7
	goto TheColdMines_EventScript_M7SetSurround1
	release
	end

TheColdMines_EventScript_M7SetSurround1::
	goto_if_set FLAG_TEMP_C, TheColdMines_EventScript_M7SetOnM8
	goto_if_unset FLAG_TEMP_C, TheColdMines_EventScript_M7SetOffM8
	release
	end

TheColdMines_EventScript_M7SetOnM8::
	clearflag FLAG_TEMP_C
	addobject LOCALID_MERAL8
	goto TheColdMines_EventScript_M7SetSurround2
	release
	end

TheColdMines_EventScript_M7SetOffM8::
	setflag FLAG_TEMP_C
	removeobject LOCALID_MERAL8
	goto TheColdMines_EventScript_M7SetSurround2
	release
	end

TheColdMines_EventScript_M7SetSurround2::
	goto_if_set FLAG_TEMP_A, TheColdMines_EventScript_M7SetOnM6
	goto_if_unset FLAG_TEMP_A, TheColdMines_EventScript_M7SetOffM6
	release
	end

TheColdMines_EventScript_M7SetOnM6::
	clearflag FLAG_TEMP_A
	addobject LOCALID_MERAL6
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M7SetOffM6::
	setflag FLAG_TEMP_A
	removeobject LOCALID_MERAL6
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M8FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M8Interact
	release
	end

TheColdMines_EventScript_M8Interact::
	goto_if_set FLAG_TEMP_C, TheColdMines_EventScript_M8TurnOn
	goto_if_unset FLAG_TEMP_C, TheColdMines_EventScript_M8TurnOff
	release
	end

TheColdMines_EventScript_M8TurnOn::
	clearflag FLAG_TEMP_C
	addobject LOCALID_MERAL8
	goto TheColdMines_EventScript_M8SetSurround1
	release
	end

TheColdMines_EventScript_M8TurnOff::
	setflag FLAG_TEMP_C
	removeobject LOCALID_MERAL8
	goto TheColdMines_EventScript_M8SetSurround1
	release
	end

TheColdMines_EventScript_M8SetSurround1::
	goto_if_set FLAG_TEMP_D, TheColdMines_EventScript_M8SetOnM9
	goto_if_unset FLAG_TEMP_D, TheColdMines_EventScript_M8SetOffM9
	release
	end

TheColdMines_EventScript_M8SetOnM9::
	clearflag FLAG_TEMP_D
	addobject LOCALID_MERAL9
	goto TheColdMines_EventScript_M8SetSurround2
	release
	end

TheColdMines_EventScript_M8SetOffM9::
	setflag FLAG_TEMP_D
	removeobject LOCALID_MERAL9
	goto TheColdMines_EventScript_M8SetSurround2
	release
	end

TheColdMines_EventScript_M8SetSurround2::
	goto_if_set FLAG_TEMP_13, TheColdMines_EventScript_M8SetOnM13
	goto_if_unset FLAG_TEMP_13, TheColdMines_EventScript_M8SetOffM13
	release
	end

TheColdMines_EventScript_M8SetOnM13::
	clearflag FLAG_TEMP_13
	addobject LOCALID_MERAL13
	goto_if_eq VAR_MINES_MERALCORE_STATE, 1, TheColdMines_EventScript_M8SetSurround3
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M8SetOffM13::
	setflag FLAG_TEMP_13
	removeobject LOCALID_MERAL13
	goto_if_eq VAR_MINES_MERALCORE_STATE, 1, TheColdMines_EventScript_M8SetSurround3
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M8SetSurround3::
	goto_if_set FLAG_TEMP_B, TheColdMines_EventScript_M8SetOnM7
	goto_if_unset FLAG_TEMP_B, TheColdMines_EventScript_M8SetOffM7
	release
	end

TheColdMines_EventScript_M8SetOnM7::
	clearflag FLAG_TEMP_B
	addobject LOCALID_MERAL7
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M8SetOffM7::
	setflag FLAG_TEMP_B
	removeobject LOCALID_MERAL7
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M9FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M9Interact
	release
	end

TheColdMines_EventScript_M9Interact::
	goto_if_set FLAG_TEMP_D, TheColdMines_EventScript_M9TurnOn
	goto_if_unset FLAG_TEMP_D, TheColdMines_EventScript_M9TurnOff
	release
	end

TheColdMines_EventScript_M9TurnOn::
	clearflag FLAG_TEMP_D
	addobject LOCALID_MERAL9
	goto TheColdMines_EventScript_M9SetSurround1
	release
	end

TheColdMines_EventScript_M9TurnOff::
	setflag FLAG_TEMP_D
	removeobject LOCALID_MERAL9
	goto TheColdMines_EventScript_M9SetSurround1
	release
	end

TheColdMines_EventScript_M9SetSurround1::
	goto_if_set FLAG_TEMP_E, TheColdMines_EventScript_M9SetOnM10
	goto_if_unset FLAG_TEMP_E, TheColdMines_EventScript_M9SetOffM10
	release
	end

TheColdMines_EventScript_M9SetOnM10::
	clearflag FLAG_TEMP_E
	addobject LOCALID_MERAL10
	goto TheColdMines_EventScript_M9SetSurround2
	release
	end

TheColdMines_EventScript_M9SetOffM10::
	setflag FLAG_TEMP_E
	removeobject LOCALID_MERAL10
	goto TheColdMines_EventScript_M9SetSurround2
	release
	end

TheColdMines_EventScript_M9SetSurround2::
	goto_if_set FLAG_TEMP_C, TheColdMines_EventScript_M9SetOnM8
	goto_if_unset FLAG_TEMP_C, TheColdMines_EventScript_M9SetOffM8
	release
	end

TheColdMines_EventScript_M9SetOnM8::
	clearflag FLAG_TEMP_C
	addobject LOCALID_MERAL8
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M9SetOffM8::
	setflag FLAG_TEMP_C
	removeobject LOCALID_MERAL8
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M10FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M10Interact
	release
	end

TheColdMines_EventScript_M10Interact::
	goto_if_set FLAG_TEMP_E, TheColdMines_EventScript_M10TurnOn
	goto_if_unset FLAG_TEMP_E, TheColdMines_EventScript_M10TurnOff
	release
	end

TheColdMines_EventScript_M10TurnOn::
	clearflag FLAG_TEMP_E
	addobject LOCALID_MERAL10
	goto TheColdMines_EventScript_M10SetSurround1
	release
	end

TheColdMines_EventScript_M10TurnOff::
	setflag FLAG_TEMP_E
	removeobject LOCALID_MERAL10
	goto TheColdMines_EventScript_M10SetSurround1
	release
	end

TheColdMines_EventScript_M10SetSurround1::
	goto_if_set FLAG_TEMP_D, TheColdMines_EventScript_M10SetOnM9
	goto_if_unset FLAG_TEMP_D, TheColdMines_EventScript_M10SetOffM9
	release
	end

TheColdMines_EventScript_M10SetOnM9::
	clearflag FLAG_TEMP_D
	addobject LOCALID_MERAL9
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M10SetOffM9::
	setflag FLAG_TEMP_D
	removeobject LOCALID_MERAL9
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M11FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M11Interact
	release
	end

TheColdMines_EventScript_M11Interact::
	goto_if_set FLAG_TEMP_11, TheColdMines_EventScript_M11TurnOn
	goto_if_unset FLAG_TEMP_11, TheColdMines_EventScript_M11TurnOff
	release
	end

TheColdMines_EventScript_M11TurnOn::
	clearflag FLAG_TEMP_11
	addobject LOCALID_MERAL11
	goto TheColdMines_EventScript_M11SetSurround1
	release
	end

TheColdMines_EventScript_M11TurnOff::
	setflag FLAG_TEMP_11
	removeobject LOCALID_MERAL11
	goto TheColdMines_EventScript_M11SetSurround1
	release
	end

TheColdMines_EventScript_M11SetSurround1::
	goto_if_set FLAG_TEMP_12, TheColdMines_EventScript_M11SetOnM12
	goto_if_unset FLAG_TEMP_12, TheColdMines_EventScript_M11SetOffM12
	release
	end

TheColdMines_EventScript_M11SetOnM12::
	clearflag FLAG_TEMP_12
	addobject LOCALID_MERAL12
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M11SetOffM12::
	setflag FLAG_TEMP_12
	removeobject LOCALID_MERAL12
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M12FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M12Interact
	release
	end

TheColdMines_EventScript_M12Interact::
	goto_if_set FLAG_TEMP_12, TheColdMines_EventScript_M12TurnOn
	goto_if_unset FLAG_TEMP_12, TheColdMines_EventScript_M12TurnOff
	release
	end

TheColdMines_EventScript_M12TurnOn::
	clearflag FLAG_TEMP_12
	addobject LOCALID_MERAL12
	goto TheColdMines_EventScript_M12SetSurround1
	release
	end

TheColdMines_EventScript_M12TurnOff::
	setflag FLAG_TEMP_12
	removeobject LOCALID_MERAL12
	goto TheColdMines_EventScript_M12SetSurround1
	release
	end

TheColdMines_EventScript_M12SetSurround1::
	goto_if_set FLAG_TEMP_13, TheColdMines_EventScript_M12SetOnM13
	goto_if_unset FLAG_TEMP_13, TheColdMines_EventScript_M12SetOffM13
	release
	end

TheColdMines_EventScript_M12SetOnM13::
	clearflag FLAG_TEMP_13
	addobject LOCALID_MERAL13
	goto TheColdMines_EventScript_M12SetSurround2
	release
	end

TheColdMines_EventScript_M12SetOffM13::
	setflag FLAG_TEMP_13
	removeobject LOCALID_MERAL13
	goto TheColdMines_EventScript_M12SetSurround2
	release
	end

TheColdMines_EventScript_M12SetSurround2::
	goto_if_set FLAG_TEMP_11, TheColdMines_EventScript_M12SetOnM11
	goto_if_unset FLAG_TEMP_11, TheColdMines_EventScript_M12SetOffM11
	release
	end

TheColdMines_EventScript_M12SetOnM11::
	clearflag FLAG_TEMP_11
	addobject LOCALID_MERAL11
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M12SetOffM11::
	setflag FLAG_TEMP_11
	removeobject LOCALID_MERAL11
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M13FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M13Interact
	release
	end

TheColdMines_EventScript_M13Interact::
	goto_if_set FLAG_TEMP_13, TheColdMines_EventScript_M13TurnOn
	goto_if_unset FLAG_TEMP_13, TheColdMines_EventScript_M13TurnOff
	release
	end

TheColdMines_EventScript_M13TurnOn::
	clearflag FLAG_TEMP_13
	addobject LOCALID_MERAL13
	goto TheColdMines_EventScript_M13SetSurround1
	release
	end

TheColdMines_EventScript_M13TurnOff::
	setflag FLAG_TEMP_13
	removeobject LOCALID_MERAL13
	goto TheColdMines_EventScript_M13SetSurround1
	release
	end

TheColdMines_EventScript_M13SetSurround1::
	goto_if_set FLAG_TEMP_C, TheColdMines_EventScript_M13SetOnM8
	goto_if_unset FLAG_TEMP_C, TheColdMines_EventScript_M13SetOffM8
	release
	end

TheColdMines_EventScript_M13SetOnM8::
	clearflag FLAG_TEMP_C
	addobject LOCALID_MERAL8
	goto TheColdMines_EventScript_M13SetSurround2
	release
	end

TheColdMines_EventScript_M13SetOffM8::
	setflag FLAG_TEMP_C
	removeobject LOCALID_MERAL8
	goto TheColdMines_EventScript_M13SetSurround2
	release
	end

TheColdMines_EventScript_M13SetSurround2::
	goto_if_set FLAG_TEMP_12, TheColdMines_EventScript_M13SetOnM12
	goto_if_unset FLAG_TEMP_12, TheColdMines_EventScript_M13SetOffM12
	release
	end

TheColdMines_EventScript_M13SetOnM12::
	clearflag FLAG_TEMP_12
	addobject LOCALID_MERAL12
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M13SetOffM12::
	setflag FLAG_TEMP_12
	removeobject LOCALID_MERAL12
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_MeddlingElectrician::
	lock
	applymovement LOCALID_ELECTRICIAN, TheColdMines_Movement_WalkUpToMeral
	waitmovement 0
	setvar VAR_MINES_MERALCORE_STATE, 2
	msgbox TheColdMines_Text_WhatIsThisThing, MSGBOX_AUTOCLOSE
	goto TheColdMines_EventScript_M13Interact
	release
	end

TheColdMines_Movement_WalkUpToMeral:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

TheColdMines_EventScript_CheckPuzzle3SetFlags::
	goto_if_set FLAG_TEMP_14, TheColdMines_EventScript_CheckTemp15
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp15::
	goto_if_set FLAG_TEMP_15, TheColdMines_EventScript_CheckTemp16
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp16::
	goto_if_set FLAG_TEMP_16, TheColdMines_EventScript_CheckTemp17
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp17::
	goto_if_set FLAG_TEMP_17, TheColdMines_EventScript_CheckTemp18
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp18::
	goto_if_set FLAG_TEMP_18, TheColdMines_EventScript_CheckTemp19
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp19::
	goto_if_set FLAG_TEMP_19, TheColdMines_EventScript_CheckTemp1A
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_CheckTemp1A::
	goto_if_set FLAG_TEMP_1A, TheColdMines_EventScript_ClearedPuzzle3
	setvar VAR_TEMP_4, 0
	release
	end

TheColdMines_EventScript_ClearedPuzzle3::
	setmetatile 40, 10, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 40, 11, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 41, 11, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 39, 11, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 38, 8, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 38, 9, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 37, 9, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 39, 9, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 37, 6, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 37, 7, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 36, 7, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 38, 7, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 39, 4, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 39, 5, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 38, 5, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 40, 5, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 41, 5, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 41, 6, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 40, 6, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 42, 6, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 43, 7, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 43, 8, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 44, 8, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 42, 8, METATILE_Snow_MeralBuriedLeft1, FALSE
	setmetatile 44, 9, METATILE_Snow_MeralBuriedTop1, FALSE
	setmetatile 44, 10, METATILE_Snow_MeralBuriedMiddle1, FALSE
	setmetatile 45, 10, METATILE_Snow_MeralBuriedRight1, FALSE
	setmetatile 43, 10, METATILE_Snow_MeralBuriedLeft1, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 40, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 11, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 41, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 9, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 37, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 7, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 36, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 4, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 5, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 38, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 6, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 40, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 8, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 44, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 10, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 45, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 10, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 40, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 11, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 36, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 4, METATILE_Snow_MeralSnow, FALSE
	setmetatile 39, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 5, METATILE_Snow_MeralSnow, FALSE
	setmetatile 41, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 40, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 42, 8, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 9, METATILE_Snow_MeralSnow, FALSE
	setmetatile 44, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 45, 10, METATILE_Snow_MeralSnow, FALSE
	setmetatile 43, 10, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setmetatile 37, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 7, METATILE_Snow_MeralBuriedMiddle2, FALSE
	setmetatile 36, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 7, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	clearflag FLAG_ITEM_TM_ZING_ZAP
	addobject LOCALID_TMBALL
	setmetatile 37, 6, METATILE_Snow_MeralSnow, FALSE
	setmetatile 37, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 36, 7, METATILE_Snow_MeralSnow, FALSE
	setmetatile 38, 7, METATILE_Snow_MeralSnow, FALSE
	special DrawWholeMapView
	playse SE_M_DIG
	waitse
	setvar VAR_MINES_MERALCORE_STATE, 4
	setvar VAR_TEMP_4, 0
	playse SE_SUCCESS
	release
	end

TheColdMines_EventScript_ZingZapTMBall::
	finditem ITEM_TM_ZING_ZAP
	end

TheColdMines_EventScript_M14FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M14Interact
	release
	end

TheColdMines_EventScript_M14Interact::
	goto_if_set FLAG_TEMP_14, TheColdMines_EventScript_M14TurnOn
	goto_if_unset FLAG_TEMP_14, TheColdMines_EventScript_M14TurnOff
	release
	end

TheColdMines_EventScript_M14TurnOn::
	clearflag FLAG_TEMP_14
	addobject LOCALID_MERAL14
	goto TheColdMines_EventScript_M14SetSurround1
	release
	end

TheColdMines_EventScript_M14TurnOff::
	setflag FLAG_TEMP_14
	removeobject LOCALID_MERAL14
	goto TheColdMines_EventScript_M14SetSurround1
	release
	end

TheColdMines_EventScript_M14SetSurround1::
	goto_if_set FLAG_TEMP_15, TheColdMines_EventScript_M14SetOnM15
	goto_if_unset FLAG_TEMP_15, TheColdMines_EventScript_M14SetOffM15
	release
	end

TheColdMines_EventScript_M14SetOnM15::
	clearflag FLAG_TEMP_15
	addobject LOCALID_MERAL15
	goto TheColdMines_EventScript_M14SetSurround2
	release
	end

TheColdMines_EventScript_M14SetOffM15::
	setflag FLAG_TEMP_15
	removeobject LOCALID_MERAL15
	goto TheColdMines_EventScript_M14SetSurround2
	release
	end

TheColdMines_EventScript_M14SetSurround2::
	goto_if_set FLAG_TEMP_1A, TheColdMines_EventScript_M14SetOnM20
	goto_if_unset FLAG_TEMP_1A, TheColdMines_EventScript_M14SetOffM20
	release
	end

TheColdMines_EventScript_M14SetOnM20::
	clearflag FLAG_TEMP_1A
	addobject LOCALID_MERAL20
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M14SetOffM20::
	setflag FLAG_TEMP_1A
	removeobject LOCALID_MERAL20
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M15FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M15Interact
	release
	end

TheColdMines_EventScript_M15Interact::
	goto_if_set FLAG_TEMP_15, TheColdMines_EventScript_M15TurnOn
	goto_if_unset FLAG_TEMP_15, TheColdMines_EventScript_M15TurnOff
	release
	end

TheColdMines_EventScript_M15TurnOn::
	clearflag FLAG_TEMP_15
	addobject LOCALID_MERAL15
	goto TheColdMines_EventScript_M15SetSurround1
	release
	end

TheColdMines_EventScript_M15TurnOff::
	setflag FLAG_TEMP_15
	removeobject LOCALID_MERAL15
	goto TheColdMines_EventScript_M15SetSurround1
	release
	end

TheColdMines_EventScript_M15SetSurround1::
	goto_if_set FLAG_TEMP_16, TheColdMines_EventScript_M15SetOnM16
	goto_if_unset FLAG_TEMP_16, TheColdMines_EventScript_M15SetOffM16
	release
	end

TheColdMines_EventScript_M15SetOnM16::
	clearflag FLAG_TEMP_16
	addobject LOCALID_MERAL16
	goto TheColdMines_EventScript_M15SetSurround2
	release
	end

TheColdMines_EventScript_M15SetOffM16::
	setflag FLAG_TEMP_16
	removeobject LOCALID_MERAL16
	goto TheColdMines_EventScript_M15SetSurround2
	release
	end

TheColdMines_EventScript_M15SetSurround2::
	goto_if_set FLAG_TEMP_14, TheColdMines_EventScript_M15SetOnM14
	goto_if_unset FLAG_TEMP_14, TheColdMines_EventScript_M15SetOffM14
	release
	end

TheColdMines_EventScript_M15SetOnM14::
	clearflag FLAG_TEMP_14
	addobject LOCALID_MERAL14
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M15SetOffM14::
	setflag FLAG_TEMP_14
	removeobject LOCALID_MERAL14
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M16FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M16Interact
	release
	end

TheColdMines_EventScript_M16Interact::
	goto_if_set FLAG_TEMP_16, TheColdMines_EventScript_M16TurnOn
	goto_if_unset FLAG_TEMP_16, TheColdMines_EventScript_M16TurnOff
	release
	end

TheColdMines_EventScript_M16TurnOn::
	clearflag FLAG_TEMP_16
	addobject LOCALID_MERAL16
	goto TheColdMines_EventScript_M16SetSurround1
	release
	end

TheColdMines_EventScript_M16TurnOff::
	setflag FLAG_TEMP_16
	removeobject LOCALID_MERAL16
	goto TheColdMines_EventScript_M16SetSurround1
	release
	end

TheColdMines_EventScript_M16SetSurround1::
	goto_if_set FLAG_TEMP_17, TheColdMines_EventScript_M16SetOnM17
	goto_if_unset FLAG_TEMP_17, TheColdMines_EventScript_M16SetOffM17
	release
	end

TheColdMines_EventScript_M16SetOnM17::
	clearflag FLAG_TEMP_17
	addobject LOCALID_MERAL17
	goto TheColdMines_EventScript_M16SetSurround2
	release
	end

TheColdMines_EventScript_M16SetOffM17::
	setflag FLAG_TEMP_17
	removeobject LOCALID_MERAL17
	goto TheColdMines_EventScript_M16SetSurround2
	release
	end

TheColdMines_EventScript_M16SetSurround2::
	goto_if_set FLAG_TEMP_15, TheColdMines_EventScript_M16SetOnM15
	goto_if_unset FLAG_TEMP_15, TheColdMines_EventScript_M16SetOffM15
	release
	end

TheColdMines_EventScript_M16SetOnM15::
	clearflag FLAG_TEMP_15
	addobject LOCALID_MERAL15
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M16SetOffM15::
	setflag FLAG_TEMP_15
	removeobject LOCALID_MERAL15
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M17FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M17Interact
	release
	end

TheColdMines_EventScript_M17Interact::
	goto_if_set FLAG_TEMP_17, TheColdMines_EventScript_M17TurnOn
	goto_if_unset FLAG_TEMP_17, TheColdMines_EventScript_M17TurnOff
	release
	end

TheColdMines_EventScript_M17TurnOn::
	clearflag FLAG_TEMP_17
	addobject LOCALID_MERAL17
	goto TheColdMines_EventScript_M17SetSurround1
	release
	end

TheColdMines_EventScript_M17TurnOff::
	setflag FLAG_TEMP_17
	removeobject LOCALID_MERAL17
	goto TheColdMines_EventScript_M17SetSurround1
	release
	end

TheColdMines_EventScript_M17SetSurround1::
	goto_if_set FLAG_TEMP_18, TheColdMines_EventScript_M17SetOnM18
	goto_if_unset FLAG_TEMP_18, TheColdMines_EventScript_M17SetOffM18
	release
	end

TheColdMines_EventScript_M17SetOnM18::
	clearflag FLAG_TEMP_18
	addobject LOCALID_MERAL18
	goto TheColdMines_EventScript_M17SetSurround2
	release
	end

TheColdMines_EventScript_M17SetOffM18::
	setflag FLAG_TEMP_18
	removeobject LOCALID_MERAL18
	goto TheColdMines_EventScript_M17SetSurround2
	release
	end

TheColdMines_EventScript_M17SetSurround2::
	goto_if_set FLAG_TEMP_16, TheColdMines_EventScript_M17SetOnM16
	goto_if_unset FLAG_TEMP_16, TheColdMines_EventScript_M17SetOffM16
	release
	end

TheColdMines_EventScript_M17SetOnM16::
	clearflag FLAG_TEMP_16
	addobject LOCALID_MERAL16
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M17SetOffM16::
	setflag FLAG_TEMP_16
	removeobject LOCALID_MERAL16
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M18FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M18Interact
	release
	end

TheColdMines_EventScript_M18Interact::
	goto_if_set FLAG_TEMP_18, TheColdMines_EventScript_M18TurnOn
	goto_if_unset FLAG_TEMP_18, TheColdMines_EventScript_M18TurnOff
	release
	end

TheColdMines_EventScript_M18TurnOn::
	clearflag FLAG_TEMP_18
	addobject LOCALID_MERAL18
	goto TheColdMines_EventScript_M18SetSurround1
	release
	end

TheColdMines_EventScript_M18TurnOff::
	setflag FLAG_TEMP_18
	removeobject LOCALID_MERAL18
	goto TheColdMines_EventScript_M18SetSurround1
	release
	end

TheColdMines_EventScript_M18SetSurround1::
	goto_if_set FLAG_TEMP_19, TheColdMines_EventScript_M18SetOnM19
	goto_if_unset FLAG_TEMP_19, TheColdMines_EventScript_M18SetOffM19
	release
	end

TheColdMines_EventScript_M18SetOnM19::
	clearflag FLAG_TEMP_19
	addobject LOCALID_MERAL19
	goto TheColdMines_EventScript_M18SetSurround2
	release
	end

TheColdMines_EventScript_M18SetOffM19::
	setflag FLAG_TEMP_19
	removeobject LOCALID_MERAL19
	goto TheColdMines_EventScript_M18SetSurround2
	release
	end

TheColdMines_EventScript_M18SetSurround2::
	goto_if_set FLAG_TEMP_17, TheColdMines_EventScript_M18SetOnM17
	goto_if_unset FLAG_TEMP_17, TheColdMines_EventScript_M18SetOffM17
	release
	end

TheColdMines_EventScript_M18SetOnM17::
	clearflag FLAG_TEMP_17
	addobject LOCALID_MERAL17
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M18SetOffM17::
	setflag FLAG_TEMP_17
	removeobject LOCALID_MERAL17
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M19FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M19Interact
	release
	end

TheColdMines_EventScript_M19Interact::
	goto_if_set FLAG_TEMP_19, TheColdMines_EventScript_M19TurnOn
	goto_if_unset FLAG_TEMP_19, TheColdMines_EventScript_M19TurnOff
	release
	end

TheColdMines_EventScript_M19TurnOn::
	clearflag FLAG_TEMP_19
	addobject LOCALID_MERAL19
	goto TheColdMines_EventScript_M19SetSurround1
	release
	end

TheColdMines_EventScript_M19TurnOff::
	setflag FLAG_TEMP_19
	removeobject LOCALID_MERAL19
	goto TheColdMines_EventScript_M19SetSurround1
	release
	end

TheColdMines_EventScript_M19SetSurround1::
	goto_if_set FLAG_TEMP_1A, TheColdMines_EventScript_M19SetOnM20
	goto_if_unset FLAG_TEMP_1A, TheColdMines_EventScript_M19SetOffM20
	release
	end

TheColdMines_EventScript_M19SetOnM20::
	clearflag FLAG_TEMP_1A
	addobject LOCALID_MERAL20
	goto TheColdMines_EventScript_M19SetSurround2
	release
	end

TheColdMines_EventScript_M19SetOffM20::
	setflag FLAG_TEMP_1A
	removeobject LOCALID_MERAL20
	goto TheColdMines_EventScript_M19SetSurround2
	release
	end

TheColdMines_EventScript_M19SetSurround2::
	goto_if_set FLAG_TEMP_18, TheColdMines_EventScript_M19SetOnM18
	goto_if_unset FLAG_TEMP_18, TheColdMines_EventScript_M19SetOffM18
	release
	end

TheColdMines_EventScript_M19SetOnM18::
	clearflag FLAG_TEMP_18
	addobject LOCALID_MERAL18
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M19SetOffM18::
	setflag FLAG_TEMP_18
	removeobject LOCALID_MERAL18
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M20FlashCheck::
	lock
	goto_if_gt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_OnceWasMeralcore
	msgbox TheColdMines_Text_ThereIsMeralcore, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE02_GET, TheColdMines_EventScript_CantFlash
	checkpartymove MOVE_FLASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantFlash
	msgbox TheColdMines_Text_WantToUseFlash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_M20Interact
	release
	end

TheColdMines_EventScript_M20Interact::
	goto_if_set FLAG_TEMP_1A, TheColdMines_EventScript_M20TurnOn
	goto_if_unset FLAG_TEMP_1A, TheColdMines_EventScript_M20TurnOff
	release
	end

TheColdMines_EventScript_M20TurnOn::
	clearflag FLAG_TEMP_1A
	addobject LOCALID_MERAL20
	goto TheColdMines_EventScript_M20SetSurround1
	release
	end

TheColdMines_EventScript_M20TurnOff::
	setflag FLAG_TEMP_1A
	removeobject LOCALID_MERAL20
	goto TheColdMines_EventScript_M20SetSurround1
	release
	end

TheColdMines_EventScript_M20SetSurround1::
	goto_if_set FLAG_TEMP_14, TheColdMines_EventScript_M20SetOnM14
	goto_if_unset FLAG_TEMP_14, TheColdMines_EventScript_M20SetOffM14
	release
	end

TheColdMines_EventScript_M20SetOnM14::
	clearflag FLAG_TEMP_14
	addobject LOCALID_MERAL14
	goto TheColdMines_EventScript_M20SetSurround2
	release
	end

TheColdMines_EventScript_M20SetOffM14::
	setflag FLAG_TEMP_14
	removeobject LOCALID_MERAL14
	goto TheColdMines_EventScript_M20SetSurround2
	release
	end

TheColdMines_EventScript_M20SetSurround2::
	goto_if_set FLAG_TEMP_19, TheColdMines_EventScript_M20SetOnM19
	goto_if_unset FLAG_TEMP_19, TheColdMines_EventScript_M20SetOffM19
	release
	end

TheColdMines_EventScript_M20SetOnM19::
	clearflag FLAG_TEMP_19
	addobject LOCALID_MERAL19
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_M20SetOffM19::
	setflag FLAG_TEMP_19
	removeobject LOCALID_MERAL19
	playse SE_M_THUNDER_WAVE
	setvar VAR_TEMP_4, 69
	release
	end

TheColdMines_EventScript_CautionTape1::
	lock
	goto_if_set FLAG_TEMP_1B, TheColdMines_EventScript_CantCut
	msgbox TheColdMines_Text_ThereIsTape, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE03_GET, TheColdMines_EventScript_CantCut
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantCut
	msgbox TheColdMines_Text_WantToUseCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_CutTape1
	release
	end

TheColdMines_EventScript_CantCut::
	msgbox TheColdMines_Text_NoCut, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_CutTape1::
	playse SE_M_CUT
	waitse
	setflag FLAG_TEMP_1B
	setmetatile 22, 17, METATILE_Snow_ColdMineRightCliff, TRUE
	setmetatile 23, 17, METATILE_Snow_ColdMineFloor, FALSE
	setmetatile 24, 17, METATILE_Snow_ColdMineFloor, FALSE
	setmetatile 25, 17, METATILE_Snow_ColdMineLeftCliff, TRUE
	special DrawWholeMapView
	release
	end

TheColdMines_EventScript_CautionTape2::
	lock
	goto_if_set FLAG_TEMP_1C, TheColdMines_EventScript_CantCut
	msgbox TheColdMines_Text_ThereIsTape, MSGBOX_DEFAULT
	goto_if_unset FLAG_BADGE03_GET, TheColdMines_EventScript_CantCut
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, TheColdMines_EventScript_CantCut
	msgbox TheColdMines_Text_WantToUseCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_CutTape2
	release
	end

TheColdMines_EventScript_CutTape2::
	playse SE_M_CUT
	waitse
	setflag FLAG_TEMP_1C
	setmetatile 8, 18, METATILE_Snow_ColdMineRightCliff, TRUE
	setmetatile 9, 18, METATILE_Snow_ColdMineFloor, FALSE
	setmetatile 10, 18, METATILE_Snow_ColdMineFloor, FALSE
	setmetatile 11, 18, METATILE_Snow_ColdMineLeftCliff, TRUE
	special DrawWholeMapView
	release
	end

TheColdMines_EventScript_SouthHardhatter::
	lock
	faceplayer
	goto_if_gt VAR_OZONE_ADMINS_STATE, 2, TheColdMines_EventScript_SouthHardhatterPostOLBHQ
	setvar VAR_OZONE_ADMINS_STATE, 1
	msgbox TheColdMines_Text_NeedHelpClearingSnow, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_SouthHardhatterPostOLBHQ::
	msgbox TheColdMines_Text_NeverGetCold, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_NorthHardhatter::
	lock
	faceplayer
	goto_if_gt VAR_OZONE_ADMINS_STATE, 2, TheColdMines_EventScript_NorthHardhatterPostOLBHQ
	setvar VAR_OZONE_ADMINS_STATE, 1
	msgbox TheColdMines_Text_LottaSnowToShovel, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_NorthHardhatterPostOLBHQ::
	msgbox TheColdMines_Text_HurtFromShoveling, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_Tabitha::
	speakername TheColdMines_Text_NameTabitha
	msgbox TheColdMines_Text_WeWillTakeCareOfThis, MSGBOX_NPC
	speakername NULL
	end

TheColdMines_EventScript_Felix::
    trainerbattle_single TRAINER_P_FELIX, TheColdMines_Text_FelixIntro, TheColdMines_Text_FelixDefeated
    msgbox TheColdMines_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
    end

TheColdMines_EventScript_Ran::
    trainerbattle_single TRAINER_P_RAN, TheColdMines_Text_RanIntro, TheColdMines_Text_RanDefeated
    msgbox TheColdMines_Text_RanPostBattle, MSGBOX_AUTOCLOSE
    end

TheColdMines_EventScript_BigHertz::
    trainerbattle_single TRAINER_P_BIG_HERTZ, TheColdMines_Text_BigHertzIntro, TheColdMines_Text_BigHertzDefeated
    msgbox TheColdMines_Text_BigHertzPostBattle, MSGBOX_AUTOCLOSE
    end

TheColdMines_EventScript_TrainingMonk::
	lock
	checkitem ITEM_FOCUS_BAND
	goto_if_eq VAR_RESULT, TRUE, TheColdMines_EventScript_GaveFocusBand
	msgbox TheColdMines_Text_UpForAToughBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_Gotou
	msgbox TheColdMines_Text_IMayBeTooTough, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_Gotou::
    trainerbattle_single TRAINER_P_SUPERBOSS_MONK_1, TheColdMines_Text_GotouIntro, TheColdMines_Text_GotouDefeated, TheColdMines_EventScript_GotouBeaten
    release
    end

TheColdMines_EventScript_GotouBeaten::
	msgbox TheColdMines_Text_AVeryThrillingMatch, MSGBOX_DEFAULT
	giveitem ITEM_FOCUS_BAND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

TheColdMines_EventScript_GaveFocusBand::
	msgbox TheColdMines_Text_MustContinueTraining, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_Teleporter::
	lock
	faceplayer
	msgbox TheColdMines_Text_WouldYouLikeToWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TheColdMines_EventScript_WarpToShrine
	msgbox TheColdMines_Text_MaybeAnotherTime, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_EventScript_WarpToShrine::
	warp MAP_MT_PYRE_2F, 1, 4
	release
	end

TheColdMines_EventScript_Bulldoze::
	lock
	faceplayer
	checkitem ITEM_TM_BULLDOZE
	goto_if_eq VAR_RESULT, TRUE, TheColdMines_EventScript_GaveBulldoze
	msgbox TheColdMines_Text_Bulldoze, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULLDOZE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

TheColdMines_EventScript_GaveBulldoze::
	msgbox TheColdMines_Text_GaveBulldoze, MSGBOX_AUTOCLOSE
	release
	end

TheColdMines_Text_Bulldoze:
	.string "here have bulldoze$"

TheColdMines_Text_GaveBulldoze:
	.string "alr gave u bulldoze$"

TheColdMines_Text_UpForAToughBattle:
	.string "This subzero cavern is the ideal place\n"
	.string "to train, young one.\p"
	.string "I have been meditating here for\n"
	.string "quite some time. My chakra… this day,\l"
	.string "they feel perfectly aligned.\p"
	.string "I can sense you are a spunky trainer.\n"
	.string "You wish for a challenge.\p"
	.string "However, I must warn you.\n"
	.string "Myself and my Pokémon will be\l"
	.string "a steep hill to conquer.\p"
	.string "Does your resolve\n"
	.string "still stand resolutely?$"

TheColdMines_Text_IMayBeTooTough:
	.string "Then I ask you to leave me\n"
	.string "to my meditation.$"

TheColdMines_Text_AVeryThrillingMatch:
	.string "Through that battle, I could easily\n"
	.string "sense your heightened focus.\p"
	.string "That talent can potentially\n"
	.string "be honed further.\l"
	.string "Please, accept this before you\l"
	.string "take your leave.$"

TheColdMines_Text_MustContinueTraining:
	.string "i must continue my training$"

TheColdMines_Text_WouldYouLikeToWarp:
	.string "wanna warp$"

TheColdMines_Text_MaybeAnotherTime:
	.string "maybe nexttime$"

TheColdMines_Text_FelixIntro:
	.string "intro$"

TheColdMines_Text_FelixDefeated:
	.string "defeat$"

TheColdMines_Text_FelixPostBattle:
	.string "post$"

TheColdMines_Text_RanIntro:
	.string "intro$"

TheColdMines_Text_RanDefeated:
	.string "defeat$"

TheColdMines_Text_RanPostBattle:
	.string "post$"

TheColdMines_Text_BigHertzIntro:
	.string "intro$"

TheColdMines_Text_BigHertzDefeated:
	.string "defeat$"

TheColdMines_Text_BigHertzPostBattle:
	.string "post$"

TheColdMines_Text_GotouIntro:
	.string "Prepare, then, to take on the might of\na glacier!$"

TheColdMines_Text_GotouDefeated:
	.string "Stalwart and confident. Very impressive.$"

TheColdMines_Text_GotouPostBattle:
	.string "post$"

TheColdMines_Text_NeedHelpClearingSnow:
	.string "What's that?\nYou want passage through here?\p"
	.string "Wouldn't we all!\p"
	.string "Unfortunately, lady luck has frowned\n"
	.string "on us and struck us with a nasty\l"
	.string "cave-in.\p"
	.string "Currently waitin' on our boss Tabitha\n"
	.string "to bring over a few more workers.\p"
	.string "Unless you can get the boss' sorry\n"
	.string "buttocks over here, I'm afraid\l"
	.string "we're deadlocked.\p"
	.string "Maybe try askin' for Tabitha at\n"
	.string "Ol' Bihq. My sorry ass isn't\l"
	.string "allowed to leave my post.$"

TheColdMines_Text_NeverGetCold:
	.string "never get cold tbh$"

TheColdMines_Text_LottaSnowToShovel:
	.string "Sigh…\p"
	.string "That's a lotta snow to dig out…\p"
	.string "Boss… please give us mercy…!$"

TheColdMines_Text_HurtFromShoveling:
	.string "i be hurtin$"

TheColdMines_Text_NameTabitha:
	.string "Tabitha$"

TheColdMines_Text_WeWillTakeCareOfThis:
	.string "It will inevitably take my men a while\n"
	.string "to work through the snow.\l"
	.string "Please, do come back after a spell.\p"
	.string "If you want something to do while\n"
	.string "you're waiting, an old friend of mine\l"
	.string "is hosting some kind of class at\l"
	.string "Scuttill Way.\p"
	.string "Tell her I sent you.$"

TheColdMines_Text_ThereIsMeralcore:
	.string "It's a road-blocking Meralcore.\n"
	.string "The icy shell courses with\l"
	.string "electricity...$"

TheColdMines_Text_WantToUseFlash:
	.string "Would you like to use Flash\n"
	.string "to direct its current?$"

TheColdMines_Text_NoFlash:
	.string "no flash tho$"

TheColdMines_Text_OnceWasMeralcore:
	.string "once was a meral here$"

TheColdMines_Text_WhatIsThisThing:
	.string "what in tarnation$"

TheColdMines_Text_ThereIsTape:
	.string "there is tape here$"

TheColdMines_Text_WantToUseCut:
	.string "wanna cut it$"

TheColdMines_Text_NoCut:
	.string "no cut$"
