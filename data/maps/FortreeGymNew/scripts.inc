FortreeGymNew_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeGymNew_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeGymNew_OnWarp
	.byte 0

FortreeGymNew_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeGymNew_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeGymNew_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeGymNew_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end
