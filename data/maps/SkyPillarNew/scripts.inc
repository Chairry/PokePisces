SkyPillarNew_MapScripts::
	.byte 0

SkyPillarNew_EventScript_Granger::
	setflag FLAG_PISCES_A
	trainerbattle_single TRAINER_P_GRANGER, SkyPillarNew_Text_GrangerIntro, SkyPillarNew_Text_GrangerDefeat, SkyPillarNew_EventScript_GrangerChoice
	goto_if_unset FLAG_PISCES_B, SkyPillarNew_EventScript_GrangerEncouragement
	goto_if_unset FLAG_PISCES_C, SkyPillarNew_EventScript_GrangerEncouragement
	goto_if_set FLAG_PISCES_B, SkyPillarNew_EventScript_GrangerRoadblockOver
	msgbox SkyPillarNew_Text_GrangerPostBattle, MSGBOX_AUTOCLOSE
	end

SkyPillarNew_EventScript_GrangerChoice::
	goto_if_unset FLAG_PISCES_B, SkyPillarNew_EventScript_GrangerEncouragement
	goto_if_unset FLAG_PISCES_C, SkyPillarNew_EventScript_GrangerEncouragement
	goto_if_set FLAG_PISCES_B, SkyPillarNew_EventScript_GrangerRoadblockOver
	end

SkyPillarNew_EventScript_GrangerEncouragement::
	msgbox SkyPillarNew_Text_GrangerEncourage, MSGBOX_NPC
	releaseall
	end

SkyPillarNew_EventScript_GrangerRoadblockOver::
	msgbox SkyPillarNew_Text_GrangerAllDone, MSGBOX_AUTOCLOSE
	setflag FLAG_PACIFIDLOG_ROADBLOCK
	setflag FLAG_HIDE_BIRCH_AFTER_STARTER
	clearflag FLAG_HIDE_LAB_RANGERS
	setvar VAR_BIRCH_LAB_STATE, 6
	warp MAP_BIRCH_MARITIME_LAB, 3, 9
	waitstate
	releaseall
	end

SkyPillarNew_EventScript_Ricky::
	setflag FLAG_PISCES_B
	trainerbattle_single TRAINER_P_RICKY, SkyPillarNew_Text_RickyIntro, SkyPillarNew_Text_RickyDefeat, SkyPillarNew_EventScript_RickyChoice
	goto_if_unset FLAG_PISCES_A, SkyPillarNew_EventScript_RickyEncouragement
	goto_if_unset FLAG_PISCES_C, SkyPillarNew_EventScript_RickyEncouragement
	goto_if_set FLAG_PISCES_A, SkyPillarNew_EventScript_RickyRoadblockOver
	msgbox SkyPillarNew_Text_RickyPostBattle, MSGBOX_AUTOCLOSE
	end

SkyPillarNew_EventScript_RickyChoice::
	goto_if_unset FLAG_PISCES_A, SkyPillarNew_EventScript_RickyEncouragement
	goto_if_unset FLAG_PISCES_C, SkyPillarNew_EventScript_RickyEncouragement
	goto_if_set FLAG_PISCES_A, SkyPillarNew_EventScript_RickyRoadblockOver
	end

SkyPillarNew_EventScript_RickyEncouragement::
	msgbox SkyPillarNew_Text_RickyEncourage, MSGBOX_NPC
	end

SkyPillarNew_EventScript_RickyRoadblockOver::
	msgbox SkyPillarNew_Text_RickyAllDone, MSGBOX_AUTOCLOSE
	setflag FLAG_PACIFIDLOG_ROADBLOCK
	setflag FLAG_HIDE_BIRCH_AFTER_STARTER
	clearflag FLAG_HIDE_LAB_RANGERS
	setvar VAR_BIRCH_LAB_STATE, 6
	warp MAP_BIRCH_MARITIME_LAB, 3, 9
	waitstate
	releaseall
	end

SkyPillarNew_EventScript_Jeannie::
	setflag FLAG_PISCES_C
	trainerbattle_single TRAINER_P_JEANNIE, SkyPillarNew_Text_JeannieIntro, SkyPillarNew_Text_JeannieDefeat, SkyPillarNew_EventScript_JeannieChoice
	goto_if_unset FLAG_PISCES_A, SkyPillarNew_EventScript_JeannieEncouragement
	goto_if_unset FLAG_PISCES_B, SkyPillarNew_EventScript_JeannieEncouragement
	goto_if_set FLAG_PISCES_A, SkyPillarNew_EventScript_JeannieRoadblockOver
	msgbox SkyPillarNew_Text_JeanniePostBattle, MSGBOX_AUTOCLOSE
	end

SkyPillarNew_EventScript_JeannieChoice::
	goto_if_unset FLAG_PISCES_A, SkyPillarNew_EventScript_JeannieEncouragement
	goto_if_unset FLAG_PISCES_B, SkyPillarNew_EventScript_JeannieEncouragement
	goto_if_set FLAG_PISCES_A, SkyPillarNew_EventScript_JeannieRoadblockOver
	end

SkyPillarNew_EventScript_JeannieEncouragement::
	msgbox SkyPillarNew_Text_JeannieEncourage, MSGBOX_NPC
	end

