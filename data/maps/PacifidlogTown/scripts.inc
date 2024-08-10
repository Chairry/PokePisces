.set LOCALID_PACIFBIRCH, 20

PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PacifidlogTown_OnFrame
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 2, PacifidlogTown_EventScript_TakePlayerToLab
	.2byte 0

PacifidlogTown_EventScript_TakePlayerToLab::
	lock
	playse SE_PIN
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchNotice
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerNotice
	waitmovement 0
	speakername PacifidlogTown_Text_NameBirch
	msgbox PacifidlogTown_Text_GladToSeeYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk1
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk1
	waitmovement 0
	msgbox PacifidlogTown_Text_PacifidlogTownIsNice, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk2
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk2
	waitmovement 0
	msgbox PacifidlogTown_Text_ResearchingTheLegends, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PACIFBIRCH, PacifidlogTown_Movement_BirchWalk3
	applymovement OBJ_EVENT_ID_PLAYER, PacifidlogTown_Movement_PlayerWalk3
	waitmovement 0
	msgbox PacifidlogTown_Text_CouldUseYourHelp, MSGBOX_DEFAULT
	speakername NULL
	clearflag FLAG_PISCES_A
	clearflag FLAG_PISCES_B
	clearflag FLAG_PISCES_C
	clearflag FLAG_PISCES_D
	clearflag FLAG_PISCES_E
	clearflag FLAG_PISCES_F
	clearflag FLAG_HIDE_TEAM_OZONE_COSMOSS
	setflag FLAG_HIDE_LAB_RANGERS
	warp MAP_BIRCH_MARITIME_LAB, 9, 14
	waitstate
	release
	end

PacifidlogTown_Movement_BirchNotice:
	emote_exclamation_mark
	jump_in_place_right
	walk_fast_right
	walk_fast_right
	step_end

PacifidlogTown_Movement_PlayerNotice:
	face_left
	delay_8
	walk_left
	walk_left
	step_end

PacifidlogTown_Movement_BirchWalk1:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

PacifidlogTown_Movement_PlayerWalk1:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PacifidlogTown_Movement_BirchWalk2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_left
	step_end

PacifidlogTown_Movement_PlayerWalk2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_left
	step_end

PacifidlogTown_Movement_BirchWalk3:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

PacifidlogTown_Movement_PlayerWalk3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_RoadblockingFisherman_1::
	lockall
	msgbox PacifidlogTown_Text_CantGoPastUs1
	releaseall
	end

PacifidlogTown_EventScript_RoadblockingFisherman_2::
	lockall
	msgbox PacifidlogTown_Text_CantGoPastUs2
	releaseall
	end

PacifidlogTown_EventScript_BetatestingRoadblock::
	msgbox PacifidlogTown_Text_Roadblockdeactivated, MSGBOX_NPC
	setflag FLAG_PACIFIDLOG_ROADBLOCK
	end

PacifidlogTown_EventScript_RestingSailor::
	msgbox PacifidlogTown_Text_RestingSailor, MSGBOX_NPC
	end

PacifidlogTown_EventScript_SwimmerF1::
	msgbox PacifidlogTown_Text_SwimmerF1, MSGBOX_NPC
	end

PacifidlogTown_EventScript_SwimmerF2::
	msgbox PacifidlogTown_Text_SwimmerF2, MSGBOX_NPC
	end

PacifidlogTown_EventScript_StockingSailor::
	msgbox PacifidlogTown_Text_StockingSailor, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Wayfarer::
	msgbox PacifidlogTown_Text_Wayfarer, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Seasheller1::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SEASHELL_1, PacifidlogTown_EventScript_GaveShell
	msgbox PacifidlogTown_Text_HaveThisShell, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SEASHELL_1
	release
	end

PacifidlogTown_EventScript_GaveShell::
	msgbox PacifidlogTown_Text_Seasheller1, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_EventScript_Seasheller2::
	msgbox PacifidlogTown_Text_Seasheller2, MSGBOX_NPC
	end

PacifidlogTown_EventScript_GiddyWoman::
	msgbox PacifidlogTown_Text_GiddyWoman, MSGBOX_NPC
	end

