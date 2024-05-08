.set LOCALID_GYMGUARD, 1

Gym2Corridor_MapScripts::
	.byte 0

Gym2Corridor_EventScript_DoorGuard::
	lock
	goto_if_eq VAR_PISCES_STORY_PROGRESS, 1, Gym2Corridor_EventScript_WantToGoIn
	goto_if_gt VAR_PISCES_STORY_PROGRESS, 1, Gym2Corridor_EventScript_CantGoIn
	release
	end

Gym2Corridor_EventScript_WantToGoIn::
	applymovement LOCALID_GYMGUARD, Gym2Corridor_Movement_GuardFacesYou
	applymovement OBJ_EVENT_ID_PLAYER, Gym2Corridor_Movement_YouFaceGuard
	msgbox Gym2Corridor_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Gym2Corridor_EventScript_PrepForGym
	applymovement OBJ_EVENT_ID_PLAYER, Gym2Corridor_Movement_MoveAway
	waitmovement 0
	msgbox Gym2Corridor_Text_ThenGoPrepare, MSGBOX_AUTOCLOSE
	release
	end

Gym2Corridor_EventScript_PrepForGym::
	clearflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	cleartrainerflag TRAINER_P_PLANCK
	cleartrainerflag TRAINER_P_LEGRI
	cleartrainerflag TRAINER_P_SPITZER
	cleartrainerflag TRAINER_P_TESS
	cleartrainerflag TRAINER_P_HITOMI
	msgbox Gym2Corridor_Text_TimeForGym, MSGBOX_DEFAULT
	warp MAP_MOSSDEEP_CITY_GYM, 30, 26
	waitstate
	release
	end

Gym2Corridor_EventScript_CantGoIn::
	applymovement LOCALID_GYMGUARD, Gym2Corridor_Movement_GuardFacesYou
	applymovement OBJ_EVENT_ID_PLAYER, Gym2Corridor_Movement_YouFaceGuard
	msgbox Gym2Corridor_Text_YouAlreadyDidThis, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Gym2Corridor_Movement_MoveAway
	waitmovement 0
	release
	end

Gym2Corridor_Movement_GuardFacesYou:
	face_right
	step_end

Gym2Corridor_Movement_YouFaceGuard:
	face_left
	step_end

Gym2Corridor_Movement_MoveAway:
	walk_down
	step_end

Gym2Corridor_Text_AreYouReady:
	.string "Welcome to the\n"
	.string "Mossdeep Gym, challenger.\p"
	.string "We are prepared to receive you.\p"
	.string "However, please be warned that upon\n"
	.string "entry, you will be unable to leave the\l"
	.string "Gym unless your entire\l"
	.string "Pokémon party faints.\p"
	.string "Knowing all this, do you feel that you\n"
	.string "are adequately prepared to\l"
	.string "challenge this gym?$"

Gym2Corridor_Text_ThenGoPrepare:
	.string "That's perfectly fine.\n"
	.string "Please do come back when you are ready.$"

Gym2Corridor_Text_TimeForGym:
	.string "Good luck, challenger.$"

Gym2Corridor_Text_YouAlreadyDidThis:
	.string "You appear to already possess the\n"
	.string "Serene Badge.\p"
	.string "Apologies, but this challenge is only\n"
	.string "for those lacking said badge.$"
