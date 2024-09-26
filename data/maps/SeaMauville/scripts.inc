.set LOCALID_P_MAN, 11
.set LOCALID_P_MAN2, 9
.set LOCALID_P_MAN3, 12
.set LOCALID_BARD, 8
.set LOCALID_TRADER, 10
.set LOCALID_DRAKE, 7
.set LOCALID_ARCHIE, 5
.set LOCALID_STERN, 6
.set LOCALID_NUE, 2

SeaMauville_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SeaMauville_OnLoad
	.byte 0

SeaMauville_OnLoad:
	call_if_lt VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_SetTraderGfx
	call_if_eq VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_SetBardGfx
	call_if_eq VAR_OLD_GUYS_STATE, 11, SeaMauville_EventScript_SetTraderGfx
	call_if_eq VAR_OLD_GUYS_STATE, 12, SeaMauville_EventScript_SetTraderGfx
	call_if_eq VAR_OLD_GUYS_STATE, 13, SeaMauville_EventScript_SetTraderGfx
	call_if_eq VAR_OLD_GUYS_STATE, 14, SeaMauville_EventScript_SetTraderGfx
	call_if_eq VAR_OLD_GUYS_STATE, 15, SeaMauville_EventScript_SetTraderGfx
	call_if_lt VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_RemoveSeafarers
	call_if_gt VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_RemoveSeafarers
	call SeaMauville_EventScript_RemoveKizuna
	call SeaMauville_EventScript_RemoveNue
	call_if_eq VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_RemoveNob
	call_if_eq VAR_OLD_GUYS_STATE, 10, SeaMauville_EventScript_RemoveNob
	call_if_ge VAR_OLD_GUYS_STATE, 16, SeaMauville_EventScript_RemoveNob
	end

SeaMauville_EventScript_SetTraderGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_TRADER
	special SetMauvilleOldManObjEventGfx
	return

SeaMauville_EventScript_SetBardGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_BARD
	special SetMauvilleOldManObjEventGfx
	return

SeaMauville_EventScript_RemoveSeafarers::
	removeobject LOCALID_ARCHIE
	setflag FLAG_TEMP_14
	removeobject LOCALID_STERN
	setflag FLAG_TEMP_15
	removeobject LOCALID_DRAKE
	setflag FLAG_TEMP_16
	removeobject LOCALID_BARD
	setflag FLAG_TEMP_17
	removeobject LOCALID_P_MAN2
	setflag FLAG_TEMP_18
	return

SeaMauville_EventScript_RemoveKizuna::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	removeobject LOCALID_P_MAN3
	setflag FLAG_TEMP_19
	return

SeaMauville_EventScript_RemoveNue::
	removeobject LOCALID_NUE
	setflag FLAG_TEMP_13
	return

SeaMauville_EventScript_RemoveNob::
	removeobject LOCALID_TRADER
	setflag FLAG_TEMP_12
	return	

SeaMauville_EventScript_BrineyFastTravel::
	lock
	faceplayer
	goto_if_eq VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_BrineyGoToSouthernIsland
	speakername SeaMauville_Text_NameBriney
	msgbox SeaMauville_Text_WantToVoyage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SeaMauville_EventScript_WarpToTidal
	msgbox SeaMauville_Text_IllBeHere, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SeaMauville_EventScript_WarpToTidal::
	msgbox SeaMauville_Text_BonVoyage, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_SS_TIDAL_MID_TERIORS, 33, 4
	release
	end

SeaMauville_EventScript_BrineyGoToSouthernIsland::
	speakername SeaMauville_Text_NameBriney
	msgbox SeaMauville_Text_ReadyForSouthernIsland, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SeaMauville_EventScript_WarpToSouthernIsland
	msgbox SeaMauville_Text_IllBeHere, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SeaMauville_EventScript_WarpToSouthernIsland::
	setvar VAR_OLD_GUYS_STATE, 10
	msgbox SeaMauville_Text_BonVoyage, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_SOUTHERN_ISLAND, 5, 3
	release
	end

