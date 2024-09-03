MauvilleNew_MapScripts::
	.byte 0

MauvilleNew_EventScript_Kurt::
    trainerbattle_single TRAINER_P_KURT, MauvilleNew_Text_KurtIntro, MauvilleNew_Text_KurtDefeated
    msgbox MauvilleNew_Text_KurtPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Kirst::
    trainerbattle_single TRAINER_P_KIRST, MauvilleNew_Text_KirstIntro, MauvilleNew_Text_KirstDefeated
    msgbox MauvilleNew_Text_KirstPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Maia::
    trainerbattle_single TRAINER_P_MAIA, MauvilleNew_Text_MaiaIntro, MauvilleNew_Text_MaiaDefeated
    msgbox MauvilleNew_Text_MaiaPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Miguel::
    trainerbattle_single TRAINER_P_MIGUEL, MauvilleNew_Text_MiguelIntro, MauvilleNew_Text_MiguelDefeated
    msgbox MauvilleNew_Text_MiguelPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_Text_KurtIntro:
	.string "intro$"

MauvilleNew_Text_KurtDefeated:
	.string "defeat$"

MauvilleNew_Text_KurtPostBattle:
	.string "post$"

MauvilleNew_Text_KirstIntro:
	.string "intro$"

MauvilleNew_Text_KirstDefeated:
	.string "defeat$"

MauvilleNew_Text_KirstPostBattle:
	.string "post$"

MauvilleNew_Text_MaiaIntro:
	.string "intro$"

MauvilleNew_Text_MaiaDefeated:
	.string "defeat$"

MauvilleNew_Text_MaiaPostBattle:
	.string "post$"

MauvilleNew_Text_MiguelIntro:
	.string "intro$"

MauvilleNew_Text_MiguelDefeated:
	.string "defeat$"

MauvilleNew_Text_MiguelPostBattle:
	.string "post$"
