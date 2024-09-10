FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FieryPath_EventScript_Cass::
    trainerbattle_single TRAINER_P_CASS, FieryPath_Text_CassIntro, FieryPath_Text_CassDefeated
    msgbox FieryPath_Text_CassPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Sandy::
    trainerbattle_single TRAINER_P_SANDY, FieryPath_Text_SandyIntro, FieryPath_Text_SandyDefeated
    msgbox FieryPath_Text_SandyPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Jan::
    trainerbattle_single TRAINER_P_JAN, FieryPath_Text_JanIntro, FieryPath_Text_JanDefeated
    msgbox FieryPath_Text_JanPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Catt::
    trainerbattle_single TRAINER_P_CATHY, FieryPath_Text_CattIntro, FieryPath_Text_CattDefeated
    msgbox FieryPath_Text_CattPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Celia::
    trainerbattle_single TRAINER_P_CELIA, FieryPath_Text_CeliaIntro, FieryPath_Text_CeliaDefeated
    msgbox FieryPath_Text_CeliaPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_REDACTED::
    trainerbattle_single TRAINER_P_REDACTED, FieryPath_Text_REDACTEDIntro, FieryPath_Text_REDACTEDDefeated
    msgbox FieryPath_Text_REDACTEDPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Dimitri::
    trainerbattle_single TRAINER_P_DIMITRI, FieryPath_Text_DimitriIntro, FieryPath_Text_DimitriDefeated
    msgbox FieryPath_Text_DimitriPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_CliffAndIssa::
    trainerbattle_double TRAINER_P_CLIFF_AND_ISSA, FieryPath_Text_CliffAndIssaIntro, FieryPath_Text_CliffAndIssaDefeated, FieryPath_Text_CliffAndIssaNeedTwoMons
    msgbox FieryPath_Text_CliffAndIssaPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Gerode::
    trainerbattle_single TRAINER_P_GERODE, FieryPath_Text_GerodeIntro, FieryPath_Text_GerodeDefeated
    msgbox FieryPath_Text_GerodePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Mezra::
    trainerbattle_single TRAINER_P_MEZRA, FieryPath_Text_MezraIntro, FieryPath_Text_MezraDefeated
    msgbox FieryPath_Text_MezraPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Lane::
    trainerbattle_single TRAINER_P_LANE, FieryPath_Text_LaneIntro, FieryPath_Text_LaneDefeated
    msgbox FieryPath_Text_LanePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Bonnie::
    trainerbattle_single TRAINER_P_BONNIE, FieryPath_Text_BonnieIntro, FieryPath_Text_BonnieDefeated
    msgbox FieryPath_Text_BonniePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Hedon::
    trainerbattle_single TRAINER_P_HEDON, FieryPath_Text_HedonIntro, FieryPath_Text_HedonDefeated
    msgbox FieryPath_Text_HedonPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Rye::
    trainerbattle_single TRAINER_P_RYE, FieryPath_Text_RyeIntro, FieryPath_Text_RyeDefeated
    msgbox FieryPath_Text_RyePostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_Ingrid::
    trainerbattle_single TRAINER_P_INGRID, FieryPath_Text_IngridIntro, FieryPath_Text_IngridDefeated
    msgbox FieryPath_Text_IngridPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_EventScript_BlaiseAndMar::
    trainerbattle_double TRAINER_P_BLAISE_AND_MAR, FieryPath_Text_BlaiseAndMarIntro, FieryPath_Text_BlaiseAndMarDefeated, FieryPath_Text_BlaiseAndMarNeedTwoMons
    msgbox FieryPath_Text_BlaiseAndMarPostBattle, MSGBOX_AUTOCLOSE
    end

FieryPath_Text_CassIntro:
	.string "intro$"

FieryPath_Text_CassDefeated:
	.string "defeat$"

FieryPath_Text_CassPostBattle:
	.string "post$"

FieryPath_Text_SandyIntro:
	.string "intro$"

FieryPath_Text_SandyDefeated:
	.string "defeat$"

FieryPath_Text_SandyPostBattle:
	.string "post$"

FieryPath_Text_JanIntro:
	.string "intro$"

FieryPath_Text_JanDefeated:
	.string "defeat$"

FieryPath_Text_JanPostBattle:
	.string "post$"

FieryPath_Text_CattIntro:
	.string "intro$"

FieryPath_Text_CattDefeated:
	.string "defeat$"

FieryPath_Text_CattPostBattle:
	.string "post$"

FieryPath_Text_CeliaIntro:
	.string "intro$"

FieryPath_Text_CeliaDefeated:
	.string "defeat$"

FieryPath_Text_CeliaPostBattle:
	.string "post$"

FieryPath_Text_REDACTEDIntro:
	.string "intro$"

FieryPath_Text_REDACTEDDefeated:
	.string "defeat$"

FieryPath_Text_REDACTEDPostBattle:
	.string "post$"

FieryPath_Text_DimitriIntro:
	.string "intro$"

FieryPath_Text_DimitriDefeated:
	.string "defeat$"

FieryPath_Text_DimitriPostBattle:
	.string "post$"

FieryPath_Text_CliffAndIssaIntro:
	.string "intro$"

FieryPath_Text_CliffAndIssaDefeated:
	.string "defeat$"

FieryPath_Text_CliffAndIssaPostBattle:
	.string "post$"

FieryPath_Text_CliffAndIssaNeedTwoMons:
	.string "need 2 dood$"

FieryPath_Text_GerodeIntro:
	.string "intro$"

FieryPath_Text_GerodeDefeated:
	.string "defeat$"

FieryPath_Text_GerodePostBattle:
	.string "post$"

FieryPath_Text_MezraIntro:
	.string "intro$"

FieryPath_Text_MezraDefeated:
	.string "defeat$"

FieryPath_Text_MezraPostBattle:
	.string "post$"

FieryPath_Text_LaneIntro:
	.string "intro$"

FieryPath_Text_LaneDefeated:
	.string "defeat$"

FieryPath_Text_LanePostBattle:
	.string "post$"

FieryPath_Text_BonnieIntro:
	.string "intro$"

FieryPath_Text_BonnieDefeated:
	.string "defeat$"

FieryPath_Text_BonniePostBattle:
	.string "post$"

FieryPath_Text_HedonIntro:
	.string "intro$"

FieryPath_Text_HedonDefeated:
	.string "defeat$"

FieryPath_Text_HedonPostBattle:
	.string "post$"

FieryPath_Text_RyeIntro:
	.string "intro$"

FieryPath_Text_RyeDefeated:
	.string "defeat$"

FieryPath_Text_RyePostBattle:
	.string "post$"

FieryPath_Text_IngridIntro:
	.string "intro$"

FieryPath_Text_IngridDefeated:
	.string "defeat$"

FieryPath_Text_IngridPostBattle:
	.string "post$"

FieryPath_Text_BlaiseAndMarIntro:
	.string "intro$"

FieryPath_Text_BlaiseAndMarDefeated:
	.string "defeat$"

FieryPath_Text_BlaiseAndMarPostBattle:
	.string "post$"

FieryPath_Text_BlaiseAndMarNeedTwoMons:
	.string "need 2 dood$"
