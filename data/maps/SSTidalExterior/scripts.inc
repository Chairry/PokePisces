SSTidalExterior_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalExterior_OnFrame
	.byte 0

SSTidalExterior_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, SSTidalExterior_EventScript_AllowedToLeave
	.2byte 0

SSTidalExterior_EventScript_AllowedToLeave::
	lockall
	playse SE_SUCCESS
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setflag FLAG_HIDE_SSTIDAL_SAILOR
	msgbox SSTidalExterior_Text_AllowedToLeave, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SSTidalExterior_Text_AllowedToLeave:
	.string "you can leave now$"
