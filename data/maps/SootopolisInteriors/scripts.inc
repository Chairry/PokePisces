SootopolisInteriors_MapScripts::
	.byte 0

SootopolisInteriors_EventScript_ShellBellMaker::
	lock
	goto_if_set FLAG_RECEIVED_SHELL_BELL, SootopolisInteriors_EventScript_NoMoreShellBell
	msgbox SootopolisInteriors_Text_IMakeShellBells, MSGBOX_DEFAULT
	checkitem ITEM_SHOAL_SHELL, 4
	goto_if_eq VAR_RESULT, FALSE, SootopolisInteriors_EventScript_GetMoreShells
	checkitem ITEM_SHOAL_SALT, 1
	goto_if_eq VAR_RESULT, FALSE, SootopolisInteriors_EventScript_GoFindSalt
	msgbox SootopolisInteriors_Text_TakeShellBell, MSGBOX_DEFAULT
	removeitem ITEM_SHOAL_SALT, 1
	removeitem ITEM_SHOAL_SHELL, 4
	giveitem ITEM_SHELL_BELL
	setflag FLAG_RECEIVED_SHELL_BELL
	closemessage
	release
	end

SootopolisInteriors_EventScript_GetMoreShells::
	msgbox SootopolisInteriors_Text_GetMoreShells, MSGBOX_DEFAULT
	release
	end

SootopolisInteriors_EventScript_GoFindSalt::
	msgbox SootopolisInteriors_Text_GoFindSalt, MSGBOX_DEFAULT
	release
	end

SootopolisInteriors_EventScript_NoMoreShellBell::
	msgbox SootopolisInteriors_Text_NoMoreShellBell, MSGBOX_DEFAULT
	release
	end

SootopolisInteriors_Text_IMakeShellBells:
	.string "Welcome to my home.\p"
	.string "My name is Bill L'Belle.\p"
	.string "As you can tell by my name, I make\n"
	.string "Pokédollar-bills for a living.\p"
	.string "…And for a hobby, I like making\n"
	.string "Shell Bells.\p"
	.string "If you have 4 shells and a package of\n"
	.string "salt, I can produce one for you.$"

SootopolisInteriors_Text_TakeShellBell:
	.string "It appears you've brought me all that\n"
	.string "I need. I'll get right to it.\p"
	.string "...\p"
	.string "Here you are.\n"
	.string "It's some of my finest work!\l"
	.string "I hope it comes in handy.$"

SootopolisInteriors_Text_GetMoreShells:
	.string "It seems you lack the requisite\n"
	.string "amount of shells.\p"
	.string "I need 4 in total; try talking to some\n"
	.string "Sea Shellers on the coast.\p"
	.string "They could have some to spare.$"

SootopolisInteriors_Text_GoFindSalt:
	.string "While you have enough shells, I also\n"
	.string "require some high-quality salt.\p"
	.string "Try asking the chef at Juan-core\n"
	.string "Cuisine at the north end of the city.\l"
	.string "He uses some grade-A salt.$"

SootopolisInteriors_Text_NoMoreShellBell:
	.string "I can hear that Shell Bell jinglin'\n"
	.string "away in your pocket.\p"
	.string "Glad it seems to be getting put to good use!$"
