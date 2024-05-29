CosmossSpaceCenter_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CosmossSpaceCenter_OnFrame
	.byte 0

CosmossSpaceCenter_OnFrame:
	map_script_2 VAR_SPACE_CENTER_QUEST_STATE, 50, CosmossSpaceCenter_EventScript_AfterInvasion
	.2byte 0

CosmossSpaceCenter_EventScript_AfterInvasion::
	lock
	msgbox CosmossSpaceCenter_Text_SavedTheRocket, MSGBOX_DEFAULT
	setvar VAR_SPACE_CENTER_QUEST_STATE, 3
	msgbox CosmossSpaceCenter_Text_MeteorsFallen, MSGBOX_AUTOCLOSE
	release
	end

CosmossSpaceCenter_EventScript_AIBlock::
	lock
	playse SE_PC_ON
	waitse
	msgbox CosmossSpaceCenter_Text_NoAccess, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, CosmossSpaceCenter_Movement_BackUp
	waitmovement 0
	release
	end

CosmossSpaceCenter_Movement_BackUp:
	walk_down
	step_end

CosmossSpaceCenter_EventScript_RocketResearcher::
	lock
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 0, CosmossSpaceCenter_EventScript_RocketFunded
	msgbox CosmossSpaceCenter_Text_NeedHelpFunding, MSGBOX_DEFAULT
	faceplayer
	showmoneybox 0, 0
	msgbox CosmossSpaceCenter_Text_WillYouFund, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CosmossSpaceCenter_EventScript_CheckMoneyForFund
	goto_if_eq VAR_RESULT, NO, CosmossSpaceCenter_EventScript_ThenGoAway
	closemessage
	hidemoneybox
	release
	end

CosmossSpaceCenter_EventScript_ThenGoAway::
	msgbox CosmossSpaceCenter_Text_ThenGoAway, MSGBOX_DEFAULT
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
	msgbox CosmossSpaceCenter_Text_YouCanNowGoUpstairs, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_ON
	waitse
	msgbox CosmossSpaceCenter_Text_AccessGranted, MSGBOX_AUTOCLOSE
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
	faceplayer
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 1, CosmossSpaceCenter_EventScript_AboutCryplin
	msgbox CosmossSpaceCenter_Text_BattleMyCryplin, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CosmossSpaceCenter_EventScript_MinkowskiBattle
	goto_if_eq VAR_RESULT, NO, CosmossSpaceCenter_EventScript_Understandable
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_Understandable::
	msgbox CosmossSpaceCenter_Text_Understandable, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_MinkowskiBattle::
	trainerbattle_single TRAINER_P_MINKOWSKI, CosmossSpaceCenter_Text_MinkowskiIntro, CosmossSpaceCenter_Text_MinkowskiDefeat, CosmossSpaceCenter_EventScript_LearnedALot
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
	faceplayer
	goto_if_lt VAR_SPACE_CENTER_QUEST_STATE, 2, CosmossSpaceCenter_EventScript_RadioWaves
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 2, CosmossSpaceCenter_EventScript_AboutUhefoe
	msgbox CosmossSpaceCenter_Text_HelpFightUFO, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CosmossSpaceCenter_EventScript_PrepForUhefoeInvasion
	goto_if_eq VAR_RESULT, NO, CosmossSpaceCenter_EventScript_Matrix
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_Matrix::
	msgbox CosmossSpaceCenter_Text_Matrix, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_PrepForUhefoeInvasion::
	msgbox CosmossSpaceCenter_Text_ToTheField, MSGBOX_DEFAULT
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
	faceplayer
	goto_if_lt VAR_SPACE_CENTER_QUEST_STATE, 3, CosmossSpaceCenter_EventScript_CivilianNo
	call_if_eq VAR_SPACE_CENTER_QUEST_STATE, 3, CosmossSpaceCenter_EventScript_GoCollectMinior
	goto_if_gt VAR_SPACE_CENTER_QUEST_STATE, 4, CosmossSpaceCenter_EventScript_ThankYou
	specialvar VAR_RESULT, CheckMiniorRed
	goto_if_eq VAR_RESULT, TRUE, CosmossSpaceCenter_EventScript_CheckOrange
	msgbox CosmossSpaceCenter_Text_NotEnoughMinior, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_CivilianNo::
	msgbox CosmossSpaceCenter_Text_CivilianNo, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_GoCollectMinior::
	setvar VAR_SPACE_CENTER_QUEST_STATE, 4
	msgbox CosmossSpaceCenter_Text_GoCollectMinior, MSGBOX_DEFAULT
	return

