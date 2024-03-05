SSTidalInteriors_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalInteriors_OnFrame
	.byte 0

SSTidalInteriors_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, SSTidalInteriors_EventScript_AllowedToLeave
	.2byte 0

SSTidalInteriors_EventScript_AllowedToLeave::
	lockall
	playse SE_SUCCESS
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setflag FLAG_HIDE_SSTIDAL_SAILOR
	msgbox SSTidalInteriors_Text_AllowedToLeave, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SSTidalInteriors_EventScript_Drake::
	lock
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_DrakeLeave
	setflag FLAG_PISCES_A
	msgbox SSTidalInteriors_Text_Drake, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_DrakeLeave::
	msgbox SSTidalInteriors_Text_DrakeLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_GymChallenger::
	lock
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_GymChallengerLeave
	setflag FLAG_PISCES_B
	msgbox SSTidalInteriors_Text_GymChallenger, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_GymChallengerLeave::
	msgbox SSTidalInteriors_Text_GymChallengerLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_DevonEmployee::
	lock
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_DevonEmployeeLeave
	setflag FLAG_PISCES_C
	msgbox SSTidalInteriors_Text_DevonEmployee, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_DevonEmployeeLeave::
	msgbox SSTidalInteriors_Text_DevonEmployeeLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_TeamAquaMale::
	lock
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_TAMLeave
	setflag FLAG_PISCES_D
	msgbox SSTidalInteriors_Text_TeamAquaMale, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_TAMLeave::
	msgbox SSTidalInteriors_Text_TAMLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_TeamAquaFemale::
	lock
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_TAFLeave
	setflag FLAG_PISCES_D
	msgbox SSTidalInteriors_Text_TeamAquaFemale, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_TAFLeave::
	msgbox SSTidalInteriors_Text_TAFLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_CheckFlags1::
	call_if_set FLAG_PISCES_B, SSTidalInteriors_EventScript_CheckFlags2
	return

SSTidalInteriors_EventScript_CheckFlags2::
	call_if_set FLAG_PISCES_C, SSTidalInteriors_EventScript_CheckFlags3
	return

SSTidalInteriors_EventScript_CheckFlags3::
	call_if_set FLAG_PISCES_D, SSTidalInteriors_EventScript_CheckFlags4
	return

SSTidalInteriors_EventScript_CheckFlags4::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	return

SSTidalInteriors_Text_AllowedToLeave:
	.string "you can leave now$"

SSTidalInteriors_Text_Drake:
	.string "drake test$"

SSTidalInteriors_Text_DrakeLeave:
	.string "drake GETOUT$"

SSTidalInteriors_Text_GymChallenger:
	.string "gym test$"

SSTidalInteriors_Text_GymChallengerLeave:
	.string "gym getout$"

SSTidalInteriors_Text_DevonEmployee:
	.string "devon test$"

SSTidalInteriors_Text_DevonEmployeeLeave:
	.string "devon getout$"

SSTidalInteriors_Text_TeamAquaMale:
	.string "tam test$"

SSTidalInteriors_Text_TAMLeave:
	.string "tam getout$"

SSTidalInteriors_Text_TeamAquaFemale:
	.string "taf test$"

SSTidalInteriors_Text_TAFLeave:
	.string "taf getout$"
