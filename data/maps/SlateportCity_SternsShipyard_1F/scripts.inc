.set LOCALID_BARD, 1
.set LOCALID_P_MAN, 4

SlateportCity_SternsShipyard_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SlateportCity_SternsShipyard_1F_OnLoad
	.byte 0

SlateportCity_SternsShipyard_1F_OnLoad:
	call_if_lt VAR_OLD_GUYS_STATE, 9, SlateportCity_SternsShipyard_1F_EventScript_SetBardGfx
	call SlateportCity_SternsShipyard_1F_EventScript_RemoveKizuna
	call_if_ge VAR_OLD_GUYS_STATE, 9, SlateportCity_SternsShipyard_1F_EventScript_RemoveDock
	end

SlateportCity_SternsShipyard_1F_EventScript_SetBardGfx::
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_BARD
	special SetMauvilleOldManObjEventGfx
	end

SlateportCity_SternsShipyard_1F_EventScript_RemoveKizuna::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

SlateportCity_SternsShipyard_1F_EventScript_RemoveDock::
	removeobject LOCALID_BARD
	setflag FLAG_TEMP_12
	return	

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_QUEST_FOUND_STERN, SlateportCity_SternsShipyard_1F_EventScript_DockCheckDrake
	goto_if_lt VAR_OLD_GUYS_STATE, 7, SlateportCity_SternsShipyard_1F_EventScript_DockPreRydel
	goto_if_eq VAR_OLD_GUYS_STATE, 8, SlateportCity_SternsShipyard_1F_EventScript_DockDuringMission
	msgbox SlateportCity_SternsShipyard_1F_Text_IAmTheBard, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	clearflag FLAG_TEMP_11
	addobject LOCALID_P_MAN
	applymovement LOCALID_P_MAN, SlateportCity_SternsShipyard_1F_Movement_KizunaEnters
	waitmovement 0
	speakername SlateportCity_SternsShipyard_1F_Text_NameKizuna
	msgbox SlateportCity_SternsShipyard_1F_Text_YoureOurNextGuy, MSGBOX_DEFAULT
	speakername SlateportCity_SternsShipyard_1F_Text_NameDock
	msgbox SlateportCity_SternsShipyard_1F_Text_BeforeIRetire, MSGBOX_DEFAULT
	speakername SlateportCity_SternsShipyard_1F_Text_NameKizuna
	msgbox SlateportCity_SternsShipyard_1F_Text_WeCanDoThat, MSGBOX_DEFAULT
	setvar VAR_OLD_GUYS_STATE, 8
	closemessage
	release
	end

SlateportCity_SternsShipyard_1F_Movement_KizunaEnters:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_SternsShipyard_1F_EventScript_DockCheckDrake::
	goto_if_set FLAG_DOCK_QUEST_FOUND_DRAKE, SlateportCity_SternsShipyard_1F_EventScript_DockCheckArchie
	speakername SlateportCity_SternsShipyard_1F_Text_NameDock
	msgbox SlateportCity_SternsShipyard_1F_Text_DockDuringMission, MSGBOX_AUTOCLOSE
	release
	end	

SlateportCity_SternsShipyard_1F_EventScript_DockCheckArchie::
	goto_if_set FLAG_DOCK_QUEST_FOUND_DRAKE, SlateportCity_SternsShipyard_1F_EventScript_DockFoundAll
	speakername SlateportCity_SternsShipyard_1F_Text_NameDock
	msgbox SlateportCity_SternsShipyard_1F_Text_DockDuringMission, MSGBOX_AUTOCLOSE
	release
	end	

SlateportCity_SternsShipyard_1F_EventScript_DockFoundAll::
	speakername SlateportCity_SternsShipyard_1F_Text_NameDock
	msgbox SlateportCity_SternsShipyard_1F_Text_TheyreAllReady, MSGBOX_DEFAULT
	setvar VAR_OLD_GUYS_STATE, 9
	warp MAP_SEA_MAUVILLE, 41, 54
	closemessage
	release
	end

SlateportCity_SternsShipyard_1F_EventScript_DockPreRydel::
	msgbox SlateportCity_SternsShipyard_1F_Text_DockPreRydel, MSGBOX_AUTOCLOSE
	release
	end	

SlateportCity_SternsShipyard_1F_EventScript_DockDuringMission::
	speakername SlateportCity_SternsShipyard_1F_Text_NameDock
	msgbox SlateportCity_SternsShipyard_1F_Text_DockDuringMission, MSGBOX_AUTOCLOSE
	release
	end	

SlateportCity_SternsShipyard_1F_EventScript_KizunaIdle::
	msgbox SlateportCity_SternsShipyard_1F_Text_KizunaIdle, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_NameKizuna:
	.string "Kizuna$"

SlateportCity_SternsShipyard_1F_Text_NameDock:
	.string "Dock$"

SlateportCity_SternsShipyard_1F_Text_DockPreRydel:
	.string "go do giddy and rydel$"

SlateportCity_SternsShipyard_1F_Text_IAmTheBard:
	.string "im the bard dock$"

SlateportCity_SternsShipyard_1F_Text_YoureOurNextGuy:
	.string "you are next mf$"

SlateportCity_SternsShipyard_1F_Text_BeforeIRetire:
	.string "before i retire gather my doods$"

SlateportCity_SternsShipyard_1F_Text_WeCanDoThat:
	.string "ok$"

SlateportCity_SternsShipyard_1F_Text_KizunaIdle:
	.string "gotta get da doods$"

SlateportCity_SternsShipyard_1F_Text_DockDuringMission:
	.string "gather my doods$"

SlateportCity_SternsShipyard_1F_Text_TheyreAllReady:
	.string "doods have been gathered$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "MR. BRINEY: Ah, {PLAYER}{KUN}!\n"
	.string "It's been too long!\p"
	.string "Aye, since I met you, this old sea dog's\n"
	.string "been feeling frisky!\p"
	.string "So I've decided to help DOCK make\n"
	.string "a ferry.\p"
	.string "Aye, after all, a ferry would be able\n"
	.string "to carry a lot of people.\p"
	.string "But, you know, that DOCK is really\n"
	.string "something special.\p"
	.string "With his knack for technology and\n"
	.string "my experience, I'm sure that we can\l"
	.string "build one great ship, aye!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "The seasons, the weather, where\n"
	.string "the moon sits in the sky…\p"
	.string "These and other conditions make\n"
	.string "the sea change its expression.\p"
	.string "That's right!\n"
	.string "The sea is like a living thing!$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "I get seasick real easily.\n"
	.string "So I get to help out here instead.$"

