.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_2F_OnTransition
	.byte 0

SootopolisCity_PokemonCenter_2F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_2F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_BallQuestGuy::
	lock
	faceplayer
	speakername SootopolisCity_PokemonCenter_2F_Text_NamePhillipe
	goto_if_lt VAR_BALL_QUEST_STATE, 1, SootopolisCity_PokemonCenter_2F_EventScript_GoDoPreviousQuest
	goto_if_gt VAR_BALL_QUEST_STATE, 1, SootopolisCity_PokemonCenter_2F_EventScript_NoMoreQuest
	goto_if_set FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR, SootopolisCity_PokemonCenter_2F_EventScript_BallQuestGuyTruncated
	setflag FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR
	msgbox SootopolisCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon, MSGBOX_DEFAULT
	getcaughtmon SPECIES_SNOTLOUD
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_PokemonCenter_2F_EventScript_Check2
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_BallQuestGuyTruncated::
	msgbox SootopolisCity_PokemonCenter_2F_Text_CaughtMonReminder, MSGBOX_DEFAULT
	getcaughtmon SPECIES_SNOTLOUD
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_PokemonCenter_2F_EventScript_Check2
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_Check2::
	getcaughtmon SPECIES_SPRYTE
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_PokemonCenter_2F_EventScript_Check3
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_Check3::
	getcaughtmon SPECIES_LUMELMO
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_PokemonCenter_2F_EventScript_GiveNewBall
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_GiveNewBall::
	addvar VAR_BALL_QUEST_STATE, 1
	clearflag FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR
	msgbox SootopolisCity_PokemonCenter_2F_Text_YouveUnlockedNewBall, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_GoDoPreviousQuest::
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoDoPreviousQuest, MSGBOX_NPC
	speakername NULL
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_NoMoreQuest::
	msgbox SootopolisCity_PokemonCenter_2F_Text_NoMoreQuest, MSGBOX_NPC
	speakername NULL
	release
	end

SootopolisCity_PokemonCenter_2F_Text_NamePhillipe:
	.string "Phillipe$"

SootopolisCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon:
	.string "you needa catch uhh\n"
	.string "spryte lumelmo snotloud$"

SootopolisCity_PokemonCenter_2F_Text_CaughtMonReminder:
	.string "Spryte, Lumelmo, and Snotloud...\n"
	.string "I very much would like to see them!\p"
	.string "Do you have them registered\l"
	.string "in your Pokédex?$"

SootopolisCity_PokemonCenter_2F_Text_GoCatchIt:
	.string "go GET em shithead$"

SootopolisCity_PokemonCenter_2F_Text_YouveUnlockedNewBall:
	.string "you have unlocked moon ball$"

SootopolisCity_PokemonCenter_2F_Text_GoDoPreviousQuest:
	.string "go do the last one(s)$"

SootopolisCity_PokemonCenter_2F_Text_NoMoreQuest:
	.string "no more quest dood$"
