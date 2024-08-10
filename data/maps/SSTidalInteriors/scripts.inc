SSTidalInteriors_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalInteriors_OnFrame
	.byte 0

SSTidalInteriors_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, SSTidalInteriors_EventScript_AllowedToLeave
	.2byte 0

SSTidalInteriors_EventScript_AllowedToLeave::
	lockall
	playse SE_SUCCESS
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setflag FLAG_HIDE_SSTIDAL_SAILOR
	msgbox SSTidalInteriors_Text_AllowedToLeave, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SSTidalInteriors_EventScript_PlayerDesk::
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, SSTidalInteriors_EventScript_WantToQuickStart
	setflag FLAG_PISCES_E
	msgbox SSTidalInteriors_Text_PlayerDesk, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_PlayerBed::
	goto_if_set FLAG_PISCES_F, SSTidalInteriors_EventScript_FinalQSTrigger
	goto_if_set FLAG_PISCES_E, SSTidalInteriors_EventScript_BedQSTrigger
	msgbox SSTidalInteriors_Text_PlayerBed, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_BedQSTrigger::
	setflag FLAG_PISCES_F
	msgbox SSTidalInteriors_Text_PlayerBed, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_FinalQSTrigger::
	playse SE_SUCCESS
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	msgbox SSTidalInteriors_Text_PlayerBed, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_WantToQuickStart::
	msgbox SSTidalInteriors_Text_WantToQuickStart, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SSTidalInteriors_EventScript_QuickStart
	goto_if_eq VAR_RESULT, NO, SSTidalInteriors_EventScript_NoQuickStart
	end

SSTidalInteriors_EventScript_QuickStart::
	lockall
	clearflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	waitstate
	clearflag FLAG_HIDE_BIRCH_AFTER_STARTER
	setflag FLAG_HIDE_BIRCH_BEFORE_STARTER
	setflag FLAG_BRINEY_MIDGAME_VISIT
	special HealPlayerParty
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	bufferleadmonspeciesname STR_VAR_1
	message SSTidalInteriors_Text_ReceivedStarter
	waitmessage
	playfanfare MUS_SLOTS_JACKPOT
	waitfanfare
	msgbox SSTidalInteriors_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SSTidalInteriors_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, SSTidalInteriors_EventScript_GivePokedex
	end

SSTidalInteriors_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto SSTidalInteriors_EventScript_GivePokedex
	end

SSTidalInteriors_EventScript_GivePokedex::
	call SSTidalInteriors_EventScript_ReceivePokedex
	call SSTidalInteriors_EventScript_GivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	setflag FLAG_HIDE_LAB_RANGERS
	warp MAP_SKY_PILLAR_NEW, 20, 27
	waitstate
	releaseall
	end

SSTidalInteriors_EventScript_ReceivePokedex::
	playfanfare MUS_OBTAIN_ITEM
	message SSTidalInteriors_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	return

SSTidalInteriors_EventScript_GivePokeBalls::
	giveitem ITEM_POKE_BALL, 10
	call_if_eq VAR_RESULT, FALSE, SSTidalInteriors_EventScript_NoRoomForPokeBalls
	msgbox SSTidalInteriors_Text_SkyPillarTeleport, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

SSTidalInteriors_EventScript_NoRoomForPokeBalls::
	msgbox SSTidalInteriors_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

SSTidalInteriors_EventScript_NoQuickStart::
	msgbox SSTidalInteriors_Text_ComeBackIfQuickStart, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_Drake::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_DrakeLeave
	setflag FLAG_PISCES_A
	msgbox SSTidalInteriors_Text_Drake, MSGBOX_DEFAULT
	speakername SSTidalInteriors_Text_NameDrake
	msgbox SSTidalInteriors_Text_DrakeCont, MSGBOX_DEFAULT
	speakername NULL
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_DrakeLeave::
	speakername SSTidalInteriors_Text_NameDrake
	msgbox SSTidalInteriors_Text_DrakeLeave, MSGBOX_NPC
	speakername NULL
	release
	end

