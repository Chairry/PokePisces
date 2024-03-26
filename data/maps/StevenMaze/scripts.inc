StevenMaze_MapScripts::
	.byte 0

StevenMaze_EventScript_ShadowSteven::
    trainerbattle_single TRAINER_BERKE, StevenMaze_Text_Gugumbir, StevenMaze_Text_Gugumbir
    msgbox StevenMaze_Text_Gugumbir, MSGBOX_AUTOCLOSE
    end

StevenMaze_Text_Gugumbir:
	.string "boo$"
