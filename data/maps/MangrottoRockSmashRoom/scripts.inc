MangrottoRockSmashRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MangrottoRockSmashRoom_OnFrame
	.byte 0

MangrottoRockSmashRoom_OnFrame:
	map_script_2 VAR_TEMP_4, 0, MangrottoRockSmashRoom_EventScript_LockPlayerIntoChoice
	map_script_2 VAR_TEMP_4, 12, MangrottoRockSmashRoom_EventScript_YouWin
	.2byte 0

MangrottoRockSmashRoom_EventScript_LockPlayerIntoChoice::
	lock
	delay 8
	applymovement OBJ_EVENT_ID_PLAYER, MangrottoRockSmashRoom_Movement_PlayerWalkUp
	goto MangrottoRockSmashRoom_EventScript_RockSmashChallenge
	release
	end

MangrottoRockSmashRoom_Movement_PlayerWalkUp:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

MangrottoRockSmashRoom_EventScript_YouWin::
	lock
	setvar VAR_TEMP_4, 69
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	msgbox MangrottoRockSmashRoom_Text_ChallengeWon, MSGBOX_AUTOCLOSE
	giveitem ITEM_TM_BREAKING_SWIPE
	release
	end

MangrottoRockSmashRoom_EventScript_RockSmashChallenge::
	lock
	faceplayer
	checkitem ITEM_TM_BREAKING_SWIPE
	goto_if_eq VAR_RESULT, TRUE, MangrottoRockSmashRoom_EventScript_NoMoreChallenge
	msgbox MangrottoRockSmashRoom_Text_WantToTakeOnChallenge, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MangrottoRockSmashRoom_EventScript_StartRSChallenge
	msgbox MangrottoRockSmashRoom_Text_MaybeNextTime, MSGBOX_AUTOCLOSE
	warp MAP_MANGROTTO_TUNNEL, 10, 10
	waitstate
	release
	end

MangrottoRockSmashRoom_EventScript_NoMoreChallenge::
	msgbox MangrottoRockSmashRoom_Text_NoMoreChallenge, MSGBOX_AUTOCLOSE
	warp MAP_MANGROTTO_TUNNEL, 10, 10
	waitstate
	release
	end

MangrottoRockSmashRoom_EventScript_StartRSChallenge::
	setvar VAR_TEMP_4, 1
	special SetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_DEPART_SLATEPORT
	msgbox MangrottoRockSmashRoom_Text_StartChallenge, MSGBOX_AUTOCLOSE
	release
	end

MangrottoRockSmashRoom_EventScript_FailedChallenge::
	lock
	special ResetSSTidalFlag
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_LAND_LILYCOVE
	msgbox MangrottoRockSmashRoom_Text_FailedChallenge, MSGBOX_AUTOCLOSE
	warp MAP_MANGROTTO_TUNNEL, 10, 10
	waitstate
	release
	end

MangrottoRockSmashRoom_EventScript_SmashChallengeRock::
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	addvar VAR_TEMP_4, 1
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

MangrottoRockSmashRoom_Text_WantToTakeOnChallenge:
	.string "want challenge?$"

MangrottoRockSmashRoom_Text_MaybeNextTime:
	.string "maybe next time$"

MangrottoRockSmashRoom_Text_NoMoreChallenge:
	.string "no more challenge$"

MangrottoRockSmashRoom_Text_StartChallenge:
	.string "start challenge$"

MangrottoRockSmashRoom_Text_FailedChallenge:
	.string "failed challenge$"

MangrottoRockSmashRoom_Text_ChallengeWon:
	.string "won challenge$"
