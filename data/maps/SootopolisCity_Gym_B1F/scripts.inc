.set LOCALID_JUAN, 14
.set LOCALID_SEBASTIAN, 15

SootopolisCity_Gym_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_B1F_OnFrame
	.byte 0

SootopolisCity_Gym_B1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 113, SootopolisCity_Gym_B1F_EventScript_JuanBattleStart
	.2byte 0

SootopolisCity_Gym_B1F_EventScript_JuanBattleStart::
	setvar VAR_ICE_STEP_COUNT, 0
	playse SE_PIN
	applymovement LOCALID_JUAN, SootopolisCity_Gym_B1F_Movement_JuanInterrupted
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_B1F_Movement_PlayerInterrupts
	waitmovement 0
	msgbox SootopolisCity_Gym_B1F_Text_JuanNotices, MSGBOX_AUTOCLOSE
	applymovement LOCALID_JUAN, SootopolisCity_Gym_B1F_Movement_JuanMoveIntoPlace
	applymovement LOCALID_SEBASTIAN, SootopolisCity_Gym_B1F_Movement_SebastianMoveIntoPlace
	waitmovement 0
	msgbox SootopolisCity_Gym_B1F_Text_ImSebastian, MSGBOX_AUTOCLOSE
	msgbox SootopolisCity_Gym_B1F_Text_BattleBegins, MSGBOX_DEFAULT
	playse SE_APPLAUSE
	delay 30
	delay 30
	delay 30
    trainerbattle_two_trainers TRAINER_P_JUAN, SootopolisCity_Gym_B1F_Text_JuanIntro, TRAINER_P_SEBASTIAN, SootopolisCity_Gym_B1F_Text_JuanDefeat, SootopolisCity_Gym_B1F_EventScript_JuanDefeated, NO_MUSIC
	goto SootopolisCity_Gym_B1F_EventScript_JuanDefeated
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse2
	msgbox SootopolisCity_Gym_B1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_B1F_Movement_JuanInterrupted:
	emote_exclamation_mark
	face_down
	step_end

SootopolisCity_Gym_B1F_Movement_PlayerInterrupts:
	face_up
	step_end

SootopolisCity_Gym_B1F_Movement_JuanMoveIntoPlace:
	walk_left
	face_down
	step_end

SootopolisCity_Gym_B1F_Movement_SebastianMoveIntoPlace:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

SootopolisCity_Gym_B1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_B1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_B1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	clearflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	addvar VAR_PISCES_STORY_PROGRESS, 1
	setvar VAR_BIRCH_LAB_STATE, 8
	setvar VAR_NEW_COO_STATE, 1
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	call SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	msgbox SootopolisCity_Gym_B1F_Text_GetOuttaHere, MSGBOX_DEFAULT
	warp MAP_NEW_SOOTO, 41, 16
	release
	end

SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_B1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_B1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_B1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_B1F_EventScript_DontGoOnStage::
	lock
	msgbox SootopolisCity_Gym_B1F_Text_DontGoOnStage, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_B1F_Movement_GetOff
	waitmovement 0
	release
	end

SootopolisCity_Gym_B1F_Movement_GetOff:
	walk_down
	step_end

SootopolisCity_Gym_B1F_EventScript_Arthur::
	trainerbattle_single TRAINER_P_ARTHUR, SootopolisCity_Gym_B1F_Text_ArthurIntro, SootopolisCity_Gym_B1F_Text_ArthurDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Hasparoth::
	trainerbattle_single TRAINER_P_HASPAROTH, SootopolisCity_Gym_B1F_Text_HasparothIntro, SootopolisCity_Gym_B1F_Text_HasparothDefeat
	msgbox SootopolisCity_Gym_B1F_Text_HasparothPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Lisa::
	trainerbattle_single TRAINER_P_LISA, SootopolisCity_Gym_B1F_Text_LisaIntro, SootopolisCity_Gym_B1F_Text_LisaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Miikachan::
	trainerbattle_single TRAINER_P_MIIKACHAN, SootopolisCity_Gym_B1F_Text_MiikachanIntro, SootopolisCity_Gym_B1F_Text_MiikachanDefeat
	msgbox SootopolisCity_Gym_B1F_Text_MiikachanPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Emily::
	trainerbattle_single TRAINER_P_EMILY, SootopolisCity_Gym_B1F_Text_EmilyIntro, SootopolisCity_Gym_B1F_Text_EmilyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_EmilyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_ArthurIntro:
	.string "I'll show you the sublime techniques\n"
	.string "I learned from our LEADER JUAN!$"

SootopolisCity_Gym_B1F_Text_ArthurDefeat:
	.string "Please forgive me, JUAN…$"

