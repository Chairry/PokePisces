.set LOCALID_PHOEBE, 11
.set LOCALID_SPENSER, 10

ZotpyreGym_MapScripts::
	.byte 0

ZotpyreGym_EventScript_ReplaceColumns1::
	lock
	goto_if_gt VAR_TEMP_5, 0, ZotpyreGym_EventScript_DontReplaceColumns
	msgbox ZotpyreGym_Text_IllMoveColumns, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_5, 1
	playse SE_M_COMET_PUNCH
	setmetatile 19, 16, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 19, 17, METATILE_OldStoneBuildings_ColumnShaft, FALSE
	setmetatile 19, 18, METATILE_OldStoneBuildings_ColumnShaft, TRUE
	setmetatile 12, 22, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 23, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 24, METATILE_OldStoneBuildings_ColumnTop, TRUE
	setmetatile 12, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 29, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 30, METATILE_OldStoneBuildings_ColumnTop, TRUE
	setmetatile 7, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 7, 29, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 19, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 19, 29, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 7, 10, METATILE_OldStoneBuildings_RelicFloor, TRUE
	setmetatile 7, 11, METATILE_OldStoneBuildings_ColumnTop, TRUE
	special DrawWholeMapView
	release
	end

ZotpyreGym_EventScript_DontReplaceColumns::
	msgbox ZotpyreGym_Text_AlreadyMovedColumns, MSGBOX_AUTOCLOSE
	release
	end

ZotpyreGym_EventScript_ReplaceColumns2::
	lock
	goto_if_gt VAR_TEMP_6, 0, ZotpyreGym_EventScript_DontReplaceColumns
	msgbox ZotpyreGym_Text_IllMoveColumns, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_6, 1
	playse SE_M_COMET_PUNCH
	setmetatile 12, 9, METATILE_OldStoneBuildings_BottomWall, TRUE
	setmetatile 12, 10, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 12, 16, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 17, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 18, METATILE_OldStoneBuildings_ColumnTop, TRUE
	special DrawWholeMapView
	release
	end

ZotpyreGym_EventScript_CheckForVar5::
	lock
	goto_if_eq VAR_TEMP_5, 0, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar6::
	lock
	goto_if_eq VAR_TEMP_6, 0, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar5And6::
	lock
	goto_if_eq VAR_TEMP_5, 0, ZotpyreGym_EventScript_WarpAway
	goto_if_eq VAR_TEMP_6, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckAgainstVar5::
	lock
	goto_if_eq VAR_TEMP_5, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar6And5::
	lock
	goto_if_eq VAR_TEMP_6, 1, ZotpyreGym_EventScript_WarpSafety
	goto_if_eq VAR_TEMP_5, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_WarpAway::
	lock
	msgbox ZotpyreGym_Text_TheFogIsComing, MSGBOX_AUTOCLOSE
	warp MAP_ZOTPYRE_GYM, 16, 28
	waitstate
	release
	end

ZotpyreGym_EventScript_WarpSafety::
	release
	end

ZotpyreGym_EventScript_Junji::
    trainerbattle_single TRAINER_P_JUNJI, ZotpyreGym_Text_JunjiIntro, ZotpyreGym_Text_JunjiDefeated
    msgbox ZotpyreGym_Text_JunjiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Kirie::
    trainerbattle_single TRAINER_P_KIRIE, ZotpyreGym_Text_KirieIntro, ZotpyreGym_Text_KirieDefeated
    msgbox ZotpyreGym_Text_KiriePostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Shuichi::
    trainerbattle_single TRAINER_P_SHUICHI, ZotpyreGym_Text_ShuichiIntro, ZotpyreGym_Text_ShuichiDefeated
    msgbox ZotpyreGym_Text_ShuichiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Tomie::
    trainerbattle_single TRAINER_P_TOMIE, ZotpyreGym_Text_TomieIntro, ZotpyreGym_Text_TomieDefeated
    msgbox ZotpyreGym_Text_TomiePostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Azami::
    trainerbattle_single TRAINER_P_AZAMI, ZotpyreGym_Text_AzamiIntro, ZotpyreGym_Text_AzamiDefeated
    msgbox ZotpyreGym_Text_AzamiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Misaki::
    trainerbattle_single TRAINER_P_MISAKI, ZotpyreGym_Text_MisakiIntro, ZotpyreGym_Text_MisakiDefeated
    msgbox ZotpyreGym_Text_MisakiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Yuina::
    trainerbattle_single TRAINER_P_YUINA, ZotpyreGym_Text_YuinaIntro, ZotpyreGym_Text_YuinaDefeated
    msgbox ZotpyreGym_Text_YuinaPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_LeaderBattle::
	lock
	faceplayer
	msgbox ZotpyreGym_Text_LeadersIntro, MSGBOX_DEFAULT
    trainerbattle_two_trainers TRAINER_P_PHOEBE, ZotpyreGym_Text_PhoebeDefeat, TRAINER_P_SPENSER, ZotpyreGym_Text_SpenserDefeat, ZotpyreGym_EventScript_LeadersDefeated, NO_MUSIC
	goto ZotpyreGym_EventScript_LeadersDefeated
	release
	end

