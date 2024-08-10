StevenCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, StevenCorridor_OnTransition
	.byte 0

StevenCorridor_OnTransition:
	call StevenCorridor_EventScript_SetFlashLevel
	end

StevenCorridor_EventScript_SetFlashLevel::
	goto_if_lt VAR_PISCES_STORY_PROGRESS, 2, StevenCorridor_EventScript_DarkRoom
	goto_if_eq VAR_PISCES_STORY_PROGRESS, 2, StevenCorridor_EventScript_BrightRoom
	goto_if_gt VAR_PISCES_STORY_PROGRESS, 2, StevenCorridor_EventScript_BrightRoom

StevenCorridor_EventScript_DarkRoom::
	setflashlevel 6
	return

StevenCorridor_EventScript_BrightRoom::
	setflashlevel 0
	return

StevenCorridor_EventScript_NoBadge2::
	lock
	msgbox StevenCorridor_Text_TooDark, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, StevenCorridor_Movement_BackAway
	release
	end

StevenCorridor_Movement_BackAway:
	walk_down
	step_end

StevenCorridor_EventScript_Steven::
	lock
	faceplayer
	speakername StevenHouse_Text_NameSteven
	goto_if_lt VAR_NEW_COO_STATE, 4, StevenCorridor_EventScript_StevenYesNo
	goto_if_eq VAR_NEW_COO_STATE, 4, StevenCorridor_EventScript_Idle
	speakername NULL
	release
	end

StevenCorridor_EventScript_StevenYesNo::
	msgbox StevenCorridor_Text_AreYouReady, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StevenCorridor_EventScript_StartPanicDojo
	msgbox StevenCorridor_Text_ThenGoPrepare, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

StevenCorridor_EventScript_StartPanicDojo::
	clearflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	cleartrainerflag TRAINER_P_S_STEVEN_1
	cleartrainerflag TRAINER_P_S_STEVEN_2
	cleartrainerflag TRAINER_P_S_STEVEN_3
	cleartrainerflag TRAINER_P_S_STEVEN_4
	cleartrainerflag TRAINER_P_S_STEVEN_5
	cleartrainerflag TRAINER_P_S_STEVEN_6
	msgbox StevenCorridor_Text_LetsBegin, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_STEVEN_MAZE, 12, 26
	waitstate
	release
	end

StevenCorridor_EventScript_Idle::
	msgbox StevenCorridor_Text_Idle, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

StevenCorridor_Text_NameSteven:
	.string "Steven$"

StevenCorridor_Text_TooDark:
	.string "(It's very dark in this room.\n"
	.string "Best to turn back.)$"

StevenCorridor_Text_AreYouReady:
	.string "Welcome back, {PLAYER}.\p"
	.string "I assume you are expecting something\n"
	.string "from me, now that your eyes can pierce\l"
	.string "the darkness.\p"
	.string "Well, then, let me ask you\n"
	.string "this question.\p"
	.string "Is your team prepared?$"

StevenCorridor_Text_ThenGoPrepare:
	.string "I see.\p"
	.string "Please get them ready, then return.$"

StevenCorridor_Text_LetsBegin:
	.string "(Steven closes his eyes and smiles.)\p"
	.string "Think fast.$"

StevenCorridor_Text_Idle:
	.string "No room in this world for spinning\n"
	.string "your wheels, {PLAYER}.\p"
	.string "The path to your next badge should be\n"
	.string "taking you northwards from Mossdeep.\p"
	.string "Never stop improving.$"
