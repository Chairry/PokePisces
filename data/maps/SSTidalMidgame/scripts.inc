SSTidalMidgame_MapScripts::
	.byte 0

SSTidalMidgame_EventScript_Briney::
	lock
	faceplayer
	speakername SSTidalMidgame_Text_NameBriney
	msgbox SSTidalMidgame_Text_WantToGoSomewhere, MSGBOX_DEFAULT
	multichoice 19, 4, MULTI_BRINEY_BOAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SSTidalMidgame_EventScript_GotoPacifidlog
	case 1, SSTidalMidgame_EventScript_GotoMossdeep
	case 2, SSTidalMidgame_EventScript_GotoLilycove
	case 3, SSTidalMidgame_EventScript_WaitAWhile
	closemessage
	release
	end

SSTidalMidgame_EventScript_GotoPacifidlog::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_PACIFIDLOG_TOWN, 48, 27
	release
	end

SSTidalMidgame_EventScript_GotoMossdeep::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_MOSSDEEP_CITY, 6, 11
	release
	end

SSTidalMidgame_EventScript_GotoLilycove::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_LILYCOVE_CITY, 55, 30
	release
	end

SSTidalMidgame_EventScript_WaitAWhile::
	msgbox SSTidalMidgame_Text_WellWait, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

SSTidalMidgame_Text_NameBriney:
	.string "Cpt. Briney$"

SSTidalMidgame_Text_WantToGoSomewhere:
	.string "wanna go someplace?$"

SSTidalMidgame_Text_LetsGo:
	.string "let's go$"

SSTidalMidgame_Text_WellWait:
	.string "we'll wait chief$"
