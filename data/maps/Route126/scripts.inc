.set LOCALID_RAY, 5
.set LOCALID_PARRYER, 21

Route126_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route126_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, Route126_OnTransition
	.byte 0

Route126_OnTransition:
	goto_if_lt VAR_SPACE_CENTER_QUEST_STATE, 3, Route126_EventScript_HideMeteors
	end

Route126_EventScript_HideMeteors::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	end

Route126_OnFrame:
	map_script_2 VAR_SPACE_CENTER_QUEST_STATE, 69, Route126_EventScript_StartInvasion
	.2byte 0

Route126_EventScript_StartInvasion::
	lock
	setvar VAR_SPACE_CENTER_QUEST_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, Route126_Movement_WalkToRocket
	waitmovement 0
	speakername Route126_Text_NameLovelace
	msgbox Route126_Text_TheyreInvading, MSGBOX_DEFAULT
	setwildbattle SPECIES_UHEFOE, 18
	settotemboost B_POSITION_OPPONENT_LEFT, 0, 2, 0, 0, 2
	playmoncry SPECIES_BEHEEYEM, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox Route126_Text_UhefoeAppears, MSGBOX_DEFAULT
	speakername NULL
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
	speakername Route126_Text_NameLovelace
	msgbox Route126_Text_YouDidIt, MSGBOX_DEFAULT
	speakername NULL
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
	trainerbattle_single TRAINER_P_MISAKI, Route126_Text_BarryIntro, Route126_Text_BarryDefeat
	msgbox Route126_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
	end

Route126_EventScript_Dean::
	trainerbattle_single TRAINER_P_YUINA, Route126_Text_DeanIntro, Route126_Text_DeanDefeat
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
	speakername Route126_Text_NameRay
	msgbox Route126_Text_RayLeaves, MSGBOX_DEFAULT
	closemessage
	speakername NULL
	goto_if_set FLAG_TEMP_16, Route126_EventScript_RayLeavesNorth
	goto_if_set FLAG_TEMP_17, Route126_EventScript_RayLeavesSouth
	release
	end

Route126_EventScript_RayLeavesNorth::
	applymovement LOCALID_RAY, Route126_Movement_RayLeavesNorth
	waitmovement 0
	removeobject LOCALID_RAY
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
	removeobject LOCALID_RAY
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

Route126_EventScript_ParryRocketScientist::
	lock
	faceplayer
	checkitem ITEM_TM_DETECT
	goto_if_eq VAR_RESULT, TRUE, Route126_EventScript_GaveDetectRS
	goto_if_eq VAR_TEMP_5, 3, Route126_EventScript_HitTheRocket
	msgbox Route126_Text_WorkingOnTheRocket, MSGBOX_AUTOCLOSE
	release
	end

Route126_EventScript_GaveDetectRS::
	msgbox Route126_Text_GaveDetectRS, MSGBOX_AUTOCLOSE
    release
    end

Route126_EventScript_HitTheRocket::
	msgbox Route126_Text_SayNoMore, MSGBOX_DEFAULT
	applymovement LOCALID_PARRYER, Route126_Movement_BBWalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Route126_Movement_PlayerWatch
	waitmovement 0
	msgbox Route126_Text_ReadyToParry, MSGBOX_DEFAULT
	playse SE_M_MEGA_KICK
	waitse
	applymovement LOCALID_PARRYER, Route126_Movement_BBParry
	waitmovement 0
	playse SE_M_MEGA_KICK2
	waitse
	applymovement LOCALID_PARRYER, Route126_Movement_BBVictorious
	msgbox Route126_Text_Victorious, MSGBOX_DEFAULT
	giveitem ITEM_TM_DETECT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	applymovement LOCALID_PARRYER, Route126_Movement_BBWalkAway
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route126_Movement_PlayerLookBack
	waitmovement 0
	msgbox Route126_Text_ThatWasEntertaining, MSGBOX_AUTOCLOSE
	release
	end

Route126_Movement_BBWalkUp:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route126_Movement_PlayerWatch:
	face_left
	step_end

Route126_Movement_BBParry:
	face_up
	delay_16
	delay_16
	delay_16
	jump_in_place_up
	walk_in_place_fast_up
	delay_8
	step_end

Route126_Movement_BBVictorious:
	face_right
	walk_in_place_right
	step_end

Route126_Movement_BBWalkAway:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

Route126_Movement_PlayerLookBack:
	face_right
	step_end

Route126_EventScript_ParryBlackBelt::
	lock
	faceplayer
	checkitem ITEM_TM_DETECT
	goto_if_eq VAR_RESULT, TRUE, Route126_EventScript_GaveDetectBB
	setvar VAR_TEMP_5, 3
	msgbox Route126_Text_IWantToParry, MSGBOX_AUTOCLOSE
	release
	end