SkyPillarNew_EventScript_JeannieRoadblockOver::
	msgbox SkyPillarNew_Text_JeannieAllDone, MSGBOX_AUTOCLOSE
	setflag FLAG_PACIFIDLOG_ROADBLOCK
	setflag FLAG_HIDE_BIRCH_AFTER_STARTER
	clearflag FLAG_HIDE_LAB_RANGERS
	setvar VAR_BIRCH_LAB_STATE, 6
	warp MAP_BIRCH_MARITIME_LAB, 3, 9
	waitstate
	releaseall
	end

SkyPillarNew_EventScript_Man::
	msgbox SkyPillarNew_Text_Man, MSGBOX_NPC
	end

SkyPillarNew_EventScript_Forester::
	msgbox SkyPillarNew_Text_Forester, MSGBOX_NPC
	end

SkyPillarNew_EventScript_Scientist::
	msgbox SkyPillarNew_Text_Scientist, MSGBOX_NPC
	end

SkyPillarNew_EventScript_SkyPillarSign::
	msgbox SkyPillarNew_Text_SkyPillarSign, MSGBOX_SIGN
	end

SkyPillarNew_EventScript_RayquazaStatue::
	msgbox SkyPillarNew_Text_RayquazaStatue, MSGBOX_SIGN
	end

SkyPillarNew_Text_GrangerIntro:
	.string "I'm told your name is {PLAYER}!\p"
	.string "Well, {PLAYER}, I'll give you a real\n"
	.string "taste of what battling is like!$"

SkyPillarNew_Text_GrangerDefeat:
	.string "You're a natural!$"

SkyPillarNew_Text_GrangerPostBattle:
	.string "this probs shouldnt show up$"

SkyPillarNew_Text_GrangerEncourage:
	.string "I may be mowed, but you\n"
	.string "owe my buddies a bout, too!$"

SkyPillarNew_Text_GrangerAllDone:
	.string "Ah, {PLAYER}!\p"
	.string "You've proven yourself a\n"
	.string "blossoming talent!\p"
	.string "We have nothing left to assist you\n"
	.string "with. Explore Hoenn to your heart's\l"
	.string "content. Be safe out there!$"

SkyPillarNew_Text_RickyIntro:
	.string "I sense a FIRE'n you, trainer!\p"
	.string "Allow me to help you stoke them\n"
	.string "there flames; the embers of a\l"
	.string "fresh new journey!!$"

SkyPillarNew_Text_RickyDefeat:
	.string "I KNEW you'd burn bright!$"

SkyPillarNew_Text_RickyPostBattle:
	.string "prob shouldnt show up$"

SkyPillarNew_Text_RickyEncourage:
	.string "Hey hey hey, trainer.\p"
	.string "You put out my flame, but my\n"
	.string "pals are still itchin' to test ya.$"

SkyPillarNew_Text_RickyAllDone:
	.string "You're on FIRE!!\p"
	.string "Burned through the three of us like\n"
	.string "we was dry paper!\p"
	.string "Keep it up, don't let that passion'a\n"
	.string "yours die out. Go show Hoenn\l"
	.string "what you're made of!$"

SkyPillarNew_Text_JeannieIntro:
	.string "Oh-ho-ho! Crashing right on the scene\n"
	.string "is the lovely {PLAYER}!\p"
	.string "I'd love to test your meddle in\n"
	.string "a quick battle!$"

SkyPillarNew_Text_JeannieDefeat:
	.string "Your flow is impeccable!$"

SkyPillarNew_Text_JeanniePostBattle:
	.string "TRAINER DIALOGUE WOW$"

SkyPillarNew_Text_JeannieEncourage:
	.string "Keep up your stream of victories,\n"
	.string "{PLAYER}. My partners graciously\l"
	.string "await their turn.$"

SkyPillarNew_Text_JeannieAllDone:
	.string "You sure cleaned house!\p"
	.string "Take a moment, while you're up\n"
	.string "here, to look down upon Hoenn.\p"
	.string "...A truly grand view, isn't it?\p"
	.string "Well, what are you waiting for?\n"
	.string "the world's your oyster!\l"
	.string "Make us proud!$"

SkyPillarNew_Text_Man:
	.string "I've had this urge recently to hop\n"
	.string "down this stream and crash down\l"
	.string "that waterfall!\p"
	.string "Will I get hurt? Probably!\n"
	.string "But think of the possibilities!$"

SkyPillarNew_Text_Forester:
	.string "Oh, I'm assuming you're that\n"
	.string "trainer my friends up top are\l"
	.string "looking for.\p"
	.string "Go give 'em a proper thrashing!$"

SkyPillarNew_Text_Scientist:
	.string "These triangle-shaped stones\n"
	.string "embedded in the ground here are\l"
	.string "what we've been calling Delta Stones.\p"
	.string "They were, as far as we know,\n"
	.string "carved out hyper-meticulously\l"
	.string "by an ancient society that\l"
	.string "worshipped the POKéMON Rayquaza.\p"
	.string "The Delta Stones are even\n"
	.string "made partially out of emerald dust,\l"
	.string "a rare material.\p"
	.string "Sky Pillar is a veritable\n"
	.string "well of olden knowledge!$"

SkyPillarNew_Text_SkyPillarSign:
	.string "S K Y   P I L L A R\p"
	.string "May the almighty skyward sentinel\n"
	.string "look down upon and guide us\l"
	.string "to peace and harmony.$"

SkyPillarNew_Text_RayquazaStatue:
	.string "(It's a statue resembling\n"
	.string "Rayquaza. The visage brings back\l"
	.string "a few memories of an\l"
	.string "adventure long past...)$"


