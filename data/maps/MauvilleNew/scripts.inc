.set LOCALID_P_MAN, 7
.set LOCALID_BONDING, 8

MauvilleNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleNew_OnLoad
	.byte 0

MauvilleNew_OnLoad:
	call_if_lt VAR_OLD_GUYS_STATE, 2, MauvilleNew_EventScript_RemovePowerlessMan
	call_if_gt VAR_OLD_GUYS_STATE, 2, MauvilleNew_EventScript_RemovePowerlessMan
	call_if_lt VAR_OLD_GUYS_STATE, 18, MauvilleNew_EventScript_RemoveMrBonding
	end

MauvilleNew_EventScript_RemovePowerlessMan::
	removeobject LOCALID_P_MAN
	setflag FLAG_TEMP_11
	return

MauvilleNew_EventScript_RemoveMrBonding::
	removeobject LOCALID_BONDING
	setflag FLAG_TEMP_12
	return

MauvilleNew_EventScript_Kizuna::
	speakername MauvilleNew_Text_NameKizuna
	msgbox MauvilleNew_Text_LookingForClues, MSGBOX_NPC
    end

MauvilleNew_EventScript_MrBonding::
	lock
	faceplayer
	goto_if_eq VAR_OLD_GUYS_STATE, 19, MauvilleNew_EventScript_MrBondingPostBattle
	goto_if_ge VAR_OLD_GUYS_STATE, 20, MauvilleNew_EventScript_MrBondingAfterGym
	speakername MauvilleNew_Text_NameMrBonding
	msgbox MauvilleNew_Text_YouHaveArrived, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BONDING, MauvilleNew_Movement_FaceDown
	waitmovement 0
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleNew_EventScript_PlayerNorthMove
	call_if_eq VAR_FACING, DIR_EAST, MauvilleNew_EventScript_PlayerEastMove
	call_if_eq VAR_FACING, DIR_SOUTH, MauvilleNew_EventScript_PlayerSouthMove
	call_if_eq VAR_FACING, DIR_WEST, MauvilleNew_EventScript_PlayerWestMove
	delay 4
	speakername MauvilleNew_Text_NameMrBonding
	trainerbattle_single TRAINER_P_MR_BONDING, MauvilleNew_Text_BondingIntro, MauvilleNew_Text_BondingDefeated, MauvilleNew_EventScript_MrBondingBeaten
	release
	end

MauvilleNew_Movement_FaceDown:
	face_down
	step_end

MauvilleNew_EventScript_PlayerNorthMove::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleNew_Movement_GetIntoPosNorth
	waitmovement 0
	delay 4
	return

MauvilleNew_Movement_GetIntoPosNorth:
	walk_down
	walk_down
	walk_down
	face_up
	step_end

MauvilleNew_EventScript_PlayerEastMove::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleNew_Movement_GetIntoPosEast
	waitmovement 0
	delay 4
	return

MauvilleNew_Movement_GetIntoPosEast:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	face_up
	step_end

MauvilleNew_EventScript_PlayerSouthMove::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleNew_Movement_GetIntoPosSouth
	waitmovement 0
	delay 4
	return

MauvilleNew_Movement_GetIntoPosSouth:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_up
	step_end

MauvilleNew_EventScript_PlayerWestMove::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleNew_Movement_GetIntoPosWest
	waitmovement 0
	delay 4
	return

MauvilleNew_Movement_GetIntoPosWest:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_up
	step_end

MauvilleNew_EventScript_MrBondingBeaten::
	speakername MauvilleNew_Text_NameMrBonding
	msgbox MauvilleNew_Text_WellDone, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleNew_Movement_RejoinMrBonding
	waitmovement 0
	msgbox MauvilleNew_Text_SomeLoreDrops, MSGBOX_DEFAULT
	giveitem ITEM_LOADED_DICE
	speakername MauvilleNew_Text_NameMrBonding
	msgbox MauvilleNew_Text_GoToVerdanturf, MSGBOX_DEFAULT
	closemessage
	release
	end

MauvilleNew_Movement_RejoinMrBonding:
	walk_up
	walk_up
	walk_up
	step_end

MauvilleNew_EventScript_MrBondingPostBattle::
	speakername MauvilleNew_Text_NameMrBonding
	msgbox MauvilleNew_Text_TheBadgeAwaits, MSGBOX_AUTOCLOSE
	release
	end

MauvilleNew_EventScript_MrBondingAfterGym::
	speakername MauvilleNew_Text_NameMrBonding
	msgbox MauvilleNew_Text_ThankYouSincerely, MSGBOX_AUTOCLOSE
	release
	end

MauvilleNew_EventScript_Kurt::
    trainerbattle_single TRAINER_P_KURT, MauvilleNew_Text_KurtIntro, MauvilleNew_Text_KurtDefeated
    msgbox MauvilleNew_Text_KurtPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Kirst::
    trainerbattle_single TRAINER_P_KIRST, MauvilleNew_Text_KirstIntro, MauvilleNew_Text_KirstDefeated
    msgbox MauvilleNew_Text_KirstPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Maia::
    trainerbattle_single TRAINER_P_MAIA, MauvilleNew_Text_MaiaIntro, MauvilleNew_Text_MaiaDefeated
    msgbox MauvilleNew_Text_MaiaPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_EventScript_Miguel::
    trainerbattle_single TRAINER_P_MIGUEL, MauvilleNew_Text_MiguelIntro, MauvilleNew_Text_MiguelDefeated
    msgbox MauvilleNew_Text_MiguelPostBattle, MSGBOX_AUTOCLOSE
    end

MauvilleNew_Text_KurtIntro:
	.string "intro$"

MauvilleNew_Text_KurtDefeated:
	.string "defeat$"

MauvilleNew_Text_KurtPostBattle:
	.string "post$"

MauvilleNew_Text_KirstIntro:
	.string "intro$"

MauvilleNew_Text_KirstDefeated:
	.string "defeat$"

MauvilleNew_Text_KirstPostBattle:
	.string "post$"

MauvilleNew_Text_MaiaIntro:
	.string "intro$"

MauvilleNew_Text_MaiaDefeated:
	.string "defeat$"

MauvilleNew_Text_MaiaPostBattle:
	.string "post$"

MauvilleNew_Text_MiguelIntro:
	.string "intro$"

MauvilleNew_Text_MiguelDefeated:
	.string "defeat$"

MauvilleNew_Text_MiguelPostBattle:
	.string "post$"

MauvilleNew_Text_NameKizuna:
	.string "Kizuna$"

MauvilleNew_Text_NameMrBonding:
	.string "Mr. Bonding$"

MauvilleNew_Text_LookingForClues:
	.string "lookin for clues$"

MauvilleNew_Text_YouHaveArrived:
	.string "you have arrived$"

MauvilleNew_Text_BondingIntro:
	.string "It's Bonding Time$"

MauvilleNew_Text_BondingDefeated:
	.string "twas not bonding time$"

MauvilleNew_Text_WellDone:
	.string "well done$"

MauvilleNew_Text_SomeLoreDrops:
	.string "here's some lore (real)$"

MauvilleNew_Text_GoToVerdanturf:
	.string "go to verdanturf now$"

MauvilleNew_Text_TheBadgeAwaits:
	.string "get that mf badge$"

MauvilleNew_Text_ThankYouSincerely:
	.string "thank you my friend$"