CosmossSpaceCenter_EventScript_CheckOrange::
	specialvar VAR_RESULT, CheckMiniorOrange
	goto_if_eq VAR_RESULT, TRUE, CosmossSpaceCenter_EventScript_CheckYellow
	msgbox CosmossSpaceCenter_Text_NotEnoughMinior, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_CheckYellow::
	specialvar VAR_RESULT, CheckMiniorYellow
	goto_if_eq VAR_RESULT, TRUE, CosmossSpaceCenter_EventScript_CheckGreen
	msgbox CosmossSpaceCenter_Text_NotEnoughMinior, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_CheckGreen::
	specialvar VAR_RESULT, CheckMiniorGreen
	goto_if_eq VAR_RESULT, TRUE, CosmossSpaceCenter_EventScript_CheckBlue
	msgbox CosmossSpaceCenter_Text_NotEnoughMinior, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_CheckBlue::
	specialvar VAR_RESULT, CheckMiniorBlue
	goto_if_eq VAR_RESULT, TRUE, CosmossSpaceCenter_EventScript_CheckViolet
	msgbox CosmossSpaceCenter_Text_NotEnoughMinior, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_CheckViolet::
	specialvar VAR_RESULT, CheckMiniorViolet
	goto_if_eq VAR_RESULT, TRUE, CosmossSpaceCenter_EventScript_ReceiveShinyMinior
	msgbox CosmossSpaceCenter_Text_NotEnoughMinior, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_ReceiveShinyMinior::
	msgbox CosmossSpaceCenter_Text_HaveThisShinyMinior, MSGBOX_DEFAULT
	setflag FLAG_FORCED_SHINY
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MINIOR_METEOR_INDIGO
	givemon SPECIES_MINIOR_METEOR_INDIGO, 17, ITEM_COMET_SHARD
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
	setvar VAR_SPACE_CENTER_QUEST_STATE, 5
	closemessage
	release
	end

CosmossSpaceCenter_EventScript_ThankYou::
	msgbox CosmossSpaceCenter_Text_YoureTheBest, MSGBOX_DEFAULT
	closemessage
	release
	end

CosmossSpaceCenter_Text_NoAccess:
	.string "(You hear a sassy female voice\n"
	.string "on the loudspeakers.)\p"
	.string "Excuse me!\p"
	.string "Where do you think you're going!?\n"
	.string "The upstairs is for trusted\l"
	.string "personnel only.$"

CosmossSpaceCenter_Text_AccessGranted:
	.string "(You hear a sassy female voice\n"
	.string "on the loudspeakers.)\p"
	.string "I've skimmed your public records…\p"
	.string "{PLAYER}, is it?\n"
	.string "Dr. Hilbert put in a good word,\l"
	.string "but I'm keeping my A-Eyes on you.\p"
	.string "Don't try anything funny.$"

CosmossSpaceCenter_Text_NeedHelpFunding:
	.string "Ah. A visitor.\p"
	.string "(The scientist tries ignoring you.)\p"
	.string "…What? You want big party?\n"
	.string "Bah, am currently in the middle of\l"
	.string "important work.\p"
	.string "Have been attempting to synthesize new\n"
	.string "green, reliable fuel for rockets.\l"
	.string "No dice.\p"
	.string "Have asked command for funding to help\n"
	.string "research go more smoothly.\l"
	.string "No dice.$"

CosmossSpaceCenter_Text_WillYouFund:
	.string "Would need approximately ¥5000 to\n"
	.string "gather necessary chemicals.\p"
	.string "(Hand over funding money?)$"

CosmossSpaceCenter_Text_ThenGoAway:
	.string "Still here?…\n"
	.string "If not helping, please leave my station.$"

CosmossSpaceCenter_Text_ThanksForFunding:
	.string "…Is quite… kind, of you.\n"
	.string "This will be put to good use.\p"
	.string "Here… take this as payment.$"

CosmossSpaceCenter_Text_YouCanNowGoUpstairs:
	.string "Will tell building AI that\n"
	.string "you assisted me…\l"
	.string "She may allow upstairs access now.$"

CosmossSpaceCenter_Text_NotEnoughMoney:
	.string "Still here?…\n"
	.string "If not helping, please leave my station.$"

CosmossSpaceCenter_Text_RocketFuel:
	.string "Mmph. Research making…\n"
	.string "many breakthroughs.$"

CosmossSpaceCenter_Text_BattleMyCryplin:
	.string "At ease.\p"
	.string "…\p"
	.string "Oh, I'm sorry, I thought you\n"
	.string "were an employee.\l"
	.string "My mistake.\p"
	.string "Though, I must say…\n"
	.string "you must be something special if Hera\l"
	.string "allowed you to come up here.\p"
	.string "I am a military lieutenant, on orders\n"
	.string "to assist the scientists here with the\l"
	.string "field research of extraterrestrial\l"
	.string "Pokémon.\p"
	.string "I have a few rowdy ones with\n"
	.string "me right now.\l"
	.string "Don't suppose you'd want to help them\l"
	.string "let off some steam?$"

CosmossSpaceCenter_Text_Understandable:
	.string "Understandable.\n"
	.string "Come see me if you change your mind.$"

CosmossSpaceCenter_Text_MinkowskiIntro:
	.string "Alright then.\p"
	.string "Cryplin!\n"
	.string "Get on out there; that's an order!$"

CosmossSpaceCenter_Text_MinkowskiDefeat:
	.string "A commanding victory!$"

CosmossSpaceCenter_Text_LearnedALot:
	.string "You displayed some real tactical moves\n"
	.string "with your team.\l"
	.string "I'm impressed.\p"
	.string "Here, I want you to take this\n"
	.string "Eject Pack; one of these has gotten\l"
	.string "me out of a precarious situation\l"
	.string "before, I tell you.$"

