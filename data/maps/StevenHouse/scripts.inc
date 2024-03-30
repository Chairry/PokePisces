.set LOCALID_STEVEN, 1
.set LOCALID_FOLLOWER, 2

StevenHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, StevenHouse_OnLoad
	.byte 0

StevenHouse_OnLoad:
	call_if_eq VAR_NEW_COO_STATE, 2, StevenHouse_EventScript_MeetSteven
	end

StevenHouse_EventScript_MeetSteven::
	lock
	applymovement LOCALID_STEVEN, StevenHouse_Movement_MeetSteven
	applymovement LOCALID_FOLLOWER, StevenHouse_Movement_StandAside
	applymovement OBJ_EVENT_ID_PLAYER, StevenHouse_Movement_MeetPlayer
	waitmovement 0
	msgbox StevenHouse_Text_Blah1, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, StevenHouse_Movement_StevenPonders
	waitmovement 0
	msgbox StevenHouse_Text_Blah1, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, StevenHouse_Movement_StevenLeaves
	waitmovement 0
	setflag FLAG_HIDE_STEVEN_IN_HOUSE
	setvar VAR_NEW_COO_STATE, 3
	release
	end

StevenHouse_Movement_MeetSteven:
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

StevenHouse_Movement_StandAside:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_right
	step_end

StevenHouse_Movement_MeetPlayer:
	delay_8
	walk_up
	walk_up
	walk_up
	face_right
	step_end

StevenHouse_Movement_StevenPonders:
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	step_end

StevenHouse_Movement_StevenLeaves:
	walk_right
	walk_right
	walk_right
	walk_up
	set_invisible
	step_end

StevenHouse_EventScript_GildedMonk::
	msgbox StevenHouse_Text_Blah1, MSGBOX_NPC
	end

StevenHouse_Text_Blah1:
	.string "test$"
