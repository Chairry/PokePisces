.set LOCALID_P_MAN, 8
.set LOCALID_BARD, 4
.set LOCALID_BRINEY, 7
.set LOCALID_BRINEY2, 2
.set LOCALID_DRAKE, 5
.set LOCALID_ARCHIE, 3
.set LOCALID_STERN, 6

SouthernIsland_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SouthernIsland_OnLoad
	.byte 0

SouthernIsland_OnLoad:
	call_if_eq VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_RemoveBriney2
	call_if_eq VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_SetBardGfx
	call_if_lt VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_RemoveSeafarers
	call_if_gt VAR_OLD_GUYS_STATE, 10, SouthernIsland_EventScript_RemoveSeafarers
	end

SouthernIsland_EventScript_SetBardGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_BARD
	special SetMauvilleOldManObjEventGfx
	end

SouthernIsland_EventScript_RemoveSeafarers::
	removeobject LOCALID_ARCHIE
	setflag FLAG_TEMP_14
	removeobject LOCALID_STERN
	setflag FLAG_TEMP_15
	removeobject LOCALID_DRAKE
	setflag FLAG_TEMP_16
	removeobject LOCALID_BARD
	setflag FLAG_TEMP_17
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	removeobject LOCALID_BRINEY
	setflag FLAG_TEMP_12
	return

SouthernIsland_EventScript_RemoveBriney2::
	removeobject LOCALID_BRINEY2
	setflag FLAG_TEMP_13
	return

SouthernIsland_EventScript_BrineyFastTravel::
	lock
	faceplayer
	speakername SouthernIsland_Text_NameBriney
	msgbox SouthernIsland_Text_WantToVoyage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SouthernIsland_EventScript_WarpToTidal
	msgbox SouthernIsland_Text_IllBeHere, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SouthernIsland_EventScript_WarpToTidal::
	msgbox SouthernIsland_Text_BonVoyage, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_SS_TIDAL_MID_TERIORS, 33, 4
	release
	end

SouthernIsland_EventScript_BardSingsSong::
	lock
	applymovement LOCALID_P_MAN, SouthernIsland_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, SouthernIsland_Movement_JoinParty
	waitmovement 0
	applymovement LOCALID_P_MAN, SouthernIsland_Movement_FaceLeft
	applymovement LOCALID_BARD, SouthernIsland_Movement_LookAround
	waitmovement 0
	speakername SouthernIsland_Text_NameDock
	msgbox SouthernIsland_Text_ISeeEveryoneHasGathered, MSGBOX_DEFAULT
	speakername SouthernIsland_Text_NameBriney
	msgbox SouthernIsland_Text_SingYourSongBro, MSGBOX_DEFAULT
	speakername SouthernIsland_Text_NameStern
	msgbox SouthernIsland_Text_ImExcited, MSGBOX_DEFAULT
	fadenewbgm MUS_NONE
	speakername SouthernIsland_Text_NameDock
	msgbox SouthernIsland_Text_Ahem, MSGBOX_DEFAULT
	closemessage
	fadenewbgm MUS_END
	delay 16
	delay 16
	speakername SouthernIsland_Text_NameDock
	msgbox SouthernIsland_Text_SongLyrics, MSGBOX_DEFAULT
	closemessage
	delay 16
	delay 16
	fadenewbgm MUS_NONE
	speakername SouthernIsland_Text_NameStern
	msgbox SouthernIsland_Text_ThatWasGreat, MSGBOX_DEFAULT
	speakername SouthernIsland_Text_NameDrake
	msgbox SouthernIsland_Text_TakesMeBack, MSGBOX_DEFAULT
	applymovement LOCALID_BARD, SouthernIsland_Movement_FaceRight
	fadenewbgm MUS_VERDANTURF
	speakername SouthernIsland_Text_NameDock
	msgbox SouthernIsland_Text_ItsTimeToRetire, MSGBOX_DEFAULT
	speakername SouthernIsland_Text_NameKizuna
	msgbox SouthernIsland_Text_AsYouWish, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_P_MAN, SouthernIsland_Movement_KizunaFormUp
	waitmovement 0
	playse SE_M_MEGA_KICK
	applymovement LOCALID_P_MAN, SouthernIsland_Movement_KizunaAbsorbGiddy
	waitmovement 0
	removeobject LOCALID_BARD
	setflag FLAG_TEMP_17
	setvar VAR_OLD_GUYS_STATE, 11
	playse SE_M_FAINT_ATTACK
	waitse
	applymovement LOCALID_ARCHIE, SouthernIsland_Movement_ArchieWalkToKizuna
	speakername SouthernIsland_Text_NameArchie
	msgbox SouthernIsland_Text_DockYouveOutdoneYourself, MSGBOX_DEFAULT
	applymovement LOCALID_P_MAN, SouthernIsland_Movement_Question
	speakername SouthernIsland_Text_NameKizuna
	msgbox SouthernIsland_Text_What, MSGBOX_DEFAULT
	speakername SouthernIsland_Text_NameStern
	msgbox SouthernIsland_Text_DontBeModest, MSGBOX_DEFAULT
	speakername SouthernIsland_Text_NameBriney
	msgbox SouthernIsland_Text_LetsHitTheSea, MSGBOX_DEFAULT
	warp MAP_SEA_MAUVILLE, 44, 54
	waitstate
	release
	end

