.set LOCALID_TUBER1, 7
.set LOCALID_TUBER2, 9
.set LOCALID_TUBER3, 10
.set LOCALID_TUBER4, 13
.set LOCALID_POMELONIAN, 8
.set LOCALID_VICTIM1, 6
.set LOCALID_VICTIM2, 11
.set LOCALID_VICTIM3, 12
.set LOCALID_PARASOL1, 19
.set LOCALID_PARASOL2, 20
.set LOCALID_PARASOL3, 21
.set LOCALID_PARASOL4, 22
.set LOCALID_PARASOL5, 23
.set LOCALID_PARASOL6, 24

NewSunbeach_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewSunbeach_OnTransition
	.byte 0

NewSunbeach_OnTransition:
	call_if_set FLAG_SUNBEACH_TUBER_1, NewSunbeach_EventScript_SetTuberTempFlags1
	call_if_set FLAG_SUNBEACH_TUBER_2, NewSunbeach_EventScript_SetTuberTempFlags2
	call_if_set FLAG_SUNBEACH_TUBER_3, NewSunbeach_EventScript_SetTuberTempFlags3
	call_if_gt VAR_PARASOL_QUEST_STATE, 1, NewSunbeach_EventScript_SetParasolTempVar
	end

NewSunbeach_EventScript_SetTuberTempFlags1::
	setvar VAR_TEMP_5, 2
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	return

NewSunbeach_EventScript_SetTuberTempFlags2::
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	return

NewSunbeach_EventScript_SetTuberTempFlags3::
	setvar VAR_TEMP_6, 2
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	return

NewSunbeach_EventScript_SetParasolTempVar::
	setvar VAR_TEMP_4, 2
	return
