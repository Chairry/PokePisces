StevenMaze_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, StevenMaze_OnTransition
	.byte 0

StevenMaze_OnTransition:
	call StevenMaze_EventScript_SetFlashLevel
	end

StevenMaze_EventScript_SetFlashLevel::
	setflashlevel 6
	return

StevenMaze_EventScript_CantUseFlash::
	lock
	setvar VAR_TEMP_1, 1
	msgbox StevenMaze_Text_Landing, MSGBOX_AUTOCLOSE
	release
	end

StevenMaze_EventScript_ShadowSteven1::
    trainerbattle_single TRAINER_P_S_STEVEN_1, StevenMaze_Text_Encounter, StevenMaze_Text_Defeat, StevenMaze_EventScript_ShadowStevenGone
    msgbox StevenMaze_Text_Darkness, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven2::
    trainerbattle_single TRAINER_P_S_STEVEN_2, StevenMaze_Text_Encounter, StevenMaze_Text_Defeat, StevenMaze_EventScript_ShadowStevenGone
    msgbox StevenMaze_Text_Darkness, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven3::
    trainerbattle_single TRAINER_P_S_STEVEN_3, StevenMaze_Text_Encounter, StevenMaze_Text_Defeat, StevenMaze_EventScript_ShadowStevenGone
    msgbox StevenMaze_Text_Darkness, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven4::
    trainerbattle_single TRAINER_P_S_STEVEN_4, StevenMaze_Text_Encounter, StevenMaze_Text_Defeat, StevenMaze_EventScript_ShadowStevenGone
    msgbox StevenMaze_Text_Darkness, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven5::
    trainerbattle_single TRAINER_P_S_STEVEN_5, StevenMaze_Text_Encounter, StevenMaze_Text_Defeat, StevenMaze_EventScript_ShadowStevenGone
    msgbox StevenMaze_Text_Darkness, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowSteven6::
    trainerbattle_single TRAINER_P_S_STEVEN_6, StevenMaze_Text_Encounter, StevenMaze_Text_Defeat, StevenMaze_EventScript_ShadowStevenGone
    msgbox StevenMaze_Text_Darkness, MSGBOX_AUTOCLOSE
    end

StevenMaze_EventScript_ShadowStevenGone::
	lock
	applymovement VAR_LAST_TALKED, StevenMaze_Movement_Dissapear
	waitmovement 0
	release
	end

StevenMaze_Movement_Dissapear:
	set_invisible
	step_end

StevenMaze_EventScript_PokeDoll::
	finditem ITEM_POKE_DOLL
	end

StevenMaze_EventScript_FinalSteven::
	lock
	speakername StevenMaze_Text_NameSteven
	msgbox StevenMaze_Text_AllDone, MSGBOX_DEFAULT
	setvar VAR_NEW_COO_STATE, 4
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, StevenMaze_EventScript_GiveEeriko
	goto StevenMaze_EventScript_TimeToLeave
	speakername NULL
	release
	end

StevenMaze_EventScript_TimeToLeave::
	speakername StevenMaze_Text_NameSteven
	setflag FLAG_DEFEATED_PANIC_EVENT
	msgbox StevenMaze_Text_Leave, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_STEVEN_HOUSE, 8, 3
	waitstate
	release
	end

StevenMaze_EventScript_GiveEeriko::
	msgbox StevenMaze_Text_Eeriko, MSGBOX_DEFAULT
	speakername NULL
	removeitem ITEM_POKE_DOLL, 1
	givemon SPECIES_EERIKO, 18
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, StevenMaze_EventScript_ReceiveEerikoParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, StevenMaze_EventScript_ReceiveEerikoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	goto StevenMaze_EventScript_TimeToLeave
	release
	end

StevenMaze_EventScript_ReceiveEerikoParty::
	call StevenMaze_EventScript_ReceivedEerikoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StevenMaze_EventScript_TimeToLeave
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto StevenMaze_EventScript_TimeToLeave
	release
	end

StevenMaze_EventScript_ReceiveEerikoPC::
	call StevenMaze_EventScript_ReceivedEerikoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StevenMaze_EventScript_SendEerikoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto StevenMaze_EventScript_SendEerikoToPC
	release
	end

StevenMaze_EventScript_SendEerikoToPC::
	call Common_EventScript_TransferredToPC
	goto StevenMaze_EventScript_TimeToLeave
	release
	end

StevenMaze_EventScript_ReceivedEerikoFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message StevenMaze_Text_PlayerReceivedEeriko
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EERIKO
	return

StevenMaze_Text_NameSteven:
	.string "Steven$"

StevenMaze_Text_Darkness:
	.string "(Nothing but darkness…)$"

StevenMaze_Text_Landing:
	.string "(Your Pokémon are a bit\n"
	.string "shaken… they are not able to use\l"
	.string "Flash right now.)$"

StevenMaze_Text_Encounter:
	.string "(A figure appears from\n"
	.string "the shadows!)$"

StevenMaze_Text_Defeat:
	.string "(The shadowy trainer\n"
	.string "vanishes…)$"

StevenMaze_Text_AllDone:
	.string "You've clawed your way\n"
	.string "out… impressive.\p"
	.string "I wanted to see your true character;\n"
	.string "to that end, I simulated a crisis\l"
	.string "situation for you and your team.\p"
	.string "The “Panic” status has always piqued\n"
	.string "my curiosity.\p"
	.string "All panicking Pokémon spend twice as\n"
	.string "much PP when choosing moves.\p"
	.string "It forces one to think ahead;\n"
	.string "to maybe save their valuable moves\l"
	.string "for when they are cured.$"

StevenMaze_Text_Eeriko:
	.string "Oh…?\p"
	.string "I noticed that doll you found\n"
	.string "in the maze.\l"
	.string "I was actually wondering where my\l"
	.string "third Eeriko ran off to.\p"
	.string "Seems that it found you… in fact,\n"
	.string "I can tell it's taken a special\l"
	.string "interest in you.\p"
	.string "Why not take Eeriko under your wing?$"

StevenMaze_Text_PlayerReceivedEeriko:
	.string "{PLAYER} received an Eeriko!$"

StevenMaze_Text_Leave:
	.string "With all that said, it's about time\n"
	.string "you get on your way, {PLAYER}.\p"
	.string "I'm beginning to see a seed of\n"
	.string "brilliance in you.\l"
	.string "I trust you plan to make it blossom.$"
