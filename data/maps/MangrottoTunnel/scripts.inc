.set LOCALID_BREAD, 18
.set LOCALID_EGGNEGGMA1, 21
.set LOCALID_EGGNEGGMA2, 20
.set LOCALID_EGGNEGGMA3, 19
.set LOCALID_EGGNEGGMA4, 22
.set LOCALID_EGGNEGGMA5, 23

MangrottoTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MangrottoTunnel_OnTransition
	.byte 0

MangrottoTunnel_OnTransition:
	call MangrottoTunnel_EventScript_SetEggState
	end

MangrottoTunnel_EventScript_SetEggState::
	goto_if_set FLAG_MANGROTTO_EGG, MangrottoTunnel_EventScript_EggGotten
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	return

MangrottoTunnel_EventScript_EggGotten::
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setvar VAR_TEMP_4, 5
	return

MangrottoTunnel_EventScript_EggEncounter1North::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA1, MangrottoTunnel_Movement_EggRunAway1North
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA1
	setflag FLAG_TEMP_11
	clearflag FLAG_TEMP_12
	setvar VAR_TEMP_4, 1
	release
	end

MangrottoTunnel_Movement_EggRunAway1North:
	emote_exclamation_mark
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MangrottoTunnel_EventScript_EggEncounter1East::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA1, MangrottoTunnel_Movement_EggRunAway1East
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA1
	setflag FLAG_TEMP_11
	clearflag FLAG_TEMP_12
	setvar VAR_TEMP_4, 1
	release
	end

MangrottoTunnel_Movement_EggRunAway1East:
	emote_exclamation_mark
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MangrottoTunnel_EventScript_EggEncounter2West::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA2, MangrottoTunnel_Movement_EggRunAway2West
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA2
	setflag FLAG_TEMP_12
	clearflag FLAG_TEMP_13
	setvar VAR_TEMP_4, 2
	release
	end

MangrottoTunnel_Movement_EggRunAway2West:
	emote_exclamation_mark
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MangrottoTunnel_EventScript_EggEncounter2East::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA2, MangrottoTunnel_Movement_EggRunAway2East
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA2
	setflag FLAG_TEMP_12
	clearflag FLAG_TEMP_11
	setvar VAR_TEMP_4, 0
	release
	end

MangrottoTunnel_Movement_EggRunAway2East:
	emote_exclamation_mark
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MangrottoTunnel_EventScript_EggEncounter3West::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA3, MangrottoTunnel_Movement_EggRunAway3West
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA3
	setflag FLAG_TEMP_13
	clearflag FLAG_TEMP_14
	setvar VAR_TEMP_4, 3
	release
	end

MangrottoTunnel_Movement_EggRunAway3West:
	emote_exclamation_mark
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MangrottoTunnel_EventScript_EggEncounter3East::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA3, MangrottoTunnel_Movement_EggRunAway3East
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA3
	setflag FLAG_TEMP_13
	clearflag FLAG_TEMP_12
	setvar VAR_TEMP_4, 1
	release
	end

MangrottoTunnel_Movement_EggRunAway3East:
	emote_exclamation_mark
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MangrottoTunnel_EventScript_EggEncounter4West::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA4, MangrottoTunnel_Movement_EggRunAway4West
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA4
	setflag FLAG_TEMP_14
	clearflag FLAG_TEMP_15
	setvar VAR_TEMP_4, 4
	release
	end

MangrottoTunnel_Movement_EggRunAway4West:
	emote_exclamation_mark
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	step_end

MangrottoTunnel_EventScript_EggEncounter4East::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA4, MangrottoTunnel_Movement_EggRunAway4East
	waitmovement 0
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	removeobject LOCALID_EGGNEGGMA4
	setflag FLAG_TEMP_14
	clearflag FLAG_TEMP_11
	setvar VAR_TEMP_4, 0
	release
	end

MangrottoTunnel_Movement_EggRunAway4East:
	emote_exclamation_mark
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

MangrottoTunnel_EventScript_EggEncounter5FinalLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MangrottoTunnel_Movement_PlayerBlockLeft
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA5, MangrottoTunnel_Movement_EggBumpIntoPlayer
	waitmovement 0
	playse SE_WALL_HIT
	waitse
	msgbox MangrottoTunnel_Text_DroppedEgg, MSGBOX_DEFAULT
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	applymovement LOCALID_EGGNEGGMA5, MangrottoTunnel_Movement_EggFlee
	waitmovement 0
	removeobject LOCALID_EGGNEGGMA5
	setflag FLAG_TEMP_15
	setflag FLAG_MANGROTTO_EGG
	setvar VAR_TEMP_4, 5
	goto MangrottoTunnel_EventScript_ReceiveEgg
	release
	end

