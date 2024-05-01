MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Deacon::
    trainerbattle_single TRAINER_P_DEACON, MtPyre_2F_Text_DeaconIntro, MtPyre_2F_Text_DeaconDefeated
    msgbox MtPyre_2F_Text_DeaconPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_2F_EventScript_Alodia::
    trainerbattle_single TRAINER_P_ALODIA, MtPyre_2F_Text_AlodiaIntro, MtPyre_2F_Text_AlodiaDefeated
    msgbox MtPyre_2F_Text_AlodiaPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_2F_EventScript_Raeliana::
    trainerbattle_single TRAINER_P_RAELIANA, MtPyre_2F_Text_RaelianaIntro, MtPyre_2F_Text_RaelianaDefeated
    msgbox MtPyre_2F_Text_RaelianaPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_2F_EventScript_Morgan::
    trainerbattle_single TRAINER_P_MORGAN, MtPyre_2F_Text_MorganIntro, MtPyre_2F_Text_MorganDefeated
    msgbox MtPyre_2F_Text_MorganPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_2F_EventScript_Misty::
    trainerbattle_single TRAINER_P_MISTY, MtPyre_2F_Text_MistyIntro, MtPyre_2F_Text_MistyDefeated
    msgbox MtPyre_2F_Text_MistyPostBattle, MSGBOX_AUTOCLOSE
    end

MtPyre_2F_Text_DeaconIntro:
	.string "intro$"

MtPyre_2F_Text_DeaconDefeated:
	.string "defeat$"

MtPyre_2F_Text_DeaconPostBattle:
	.string "post$"

MtPyre_2F_Text_AlodiaIntro:
	.string "intro$"

MtPyre_2F_Text_AlodiaDefeated:
	.string "defeat$"

MtPyre_2F_Text_AlodiaPostBattle:
	.string "post$"

MtPyre_2F_Text_RaelianaIntro:
	.string "intro$"

MtPyre_2F_Text_RaelianaDefeated:
	.string "defeat$"

MtPyre_2F_Text_RaelianaPostBattle:
	.string "post$"

MtPyre_2F_Text_MorganIntro:
	.string "intro$"

MtPyre_2F_Text_MorganDefeated:
	.string "defeat$"

MtPyre_2F_Text_MorganPostBattle:
	.string "post$"

MtPyre_2F_Text_MistyIntro:
	.string "intro$"

MtPyre_2F_Text_MistyDefeated:
	.string "defeat$"

MtPyre_2F_Text_MistyPostBattle:
	.string "post$"
