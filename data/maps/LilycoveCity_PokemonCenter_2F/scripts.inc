.set LOCALID_NURSE, 1

LilycoveCity_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_2F_OnTransition
	.byte 0

LilycoveCity_PokemonCenter_2F_OnTransition:
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	end

LilycoveCity_PokemonCenter_2F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_BallQuestGuy::
	lock
	faceplayer
	goto_if_lt VAR_BALL_QUEST_STATE, 3, LilycoveCity_PokemonCenter_2F_EventScript_GoDoPreviousQuest
	goto_if_gt VAR_BALL_QUEST_STATE, 3, LilycoveCity_PokemonCenter_2F_EventScript_NoMoreQuest
	msgbox LilycoveCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon, MSGBOX_DEFAULT
	getcaughtmon SPECIES_LOTTABATS
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_2F_EventScript_Check2
	msgbox LilycoveCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_Check2::
	getcaughtmon SPECIES_MATCHLIT
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_2F_EventScript_Check3
	msgbox LilycoveCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_Check3::
	getcaughtmon SPECIES_FLAGUE
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_PokemonCenter_2F_EventScript_GiveNewBall
	msgbox LilycoveCity_PokemonCenter_2F_Text_GoCatchIt, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_GiveNewBall::
	addvar VAR_BALL_QUEST_STATE, 1
	msgbox LilycoveCity_PokemonCenter_2F_Text_YouveUnlockedNewBall, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_GoDoPreviousQuest::
	msgbox LilycoveCity_PokemonCenter_2F_Text_GoDoPreviousQuest, MSGBOX_NPC
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_NoMoreQuest::
	msgbox LilycoveCity_PokemonCenter_2F_Text_NoMoreQuest, MSGBOX_NPC
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_Teleporter::
	lock
	faceplayer
	goto_if_unset FLAG_ZOTPYRE_PSYCHICS, LilycoveCity_PokemonCenter_2F_EventScript_WhereIsMySibling
	msgbox LilycoveCity_PokemonCenter_2F_Text_WouldYouLikeToWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_PokemonCenter_2F_EventScript_WarpToShrine
	msgbox LilycoveCity_PokemonCenter_2F_Text_MaybeAnotherTime, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_WhereIsMySibling::
	msgbox LilycoveCity_PokemonCenter_2F_Text_CanYouFindMyKin, MSGBOX_AUTOCLOSE
	release
	end

LilycoveCity_PokemonCenter_2F_EventScript_WarpToShrine::
	warp MAP_MT_PYRE_1F, 14, 21
	release
	end

LilycoveCity_PokemonCenter_2F_Text_WouldYouLikeToWarp:
	.string "wanna warp$"

LilycoveCity_PokemonCenter_2F_Text_MaybeAnotherTime:
	.string "maybe nexttime$"

LilycoveCity_PokemonCenter_2F_Text_CanYouFindMyKin:
	.string "can u find my kin$"

LilycoveCity_PokemonCenter_2F_Text_HaveYouCaughtThisMon:
	.string "you needa catch uhh\n"
	.string "lottabats matchlit flague$"

LilycoveCity_PokemonCenter_2F_Text_GoCatchIt:
	.string "go GET em shithead$"

LilycoveCity_PokemonCenter_2F_Text_YouveUnlockedNewBall:
	.string "you have unlocked frien ball$"

LilycoveCity_PokemonCenter_2F_Text_GoDoPreviousQuest:
	.string "go do the last one(s)$"

LilycoveCity_PokemonCenter_2F_Text_NoMoreQuest:
	.string "no more quest dood$"
