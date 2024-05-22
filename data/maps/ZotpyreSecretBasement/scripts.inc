.set LOCALID_ELDERWOMAN, 1

ZotpyreSecretBasement_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ZotpyreSecretBasement_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ZotpyreSecretBasement_OnFrame
	.byte 0

ZotpyreSecretBasement_OnFrame:
	map_script_2 VAR_GRAVE_QUEST_STATE, 4, ZotpyreSecretBasement_EventScript_ElderWoman
	.2byte 0

ZotpyreSecretBasement_OnLoad:
	call ZotpyreSecretBasement_EventScript_SetElderWomanFlags
	end

ZotpyreSecretBasement_EventScript_SetElderWomanFlags::
	setflag FLAG_TEMP_12
	removeobject LOCALID_ELDERWOMAN
	return

ZotpyreSecretBasement_EventScript_ElderWoman::
	lock
	clearflag FLAG_TEMP_12
	addobject LOCALID_ELDERWOMAN
	delay 16
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, ZotpyreSecretBasement_Movement_PlayerWalkForwards
	waitmovement 0
	msgbox ZotpyreSecretBasement_Text_IWantToSeeATrueBond, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_MAX, ZotpyreSecretBasement_EventScript_ICanMoveOn
	msgbox ZotpyreSecretBasement_Text_NotEnough, MSGBOX_AUTOCLOSE
	warp MAP_ZOTPYRE_INTERIORS, 3, 7
	release
	end

ZotpyreSecretBasement_Movement_PlayerWalkForwards:
	walk_slow_up
	step_end

ZotpyreSecretBasement_EventScript_ICanMoveOn::
	msgbox ZotpyreSecretBasement_Text_ATrueBondIndeed, MSGBOX_DEFAULT
	setvar VAR_GRAVE_QUEST_STATE, 5
	setflag FLAG_TEMP_12
	removeobject LOCALID_ELDERWOMAN
	release
	end

ZotpyreSecretBasement_Text_IWantToSeeATrueBond:
	.string "I Feel A Presence\p"
	.string "A Trainer\p"
	.string "Tell Me\p"
	.string "No\p"
	.string "Show Me\p"
	.string "The Bonds Of Those Whom Travel\n"
	.string "Alongside You$"

ZotpyreSecretBasement_Text_NotEnough:
	.string "Ah\p"
	.string "I Have Been Mistaken\p"
	.string "A True Bond Like That Which I Seek\p"
	.string "Not Possible$"

ZotpyreSecretBasement_Text_ATrueBondIndeed:
	.string "Your Companions\p"
	.string "They Cherish You\p"
	.string "A True Bond\p"
	.string "Does Exist After All\p"
	.string " \p"
	.string "Maychance\p"
	.string "Even I\p"
	.string "Had A True Bond\p"
	.string "Once\p"
	.string " \p"
	.string "The Cacophony In My Mind\p"
	.string "It Has Quieted$"
