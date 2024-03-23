.set LOCALID_STEVEN, 1

StevenHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, StevenHouse_OnLoad
	.byte 0

StevenHouse_OnLoad:
	call_if_eq VAR_NEW_COO_STATE, 2, StevenHouse_EventScript_MeetSteven
	end

StevenHouse_EventScript_MeetSteven::
	lock
	applymovement LOCALID_STEVEN, StevenHouse_Movement_MeetSteven
	applymovement OBJ_EVENT_ID_PLAYER, StevenHouse_Movement_MeetPlayer
	waitmovement 0
	msgbox StevenHouse_Text_Blah1, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, StevenHouse_Movement_StevenPonders
	waitmovement 0
	applymovement LOCALID_STEVEN, StevenHouse_Movement_StevenLeaves
	waitmovement 0
	setflag FLAG_HIDE_STEVEN_IN_HOUSE
	addvar VAR_NEW_COO_STATE, 1
	release
	end

StevenHouse_Movement_MeetSteven:
	step_end

StevenHouse_Movement_MeetPlayer:
	step_end

StevenHouse_Movement_StevenPonders:
	step_end

StevenHouse_Movement_StevenLeaves:
	step_end
