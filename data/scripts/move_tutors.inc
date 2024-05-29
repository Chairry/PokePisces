SlateportCity_PokemonFanClub_EventScript_SwaggerTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SWAGGER, MoveTutor_EventScript_SwaggerTaught
	msgbox MoveTutor_Text_SwaggerTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SwaggerDeclined
	msgbox MoveTutor_Text_SwaggerWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SWAGGER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SwaggerDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SWAGGER
	goto MoveTutor_EventScript_SwaggerTaught
	end

MoveTutor_EventScript_SwaggerDeclined::
	msgbox MoveTutor_Text_SwaggerDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SwaggerTaught::
	msgbox MoveTutor_Text_SwaggerTaught, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RolloutTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT, MoveTutor_EventScript_RolloutTaught
	msgbox MoveTutor_Text_RolloutTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_RolloutDeclined
	msgbox MoveTutor_Text_RolloutWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_ROLLOUT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_RolloutDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT
	goto MoveTutor_EventScript_RolloutTaught
	end

MoveTutor_EventScript_RolloutDeclined::
	msgbox MoveTutor_Text_RolloutDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_RolloutTaught::
	msgbox MoveTutor_Text_RolloutTaught, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER, MoveTutor_EventScript_FuryCutterTaught
	msgbox MoveTutor_Text_FuryCutterTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_FuryCutterDeclined
	msgbox MoveTutor_Text_FuryCutterWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FURY_CUTTER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FuryCutterDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER
	goto MoveTutor_EventScript_FuryCutterTaught
	end

MoveTutor_EventScript_FuryCutterDeclined::
	msgbox MoveTutor_Text_FuryCutterDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_FuryCutterTaught::
	msgbox MoveTutor_Text_FuryCutterTaught, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_House_EventScript_MimicTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_MIMIC, MoveTutor_EventScript_MimicTaught
	msgbox MoveTutor_MimicTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MimicDeclined
	msgbox MoveTutor_Text_MimicWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_MIMIC
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MimicDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_MIMIC
	goto MoveTutor_EventScript_MimicTaught
	end

MoveTutor_EventScript_MimicDeclined::
	msgbox MoveTutor_MimicDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MimicTaught::
	msgbox MoveTutor_Text_MimicTaught, MSGBOX_DEFAULT
	release
	end

FallarborTown_Mart_EventScript_MetronomeTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_METRONOME, MoveTutor_EventScript_MetronomeTaught
	msgbox MoveTutor_Text_MetronomeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_MetronomeDeclined
	msgbox MoveTutor_Text_MetronomeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_METRONOME
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MetronomeDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_METRONOME
	goto MoveTutor_EventScript_MetronomeTaught
	end

MoveTutor_EventScript_MetronomeDeclined::
	msgbox MoveTutor_Text_MetronomeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_MetronomeTaught::
	msgbox MoveTutor_Text_MetronomeTaught, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_SleepTalkTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK, MoveTutor_EventScript_SleepTalkTaught
	msgbox MoveTutor_Text_SleepTalkTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SleepTalkDeclined
	msgbox MoveTutor_Text_SleepTalkWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SLEEP_TALK
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SleepTalkDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK
	goto MoveTutor_EventScript_SleepTalkTaught
	end

MoveTutor_EventScript_SleepTalkDeclined::
	msgbox MoveTutor_Text_SleepTalkDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SleepTalkTaught::
	msgbox MoveTutor_Text_SleepTalkTaught, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE, MoveTutor_EventScript_SubstituteTaught
	msgbox MoveTutor_Text_SubstituteTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_SubstituteDeclined
	msgbox MoveTutor_Text_SubstituteWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SubstituteDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE
	goto MoveTutor_EventScript_SubstituteTaught
	end

MoveTutor_EventScript_SubstituteDeclined::
	msgbox MoveTutor_Text_SubstituteDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_SubstituteTaught::
	msgbox MoveTutor_Text_SubstituteTaught, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DynamicPunchTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH, MoveTutor_EventScript_DynamicPunchTaught
	msgbox MoveTutor_Text_DynamicPunchTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DynamicPunchDeclined
	msgbox MoveTutor_Text_DynamicPunchWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DYNAMIC_PUNCH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DynamicPunchDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH
	goto MoveTutor_EventScript_DynamicPunchTaught
	end

MoveTutor_EventScript_DynamicPunchDeclined::
	msgbox MoveTutor_Text_DynamicPunchDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DynamicPunchTaught::
	msgbox MoveTutor_Text_DynamicPunchTaught, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE, MoveTutor_EventScript_DoubleEdgeTaught
	msgbox MoveTutor_Text_DoubleEdgeTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_DoubleEdgeDeclined
	msgbox MoveTutor_Text_DoubleEdgeWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DOUBLE_EDGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DoubleEdgeDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE
	goto MoveTutor_EventScript_DoubleEdgeTaught
	end

MoveTutor_EventScript_DoubleEdgeDeclined::
	msgbox MoveTutor_Text_DoubleEdgeDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_DoubleEdgeTaught::
	msgbox MoveTutor_Text_DoubleEdgeTaught, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor::
	lock
	faceplayer
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION, MoveTutor_EventScript_ExplosionTaught
	msgbox MoveTutor_Text_ExplosionTeach, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	call MoveTutor_EventScript_CanOnlyBeLearnedOnce
	goto_if_eq VAR_RESULT, NO, MoveTutor_EventScript_ExplosionDeclined
	msgbox MoveTutor_Text_ExplosionWhichMon, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_EXPLOSION
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExplosionDeclined
	setflag FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION
	goto MoveTutor_EventScript_ExplosionTaught
	end

