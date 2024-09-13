.set LOCALID_FLANNERY, 1
.set LOCALID_MOORE, 6
.set LOCALID_HEDORAH, 4
.set LOCALID_GHIDORAH, 3
.set LOCALID_GOJIRA, 2
.set LOCALID_GAMERA, 5

LavaridgeGymNew_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeGymNew_OnFrame
	.byte 0

LavaridgeGymNew_OnFrame:
	map_script_2 VAR_TEMP_7, 0, LavaridgeGymNew_EventScript_Interrogation
	.2byte 0

LavaridgeGymNew_EventScript_Interrogation::
	lock
	setvar VAR_TEMP_7, 1
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_SetInvis
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_SetInvis
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeGymNew_Movement_FaceUp
	waitmovement 0
	msgbox LavaridgeGymNew_Text_GojiraWelcome, MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeGymNew_Movement_PlayerWalkToTable
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_GojiraWalkToTable
	waitmovement 0
	delay 16
	msgbox LavaridgeGymNew_Text_DurinTest, MSGBOX_DEFAULT
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahGiveDurin
	waitmovement 0
	delay 16
	setmetatile 7, 6, METATILE_LavaridgeGymNew_DurinOnTable, TRUE
	special DrawWholeMapView
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahWalkBack
	msgbox LavaridgeGymNew_Text_WeInsist, MSGBOX_DEFAULT
	switch VAR_DURIN_RESISTANCE
	case 0, LavaridgeGymNew_EventScript_Eat0Resist
	case 1, LavaridgeGymNew_EventScript_Eat1Resist
	case 2, LavaridgeGymNew_EventScript_Eat2Resist
	case 3, LavaridgeGymNew_EventScript_EatMaxResist
	case 4, LavaridgeGymNew_EventScript_EatMaxResist
	closemessage
	release
	end

LavaridgeGymNew_EventScript_Eat0Resist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	pike_flashscreen
	playse SE_M_NIGHTMARE
	msgbox LavaridgeGymNew_Text_Eat0Resist, MSGBOX_DEFAULT
	poisonplayerparty
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_Eat1Resist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	pike_flashscreen
	playse SE_M_NIGHTMARE
	msgbox LavaridgeGymNew_Text_Eat1Resist, MSGBOX_DEFAULT
	poisonplayerparty
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_Eat2Resist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	pike_flashscreen
	playse SE_M_NIGHTMARE
	msgbox LavaridgeGymNew_Text_Eat2Resist, MSGBOX_DEFAULT
	poisonplayerparty
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_EatMaxResist::
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	msgbox LavaridgeGymNew_Text_EatMaxResist, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart2
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart2::
	msgbox LavaridgeGymNew_Text_DurinPride, MSGBOX_DEFAULT
	msgbox LavaridgeGymNew_Text_WhatDoForLiving, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_1, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_StudyPokemon
	case 1, LavaridgeGymNew_EventScript_TasteTestSoup
	case 2, LavaridgeGymNew_EventScript_Cop
	closemessage
	release
	end

LavaridgeGymNew_EventScript_StudyPokemon::
	setflag FLAG_TEMP_1
	msgbox LavaridgeGymNew_Text_SoYouStudyPokemon, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart3
	release
	end

LavaridgeGymNew_EventScript_TasteTestSoup::
	setflag FLAG_TEMP_2
	msgbox LavaridgeGymNew_Text_SoYouTasteTestSoup, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart3
	release
	end