SSTidalInteriors_EventScript_GymChallenger::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_GymChallengerLeave
	setflag FLAG_PISCES_B
	msgbox SSTidalInteriors_Text_GymChallenger, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_GymChallengerLeave::
	msgbox SSTidalInteriors_Text_GymChallengerLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_DevonEmployee::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_DevonEmployeeLeave
	setflag FLAG_PISCES_C
	msgbox SSTidalInteriors_Text_DevonEmployee, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_DevonEmployeeLeave::
	msgbox SSTidalInteriors_Text_DevonEmployeeLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_TeamAquaMale::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_TAMLeave
	setflag FLAG_PISCES_D
	msgbox SSTidalInteriors_Text_TeamAquaMale, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_TAMLeave::
	msgbox SSTidalInteriors_Text_TAMLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_TeamAquaFemale::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, SSTidalInteriors_EventScript_TAFLeave
	setflag FLAG_PISCES_D
	msgbox SSTidalInteriors_Text_TeamAquaFemale, MSGBOX_DEFAULT
	call_if_set FLAG_PISCES_A, SSTidalInteriors_EventScript_CheckFlags1
	release
	end

SSTidalInteriors_EventScript_TAFLeave::
	msgbox SSTidalInteriors_Text_TAFLeave, MSGBOX_NPC
	release
	end

SSTidalInteriors_EventScript_CheckFlags1::
	call_if_set FLAG_PISCES_B, SSTidalInteriors_EventScript_CheckFlags2
	return

SSTidalInteriors_EventScript_CheckFlags2::
	call_if_set FLAG_PISCES_C, SSTidalInteriors_EventScript_CheckFlags3
	return

SSTidalInteriors_EventScript_CheckFlags3::
	call_if_set FLAG_PISCES_D, SSTidalInteriors_EventScript_CheckFlags4
	return

SSTidalInteriors_EventScript_CheckFlags4::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	return

SSTidalInteriors_EventScript_Janitor::
	msgbox SSTidalInteriors_Text_Janitor, MSGBOX_NPC
	end

SSTidalInteriors_EventScript_LeftSailor::
	msgbox SSTidalInteriors_Text_LeftSailor, MSGBOX_NPC
	end

SSTidalInteriors_EventScript_RightSailor::
	msgbox SSTidalInteriors_Text_RightSailor, MSGBOX_NPC
	end

SSTidalInteriors_EventScript_RoomSign1::
	msgbox SSTidalInteriors_Text_RoomSign1, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_RoomSign2::
	msgbox SSTidalInteriors_Text_RoomSign2, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_RoomSign3::
	msgbox SSTidalInteriors_Text_RoomSign3, MSGBOX_SIGN
	end

SSTidalInteriors_EventScript_RoomSign4::
	msgbox SSTidalInteriors_Text_RoomSign4, MSGBOX_SIGN
	end

SSTidalInteriors_Text_AllowedToLeave:
	.string "ATTENTION ALL PASSENGERS!\p"
	.string "The S.S. Tidal has hauled anchor\n"
	.string "upon her destination, Pacifidlog Town!\p"
	.string "Please prepare to disembark.$"

SSTidalInteriors_Text_PlayerDesk:
	.string "It's your desk.\n"
	.string "There are many research papers\l"
	.string "stuffed inside, pertaining to the\l"
	.string "study of Seviian POKéMON species.$"

SSTidalInteriors_Text_PlayerBed:
	.string "It's your bed.\n"
	.string "It's neatly made.$"

SSTidalInteriors_Text_WantToQuickStart:
	.string "You have done the correct sequence\n"
	.string "of events to initiate the\l"
	.string "Quick Start feature.\p"
	.string "Quick Start will allow you to jump\n"
	.string "ahead of all intro dialogue and\l"
	.string "give you all you need to start\l"
	.string "your journey.\p"
	.string "Would you like to use Quick Start?$"

SSTidalInteriors_Text_ReceivedStarter:
	.string "{PLAYER} has received their\n"
	.string "Starter POKéMON, {STR_VAR_1}!$"

SSTidalInteriors_Text_Nickname:
	.string "Give it a nickname?$"

