.set LOCALID_BREAD, 1
.set LOCALID_FUZKY, 13
.set LOCALID_SNOWNINJA, 14

Route123_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
	.byte 0

Route123_OnTransition:
	call_if_gt VAR_BREADWINNER_STATE, 1, Route123_EventScript_SetTempFlags
	end

Route123_EventScript_SetTempFlags::
	setflag FLAG_TEMP_11
	removeobject LOCALID_BREAD
	setflag FLAG_TEMP_16
	removeobject LOCALID_SNOWNINJA
	return

Route123_EventScript_BreadPos1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route123_Movement_PlayerMoveIntoPos1
	waitmovement 0
	goto Route123_EventScript_BreadwinnerEncounter
	release
	end

Route123_Movement_PlayerMoveIntoPos1:
	walk_right
	face_up
	step_end

Route123_EventScript_BreadPos2::
	lock
	goto Route123_EventScript_BreadwinnerEncounter
	release
	end

Route123_EventScript_BreadwinnerEncounter::
	lock
	speakername Route123_Text_NamePandou
	applymovement OBJ_EVENT_ID_PLAYER, Route123_Movement_PlayerWalkUpStairs
	applymovement LOCALID_BREAD, Route123_Movement_BreadEnc
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_BREAD, Route123_Movement_BreadBackUp
	waitmovement 0
	trainerbattle_single TRAINER_P_PANDOU_2, Route123_Text_BreadwinnerIntro, Route123_Text_BreadwinnerDefeat, Route123_EventScript_BreadRun
	speakername NULL
	release
	end

Route123_Movement_PlayerWalkUpStairs:
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route123_Movement_BreadEnc:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route123_Movement_BreadBackUp:
	walk_right
	face_left
	step_end

Route123_EventScript_BreadRun::
	setvar VAR_BREADWINNER_STATE, 2
	speakername Route123_Text_NamePandou
	msgbox Route123_Text_BreadwinnerRunAway, MSGBOX_DEFAULT
	closemessage
	playse SE_FLEE
	applymovement LOCALID_BREAD, Route123_Movement_BreadEscape
	waitmovement 0
	speakername NULL
	msgbox Route123_Text_ProtectTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_PROTECT
	setflag FLAG_TEMP_11
	removeobject LOCALID_BREAD
	release
	end

Route123_Movement_BreadEscape:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route123_EventScript_Rami::
    trainerbattle_single TRAINER_P_RAMI, Route123_Text_RamiIntro, Route123_Text_RamiDefeated
    msgbox Route123_Text_RamiPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Tsunami::
    trainerbattle_single TRAINER_P_TSUNAMI, Route123_Text_TsunamiIntro, Route123_Text_TsunamiDefeated
    msgbox Route123_Text_TsunamiPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Jinxie::
    trainerbattle_single TRAINER_P_JINXIE, Route123_Text_JinxieIntro, Route123_Text_JinxieDefeated
    msgbox Route123_Text_JinxiePostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Carolina::
    trainerbattle_single TRAINER_P_CAROLINA, Route123_Text_CarolinaIntro, Route123_Text_CarolinaDefeated
    msgbox Route123_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Betty::
    trainerbattle_single TRAINER_P_BETTY, Route123_Text_BettyIntro, Route123_Text_BettyDefeated
    msgbox Route123_Text_BettyPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Hazakura::
    trainerbattle_single TRAINER_P_HAZAKURA, Route123_Text_HazakuraIntro, Route123_Text_HazakuraDefeated
    msgbox Route123_Text_HazakuraPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Mia::
    trainerbattle_single TRAINER_P_MIA, Route123_Text_MiaIntro, Route123_Text_MiaDefeated
    msgbox Route123_Text_MiaPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Maya::
    trainerbattle_single TRAINER_P_MAYA, Route123_Text_MayaIntro, Route123_Text_MayaDefeated
    msgbox Route123_Text_MayaPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Kumori::
    trainerbattle_single TRAINER_P_KUMORI, Route123_Text_KumoriIntro, Route123_Text_KumoriDefeated
    msgbox Route123_Text_KumoriPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Hoth::
    trainerbattle_single TRAINER_P_HOTH, Route123_Text_HothIntro, Route123_Text_HothDefeated
    msgbox Route123_Text_HothPostBattle, MSGBOX_AUTOCLOSE
    end

