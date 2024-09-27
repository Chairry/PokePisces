.set LOCALID_RYDEL1, 16
.set LOCALID_RYDEL2, 17

CyclingRoad_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CyclingRoad_OnTransition
	.byte 0

CyclingRoad_OnTransition:
	call CyclingRoad_EventScript_RemoveRydel
	call_if_eq VAR_OLD_GUYS_STATE, 6, CyclingRoad_EventScript_SetRydel
	end

CyclingRoad_EventScript_RemoveRydel::
	removeobject LOCALID_RYDEL1
	removeobject LOCALID_RYDEL2
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_4, 1
	return

CyclingRoad_EventScript_SetRydel::
	clearflag FLAG_TEMP_11
	clearflag FLAG_TEMP_12
	addobject LOCALID_RYDEL1
	addobject LOCALID_RYDEL2
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_BARD_COLOR, MAUVILLE_MAN_HIPSTER
	special SetMauvilleOldManObjEventGfx
	return	

CyclingRoad_EventScript_RydelHype1::
	playse SE_APPLAUSE
	applymovement LOCALID_RYDEL1, CyclingRoad_Movement_HopUp
	message CyclingRoad_Text_RydelHype1
	setvar VAR_TEMP_3, 1
	end

CyclingRoad_EventScript_RydelHype2::
	playse SE_APPLAUSE
	applymovement LOCALID_RYDEL2, CyclingRoad_Movement_HopUp
	message CyclingRoad_Text_RydelHype2
	setvar VAR_TEMP_4, 1
	end

CyclingRoad_Movement_HopUp:
	jump_in_place_left
	jump_in_place_right
	jump_in_place_down
	step_end

CyclingRoad_EventScript_Rhode::
    trainerbattle_single TRAINER_P_RHODE, CyclingRoad_Text_RhodeIntro, CyclingRoad_Text_RhodeDefeated
    msgbox CyclingRoad_Text_RhodePostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Cruz::
    trainerbattle_single TRAINER_P_CRUZ, CyclingRoad_Text_CruzIntro, CyclingRoad_Text_CruzDefeated
    msgbox CyclingRoad_Text_CruzPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Mona::
    trainerbattle_single TRAINER_P_MONA, CyclingRoad_Text_MonaIntro, CyclingRoad_Text_MonaDefeated
    msgbox CyclingRoad_Text_MonaPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Solo::
    trainerbattle_single TRAINER_P_SOLO, CyclingRoad_Text_SoloIntro, CyclingRoad_Text_SoloDefeated
    msgbox CyclingRoad_Text_SoloPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Hichael::
    trainerbattle_single TRAINER_P_HICHAEL, CyclingRoad_Text_HichaelIntro, CyclingRoad_Text_HichaelDefeated
    msgbox CyclingRoad_Text_HichaelPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Penny::
    trainerbattle_single TRAINER_P_PENNY, CyclingRoad_Text_PennyIntro, CyclingRoad_Text_PennyDefeated
    msgbox CyclingRoad_Text_PennyPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Junior::
    trainerbattle_single TRAINER_P_JUNIOR, CyclingRoad_Text_JuniorIntro, CyclingRoad_Text_JuniorDefeated
    msgbox CyclingRoad_Text_JuniorPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Hichaelson::
    trainerbattle_single TRAINER_P_HICHAELSON, CyclingRoad_Text_HichaelsonIntro, CyclingRoad_Text_HichaelsonDefeated
    msgbox CyclingRoad_Text_HichaelsonPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Lulu::
    trainerbattle_single TRAINER_P_LULU, CyclingRoad_Text_LuluIntro, CyclingRoad_Text_LuluDefeated
    msgbox CyclingRoad_Text_LuluPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Kaira::
    trainerbattle_single TRAINER_P_KAIRA, CyclingRoad_Text_KairaIntro, CyclingRoad_Text_KairaDefeated
    msgbox CyclingRoad_Text_KairaPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Woody::
    trainerbattle_single TRAINER_P_WOODY, CyclingRoad_Text_WoodyIntro, CyclingRoad_Text_WoodyDefeated
    msgbox CyclingRoad_Text_WoodyPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Ana::
    trainerbattle_single TRAINER_P_ANA, CyclingRoad_Text_AnaIntro, CyclingRoad_Text_AnaDefeated
    msgbox CyclingRoad_Text_AnaPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Yoko::
    trainerbattle_single TRAINER_P_YOKO, CyclingRoad_Text_YokoIntro, CyclingRoad_Text_YokoDefeated
    msgbox CyclingRoad_Text_YokoPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Flats::
    trainerbattle_single TRAINER_P_FLATS, CyclingRoad_Text_FlatsIntro, CyclingRoad_Text_FlatsDefeated
    msgbox CyclingRoad_Text_FlatsPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_EventScript_Phillip::
    trainerbattle_single TRAINER_P_PHILLIP, CyclingRoad_Text_PhillipIntro, CyclingRoad_Text_PhillipDefeated
    msgbox CyclingRoad_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
    end

