StraeSeapath_MapScripts::
	.byte 0

StraeSeapath_EventScript_Mary::
    trainerbattle_single TRAINER_P_MARY, StraeSeapath_Text_MaryIntro, StraeSeapath_Text_MaryDefeated
    msgbox StraeSeapath_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_Jose::
    trainerbattle_single TRAINER_P_JOSE, StraeSeapath_Text_JoseIntro, StraeSeapath_Text_JoseDefeated
    msgbox StraeSeapath_Text_JosePostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_Daria::
    trainerbattle_single TRAINER_P_DARIA, StraeSeapath_Text_DariaIntro, StraeSeapath_Text_DariaDefeated
    msgbox StraeSeapath_Text_DariaPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_Jean::
    trainerbattle_single TRAINER_P_JEAN, StraeSeapath_Text_JeanIntro, StraeSeapath_Text_JeanDefeated
    msgbox StraeSeapath_Text_JeanPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_Lynn::
    trainerbattle_single TRAINER_P_LYNN, StraeSeapath_Text_LynnIntro, StraeSeapath_Text_LynnDefeated
    msgbox StraeSeapath_Text_LynnPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_Aiofe::
    trainerbattle_single TRAINER_P_AIOFE, StraeSeapath_Text_AiofeIntro, StraeSeapath_Text_AiofeDefeated
    msgbox StraeSeapath_Text_AiofePostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_DickAndJane::
    trainerbattle_double TRAINER_P_DICK_AND_JANE, StraeSeapath_Text_DickAndJaneIntro, StraeSeapath_Text_DickAndJaneDefeated, StraeSeapath_Text_DickAndJaneNeedTwoMons
    msgbox StraeSeapath_Text_DickAndJanePostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_RosieAndPalms::
    trainerbattle_double TRAINER_P_ROSIE_AND_PALMS, StraeSeapath_Text_RosieAndPalmsIntro, StraeSeapath_Text_RosieAndPalmsDefeated, StraeSeapath_Text_RosieAndPalmsNeedTwoMons
    msgbox StraeSeapath_Text_RosieAndPalmsPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_Maomao::
    trainerbattle_single TRAINER_P_MAOMAO, StraeSeapath_Text_MaomaoIntro, StraeSeapath_Text_MaomaoDefeated
    msgbox StraeSeapath_Text_MaomaoPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_EventScript_Barnaby::
    trainerbattle_single TRAINER_P_BARNABY, StraeSeapath_Text_BarnabyIntro, StraeSeapath_Text_BarnabyDefeated
    msgbox StraeSeapath_Text_BarnabyPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapath_Text_MaryIntro:
	.string "intro$"

StraeSeapath_Text_MaryDefeated:
	.string "defeat$"

StraeSeapath_Text_MaryPostBattle:
	.string "post$"

StraeSeapath_Text_JoseIntro:
	.string "intro$"

StraeSeapath_Text_JoseDefeated:
	.string "defeat$"

StraeSeapath_Text_JosePostBattle:
	.string "post$"

StraeSeapath_Text_DariaIntro:
	.string "intro$"

StraeSeapath_Text_DariaDefeated:
	.string "defeat$"

StraeSeapath_Text_DariaPostBattle:
	.string "post$"

StraeSeapath_Text_JeanIntro:
	.string "intro$"

StraeSeapath_Text_JeanDefeated:
	.string "defeat$"

StraeSeapath_Text_JeanPostBattle:
	.string "post$"

StraeSeapath_Text_LynnIntro:
	.string "intro$"

StraeSeapath_Text_LynnDefeated:
	.string "defeat$"

StraeSeapath_Text_LynnPostBattle:
	.string "post$"

StraeSeapath_Text_AiofeIntro:
	.string "intro$"

StraeSeapath_Text_AiofeDefeated:
	.string "defeat$"

StraeSeapath_Text_AiofePostBattle:
	.string "post$"

StraeSeapath_Text_DickAndJaneIntro:
	.string "intro$"

StraeSeapath_Text_DickAndJaneDefeated:
	.string "defeat$"

StraeSeapath_Text_DickAndJanePostBattle:
	.string "post$"

StraeSeapath_Text_DickAndJaneNeedTwoMons:
	.string "need 2 dood$"

StraeSeapath_Text_RosieAndPalmsIntro:
	.string "intro$"

StraeSeapath_Text_RosieAndPalmsDefeated:
	.string "defeat$"

StraeSeapath_Text_RosieAndPalmsPostBattle:
	.string "post$"

StraeSeapath_Text_RosieAndPalmsNeedTwoMons:
	.string "need 2 dood$"

StraeSeapath_Text_MaomaoIntro:
	.string "intro$"

StraeSeapath_Text_MaomaoDefeated:
	.string "defeat$"

StraeSeapath_Text_MaomaoPostBattle:
	.string "post$"

StraeSeapath_Text_BarnabyIntro:
	.string "intro$"

StraeSeapath_Text_BarnabyDefeated:
	.string "defeat$"

StraeSeapath_Text_BarnabyPostBattle:
	.string "post$"
