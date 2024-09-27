OceanicMuseumNew_MapScripts::
	.byte 0

OceanicMuseumNew_EventScript_Stern::
	lock
	faceplayer
	goto_if_lt VAR_OLD_GUYS_STATE, 8, OceanicMuseumNew_EventScript_SternPreDock
	goto_if_gt VAR_OLD_GUYS_STATE, 8, OceanicMuseumNew_EventScript_SternPostDock
	goto_if_set FLAG_DOCK_QUEST_FOUND_STERN, OceanicMuseumNew_EventScript_SternGatherOthers
	setflag FLAG_DOCK_QUEST_FOUND_STERN
	msgbox OceanicMuseumNew_Text_ImCaptStern, MSGBOX_DEFAULT
	speakername OceanicMuseumNew_Text_NameStern
	msgbox OceanicMuseumNew_Text_DockWantsMe, MSGBOX_AUTOCLOSE
	release
	end

OceanicMuseumNew_EventScript_SternPreDock::
	msgbox OceanicMuseumNew_Text_SternPreDock, MSGBOX_AUTOCLOSE
	release
	end

OceanicMuseumNew_EventScript_SternGatherOthers::
	speakername OceanicMuseumNew_Text_NameStern
	msgbox OceanicMuseumNew_Text_SternGatherOthers, MSGBOX_AUTOCLOSE
	release
	end

OceanicMuseumNew_EventScript_SternPostDock::
	speakername OceanicMuseumNew_Text_NameStern
	msgbox OceanicMuseumNew_Text_SternPostDock, MSGBOX_AUTOCLOSE
	release
	end

OceanicMuseumNew_EventScript_Moon::
    trainerbattle_single TRAINER_P_MOON, OceanicMuseumNew_Text_MoonIntro, OceanicMuseumNew_Text_MoonDefeated
    msgbox OceanicMuseumNew_Text_MoonPostBattle, MSGBOX_AUTOCLOSE
    end

OceanicMuseumNew_EventScript_Venus::
    trainerbattle_single TRAINER_P_VENUS, OceanicMuseumNew_Text_VenusIntro, OceanicMuseumNew_Text_VenusDefeated
    msgbox OceanicMuseumNew_Text_VenusPostBattle, MSGBOX_AUTOCLOSE
    end

OceanicMuseumNew_Text_NameStern:
	.string "Cpt. Stern$"

OceanicMuseumNew_Text_SternPreDock:
	.string "go away maybe?$"

OceanicMuseumNew_Text_ImCaptStern:
	.string "im captain stern$"

OceanicMuseumNew_Text_DockWantsMe:
	.string "docky boy needs me? k$"

OceanicMuseumNew_Text_SternGatherOthers:
	.string "gather the other doods$"

OceanicMuseumNew_Text_SternPostDock:
	.string "man i liked that song$"

OceanicMuseumNew_Text_MoonIntro:
	.string "intro$"

OceanicMuseumNew_Text_MoonDefeated:
	.string "defeat$"

OceanicMuseumNew_Text_MoonPostBattle:
	.string "post$"

OceanicMuseumNew_Text_VenusIntro:
	.string "intro$"

OceanicMuseumNew_Text_VenusDefeated:
	.string "defeat$"

OceanicMuseumNew_Text_VenusPostBattle:
	.string "post$"
