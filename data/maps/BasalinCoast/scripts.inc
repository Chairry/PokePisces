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
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SEASHELL_4, BasalinCoast_EventScript_SelkoGivenShell
    msgbox BasalinCoast_Text_WantMySeashell, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BasalinCoast_EventScript_BattleSelko
	goto_if_eq VAR_RESULT, NO, BasalinCoast_EventScript_AreYaSure
	end

BasalinCoast_EventScript_BattleSelko::
	trainerbattle_single TRAINER_P_SELKO, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated, BasalinCoast_EventScript_GiveSelkoShell
	release
	end

BasalinCoast_EventScript_GiveSelkoShell::
	msgbox BasalinCoast_Text_YouEarnedThisShell, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SHELL
	setflag FLAG_RECEIVED_SEASHELL_4
	release
	end

BasalinCoast_EventScript_AreYaSure::
	msgbox BasalinCoast_Text_AreYaSure, MSGBOX_DEFAULT
	release
	end

BasalinCoast_EventScript_SelkoGivenShell::
	msgbox BasalinCoast_Text_SelkoPostBattle, MSGBOX_NPC
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

BasalinCoast_EventScript_SeaShellGiver::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SEASHELL_3, BasalinCoast_EventScript_GaveSeashellAlr
	msgbox BasalinCoast_Text_HaveMyShell, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SEASHELL_3
	release
	end

BasalinCoast_EventScript_GaveSeashellAlr::
    msgbox BasalinCoast_Text_GaveSeashellAlr, MSGBOX_AUTOCLOSE
    release
    end

BasalinCoast_Text_GugumbirIntro:
	.string "intro$"

BasalinCoast_Text_GugumbirDefeated:
	.string "defeat$"

BasalinCoast_Text_GugumbirPostBattle:
	.string "post$"

BasalinCoast_Text_WantMySeashell:
    .string "want my shell?$"

BasalinCoast_Text_YouEarnedThisShell:
    .string "you earned this$"

BasalinCoast_Text_AreYaSure:
    .string "you suuuuuuuuure?$"

BasalinCoast_Text_SelkoPostBattle:
    .string "selko post battle lol$"

BasalinCoast_Text_HaveShedShell:
    .string "have this shell haha$"

BasalinCoast_Text_GaveShedShell:
    .string "already gave ya one$"

BasalinCoast_Text_HaveMyShell:
    .string "have my sneed shell$"

BasalinCoast_Text_GaveSeashellAlr:
    .string "i like rocks$"
