PacifidlogInteriors_MapScripts::
	.byte 0

PacifidlogInteriors_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, PacifidlogInteriors_EventScript_HowsFishing
	goto_if_set FLAG_RECEIVED_GOOD_ROD, PacifidlogInteriors_EventScript_SaltySeas
	msgbox PacifidlogInteriors_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogInteriors_EventScript_BattleSadFisher
	goto_if_eq VAR_RESULT, NO, PacifidlogInteriors_EventScript_NotGettingItchToFish
	end

PacifidlogInteriors_EventScript_BattleSadFisher::
	trainerbattle_single TRAINER_P_SADFISHER_1, PacifidlogInteriors_Text_SadFisherIntro, PacifidlogInteriors_Text_SadFisherDefeat, PacifidlogInteriors_EventScript_GiveOldRod
	release
	end

PacifidlogInteriors_EventScript_GiveOldRod::
	speakername PacifidlogInteriors_Text_NameSadFisher
	msgbox PacifidlogInteriors_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox PacifidlogInteriors_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	speakername NULL
	release
	end

PacifidlogInteriors_EventScript_NotGettingItchToFish::
	msgbox PacifidlogInteriors_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

PacifidlogInteriors_EventScript_HowsFishing::
	speakername PacifidlogInteriors_Text_NameSadFisher
	message PacifidlogInteriors_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, PacifidlogInteriors_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, PacifidlogInteriors_EventScript_FishingNotSoGood
	end

PacifidlogInteriors_EventScript_FishingExcellent::
	msgbox PacifidlogInteriors_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	speakername NULL
	release
	end

PacifidlogInteriors_EventScript_FishingNotSoGood::
	msgbox PacifidlogInteriors_Text_FishingAdvice, MSGBOX_DEFAULT
	speakername NULL
	release
	end

PacifidlogInteriors_EventScript_SaltySeas::
	speakername PacifidlogInteriors_Text_NameSadFisher
	msgbox PacifidlogInteriors_Text_HowsYourFishing, MSGBOX_AUTOCLOSE
	specialvar VAR_RESULT, CheckAllSadsod
	goto_if_eq VAR_RESULT, TRUE, PacifidlogInteriors_EventScript_SaltyTear
	speakername NULL
	release
	end

PacifidlogInteriors_EventScript_SaltyTear::
	checkitem ITEM_SALTY_TEAR
	goto_if_eq VAR_RESULT, TRUE, PacifidlogInteriors_EventScript_GaveSaltyTear
	msgbox PacifidlogInteriors_Text_SadsodMaster, MSGBOX_DEFAULT
	speakername NULL
	giveitem ITEM_SALTY_TEAR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

PacifidlogInteriors_EventScript_GaveSaltyTear::
	msgbox PacifidlogInteriors_Text_AlreadyGaveIt, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PacifidlogInteriors_EventScript_OldMan::
	msgbox PacifidlogInteriors_Text_OldMan, MSGBOX_NPC
	end

PacifidlogInteriors_EventScript_Angler::
	msgbox PacifidlogInteriors_Text_Angler, MSGBOX_NPC
	end

PacifidlogInteriors_EventScript_Fisher::
	msgbox PacifidlogInteriors_Text_Fisher, MSGBOX_NPC
	end

PacifidlogInteriors_EventScript_Sailor::
	msgbox PacifidlogInteriors_Text_Sailor, MSGBOX_NPC
	end

PacifidlogInteriors_EventScript_DarkskinBoy1::
	msgbox PacifidlogInteriors_Text_DarkskinBoy1, MSGBOX_NPC
	end

PacifidlogInteriors_EventScript_DarkskinBoy2::
	msgbox PacifidlogInteriors_Text_DarkskinBoy2, MSGBOX_NPC
	end

PacifidlogInteriors_EventScript_DarkskinWoman::
	msgbox PacifidlogInteriors_Text_DarkskinWoman, MSGBOX_NPC
	end

PacifidlogInteriors_EventScript_OldWoman::
	msgbox PacifidlogInteriors_Text_OldWoman, MSGBOX_NPC
	end

PacifidlogInteriors_Text_NameSadFisher:
	.string "Sad Fisher$"

PacifidlogInteriors_Text_GettingItchToFish:
	.string "...How's life been for you, trainer?\n"
	.string "I hope that you came because of my\l"
	.string "sign outside.\p"
	.string "Are you wanting to get serious\n"
	.string "about fishing up and catching\l"
	.string "strong piscine POKéMON?$"

