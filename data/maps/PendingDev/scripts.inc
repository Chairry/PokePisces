PendingDev_MapScripts::
	.byte 0

PendingDev_EventScript_Gunfried::
    trainerbattle_single TRAINER_P_GUNFRIED, PendingDev_Text_GunfriedIntro, PendingDev_Text_GunfriedDefeated
    msgbox PendingDev_Text_GunfriedPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_Rex::
    trainerbattle_single TRAINER_P_REX, PendingDev_Text_RexIntro, PendingDev_Text_RexDefeated
    msgbox PendingDev_Text_RexPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_Guinda::
    trainerbattle_single TRAINER_P_GUINDA, PendingDev_Text_GuindaIntro, PendingDev_Text_GuindaDefeated
    msgbox PendingDev_Text_GuindaPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_Gunder::
    trainerbattle_single TRAINER_P_GUNDER, PendingDev_Text_GunderIntro, PendingDev_Text_GunderDefeated
    msgbox PendingDev_Text_GunderPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_Gunhild::
    trainerbattle_single TRAINER_P_GUNHILD, PendingDev_Text_GunhildIntro, PendingDev_Text_GunhildDefeated
    msgbox PendingDev_Text_GunhildPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_Elon::
    trainerbattle_single TRAINER_P_ELON, PendingDev_Text_ElonIntro, PendingDev_Text_ElonDefeated
    msgbox PendingDev_Text_ElonPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_Lilith::
    trainerbattle_single TRAINER_P_LILITH, PendingDev_Text_LilithIntro, PendingDev_Text_LilithDefeated
    msgbox PendingDev_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_SodAndSandy::
    trainerbattle_double TRAINER_P_SOD_AND_SANDY, PendingDev_Text_SodAndSandyIntro, PendingDev_Text_SodAndSandyDefeated, PendingDev_Text_SodAndSandyNeedTwoMons
    msgbox PendingDev_Text_SodAndSandyPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_EventScript_Pendragon::
    trainerbattle_single TRAINER_P_PENDRAGON, PendingDev_Text_PendragonIntro, PendingDev_Text_PendragonDefeated
    msgbox PendingDev_Text_PendragonPostBattle, MSGBOX_AUTOCLOSE
    end

PendingDev_Text_GunfriedIntro:
	.string "intro$"

PendingDev_Text_GunfriedDefeated:
	.string "defeat$"

PendingDev_Text_GunfriedPostBattle:
	.string "post$"

PendingDev_Text_RexIntro:
	.string "intro$"

PendingDev_Text_RexDefeated:
	.string "defeat$"

PendingDev_Text_RexPostBattle:
	.string "post$"

PendingDev_Text_GuindaIntro:
	.string "intro$"

PendingDev_Text_GuindaDefeated:
	.string "defeat$"

PendingDev_Text_GuindaPostBattle:
	.string "post$"

PendingDev_Text_GunderIntro:
	.string "intro$"

PendingDev_Text_GunderDefeated:
	.string "defeat$"

PendingDev_Text_GunderPostBattle:
	.string "post$"

PendingDev_Text_GunhildIntro:
	.string "intro$"

PendingDev_Text_GunhildDefeated:
	.string "defeat$"

PendingDev_Text_GunhildPostBattle:
	.string "post$"

PendingDev_Text_ElonIntro:
	.string "intro$"

PendingDev_Text_ElonDefeated:
	.string "defeat$"

PendingDev_Text_ElonPostBattle:
	.string "post$"

PendingDev_Text_LilithIntro:
	.string "intro$"

PendingDev_Text_LilithDefeated:
	.string "defeat$"

PendingDev_Text_LilithPostBattle:
	.string "post$"

PendingDev_Text_SodAndSandyIntro:
	.string "intro$"

PendingDev_Text_SodAndSandyDefeated:
	.string "defeat$"

PendingDev_Text_SodAndSandyPostBattle:
	.string "post$"

PendingDev_Text_SodAndSandyNeedTwoMons:
	.string "need 2 dood$"

PendingDev_Text_PendragonIntro:
	.string "intro$"

PendingDev_Text_PendragonDefeated:
	.string "defeat$"

PendingDev_Text_PendragonPostBattle:
	.string "post$"
