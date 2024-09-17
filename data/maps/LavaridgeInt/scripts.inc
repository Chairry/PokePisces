.set LOCALID_ANGRYLADY1, 2
.set LOCALID_ANGRYLADY2, 3

LavaridgeInt_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeInt_OnLoad
	.byte 0

LavaridgeInt_OnLoad:
	call_if_gt VAR_DURIN_RESISTANCE, 0, LavaridgeInt_EventScript_RemoveAngryLady
	end

LavaridgeInt_EventScript_RemoveAngryLady::
	removeobject LOCALID_ANGRYLADY1
	removeobject LOCALID_ANGRYLADY2
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	return

LavaridgeInt_EventScript_SouthTriggerLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeInt_Movement_PositionPlayerLeft
	goto LavaridgeInt_EventScript_AngryLadySouth
	release
	end

LavaridgeInt_Movement_PositionPlayerLeft:
	walk_right
	face_up
	step_end

LavaridgeInt_EventScript_SouthTriggerRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeInt_Movement_PositionPlayerRight
	goto LavaridgeInt_EventScript_AngryLadySouth
	release
	end

LavaridgeInt_Movement_PositionPlayerRight:
	walk_left
	face_up
	step_end

LavaridgeInt_EventScript_AngryLadySouth::
	lock
	applymovement LOCALID_ANGRYLADY1, LavaridgeInt_Movement_AngryLadyWalkUpSouth
	waitmovement 0
	msgbox LavaridgeInt_Text_HateThisMFTown, MSGBOX_DEFAULT
	applymovement LOCALID_ANGRYLADY1, LavaridgeInt_Movement_AngryLadyGoAwaySouth
	waitmovement 0
	call LavaridgeInt_EventScript_RemoveAngryLady
	setvar VAR_DURIN_RESISTANCE, 1
	msgbox LavaridgeInt_Text_SheLeftBehindAGreenBerry, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_EAT_OR_DONT_EAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeInt_EventScript_AngryLadyEat
	case 1, LavaridgeInt_EventScript_AngryLadyDontEat
	release
	end

LavaridgeInt_Movement_AngryLadyWalkUpSouth:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

LavaridgeInt_Movement_AngryLadyGoAwaySouth:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LavaridgeInt_EventScript_AngryLadyEat::
	call LavaridgeInt_EventScript_DurinResistanceCheck
	closemessage
	release
	end

LavaridgeInt_EventScript_AngryLadyDontEat::
	msgbox LavaridgeInt_Text_DontEat, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_NorthTrigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeInt_Movement_PositionPlayerNorth
	goto LavaridgeInt_EventScript_AngryLadyNorth
	release
	end

LavaridgeInt_Movement_PositionPlayerNorth:
	walk_right
	face_down
	step_end

LavaridgeInt_EventScript_AngryLadyNorth::
	lock
	applymovement LOCALID_ANGRYLADY1, LavaridgeInt_Movement_AngryLadyWalkUpNorth
	waitmovement 0
	msgbox LavaridgeInt_Text_HateThisMFTown, MSGBOX_DEFAULT
	applymovement LOCALID_ANGRYLADY1, LavaridgeInt_Movement_AngryLadyGoAwayNorth
	waitmovement 0
	call LavaridgeInt_EventScript_RemoveAngryLady
	setvar VAR_DURIN_RESISTANCE, 1
	msgbox LavaridgeInt_Text_SheLeftBehindAGreenBerry, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_EAT_OR_DONT_EAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeInt_EventScript_AngryLadyEat
	case 1, LavaridgeInt_EventScript_AngryLadyDontEat
	release
	end

LavaridgeInt_Movement_AngryLadyWalkUpNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LavaridgeInt_Movement_AngryLadyGoAwayNorth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	jump_2_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_up
	step_end

LavaridgeInt_EventScript_DurinCollector::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_11, LavaridgeInt_EventScript_DurinCollectorPostEat
	goto_if_ge VAR_DURIN_RESISTANCE, 4, LavaridgeInt_EventScript_DurinCollectorPostEat
	msgbox LavaridgeInt_Text_EverTryADurinBefore, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_EAT_OR_DONT_EAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeInt_EventScript_DurinCollectorEat
	case 1, LavaridgeInt_EventScript_DurinCollectorDontEat
	release
	end

