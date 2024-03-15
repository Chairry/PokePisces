.set LOCALID_NURSE, 1

PacifidlogTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
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
	goto_if_eq VAR_BALL_QUEST_STATE, 1, PacifidlogTown_PokemonCenter_2F_EventScript_NoMoreQuest
	msgbox PacifidlogTown_PokemonCenter_2F_Text_HaveYouCaughtThisMon, MSGBOX_DEFAULT
	getcaughtmon SPECIES_BERM
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_PokemonCenter_2F_EventScript_Check2
	msgbox PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_Check2::
	getcaughtmon SPECIES_EBIBI
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_PokemonCenter_2F_EventScript_Check3
	msgbox PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_Check3::
	getcaughtmon SPECIES_KITIKITI
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_PokemonCenter_2F_EventScript_GiveNewBall
	msgbox PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_GiveNewBall::
	addvar VAR_BALL_QUEST_STATE, 1
	msgbox PacifidlogTown_PokemonCenter_2F_Text_YouveUnlockedNewBall, MSGBOX_AUTOCLOSE
	release
	end

PacifidlogTown_PokemonCenter_2F_EventScript_NoMoreQuest::
	msgbox PacifidlogTown_PokemonCenter_2F_Text_NoMoreQuest, MSGBOX_NPC
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

PacifidlogTown_PokemonCenter_2F_Text_HaveYouCaughtThisMon:
	.string "do you have berm,\n"
	.string "kitikiti and ebibi?$"

PacifidlogTown_PokemonCenter_2F_Text_GoCatchIt:
	.string "loser !!$"

PacifidlogTown_PokemonCenter_2F_Text_YouveUnlockedNewBall:
	.string "new balls unlocked bro$"

PacifidlogTown_PokemonCenter_2F_Text_NoMoreQuest:
	.string "nothin left for you idiot$"
