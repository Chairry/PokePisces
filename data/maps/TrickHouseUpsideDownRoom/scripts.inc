.set LOCALID_PANDOU, 1

TrickHouseUpsideDownRoom_MapScripts::
	.byte 0

TrickHouseUpsideDownRoom_EventScript_ScrollB::
	lock
	msgbox TrickHouseUpsideDownRoom_Text_ScrollB, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseUpsideDownRoom_EventScript_BreadLeftEncounter::
	lock
	goto_if_defeated TRAINER_P_PANDOU_4, TrickHouseUpsideDownRoom_EventScript_RemovePandou
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseUpsideDownRoom_Movement_PlayerLeftMerge
	goto TrickHouseUpsideDownRoom_EventScript_BreadEncounter
	release
	end

TrickHouseUpsideDownRoom_EventScript_RemovePandou::
	removeobject LOCALID_PANDOU
	setflag FLAG_TEMP_11
	setvar VAR_TEMP_7, 1
	release
	end

TrickHouseUpsideDownRoom_Movement_PlayerLeftMerge:
	walk_right
	face_down
	step_end

TrickHouseUpsideDownRoom_EventScript_BreadRightEncounter::
	lock
	goto_if_defeated TRAINER_P_PANDOU_4, TrickHouseUpsideDownRoom_EventScript_RemovePandou
	applymovement OBJ_EVENT_ID_PLAYER, TrickHouseUpsideDownRoom_Movement_PlayerRightMerge
	goto TrickHouseUpsideDownRoom_EventScript_BreadEncounter
	release
	end

TrickHouseUpsideDownRoom_Movement_PlayerRightMerge:
	walk_left
	face_down
	step_end

TrickHouseUpsideDownRoom_EventScript_BreadEncounter::
	lock
	setvar VAR_TEMP_7, 1
	goto_if_defeated TRAINER_P_PANDOU_4, TrickHouseUpsideDownRoom_EventScript_RemovePandou
	speakername TrickHouseUpsideDownRoom_Text_NamePandou
	applymovement LOCALID_PANDOU, TrickHouseUpsideDownRoom_Movement_BumpIntoPlayer
	waitmovement 0
	msgbox TrickHouseUpsideDownRoom_Text_WhatIsGoingOn, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_P_PANDOU_4, TrickHouseUpsideDownRoom_Text_BreadwinnerIntro, TrickHouseUpsideDownRoom_Text_BreadwinnerDefeat, TrickHouseUpsideDownRoom_EventScript_BreadRun
	speakername NULL
	goto TrickHouseUpsideDownRoom_EventScript_BreadRun
	release
	end

TrickHouseUpsideDownRoom_Movement_BumpIntoPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	walk_down
	walk_down
	walk_up
	delay_4
	step_end

TrickHouseUpsideDownRoom_EventScript_BreadRun::
	speakername TrickHouseUpsideDownRoom_Text_NamePandou
	msgbox TrickHouseUpsideDownRoom_Text_IGottaGo, MSGBOX_DEFAULT
	applymovement LOCALID_PANDOU, TrickHouseUpsideDownRoom_Movement_RunAway
	waitmovement 0
	delay 8
	removeobject LOCALID_PANDOU
	setflag FLAG_TEMP_11
	closemessage
	speakername NULL
	release
	end

TrickHouseUpsideDownRoom_Movement_RunAway:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	face_down
	step_end

TrickHouseUpsideDownRoom_Text_NamePandou:
	.string "Pandou$"

TrickHouseUpsideDownRoom_Text_WhatIsGoingOn:
	.string "What DA HELL IS GOIN ON$"

TrickHouseUpsideDownRoom_Text_BreadwinnerIntro:
	.string "?????$"

TrickHouseUpsideDownRoom_Text_BreadwinnerDefeat:
	.string "INTERROBANG$"

TrickHouseUpsideDownRoom_Text_IGottaGo:
	.string "GOTTA JET????$"

TrickHouseUpsideDownRoom_Text_ScrollB:
	.string "(It's a scroll with odd\n"
	.string "handwriting on it...)\p"
	.string "Here is this room's number hint!\n"
	.string "Keep it well within your\l"
	.string "frontal lobe.\p"
	.string "In the final sequence, this\n"
	.string "room's digit equals the number\l"
	.string "directly to its right, minus\l"
	.string "the one directly to its left.\p"
	.string "- Trick Master is a genius.$"
