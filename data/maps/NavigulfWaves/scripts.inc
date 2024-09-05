NavigulfWaves_MapScripts::
	.byte 0

NavigulfWaves_EventScript_Chad::
    trainerbattle_single TRAINER_P_CHAD, NavigulfWaves_Text_ChadIntro, NavigulfWaves_Text_ChadDefeated
    msgbox NavigulfWaves_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfWaves_EventScript_Chaz::
    trainerbattle_single TRAINER_P_CHAZ, NavigulfWaves_Text_ChazIntro, NavigulfWaves_Text_ChazDefeated
    msgbox NavigulfWaves_Text_ChazPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfWaves_EventScript_Brody::
    trainerbattle_single TRAINER_P_BRODY, NavigulfWaves_Text_BrodyIntro, NavigulfWaves_Text_BrodyDefeated
    msgbox NavigulfWaves_Text_BrodyPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfWaves_EventScript_Dela::
    trainerbattle_single TRAINER_P_DELA, NavigulfWaves_Text_DelaIntro, NavigulfWaves_Text_DelaDefeated
    msgbox NavigulfWaves_Text_DelaPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfWaves_EventScript_Kiera::
    trainerbattle_single TRAINER_P_KIERA, NavigulfWaves_Text_KieraIntro, NavigulfWaves_Text_KieraDefeated
    msgbox NavigulfWaves_Text_KieraPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfWaves_EventScript_Libra::
    trainerbattle_single TRAINER_P_LIBRA, NavigulfWaves_Text_LibraIntro, NavigulfWaves_Text_LibraDefeated
    msgbox NavigulfWaves_Text_LibraPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfWaves_Text_ChadIntro:
	.string "intro$"

NavigulfWaves_Text_ChadDefeated:
	.string "defeat$"

NavigulfWaves_Text_ChadPostBattle:
	.string "post$"

NavigulfWaves_Text_ChazIntro:
	.string "intro$"

NavigulfWaves_Text_ChazDefeated:
	.string "defeat$"

NavigulfWaves_Text_ChazPostBattle:
	.string "post$"

NavigulfWaves_Text_BrodyIntro:
	.string "intro$"

NavigulfWaves_Text_BrodyDefeated:
	.string "defeat$"

NavigulfWaves_Text_BrodyPostBattle:
	.string "post$"

NavigulfWaves_Text_DelaIntro:
	.string "intro$"

NavigulfWaves_Text_DelaDefeated:
	.string "defeat$"

NavigulfWaves_Text_DelaPostBattle:
	.string "post$"

NavigulfWaves_Text_KieraIntro:
	.string "intro$"

NavigulfWaves_Text_KieraDefeated:
	.string "defeat$"

NavigulfWaves_Text_KieraPostBattle:
	.string "post$"

NavigulfWaves_Text_LibraIntro:
	.string "intro$"

NavigulfWaves_Text_LibraDefeated:
	.string "defeat$"

NavigulfWaves_Text_LibraPostBattle:
	.string "post$"
