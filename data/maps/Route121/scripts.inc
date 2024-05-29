.set LOCALID_SNOWNINJA, 12

Route121_MapScripts::
	.byte 0

Route121_EventScript_Barney::
    trainerbattle_single TRAINER_P_BARNEY, Route121_Text_BarneyIntro, Route121_Text_BarneyDefeated
    msgbox Route121_Text_BarneyPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Charon::
    trainerbattle_single TRAINER_P_CHARON, Route121_Text_CharonIntro, Route121_Text_CharonDefeated
    msgbox Route121_Text_CharonPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Garnet::
    trainerbattle_single TRAINER_P_GARNET, Route121_Text_GarnetIntro, Route121_Text_GarnetDefeated
    msgbox Route121_Text_GarnetPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Lapiz::
    trainerbattle_single TRAINER_P_LAPIZ, Route121_Text_LapizIntro, Route121_Text_LapizDefeated
    msgbox Route121_Text_LapizPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Vergil::
    trainerbattle_single TRAINER_P_VERGIL, Route121_Text_VergilIntro, Route121_Text_VergilDefeated
    msgbox Route121_Text_VergilPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Yosh::
    trainerbattle_single TRAINER_P_YOSH, Route121_Text_YoshIntro, Route121_Text_YoshDefeated
    msgbox Route121_Text_YoshPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Kaiji::
    trainerbattle_single TRAINER_P_KAIJI, Route121_Text_KaijiIntro, Route121_Text_KaijiDefeated
    msgbox Route121_Text_KaijiPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Lars::
    trainerbattle_single TRAINER_P_LARS, Route121_Text_LarsIntro, Route121_Text_LarsDefeated
    msgbox Route121_Text_LarsPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Darcie::
    trainerbattle_single TRAINER_P_DARCIE, Route121_Text_DarcieIntro, Route121_Text_DarcieDefeated
    msgbox Route121_Text_DarciePostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_Wynton::
    trainerbattle_single TRAINER_P_WYNTON, Route121_Text_WyntonIntro, Route121_Text_WyntonDefeated
    msgbox Route121_Text_WyntonPostBattle, MSGBOX_AUTOCLOSE
    end

Route121_EventScript_SnowballFight::
	lock
	faceplayer
	checkitem ITEM_SNOWBALL
	goto_if_eq VAR_RESULT, TRUE, Route121_EventScript_GaveSnowball
	msgbox Route121_Text_WannaHaveSnowballFight, MSGBOX_DEFAULT
	closemessage
	playse SE_M_VITAL_THROW2
	setmetatile 74, 12, METATILE_Snow_SnowPileTopLeft, FALSE
	setmetatile 75, 12, METATILE_Snow_SnowPileTopRight, FALSE
	setmetatile 74, 13, METATILE_Snow_SnowPileBottomLeft, TRUE
	setmetatile 75, 13, METATILE_Snow_SnowPileBottomRight, TRUE
	special DrawWholeMapView
	removeobject LOCALID_SNOWNINJA
	setflag FLAG_SNOWBALL_BOY
	delay 16
	delay 16
	giveitem ITEM_SNOWBALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

Route121_EventScript_GaveSnowball::
	msgbox Route121_Text_IShallGetRevenge, MSGBOX_AUTOCLOSE
	release
	end

Route121_EventScript_OneWayTripDown::
	lock
	faceplayer
	msgbox Route121_Text_WantToHopDownTheMountain, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route121_EventScript_WarpToLilycove
	msgbox Route121_Text_ThatsFine, MSGBOX_AUTOCLOSE
	release
	end

Route121_EventScript_WarpToLilycove::
	msgbox Route121_Text_TryNotToSlip, MSGBOX_DEFAULT
	warp MAP_LILYCOVE_CITY, 17, 14
	release
	end

Route121_Text_WannaHaveSnowballFight:
	.string "test$"

Route121_Text_IShallGetRevenge:
	.string "test$"

Route121_Text_WantToHopDownTheMountain:
	.string "test$"

Route121_Text_ThatsFine:
	.string "test$"

Route121_Text_TryNotToSlip:
	.string "test$"

Route121_Text_BarneyIntro:
	.string "intro$"

Route121_Text_BarneyDefeated:
	.string "defeat$"

Route121_Text_BarneyPostBattle:
	.string "post$"

Route121_Text_CharonIntro:
	.string "intro$"

Route121_Text_CharonDefeated:
	.string "defeat$"

Route121_Text_CharonPostBattle:
	.string "post$"

Route121_Text_GarnetIntro:
	.string "intro$"

Route121_Text_GarnetDefeated:
	.string "defeat$"

Route121_Text_GarnetPostBattle:
	.string "post$"

Route121_Text_LapizIntro:
	.string "intro$"

Route121_Text_LapizDefeated:
	.string "defeat$"

Route121_Text_LapizPostBattle:
	.string "post$"

Route121_Text_VergilIntro:
	.string "intro$"

Route121_Text_VergilDefeated:
	.string "defeat$"

Route121_Text_VergilPostBattle:
	.string "post$"

Route121_Text_YoshIntro:
	.string "intro$"

Route121_Text_YoshDefeated:
	.string "defeat$"

Route121_Text_YoshPostBattle:
	.string "post$"

Route121_Text_KaijiIntro:
	.string "intro$"

Route121_Text_KaijiDefeated:
	.string "defeat$"

Route121_Text_KaijiPostBattle:
	.string "post$"

Route121_Text_LarsIntro:
	.string "intro$"

Route121_Text_LarsDefeated:
	.string "defeat$"

Route121_Text_LarsPostBattle:
	.string "post$"

Route121_Text_DarcieIntro:
	.string "intro$"

Route121_Text_DarcieDefeated:
	.string "defeat$"

Route121_Text_DarciePostBattle:
	.string "post$"

Route121_Text_WyntonIntro:
	.string "intro$"

Route121_Text_WyntonDefeated:
	.string "defeat$"

Route121_Text_WyntonPostBattle:
	.string "post$"
