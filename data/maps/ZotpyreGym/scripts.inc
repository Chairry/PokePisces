.set LOCALID_PHOEBE, 11
.set LOCALID_SPENSER, 10

ZotpyreGym_MapScripts::
	.byte 0

ZotpyreGym_EventScript_ReplaceColumns1::
	lock
	goto_if_gt VAR_TEMP_5, 0, ZotpyreGym_EventScript_DontReplaceColumns
	msgbox ZotpyreGym_Text_IllMoveColumns1, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_5, 1
	playse SE_M_COMET_PUNCH
	setmetatile 19, 16, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 19, 17, METATILE_OldStoneBuildings_ColumnShaft, FALSE
	setmetatile 19, 18, METATILE_OldStoneBuildings_ColumnShaft, TRUE
	setmetatile 12, 22, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 23, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 24, METATILE_OldStoneBuildings_ColumnTop, TRUE
	setmetatile 12, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 29, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 30, METATILE_OldStoneBuildings_ColumnTop, TRUE
	setmetatile 7, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 7, 29, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 19, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 19, 29, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 7, 10, METATILE_OldStoneBuildings_RelicFloor, TRUE
	setmetatile 7, 11, METATILE_OldStoneBuildings_ColumnTop, TRUE
	special DrawWholeMapView
	release
	end

ZotpyreGym_EventScript_DontReplaceColumns::
	msgbox ZotpyreGym_Text_AlreadyMovedColumns, MSGBOX_AUTOCLOSE
	release
	end

ZotpyreGym_EventScript_ReplaceColumns2::
	lock
	goto_if_gt VAR_TEMP_6, 0, ZotpyreGym_EventScript_DontReplaceColumns
	msgbox ZotpyreGym_Text_IllMoveColumns2, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_6, 1
	playse SE_M_COMET_PUNCH
	setmetatile 12, 9, METATILE_OldStoneBuildings_BottomWall, TRUE
	setmetatile 12, 10, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 12, 16, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 17, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 18, METATILE_OldStoneBuildings_ColumnTop, TRUE
	special DrawWholeMapView
	release
	end

ZotpyreGym_EventScript_CheckForVar5::
	lock
	goto_if_eq VAR_TEMP_5, 0, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar6::
	lock
	goto_if_eq VAR_TEMP_6, 0, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar5And6::
	lock
	goto_if_eq VAR_TEMP_5, 0, ZotpyreGym_EventScript_WarpAway
	goto_if_eq VAR_TEMP_6, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckAgainstVar5::
	lock
	goto_if_eq VAR_TEMP_5, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar6And5::
	lock
	goto_if_eq VAR_TEMP_6, 1, ZotpyreGym_EventScript_WarpSafety
	goto_if_eq VAR_TEMP_5, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_WarpAway::
	lock
	msgbox ZotpyreGym_Text_TheFogIsComing, MSGBOX_AUTOCLOSE
	warp MAP_ZOTPYRE_GYM, 16, 28
	waitstate
	release
	end

ZotpyreGym_EventScript_WarpSafety::
	release
	end

ZotpyreGym_EventScript_Junji::
    trainerbattle_single TRAINER_P_JUNJI, ZotpyreGym_Text_JunjiIntro, ZotpyreGym_Text_JunjiDefeated, ZotpyreGym_EventScript_JunjiExplainRelic
    msgbox ZotpyreGym_Text_JunjiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_JunjiExplainRelic::
	msgbox ZotpyreGym_Text_JunjiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Kirie::
    trainerbattle_single TRAINER_P_KIRIE, ZotpyreGym_Text_KirieIntro, ZotpyreGym_Text_KirieDefeated
    msgbox ZotpyreGym_Text_KiriePostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Shuichi::
    trainerbattle_single TRAINER_P_SHUICHI, ZotpyreGym_Text_ShuichiIntro, ZotpyreGym_Text_ShuichiDefeated
    msgbox ZotpyreGym_Text_ShuichiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Tomie::
    trainerbattle_single TRAINER_P_TOMIE, ZotpyreGym_Text_TomieIntro, ZotpyreGym_Text_TomieDefeated
    msgbox ZotpyreGym_Text_TomiePostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Azami::
    trainerbattle_single TRAINER_P_AZAMI, ZotpyreGym_Text_AzamiIntro, ZotpyreGym_Text_AzamiDefeated
    msgbox ZotpyreGym_Text_AzamiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Misaki::
    trainerbattle_single TRAINER_P_MISAKI, ZotpyreGym_Text_MisakiIntro, ZotpyreGym_Text_MisakiDefeated
    msgbox ZotpyreGym_Text_MisakiPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_Yuina::
    trainerbattle_single TRAINER_P_YUINA, ZotpyreGym_Text_YuinaIntro, ZotpyreGym_Text_YuinaDefeated
    msgbox ZotpyreGym_Text_YuinaPostBattle, MSGBOX_AUTOCLOSE
    end

