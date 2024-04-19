LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	end

LilycoveCity_EventScript_FalseSwipeGiver::
	lock
	faceplayer
	checkitem ITEM_TM_FALSE_SWIPE
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_GaveFalseSwipe
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring STR_VAR_1, VAR_0x8008
	buffernumberstring STR_VAR_2, VAR_0x8009
	goto_if_gt VAR_0x8009, 39, LilycoveCity_EventScript_GiveFalseSwipe
	msgbox LilycoveCity_Text_WantToSee40CaughtMons, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_EventScript_GiveFalseSwipe::
	msgbox LilycoveCity_Text_LotsOfCaughtMons, MSGBOX_DEFAULT
	giveitem ITEM_TM_FALSE_SWIPE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

LilycoveCity_EventScript_GaveFalseSwipe::
	msgbox LilycoveCity_Text_GaveFS, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_Text_WantToSee40CaughtMons:
	.string "i wanna see 40 caught$"

LilycoveCity_Text_LotsOfCaughtMons:
	.string "wow u caught 40 mons$"

LilycoveCity_Text_GaveFS:
	.string "gave u FS already$"
