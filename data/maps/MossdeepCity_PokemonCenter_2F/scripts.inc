.set LOCALID_NURSE, 1

MossdeepCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_2F_OnTransition
	.byte 0

MossdeepCity_PokemonCenter_2F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_2F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_BallQuestGuy::
	lock
	faceplayer
	speakername MossdeepCity_PokemonCenter_2F_Text_NamePhillipe
	goto_if_lt VAR_BALL_QUEST_STATE, 2, MossdeepCity_PokemonCenter_2F_EventScript_GoDoPreviousQuest
	goto_if_gt VAR_BALL_QUEST_STATE, 2, MossdeepCity_PokemonCenter_2F_EventScript_NoMoreQuest
	goto_if_set FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR, MossdeepCity_PokemonCenter_2F_EventScript_BallQuestGuyTruncated
	setflag FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR
	msgbox MossdeepCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon, MSGBOX_DEFAULT
	getcaughtmon SPECIES_MINOTE
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_2F_EventScript_Check2
	msgbox MossdeepCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_BallQuestGuyTruncated::
	msgbox MossdeepCity_PokemonCenter_2F_Text_CaughtMonReminder, MSGBOX_DEFAULT
	getcaughtmon SPECIES_MINOTE
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_2F_EventScript_Check2
	msgbox MossdeepCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_Check2::
	getcaughtmon SPECIES_SLICKSLICE
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_2F_EventScript_Check3
	msgbox MossdeepCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_Check3::
	getcaughtmon SPECIES_SPOINK
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_PokemonCenter_2F_EventScript_GiveNewBall
	msgbox MossdeepCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_GiveNewBall::
	addvar VAR_BALL_QUEST_STATE, 1
	clearflag FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR
	msgbox MossdeepCity_PokemonCenter_2F_Text_YouveUnlockedNewBall, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_GoDoPreviousQuest::
	msgbox MossdeepCity_PokemonCenter_2F_Text_GoDoPreviousQuest, MSGBOX_NPC
	speakername NULL
	release
	end

MossdeepCity_PokemonCenter_2F_EventScript_NoMoreQuest::
	msgbox MossdeepCity_PokemonCenter_2F_Text_NoMoreQuest, MSGBOX_NPC
	speakername NULL
	release
	end

MossdeepCity_PokemonCenter_2F_Text_NamePhillipe:
	.string "Phillipe$"

MossdeepCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon:
	.string "you needa catch uhh\n"
	.string "slickslice minote spoink$"

MossdeepCity_PokemonCenter_2F_Text_CaughtMonReminder:
	.string "Slickslice, Minote, and Spoink...\n"
	.string "I very much would like to see them!\p"
	.string "Do you have them registered\l"
	.string "in your Pokédex?$"

MossdeepCity_PokemonCenter_2F_Text_GoCatchIt:
	.string "go GET em shithead$"

MossdeepCity_PokemonCenter_2F_Text_YouveUnlockedNewBall:
	.string "you have unlocked frien ball$"

MossdeepCity_PokemonCenter_2F_Text_GoDoPreviousQuest:
	.string "go do the last one(s)$"

MossdeepCity_PokemonCenter_2F_Text_NoMoreQuest:
	.string "no more quest dood$"
