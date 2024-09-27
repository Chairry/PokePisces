FossilShoreHouses_MapScripts::
	.byte 0

FossilShoreHouses_EventScript_Drake::
	lock
	faceplayer
	goto_if_lt VAR_OLD_GUYS_STATE, 8, FossilShoreHouses_EventScript_DrakePreDock
	goto_if_gt VAR_OLD_GUYS_STATE, 8, FossilShoreHouses_EventScript_DrakePostDock
	goto_if_set FLAG_DOCK_QUEST_FOUND_DRAKE, FossilShoreHouses_EventScript_DrakeGatherOthers
	setflag FLAG_DOCK_QUEST_FOUND_DRAKE
	speakername FossilShoreHouses_Text_NameDrake
	msgbox FossilShoreHouses_Text_DockNeedsMe, MSGBOX_AUTOCLOSE
	release
	end

FossilShoreHouses_EventScript_DrakePreDock::
	msgbox FossilShoreHouses_Text_DrakePreDock, MSGBOX_AUTOCLOSE
	release
	end

FossilShoreHouses_EventScript_DrakePostDock::
	msgbox FossilShoreHouses_Text_DrakePostDock, MSGBOX_AUTOCLOSE
	release
	end

FossilShoreHouses_EventScript_DrakeGatherOthers::
	msgbox FossilShoreHouses_Text_DrakeGatherOthers, MSGBOX_AUTOCLOSE
	release
	end

FossilShoreHouses_EventScript_SadFisherman::
	lock
	faceplayer
	speakername FossilShoreHouses_Text_NameSadFisher
	goto_if_unset FLAG_RECEIVED_OLD_ROD, FossilShoreHouses_EventScript_NoOldRod
	goto_if_unset FLAG_RECEIVED_GOOD_ROD, FossilShoreHouses_EventScript_NoGoodRod
	goto_if_set FLAG_RECEIVED_SUPER_ROD, FossilShoreHouses_EventScript_HowsFishing
	msgbox FossilShoreHouses_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FossilShoreHouses_EventScript_BattleSadFisher
	goto_if_eq VAR_RESULT, NO, FossilShoreHouses_EventScript_NotGettingItchToFish
	end

FossilShoreHouses_EventScript_NoOldRod::
	msgbox FossilShoreHouses_Text_NoOldRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FossilShoreHouses_EventScript_BattleSadFisherNoOldRod
	msgbox FossilShoreHouses_Text_DontLetDoorHitYa, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_BattleSadFisherNoOldRod::
	trainerbattle_single TRAINER_P_SADFISHER_2, FossilShoreHouses_Text_SadFisherIntro, FossilShoreHouses_Text_SadFisherDefeat, FossilShoreHouses_EventScript_GiveOldGoodAndSuperRod
	release
	end

FossilShoreHouses_EventScript_GiveOldGoodAndSuperRod::
	msgbox FossilShoreHouses_Text_PostNoOld, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox FossilShoreHouses_Text_FishingAdviceNoOld, MSGBOX_DEFAULT
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_NoGoodRod::
	msgbox FossilShoreHouses_Text_NoGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FossilShoreHouses_EventScript_BattleSadFisherNoGoodRod
	msgbox FossilShoreHouses_Text_DontLetDoorHitYa, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_BattleSadFisherNoGoodRod::
	trainerbattle_single TRAINER_P_SADFISHER_2, FossilShoreHouses_Text_SadFisherIntro, FossilShoreHouses_Text_SadFisherDefeat, FossilShoreHouses_EventScript_GiveGoodAndSuperRod
	release
	end

FossilShoreHouses_EventScript_GiveGoodAndSuperRod::
	msgbox FossilShoreHouses_Text_PostNoGood, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	setflag FLAG_RECEIVED_GOOD_ROD
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox FossilShoreHouses_Text_FishingAdviceNoGood, MSGBOX_DEFAULT
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_BattleSadFisher::
	trainerbattle_single TRAINER_P_SADFISHER_2, FossilShoreHouses_Text_SadFisherIntro, FossilShoreHouses_Text_SadFisherDefeat, FossilShoreHouses_EventScript_GiveGoodRod
	release
	end

FossilShoreHouses_EventScript_GiveGoodRod::
	msgbox FossilShoreHouses_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox FossilShoreHouses_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_NotGettingItchToFish::
	msgbox FossilShoreHouses_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_HowsFishing::
	msgbox FossilShoreHouses_Text_HowsYourFishing, MSGBOX_AUTOCLOSE
	specialvar VAR_RESULT, CheckAllSadsod
	goto_if_eq VAR_RESULT, TRUE, FossilShoreHouses_EventScript_SaltyTear
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_SaltyTear::
	checkitem ITEM_SALTY_TEAR
	goto_if_eq VAR_RESULT, TRUE, FossilShoreHouses_EventScript_GaveSaltyTear
	msgbox FossilShoreHouses_Text_SadsodMaster, MSGBOX_DEFAULT
	giveitem ITEM_SALTY_TEAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

