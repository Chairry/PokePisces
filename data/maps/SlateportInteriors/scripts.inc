SlateportInteriors_MapScripts::
	.byte 0

SlateportInteriors_EventScript_FanClubChairman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKE_FLUTE, SlateportInteriors_EventScript_FanClubChairmanPostFlute
	checkitem ITEM_TEACHY_TV
	goto_if_eq VAR_RESULT, TRUE, SlateportInteriors_EventScript_PokeFluteSpiel
	msgbox SlateportInteriors_Text_ILovePrimo, MSGBOX_AUTOCLOSE
	release
	end

SlateportInteriors_EventScript_PokeFluteSpiel::
	msgbox SlateportInteriors_Text_WhyItsATeachyTV, MSGBOX_DEFAULT
	playbgm MUS_RG_TEACHY_TV_MENU, FALSE
	msgbox SlateportInteriors_Text_PrimoAndFluteStory, MSGBOX_DEFAULT
	fadenewbgm MUS_SLATEPORT
	delay 32
	msgbox SlateportInteriors_Text_AnywaysLetsTrade, MSGBOX_DEFAULT
	removeitem ITEM_TEACHY_TV, 1
	giveitem ITEM_POKE_FLUTE
	setflag FLAG_RECEIVED_POKE_FLUTE
	closemessage
	release
	end

SlateportInteriors_EventScript_FanClubChairmanPostFlute::
	msgbox SlateportInteriors_Text_ILoveMyNewTV, MSGBOX_AUTOCLOSE
	release
	end

SlateportInteriors_Text_ILovePrimo:
	.string "I say, as the chairman of the club,\n"
	.string "things have rather changed\l"
	.string "over the years!\p"
	.string "Nowadays, these younger inductees\n"
	.string "are really into their\l"
	.string "Pokemon cards and whatnot.\p"
	.string "But during the club's heyday?\n"
	.string "Primo's program on the Teachy TV\l"
	.string "was all the rage...!\p"
	.string "I'm still a diehard fan.\n"
	.string "If only I hadn't lost my vintage\l"
	.string "Teachy TV Set from years ago...$"

SlateportInteriors_Text_WhyItsATeachyTV:
	.string "!\n"
	.string "W-Why, it's a mint condition...\l"
	.string "...T-T-TEACHY TV SET!!!$"

SlateportInteriors_Text_PrimoAndFluteStory:
	.string "We share a kindred love for\n"
	.string "the program, you and I!\p"
	.string "Golly, my favorite episode is\n"
	.string "loaded onto here. Surely you\l"
	.string "remember “Unbolt The Rock”?\l"
	.string "It's a veritable CLASSIC.\p"
	.string "Our suave, handsome hero Primo\n"
	.string "has his path to the next city\l"
	.string "blocked by a ginormous\l"
	.string "sleeping Bolterock!\p"
	.string "OH, WHAT IS HE TO DO!?\p"
	.string "As it just so happens, in the\n"
	.string "nearby ruins is an instumental\l"
	.string "instrument; the Poke Flute.\l"
	.string "Said to awake any sleeper,\l"
	.string "no matter how giant.\p"
	.string "Primo, intelligent as ever,\n"
	.string "brings the Flute back to\l"
	.string "the Bolterock and awakens it.\p"
	.string "A fierce, drawn out battle begins\n"
	.string "between the roused creature\l"
	.string "and the hero's ragtag team...\l"
	.string "and they narrowly escape with\l"
	.string "the victory.\p"
	.string "I get goosebumps just recalling it!\n"
	.string "My stars...$"

SlateportInteriors_Text_AnywaysLetsTrade:
	.string "...Mm. I could ramble on, but let\n"
	.string "me officially trade you something\l"
	.string "equally valuable for the TV Set.\p"
	.string "It just so happens I own a second,\n"
	.string "no-longer-for-sale replica of\l"
	.string "the Poke Flute used in the show!\p"
	.string "Please, I insist on a superfan\n"
	.string "like you to give it a good home.$"

SlateportInteriors_Text_ILoveMyNewTV:
	.string "I have been binge-watching the\n"
	.string "whole Primo series on the\l"
	.string "TV Set you traded me, friend.\p"
	.string "Almost at the mid-season 19 finale,\n"
	.string "“Blinguin Gets Shot By The CIA”!\p"
	.string "It was controversial at the time.$"
