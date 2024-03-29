.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
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
	goto_if_gt VAR_BALL_QUEST_STATE, 1, SootopolisCity_PokemonCenter_2F_EventScript_NoMoreQuest
	msgbox SootopolisCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon, MSGBOX_DEFAULT
	getcaughtmon SPECIES_SNOTLOUD
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_PokemonCenter_2F_EventScript_Check2
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_Check2::
	getcaughtmon SPECIES_SPRYTE
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_PokemonCenter_2F_EventScript_Check3
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_Check3::
	getcaughtmon SPECIES_LUMELMO
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_PokemonCenter_2F_EventScript_GiveNewBall
	msgbox SootopolisCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_GiveNewBall::
	addvar VAR_BALL_QUEST_STATE, 1
	msgbox SootopolisCity_PokemonCenter_2F_Text_YouveUnlockedNewBall, MSGBOX_AUTOCLOSE
	release
	end

SootopolisCity_PokemonCenter_2F_EventScript_NoMoreQuest::
	msgbox SootopolisCity_PokemonCenter_2F_Text_NoMoreQuest, MSGBOX_NPC
	release
	end

SootopolisCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon:
	.string "you needa catch uhh\n$"
	.string "spryte lumelmo snotloud$"

SootopolisCity_PokemonCenter_2F_Text_GoCatchIt:
	.string "go GET em shithead$"

SootopolisCity_PokemonCenter_2F_Text_YouveUnlockedNewBall:
	.string "you have unlocked moon ball$"

SootopolisCity_PokemonCenter_2F_Text_NoMoreQuest:
	.string "no more quest dood$"
