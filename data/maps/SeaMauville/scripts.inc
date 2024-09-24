.set LOCALID_P_MAN, 11
.set LOCALID_P_MAN2, 9
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
	call_if_lt VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_RemoveSeafarers
	call_if_gt VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_RemoveSeafarers
	call SeaMauville_EventScript_RemoveKizuna
	call SeaMauville_EventScript_RemoveNue
	call_if_eq VAR_OLD_GUYS_STATE, 9, SeaMauville_EventScript_RemoveNob
	call_if_eq VAR_OLD_GUYS_STATE, 10, SeaMauville_EventScript_RemoveNob
	call_if_gt VAR_OLD_GUYS_STATE, 14, SeaMauville_EventScript_RemoveNob
	end

SeaMauville_EventScript_SetTraderGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_TRADER
	special SetMauvilleOldManObjEventGfx
	end

SeaMauville_EventScript_SetBardGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_BARD
	special SetMauvilleOldManObjEventGfx
	end

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
	release
	end

SeaMauville_Movement_WalkRight:
	walk_right
	step_end

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
