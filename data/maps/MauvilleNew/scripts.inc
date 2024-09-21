.set LOCALID_P_MAN, 7

MauvilleNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleNew_OnLoad
	.byte 0

MauvilleNew_OnLoad:
	call_if_lt VAR_OLD_GUYS_STATE, 2, MauvilleNew_EventScript_RemovePowerlessMan
	call_if_gt VAR_OLD_GUYS_STATE, 2, MauvilleNew_EventScript_RemovePowerlessMan
	end

MauvilleNew_EventScript_RemovePowerlessMan::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

MauvilleNew_EventScript_Kizuna::
	speakername MauvilleNew_Text_NameKizuna
	msgbox MauvilleNew_Text_LookingForClues, MSGBOX_NPC
    end

MauvilleNew_EventScript_Kurt::
    trainerbattle_single TRAINER_P_KURT, MauvilleNew_Text_KurtIntro, MauvilleNew_Text_KurtDefeated
    msgbox MauvilleNew_Text_KurtPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Kirst::
    trainerbattle_single TRAINER_P_KIRST, MauvilleNew_Text_KirstIntro, MauvilleNew_Text_KirstDefeated
    msgbox MauvilleNew_Text_KirstPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Maia::
    trainerbattle_single TRAINER_P_MAIA, MauvilleNew_Text_MaiaIntro, MauvilleNew_Text_MaiaDefeated
    msgbox MauvilleNew_Text_MaiaPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Miguel::
    trainerbattle_single TRAINER_P_MIGUEL, MauvilleNew_Text_MiguelIntro, MauvilleNew_Text_MiguelDefeated
    msgbox MauvilleNew_Text_MiguelPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_Text_KurtIntro:
	.string "intro$"

MauvilleNew_Text_KurtDefeated:
	.string "defeat$"

MauvilleNew_Text_KurtPostBattle:
	.string "post$"

MauvilleNew_Text_KirstIntro:
	.string "intro$"

MauvilleNew_Text_KirstDefeated:
	.string "defeat$"

MauvilleNew_Text_KirstPostBattle:
	.string "post$"

MauvilleNew_Text_MaiaIntro:
	.string "intro$"

MauvilleNew_Text_MaiaDefeated:
	.string "defeat$"

MauvilleNew_Text_MaiaPostBattle:
	.string "post$"

MauvilleNew_Text_MiguelIntro:
	.string "intro$"

MauvilleNew_Text_MiguelDefeated:
	.string "defeat$"

MauvilleNew_Text_MiguelPostBattle:
	.string "post$"

MauvilleNew_Text_NameKizuna:
	.string "Kizuna$"

MauvilleNew_Text_LookingForClues:
	.string "lookin for clues$"
