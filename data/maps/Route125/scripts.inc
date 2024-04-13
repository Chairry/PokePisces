.set LOCALID_EGGNEGGMA1, 17
.set LOCALID_EGGNEGGMA2, 14
.set LOCALID_EGGNEGGMA3, 15
.set LOCALID_EGGNEGGMA4, 16
.set LOCALID_BIRDWATCHER, 8
.set LOCALID_EGGLIKERMAN, 18
.set LOCALID_EGGLIKERLADY, 19

Route125_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route125_OnTransition
	.byte 0

Route125_OnTransition:
	call Route125_EventScript_SetEggState
	goto_if_unset FLAG_DEFEATED_PANIC_EVENT, Route125_EventScript_SurferBlocking
	end

Route125_EventScript_SetEggState::
	goto_if_set FLAG_TRAP_PRECIPIKE_EGGNEGGMA, Route125_EventScript_CaptureEggneggmaState
	goto_if_set FLAG_PRECIPIKE_EGG, Route125_EventScript_EggGotten
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	return

Route125_EventScript_CaptureEggneggmaState::
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	return

Route125_EventScript_EggGotten::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setvar VAR_TEMP_4, 5
	return

Route125_EventScript_SurferBlocking::
	setflag FLAG_TEMP_17
	end

Route125_EventScript_LeftRoadblocker::
	lock
	goto_if_set FLAG_DEFEATED_PANIC_EVENT, Route125_EventScript_LeftRoadblockerPost
	msgbox Route125_Text_Left_1, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_LeftRoadblockerPost::
	msgbox Route125_Text_Left_2, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_RightRoadblocker::
	lock
	goto_if_set FLAG_DEFEATED_PANIC_EVENT, Route125_EventScript_RightRoadblockerPost
	msgbox Route125_Text_Right_1, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_RightRoadblockerPost::
	faceplayer
	msgbox Route125_Text_Right_2, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_EggEncounter1South::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA1, Route125_Movement_EggRunAway1South
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA1
	setflag FLAG_TEMP_11
	clearflag FLAG_TEMP_12
	setvar VAR_TEMP_4, 1
	release
	end

Route125_Movement_EggRunAway1South:
	emote_exclamation_mark
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route125_EventScript_EggEncounter1North::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA1, Route125_Movement_EggRunAway1North
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA1
	setflag FLAG_TEMP_11
	clearflag FLAG_TEMP_14
	setvar VAR_TEMP_4, 3
	release
	end

Route125_Movement_EggRunAway1North:
	emote_exclamation_mark
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route125_EventScript_EggEncounter2East::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA2, Route125_Movement_EggRunAway2East
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA2
	setflag FLAG_TEMP_12
	clearflag FLAG_TEMP_13
	setvar VAR_TEMP_4, 2
	release
	end

Route125_Movement_EggRunAway2East:
	emote_exclamation_mark
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route125_EventScript_EggEncounter2WestTop::
	lock
	goto_if_set FLAG_TRAP_PRECIPIKE_EGGNEGGMA, Route125_EventScript_EggEncounterTrapTop
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA2, Route125_Movement_EggRunAway2West
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA2
	setflag FLAG_TEMP_12
	clearflag FLAG_TEMP_11
	setvar VAR_TEMP_4, 0
	release
	end

Route125_Movement_EggRunAway2West:
	emote_exclamation_mark
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route125_EventScript_EggEncounter2WestBottom::
	lock
	goto_if_set FLAG_TRAP_PRECIPIKE_EGGNEGGMA, Route125_EventScript_EggEncounterTrapBottom
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA2, Route125_Movement_EggRunAway2West
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA2
	setflag FLAG_TEMP_12
	clearflag FLAG_TEMP_11
	setvar VAR_TEMP_4, 0
	release
	end

Route125_EventScript_EggEncounter3North::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA3, Route125_Movement_EggRunAway3North
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA3
	setflag FLAG_TEMP_13
	clearflag FLAG_TEMP_14
	setvar VAR_TEMP_4, 3
	release
	end

Route125_Movement_EggRunAway3North:
	emote_exclamation_mark
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route125_EventScript_EggEncounter3South::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA3, Route125_Movement_EggRunAway3South
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA3
	setflag FLAG_TEMP_13
	clearflag FLAG_TEMP_12
	setvar VAR_TEMP_4, 1
	release
	end

Route125_Movement_EggRunAway3South:
	emote_exclamation_mark
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route125_EventScript_EggEncounter4West::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA4, Route125_Movement_EggRunAway4West
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA4
	setflag FLAG_TEMP_14
	clearflag FLAG_TEMP_11
	setvar VAR_TEMP_4, 0
	release
	end

