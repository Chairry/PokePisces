SootopolisInteriors_MapScripts::
	.byte 0

SootopolisInteriors_EventScript_ShellBellMaker::
	lock
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SootopolisInteriors_EventScript_LunasterTale
	goto_if_set FLAG_RECEIVED_SHELL_BELL, SootopolisInteriors_EventScript_HealBellQuest
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

SootopolisInteriors_EventScript_HealBellQuest::
	msgbox SootopolisInteriors_Text_BringHealBell, MSGBOX_DEFAULT
	checkpartynonhmmove MOVE_HEAL_BELL
	goto_if_eq VAR_RESULT, PARTY_SIZE, NewSooto_EventScript_Hint
	setflag FLAG_RECEIVED_SOOTHE_BELL
	msgbox SootopolisInteriors_Text_HaveSootheBell, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	release
	end

NewSooto_EventScript_Hint::
	msgbox SootopolisInteriors_Text_HealBellHint, MSGBOX_AUTOCLOSE
	release
	end

SootopolisInteriors_EventScript_LunasterTale::
	msgbox SootopolisInteriors_Text_BellStory, MSGBOX_AUTOCLOSE
	release
	end

SootopolisInteriors_EventScript_DragonResearcher::
    lock
	faceplayer
	checkitem ITEM_TM_DRAGON_BREATH
	goto_if_eq VAR_RESULT, TRUE, SootopolisInteriors_EventScript_GaveDB
	msgbox SootopolisInteriors_Text_ResearchingDragons, MSGBOX_DEFAULT
	giveitem ITEM_TM_DRAGON_BREATH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

SootopolisInteriors_EventScript_GaveDB::
    msgbox SootopolisInteriors_Text_GaveDB, MSGBOX_AUTOCLOSE
    release
    end

SootopolisInteriors_Text_ResearchingDragons:
	.string "The Dragon type is, in my humble\n"
	.string "opinion, the most eye-grabbing\l"
	.string "of the whole lot.\p"
	.string "Hulking, commanding creatures that\n"
	.string "harness some sort of arcane power...\p"
	.string "I can think of nothing cooler!\p"
	.string "Not every Pokémon can be a Dragon,\n"
	.string "but there's a bunch out there that\l"
	.string "can conjure similar energy.\p"
	.string "Here, have this TM; it'll allow\n"
	.string "the taught Pokémon to spew\l"
	.string "violent dragon breath!$"

SootopolisInteriors_Text_GaveDB:
	.string "Tales tell of the most powerful\n"
	.string "of all Dragons, the great Rayquaza.\p"
	.string "I'd love to see it someday.$"

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

SootopolisInteriors_Text_BringHealBell:
	.string "Here's something you can do for me if\n"
	.string "you're wanting to become a\l"
	.string "true bell afficionado.\p"
	.string "There is a Pokémon move called\n"
	.string "“Heal Bell”.\l"
	.string "Find one that knows that move and\l"
	.string "bring it here.$"

SootopolisInteriors_Text_HealBellHint:
	.string "Ah, do you want a hint for a Pokémon\n"
	.string "that can learn it?…\p"
	.string "Well, as they say,\n"
	.string "For Pigs the Bell Tolls.$"

SootopolisInteriors_Text_HaveSootheBell:
	.string "I can hear a warm dingling coming\n"
	.string "from your Pokémon party!\p"
	.string "I see you've learned the joys\n"
	.string "of Heal Bell.\p"
	.string "Within you I can sense a true\n"
	.string "Bell Fanatic! Ha-ha!\l"
	.string "We share a kinship, you and I!\p"
	.string "Take this; it's a token\n"
	.string "of our friendship!$"

SootopolisInteriors_Text_BellStory:
	.string "I trust you enough to confide in you\n"
	.string "regarding… my biggest regret as a\l"
	.string "Bell Fanatic.\p"
	.string "I once owned a Pokémon called Lunaster.\n"
	.string "Friendly little bugger.\l"
	.string "It, too, loved the ringing of brass.\p"
	.string "It used its power to help me create a\n"
	.string "large, magical bell… Lunaster kept\l"
	.string "what it actually would do\l"
	.string "when rung a secret.\p"
	.string "Until eventually, I learned the truth.\p"
	.string "That bell could turn humans\n"
	.string "into Saintisow.\l"
	.string "It was… unnatural sorcery.\p"
	.string "I sealed the magic bell away, in a\n"
	.string "secret location.\p"
	.string "Lunaster felt so betrayed,\n"
	.string "that it ran away.\p"
	.string "I tend to believe it was just trying\n"
	.string "to cause harmless mischief,\l"
	.string "and didn't realize the consequences.\p"
	.string "Let that be a cautionary tale to you,\n"
	.string "fellow Bell Fanatic.$"

SootopolisInteriors_Text_LunasterDefeated:
	.string "…Oh?… Lunaster, it…\n"
	.string "found the magic bell.\l"
	.string "And you put a stop to it using\l"
	.string "said bell for its own gain…\p"
	.string "I see.\p"
	.string "Well, {PLAYER}, one thing\n"
	.string "is for sure.\p"
	.string "I am immensely grateful that a\n"
	.string "loose end I had wanted to forget\l"
	.string "has been properly dealt with.\p"
	.string "You are more than worthy of taking my\n"
	.string "throne as the Bell Master!$"
