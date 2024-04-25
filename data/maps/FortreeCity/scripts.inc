FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end