ZotpyreGym_EventScript_HintGiver1::
	msgbox ZotpyreGym_Text_Hint1, MSGBOX_NPC
	end

ZotpyreGym_EventScript_HintGiver2::
	msgbox ZotpyreGym_Text_Hint2, MSGBOX_NPC
	end

ZotpyreGym_EventScript_LeaderBattle::
	lock
	faceplayer
	msgbox ZotpyreGym_Text_LeadersIntro, MSGBOX_DEFAULT
    trainerbattle_two_trainers TRAINER_P_PHOEBE, ZotpyreGym_Text_PhoebeDefeat, TRAINER_P_SPENSER, ZotpyreGym_Text_SpenserDefeat, ZotpyreGym_EventScript_LeadersDefeated, NO_MUSIC
	goto ZotpyreGym_EventScript_LeadersDefeated
	release
	end

ZotpyreGym_EventScript_EncLeft::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, ZotpyreGym_Movement_WalkLeft
	goto ZotpyreGym_EventScript_EncounterLeaders
	end

ZotpyreGym_Movement_WalkLeft:
	walk_left
	step_end

ZotpyreGym_EventScript_EncRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, ZotpyreGym_Movement_WalkRight
	goto ZotpyreGym_EventScript_EncounterLeaders
	end

ZotpyreGym_Movement_WalkRight:
	walk_right
	step_end

ZotpyreGym_EventScript_EncounterLeaders::
	lock
	speakername ZotpyreGym_Text_NameSpenser
	applymovement OBJ_EVENT_ID_PLAYER, ZotpyreGym_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_SPENSER, ZotpyreGym_Movement_SpenserTalk
	msgbox ZotpyreGym_Text_Spenser1, MSGBOX_DEFAULT
	speakername ZotpyreGym_Text_NamePhoebe
	applymovement LOCALID_PHOEBE, ZotpyreGym_Movement_PhoebeTurn
	msgbox ZotpyreGym_Text_Phoebe1, MSGBOX_DEFAULT
	speakername ZotpyreGym_Text_NameSpenser
	applymovement LOCALID_SPENSER, ZotpyreGym_Movement_SpenserTalk
	msgbox ZotpyreGym_Text_Spenser2, MSGBOX_DEFAULT
	speakername ZotpyreGym_Text_NamePhoebe
	applymovement LOCALID_PHOEBE, ZotpyreGym_Movement_PhoebeTalk
	msgbox ZotpyreGym_Text_Phoebe2, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_PHOEBE, ZotpyreGym_Text_PhoebeDefeat, TRAINER_P_SPENSER, ZotpyreGym_Text_SpenserDefeat, ZotpyreGym_EventScript_LeadersDefeated, NO_MUSIC
	goto ZotpyreGym_EventScript_LeadersDefeated
	release
	end

ZotpyreGym_Movement_WalkUp:
	walk_up
	step_end

ZotpyreGym_Movement_SpenserTalk:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

ZotpyreGym_Movement_PhoebeTurn:
	face_right
	step_end

ZotpyreGym_Movement_PhoebeTalk:
	face_right
	delay_8
	delay_8
	delay_8
	face_down
	step_end

ZotpyreGym_EventScript_LeadersDefeated::
	speakername ZotpyreGym_Text_NameSpenser
	applymovement LOCALID_SPENSER, ZotpyreGym_Movement_SpenserTalk
	msgbox ZotpyreGym_Text_Spenser3, MSGBOX_DEFAULT
	speakername ZotpyreGym_Text_NamePhoebe
	applymovement LOCALID_PHOEBE, ZotpyreGym_Movement_PhoebeTalk
	msgbox ZotpyreGym_Text_Phoebe3, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 4
	giveitem ITEM_DILATANT_MOD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_FEAR_FACTOR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername ZotpyreGym_Text_NameSpenser
	applymovement LOCALID_SPENSER, ZotpyreGym_Movement_SpenserTalk
	msgbox ZotpyreGym_Text_Spenser4, MSGBOX_DEFAULT
	speakername ZotpyreGym_Text_NamePhoebe
	applymovement LOCALID_PHOEBE, ZotpyreGym_Movement_PhoebeTalk
	msgbox ZotpyreGym_Text_Phoebe4, MSGBOX_DEFAULT
	speakername NULL
	message ZotpyreGym_Text_ReceivedYoreBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername ZotpyreGym_Text_NamePhoebe
	applymovement LOCALID_PHOEBE, ZotpyreGym_Movement_PhoebeTalk
	msgbox ZotpyreGym_Text_Phoebe5, MSGBOX_DEFAULT
	speakername ZotpyreGym_Text_NameSpenser
	applymovement LOCALID_SPENSER, ZotpyreGym_Movement_SpenserTalk
	msgbox ZotpyreGym_Text_Spenser5, MSGBOX_DEFAULT
	speakername NULL
	warp MAP_ROUTE122, 42, 14
	release
	end

