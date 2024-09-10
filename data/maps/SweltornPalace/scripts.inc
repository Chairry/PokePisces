SweltornPalace_MapScripts::
	.byte 0

SweltornPalace_EventScript_Reli::
    trainerbattle_single TRAINER_P_RELI, SweltornPalace_Text_ReliIntro, SweltornPalace_Text_ReliDefeated
    msgbox SweltornPalace_Text_ReliPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalace_EventScript_Castle::
    trainerbattle_single TRAINER_P_CASTLE, SweltornPalace_Text_CastleIntro, SweltornPalace_Text_CastleDefeated
    msgbox SweltornPalace_Text_CastlePostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalace_EventScript_Katrina::
    trainerbattle_single TRAINER_P_KATRINA, SweltornPalace_Text_KatrinaIntro, SweltornPalace_Text_KatrinaDefeated
    msgbox SweltornPalace_Text_KatrinaPostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalace_EventScript_Gertrude::
    trainerbattle_single TRAINER_P_GERTRUDE, SweltornPalace_Text_GertrudeIntro, SweltornPalace_Text_GertrudeDefeated
    msgbox SweltornPalace_Text_GertrudePostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalace_EventScript_Tootsie::
    trainerbattle_single TRAINER_P_TOOTSIE, SweltornPalace_Text_TootsieIntro, SweltornPalace_Text_TootsieDefeated
    msgbox SweltornPalace_Text_TootsiePostBattle, MSGBOX_AUTOCLOSE
    end

SweltornPalace_Text_ReliIntro:
	.string "intro$"

SweltornPalace_Text_ReliDefeated:
	.string "defeat$"

SweltornPalace_Text_ReliPostBattle:
	.string "post$"

SweltornPalace_Text_CastleIntro:
	.string "intro$"

SweltornPalace_Text_CastleDefeated:
	.string "defeat$"

SweltornPalace_Text_CastlePostBattle:
	.string "post$"

SweltornPalace_Text_KatrinaIntro:
	.string "intro$"

SweltornPalace_Text_KatrinaDefeated:
	.string "defeat$"

SweltornPalace_Text_KatrinaPostBattle:
	.string "post$"

SweltornPalace_Text_GertrudeIntro:
	.string "intro$"

SweltornPalace_Text_GertrudeDefeated:
	.string "defeat$"

SweltornPalace_Text_GertrudePostBattle:
	.string "post$"

SweltornPalace_Text_TootsieIntro:
	.string "intro$"

SweltornPalace_Text_TootsieDefeated:
	.string "defeat$"

SweltornPalace_Text_TootsiePostBattle:
	.string "post$"
