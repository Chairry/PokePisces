.set LOCALID_WORKER1, 15
.set LOCALID_WORKER2, 16
.set LOCALID_WORKER3, 17
.set LOCALID_TABITHA, 18
.set LOCALID_MATT, 19

OzoneLilycoveHQ_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneLilycoveHQ_OnFrame
	.byte 0

OzoneLilycoveHQ_OnFrame:
	map_script_2 VAR_OZONE_ADMINS_STATE, 0, OzoneLilycoveHQ_EventScript_NoBusinessHere
	map_script_2 VAR_OZONE_ADMINS_STATE, 1, OzoneLilycoveHQ_EventScript_SomeBusinessHere
	.2byte 0

OzoneLilycoveHQ_EventScript_NoBusinessHere::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_ToTheCounter
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_NoBusinessHere, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_BackOutside
	warp MAP_LILYCOVE_CITY, 64, 15
	waitstate
	release
	end

OzoneLilycoveHQ_Movement_ToTheCounter:
	walk_up
	walk_up
	step_end

OzoneLilycoveHQ_Movement_BackOutside:
	walk_down
	walk_down
	step_end

OzoneLilycoveHQ_EventScript_SomeBusinessHere::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_ToTheCounter
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_SomeBusinessHere, MSGBOX_AUTOCLOSE
	setvar VAR_OZONE_ADMINS_STATE, 2
	release
	end

OzoneLilycoveHQ_EventScript_Landon::
    trainerbattle_single TRAINER_P_LANDON, OzoneLilycoveHQ_Text_LandonIntro, OzoneLilycoveHQ_Text_LandonDefeated
    msgbox OzoneLilycoveHQ_Text_LandonPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_Terra::
    trainerbattle_single TRAINER_P_TERRA, OzoneLilycoveHQ_Text_TerraIntro, OzoneLilycoveHQ_Text_TerraDefeated
    msgbox OzoneLilycoveHQ_Text_TerraPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_Sean::
    trainerbattle_single TRAINER_P_SEAN, OzoneLilycoveHQ_Text_SeanIntro, OzoneLilycoveHQ_Text_SeanDefeated
    msgbox OzoneLilycoveHQ_Text_SeanPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_Marina::
    trainerbattle_single TRAINER_P_MARINA, OzoneLilycoveHQ_Text_MarinaIntro, OzoneLilycoveHQ_Text_MarinaDefeated
    msgbox OzoneLilycoveHQ_Text_MarinaPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_UmbrellaResearcher::
	lock
	faceplayer
	goto_if_eq VAR_PARASOL_QUEST_STATE, 0, OzoneLilycoveHQ_EventScript_HelpWithBrellas
	goto_if_eq VAR_PARASOL_QUEST_STATE, 1, OzoneLilycoveHQ_EventScript_GoGetBrellas
	goto_if_eq VAR_PARASOL_QUEST_STATE, 2, OzoneLilycoveHQ_EventScript_HaveBrella
	goto_if_gt VAR_PARASOL_QUEST_STATE, 2, OzoneLilycoveHQ_EventScript_NoMoreBrella
	release
	end

OzoneLilycoveHQ_EventScript_HelpWithBrellas::
	setvar VAR_PARASOL_QUEST_STATE, 1
	msgbox OzoneLilycoveHQ_Text_BrellaHelp, MSGBOX_AUTOCLOSE
	release
	end

OzoneLilycoveHQ_EventScript_GoGetBrellas::
	msgbox OzoneLilycoveHQ_Text_BrellaGoGettem, MSGBOX_AUTOCLOSE
	release
	end

OzoneLilycoveHQ_EventScript_HaveBrella::
	msgbox OzoneLilycoveHQ_Text_BrellaThanks, MSGBOX_DEFAULT
	giveitem ITEM_UTILITY_UMBRELLA
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_PARASOL_QUEST_STATE, 3
	msgbox OzoneLilycoveHQ_Text_BrellaAbout, MSGBOX_AUTOCLOSE
	release
	end

OzoneLilycoveHQ_EventScript_NoMoreBrella::
	msgbox OzoneLilycoveHQ_Text_BrellaNoMore, MSGBOX_AUTOCLOSE
	release
	end

OzoneLilycoveHQ_EventScript_BoardroomMeeting::
	lock
	msgbox OzoneLilycoveHQ_Text_Boardroom1, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_PlayerHide
	waitmovement 0
	applymovement LOCALID_WORKER2, OzoneLilycoveHQ_Movement_Worker2Talking
	msgbox OzoneLilycoveHQ_Text_Boardroom2, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt1, MSGBOX_DEFAULT
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha1, MSGBOX_DEFAULT
	applymovement LOCALID_WORKER1, OzoneLilycoveHQ_Movement_Worker1Talking
	msgbox OzoneLilycoveHQ_Text_Boardroom3, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt2, MSGBOX_DEFAULT
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha2, MSGBOX_DEFAULT
	applymovement LOCALID_WORKER3, OzoneLilycoveHQ_Movement_Worker3Talking
	msgbox OzoneLilycoveHQ_Text_Boardroom4, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_PlayerEnters
	waitmovement 0
	applymovement LOCALID_WORKER2, OzoneLilycoveHQ_Movement_WorkerFlabbergasted
	msgbox OzoneLilycoveHQ_Text_Boardroom5, MSGBOX_DEFAULT
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha3, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattAngry
	msgbox OzoneLilycoveHQ_Text_Matt3, MSGBOX_DEFAULT
	playse SE_M_SWEET_SCENT
	msgbox OzoneLilycoveHQ_Text_BoardSigh, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt4, MSGBOX_DEFAULT
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha4, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattJumping
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_Matt5, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_OZONE_MATT_1, OzoneLilycoveHQ_Text_MattDefeated, TRAINER_P_OZONE_TABITHA_1, OzoneLilycoveHQ_Text_TabithaDefeated, OzoneLilycoveHQ_EventScript_AdminsDefeated, NO_MUSIC
	goto OzoneLilycoveHQ_EventScript_AdminsDefeated
	release
	end

