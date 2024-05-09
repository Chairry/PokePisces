.set LOCALID_BARRELFISHER, 7

MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_Pearl::
    trainerbattle_single TRAINER_P_PEARL, MtPyre_1F_Text_PearlIntro, MtPyre_1F_Text_PearlDefeated
    msgbox MtPyre_1F_Text_PearlPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_1F_EventScript_Neko::
    trainerbattle_single TRAINER_P_NEKO, MtPyre_1F_Text_NekoIntro, MtPyre_1F_Text_NekoDefeated
    msgbox MtPyre_1F_Text_NekoPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_1F_EventScript_Ayumu::
    trainerbattle_single TRAINER_P_AYUMU, MtPyre_1F_Text_AyumuIntro, MtPyre_1F_Text_AyumuDefeated
    msgbox MtPyre_1F_Text_AyumuPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_1F_EventScript_Reimu::
    trainerbattle_single TRAINER_P_REIMU, MtPyre_1F_Text_ReimuIntro, MtPyre_1F_Text_ReimuDefeated
    msgbox MtPyre_1F_Text_ReimuPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_1F_EventScript_Miko::
    trainerbattle_single TRAINER_P_MIKO, MtPyre_1F_Text_MikoIntro, MtPyre_1F_Text_MikoDefeated
    msgbox MtPyre_1F_Text_MikoPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_1F_EventScript_LostKin::
	lock
	goto_if_set FLAG_ZOTPYRE_PSYCHICS, MtPyre_1F_EventScript_Teleporter
	faceplayer
	setflag FLAG_ZOTPYRE_PSYCHICS
	msgbox MtPyre_1F_Text_IReuniteWithMyKin, MSGBOX_DEFAULT
	goto MtPyre_1F_EventScript_Teleporter
	release
	end

MtPyre_1F_EventScript_Teleporter::
	lock
	faceplayer
	msgbox MtPyre_1F_Text_WouldYouLikeToWarp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MtPyre_1F_EventScript_WarpToCenter
	msgbox MtPyre_1F_Text_MaybeAnotherTime, MSGBOX_AUTOCLOSE
	release
	end

MtPyre_1F_EventScript_WarpToCenter::
	warp MAP_LILYCOVE_CITY_POKEMON_CENTER_2F, 12, 3
	release
	end

MtPyre_1F_EventScript_SpookBarrelCheck::
    lock
	checkitem ITEM_TM_POUNCE
	goto_if_eq VAR_RESULT, TRUE, MtPyre_1F_EventScript_SpookBarrel
	setvar VAR_TEMP_1, 1
	release
	end

MtPyre_1F_EventScript_SpookBarrel::
	clearflag FLAG_RECEIVED_TM_POUNCE
	addobject LOCALID_BARRELFISHER
	applymovement LOCALID_BARRELFISHER, MtPyre_1F_Movement_JumpFromBarrel
	waitmovement 0
	checkitem ITEM_TM_SPOOK
	goto_if_eq VAR_RESULT, TRUE, MtPyre_1F_EventScript_GaveSpook
	msgbox MtPyre_1F_Text_GotYou, MSGBOX_DEFAULT
	giveitem ITEM_TM_SPOOK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_TEMP_1, 1
	setflag FLAG_RECEIVED_TM_POUNCE
	applymovement LOCALID_BARRELFISHER, MtPyre_1F_Movement_JumpIntoBarrel
	waitmovement 0
	release
	end

MtPyre_1F_Movement_JumpFromBarrel:
	set_visible
	jump_left
	face_left
	step_end

MtPyre_1F_Movement_JumpIntoBarrel:
	jump_right
	face_right
	set_invisible
	step_end

MtPyre_1F_EventScript_GaveSpook::
    msgbox MtPyre_1F_Text_AlreadyGotYou, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_1, 1
	setflag FLAG_RECEIVED_TM_POUNCE
	applymovement LOCALID_BARRELFISHER, MtPyre_1F_Movement_JumpIntoBarrel
	waitmovement 0
    release
    end

MtPyre_1F_Text_GotYou:
	.string "BOOGA BOOGA BOOGA!!!\p"
	.string "HAH! I gotcha AGAIN!\n"
	.string "Weren't expectin' the ol' barrel\l"
	.string "fisher in a place like this, huh?\p"
	.string "Hey! Don't be glarin' at me!\n"
	.string "I'll supply ya with another\l"
	.string "TM. This time, for Spook!\p"
	.string "Learning the art of the scare\n"
	.string "may help you avoid me in the future!\p"
	.string "....or maybe not, hehehe!$"

MtPyre_1F_Text_AlreadyGotYou:
	.string "BOOGA...boo...ga...\p"
	.string "Listen bud. We gotta stop\n"
	.string "meeting like this...$"

MtPyre_1F_Text_WouldYouLikeToWarp:
	.string "wanna warp$"

MtPyre_1F_Text_MaybeAnotherTime:
	.string "maybe nexttime$"

MtPyre_1F_Text_IReuniteWithMyKin:
	.string "psychic connection activate$"

MtPyre_1F_Text_PearlIntro:
	.string "intro$"

MtPyre_1F_Text_PearlDefeated:
	.string "defeat$"

MtPyre_1F_Text_PearlPostBattle:
	.string "post$"

MtPyre_1F_Text_NekoIntro:
	.string "intro$"

MtPyre_1F_Text_NekoDefeated:
	.string "defeat$"

MtPyre_1F_Text_NekoPostBattle:
	.string "post$"

MtPyre_1F_Text_AyumuIntro:
	.string "intro$"

MtPyre_1F_Text_AyumuDefeated:
	.string "defeat$"

MtPyre_1F_Text_AyumuPostBattle:
	.string "post$"

MtPyre_1F_Text_ReimuIntro:
	.string "intro$"

MtPyre_1F_Text_ReimuDefeated:
	.string "defeat$"

MtPyre_1F_Text_ReimuPostBattle:
	.string "post$"

MtPyre_1F_Text_MikoIntro:
	.string "intro$"

MtPyre_1F_Text_MikoDefeated:
	.string "defeat$"

MtPyre_1F_Text_MikoPostBattle:
	.string "post$"

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"
