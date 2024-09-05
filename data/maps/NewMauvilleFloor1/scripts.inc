NewMauvilleFloor1_MapScripts::
	.byte 0

NewMauvilleFloor1_EventScript_Roy::
    trainerbattle_single TRAINER_P_ROY, NewMauvilleFloor1_Text_RoyIntro, NewMauvilleFloor1_Text_RoyDefeated
    msgbox NewMauvilleFloor1_Text_RoyPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_EventScript_McKayleigh::
    trainerbattle_single TRAINER_P_MCKAYLEIGH, NewMauvilleFloor1_Text_McKayleighIntro, NewMauvilleFloor1_Text_McKayleighDefeated
    msgbox NewMauvilleFloor1_Text_McKayleighPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_EventScript_Aiden::
    trainerbattle_single TRAINER_P_AIDEN, NewMauvilleFloor1_Text_AidenIntro, NewMauvilleFloor1_Text_AidenDefeated
    msgbox NewMauvilleFloor1_Text_AidenPostBattle, MSGBOX_AUTOCLOSE
    end

NewMauvilleFloor1_Text_RoyIntro:
	.string "intro$"

NewMauvilleFloor1_Text_RoyDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_RoyPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_McKayleighIntro:
	.string "intro$"

NewMauvilleFloor1_Text_McKayleighDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_McKayleighPostBattle:
	.string "post$"

NewMauvilleFloor1_Text_AidenIntro:
	.string "intro$"

NewMauvilleFloor1_Text_AidenDefeated:
	.string "defeat$"

NewMauvilleFloor1_Text_AidenPostBattle:
	.string "post$"
