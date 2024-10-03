.set LOCALID_SURFER_1, 11
.set LOCALID_SURFER_POST_1, 13
.set LOCALID_SURFER_2, 12
.set LOCALID_SURFER_POST_2, 14
.set LOCALID_SURFER_3, 8
.set LOCALID_SURFER_POST_3, 16
.set LOCALID_SURFER_4, 10
.set LOCALID_SURFER_POST_4, 15

DewfordGymNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DewfordGymNew_OnLoad
	.byte 0

DewfordGymNew_OnLoad:
	call DewfordGymNew_EventScript_RemovePostSurfers
	end

DewfordGymNew_EventScript_RemovePostSurfers::
	removeobject LOCALID_SURFER_POST_1
	setflag FLAG_TEMP_14
	removeobject LOCALID_SURFER_POST_2
	setflag FLAG_TEMP_15
	removeobject LOCALID_SURFER_POST_3
	setflag FLAG_TEMP_16
	removeobject LOCALID_SURFER_POST_4
	setflag FLAG_TEMP_17
	return

DewfordGymNew_EventScript_StrengthSurfer1::
	lockall
	goto_if_unset FLAG_BADGE05_GET, DewfordGymNew_EventScript_CantStrength
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, DewfordGymNew_EventScript_CantStrength
	msgbox DewfordGymNew_Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordGymNew_EventScript_CancelStrength
	closemessage
	playse SE_M_VITAL_THROW2
	delay 4
	applymovement LOCALID_SURFER_1, DewfordGymNew_Movement_PushSurfer1
	waitmovement 0
	removeobject LOCALID_SURFER_1
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_14
	addobject LOCALID_SURFER_POST_1
	playse SE_M_DIVE
	delay 8
	setmetatile 44, 6, METATILE_General_CalmWater, TRUE
	setmetatile 45, 6, METATILE_General_CalmWater, FALSE
	setmetatile 46, 6, METATILE_General_CalmWater, FALSE
	setmetatile 47, 6, METATILE_General_CalmWater, FALSE
	setmetatile 48, 6, METATILE_General_CalmWater, FALSE
	setmetatile 49, 6, METATILE_General_CalmWater, FALSE
	setmetatile 50, 6, METATILE_General_CalmWater, FALSE
	setmetatile 51, 6, METATILE_General_CalmWater, FALSE
	setmetatile 52, 6, METATILE_General_CalmWater, FALSE
	setmetatile 53, 6, METATILE_General_CalmWater, FALSE
	special DrawWholeMapView
	releaseall
	end

DewfordGymNew_Movement_PushSurfer1:
	slide_down
	step_end

DewfordGymNew_EventScript_StrengthSurfer1Post::
	lock
	msgbox DewfordGymNew_Text_InTheWater, MSGBOX_AUTOCLOSE
	release
	end

DewfordGymNew_EventScript_StrengthSurfer2::
	lockall
	goto_if_unset FLAG_BADGE05_GET, DewfordGymNew_EventScript_CantStrength
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, DewfordGymNew_EventScript_CantStrength
	msgbox DewfordGymNew_Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordGymNew_EventScript_CancelStrength
	closemessage
	playse SE_M_VITAL_THROW2
	delay 4
	applymovement LOCALID_SURFER_2, DewfordGymNew_Movement_PushSurfer2
	waitmovement 0
	removeobject LOCALID_SURFER_2
	setflag FLAG_TEMP_5
	clearflag FLAG_TEMP_15
	addobject LOCALID_SURFER_POST_2
	playse SE_M_DIVE
	delay 8
	setmetatile 44, 7, METATILE_General_CalmWater, TRUE
	setmetatile 45, 7, METATILE_General_CalmWater, FALSE
	setmetatile 46, 7, METATILE_General_CalmWater, FALSE
	setmetatile 47, 7, METATILE_General_CalmWater, FALSE
	setmetatile 48, 7, METATILE_General_CalmWater, FALSE
	setmetatile 49, 7, METATILE_General_CalmWater, FALSE
	setmetatile 50, 7, METATILE_General_CalmWater, FALSE
	setmetatile 51, 7, METATILE_General_CalmWater, FALSE
	setmetatile 52, 7, METATILE_General_CalmWater, FALSE
	setmetatile 53, 7, METATILE_General_CalmWater, FALSE
	setmetatile 54, 7, METATILE_General_CalmWater, FALSE
	setmetatile 55, 7, METATILE_General_CalmWater, FALSE
	setmetatile 56, 7, METATILE_General_CalmWater, FALSE
	setmetatile 57, 7, METATILE_General_CalmWater, FALSE
	setmetatile 56, 6, METATILE_General_CalmWater, FALSE
	setmetatile 57, 6, METATILE_General_CalmWater, FALSE
	special DrawWholeMapView
	releaseall
	end

