SeaMauville_MapScripts::
	.byte 0

SeaMauville_EventScript_Nue::
    trainerbattle_single TRAINER_P_NUE, SeaMauville_Text_NueIntro, SeaMauville_Text_NueDefeated
    msgbox SeaMauville_Text_NuePostBattle, MSGBOX_AUTOCLOSE
    end

SeaMauville_EventScript_Gary::
    trainerbattle_single TRAINER_P_GARY, SeaMauville_Text_GaryIntro, SeaMauville_Text_GaryDefeated
    msgbox SeaMauville_Text_GaryPostBattle, MSGBOX_AUTOCLOSE
    end

SeaMauville_Text_NueIntro:
	.string "intro$"

SeaMauville_Text_NueDefeated:
	.string "defeat$"

SeaMauville_Text_NuePostBattle:
	.string "post$"

SeaMauville_Text_GaryIntro:
	.string "intro$"

SeaMauville_Text_GaryDefeated:
	.string "defeat$"

SeaMauville_Text_GaryPostBattle:
	.string "post$"
