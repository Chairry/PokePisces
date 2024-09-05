SailorsPause_MapScripts::
	.byte 0

SailorsPause_EventScript_Valerie::
    trainerbattle_single TRAINER_P_VALERIE, SailorsPause_Text_ValerieIntro, SailorsPause_Text_ValerieDefeated
    msgbox SailorsPause_Text_ValeriePostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPause_EventScript_Queequeg::
    trainerbattle_single TRAINER_P_QUEEQUEG, SailorsPause_Text_QueequegIntro, SailorsPause_Text_QueequegDefeated
    msgbox SailorsPause_Text_QueequegPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPause_EventScript_Jess::
    trainerbattle_single TRAINER_P_JESS, SailorsPause_Text_JessIntro, SailorsPause_Text_JessDefeated
    msgbox SailorsPause_Text_JessPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPause_Text_ValerieIntro:
	.string "intro$"

SailorsPause_Text_ValerieDefeated:
	.string "defeat$"

SailorsPause_Text_ValeriePostBattle:
	.string "post$"

SailorsPause_Text_QueequegIntro:
	.string "intro$"

SailorsPause_Text_QueequegDefeated:
	.string "defeat$"

SailorsPause_Text_QueequegPostBattle:
	.string "post$"

SailorsPause_Text_JessIntro:
	.string "intro$"

SailorsPause_Text_JessDefeated:
	.string "defeat$"

SailorsPause_Text_JessPostBattle:
	.string "post$"