Route123_EventScript_Gravestone1::
	lock
	goto_if_ge VAR_GRAVE_QUEST_STATE, 3, Route123_EventScript_KeepMoving
	goto_if_set FLAG_TEMP_13, Route123_EventScript_KeepMoving
	msgbox Route123_Text_WantToPayRespects1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route123_EventScript_Grave1Respects
	release
	end

Route123_EventScript_Grave1Respects::
	msgbox Route123_Text_YouFoldYourHands, MSGBOX_AUTOCLOSE
	fadeoutbgm 1
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	fadeinbgm 1
	addvar VAR_GRAVE_QUEST_STATE, 1
	setflag FLAG_TEMP_13
	msgbox Route123_Text_MayTheyRestInPeace, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_GRAVE_QUEST_STATE, 3, Route123_EventScript_BindingBand
	release
	end

Route123_EventScript_KeepMoving::
	msgbox Route123_Text_GottaKeepMoving, MSGBOX_AUTOCLOSE
	release
	end

Route123_EventScript_Gravestone2::
	lock
	goto_if_ge VAR_GRAVE_QUEST_STATE, 3, Route123_EventScript_KeepMoving
	goto_if_set FLAG_TEMP_14, Route123_EventScript_KeepMoving
	msgbox Route123_Text_WantToPayRespects2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route123_EventScript_Grave2Respects
	release
	end

Route123_EventScript_Grave2Respects::
	msgbox Route123_Text_YouFoldYourHands, MSGBOX_AUTOCLOSE
	fadeoutbgm 1
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	fadeinbgm 1
	addvar VAR_GRAVE_QUEST_STATE, 1
	setflag FLAG_TEMP_14
	msgbox Route123_Text_MayTheyRestInPeace, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_GRAVE_QUEST_STATE, 3, Route123_EventScript_BindingBand
	release
	end

Route123_EventScript_Gravestone3::
	lock
	goto_if_ge VAR_GRAVE_QUEST_STATE, 3, Route123_EventScript_KeepMoving
	goto_if_set FLAG_TEMP_15, Route123_EventScript_KeepMoving
	msgbox Route123_Text_WantToPayRespects3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route123_EventScript_Grave3Respects
	release
	end

Route123_EventScript_Grave3Respects::
	msgbox Route123_Text_YouFoldYourHands, MSGBOX_AUTOCLOSE
	fadeoutbgm 1
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	delay 60
	fadeinbgm 1
	addvar VAR_GRAVE_QUEST_STATE, 1
	setflag FLAG_TEMP_15
	msgbox Route123_Text_MayTheyRestInPeace, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_GRAVE_QUEST_STATE, 3, Route123_EventScript_BindingBand
	release
	end

Route123_EventScript_BindingBand::
	msgbox Route123_Text_TheresSomethingOnYourWrist, MSGBOX_DEFAULT
	giveitem ITEM_BINDING_BAND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route123_Text_TheEngravingSays, MSGBOX_AUTOCLOSE
	release
	end

Route123_EventScript_LureFuzky::
	lock
	msgbox Route123_Text_TheresAnOddFuzky, MSGBOX_DEFAULT
	checkitem ITEM_WEIRD_STICK
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_WantToThrowStick
	release
	end

Route123_EventScript_WantToThrowStick::
	msgbox Route123_Text_WantToThrowStick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route123_EventScript_FuzkyBattle
	release
	end