SootopolisCity_Gym_B1F_Text_ArthurPostBattle:
	.string "Watch what happens if you crack all\n"
	.string "the floor tiles.$"

SootopolisCity_Gym_B1F_Text_HasparothIntro:
	.string "You came all the way here, but you won't\n"
	.string "get to see JUAN.\p"
	.string "Not if you lose to me, you won't!$"

SootopolisCity_Gym_B1F_Text_HasparothDefeat:
	.string "You're strong!\n"
	.string "I was fooled by your cute looks!$"

SootopolisCity_Gym_B1F_Text_HasparothPostBattle:
	.string "You might be good enough to avoid\n"
	.string "being wiped out in one hit by JUAN.$"

SootopolisCity_Gym_B1F_Text_EmilyIntro:
	.string "The sight of JUAN conducting\n"
	.string "a battle…\p"
	.string "The very beauty of it compelled me to\n"
	.string "become a TRAINER.$"

SootopolisCity_Gym_B1F_Text_EmilyDefeat:
	.string "You battled with more beauty than\n"
	.string "I could muster…$"

SootopolisCity_Gym_B1F_Text_EmilyPostBattle:
	.string "The grace you bring to battle is\n"
	.string "fabulous.\p"
	.string "Oh… I'm so fortunate to have found\n"
	.string "POKéMON.$"

SootopolisCity_Gym_B1F_Text_LisaIntro:
	.string "A graceful glide across the ice while\n"
	.string "crossing no lines…\p"
	.string "A TRAINER putting on that performance\n"
	.string "would be elegantly beautiful!$"

SootopolisCity_Gym_B1F_Text_LisaDefeat:
	.string "Well, excuse me?!$"

SootopolisCity_Gym_B1F_Text_LisaPostBattle:
	.string "This is really obvious, but how strong\n"
	.string "you are as a TRAINER has nothing to do\l"
	.string "with how young or old you are.$"

SootopolisCity_Gym_B1F_Text_MiikachanIntro:
	.string "When I'm with my POKéMON, the time\n"
	.string "flies by before you can say, “Oops!”$"

SootopolisCity_Gym_B1F_Text_MiikachanDefeat:
	.string "Oops!$"

SootopolisCity_Gym_B1F_Text_MiikachanPostBattle:
	.string "I wish I could forget about lost causes\n"
	.string "before I can manage an “Oops!”$"

SootopolisCity_Gym_B1F_Text_JuanIntro:
	.string "wtf !! (two)$"

SootopolisCity_Gym_B1F_Text_JuanDefeat:
	.string "sebeta male$"

SootopolisCity_Gym_B1F_Text_ReceivedRainBadge:
	.string "{PLAYER} received the RAIN BADGE\n"
	.string "from JUAN.$"

SootopolisCity_Gym_B1F_Text_ExplainRainBadgeTakeThis:
	.string "Having the RAIN BADGE shall assure you\n"
	.string "the full obedience of all your POKéMON\l"
	.string "to your every command.\p"
	.string "The RAIN BADGE also allows the use\n"
	.string "of the HM move WATERFALL to scale\l"
	.string "walls of cascading water.\p"
	.string "And, so that you never forget the\n"
	.string "battle we shared, take this…$"

SootopolisCity_Gym_B1F_Text_ExplainWaterPulse:
	.string "The TECHNICAL MACHINE I handed you\n"
	.string "contains WATER PULSE.\p"
	.string "In use, it will occasionally confuse\n"
	.string "the target with ultrasonic waves.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_B1F_Text_RegisteredJuan:
	.string "Registered GYM LEADER JUAN\n"
	.string "in the POKéNAV.$"

SootopolisCity_Gym_B1F_Text_JuanPostBattle:
	.string "The TRAINERS who have gathered all\n"
	.string "the GYM BADGES of HOENN should make\l"
	.string "way to the ultimate destination.\p"
	.string "The POKéMON LEAGUE.\p"
	.string "Travel to the easternmost reaches\n"
	.string "of HOENN, to the island EVER GRANDE.\p"
	.string "There, you shall find the POKéMON\n"
	.string "LEAGUE.$"

SootopolisCity_Gym_B1F_Text_JuanNotices:
	.string "wtf !!\p"
	.string "sebastian help!$"

SootopolisCity_Gym_B1F_Text_ImSebastian:
	.string "im sebastian btw$"

SootopolisCity_Gym_B1F_Text_BattleBegins:
	.string "time to battle bruv$"

SootopolisCity_Gym_B1F_Text_GetOuttaHere:
	.string "now please scram thx$"

SootopolisCity_Gym_B1F_Text_DontGoOnStage:
	.string "dont go up there$"
