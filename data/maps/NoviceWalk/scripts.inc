NoviceWalk_MapScripts::
	.byte 0

NoviceWalk_EventScript_Joey::
    trainerbattle_single TRAINER_P_JOEY, NoviceWalk_Text_JoeyIntro, NoviceWalk_Text_JoeyDefeated
    msgbox NoviceWalk_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Josephine::
    trainerbattle_single TRAINER_P_JOSEPHINE, NoviceWalk_Text_JosephineIntro, NoviceWalk_Text_JosephineDefeated
    msgbox NoviceWalk_Text_JosephinePostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Lenny::
    trainerbattle_single TRAINER_P_LENNY, NoviceWalk_Text_LennyIntro, NoviceWalk_Text_LennyDefeated
    msgbox NoviceWalk_Text_LennyPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Bridget::
    trainerbattle_single TRAINER_P_BRIDGET, NoviceWalk_Text_BridgetIntro, NoviceWalk_Text_BridgetDefeated
    msgbox NoviceWalk_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Darwin::
    trainerbattle_single TRAINER_P_DARWIN, NoviceWalk_Text_DarwinIntro, NoviceWalk_Text_DarwinDefeated
    msgbox NoviceWalk_Text_DarwinPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Gumball::
    trainerbattle_single TRAINER_P_GUMBALL, NoviceWalk_Text_GumballIntro, NoviceWalk_Text_GumballDefeated
    msgbox NoviceWalk_Text_GumballPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Jimmy::
    trainerbattle_single TRAINER_P_JIMMY_2, NoviceWalk_Text_JimmyIntro, NoviceWalk_Text_JimmyDefeated
    msgbox NoviceWalk_Text_JimmyPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Timmy::
    trainerbattle_single TRAINER_P_TIMMY_2, NoviceWalk_Text_TimmyIntro, NoviceWalk_Text_TimmyDefeated
    msgbox NoviceWalk_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Joe::
    trainerbattle_single TRAINER_P_JOE, NoviceWalk_Text_JoeIntro, NoviceWalk_Text_JoeDefeated
    msgbox NoviceWalk_Text_JoePostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Sasha::
    trainerbattle_single TRAINER_P_SASHA, NoviceWalk_Text_SashaIntro, NoviceWalk_Text_SashaDefeated
    msgbox NoviceWalk_Text_SashaPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Elle::
    trainerbattle_single TRAINER_P_ELLE, NoviceWalk_Text_ElleIntro, NoviceWalk_Text_ElleDefeated
    msgbox NoviceWalk_Text_EllePostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_Tay::
    trainerbattle_single TRAINER_P_TAY, NoviceWalk_Text_TayIntro, NoviceWalk_Text_TayDefeated
    msgbox NoviceWalk_Text_TayPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_EventScript_EthanAndKai::
    trainerbattle_double TRAINER_P_ETHAN_AND_KAI, NoviceWalk_Text_EthanAndKaiIntro, NoviceWalk_Text_EthanAndKaiDefeated, NoviceWalk_Text_EthanAndKaiNeedTwoMons
    msgbox NoviceWalk_Text_EthanAndKaiPostBattle, MSGBOX_AUTOCLOSE
    end

NoviceWalk_Text_JoeyIntro:
	.string "intro$"

NoviceWalk_Text_JoeyDefeated:
	.string "defeat$"

NoviceWalk_Text_JoeyPostBattle:
	.string "post$"

NoviceWalk_Text_JosephineIntro:
	.string "intro$"

NoviceWalk_Text_JosephineDefeated:
	.string "defeat$"

NoviceWalk_Text_JosephinePostBattle:
	.string "post$"

NoviceWalk_Text_LennyIntro:
	.string "intro$"

NoviceWalk_Text_LennyDefeated:
	.string "defeat$"

NoviceWalk_Text_LennyPostBattle:
	.string "post$"

NoviceWalk_Text_BridgetIntro:
	.string "intro$"

NoviceWalk_Text_BridgetDefeated:
	.string "defeat$"

NoviceWalk_Text_BridgetPostBattle:
	.string "post$"

NoviceWalk_Text_DarwinIntro:
	.string "intro$"

NoviceWalk_Text_DarwinDefeated:
	.string "defeat$"

NoviceWalk_Text_DarwinPostBattle:
	.string "post$"

NoviceWalk_Text_GumballIntro:
	.string "intro$"

NoviceWalk_Text_GumballDefeated:
	.string "defeat$"

NoviceWalk_Text_GumballPostBattle:
	.string "post$"

NoviceWalk_Text_JimmyIntro:
	.string "intro$"

NoviceWalk_Text_JimmyDefeated:
	.string "defeat$"

NoviceWalk_Text_JimmyPostBattle:
	.string "post$"

NoviceWalk_Text_TimmyIntro:
	.string "intro$"

NoviceWalk_Text_TimmyDefeated:
	.string "defeat$"

NoviceWalk_Text_TimmyPostBattle:
	.string "post$"

NoviceWalk_Text_JoeIntro:
	.string "intro$"

NoviceWalk_Text_JoeDefeated:
	.string "defeat$"

NoviceWalk_Text_JoePostBattle:
	.string "post$"

NoviceWalk_Text_SashaIntro:
	.string "intro$"

NoviceWalk_Text_SashaDefeated:
	.string "defeat$"

NoviceWalk_Text_SashaPostBattle:
	.string "post$"

NoviceWalk_Text_ElleIntro:
	.string "intro$"

NoviceWalk_Text_ElleDefeated:
	.string "defeat$"

NoviceWalk_Text_EllePostBattle:
	.string "post$"

NoviceWalk_Text_TayIntro:
	.string "intro$"

NoviceWalk_Text_TayDefeated:
	.string "defeat$"

NoviceWalk_Text_TayPostBattle:
	.string "post$"

NoviceWalk_Text_EthanAndKaiIntro:
	.string "intro$"

NoviceWalk_Text_EthanAndKaiDefeated:
	.string "defeat$"

NoviceWalk_Text_EthanAndKaiPostBattle:
	.string "post$"

NoviceWalk_Text_EthanAndKaiNeedTwoMons:
	.string "need 2 dood$"
