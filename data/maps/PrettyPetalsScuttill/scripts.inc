.set LOCALID_COURTNEY, 1
.set LOCALID_SISTER1, 2
.set LOCALID_SISTER2, 3
.set LOCALID_SISTER3, 4
.set LOCALID_SISTER1POST, 5
.set LOCALID_SISTER2POST, 7
.set LOCALID_SISTER3POST, 6

PrettyPetalsScuttill_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PrettyPetalsScuttill_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PrettyPetalsScuttill_OnFrame
	.byte 0

PrettyPetalsScuttill_OnFrame:
	map_script_2 VAR_OZONE_ADMINS_STATE, 3, PrettyPetalsScuttill_EventScript_BloomingEvent
	.2byte 0

PrettyPetalsScuttill_OnLoad:
	call_if_le VAR_OZONE_ADMINS_STATE, 3, PrettyPetalsScuttill_EventScript_SetSistersFlagsPre
	call_if_gt VAR_OZONE_ADMINS_STATE, 3, PrettyPetalsScuttill_EventScript_SetSistersFlagsPost
	end

PrettyPetalsScuttill_EventScript_SetSistersFlagsPre::
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	removeobject LOCALID_SISTER1POST
	removeobject LOCALID_SISTER2POST
	removeobject LOCALID_SISTER3POST
	return

PrettyPetalsScuttill_EventScript_SetSistersFlagsPost::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	removeobject LOCALID_COURTNEY
	removeobject LOCALID_SISTER1
	removeobject LOCALID_SISTER2
	removeobject LOCALID_SISTER3
	return

PrettyPetalsScuttill_EventScript_BloomingEvent::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, PrettyPetalsScuttill_Movement_WalkIn
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyGreet
	waitmovement 0
	msgbox PrettyPetalsScuttill_Text_ComeJoinOurLesson, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, PrettyPetalsScuttill_Movement_PlayerMoveToPos
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyMoveToPos
	waitmovement 0
	msgbox PrettyPetalsScuttill_Text_TeachingAboutBloom, MSGBOX_DEFAULT
	applymovement LOCALID_SISTER1, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Natalie1, MSGBOX_DEFAULT
	applymovement LOCALID_SISTER3, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Nicole1, MSGBOX_DEFAULT
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyTalk
	msgbox PrettyPetalsScuttill_Text_Courtney1, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_JUAN, PrettyPetalsScuttill_Text_NatalieDefeat, TRAINER_P_SEBASTIAN, PrettyPetalsScuttill_Text_NicoleDefeat, PrettyPetalsScuttill_EventScript_NatalieNicoleDefeated, NO_MUSIC
	goto PrettyPetalsScuttill_EventScript_NatalieNicoleDefeated
	release
	end

PrettyPetalsScuttill_Movement_WalkIn:
	walk_up
	walk_up
	step_end

PrettyPetalsScuttill_Movement_CourtneyGreet:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

PrettyPetalsScuttill_Movement_PlayerMoveToPos:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_up
	step_end

PrettyPetalsScuttill_Movement_CourtneyMoveToPos:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

PrettyPetalsScuttill_Movement_SisterTalk:
	walk_in_place_down
	step_end

PrettyPetalsScuttill_Movement_CourtneyTalk:
	walk_in_place_right
	step_end

PrettyPetalsScuttill_EventScript_NatalieNicoleDefeated::
	lock
	applymovement LOCALID_SISTER2, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Rita1, MSGBOX_DEFAULT
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyTalk
	msgbox PrettyPetalsScuttill_Text_Courtney2, MSGBOX_DEFAULT
	applymovement LOCALID_SISTER2, PrettyPetalsScuttill_Movement_SisterTalk
	waitmovement 0
	trainerbattle_single TRAINER_P_PANDOU_1, PrettyPetalsScuttill_Text_RitaIntro, PrettyPetalsScuttill_Text_RitaDefeat, PrettyPetalsScuttill_EventScript_BloomingEventDone
	goto PrettyPetalsScuttill_EventScript_BloomingEventDone
	release
	end

PrettyPetalsScuttill_EventScript_BloomingEventDone::
	lock
	applymovement LOCALID_SISTER1, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Natalie2, MSGBOX_DEFAULT
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyTalk
	msgbox PrettyPetalsScuttill_Text_Courtney3, MSGBOX_DEFAULT
	setvar VAR_OZONE_ADMINS_STATE, 4
	release
	end

PrettyPetalsScuttill_Text_ComeJoinOurLesson:
	.string "come join the lesson$"

PrettyPetalsScuttill_Text_TeachingAboutBloom:
	.string "today we are talkin bou bloom$"

PrettyPetalsScuttill_Text_Natalie1:
	.string "natalie 1$"

PrettyPetalsScuttill_Text_Nicole1:
	.string "nicole 1$"

PrettyPetalsScuttill_Text_Courtney1:
	.string "courtney 1$"

PrettyPetalsScuttill_Text_NatalieDefeat:
	.string "natalie defeat$"

PrettyPetalsScuttill_Text_NicoleDefeat:
	.string "nicole defeat$"

PrettyPetalsScuttill_Text_Rita1:
	.string "rita 1$"

PrettyPetalsScuttill_Text_Courtney2:
	.string "courtney 2$"

PrettyPetalsScuttill_Text_RitaIntro:
	.string "rita 2$"

PrettyPetalsScuttill_Text_RitaDefeat:
	.string "rita defeat$"

PrettyPetalsScuttill_Text_Natalie2:
	.string "natalie 2$"

PrettyPetalsScuttill_Text_Courtney3:
	.string "courtney 3$"
