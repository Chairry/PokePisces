.set LOCALID_BIRCH, 2

BirchMaritimeLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BirchMaritimeLab_OnFrame
	.byte 0

BirchMaritimeLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, BirchMaritimeLab_EventScript_BeforeStarter
	.2byte 0

BirchMaritimeLab_EventScript_BeforeStarter::
	lockall
	setobjectxyperm LOCALID_BIRCH, 9, 13
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
	walk_left
	face_right
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
	msgbox BirchMaritimeLab_Text_TakeStarter, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	clearflag FLAG_HIDE_BIRCH_AFTER_STARTER
	setflag FLAG_HIDE_BIRCH_BEFORE_STARTER
	special HealPlayerParty
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
	playbgm MUS_ENCOUNTER_MAY, FALSE
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

BirchMaritimeLab_Text_TakeStarter:
	.string "For a journey as long and,\n"
	.string "hopefully, fruitful as it seems\l"
	.string "this one will be... I'd love\l"
	.string "to give you one of these\l"
	.string "three Starter POKéMON, as a\l"
	.string "close traveling companion.\p"
	.string "Just like old times, huh?\p"
	.string "With the move to Pacifidlog,\n"
	.string "I had to start collecting 3 new\l"
	.string "species of POKéMON to give out\l"
	.string "to budding trainers.\p"
	.string "I think you'll really take to them!$"

BirchMaritimeLab_Text_ReceivedStarter:
	.string "{PLAYER} has received their\n"
	.string "Starter POKéMON, {STR_VAR_1}!$"

BirchMaritimeLab_Text_AfterGettingStarter:
	.string "Go get em champ!$"

BirchMaritimeLab_Text_WhyNotGiveNicknameToMon:
	.string "Ah! Your new friend is wanting\n"
	.string "to show you its loyalty!\p"
	.string "Want to give it a nickname?$"

BirchMaritimeLab_Text_HeardYouBeatRivalTakePokedex:
	.string "Very good then!\n"
	.string "Along with your Starter POKéMON,\l"
	.string "I'd be remiss if I didn't also\l"
	.string "give you a brand new POKéDEX as well!$"

BirchMaritimeLab_Text_ExplainPokedex:
	.string "This model is much the same\n"
	.string "as the one you had used some time\l"
	.string "ago. Be aware, though, that the\l"
	.string "slate has been wiped clean,\l"
	.string "so to speak.\p"
	.string "I'm sure you will encounter\n"
	.string "many new faces in your\l"
	.string "journey across the Hoenn region!$"

BirchMaritimeLab_Text_ReceivedPokedex:
	.string "{PLAYER} received a new POKéDEX!$"

BirchMaritimeLab_Text_TakeBalls:
	.string "Now, {PLAYER}, kiddo...\p"
	.string "I know you're really wanting\n"
	.string "to get started and blitz through\l"
	.string "the path forward, but I don't\l"
	.string "think you've battled in a while,\l"
	.string "would I have that right?\p"
	.string "So, I took the liberty of\n"
	.string "contracting a few kindhearted\l"
	.string "Rangers to give you some\l"
	.string "warm-up fights!\p"
	.string "You'll find them atop Sky Pillar\n"
	.string "to the north.\p"
	.string "...Oh! And if you want to\n"
	.string "catch any more POKéMON along the\l"
	.string "way there, uhm... here...\p"
	.string "(Your dad shuffles through\n"
	.string "his labcoat pockets haphazardly.)$"

BirchMaritimeLab_Text_GoFightTheRangers:
	.string "Ten should suffice!\p"
	.string "...Alrighty! That's about all\n"
	.string "your pops has got to give.\p"
	.string "Please stay safe out there,\n"
	.string "alright kiddo?\p"
	.string "Good luck; I'm always in your corner!$"

BirchMaritimeLab_Text_OhYourBagsFull:
	.string "uh oh spaghettios$"
