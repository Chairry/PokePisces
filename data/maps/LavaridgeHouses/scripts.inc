LavaridgeHouses_MapScripts::
	.byte 0

LavaridgeHouses_EventScript_DurinGrandma::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_11, LavaridgeHouses_EventScript_DurinGrandmaPostEat
	goto_if_ge VAR_DURIN_RESISTANCE, 5, LavaridgeHouses_EventScript_DurinGrandmaPostEat
	msgbox LavaridgeHouses_Text_MyGrandkidsDidntShow, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_EAT_OR_DONT_EAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeHouses_EventScript_DurinGrandmaEat
	case 1, LavaridgeHouses_EventScript_DurinGrandmaDontEat
	release
	end

LavaridgeHouses_EventScript_DurinGrandmaEat::
	call LavaridgeHouses_EventScript_DurinResistanceCheck
	setflag FLAG_TEMP_11
	msgbox LavaridgeHouses_Text_DurinGrandmaEat, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeHouses_EventScript_DurinGrandmaDontEat::
	msgbox LavaridgeHouses_Text_DurinGrandmaDontEat, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeHouses_EventScript_DurinGrandmaPostEat::
	msgbox LavaridgeHouses_Text_DurinGrandmaPost, MSGBOX_AUTOCLOSE
	release
	end

LavaridgeHouses_EventScript_DurinResistanceCheck::
	switch VAR_DURIN_RESISTANCE
	case 1, LavaridgeHouses_EventScript_EatResist0
	case 2, LavaridgeHouses_EventScript_EatResist1
	case 3, LavaridgeHouses_EventScript_EatResist2
	case 4, LavaridgeHouses_EventScript_EatResist3
	case 5, LavaridgeHouses_EventScript_EatResistMax
	return

LavaridgeHouses_EventScript_EatResist0::
	playse SE_FIELD_POISON
	poisonplayerparty
	msgbox LavaridgeHouses_Text_EatResist0, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeHouses_EventScript_EatResist1::
	playse SE_FIELD_POISON
	poisonplayerparty
	msgbox LavaridgeHouses_Text_EatResist1, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeHouses_EventScript_EatResist2::
	playse SE_FIELD_POISON
	poisonplayerparty
	msgbox LavaridgeHouses_Text_EatResist2, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeHouses_EventScript_EatResist3::
	msgbox LavaridgeHouses_Text_EatResist3, MSGBOX_DEFAULT
	addvar VAR_DURIN_RESISTANCE, 1
	return

LavaridgeHouses_EventScript_EatResistMax::
	msgbox LavaridgeHouses_Text_EatResistMax, MSGBOX_DEFAULT
	return

LavaridgeHouses_Text_EatResist0:
	.string "(You take a bite of the berry...)\p"
	.string "(It tastes like week-old compost\n"
	.string "overrun with mold. Your\l"
	.string "stomach instantly and viscerally\l"
	.string "rejects the food. You\l"
	.string "instantly feel ill, as does\l"
	.string "your party.)$"

LavaridgeHouses_Text_EatResist1:
	.string "(Bad again. Bad bad bad.\n"
	.string "Your tongue frowns at you\l"
	.string "as you attempt to swallow\l"
	.string "the rank, festering fruit.\l"
	.string "It goes down somewhat easier.\l"
	.string "But was it worth it?)$"

LavaridgeHouses_Text_EatResist2:
	.string "(Yuck. The taste being familiar\n"
	.string "does not help in any way.\l"
	.string "Must resist the urge to spit\l"
	.string "it out and muscle through.)$"

LavaridgeHouses_Text_EatResist3:
	.string "(...This time, you could\n"
	.string "stomach it. It certainly is\l"
	.string "terrible, but getting it down\l"
	.string "quickly doesn't let the\l"
	.string "taste linger too long.\l"
	.string "There's a possibility that you\l"
	.string "are getting resilient to\l"
	.string "Durin Berries.)$"

LavaridgeHouses_Text_EatResistMax:
	.string "(Down... the hatch.\n"
	.string "Quick and somewhat painless.)$"

LavaridgeHouses_Text_MyGrandkidsDidntShow:
	.string "Oh... good day to you.\p"
	.string "My grandkids unfortunately\n"
	.string "couldn't visit today. We\l"
	.string "had planned on it, but,\l"
	.string "last minute complications...\p"
	.string "I cut up a bushel of their\n"
	.string "favorite berries in\l"
	.string "anticipation... oh, dear.\l"
	.string "I may have to throw them out.\p"
	.string "(It would prove kind to\n"
	.string "indulge the grandma...)$"

LavaridgeHouses_Text_DurinGrandmaEat:
	.string "Oh, sweetheart. That was\n"
	.string "awfully kind to sit with me.\l"
	.string "You remind me of my eldest!\p"
	.string "Now the food won't go to\n"
	.string "waste, thank heavens...$"

LavaridgeHouses_Text_DurinGrandmaDontEat:
	.string "Don't you worry about\n"
	.string "me, sweetheart.\l"
	.string "I will be fine.$"

LavaridgeHouses_Text_DurinGrandmaPost:
	.string "The kiddos are little\n"
	.string "bottles of chaos sometimes...\l"
	.string "but we can't take youthful\l"
	.string "energy for granted.\l"
	.string "I'll continue to spoil them!$"
