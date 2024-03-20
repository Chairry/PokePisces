.set LOCALID_DRAKE, 2

NewSooto_MapScripts::
	.byte 0

NewSooto_EventScript_DontGoInCave::
	lock
	msgbox NewSooto_Text_BestNotTo, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerGoAway
	waitmovement 0
	release
	end

NewSooto_Movement_PlayerGoAway:
	walk_down
	step_end

NewSooto_EventScript_TakePlayerToCave1::
	lock
	playse SE_PIN
	applymovement LOCALID_DRAKE, NewSooto_Movement_DrakeNoticeLeft
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave1
	waitmovement 0
	msgbox NewSooto_Text_CheckOutTheCave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave5
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN, 14, 4
	waitstate
	release
	end

NewSooto_Movement_DrakeNoticeLeft:
	emote_exclamation_mark
	face_left
	step_end

NewSooto_Movement_PlayerWalkToCave1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

NewSooto_Movement_PlayerWalkToCave5:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewSooto_EventScript_TakePlayerToCave2::
	lock
	playse SE_PIN
	applymovement LOCALID_DRAKE, NewSooto_Movement_DrakeNoticeLeft
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave2
	waitmovement 0
	msgbox NewSooto_Text_CheckOutTheCave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave5
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN, 14, 4
	waitstate
	release
	end

NewSooto_Movement_PlayerWalkToCave2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_right
	step_end

NewSooto_EventScript_TakePlayerToCave3::
	lock
	playse SE_PIN
	applymovement LOCALID_DRAKE, NewSooto_Movement_DrakeNoticeRight
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave3
	waitmovement 0
	msgbox NewSooto_Text_CheckOutTheCave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave5
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN, 14, 4
	waitstate
	release
	end

NewSooto_Movement_DrakeNoticeRight:
	emote_exclamation_mark
	face_right
	delay_8
	delay_8
	delay_8
	face_left
	step_end

NewSooto_Movement_PlayerWalkToCave3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_right
	step_end

NewSooto_EventScript_TakePlayerToCave4::
	lock
	playse SE_PIN
	applymovement LOCALID_DRAKE, NewSooto_Movement_DrakeNoticeRight
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave4
	waitmovement 0
	msgbox NewSooto_Text_CheckOutTheCave, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewSooto_Movement_PlayerWalkToCave5
	waitmovement 0
	warp MAP_CAVE_OF_ORIGIN, 14, 4
	waitstate
	release
	end

NewSooto_Movement_PlayerWalkToCave4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_right
	step_end

NewSooto_EventScript_PaperSeller::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BLUNDER_POLICY, NewSooto_EventScript_NoMorePolicies
	showmoneybox 0, 0
	msgbox NewSooto_Text_WantAPaper, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewSooto_EventScript_CheckMoneyForBP
	closemessage
	hidemoneybox
	release
	end

NewSooto_EventScript_CheckMoneyForBP::
	checkmoney 1000
	goto_if_eq VAR_RESULT, FALSE, NewSooto_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 1000
	updatemoneybox
	delay 40
	hidemoneybox
	giveitem ITEM_BLUNDER_POLICY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_BLUNDER_POLICY
	msgbox NewSooto_Text_ThanksForBuying, MSGBOX_AUTOCLOSE
	release
	end

NewSooto_EventScript_NoMorePolicies::
    msgbox NewSooto_Text_NoMorePolicies, MSGBOX_AUTOCLOSE
    release
    end

NewSooto_EventScript_NotEnoughMoney::
	msgbox NewSooto_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

NewSooto_Text_CheckOutTheCave:
	.string "Hurrumph!\n"
	.string "If it isn't that {PLAYER} fellow.\p"
	.string "I hope you have been faring well.\p"
	.string "What begets my audience in Sootopolis?…\n"
	.string "The Legends I had discussed with you\l"
	.string "aboard the Tidal, of course.\p"
	.string "This borough has seen many an\n"
	.string "encounter with the divine and\l"
	.string "powerful, after all.\p"
	.string "You seem interested, my friend.\p"
	.string "Head forth into the Cave of Origin,\n"
	.string "{PLAYER}.\p"
	.string "You will meet a man who bore witness\n"
	.string "to the clash between the Behemoth\l"
	.string "and the Leviathan…\p"
	.string "I just finished up conversing with the\n"
	.string "fellow, I believe it will\l"
	.string "pique your curiosity.$"

NewSooto_Text_WantAPaper:
	.string "Papers! Papers!\n"
	.string "Get'cha mornin' papers here!\p"
	.string "Hey! I can tell ya wanna paper.\n"
	.string "How's ¥1000 sound?\l"
	.string "It's a great deal!$"

NewSooto_Text_ThanksForBuying:
	.string "Alrighty!\p"
	.string "(The Paper Boy shuffles\n"
	.string "through his pack.)\p"
	.string "Ah, here's one'a the best!$"

NewSooto_Text_NoMorePolicies:
	.string "Hmm? Nah, I ain't got no news papers.\p"
	.string "I got, uh… let's see here…\p"
	.string "Old tax return…\n"
	.string "condemned buildin' notice…\l"
	.string "D- math test…$"

NewSooto_Text_NotEnoughMoney:
	.string "Ah, maybe next time.\n"
	.string "Won't nab a better paper anywhere else!$"

NewSooto_Text_BestNotTo:
	.string "(Looks like an intimidating cave.\n"
	.string "...best to wait until you're\l"
	.string "a bit stronger.)$"
