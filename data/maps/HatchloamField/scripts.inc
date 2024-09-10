HatchloamField_MapScripts::
	.byte 0

HatchloamField_EventScript_Dustin::
    trainerbattle_single TRAINER_P_DUSTIN, HatchloamField_Text_DustinIntro, HatchloamField_Text_DustinDefeated
    msgbox HatchloamField_Text_DustinPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Hayley::
    trainerbattle_single TRAINER_P_HAYLEY, HatchloamField_Text_HayleyIntro, HatchloamField_Text_HayleyDefeated
    msgbox HatchloamField_Text_HayleyPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_EnaAndMina::
    trainerbattle_double TRAINER_P_ENA_AND_MINA, HatchloamField_Text_EnaAndMinaIntro, HatchloamField_Text_EnaAndMinaDefeated, HatchloamField_Text_EnaAndMinaNeedTwoMons
    msgbox HatchloamField_Text_EnaAndMinaPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Dill::
    trainerbattle_single TRAINER_P_DILL, HatchloamField_Text_DillIntro, HatchloamField_Text_DillDefeated
    msgbox HatchloamField_Text_DillPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Delilah::
    trainerbattle_single TRAINER_P_DELILAH, HatchloamField_Text_DelilahIntro, HatchloamField_Text_DelilahDefeated
    msgbox HatchloamField_Text_DelilahPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_JiyuAndShirou::
    trainerbattle_double TRAINER_P_JIYU_AND_SHIROU, HatchloamField_Text_JiyuAndShirouIntro, HatchloamField_Text_JiyuAndShirouDefeated, HatchloamField_Text_JiyuAndShirouNeedTwoMons
    msgbox HatchloamField_Text_JiyuAndShirouPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_Samuel::
    trainerbattle_single TRAINER_P_SAMUEL, HatchloamField_Text_SamuelIntro, HatchloamField_Text_SamuelDefeated
    msgbox HatchloamField_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_YerbaAndBuena::
    trainerbattle_double TRAINER_P_YERBA_AND_BUENA, HatchloamField_Text_YerbaAndBuenaIntro, HatchloamField_Text_YerbaAndBuenaDefeated, HatchloamField_Text_YerbaAndBuenaNeedTwoMons
    msgbox HatchloamField_Text_YerbaAndBuenaPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_EventScript_LexAndTrish::
    trainerbattle_double TRAINER_P_LEX_AND_TRISH, HatchloamField_Text_LexAndTrishIntro, HatchloamField_Text_LexAndTrishDefeated, HatchloamField_Text_LexAndTrishNeedTwoMons
    msgbox HatchloamField_Text_LexAndTrishPostBattle, MSGBOX_AUTOCLOSE
    end

HatchloamField_Text_DustinIntro:
	.string "intro$"

HatchloamField_Text_DustinDefeated:
	.string "defeat$"

HatchloamField_Text_DustinPostBattle:
	.string "post$"

HatchloamField_Text_HayleyIntro:
	.string "intro$"

HatchloamField_Text_HayleyDefeated:
	.string "defeat$"

HatchloamField_Text_HayleyPostBattle:
	.string "post$"

HatchloamField_Text_EnaAndMinaIntro:
	.string "intro$"

HatchloamField_Text_EnaAndMinaDefeated:
	.string "defeat$"

HatchloamField_Text_EnaAndMinaPostBattle:
	.string "post$"

HatchloamField_Text_EnaAndMinaNeedTwoMons:
	.string "need 2 dood$"

HatchloamField_Text_DillIntro:
	.string "intro$"

HatchloamField_Text_DillDefeated:
	.string "defeat$"

HatchloamField_Text_DillPostBattle:
	.string "post$"

HatchloamField_Text_DelilahIntro:
	.string "intro$"

HatchloamField_Text_DelilahDefeated:
	.string "defeat$"

HatchloamField_Text_DelilahPostBattle:
	.string "post$"

HatchloamField_Text_JiyuAndShirouIntro:
	.string "intro$"

HatchloamField_Text_JiyuAndShirouDefeated:
	.string "defeat$"

HatchloamField_Text_JiyuAndShirouPostBattle:
	.string "post$"

HatchloamField_Text_JiyuAndShirouNeedTwoMons:
	.string "need 2 dood$"

HatchloamField_Text_SamuelIntro:
	.string "intro$"

HatchloamField_Text_SamuelDefeated:
	.string "defeat$"

HatchloamField_Text_SamuelPostBattle:
	.string "post$"

HatchloamField_Text_YerbaAndBuenaIntro:
	.string "intro$"

HatchloamField_Text_YerbaAndBuenaDefeated:
	.string "defeat$"

HatchloamField_Text_YerbaAndBuenaPostBattle:
	.string "post$"

HatchloamField_Text_YerbaAndBuenaNeedTwoMons:
	.string "need 2 dood$"

HatchloamField_Text_LexAndTrishIntro:
	.string "intro$"

HatchloamField_Text_LexAndTrishDefeated:
	.string "defeat$"

HatchloamField_Text_LexAndTrishPostBattle:
	.string "post$"

HatchloamField_Text_LexAndTrishNeedTwoMons:
	.string "need 2 dood$"
