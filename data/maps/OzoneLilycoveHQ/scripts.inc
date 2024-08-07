.set LOCALID_WORKER1, 15
.set LOCALID_WORKER2, 16
.set LOCALID_WORKER3, 17
.set LOCALID_TABITHA, 18
.set LOCALID_MATT, 19

OzoneLilycoveHQ_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OzoneLilycoveHQ_OnFrame
	.byte 0

OzoneLilycoveHQ_OnFrame:
	map_script_2 VAR_OZONE_ADMINS_STATE, 0, OzoneLilycoveHQ_EventScript_NoBusinessHere
	map_script_2 VAR_OZONE_ADMINS_STATE, 1, OzoneLilycoveHQ_EventScript_SomeBusinessHere
	.2byte 0

OzoneLilycoveHQ_EventScript_NoBusinessHere::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_ToTheCounter
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_NoBusinessHere, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_BackOutside
	warp MAP_LILYCOVE_CITY, 64, 15
	waitstate
	release
	end

OzoneLilycoveHQ_Movement_ToTheCounter:
	walk_up
	walk_up
	step_end

OzoneLilycoveHQ_Movement_BackOutside:
	walk_down
	walk_down
	step_end

OzoneLilycoveHQ_EventScript_SomeBusinessHere::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_ToTheCounter
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_SomeBusinessHere, MSGBOX_AUTOCLOSE
	setvar VAR_OZONE_ADMINS_STATE, 2
	release
	end

OzoneLilycoveHQ_EventScript_Landon::
    trainerbattle_single TRAINER_P_LANDON, OzoneLilycoveHQ_Text_LandonIntro, OzoneLilycoveHQ_Text_LandonDefeated
    msgbox OzoneLilycoveHQ_Text_LandonPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_Terra::
    trainerbattle_single TRAINER_P_TERRA, OzoneLilycoveHQ_Text_TerraIntro, OzoneLilycoveHQ_Text_TerraDefeated
    msgbox OzoneLilycoveHQ_Text_TerraPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_Sean::
    trainerbattle_single TRAINER_P_OZONE_SEAN, OzoneLilycoveHQ_Text_SeanIntro, OzoneLilycoveHQ_Text_SeanDefeated
    msgbox OzoneLilycoveHQ_Text_SeanPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_Marina::
    trainerbattle_single TRAINER_P_MARINA, OzoneLilycoveHQ_Text_MarinaIntro, OzoneLilycoveHQ_Text_MarinaDefeated
    msgbox OzoneLilycoveHQ_Text_MarinaPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneLilycoveHQ_EventScript_UmbrellaResearcher::
	lock
	faceplayer
	goto_if_eq VAR_PARASOL_QUEST_STATE, 0, OzoneLilycoveHQ_EventScript_HelpWithBrellas
	goto_if_eq VAR_PARASOL_QUEST_STATE, 1, OzoneLilycoveHQ_EventScript_GoGetBrellas
	goto_if_eq VAR_PARASOL_QUEST_STATE, 2, OzoneLilycoveHQ_EventScript_HaveBrella
	goto_if_gt VAR_PARASOL_QUEST_STATE, 2, OzoneLilycoveHQ_EventScript_NoMoreBrella
	release
	end

OzoneLilycoveHQ_EventScript_HelpWithBrellas::
	setvar VAR_PARASOL_QUEST_STATE, 1
	msgbox OzoneLilycoveHQ_Text_BrellaHelp, MSGBOX_AUTOCLOSE
	goto OzoneLilycoveHQ_EventScript_GoGetBrellas
	release
	end

OzoneLilycoveHQ_EventScript_GoGetBrellas::
	msgbox OzoneLilycoveHQ_Text_BrellaGoGettem, MSGBOX_AUTOCLOSE
	release
	end

OzoneLilycoveHQ_EventScript_HaveBrella::
	msgbox OzoneLilycoveHQ_Text_BrellaThanks, MSGBOX_DEFAULT
	giveitem ITEM_UTILITY_UMBRELLA
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_PARASOL_QUEST_STATE, 3
	msgbox OzoneLilycoveHQ_Text_BrellaAbout, MSGBOX_AUTOCLOSE
	release
	end

OzoneLilycoveHQ_EventScript_NoMoreBrella::
	msgbox OzoneLilycoveHQ_Text_BrellaNoMore, MSGBOX_AUTOCLOSE
	release
	end