DewfordGymNew_Movement_PushSurfer2:
	slide_up
	step_end

DewfordGymNew_EventScript_StrengthSurfer2Post::
	lock
	msgbox DewfordGymNew_Text_InTheWater, MSGBOX_AUTOCLOSE
	release
	end

DewfordGymNew_EventScript_StrengthSurfer3::
	lockall
	faceplayer
	trainerbattle_single TRAINER_P_CASPIAN, DewfordGymNew_Text_CaspianIntro, DewfordGymNew_Text_CaspianDefeated, DewfordGymNew_EventScript_StrengthSurfer3AfterBattle
	releaseall
	end

DewfordGymNew_EventScript_StrengthSurfer3AfterBattle::
	lockall
	delay 4
	msgbox DewfordGymNew_Text_IWillJumpOutOfRespect, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SURFER_3, DewfordGymNew_Movement_PushSurfer3
	waitmovement 0
	removeobject LOCALID_SURFER_3
	setflag FLAG_TEMP_6
	clearflag FLAG_TEMP_16
	addobject LOCALID_SURFER_POST_3
	playse SE_M_DIVE
	delay 8
	setmetatile 17, 7, METATILE_General_CalmWater, FALSE
	setmetatile 18, 7, METATILE_General_CalmWater, TRUE
	setmetatile 19, 7, METATILE_General_CalmWater, FALSE
	setmetatile 20, 7, METATILE_General_CalmWater, FALSE
	setmetatile 21, 7, METATILE_General_CalmWater, FALSE
	setmetatile 22, 7, METATILE_General_CalmWater, FALSE
	setmetatile 23, 7, METATILE_General_CalmWater, FALSE
	setmetatile 24, 7, METATILE_General_CalmWater, FALSE
	setmetatile 25, 7, METATILE_General_CalmWater, FALSE
	setmetatile 26, 7, METATILE_General_CalmWater, FALSE
	setmetatile 27, 7, METATILE_General_CalmWater, FALSE
	setmetatile 28, 7, METATILE_General_CalmWater, FALSE
	setmetatile 29, 7, METATILE_General_CalmWater, FALSE
	setmetatile 30, 7, METATILE_General_CalmWater, FALSE
	setmetatile 31, 7, METATILE_General_CalmWater, FALSE
	setmetatile 32, 7, METATILE_General_CalmWater, FALSE
	setmetatile 33, 7, METATILE_General_CalmWater, FALSE
	setmetatile 34, 7, METATILE_General_CalmWater, FALSE
	setmetatile 35, 7, METATILE_General_CalmWater, FALSE
	setmetatile 36, 7, METATILE_General_CalmWater, FALSE
	setmetatile 37, 7, METATILE_General_CalmWater, FALSE
	setmetatile 38, 7, METATILE_General_CalmWater, FALSE
	setmetatile 39, 7, METATILE_General_CalmWater, FALSE
	setmetatile 40, 7, METATILE_General_CalmWater, FALSE
	special DrawWholeMapView
	releaseall
	end

DewfordGymNew_Movement_PushSurfer3:
	jump_up
	step_end

DewfordGymNew_EventScript_StrengthSurfer3Post::
	lock
	msgbox DewfordGymNew_Text_InTheWater, MSGBOX_AUTOCLOSE
	release
	end

