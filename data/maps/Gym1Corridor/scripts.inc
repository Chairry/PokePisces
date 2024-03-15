.set LOCALID_GYMGUARD, 1

Gym1Corridor_MapScripts::
	.byte 0

Gym1Corridor_EventScript_DoorGuard::
	lockall
	goto_if_eq VAR_PISCES_STORY_PROGRESS, 0, Gym1Corridor_EventScript_WantToGoIn
	goto_if_gt VAR_PISCES_STORY_PROGRESS, 0, Gym1Corridor_EventScript_CantGoIn
	releaseall
	end

Gym1Corridor_EventScript_WantToGoIn::
	msgbox Gym1Corridor_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Gym1Corridor_EventScript_PrepForGym
	applymovement OBJ_EVENT_ID_PLAYER, Gym1Corridor_Movement_MoveAway
	msgbox Gym1Corridor_Text_ThenGoPrepare, MSGBOX_AUTOCLOSE
	releaseall
	end

Gym1Corridor_EventScript_PrepForGym::
	setflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	cleartrainerflag TRAINER_P_ARTHUR
	cleartrainerflag TRAINER_P_HASPAROTH
	cleartrainerflag TRAINER_P_LISA
	cleartrainerflag TRAINER_P_MIIKACHAN
	cleartrainerflag TRAINER_P_EMILY
	msgbox Gym1Corridor_Text_TimeForGym, MSGBOX_DEFAULT
	warp MAP_SOOTOPOLIS_CITY_GYM_B1F, 1, 18
	waitstate
	releaseall
	end

Gym1Corridor_EventScript_CantGoIn::
	applymovement LOCALID_GYMGUARD, Gym1Corridor_Movement_GuardFacesYou
	applymovement OBJ_EVENT_ID_PLAYER, Gym1Corridor_Movement_YouFaceGuard
	msgbox Gym1Corridor_Text_YouAlreadyDidThis, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Gym1Corridor_Movement_MoveAway
	releaseall
	end

Gym1Corridor_Movement_GuardFacesYou:
	face_right
	step_end

Gym1Corridor_Movement_YouFaceGuard:
	face_left
	step_end

Gym1Corridor_Movement_MoveAway:
	walk_down
	step_end

Gym1Corridor_Text_AreYouReady:
	.string "you ready for this?$"

Gym1Corridor_Text_ThenGoPrepare:
	.string "then why u here$"

Gym1Corridor_Text_TimeForGym:
	.string "time for da gym dood$"

Gym1Corridor_Text_YouAlreadyDidThis:
	.string "cant do it twice dipshint$"
