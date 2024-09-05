RustburgWharf_MapScripts::
	.byte 0

RustburgWharf_EventScript_Britney::
    trainerbattle_single TRAINER_P_BRITNEY, RustburgWharf_Text_BritneyIntro, RustburgWharf_Text_BritneyDefeated
    msgbox RustburgWharf_Text_BritneyPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Cora::
    trainerbattle_single TRAINER_P_CORA, RustburgWharf_Text_CoraIntro, RustburgWharf_Text_CoraDefeated
    msgbox RustburgWharf_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Mel::
    trainerbattle_single TRAINER_P_MEL, RustburgWharf_Text_MelIntro, RustburgWharf_Text_MelDefeated
    msgbox RustburgWharf_Text_MelPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Line::
    trainerbattle_single TRAINER_P_LINE, RustburgWharf_Text_LineIntro, RustburgWharf_Text_LineDefeated
    msgbox RustburgWharf_Text_LinePostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Hook::
    trainerbattle_single TRAINER_P_HOOK, RustburgWharf_Text_HookIntro, RustburgWharf_Text_HookDefeated
    msgbox RustburgWharf_Text_HookPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Yukari::
    trainerbattle_single TRAINER_P_YUKARI, RustburgWharf_Text_YukariIntro, RustburgWharf_Text_YukariDefeated
    msgbox RustburgWharf_Text_YukariPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Makoto::
    trainerbattle_single TRAINER_P_MAKOTO, RustburgWharf_Text_MakotoIntro, RustburgWharf_Text_MakotoDefeated
    msgbox RustburgWharf_Text_MakotoPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Inigo::
    trainerbattle_single TRAINER_P_INIGO, RustburgWharf_Text_InigoIntro, RustburgWharf_Text_InigoDefeated
    msgbox RustburgWharf_Text_InigoPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Fezzik::
    trainerbattle_single TRAINER_P_FEZZIK, RustburgWharf_Text_FezzikIntro, RustburgWharf_Text_FezzikDefeated
    msgbox RustburgWharf_Text_FezzikPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_JeanAndJackitt::
    trainerbattle_double TRAINER_P_JEAN_AND_JACKITT, RustburgWharf_Text_JeanAndJackittIntro, RustburgWharf_Text_JeanAndJackittDefeated, RustburgWharf_Text_JeanAndJackittNeedTwoMons
    msgbox RustburgWharf_Text_JeanAndJackittPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_LunaAndStar::
    trainerbattle_double TRAINER_P_LUNA_AND_STAR, RustburgWharf_Text_LunaAndStarIntro, RustburgWharf_Text_LunaAndStarDefeated, RustburgWharf_Text_LunaAndStarNeedTwoMons
    msgbox RustburgWharf_Text_LunaAndStarPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Lance::
    trainerbattle_single TRAINER_P_LANCE, RustburgWharf_Text_LanceIntro, RustburgWharf_Text_LanceDefeated
    msgbox RustburgWharf_Text_LancePostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Micycle::
    trainerbattle_single TRAINER_P_MICYCLE, RustburgWharf_Text_MicycleIntro, RustburgWharf_Text_MicycleDefeated
    msgbox RustburgWharf_Text_MicyclePostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Skipper::
    trainerbattle_single TRAINER_P_SKIPPER, RustburgWharf_Text_SkipperIntro, RustburgWharf_Text_SkipperDefeated
    msgbox RustburgWharf_Text_SkipperPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Twoffany::
    trainerbattle_single TRAINER_P_TWOFFANY, RustburgWharf_Text_TwoffanyIntro, RustburgWharf_Text_TwoffanyDefeated
    msgbox RustburgWharf_Text_TwoffanyPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Olivier::
    trainerbattle_single TRAINER_P_OLIVIER, RustburgWharf_Text_OlivierIntro, RustburgWharf_Text_OlivierDefeated
    msgbox RustburgWharf_Text_OlivierPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Tiktaalik::
    trainerbattle_single TRAINER_P_TIKTAALIK, RustburgWharf_Text_TiktaalikIntro, RustburgWharf_Text_TiktaalikDefeated
    msgbox RustburgWharf_Text_TiktaalikPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_EventScript_Patrick::
    trainerbattle_single TRAINER_P_PATRICK, RustburgWharf_Text_PatrickIntro, RustburgWharf_Text_PatrickDefeated
    msgbox RustburgWharf_Text_PatrickPostBattle, MSGBOX_AUTOCLOSE
    end

