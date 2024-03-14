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
