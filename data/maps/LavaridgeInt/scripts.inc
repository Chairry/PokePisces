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
	poisonplayerparty
	addvar VAR_DURIN_RESISTANCE, 1
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
	poisonplayerparty
	addvar VAR_DURIN_RESISTANCE, 1
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

LavaridgeInt_Text_EverTryADurinBefore:
	.string "$"

LavaridgeInt_Text_DurinCollectorEat:
	.string "$"

LavaridgeInt_Text_DurinCollectorDontEat:
	.string "$"

LavaridgeInt_Text_DurinCollectorPost:
	.string "$"

LavaridgeInt_Text_CantReachThatDurin:
	.string "$"

LavaridgeInt_Text_YouHaveAFlyer:
	.string "$"

LavaridgeInt_Text_NoFly:
	.string "$"

LavaridgeInt_Text_WannaSplitIt:
	.string "$"

LavaridgeInt_Text_DurinFlyHarvesterEat:
	.string "$"

LavaridgeInt_Text_DurinFlyHarvesterDontEat:
	.string "$"

LavaridgeInt_Text_DurinFlyHarvesterPost:
	.string "$"
