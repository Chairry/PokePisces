.set LOCALID_P_MAN, 8
.set LOCALID_BARD, 4
.set LOCALID_BRINEY, 7
.set LOCALID_BRINEY2, 2
.set LOCALID_DRAKE, 5
.set LOCALID_ARCHIE, 3
.set LOCALID_STERN, 6

SouthernIsland_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SouthernIsland_OnLoad
	.byte 0

SouthernIsland_OnLoad:
	call_if_eq VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_RemoveBriney2
	call_if_eq VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_SetBardGfx
	call_if_lt VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_RemoveSeafarers
	call_if_gt VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_RemoveSeafarers
	end

SouthernIsland_EventScript_SetBardGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_BARD
	special SetMauvilleOldManObjEventGfx
	end

SouthernIsland_EventScript_RemoveSeafarers::
	removeobject LOCALID_ARCHIE
	setflag FLAG_TEMP_14
	removeobject LOCALID_STERN
	setflag FLAG_TEMP_15
	removeobject LOCALID_DRAKE
	setflag FLAG_TEMP_16
	removeobject LOCALID_BARD
	setflag FLAG_TEMP_17
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	removeobject LOCALID_BRINEY
	setflag FLAG_TEMP_12
	return

SouthernIsland_EventScript_RemoveBriney2::
	removeobject LOCALID_BRINEY2
	setflag FLAG_TEMP_13
	return
