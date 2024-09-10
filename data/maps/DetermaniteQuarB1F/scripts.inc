DetermaniteQuarB1F_MapScripts::
	.byte 0

DetermaniteQuarB1F_EventScript_Jiggles::
    trainerbattle_single TRAINER_P_JIGGLES, DetermaniteQuarB1F_Text_JigglesIntro, DetermaniteQuarB1F_Text_JigglesDefeated
    msgbox DetermaniteQuarB1F_Text_JigglesPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteQuarB1F_EventScript_Dahlia::
    trainerbattle_single TRAINER_P_DAHLIA, DetermaniteQuarB1F_Text_DahliaIntro, DetermaniteQuarB1F_Text_DahliaDefeated
    msgbox DetermaniteQuarB1F_Text_DahliaPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteQuarB1F_EventScript_June::
    trainerbattle_single TRAINER_P_JUNE, DetermaniteQuarB1F_Text_JuneIntro, DetermaniteQuarB1F_Text_JuneDefeated
    msgbox DetermaniteQuarB1F_Text_JunePostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteQuarB1F_EventScript_August::
    trainerbattle_single TRAINER_P_AUGUST, DetermaniteQuarB1F_Text_AugustIntro, DetermaniteQuarB1F_Text_AugustDefeated
    msgbox DetermaniteQuarB1F_Text_AugustPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteQuarB1F_EventScript_Mildred::
    trainerbattle_single TRAINER_P_MILDRED, DetermaniteQuarB1F_Text_MildredIntro, DetermaniteQuarB1F_Text_MildredDefeated
    msgbox DetermaniteQuarB1F_Text_MildredPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteQuarB1F_EventScript_Grey::
    trainerbattle_single TRAINER_P_GREY, DetermaniteQuarB1F_Text_GreyIntro, DetermaniteQuarB1F_Text_GreyDefeated
    msgbox DetermaniteQuarB1F_Text_GreyPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteQuarB1F_Text_JigglesIntro:
	.string "intro$"

DetermaniteQuarB1F_Text_JigglesDefeated:
	.string "defeat$"

DetermaniteQuarB1F_Text_JigglesPostBattle:
	.string "post$"

DetermaniteQuarB1F_Text_DahliaIntro:
	.string "intro$"

DetermaniteQuarB1F_Text_DahliaDefeated:
	.string "defeat$"

DetermaniteQuarB1F_Text_DahliaPostBattle:
	.string "post$"

DetermaniteQuarB1F_Text_JuneIntro:
	.string "intro$"

DetermaniteQuarB1F_Text_JuneDefeated:
	.string "defeat$"

DetermaniteQuarB1F_Text_JunePostBattle:
	.string "post$"

DetermaniteQuarB1F_Text_AugustIntro:
	.string "intro$"

DetermaniteQuarB1F_Text_AugustDefeated:
	.string "defeat$"

DetermaniteQuarB1F_Text_AugustPostBattle:
	.string "post$"

DetermaniteQuarB1F_Text_MildredIntro:
	.string "intro$"

DetermaniteQuarB1F_Text_MildredDefeated:
	.string "defeat$"

DetermaniteQuarB1F_Text_MildredPostBattle:
	.string "post$"

DetermaniteQuarB1F_Text_GreyIntro:
	.string "intro$"

DetermaniteQuarB1F_Text_GreyDefeated:
	.string "defeat$"

DetermaniteQuarB1F_Text_GreyPostBattle:
	.string "post$"
