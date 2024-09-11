FortreeGymNew_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeGymNew_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeGymNew_OnWarp
	.byte 0

FortreeGymNew_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeGymNew_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeGymNew_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeGymNew_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeGymNew_EventScript_DoorGuard::
	lock
	goto_if_eq VAR_PISCES_STORY_PROGRESS, 4, FortreeGymNew_EventScript_WantToGoIn
	goto_if_gt VAR_PISCES_STORY_PROGRESS, 4, FortreeGymNew_EventScript_CantGoIn
	release
	end

FortreeGymNew_EventScript_WantToGoIn::
	applymovement LOCALID_GYMGUARD, FortreeGymNew_Movement_GuardFacesYou
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymNew_Movement_YouFaceGuard
	msgbox FortreeGymNew_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeGymNew_EventScript_PrepForGym
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymNew_Movement_MoveAway
	waitmovement 0
	msgbox FortreeGymNew_Text_ThenGoPrepare, MSGBOX_AUTOCLOSE
	release
	end

FortreeGymNew_EventScript_PrepForGym::
	clearflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	msgbox FortreeGymNew_Text_TimeForGym, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymNew_Movement_IntoGym
	waitmovement 0
	release
	end

FortreeGymNew_EventScript_CantGoIn::
	applymovement LOCALID_GYMGUARD, FortreeGymNew_Movement_GuardFacesYou
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymNew_Movement_YouFaceGuard
	msgbox FortreeGymNew_Text_YouAlreadyDidThis, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymNew_Movement_MoveAway
	waitmovement 0
	release
	end

FortreeGymNew_Movement_GuardFacesYou:
	face_right
	step_end

FortreeGymNew_Movement_YouFaceGuard:
	face_left
	step_end

FortreeGymNew_Movement_MoveAway:
	walk_up
	step_end

FortreeGymNew_Movement_IntoGym:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

FortreeGymNew_EventScript_CantStopNow::
	lock
	msgbox FortreeGymNew_Text_CantStopNow, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, FortreeGymNew_Movement_CantStopChallenge
	waitmovement 0
	release
	end

FortreeGymNew_Movement_CantStopChallenge:
	walk_left
	step_end

FortreeGymNew_EventScript_Everest::
    trainerbattle_single TRAINER_P_EVEREST, FortreeGymNew_Text_EverestIntro, FortreeGymNew_Text_EverestDefeated
    msgbox FortreeGymNew_Text_EverestPostBattle, MSGBOX_AUTOCLOSE
    end

FortreeGymNew_EventScript_Lhotse::
    trainerbattle_single TRAINER_P_LHOTSE, FortreeGymNew_Text_LhotseIntro, FortreeGymNew_Text_LhotseDefeated
    msgbox FortreeGymNew_Text_LhotsePostBattle, MSGBOX_AUTOCLOSE
    end

FortreeGymNew_EventScript_Denali::
    trainerbattle_single TRAINER_P_DENALI, FortreeGymNew_Text_DenaliIntro, FortreeGymNew_Text_DenaliDefeated
    msgbox FortreeGymNew_Text_DenaliPostBattle, MSGBOX_AUTOCLOSE
    end

FortreeGymNew_EventScript_Rainier::
    trainerbattle_single TRAINER_P_RAINIER, FortreeGymNew_Text_RainierIntro, FortreeGymNew_Text_RainierDefeated
    msgbox FortreeGymNew_Text_RainierPostBattle, MSGBOX_AUTOCLOSE
    end

FortreeGymNew_EventScript_Fuji::
    trainerbattle_single TRAINER_P_FUJI, FortreeGymNew_Text_FujiIntro, FortreeGymNew_Text_FujiDefeated
    msgbox FortreeGymNew_Text_FujiPostBattle, MSGBOX_AUTOCLOSE
    end

FortreeGymNew_Text_EverestIntro:
	.string "intro$"

FortreeGymNew_Text_EverestDefeated:
	.string "defeat$"

FortreeGymNew_Text_EverestPostBattle:
	.string "post$"

FortreeGymNew_Text_LhotseIntro:
	.string "intro$"

FortreeGymNew_Text_LhotseDefeated:
	.string "defeat$"

FortreeGymNew_Text_LhotsePostBattle:
	.string "post$"

FortreeGymNew_Text_DenaliIntro:
	.string "intro$"

FortreeGymNew_Text_DenaliDefeated:
	.string "defeat$"

FortreeGymNew_Text_DenaliPostBattle:
	.string "post$"

FortreeGymNew_Text_RainierIntro:
	.string "intro$"

FortreeGymNew_Text_RainierDefeated:
	.string "defeat$"

FortreeGymNew_Text_RainierPostBattle:
	.string "post$"

FortreeGymNew_Text_FujiIntro:
	.string "intro$"

FortreeGymNew_Text_FujiDefeated:
	.string "defeat$"

FortreeGymNew_Text_FujiPostBattle:
	.string "post$"

FortreeGymNew_Text_AreYouReady:
	.string "Welcome to the\n"
	.string "Fortree Gym, challenger.\p"
	.string "We are prepared to receive you.\p"
	.string "However, please be warned that upon\n"
	.string "entry, you will be unable to leave the\l"
	.string "Gym unless your entire\l"
	.string "Pokémon party faints.\p"
	.string "Knowing all this, do you feel that you\n"
	.string "are adequately prepared to\l"
	.string "challenge this gym?$"

FortreeGymNew_Text_ThenGoPrepare:
	.string "That's perfectly fine.\n"
	.string "Please do come back when you are ready.$"

FortreeGymNew_Text_TimeForGym:
	.string "Good luck, challenger.$"

FortreeGymNew_Text_YouAlreadyDidThis:
	.string "You appear to already possess the\n"
	.string "Horizon Badge.\p"
	.string "Apologies, but this challenge is only\n"
	.string "for those lacking said badge.$"

FortreeGymNew_Text_CantStopNow:
	.string "(No going back now.)$"