LavaridgeGymNew_EventScript_Cop::
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_ShockAtCop
	msgbox LavaridgeGymNew_Text_GetOutDirtyCop, MSGBOX_DEFAULT
	warp MAP_LAVARIDGE_INT, 23, 11
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart3::
	msgbox LavaridgeGymNew_Text_SmallTalk, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_FaceRight
	msgbox LavaridgeGymNew_Text_HoldOnHere, MSGBOX_DEFAULT
	applymovement LOCALID_GHIDORAH, LavaridgeGymNew_Movement_GhidorahAccost
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahAccost
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WeWannaBattle, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_HEDORAH, LavaridgeGymNew_Text_HedorahDefeat, TRAINER_P_GHIDORAH, LavaridgeGymNew_Text_GhidorahDefeat, LavaridgeGymNew_EventScript_InterrogationPart4, NO_MUSIC
	goto LavaridgeGymNew_EventScript_InterrogationPart4
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart4::
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_SetInvis
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_SetInvis
	waitmovement 0
	applymovement LOCALID_GHIDORAH, LavaridgeGymNew_Movement_Shocked
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_Shocked
	waitmovement 0
	msgbox LavaridgeGymNew_Text_YoureToughStuff, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_StandAtAttention
	waitmovement 0
	playse SE_BANG
	msgbox LavaridgeGymNew_Text_EnoughFromYou, MSGBOX_DEFAULT
	applymovement LOCALID_GHIDORAH, LavaridgeGymNew_Movement_GhidorahLeave
	applymovement LOCALID_HEDORAH, LavaridgeGymNew_Movement_HedorahLeave
	waitmovement 0
	removeobject LOCALID_GHIDORAH
	removeobject LOCALID_HEDORAH
	applymovement LOCALID_GAMERA, LavaridgeGymNew_Movement_GameraEnter
	waitmovement 0
	msgbox LavaridgeGymNew_Text_IWillBeginSupervising, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_SitBackDown
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WillQuestionYou, MSGBOX_DEFAULT
	msgbox LavaridgeGymNew_Text_HowMuchWouldYouSpend, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_2, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_MoneyNone
	case 1, LavaridgeGymNew_EventScript_MoneyAll
	case 2, LavaridgeGymNew_EventScript_MoneyNameYourPrice
	closemessage
	release
	end

LavaridgeGymNew_EventScript_MoneyNone::
	msgbox LavaridgeGymNew_Text_MoneyNone, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion2
	release
	end

LavaridgeGymNew_EventScript_MoneyAll::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_MoneyAll, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion2
	release
	end

LavaridgeGymNew_EventScript_MoneyNameYourPrice::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_MoneyNameYourPrice, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion2
	release
	end

LavaridgeGymNew_EventScript_GameraQuestion2::
	msgbox LavaridgeGymNew_Text_HaveYouEverDropKicked, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_3, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_DropKickNo
	case 1, LavaridgeGymNew_EventScript_DropKickSeveral
	case 2, LavaridgeGymNew_EventScript_DropKickWoman
	closemessage
	release
	end

LavaridgeGymNew_EventScript_DropKickNo::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_DropKickNo, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion3
	release
	end

LavaridgeGymNew_EventScript_DropKickSeveral::
	msgbox LavaridgeGymNew_Text_DropKickSeveral, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion3
	release
	end

LavaridgeGymNew_EventScript_DropKickWoman::
	trainerbattle_single TRAINER_P_GAMERA, LavaridgeGymNew_Text_GameraDropKickIntro, LavaridgeGymNew_Text_GameraDefeat, LavaridgeGymNew_EventScript_InterrogationPart5
	goto LavaridgeGymNew_EventScript_InterrogationPart5
	release
	end

LavaridgeGymNew_EventScript_GameraQuestion3::
	msgbox LavaridgeGymNew_Text_HowMuchSmokeInhaled, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_4, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_SmokeALittle
	case 1, LavaridgeGymNew_EventScript_SmokeALottle
	case 2, LavaridgeGymNew_EventScript_SmokeCoughingFit
	closemessage
	release
	end	

LavaridgeGymNew_EventScript_SmokeALittle::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_SmokeALittle, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion4
	release
	end

LavaridgeGymNew_EventScript_SmokeALottle::
	addvar VAR_TEMP_8, 1
	msgbox LavaridgeGymNew_Text_SmokeALottle, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion4
	release
	end

LavaridgeGymNew_EventScript_SmokeCoughingFit::
	msgbox LavaridgeGymNew_Text_SmokeCoughingFit, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_GameraQuestion4
	release
	end

