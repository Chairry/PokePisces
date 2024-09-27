.set LOCALID_RYDEL, 1
.set LOCALID_APPRENTICE, 2
.set LOCALID_P_MAN, 3

NewMauvilleRydelCycles_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauvilleRydelCycles_OnLoad
	.byte 0

NewMauvilleRydelCycles_OnLoad:
	call NewMauvilleRydelCycles_EventScript_RemoveKizuna
	call_if_eq VAR_OLD_GUYS_STATE, 5, NewMauvilleRydelCycles_EventScript_SetMauvilleOldManGfx
	call_if_lt VAR_OLD_GUYS_STATE, 5, NewMauvilleRydelCycles_EventScript_RemoveRydel
	call_if_gt VAR_OLD_GUYS_STATE, 6, NewMauvilleRydelCycles_EventScript_RemoveRydel
	end

NewMauvilleRydelCycles_EventScript_SetMauvilleOldManGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_HIPSTER
	special SetMauvilleOldManObjEventGfx
	end

NewMauvilleRydelCycles_EventScript_RemoveKizuna::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

NewMauvilleRydelCycles_EventScript_RemoveRydel::
	removeobject LOCALID_RYDEL
	setflag FLAG_TEMP_12
	return

NewMauvilleRydelCycles_EventScript_Rydel::
	lock
	goto_if_eq VAR_OLD_GUYS_STATE, 6, NewMauvilleRydelCycles_EventScript_RydelPostChallenge
	speakername NewMauvilleRydelCycles_Text_NameRydel
	msgbox NewMauvilleRydelCycles_Text_IAmTheHipster, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLD_GUYS_STATE, 6
	playse SE_DOOR
	clearflag FLAG_TEMP_11
	addobject LOCALID_P_MAN
	applymovement LOCALID_P_MAN, NewMauvilleRydelCycles_Movement_KizunaEnterRoom
	speakername NewMauvilleRydelCycles_Text_NameKizuna
	msgbox NewMauvilleRydelCycles_Text_YouTheNextGuy, MSGBOX_DEFAULT
	speakername NewMauvilleRydelCycles_Text_NameRydel
	msgbox NewMauvilleRydelCycles_Text_TakeMyChallenge, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	applymovement LOCALID_P_MAN, NewMauvilleRydelCycles_Movement_KizunaFaceRight
	speakername NewMauvilleRydelCycles_Text_NameKizuna
	msgbox NewMauvilleRydelCycles_Text_AsLongAsYoureUpForIt, MSGBOX_DEFAULT
	speakername NewMauvilleRydelCycles_Text_NameRydel
	msgbox NewMauvilleRydelCycles_Text_BrilliantLetsBegin, MSGBOX_DEFAULT
	closemessage
	warp MAP_ROUTE110_SEASIDE_CYCLING_ROAD_NORTH_ENTRANCE, 4, 4
	release
	end

NewMauvilleRydelCycles_Movement_KizunaEnterRoom:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewMauvilleRydelCycles_Movement_KizunaFaceRight:
	face_right
	step_end

NewMauvilleRydelCycles_EventScript_RydelPostChallenge::
	msgbox NewMauvilleRydelCycles_Text_RydelPostChallenge, MSGBOX_AUTOCLOSE
	release
	end

NewMauvilleRydelCycles_Text_NameRydel:
	.string "Rydel$"

NewMauvilleRydelCycles_Text_NameKizuna:
	.string "Kizuna$"

NewMauvilleRydelCycles_Text_IAmTheHipster:
	.string "i da jokah baybee$"

NewMauvilleRydelCycles_Text_YouTheNextGuy:
	.string "you da next one baybee$"

NewMauvilleRydelCycles_Text_TakeMyChallenge:
	.string "take my challenge$"

NewMauvilleRydelCycles_Text_AsLongAsYoureUpForIt:
	.string "ok do it bro$"

NewMauvilleRydelCycles_Text_BrilliantLetsBegin:
	.string "briliant (british)$"

NewMauvilleRydelCycles_Text_RydelPostChallenge:
	.string "rydel post$"
