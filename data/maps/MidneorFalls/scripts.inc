MidneorFalls_MapScripts::
	.byte 0

MidneorFalls_EventScript_Catt::
    trainerbattle_single TRAINER_P_CATT, MidneorFalls_Text_CattIntro, MidneorFalls_Text_CattDefeated
    msgbox MidneorFalls_Text_CattPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Taii::
    trainerbattle_single TRAINER_P_TAII, MidneorFalls_Text_TaiiIntro, MidneorFalls_Text_TaiiDefeated
    msgbox MidneorFalls_Text_TaiiPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_ErkinAndKaya::
    trainerbattle_double TRAINER_P_ERKIN_AND_KAYA, MidneorFalls_Text_ErkinAndKayaIntro, MidneorFalls_Text_ErkinAndKayaDefeated, MidneorFalls_Text_ErkinAndKayaNeedTwoMons
    msgbox MidneorFalls_Text_ErkinAndKayaPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Griselda::
    trainerbattle_single TRAINER_P_GRISELDA, MidneorFalls_Text_GriseldaIntro, MidneorFalls_Text_GriseldaDefeated
    msgbox MidneorFalls_Text_GriseldaPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Morgana::
    trainerbattle_single TRAINER_P_MORGANA, MidneorFalls_Text_MorganaIntro, MidneorFalls_Text_MorganaDefeated
    msgbox MidneorFalls_Text_MorganaPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Zephyr::
    trainerbattle_single TRAINER_P_ZEPHYR, MidneorFalls_Text_ZephyrIntro, MidneorFalls_Text_ZephyrDefeated
    msgbox MidneorFalls_Text_ZephyrPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Anthreeny::
    trainerbattle_single TRAINER_P_ANTHREENY, MidneorFalls_Text_AnthreenyIntro, MidneorFalls_Text_AnthreenyDefeated
    msgbox MidneorFalls_Text_AnthreenyPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Schuli::
    trainerbattle_single TRAINER_P_SCHULI, MidneorFalls_Text_SchuliIntro, MidneorFalls_Text_SchuliDefeated
    msgbox MidneorFalls_Text_SchuliPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Gerier::
    trainerbattle_single TRAINER_P_GERIER, MidneorFalls_Text_GerierIntro, MidneorFalls_Text_GerierDefeated
    msgbox MidneorFalls_Text_GerierPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_EventScript_Gonzeros::
    trainerbattle_single TRAINER_P_GONZEROS, MidneorFalls_Text_GonzerosIntro, MidneorFalls_Text_GonzerosDefeated
    msgbox MidneorFalls_Text_GonzerosPostBattle, MSGBOX_AUTOCLOSE
    end

MidneorFalls_Text_CattIntro:
	.string "intro$"

MidneorFalls_Text_CattDefeated:
	.string "defeat$"

MidneorFalls_Text_CattPostBattle:
	.string "post$"

MidneorFalls_Text_TaiiIntro:
	.string "intro$"

MidneorFalls_Text_TaiiDefeated:
	.string "defeat$"

MidneorFalls_Text_TaiiPostBattle:
	.string "post$"

MidneorFalls_Text_ErkinAndKayaIntro:
	.string "intro$"

MidneorFalls_Text_ErkinAndKayaDefeated:
	.string "defeat$"

MidneorFalls_Text_ErkinAndKayaPostBattle:
	.string "post$"

MidneorFalls_Text_ErkinAndKayaNeedTwoMons:
	.string "need 2 dood$"

MidneorFalls_Text_GriseldaIntro:
	.string "intro$"

MidneorFalls_Text_GriseldaDefeated:
	.string "defeat$"

MidneorFalls_Text_GriseldaPostBattle:
	.string "post$"

MidneorFalls_Text_MorganaIntro:
	.string "intro$"

MidneorFalls_Text_MorganaDefeated:
	.string "defeat$"

MidneorFalls_Text_MorganaPostBattle:
	.string "post$"

MidneorFalls_Text_ZephyrIntro:
	.string "intro$"

MidneorFalls_Text_ZephyrDefeated:
	.string "defeat$"

MidneorFalls_Text_ZephyrPostBattle:
	.string "post$"

MidneorFalls_Text_AnthreenyIntro:
	.string "intro$"

MidneorFalls_Text_AnthreenyDefeated:
	.string "defeat$"

MidneorFalls_Text_AnthreenyPostBattle:
	.string "post$"

MidneorFalls_Text_SchuliIntro:
	.string "intro$"

MidneorFalls_Text_SchuliDefeated:
	.string "defeat$"

MidneorFalls_Text_SchuliPostBattle:
	.string "post$"

MidneorFalls_Text_GerierIntro:
	.string "intro$"

MidneorFalls_Text_GerierDefeated:
	.string "defeat$"

MidneorFalls_Text_GerierPostBattle:
	.string "post$"

MidneorFalls_Text_GonzerosIntro:
	.string "intro$"

MidneorFalls_Text_GonzerosDefeated:
	.string "defeat$"

MidneorFalls_Text_GonzerosPostBattle:
	.string "post$"
