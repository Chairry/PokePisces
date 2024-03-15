BasalinCoast_MapScripts::
	.byte 0

BasalinCoast_EventScript_Beatrice::
    trainerbattle_single TRAINER_P_BEATRICE, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Nancy::
    trainerbattle_single TRAINER_P_NANCY, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Sadie::
    trainerbattle_single TRAINER_P_SADIE, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Melanie::
    trainerbattle_single TRAINER_P_MELANIE, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Timmy::
    trainerbattle_single TRAINER_P_TIMMY, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Wadelle::
    trainerbattle_single TRAINER_P_WADELLE, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Yanny::
    trainerbattle_single TRAINER_P_YANNY, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Remy::
    trainerbattle_single TRAINER_P_REMY, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Selko::
    trainerbattle_single TRAINER_P_SELKO, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_ShedShellKid::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SHED_SHELL, BasalinCoast_EventScript_GaveShedShell
	msgbox BasalinCoast_Text_HaveShedShell, MSGBOX_DEFAULT
	giveitem ITEM_SHED_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SHED_SHELL
	release
	end

BasalinCoast_EventScript_GaveShedShell::
    msgbox BasalinCoast_Text_GaveShedShell, MSGBOX_AUTOCLOSE
    release
    end

BasalinCoast_Text_GugumbirIntro:
	.string "intro$"

BasalinCoast_Text_GugumbirDefeated:
	.string "defeat$"

BasalinCoast_Text_GugumbirPostBattle:
	.string "post$"

BasalinCoast_Text_HaveShedShell:
    .string "have this shell haha$"

BasalinCoast_Text_GaveShedShell:
    .string "already gave ya one$"