OzoneLilycoveHQ_EventScript_BoardroomMeeting::
	lock
	msgbox OzoneLilycoveHQ_Text_Boardroom1, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_PlayerHide
	waitmovement 0
	applymovement LOCALID_WORKER2, OzoneLilycoveHQ_Movement_Worker2Talking
	msgbox OzoneLilycoveHQ_Text_Boardroom2, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameMatt
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt1, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameTabitha
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha1, MSGBOX_DEFAULT
	speakername NULL
	applymovement LOCALID_WORKER1, OzoneLilycoveHQ_Movement_Worker1Talking
	msgbox OzoneLilycoveHQ_Text_Boardroom3, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameMatt
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt2, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameTabitha
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha2, MSGBOX_DEFAULT
	speakername NULL
	applymovement LOCALID_WORKER3, OzoneLilycoveHQ_Movement_Worker3Talking
	msgbox OzoneLilycoveHQ_Text_Boardroom4, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, OzoneLilycoveHQ_Movement_PlayerEnters
	waitmovement 0
	applymovement LOCALID_WORKER2, OzoneLilycoveHQ_Movement_WorkerFlabbergasted
	msgbox OzoneLilycoveHQ_Text_Boardroom5, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameTabitha
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha3, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameMatt
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattAngry
	msgbox OzoneLilycoveHQ_Text_Matt3, MSGBOX_DEFAULT
	playse SE_M_SWEET_SCENT
	speakername NULL
	msgbox OzoneLilycoveHQ_Text_BoardSigh, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameMatt
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt4, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameTabitha
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha4, MSGBOX_DEFAULT
	speakername NULL
	msgbox OzoneLilycoveHQ_Text_YouNod, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameMatt
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattJumping
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_Matt5, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_OZONE_MATT_1, OzoneLilycoveHQ_Text_MattDefeated, TRAINER_P_OZONE_TABITHA_1, OzoneLilycoveHQ_Text_TabithaDefeated, OzoneLilycoveHQ_EventScript_AdminsDefeated, NO_MUSIC
	goto OzoneLilycoveHQ_EventScript_AdminsDefeated
	release
	end

OzoneLilycoveHQ_EventScript_AdminsDefeated::
	delay 16
	speakername OzoneLilycoveHQ_Text_NameTabitha
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha5, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameMatt
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattTalking
	msgbox OzoneLilycoveHQ_Text_Matt6, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameTabitha
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaDeclaration
	waitmovement 0
	msgbox OzoneLilycoveHQ_Text_Tabitha6, MSGBOX_DEFAULT
	speakername OzoneLilycoveHQ_Text_NameMatt
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattUpset
	msgbox OzoneLilycoveHQ_Text_Matt7, MSGBOX_DEFAULT
	applymovement LOCALID_MATT, OzoneLilycoveHQ_Movement_MattLeaves
	waitmovement 0
	speakername OzoneLilycoveHQ_Text_NameTabitha
	applymovement LOCALID_TABITHA, OzoneLilycoveHQ_Movement_TabithaTalking
	msgbox OzoneLilycoveHQ_Text_Tabitha7, MSGBOX_AUTOCLOSE
	speakername NULL
	setvar VAR_OZONE_ADMINS_STATE, 3
	setvar VAR_PISCES_STORY_PROGRESS, 3
	warp MAP_THE_COLD_MINES, 56, 35
	release
	end

OzoneLilycoveHQ_Movement_PlayerHide:
	walk_right
	walk_up
	face_right
	step_end

OzoneLilycoveHQ_Movement_Worker2Talking:
	walk_in_place_slow_up
	step_end

OzoneLilycoveHQ_Movement_MattTalking:
	walk_in_place_slow_down
	step_end

OzoneLilycoveHQ_Movement_TabithaTalking:
	walk_in_place_down
	step_end

OzoneLilycoveHQ_Movement_Worker1Talking:
	walk_in_place_slow_right
	step_end

OzoneLilycoveHQ_Movement_Worker3Talking:
	walk_in_place_slow_left
	step_end

OzoneLilycoveHQ_Movement_PlayerEnters:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

OzoneLilycoveHQ_Movement_WorkerFlabbergasted:
	delay_16
	emote_question_mark
	delay_16
	walk_in_place_fast_left
	step_end

OzoneLilycoveHQ_Movement_MattAngry:
	walk_in_place_fast_left
	step_end

OzoneLilycoveHQ_Movement_MattJumping:
	emote_exclamation_mark
	delay_4
	jump_in_place_down
	step_end

OzoneLilycoveHQ_Movement_TabithaDeclaration:
	walk_left
	walk_down
	walk_down
	walk_right
	face_down
	step_end

