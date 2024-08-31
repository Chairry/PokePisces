PerplumeMaze_MapScripts::
	.byte 0

PerplumeMaze_EventScript_Kris::
    trainerbattle_single TRAINER_P_KRIS, PerplumeMaze_Text_KrisIntro, PerplumeMaze_Text_KrisDefeated
    msgbox PerplumeMaze_Text_KrisPostBattle, MSGBOX_AUTOCLOSE
    end

PerplumeMaze_EventScript_Susie::
    trainerbattle_single TRAINER_P_SUSIE, PerplumeMaze_Text_SusieIntro, PerplumeMaze_Text_SusieDefeated
    msgbox PerplumeMaze_Text_SusiePostBattle, MSGBOX_AUTOCLOSE
    end

PerplumeMaze_EventScript_Ralsei::
    trainerbattle_single TRAINER_P_RALSEI, PerplumeMaze_Text_RalseiIntro, PerplumeMaze_Text_RalseiDefeated
    msgbox PerplumeMaze_Text_RalseiPostBattle, MSGBOX_AUTOCLOSE
    end

PerplumeMaze_Text_KrisIntro:
	.string "intro$"

PerplumeMaze_Text_KrisDefeated:
	.string "defeat$"

PerplumeMaze_Text_KrisPostBattle:
	.string "post$"

PerplumeMaze_Text_SusieIntro:
	.string "intro$"

PerplumeMaze_Text_SusieDefeated:
	.string "defeat$"

PerplumeMaze_Text_SusiePostBattle:
	.string "post$"

PerplumeMaze_Text_RalseiIntro:
	.string "intro$"

PerplumeMaze_Text_RalseiDefeated:
	.string "defeat$"

PerplumeMaze_Text_RalseiPostBattle:
	.string "post$"