SSTidalInteriors_Text_ReceivedPokedex:
	.string "{PLAYER} has received\n"
	.string "a POKéDEX!$"

SSTidalInteriors_Text_SkyPillarTeleport:
	.string "You will now be teleported to\n"
	.string "the entrance of Sky Pillar.\p"
	.string "We hope you enjoyed Quick Start!$"

SSTidalInteriors_Text_OhYourBagsFull:
	.string "bag full dooooooood$"

SSTidalInteriors_Text_ComeBackIfQuickStart:
	.string "Quick Start protocol terminated.$"

SSTidalInteriors_Text_NameDrake:
	.string "Drake$"

SSTidalInteriors_Text_Drake:
	.string "Greetings.\p"
	.string "I am Drake, a master of Dragons.\p"
	.string "What brings you aboard the fine\n"
	.string "Captain Briney's vessel today?$"

SSTidalInteriors_Text_DrakeCont:
	.string "...\p"
	.string "Off to see Prof. Birch, I see.\n"
	.string "I know of the man. I had recently\l"
	.string "picked his brain regarding the\l"
	.string "Legendary POKéMON of Hoenn.\p"
	.string "As a lifelong seafarer, Legendary\n"
	.string "beings that roam the waters have\l"
	.string "become of utmost interest to me.\p"
	.string "Myths tell of a pair of large\n"
	.string "fish POKéMON that, when together,\l"
	.string "bring balance and unity to\l"
	.string "the region they inhabit.\p"
	.string "Those who believe in them\n"
	.string "attribute the recent times of peace\l"
	.string "in Hoenn to their presence.\p"
	.string "I seek to find evidence of the\n"
	.string "existence of these fabled deities.\p"
	.string "If that interests you, come\n"
	.string "seek me out in Sootopolis City.\p"
	.string "Otherwise, may the tides ebb\n"
	.string "in your favor, Trainer.$"

SSTidalInteriors_Text_DrakeLeave:
	.string "Well, well, well... it is about\n"
	.string "time for myself and the Tidal to\l"
	.string "part ways again.\p"
	.string "I shall have to pay the Captain\n"
	.string "a visit before I go.$"

SSTidalInteriors_Text_GymChallenger:
	.string "That look in your eye...\p"
	.string "You're a Trainer, aren't you?\n"
	.string "I'd battle you right now, but\l"
	.string "my POKéMON are taking time to rest.\p"
	.string "After battling the Indigo League,\n"
	.string "I thought I'd take on the Hoenn\l"
	.string "Gym Challenge as well. Another\l"
	.string "notch in the belt, y'know?\p"
	.string "I get the sense you're looking\n"
	.string "to take the challenge too, eh?\p"
	.string "(You take out your old, dusty\n"
	.string "badge case from some time ago\l"
	.string "and show the man.)\p"
	.string "Six badges... huh. Oh. These\n"
	.string "are all old ones, you know?\p"
	.string "They've recently revamped the entire\n"
	.string "gym challenge to spice things up!\p"
	.string "Even if you've done it before,\n"
	.string "I think you'll enjoy the remixed\l"
	.string "ordeals along the way.\p"
	.string "I hope I'll see you\n"
	.string "on the front lines!$"

SSTidalInteriors_Text_GymChallengerLeave:
	.string "My POKéMON and I are itching\n"
	.string "to plow through some trainers!\p"
	.string "Good luck out there!$"

SSTidalInteriors_Text_DevonEmployee:
	.string "(There is a man here buried\n"
	.string "in mountains of paperwork.)\p"
	.string "...Don't even ask.\p"
	.string "...What, you're not going away?\n"
	.string "Well... I need to let off some steam.\p"
	.string "Listen, you're young. Let this be\n"
	.string "a warning. NEVER work for any of\l"
	.string "the bigwig corporations in Hoenn.\p"
	.string "Recently, Greater Mauville Holdings\n"
	.string "bought out the formerly largest\l"
	.string "business in the region, Devon Corp.\p"
	.string "With the new hierarchy, a lot of\n"
	.string "operational protocols have been\l"
	.string "completely gutted and redone\l"
	.string "from scratch. Managers and employees\l"
	.string "alike have needed re-training.\p"
	.string "And guess who gets all the complaints?\p"
	.string "That's right! Middlemen like me.\n"
	.string "Not jolly ol' Papa Wattson, no sir!\l"
	.string "Everyone just thinks he's super!\p"
	.string "Not that Mr. Stone is a saint,\n"
	.string "but I feel like things were simpler\l"
	.string "when it was just him.\l"
	.string "What a sellout!\p"
	.string "...Sorry. My ranting went on a bit\n"
	.string "longer than expected.\l"
	.string "Thank you for letting me vent.$"

