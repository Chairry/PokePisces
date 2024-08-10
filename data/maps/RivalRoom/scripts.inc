.set LOCALID_BRINEY, 1

RivalRoom_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, RivalRoom_OnFrame
	.byte 0

RivalRoom_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, RivalRoom_EventScript_BrineyOpening
	.2byte 0

RivalRoom_EventScript_BrineyOpening::
	lockall
	applymovement LOCALID_BRINEY, RivalRoom_Movement_BrineyFacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, RivalRoom_Movement_PlayerFaceBriney
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_SYS_B_DASH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_HIDE_BIRCH_AFTER_STARTER
	clearflag FLAG_HIDE_BIRCH_BEFORE_STARTER
	speakername RivalRoom_Text_NameBriney
	msgbox RivalRoom_Text_GoTalkToOthers, MSGBOX_DEFAULT
	speakername NULL
	closemessage
	releaseall
	end

RivalRoom_Movement_BrineyFacePlayer:
	face_right
	step_end

RivalRoom_Movement_PlayerFaceBriney:
	face_left
	step_end

RivalRoom_EventScript_GetOut::
	speakername RivalRoom_Text_NameBriney
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, RivalRoom_EventScript_Docked
    msgbox RivalRoom_Text_BrineyText, MSGBOX_NPC
	speakername NULL
	end

RivalRoom_EventScript_Docked::
	msgbox RivalRoom_Text_Docked, MSGBOX_NPC
	speakername NULL
	end

RivalRoom_Text_NameBriney:
	.string "Cpt. Briney$"

RivalRoom_Text_GoTalkToOthers:
	.string "The Tidal's voyage should be\n"
	.string "concluding in a short spell.\p"
	.string "Why not go talk to the other\n"
	.string "passengers to pass the time?\p"
	.string "My good friend Drake is\n"
	.string "aboard today... I am positive\l"
	.string "that he would enjoy some\l"
	.string "brief company.\p"
	.string "I'll make the announcement when\n"
	.string "we are docked.$"

RivalRoom_Text_BrineyText:
	.string "I encourage you to go\n"
	.string "interact with the other passengers.$"

RivalRoom_Text_Docked:
	.string "Well {PLAYER}, that'll\n"
	.string "be it for the S.S. Tidal's voyage\l"
	.string "on this fine morning.\p"
	.string "It's been a pleasure meeting\n"
	.string "you. Tell Birch that I said Ahoy!$"