MoveTutor_EventScript_ExplosionDeclined::
	msgbox MoveTutor_Text_ExplosionDeclined, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_ExplosionTaught::
	msgbox MoveTutor_Text_ExplosionTaught, MSGBOX_DEFAULT
	release
	end

ZotpyreInteriors_EventScript_MoveTutor1::
	lock
	faceplayer
	msgbox MoveTutor_Text_LearnMove, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_ZOTPYRE_MOVE_TUTOR_1
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_FloralHealing
	case 1, MoveTutor_EventScript_Hearthwarm
	case 2, MoveTutor_EventScript_Roost
	case 3, MoveTutor_EventScript_Ingrain
	case 4, MoveTutor_EventScript_PainSplit
	case 5, MoveTutor_EventScript_Wish
	case 6, MoveTutor_EventScript_HealPulse
	case 7, MoveTutor_EventScript_AquaRing
	case 8, MoveTutor_EventScript_LifeDew
	case 9, MoveTutor_EventScript_SlackOff
	case 10, MoveTutor_EventScript_ExitRules
	case MULTI_B_PRESSED, MoveTutor_EventScript_ExitRules
	end

MoveTutor_EventScript_FloralHealing::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FLORAL_HEALING
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Hearthwarm::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_HEARTHWARM
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Roost::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_ROOST
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Ingrain::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_INGRAIN
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_PainSplit::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_PAIN_SPLIT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Wish::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_WISH
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_HealPulse::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_HEAL_PULSE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_AquaRing::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_AQUA_RING
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_LifeDew::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_LIFE_DEW
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_SlackOff::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SLACK_OFF
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

ZotpyreInteriors_EventScript_MoveTutor2::
	lock
	faceplayer
	msgbox MoveTutor_Text_LearnMove, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_ZOTPYRE_MOVE_TUTOR_2
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_Aromatherapy
	case 1, MoveTutor_EventScript_HealBell
	case 2, MoveTutor_EventScript_Safeguard
	case 3, MoveTutor_EventScript_MagicCoat
	case 4, MoveTutor_EventScript_ExitRules
	case MULTI_B_PRESSED, MoveTutor_EventScript_ExitRules
	end

MoveTutor_EventScript_Aromatherapy::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_AROMATHERAPY
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_HealBell::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_HEAL_BELL
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Safeguard::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SAFEGUARD
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_MagicCoat::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_MAGIC_COAT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

ZotpyreInteriors_EventScript_MoveTutor3::
	lock
	faceplayer
	msgbox MoveTutor_Text_LearnMove, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_ZOTPYRE_MOVE_TUTOR_3
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_LeechLife
	case 1, MoveTutor_EventScript_PollenPuff
	case 2, MoveTutor_EventScript_Paracharge
	case 3, MoveTutor_EventScript_GigaDrain
	case 4, MoveTutor_EventScript_VenomDrain
	case 5, MoveTutor_EventScript_DreamEater
	case 6, MoveTutor_EventScript_ExitRules
	case MULTI_B_PRESSED, MoveTutor_EventScript_ExitRules
	end

MoveTutor_EventScript_LeechLife::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_LEECH_LIFE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_PollenPuff::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_POLLEN_PUFF
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Paracharge::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_PARABOLIC_CHARGE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_GigaDrain::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_GIGA_DRAIN
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_VenomDrain::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_VENOM_DRAIN
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_DreamEater::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_DREAM_EATER
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

ZotpyreInteriors_EventScript_MoveTutor4::
	lock
	faceplayer
	msgbox MoveTutor_Text_LearnMove, MSGBOX_DEFAULT
	setvar VAR_0x8004, SCROLL_MULTI_ZOTPYRE_MOVE_TUTOR_4
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, MoveTutor_EventScript_FinalGambit
	case 1, MoveTutor_EventScript_Reversal
	case 2, MoveTutor_EventScript_Flail
	case 3, MoveTutor_EventScript_MiseryWail
	case 4, MoveTutor_EventScript_Substitute
	case 5, MoveTutor_EventScript_ExitRules
	case MULTI_B_PRESSED, MoveTutor_EventScript_ExitRules
	end

MoveTutor_EventScript_FinalGambit::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FINAL_GAMBIT
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Reversal::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_REVERSAL
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Flail::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_FLAIL
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_MiseryWail::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_MISERY_WAIL
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_Substitute::
	msgbox MoveTutor_Text_WhoWillLearnTheMove, MSGBOX_DEFAULT
	setvar VAR_0x8005, MOVE_SUBSTITUTE
	call MoveTutor_EventScript_OpenPartyMenu
	goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExitRules
	goto MoveTutor_EventScript_MoveTaught
	end

MoveTutor_EventScript_ExitRules::
	release
	end

MoveTutor_EventScript_MoveTaught::
	msgbox MoveTutor_Text_MoveTaught, MSGBOX_DEFAULT
	release
	end

MoveTutor_EventScript_OpenPartyMenu::
	special ChooseMonForMoveTutor
	waitstate
	lock
	faceplayer
	return

MoveTutor_EventScript_CanOnlyBeLearnedOnce::
	msgbox MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce, MSGBOX_YESNO
	return