RustburgWharf_Text_BritneyIntro:
	.string "intro$"

RustburgWharf_Text_BritneyDefeated:
	.string "defeat$"

RustburgWharf_Text_BritneyPostBattle:
	.string "post$"

RustburgWharf_Text_CoraIntro:
	.string "intro$"

RustburgWharf_Text_CoraDefeated:
	.string "defeat$"

RustburgWharf_Text_CoraPostBattle:
	.string "post$"

RustburgWharf_Text_MelIntro:
	.string "intro$"

RustburgWharf_Text_MelDefeated:
	.string "defeat$"

RustburgWharf_Text_MelPostBattle:
	.string "post$"

RustburgWharf_Text_LineIntro:
	.string "intro$"

RustburgWharf_Text_LineDefeated:
	.string "defeat$"

RustburgWharf_Text_LinePostBattle:
	.string "post$"

RustburgWharf_Text_HookIntro:
	.string "intro$"

RustburgWharf_Text_HookDefeated:
	.string "defeat$"

RustburgWharf_Text_HookPostBattle:
	.string "post$"

RustburgWharf_Text_YukariIntro:
	.string "intro$"

RustburgWharf_Text_YukariDefeated:
	.string "defeat$"

RustburgWharf_Text_YukariPostBattle:
	.string "post$"

RustburgWharf_Text_MakotoIntro:
	.string "intro$"

RustburgWharf_Text_MakotoDefeated:
	.string "defeat$"

RustburgWharf_Text_MakotoPostBattle:
	.string "post$"

RustburgWharf_Text_InigoIntro:
	.string "intro$"

RustburgWharf_Text_InigoDefeated:
	.string "defeat$"

RustburgWharf_Text_InigoPostBattle:
	.string "post$"

RustburgWharf_Text_FezzikIntro:
	.string "intro$"

RustburgWharf_Text_FezzikDefeated:
	.string "defeat$"

RustburgWharf_Text_FezzikPostBattle:
	.string "post$"

RustburgWharf_Text_JeanAndJackittIntro:
	.string "intro$"

RustburgWharf_Text_JeanAndJackittDefeated:
	.string "defeat$"

RustburgWharf_Text_JeanAndJackittPostBattle:
	.string "post$"

RustburgWharf_Text_JeanAndJackittNeedTwoMons:
	.string "need 2 dood$"

RustburgWharf_Text_LunaAndStarIntro:
	.string "intro$"

RustburgWharf_Text_LunaAndStarDefeated:
	.string "defeat$"

RustburgWharf_Text_LunaAndStarPostBattle:
	.string "post$"

RustburgWharf_Text_LunaAndStarNeedTwoMons:
	.string "need 2 dood$"

RustburgWharf_Text_LanceIntro:
	.string "intro$"

RustburgWharf_Text_LanceDefeated:
	.string "defeat$"

RustburgWharf_Text_LancePostBattle:
	.string "post$"

RustburgWharf_Text_MicycleIntro:
	.string "intro$"

RustburgWharf_Text_MicycleDefeated:
	.string "defeat$"

RustburgWharf_Text_MicyclePostBattle:
	.string "post$"

RustburgWharf_Text_SkipperIntro:
	.string "intro$"

RustburgWharf_Text_SkipperDefeated:
	.string "defeat$"

RustburgWharf_Text_SkipperPostBattle:
	.string "post$"

RustburgWharf_Text_TwoffanyIntro:
	.string "intro$"

RustburgWharf_Text_TwoffanyDefeated:
	.string "defeat$"

RustburgWharf_Text_TwoffanyPostBattle:
	.string "post$"

RustburgWharf_Text_OlivierIntro:
	.string "intro$"

RustburgWharf_Text_OlivierDefeated:
	.string "defeat$"

RustburgWharf_Text_OlivierPostBattle:
	.string "post$"

RustburgWharf_Text_TiktaalikIntro:
	.string "intro$"

RustburgWharf_Text_TiktaalikDefeated:
	.string "defeat$"

RustburgWharf_Text_TiktaalikPostBattle:
	.string "post$"

RustburgWharf_Text_PatrickIntro:
	.string "intro$"

RustburgWharf_Text_PatrickDefeated:
	.string "defeat$"

RustburgWharf_Text_PatrickPostBattle:
	.string "post$"
