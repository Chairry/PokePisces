CrimneyClimb_MapScripts::
	.byte 0

CrimneyClimb_EventScript_Lara::
    trainerbattle_single TRAINER_P_LARA, CrimneyClimb_Text_LaraIntro, CrimneyClimb_Text_LaraDefeated
    msgbox CrimneyClimb_Text_LaraPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Erica::
    trainerbattle_single TRAINER_P_ERICA, CrimneyClimb_Text_EricaIntro, CrimneyClimb_Text_EricaDefeated
    msgbox CrimneyClimb_Text_EricaPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Jin::
    trainerbattle_single TRAINER_P_JIN, CrimneyClimb_Text_JinIntro, CrimneyClimb_Text_JinDefeated
    msgbox CrimneyClimb_Text_JinPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_AkiAndMitsu::
    trainerbattle_double TRAINER_P_AKI_AND_MITSU, CrimneyClimb_Text_AkiAndMitsuIntro, CrimneyClimb_Text_AkiAndMitsuDefeated, CrimneyClimb_Text_AkiAndMitsuNeedTwoMons
    msgbox CrimneyClimb_Text_AkiAndMitsuPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Daisy::
    trainerbattle_single TRAINER_P_DAISY, CrimneyClimb_Text_DaisyIntro, CrimneyClimb_Text_DaisyDefeated
    msgbox CrimneyClimb_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Gwunivere::
    trainerbattle_single TRAINER_P_GWUNIVERE, CrimneyClimb_Text_GwunivereIntro, CrimneyClimb_Text_GwunivereDefeated
    msgbox CrimneyClimb_Text_GwuniverePostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Yisan::
    trainerbattle_single TRAINER_P_YISAN, CrimneyClimb_Text_YisanIntro, CrimneyClimb_Text_YisanDefeated
    msgbox CrimneyClimb_Text_YisanPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Hamm::
    trainerbattle_single TRAINER_P_HAMM, CrimneyClimb_Text_HammIntro, CrimneyClimb_Text_HammDefeated
    msgbox CrimneyClimb_Text_HammPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Frank::
    trainerbattle_single TRAINER_P_FRANK, CrimneyClimb_Text_FrankIntro, CrimneyClimb_Text_FrankDefeated
    msgbox CrimneyClimb_Text_FrankPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Weiner::
    trainerbattle_single TRAINER_P_WEINER, CrimneyClimb_Text_WeinerIntro, CrimneyClimb_Text_WeinerDefeated
    msgbox CrimneyClimb_Text_WeinerPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Evelynn::
    trainerbattle_single TRAINER_P_EVELYNN, CrimneyClimb_Text_EvelynnIntro, CrimneyClimb_Text_EvelynnDefeated
    msgbox CrimneyClimb_Text_EvelynnPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Dyna::
    trainerbattle_single TRAINER_P_DYNA, CrimneyClimb_Text_DynaIntro, CrimneyClimb_Text_DynaDefeated
    msgbox CrimneyClimb_Text_DynaPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_Audrey::
    trainerbattle_single TRAINER_P_AUDREY, CrimneyClimb_Text_AudreyIntro, CrimneyClimb_Text_AudreyDefeated
    msgbox CrimneyClimb_Text_AudreyPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_EventScript_AudreyII::
    trainerbattle_single TRAINER_P_AUDREY_II, CrimneyClimb_Text_AudreyIIIntro, CrimneyClimb_Text_AudreyIIDefeated
    msgbox CrimneyClimb_Text_AudreyIIPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyClimb_Text_LaraIntro:
	.string "intro$"

CrimneyClimb_Text_LaraDefeated:
	.string "defeat$"

CrimneyClimb_Text_LaraPostBattle:
	.string "post$"

CrimneyClimb_Text_EricaIntro:
	.string "intro$"

CrimneyClimb_Text_EricaDefeated:
	.string "defeat$"

CrimneyClimb_Text_EricaPostBattle:
	.string "post$"

CrimneyClimb_Text_JinIntro:
	.string "intro$"

CrimneyClimb_Text_JinDefeated:
	.string "defeat$"

CrimneyClimb_Text_JinPostBattle:
	.string "post$"

CrimneyClimb_Text_AkiAndMitsuIntro:
	.string "intro$"

CrimneyClimb_Text_AkiAndMitsuDefeated:
	.string "defeat$"

CrimneyClimb_Text_AkiAndMitsuPostBattle:
	.string "post$"

CrimneyClimb_Text_AkiAndMitsuNeedTwoMons:
	.string "need 2 dood$"

CrimneyClimb_Text_DaisyIntro:
	.string "intro$"

CrimneyClimb_Text_DaisyDefeated:
	.string "defeat$"

CrimneyClimb_Text_DaisyPostBattle:
	.string "post$"

CrimneyClimb_Text_GwunivereIntro:
	.string "intro$"

CrimneyClimb_Text_GwunivereDefeated:
	.string "defeat$"

CrimneyClimb_Text_GwuniverePostBattle:
	.string "post$"

CrimneyClimb_Text_YisanIntro:
	.string "intro$"

CrimneyClimb_Text_YisanDefeated:
	.string "defeat$"

CrimneyClimb_Text_YisanPostBattle:
	.string "post$"

CrimneyClimb_Text_HammIntro:
	.string "intro$"

CrimneyClimb_Text_HammDefeated:
	.string "defeat$"

CrimneyClimb_Text_HammPostBattle:
	.string "post$"

CrimneyClimb_Text_FrankIntro:
	.string "intro$"

CrimneyClimb_Text_FrankDefeated:
	.string "defeat$"

CrimneyClimb_Text_FrankPostBattle:
	.string "post$"

CrimneyClimb_Text_WeinerIntro:
	.string "intro$"

CrimneyClimb_Text_WeinerDefeated:
	.string "defeat$"

CrimneyClimb_Text_WeinerPostBattle:
	.string "post$"

CrimneyClimb_Text_EvelynnIntro:
	.string "intro$"

CrimneyClimb_Text_EvelynnDefeated:
	.string "defeat$"

CrimneyClimb_Text_EvelynnPostBattle:
	.string "post$"

CrimneyClimb_Text_DynaIntro:
	.string "intro$"

CrimneyClimb_Text_DynaDefeated:
	.string "defeat$"

CrimneyClimb_Text_DynaPostBattle:
	.string "post$"

CrimneyClimb_Text_AudreyIntro:
	.string "intro$"

CrimneyClimb_Text_AudreyDefeated:
	.string "defeat$"

CrimneyClimb_Text_AudreyPostBattle:
	.string "post$"

CrimneyClimb_Text_AudreyIIIntro:
	.string "intro$"

CrimneyClimb_Text_AudreyIIDefeated:
	.string "defeat$"

CrimneyClimb_Text_AudreyIIPostBattle:
	.string "post$"