PacifidlogTown_EventScript_ManWorkingOut::
	msgbox PacifidlogTown_Text_ManWorkingOut, MSGBOX_NPC
	end

PacifidlogTown_EventScript_WaterFisher1::
	msgbox PacifidlogTown_Text_WaterFisher1, MSGBOX_NPC
	end

PacifidlogTown_EventScript_WaterFisher2::
	msgbox PacifidlogTown_Text_WaterFisher2, MSGBOX_NPC
	end

PacifidlogTown_EventScript_CoralScientist::
	msgbox PacifidlogTown_Text_CoralScientist, MSGBOX_NPC
	end

PacifidlogTown_EventScript_FishScientist::
	msgbox PacifidlogTown_Text_FishScientist, MSGBOX_NPC
	end

PacifidlogTown_EventScript_RunningTuber::
	msgbox PacifidlogTown_Text_RunningTuber, MSGBOX_NPC
	end

PacifidlogTown_EventScript_NorthToSkyPillar::
	msgbox PacifidlogTown_Text_NorthToSkyPillar, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_EastToFlotshoreTrail::
	msgbox PacifidlogTown_Text_EastToFlotshoreTrail, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_LabSign::
	msgbox PacifidlogTown_Text_LabSign, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_SadFisherHouse::
	msgbox PacifidlogTown_Text_SadFisherHouse, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_PacifidlogTownSign::
	msgbox PacifidlogTown_Text_PacifidlogTownSign, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_BigCoral::
	msgbox PacifidlogTown_Text_BigCoral, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_BoxLabel::
	msgbox PacifidlogTown_Text_BoxLabel, MSGBOX_SIGN
	end

PacifidlogTown_EventScript_BrineyFastTravel::
	lock
	faceplayer
	speakername PacifidlogTown_Text_NameBriney
	msgbox PacifidlogTown_Text_WantToVoyage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_EventScript_WarpToTidal
	msgbox PacifidlogTown_Text_IllBeHere, MSGBOX_AUTOCLOSE
	speakername NULL
	release
	end

PacifidlogTown_EventScript_WarpToTidal::
	msgbox PacifidlogTown_Text_BonVoyage, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_SS_TIDAL_MID_TERIORS, 33, 4
	release
	end

PacifidlogTown_Text_NameBirch:
	.string "Dad$"

PacifidlogTown_Text_NameBriney:
	.string "Cpt. Briney$"

PacifidlogTown_Text_WantToVoyage:
	.string "wanna go to ss tidle$"

PacifidlogTown_Text_IllBeHere:
	.string "ill be waitin$"

PacifidlogTown_Text_BonVoyage:
	.string "bon voyage$"

PacifidlogTown_Text_FastRunningCurrent:
	.string "The sea between PACIFIDLOG and\n"
	.string "SLATEPORT has a fast-running tide.\p"
	.string "If you decide to SURF, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "The SKY PILLAR?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in PACIFIDLOG,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

PacifidlogTown_Text_GladToSeeYou:
	.string "Welcome home, kiddo!\p"
	.string "(Your dad looks a bit tired.)\p"
	.string "Your… uh… your vessel was a mighty bit\n"
	.string "off-schedule.\l"
	.string "I've been planted here for a while!\l"
	.string "It's all worth it in the end to see my\l"
	.string "little professor prodigy!\p"
	.string "Listen, I know it's not Littleroot,\n"
	.string "but Pacifidlog is a lovely town that has\l"
	.string "welcomed me with open arms.\l"
	.string "Let's take a quick jog to the lab!$"

PacifidlogTown_Text_PacifidlogTownIsNice:
	.string "Feeling a bit nostalgic, huh? Ha,\n"
	.string "it feels like just yesterday when you\l"
	.string "left the nest to go on your journey!\p"
	.string "(You think about how you\n"
	.string "cut your journey short last time.\l"
	.string "It makes you wistful…)\p"
	.string "Aw, why the frown, {PLAYER}?\n"
	.string "Don't ever think you let\l"
	.string "your old man down.\l"
	.string "You've done well for yourself.\p"
	.string "…\p"
	.string "…What happened to Norman's kid?\p"
	.string "Hmm…\n"
	.string "good question.\p"
	.string "Shortly into their reign as the\n"
	.string "Champion, they disappeared.\l"
	.string "Their family seems to know what's up,\l"
	.string "but they haven't divulged anything.\l"
	.string "It's been left a mystery.\p"
	.string "…I can see that you\n"
	.string "probably wanted to reconnect with them,\l"
	.string "kiddo.\p"
	.string "I'll try and pry some more\n"
	.string "with Norman later.$"

