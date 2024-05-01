.set LOCALID_BREAD, 1

Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition:
	call_if_gt VAR_BREADWINNER_STATE, 1, Route123_EventScript_SetTempFlags
	end

Route123_EventScript_SetTempFlags::
	setflag FLAG_TEMP_11
	removeobject LOCALID_BREAD
	return

Route123_EventScript_BreadPos1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route123_Movement_PlayerMoveIntoPos
	waitmovement 0
	goto Route123_EventScript_BreadwinnerEncounter
	release
	end

Route123_Movement_PlayerMoveIntoPos:
	walk_right
	face_up
	step_end

Route123_EventScript_BreadwinnerEncounter::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route123_Movement_PlayerWalkUpStairs
	applymovement LOCALID_BREAD, Route123_Movement_BreadEnc
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_BREAD, Route123_Movement_BreadBackUp
	waitmovement 0
	trainerbattle_single TRAINER_P_PANDOU_2, Route123_Text_BreadwinnerIntro, Route123_Text_BreadwinnerDefeat, Route123_EventScript_BreadRun
	release
	end

Route123_Movement_PlayerWalkUpStairs:
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route123_Movement_BreadEnc:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route123_Movement_BreadBackUp:
	walk_right
	face_left
	step_end

Route123_EventScript_BreadRun::
	setvar VAR_BREADWINNER_STATE, 2
	msgbox Route123_Text_BreadwinnerRunAway, MSGBOX_DEFAULT
	closemessage
	playse SE_FLEE
	applymovement LOCALID_BREAD, Route123_Movement_BreadEscape
	waitmovement 0
	setflag FLAG_TEMP_11
	removeobject LOCALID_BREAD
	release
	end

Route123_Movement_BreadEscape:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route123_EventScript_Rami::
    trainerbattle_single TRAINER_P_RAMI, Route123_Text_RamiIntro, Route123_Text_RamiDefeated
    msgbox Route123_Text_RamiPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Tsunami::
    trainerbattle_single TRAINER_P_TSUNAMI, Route123_Text_TsunamiIntro, Route123_Text_TsunamiDefeated
    msgbox Route123_Text_TsunamiPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Jinxie::
    trainerbattle_single TRAINER_P_JINXIE, Route123_Text_JinxieIntro, Route123_Text_JinxieDefeated
    msgbox Route123_Text_JinxiePostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Carolina::
    trainerbattle_single TRAINER_P_CAROLINA, Route123_Text_CarolinaIntro, Route123_Text_CarolinaDefeated
    msgbox Route123_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Betty::
    trainerbattle_single TRAINER_P_BETTY, Route123_Text_BettyIntro, Route123_Text_BettyDefeated
    msgbox Route123_Text_BettyPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Hazakura::
    trainerbattle_single TRAINER_P_HAZAKURA, Route123_Text_HazakuraIntro, Route123_Text_HazakuraDefeated
    msgbox Route123_Text_HazakuraPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Mia::
    trainerbattle_single TRAINER_P_MIA, Route123_Text_MiaIntro, Route123_Text_MiaDefeated
    msgbox Route123_Text_MiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Maya::
    trainerbattle_single TRAINER_P_MAYA, Route123_Text_MayaIntro, Route123_Text_MayaDefeated
    msgbox Route123_Text_MayaPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Kumori::
    trainerbattle_single TRAINER_P_KUMORI, Route123_Text_KumoriIntro, Route123_Text_KumoriDefeated
    msgbox Route123_Text_KumoriPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Hoth::
    trainerbattle_single TRAINER_P_HOTH, Route123_Text_HothIntro, Route123_Text_HothDefeated
    msgbox Route123_Text_HothPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_Text_RamiIntro:
	.string "intro$"

Route123_Text_RamiDefeated:
	.string "defeat$"

Route123_Text_RamiPostBattle:
	.string "post$"

Route123_Text_TsunamiIntro:
	.string "intro$"

Route123_Text_TsunamiDefeated:
	.string "defeat$"

Route123_Text_TsunamiPostBattle:
	.string "post$"

Route123_Text_JinxieIntro:
	.string "intro$"

Route123_Text_JinxieDefeated:
	.string "defeat$"

Route123_Text_JinxiePostBattle:
	.string "post$"

Route123_Text_CarolinaIntro:
	.string "intro$"

Route123_Text_CarolinaDefeated:
	.string "defeat$"

Route123_Text_CarolinaPostBattle:
	.string "post$"

Route123_Text_BettyIntro:
	.string "intro$"

Route123_Text_BettyDefeated:
	.string "defeat$"

Route123_Text_BettyPostBattle:
	.string "post$"

Route123_Text_HazakuraIntro:
	.string "intro$"

Route123_Text_HazakuraDefeated:
	.string "defeat$"

Route123_Text_HazakuraPostBattle:
	.string "post$"

Route123_Text_MiaIntro:
	.string "intro$"

Route123_Text_MiaDefeated:
	.string "defeat$"

Route123_Text_MiaPostBattle:
	.string "post$"

Route123_Text_MayaIntro:
	.string "intro$"

Route123_Text_MayaDefeated:
	.string "defeat$"

Route123_Text_MayaPostBattle:
	.string "post$"

Route123_Text_KumoriIntro:
	.string "intro$"

Route123_Text_KumoriDefeated:
	.string "defeat$"

Route123_Text_KumoriPostBattle:
	.string "post$"

Route123_Text_HothIntro:
	.string "intro$"

Route123_Text_HothDefeated:
	.string "defeat$"

Route123_Text_HothPostBattle:
	.string "post$"

Route123_Text_BreadwinnerIntro:
	.string "bread intro$"

Route123_Text_BreadwinnerDefeat:
	.string "bread defeat$"

Route123_Text_BreadwinnerRunAway:
	.string "runnin outta here$"
