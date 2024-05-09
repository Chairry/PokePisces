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
	.string "i wanna see a tru bond$"

ZotpyreSecretBasement_Text_NotEnough:
	.string "not enough friendship$"

ZotpyreSecretBasement_Text_ATrueBondIndeed:
	.string "a true bond indeed\n"
	.string "i can now move on$"
