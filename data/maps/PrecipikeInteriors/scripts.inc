PrecipikeInteriors_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PrecipikeInteriors_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, PrecipikeInteriors_OnTransition
	.byte 0

PrecipikeInteriors_OnFrame:
	map_script_2 VAR_TEMP_4, 69, PrecipikeInteriors_EventScript_GiveEgg
	.2byte 0

PrecipikeInteriors_OnTransition:
	call_if_set FLAG_PISCES_D, PrecipikeInteriors_EventScript_SetTempVar
	end

PrecipikeInteriors_EventScript_SetTempVar::
	setvar VAR_TEMP_4, 69
	return

PrecipikeInteriors_EventScript_GiveEgg::
	applymovement OBJ_EVENT_ID_PLAYER, PrecipikeInteriors_Movement_FaceLady
	msgbox PrecipikeInteriors_Text_CaughtThatRascal, MSGBOX_DEFAULT
	setflag FLAG_PRECIPIKE_EGG
	setvar VAR_TEMP_4, 0
	clearflag FLAG_PISCES_D
	clearflag FLAG_TRAP_PRECIPIKE_EGGNEGGMA
	goto PrecipikeInteriors_EventScript_ReceiveEgg
	end

PrecipikeInteriors_EventScript_ReceiveEgg::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EGG
	giveegg SPECIES_DRAKULARK
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PrecipikeInteriors_EventScript_ReceiveEggParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PrecipikeInteriors_EventScript_ReceiveEggPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

PrecipikeInteriors_EventScript_ReceiveEggParty::
	call PrecipikeInteriors_EventScript_ReceivedEggFanfare
	end

PrecipikeInteriors_EventScript_ReceiveEggPC::
	call PrecipikeInteriors_EventScript_ReceivedEggFanfare
	call Common_EventScript_TransferredToPC
	end

PrecipikeInteriors_EventScript_ReceivedEggFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message PrecipikeInteriors_Text_PlayerReceivedEgg
	waitmessage
	waitfanfare
	closemessage
	return

PrecipikeInteriors_Movement_FaceLady:
	face_up
	step_end

PrecipikeInteriors_EventScript_EggLady::
	lock
	faceplayer
	goto_if_set FLAG_SCUTTILL_EGG, PrecipikeInteriors_EventScript_TheEggDemon
	goto_if_set FLAG_PRECIPIKE_EGG, PrecipikeInteriors_EventScript_GoToScuttill
	msgbox PrecipikeInteriors_Text_HelloILikeEggs, MSGBOX_DEFAULT
	goto_if_defeated TRAINER_P_WREN, PrecipikeInteriors_EventScript_CheckMangrottoEgg
	msgbox PrecipikeInteriors_Text_GoHuntSomeEggThieves, MSGBOX_DEFAULT
	closemessage
	release
	end

PrecipikeInteriors_EventScript_CheckMangrottoEgg::
	goto_if_set FLAG_MANGROTTO_EGG, PrecipikeInteriors_EventScript_CheckMossdeepEgg
	msgbox PrecipikeInteriors_Text_GoHuntSomeEggThieves, MSGBOX_DEFAULT
	closemessage
	release
	end

PrecipikeInteriors_EventScript_CheckMossdeepEgg::
	goto_if_set FLAG_MOSSDEEP_EGG, PrecipikeInteriors_EventScript_WantToCatchEgg
	msgbox PrecipikeInteriors_Text_GoHuntSomeEggThieves, MSGBOX_DEFAULT
	closemessage
	release
	end

PrecipikeInteriors_EventScript_WantToCatchEgg::
	msgbox PrecipikeInteriors_Text_WeShouldCatchThatGuy, MSGBOX_DEFAULT
	setflag FLAG_TRAP_PRECIPIKE_EGGNEGGMA
	closemessage
	release
	end

PrecipikeInteriors_EventScript_GoToScuttill::
	msgbox PrecipikeInteriors_Text_GoToScuttill, MSGBOX_AUTOCLOSE
	release
	end

PrecipikeInteriors_EventScript_TheEggDemon::
	msgbox PrecipikeInteriors_Text_TheEggDemon, MSGBOX_AUTOCLOSE
	release
	end

