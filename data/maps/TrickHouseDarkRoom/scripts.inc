.set LOCALID_JUMPSCARER, 1

TrickHouseDarkRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TrickHouseDarkRoom_OnLoad
	.byte 0

TrickHouseDarkRoom_OnLoad:
	call TrickHouseDarkRoom_EventScript_RemoveDemolitionist
	call TrickHouseDarkRoom_EventScript_SetFlashLevel
	call_if_set FLAG_DEFEATED_ANTON, TrickHouseDarkRoom_EventScript_ExplodePart7
	end

TrickHouseDarkRoom_EventScript_ScrollC::
	lock
	msgbox TrickHouseDarkRoom_Text_ScrollC, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseDarkRoom_EventScript_RemoveDemolitionist::
	removeobject LOCALID_JUMPSCARER
	setflag FLAG_TEMP_5
	return

TrickHouseDarkRoom_EventScript_SetFlashLevel::
	setflashlevel 1
	return

TrickHouseDarkRoom_EventScript_DemoTrigger::
	lock
	goto_if_gt VAR_TEMP_6, 0, TrickHouseDarkRoom_EventScript_DemoJumpscare
	addvar VAR_TEMP_6, 1
	release
	end

TrickHouseDarkRoom_EventScript_DemoJumpscare::
	lockall
	playse SE_FALL
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseDarkRoom_Movement_NoticeFall
	clearflag FLAG_TEMP_5
	addobject LOCALID_JUMPSCARER
	applymovement LOCALID_JUMPSCARER, TrickHouseDarkRoom_Movement_FallIn
	waitmovement 0
	playse SE_LAVARIDGE_FALL_WARP
	waitse
	applymovement LOCALID_JUMPSCARER, TrickHouseDarkRoom_Movement_Challenge
	waitmovement 0
	trainerbattle_single TRAINER_P_ANTON, TrickHouseDarkRoom_Text_AntonIntro, TrickHouseDarkRoom_Text_AntonDefeated, TrickHouseDarkRoom_EventScript_Explosion
	releaseall
	end

TrickHouseDarkRoom_Movement_NoticeFall:
	face_right
	emote_exclamation_mark
	step_end

TrickHouseDarkRoom_Movement_FallIn:
	jump_2_down
	step_end

TrickHouseDarkRoom_Movement_Challenge:
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

TrickHouseDarkRoom_EventScript_Explosion::
	msgbox TrickHouseDarkRoom_Text_AntonBlowUp, MSGBOX_DEFAULT
	applymovement LOCALID_JUMPSCARER, TrickHouseDarkRoom_Movement_ReadyToBlow
	waitmovement 0
	removeobject LOCALID_JUMPSCARER
	setflag FLAG_TEMP_5
	call TrickHouseDarkRoom_EventScript_ExplodePart1
	call TrickHouseDarkRoom_EventScript_ExplodePart2
	call TrickHouseDarkRoom_EventScript_ExplodePart3
	call TrickHouseDarkRoom_EventScript_ExplodePart4
	call TrickHouseDarkRoom_EventScript_ExplodePart5
	call TrickHouseDarkRoom_EventScript_ExplodePart6
	call TrickHouseDarkRoom_EventScript_ExplodePart7
	setflag FLAG_DEFEATED_ANTON
	releaseall
	end

TrickHouseDarkRoom_Movement_ReadyToBlow:
	walk_in_place_faster_left
	walk_in_place_faster_right
	walk_in_place_faster_left
	walk_in_place_faster_right
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

TrickHouseDarkRoom_EventScript_ExplodePart1::
	setmetatile 6, 2, METATILE_TrickHouseNew_Explosion1x6y2, TRUE
	setmetatile 6, 3, METATILE_TrickHouseNew_Explosion1x6y3, TRUE
	setmetatile 7, 1, METATILE_TrickHouseNew_Explosion1x7y1, TRUE
	setmetatile 7, 2, METATILE_TrickHouseNew_Explosion1x7y2, TRUE
	setmetatile 7, 3, METATILE_TrickHouseNew_Explosion1x7y3, TRUE
	setmetatile 8, 1, METATILE_TrickHouseNew_Explosion1x8y1, TRUE
	setmetatile 8, 2, METATILE_TrickHouseNew_Explosion1x8y2, TRUE
	setmetatile 8, 3, METATILE_TrickHouseNew_Explosion1x8y3, TRUE
	special DrawWholeMapView
	playse SE_M_EXPLOSION
	delay 4
	return