CyclingRoad_Text_RhodeIntro:
	.string "intro$"

CyclingRoad_Text_RhodeDefeated:
	.string "defeat$"

CyclingRoad_Text_RhodePostBattle:
	.string "post$"

CyclingRoad_Text_CruzIntro:
	.string "intro$"

CyclingRoad_Text_CruzDefeated:
	.string "defeat$"

CyclingRoad_Text_CruzPostBattle:
	.string "post$"

CyclingRoad_Text_MonaIntro:
	.string "intro$"

CyclingRoad_Text_MonaDefeated:
	.string "defeat$"

CyclingRoad_Text_MonaPostBattle:
	.string "post$"

CyclingRoad_Text_SoloIntro:
	.string "intro$"

CyclingRoad_Text_SoloDefeated:
	.string "defeat$"

CyclingRoad_Text_SoloPostBattle:
	.string "post$"

CyclingRoad_Text_HichaelIntro:
	.string "intro$"

CyclingRoad_Text_HichaelDefeated:
	.string "defeat$"

CyclingRoad_Text_HichaelPostBattle:
	.string "post$"

CyclingRoad_Text_PennyIntro:
	.string "intro$"

CyclingRoad_Text_PennyDefeated:
	.string "defeat$"

CyclingRoad_Text_PennyPostBattle:
	.string "post$"

CyclingRoad_Text_JuniorIntro:
	.string "intro$"

CyclingRoad_Text_JuniorDefeated:
	.string "defeat$"

CyclingRoad_Text_JuniorPostBattle:
	.string "post$"

CyclingRoad_Text_HichaelsonIntro:
	.string "intro$"

CyclingRoad_Text_HichaelsonDefeated:
	.string "defeat$"

CyclingRoad_Text_HichaelsonPostBattle:
	.string "post$"

CyclingRoad_Text_LuluIntro:
	.string "intro$"

CyclingRoad_Text_LuluDefeated:
	.string "defeat$"

CyclingRoad_Text_LuluPostBattle:
	.string "post$"

CyclingRoad_Text_KairaIntro:
	.string "intro$"

CyclingRoad_Text_KairaDefeated:
	.string "defeat$"

CyclingRoad_Text_KairaPostBattle:
	.string "post$"

CyclingRoad_Text_WoodyIntro:
	.string "intro$"

CyclingRoad_Text_WoodyDefeated:
	.string "defeat$"

CyclingRoad_Text_WoodyPostBattle:
	.string "post$"

CyclingRoad_Text_AnaIntro:
	.string "intro$"

CyclingRoad_Text_AnaDefeated:
	.string "defeat$"

CyclingRoad_Text_AnaPostBattle:
	.string "post$"

CyclingRoad_Text_YokoIntro:
	.string "intro$"

CyclingRoad_Text_YokoDefeated:
	.string "defeat$"

CyclingRoad_Text_YokoPostBattle:
	.string "post$"

CyclingRoad_Text_FlatsIntro:
	.string "intro$"

CyclingRoad_Text_FlatsDefeated:
	.string "defeat$"

CyclingRoad_Text_FlatsPostBattle:
	.string "post$"

CyclingRoad_Text_PhillipIntro:
	.string "intro$"

CyclingRoad_Text_PhillipDefeated:
	.string "defeat$"

CyclingRoad_Text_PhillipPostBattle:
	.string "post$"

CyclingRoad_Text_RydelHype1:
	.string "Folks, we have the quickest wheels\n"
	.string "in Hoenn on the track! {PLAYER}!!!$"

CyclingRoad_Text_RydelHype2:
	.string "{PLAYER} is rounding the final\n"
	.string "stretch! A true nail biter!!!$"
