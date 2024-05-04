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