SouthernIsland_Movement_FaceRight:
	face_right
	step_end

SouthernIsland_Movement_JoinParty:
	walk_left
	walk_left
	step_end

SouthernIsland_Movement_FaceLeft:
	face_left
	step_end

SouthernIsland_Movement_LookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_down
	delay_8
	step_end

SouthernIsland_Movement_KizunaFormUp:
	walk_left
	walk_left
	walk_left
	walk_up
	face_left
	step_end

SouthernIsland_Movement_KizunaAbsorbGiddy:
	walk_slow_left
	step_end

SouthernIsland_Movement_ArchieWalkToKizuna:
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

SouthernIsland_Movement_Question:
	emote_question_mark
	face_down
	step_end

SouthernIsland_Text_NameDock:
	.string "Dock$"

SouthernIsland_Text_NameBriney:
	.string "Cpt. Briney$"

SouthernIsland_Text_NameStern:
	.string "Cpt. Stern$"

SouthernIsland_Text_NameDrake:
	.string "Drake$"

SouthernIsland_Text_NameKizuna:
	.string "Kizuna$"

SouthernIsland_Text_NameArchie:
	.string "Archie$"

SouthernIsland_Text_WantToVoyage:
	.string "wanna go to ss tidle$"

SouthernIsland_Text_IllBeHere:
	.string "ill be waitin$"

SouthernIsland_Text_BonVoyage:
	.string "bon voyage$"

SouthernIsland_Text_ISeeEveryoneHasGathered:
	.string "I see yall here now$"

SouthernIsland_Text_SingYourSongBro:
	.string "sing that mf song$"

SouthernIsland_Text_ImExcited:
	.string "im excited$"

SouthernIsland_Text_Ahem:
	.string "Ahem.$"

SouthernIsland_Text_SongLyrics:
	.string "Those whose memories fade seek to\n"
	.string "carve them in their hearts...\p"
	.string "All dreams are but another reality.\n"
	.string "Never forget...$"

SouthernIsland_Text_ThatWasGreat:
	.string "epic$"

SouthernIsland_Text_TakesMeBack:
	.string "takes me back boyo$"

SouthernIsland_Text_ItsTimeToRetire:
	.string "time 2 retire now$"

SouthernIsland_Text_AsYouWish:
	.string "as you wish$"

SouthernIsland_Text_DockYouveOutdoneYourself:
	.string "dock youre so cool$"

SouthernIsland_Text_What:
	.string "what$"

SouthernIsland_Text_DontBeModest:
	.string "dont be modest$"

SouthernIsland_Text_LetsHitTheSea:
	.string "lets hit it (hits it)$"