FossilShoreHouses_EventScript_GaveSaltyTear::
	msgbox FossilShoreHouses_Text_AlreadyGaveIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

FossilShoreHouses_Text_NameSadFisher:
	.string "Sad Fisher$"

FossilShoreHouses_Text_GettingItchToFish:
	.string "Surprised to come upon me again, eh?\n"
	.string "Well, the shores have a way of\l"
	.string "keepin' fishers connected.\p"
	.string "I see you've been gettin' good use\n"
	.string "out of your current fishin' skills.\l"
	.string "Maybe it's time you got yourself\l"
	.string "a shiny new upgrade.\p"
	.string "Lucky you. I have a spare rod.\n"
	.string "Bit of a step up from your gear.\l"
	.string "But I ain't givin' it up\l"
	.string "without a battle, rookie.\p"
	.string "You prepared?\n"
	.string "I ain't goin' easy on ya this time.$"

FossilShoreHouses_Text_NoOldRod:
	.string "placeholder$"

FossilShoreHouses_Text_NoGoodRod:
	.string "...Hey, stranger.\p"
	.string "Hmm... you've gotten this far\n"
	.string "without any fishin' whatsoever!?\l"
	.string "Must be equally foolish, and lucky.\p"
	.string "MAYBE I shouldn't give you the\n"
	.string "courtesy of offerin' a Good Rod.\l"
	.string "But... eh, what's a hobby\l"
	.string "if ya don't try sharin' it.\p"
	.string "Best me in battle, I give ya\n"
	.string "an Old AND Good Rod. But I'm\l"
	.string "a high level competitor...\p"
	.string "Sound like a plan?\n$"

FossilShoreHouses_Text_SadFisherIntro:
	.string "Don't you shed a tear\n"
	.string "when you get whooped, y'hear?$"

FossilShoreHouses_Text_SadFisherDefeat:
	.string "...Showed me up.$"

FossilShoreHouses_Text_GiveYouOneOfMyRods:
	.string "Time for the next level, {PLAYER}.$"

FossilShoreHouses_Text_ThrowInFishingAdvice:
	.string "This rod is more enticing\n"
	.string "to a broad range of aquatic Pokemon.\l"
	.string "I'd advise usin' it whenever\l"
	.string "you see water. You'll haul in\l"
	.string "quite a few new catches.$"

FossilShoreHouses_Text_ThatsTooBadThen:
	.string "Hah!\n"
	.string "Once a rookie, always a rookie.$"

FossilShoreHouses_Text_DontLetDoorHitYa:
	.string "Then don't let the door hit ya\n"
	.string "on your way out.$"

FossilShoreHouses_Text_PostNoOld:
	.string "placeholder$"

FossilShoreHouses_Text_FishingAdviceNoOld:
	.string "placeholder$"

FossilShoreHouses_Text_PostNoGood:
	.string "Fair n' square. Here's your gear.$"

FossilShoreHouses_Text_FishingAdviceNoGood:
	.string "Take them there rods out to any\n"
	.string "shoreline and let 'em rip.\l"
	.string "Huge variety of Pokemon in\l"
	.string "the water that you can't be\l"
	.string "gettin' anywhere else.\p"
	.string "Don't remain ignorant to the\n"
	.string "call of the seas, got it?\l"
	.string "...n' best of luck to ya.$"

FossilShoreHouses_Text_HowsYourFishing:
	.string "Sadsod's my most liked Pokemon.\n"
	.string "There's somethin' in their\l"
	.string "demeanor that makes ya want\l"
	.string "to care for 'em.\p"
	.string "Catch one and give it a good home.$"

FossilShoreHouses_Text_SadsodMaster:
	.string "Well, I'll be damned!\n"
	.string "A whole party of Sadsod, like me...\l"
	.string "you have pristine piscine taste.\p"
	.string "Listen up. I don't have plans\n"
	.string "to evolve mine, but... you might.\l"
	.string "And to do that, Sadsod must be...\l"
	.string "err, pushed, more than most.\p"
	.string "This item may help ya.\n"
	.string "But take caution, as the little guy\l"
	.string "may get even sadder...$"

FossilShoreHouses_Text_AlreadyGaveIt:
	.string "I can hear your Sadsod grunting\n"
	.string "occassionally. That means they\l"
	.string "like ya.$"

FossilShoreHouses_Text_NameDrake:
	.string "Drake$"

FossilShoreHouses_Text_DockNeedsMe:
	.string "dock needs me to show tf up$"

FossilShoreHouses_Text_DrakePreDock:
	.string "welcome to my house$"

FossilShoreHouses_Text_DrakePostDock:
	.string "never talk 2 me again$"

FossilShoreHouses_Text_DrakeGatherOthers:
	.string "gather the other doods$"
