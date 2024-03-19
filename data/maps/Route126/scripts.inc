.set LOCALID_RAY, 5

Route126_MapScripts::
	.byte 0

Route126_EventScript_Barry::
	trainerbattle_single TRAINER_BARRY, Route126_Text_BarryIntro, Route126_Text_BarryDefeat
	msgbox Route126_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN, Route126_Text_DeanIntro, Route126_Text_DeanDefeat
	msgbox Route126_Text_DeanPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Nikki::
	trainerbattle_single TRAINER_NIKKI, Route126_Text_NikkiIntro, Route126_Text_NikkiDefeat
	msgbox Route126_Text_NikkiPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Brenda::
	trainerbattle_single TRAINER_BRENDA, Route126_Text_BrendaIntro, Route126_Text_BrendaDefeat
	msgbox Route126_Text_BrendaPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Leonardo::
	trainerbattle_single TRAINER_LEONARDO, Route126_Text_LeonardoIntro, Route126_Text_LeonardoDefeat
	msgbox Route126_Text_LeonardoPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Isobel::
	trainerbattle_single TRAINER_ISOBEL, Route126_Text_IsobelIntro, Route126_Text_IsobelDefeat
	msgbox Route126_Text_IsobelPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Sienna::
	trainerbattle_single TRAINER_SIENNA, Route126_Text_SiennaIntro, Route126_Text_SiennaDefeat
	msgbox Route126_Text_SiennaPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Pablo::
	trainerbattle_single TRAINER_PABLO_1, Route126_Text_PabloIntro, Route126_Text_PabloDefeat, Route126_EventScript_RegisterPablo
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route126_EventScript_RematchPablo
	msgbox Route126_Text_PabloPostBattle, MSGBOX_DEFAULT
	release
	end

Route126_EventScript_RegisterPablo::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route126_Text_PabloRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_PABLO_1
	release
	end

Route126_EventScript_RematchPablo::
	trainerbattle_rematch TRAINER_PABLO_1, Route126_Text_PabloRematchIntro, Route126_Text_PabloRematchDefeat
	msgbox Route126_Text_PabloPostRematch, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_LoadMeteors::
	lock
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	msgbox Route126_Text_MeteorsTest, MSGBOX_AUTOCLOSE
	release
	end

Route126_EventScript_RayEncounterNorth::
	lock
	setflag FLAG_TEMP_16
	applymovement LOCALID_RAY, Route126_Movement_RayEncounterNorth
	waitmovement 0
	goto Route126_EventScript_RayBattleStart
	release
	end

Route126_Movement_RayEncounterNorth:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	emote_question_mark
	walk_left
	walk_left
	walk_left
	step_end

Route126_EventScript_RayEncounterSouth::
	lock
	setflag FLAG_TEMP_17
	applymovement LOCALID_RAY, Route126_Movement_RayEncounterSouth
	waitmovement 0
	goto Route126_EventScript_RayBattleStart
	release
	end

Route126_Movement_RayEncounterSouth:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	emote_question_mark
	walk_left
	walk_left
	walk_left
	step_end

Route126_EventScript_RayBattleStart::
	trainerbattle_single TRAINER_P_JIMMY, Route126_Text_RayIntro, Route126_Text_RayDefeat, Route126_EventScript_RayLeaves
	release
	end

Route126_EventScript_RayLeaves::
	msgbox Route126_Text_RayLeaves, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_TEMP_16, Route126_EventScript_RayLeavesNorth
	goto_if_set FLAG_TEMP_17, Route126_EventScript_RayLeavesSouth
	release
	end

Route126_EventScript_RayLeavesNorth::
	applymovement LOCALID_RAY, Route126_Movement_RayLeavesNorth
	waitmovement 0
	setflag FLAG_HIDE_RAY
	setvar VAR_RAY_STATE, 1
	release
	end

Route126_Movement_RayLeavesNorth:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route126_EventScript_RayLeavesSouth::
	applymovement LOCALID_RAY, Route126_Movement_RayLeavesSouth
	waitmovement 0
	setflag FLAG_HIDE_RAY
	setvar VAR_RAY_STATE, 1
	release
	end

Route126_Movement_RayLeavesSouth:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route126_EventScript_SpaceCenterVarTest::
	lock
	setvar VAR_SPACE_CENTER_QUEST_STATE, 3
	msgbox Route126_Text_VarTest, MSGBOX_AUTOCLOSE
	release
	end

Route126_Text_MeteorsTest:
	.string "meteors unset$"

Route126_Text_RayIntro:
	.string "hey its me ray lets battle$"

Route126_Text_RayDefeat:
	.string "oof$"

Route126_Text_RayLeaves:
	.string "outie$"

Route126_Text_VarTest:
	.string "space center var set 3$"
