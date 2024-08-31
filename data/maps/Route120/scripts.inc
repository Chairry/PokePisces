Route120_MapScripts::
	.byte 0

Route120_EventScript_Colby::
    trainerbattle_single TRAINER_P_COLBY, Route120_Text_ColbyIntro, Route120_Text_ColbyDefeated
    msgbox Route120_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_KatAndAna::
    trainerbattle_double TRAINER_P_KAT_AND_ANA, Route120_Text_KatAndAnaIntro, Route120_Text_KatAndAnaDefeated, Route120_Text_KatAndAnaNeedTwoMons
    msgbox Route120_Text_KatAndAnaPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Thatcher::
    trainerbattle_single TRAINER_P_THATCHER, Route120_Text_ThatcherIntro, Route120_Text_ThatcherDefeated
    msgbox Route120_Text_ThatcherPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Cherie::
    trainerbattle_single TRAINER_P_CHERIE, Route120_Text_CherieIntro, Route120_Text_CherieDefeated
    msgbox Route120_Text_CheriePostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Finn::
    trainerbattle_single TRAINER_P_FINN, Route120_Text_FinnIntro, Route120_Text_FinnDefeated
    msgbox Route120_Text_FinnPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Junie::
    trainerbattle_single TRAINER_P_JUNIE, Route120_Text_JunieIntro, Route120_Text_JunieDefeated
    msgbox Route120_Text_JuniePostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Kiwi::
    trainerbattle_single TRAINER_P_KIWI, Route120_Text_KiwiIntro, Route120_Text_KiwiDefeated
    msgbox Route120_Text_KiwiPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_JimBob::
    trainerbattle_single TRAINER_P_JIM_BOB, Route120_Text_JimBobIntro, Route120_Text_JimBobDefeated
    msgbox Route120_Text_JimBobPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_MaddyAndCross::
    trainerbattle_double TRAINER_P_MADDY_AND_CROSS, Route120_Text_MaddyAndCrossIntro, Route120_Text_MaddyAndCrossDefeated, Route120_Text_MaddyAndCrossNeedTwoMons
    msgbox Route120_Text_MaddyAndCrossPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Hector::
    trainerbattle_single TRAINER_P_HECTOR, Route120_Text_HectorIntro, Route120_Text_HectorDefeated
    msgbox Route120_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Patrasche::
    trainerbattle_single TRAINER_P_PATRASCHE, Route120_Text_PatrascheIntro, Route120_Text_PatrascheDefeated
    msgbox Route120_Text_PatraschePostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Amira::
    trainerbattle_single TRAINER_P_AMIRA, Route120_Text_AmiraIntro, Route120_Text_AmiraDefeated
    msgbox Route120_Text_AmiraPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_EventScript_Leilei::
    trainerbattle_single TRAINER_P_LEILEI, Route120_Text_LeileiIntro, Route120_Text_LeileiDefeated
    msgbox Route120_Text_LeileiPostBattle, MSGBOX_AUTOCLOSE
    end

Route120_Text_ColbyIntro:
	.string "intro$"

Route120_Text_ColbyDefeated:
	.string "defeat$"

Route120_Text_ColbyPostBattle:
	.string "post$"

Route120_Text_KatAndAnaIntro:
	.string "intro$"

Route120_Text_KatAndAnaDefeated:
	.string "defeat$"

Route120_Text_KatAndAnaPostBattle:
	.string "post$"

Route120_Text_KatAndAnaNeedTwoMons:
	.string "need 2 dood$"

Route120_Text_ThatcherIntro:
	.string "intro$"

Route120_Text_ThatcherDefeated:
	.string "defeat$"

Route120_Text_ThatcherPostBattle:
	.string "post$"

Route120_Text_CherieIntro:
	.string "intro$"

Route120_Text_CherieDefeated:
	.string "defeat$"

Route120_Text_CheriePostBattle:
	.string "post$"

Route120_Text_FinnIntro:
	.string "intro$"

Route120_Text_FinnDefeated:
	.string "defeat$"

Route120_Text_FinnPostBattle:
	.string "post$"

Route120_Text_JunieIntro:
	.string "intro$"

Route120_Text_JunieDefeated:
	.string "defeat$"

Route120_Text_JuniePostBattle:
	.string "post$"

Route120_Text_KiwiIntro:
	.string "intro$"

Route120_Text_KiwiDefeated:
	.string "defeat$"

Route120_Text_KiwiPostBattle:
	.string "post$"

Route120_Text_JimBobIntro:
	.string "intro$"

Route120_Text_JimBobDefeated:
	.string "defeat$"

Route120_Text_JimBobPostBattle:
	.string "post$"

Route120_Text_MaddyAndCrossIntro:
	.string "intro$"

Route120_Text_MaddyAndCrossDefeated:
	.string "defeat$"

Route120_Text_MaddyAndCrossPostBattle:
	.string "post$"

Route120_Text_MaddyAndCrossNeedTwoMons:
	.string "need 2 dood$"

Route120_Text_HectorIntro:
	.string "intro$"

Route120_Text_HectorDefeated:
	.string "defeat$"

Route120_Text_HectorPostBattle:
	.string "post$"

Route120_Text_PatrascheIntro:
	.string "intro$"

Route120_Text_PatrascheDefeated:
	.string "defeat$"

Route120_Text_PatraschePostBattle:
	.string "post$"

Route120_Text_AmiraIntro:
	.string "intro$"

Route120_Text_AmiraDefeated:
	.string "defeat$"

Route120_Text_AmiraPostBattle:
	.string "post$"

Route120_Text_LeileiIntro:
	.string "intro$"

Route120_Text_LeileiDefeated:
	.string "defeat$"

Route120_Text_LeileiPostBattle:
	.string "post$"
