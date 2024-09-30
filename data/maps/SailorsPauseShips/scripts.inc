SailorsPauseShips_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SailorsPauseShips_OnLoad
	.byte 0

SailorsPauseShips_OnLoad:
	call_if_set FLAG_FOUND_SHELLY, SailorsPauseShips_EventScript_RemoveShelly
	end

SailorsPauseShips_EventScript_RemoveShelly::
	setmetatile 39, 1, METATILE_InsideShip_ShellyGoneTop, TRUE
	setmetatile 39, 2, METATILE_InsideShip_ShellyGoneBottom, TRUE
	special DrawWholeMapView
	return

SailorsPauseShips_EventScript_Shelly::
	lockall
	goto_if_set FLAG_FOUND_SHELLY, SailorsPauseShips_EventScript_ShellyGone
	msgbox SailorsPauseShips_Text_ShellyGreeting, MSGBOX_DEFAULT
	setflag FLAG_FOUND_SHELLY
	delay 32
	closemessage
	playse SE_EXIT
	setmetatile 39, 1, METATILE_InsideShip_ShellyGoneTop, TRUE
	setmetatile 39, 2, METATILE_InsideShip_ShellyGoneBottom, TRUE
	special DrawWholeMapView
	releaseall
	end

SailorsPauseShips_EventScript_ShellyGone::
	msgbox SailorsPauseShips_Text_ShellyGone, MSGBOX_AUTOCLOSE
	releaseall
	end

SailorsPauseShips_EventScript_Ami::
    trainerbattle_single TRAINER_P_AMI, SailorsPauseShips_Text_AmiIntro, SailorsPauseShips_Text_AmiDefeated
    msgbox SailorsPauseShips_Text_AmiPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Marcy::
    trainerbattle_single TRAINER_P_MARCY, SailorsPauseShips_Text_MarcyIntro, SailorsPauseShips_Text_MarcyDefeated
    msgbox SailorsPauseShips_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Sponge::
    trainerbattle_single TRAINER_P_SPONGE, SailorsPauseShips_Text_SpongeIntro, SailorsPauseShips_Text_SpongeDefeated
    msgbox SailorsPauseShips_Text_SpongePostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Walton::
    trainerbattle_single TRAINER_P_WALTON, SailorsPauseShips_Text_WaltonIntro, SailorsPauseShips_Text_WaltonDefeated
    msgbox SailorsPauseShips_Text_WaltonPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Joshu::
    trainerbattle_single TRAINER_P_JOSHU, SailorsPauseShips_Text_JoshuIntro, SailorsPauseShips_Text_JoshuDefeated
    msgbox SailorsPauseShips_Text_JoshuPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Janelle::
    trainerbattle_single TRAINER_P_JANELLE, SailorsPauseShips_Text_JanelleIntro, SailorsPauseShips_Text_JanelleDefeated
    msgbox SailorsPauseShips_Text_JanellePostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Nunya::
    trainerbattle_single TRAINER_P_NUNYA, SailorsPauseShips_Text_NunyaIntro, SailorsPauseShips_Text_NunyaDefeated
    msgbox SailorsPauseShips_Text_NunyaPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Jack::
    trainerbattle_single TRAINER_P_JACK, SailorsPauseShips_Text_JackIntro, SailorsPauseShips_Text_JackDefeated
    msgbox SailorsPauseShips_Text_JackPostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_EventScript_Rose::
    trainerbattle_single TRAINER_P_ROSE, SailorsPauseShips_Text_RoseIntro, SailorsPauseShips_Text_RoseDefeated
    msgbox SailorsPauseShips_Text_RosePostBattle, MSGBOX_AUTOCLOSE
    end

SailorsPauseShips_Text_AmiIntro:
	.string "intro$"

SailorsPauseShips_Text_AmiDefeated:
	.string "defeat$"

SailorsPauseShips_Text_AmiPostBattle:
	.string "post$"

SailorsPauseShips_Text_MarcyIntro:
	.string "intro$"

SailorsPauseShips_Text_MarcyDefeated:
	.string "defeat$"

SailorsPauseShips_Text_MarcyPostBattle:
	.string "post$"

SailorsPauseShips_Text_SpongeIntro:
	.string "intro$"

SailorsPauseShips_Text_SpongeDefeated:
	.string "defeat$"

SailorsPauseShips_Text_SpongePostBattle:
	.string "post$"

SailorsPauseShips_Text_WaltonIntro:
	.string "intro$"

SailorsPauseShips_Text_WaltonDefeated:
	.string "defeat$"

SailorsPauseShips_Text_WaltonPostBattle:
	.string "post$"

SailorsPauseShips_Text_JoshuIntro:
	.string "intro$"

SailorsPauseShips_Text_JoshuDefeated:
	.string "defeat$"

SailorsPauseShips_Text_JoshuPostBattle:
	.string "post$"

SailorsPauseShips_Text_JanelleIntro:
	.string "intro$"

SailorsPauseShips_Text_JanelleDefeated:
	.string "defeat$"

SailorsPauseShips_Text_JanellePostBattle:
	.string "post$"

SailorsPauseShips_Text_NunyaIntro:
	.string "intro$"

SailorsPauseShips_Text_NunyaDefeated:
	.string "defeat$"

SailorsPauseShips_Text_NunyaPostBattle:
	.string "post$"

SailorsPauseShips_Text_JackIntro:
	.string "intro$"

SailorsPauseShips_Text_JackDefeated:
	.string "defeat$"

SailorsPauseShips_Text_JackPostBattle:
	.string "post$"

SailorsPauseShips_Text_RoseIntro:
	.string "intro$"

SailorsPauseShips_Text_RoseDefeated:
	.string "defeat$"

SailorsPauseShips_Text_RosePostBattle:
	.string "post$"

SailorsPauseShips_Text_ShellyGreeting:
	.string "shellgreet$"

SailorsPauseShips_Text_ShellyGone:
	.string "nothing there (reference)$"
