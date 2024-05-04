.set LOCALID_RAY, 1

Route122_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnTransition
	.byte 0

Route122_OnTransition:
	call_if_gt VAR_RAY_STATE, 1, Route122_EventScript_SetTempFlags
	end

Route122_EventScript_SetTempFlags::
	setflag FLAG_TEMP_11
	removeobject LOCALID_RAY
	return

Route122_EventScript_RayEncounterWest::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route122_Movement_RayEncounterWest
	applymovement LOCALID_RAY, Route122_Movement_RaySquaresUp
	waitmovement 0
	goto Route122_EventScript_RayBattleStart
	release
	end

Route122_Movement_RayEncounterWest:
	walk_up
	walk_right
	face_up
	step_end

Route122_Movement_RaySquaresUp:
	walk_down
	walk_down
	walk_down
	emote_exclamation_mark
	delay_16
	delay_8
	walk_fast_down
	walk_fast_left
	face_down
	step_end

Route122_EventScript_RayEncounterEast::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route122_Movement_RayEncounterEast
	applymovement LOCALID_RAY, Route122_Movement_RaySquaresUp
	waitmovement 0
	goto Route122_EventScript_RayBattleStart
	release
	end

Route122_Movement_RayEncounterEast:
	walk_up
	step_end

Route122_EventScript_RayBattleStart::
	trainerbattle_single TRAINER_P_RAY_2, Route122_Text_RayIntro, Route122_Text_RayDefeat, Route122_EventScript_RayLeaves
	release
	end

Route122_EventScript_RayLeaves::
	msgbox Route122_Text_RayLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAY, Route122_Movement_RayLeaves
	waitmovement 0
	removeobject LOCALID_RAY
	setflag FLAG_TEMP_11
	setvar VAR_RAY_STATE, 2
	release
	end

Route122_Movement_RayLeaves:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

Route122_Text_RayIntro:
	.string "Let's tussle!!$"

Route122_Text_RayDefeat:
	.string "Are you KIDDING me!?$"

Route122_Text_RayLeaves:
	.string "I'll make sure of THAT!$"
