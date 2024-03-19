.set LOCALID_STUDENT, 27

BasalinCoast_MapScripts::
	.byte 0

BasalinCoast_EventScript_Beatrice::
    trainerbattle_single TRAINER_P_BEATRICE, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Nancy::
    trainerbattle_single TRAINER_P_NANCY, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Sadie::
    trainerbattle_single TRAINER_P_SADIE, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Melanie::
    trainerbattle_single TRAINER_P_MELANIE, BasalinCoast_Text_MelanieIntro, BasalinCoast_Text_MelanieDefeated
    msgbox BasalinCoast_Text_MelaniePostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Timmy::
    trainerbattle_single TRAINER_P_TIMMY, BasalinCoast_Text_TimmyIntro, BasalinCoast_Text_TimmyDefeated
    msgbox BasalinCoast_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Wadelle::
    trainerbattle_single TRAINER_P_WADELLE, BasalinCoast_Text_CatIntro, BasalinCoast_Text_CatDefeated
    msgbox BasalinCoast_Text_CatPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Yanny::
    trainerbattle_single TRAINER_P_YANNY, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Remy::
    trainerbattle_single TRAINER_P_REMY, BasalinCoast_Text_GugumbirIntro, BasalinCoast_Text_GugumbirDefeated
    msgbox BasalinCoast_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

BasalinCoast_EventScript_Selko::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SEASHELL_4, BasalinCoast_EventScript_SelkoGivenShell
    msgbox BasalinCoast_Text_WantMySeashell, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BasalinCoast_EventScript_BattleSelko
	goto_if_eq VAR_RESULT, NO, BasalinCoast_EventScript_AreYaSure
	end

BasalinCoast_EventScript_BattleSelko::
	trainerbattle_single TRAINER_P_SELKO, BasalinCoast_Text_SelkoIntro, BasalinCoast_Text_SelkoDefeated, BasalinCoast_EventScript_GiveSelkoShell
	release
	end

BasalinCoast_EventScript_GiveSelkoShell::
	msgbox BasalinCoast_Text_YouEarnedThisShell, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SHELL
	setflag FLAG_RECEIVED_SEASHELL_4
	release
	end

BasalinCoast_EventScript_AreYaSure::
	msgbox BasalinCoast_Text_AreYaSure, MSGBOX_DEFAULT
	release
	end

BasalinCoast_EventScript_SelkoGivenShell::
	msgbox BasalinCoast_Text_SelkoPostBattle, MSGBOX_NPC
	end

BasalinCoast_EventScript_ShedShellKid::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SHED_SHELL, BasalinCoast_EventScript_GaveShedShell
	msgbox BasalinCoast_Text_HaveShedShell, MSGBOX_DEFAULT
	giveitem ITEM_SHED_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SHED_SHELL
	release
	end

BasalinCoast_EventScript_GaveShedShell::
    msgbox BasalinCoast_Text_GaveShedShell, MSGBOX_AUTOCLOSE
    release
    end

BasalinCoast_EventScript_SeaShellGiver::
    lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SEASHELL_3, BasalinCoast_EventScript_GaveSeashellAlr
	msgbox BasalinCoast_Text_HaveMyShell, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SEASHELL_3
	release
	end

BasalinCoast_EventScript_GaveSeashellAlr::
    msgbox BasalinCoast_Text_GaveSeashellAlr, MSGBOX_AUTOCLOSE
    release
    end

BasalinCoast_EventScript_BluePKMNCenters1::
    lock
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentMeet1
    waitmovement 0
    msgbox BasalinCoast_Text_ILikeRouteCenters, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentTakeYou1
    applymovement OBJ_EVENT_ID_PLAYER, BasalinCoast_Movement_PlayerTakeYou1
    waitmovement 0
    msgbox BasalinCoast_Text_ExplainRouteCenters, MSGBOX_DEFAULT
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentLeaves
    setvar VAR_BALL_QUEST_STATE, 0
    clearflag FLAG_HIDE_BIRCH_AFTER_STARTER
    waitmovement 0
    setflag FLAG_HIDE_LAB_RANGERS
    release
    end

BasalinCoast_Movement_StudentMeet1:
    walk_down
    walk_down
    walk_down
    walk_left
    walk_down
    walk_down
    step_end

BasalinCoast_Movement_StudentTakeYou1:
    walk_up
    walk_up
    walk_right
    walk_up
    walk_up
    face_down
    step_end

BasalinCoast_Movement_PlayerTakeYou1:
    walk_up
    walk_up
    walk_up
    walk_right
    walk_up
    step_end

BasalinCoast_Movement_StudentLeaves:
    walk_right
    walk_right
    walk_right
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    step_end

BasalinCoast_EventScript_BluePKMNCenters2::
    lock
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentMeet2
    waitmovement 0
    msgbox BasalinCoast_Text_ILikeRouteCenters, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentTakeYou2
    applymovement OBJ_EVENT_ID_PLAYER, BasalinCoast_Movement_PlayerTakeYou2
    waitmovement 0
    msgbox BasalinCoast_Text_ExplainRouteCenters, MSGBOX_DEFAULT
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentLeaves
    setvar VAR_BALL_QUEST_STATE, 0
    clearflag FLAG_HIDE_BIRCH_AFTER_STARTER
    waitmovement 0
    setflag FLAG_HIDE_LAB_RANGERS
    release
    end

