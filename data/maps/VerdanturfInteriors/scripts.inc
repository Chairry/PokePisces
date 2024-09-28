.set LOCALID_P_MAN, 3
.set LOCALID_SCOTT, 2
.set LOCALID_WATTSON, 1

VerdanturfInteriors_MapScripts::
	.byte 0

VerdanturfInteriors_EventScript_MeetingLeftTrigger::
	lock
	goto_if_set FLAG_BADGE06_GET, VerdanturfInteriors_EventScript_TurnBack
	goto_if_eq VAR_OLD_GUYS_STATE, 20, VerdanturfInteriors_EventScript_MoveUpLeft
	goto VerdanturfInteriors_EventScript_TurnBack
	release
	end

VerdanturfInteriors_EventScript_MeetingRightTrigger::
	lock
	goto_if_set FLAG_BADGE06_GET, VerdanturfInteriors_EventScript_TurnBack
	goto_if_eq VAR_OLD_GUYS_STATE, 20, VerdanturfInteriors_EventScript_MoveUpRight
	goto VerdanturfInteriors_EventScript_TurnBack
	release
	end

VerdanturfInteriors_EventScript_TurnBack::
	msgbox VerdanturfInteriors_Text_TurnBack, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfInteriors_Movement_WalkDown
	waitmovement 0
	delay 8
	closemessage
	release
	end

VerdanturfInteriors_Movement_WalkDown:
	walk_down
	step_end

VerdanturfInteriors_EventScript_MoveUpLeft::
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfInteriors_Movement_MoveUpLeft
	waitmovement 0
	goto VerdanturfInteriors_EventScript_MeetWattsonAndScott
	release
	end

VerdanturfInteriors_Movement_MoveUpLeft:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfInteriors_EventScript_MoveUpRight::
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfInteriors_Movement_MoveUpRight
	waitmovement 0
	goto VerdanturfInteriors_EventScript_MeetWattsonAndScott
	release
	end

VerdanturfInteriors_Movement_MoveUpRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfInteriors_EventScript_MeetWattsonAndScott::
	delay 8
	applymovement LOCALID_P_MAN, VerdanturfInteriors_Movement_Shocked
	waitmovement 0
	msgbox VerdanturfInteriors_Text_WhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_P_MAN, VerdanturfInteriors_Movement_ManWalkIntoRoom
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfInteriors_Movement_PlayerWalkIntoRoom
	waitmovement 0
	delay 16
	speakername VerdanturfInteriors_Text_NameScott
	msgbox VerdanturfInteriors_Text_ANewFace, MSGBOX_DEFAULT
	speakername VerdanturfInteriors_Text_NameWattson
	msgbox VerdanturfInteriors_Text_JustGiveTheBadge, MSGBOX_DEFAULT
	speakername VerdanturfInteriors_Text_NameScott
	msgbox VerdanturfInteriors_Text_HereYouGo, MSGBOX_DEFAULT
	message VerdanturfInteriors_Text_ReceivedMetroBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE06_GET
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 7
	speakername VerdanturfInteriors_Text_NameWattson
	msgbox VerdanturfInteriors_Text_YouMayNowLeave, MSGBOX_DEFAULT
	speakername NULL
	msgbox VerdanturfInteriors_Text_StandYourGround, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VerdanturfInteriors_EventScript_BattleWattsonAndScott
	msgbox VerdanturfInteriors_Text_LeaveAwkwardly, MSGBOX_DEFAULT
	closemessage
	warp MAP_VERDANTURF_NEW, 32, 9
	waitstate
	release
	end

VerdanturfInteriors_Movement_Shocked:
	face_down
	delay_4
	emote_exclamation_mark
	step_end

VerdanturfInteriors_Movement_ManWalkIntoRoom:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	face_left
	step_end

VerdanturfInteriors_Movement_PlayerWalkIntoRoom:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	face_right
	step_end

VerdanturfInteriors_EventScript_BattleWattsonAndScott::
	speakername VerdanturfInteriors_Text_NameWattson
	msgbox VerdanturfInteriors_Text_HowArrogant, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_WATTSON, VerdanturfInteriors_Text_WattsonDefeat, TRAINER_P_SCOTT, VerdanturfInteriors_Text_ScottDefeat, VerdanturfInteriors_EventScript_LeadersDefeated, NO_MUSIC
	goto VerdanturfInteriors_EventScript_LeadersDefeated
	release
	end

VerdanturfInteriors_EventScript_LeadersDefeated::
	speakername VerdanturfInteriors_Text_NameWattson
	msgbox VerdanturfInteriors_Text_DidThatSuffice, MSGBOX_DEFAULT
	speakername VerdanturfInteriors_Text_NameScott
	msgbox VerdanturfInteriors_Text_IKindaHadFun, MSGBOX_DEFAULT
	speakername VerdanturfInteriors_Text_NameWattson
	msgbox VerdanturfInteriors_Text_IMustStressThatYouLeave, MSGBOX_DEFAULT
	closemessage
	warp MAP_VERDANTURF_NEW, 32, 9
	waitstate
	release
	end

VerdanturfInteriors_Text_NameScott:
	.string "Scott$"

VerdanturfInteriors_Text_NameWattson:
	.string "Wattson$"

VerdanturfInteriors_Text_TurnBack:
	.string "turning back$"

VerdanturfInteriors_Text_WhoAreYou:
	.string "who are you$"

VerdanturfInteriors_Text_ANewFace:
	.string "oh a new face$"

VerdanturfInteriors_Text_JustGiveTheBadge:
	.string "just give the badge$"

VerdanturfInteriors_Text_HereYouGo:
	.string "here y'are$"

VerdanturfInteriors_Text_ReceivedMetroBadge:
	.string "{PLAYER} received the\n"
	.string "Metro Badge\l"
	.string "from Scott and Wattson.\p"
	.string "It felt a little hollow.$"

VerdanturfInteriors_Text_YouMayNowLeave:
	.string "you may now leave$"

VerdanturfInteriors_Text_StandYourGround:
	.string "stand your ground?$"

VerdanturfInteriors_Text_LeaveAwkwardly:
	.string "haha loser$"

VerdanturfInteriors_Text_HowArrogant:
	.string "how arrogant$"

VerdanturfInteriors_Text_WattsonDefeat:
	.string "w defeat$"

VerdanturfInteriors_Text_ScottDefeat:
	.string "s defeat$"

VerdanturfInteriors_Text_DidThatSuffice:
	.string "did that suffice dickhead$"

VerdanturfInteriors_Text_IKindaHadFun:
	.string "idk i had fun$"

VerdanturfInteriors_Text_IMustStressThatYouLeave:
	.string "die$"
