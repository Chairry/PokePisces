SlateportShore_MapScripts::
	.byte 0

SlateportShore_EventScript_Jello::
    trainerbattle_single TRAINER_P_JELLO, SlateportShore_Text_JelloIntro, SlateportShore_Text_JelloDefeated
    msgbox SlateportShore_Text_JelloPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Len::
    trainerbattle_single TRAINER_P_LEN, SlateportShore_Text_LenIntro, SlateportShore_Text_LenDefeated
    msgbox SlateportShore_Text_LenPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Rin::
    trainerbattle_single TRAINER_P_RIN, SlateportShore_Text_RinIntro, SlateportShore_Text_RinDefeated
    msgbox SlateportShore_Text_RinPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_RoseAndThorn::
    trainerbattle_double TRAINER_P_ROSE_AND_THORN, SlateportShore_Text_RoseAndThornIntro, SlateportShore_Text_RoseAndThornDefeated, SlateportShore_Text_RoseAndThornNeedTwoMons
    msgbox SlateportShore_Text_RoseAndThornPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Tex::
    trainerbattle_single TRAINER_P_TEX, SlateportShore_Text_TexIntro, SlateportShore_Text_TexDefeated
    msgbox SlateportShore_Text_TexPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Dawn::
    trainerbattle_single TRAINER_P_DAWN, SlateportShore_Text_DawnIntro, SlateportShore_Text_DawnDefeated
    msgbox SlateportShore_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Louise::
    trainerbattle_single TRAINER_P_LOUISE, SlateportShore_Text_LouiseIntro, SlateportShore_Text_LouiseDefeated
    msgbox SlateportShore_Text_LouisePostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Prag::
    trainerbattle_single TRAINER_P_PRAG, SlateportShore_Text_PragIntro, SlateportShore_Text_PragDefeated
    msgbox SlateportShore_Text_PragPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Mark::
    trainerbattle_single TRAINER_P_MARK, SlateportShore_Text_MarkIntro, SlateportShore_Text_MarkDefeated
    msgbox SlateportShore_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Sacred::
    trainerbattle_single TRAINER_P_SACRED, SlateportShore_Text_SacredIntro, SlateportShore_Text_SacredDefeated
    msgbox SlateportShore_Text_SacredPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Mandalore::
    trainerbattle_single TRAINER_P_MANDALORE, SlateportShore_Text_MandaloreIntro, SlateportShore_Text_MandaloreDefeated
    msgbox SlateportShore_Text_MandalorePostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_Beast::
    trainerbattle_single TRAINER_P_BEAST, SlateportShore_Text_BeastIntro, SlateportShore_Text_BeastDefeated
    msgbox SlateportShore_Text_BeastPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_EventScript_CaseyNat::
    trainerbattle_single TRAINER_P_KAISENAT, SlateportShore_Text_CaseyNatIntro, SlateportShore_Text_CaseyNatDefeated
    msgbox SlateportShore_Text_CaseyNatPostBattle, MSGBOX_AUTOCLOSE
    end

SlateportShore_Text_JelloIntro:
	.string "intro$"

SlateportShore_Text_JelloDefeated:
	.string "defeat$"

SlateportShore_Text_JelloPostBattle:
	.string "post$"

SlateportShore_Text_LenIntro:
	.string "intro$"

SlateportShore_Text_LenDefeated:
	.string "defeat$"

SlateportShore_Text_LenPostBattle:
	.string "post$"

SlateportShore_Text_RinIntro:
	.string "intro$"

SlateportShore_Text_RinDefeated:
	.string "defeat$"

SlateportShore_Text_RinPostBattle:
	.string "post$"

SlateportShore_Text_RoseAndThornIntro:
	.string "intro$"

SlateportShore_Text_RoseAndThornDefeated:
	.string "defeat$"

SlateportShore_Text_RoseAndThornPostBattle:
	.string "post$"

SlateportShore_Text_RoseAndThornNeedTwoMons:
	.string "need 2 dood$"

SlateportShore_Text_TexIntro:
	.string "intro$"

SlateportShore_Text_TexDefeated:
	.string "defeat$"

SlateportShore_Text_TexPostBattle:
	.string "post$"

SlateportShore_Text_DawnIntro:
	.string "intro$"

SlateportShore_Text_DawnDefeated:
	.string "defeat$"

SlateportShore_Text_DawnPostBattle:
	.string "post$"

SlateportShore_Text_LouiseIntro:
	.string "intro$"

SlateportShore_Text_LouiseDefeated:
	.string "defeat$"

SlateportShore_Text_LouisePostBattle:
	.string "post$"

SlateportShore_Text_PragIntro:
	.string "intro$"

SlateportShore_Text_PragDefeated:
	.string "defeat$"

SlateportShore_Text_PragPostBattle:
	.string "post$"

SlateportShore_Text_MarkIntro:
	.string "intro$"

SlateportShore_Text_MarkDefeated:
	.string "defeat$"

SlateportShore_Text_MarkPostBattle:
	.string "post$"

SlateportShore_Text_SacredIntro:
	.string "intro$"

SlateportShore_Text_SacredDefeated:
	.string "defeat$"

SlateportShore_Text_SacredPostBattle:
	.string "post$"

SlateportShore_Text_MandaloreIntro:
	.string "intro$"

SlateportShore_Text_MandaloreDefeated:
	.string "defeat$"

SlateportShore_Text_MandalorePostBattle:
	.string "post$"

SlateportShore_Text_BeastIntro:
	.string "intro$"

SlateportShore_Text_BeastDefeated:
	.string "defeat$"

SlateportShore_Text_BeastPostBattle:
	.string "post$"

SlateportShore_Text_CaseyNatIntro:
	.string "intro$"

SlateportShore_Text_CaseyNatDefeated:
	.string "defeat$"

SlateportShore_Text_CaseyNatPostBattle:
	.string "post$"