TrickHouseDarkRoom_EventScript_ExplodePart2::
	setmetatile 6, 1, METATILE_TrickHouseNew_Explosion2x6y1, TRUE
	setmetatile 6, 2, METATILE_TrickHouseNew_Explosion2x6y2, TRUE
	setmetatile 6, 3, METATILE_TrickHouseNew_Explosion2x6y3, TRUE
	setmetatile 7, 0, METATILE_TrickHouseNew_Explosion2x7y0, TRUE
	setmetatile 7, 1, METATILE_TrickHouseNew_Explosion2x7y1, TRUE
	setmetatile 7, 2, METATILE_TrickHouseNew_Explosion2x7y2, TRUE
	setmetatile 7, 3, METATILE_TrickHouseNew_Explosion2x7y3, TRUE
	setmetatile 8, 0, METATILE_TrickHouseNew_Explosion2x8y0, TRUE
	setmetatile 8, 1, METATILE_TrickHouseNew_Explosion2x8y1, TRUE
	setmetatile 8, 2, METATILE_TrickHouseNew_Explosion2x8y2, TRUE
	setmetatile 8, 3, METATILE_TrickHouseNew_Explosion2x8y3, TRUE
	special DrawWholeMapView
	delay 4
	return

TrickHouseDarkRoom_EventScript_ExplodePart3::
	setmetatile 6, 0, METATILE_TrickHouseNew_InsideBlastHoleTopLeft, TRUE
	setmetatile 6, 1, METATILE_TrickHouseNew_Explosion3x6y1, TRUE
	setmetatile 6, 2, METATILE_TrickHouseNew_Explosion3x6y2, TRUE
	setmetatile 6, 3, METATILE_TrickHouseNew_Explosion3x6y3, TRUE
	setmetatile 7, 0, METATILE_TrickHouseNew_Explosion3x7y0, TRUE
	setmetatile 7, 1, METATILE_TrickHouseNew_Explosion3x7y1, TRUE
	setmetatile 7, 2, METATILE_TrickHouseNew_Explosion3x7y2, TRUE
	setmetatile 7, 3, METATILE_TrickHouseNew_Explosion3x7y3, TRUE
	setmetatile 8, 0, METATILE_TrickHouseNew_Explosion3x8y0, TRUE
	setmetatile 8, 1, METATILE_TrickHouseNew_Explosion3x8y1, TRUE
	setmetatile 8, 2, METATILE_TrickHouseNew_Explosion3x8y2, TRUE
	setmetatile 8, 3, METATILE_TrickHouseNew_Explosion3x8y3, TRUE
	special DrawWholeMapView
	delay 4
	return

TrickHouseDarkRoom_EventScript_ExplodePart4::
	setmetatile 6, 0, METATILE_TrickHouseNew_Explosion4x6y0, TRUE
	setmetatile 6, 1, METATILE_TrickHouseNew_Explosion4x6y1, TRUE
	setmetatile 6, 2, METATILE_TrickHouseNew_Explosion4x6y2, TRUE
	setmetatile 6, 3, METATILE_TrickHouseNew_Explosion4x6y3, TRUE
	setmetatile 7, 0, METATILE_TrickHouseNew_Explosion4x7y0, TRUE
	setmetatile 7, 1, METATILE_TrickHouseNew_Explosion4x7y1, TRUE
	setmetatile 7, 2, METATILE_TrickHouseNew_Explosion4x7y2, TRUE
	setmetatile 7, 3, METATILE_TrickHouseNew_Explosion4x7y3, TRUE
	setmetatile 8, 0, METATILE_TrickHouseNew_Explosion4x8y0, TRUE
	setmetatile 8, 1, METATILE_TrickHouseNew_Explosion4x8y1, TRUE
	setmetatile 8, 2, METATILE_TrickHouseNew_Explosion4x8y2, TRUE
	setmetatile 8, 3, METATILE_TrickHouseNew_Explosion4x8y3, TRUE
	special DrawWholeMapView
	delay 4
	return