ZotpyreGym_Text_NamePhoebe:
	.string "Phoebe$"

ZotpyreGym_Text_NameSpenser:
	.string "Spenser$"

ZotpyreGym_Text_Hint1:
	.string "This lifeless haze…\n"
	.string "it redirects those who disturb it…\p"
	.string "Those who traverse uneven paths…$"

ZotpyreGym_Text_Hint2:
	.string "The trainers here are quite\n"
	.string "knowledgeable about this peculiar\l"
	.string "type of Pokémon!\p"
	.string "I try to talk to as many as I can.$"

ZotpyreGym_Text_JunjiIntro:
	.string "Ho-ho-ho…\p"
	.string "If only you knew what\n"
	.string "you were walking into.\p"
	.string "Allow me to give you a trial by fire…\n"
	.string "of Relic-type Pokémon!$"

ZotpyreGym_Text_JunjiDefeated:
	.string "Now I am but a moment past…!$"

ZotpyreGym_Text_JunjiPostBattle:
	.string "Relic-type Pokémon and moves are very\n"
	.string "ancient, and were thought\l"
	.string "to be wiped out.\p"
	.string "Recent findings have confirmed the\n"
	.string "survival of certain species.\l"
	.string "Our leader, Spenser, led the\l"
	.string "efforts in Hoenn.\p"
	.string "The Relic-type is possessed by\n"
	.string "creatures that were originally\l"
	.string "constructed to combat\l"
	.string "otherworldly beings.\p"
	.string "As such, it is good against magical\n"
	.string "Pokémon, lke Dragon- & Fairy-types.\p"
	.string "Conversely, Relic-type Pokémon are\n"
	.string "weak to the natural element of Grass.\p"
	.string "You will surely find out more by\n"
	.string "continuing onwards; good luck.$"

ZotpyreGym_Text_KirieIntro:
	.string "My Relic-type Pokémon are at one\n"
	.string "thousand-percent power!$"

ZotpyreGym_Text_KirieDefeated:
	.string "Shut down, like a decades-old OS…$"

ZotpyreGym_Text_KiriePostBattle:
	.string "Fire and Water attacks don't really do\n"
	.string "all that much to Relic Pokémon,\l"
	.string "I've heard scientists say that said\l"
	.string "moves “fuel” them, in a way.$"

ZotpyreGym_Text_ShuichiIntro:
	.string "It takes a brilliant mind to\n"
	.string "understand Relic Pokémon!$"

ZotpyreGym_Text_ShuichiDefeated:
	.string "You're definitely sharp!$"

ZotpyreGym_Text_ShuichiPostBattle:
	.string "What I said before wasn't\n"
	.string "just a platitude.\p"
	.string "Relic-types are complex beings.\n"
	.string "However, Psychic-type Pokémonm with\l"
	.string "their high IQs, know their inner\l"
	.string "workings well to exploit\l"
	.string "their weaknesses.$"

ZotpyreGym_Text_TomieIntro:
	.string "intro$"

ZotpyreGym_Text_TomieDefeated:
	.string "defeat$"

ZotpyreGym_Text_TomiePostBattle:
	.string "post$"

ZotpyreGym_Text_AzamiIntro:
	.string "intro$"

ZotpyreGym_Text_AzamiDefeated:
	.string "defeat$"

ZotpyreGym_Text_AzamiPostBattle:
	.string "post$"

ZotpyreGym_Text_MisakiIntro:
	.string "intro$"

ZotpyreGym_Text_MisakiDefeated:
	.string "defeat$"

ZotpyreGym_Text_MisakiPostBattle:
	.string "post$"

ZotpyreGym_Text_YuinaIntro:
	.string "Whether a ghost or a relic;\n"
	.string "you'll join them in the past!$"

ZotpyreGym_Text_YuinaDefeated:
	.string "Seems you were more present than I…$"

