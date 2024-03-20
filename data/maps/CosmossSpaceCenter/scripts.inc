CosmossSpaceCenter_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CosmossSpaceCenter_OnFrame
	.byte 0

CosmossSpaceCenter_OnFrame:
	map_script_2 VAR_SPACE_CENTER_QUEST_STATE, 50, CosmossSpaceCenter_EventScript_AfterInvasion
	.2byte 0

CosmossSpaceCenter_EventScript_AfterInvasion::
	lock
	msgbox CosmossSpaceCenter_Text_SavedTheRocket, MSGBOX_DEFAULT
	giveitem ITEM_ORAN_BERRY
	setvar VAR_SPACE_CENTER_QUEST_STATE, 3
	msgbox CosmossSpaceCenter_Text_MeteorsFallen, MSGBOX_AUTOCLOSE
	release
	end

CosmossSpaceCenter_EventScript_RocketResearcher::
	lock
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 0, CosmossSpaceCenter_EventScript_RocketFunded
	msgbox CosmossSpaceCenter_Text_NeedHelpFunding, MSGBOX_DEFAULT
	showmoneybox 0, 0
	msgbox CosmossSpaceCenter_Text_WillYouFund, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CosmossSpaceCenter_EventScript_CheckMoneyForFund
	closemessage
	hidemoneybox
	release
	end

CosmossSpaceCenter_EventScript_CheckMoneyForFund::
	checkmoney 5000
	goto_if_eq VAR_RESULT, FALSE, CosmossSpaceCenter_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 5000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox CosmossSpaceCenter_Text_ThanksForFunding, MSGBOX_DEFAULT
	giveitem ITEM_EJECT_BUTTON
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_SPACE_CENTER_QUEST_STATE, 1
	msgbox CosmossSpaceCenter_Text_YouCanNowGoUpstairs, MSGBOX_AUTOCLOSE
	release
	end

CosmossSpaceCenter_EventScript_NotEnoughMoney::
	msgbox CosmossSpaceCenter_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

CosmossSpaceCenter_EventScript_RocketFunded::
	msgbox CosmossSpaceCenter_Text_RocketFuel, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_AlienResearcher::
	lock
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 1, CosmossSpaceCenter_EventScript_AboutCryplin
	msgbox CosmossSpaceCenter_Text_BattleMyCryplin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CosmossSpaceCenter_EventScript_PonsonbyBattle
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_PonsonbyBattle::
	trainerbattle_single TRAINER_P_JIMMY, CosmossSpaceCenter_Text_PonsonbyIntro, CosmossSpaceCenter_Text_PonsonbyDefeat, CosmossSpaceCenter_EventScript_LearnedALot
	release
	end

CosmossSpaceCenter_EventScript_LearnedALot::
	msgbox CosmossSpaceCenter_Text_LearnedALot, MSGBOX_DEFAULT
	giveitem ITEM_EJECT_PACK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_SPACE_CENTER_QUEST_STATE, 2
	msgbox CosmossSpaceCenter_Text_HelpMyFriend, MSGBOX_AUTOCLOSE
	release
	end

CosmossSpaceCenter_EventScript_AboutCryplin::
	msgbox CosmossSpaceCenter_Text_AboutCryplin, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_UFOResearcher::
	lock
	goto_if_lt VAR_SPACE_CENTER_QUEST_STATE, 2, CosmossSpaceCenter_EventScript_RadioWaves
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 2, CosmossSpaceCenter_EventScript_AboutUhefoe
	msgbox CosmossSpaceCenter_Text_HelpFightUFO, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CosmossSpaceCenter_EventScript_PrepForUhefoeInvasion
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_PrepForUhefoeInvasion::
	setvar VAR_SPACE_CENTER_QUEST_STATE, 69
	warp MAP_ROUTE126, 61, 15
	waitstate
	release
	end

