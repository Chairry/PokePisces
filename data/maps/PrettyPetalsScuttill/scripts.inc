.set LOCALID_COURTNEY, 1
.set LOCALID_SISTER1, 2
.set LOCALID_SISTER2, 3
.set LOCALID_SISTER3, 4
.set LOCALID_SISTER1POST, 5
.set LOCALID_SISTER2POST, 7
.set LOCALID_SISTER3POST, 6

PrettyPetalsScuttill_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PrettyPetalsScuttill_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PrettyPetalsScuttill_OnFrame
	.byte 0

PrettyPetalsScuttill_OnFrame:
	map_script_2 VAR_TEMP_4, 1, PrettyPetalsScuttill_EventScript_FightRita
	map_script_2 VAR_OZONE_ADMINS_STATE, 3, PrettyPetalsScuttill_EventScript_BloomingEvent
	.2byte 0

PrettyPetalsScuttill_OnLoad:
	call_if_le VAR_OZONE_ADMINS_STATE, 3, PrettyPetalsScuttill_EventScript_SetSistersFlagsPre
	call_if_gt VAR_OZONE_ADMINS_STATE, 3, PrettyPetalsScuttill_EventScript_SetSistersFlagsPost
	end

PrettyPetalsScuttill_EventScript_SetSistersFlagsPre::
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	removeobject LOCALID_SISTER1POST
	removeobject LOCALID_SISTER2POST
	removeobject LOCALID_SISTER3POST
	return

PrettyPetalsScuttill_EventScript_SetSistersFlagsPost::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	removeobject LOCALID_COURTNEY
	removeobject LOCALID_SISTER1
	removeobject LOCALID_SISTER2
	removeobject LOCALID_SISTER3
	return

PrettyPetalsScuttill_EventScript_BloomingEvent::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, PrettyPetalsScuttill_Movement_WalkIn
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyGreet
	waitmovement 0
	msgbox PrettyPetalsScuttill_Text_Courtney1, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, PrettyPetalsScuttill_Movement_PlayerMoveToPos
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyMoveToPos
	waitmovement 0
	applymovement LOCALID_SISTER2, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Rita1, MSGBOX_DEFAULT
	speakername PrettyPetalsScuttill_Text_NameNatalie
	applymovement LOCALID_SISTER1, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Natalie1, MSGBOX_DEFAULT
	speakername PrettyPetalsScuttill_Text_NameNicole
	applymovement LOCALID_SISTER3, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Nicole1, MSGBOX_DEFAULT
	speakername PrettyPetalsScuttill_Text_NameNatalie
	applymovement LOCALID_SISTER1, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Natalie2, MSGBOX_DEFAULT
	speakername PrettyPetalsScuttill_Text_NameCourtney
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyTalk
	msgbox PrettyPetalsScuttill_Text_Courtney2, MSGBOX_DEFAULT
	speakername PrettyPetalsScuttill_Text_NameNatalie
	applymovement LOCALID_SISTER1, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Natalie3, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_NATALIE, PrettyPetalsScuttill_Text_NatalieDefeat, TRAINER_P_NICOLE, PrettyPetalsScuttill_Text_NicoleDefeat, PrettyPetalsScuttill_EventScript_NatalieNicoleDefeated, NO_MUSIC
	goto PrettyPetalsScuttill_EventScript_NatalieNicoleDefeated
	release
	end

PrettyPetalsScuttill_Movement_WalkIn:
	walk_up
	walk_up
	walk_up
	step_end

PrettyPetalsScuttill_Movement_CourtneyGreet:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

PrettyPetalsScuttill_Movement_PlayerMoveToPos:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_up
	step_end

PrettyPetalsScuttill_Movement_CourtneyMoveToPos:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

PrettyPetalsScuttill_Movement_SisterTalk:
	walk_in_place_down
	step_end

PrettyPetalsScuttill_Movement_CourtneyTalk:
	walk_in_place_right
	step_end

PrettyPetalsScuttill_EventScript_NatalieNicoleDefeated::
	lock
	setvar VAR_TEMP_4, 1
	cleartrainerflag TRAINER_P_RITA
	speakername PrettyPetalsScuttill_Text_NameNicole
	applymovement LOCALID_SISTER3, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Nicole2, MSGBOX_DEFAULT
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_FightRita::
	lock
	speakername PrettyPetalsScuttill_Text_NameRita
	applymovement LOCALID_SISTER2, PrettyPetalsScuttill_Movement_SisterTalk
	waitmovement 0
	trainerbattle_single TRAINER_P_RITA, PrettyPetalsScuttill_Text_Rita2, PrettyPetalsScuttill_Text_RitaDefeat, PrettyPetalsScuttill_EventScript_BloomingEventDone
	release
	end

