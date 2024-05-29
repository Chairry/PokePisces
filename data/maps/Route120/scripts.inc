Route120_MapScripts::
	.byte 0

Route120_EventScript_Colby::
    trainerbattle_single TRAINER_P_COLBY, Route120_Text_ColbyIntro, Route120_Text_ColbyDefeated
    msgbox Route120_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_Text_ColbyIntro:
	.string "intro$"

Route120_Text_ColbyDefeated:
	.string "defeat$"

Route120_Text_ColbyPostBattle:
	.string "post$"
