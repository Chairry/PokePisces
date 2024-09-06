CrimneyCaldera_MapScripts::
	.byte 0

CrimneyCaldera_EventScript_Meiyu::
    trainerbattle_single TRAINER_P_MEIYU, CrimneyCaldera_Text_MeiyuIntro, CrimneyCaldera_Text_MeiyuDefeated
    msgbox CrimneyCaldera_Text_MeiyuPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyCaldera_EventScript_Centauri::
    trainerbattle_single TRAINER_P_CENTAURI, CrimneyCaldera_Text_CentauriIntro, CrimneyCaldera_Text_CentauriDefeated
    msgbox CrimneyCaldera_Text_CentauriPostBattle, MSGBOX_AUTOCLOSE
    end

CrimneyCaldera_Text_MeiyuIntro:
	.string "intro$"

CrimneyCaldera_Text_MeiyuDefeated:
	.string "defeat$"

CrimneyCaldera_Text_MeiyuPostBattle:
	.string "post$"

CrimneyCaldera_Text_CentauriIntro:
	.string "intro$"

CrimneyCaldera_Text_CentauriDefeated:
	.string "defeat$"

CrimneyCaldera_Text_CentauriPostBattle:
	.string "post$"
