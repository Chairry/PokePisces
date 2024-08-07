.set LOCALID_STEVEN, 1
.set LOCALID_FOLLOWER, 2

StevenHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, StevenHouse_OnFrame
	.byte 0

StevenHouse_OnFrame:
	map_script_2 VAR_NEW_COO_STATE, 2, StevenHouse_EventScript_MeetSteven
	.2byte 0

StevenHouse_EventScript_MeetSteven::
	msgbox StevenHouse_Text_MonkIntroduce, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, StevenHouse_Movement_MeetSteven
	applymovement LOCALID_FOLLOWER, StevenHouse_Movement_StandAside
	applymovement OBJ_EVENT_ID_PLAYER, StevenHouse_Movement_MeetPlayer
	waitmovement 0
	speakername StevenHouse_Text_NameSteven
	msgbox StevenHouse_Text_StevenGreet, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, StevenHouse_Movement_StevenPonders
	waitmovement 0
	msgbox StevenHouse_Text_Pondering, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, StevenHouse_Movement_StevenLeaves
	waitmovement 0
	speakername NULL
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
	msgbox StevenHouse_Text_MonkIdle, MSGBOX_NPC
	end

StevenHouse_Text_MonkIntroduce:
	.string "My pleasure to introduce you to\n"
	.string "former Champion, Steven.$"

StevenHouse_Text_NameSteven:
	.string "Steven$"

StevenHouse_Text_StevenGreet:
	.string "I believe we've met once or twice.\n"
	.string "It's good to know you're\l"
	.string "holding up well.\p"
	.string "Now… why are you here,\n"
	.string "you may be thinking.\p"
	.string "Professor Birch had contacted me…\n"
	.string "to keep an eye on a certain\l"
	.string "up-and-coming master trainer.\p"
	.string "Trust me when I say that he thinks\n"
	.string "quite highly of you.$"

StevenHouse_Text_Pondering:
	.string "Apologies, but I don't quite see it.\p"
	.string "Truth be told, I am looking for a\n"
	.string "trainer at the level of\l"
	.string "hypercompetence matching\l"
	.string "your old rival.\p"
	.string "I do hope you keep accelerating\n"
	.string "your momentum. If… and only if… you\l"
	.string "get to a champion power level…\p"
	.string "I will bring you along a very…\n"
	.string "special voyage.$"
	.string "To that end, here is a\n"
	.string "deal I'll make you.\p"
	.string "Challenge the Mossdeep Gym,\n"
	.string "and triumph.\p"
	.string "Once you are able to light your way\n"
	.string "through the darkness…\p"
	.string "Meet me in my training dojo.$"

StevenHouse_Text_MonkIdle:
	.string "Please make yourself comfortable.$"

StevenHouse_Text_Blah1:
	.string "test$"