DewfordGymNew_EventScript_StrengthSurfer4::
	lockall
	goto_if_unset FLAG_BADGE05_GET, DewfordGymNew_EventScript_CantStrength
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, DewfordGymNew_EventScript_CantStrength
	msgbox DewfordGymNew_Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DewfordGymNew_EventScript_CancelStrength
	closemessage
	playse SE_M_VITAL_THROW2
	delay 4
	applymovement LOCALID_SURFER_4, DewfordGymNew_Movement_PushSurfer4
	waitmovement 0
	removeobject LOCALID_SURFER_4
	setflag FLAG_TEMP_7
	clearflag FLAG_TEMP_17
	addobject LOCALID_SURFER_POST_4
	playse SE_M_DIVE
	delay 8
	setmetatile 16, 6, METATILE_General_CalmWater, FALSE
	setmetatile 17, 6, METATILE_General_CalmWater, FALSE
	setmetatile 18, 6, METATILE_General_CalmWater, TRUE
	setmetatile 19, 6, METATILE_General_CalmWater, FALSE
	setmetatile 20, 6, METATILE_General_CalmWater, FALSE
	setmetatile 21, 6, METATILE_General_CalmWater, FALSE
	setmetatile 22, 6, METATILE_General_CalmWater, FALSE
	setmetatile 23, 6, METATILE_General_CalmWater, FALSE
	setmetatile 24, 6, METATILE_General_CalmWater, FALSE
	setmetatile 25, 6, METATILE_General_CalmWater, FALSE
	setmetatile 26, 6, METATILE_General_CalmWater, FALSE
	setmetatile 27, 6, METATILE_General_CalmWater, FALSE
	setmetatile 28, 6, METATILE_General_CalmWater, FALSE
	setmetatile 29, 6, METATILE_General_CalmWater, FALSE
	setmetatile 30, 6, METATILE_General_CalmWater, FALSE
	setmetatile 31, 6, METATILE_General_CalmWater, FALSE
	setmetatile 32, 6, METATILE_General_CalmWater, FALSE
	setmetatile 33, 6, METATILE_General_CalmWater, FALSE
	setmetatile 34, 6, METATILE_General_CalmWater, FALSE
	setmetatile 35, 6, METATILE_General_CalmWater, FALSE
	setmetatile 36, 6, METATILE_General_CalmWater, FALSE
	setmetatile 37, 6, METATILE_General_CalmWater, FALSE
	setmetatile 38, 6, METATILE_General_CalmWater, FALSE
	setmetatile 39, 6, METATILE_General_CalmWater, FALSE
	setmetatile 40, 6, METATILE_General_CalmWater, FALSE
	setmetatile 41, 6, METATILE_General_CalmWater, FALSE
	special DrawWholeMapView
	releaseall
	end

DewfordGymNew_Movement_PushSurfer4:
	slide_down
	step_end

DewfordGymNew_EventScript_StrengthSurfer4Post::
	lock
	msgbox DewfordGymNew_Text_InTheWater, MSGBOX_AUTOCLOSE
	release
	end

DewfordGymNew_EventScript_CantStrength::
	msgbox DewfordGymNew_Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

DewfordGymNew_EventScript_CancelStrength::
	closemessage
	releaseall
	end

DewfordGymNew_EventScript_GymBattle::
	lock
	speakername DewfordGymNew_Text_NameBrawly
	msgbox DewfordGymNew_Text_LookWhatWashedUp, MSGBOX_DEFAULT
	speakername DewfordGymNew_Text_NameShelly
	msgbox DewfordGymNew_Text_TimeToBattle, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_BRAWLY, DewfordGymNew_Text_BrawlyDefeat, TRAINER_P_SHELLY_1, DewfordGymNew_Text_ShellyDefeat, DewfordGymNew_EventScript_LeadersDefeated, NO_MUSIC
	goto DewfordGymNew_EventScript_LeadersDefeated
	release
	end

DewfordGymNew_EventScript_LeadersDefeated::
	speakername DewfordGymNew_Text_NameBrawly
	msgbox DewfordGymNew_Text_YouDidIt, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 8
	giveitem ITEM_TM_BODY_PRESS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_SCALD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername NULL
	message DewfordGymNew_Text_ReceivedBeachBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername DewfordGymNew_Text_NameShelly
	msgbox DewfordGymNew_Text_ByeBye, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_DEWFORD_NEW, 37, 26
	waitstate
	release
	end

DewfordGymNew_EventScript_Tahoe::
    trainerbattle_single TRAINER_P_TAHOE, DewfordGymNew_Text_TahoeIntro, DewfordGymNew_Text_TahoeDefeated
    msgbox DewfordGymNew_Text_TahoePostBattle, MSGBOX_AUTOCLOSE
    end

DewfordGymNew_EventScript_Huron::
    trainerbattle_single TRAINER_P_HURON, DewfordGymNew_Text_HuronIntro, DewfordGymNew_Text_HuronDefeated
    msgbox DewfordGymNew_Text_HuronPostBattle, MSGBOX_AUTOCLOSE
    end

DewfordGymNew_EventScript_Eyre::
    trainerbattle_single TRAINER_P_EYRE, DewfordGymNew_Text_EyreIntro, DewfordGymNew_Text_EyreDefeated
    msgbox DewfordGymNew_Text_EyrePostBattle, MSGBOX_AUTOCLOSE
    end

