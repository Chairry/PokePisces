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
	.string "i make the shell bell\n"
	.string "do you have the materials\l"
	.string "4 shells 1 salt$"

SootopolisInteriors_Text_TakeShellBell:
	.string "have this dood$"

SootopolisInteriors_Text_GetMoreShells:
	.string "you need 4 total shells$"

SootopolisInteriors_Text_GoFindSalt:
	.string "you need salt. try the\n"
	.string "restaurant$"

SootopolisInteriors_Text_NoMoreShellBell:
	.string "no more bells$"
