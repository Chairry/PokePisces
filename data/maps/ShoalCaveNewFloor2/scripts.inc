.set LOCALID_BRAWLY, 6

ShoalCaveNewFloor2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCaveNewFloor2_OnLoad
	.byte 0

ShoalCaveNewFloor2_OnLoad:
	call_if_set FLAG_FOUND_BRAWLY, ShoalCaveNewFloor2_EventScript_RemoveBrawly
	end

ShoalCaveNewFloor2_EventScript_RemoveBrawly::
	removeobject LOCALID_BRAWLY
	setflag FLAG_TEMP_11
	return

ShoalCaveNewFloor2_EventScript_Brawly::
	lockall
	faceplayer
	goto_if_set FLAG_FOUND_BRAWLY, ShoalCaveNewFloor2_EventScript_BrawlyGone
	msgbox ShoalCaveNewFloor2_Text_BrawlyGreeting, MSGBOX_DEFAULT
	setflag FLAG_FOUND_BRAWLY
	delay 32
	closemessage
	playse SE_EXIT
	removeobject LOCALID_BRAWLY
	setflag FLAG_TEMP_11
	releaseall
	end

ShoalCaveNewFloor2_EventScript_BrawlyGone::
	msgbox ShoalCaveNewFloor2_Text_BrawlyGone, MSGBOX_AUTOCLOSE
	releaseall
	end

ShoalCaveNewFloor2_EventScript_StrengthBoulder::
	lockall
	goto_if_unset FLAG_BADGE05_GET, ShoalCaveNewFloor2_EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, ShoalCaveNewFloor2_EventScript_CheckActivatedBoulder
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, ShoalCaveNewFloor2_EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox ShoalCaveNewFloor2_Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ShoalCaveNewFloor2_EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto ShoalCaveNewFloor2_EventScript_ActivateStrength
	end

ShoalCaveNewFloor2_EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto ShoalCaveNewFloor2_EventScript_ActivateStrength
	end

ShoalCaveNewFloor2_EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox ShoalCaveNewFloor2_Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

ShoalCaveNewFloor2_EventScript_CantStrength::
	msgbox ShoalCaveNewFloor2_Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

ShoalCaveNewFloor2_EventScript_CheckActivatedBoulder::
	msgbox ShoalCaveNewFloor2_Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

ShoalCaveNewFloor2_EventScript_CancelStrength::
	closemessage
	releaseall
	end

ShoalCaveNewFloor2_EventScript_Magnus::
    trainerbattle_single TRAINER_P_MAGNUS, ShoalCaveNewFloor2_Text_MagnusIntro, ShoalCaveNewFloor2_Text_MagnusDefeated
    msgbox ShoalCaveNewFloor2_Text_MagnusPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor2_EventScript_Juneau::
    trainerbattle_single TRAINER_P_JUNEAU, ShoalCaveNewFloor2_Text_JuneauIntro, ShoalCaveNewFloor2_Text_JuneauDefeated
    msgbox ShoalCaveNewFloor2_Text_JuneauPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor2_EventScript_Alaska::
    trainerbattle_single TRAINER_P_ALASKA, ShoalCaveNewFloor2_Text_AlaskaIntro, ShoalCaveNewFloor2_Text_AlaskaDefeated
    msgbox ShoalCaveNewFloor2_Text_AlaskaPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor2_Text_MagnusIntro:
	.string "intro$"

ShoalCaveNewFloor2_Text_MagnusDefeated:
	.string "defeat$"

ShoalCaveNewFloor2_Text_MagnusPostBattle:
	.string "post$"

ShoalCaveNewFloor2_Text_JuneauIntro:
	.string "intro$"

ShoalCaveNewFloor2_Text_JuneauDefeated:
	.string "defeat$"

ShoalCaveNewFloor2_Text_JuneauPostBattle:
	.string "post$"

ShoalCaveNewFloor2_Text_AlaskaIntro:
	.string "intro$"

ShoalCaveNewFloor2_Text_AlaskaDefeated:
	.string "defeat$"

ShoalCaveNewFloor2_Text_AlaskaPostBattle:
	.string "post$"

ShoalCaveNewFloor2_Text_BrawlyGreeting:
	.string "brawly greetin$"

ShoalCaveNewFloor2_Text_BrawlyGone:
	.string "hey dunko$"

ShoalCaveNewFloor2_Text_WantToStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

ShoalCaveNewFloor2_Text_MonUsedStrength:
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}'s STRENGTH made it\n"
	.string "possible to move boulders around!$"

ShoalCaveNewFloor2_Text_CantStrength:
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

ShoalCaveNewFloor2_Text_StrengthActivated:
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"
