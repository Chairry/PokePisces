.set LOCALID_MONK, 9

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	goto_if_lt VAR_SPACE_CENTER_QUEST_STATE, 3, MossdeepCity_EventScript_HideMeteors
	end

MossdeepCity_EventScript_HideMeteors::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	end

MossdeepCity_EventScript_MonkEncounter1::
	lock
	applymovement LOCALID_MONK, MossdeepCity_Movement_MeetPlayer1
	waitmovement 0
	goto MossdeepCity_EventScript_MonkTakeToHouse
	release
	end

MossdeepCity_Movement_MeetPlayer1:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_EventScript_MonkEncounter2::
	lock
	applymovement LOCALID_MONK, MossdeepCity_Movement_MeetPlayer2
	waitmovement 0
	goto MossdeepCity_EventScript_MonkTakeToHouse
	release
	end

MossdeepCity_Movement_MeetPlayer2:
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_EventScript_MonkTakeToHouse::
	msgbox MossdeepCity_Text_MonkGreeting, MSGBOX_DEFAULT
	applymovement LOCALID_MONK, MossdeepCity_Movement_MonkTakePlayer
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerFollow
	waitmovement 0
	msgbox MossdeepCity_Text_Gugumbir, MSGBOX_DEFAULT
	warp MAP_STEVEN_HOUSE, 3, 7
	waitstate
	release
	end

MossdeepCity_Movement_MonkTakePlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

MossdeepCity_Movement_PlayerFollow:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_EventScript_MudShotGuy::
    lock
	faceplayer
	checkitem ITEM_TM_MUD_SHOT
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_EventScript_GaveMudShot
	msgbox MossdeepCity_Text_HaveMudShot, MSGBOX_DEFAULT
	giveitem ITEM_TM_MUD_SHOT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

MossdeepCity_EventScript_GaveMudShot::
    msgbox MossdeepCity_Text_GaveMudShot, MSGBOX_AUTOCLOSE
    release
    end

MossdeepCity_EventScript_Rawr::
	lock
	faceplayer
	checkitem ITEM_TM_SNARL
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_EventScript_GaveSnarl
	msgbox MossdeepCity_Text_WantToSeeMonGrowl, MSGBOX_DEFAULT
	checkpartynonhmmove MOVE_GROWL
	goto_if_eq VAR_RESULT, PARTY_SIZE, MossdeepCity_EventScript_NoGrowl
	msgbox MossdeepCity_Text_HaveSnarl, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNARL
	release
	end

MossdeepCity_EventScript_NoGrowl::
	msgbox MossdeepCity_Text_NoGrowl, MSGBOX_AUTOCLOSE
	release
	end

MossdeepCity_EventScript_GaveSnarl::
	msgbox MossdeepCity_Text_GaveSnarl, MSGBOX_AUTOCLOSE
	release
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_Gugumbir, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_Gugumbir, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_Text_HaveMudShot:
	.string "I love the feel of the beach\n"
	.string "beneath my feet!\p"
	.string "You know, certain kinds of mud have\n"
	.string "healing, soothing properties.\p"
	.string "Especially ones made by Pokémon!\p"
	.string "With this TM, you too can\n"
	.string "enjoy the smoothness of mud!$"

MossdeepCity_Text_GaveMudShot:
	.string "I have a mud bath appointment\n"
	.string "coming up soon..."

MossdeepCity_Text_WantToSeeMonGrowl:
	.string "Grr... Rrrraaarghhh...\p"
	.string "(He's scowling and growling...)\p"
	.string "(Perhaps he wants you to...\n"
	.string "...growl... back??)$"

MossdeepCity_Text_HaveSnarl:
	.string "(You growl at the odd man.)\p"
	.string "GRRAHHRRAHHRGH!! GRRAROAGH!!\p"
	.string "(He hands you something...)$"

MossdeepCity_Text_NoGrowl:
	.string "(You feel intimidated by the\n"
	.string "snarling man...)$"

MossdeepCity_Text_GaveSnarl:
	.string "(You respect each others' turf.)$"

MossdeepCity_Text_MonkGreeting:
	.string "Greetings and Good Fortune.\p"
	.string "I am speaking to {PLAYER}, correct?\p"
	.string "A very special someone wishes\n"
	.string "to speak with you.\p"
	.string "Allow me to escort you…$"

MossdeepCity_Text_Gugumbir:
	.string "test$"
