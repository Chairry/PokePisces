ZotpyreInteriors_MapScripts::
	.byte 0

ZotpyreInteriors_EventScript_SpiritBreak::
	lock
	faceplayer
	checkitem ITEM_TM_SPIRIT_BREAK
	goto_if_eq VAR_RESULT, TRUE, ZotpyreInteriors_EventScript_GaveSpiritBreak
	msgbox ZotpyreInteriors_Text_SpiritBreak, MSGBOX_DEFAULT
	giveitem ITEM_TM_SPIRIT_BREAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

ZotpyreInteriors_EventScript_GaveSpiritBreak::
	msgbox ZotpyreInteriors_Text_GaveSpiritBreak, MSGBOX_AUTOCLOSE
	release
	end

ZotpyreInteriors_Text_SpiritBreak:
	.string "here have spirit break$"

ZotpyreInteriors_Text_GaveSpiritBreak:
	.string "alr gave u spirit break$"
