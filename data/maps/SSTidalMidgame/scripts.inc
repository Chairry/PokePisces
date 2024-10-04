SSTidalMidgame_MapScripts::
	.byte 0

SSTidalMidgame_EventScript_Briney::
	lock
	faceplayer
	speakername SSTidalMidgame_Text_NameBriney
	goto_if_set FLAG_BRINEY_DEWFORD_VISIT, SSTidalMidgame_EventScript_BrineyPostDewford
	goto_if_ge VAR_OLD_GUYS_STATE, 1, SSTidalMidgame_EventScript_BrineyPostSeaMauville
	msgbox SSTidalMidgame_Text_WantToGoSomewhere, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_BRINEY_BOAT, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SSTidalMidgame_EventScript_GotoPacifidlog
	case 1, SSTidalMidgame_EventScript_GotoMossdeep
	case 2, SSTidalMidgame_EventScript_GotoLilycove
	case 3, SSTidalMidgame_EventScript_WaitAWhile
	closemessage
	release
	end

SSTidalMidgame_EventScript_BrineyPostSeaMauville::
	msgbox SSTidalMidgame_Text_WantToGoSomewhere, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_BRINEY_BOAT_2, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SSTidalMidgame_EventScript_GotoPacifidlog
	case 1, SSTidalMidgame_EventScript_GotoMossdeep
	case 2, SSTidalMidgame_EventScript_GotoLilycove
	case 3, SSTidalMidgame_EventScript_GotoSeaMauville
	case 4, SSTidalMidgame_EventScript_GotoSouthernIsland
	case 5, SSTidalMidgame_EventScript_WaitAWhile
	closemessage
	release
	end

SSTidalMidgame_EventScript_BrineyPostDewford::
	msgbox SSTidalMidgame_Text_WantToGoSomewhere, MSGBOX_DEFAULT
	multichoice 19, 0, MULTI_BRINEY_BOAT_3, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, SSTidalMidgame_EventScript_GotoPacifidlog
	case 1, SSTidalMidgame_EventScript_GotoMossdeep
	case 2, SSTidalMidgame_EventScript_GotoLilycove
	case 3, SSTidalMidgame_EventScript_GotoSeaMauville
	case 4, SSTidalMidgame_EventScript_GotoSouthernIsland
	case 5, SSTidalMidgame_EventScript_GotoDewford
	case 6, SSTidalMidgame_EventScript_WaitAWhile
	closemessage
	release
	end

SSTidalMidgame_EventScript_GotoPacifidlog::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_PACIFIDLOG_TOWN, 48, 27
	waitstate
	release
	end

SSTidalMidgame_EventScript_GotoMossdeep::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_MOSSDEEP_CITY, 6, 11
	waitstate
	release
	end

SSTidalMidgame_EventScript_GotoLilycove::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_LILYCOVE_CITY, 55, 30
	waitstate
	release
	end

SSTidalMidgame_EventScript_GotoSeaMauville::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_SEA_MAUVILLE, 44, 54
	waitstate
	release
	end

SSTidalMidgame_EventScript_GotoSouthernIsland::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_SOUTHERN_ISLAND, 5, 3
	waitstate
	release
	end

SSTidalMidgame_EventScript_GotoDewford::
	msgbox SSTidalMidgame_Text_LetsGo, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_DEWFORD_NEW, 33, 10
	waitstate
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
	.string "Where would you like to\n"
	.string "venture to, {PLAYER}?$"

SSTidalMidgame_Text_LetsGo:
	.string "Affirmative!\n"
	.string "Enjoy the ride!$"

SSTidalMidgame_Text_WellWait:
	.string "That can wait.\n"
	.string "You may explore the ship\l"
	.string "to your heart's content.$"