CosmossSpaceCenter_Text_HelpMyFriend:
	.string "If you have time, please check on my\n"
	.string "comms officer, Eiffel.\p"
	.string "He, regrettably, is easily…\n"
	.string "distracted.$"

CosmossSpaceCenter_Text_AboutCryplin:
	.string "Our battle brought to mind the time\n"
	.string "I had to defend the facility from a\l"
	.string "rampaging Cardiovor.\p"
	.string "Hah… good times.$"

CosmossSpaceCenter_Text_HelpFightUFO:
	.string "What now?\p"
	.string "…Minkowski wants me to\n"
	.string "stop slacking off?\p"
	.string "Haha!\n"
	.string "Do birds chirp?\p"
	.string "Look, I dunno what command\n"
	.string "is expecting here.\p"
	.string "Do they really believe that my daily\n"
	.string "ET-Phoning-Home is gonna…\p"
	.string "…Uhhh… am I officially off my rocker,\n"
	.string "or… am I seeing an unidentified signal\l"
	.string "at Launch Pad B…?\p"
	.string "C-could I get you to check\n"
	.string "that out for me?$"

CosmossSpaceCenter_Text_RadioWaves:
	.string "Oh, hey.\p"
	.string "Welcome to Casa-de-Doug, home of the\n"
	.string "“Useless Task Club.”\l"
	.string "On the docket today?\p"
	.string "Oh, lookin' like another 8 hours of\n"
	.string "sending out radio signals and\l"
	.string "seeing jack all.\p"
	.string "Fantastic.$"

CosmossSpaceCenter_Text_Matrix:
	.string "Right, right…\n"
	.string "must be a glitch in the matrix…$"

CosmossSpaceCenter_Text_ToTheField:
	.string "Okay…\n"
	.string "I'll send you over to Captain Lovelace.$"

CosmossSpaceCenter_Text_SavedTheRocket:
	.string "Watched you beat the crap out of that\n"
	.string "freaky floatin' curling stone\l"
	.string "from here. Kudos!$"

CosmossSpaceCenter_Text_MeteorsFallen:
	.string "While that was going on, I happened to\n"
	.string "spot a couple chunks of meteorite on\l"
	.string "a crash course for the\l"
	.string "bridge and the city.\p"
	.string "Seems like none of 'em\n"
	.string "did any major damage.\p"
	.string "If you want to go pick yourself up a\n"
	.string "genuine space rock, here's your shot.$"

CosmossSpaceCenter_Text_AboutUhefoe:
	.string "Yawn… back on the nada grind.\p"
	.string "Should steal myself more coffee\n"
	.string "when Minkowski isn't looking…$"

CosmossSpaceCenter_Text_CivilianNo:
	.string "Ah, hello there.\p"
	.string "You're a civilian, no?\p"
	.string "As the boss, I have to ask you to\n"
	.string "leave my team to their work.\l"
	.string "No distractions when we're making\l"
	.string "so much progress!$"

CosmossSpaceCenter_Text_GoCollectMinior:
	.string "Well, now, if it isn't Officer\n"
	.string "{PLAYER}!\p"
	.string "Oh? You're no officer?\p"
	.string "Pish-posh! Let's see the\n"
	.string "bigger picture here:\p"
	.string "You've been outperforming\n"
	.string "my subordinates! I'll have to give them\l"
	.string "a… stern talking to.\p"
	.string "While you're here, Officer {PLAYER},\n"
	.string "I could use some help.\p"
	.string "You see, I have an interest in those\n"
	.string "meteorites that have recently landed.\p"
	.string "I have concluded that they contain the\n"
	.string "Pokémon Minior, hiding inside.\p"
	.string "They come in many color variants.\n"
	.string "May I ask you to seek and capture all\l"
	.string "six? You will be rewarded.$"

CosmossSpaceCenter_Text_HaveThisShinyMinior:
	.string "Wonderful! You have all\n"
	.string "colors of Minior!\l"
	.string "What a pretty little rainbow.\p"
	.string "Except…\p"
	.string "Missing a color, aren't you?\p"
	.string "That's right, any self-respecting\n"
	.string "Minior expert would know there's 7\l"
	.string "variants.\p"
	.string "…But those are only found in\n"
	.string "Midneor Falls to the north.\p"
	.string "In fact, I have a special indigo\n"
	.string "colored Minior with your name on it.\p"
	.string "On behalf of all of us at the space\n"
	.string "center, you may have it.$"

CosmossSpaceCenter_Text_PlayerReceivedShinyMinior:
	.string "{PLAYER} received a special\n"
	.string "Indigo Minior!$"

CosmossSpaceCenter_Text_YoureTheBest:
	.string "My team sends their regards,\n"
	.string "Officer {PLAYER}.\l"
	.string "You can always feel welcome here!$"

CosmossSpaceCenter_Text_NotEnoughMinior:
	.string "From the looks of it, you don't have\n"
	.string "all six Minior forms on you.\p"
	.string "What a shame…\p"
	.string "Come meet me with all 6 in your party.$"
