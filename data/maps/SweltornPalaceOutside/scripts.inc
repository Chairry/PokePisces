SweltornPalaceOutside_MapScripts::
	.byte 0

SweltornPalaceOutside_EventScript_Cy::
    trainerbattle_single TRAINER_P_CY, SweltornPalaceOutside_Text_CyIntro, SweltornPalaceOutside_Text_CyDefeated
    msgbox SweltornPalaceOutside_Text_CyPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalaceOutside_EventScript_WendyAndGale::
    trainerbattle_double TRAINER_P_WENDY_AND_GALE, SweltornPalaceOutside_Text_WendyAndGaleIntro, SweltornPalaceOutside_Text_WendyAndGaleDefeated, SweltornPalaceOutside_Text_WendyAndGaleNeedTwoMons
    msgbox SweltornPalaceOutside_Text_WendyAndGalePostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalaceOutside_EventScript_Kaku::
    trainerbattle_single TRAINER_P_KAKU, SweltornPalaceOutside_Text_KakuIntro, SweltornPalaceOutside_Text_KakuDefeated
    msgbox SweltornPalaceOutside_Text_KakuPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalaceOutside_Text_CyIntro:
	.string "intro$"

SweltornPalaceOutside_Text_CyDefeated:
	.string "defeat$"

SweltornPalaceOutside_Text_CyPostBattle:
	.string "post$"

SweltornPalaceOutside_Text_WendyAndGaleIntro:
	.string "intro$"

SweltornPalaceOutside_Text_WendyAndGaleDefeated:
	.string "defeat$"

SweltornPalaceOutside_Text_WendyAndGalePostBattle:
	.string "post$"

SweltornPalaceOutside_Text_WendyAndGaleNeedTwoMons:
	.string "need 2 dood$"

SweltornPalaceOutside_Text_KakuIntro:
	.string "intro$"

SweltornPalaceOutside_Text_KakuDefeated:
	.string "defeat$"

SweltornPalaceOutside_Text_KakuPostBattle:
	.string "post$"