PacifidlogTown_Text_ResearchingTheLegends:
	.string "You know…\p"
	.string "…Hoenn has changed a lot since\n"
	.string "last time, {PLAYER}.\l"
	.string "It's practically a new region!\p"
	.string "And, y'know, I think it'd be very\n"
	.string "fulfilling to explore it again!\p"
	.string "(You begin to feel a deep\n"
	.string "resolve brewing…)\p"
	.string "Of course, I'd love to\n"
	.string "have us stay here and have\l"
	.string "a quiet vacation.\l"
	.string "But there's always time to relax and\l"
	.string "catch up.\p"
	.string "I sense that you want a do-over.\n"
	.string "A chance to go above and beyond!\l"
	.string "That's the {PLAYER} I love.$"

PacifidlogTown_Text_CouldUseYourHelp:
	.string "(You nod, determined, at your dad.)\p"
	.string "That look in your eye!\n"
	.string "It's tenacious!\p"
	.string "Well, let's get this show on the road.\p"
	.string "Come on in; I'll get you set up.$"

PacifidlogTown_Text_CantGoPastUs1:
	.string "(There are two men attempting\n"
	.string "to lift a box.)\p"
	.string "W-What did the boss stuff into\n"
	.string "this box again?\p"
	.string "...200 pounds of fish!? Ridiculous!\p"
	.string "(Perhaps it is best to leave them be.)$"

PacifidlogTown_Text_CantGoPastUs2:
	.string "(There are two men attempting\n"
	.string "to lift a box.)\p"
	.string "You know, I wish we could just push\n"
	.string "the crate off the dock and let\l"
	.string "the Vangar have at it.\p"
	.string "...But then I'd get fired.\p"
	.string "(Perhaps it is best to leave them be.)$"

PacifidlogTown_Text_Roadblockdeactivated:
	.string "roadblock off$"

PacifidlogTown_Text_RestingSailor:
	.string "Takin' the load off today before\n"
	.string "me n' the other sailors\l"
	.string "head out westward.\p"
	.string "Pacifidlog is the perfect lazy town\n"
	.string "to forget about work in, I'd say!$"

PacifidlogTown_Text_SwimmerF1:
	.string "Pacifidlog's water is a breathtaking\n"
	.string "place to take a dip in!\p"
	.string "These coral structures blow my mind!$"

PacifidlogTown_Text_SwimmerF2:
	.string "Last week I stubbed my toe hopping\n"
	.string "into the water on these docks.\l"
	.string "There's untold amounts of jagged\l"
	.string "coral strewn about down there...$"

PacifidlogTown_Text_StockingSailor:
	.string "Dum-dee-dum-dee-dum...\p"
	.string "Oh? Why am I stocking\n"
	.string "lox into this barrel?\p"
	.string "Strict orders from my superior!\n"
	.string "He said it'd be kinda funny.$"

PacifidlogTown_Text_Wayfarer:
	.string "Rumor has it that there's a land full\n"
	.string "of really tough battlers due south.\p"
	.string "(You look southward and can make out\n"
	.string "a few islands made of golden rocks.)\p"
	.string "What, are you wanting to check it out\n"
	.string "someday? Be my guest!$"

PacifidlogTown_Text_HaveThisShell:
	.string "Hey! Lookit one of these cool\n"
	.string "seashells I found in the water!\p"
	.string "Do you like collecting shells too?\n"
	.string "I'll let you keep it if you promise\l"
	.string "to take care of it!$"

PacifidlogTown_Text_Seasheller1:
	.string "I heard from my friend that\n"
	.string "there's a nice lady in Sootopolis\l"
	.string "that makes a special item\l"
	.string "out of sea shells!\p"
	.string "And I think something else, but...\n"
	.string "I forgot that part.$"

