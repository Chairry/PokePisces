.set LOCALID_RAY, 1

Route122_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route122_OnTransition
	.byte 0

Route122_OnTransition:
	call_if_gt VAR_RAY_STATE, 1, Route122_EventScript_SetTempFlags
	end

Route122_EventScript_SetTempFlags::
	setflag FLAG_TEMP_11
	removeobject LOCALID_RAY
	return

Route122_EventScript_RayEncounterWest::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route122_Movement_RayEncounterWest
	applymovement LOCALID_RAY, Route122_Movement_RaySquaresUp
	waitmovement 0
	goto Route122_EventScript_RayBattleStart
	release
	end

Route122_Movement_RayEncounterWest:
	walk_up
	walk_right
	face_up
	step_end

Route122_Movement_RaySquaresUp:
	walk_down
	walk_down
	walk_down
	emote_exclamation_mark
	delay_16
	delay_8
	walk_fast_down
	walk_fast_left
	face_down
	step_end

Route122_EventScript_RayEncounterEast::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route122_Movement_RayEncounterEast
	applymovement LOCALID_RAY, Route122_Movement_RaySquaresUp
	waitmovement 0
	goto Route122_EventScript_RayBattleStart
	release
	end

Route122_Movement_RayEncounterEast:
	walk_up
	step_end

Route122_EventScript_RayBattleStart::
	trainerbattle_single TRAINER_P_RAY_2, Route122_Text_RayIntro, Route122_Text_RayDefeat, Route122_EventScript_RayLeaves
	release
	end

Route122_EventScript_RayLeaves::
	msgbox Route122_Text_RayLeaves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RAY, Route122_Movement_RayLeaves
	waitmovement 0
	removeobject LOCALID_RAY
	setflag FLAG_TEMP_11
	setvar VAR_RAY_STATE, 2
	release
	end

Route122_Movement_RayLeaves:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

Route122_EventScript_ElderMan::
	lock
	faceplayer
	goto_if_eq VAR_GRAVE_QUEST_STATE, 3, Route122_EventScript_BindingBand
	goto_if_eq VAR_GRAVE_QUEST_STATE, 4, Route122_EventScript_GoFindHerSpirit
	goto_if_eq VAR_GRAVE_QUEST_STATE, 5, Route122_EventScript_DestinyKnot
	goto_if_eq VAR_GRAVE_QUEST_STATE, 6, Route122_EventScript_ThankYou
	msgbox Route122_Text_GreetingsChild, MSGBOX_AUTOCLOSE
	release
	end

Route122_EventScript_BindingBand::
	msgbox Route122_Text_ISeeThatBindingBand, MSGBOX_AUTOCLOSE
	setvar VAR_GRAVE_QUEST_STATE, 4
	release
	end

Route122_EventScript_GoFindHerSpirit::
	msgbox Route122_Text_GoFindHerSpirit, MSGBOX_AUTOCLOSE
	release
	end

Route122_EventScript_DestinyKnot::
	msgbox Route122_Text_YouHelpedHerFindPeace, MSGBOX_DEFAULT
	giveitem ITEM_DESTINY_KNOT
	setvar VAR_GRAVE_QUEST_STATE, 6
	msgbox Route122_Text_ThankYou, MSGBOX_AUTOCLOSE
	release
	end

Route122_EventScript_ThankYou::
	msgbox Route122_Text_ThankYou, MSGBOX_AUTOCLOSE
	release
	end

Route122_Text_GreetingsChild:
	.string "A pleasant welcome to\n"
	.string "our village, stranger.\p"
	.string "I am the Elder of Zotpyre.\p"
	.string "We sincerely hope you can find respite\n"
	.string "in our humble abodes.$"

Route122_Text_ISeeThatBindingBand:
	.string "…That band on your wrist…\p"
	.string "…Hm.\p"
	.string "I take it that the spirits of this land\n"
	.string "are quite fond of you.\p"
	.string "…Mayhaps you can be the one\n"
	.string "to calm her spirit.\p"
	.string "The basement of the inn…\n"
	.string "I ask you, kindly, to investigate.$"

Route122_Text_GoFindHerSpirit:
	.string "A troubled remnant is lingering in the\n"
	.string "basement of the inn…\p"
	.string "Mayhaps you can connect with her.$"

Route122_Text_YouHelpedHerFindPeace:
	.string "You do not need to brief me.\n"
	.string "I can feel that her presence has,\l"
	.string "at last, left this plane.\p"
	.string "My wife, the former elder…\p"
	.string "In her last days, her brain ebbed away.\n"
	.string "She lost herself.\l"
	.string "Even in death, she was fractured.\p"
	.string "Thank you very much for being that\n"
	.string "spark to get her to move on.\p"
	.string "Truly.\p"
	.string "Please accept… this.$"

Route122_Text_ThankYou:
	.string "thank you!$"

Route122_Text_RayIntro:
	.string "Let's tussle!!$"

Route122_Text_RayDefeat:
	.string "Are you KIDDING me!?$"

Route122_Text_RayLeaves:
	.string "I'll make sure of THAT!$"