TrickHouseDarkRoom_EventScript_ExplodePart5::
	setmetatile 6, 0, METATILE_TrickHouseNew_Explosion5x6y0, TRUE
	setmetatile 6, 1, METATILE_TrickHouseNew_Explosion5x6y1, TRUE
	setmetatile 6, 2, METATILE_TrickHouseNew_Explosion5x6y2, TRUE
	setmetatile 6, 3, METATILE_TrickHouseNew_Explosion5x6y3, TRUE
	setmetatile 7, 0, METATILE_TrickHouseNew_Explosion5x7y0, TRUE
	setmetatile 7, 1, METATILE_TrickHouseNew_Explosion5x7y1, TRUE
	setmetatile 7, 2, METATILE_TrickHouseNew_Explosion5x7y2, TRUE
	setmetatile 7, 3, METATILE_TrickHouseNew_Explosion5x7y3, TRUE
	setmetatile 8, 0, METATILE_TrickHouseNew_Explosion5x8y0, TRUE
	setmetatile 8, 1, METATILE_TrickHouseNew_Explosion5x8y1, TRUE
	setmetatile 8, 2, METATILE_TrickHouseNew_Explosion5x8y2, TRUE
	setmetatile 8, 3, METATILE_TrickHouseNew_FakeCaveFloor, TRUE
	special DrawWholeMapView
	delay 4
	return

TrickHouseDarkRoom_EventScript_ExplodePart6::
	setmetatile 6, 0, METATILE_TrickHouseNew_Explosion6x6y0, TRUE
	setmetatile 6, 1, METATILE_TrickHouseNew_Explosion6x6y1, TRUE
	setmetatile 6, 2, METATILE_TrickHouseNew_Explosion6x6y2, TRUE
	setmetatile 6, 3, METATILE_TrickHouseNew_FakeCaveFloor, TRUE
	setmetatile 7, 0, METATILE_TrickHouseNew_Explosion6x7y0, TRUE
	setmetatile 7, 1, METATILE_TrickHouseNew_Explosion6x7y1, TRUE
	setmetatile 7, 2, METATILE_TrickHouseNew_FakeCaveFloor, TRUE
	setmetatile 7, 3, METATILE_TrickHouseNew_FakeCaveFloor, TRUE
	setmetatile 8, 0, METATILE_TrickHouseNew_InsideBlastHoleTopRight, TRUE
	setmetatile 8, 1, METATILE_TrickHouseNew_InsideBlastHoleRight, TRUE
	setmetatile 8, 2, METATILE_TrickHouseNew_FakeCaveFloor, TRUE
	setmetatile 8, 3, METATILE_TrickHouseNew_FakeCaveFloor, TRUE
	special DrawWholeMapView
	delay 4
	return

TrickHouseDarkRoom_EventScript_ExplodePart7::
	setmetatile 6, 0, METATILE_TrickHouseNew_InsideBlastHoleTopLeft, TRUE
	setmetatile 6, 1, METATILE_TrickHouseNew_InsideBlastHoleLeft, TRUE
	setmetatile 6, 2, METATILE_TrickHouseNew_FakeCaveFloor, FALSE
	setmetatile 6, 3, METATILE_TrickHouseNew_FakeCaveFloor, FALSE
	setmetatile 7, 0, METATILE_TrickHouseNew_InsideBlastHoleTopMiddle, TRUE
	setmetatile 7, 1, METATILE_TrickHouseNew_InsideBlastHoleMiddle, FALSE
	setmetatile 7, 2, METATILE_TrickHouseNew_FakeCaveFloor, FALSE
	setmetatile 7, 3, METATILE_TrickHouseNew_FakeCaveFloor, FALSE
	setmetatile 8, 0, METATILE_TrickHouseNew_InsideBlastHoleTopRight, TRUE
	setmetatile 8, 1, METATILE_TrickHouseNew_InsideBlastHoleRight, TRUE
	setmetatile 8, 2, METATILE_TrickHouseNew_FakeCaveFloor, FALSE
	setmetatile 8, 3, METATILE_TrickHouseNew_FakeCaveFloor, FALSE
	special DrawWholeMapView
	setvar VAR_TEMP_6, 1
	return

TrickHouseDarkRoom_Text_AntonIntro:
	.string "yo$"

TrickHouseDarkRoom_Text_AntonDefeated:
	.string "uh oh$"

TrickHouseDarkRoom_Text_AntonBlowUp:
	.string "gotta blast$"

TrickHouseDarkRoom_Text_ScrollC:
	.string "(It's a scroll with odd\n"
	.string "handwriting on it...)\p"
	.string "Seeking a number? A hint you get!\n"
	.string "This is the only ODD one in the set!\p"
	.string "- Trick Master is fabulous.$"
