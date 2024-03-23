.set LOCALID_BREAD, 18

MangrottoTunnel_MapScripts::
	.byte 0

MangrottoTunnel_EventScript_BreadwinnerEnc1::
	lock
	setflag FLAG_TEMP_16
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadE1
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadBackUp
	waitmovement 0
	trainerbattle_single TRAINER_P_JIMMY, MangrottoTunnel_Text_BreadwinnerIntro, MangrottoTunnel_Text_BreadwinnerDefeat, MangrottoTunnel_EventScript_BreadRun
	release
	end

MangrottoTunnel_Movement_BreadE1:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MangrottoTunnel_EventScript_BreadwinnerEnc2::
	lock
	setflag FLAG_TEMP_17
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadE2
	waitmovement 0
	playse SE_WALL_HIT
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadBackUp
	waitmovement 0
	trainerbattle_single TRAINER_P_PANDOU_1, MangrottoTunnel_Text_BreadwinnerIntro, MangrottoTunnel_Text_BreadwinnerDefeat, MangrottoTunnel_EventScript_BreadRun
	release
	end

MangrottoTunnel_Movement_BreadE2:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

MangrottoTunnel_Movement_BreadBackUp:
	walk_fast_up
	walk_fast_up
	face_down
	step_end

MangrottoTunnel_EventScript_BreadRun::
	setvar VAR_BREADWINNER_STATE, 1
	msgbox MangrottoTunnel_Text_BreadwinnerRunAway, MSGBOX_DEFAULT
	closemessage
	goto_if_set FLAG_TEMP_16, MangrottoTunnel_EventScript_BreadEscape1
	goto_if_set FLAG_TEMP_17, MangrottoTunnel_EventScript_BreadEscape2
	release
	end

MangrottoTunnel_EventScript_BreadEscape1::
	playse SE_FLEE
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadEsc1
	waitmovement 0
	setflag FLAG_HIDE_TEAM_OZONE_COSMOSS
	release
	end

MangrottoTunnel_Movement_BreadEsc1:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MangrottoTunnel_EventScript_BreadEscape2::
	playse SE_FLEE
	applymovement LOCALID_BREAD, MangrottoTunnel_Movement_BreadEsc2
	waitmovement 0
	setflag FLAG_HIDE_TEAM_OZONE_COSMOSS
	release
	end

MangrottoTunnel_Movement_BreadEsc2:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MangrottoTunnel_EventScript_Dundee::
    trainerbattle_single TRAINER_P_DUNDEE, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Moka::
    trainerbattle_single TRAINER_P_MOKA, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Woods::
    trainerbattle_single TRAINER_P_WOODS, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Fauna::
    trainerbattle_single TRAINER_P_FAUNA, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Declan::
    trainerbattle_single TRAINER_P_DECLAN, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Shinji::
    trainerbattle_single TRAINER_P_SHINJI, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Skeeter::
    trainerbattle_single TRAINER_P_SKEETER, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Jaja::
    trainerbattle_single TRAINER_P_JAJA, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Jane::
    trainerbattle_single TRAINER_P_JANE, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_EventScript_Jo_And_Jo::
    trainerbattle_double TRAINER_P_JO_AND_JO, MangrottoTunnel_Text_GugumbirIntro, MangrottoTunnel_Text_GugumbirDefeated, MangrottoTunnel_Text_GugumbirNeedTwoMons
    msgbox MangrottoTunnel_Text_GugumbirPostBattle, MSGBOX_AUTOCLOSE
    end

MangrottoTunnel_Text_BreadwinnerIntro:
	.string "i'm late bro!$"

MangrottoTunnel_Text_BreadwinnerDefeat:
	.string "jimminy jillikers!$"

MangrottoTunnel_Text_BreadwinnerRunAway:
	.string "still late bro!$"

MangrottoTunnel_Text_GugumbirIntro:
	.string "intro$"

MangrottoTunnel_Text_GugumbirDefeated:
	.string "defeat$"

MangrottoTunnel_Text_GugumbirPostBattle:
	.string "post$"

MangrottoTunnel_Text_GugumbirNeedTwoMons:
	.string "need 2 doods$"
