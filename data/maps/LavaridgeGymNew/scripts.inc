.set LOCALID_FLANNERY, 1
.set LOCALID_MOORE, 6
.set LOCALID_HEDORAH, 4
.set LOCALID_GHIDORAH, 3
.set LOCALID_GOJIRA, 2
.set LOCALID_GAMERA, 5

LavaridgeGymNew_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeGymNew_OnFrame
	.byte 0

LavaridgeGymNew_OnFrame:
	map_script_2 VAR_TEMP_7, 0, LavaridgeGymNew_EventScript_Interrogation
	.2byte 0

LavaridgeGymNew_EventScript_Interrogation::
	lock
	setvar VAR_TEMP_7, 1
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_SetInvis
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_SetInvis
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeGymNew_Movement_FaceUp
	waitmovement 0
	msgbox LavaridgeGymNew_Text_Gojira1, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeGymNew_Movement_PlayerWalkToTable
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_GojiraWalkToTable
	waitmovement 0
	msgbox LavaridgeGymNew_Text_Gojira2, MSGBOX_DEFAULT
	msgbox LavaridgeGymNew_Text_WhatDoForLiving, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_1, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_StudyPokemon
	case 1, LavaridgeGymNew_EventScript_TasteTestSoup
	case 2, LavaridgeGymNew_EventScript_Cop
	closemessage
	release
	end

LavaridgeGymNew_EventScript_StudyPokemon::
	setflag FLAG_TEMP_1
	msgbox LavaridgeGymNew_Text_SoYouStudyPokemon, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_TasteTestSoup::
	setflag FLAG_TEMP_2
	msgbox LavaridgeGymNew_Text_SoYouTasteTestSoup, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_Cop::
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_ShockAtCop
	msgbox LavaridgeGymNew_Text_GetOutDirtyCop, MSGBOX_DEFAULT
	warp MAP_LAVARIDGE_INT, 23, 11
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart2::
	msgbox LavaridgeGymNew_Text_SmallTalk, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_FaceRight
	msgbox LavaridgeGymNew_Text_HoldOnHere, MSGBOX_DEFAULT
	applymovement LOCALID_GHIDORAH, LavaridgeGymNew_Movement_GhidorahAccost
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahAccost
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WeWannaBattle, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_GHIDORAH, LavaridgeGymNew_Text_GhidorahDefeat, TRAINER_P_HEDORAH, LavaridgeGymNew_Text_HedorahDefeat, LavaridgeGymNew_EventScript_InterrogationPart3, NO_MUSIC
	goto LavaridgeGymNew_EventScript_InterrogationPart3
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart3::
	release
	end

LavaridgeGymNew_Movement_GhidorahAccost:
	delay_4
	jump_2_left
	walk_left
	walk_left
	step_end

LavaridgeGymNew_Movement_HedorahAccost:
	jump_2_left
	jump_2_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	face_right
	step_end

LavaridgeGymNew_Movement_FaceRight:
	face_right
	step_end

LavaridgeGymNew_Movement_ShockAtCop:
	emote_exclamation_mark
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

LavaridgeGymNew_Movement_SetInvis:
	set_invisible
	step_end

LavaridgeGymNew_Movement_FaceUp:
	face_up
	step_end

LavaridgeGymNew_Movement_PlayerWalkToTable:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	face_down
	step_end

LavaridgeGymNew_Movement_GojiraWalkToTable:
	delay_16
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	walk_up
	face_left
	step_end

LavaridgeGymNew_Text_Gojira1:
	.string "Gojira 1$"

LavaridgeGymNew_Text_Gojira2:
	.string "Gojira 2$"

LavaridgeGymNew_Text_WhatDoForLiving:
	.string "What do 4 livin$"

LavaridgeGymNew_Text_SoYouStudyPokemon:
	.string "so u study pokes$"

LavaridgeGymNew_Text_SoYouTasteTestSoup:
	.string "so u taste test soup$"

LavaridgeGymNew_Text_GetOutDirtyCop:
	.string "get out fucker$"

LavaridgeGymNew_Text_SmallTalk:
	.string "small talk$"

LavaridgeGymNew_Text_HoldOnHere:
	.string "hold da heck on$"

LavaridgeGymNew_Text_WeWannaBattle:
	.string "battle time$"

LavaridgeGymNew_Text_GhidorahDefeat:
	.string "Ghid defeat$"

LavaridgeGymNew_Text_HedorahDefeat:
	.string "Hed defeat$"

