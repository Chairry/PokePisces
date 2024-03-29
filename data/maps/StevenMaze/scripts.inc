StevenMaze_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, StevenMaze_OnTransition
	.byte 0

StevenMaze_OnTransition:
	call StevenMaze_EventScript_SetFlashLevel
	end

StevenMaze_EventScript_SetFlashLevel::
	setflashlevel 6
	return

StevenMaze_EventScript_ShadowSteven1::
    trainerbattle_single TRAINER_P_S_STEVEN_1, StevenMaze_Text_Gugumbir, StevenMaze_Text_Gugumbir
    msgbox StevenMaze_Text_Gugumbir, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven2::
    trainerbattle_single TRAINER_P_S_STEVEN_2, StevenMaze_Text_Gugumbir, StevenMaze_Text_Gugumbir
    msgbox StevenMaze_Text_Gugumbir, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven3::
    trainerbattle_single TRAINER_P_S_STEVEN_3, StevenMaze_Text_Gugumbir, StevenMaze_Text_Gugumbir
    msgbox StevenMaze_Text_Gugumbir, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven4::
    trainerbattle_single TRAINER_P_S_STEVEN_4, StevenMaze_Text_Gugumbir, StevenMaze_Text_Gugumbir
    msgbox StevenMaze_Text_Gugumbir, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven5::
    trainerbattle_single TRAINER_P_S_STEVEN_5, StevenMaze_Text_Gugumbir, StevenMaze_Text_Gugumbir
    msgbox StevenMaze_Text_Gugumbir, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven6::
    trainerbattle_single TRAINER_P_S_STEVEN_6, StevenMaze_Text_Gugumbir, StevenMaze_Text_Gugumbir
    msgbox StevenMaze_Text_Gugumbir, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_FinalSteven::
	lock
	msgbox StevenMaze_Text_Gugumbir, MSGBOX_DEFAULT
	setvar VAR_NEW_COO_STATE, 4
	msgbox StevenMaze_Text_Gugumbir, MSGBOX_DEFAULT
	warp MAP_STEVEN_HOUSE, 8, 3
	waitstate
	release
	end

StevenMaze_Text_Gugumbir:
	.string "boo$"
