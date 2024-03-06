.set LOCALID_NURSE, 1

LilycoveCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_2F_OnTransition:
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	end

LilycoveCity_PokemonCenter_2F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
