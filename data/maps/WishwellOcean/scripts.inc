WishwellOcean_MapScripts::
	.byte 0

WishwellOcean_EventScript_Xerxes::
    trainerbattle_single TRAINER_P_XERXES, WishwellOcean_Text_XerxesIntro, WishwellOcean_Text_XerxesDefeated
    msgbox WishwellOcean_Text_XerxesPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Yvette::
    trainerbattle_single TRAINER_P_YVETTE, WishwellOcean_Text_YvetteIntro, WishwellOcean_Text_YvetteDefeated
    msgbox WishwellOcean_Text_YvettePostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_PiAndSees::
    trainerbattle_double TRAINER_P_PI_AND_SEES, WishwellOcean_Text_PiAndSeesIntro, WishwellOcean_Text_PiAndSeesDefeated, WishwellOcean_Text_PiAndSeesNeedTwoMons
    msgbox WishwellOcean_Text_PiAndSeesPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_KuAndMori::
    trainerbattle_double TRAINER_P_KU_AND_MORI, WishwellOcean_Text_KuAndMoriIntro, WishwellOcean_Text_KuAndMoriDefeated, WishwellOcean_Text_KuAndMoriNeedTwoMons
    msgbox WishwellOcean_Text_KuAndMoriPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Persephone::
    trainerbattle_single TRAINER_P_PERSEPHONE, WishwellOcean_Text_PersephoneIntro, WishwellOcean_Text_PersephoneDefeated
    msgbox WishwellOcean_Text_PersephonePostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Xavier::
    trainerbattle_single TRAINER_P_XAVIER, WishwellOcean_Text_XavierIntro, WishwellOcean_Text_XavierDefeated
    msgbox WishwellOcean_Text_XavierPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Nafi::
    trainerbattle_single TRAINER_P_NAFI, WishwellOcean_Text_NafiIntro, WishwellOcean_Text_NafiDefeated
    msgbox WishwellOcean_Text_NafiPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Madeline::
    trainerbattle_single TRAINER_P_MADELINE, WishwellOcean_Text_MadelineIntro, WishwellOcean_Text_MadelineDefeated
    msgbox WishwellOcean_Text_MadelinePostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Enrique::
    trainerbattle_single TRAINER_P_ENRIQUE, WishwellOcean_Text_EnriqueIntro, WishwellOcean_Text_EnriqueDefeated
    msgbox WishwellOcean_Text_EnriquePostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Maria::
    trainerbattle_single TRAINER_P_MARIA, WishwellOcean_Text_MariaIntro, WishwellOcean_Text_MariaDefeated
    msgbox WishwellOcean_Text_MariaPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Fern::
    trainerbattle_single TRAINER_P_FERN, WishwellOcean_Text_FernIntro, WishwellOcean_Text_FernDefeated
    msgbox WishwellOcean_Text_FernPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Dudley::
    trainerbattle_single TRAINER_P_DUDLEY, WishwellOcean_Text_DudleyIntro, WishwellOcean_Text_DudleyDefeated
    msgbox WishwellOcean_Text_DudleyPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Gustavo::
    trainerbattle_single TRAINER_P_GUSTAVO, WishwellOcean_Text_GustavoIntro, WishwellOcean_Text_GustavoDefeated
    msgbox WishwellOcean_Text_GustavoPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_EventScript_Neil::
    trainerbattle_single TRAINER_P_NEIL, WishwellOcean_Text_NeilIntro, WishwellOcean_Text_NeilDefeated
    msgbox WishwellOcean_Text_NeilPostBattle, MSGBOX_AUTOCLOSE
    end

WishwellOcean_Text_XerxesIntro:
	.string "intro$"

WishwellOcean_Text_XerxesDefeated:
	.string "defeat$"

WishwellOcean_Text_XerxesPostBattle:
	.string "post$"

WishwellOcean_Text_YvetteIntro:
	.string "intro$"

WishwellOcean_Text_YvetteDefeated:
	.string "defeat$"

WishwellOcean_Text_YvettePostBattle:
	.string "post$"

WishwellOcean_Text_PiAndSeesIntro:
	.string "intro$"

WishwellOcean_Text_PiAndSeesDefeated:
	.string "defeat$"

WishwellOcean_Text_PiAndSeesPostBattle:
	.string "post$"

WishwellOcean_Text_PiAndSeesNeedTwoMons:
	.string "need 2 dood$"

WishwellOcean_Text_KuAndMoriIntro:
	.string "intro$"

WishwellOcean_Text_KuAndMoriDefeated:
	.string "defeat$"

WishwellOcean_Text_KuAndMoriPostBattle:
	.string "post$"

WishwellOcean_Text_KuAndMoriNeedTwoMons:
	.string "need 2 dood$"

WishwellOcean_Text_PersephoneIntro:
	.string "intro$"

WishwellOcean_Text_PersephoneDefeated:
	.string "defeat$"

WishwellOcean_Text_PersephonePostBattle:
	.string "post$"

WishwellOcean_Text_XavierIntro:
	.string "intro$"

WishwellOcean_Text_XavierDefeated:
	.string "defeat$"

WishwellOcean_Text_XavierPostBattle:
	.string "post$"

WishwellOcean_Text_NafiIntro:
	.string "intro$"

WishwellOcean_Text_NafiDefeated:
	.string "defeat$"

WishwellOcean_Text_NafiPostBattle:
	.string "post$"

WishwellOcean_Text_MadelineIntro:
	.string "intro$"

WishwellOcean_Text_MadelineDefeated:
	.string "defeat$"

WishwellOcean_Text_MadelinePostBattle:
	.string "post$"

WishwellOcean_Text_EnriqueIntro:
	.string "intro$"

WishwellOcean_Text_EnriqueDefeated:
	.string "defeat$"

WishwellOcean_Text_EnriquePostBattle:
	.string "post$"

WishwellOcean_Text_MariaIntro:
	.string "intro$"

WishwellOcean_Text_MariaDefeated:
	.string "defeat$"

WishwellOcean_Text_MariaPostBattle:
	.string "post$"

WishwellOcean_Text_FernIntro:
	.string "intro$"

WishwellOcean_Text_FernDefeated:
	.string "defeat$"

WishwellOcean_Text_FernPostBattle:
	.string "post$"

WishwellOcean_Text_DudleyIntro:
	.string "intro$"

WishwellOcean_Text_DudleyDefeated:
	.string "defeat$"

WishwellOcean_Text_DudleyPostBattle:
	.string "post$"

WishwellOcean_Text_GustavoIntro:
	.string "intro$"

WishwellOcean_Text_GustavoDefeated:
	.string "defeat$"

WishwellOcean_Text_GustavoPostBattle:
	.string "post$"

WishwellOcean_Text_NeilIntro:
	.string "intro$"

WishwellOcean_Text_NeilDefeated:
	.string "defeat$"

WishwellOcean_Text_NeilPostBattle:
	.string "post$"
