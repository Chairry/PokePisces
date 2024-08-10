TestMap_MapScripts::
	.byte 0

TestMap_EventScript_Mendel::
    trainerbattle_single TRAINER_P_MENDEL, TestMap_Text_MendelIntro, TestMap_Text_MendelDefeated
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    end

TestMap_EventScript_Egg::
	lock
	faceplayer
	playfanfare MUS_OBTAIN_ITEM
	message TestMap_Text_MendelPostBattle
	waitfanfare
	giveegg SPECIES_WANNEGG
	release
	end

TestMap_EventScript_SpeakerNameTest::
    lock
    speakername TestMap_Text_NameJacob
    msgbox TestMap_Text_MendelIntro, MSGBOX_DEFAULT
    speakername NULL
    msgbox TestMap_Text_MendelPostBattle, MSGBOX_AUTOCLOSE
    release
    end

TestMap_EventScript_GymLeader::
	lock
	trainerbattle_two_trainers TRAINER_P_MENDEL, TestMap_Text_MendelIntro, TRAINER_GRUNT_AQUA_HIDEOUT_2, TestMap_Text_MendelDefeated, TestMap_EventScript_Mendel, NO_MUSIC
	release
	end

TestMap_EventScript_ItemBurntBranch::
	finditem ITEM_BURNT_BRANCH
	end

TestMap_EventScript_ItemCursedAmulet::
	finditem ITEM_CURSED_AMULET
	end

TestMap_Text_MendelIntro:
	.string "intro$"

TestMap_Text_MendelDefeated:
	.string "defeat$"

TestMap_Text_MendelPostBattle:
	.string "post$"

TestMap_Text_NameJacob:
	.string "Jacob$"