PrettyPetalsScuttill_EventScript_BloomingEventDone::
	lock
	setvar VAR_TEMP_4, 2
	speakername PrettyPetalsScuttill_Text_NameRita
	applymovement LOCALID_SISTER2, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Rita3, MSGBOX_DEFAULT
	speakername PrettyPetalsScuttill_Text_NameNicole
	applymovement LOCALID_SISTER3, PrettyPetalsScuttill_Movement_SisterTalk
	msgbox PrettyPetalsScuttill_Text_Nicole3, MSGBOX_DEFAULT
	speakername PrettyPetalsScuttill_Text_NameCourtney
	applymovement LOCALID_COURTNEY, PrettyPetalsScuttill_Movement_CourtneyTalk
	msgbox PrettyPetalsScuttill_Text_Courtney3, MSGBOX_DEFAULT
	speakername NULL
	setvar VAR_OZONE_ADMINS_STATE, 4
	setflag FLAG_DEFEATED_OZONE_BRANCH
	warp MAP_ROUTE120, 31, 83
	release
	end

PrettyPetalsScuttill_EventScript_Natalie::
	lock
	faceplayer
	speakername PrettyPetalsScuttill_Text_NameNatalie
	goto_if_lt VAR_OZONE_ADMINS_STATE, 4, PrettyPetalsScuttill_EventScript_NataliePreBloom
	checkitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, TRUE, PrettyPetalsScuttill_EventScript_GaveTropKick
	msgbox PrettyPetalsScuttill_Text_DoYouHaveKickMove, MSGBOX_DEFAULT
	checkpartynonhmmove MOVE_DOUBLE_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_CheckLowKick
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_CheckLowKick::
	checkpartynonhmmove MOVE_LOW_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_CheckBlazeKick
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_CheckBlazeKick::
	checkpartynonhmmove MOVE_BLAZE_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_CheckTripleKick
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_CheckTripleKick::
	checkpartynonhmmove MOVE_TRIPLE_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_CheckJumpKick
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_CheckJumpKick::
	checkpartynonhmmove MOVE_JUMP_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_CheckHighJumpKick
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_CheckHighJumpKick::
	checkpartynonhmmove MOVE_HIGH_JUMP_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_CheckRollingKick
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_CheckRollingKick::
	checkpartynonhmmove MOVE_ROLLING_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_CheckMegaKick
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_CheckMegaKick::
	checkpartynonhmmove MOVE_MEGA_KICK
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_NoKickingMoves
	msgbox PrettyPetalsScuttill_Text_YouHaveKickMove, MSGBOX_DEFAULT
	giveitem ITEM_TM_TROP_KICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_NoKickingMoves::
	msgbox PrettyPetalsScuttill_Text_NoKickMove, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_GaveTropKick::
	msgbox PrettyPetalsScuttill_Text_PostTropKick, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_NataliePreBloom::
	speakername PrettyPetalsScuttill_Text_NameNatalie
	msgbox PrettyPetalsScuttill_Text_NatPreBloom, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_Nicole::
	lock
	faceplayer
	speakername PrettyPetalsScuttill_Text_NameNicole
	goto_if_lt VAR_OZONE_ADMINS_STATE, 4, PrettyPetalsScuttill_EventScript_NicolePreBloom
	checkitem ITEM_FAIRY_RING
	goto_if_eq VAR_RESULT, TRUE, PrettyPetalsScuttill_EventScript_GaveFairyRing
	msgbox PrettyPetalsScuttill_Text_DoYouHaveIngrain, MSGBOX_DEFAULT
	checkpartynonhmmove MOVE_INGRAIN
	goto_if_eq VAR_RESULT, PARTY_SIZE, PrettyPetalsScuttill_EventScript_NoIngrain
	msgbox PrettyPetalsScuttill_Text_YouHaveIngrain, MSGBOX_DEFAULT
	giveitem ITEM_FAIRY_RING
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_NoIngrain::
	msgbox PrettyPetalsScuttill_Text_NoIngrain, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_GaveFairyRing::
	msgbox PrettyPetalsScuttill_Text_PostFairyRing, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_NicolePreBloom::
	speakername PrettyPetalsScuttill_Text_NameNicole
	msgbox PrettyPetalsScuttill_Text_NicPreBloom, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_Rita::
	lock
	faceplayer
	speakername PrettyPetalsScuttill_Text_NameRita
	goto_if_lt VAR_OZONE_ADMINS_STATE, 4, PrettyPetalsScuttill_EventScript_RitaPreBloom
	checkitem ITEM_WEIRD_STICK
	goto_if_eq VAR_RESULT, TRUE, PrettyPetalsScuttill_EventScript_GoCollectSticks
	msgbox PrettyPetalsScuttill_Text_AboutSticks, MSGBOX_DEFAULT
	giveitem ITEM_WEIRD_STICK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox PrettyPetalsScuttill_Text_Need100Sticks, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_RitaPreBloom::
	msgbox PrettyPetalsScuttill_Text_RitaPreBloom, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_GoCollectSticks::
	checkitem ITEM_WEIRD_STICK, 100
	goto_if_eq VAR_RESULT, TRUE, PrettyPetalsScuttill_EventScript_GotTheSticks
	msgbox PrettyPetalsScuttill_Text_Need100Sticks, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_GotTheSticks::
	msgbox PrettyPetalsScuttill_Text_Wow100Sticks, MSGBOX_DEFAULT
	giveitem ITEM_MAX_POTION
	msgbox PrettyPetalsScuttill_Text_StickMaster, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PrettyPetalsScuttill_EventScript_BerryShop::
	lock
	faceplayer
	message PrettyPetalsScuttill_Text_WelcomeToPrettyPetals
	waitmessage
	pokemart PrettyPetalsScuttill_Mart_BerryShop
	msgbox PrettyPetalsScuttill_Text_HaveAPrettyPleasantDay, MSGBOX_AUTOCLOSE
	release
	end

	.align 2