SeaMauville_EventScript_DrakeIdle::
	speakername SeaMauville_Text_NameDrake
	msgbox SeaMauville_Text_DrakeIdle, MSGBOX_NPC
	end

SeaMauville_EventScript_ArchieIdle::
	speakername SeaMauville_Text_NameArchie
	msgbox SeaMauville_Text_ArchieIdle, MSGBOX_NPC
	end

SeaMauville_EventScript_SternIdle::
	speakername SeaMauville_Text_NameStern
	msgbox SeaMauville_Text_SternIdle, MSGBOX_NPC
	end

SeaMauville_EventScript_KizunaIdle::
	speakername SeaMauville_Text_NameKizuna
	msgbox SeaMauville_Text_KizunaIdle, MSGBOX_NPC
	end

SeaMauville_EventScript_DockIdle::
	speakername SeaMauville_Text_NameDock
	msgbox SeaMauville_Text_DockIdle, MSGBOX_NPC
	end

SeaMauville_EventScript_MustSail::
	lock
	msgbox SeaMauville_Text_MustSail, MSGBOX_AUTOCLOSE 
	applymovement OBJ_EVENT_ID_PLAYER, SeaMauville_Movement_WalkRight
	waitmovement 0
	release
	end

SeaMauville_Movement_WalkRight:
	walk_right
	step_end

SeaMauville_EventScript_PostIslandUpperTrigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, SeaMauville_Movement_MoveToRight
	goto SeaMauville_EventScript_KizunaPostIsland
	release
	end

SeaMauville_EventScript_KizunaPostIsland::
	lock
	clearflag FLAG_TEMP_19
	addobject LOCALID_P_MAN3
	playse SE_DOOR
	waitse
	applymovement LOCALID_P_MAN3, SeaMauville_Movement_KizunaGetOffShip
	waitmovement 0
	speakername SeaMauville_Text_NameKizuna
	msgbox SeaMauville_Text_AboutDock, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_P_MAN3, SeaMauville_Movement_KizunaGoToMarket
	waitmovement 0
	setvar VAR_OLD_GUYS_STATE, 12
	removeobject LOCALID_P_MAN3
	setflag FLAG_TEMP_19
	release
	end

SeaMauville_Movement_MoveToRight:
	walk_right
	face_down
	step_end

SeaMauville_Movement_KizunaGetOffShip:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

