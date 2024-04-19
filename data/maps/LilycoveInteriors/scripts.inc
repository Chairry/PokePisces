LilycoveInteriors_MapScripts::
	.byte 0

LilycoveInteriors_EventScript_Briney::
	lock
	faceplayer
	clearflag FLAG_BRINEY_MIDGAME_VISIT
	msgbox LilycoveInteriors_Text_WantToVoyage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveInteriors_EventScript_WarpToTidal
	msgbox LilycoveInteriors_Text_IllBeHere, MSGBOX_AUTOCLOSE
	release
	end

LilycoveInteriors_EventScript_WarpToTidal::
	msgbox LilycoveInteriors_Text_BonVoyage, MSGBOX_DEFAULT
	warp MAP_SS_TIDAL_MID_TERIORS, 33, 4
	release
	end

LilycoveInteriors_Text_WantToVoyage:
	.string "wanna go to ss tidle$"

LilycoveInteriors_Text_IllBeHere:
	.string "ill be waitin$"

LilycoveInteriors_Text_BonVoyage:
	.string "bon voyage$"
