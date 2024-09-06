PetalburgWoodsNew_MapScripts::
	.byte 0

PetalburgWoodsNew_EventScript_Tutu::
    trainerbattle_single TRAINER_P_TUTU, PetalburgWoodsNew_Text_TutuIntro, PetalburgWoodsNew_Text_TutuDefeated
    msgbox PetalburgWoodsNew_Text_TutuPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Duck::
    trainerbattle_single TRAINER_P_DUCK, PetalburgWoodsNew_Text_DuckIntro, PetalburgWoodsNew_Text_DuckDefeated
    msgbox PetalburgWoodsNew_Text_DuckPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Violet::
    trainerbattle_single TRAINER_P_VIOLET, PetalburgWoodsNew_Text_VioletIntro, PetalburgWoodsNew_Text_VioletDefeated
    msgbox PetalburgWoodsNew_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Elizabeth::
    trainerbattle_single TRAINER_P_ELIZABETH, PetalburgWoodsNew_Text_ElizabethIntro, PetalburgWoodsNew_Text_ElizabethDefeated
    msgbox PetalburgWoodsNew_Text_ElizabethPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Artie::
    trainerbattle_single TRAINER_P_ARTIE, PetalburgWoodsNew_Text_ArtieIntro, PetalburgWoodsNew_Text_ArtieDefeated
    msgbox PetalburgWoodsNew_Text_ArtiePostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Gyomaru::
    trainerbattle_single TRAINER_P_GYOMARU, PetalburgWoodsNew_Text_GyomaruIntro, PetalburgWoodsNew_Text_GyomaruDefeated
    msgbox PetalburgWoodsNew_Text_GyomaruPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Suzume::
    trainerbattle_single TRAINER_P_SUZUME, PetalburgWoodsNew_Text_SuzumeIntro, PetalburgWoodsNew_Text_SuzumeDefeated
    msgbox PetalburgWoodsNew_Text_SuzumePostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Mio::
    trainerbattle_single TRAINER_P_MIO, PetalburgWoodsNew_Text_MioIntro, PetalburgWoodsNew_Text_MioDefeated
    msgbox PetalburgWoodsNew_Text_MioPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Lemmy::
    trainerbattle_single TRAINER_P_LEMMY, PetalburgWoodsNew_Text_LemmyIntro, PetalburgWoodsNew_Text_LemmyDefeated
    msgbox PetalburgWoodsNew_Text_LemmyPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_Ichi::
    trainerbattle_single TRAINER_P_ICHI, PetalburgWoodsNew_Text_IchiIntro, PetalburgWoodsNew_Text_IchiDefeated
    msgbox PetalburgWoodsNew_Text_IchiPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_EventScript_InuAndPersia::
    trainerbattle_double TRAINER_P_INU_AND_PERSIA, PetalburgWoodsNew_Text_InuAndPersiaIntro, PetalburgWoodsNew_Text_InuAndPersiaDefeated, PetalburgWoodsNew_Text_InuAndPersiaNeedTwoMons
    msgbox PetalburgWoodsNew_Text_InuAndPersiaPostBattle, MSGBOX_AUTOCLOSE
    end

PetalburgWoodsNew_Text_TutuIntro:
	.string "intro$"

PetalburgWoodsNew_Text_TutuDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_TutuPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_DuckIntro:
	.string "intro$"

PetalburgWoodsNew_Text_DuckDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_DuckPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_VioletIntro:
	.string "intro$"

PetalburgWoodsNew_Text_VioletDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_VioletPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_ElizabethIntro:
	.string "intro$"

PetalburgWoodsNew_Text_ElizabethDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_ElizabethPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_ArtieIntro:
	.string "intro$"

PetalburgWoodsNew_Text_ArtieDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_ArtiePostBattle:
	.string "post$"

PetalburgWoodsNew_Text_GyomaruIntro:
	.string "intro$"

PetalburgWoodsNew_Text_GyomaruDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_GyomaruPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_SuzumeIntro:
	.string "intro$"

PetalburgWoodsNew_Text_SuzumeDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_SuzumePostBattle:
	.string "post$"

PetalburgWoodsNew_Text_MioIntro:
	.string "intro$"

PetalburgWoodsNew_Text_MioDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_MioPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_LemmyIntro:
	.string "intro$"

PetalburgWoodsNew_Text_LemmyDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_LemmyPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_IchiIntro:
	.string "intro$"

PetalburgWoodsNew_Text_IchiDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_IchiPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_InuAndPersiaIntro:
	.string "intro$"

PetalburgWoodsNew_Text_InuAndPersiaDefeated:
	.string "defeat$"

PetalburgWoodsNew_Text_InuAndPersiaPostBattle:
	.string "post$"

PetalburgWoodsNew_Text_InuAndPersiaNeedTwoMons:
	.string "need 2 dood$"
