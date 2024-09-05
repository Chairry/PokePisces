ShoalCaveNewFloor1_MapScripts::
	.byte 0

ShoalCaveNewFloor1_EventScript_Ludi::
    trainerbattle_single TRAINER_P_LUDI, ShoalCaveNewFloor1_Text_LudiIntro, ShoalCaveNewFloor1_Text_LudiDefeated
    msgbox ShoalCaveNewFloor1_Text_LudiPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor1_EventScript_Solaire::
    trainerbattle_single TRAINER_P_SOLAIRE, ShoalCaveNewFloor1_Text_SolaireIntro, ShoalCaveNewFloor1_Text_SolaireDefeated
    msgbox ShoalCaveNewFloor1_Text_SolairePostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor1_EventScript_Luna::
    trainerbattle_single TRAINER_P_LUNA, ShoalCaveNewFloor1_Text_LunaIntro, ShoalCaveNewFloor1_Text_LunaDefeated
    msgbox ShoalCaveNewFloor1_Text_LunaPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor1_EventScript_Wu::
    trainerbattle_single TRAINER_P_WU, ShoalCaveNewFloor1_Text_WuIntro, ShoalCaveNewFloor1_Text_WuDefeated
    msgbox ShoalCaveNewFloor1_Text_WuPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor1_EventScript_Tang::
    trainerbattle_single TRAINER_P_TANG, ShoalCaveNewFloor1_Text_TangIntro, ShoalCaveNewFloor1_Text_TangDefeated
    msgbox ShoalCaveNewFloor1_Text_TangPostBattle, MSGBOX_AUTOCLOSE
    end

ShoalCaveNewFloor1_Text_LudiIntro:
	.string "intro$"

ShoalCaveNewFloor1_Text_LudiDefeated:
	.string "defeat$"

ShoalCaveNewFloor1_Text_LudiPostBattle:
	.string "post$"

ShoalCaveNewFloor1_Text_SolaireIntro:
	.string "intro$"

ShoalCaveNewFloor1_Text_SolaireDefeated:
	.string "defeat$"

ShoalCaveNewFloor1_Text_SolairePostBattle:
	.string "post$"

ShoalCaveNewFloor1_Text_LunaIntro:
	.string "intro$"

ShoalCaveNewFloor1_Text_LunaDefeated:
	.string "defeat$"

ShoalCaveNewFloor1_Text_LunaPostBattle:
	.string "post$"

ShoalCaveNewFloor1_Text_WuIntro:
	.string "intro$"

ShoalCaveNewFloor1_Text_WuDefeated:
	.string "defeat$"

ShoalCaveNewFloor1_Text_WuPostBattle:
	.string "post$"

ShoalCaveNewFloor1_Text_TangIntro:
	.string "intro$"

ShoalCaveNewFloor1_Text_TangDefeated:
	.string "defeat$"

ShoalCaveNewFloor1_Text_TangPostBattle:
	.string "post$"