Route126_EventScript_GaveDetectBB::
	msgbox Route126_Text_GaveDetectBB, MSGBOX_AUTOCLOSE
    release
    end

Route126_EventScript_SwiftGirl::
    lock
	faceplayer
	checkitem ITEM_TM_SWIFT
	goto_if_eq VAR_RESULT, TRUE, Route126_EventScript_GaveSwift
	msgbox Route126_Text_ShootingStars, MSGBOX_DEFAULT
	giveitem ITEM_TM_SWIFT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

Route126_EventScript_GaveSwift::
    msgbox Route126_Text_GaveSwift, MSGBOX_AUTOCLOSE
    release
    end

Route126_EventScript_OzoneRoadblocker1::
	msgbox Route126_Text_OzoneRoadblocker1, MSGBOX_NPC
	end

Route126_EventScript_OzoneRoadblocker2::
	msgbox Route126_Text_OzoneRoadblocker2, MSGBOX_NPC
	end

Route126_EventScript_OzoneRoadblocker3::
	msgbox Route126_Text_OzoneRoadblocker3, MSGBOX_NPC
	end

Route126_Text_OzoneRoadblocker1:
	.string "Apologies, but I'm afraid that Cosmoss\n"
	.string "Bridge has a temporary closure.\p"
	.string "A metoerite impacted the bridge this\n"
	.string "morning and damaged its structural\l"
	.string "integrity.\p"
	.string "It shouldn't take much longer to be\n"
	.string "cleared up.$"

Route126_Text_OzoneRoadblocker2:
	.string "It's not every day that we get to\n"
	.string "crack open a fresh metorite\l"
	.string "and study it!\l"
	.string "Exciting developments!$"

Route126_Text_OzoneRoadblocker3:
	.string "Team Ozone and the Cosmoss Space\n"
	.string "Center work together regularly.\l"
	.string "Took us no time at all to come in\l"
	.string "with the assist!$"

Route126_Text_ShootingStars:
	.string "Ah, the beauty of shooting stars...\p"
	.string "You know, this bridge is a hotspot\n"
	.string "for viewing them. How romantic!\p"
	.string "Teach your Pokémon this move;\n"
	.string "that way, you can make your own\l"
	.string "personal meteor shower!$"

Route126_Text_GaveSwift:
	.string "I don't believe on making\n"
	.string "more than one wish on a shooting\l"
	.string "star. I'll save it for just\l"
	.string "the right moment in my life!$"

Route126_Text_WorkingOnTheRocket:
	.string "Very much hoping that this\n"
	.string "rocket's structural integrity\l"
	.string "is sound enough for launch...$"

Route126_Text_GaveDetectRS:
	.string "Thanks to that parry, I KNOW\n"
	.string "the rocket is sturdy as\l"
	.string "all get out!$"

Route126_Text_SayNoMore:
	.string "...What's that you're telling me?\n"
	.string "C-Can the rocket... fight?\p"
	.string "Surely you're joking. This is\n"
	.string "a state of the art vessel made of\l"
	.string "many tonnes of steel.\p"
	.string "Nothing could dent thi-\p"
	.string "SAY NO MORE!$"

Route126_Text_ReadyToParry:
	.string "Rocket-kun... my new arch-nemesis...!\n"
	.string "I have what it takes to match your\l"
	.string "strikes...! You will NOT win!\p"
	.string "(He is winding up...)$"

Route126_Text_Victorious:
	.string "(Blue energy is flaring around\n"
	.string "the black belt...)\p"
	.string "Victorious once again!\n"
	.string "Seems you were all talk, Rocket-kun...\p"
	.string "Allow me to pass some of my skills\n"
	.string "to your Pokémon... in the form of a TM.$"

Route126_Text_ThatWasEntertaining:
	.string "???? Ok???\p"
	.string "Didn't seem like he really did\n"
	.string "anything???$"

Route126_Text_IWantToParry:
	.string "Hai. I have trained for eons in\n"
	.string "the art... of parrying.\p"
	.string "I have not been challenged in\n"
	.string "quite some time.\p"
	.string "Could you possibly find me...\n"
	.string "a worthy opponent?$"

Route126_Text_GaveDetectBB:
	.string "The next opponent awaits me...$"

Route126_Text_MeteorsTest:
	.string "meteors unset$"

Route126_Text_NameRay:
	.string "Ray$"

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

Route126_Text_NameLovelace:
	.string "Cpt. Lovelace$"

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