Route125_Movement_EggRunAway4West:
	emote_exclamation_mark
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route125_EventScript_EggEncounter4East::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA4, Route125_Movement_EggRunAway4East
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA4
	setflag FLAG_TEMP_14
	clearflag FLAG_TEMP_13
	setvar VAR_TEMP_4, 2
	release
	end

Route125_Movement_EggRunAway4East:
	emote_exclamation_mark
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route125_EventScript_EggEncounterTrapTop::
	applymovement OBJ_EVENT_ID_PLAYER, Route125_Movement_PlayerGetIntoPos
	goto Route125_EventScript_EggEncounterTrapBottom
	release
	end

Route125_Movement_PlayerGetIntoPos:
	walk_down
	face_right
	step_end

Route125_EventScript_EggEncounterTrapBottom::
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA2, Route125_Movement_EggNervous
	waitmovement 0
	msgbox Route125_Text_WeHaveYouCornered, MSGBOX_DEFAULT
	applymovement LOCALID_EGGLIKERMAN, Route125_Movement_BlockEgg1
	applymovement LOCALID_EGGLIKERLADY, Route125_Movement_BlockEgg2
	applymovement LOCALID_BIRDWATCHER, Route125_Movement_BlockEgg3
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	applymovement LOCALID_EGGNEGGMA2, Route125_Movement_EggUpset
	waitmovement 0
	setflag FLAG_PISCES_D
	clearflag FLAG_TRAP_PRECIPIKE_EGGNEGGMA
	msgbox Route125_Text_GotYouBitch, MSGBOX_DEFAULT
	warp MAP_PRECIPIKE_INTERIORS, 6, 4
	waitstate
	release
	end

Route125_Movement_EggNervous:
	emote_exclamation_mark
	delay_16
	face_left
	step_end

Route125_Movement_BlockEgg1:
	walk_down
	walk_right
	step_end

Route125_Movement_BlockEgg2:
	walk_fast_down
	walk_left
	walk_left
	walk_left
	step_end

Route125_Movement_BlockEgg3:
	walk_left
	walk_left
	step_end

Route125_Movement_EggUpset:
	face_right
	delay_8
	face_left
	delay_8
	face_right
	delay_8
	face_left
	jump_in_place_down
	step_end

Route125_EventScript_Shellylouh::
	lock
	faceplayer
	goto_if_gt VAR_SHELLYLOUH_STATE, 2, Route125_EventScript_ShellRiddle3
	goto_if_eq VAR_SHELLYLOUH_STATE, 2, Route125_EventScript_ShellRiddle2
	goto_if_eq VAR_SHELLYLOUH_STATE, 1, Route125_EventScript_ShellRiddle1
	goto_if_lt VAR_SHELLYLOUH_STATE, 1, Route125_EventScript_SetupShellRiddle1
	release
	end

Route125_EventScript_SetupShellRiddle1::
	setvar VAR_SHELLYLOUH_STATE, 1
	goto Route125_EventScript_ShellRiddle1
	release
	end

Route125_EventScript_ShellRiddle1::
	msgbox Route125_Text_ShellRiddle1, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_ShellRiddle2::
	msgbox Route125_Text_HereIsShellPolish, MSGBOX_DEFAULT
	giveitem ITEM_PEARL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_SHELLYLOUH_STATE, 3
	msgbox Route125_Text_ShellRiddle3, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_ShellRiddle3::
	msgbox Route125_Text_ShellRiddle3, MSGBOX_AUTOCLOSE
	release
	end

Route125_Text_ShellRiddle1:
	.string "secret cave in mossdeep\p"
	.string "bring me polish$"

Route125_Text_HereIsShellPolish:
	.string "have this$"

Route125_Text_ShellRiddle3:
	.string "we shall meet again$"

Route125_Text_WeHaveYouCornered:
	.string "gotcha$"

Route125_Text_Left_1:
	.string "(Two men are locked here in a\n"
	.string "fierce grapple.)\p"
	.string "K-Kushiwara-San…! I WILL NOT…\n"
	.string "FALL… TO YOU…!\p"
	.string "(This seems to be their final battle…)$"

Route125_Text_Right_1:
	.string "(Two men are locked here in a\n"
	.string "fierce grapple.)\p"
	.string "BOKIKOOO…!\p"
	.string "GIVE ME… ALL YOU'VE GOT…!$"
	.string "(This seems to be their final battle…)$"

Route125_Text_Left_2:
	.string "Helloooo…! Up there!\p"
	.string "I won't lose next time…!$"

Route125_Text_Right_2:
	.string "I gave it my all…\n"
	.string "and vanquished my lifelong rival…\p"
	.string "Over… what, you ask?\p"
	.string "He called me a… grrRR…!\n"
	.string "A DOO-DOO HEAD!!$"

Route125_Text_GotYouBitch:
	.string "give us your money$"