LavaridgeInt_EventScript_DurinCollectorEat::
	call LavaridgeInt_EventScript_DurinResistanceCheck
	setflag FLAG_TEMP_11
	msgbox LavaridgeInt_Text_DurinCollectorEat, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_DurinCollectorDontEat::
	msgbox LavaridgeInt_Text_DurinCollectorDontEat, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_DurinCollectorPostEat::
	msgbox LavaridgeInt_Text_DurinCollectorPost, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_DurinFlyHarvester::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_12, LavaridgeInt_EventScript_DurinFlyHarvesterPostEat
	goto_if_ge VAR_DURIN_RESISTANCE, 4, LavaridgeInt_EventScript_DurinFlyHarvesterPostEat
	msgbox LavaridgeInt_Text_CantReachThatDurin, MSGBOX_DEFAULT
	checkpartymove MOVE_FLY
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeInt_EventScript_CantFly
	msgbox LavaridgeInt_Text_YouHaveAFlyer, MSGBOX_DEFAULT
	playse SE_M_CUT
	waitse
	setflag FLAG_TEMP_12
	setmetatile 22, 24, METATILE_LavaridgeNew_DurinHarvestedBrach, TRUE
	special DrawWholeMapView
	goto LavaridgeInt_EventScript_DurinFlyHarvesterPostHM
	release
	end

LavaridgeInt_EventScript_CantFly::
	msgbox LavaridgeInt_Text_NoFly, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_DurinFlyHarvesterPostHM::
	msgbox LavaridgeInt_Text_WannaSplitIt, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_EAT_OR_DONT_EAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeInt_EventScript_DurinFlyHarvesterEat
	case 1, LavaridgeInt_EventScript_DurinFlyHarvesterDontEat
	release
	end

LavaridgeInt_EventScript_DurinFlyHarvesterEat::
	call LavaridgeInt_EventScript_DurinResistanceCheck
	setflag FLAG_TEMP_12
	msgbox LavaridgeInt_Text_DurinFlyHarvesterEat, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_DurinFlyHarvesterDontEat::
	msgbox LavaridgeInt_Text_DurinFlyHarvesterDontEat, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_DurinFlyHarvesterPostEat::
	msgbox LavaridgeInt_Text_DurinFlyHarvesterPost, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeInt_EventScript_DurinResistanceCheck::
	switch VAR_DURIN_RESISTANCE
	case 1, LavaridgeInt_EventScript_EatResist0
	case 2, LavaridgeInt_EventScript_EatResist1
	case 3, LavaridgeInt_EventScript_EatResist2
	case 4, LavaridgeInt_EventScript_EatResist3
	case 5, LavaridgeInt_EventScript_EatResistMax
	return

LavaridgeInt_EventScript_EatResist0::
	playse SE_FIELD_POISON
	poisonplayerparty
	msgbox LavaridgeInt_Text_EatResist0, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeInt_EventScript_EatResist1::
	playse SE_FIELD_POISON
	poisonplayerparty
	msgbox LavaridgeInt_Text_EatResist1, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeInt_EventScript_EatResist2::
	playse SE_FIELD_POISON
	poisonplayerparty
	msgbox LavaridgeInt_Text_EatResist2, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeInt_EventScript_EatResist3::
	msgbox LavaridgeInt_Text_EatResist3, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeInt_EventScript_EatResistMax::
	msgbox LavaridgeInt_Text_EatResistMax, MSGBOX_DEFAULT
	return

LavaridgeInt_Text_EatResist0:
	.string "(You take a bite of the berry...)\p"
	.string "(It tastes like week-old compost\n"
	.string "overrun with mold. Your\l"
	.string "stomach instantly and viscerally\l"
	.string "rejects the food. You\l"
	.string "instantly feel ill, as does\l"
	.string "your party.)$"

