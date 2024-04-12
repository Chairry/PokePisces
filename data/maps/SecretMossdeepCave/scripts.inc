SecretMossdeepCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SecretMossdeepCave_OnTransition
	.byte 0

SecretMossdeepCave_OnTransition:
	call_if_lt VAR_SHELLYLOUH_STATE, 1, SecretMossdeepCave_EventScript_SetTempFlags
	end

SecretMossdeepCave_EventScript_SetTempFlags::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	return

SecretMossdeepCave_EventScript_PomAndAtia::
	trainerbattle_double TRAINER_P_JO_AND_JO, SecretMossdeepCave_Text_PomAtiaIntro, SecretMossdeepCave_Text_PomAtiaDefeated, SecretMossdeepCave_Text_PomAtiaNeedTwoMons, SecretMossdeepCave_EventScript_GiveShellPolish
    msgbox SecretMossdeepCave_Text_PomAtiaPostBattle, MSGBOX_AUTOCLOSE
    end

SecretMossdeepCave_EventScript_GiveShellPolish::
	msgbox SecretMossdeepCave_Text_HaveSP, MSGBOX_DEFAULT
	setvar VAR_SHELLYLOUH_STATE, 2
	giveitem ITEM_SHELL_POLISH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

SecretMossdeepCave_Text_PomAtiaIntro:
	.string "feel the power of shell$"

SecretMossdeepCave_Text_PomAtiaDefeated:
	.string "shell naw$"

SecretMossdeepCave_Text_PomAtiaNeedTwoMons:
	.string "need 2 dood$"

SecretMossdeepCave_Text_PomAtiaPostBattle:
	.string "tsuinsu$"

SecretMossdeepCave_Text_HaveSP:
	.string "have some shell polish$"
