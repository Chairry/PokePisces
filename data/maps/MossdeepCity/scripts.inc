MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	.byte 0

MossdeepCity_OnTransition:
	call_if_lt VAR_SPACE_CENTER_QUEST_STATE, 3, MossdeepCity_EventScript_HideMeteors
	end

MossdeepCity_EventScript_HideMeteors::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	end

MossdeepCity_EventScript_Woman::
	msgbox MossdeepCity_Text_Gugumbir, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_Gugumbir, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_Text_Gugumbir:
	.string "test$"