PrettyPetalsScuttill_Mart_BerryShop:
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_PERSIM_BERRY
	.2byte ITEM_PAMTRE_BERRY
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_NONE
	release
	end	

PrettyPetalsScuttill_Text_NameCourtney:
	.string "Courtney$"

PrettyPetalsScuttill_Text_NameRita:
	.string "Rita$"

PrettyPetalsScuttill_Text_NameNatalie:
	.string "Natalie$"

PrettyPetalsScuttill_Text_NameNicole:
	.string "Nicole$"

PrettyPetalsScuttill_Text_WelcomeToPrettyPetals:
	.string "Welcome to Pretty Petals!\n"
	.string "All of our produce is hand-picked\l"
	.string "and home-grown by our 3\l"
	.string "lovely owners!\p"
	.string "How may I help?$"

PrettyPetalsScuttill_Text_HaveAPrettyPleasantDay:
	.string "Have a Pretty Pleasant day!$"

PrettyPetalsScuttill_Text_NatPreBloom:
	.string "hey im nat$"

PrettyPetalsScuttill_Text_DoYouHaveKickMove:
	.string "do u have a kickin move$"

PrettyPetalsScuttill_Text_YouHaveKickMove:
	.string "u have one take this$"

PrettyPetalsScuttill_Text_NoKickMove:
	.string "no kick no dick$"

PrettyPetalsScuttill_Text_PostTropKick:
	.string "trop kick cool eh?$"

PrettyPetalsScuttill_Text_NicPreBloom:
	.string "hello im nicole$"

PrettyPetalsScuttill_Text_DoYouHaveIngrain:
	.string "do u have ingrain$"

PrettyPetalsScuttill_Text_YouHaveIngrain:
	.string "u do have this$"

PrettyPetalsScuttill_Text_NoIngrain:
	.string "no ingrain, ingrate$"

PrettyPetalsScuttill_Text_PostFairyRing:
	.string "wear dat fairy ring$"

PrettyPetalsScuttill_Text_RitaPreBloom:
	.string "me be rita$"

PrettyPetalsScuttill_Text_AboutSticks:
	.string "u get sticks from cut trees\n"
	.string "here is 1 to start$"

PrettyPetalsScuttill_Text_Need100Sticks:
	.string "bring me 100$"

PrettyPetalsScuttill_Text_Wow100Sticks:
	.string "wow holy shit have this$"

PrettyPetalsScuttill_Text_StickMaster:
	.string "stick master $"

