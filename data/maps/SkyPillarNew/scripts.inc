SkyPillarNew_MapScripts::
	.byte 0

SkyPillarNew_EventScript_Granger::
	trainerbattle_single TRAINER_GABRIELLE_1, SkyPillarNew_Text_GrangerIntro, SkyPillarNew_Text_GrangerDefeat
	setflag FLAG_PISCES_A
	goto_if_unset FLAG_PISCES_B, SkyPillarNew_EventScript_GrangerEncouragement
	goto_if_unset FLAG_PISCES_C, SkyPillarNew_EventScript_GrangerEncouragement
	goto_if_set FLAG_PISCES_B, SkyPillarNew_EventScript_GrangerRoadblockOver
	msgbox SkyPillarNew_Text_GrangerPostBattle, MSGBOX_AUTOCLOSE
	end

SkyPillarNew_EventScript_GrangerEncouragement::
	msgbox SkyPillarNew_Text_GrangerEncourage, MSGBOX_NPC
	end

SkyPillarNew_EventScript_GrangerRoadblockOver::
	msgbox SkyPillarNew_Text_GrangerAllDone, MSGBOX_NPC
	setflag FLAG_PACIFIDLOG_ROADBLOCK
	end

SkyPillarNew_EventScript_Ricky::
	trainerbattle_single TRAINER_GRUNT_PETALBURG_WOODS, SkyPillarNew_Text_RickyIntro, SkyPillarNew_Text_RickyDefeat
	setflag FLAG_PISCES_B
	goto_if_unset FLAG_PISCES_A, SkyPillarNew_EventScript_RickyEncouragement
	goto_if_unset FLAG_PISCES_C, SkyPillarNew_EventScript_RickyEncouragement
	goto_if_set FLAG_PISCES_A, SkyPillarNew_EventScript_RickyRoadblockOver
	msgbox SkyPillarNew_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
	end

SkyPillarNew_EventScript_RickyEncouragement::
	msgbox SkyPillarNew_Text_RickyEncourage, MSGBOX_NPC
	end

SkyPillarNew_EventScript_RickyRoadblockOver::
	msgbox SkyPillarNew_Text_RickyAllDone, MSGBOX_NPC
	setflag FLAG_PACIFIDLOG_ROADBLOCK
	end

SkyPillarNew_EventScript_Jeannie::
	trainerbattle_single TRAINER_MARCEL, SkyPillarNew_Text_JeannieIntro, SkyPillarNew_Text_JeannieDefeat
	setflag FLAG_PISCES_C
	goto_if_unset FLAG_PISCES_A, SkyPillarNew_EventScript_JeannieEncouragement
	goto_if_unset FLAG_PISCES_B, SkyPillarNew_EventScript_JeannieEncouragement
	goto_if_set FLAG_PISCES_A, SkyPillarNew_EventScript_JeannieRoadblockOver
	msgbox SkyPillarNew_Text_JeanniePostBattle, MSGBOX_AUTOCLOSE
	end

SkyPillarNew_EventScript_JeannieEncouragement::
	msgbox SkyPillarNew_Text_JeannieEncourage, MSGBOX_NPC
	end

SkyPillarNew_EventScript_JeannieRoadblockOver::
	msgbox SkyPillarNew_Text_JeannieAllDone, MSGBOX_NPC
	setflag FLAG_PACIFIDLOG_ROADBLOCK
	end

SkyPillarNew_Text_GrangerIntro:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_GrangerDefeat:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_GrangerPostBattle:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_GrangerEncourage:
	.string "go kill them others sonny$"

SkyPillarNew_Text_GrangerAllDone:
	.string "ur done now go be merry$"

SkyPillarNew_Text_RickyIntro:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_RickyDefeat:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_RickyPostBattle:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_RickyEncourage:
	.string "go kill them others sonny$"

SkyPillarNew_Text_RickyAllDone:
	.string "ur done now go be merry$"

SkyPillarNew_Text_JeannieIntro:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_JeannieDefeat:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_JeanniePostBattle:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_JeannieEncourage:
	.string "go kill them others sonny$"

SkyPillarNew_Text_JeannieAllDone:
	.string "ur done now go be merry$"


