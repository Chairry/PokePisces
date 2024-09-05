NavigulfUnderwater_MapScripts::
	.byte 0

NavigulfUnderwater_EventScript_Daphne::
    trainerbattle_single TRAINER_P_DAPHNE, NavigulfUnderwater_Text_DaphneIntro, NavigulfUnderwater_Text_DaphneDefeated
    msgbox NavigulfUnderwater_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfUnderwater_EventScript_Velma::
    trainerbattle_single TRAINER_P_VELMA, NavigulfUnderwater_Text_VelmaIntro, NavigulfUnderwater_Text_VelmaDefeated
    msgbox NavigulfUnderwater_Text_VelmaPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfUnderwater_EventScript_Fred::
    trainerbattle_single TRAINER_P_FRED, NavigulfUnderwater_Text_FredIntro, NavigulfUnderwater_Text_FredDefeated
    msgbox NavigulfUnderwater_Text_FredPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfUnderwater_EventScript_Shaggy::
    trainerbattle_single TRAINER_P_SHAGGY, NavigulfUnderwater_Text_ShaggyIntro, NavigulfUnderwater_Text_ShaggyDefeated
    msgbox NavigulfUnderwater_Text_ShaggyPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfUnderwater_EventScript_Scoob::
    trainerbattle_single TRAINER_P_SCOOB, NavigulfUnderwater_Text_ScoobIntro, NavigulfUnderwater_Text_ScoobDefeated
    msgbox NavigulfUnderwater_Text_ScoobPostBattle, MSGBOX_AUTOCLOSE
    end

NavigulfUnderwater_Text_DaphneIntro:
	.string "intro$"

NavigulfUnderwater_Text_DaphneDefeated:
	.string "defeat$"

NavigulfUnderwater_Text_DaphnePostBattle:
	.string "post$"

NavigulfUnderwater_Text_VelmaIntro:
	.string "intro$"

NavigulfUnderwater_Text_VelmaDefeated:
	.string "defeat$"

NavigulfUnderwater_Text_VelmaPostBattle:
	.string "post$"

NavigulfUnderwater_Text_FredIntro:
	.string "intro$"

NavigulfUnderwater_Text_FredDefeated:
	.string "defeat$"

NavigulfUnderwater_Text_FredPostBattle:
	.string "post$"

NavigulfUnderwater_Text_ShaggyIntro:
	.string "intro$"

NavigulfUnderwater_Text_ShaggyDefeated:
	.string "defeat$"

NavigulfUnderwater_Text_ShaggyPostBattle:
	.string "post$"

NavigulfUnderwater_Text_ScoobIntro:
	.string "intro$"

NavigulfUnderwater_Text_ScoobDefeated:
	.string "defeat$"

NavigulfUnderwater_Text_ScoobPostBattle:
	.string "post$"