Route123_EventScript_FuzkyBattle::
	removeitem ITEM_WEIRD_STICK, 1
	msgbox Route123_Text_YouThrowTheStick, MSGBOX_DEFAULT
	applymovement LOCALID_FUZKY, Route123_Movement_FuzkyAttacks
	waitmovement 0
	setwildbattle SPECIES_FUZKY, 26
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 3, 1, 2, 3, 2
	playmoncry SPECIES_FUZKY, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox Route123_Text_TheFuzkyWantsToBattle, MSGBOX_DEFAULT
	dowildbattle
	goto Route123_EventScript_FuzkyDefeat
	release
	end

Route123_Movement_FuzkyAttacks:
	walk_fast_right
	walk_fast_up
	jump_up
	step_end

Route123_EventScript_FuzkyDefeat::
	msgbox Route123_Text_ItTakesOffTheMantle, MSGBOX_DEFAULT
	giveitem ITEM_LOST_MANTLE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	applymovement LOCALID_FUZKY, Route123_Movement_FuzkyRunAway
	waitmovement 0
	setflag FLAG_TEMP_17
	removeobject LOCALID_FUZKY
	release
	end

Route123_Movement_FuzkyRunAway:
	jump_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	jump_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route123_EventScript_SnowNinjaTrigger::
	lock
	setvar VAR_TEMP_5, 1
	goto_if_set FLAG_SNOWBALL_BOY, Route123_EventScript_SnowNinja
	release
	end

Route123_EventScript_SnowNinja::
	clearflag FLAG_TEMP_16
	addobject LOCALID_SNOWNINJA
	delay 16
	applymovement LOCALID_SNOWNINJA, Route123_Movement_Ambush
	waitmovement 0
	trainerbattle_single TRAINER_P_HAZAKURA, Route123_Text_HazakuraIntro, Route123_Text_HazakuraDefeated, Route123_EventScript_SmokeBall
	release
	end

Route123_Movement_Ambush:
	jump_right
	face_up
	step_end

Route123_EventScript_SmokeBall::
	lock
	msgbox Route123_Text_BackToTheSnow, MSGBOX_DEFAULT
	applymovement LOCALID_SNOWNINJA, Route123_Movement_BackToTheSnow
	waitmovement 0
	setflag FLAG_TEMP_16
	removeobject LOCALID_SNOWNINJA
	msgbox Route123_Text_HeLeftBehindSomething, MSGBOX_DEFAULT
	giveitem ITEM_SMOKE_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

Route123_Movement_BackToTheSnow:
	jump_left
	step_end

Route123_Text_BackToTheSnow:
	.string "Even after plotting my revenge over a\n"
	.string "painstaking 20 minutes…\l"
	.string "I lose…\p"

Route123_Text_HeLeftBehindSomething:
	.string "(The boy disappears,\n"
	.string "leaving behind an item.)$"

Route123_Text_WantToPayRespects1:
	.string "(Would you like to take a moment of\n"
	.string "silence to respect the dead?)$"

Route123_Text_WantToPayRespects2:
	.string "(Would you like to pay respects\n"
	.string "again here?)$"

Route123_Text_WantToPayRespects3:
	.string "(It's another epitaph.\n"
	.string "Pay respects again?)$"

Route123_Text_YouFoldYourHands:
	.string "…$"

Route123_Text_MayTheyRestInPeace:
	.string "(May they rest in peace.)$"

Route123_Text_GottaKeepMoving:
	.string "lets get goin$"

Route123_Text_TheresSomethingOnYourWrist:
	.string "(After your prayer, you look down to\n"
	.string "your wrist to find that there is\l"
	.string "a band around it.)$"

Route123_Text_TheEngravingSays:
	.string "(It's engraved…)\p"
	.string "OUR GRATITUDE$"

Route123_Text_TheresAnOddFuzky:
	.string "(You can see a Fuzky pacing around\n"
	.string "in the area that you can't reach.)\p"
	.string "(It is wearing a red hood.)$"

