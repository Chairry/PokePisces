DetermaniteBeach_MapScripts::
	.byte 0

DetermaniteBeach_EventScript_Mimi::
    trainerbattle_single TRAINER_P_MIMI, DetermaniteBeach_Text_MimiIntro, DetermaniteBeach_Text_MimiDefeated
    msgbox DetermaniteBeach_Text_MimiPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Seamus::
    trainerbattle_single TRAINER_P_SEAMUS, DetermaniteBeach_Text_SeamusIntro, DetermaniteBeach_Text_SeamusDefeated
    msgbox DetermaniteBeach_Text_SeamusPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Laura::
    trainerbattle_single TRAINER_P_LAURA, DetermaniteBeach_Text_LauraIntro, DetermaniteBeach_Text_LauraDefeated
    msgbox DetermaniteBeach_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Laharl::
    trainerbattle_single TRAINER_P_LAHARL, DetermaniteBeach_Text_LaharlIntro, DetermaniteBeach_Text_LaharlDefeated
    msgbox DetermaniteBeach_Text_LaharlPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Etna::
    trainerbattle_single TRAINER_P_ETNA, DetermaniteBeach_Text_EtnaIntro, DetermaniteBeach_Text_EtnaDefeated
    msgbox DetermaniteBeach_Text_EtnaPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Flonne::
    trainerbattle_single TRAINER_P_FLONNE, DetermaniteBeach_Text_FlonneIntro, DetermaniteBeach_Text_FlonneDefeated
    msgbox DetermaniteBeach_Text_FlonnePostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Yasuke::
    trainerbattle_single TRAINER_P_YASUKE, DetermaniteBeach_Text_YasukeIntro, DetermaniteBeach_Text_YasukeDefeated
    msgbox DetermaniteBeach_Text_YasukePostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Gatherer::
    trainerbattle_single TRAINER_P_GATHERER, DetermaniteBeach_Text_GathererIntro, DetermaniteBeach_Text_GathererDefeated
    msgbox DetermaniteBeach_Text_GathererPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Yue::
    trainerbattle_single TRAINER_P_YUE, DetermaniteBeach_Text_YueIntro, DetermaniteBeach_Text_YueDefeated
    msgbox DetermaniteBeach_Text_YuePostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_Prince::
    trainerbattle_single TRAINER_P_PRINCE, DetermaniteBeach_Text_PrinceIntro, DetermaniteBeach_Text_PrinceDefeated
    msgbox DetermaniteBeach_Text_PrincePostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_King::
    trainerbattle_single TRAINER_P_KING, DetermaniteBeach_Text_KingIntro, DetermaniteBeach_Text_KingDefeated
    msgbox DetermaniteBeach_Text_KingPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_EventScript_SaiAndMisha::
    trainerbattle_double TRAINER_P_SAI_AND_MISHA, DetermaniteBeach_Text_SaiAndMishaIntro, DetermaniteBeach_Text_SaiAndMishaDefeated, DetermaniteBeach_Text_SaiAndMishaNeedTwoMons
    msgbox DetermaniteBeach_Text_SaiAndMishaPostBattle, MSGBOX_AUTOCLOSE
    end

DetermaniteBeach_Text_MimiIntro:
	.string "intro$"

DetermaniteBeach_Text_MimiDefeated:
	.string "defeat$"

DetermaniteBeach_Text_MimiPostBattle:
	.string "post$"

DetermaniteBeach_Text_SeamusIntro:
	.string "intro$"

DetermaniteBeach_Text_SeamusDefeated:
	.string "defeat$"

DetermaniteBeach_Text_SeamusPostBattle:
	.string "post$"

DetermaniteBeach_Text_LauraIntro:
	.string "intro$"

DetermaniteBeach_Text_LauraDefeated:
	.string "defeat$"

DetermaniteBeach_Text_LauraPostBattle:
	.string "post$"

DetermaniteBeach_Text_LaharlIntro:
	.string "intro$"

DetermaniteBeach_Text_LaharlDefeated:
	.string "defeat$"

DetermaniteBeach_Text_LaharlPostBattle:
	.string "post$"

DetermaniteBeach_Text_EtnaIntro:
	.string "intro$"

DetermaniteBeach_Text_EtnaDefeated:
	.string "defeat$"

DetermaniteBeach_Text_EtnaPostBattle:
	.string "post$"

DetermaniteBeach_Text_FlonneIntro:
	.string "intro$"

DetermaniteBeach_Text_FlonneDefeated:
	.string "defeat$"

DetermaniteBeach_Text_FlonnePostBattle:
	.string "post$"

DetermaniteBeach_Text_YasukeIntro:
	.string "intro$"

DetermaniteBeach_Text_YasukeDefeated:
	.string "defeat$"

DetermaniteBeach_Text_YasukePostBattle:
	.string "post$"

DetermaniteBeach_Text_GathererIntro:
	.string "intro$"

DetermaniteBeach_Text_GathererDefeated:
	.string "defeat$"

DetermaniteBeach_Text_GathererPostBattle:
	.string "post$"

DetermaniteBeach_Text_YueIntro:
	.string "intro$"

DetermaniteBeach_Text_YueDefeated:
	.string "defeat$"

DetermaniteBeach_Text_YuePostBattle:
	.string "post$"

DetermaniteBeach_Text_PrinceIntro:
	.string "intro$"

DetermaniteBeach_Text_PrinceDefeated:
	.string "defeat$"

DetermaniteBeach_Text_PrincePostBattle:
	.string "post$"

DetermaniteBeach_Text_KingIntro:
	.string "intro$"

DetermaniteBeach_Text_KingDefeated:
	.string "defeat$"

DetermaniteBeach_Text_KingPostBattle:
	.string "post$"

DetermaniteBeach_Text_SaiAndMishaIntro:
	.string "intro$"

DetermaniteBeach_Text_SaiAndMishaDefeated:
	.string "defeat$"

DetermaniteBeach_Text_SaiAndMishaPostBattle:
	.string "post$"

DetermaniteBeach_Text_SaiAndMishaNeedTwoMons:
	.string "need 2 dood$"