SeaMauville_Movement_KizunaGoToMarket:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SeaMauville_EventScript_Nob::
	lock
	faceplayer
	goto_if_lt VAR_OLD_GUYS_STATE, 12, SeaMauville_EventScript_NobPreDock
	goto_if_eq VAR_OLD_GUYS_STATE, 13, SeaMauville_EventScript_NobStartedQuest
	goto_if_eq VAR_OLD_GUYS_STATE, 14, SeaMauville_EventScript_NobStartedQuest
	goto_if_eq VAR_OLD_GUYS_STATE, 15, SeaMauville_EventScript_NobRetire
	msgbox SeaMauville_Text_TraderGreeting, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLD_GUYS_STATE, 13
	clearflag FLAG_TEMP_11
	addobject LOCALID_P_MAN
	delay 8
	applymovement LOCALID_P_MAN, SeaMauville_Movement_KizunaGreetNob
	waitmovement 0
	speakername SeaMauville_Text_NameKizuna
	msgbox SeaMauville_Text_HesSpeakingJapanese, MSGBOX_DEFAULT
	speakername SeaMauville_Text_NameNob
	msgbox SeaMauville_Text_IWantThis, MSGBOX_DEFAULT
	speakername SeaMauville_Text_NameKizuna
	msgbox SeaMauville_Text_LetsTryAndFigureItOut, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_Movement_KizunaGreetNob:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SeaMauville_EventScript_NobPreDock::
	msgbox SeaMauville_Text_NobPreDock, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_EventScript_NobStartedQuest::
	speakername SeaMauville_Text_NameNob
	msgbox SeaMauville_Text_NobStartedQuest, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_EventScript_NobRetire::
	speakername SeaMauville_Text_NameNob
	msgbox SeaMauville_Text_IWillTradeForThatItem, MSGBOX_DEFAULT
	giveitem ITEM_LOADED_DICE, 1
	speakername SeaMauville_Text_NameNob
	msgbox SeaMauville_Text_ThanksForYourTime, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_TEMP_11
	addobject LOCALID_P_MAN
	delay 8
	applymovement LOCALID_P_MAN, SeaMauville_Movement_KizunaGreetNob
	waitmovement 0
	speakername SeaMauville_Text_NameKizuna
	msgbox SeaMauville_Text_YouAllSet, MSGBOX_DEFAULT
	fadenewbgm MUS_VERDANTURF
	speakername SeaMauville_Text_NameNob
	msgbox SeaMauville_Text_YesItsMyTimeToGo, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SeaMauville_Movement_PlayerMoveOutOfWay
	waitmovement 0
	playse SE_M_MEGA_KICK
	applymovement LOCALID_P_MAN, SeaMauville_Movement_KizunaAbsorbNob
	waitmovement 0
	removeobject LOCALID_TRADER
	setflag FLAG_TEMP_12
	setvar VAR_OLD_GUYS_STATE, 16
	playse SE_M_FAINT_ATTACK
	waitse
	fadenewbgm MUS_NONE
	applymovement LOCALID_P_MAN, SeaMauville_Movement_KizunaFormUp
	waitmovement 0
	speakername SeaMauville_Text_NameKizuna
	msgbox SeaMauville_Text_OneMoreToGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_P_MAN, SeaMauville_Movement_KizunaWalkAway
	waitmovement 0
	fadenewbgm MUS_SLATEPORT
	delay 16
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	release
	end

SeaMauville_Movement_PlayerMoveOutOfWay:
	walk_right
	delay_4
	face_left
	step_end

SeaMauville_Movement_KizunaAbsorbNob:
	walk_fast_right
	walk_slow_up
	step_end

SeaMauville_Movement_KizunaFormUp:
	walk_slow_down
	delay_8
	face_right
	step_end

SeaMauville_Movement_KizunaWalkAway:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

SeaMauville_EventScript_KizunaIdle2::
	speakername SeaMauville_Text_NameKizuna
	msgbox SeaMauville_Text_KizunaIdle2, MSGBOX_NPC
	end

SeaMauville_EventScript_SuitcaseInterceptor::
	lock
	faceplayer
	goto_if_eq VAR_OLD_GUYS_STATE, 13, SeaMauville_EventScript_GoGetThatSuitcase
	goto_if_eq VAR_OLD_GUYS_STATE, 14, SeaMauville_EventScript_SuitcaseInstructions
	goto_if_eq VAR_OLD_GUYS_STATE, 14, SeaMauville_EventScript_TradeSuitcaseForTeachyTV
	goto_if_gt VAR_OLD_GUYS_STATE, 15, SeaMauville_EventScript_ThanksForSuitcase
	msgbox SeaMauville_Text_ImUpToNoGood, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_EventScript_GoGetThatSuitcase::
	setvar VAR_OLD_GUYS_STATE, 14
	msgbox SeaMauville_Text_GoGetMeASuitcase, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_EventScript_SuitcaseInstructions::
	msgbox SeaMauville_Text_SuitcaseInstructions, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_EventScript_TradeSuitcaseForTeachyTV::
	msgbox SeaMauville_Text_YouGotTheStuff, MSGBOX_DEFAULT
	removeitem ITEM_DEVON_PARTS, 1
	giveitem ITEM_TEACHY_TV
	msgbox SeaMauville_Text_ThanksForSuitcase, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_EventScript_ThanksForSuitcase::
	msgbox SeaMauville_Text_ThanksForSuitcase, MSGBOX_AUTOCLOSE
	release
	end

