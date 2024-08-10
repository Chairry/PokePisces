.set LOCALID_BIRCH, 2

BirchMaritimeLab_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BirchMaritimeLab_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BirchMaritimeLab_OnLoad
	.byte 0

BirchMaritimeLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, BirchMaritimeLab_EventScript_BeforeStarter
	map_script_2 VAR_BIRCH_LAB_STATE, 6, BirchMaritimeLab_EventScript_BeatenRangers
	.2byte 0

BirchMaritimeLab_OnLoad:
	call_if_gt VAR_BIRCH_LAB_STATE, 4, BirchMaritimeLab_EventScript_ReplaceTable
	end

BirchMaritimeLab_EventScript_ReplaceTable::
	setmetatile 9, 2, METATILE_BirchLab_BirchTable1, TRUE
	setmetatile 10, 2, METATILE_BirchLab_BirchTable2, TRUE
	setmetatile 9, 3, METATILE_BirchLab_BirchTable3, TRUE
	setmetatile 10, 3, METATILE_BirchLab_BirchTable4, TRUE
	special DrawWholeMapView
	return

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
	speakername BirchMaritimeLab_Text_NameBirch
	msgbox BirchMaritimeLab_Text_TakeStarter, MSGBOX_DEFAULT
	closemessage
	speakername NULL
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	clearflag FLAG_HIDE_BIRCH_AFTER_STARTER
	setflag FLAG_HIDE_BIRCH_BEFORE_STARTER
	setflag FLAG_BRINEY_MIDGAME_VISIT
	special HealPlayerParty
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	goto BirchMaritimeLab_EventScript_GiveStarterEvent
	end

BirchMaritimeLab_EventScript_GiveStarterEvent::
	lockall
	bufferleadmonspeciesname STR_VAR_1
	setmetatile 9, 2, METATILE_BirchLab_BirchTable1, TRUE
	setmetatile 10, 2, METATILE_BirchLab_BirchTable2, TRUE
	setmetatile 9, 3, METATILE_BirchLab_BirchTable3, TRUE
	setmetatile 10, 3, METATILE_BirchLab_BirchTable4, TRUE
	special DrawWholeMapView
	speakername BirchMaritimeLab_Text_NameBirch
	message BirchMaritimeLab_Text_ReceivedStarter
	waitmessage
	playfanfare MUS_SLOTS_JACKPOT
	waitfanfare
	msgbox BirchMaritimeLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	speakername NULL
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
	speakername BirchMaritimeLab_Text_NameBirch
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
	speakername NULL
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
	speakername BirchMaritimeLab_Text_NameBirch
	msgbox BirchMaritimeLab_Text_AfterGettingStarter, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

BirchMaritimeLab_EventScript_NoRoomForPokeBalls::
	msgbox BirchMaritimeLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

BirchMaritimeLab_EventScript_BeatenRangers::
	setflag FLAG_HIDE_SKY_PILLAR_RANGERS
	setvar VAR_BIRCH_LAB_STATE, 7
	applymovement OBJ_EVENT_ID_PLAYER, BirchMaritimeLab_Movement_PlayerReturnFromSkyPillar
	speakername BirchMaritimeLab_Text_NameBirch
	msgbox BirchMaritimeLab_Text_HaveEXPShare, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	setflag FLAG_RECEIVED_TM_POUNCE
	setflag FLAG_RECEIVED_EXP_SHARE
	setvar VAR_BALL_QUEST_STATE, 69
	msgbox BirchMaritimeLab_Text_GoToSootopolis, MSGBOX_AUTOCLOSE
	speakername NULL
	releaseall
	end

BirchMaritimeLab_EventScript_BirchPostSkyPillar::
	speakername BirchMaritimeLab_Text_NameBirch
	msgbox BirchMaritimeLab_Text_BirchPostSkyPillar, MSGBOX_NPC
	speakername NULL
	end

BirchMaritimeLab_EventScript_GrangerPostSkyPillar::
	speakername BirchMaritimeLab_Text_NameGranger
	msgbox BirchMaritimeLab_Text_GrangerPostSkyPillar, MSGBOX_NPC
	speakername NULL
	end

BirchMaritimeLab_EventScript_JeanniePostSkyPillar::
	speakername BirchMaritimeLab_Text_NameJeannie
	msgbox BirchMaritimeLab_Text_JeanniePostSkyPillar, MSGBOX_NPC
	speakername NULL
	end

BirchMaritimeLab_EventScript_RickyPostSkyPillar::
	speakername BirchMaritimeLab_Text_NameRicky
	msgbox BirchMaritimeLab_Text_RickyPostSkyPillar, MSGBOX_NPC
	speakername NULL
	end

BirchMaritimeLab_Movement_PlayerReturnFromSkyPillar:
	face_up
	step_end

BirchMaritimeLab_Text_NameBirch:
	.string "Dad$"

BirchMaritimeLab_Text_NameGranger:
	.string "Granger$"

BirchMaritimeLab_Text_NameJeannie:
	.string "Jeannie$"

BirchMaritimeLab_Text_NameRicky:
	.string "Ricky$"

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
	.string "species of Pokémon to give out\l"
	.string "to budding trainers.\p"
	.string "I think you'll really take to them!$"

BirchMaritimeLab_Text_ReceivedStarter:
	.string "{PLAYER} has received their\n"
	.string "Starter Pokémon, {STR_VAR_1}!$"

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

BirchMaritimeLab_Text_HaveEXPShare:
	.string "Great job, kiddo!\n"
	.string "Heard they got a good whoopin'.\p"
	.string "You should be off properly, now.\p"
	.string "If you want to fill out the badge case,\n"
	.string "Sootopolis City is the place to be!\p"
	.string "You can get there by leaving via the\n"
	.string "east exit of Pacifidlog,\l"
	.string "and hiking up the coastal rocks.\p"
	.string "Oh!\p"
	.string "And I suspect you're going to want to\n"
	.string "raise a lot of team members.\p"
	.string "Here; this EXP Share should help\n"
	.string "with that!$"

BirchMaritimeLab_Text_GoToSootopolis:
	.string "You can turn on the EXP Share from your\n"
	.string "bag, {PLAYER}.\l"
	.string "When on, it'll share EXP to Pokémon\l"
	.string "in your party, even if\l"
	.string "they didn't battle.\p"
	.string "Hah!\n"
	.string "You look about ready\l"
	.string "to take on anything!\p"
	.string "Go get 'em, champ;\n"
	.string "dear ol' dad is rooting you on!$"

BirchMaritimeLab_Text_BirchPostSkyPillar:
	.string "{PLAYER}, don't forget;\n"
	.string "your goal right now should be\l"
	.string "getting to Sootopolis City.\p"
	.string "It's a simple trek east!\n"
	.string "Make me proud, and be safe!$"

BirchMaritimeLab_Text_GrangerPostSkyPillar:
	.string "Ah, {PLAYER}!\p"
	.string "You've proven yourself a\n"
	.string "blossoming talent!\p"
	.string "We have nothing left to assist you\n"
	.string "with. Explore Hoenn to your heart's\l"
	.string "content. Be safe out there!$"

BirchMaritimeLab_Text_JeanniePostSkyPillar:
	.string "Well, what are you waiting for?\n"
	.string "the world's your oyster!\l"
	.string "Make us proud!$"

BirchMaritimeLab_Text_RickyPostSkyPillar:
	.string "You're on FIRE!!\p"
	.string "Burned through the three of us like\n"
	.string "we was dry paper!\p"
	.string "Keep it up, don't let that passion'a\n"
	.string "yours die out. Go show Hoenn\l"
	.string "what you're made of!$"