LavaridgeGymNew_EventScript_GameraQuestion4::
	msgbox LavaridgeGymNew_Text_ManWithFuschiaHair, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_LAVAGYM_QUESTION_5, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LavaridgeGymNew_EventScript_BreadFightHim
	case 1, LavaridgeGymNew_EventScript_BreadFightHim
	case 2, LavaridgeGymNew_EventScript_BreadFightHim
	closemessage
	release
	end

LavaridgeGymNew_EventScript_BreadFightHim::
	msgbox LavaridgeGymNew_Text_BreadFightHim, MSGBOX_DEFAULT
	goto_if_ge VAR_TEMP_8, 2, LavaridgeGymNew_EventScript_FightGameraGojira
	goto LavaridgeGymNew_EventScript_GameraGojiraRespect
	release
	end

LavaridgeGymNew_EventScript_FightGameraGojira::
	playse SE_BANG
	msgbox LavaridgeGymNew_Text_NotApproved, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_GAMERA, LavaridgeGymNew_Text_GameraDefeat, TRAINER_P_GOJIRA, LavaridgeGymNew_Text_GojiraDefeat, LavaridgeGymNew_EventScript_InterrogationPart5, NO_MUSIC
	goto LavaridgeGymNew_EventScript_InterrogationPart5
	release
	end

LavaridgeGymNew_EventScript_GameraGojiraRespect::
	msgbox LavaridgeGymNew_Text_Approved, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart5
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart5::
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_SetInvis
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_SetInvis
	waitmovement 0
	playse SE_BANG
	msgbox LavaridgeGymNew_Text_WeveHeardEnough, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_LookUpInShock
	applymovement LOCALID_GAMERA, LavaridgeGymNew_Movement_LookUpInShock
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryEnterRoom
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreEnterRoom
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WeWillTakeCareOfThis, MSGBOX_DEFAULT
	applymovement LOCALID_GOJIRA, LavaridgeGymNew_Movement_GojiraRunAway
	applymovement LOCALID_GAMERA, LavaridgeGymNew_Movement_GameraRunAway
	removeobject LOCALID_GOJIRA
	removeobject LOCALID_GAMERA
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryGoToTable
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreGoToTable
	waitmovement 0
	msgbox LavaridgeGymNew_Text_MooreFamilyHistory, MSGBOX_DEFAULT
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreGiveLava
	waitmovement 0
	delay 16
	setmetatile 7, 6, METATILE_LavaridgeGymNew_SoupOnTable, TRUE
	special DrawWholeMapView
	msgbox LavaridgeGymNew_Text_HaveSomeSearingSpicySoup, MSGBOX_DEFAULT
	goto_if_set FLAG_TEMP_2, LavaridgeGymNew_EventScript_SkipSoup
	msgbox LavaridgeGymNew_Text_CantRefuseSoup, MSGBOX_DEFAULT
	pike_flashscreen
	playse SE_M_EMBER
	burnplayerparty
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	msgbox LavaridgeGymNew_Text_ItBurns, MSGBOX_DEFAULT
	goto LavaridgeGymNew_EventScript_InterrogationPart6
	release
	end

LavaridgeGymNew_EventScript_SkipSoup::
	msgbox LavaridgeGymNew_Text_OhYouEatEnoughSoup, MSGBOX_DEFAULT
	setmetatile 7, 6, METATILE_LavaridgeGymNew_TableTop, TRUE
	special DrawWholeMapView
	goto LavaridgeGymNew_EventScript_InterrogationPart6
	release
	end

LavaridgeGymNew_EventScript_InterrogationPart6::
	applymovement LOCALID_MOORE, LavaridgeGymNew_Movement_MooreSitBackDown
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryGetUpWater
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WouldYouLikeWater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavaridgeGymNew_EventScript_HowDareYou
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FaceDown
	waitmovement 0
	msgbox LavaridgeGymNew_Text_WouldYouLikeAirCon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavaridgeGymNew_EventScript_HowDareYou
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_FlanneryBackToSeat
	waitmovement 0
	msgbox LavaridgeGymNew_Text_ItsTimeForBattle, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_FLANNERY, LavaridgeGymNew_Text_FlanneryDefeat, TRAINER_P_MR_MOORE, LavaridgeGymNew_Text_MooreDefeat, LavaridgeGymNew_EventScript_GymBattleOver, NO_MUSIC
	goto LavaridgeGymNew_EventScript_GymBattleOver
	release
	end