PacifidlogInteriors_Text_SadFisherIntro:
	.string "Prove it to me, then.\p"
	.string "If you can take down my team of\n"
	.string "six all-stars... you will\l"
	.string "be heavily rewarded.$"

PacifidlogInteriors_Text_SadFisherDefeat:
	.string "Well... isn't that interesting...$"

PacifidlogInteriors_Text_GiveYouOneOfMyRods:
	.string "Not many can weather the storm\n"
	.string "of my six Sadsod. You've more than\l"
	.string "earned this special fishing tool...$"

PacifidlogInteriors_Text_ThrowInFishingAdvice:
	.string "That is special bait that I\n"
	.string "crafted myself. It's fine-tuned to\l"
	.string "attract small, scrappy fish.\p"
	.string "You might say that the smallest\n"
	.string "fish are the weakest ones, but I\l"
	.string "am living proof that they are\l"
	.string "powerful in the right hands.\p"
	.string "Use it wisely and raise them with care.$"

PacifidlogInteriors_Text_ThatsTooBadThen:
	.string "...Cowardly. Come back if you ever\n"
	.string "decide to take charge in your life.$"

PacifidlogInteriors_Text_HowsYourFishing:
	.string "How have your fishing escapades been\n"
	.string "going? Hook any interesting fish?$"

PacifidlogInteriors_Text_GreatHaulInSomeBigOnes:
	.string "Keep it up. Play your cards right\n"
	.string "and I may hook you up with more\l"
	.string "advanced tools in the future.$"

PacifidlogInteriors_Text_FishingAdvice:
	.string "Then you... must not be giving\n"
	.string "it your all at the waves.\p"
	.string "Be patient and keep at it.$"

PacifidlogInteriors_Text_OldMan:
	.string "Ah.\p"
	.string "Mmmf... the years have not been kind\n"
	.string "to me, I tell you.\p"
	.string "I used to keep a watchful eye on an\n"
	.string "odd phenomenon towards the east seas.\p"
	.string "Mirage Island, it became known as.\p"
	.string "Dozens of adventuring seafarers sought\n"
	.string "to reach that mystical place...\l"
	.string "And they all failed.\p"
	.string "The area known as the Sailor's Pause\n"
	.string "is where the derelict remains of those\l"
	.string "failed voyages are left to wither.$"

PacifidlogInteriors_Text_Angler:
	.string "Today, I'm as hungry as a Gupspar!$"

PacifidlogInteriors_Text_Fisher:
	.string "Your fun metaphors don't give\n"
	.string "you an excuse to eat more than\l"
	.string "your fair share, now!$"

PacifidlogInteriors_Text_Sailor:
	.string "Hey! I'm sittin' here waitin'\n"
	.string "for my employees to bring over our\l"
	.string "feast for the evening.\p"
	.string "What's takin' 'em so dang long!?\n"
	.string "It's just a couple pounds of seafood!$"

PacifidlogInteriors_Text_DarkskinBoy1:
	.string "Fufufufu...\p"
	.string "I had my pet Marinaroc hide out\n"
	.string "inside this guy's fish crate.\p"
	.string "He'll have to go help those\n"
	.string "guys lift it if he wants to eat!$"

PacifidlogInteriors_Text_DarkskinBoy2:
	.string "I like to drink the water\n"
	.string "from the ocean!\p"
	.string "...Don't do that? Gosh...\n"
	.string "that's what they ALL say...$"

PacifidlogInteriors_Text_DarkskinWoman:
	.string "Sigh...\p"
	.string "My son's sodium intake is so\n"
	.string "beyond the pale. I've been feeding\l"
	.string "him nothing but celery to try\l"
	.string "and counterbalance it.$"

PacifidlogInteriors_Text_OldWoman:
	.string "Legends tell of a flying serpent\n"
	.string "POKéMON named Rayquaza, that defended\l"
	.string "the region against cataclysmic events.\p"
	.string "Its old home, Sky Pillar, lies north\n"
	.string "of our humble town. Mayhaps\l"
	.string "I will pay it a visit today.$"

PacifidlogInteriors_Text_SadsodMaster:
	.string "woah u have 6 sadsod$"

PacifidlogInteriors_Text_AlreadyGaveIt:
	.string "already gave it charlatan$"