PrecipikeInteriors_EventScript_SadFisherman::
	lock
	faceplayer
	speakername PrecipikeInteriors_Text_NameSadFisher
	goto_if_unset FLAG_RECEIVED_OLD_ROD, PrecipikeInteriors_EventScript_GoGetOldRod
	goto_if_set FLAG_RECEIVED_GOOD_ROD, PrecipikeInteriors_EventScript_HowsFishing
	msgbox PrecipikeInteriors_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PrecipikeInteriors_EventScript_BattleSadFisher
	goto_if_eq VAR_RESULT, NO, PrecipikeInteriors_EventScript_NotGettingItchToFish
	end

PrecipikeInteriors_EventScript_GoGetOldRod::
	msgbox PrecipikeInteriors_Text_GoGetOldRod, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrecipikeInteriors_EventScript_BattleSadFisher::
	trainerbattle_single TRAINER_P_SADFISHER_2, PrecipikeInteriors_Text_SadFisherIntro, PrecipikeInteriors_Text_SadFisherDefeat, PrecipikeInteriors_EventScript_GiveOldRod
	release
	end

PrecipikeInteriors_EventScript_GiveOldRod::
	msgbox PrecipikeInteriors_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	msgbox PrecipikeInteriors_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	speakername NULL
	release
	end

PrecipikeInteriors_EventScript_NotGettingItchToFish::
	msgbox PrecipikeInteriors_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	speakername NULL
	release
	end

PrecipikeInteriors_EventScript_HowsFishing::
	msgbox PrecipikeInteriors_Text_HowsYourFishing, MSGBOX_AUTOCLOSE
	specialvar VAR_RESULT, CheckAllSadsod
	goto_if_eq VAR_RESULT, TRUE, PrecipikeInteriors_EventScript_SaltyTear
	speakername NULL
	release
	end

PrecipikeInteriors_EventScript_SaltyTear::
	checkitem ITEM_SALTY_TEAR
	goto_if_eq VAR_RESULT, TRUE, PrecipikeInteriors_EventScript_GaveSaltyTear
	msgbox PrecipikeInteriors_Text_SadsodMaster, MSGBOX_DEFAULT
	giveitem ITEM_SALTY_TEAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrecipikeInteriors_EventScript_GaveSaltyTear::
	msgbox PrecipikeInteriors_Text_AlreadyGaveIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrecipikeInteriors_Text_NameSadFisher:
	.string "Sad Fisher$"

PrecipikeInteriors_Text_GettingItchToFish:
	.string "want to fight me for goodrod$"

PrecipikeInteriors_Text_GoGetOldRod:
	.string "go get the old rod stupi$"

PrecipikeInteriors_Text_SadFisherIntro:
	.string "gonna beat your ass$"

PrecipikeInteriors_Text_SadFisherDefeat:
	.string "oh no !$"

PrecipikeInteriors_Text_GiveYouOneOfMyRods:
	.string "have my rod lol$"

PrecipikeInteriors_Text_ThrowInFishingAdvice:
	.string "heres advice; fish$"

PrecipikeInteriors_Text_ThatsTooBadThen:
	.string "coward$"

PrecipikeInteriors_Text_HowsYourFishing:
	.string "how goes it$"

PrecipikeInteriors_Text_SadsodMaster:
	.string "woah u have 6 sadsod$"

PrecipikeInteriors_Text_AlreadyGaveIt:
	.string "already gave it charlatan$"

PrecipikeInteriors_Text_CaughtThatRascal:
	.string "gottem$"

PrecipikeInteriors_Text_PlayerReceivedEgg:
	.string "{PLAYER} received an Egg!$"

PrecipikeInteriors_Text_HelloILikeEggs:
	.string "hey i like eggs$"

PrecipikeInteriors_Text_GoHuntSomeEggThieves:
	.string "go get the moss and mang eggs$"

PrecipikeInteriors_Text_WeShouldCatchThatGuy:
	.string "lets go get that MF$"

PrecipikeInteriors_Text_GoToScuttill:
	.string "go to scuttill bro$"

PrecipikeInteriors_Text_TheEggDemon:
	.string "dernon ehhg$"