MangrottoTunnel_EventScript_ReceiveEgg::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EGG
	giveegg SPECIES_WELPROOT
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MangrottoTunnel_EventScript_ReceiveEggParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MangrottoTunnel_EventScript_ReceiveEggPC
	goto Common_EventScript_NoMoreRoomForPokemon
	release
	end

MangrottoTunnel_EventScript_ReceiveEggParty::
	call MangrottoTunnel_EventScript_ReceivedEggFanfare
	release
	end

MangrottoTunnel_EventScript_ReceiveEggPC::
	call MangrottoTunnel_EventScript_ReceivedEggFanfare
	call Common_EventScript_TransferredToPC
	release
	end

MangrottoTunnel_EventScript_ReceivedEggFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message MangrottoTunnel_Text_PlayerReceivedEgg
	waitmessage
	waitfanfare
	return

MangrottoTunnel_Movement_PlayerBlockLeft:
	walk_right
	face_down
	step_end

MangrottoTunnel_Movement_EggBumpIntoPlayer:
	emote_exclamation_mark
	delay 30
	delay 30
	walk_fast_up
	walk_fast_up
	step_end

MangrottoTunnel_Movement_EggFlee:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MangrottoTunnel_EventScript_EggEncounter5FinalMiddle::
	lock
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA5, MangrottoTunnel_Movement_EggBumpIntoPlayer
	waitmovement 0
	playse SE_WALL_HIT
	waitse
	msgbox MangrottoTunnel_Text_DroppedEgg, MSGBOX_DEFAULT
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	applymovement LOCALID_EGGNEGGMA5, MangrottoTunnel_Movement_EggFlee
	waitmovement 0
	removeobject LOCALID_EGGNEGGMA5
	setflag FLAG_TEMP_15
	setflag FLAG_MANGROTTO_EGG
	setvar VAR_TEMP_4, 5
	goto MangrottoTunnel_EventScript_ReceiveEgg
	release
	end

MangrottoTunnel_EventScript_EggEncounter5FinalRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MangrottoTunnel_Movement_PlayerBlockRight
	playse SE_PIN
	applymovement LOCALID_EGGNEGGMA5, MangrottoTunnel_Movement_EggBumpIntoPlayer
	waitmovement 0
	playse SE_WALL_HIT
	waitse
	msgbox MangrottoTunnel_Text_DroppedEgg, MSGBOX_DEFAULT
	playmoncry SPECIES_EGGNEGGMA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	applymovement LOCALID_EGGNEGGMA5, MangrottoTunnel_Movement_EggFlee
	waitmovement 0
	removeobject LOCALID_EGGNEGGMA5
	setflag FLAG_TEMP_15
	setflag FLAG_MANGROTTO_EGG
	setvar VAR_TEMP_4, 5
	goto MangrottoTunnel_EventScript_ReceiveEgg
	release
	end

MangrottoTunnel_Movement_PlayerBlockRight:
	walk_left
	face_down
	step_end

MangrottoTunnel_EventScript_BreadwinnerEnc1::
	lock
	setflag FLAG_TEMP_16
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadE1
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadBackUp
	waitmovement 0
	trainerbattle_single TRAINER_P_PANDOU_1, MangrottoTunnel_Text_BreadwinnerIntro, MangrottoTunnel_Text_BreadwinnerDefeat, MangrottoTunnel_EventScript_BreadRun
	release
	end

MangrottoTunnel_Movement_BreadE1:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MangrottoTunnel_EventScript_BreadwinnerEnc2::
	lock
	setflag FLAG_TEMP_17
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadE2
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadBackUp
	waitmovement 0
	trainerbattle_single TRAINER_P_PANDOU_1, MangrottoTunnel_Text_BreadwinnerIntro, MangrottoTunnel_Text_BreadwinnerDefeat, MangrottoTunnel_EventScript_BreadRun
	release
	end

MangrottoTunnel_Movement_BreadE2:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MangrottoTunnel_Movement_BreadBackUp:
	walk_fast_up
	walk_fast_up
	face_down
	step_end

MangrottoTunnel_EventScript_BreadRun::
	setvar VAR_BREADWINNER_STATE, 1
	speakername MangrottoTunnel_Text_NamePandou
	msgbox MangrottoTunnel_Text_BreadwinnerRunAway, MSGBOX_DEFAULT
	closemessage
	speakername NULL
	goto_if_set FLAG_TEMP_16, MangrottoTunnel_EventScript_BreadEscape1
	goto_if_set FLAG_TEMP_17, MangrottoTunnel_EventScript_BreadEscape2
	release
	end

MangrottoTunnel_EventScript_BreadEscape1::
	playse SE_FLEE
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadEsc1
	waitmovement 0
	setflag FLAG_HIDE_TEAM_OZONE_COSMOSS
	release
	end

