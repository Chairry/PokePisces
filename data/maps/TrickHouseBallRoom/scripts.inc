TrickHouseBallRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, TrickHouseBallRoom_OnLoad
	.byte 0

TrickHouseBallRoom_OnLoad:
	call_if_set FLAG_SOLVED_5_FAERED_PUZZLE, TrickHouseBallRoom_EventScript_CloseShutter
	end

TrickHouseBallRoom_EventScript_ScrollD::
	lock
	msgbox TrickHouseBallRoom_Text_ScrollD, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseBallRoom_EventScript_ClownHinter::
	lock
	faceplayer
	goto_if_set FLAG_SOLVED_5_FAERED_PUZZLE, TrickHouseBallRoom_EventScript_ClownHinterPost
	msgbox TrickHouseBallRoom_Text_HeresAHint, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseBallRoom_EventScript_ClownHinterPost::
	msgbox TrickHouseBallRoom_Text_YouDidIt, MSGBOX_AUTOCLOSE
	release
	end

TrickHouseBallRoom_EventScript_FaeredChoose1::
	lockall
	msgbox TrickHouseBallRoom_Text_Faered1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TrickHouseBallRoom_EventScript_FaeredReveal
	closemessage
	releaseall
	end

TrickHouseBallRoom_EventScript_FaeredChoose2::
	lockall
	msgbox TrickHouseBallRoom_Text_Faered2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TrickHouseBallRoom_EventScript_FaeredReveal
	closemessage
	releaseall
	end

TrickHouseBallRoom_EventScript_FaeredChoose3::
	lockall
	msgbox TrickHouseBallRoom_Text_Faered3, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TrickHouseBallRoom_EventScript_FaeredReveal
	closemessage
	releaseall
	end

TrickHouseBallRoom_EventScript_FaeredChoose4::
	lockall
	msgbox TrickHouseBallRoom_Text_Faered4, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TrickHouseBallRoom_EventScript_FaeredReveal
	closemessage
	releaseall
	end

TrickHouseBallRoom_EventScript_FaeredReveal::
	closemessage
	delay 16
	applymovement VAR_LAST_TALKED, TrickHouseBallRoom_Movement_FaeredReveal
	delay 32
	setwildbattle SPECIES_FAERED, 30
	playmoncry SPECIES_FAERED, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	dowildbattle
	removeobject VAR_LAST_TALKED
	releaseall
	end

TrickHouseBallRoom_Movement_FaeredReveal:
	faered_reveal
	step_end

TrickHouseBallRoom_EventScript_CorrectBall::
	lockall
	msgbox TrickHouseBallRoom_Text_CorrectBall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TrickHouseBallRoom_EventScript_PickUpBall
	closemessage
	releaseall
	end

TrickHouseBallRoom_EventScript_PickUpBall::
	msgbox TrickHouseBallRoom_Text_YouChoseCorrectly, MSGBOX_DEFAULT
	removeobject VAR_LAST_TALKED
	setflag FLAG_SOLVED_5_FAERED_PUZZLE	
	playse SE_CLICK
	call TrickHouseBallRoom_EventScript_CloseShutter
	release
	end

TrickHouseBallRoom_EventScript_CloseShutter::
	setmetatile 3, 5, METATILE_TrickHouseNew_ShutterClosed, FALSE
	special DrawWholeMapView
	return

TrickHouseBallRoom_Text_Faered1:
	.string "(You listen to the ball...)\p"
	.string "Eeeee......\n"
	.string "ee-yuh... eeee-yyuh..!\p"
	.string "(Open this ball?)$"

TrickHouseBallRoom_Text_Faered2:
	.string "(You listen to the ball...)\p"
	.string "EEEE-YUH-UH. Yuheee...\p"
	.string "(Open this ball?)$"

TrickHouseBallRoom_Text_Faered3:
	.string "(You listen to the ball...)\p"
	.string "Ah! Ah-yuh-yuh-yyyyyyuh!\n"
	.string "Eyuhyuhhhh....!\p"
	.string "(Open this ball?)$"

TrickHouseBallRoom_Text_Faered4:
	.string "(You listen to the ball...)\p"
	.string "Eh.... yeh... yuhee.\n"
	.string "Eyuh, eyuh.\p"
	.string "(Open this ball?)$"

TrickHouseBallRoom_Text_CorrectBall:
	.string "(You listen to the ball...)\p"
	.string "...\p"
	.string "(Open this ball?)$"

TrickHouseBallRoom_Text_HeresAHint:
	.string "Aha, hello hello.\p"
	.string "A hint for this puzzle room\n"
	.string "is that two of the five\l"
	.string "of these balls are telling\l"
	.string "the truth. The other three\l"
	.string "only tell lies.\p"
	.string "Use what they tell you to figure out\n"
	.string "which ball is not a trick,\l"
	.string "then open it up!$"

TrickHouseBallRoom_Text_YouDidIt:
	.string "Amazing!!\n"
	.string "I've never seen a soul\l"
	.string "solve this puppy so fast...$"

TrickHouseBallRoom_Text_YouChoseCorrectly:
	.string "(! There is a switch inside.)$"

TrickHouseBallRoom_Text_ScrollD:
	.string "(It's a scroll with odd\n"
	.string "handwriting on it...)\p"
	.string "Another clue? For you?\n"
	.string "Oh, you sly dog!\p"
	.string "This room's number hint is that,\n"
	.string "in the final sequence, the\l"
	.string "number corresponding to this\l"
	.string "room is half of the number\l"
	.string "directly to its right.\p"
	.string "It is also greater than the\n"
	.string "rightmost number in the sequence!\p"
	.string "- Trick Master is coveted.$"