ZotpyreGym_Text_YuinaPostBattle:
	.string "Ghosts are resistant to Relic moves.\p"
	.string "My best guess?\n"
	.string "That's because Relic-types were\l"
	.string "intended as weapons to\l"
	.string "eliminate threats.\p"
	.string "The spirits?\n"
	.string "Already long-gone!$"

ZotpyreGym_Text_Spenser1:
	.string "So you've dragged your behind into\n"
	.string "my chambers, challenger?\p"
	.string "Bah!\n"
	.string "You are looking mighty weak!\p"
	.string "A puny hooligan, traipsing up to the\n"
	.string "legendary, all-powerful, MASTER\l"
	.string "trainer, Spenser? Give me a break!\p"
	.string "I've half a mind to summon a wild\n"
	.string "Boozard to blow you over!\l"
	.string "And furthermore…!$"

ZotpyreGym_Text_Phoebe1:
	.string "(The woman next to Spenser\n"
	.string "appears perturbed.)\p"
	.string "The hallowed deceased are conversing\n"
	.string "with me, desperate for you to lower\l"
	.string "your volume, Spenser.$"

ZotpyreGym_Text_Spenser2:
	.string "(He lowers his voice to a whisper.)\p"
	.string "As I was saying!\p"
	.string "Your throwing arm is boney as a\n"
	.string "Coffiddle's legs!\l"
	.string "Your strained voice will confuse,\l"
	.string "rather than command, your team!\p"
	.string "You. Are. WEAK!$"

ZotpyreGym_Text_Phoebe2:
	.string "Much better.\p"
	.string "Let us commence this rendesvouz of\n"
	.string "three fates, challenger.\p"
	.string "Prove to us your worth!$"

ZotpyreGym_Text_PhoebeDefeat:
	.string "{PLAYER}, you have taken destiny\n"
	.string "into your own hands.$"

ZotpyreGym_Text_SpenserDefeat:
	.string "…\p"
	.string "Gwahah!\p"
	.string "Gwahahahaha!\p"
	.string "Great work, youngin'!\p"
	.string "You didn't let an old man's\n"
	.string "taunts phase ya!$"

ZotpyreGym_Text_Spenser3:
	.string "Golly, is it hard to not burst into a\n"
	.string "fit'a laughter when puttin' up that\l"
	.string "cocky, tough act!\p"
	.string "Good on ya for keepin' your composure!$"

ZotpyreGym_Text_Phoebe3:
	.string "For your victory,\n"
	.string "you have earned these spoils…$"

ZotpyreGym_Text_Spenser4:
	.string "You seem a li'l puzzled\n"
	.string "by that first reward.\p"
	.string "Whelp, y'see, Relic moves were only\n"
	.string "recently discovered.\p"
	.string "They don't got any Technical Machines\n"
	.string "made of 'em yet!\p"
	.string "So instead, you'll be takin' home a\n"
	.string "trinket I found minin'!$"

ZotpyreGym_Text_Phoebe4:
	.string "Take this as well, {PLAYER}.$"

ZotpyreGym_Text_ReceivedYoreBadge:
	.string "{PLAYER} received the\n"
	.string "Yore Badge\l"
	.string "from Phoebe and Spenser.$"

ZotpyreGym_Text_Phoebe5:
	.string "The Yore Badge will allow usage of the\n"
	.string "field move, Cut.\p"
	.string "You may use it wisely to carve your\n"
	.string "path forward.\p"
	.string "…\p"
	.string "The spirits… their voices\n"
	.string "ring out in agreement.\p"
	.string "They believe you are destined for a\n"
	.string "rocky road ahead.\p"
	.string "On the other side, they hope\n"
	.string "to see you triumphant.$"

ZotpyreGym_Text_Spenser5:
	.string "As do we! Take care, youngin'!$"

ZotpyreGym_Text_LeadersIntro:
	.string "finnina battle$"

ZotpyreGym_Text_LeadersYouWon:
	.string "u woned take this$"

ZotpyreGym_Text_IllMoveColumns1:
	.string "It seems you have reached\n"
	.string "an end, trainer.\p"
	.string "Allow me; to expand this\n"
	.string "novel for you.\p"
	.string "(He begins to meditate…)$"

ZotpyreGym_Text_IllMoveColumns2:
	.string "You have been crafty, indeed,\n"
	.string "to come upon me.\p"
	.string "I shall consult the spirits for you…\p"
	.string "Perhaps, then, shall your\n"
	.string "destination await.$"

ZotpyreGym_Text_AlreadyMovedColumns:
	.string "(The monk is aligning his chakra…)$"

ZotpyreGym_Text_TheFogIsComing:
	.string "(The endless fog envelops you, until\n"
	.string "your vision becomes a blur…)$"
