RivalRoom_MapScripts::
	.byte 0

RivalRoom_EventScript_BrineyText::
	setvar VAR_BIRCH_LAB_STATE, 2
	msgbox RivalRoom_Text_BrineyText, MSGBOX_NPC
	end

RivalRoom_Text_BrineyText:
	.string "var birch lab 2$"
