MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_Narrator1::
	lock
	fadeoutbgm 1
	setvar VAR_TEMP_5, 1
	speakername MossdeepCity_Gym_Text_NameVoice
	msgbox MossdeepCity_Gym_Text_Narrator_1, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_Gym_EventScript_Narrator2::
	lock
	setvar VAR_TEMP_5, 2
	speakername MossdeepCity_Gym_Text_NameVoice
	msgbox MossdeepCity_Gym_Text_Narrator_2, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_Gym_EventScript_Narrator3::
	lock
	setvar VAR_TEMP_5, 3
	speakername MossdeepCity_Gym_Text_NameVoice
	msgbox MossdeepCity_Gym_Text_Narrator_3, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

MossdeepCity_Gym_EventScript_Planck::
    trainerbattle_single TRAINER_P_PLANCK, MossdeepCity_Gym_Text_GugumbirIntro, MossdeepCity_Gym_Text_GugumbirDefeated
    msgbox MossdeepCity_Gym_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MossdeepCity_Gym_EventScript_Legri::
    trainerbattle_single TRAINER_P_LEGRI, MossdeepCity_Gym_Text_GugumbirIntro, MossdeepCity_Gym_Text_GugumbirDefeated
    msgbox MossdeepCity_Gym_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MossdeepCity_Gym_EventScript_Spitzer::
    trainerbattle_single TRAINER_P_SPITZER, MossdeepCity_Gym_Text_GugumbirIntro, MossdeepCity_Gym_Text_GugumbirDefeated
    msgbox MossdeepCity_Gym_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MossdeepCity_Gym_EventScript_Tess::
    trainerbattle_single TRAINER_P_TESS, MossdeepCity_Gym_Text_GugumbirIntro, MossdeepCity_Gym_Text_GugumbirDefeated
    msgbox MossdeepCity_Gym_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MossdeepCity_Gym_EventScript_Hitomi::
    trainerbattle_single TRAINER_P_HITOMI, MossdeepCity_Gym_Text_GugumbirIntro, MossdeepCity_Gym_Text_GugumbirDefeated
    msgbox MossdeepCity_Gym_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_single TRAINER_P_LIZA, MossdeepCity_Gym_Text_LizaIntro, MossdeepCity_Gym_Text_LizaDefeat, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	msgbox MossdeepCity_Gym_Text_GugumbirIntro, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	speakername MossdeepCity_Gym_Text_NameLiza
	msgbox MossdeepCity_Gym_Text_LizaPostBattle, MSGBOX_DEFAULT
	msgbox MossdeepCity_Gym_Text_LizaBadge, MSGBOX_DEFAULT
	speakername NULL
	message MossdeepCity_Gym_Text_GotSereneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername MossdeepCity_Gym_Text_NameLiza
	msgbox MossdeepCity_Gym_Text_LizaExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE02_GET
	setvar VAR_PISCES_STORY_PROGRESS, 2
	setvar VAR_0x8008, 2
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	speakername NULL
	warp MAP_MOSSDEEP_CITY, 48, 24
	waitstate
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_REFLECT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_LIGHT_SCREEN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_LizaEnd, MSGBOX_DEFAULT
	return

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PANIC_EVENT, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going, CHAMPION-bound\n"
	.string "{PLAYER}?\p"
	.string "The GYM LEADERS here use\n"
	.string "PSYCHIC-type POKéMON.\p"
	.string "If you go up against them with\n"
	.string "FIGHTING- or POISON-type POKéMON,\l"
	.string "they'll inflict horrible damage!\p"
	.string "Plus, they'll come at you with\n"
	.string "outstanding combination attacks.\p"
	.string "If you want to win, you'll need to show\n"
	.string "them how tight you are with your\l"
	.string "POKéMON. Go for it!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, you're astounding!\n"
	.string "You're one great TRAINER!$"

MossdeepCity_Gym_Text_GugumbirIntro:
	.string "…$"

MossdeepCity_Gym_Text_GugumbirDefeated:
	.string "…$"

MossdeepCity_Gym_Text_GugumbirPostBattle:
	.string "…$"

MossdeepCity_Gym_Text_GugumbirNeedTwoMons:
	.string "need 2 dood$"

MossdeepCity_Gym_Text_NameVoice:
	.string "Voice$"

MossdeepCity_Gym_Text_NameLiza:
	.string "Liza$"

MossdeepCity_Gym_Text_Narrator_1:
	.string "(The atmosphere has become very quiet.\n"
	.string "Through it all, you hear a very calm\l"
	.string "and composed voice in your head.)\p"
	.string "{PLAYER}…\p"
	.string "Centralize your mind, body, and soul…\p"
	.string "Concentrate on the path ahead…\p"
	.string "And take the necessary steps\n"
	.string "toward victory…$"

MossdeepCity_Gym_Text_Narrator_2:
	.string "Be mindful of the wills and struggles\n"
	.string "of your Pokémon…\p"
	.string "One imperfection in a house of cards…\p"
	.string "Can crumble the entire structure…$"

MossdeepCity_Gym_Text_Narrator_3:
	.string "Deep breaths, {PLAYER}…\p"
	.string "You approach an ending…\p"
	.string "Keep focus…\p"
	.string "Every small detail…\n"
	.string "every tough call…\p"
	.string "May affect your future…$"

MossdeepCity_Gym_Text_LizaIntro:
	.string "(There is a girl standing at the end\n"
	.string "of this impossible space.\l"
	.string "You recognize her as Liza,\l"
	.string "the gym leader.)\p"
	.string "(…It is strange that she is solo.)\p"
	.string "(Without a word, Liza\n"
	.string "holds out a Pokéball…)\p"
	.string "(And the bout begins.)$"

MossdeepCity_Gym_Text_LizaDefeat:
	.string "…\p"
	.string "…\p"
	.string "…Oh! I can't hold it in any longer!\p"
	.string "That was fun!\n"
	.string "Congratulations on your victory!$"

MossdeepCity_Gym_Text_LizaPostBattle:
	.string "You know, I AM one of the most attuned\n"
	.string "psychics in Hoenn.\l"
	.string "That was actually me in your head\l"
	.string "back there!\p"
	.string "I could read those questions bouncing\n"
	.string "around in your brain.\p"
	.string "My brother Tate?\p"
	.string "He is on a solitary journey to find a\n"
	.string "unique place in this world.\p"
	.string "While twins share a special connection,\n"
	.string "it is nice and fulfilling to take on\l"
	.string "some goals independent of each other.$"

MossdeepCity_Gym_Text_LizaBadge:
	.string "In the spirit of that, I'll give\n"
	.string "you my gym's badge!$"

MossdeepCity_Gym_Text_GotSereneBadge:
	.string "{PLAYER} has obtained the\n"
	.string "Serene Badge!$"

MossdeepCity_Gym_Text_LizaExplain:
	.string "The Serene Badge allows you to use the\n"
	.string "“Flash” move in the field.\p"
	.string "You have also earned these two TMS;\n"
	.string "use 'em well to set up your\l"
	.string "Pokémon for success!$"

MossdeepCity_Gym_Text_LizaEnd:
	.string "That's all for our time today,\n"
	.string "{PLAYER}.\p"
	.string "I sincerely hope you reach\n"
	.string "an inner peace.$"
