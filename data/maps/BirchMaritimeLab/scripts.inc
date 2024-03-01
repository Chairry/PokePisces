.set LOCALID_BIRCH, 2

BirchMaritimeLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BirchMaritimeLab_OnFrame
	.byte 0

BirchMaritimeLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, BirchMaritimeLab_EventScript_BeforeStarter
	.2byte 0

BirchMaritimeLab_EventScript_BeforeStarter::
	lockall
	setobjectxy LOCALID_BIRCH, 9, 13
	applymovement LOCALID_BIRCH, BirchMaritimeLab_Movement_BirchEnterLabForPokedex
	applymovement OBJ_EVENT_ID_PLAYER, BirchMaritimeLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto BirchMaritimeLab_EventScript_PickYourStarter
	end

BirchMaritimeLab_Movement_BirchEnterLabForPokedex:
	walk_right
	walk_right
	walk_right
	walk_right
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
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

BirchMaritimeLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
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
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

BirchMaritimeLab_EventScript_PickYourStarter::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	goto BirchMaritimeLab_EventScript_GiveStarterEvent
	end

BirchMaritimeLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message BirchMaritimeLab_Text_ReceivedStarter
	waitmessage
	playfanfare MUS_SLOTS_JACKPOT
	waitfanfare
	playbgm MUS_ENCOUNTER_MAY, FALSE
	msgbox BirchMaritimeLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BirchMaritimeLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, BirchMaritimeLab_EventScript_GivePokedex
	end

BirchMaritimeLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto BirchMaritimeLab_EventScript_GivePokedex
	end

BirchMaritimeLab_EventScript_GivePokedex::
	msgbox BirchMaritimeLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call BirchMaritimeLab_EventScript_ReceivePokedex
	msgbox BirchMaritimeLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	call BirchMaritimeLab_EventScript_GivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	releaseall
	end

BirchMaritimeLab_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message BirchMaritimeLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

BirchMaritimeLab_EventScript_GivePokeBalls::
	msgbox BirchMaritimeLab_Text_TakeBalls, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 10
	call_if_eq VAR_RESULT, FALSE, BirchMaritimeLab_EventScript_NoRoomForPokeBalls
	msgbox BirchMaritimeLab_Text_GoFightTheRangers, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

BirchMaritimeLab_EventScript_PokemonAwait::
	msgbox BirchMaritimeLab_Text_AfterGettingStarter, MSGBOX_DEFAULT
	release
	end

BirchMaritimeLab_EventScript_NoRoomForPokeBalls::
	msgbox BirchMaritimeLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

BirchMaritimeLab_Text_ReceivedStarter:
	.string "{PLAYER} has received their\n"
	.string "Starter POKéMON, {STR_VAR_1}!$"

BirchMaritimeLab_Text_AfterGettingStarter:
	.string "Go get em champ!$"

BirchMaritimeLab_Text_WhyNotGiveNicknameToMon:
	.string "nickname it$"

BirchMaritimeLab_Text_HeardYouBeatRivalTakePokedex:
	.string "take this dex nerd$"

BirchMaritimeLab_Text_ExplainPokedex:
	.string "this lets you see nudes$"

BirchMaritimeLab_Text_ReceivedPokedex:
	.string "you got da dex$"

BirchMaritimeLab_Text_TakeBalls:
	.string "take my buols$"

BirchMaritimeLab_Text_GoFightTheRangers:
	.string "go fight the doods$"

BirchMaritimeLab_Text_OhYourBagsFull:
	.string "uh oh spaghettios$"
