ShoalCaveNewFloor2_MapScripts::
	.byte 0

ShoalCaveNewFloor2_EventScript_Magnus::
    trainerbattle_single TRAINER_P_MAGNUS, ShoalCaveNewFloor2_Text_MagnusIntro, ShoalCaveNewFloor2_Text_MagnusDefeated
    msgbox ShoalCaveNewFloor2_Text_MagnusPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor2_EventScript_Juneau::
    trainerbattle_single TRAINER_P_JUNEAU, ShoalCaveNewFloor2_Text_JuneauIntro, ShoalCaveNewFloor2_Text_JuneauDefeated
    msgbox ShoalCaveNewFloor2_Text_JuneauPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor2_EventScript_Alaska::
    trainerbattle_single TRAINER_P_ALASKA, ShoalCaveNewFloor2_Text_AlaskaIntro, ShoalCaveNewFloor2_Text_AlaskaDefeated
    msgbox ShoalCaveNewFloor2_Text_AlaskaPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor2_Text_MagnusIntro:
	.string "intro$"

ShoalCaveNewFloor2_Text_MagnusDefeated:
	.string "defeat$"

ShoalCaveNewFloor2_Text_MagnusPostBattle:
	.string "post$"

ShoalCaveNewFloor2_Text_JuneauIntro:
	.string "intro$"

ShoalCaveNewFloor2_Text_JuneauDefeated:
	.string "defeat$"

ShoalCaveNewFloor2_Text_JuneauPostBattle:
	.string "post$"

ShoalCaveNewFloor2_Text_AlaskaIntro:
	.string "intro$"

ShoalCaveNewFloor2_Text_AlaskaDefeated:
	.string "defeat$"

ShoalCaveNewFloor2_Text_AlaskaPostBattle:
	.string "post$"