PacifidlogTown_Text_Seasheller2:
	.string "Mom told me to stop runnin' on\n"
	.string "the docks. Hah! No way that I'll get\l"
	.string "hurt! The wood isn't THAT slippery!\p"
	.string "(His ankles and shins are clearly\n"
	.string "bruised all over.)$"

PacifidlogTown_Text_GiddyWoman:
	.string "I'm positively BEAMING!\n"
	.string "Pacifidlog is such an underrated,\l"
	.string "beautiful Hoenn locale!$"

PacifidlogTown_Text_ManWorkingOut:
	.string "These coral branches can double as\n"
	.string "pull-up bars! I know, I've tried!\p"
	.string "They're surprisingly rock solid.\p"
	.string "Except when they're not. You kinda\n"
	.string "have to figure that out through\l"
	.string "trial and error.$"

PacifidlogTown_Text_WaterFisher1:
	.string "I don't know about you, but I feel like\n"
	.string "I pull better catches the higher up\l"
	.string "my post is.\p"
	.string "I got a long enough rod to pull it off!\p"
	.string "Stop snickering!$"

PacifidlogTown_Text_WaterFisher2:
	.string "The Snelfrend around here are too nice\n"
	.string "for their own good. I want to reel up\l"
	.string "some actual fish, but every time\l"
	.string "I cast out, one of these friendly\l"
	.string "buggers clings to the hook\l"
	.string "and won't let go!$"

PacifidlogTown_Text_CoralScientist:
	.string "Hello, {PLAYER}. I've been helping\n"
	.string "your dad with researching the biology\l"
	.string "of the healthy coral deposits in\l"
	.string "the waters surrounding Pacifidlog.\p"
	.string "He seems to think that they can\n"
	.string "be used as part of a plan to\l"
	.string "clean up the water pollution\l"
	.string "in the bigger cities, but\l"
	.string "I'm not so sure it's that easy...$"

PacifidlogTown_Text_FishScientist:
	.string "The Water and Rock type POKéMON\n"
	.string "Marinaroc are likely the cause\l"
	.string "of Pacifidlog Town's extremely\l"
	.string "healthy oceanic habitat.\p"
	.string "You see, {PLAYER}, they are able to\n"
	.string "filter the water they swim through.\l"
	.string "They love doing their part to\l"
	.string "keep the natural coral here healthy.\p"
	.string "They prove very hard to fish\n"
	.string "up because of their weight, too;\l"
	.string "perfect for avoiding trophy hunting\l"
	.string "or a potential overfishing problem!$"

PacifidlogTown_Text_RunningTuber:
	.string "VAN-GUARD!\p"
	.string "(The child brandishes a balloon\n"
	.string "cutlass at you.\l"
	.string "You dramatically feign surrender.)\p"
	.string "That's right! I'M the pirate captain!\n"
	.string "YARRR!$"

PacifidlogTown_Text_NorthToSkyPillar:
	.string "NORTH: SKY PILLAR\p"
	.string "We ask you to respect this historical\n"
	.string "monument and to keep it clean.$"

PacifidlogTown_Text_EastToFlotshoreTrail:
	.string "EAST: FLOTSHORE TRAIL\p"
	.string "Mondays through Thursdays are\n"
	.string "scheduled bulk-fishing days.\l"
	.string "All recreational fishers and swimmers\l"
	.string "should be respectful and stay out\l"
	.string "of the way on those dates.$"

PacifidlogTown_Text_LabSign:
	.string "PROFESSOR BIRCH'S\n"
	.string "MARITIME POKéMON LAB$"

PacifidlogTown_Text_SadFisherHouse:
	.string "See me if you're serious about\n"
	.string "fishing for strong POKéMON.$"

PacifidlogTown_Text_PacifidlogTownSign:
	.string "PACIFIDLOG TOWN\p"
	.string "Where the morning sun\n"
	.string "smiles upon the waters.$"

PacifidlogTown_Text_BigCoral:
	.string "(It's a large natural\n"
	.string "structure made of coral.)$"

PacifidlogTown_Text_BoxLabel:
	.string "(The box is labelled...)\p"
	.string "DINNER FOR THREE$"
