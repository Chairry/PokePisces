MasoriedHike_MapScripts::
	.byte 0

MasonriedHike_EventScript_Michael::
    trainerbattle_single TRAINER_P_MICHAEL, MasonriedHike_Text_MichaelIntro, MasonriedHike_Text_MichaelDefeated
    msgbox MasonriedHike_Text_MichaelPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_Chloe::
    trainerbattle_single TRAINER_P_CHLOE, MasonriedHike_Text_ChloeIntro, MasonriedHike_Text_ChloeDefeated
    msgbox MasonriedHike_Text_ChloePostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_Bichael::
    trainerbattle_single TRAINER_P_BICHAEL, MasonriedHike_Text_BichaelIntro, MasonriedHike_Text_BichaelDefeated
    msgbox MasonriedHike_Text_BichaelPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_Flowers::
    trainerbattle_single TRAINER_P_FLOWERS, MasonriedHike_Text_FlowersIntro, MasonriedHike_Text_FlowersDefeated
    msgbox MasonriedHike_Text_FlowersPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_EventScript_JayAndEm::
    trainerbattle_double TRAINER_P_JAY_AND_EM, MasonriedHike_Text_JayAndEmIntro, MasonriedHike_Text_JayAndEmDefeated, MasonriedHike_Text_JayAndEmNeedTwoMons
    msgbox MasonriedHike_Text_JayAndEmPostBattle, MSGBOX_AUTOCLOSE
    end

MasonriedHike_Text_MichaelIntro:
	.string "intro$"

MasonriedHike_Text_MichaelDefeated:
	.string "defeat$"

MasonriedHike_Text_MichaelPostBattle:
	.string "post$"

MasonriedHike_Text_ChloeIntro:
	.string "intro$"

MasonriedHike_Text_ChloeDefeated:
	.string "defeat$"

MasonriedHike_Text_ChloePostBattle:
	.string "post$"

MasonriedHike_Text_BichaelIntro:
	.string "intro$"

MasonriedHike_Text_BichaelDefeated:
	.string "defeat$"

MasonriedHike_Text_BichaelPostBattle:
	.string "post$"

MasonriedHike_Text_FlowersIntro:
	.string "intro$"

MasonriedHike_Text_FlowersDefeated:
	.string "defeat$"

MasonriedHike_Text_FlowersPostBattle:
	.string "post$"

MasonriedHike_Text_JayAndEmIntro:
	.string "intro$"

MasonriedHike_Text_JayAndEmDefeated:
	.string "defeat$"

MasonriedHike_Text_JayAndEmPostBattle:
	.string "post$"

MasonriedHike_Text_JayAndEmNeedTwoMons:
	.string "need 2 dood$"
