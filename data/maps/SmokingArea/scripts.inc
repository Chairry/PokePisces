.set LOCALID_P_MAN, 5
.set LOCALID_STORYTELLER, 1
.set LOCALID_BONDING, 6

SmokingArea_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SmokingArea_OnLoad
	.byte 0

SmokingArea_OnLoad:
	call_if_eq VAR_OLD_GUYS_STATE, 17, SmokingArea_EventScript_SetStorytellerGfx
	call_if_lt VAR_OLD_GUYS_STATE, 17, SmokingArea_EventScript_RemoveStoryteller
	call_if_gt VAR_OLD_GUYS_STATE, 17, SmokingArea_EventScript_RemoveStoryteller
	call SmokingArea_EventScript_RemoveKizuna
	end

SmokingArea_EventScript_SetStorytellerGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_STORYTELLER
	special SetMauvilleOldManObjEventGfx
	return

SmokingArea_EventScript_RemoveStoryteller::
	removeobject LOCALID_STORYTELLER
	setflag FLAG_TEMP_12
	return

SmokingArea_EventScript_RemoveKizuna::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	removeobject LOCALID_BONDING
	setflag FLAG_TEMP_13
	return

SmokingArea_EventScript_Storyteller::
	lock
	faceplayer
	msgbox SmokingArea_Text_IAmTheStoryteller, MSGBOX_DEFAULT
	closemessage
	delay 32
	clearflag FLAG_TEMP_11
	addobject LOCALID_P_MAN
	playse SE_DOOR
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, SmokingArea_Movement_PlayerMoveOutOfWay
	applymovement LOCALID_P_MAN, SmokingArea_Movement_KizunaEnters
	waitmovement 0
	speakername SmokingArea_Text_NameKizuna
	msgbox SmokingArea_Text_YoureTheLastGuy, MSGBOX_DEFAULT
	speakername SmokingArea_Text_NameStoryteller
	msgbox SmokingArea_Text_LetMeTellMyStory, MSGBOX_DEFAULT
	fadenewbgm MUS_VERDANTURF
	msgbox SmokingArea_Text_MauvilleStory, MSGBOX_DEFAULT
	fadenewbgm MUS_NONE
	speakername SmokingArea_Text_NameKizuna
	msgbox SmokingArea_Text_ISee, MSGBOX_DEFAULT
	speakername SmokingArea_Text_NameStoryteller
	msgbox SmokingArea_Text_TimeToRetire, MSGBOX_DEFAULT
	closemessage
	playse SE_M_MEGA_KICK
	applymovement LOCALID_P_MAN, SmokingArea_Movement_KizunaAbsorbST
	waitmovement 0
	removeobject LOCALID_STORYTELLER
	setflag FLAG_TEMP_12
	playse SE_M_FAINT_ATTACK
	waitse
	delay 32
	applymovement LOCALID_P_MAN, SmokingArea_Movement_KizunaWalkUp
	waitmovement 0
	playse SE_BANG
	waitse
	delay 24
	applymovement LOCALID_P_MAN, SmokingArea_Movement_KizunaWalkUp
	waitmovement 0
	playse SE_BANG
	waitse
	delay 24
	applymovement LOCALID_P_MAN, SmokingArea_Movement_KizunaWalkUp
	waitmovement 0
	playse SE_BANG
	waitse
	delay 32
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, SmokingArea_Movement_PlayerConcern
	waitmovement 0
	playse SE_M_MEGA_KICK
	waitse
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	delay 4
	playse SE_SHINY
	clearflag FLAG_TEMP_13
	addobject LOCALID_BONDING
	applymovement LOCALID_BONDING, SmokingArea_Movement_BondingFaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SmokingArea_Movement_PlayerConfused
	waitmovement 0
	speakername SmokingArea_Text_NameKizuna2
	msgbox SmokingArea_Text_IHaveBeenReborn, MSGBOX_DEFAULT
	speakername SmokingArea_Text_NameMrBonding
	msgbox SmokingArea_Text_IndulgeMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BONDING, SmokingArea_Movement_BondingWalkAway
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_BONDING
	setflag FLAG_TEMP_13
	setvar VAR_OLD_GUYS_STATE, 18
	playbgm MUS_NONE, FALSE
	delay 16
	release
	end

SmokingArea_Movement_PlayerMoveOutOfWay:
	delay_16
	face_up
	delay_16
	delay_8
	walk_left
	face_right
	step_end

SmokingArea_Movement_KizunaEnters:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_left
	walk_slow_down
	walk_slow_down
	step_end

SmokingArea_Movement_KizunaAbsorbST:
	walk_slow_down
	face_up
	step_end

SmokingArea_Movement_KizunaWalkUp:
	walk_slow_up
	step_end

SmokingArea_Movement_PlayerConcern:
	walk_right
	face_up
	step_end

SmokingArea_Movement_BondingFaceDown:
	face_down
	step_end

SmokingArea_Movement_PlayerConfused:
	emote_question_mark
	step_end

SmokingArea_Movement_BondingWalkAway:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	step_end

SmokingArea_Text_NameKizuna:
	.string "Kizuna$"

SmokingArea_Text_NameStoryteller:
	.string "Storyteller$"

SmokingArea_Text_NameKizuna2:
	.string "Kizuna?$"

SmokingArea_Text_NameMrBonding:
	.string "Mr. Bonding$"

SmokingArea_Text_IAmTheStoryteller:
	.string "i am storyteller$"

SmokingArea_Text_YoureTheLastGuy:
	.string "you da last guy$"

SmokingArea_Text_LetMeTellMyStory:
	.string "indeed lemme spit$"

SmokingArea_Text_MauvilleStory:
	.string "insert story here$"

SmokingArea_Text_ISee:
	.string "i see$"

SmokingArea_Text_TimeToRetire:
	.string "time 2 retire$"

SmokingArea_Text_IHaveBeenReborn:
	.string "i have reborn$"

SmokingArea_Text_IndulgeMe:
	.string "come fight me dude$"
