BirchMaritimeLab_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BirchMaritimeLab_OnResume
	.byte 0

BirchMaritimeLab_OnResume:
	setdivewarp MAP_LAB_BASEMENT, 9, 8
	end
