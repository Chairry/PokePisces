Flotshore_MapScripts::
	.byte 0

Flotshore_EventScript_Sean::
    trainerbattle_single TRAINER_P_SEAN, Flotshore_Text_SeanIntro, Flotshore_Text_SeanDefeated
    msgbox Flotshore_Text_SeanPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Janice::
    trainerbattle_single TRAINER_P_JANICE, Flotshore_Text_JaniceIntro, Flotshore_Text_JaniceDefeated
    msgbox Flotshore_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Jimmy::
    trainerbattle_single TRAINER_P_JIMMY, Flotshore_Text_JimmyIntro, Flotshore_Text_JimmyDefeated
    msgbox Flotshore_Text_JimmyPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Dan::
    trainerbattle_single TRAINER_P_DAN, Flotshore_Text_DanIntro, Flotshore_Text_DanDefeated
    msgbox Flotshore_Text_DanPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Lad::
    trainerbattle_single TRAINER_P_LAD, Flotshore_Text_LadIntro, Flotshore_Text_LadDefeated
    msgbox Flotshore_Text_LadPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Sammie::
    trainerbattle_single TRAINER_P_SAMMIE, Flotshore_Text_SammieIntro, Flotshore_Text_SammieDefeated
    msgbox Flotshore_Text_SammiePostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_Barbara::
    trainerbattle_single TRAINER_P_BARBARA, Flotshore_Text_BarbaraIntro, Flotshore_Text_BarbaraDefeated
    msgbox Flotshore_Text_BarbaraPostBattle, MSGBOX_AUTOCLOSE
    end

Flotshore_EventScript_SeaShellGiver::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SEASHELL_2, Flotshore_EventScript_GaveSeashellAlr
	msgbox Flotshore_Text_HaveMyShell, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SEASHELL_2
	release
	end

Flotshore_EventScript_GaveSeashellAlr::
    msgbox Flotshore_Text_GaveSeashellAlr, MSGBOX_AUTOCLOSE
    release
    end

Flotshore_Text_SeanIntro:
	.string "test$"

Flotshore_Text_SeanDefeated:
	.string "test$"

Flotshore_Text_SeanPostBattle:
	.string "test$"

Flotshore_Text_JaniceIntro:
	.string "test$"

Flotshore_Text_JaniceDefeated:
	.string "test$"

Flotshore_Text_JanicePostBattle:
	.string "test$"

Flotshore_Text_JimmyIntro:
	.string "I'm something of a boy\n"
	.string "genius, y'know!$"

Flotshore_Text_JimmyDefeated:
	.string "Even my super-powered mind\n"
	.string "couldn't measure up…$"

Flotshore_Text_JimmyPostBattle:
	.string "Hope you have a knack for adventure!\n"
	.string "The route branches off up ahead.$"

Flotshore_Text_DanIntro:
	.string "test$"

Flotshore_Text_DanDefeated:
	.string "test$"

Flotshore_Text_DanPostBattle:
	.string "test$"

Flotshore_Text_LadIntro:
	.string "test$"

Flotshore_Text_LadDefeated:
	.string "test$"

Flotshore_Text_LadPostBattle:
	.string "test$"

Flotshore_Text_SammieIntro:
	.string "test$"

Flotshore_Text_SammieDefeated:
	.string "test$"

Flotshore_Text_SammiePostBattle:
	.string "test$"

Flotshore_Text_BarbaraIntro:
	.string "test$"

Flotshore_Text_BarbaraDefeated:
	.string "test$"

Flotshore_Text_BarbaraPostBattle:
	.string "test$"

Flotshore_Text_HaveMyShell:
	.string "I love searchin' underneath\n"
	.string "the boards!\p"
	.string "Here, take this shell\n"
	.string "I found down there.$"

Flotshore_Text_GaveSeashellAlr:
	.string "I think I'll make a fort\n"
	.string "down there… just for me!$"