MangrottoTunnel_Movement_BreadEsc1:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MangrottoTunnel_EventScript_BreadEscape2::
	playse SE_FLEE
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadEsc2
	waitmovement 0
	setflag FLAG_HIDE_TEAM_OZONE_COSMOSS
	release
	end

MangrottoTunnel_Movement_BreadEsc2:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MangrottoTunnel_EventScript_Dundee::
    trainerbattle_single TRAINER_P_DUNDEE, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Moka::
    trainerbattle_single TRAINER_P_MOKA, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Woods::
    trainerbattle_single TRAINER_P_WOODS, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Fauna::
    trainerbattle_single TRAINER_P_FAUNA, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Declan::
    trainerbattle_single TRAINER_P_DECLAN, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Shinji::
    trainerbattle_single TRAINER_P_SHINJI, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Skeeter::
    trainerbattle_single TRAINER_P_SKEETER, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Jaja::
    trainerbattle_single TRAINER_P_JAJA, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Jane::
    trainerbattle_single TRAINER_P_JANE, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Layton::
    trainerbattle_single TRAINER_P_LAYTON, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Jo_And_Jo::
    trainerbattle_double TRAINER_P_JO_AND_JO, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated, MangrottoTunnel_Text_GugumbirNeedTwoMons
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Infestation::
    lock
	faceplayer
	checkitem ITEM_TM_INFESTATION
	goto_if_eq VAR_RESULT, TRUE, MangrottoTunnel_EventScript_GaveInfestation
	msgbox MangrottoTunnel_Text_InfestedTree, MSGBOX_DEFAULT
	giveitem ITEM_TM_INFESTATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

MangrottoTunnel_EventScript_GaveInfestation::
    msgbox MangrottoTunnel_Text_CuringTheTree, MSGBOX_AUTOCLOSE
    release
    end

MangrottoTunnel_EventScript_RockSmashDoor::
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	addvar VAR_TEMP_4, 1
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox MangrottoTunnel_Text_WeirdIndent, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto MangrottoTunnel_EventScript_RockSmashDoorEnd
	end

MangrottoTunnel_EventScript_RockSmashDoorEnd::
	setmetatile 66, 30, METATILE_Mossdeep_MangrottoCaveDoor, FALSE
	special DrawWholeMapView
	releaseall
	end

MangrottoTunnel_Text_WeirdIndent:
	.string "There is an odd indent in\n"
	.string "the cave wall here.\p"
	.string "Would you like to have a\n"
	.string "Pokémon use Rock Smash?$"

MangrottoTunnel_Text_InfestedTree:
	.string "Ugh, this tree is INFESTED\n"
	.string "with Mandimytes! They're eating\l"
	.string "the poor thing to splinters...\p"
	.string "(You look inside the trunk and see\n"
	.string "a... TM? The Mandimytes are\l"
	.string "crowding around. You reach in\l"
	.string "and remove it.)\p"
	.string "Oh? They're scattering now.\n"
	.string "Well, thanks for the help!$"

MangrottoTunnel_Text_CuringTheTree:
	.string "Those critters did a number\n"
	.string "on this tree... I'll try\l"
	.string "my best to nurse it back to health.$"

MangrottoTunnel_Text_DroppedEgg:
	.string "(The strange wild Pokémon dropped\n"
	.string "the egg it was holding!)$"

MangrottoTunnel_Text_PlayerReceivedEgg:
	.string "{PLAYER} received an Egg!$"

MangrottoTunnel_Text_NamePandou:
	.string "Pandou$"

MangrottoTunnel_Text_BreadwinnerIntro:
	.string "Heavens to Betsy,\n"
	.string "I am so sorry!\p"
	.string "I'm in a HUGE rush to\n"
	.string "get to work today.\l"
	.string "I'll just squeeze on past here…\p"
	.string "(You lock eyes with the man, glaring\n"
	.string "directly into his very soul.)\p"
	.string "Wh-what? I, Um, don't have time for a-$"

MangrottoTunnel_Text_BreadwinnerDefeat:
	.string "I surrender!!\p"
	.string "P-please just let me pass!$"

MangrottoTunnel_Text_BreadwinnerRunAway:
	.string "Look, th-that was fun and all, but\n"
	.string "now I am ever more minutes late!!\p"
	.string "Excuse me…$"

MangrottoTunnel_Text_GugumbirIntro:
	.string "intro$"

MangrottoTunnel_Text_GugumbirDefeated:
	.string "defeat$"

MangrottoTunnel_Text_GugumbirPostBattle:
	.string "post$"

MangrottoTunnel_Text_GugumbirNeedTwoMons:
	.string "need 2 doods$"