OzoneLilycoveHQ_Movement_MattUpset:
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

OzoneLilycoveHQ_Movement_MattLeaves:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
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
	step_end

OzoneLilycoveHQ_Text_NameMatt:
	.string "Matt$"

OzoneLilycoveHQ_Text_NameTabitha:
	.string "Tabitha$"

OzoneLilycoveHQ_Text_Boardroom1:
	.string "(There appears to be some\n"
	.string "kind of meeting going on…)$"

OzoneLilycoveHQ_Text_Boardroom2:
	.string "We are awaiting the directive from our\n"
	.string "administers, regarding where to funnel\l"
	.string "our time and resources.\p"
	.string "I was hoping we could get a concrete\n"
	.string "plan put into motion today?$"

OzoneLilycoveHQ_Text_Matt1:
	.string "I've been tellin' this knucklehead\n"
	.string "that we should keep on\l"
	.string "surveyin' the desert!\p"
	.string "Bound to be a crap-ton of historical\n"
	.string "finds buried there still!$"

OzoneLilycoveHQ_Text_Tabitha1:
	.string "Ridiculous, as usual.\n"
	.string "I remain firm in my assessment,\l"
	.string "being that the arctic regions\l"
	.string "of Hoenn should be focused on.\p"
	.string "I believe it noble to supply the\n"
	.string "subzero-dwelling monks and villagegoers\l"
	.string "with all they need to thrive\l"
	.string "in a harsh climate.$"

OzoneLilycoveHQ_Text_Boardroom3:
	.string "Well, ehem, Sweltorn Desert is not\n"
	.string "exactly the pinnacle of living\l"
	.string "conditions, either.$"

OzoneLilycoveHQ_Text_Matt2:
	.string "Damn right! Was JUST gonna say that!\p"
	.string "Sweltorn's people need help much more!$"

OzoneLilycoveHQ_Text_Tabitha2:
	.string "Are we really to believe that your\n"
	.string "intentions were altruistic,\l"
	.string "instead of what amounts to a\l"
	.string "juvenile treasure hunt…?$"

OzoneLilycoveHQ_Text_Boardroom4:
	.string "I… I d-don't see why we can't just…\n"
	.string "uhh…\l"
	.string "split resources?\p"
	.string "(Matt and Tabitha, in unison:)\n"
	.string "No.\p"
	.string "(You decide now is the… perfect, time\n"
	.string "to voice your opinion.)$"

OzoneLilycoveHQ_Text_Boardroom5:
	.string "Who is this? Are you on the committee?\p"
	.string "(You talk about the cave-in\n"
	.string "at the mines.)$"

OzoneLilycoveHQ_Text_Tabitha3:
	.string "This one has some common sense.\p"
	.string "I agree, we should make that our\n"
	.string "priority, post-haste.$"

OzoneLilycoveHQ_Text_Matt3:
	.string "WAIT UP! THAT AIN'T FAIR!$"

OzoneLilycoveHQ_Text_BoardSigh:
	.string "(A defeated sigh erupts from nearly\n"
	.string "everyone in the room.)$"

OzoneLilycoveHQ_Text_Matt4:
	.string "Why are we even gonna take orders\n"
	.string "from some rando?\p"
	.string "I bet this kid doesn't know jack\n"
	.string "about management!$"

OzoneLilycoveHQ_Text_Tabitha4:
	.string "Though I truly loathe you with every\n"
	.string "bone in my body, you do have some\l"
	.string "semblance of a point.\p"
	.string "Stranger, I personally believe the\n"
	.string "best way to read a person\l"
	.string "is through battle.\p"
	.string "Will you entertain my request?$"

OzoneLilycoveHQ_Text_YouNod:	
	.string "(You nod.)$"

OzoneLilycoveHQ_Text_Matt5:
	.string "Hey! Don't leave me outta this!$"

OzoneLilycoveHQ_Text_MattDefeated:
	.string "Ay caramba…! You weren't just some\n"
	.string "street rat after all!$"

OzoneLilycoveHQ_Text_TabithaDefeated:
	.string "Your team clearly trusts your judgment…\n"
	.string "I believe we should too.$"

OzoneLilycoveHQ_Text_Tabitha5:
	.string "{PLAYER}, well done…\n"
	.string "Matt, you were actively detrimental,\l"
	.string "at best.$"

OzoneLilycoveHQ_Text_Matt6:
	.string "Not my fault you insist on a crappy\n"
	.string "hail team! Sand is king, baby!$"