LavaridgeGymNew_EventScript_HowDareYou::
	applymovement LOCALID_FLANNERY, LavaridgeGymNew_Movement_HowDareYou
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, FALSE
	msgbox LavaridgeGymNew_Text_WeLikeToSweat, MSGBOX_DEFAULT
	delay 16
	setweather WEATHER_DROUGHT
	doweather
	delay 8
	msgbox LavaridgeGymNew_Text_BattleUsInSwelteringHeat, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_FLANNERY, LavaridgeGymNew_Text_FlanneryDefeat, TRAINER_P_MR_MOORE, LavaridgeGymNew_Text_MooreDefeat, LavaridgeGymNew_EventScript_GymBattleOver, NO_MUSIC
	goto LavaridgeGymNew_EventScript_GymBattleOver
	release
	end

LavaridgeGymNew_EventScript_GymBattleOver::
	speakername LavaridgeGymNew_Text_NameMoore
	msgbox LavaridgeGymNew_Text_YouDidIt, MSGBOX_DEFAULT
	setflag FLAG_BADGE05_GET
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 6
	giveitem ITEM_TM_WILL_O_WISP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_DRAGON_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername NULL
	message LavaridgeGymNew_Text_ReceivedTemperBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername LavaridgeGymNew_Text_NameFlannery
	msgbox LavaridgeGymNew_Text_ByeBye, MSGBOX_DEFAULT
	speakername NULL
	setvar VAR_TEMP_7, 1
	warp MAP_LAVARIDGE_INT, 23, 11
	waitstate
	release
	end	

LavaridgeGymNew_Movement_FlanneryBackToSeat:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

LavaridgeGymNew_Movement_HowDareYou:
	face_down
	delay_16
	delay_16
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

LavaridgeGymNew_Movement_FaceDown:
	face_down
	step_end

LavaridgeGymNew_Movement_FlanneryGetUpWater:
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

LavaridgeGymNew_Movement_MooreSitBackDown:
	walk_slow_right
	walk_slow_right
	walk_slow_up
	face_left
	step_end

LavaridgeGymNew_Movement_MooreGiveLava:
	walk_slow_down
	walk_slow_left
	walk_slow_left
	face_up
	delay_8
	step_end

LavaridgeGymNew_Movement_GameraRunAway:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	set_invisible
	step_end

LavaridgeGymNew_Movement_GojiraRunAway:
	jump_in_place_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	set_invisible
	step_end

LavaridgeGymNew_Movement_MooreGoToTable:
	walk_slow_down
	walk_slow_right
	walk_slow_right
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	face_left
	step_end

LavaridgeGymNew_Movement_FlanneryGoToTable:
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end

LavaridgeGymNew_Movement_MooreEnterRoom:
	set_visible
	walk_slow_down
	walk_slow_left
	face_down
	step_end

LavaridgeGymNew_Movement_FlanneryEnterRoom:
	set_visible
	walk_down
	walk_right
	face_down
	step_end

LavaridgeGymNew_Movement_LookUpInShock:
	emote_exclamation_mark
	face_up
	step_end

LavaridgeGymNew_Movement_SitBackDown:
	walk_right
	walk_right
	walk_up
	face_left
	step_end

LavaridgeGymNew_Movement_GameraEnter:
	walk_slow_up
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_down
	face_right
	step_end

LavaridgeGymNew_Movement_HedorahLeave:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	set_invisible
	step_end

LavaridgeGymNew_Movement_GhidorahLeave:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	set_invisible
	step_end

LavaridgeGymNew_Movement_StandAtAttention:
	walk_down
	walk_left
	walk_left
	face_up
	delay_8
	step_end

