Route133_MapScripts::
	.byte 0

Route133_EventScript_Franklin::
	trainerbattle_single TRAINER_P_CHERIE, Route133_Text_FranklinIntro, Route133_Text_FranklinDefeat
	msgbox Route133_Text_FranklinPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Debra::
	trainerbattle_single TRAINER_P_KING, Route133_Text_DebraIntro, Route133_Text_DebraDefeat
	msgbox Route133_Text_DebraPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Linda::
	trainerbattle_single TRAINER_P_SAI_AND_MISHA, Route133_Text_LindaIntro, Route133_Text_LindaDefeat
	msgbox Route133_Text_LindaPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Warren::
	trainerbattle_single TRAINER_P_JUNICHI, Route133_Text_WarrenIntro, Route133_Text_WarrenDefeat
	msgbox Route133_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Beck::
	trainerbattle_single TRAINER_P_MARCY, Route133_Text_BeckIntro, Route133_Text_BeckDefeat
	msgbox Route133_Text_BeckPostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Mollie::
	trainerbattle_single TRAINER_P_TSUNAMI, Route133_Text_MollieIntro, Route133_Text_MollieDefeat
	msgbox Route133_Text_MolliePostBattle, MSGBOX_AUTOCLOSE
	end

Route133_EventScript_Conor::
	trainerbattle_single TRAINER_P_THYME, Route133_Text_ConorIntro, Route133_Text_ConorDefeat
	msgbox Route133_Text_ConorPostBattle, MSGBOX_AUTOCLOSE
	end

