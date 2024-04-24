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

TheColdMines_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TheColdMines_OnLoad
	.byte 0

TheColdMines_OnLoad:
	call_if_gt VAR_OZONE_ADMINS_STATE, 3, TheColdMines_EventScript_ReplaceSouthSnow
	call_if_gt VAR_OZONE_ADMINS_STATE, 4, TheColdMines_EventScript_ReplaceNorthSnow
	call_if_eq VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_SetupMeralcorePuzzle1
	call_if_gt VAR_MINES_MERALCORE_STATE, 0, TheColdMines_EventScript_RemoveMeralcorePuzzle1
	call_if_lt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_SetupMeralcorePuzzle2
	call_if_gt VAR_MINES_MERALCORE_STATE, 1, TheColdMines_EventScript_RemoveMeralcorePuzzle2
	call_if_lt VAR_MINES_MERALCORE_STATE, 3, TheColdMines_EventScript_SetupMeralcorePuzzle3
	call_if_gt VAR_MINES_MERALCORE_STATE, 2, TheColdMines_EventScript_RemoveMeralcorePuzzle3
	end

TheColdMines_EventScript_SetupMeralcorePuzzle1::
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	removeobject LOCALID_MERAL3
	removeobject LOCALID_MERAL4
	return

TheColdMines_EventScript_SetupMeralcorePuzzle2::
	setflag FLAG_TEMP_A
	setflag FLAG_TEMP_C
	setflag FLAG_TEMP_13
	removeobject LOCALID_MERAL6
	removeobject LOCALID_MERAL8
	removeobject LOCALID_MERAL13
	return

TheColdMines_EventScript_SetupMeralcorePuzzle3::
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_19
	removeobject LOCALID_MERAL16
	removeobject LOCALID_MERAL17
	removeobject LOCALID_MERAL19
	return

TheColdMines_EventScript_ReplaceSouthSnow::
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