BasalinCoast_Movement_StudentMeet2:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

BasalinCoast_Movement_StudentTakeYou2:
    walk_up
    walk_up
    walk_up
    walk_up
    face_down
    step_end

BasalinCoast_Movement_PlayerTakeYou2:
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

BasalinCoast_EventScript_BluePKMNCenters3::
    lock
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentMeet3
    waitmovement 0
    msgbox BasalinCoast_Text_ILikeRouteCenters, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentTakeYou3
    applymovement OBJ_EVENT_ID_PLAYER, BasalinCoast_Movement_PlayerTakeYou3
    waitmovement 0
    msgbox BasalinCoast_Text_ExplainRouteCenters, MSGBOX_DEFAULT
    applymovement LOCALID_STUDENT, BasalinCoast_Movement_StudentLeaves
    setvar VAR_BALL_QUEST_STATE, 0
    clearflag FLAG_HIDE_BIRCH_AFTER_STARTER
    waitmovement 0
    setflag FLAG_HIDE_LAB_RANGERS
    release
    end

BasalinCoast_Movement_StudentMeet3:
    walk_down
    walk_down
    walk_down
    walk_right
    walk_down
    walk_down
    step_end

BasalinCoast_Movement_StudentTakeYou3:
    walk_up
    walk_up
    walk_left
    walk_up
    walk_up
    face_down
    step_end

BasalinCoast_Movement_PlayerTakeYou3:
    walk_up
    walk_up
    walk_up
    walk_left
    walk_up
    step_end

BasalinCoast_Text_GugumbirIntro:
	.string "intro$"

BasalinCoast_Text_GugumbirDefeated:
	.string "defeat$"

BasalinCoast_Text_GugumbirPostBattle:
	.string "post$"

BasalinCoast_Text_MelanieIntro:
	.string "Have you found a Fluffsir? I can't\n"
    .string "find one! Hand it over!$"

BasalinCoast_Text_MelanieDefeated:
	.string "Alright! I'll back off!$"

BasalinCoast_Text_MelaniePostBattle:
	.string "Watch out on the stairs… I tumbled\n"
    .string "down 'em once. It really hurt!$"

BasalinCoast_Text_TimmyIntro:
	.string "I'm just your average kid… that no one\n"
    .string "understands!$"

BasalinCoast_Text_TimmyDefeated:
	.string "You're such an odd trainer!\n"
    .string "Fairly odd trainer!$"

BasalinCoast_Text_TimmyPostBattle:
	.string "I should shop for a new hat.\n"
    .string "I'm thinking pink!$"

BasalinCoast_Text_CatIntro:
	.string "My mother always told me there'd be\n"
    .string "days like this…$"

BasalinCoast_Text_CatDefeated:
	.string "Express elevator going\n"
    .string "doooooown…!$"

BasalinCoast_Text_CatPostBattle:
	.string "How could a Cat have such a\n"
    .string "dog of a day…?$"

BasalinCoast_Text_WantMySeashell:
    .string "Hee-hee-hee...\p"
    .string "I can tell you're lookin' for shells.\n"
    .string "Wanna try takin' mine?$"

BasalinCoast_Text_SelkoIntro:
	.string "Hah-hah-hah!\n"
    .string "I've caught you! You want my shell?\l"
    .string "You're gonna have to get through...\l"
    .string "THIS!$"

BasalinCoast_Text_SelkoDefeated:
	.string "I didn't expect THAT!$"

BasalinCoast_Text_YouEarnedThisShell:
    .string "Yeah, yeah... take it.$"

BasalinCoast_Text_AreYaSure:
    .string "Are you suuuuuuuuure?$"

BasalinCoast_Text_SelkoPostBattle:
    .string "Look, I take shell collecting VERY\n"
    .string "seriously. Please treat that\l"
    .string "shell with care.$"

BasalinCoast_Text_HaveShedShell:
    .string "I hear some peeps have been looking\n"
    .string "for shells to make into a Shell Bell.\p"
    .string "Well, my bug Pokémon leave behind\n"
    .string "a lot of those!\p"
    .string "Here; you can take one.$"

BasalinCoast_Text_GaveShedShell:
    .string "Y'know, I AM a bit confused as to how\n"
    .string "that's gonna make a good bell…$"

BasalinCoast_Text_HaveMyShell:
    .string "(This boy is skipping the water with a\n"
    .string "seashell you might need.)\p"
    .string "Hey there! Bet you can't skip this\n"
    .string "shell further'n me!\p"
    .string "(You take the shell and swap it with\n"
    .string "a rock while he isn't looking.\l"
    .string "Then, you let it rip. It goes dozens\l"
    .string "of meters into the ocean.)\p"
    .string "WOAH! You're strong!$"

BasalinCoast_Text_GaveSeashellAlr:
    .string "I'm gonna go dive and snatch that\n"
    .string "shell back later.$"

BasalinCoast_Text_ILikeRouteCenters:
    .string "I like peanuts without the t$"

BasalinCoast_Text_ExplainRouteCenters:
    .string "looky looky blue roof$"
