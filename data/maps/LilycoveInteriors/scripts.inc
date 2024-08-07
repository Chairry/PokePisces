LilycoveInteriors_MapScripts::
	.byte 0

LilycoveInteriors_EventScript_Briney::
	lock
	faceplayer
	speakername LilycoveInteriors_Text_NameBriney
	clearflag FLAG_BRINEY_MIDGAME_VISIT
	msgbox LilycoveInteriors_Text_WantToVoyage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveInteriors_EventScript_WarpToTidal
	msgbox LilycoveInteriors_Text_IllBeHere, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

LilycoveInteriors_EventScript_WarpToTidal::
	msgbox LilycoveInteriors_Text_BonVoyage, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_SS_TIDAL_MID_TERIORS, 33, 4
	release
	end

LilycoveInteriors_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RAITAIC_TRADE_COMPLETED, LilycoveInteriors_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_RAITAIC
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox LilycoveInteriors_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveInteriors_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveInteriors_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, LilycoveInteriors_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox LilycoveInteriors_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RAITAIC_TRADE_COMPLETED
	release
	end

LilycoveInteriors_EventScript_DeclineTrade::
	msgbox LilycoveInteriors_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

LilycoveInteriors_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox LilycoveInteriors_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

LilycoveInteriors_EventScript_TradeCompleted::
	msgbox LilycoveInteriors_Text_ThanksForTrading, MSGBOX_DEFAULT
	release
	end

LilycoveInteriors_Text_NameBriney:
	.string "Cpt. Briney$"

LilycoveInteriors_Text_IllTradeIfYouWant:
	.string "I'll trade you my {STR_VAR_2} for\n"
	.string "a {STR_VAR_1} if you want.$"

LilycoveInteriors_Text_PleaseBeGoodToMyPokemon:
	.string "Please be good to my POKéMON.$"

LilycoveInteriors_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

LilycoveInteriors_Text_YouDontWantToThatsOkay:
	.string "Oh, if you don't want to, that's okay.$"

LilycoveInteriors_Text_ThanksForTrading:
	.string "Thanks for the trade.$"

LilycoveInteriors_Text_WantToVoyage:
	.string "wanna go to ss tidle$"

LilycoveInteriors_Text_IllBeHere:
	.string "ill be waitin$"

LilycoveInteriors_Text_BonVoyage:
	.string "bon voyage$"