LavaridgeGymNew_Movement_Shocked:
	emote_exclamation_mark
	delay_8
	step_end

LavaridgeGymNew_Movement_HedorahWalkBack:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	face_left
	step_end

LavaridgeGymNew_Movement_HedorahGiveDurin:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	face_right
	delay_16
	delay_8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	step_end

LavaridgeGymNew_Movement_GhidorahAccost:
	delay_4
	jump_2_left
	walk_left
	walk_left
	step_end

LavaridgeGymNew_Movement_HedorahAccost:
	jump_2_left
	jump_2_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	face_right
	step_end

LavaridgeGymNew_Movement_FaceRight:
	face_right
	step_end

LavaridgeGymNew_Movement_ShockAtCop:
	emote_exclamation_mark
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end

LavaridgeGymNew_Movement_SetInvis:
	set_invisible
	step_end

LavaridgeGymNew_Movement_FaceUp:
	face_up
	step_end

LavaridgeGymNew_Movement_PlayerWalkToTable:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	face_down
	step_end

LavaridgeGymNew_Movement_GojiraWalkToTable:
	delay_16
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	walk_up
	face_left
	step_end

LavaridgeGymNew_Text_NameMoore:
	.string "Mr. Moore$"

LavaridgeGymNew_Text_NameFlannery:
	.string "Flannery$"

LavaridgeGymNew_Text_GojiraWelcome:
	.string "The pleasure is ours, challenger.\n"
	.string "Respectfully, if your wish is an\l"
	.string "audience with the Moore family,\l"
	.string "we will need to seriously\l"
	.string "pick your brain.\p"
	.string "Come, pull up a seat.$"

LavaridgeGymNew_Text_DurinTest:
	.string "I'm sure you are in the know\n"
	.string "of Lavaridge's pride and joy,\l"
	.string "mmm? The Durin Berry.\l"
	.string "A delicacy, really. In fact...\p"
	.string "Hedorah?\n"
	.string "Please get a berry for\l"
	.string "this challenger.$"

LavaridgeGymNew_Text_WeInsist:
	.string "Bottoms up.\p"
	.string "(You sense that saying\n"
	.string ""no" here is futile.)$"

LavaridgeGymNew_Text_Eat0Resist:
	.string "(It is absolutely profane.\n"
	.string "A cancer on the mouth.\l"
	.string "You instantly get food poisoning\l"
	.string "SO bad, the effects ripple\l"
	.string "through your party members.)$"

LavaridgeGymNew_Text_Eat1Resist:
	.string "(It is no better the second time.\n"
	.string "You resist the urge to vomit to\l"
	.string "save face. The putrid fruit\l"
	.string "descends punctuatingly into\l"
	.string "your stomach.)$"

LavaridgeGymNew_Text_Eat2Resist:
	.string "(Breathing deeply and steadily,\n"
	.string "you down the Durin.\l"
	.string "You regulate the bile attempting\l"
	.string "to breach and rid your body\l"
	.string "of the hideous produce.\l"
	.string "...Wasn't AS bad as before.)$"

LavaridgeGymNew_Text_EatMaxResist:
	.string "(You hastily get all of the\n"
	.string "berry consumed and swallowed\l"
	.string "before your tongue realizes\l"
	.string "what is on it.\l"
	.string "This berry, for once,\l"
	.string "did not make you sick.)$"

LavaridgeGymNew_Text_AfterEat:
	.string "I will front you some respect;\n"
	.string "that fruit is hazardous\l"
	.string "to outsiders.\p"
	.string "Muscle through it.$"

LavaridgeGymNew_Text_AfterEatResisted:
	.string "A Durin regular!\n"
	.string "Don't get challengers like\l"
	.string "that every day. Impressive.$"

LavaridgeGymNew_Text_DurinPride:
	.string "Durin Berries are the perfect\n"
	.string "emblem of our town. We find\l"
	.string "solace in things the rest\l"
	.string "of the world would deem\l"
	.string "disgusting, or worth refusing.\p"
	.string "That's weakling behavior!$"

LavaridgeGymNew_Text_WhatDoForLiving:
	.string "What do 4 livin$"

