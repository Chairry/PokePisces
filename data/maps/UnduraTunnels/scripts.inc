UnduraTunnels_MapScripts::
	.byte 0

UnduraTunnels_EventScript_Guntilda::
    trainerbattle_single TRAINER_P_GUNTILDA, UnduraTunnels_Text_GuntildaIntro, UnduraTunnels_Text_GuntildaDefeated
    msgbox UnduraTunnels_Text_GuntildaPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnels_EventScript_Laios::
    trainerbattle_single TRAINER_P_LAIOS, UnduraTunnels_Text_LaiosIntro, UnduraTunnels_Text_LaiosDefeated
    msgbox UnduraTunnels_Text_LaiosPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnels_EventScript_Gio::
    trainerbattle_single TRAINER_P_GIO, UnduraTunnels_Text_GioIntro, UnduraTunnels_Text_GioDefeated
    msgbox UnduraTunnels_Text_GioPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnels_EventScript_Eunmi::
    trainerbattle_single TRAINER_P_EUNMI, UnduraTunnels_Text_EunmiIntro, UnduraTunnels_Text_EunmiDefeated
    msgbox UnduraTunnels_Text_EunmiPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnels_EventScript_Thyme::
    trainerbattle_single TRAINER_P_THYME, UnduraTunnels_Text_ThymeIntro, UnduraTunnels_Text_ThymeDefeated
    msgbox UnduraTunnels_Text_ThymePostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnels_EventScript_Basil::
    trainerbattle_single TRAINER_P_BASIL, UnduraTunnels_Text_BasilIntro, UnduraTunnels_Text_BasilDefeated
    msgbox UnduraTunnels_Text_BasilPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnels_Text_GuntildaIntro:
	.string "intro$"

UnduraTunnels_Text_GuntildaDefeated:
	.string "defeat$"

UnduraTunnels_Text_GuntildaPostBattle:
	.string "post$"

UnduraTunnels_Text_LaiosIntro:
	.string "intro$"

UnduraTunnels_Text_LaiosDefeated:
	.string "defeat$"

UnduraTunnels_Text_LaiosPostBattle:
	.string "post$"

UnduraTunnels_Text_GioIntro:
	.string "intro$"

UnduraTunnels_Text_GioDefeated:
	.string "defeat$"

UnduraTunnels_Text_GioPostBattle:
	.string "post$"

UnduraTunnels_Text_EunmiIntro:
	.string "intro$"

UnduraTunnels_Text_EunmiDefeated:
	.string "defeat$"

UnduraTunnels_Text_EunmiPostBattle:
	.string "post$"

UnduraTunnels_Text_ThymeIntro:
	.string "intro$"

UnduraTunnels_Text_ThymeDefeated:
	.string "defeat$"

UnduraTunnels_Text_ThymePostBattle:
	.string "post$"

UnduraTunnels_Text_BasilIntro:
	.string "intro$"

UnduraTunnels_Text_BasilDefeated:
	.string "defeat$"

UnduraTunnels_Text_BasilPostBattle:
	.string "post$"
