LavaridgeHouses_MapScripts::
	.byte 0

LavaridgeHouses_EventScript_DurinGrandma::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_11, LavaridgeHouses_EventScript_DurinGrandmaPostEat
	goto_if_ge VAR_DURIN_RESISTANCE, 4, LavaridgeHouses_EventScript_DurinGrandmaPostEat
	msgbox LavaridgeHouses_Text_MyGrandkidsDidntShow, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_EAT_OR_DONT_EAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeHouses_EventScript_DurinGrandmaEat
	case 1, LavaridgeHouses_EventScript_DurinGrandmaDontEat
	release
	end

LavaridgeHouses_EventScript_DurinGrandmaEat::
	poisonplayerparty
	addvar VAR_DURIN_RESISTANCE, 1
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

LavaridgeHouses_Text_MyGrandkidsDidntShow:
	.string "$"

LavaridgeHouses_Text_DurinGrandmaEat:
	.string "$"

LavaridgeHouses_Text_DurinGrandmaDontEat:
	.string "$"

LavaridgeHouses_Text_DurinGrandmaPost:
	.string "$"
