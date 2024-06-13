.set LOCALID_MOSSGUY, 1

FamilyMossCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FamilyMossCave_OnLoad
	.byte 0

FamilyMossCave_OnLoad:
	call_if_unset FLAG_SUNBEACH_TUBER_1, FamilyMossCave_EventScript_DeloadMossGuy
	end

FamilyMossCave_EventScript_DeloadMossGuy::
	setflag FLAG_TEMP_11
	removeobject LOCALID_MOSSGUY
	return

FamilyMossCave_EventScript_DevonMossGuy::
	lock
	faceplayer
	checkitem ITEM_FAMILY_MOSS
	goto_if_eq VAR_RESULT, TRUE, FamilyMossCave_EventScript_GaveFamilyMoss
	goto_if_set FLAG_TALKED_TO_MOSS_GUY, FamilyMossCave_EventScript_CheckPus
	msgbox FamilyMossCave_Text_WelcomeToTheUnderground, MSGBOX_DEFAULT
	setflag FLAG_TALKED_TO_MOSS_GUY
	specialvar VAR_RESULT, CheckPapypusAndMamypus
	goto_if_eq VAR_RESULT, TRUE, FamilyMossCave_EventScript_ReceiveFamilyMoss
	msgbox FamilyMossCave_Text_NoPus, MSGBOX_AUTOCLOSE
	release
	end

FamilyMossCave_EventScript_CheckPus::
	msgbox FamilyMossCave_Text_GonnaCheckYourParty, MSGBOX_DEFAULT
	specialvar VAR_RESULT, CheckPapypusAndMamypus
	goto_if_eq VAR_RESULT, TRUE, FamilyMossCave_EventScript_ReceiveFamilyMoss
	msgbox FamilyMossCave_Text_NoPus, MSGBOX_AUTOCLOSE
	release
	end

FamilyMossCave_EventScript_ReceiveFamilyMoss::
	msgbox FamilyMossCave_Text_HappyFamily, MSGBOX_DEFAULT
	giveitem ITEM_FAMILY_MOSS
	release
	end

FamilyMossCave_EventScript_GaveFamilyMoss::
	msgbox FamilyMossCave_Text_SevenLuvdiscSouls, MSGBOX_AUTOCLOSE
	release
	end

FamilyMossCave_Text_WelcomeToTheUnderground:
	.string "Welcome to the Underground!\n"
	.string "How are your balls?\p"
	.string "Poké-Balls, that is.\p"
	.string "Oh! I remember you from Sunbeach.\n"
	.string "Thanks again for chasing off\l"
	.string "that annoying dog.\p"
	.string "I have found the perfect mossy\n"
	.string "cave here to feast on however much\l"
	.string "lichen I can get my mits on!\p"
	.string "You know there's a Pokémon\n"
	.string "out there that loves 'em some moss\l"
	.string "too, right?\p"
	.string "They're called Papypus. Lazy lil'\n"
	.string "buggers! The males and females look\l"
	.string "a bit different. It's actually kind\l"
	.string "of rare to see 'em together in the\l"
	.string "wild, on account of the gals\l"
	.string "always roaming to find new mates.\p"
	.string "There's some males that take care\n"
	.string "of their children right in this\l"
	.string "here hidey hole. If you can catch\l"
	.string "one, and then also show up with a\l"
	.string "female in the same party, I'll\l"
	.string "give you something special to\l"
	.string "celebrate the happy family!$"

FamilyMossCave_Text_GonnaCheckYourParty:
	.string "Have you brought me the two genders\n"
	.string "of Papypus? They should be in the\l"
	.string "front two slots of your party!$"

FamilyMossCave_Text_NoPus:
	.string "Seems you don't have 'em both!\p"
	.string "That's ok; like I said, they're\n"
	.string "almost never found together.\p"
	.string "Come back when you've found 'em!$"

FamilyMossCave_Text_HappyFamily:
	.string "Aww, that's a seldom seen treat!\n"
	.string "A happy Papy family indeed!\p"
	.string "I'll give you this special item to\n"
	.string "commemorate the occasion!\p"
	.string "This Family Moss symbolizes a true\n"
	.string "connection between a Papypus\l"
	.string "and its partner.$"

FamilyMossCave_Text_SevenLuvdiscSouls:
	.string "You ever hear the legend about the\n"
	.string "deceptively ferocious and devious\l"
	.string "Tidpit that tried to become\l"
	.string "all-powerful? Sounds like\l"
	.string "total bologna to me!\p"
	.string "Apparently the Tidpit was betrayed\n"
	.string "in the eleventh hour by seven\l"
	.string "rainbow colored Luvdisc...\p"
	.string "Man! What a blunder tale!$"
