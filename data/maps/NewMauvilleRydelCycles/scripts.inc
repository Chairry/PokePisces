.set LOCALID_RYDEL, 1
.set LOCALID_APPRENTICE, 2
.set LOCALID_P_MAN, 3

NewMauvilleRydelCycles_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauvilleRydelCycles_OnLoad
	.byte 0

NewMauvilleRydelCycles_OnLoad:
	call NewMauvilleRydelCycles_EventScript_RemoveKizuna
	call NewMauvilleRydelCycles_EventScript_SetMauvilleOldManGfx
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
	goto_if_lt VAR_OLD_GUYS_STATE, 5, NewMauvilleRydelCycles_EventScript_RydelPreTrickHouse
	goto_if_eq VAR_OLD_GUYS_STATE, 6, NewMauvilleRydelCycles_EventScript_RydelPostChallenge
	speakername NewMauvilleRydelCycles_Text_NameRydel
	msgbox NewMauvilleRydelCycles_Text_IAmTheHipster, MSGBOX_DEFAULT
	release
	end

NewMauvilleRydelCycles_EventScript_RydelPreTrickHouse::
	release
	end

NewMauvilleRydelCycles_EventScript_RydelPostChallenge::
	release
	end

NewMauvilleRydelCycles_Text_NameRydel:
	.string "Rydel$"

NewMauvilleRydelCycles_Text_NameKizuna:
	.string "Kizuna$"

NewMauvilleRydelCycles_Text_IAmTheHipster:
	.string "i da jokah baybee$"
