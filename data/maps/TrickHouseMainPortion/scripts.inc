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