DewfordGymNew_EventScript_Victoria::
    trainerbattle_single TRAINER_P_VICTORIA, DewfordGymNew_Text_VictoriaIntro, DewfordGymNew_Text_VictoriaDefeated
    msgbox DewfordGymNew_Text_VictoriaPostBattle, MSGBOX_AUTOCLOSE
    end

DewfordGymNew_EventScript_Albert::
    trainerbattle_single TRAINER_P_ALBERT, DewfordGymNew_Text_AlbertIntro, DewfordGymNew_Text_AlbertDefeated
    msgbox DewfordGymNew_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
    end

DewfordGymNew_EventScript_Marcel::
    trainerbattle_single TRAINER_P_MARCEL, DewfordGymNew_Text_MarcelIntro, DewfordGymNew_Text_MarcelDefeated
    msgbox DewfordGymNew_Text_MarcelPostBattle, MSGBOX_AUTOCLOSE
    end

DewfordGymNew_EventScript_Nessie::
    trainerbattle_single TRAINER_P_NESSIE, DewfordGymNew_Text_NessieIntro, DewfordGymNew_Text_NessieDefeated
    msgbox DewfordGymNew_Text_NessiePostBattle, MSGBOX_AUTOCLOSE
    end

DewfordGymNew_Text_TahoeIntro:
	.string "intro$"

DewfordGymNew_Text_TahoeDefeated:
	.string "defeat$"

DewfordGymNew_Text_TahoePostBattle:
	.string "post$"

DewfordGymNew_Text_HuronIntro:
	.string "intro$"

DewfordGymNew_Text_HuronDefeated:
	.string "defeat$"

DewfordGymNew_Text_HuronPostBattle:
	.string "post$"

DewfordGymNew_Text_EyreIntro:
	.string "intro$"

DewfordGymNew_Text_EyreDefeated:
	.string "defeat$"

DewfordGymNew_Text_EyrePostBattle:
	.string "post$"

DewfordGymNew_Text_VictoriaIntro:
	.string "intro$"

DewfordGymNew_Text_VictoriaDefeated:
	.string "defeat$"

DewfordGymNew_Text_VictoriaPostBattle:
	.string "post$"

DewfordGymNew_Text_AlbertIntro:
	.string "intro$"

DewfordGymNew_Text_AlbertDefeated:
	.string "defeat$"

DewfordGymNew_Text_AlbertPostBattle:
	.string "post$"

DewfordGymNew_Text_MarcelIntro:
	.string "intro$"

DewfordGymNew_Text_MarcelDefeated:
	.string "defeat$"

DewfordGymNew_Text_MarcelPostBattle:
	.string "post$"

DewfordGymNew_Text_NessieIntro:
	.string "intro$"

DewfordGymNew_Text_NessieDefeated:
	.string "defeat$"

DewfordGymNew_Text_NessiePostBattle:
	.string "post$"

DewfordGymNew_Text_WantToStrength:
	.string "It's a man. A Pokémon\n"
	.string "may be able to push him aside.\p"
	.string "Would you like to use Strength?$"

DewfordGymNew_Text_MonUsedStrength:
	.string "{STR_VAR_1} used Strength!\p"
	.string "{STR_VAR_1}'s Strength made it\n"
	.string "possible to move boulders around!$"

DewfordGymNew_Text_CantStrength:
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.$"

DewfordGymNew_Text_StrengthActivated:
	.string "Strength made it possible to move\n"
	.string "boulders around.$"

DewfordGymNew_Text_InTheWater:
	.string "He's blocking the flow.$"

DewfordGymNew_Text_CaspianIntro:
	.string "wanna push me? lets fight$"

DewfordGymNew_Text_CaspianDefeated:
	.string "oh no$"

DewfordGymNew_Text_IWillJumpOutOfRespect:
	.string "ill jump cuz that was cool$"

DewfordGymNew_Text_NameBrawly:
	.string "Brawly$"

DewfordGymNew_Text_LookWhatWashedUp:
	.string "wowee cool surfin$"

DewfordGymNew_Text_NameShelly:
	.string "Shelly$"

DewfordGymNew_Text_TimeToBattle:
	.string "time 2 battle$"

DewfordGymNew_Text_BrawlyDefeat:
	.string "B defeat$"

DewfordGymNew_Text_ShellyDefeat:
	.string "S defeat$"

DewfordGymNew_Text_YouDidIt:
	.string "you DID it$"

DewfordGymNew_Text_ReceivedBeachBadge:
	.string "{PLAYER} received the\n"
	.string "Beach Badge\l"
	.string "from Brawly and Shelly.$"

DewfordGymNew_Text_ByeBye:
	.string "bye bye$"