Route123_Text_WantToThrowStick:
	.string "(You have a Stick in your inventory.\n"
	.string "Throw the Stick?)$"

Route123_Text_YouThrowTheStick:
	.string "(You toss the stick in front\n"
	.string "of you in an attempt to lure over\l"
	.string "the odd Pokemon.)$"

Route123_Text_TheFuzkyWantsToBattle:
	.string "(The Fuzky is attacking!)$"

Route123_Text_ItTakesOffTheMantle:
	.string "(The Fuzky, beaten, drops the\n"
	.string "red hood it was wearing.)$"

Route123_Text_RamiIntro:
	.string "intro$"

Route123_Text_RamiDefeated:
	.string "defeat$"

Route123_Text_RamiPostBattle:
	.string "post$"

Route123_Text_TsunamiIntro:
	.string "intro$"

Route123_Text_TsunamiDefeated:
	.string "defeat$"

Route123_Text_TsunamiPostBattle:
	.string "post$"

Route123_Text_JinxieIntro:
	.string "intro$"

Route123_Text_JinxieDefeated:
	.string "defeat$"

Route123_Text_JinxiePostBattle:
	.string "post$"

Route123_Text_CarolinaIntro:
	.string "intro$"

Route123_Text_CarolinaDefeated:
	.string "defeat$"

Route123_Text_CarolinaPostBattle:
	.string "post$"

Route123_Text_BettyIntro:
	.string "intro$"

Route123_Text_BettyDefeated:
	.string "defeat$"

Route123_Text_BettyPostBattle:
	.string "post$"

Route123_Text_HazakuraIntro:
	.string "Your guard was down, and I strike!\n"
	.string "This'll teach you not to mess with me!$"

Route123_Text_HazakuraDefeated:
	.string "Buried in the snow once more…!$"

Route123_Text_HazakuraPostBattle:
	.string "post$"

Route123_Text_MiaIntro:
	.string "intro$"

Route123_Text_MiaDefeated:
	.string "defeat$"

Route123_Text_MiaPostBattle:
	.string "post$"

Route123_Text_MayaIntro:
	.string "intro$"

Route123_Text_MayaDefeated:
	.string "defeat$"

Route123_Text_MayaPostBattle:
	.string "post$"

Route123_Text_KumoriIntro:
	.string "intro$"

Route123_Text_KumoriDefeated:
	.string "defeat$"

Route123_Text_KumoriPostBattle:
	.string "post$"

Route123_Text_HothIntro:
	.string "intro$"

Route123_Text_HothDefeated:
	.string "defeat$"

Route123_Text_HothPostBattle:
	.string "post$"

Route123_Text_NamePandou:
	.string "Pandou$"

Route123_Text_BreadwinnerIntro:
	.string "Many p-p-pardons!\p"
	.string "This c-c-cold is so b-bitter,\n"
	.string "it's d-d-dulling my senses…!\l"
	.string "Not t-to mention, my g-g-glasses\l"
	.string "are fogging right up!\p"
	.string "…\p"
	.string "…What!?\n"
	.string "B-b-b-battle!?\l"
	.string "Now!?\l"
	.string "That's prepostero-$"

Route123_Text_BreadwinnerDefeat:
	.string "I can BARELY even s-s-see!$"

Route123_Text_BreadwinnerRunAway:
	.string "(Pandou rummages through his briefcase\n"
	.string "to find a glasses wipe.)\p"
	.string "YOU!? Golly… you're s-s-super\n"
	.string "b-battle hungry!\p"
	.string "D-do you have it out for me or\n"
	.string "s-s-something…?\p"
	.string "Jeez Louise…\n"
	.string "I'm way p-p-past schedule!\l"
	.string "I g-gotta make up some t-t-time!$"

Route123_Text_ProtectTM:
	.string "(He seems to have dropped something.)$"
