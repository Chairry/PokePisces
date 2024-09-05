SailorsPauseUnderwater_MapScripts::
	.byte 0

SailorsPauseUnderwater_EventScript_Sandeep::
    trainerbattle_single TRAINER_P_SANDEEP, SailorsPauseUnderwater_Text_SandeepIntro, SailorsPauseUnderwater_Text_SandeepDefeated
    msgbox SailorsPauseUnderwater_Text_SandeepPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseUnderwater_Text_SandeepIntro:
	.string "intro$"

SailorsPauseUnderwater_Text_SandeepDefeated:
	.string "defeat$"

SailorsPauseUnderwater_Text_SandeepPostBattle:
	.string "post$"
