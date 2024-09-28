.set LOCALID_BONDING, 2
.set LOCALID_GUARD, 1

VerdanturfTransition_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VerdanturfTransition_OnLoad
	.byte 0

VerdanturfTransition_OnLoad:
	call VerdanturfTransition_EventScript_RemoveMrBonding
	call_if_ge VAR_OLD_GUYS_STATE, 20, VerdanturfTransition_EventScript_SetTempVar
	call_if_set FLAG_PAID_FOR_BADGE_06, VerdanturfTransition_EventScript_SetTempVar
	end

VerdanturfTransition_EventScript_RemoveMrBonding::
	removeobject LOCALID_BONDING
	setflag FLAG_TEMP_12
	return

VerdanturfTransition_EventScript_SetTempVar::
	setvar VAR_TEMP_4, 1
	return

VerdanturfTransition_EventScript_Roadblock::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTransition_Movement_FaceDown
	waitmovement 0
	msgbox VerdanturfTransition_Text_ExclusiveAccess, MSGBOX_DEFAULT
	goto_if_eq VAR_OLD_GUYS_STATE, 19, VerdanturfTransition_EventScript_MrBondingAppears
	showmoneybox 0, 0
	msgbox VerdanturfTransition_Text_WillYouPay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VerdanturfTransition_EventScript_CheckMoney
	msgbox VerdanturfTransition_Text_SorryToHear, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTransition_Movement_MoveRight
	waitmovement 0
	closemessage
	release
	end

VerdanturfTransition_Movement_FaceDown:
	face_down
	step_end

VerdanturfTransition_Movement_MoveRight:
	walk_right
	step_end

VerdanturfTransition_EventScript_CheckMoney::
	checkmoney 100000
	goto_if_eq VAR_RESULT, FALSE, VerdanturfTransition_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 100000
	updatemoneybox
	delay 40
	hidemoneybox
	msgbox VerdanturfTransition_Text_Delightful, MSGBOX_DEFAULT
	message VerdanturfTransition_Text_ReceivedMetroBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_PAID_FOR_BADGE_06
	setflag FLAG_BADGE06_GET
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 7
	setvar VAR_TEMP_4, 1
	msgbox VerdanturfTransition_Text_WeWillAlsoThrowIn, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	msgbox VerdanturfTransition_Text_HaveAGoodJourney, MSGBOX_DEFAULT
	closemessage
	release
	end

VerdanturfTransition_EventScript_NotEnoughMoney::
	msgbox VerdanturfTransition_Text_NotEnoughMoney, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTransition_Movement_MoveRight
	waitmovement 0
	closemessage
	release
	end

VerdanturfTransition_EventScript_MrBondingAppears::
	closemessage
	clearflag FLAG_TEMP_12
	addobject LOCALID_BONDING
	playse SE_DOOR
	waitse
	applymovement LOCALID_GUARD, VerdanturfTransition_Movement_GuardShocked
	waitmovement 0
	applymovement LOCALID_BONDING, VerdanturfTransition_Movement_MrBondingArrives
	waitmovement 0
	speakername VerdanturfTransition_Text_NameMrBonding
	msgbox VerdanturfTransition_Text_HelloGuard, MSGBOX_DEFAULT
	speakername NULL
	msgbox VerdanturfTransition_Text_IsThatAugustus, MSGBOX_DEFAULT
	speakername VerdanturfTransition_Text_NameMrBonding
	msgbox VerdanturfTransition_Text_LetInPlayer, MSGBOX_DEFAULT
	speakername NULL
	msgbox VerdanturfTransition_Text_SureThing, MSGBOX_DEFAULT
	applymovement LOCALID_GUARD, VerdanturfTransition_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTransition_Movement_FaceRight
	applymovement LOCALID_BONDING, VerdanturfTransition_Movement_MrBondingTalkToPlayer
	waitmovement 0
	speakername VerdanturfTransition_Text_NameMrBonding
	msgbox VerdanturfTransition_Text_YouveGotThis, MSGBOX_DEFAULT
	setvar VAR_OLD_GUYS_STATE, 20
	setvar VAR_TEMP_4, 1
	closemessage
	applymovement LOCALID_BONDING, VerdanturfTransition_Movement_MrBondingLeaves
	waitmovement 0
	removeobject LOCALID_BONDING
	setflag FLAG_TEMP_12
	playse SE_EXIT
	release
	end

VerdanturfTransition_Movement_GuardShocked:
	face_right
	emote_exclamation_mark
	step_end

VerdanturfTransition_Movement_MrBondingArrives:
	walk_left
	walk_left
	step_end

VerdanturfTransition_Movement_FaceUp:
	face_up
	step_end

VerdanturfTransition_Movement_FaceRight:
	face_right
	step_end

VerdanturfTransition_Movement_MrBondingTalkToPlayer:
	walk_up
	walk_up
	face_left
	step_end

VerdanturfTransition_Movement_MrBondingLeaves:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

VerdanturfTransition_EventScript_Guard::
	lock
	msgbox VerdanturfTransition_Text_WelcomeValuedCitizen, MSGBOX_AUTOCLOSE
	release
	end

VerdanturfTransition_Text_NameMrBonding:
	.string "Mr. Bonding$"

VerdanturfTransition_Text_ExclusiveAccess:
	.string "this here is exclusive son$"

VerdanturfTransition_Text_WillYouPay:
	.string "finnina pay up?$"

VerdanturfTransition_Text_SorryToHear:
	.string "looks like youre poor LOL$"

VerdanturfTransition_Text_Delightful:
	.string "delightful$"

VerdanturfTransition_Text_ReceivedMetroBadge:
	.string "{PLAYER} received the\n"
	.string "Metro Badge\l"
	.string "through the power of money!$"

VerdanturfTransition_Text_WeWillAlsoThrowIn:
	.string "will also throw in$"

VerdanturfTransition_Text_HaveAGoodJourney:
	.string "have a good one bruv$"

VerdanturfTransition_Text_NotEnoughMoney:
	.string "no money POOR POOR POOR$"

VerdanturfTransition_Text_HelloGuard:
	.string "hello guard$"

VerdanturfTransition_Text_IsThatAugustus:
	.string "holy crap lois is that augustus$"

VerdanturfTransition_Text_LetInPlayer:
	.string "let my pal in$"

VerdanturfTransition_Text_SureThing:
	.string "ok$"

VerdanturfTransition_Text_YouveGotThis:
	.string "youve got this$"

VerdanturfTransition_Text_WelcomeValuedCitizen:
	.string "welcome$"