ZotpyreGym_EventScript_EncLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, ZotpyreGym_Movement_WalkLeft
	goto ZotpyreGym_EventScript_EncounterLeaders
	end

ZotpyreGym_Movement_WalkLeft:
	walk_left
	step_end

ZotpyreGym_EventScript_EncRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, ZotpyreGym_Movement_WalkRight
	goto ZotpyreGym_EventScript_EncounterLeaders
	end

ZotpyreGym_Movement_WalkRight:
	walk_right
	step_end

ZotpyreGym_EventScript_EncounterLeaders::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, ZotpyreGym_Movement_WalkUp
	msgbox ZotpyreGym_Text_LeadersIntro, MSGBOX_DEFAULT
	applymovement LOCALID_SPENSER, ZotpyreGym_Movement_Talk
	msgbox ZotpyreGym_Text_Spenser1, MSGBOX_DEFAULT
	applymovement LOCALID_SPENSER, ZotpyreGym_Movement_Talk
	msgbox ZotpyreGym_Text_Phoebe1, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_PHOEBE, ZotpyreGym_Text_PhoebeDefeat, TRAINER_P_SPENSER, ZotpyreGym_Text_SpenserDefeat, ZotpyreGym_EventScript_LeadersDefeated, NO_MUSIC
	goto ZotpyreGym_EventScript_LeadersDefeated
	release
	end

ZotpyreGym_Movement_WalkUp:
	walk_up
	step_end

ZotpyreGym_Movement_Talk:
	walk_in_place_down
	step_end

ZotpyreGym_EventScript_LeadersDefeated::
	msgbox ZotpyreGym_Text_LeadersYouWon, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 4
	giveitem ITEM_DILATANT_MOD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_FEAR_FACTOR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	warp MAP_ROUTE122, 42, 14
	release
	end

ZotpyreGym_Text_JunjiIntro:
	.string "intro$"

ZotpyreGym_Text_JunjiDefeated:
	.string "defeat$"

ZotpyreGym_Text_JunjiPostBattle:
	.string "post$"

ZotpyreGym_Text_KirieIntro:
	.string "intro$"

ZotpyreGym_Text_KirieDefeated:
	.string "defeat$"

ZotpyreGym_Text_KiriePostBattle:
	.string "post$"

ZotpyreGym_Text_ShuichiIntro:
	.string "intro$"

ZotpyreGym_Text_ShuichiDefeated:
	.string "defeat$"

ZotpyreGym_Text_ShuichiPostBattle:
	.string "post$"

ZotpyreGym_Text_TomieIntro:
	.string "intro$"

ZotpyreGym_Text_TomieDefeated:
	.string "defeat$"

ZotpyreGym_Text_TomiePostBattle:
	.string "post$"

ZotpyreGym_Text_AzamiIntro:
	.string "intro$"

ZotpyreGym_Text_AzamiDefeated:
	.string "defeat$"

ZotpyreGym_Text_AzamiPostBattle:
	.string "post$"

ZotpyreGym_Text_MisakiIntro:
	.string "intro$"

ZotpyreGym_Text_MisakiDefeated:
	.string "defeat$"

ZotpyreGym_Text_MisakiPostBattle:
	.string "post$"

ZotpyreGym_Text_YuinaIntro:
	.string "intro$"

ZotpyreGym_Text_YuinaDefeated:
	.string "defeat$"

ZotpyreGym_Text_YuinaPostBattle:
	.string "post$"

ZotpyreGym_Text_Spenser1:
	.string "hello$"

ZotpyreGym_Text_Phoebe1:
	.string "hello$"

ZotpyreGym_Text_PhoebeDefeat:
	.string "defeat$"

ZotpyreGym_Text_SpenserDefeat:
	.string "defeat$"

ZotpyreGym_Text_LeadersIntro:
	.string "finnina battle$"

ZotpyreGym_Text_LeadersYouWon:
	.string "u woned take this$"

ZotpyreGym_Text_IllMoveColumns:
	.string "ill move deez columns$"

ZotpyreGym_Text_AlreadyMovedColumns:
	.string "already moved columns$"

ZotpyreGym_Text_TheFogIsComing:
	.string "the fog is coming$"
