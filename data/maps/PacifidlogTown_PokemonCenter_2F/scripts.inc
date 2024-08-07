.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_2F_OnTransition
	.byte 0

PacifidlogTown_PokemonCenter_2F_OnTransition:
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_2F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_BallQuestGuy::
	lock
	faceplayer
	goto_if_gt VAR_BALL_QUEST_STATE, 0, PacifidlogTown_PokemonCenter_2F_EventScript_NoMoreQuest
	goto_if_set FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR, PacifidlogTown_PokemonCenter_2F_EventScript_BallQuestGuyTruncated
	msgbox PacifidlogTown_PokemonCenter_2F_Text_HaveYouCaughtThisMon, MSGBOX_DEFAULT
	setflag FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR
	getcaughtmon SPECIES_BERM
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_PokemonCenter_2F_EventScript_Check2
	msgbox PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_BallQuestGuyTruncated::
	speakername PacifidlogTown_PokemonCenter_2F_Text_NamePhil
	msgbox PacifidlogTown_PokemonCenter_2F_Text_CaughtMonReminder, MSGBOX_DEFAULT
	getcaughtmon SPECIES_BERM
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_PokemonCenter_2F_EventScript_Check2
	msgbox PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_Check2::
	getcaughtmon SPECIES_EBIBI
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_PokemonCenter_2F_EventScript_Check3
	msgbox PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_Check3::
	getcaughtmon SPECIES_KITIKITI
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_PokemonCenter_2F_EventScript_GiveNewBall
	msgbox PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_GiveNewBall::
	speakername PacifidlogTown_PokemonCenter_2F_Text_NamePhil
	addvar VAR_BALL_QUEST_STATE, 1
	clearflag FLAG_BALL_QUEST_DIALOGUE_TRUNCATOR
	msgbox PacifidlogTown_PokemonCenter_2F_Text_YouveUnlockedNewBall, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_NoMoreQuest::
	speakername PacifidlogTown_PokemonCenter_2F_Text_NamePhil
	msgbox PacifidlogTown_PokemonCenter_2F_Text_NoMoreQuest, MSGBOX_NPC
	speakername NULL
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_BallCounterTest::
	addvar VAR_BALL_QUEST_STATE, 1
	msgbox PacifidlogTown_PokemonCenter_2F_Text_BallCounterTest, MSGBOX_NPC
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_BadgeCounterTest::
	addvar VAR_PISCES_STORY_PROGRESS, 1
	msgbox PacifidlogTown_PokemonCenter_2F_Text_BadgeCounterTest, MSGBOX_NPC
	release
	end

PacifidlogTown_PokemonCenter_2F_Text_BallCounterTest:
	.string "ball quest plus 1$"

PacifidlogTown_PokemonCenter_2F_Text_BadgeCounterTest:
	.string "gym badge plus 1$"

PacifidlogTown_PokemonCenter_2F_Text_NamePhil:
	.string "Phillipe$"

PacifidlogTown_PokemonCenter_2F_Text_HaveYouCaughtThisMon:
	.string "Salut! I am un artiste. You may\n"
	.string "have heard of me, non? I run the\l"
	.string "Musée de Lilycove, where I have\l"
	.string "put all of my best pieces\l"
	.string "on display.\p"
	.string "Mon nom est Phillipe.\p"
	.string "Mais hélas, I am in dire need\n"
	.string "of inspiration. I would like some\l"
	.string "Pokémon to draw, but I am a\l"
	.string "born photographre, not un\l"
	.string "Pokémon wrangler...\p"
	.string "Ah! Perhaps vous may assist me!\p"
	.string "I would like to lay an eye on\n"
	.string "3 particular Pokémon.\p"
	.string "Berm, Ebibi, and Kitikiti.\p"
	.string "Catch those trés and show me your\n"
	.string "Pokédex, and I will make it\l"
	.string "worth your troubles.$"

PacifidlogTown_PokemonCenter_2F_Text_CaughtMonReminder:
	.string "Berm, Ebibi, and Kitikiti...\n"
	.string "I very much would like to see them!\p"
	.string "Do you have them registered\l"
	.string "in your Pokédex?$"

PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt:
	.string "I see you have not the required\n"
	.string "Pokémon, amie. They should be in\l"
	.string "areas close to here.\p"
	.string "Bonne chance!$"

PacifidlogTown_PokemonCenter_2F_Text_YouveUnlockedNewBall:
	.string "...\p"
	.string "Ah! There they are! Lovely catches!\p"
	.string "Berm's adorable charm...\n"
	.string "That pesky smile on Kitikiti...\l"
	.string "Ebibi's flaky fur...\p"
	.string "Inspiration strikes! Incroyable!\n"
	.string "I must get to painting.\p"
	.string "Merci, trainer. I will put in a good\n"
	.string "word for you with Purplina;\l"
	.string "you should soon be able to\l"
	.string "purchase Lure Balls from her.\p"
	.string "Au revoir!$"

PacifidlogTown_PokemonCenter_2F_Text_NoMoreQuest:
	.string "Bon aprés-midi, trainer.\n"
	.string "I have naught in the way of new\l"
	.string "jobs for you this very moment.\p"
	.string "Perhaps when we next meet,\n"
	.string "we shall work together again.$"
