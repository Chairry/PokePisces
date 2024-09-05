StraeSeapathUnderwater_MapScripts::
	.byte 0

StraeSeapathUnderwater_EventScript_Meenah::
    trainerbattle_single TRAINER_P_MEENAH, StraeSeapathUnderwater_Text_MeenahIntro, StraeSeapathUnderwater_Text_MeenahDefeated
    msgbox StraeSeapathUnderwater_Text_MeenahPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapathUnderwater_EventScript_Feferi::
    trainerbattle_single TRAINER_P_FEFERI, StraeSeapathUnderwater_Text_FeferiIntro, StraeSeapathUnderwater_Text_FeferiDefeated
    msgbox StraeSeapathUnderwater_Text_FeferiPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapathUnderwater_EventScript_Howlee::
    trainerbattle_single TRAINER_P_HOWLEE, StraeSeapathUnderwater_Text_HowleeIntro, StraeSeapathUnderwater_Text_HowleeDefeated
    msgbox StraeSeapathUnderwater_Text_HowleePostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapathUnderwater_EventScript_Mowgli::
    trainerbattle_single TRAINER_P_MOWGLI, StraeSeapathUnderwater_Text_MowgliIntro, StraeSeapathUnderwater_Text_MowgliDefeated
    msgbox StraeSeapathUnderwater_Text_MowgliPostBattle, MSGBOX_AUTOCLOSE
    end

StraeSeapathUnderwater_Text_MeenahIntro:
	.string "intro$"

StraeSeapathUnderwater_Text_MeenahDefeated:
	.string "defeat$"

StraeSeapathUnderwater_Text_MeenahPostBattle:
	.string "post$"

StraeSeapathUnderwater_Text_FeferiIntro:
	.string "intro$"

StraeSeapathUnderwater_Text_FeferiDefeated:
	.string "defeat$"

StraeSeapathUnderwater_Text_FeferiPostBattle:
	.string "post$"

StraeSeapathUnderwater_Text_HowleeIntro:
	.string "intro$"

StraeSeapathUnderwater_Text_HowleeDefeated:
	.string "defeat$"

StraeSeapathUnderwater_Text_HowleePostBattle:
	.string "post$"

StraeSeapathUnderwater_Text_MowgliIntro:
	.string "intro$"

StraeSeapathUnderwater_Text_MowgliDefeated:
	.string "defeat$"

StraeSeapathUnderwater_Text_MowgliPostBattle:
	.string "post$"