OzoneLilycoveHQ_Text_Tabitha6:
	.string "Hmph.\n"
	.string "You know what, this experience has\l"
	.string "been enlightening in more ways\l"
	.string "than one.\p"
	.string "Matt, you imbecile. I believe you unfit\n"
	.string "to be an admin.\p"
	.string "Henceforth, I refuse to\n"
	.string "work alongside you.$"

OzoneLilycoveHQ_Text_Matt7:
	.string "What!? What a joke, you crudmuncher!\p"
	.string "Fine! I don't wanna work\n"
	.string "with you either!\p"
	.string "You can keep THESE nerds…\n"
	.string "I'll get perms to lead my OWN branch\l"
	.string "from the bosses!\p"
	.string "You'll be fired in a week\n"
	.string "tops without my help!$"

OzoneLilycoveHQ_Text_Tabitha7:
	.string "…I will work things out\n"
	.string "with Maxie later.\p"
	.string "For now, all… we should get to work on\n"
	.string "cleaning the cave-in.\p"
	.string "You should come with, {PLAYER}.$"

OzoneLilycoveHQ_Text_BrellaHelp:
	.string "I've been doing extensive field testing\n"
	.string "for a product I gather that most\l"
	.string "don't think is important;\l"
	.string "umbrellas.\p"
	.string "A potent protector from precipitation,\n"
	.string "AND UV rays to boot!?\l"
	.string "Fantastic!\p"
	.string "I yearn to make Hoenn's\n"
	.string "best ever parasol!\p"
	.string "To that end, I have been supplying a\n"
	.string "few Parasol Ladies some test\l"
	.string "products to see how they fare.\p"
	.string "Problem, though…\p"
	.string "They have… refused to give them back.\p"
	.string "Those women have expressed that they\n"
	.string "will not return my umbrellas until\l"
	.string "they are defeated in COMBAT!\l"
	.string "Pokémon combat, I'd hope…\p"
	.string "You look tough. Would you be willing\n"
	.string "to fight them for me?\l"
	.string "A marvelous parasol would be in store…$"

OzoneLilycoveHQ_Text_BrellaGoGettem:
	.string "Most excellent!\p"
	.string "Last I'd heard, this herd of hoarders\n"
	.string "grouped up on the south beach of\l"
	.string "Sunbeach Strait.\p"
	.string "Go give 'em what's what!$"

OzoneLilycoveHQ_Text_BrellaThanks:
	.string "Gasp! My parasols! All intact!\n"
	.string "Thank the stars!\p"
	.string "I hope that bout wasn't\n"
	.string "too rough for you.\l"
	.string "Rest assured, your reward\l"
	.string "will be grand…\p"
	.string "…\p"
	.string "(He begins to tinker.)\p"
	.string "…That should do it!\n"
	.string "I proudly present…the…!\p"
	.string "Um, I have yet to think of\n"
	.string "a winning name.$"

OzoneLilycoveHQ_Text_BrellaAbout:
	.string "This masterpiece will protect you from\n"
	.string "the harsh weathers of life!\p"
	.string "I couldn't have completed this\n"
	.string "without you.\l"
	.string "Thanks a bundle!$"

OzoneLilycoveHQ_Text_BrellaNoMore:
	.string "no mas$"

OzoneLilycoveHQ_Text_LandonIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_LandonDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_LandonPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_TerraIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_TerraDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_TerraPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_SeanIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_SeanDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_SeanPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_MarinaIntro:
	.string "intro$"

OzoneLilycoveHQ_Text_MarinaDefeated:
	.string "defeat$"

OzoneLilycoveHQ_Text_MarinaPostBattle:
	.string "post$"

OzoneLilycoveHQ_Text_NoBusinessHere:
	.string "Welcome to the\n"
	.string "Ozone Lilycove Branch HQ;\l"
	.string "how may I help you?\p"
	.string "I see. Well, if you have no\n"
	.string "business here... I must ask\l"
	.string "you to leave, so we can give\l"
	.string "full attention to those with\l"
	.string "upcoming appointments...$"

OzoneLilycoveHQ_Text_SomeBusinessHere:
	.string "Welcome to the\n"
	.string "Ozone Lilycove Branch HQ;\l"
	.string "how may I help you?\p"
	.string "Oh? You are wanting to see Tabitha?\p"
	.string "He is in a brief meeting right now.\n"
	.string "However, most of the office is on\l"
	.string "lunch break; it could help you pass\l"
	.string "the time to chat around.\p"
	.string "I'll have the guards grant you access\n"
	.string "to the upper floors.$"