LavaridgeInt_Text_EatResist1:
	.string "(Bad again. Bad bad bad.\n"
	.string "Your tongue frowns at you\l"
	.string "as you attempt to swallow\l"
	.string "the rank, festering fruit.\l"
	.string "It goes down somewhat easier.\l"
	.string "But was it worth it?)$"

LavaridgeInt_Text_EatResist2:
	.string "(Yuck. The taste being familiar\n"
	.string "does not help in any way.\l"
	.string "Must resist the urge to spit\l"
	.string "it out and muscle through.)$"

LavaridgeInt_Text_EatResist3:
	.string "(...This time, you could\n"
	.string "stomach it. It certainly is\l"
	.string "terrible, but getting it down\l"
	.string "quickly doesn't let the\l"
	.string "taste linger too long.\l"
	.string "There's a possibility that you\l"
	.string "are getting resilient to\l"
	.string "Durin Berries.)$"

LavaridgeInt_Text_EatResistMax:
	.string "(Down... the hatch.\n"
	.string "Quick and somewhat painless.)$"

LavaridgeInt_Text_DontEat:
	.string "(Best not to.)$"

LavaridgeInt_Text_HateThisMFTown:
	.string "Had it with this place.\n"
	.string "Had it with this place!\p"
	.string "Hey, do yourself a favor, buddy.\p"
	.string "DON'T ever be eatin' them rank\n"
	.string "fruits they grow here.\l"
	.string "Nastiest slop I've chowed\l"
	.string "down on. Ugh!$"

LavaridgeInt_Text_SheLeftBehindAGreenBerry:
	.string "(She throws a green fruit into the\n"
	.string "air as she leaves.\l"
	.string "You manage to catch it.)\p"
	.string "...\p"
	.string "(It can't be THAT bad...)$"

LavaridgeInt_Text_EverTryADurinBefore:
	.string "Eying up my Durin Berry harvest?\n"
	.string "Heh, for an outsider, you seem\l"
	.string "to have an appreciation\l"
	.string "for local delicacies.\p"
	.string "Take one on the house!\n"
	.string "I insist.\p"
	.string "(Eat the Durin Berry?)$"

LavaridgeInt_Text_DurinCollectorEat:
	.string "It's an acquired taste!\n"
	.string "Be proud you at least tried it.$"

LavaridgeInt_Text_DurinCollectorDontEat:
	.string "It can be intimidating. Who\n"
	.string "knows; it could be your\l"
	.string "new favorite food!$"

LavaridgeInt_Text_DurinCollectorPost:
	.string "Afraid I can't part with any\n"
	.string "more berries.\p"
	.string "I've got a buyer lined up.\n"
	.string "They're planning to\l"
	.string "purchase a whole gross!\p"
	.string "...Hmm.\n"
	.string "Maybe, they were actually\l"
	.string "saying, they WERE gross...$"

LavaridgeInt_Text_CantReachThatDurin:
	.string "See up there?\n"
	.string "Coupl'a perfect Durin Berries\l"
	.string "at the tippity-top.\l"
	.string "But, no way to reach up there.$"

LavaridgeInt_Text_YouHaveAFlyer:
	.string "...What's that? You\n"
	.string "got a 'mon that flies? Sweet.\l"
	.string "if you can get that batch down,\l"
	.string "I'll split one witcha.$"

LavaridgeInt_Text_NoFly:
	.string "(Perhaps a Flying Pokémon\n"
	.string "could come in handy...)$"

LavaridgeInt_Text_WannaSplitIt:
	.string "Sick. What a treat.\n"
	.string "Ready to split, pal?$"

LavaridgeInt_Text_DurinFlyHarvesterEat:
	.string "Love the taste of this\n"
	.string "rancid produce in the mornin'.$"

LavaridgeInt_Text_DurinFlyHarvesterDontEat:
	.string "More for me!\n"
	.string "Thanks for the help.$"

LavaridgeInt_Text_DurinFlyHarvesterPost:
	.string "Typically, the higher a\n"
	.string "Durin grows, juicier it is.$"
