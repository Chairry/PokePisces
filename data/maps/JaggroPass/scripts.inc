JaggroPass_MapScripts::
	.byte 0

JaggroPass_EventScript_Emmy::
    trainerbattle_single TRAINER_P_EMMY, JaggroPass_Text_EmmyIntro, JaggroPass_Text_EmmyDefeated
    msgbox JaggroPass_Text_EmmyPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Dayton::
    trainerbattle_single TRAINER_P_DAYTON, JaggroPass_Text_DaytonIntro, JaggroPass_Text_DaytonDefeated
    msgbox JaggroPass_Text_DaytonPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Anto::
    trainerbattle_single TRAINER_P_ANTO, JaggroPass_Text_AntoIntro, JaggroPass_Text_AntoDefeated
    msgbox JaggroPass_Text_AntoPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Baze::
    trainerbattle_single TRAINER_P_BAZE, JaggroPass_Text_BazeIntro, JaggroPass_Text_BazeDefeated
    msgbox JaggroPass_Text_BazePostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Chinzao::
    trainerbattle_single TRAINER_P_CHINZAO, JaggroPass_Text_ChinzaoIntro, JaggroPass_Text_ChinzaoDefeated
    msgbox JaggroPass_Text_ChinzaoPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Marimar::
    trainerbattle_single TRAINER_P_MARIMAR, JaggroPass_Text_MarimarIntro, JaggroPass_Text_MarimarDefeated
    msgbox JaggroPass_Text_MarimarPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_EventScript_Jelly::
    trainerbattle_single TRAINER_P_JELLY, JaggroPass_Text_JellyIntro, JaggroPass_Text_JellyDefeated
    msgbox JaggroPass_Text_JellyPostBattle, MSGBOX_AUTOCLOSE
    end

JaggroPass_Text_EmmyIntro:
	.string "intro$"

JaggroPass_Text_EmmyDefeated:
	.string "defeat$"

JaggroPass_Text_EmmyPostBattle:
	.string "post$"

JaggroPass_Text_DaytonIntro:
	.string "intro$"

JaggroPass_Text_DaytonDefeated:
	.string "defeat$"

JaggroPass_Text_DaytonPostBattle:
	.string "post$"

JaggroPass_Text_AntoIntro:
	.string "intro$"

JaggroPass_Text_AntoDefeated:
	.string "defeat$"

JaggroPass_Text_AntoPostBattle:
	.string "post$"

JaggroPass_Text_BazeIntro:
	.string "intro$"

JaggroPass_Text_BazeDefeated:
	.string "defeat$"

JaggroPass_Text_BazePostBattle:
	.string "post$"

JaggroPass_Text_ChinzaoIntro:
	.string "intro$"

JaggroPass_Text_ChinzaoDefeated:
	.string "defeat$"

JaggroPass_Text_ChinzaoPostBattle:
	.string "post$"

JaggroPass_Text_MarimarIntro:
	.string "intro$"

JaggroPass_Text_MarimarDefeated:
	.string "defeat$"

JaggroPass_Text_MarimarPostBattle:
	.string "post$"

JaggroPass_Text_JellyIntro:
	.string "intro$"

JaggroPass_Text_JellyDefeated:
	.string "defeat$"

JaggroPass_Text_JellyPostBattle:
	.string "post$"
