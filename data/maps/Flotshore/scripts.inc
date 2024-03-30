.set LOCALID_BARRELFISHER, 19

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

Flotshore_EventScript_PounceFlagTest::
	lock
	setflag FLAG_RECEIVED_TM_POUNCE
	msgbox Flotshore_Text_Gugumbir, MSGBOX_AUTOCLOSE
	release
	end

Flotshore_EventScript_VacuumWaveJanitor::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_VACUUM_WAVE, Flotshore_EventScript_GaveVacuumWave
	msgbox Flotshore_Text_Gugumbir, MSGBOX_DEFAULT
	giveitem ITEM_TM_VACUUM_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_VACUUM_WAVE
	release
	end

Flotshore_EventScript_GaveVacuumWave::
    msgbox Flotshore_Text_Gugumbir, MSGBOX_AUTOCLOSE
    release
    end

Flotshore_EventScript_PounceBarrel::
    lock
	clearflag FLAG_RECEIVED_TM_POUNCE
	addobject LOCALID_BARRELFISHER
	applymovement LOCALID_BARRELFISHER, Flotshore_Movement_JumpFromBarrel
	waitmovement 0
	checkitem ITEM_TM_POUNCE
	goto_if_eq VAR_RESULT, TRUE, Flotshore_EventScript_GavePounce
	msgbox Flotshore_Text_GotYou, MSGBOX_DEFAULT
	giveitem ITEM_TM_POUNCE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_TEMP_1, 1
	setflag FLAG_RECEIVED_TM_POUNCE
	applymovement LOCALID_BARRELFISHER, Flotshore_Movement_JumpIntoBarrel
	waitmovement 0
	release
	end

Flotshore_Movement_JumpFromBarrel:
	set_visible
	jump_right
	face_right
	step_end

Flotshore_Movement_JumpIntoBarrel:
	jump_left
	face_left
	set_invisible
	step_end

Flotshore_EventScript_GavePounce::
    msgbox Flotshore_Text_AlreadyGotYou, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_1, 1
	setflag FLAG_RECEIVED_TM_POUNCE
	applymovement LOCALID_BARRELFISHER, Flotshore_Movement_JumpIntoBarrel
	waitmovement 0
    release
    end

Flotshore_Text_GotYou:
	.string "BOOGA BOOGA BOOGA!!!\p"
	.string "Haha! Did I getcha? Come on now,\n"
	.string "lighten up! We're havin' as much\l"
	.string "fun as a BARREL of monkeys!!\p"
	.string "Haha! Here's my apology for\n"
	.string "the sensory overload.\p"
	.string "Take this and maybe YOU can get\n"
	.string "the drop on someone else!$"

Flotshore_Text_AlreadyGotYou:
	.string "BOOGA...boo...ga...\p"
	.string "Hey! I already jumpscared you\n"
	.string "before! Leave room for another sucker!$"

Flotshore_Text_Gugumbir:
	.string "test$"

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
	.string "Is there anythin' better than fishin'?$"

Flotshore_Text_DanDefeated:
	.string "I suppose battlin' is a close second.$"

Flotshore_Text_DanPostBattle:
	.string "Y'know, plenty o' people go fishin'\n"
	.string "all of their lives, without knowin'\l"
	.string "that it ain't the fish\l"
	.string "they are really after.\p"
	.string "There's a little wisdom for ya'.$"

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
	.string "I wonder, what kind of\n"
	.string "Pokémon do you use?\p"
	.string "Ones that are good at battle, or\n"
	.string "ones that can help you outside of it?$"

Flotshore_Text_BarbaraDefeated:
	.string "Hmm... Perhaps,\n"
	.string "a healthy mix of both is best.$"

Flotshore_Text_BarbaraPostBattle:
	.string "My Pokémon help me swim around\n"
	.string "the local waterways when I\l"
	.string "want to find a new fishing spot.$"

Flotshore_Text_HaveMyShell:
	.string "I love searchin' underneath\n"
	.string "the boards!\p"
	.string "Here, take this shell\n"
	.string "I found down there.$"

Flotshore_Text_GaveSeashellAlr:
	.string "I think I'll make a fort\n"
	.string "down there… just for me!$"