SSTidalInteriors_Text_DevonEmployeeLeave:
	.string "(He's frantically collecting\n"
	.string "all of his strewn about files.)$"

SSTidalInteriors_Text_TeamAquaMale:
	.string "Aye! Welcome t'our room.\p"
	.string "Me sis n' I just can't get enough\n"
	.string "o' sailin' the high seas!\p"
	.string "Both'a us were in Team Aqua some\n"
	.string "time ago. I was in it thinkin'\l"
	.string "we was gonna save the oceans!\p"
	.string "But... things got out'o hand,\n"
	.string "ye could say. Team Aqua did some\l"
	.string "nasty things in pursuit'o a goal\l"
	.string "that was misguided'n the first place.\p"
	.string "They've since dissolved n' reformed.\n"
	.string "I didn't keep up wif'em, but\l"
	.string "I hope me ol' comrades are holdin'\l"
	.string "up well.$"

SSTidalInteriors_Text_TAMLeave:
	.string "Yarr harr! Another\n"
	.string "voyage awaits!$"

SSTidalInteriors_Text_TeamAquaFemale:
	.string "Aye, aye. Enjoyin' the rock\n"
	.string "o' the waves, Trainer?\p"
	.string "...Ah, yer lookin' at me funny\n"
	.string "cuz'a me outfit. Don' worry about\l"
	.string "me. I ain't a thug. 'Least, not\l"
	.string "no more.\p"
	.string "Team Aqua n' Magma disbanded soon\n"
	.string "after that whole Sootopolis ruckus.\p"
	.string "Feelin' remorseful for what they did,\n"
	.string "Maxie n' Archie put aside their\l"
	.string "differences n' formed the joint team,\l"
	.string "Team Ozone, wif' the goal o' actually\l"
	.string "doin' their part to keep the region's\l"
	.string "ecosystem healthy n' all that.\p"
	.string "I'm not cut out fer the labor\n"
	.string "they do, so I packed up n' left.\p"
	.string "Wish 'em the best, though.$"

SSTidalInteriors_Text_TAFLeave:
	.string "'S about time me bruvva n' I\n"
	.string "get on our way.$"

SSTidalInteriors_Text_Janitor:
	.string "Sweep, sweep, sweep...\p"
	.string "(She's nodding off.)\p"
	.string "...Sleep...sleep...sleep...$"

SSTidalInteriors_Text_LeftSailor:
	.string "Ever hear of the Behemoth of\n"
	.string "the mountain peaks, Groudon?\p"
	.string "It's a formidable lookin' one, I\n"
	.string "tell ya! I've been tryin' to\l"
	.string "convince my buddy here that\l"
	.string "it beats its rival in one-on-one\l"
	.string "combat, for sure!$"

SSTidalInteriors_Text_RightSailor:
	.string "You know about the Leviathan that\n"
	.string "lurks in the ocean depths, Kyogre?\p"
	.string "No contest, one of the strongest\n"
	.string "POKéMON ever. This guy across\l"
	.string "from me doesn't seem to think so.$"

SSTidalInteriors_Text_RoomSign1:
	.string "Economy Class Cabin 1$"

SSTidalInteriors_Text_RoomSign2:
	.string "Economy Class Cabin 3\n"
	.string "Reserved by Devon Corp.$"

SSTidalInteriors_Text_RoomSign3:
	.string "Economy Class Cabin 2$"

SSTidalInteriors_Text_RoomSign4:
	.string "Economy Class Cabin 4\n"
	.string "Reserved for {PLAYER}$"
