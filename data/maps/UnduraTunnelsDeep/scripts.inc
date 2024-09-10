UnduraTunnelsDeep_MapScripts::
	.byte 0

UnduraTunnelsDeep_EventScript_Coheed::
    trainerbattle_single TRAINER_P_COHEED, UnduraTunnelsDeep_Text_CoheedIntro, UnduraTunnelsDeep_Text_CoheedDefeated
    msgbox UnduraTunnelsDeep_Text_CoheedPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnelsDeep_EventScript_Cambria::
    trainerbattle_single TRAINER_P_CAMBRIA, UnduraTunnelsDeep_Text_CambriaIntro, UnduraTunnelsDeep_Text_CambriaDefeated
    msgbox UnduraTunnelsDeep_Text_CambriaPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnelsDeep_EventScript_Serling::
    trainerbattle_single TRAINER_P_SERLING, UnduraTunnelsDeep_Text_SerlingIntro, UnduraTunnelsDeep_Text_SerlingDefeated
    msgbox UnduraTunnelsDeep_Text_SerlingPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnelsDeep_EventScript_Mariana::
    trainerbattle_single TRAINER_P_MARIANA, UnduraTunnelsDeep_Text_MarianaIntro, UnduraTunnelsDeep_Text_MarianaDefeated
    msgbox UnduraTunnelsDeep_Text_MarianaPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnelsDeep_EventScript_Coral::
    trainerbattle_single TRAINER_P_CORAL, UnduraTunnelsDeep_Text_CoralIntro, UnduraTunnelsDeep_Text_CoralDefeated
    msgbox UnduraTunnelsDeep_Text_CoralPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnelsDeep_EventScript_Gus::
    trainerbattle_single TRAINER_P_GUS, UnduraTunnelsDeep_Text_GusIntro, UnduraTunnelsDeep_Text_GusDefeated
    msgbox UnduraTunnelsDeep_Text_GusPostBattle, MSGBOX_AUTOCLOSE
    end

UnduraTunnelsDeep_Text_CoheedIntro:
	.string "intro$"

UnduraTunnelsDeep_Text_CoheedDefeated:
	.string "defeat$"

UnduraTunnelsDeep_Text_CoheedPostBattle:
	.string "post$"

UnduraTunnelsDeep_Text_CambriaIntro:
	.string "intro$"

UnduraTunnelsDeep_Text_CambriaDefeated:
	.string "defeat$"

UnduraTunnelsDeep_Text_CambriaPostBattle:
	.string "post$"

UnduraTunnelsDeep_Text_SerlingIntro:
	.string "intro$"

UnduraTunnelsDeep_Text_SerlingDefeated:
	.string "defeat$"

UnduraTunnelsDeep_Text_SerlingPostBattle:
	.string "post$"

UnduraTunnelsDeep_Text_MarianaIntro:
	.string "intro$"

UnduraTunnelsDeep_Text_MarianaDefeated:
	.string "defeat$"

UnduraTunnelsDeep_Text_MarianaPostBattle:
	.string "post$"

UnduraTunnelsDeep_Text_CoralIntro:
	.string "intro$"

UnduraTunnelsDeep_Text_CoralDefeated:
	.string "defeat$"

UnduraTunnelsDeep_Text_CoralPostBattle:
	.string "post$"

UnduraTunnelsDeep_Text_GusIntro:
	.string "intro$"

UnduraTunnelsDeep_Text_GusDefeated:
	.string "defeat$"

UnduraTunnelsDeep_Text_GusPostBattle:
	.string "post$"