CosmossSpaceCenter_EventScript_RadioWaves::
	msgbox CosmossSpaceCenter_Text_RadioWaves, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_AboutUhefoe::
	msgbox CosmossSpaceCenter_Text_AboutUhefoe, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_AsteroidResearcher::
	lock
	goto_if_lt VAR_SPACE_CENTER_QUEST_STATE, 3, CosmossSpaceCenter_EventScript_AboutCryplin
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 3, CosmossSpaceCenter_EventScript_AboutCryplin
	msgbox CosmossSpaceCenter_Text_GoCollectMinior, MSGBOX_DEFAULT
	goto CosmossSpaceCenter_EventScript_ReceiveShinyMinior
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_ReceiveShinyMinior::
	msgbox CosmossSpaceCenter_Text_HaveThisShinyMinior, MSGBOX_DEFAULT
	setflag FLAG_FORCED_SHINY
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MINIOR_METEOR_INDIGO
	givemon SPECIES_MINIOR_METEOR_INDIGO, 20, ITEM_COMET_SHARD
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, CosmossSpaceCenter_EventScript_ReceiveShinyMiniorParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, CosmossSpaceCenter_EventScript_ReceiveShinyMiniorPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

CosmossSpaceCenter_EventScript_ReceiveShinyMiniorParty::
	call CosmossSpaceCenter_EventScript_ReceivedShinyMiniorFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CosmossSpaceCenter_EventScript_ExplainShinyMinior
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto CosmossSpaceCenter_EventScript_ExplainShinyMinior
	end

CosmossSpaceCenter_EventScript_ReceiveShinyMiniorPC::
	call CosmossSpaceCenter_EventScript_ReceivedShinyMiniorFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CosmossSpaceCenter_EventScript_SendShinyMiniorToPC
	call Common_EventScript_NameReceivedBoxMon
	goto CosmossSpaceCenter_EventScript_SendShinyMiniorToPC
	end

CosmossSpaceCenter_EventScript_SendShinyMiniorToPC::
	call Common_EventScript_TransferredToPC
	goto CosmossSpaceCenter_EventScript_ExplainShinyMinior
	end

CosmossSpaceCenter_EventScript_ReceivedShinyMiniorFanfare::
	playfanfare MUS_OBTAIN_ITEM
	clearflag FLAG_FORCED_SHINY
	message CosmossSpaceCenter_Text_PlayerReceivedShinyMinior
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MINIOR
	return

CosmossSpaceCenter_EventScript_ExplainShinyMinior::
	msgbox CosmossSpaceCenter_Text_YoureTheBest, MSGBOX_DEFAULT
	setvar VAR_SPACE_CENTER_QUEST_STATE, 4
	closemessage
	release
	end

CosmossSpaceCenter_Text_NeedHelpFunding:
	.string "test$"

CosmossSpaceCenter_Text_WillYouFund:
	.string "test$"

CosmossSpaceCenter_Text_ThanksForFunding:
	.string "test$"

CosmossSpaceCenter_Text_YouCanNowGoUpstairs:
	.string "test$"

CosmossSpaceCenter_Text_NotEnoughMoney:
	.string "test$"

CosmossSpaceCenter_Text_RocketFuel:
	.string "test$"

CosmossSpaceCenter_Text_BattleMyCryplin:
	.string "test$"

CosmossSpaceCenter_Text_PonsonbyIntro:
	.string "test$"

CosmossSpaceCenter_Text_PonsonbyDefeat:
	.string "test$"

CosmossSpaceCenter_Text_LearnedALot:
	.string "test$"

CosmossSpaceCenter_Text_HelpMyFriend:
	.string "test$"

CosmossSpaceCenter_Text_AboutCryplin:
	.string "test$"

CosmossSpaceCenter_Text_HelpFightUFO:
	.string "test$"

CosmossSpaceCenter_Text_RadioWaves:
	.string "test$"

CosmossSpaceCenter_Text_SavedTheRocket:
	.string "test$"

CosmossSpaceCenter_Text_MeteorsFallen:
	.string "test$"

CosmossSpaceCenter_Text_AboutUhefoe:
	.string "test$"

CosmossSpaceCenter_Text_GoCollectMinior:
	.string "test$"

CosmossSpaceCenter_Text_HaveThisShinyMinior:
	.string "test$"

CosmossSpaceCenter_Text_PlayerReceivedShinyMinior:
	.string "test$"

CosmossSpaceCenter_Text_YoureTheBest:
	.string "test$"