LavaridgeGymNew_Text_SoYouStudyPokemon:
	.string "so u study pokes$"

LavaridgeGymNew_Text_SoYouTasteTestSoup:
	.string "so u taste test soup$"

LavaridgeGymNew_Text_GetOutDirtyCop:
	.string "get out fucker$"

LavaridgeGymNew_Text_SmallTalk:
	.string "small talk$"

LavaridgeGymNew_Text_HoldOnHere:
	.string "hold da heck on$"

LavaridgeGymNew_Text_WeWannaBattle:
	.string "battle time$"

LavaridgeGymNew_Text_GhidorahDefeat:
	.string "Ghid defeat$"

LavaridgeGymNew_Text_HedorahDefeat:
	.string "Hed defeat$"

LavaridgeGymNew_Text_YoureToughStuff:
	.string "$"

LavaridgeGymNew_Text_EnoughFromYou:
	.string "$"

LavaridgeGymNew_Text_IWillBeginSupervising:
	.string "$"

LavaridgeGymNew_Text_WillQuestionYou:
	.string "$"

LavaridgeGymNew_Text_HowMuchWouldYouSpend:
	.string "$"

LavaridgeGymNew_Text_MoneyNone:
	.string "$"

LavaridgeGymNew_Text_MoneyAll:
	.string "$"

LavaridgeGymNew_Text_MoneyNameYourPrice:
	.string "$"

LavaridgeGymNew_Text_HaveYouEverDropKicked:
	.string "$"

LavaridgeGymNew_Text_DropKickNo:
	.string "$"

LavaridgeGymNew_Text_DropKickSeveral:
	.string "$"

LavaridgeGymNew_Text_GameraDropKickIntro:
	.string "$"

LavaridgeGymNew_Text_HowMuchSmokeInhaled:
	.string "$"

LavaridgeGymNew_Text_SmokeALittle:
	.string "$"

LavaridgeGymNew_Text_SmokeALottle:
	.string "$"

LavaridgeGymNew_Text_SmokeCoughingFit:
	.string "$"

LavaridgeGymNew_Text_ManWithFuschiaHair:
	.string "$"

LavaridgeGymNew_Text_BreadFightHim:
	.string "$"

LavaridgeGymNew_Text_NotApproved:
	.string "$"

LavaridgeGymNew_Text_GameraDefeat:
	.string "$"

LavaridgeGymNew_Text_GojiraDefeat:
	.string "$"

LavaridgeGymNew_Text_Approved:
	.string "$"

LavaridgeGymNew_Text_WeveHeardEnough:
	.string "$"

LavaridgeGymNew_Text_WeWillTakeCareOfThis:
	.string "$"

LavaridgeGymNew_Text_MooreFamilyHistory:
	.string "$"

LavaridgeGymNew_Text_HaveSomeSearingSpicySoup:
	.string "$"

LavaridgeGymNew_Text_CantRefuseSoup:
	.string "$"

LavaridgeGymNew_Text_ItBurns:
	.string "$"

LavaridgeGymNew_Text_OhYouEatEnoughSoup:
	.string "$"

LavaridgeGymNew_Text_WouldYouLikeWater:
	.string "$"

LavaridgeGymNew_Text_WouldYouLikeAirCon:
	.string "$"

LavaridgeGymNew_Text_ItsTimeForBattle:
	.string "$"

LavaridgeGymNew_Text_WeLikeToSweat:
	.string "$"

LavaridgeGymNew_Text_BattleUsInSwelteringHeat:
	.string "$"

LavaridgeGymNew_Text_FlanneryDefeat:
	.string "$"

LavaridgeGymNew_Text_MooreDefeat:
	.string "$"

LavaridgeGymNew_Text_YouDidIt:
	.string "$"

LavaridgeGymNew_Text_ReceivedTemperBadge:
	.string "{PLAYER} received the\n"
	.string "Temper Badge\l"
	.string "from Mr. Moore and Flannery.$"

LavaridgeGymNew_Text_ByeBye:
	.string "$"