PrettyPetalsScuttill_Text_Courtney1:
	.string "Welcome to Pretty Petal Flower Shop!\p"
	.string "We're actually holding a class today\n"
	.string "if you'd like to join in.\l"
	.string "Could I have your name?\p"
	.string "…\p"
	.string "{PLAYER}?\n"
	.string "And, er, Tabitha sent you?\l"
	.string "My, my. A small world we live in.\p"
	.string "Let's not dawdle around here;\n"
	.string "I should get to introductions.\l"
	.string "Come along.$"

PrettyPetalsScuttill_Text_Rita1:
	.string "Ah, a new guest. Pleased\n"
	.string "to make your acquaintance!\p"
	.string "I am Rita; I own and run the shop\n"
	.string "alongside my younger sisters,\l"
	.string "Natalie and Nicole.\p"
	.string "The lovely Courtney, who greeted you,\n"
	.string "is a lifelong friend of mine.$"

PrettyPetalsScuttill_Text_Natalie1:
	.string "Hmph! I'm not all impressed by 'em.\p"
	.string "Hey, Trainer! Ready to get thrown\n"
	.string "for a loop, Scuttill Style?$"

PrettyPetalsScuttill_Text_Nicole1:
	.string "NAT! That's no way to treat newbies.\n"
	.string "Aren't we SUPPOSED to be\l"
	.string "teaching here?$"

PrettyPetalsScuttill_Text_Natalie2:
	.string "Best way to learn is harsh punishment!$"

PrettyPetalsScuttill_Text_Courtney2:
	.string "{PLAYER}, keep a cool head.\p"
	.string "These sisters are going to deploy the\n"
	.string "fancy “Blooming” status\l"
	.string "on you in battle.\p"
	.string "It's a complex status that benefits\n"
	.string "those that contract it in many ways;\l"
	.string "ESPECIALLY Grass-type Pokémon.\p"
	.string "Try and pay close attention to the way\n"
	.string "it affects their moves.$"

PrettyPetalsScuttill_Text_Natalie3:
	.string "Ah-ah-ah!\p"
	.string "Enough lecturing! More battling!$"

PrettyPetalsScuttill_Text_NatalieDefeat:
	.string "Crud! Blast! Fiddlesticks!$"

PrettyPetalsScuttill_Text_NicoleDefeat:
	.string "I do hope you learned\n"
	.string "something from my moves!$"

PrettyPetalsScuttill_Text_Nicole2:
	.string "You're awfuly tough. Big sis\n"
	.string "will need to bring her A-game!$"

PrettyPetalsScuttill_Text_Rita2:
	.string "Hee-hee… I do suppose I will.\p"
	.string "Grass-type Pokémon become especially\n"
	.string "potent and unpredictable whence\l"
	.string "Blooming becomes involved.\p"
	.string "Can you keep up?$"

PrettyPetalsScuttill_Text_RitaDefeat:
	.string "I see.\p"
	.string "Your potential… it blooms as well.$"

PrettyPetalsScuttill_Text_Rita3:
	.string "That should wrap up our trial battles,\n"
	.string "{PLAYER}.\p"
	.string "I quite enjoyed myself!$"

PrettyPetalsScuttill_Text_Nicole3:
	.string "Y'see how Blooming can add to\n"
	.string "your bag of tricks?\p"
	.string "I really recommend searching for\n"
	.string "a Grass type with Ingrain to\l"
	.string "try it out more extensively\l"
	.string "on your own!$"

PrettyPetalsScuttill_Text_Courtney3:
	.string "You were an excellent student.\n"
	.string "Grass 'mons are my favorites,\l"
	.string "you know. I hope this gave you a\l"
	.string "greater appreciation for what they can do.\p"
	.string "…So, you know Tabitha, right?\p"
	.string "Him and I used to work together in an\n"
	.string "organization that, on paper, sought to\l"
	.string "bathe the world in new land and\l"
	.string "shining sunlight.\p"
	.string "In the end, though, misguided ambition\n"
	.string "took the team down the wrong path.\p"
	.string "Since then, him and I have parted ways\n"
	.string "to help our world with\l"
	.string "our own unique methods.\p"
	.string "I do sincerely hope he is improving\n"
	.string "on himself, always.\p"
	.string "Should you find yourself in central\n"
	.string "Hoenn down the line, please consider\l"
	.string "visiting me at the farm, {PLAYER}.$"