OzoneLilycoveHQ_EventScript_AdminsDefeated::
	delay 16
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha5, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt6, MSGBOX_DEFAULT
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaDeclaration
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_Tabitha6, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattUpset
	msgbox OzoneLilycoveHQ_Text_Matt7, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattLeaves
	waitmovement 0
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha7, MSGBOX_AUTOCLOSE
	setvar VAR_OZONE_ADMINS_STATE, 3
	warp MAP_THE_COLD_MINES, 56, 35
	release
	end

OzoneLilycoveHQ_Movement_PlayerHide:
	walk_right
	walk_up
	face_right
	step_end

OzoneLilycoveHQ_Movement_Worker2Talking:
	walk_in_place_slow_up
	step_end

OzoneLilycoveHQ_Movement_MattTalking:
	walk_in_place_slow_down
	step_end

OzoneLilycoveHQ_Movement_TabithaTalking:
	walk_in_place_down
	step_end

OzoneLilycoveHQ_Movement_Worker1Talking:
	walk_in_place_slow_right
	step_end

OzoneLilycoveHQ_Movement_Worker3Talking:
	walk_in_place_slow_left
	step_end

OzoneLilycoveHQ_Movement_PlayerEnters:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

OzoneLilycoveHQ_Movement_WorkerFlabbergasted:
	delay_16
	emote_question_mark
	delay_16
	walk_in_place_fast_left
	step_end

OzoneLilycoveHQ_Movement_MattAngry:
	walk_in_place_fast_left
	step_end

OzoneLilycoveHQ_Movement_MattJumping:
	emote_exclamation_mark
	delay_4
	jump_in_place_down
	step_end

OzoneLilycoveHQ_Movement_TabithaDeclaration:
	walk_left
	walk_down
	walk_down
	walk_right
	face_down
	step_end

OzoneLilycoveHQ_Movement_MattUpset:
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

OzoneLilycoveHQ_Movement_MattLeaves:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OzoneLilycoveHQ_Text_Boardroom1:
	.string "boardroom 1$"

OzoneLilycoveHQ_Text_Boardroom2:
	.string "boardroom 2$"

OzoneLilycoveHQ_Text_Matt1:
	.string "matt 1$"

OzoneLilycoveHQ_Text_Tabitha1:
	.string "tabitha 1$"

OzoneLilycoveHQ_Text_Boardroom3:
	.string "boardroom 3$"

OzoneLilycoveHQ_Text_Matt2:
	.string "matt 2$"

OzoneLilycoveHQ_Text_Tabitha2:
	.string "tabitha 2$"

OzoneLilycoveHQ_Text_Boardroom4:
	.string "boardroom 4$"

OzoneLilycoveHQ_Text_Boardroom5:
	.string "boardroom 5$"

OzoneLilycoveHQ_Text_Tabitha3:
	.string "tabitha 3$"

OzoneLilycoveHQ_Text_Matt3:
	.string "matt 3$"

OzoneLilycoveHQ_Text_BoardSigh:
	.string "boardroom sigh$"

OzoneLilycoveHQ_Text_Matt4:
	.string "matt 4$"

OzoneLilycoveHQ_Text_Tabitha4:
	.string "tabitha 4$"

OzoneLilycoveHQ_Text_Matt5:
	.string "matt 5$"

OzoneLilycoveHQ_Text_MattDefeated:
	.string "matt defeat$"

OzoneLilycoveHQ_Text_TabithaDefeated:
	.string "tabitha defeat$"

OzoneLilycoveHQ_Text_Tabitha5:
	.string "tabitha 5$"

OzoneLilycoveHQ_Text_Matt6:
	.string "matt 6$"

OzoneLilycoveHQ_Text_Tabitha6:
	.string "tabitha 6$"

OzoneLilycoveHQ_Text_Matt7:
	.string "matt 7$"

OzoneLilycoveHQ_Text_Tabitha7:
	.string "tabitha 7$"

OzoneLilycoveHQ_Text_BrellaHelp:
	.string "intro$"

OzoneLilycoveHQ_Text_BrellaGoGettem:
	.string "intro$"

OzoneLilycoveHQ_Text_BrellaThanks:
	.string "intro$"

OzoneLilycoveHQ_Text_BrellaAbout:
	.string "intro$"

OzoneLilycoveHQ_Text_BrellaNoMore:
	.string "intro$"

OzoneLilycoveHQ_Text_LandonIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_LandonDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_LandonPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_TerraIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_TerraDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_TerraPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_SeanIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_SeanDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_SeanPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_MarinaIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_MarinaDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_MarinaPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_NoBusinessHere:
	.string "get outta my house$"

OzoneLilycoveHQ_Text_SomeBusinessHere:
	.string "tabitha is upstairs bruv$"
