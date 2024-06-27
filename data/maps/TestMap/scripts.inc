TestMap_MapScripts::
	.byte 0

TestMap_EventScript_Mendel::
    trainerbattle_single TRAINER_P_MENDEL, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_Text_MendelIntro:
	.string "intro$"

TestMap_Text_MendelDefeated:
	.string "defeat$"

TestMap_Text_MendelPostBattle:
	.string "post$"