SeaMauville_EventScript_Nue::
    trainerbattle_single TRAINER_P_NUE, SeaMauville_Text_NueIntro, SeaMauville_Text_NueDefeated
    msgbox SeaMauville_Text_NuePostBattle, MSGBOX_AUTOCLOSE
    end

SeaMauville_EventScript_Gary::
    trainerbattle_single TRAINER_P_GARY, SeaMauville_Text_GaryIntro, SeaMauville_Text_GaryDefeated
    msgbox SeaMauville_Text_GaryPostBattle, MSGBOX_AUTOCLOSE
    end

SeaMauville_Text_NameBriney:
	.string "Cpt. Briney$"

SeaMauville_Text_NameKizuna:
	.string "Kizuna$"

SeaMauville_Text_NameArchie:
	.string "Archie$"

SeaMauville_Text_NameDrake:
	.string "Drake$"

SeaMauville_Text_NameStern:
	.string "Cpt. Stern$"

SeaMauville_Text_NameDock:
	.string "Dock$"

SeaMauville_Text_NameNob:
	.string "Nob$"

SeaMauville_Text_NueIntro:
	.string "intro$"

SeaMauville_Text_NueDefeated:
	.string "defeat$"

SeaMauville_Text_NuePostBattle:
	.string "post$"

SeaMauville_Text_GaryIntro:
	.string "intro$"

SeaMauville_Text_GaryDefeated:
	.string "defeat$"

SeaMauville_Text_GaryPostBattle:
	.string "post$"

SeaMauville_Text_WantToVoyage:
	.string "wanna go to ss tidle$"

SeaMauville_Text_IllBeHere:
	.string "ill be waitin$"

SeaMauville_Text_BonVoyage:
	.string "bon voyage$"

SeaMauville_Text_ReadyForSouthernIsland:
	.string "ready for the south?$"

SeaMauville_Text_DrakeIdle:
	.string "yarr im drake$"

SeaMauville_Text_KizunaIdle:
	.string "this shit cray man$"

SeaMauville_Text_ArchieIdle:
	.string "team gackwag$"

SeaMauville_Text_SternIdle:
	.string "stern goes bwah like angru bird$"

SeaMauville_Text_DockIdle:
	.string "DOCK TEXT$"

SeaMauville_Text_MustSail:
	.string "must sail$"

SeaMauville_Text_AboutDock:
	.string "so whats dock deal\p"
	.string "anyways letsgo to market$"

SeaMauville_Text_TraderGreeting:
	.string "$"

SeaMauville_Text_HesSpeakingJapanese:
	.string "$"

SeaMauville_Text_IWantThis:
	.string "$"

SeaMauville_Text_LetsTryAndFigureItOut:
	.string "$"

SeaMauville_Text_NobPreDock:
	.string "$"

SeaMauville_Text_NobStartedQuest:
	.string "$"

SeaMauville_Text_IWillTradeForThatItem:
	.string "$"

SeaMauville_Text_ThanksForYourTime:
	.string "$"

SeaMauville_Text_YouAllSet:
	.string "$"

SeaMauville_Text_YesItsMyTimeToGo:
	.string "$"

SeaMauville_Text_OneMoreToGo:
	.string "$"

SeaMauville_Text_KizunaIdle2:
	.string "figure it out ig$"

SeaMauville_Text_ImUpToNoGood:
	.string "$"

SeaMauville_Text_GoGetMeASuitcase:
	.string "$"

SeaMauville_Text_SuitcaseInstructions:
	.string "$"

SeaMauville_Text_YouGotTheStuff:
	.string "$"

SeaMauville_Text_ThanksForSuitcase:
	.string "$"
