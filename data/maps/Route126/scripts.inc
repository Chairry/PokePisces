.set LOCALID_RAY, 5

Route126_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route126_OnFrame
	.byte 0

Route126_OnFrame:
	map_script_2 VAR_SPACE_CENTER_QUEST_STATE, 69, Route126_EventScript_StartInvasion

Route126_EventScript_StartInvasion::
	lock
	setvar VAR_SPACE_CENTER_QUEST_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, Route126_Movement_WalkToRocket
	waitmovement 0
	msgbox Route126_Text_TheyreInvading, MSGBOX_DEFAULT
	setwildbattle SPECIES_UHEFOE, 20
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 0, 2
	playmoncry SPECIES_BEHEEYEM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox Route126_Text_UhefoeAppears, MSGBOX_DEFAULT
	dowildbattle
	goto Route126_EventScript_YouDidIt
	release
	end

Route126_Movement_WalkToRocket:
	walk_up
	walk_up
	walk_up
	step_end

Route126_EventScript_YouDidIt::
	msgbox Route126_Text_YouDidIt, MSGBOX_DEFAULT
	giveitem ITEM_GRAVITY_CORE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_SPACE_CENTER_QUEST_STATE, 50
	warp MAP_COSMOSS_SPACE_CENTER, 10, 28
	waitstate
	release
	end

Route126_EventScript_Lovelace::
	msgbox Route126_Text_Lovelace, MSGBOX_NPC
	end

Route126_EventScript_Stella::
    trainerbattle_single TRAINER_P_STELLA, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

Route126_EventScript_Isaac::
    trainerbattle_single TRAINER_P_ISAAC, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

Route126_EventScript_Rise::
    trainerbattle_single TRAINER_P_RISE, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

Route126_EventScript_Yu::
    trainerbattle_single TRAINER_P_YU, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

Route126_EventScript_Geiger::
    trainerbattle_single TRAINER_P_GEIGER, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

Route126_EventScript_York::
    trainerbattle_single TRAINER_P_YORK, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

Route126_EventScript_Rika::
    trainerbattle_single TRAINER_P_RIKA, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

Route126_EventScript_Pete::
    trainerbattle_single TRAINER_P_PETE, Route126_Text_GugumbirIntro, Route126_Text_GugumbirDefeated
    msgbox Route126_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

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
	trainerbattle_single TRAINER_P_RAY_1, Route126_Text_RayIntro, Route126_Text_RayDefeat, Route126_EventScript_RayLeaves
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
	.string "Woah, woah, woah, slow down\n"
	.string "there, buster!\p"
	.string "This bridge is supposed to be off\n"
	.string "limits to non-Ozone-workers while we\l"
	.string "conduct VERY valuable research.\l"
	.string "I have to ask you to leave!\p"
	.string "…The rest of my teammates left already?\p"
	.string "Hah! Nice attempt. Trying to pull a\n"
	.string "fast one… on me, THE Ray\l"
	.string "(of Team Ozone)!\p"
	.string "Hm… wait a tick.\p"
	.string "I think I recognize you!\p"
	.string "Yeah, that's right.\n"
	.string "You're that (supposed) hotshot\l"
	.string "(unconfirmed) from Littleroot!\p"
	.string "Now I REALLY feel a desire to knock\n"
	.string "you down a peg!\p"
	.string "(Ray makes a “come at me” gesture.)\p"
	.string "Let's tussle!!$"

Route126_Text_RayDefeat:
	.string "Are you KIDDING me!?$"

Route126_Text_RayLeaves:
	.string "Huff… that was a straight up fluke.\p"
	.string "You cheated, I let you win, I'm feeling\n"
	.string "under the weather, et cetera.\p"
	.string "In my post-loss-clarity state, I am\n"
	.string "now realzing that my team HAS left.\p"
	.string "Mm.\p"
	.string "Likely your fault.\p"
	.string "As we established, you are THE dirty\n"
	.string "cheat (worst of the worst) who\l"
	.string "smells (bad)!\p"
	.string "This won't be the last you see of Ray.\p"
	.string "I'll make sure of THAT!$"

Route126_Text_VarTest:
	.string "space center var set 3$"

Route126_Text_Lovelace:
	.string "All systems nominal here.\n"
	.string "Itching to embark whenever it's time.$"

Route126_Text_TheyreInvading:
	.string "…Hmm?\p"
	.string "Eiffel's reporting some\n"
	.string "kind of problem? Nonsense.\p"
	.string "His lazy bum is probably using this as\n"
	.string "an excuse to get sent home early.$"

Route126_Text_UhefoeAppears:
	.string "(You hear a Pokémon's cry.)\p"
	.string "Crud, watch out…\n"
	.string "looks like something wants to give us\l"
	.string "a warm welcome…!$"

Route126_Text_YouDidIt:
	.string "Thanks for taking care of that thing.\p"
	.string "Here, take this;\n"
	.string "the Pokémon was holding it.\p"
	.string "Think of it as a… trophy.$"

Route126_Text_GugumbirIntro:
	.string "intro$"

Route126_Text_GugumbirDefeated:
	.string "defeat$"

Route126_Text_GugumbirPostBattle:
	.string "post$"

Route126_Text_GugumbirNeedTwoMons:
	.string "need 2 dood$"
