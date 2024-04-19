.set LOCALID_TUBER1, 7
.set LOCALID_TUBER2, 9
.set LOCALID_TUBER3, 10
.set LOCALID_TUBER4, 13
.set LOCALID_POMELONIAN, 8
.set LOCALID_VICTIM1, 6
.set LOCALID_VICTIM2, 11
.set LOCALID_VICTIM3, 12
.set LOCALID_PARASOL1, 19
.set LOCALID_PARASOL2, 20
.set LOCALID_PARASOL3, 21
.set LOCALID_PARASOL4, 22
.set LOCALID_PARASOL5, 23
.set LOCALID_PARASOL6, 24

Route124_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	.byte 0

Route124_OnTransition:
	call_if_eq VAR_TEMP_7, 0
	call_if_set FLAG_SUNBEACH_TUBER_1, Route124_EventScript_SetTuberTempFlags1
	call_if_set FLAG_SUNBEACH_TUBER_2, Route124_EventScript_SetTuberTempFlags2
	call_if_set FLAG_SUNBEACH_TUBER_3, Route124_EventScript_SetTuberTempFlags3
	call_if_gt VAR_PARASOL_QUEST_STATE, 1, Route124_EventScript_SetParasolTempVar
	end

Route124_EventScript_SetTuberTempFlags1::
	setvar VAR_TEMP_5, 2
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	return

Route124_EventScript_SetTuberTempFlags2::
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	return

Route124_EventScript_SetTuberTempFlags3::
	setvar VAR_TEMP_6, 2
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	return

Route124_EventScript_SetParasolTempVar::
	setvar VAR_TEMP_4, 2
	return

Route124_EventScript_EvilTuber1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Route124_Movement_PlayerMoveIntoPos1
	waitmovement 0
	applymovement LOCALID_VICTIM1, Route124_Movement_Helpme1
	waitmovement 0
	trainerbattle_single TRAINER_P_TOBY, Route124_Text_TobyIntro, Route124_Text_TobyDefeated, Route124_EventScript_TobyLeaves
	release
	end

Route124_Movement_PlayerMoveIntoPos1:
	walk_right
	walk_down
	walk_right
	walk_down
	walk_right
	walk_right
	face_up
	step_end

Route124_Movement_Helpme1:
	walk_in_place_fast_down
	walk_in_place_fast_down
	step_end

Route124_EventScript_TobyLeaves::
	applymovement OBJ_EVENT_ID_PLAYER, Route124_Movement_PlayerLook
	applymovement LOCALID_TUBER1, Route124_Movement_TobyFaceDown
	applymovement LOCALID_POMELONIAN, Route124_Movement_TobyFaceDown
	waitmovement 0
	msgbox Route124_Text_TobyPostBattle, MSGBOX_DEFAULT
	applymovement LOCALID_TUBER1, Route124_Movement_TobyWalkAway
	applymovement LOCALID_POMELONIAN, Route124_Movement_PomLeave
	waitmovement 0
	removeobject LOCALID_TUBER1
	removeobject LOCALID_POMELONIAN
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_13
	applymovement LOCALID_VICTIM1, Route124_Movement_Helpme1
	msgbox Route124_Text_YouSavedMe1, MSGBOX_DEFAULT
	giveitem ITEM_LUMINOUS_MOSS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route124_Text_GottaGo1, MSGBOX_DEFAULT
	setflag FLAG_SUNBEACH_TUBER_1
	applymovement LOCALID_VICTIM1, Route124_Movement_VictimLeaves1
	waitmovement 0
	closemessage
	removeobject LOCALID_VICTIM1
	setvar VAR_TEMP_5, 1
	setflag FLAG_TEMP_12
	release
	end

Route124_Movement_PlayerLook:
	face_up
	step_end

Route124_Movement_TobyFaceDown:
	face_down
	step_end

Route124_Movement_TobyWalkAway:
	walk_up
	jump_up
	walk_up
	walk_up
	walk_up
	step_end

Route124_Movement_PomLeave:
	jump_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	step_end
	
Route124_Movement_VictimLeaves1:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

Route124_EventScript_EvilTuber2::
	msgbox Route124_Text_EbbPostBattle, MSGBOX_DEFAULT
	applymovement LOCALID_TUBER2, Route124_Movement_EbbNFloWalkAway
	applymovement LOCALID_TUBER3, Route124_Movement_EbbNFloWalkAway
	waitmovement 0
	removeobject LOCALID_TUBER2
	removeobject LOCALID_TUBER3
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	closemessage
	release
	end

Route124_Movement_EbbNFloWalkAway:
	walk_up
	walk_left
	jump_left
	jump_left
	jump_left
	jump_left
	jump_left
	jump_left
	jump_left
	step_end

Route124_EventScript_Victim2::
	lock
	faceplayer
	goto_if_set FLAG_SUNBEACH_TUBER_2, Route124_EventScript_Victim2AlreadyHelped
	msgbox Route124_Text_YouSavedMe2, MSGBOX_DEFAULT
	giveitem ITEM_ABSORB_BULB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_SUNBEACH_TUBER_2
	release
	end

Route124_EventScript_Victim2AlreadyHelped::
	msgbox Route124_Text_GottaGo2, MSGBOX_NPC
	release
	end

Route124_EventScript_EvilTuber3::
	lock
	applymovement LOCALID_TUBER4, Route124_Movement_TobyFaceDown
	waitmovement 0
	trainerbattle_single TRAINER_P_JULIO, Route124_Text_JulioIntro, Route124_Text_JulioDefeated, Route124_EventScript_JulioLeaves
	release
	end

Route124_EventScript_JulioLeaves::
	msgbox Route124_Text_JulioPostBattle, MSGBOX_DEFAULT
	applymovement LOCALID_TUBER4, Route124_Movement_JulioEscapes
	waitmovement 0
	removeobject LOCALID_TUBER4
	setflag FLAG_TEMP_17
	msgbox Route124_Text_YouSavedMe3, MSGBOX_DEFAULT
	giveitem ITEM_PASSHO_BERRY
	setflag FLAG_SUNBEACH_TUBER_3
	applymovement OBJ_EVENT_ID_PLAYER, Route124_Movement_PlayerMoveIntoPos2
	applymovement LOCALID_VICTIM3, Route124_Movement_VictimLeaves3
	waitmovement 0
	removeobject LOCALID_VICTIM3
	setflag FLAG_TEMP_18
	setvar VAR_TEMP_6, 1
	release
	end

Route124_Movement_JulioEscapes:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route124_Movement_PlayerMoveIntoPos2:
	walk_left
	face_right
	step_end

Route124_Movement_VictimLeaves3:
	walk_left
	walk_left
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route124_EventScript_ParasolLadies::
	lock
	goto_if_eq VAR_PARASOL_QUEST_STATE, 0, Route124_EventScript_NotStrongEnough
	applymovement OBJ_EVENT_ID_PLAYER, Route124_Movement_ConfrontPLs
	waitmovement 0
	msgbox Route124_Text_WantThoseBrellas, MSGBOX_DEFAULT
	applymovement LOCALID_PARASOL1, Route124_Movement_Twirl1
	applymovement LOCALID_PARASOL6, Route124_Movement_Twirl6
	delay 16
	msgbox Route124_Text_ShalaIntro, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_SHALA, Route124_Text_ShalaDefeated, TRAINER_P_LALA, Route124_Text_LalaDefeated, Route124_EventScript_ParasolLadiesRound2, NO_MUSIC
	goto Route124_EventScript_ParasolLadiesRound2
	end

Route124_Movement_ConfrontPLs:
	walk_up
	walk_up
	delay_8
	face_left
	delay_8
	face_right
	delay_8
	face_up
	step_end

Route124_Movement_Twirl1:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	step_end

Route124_Movement_Twirl6:
	face_down
	delay_4
	face_right
	delay_4
	face_up
	delay_4
	face_left
	step_end

Route124_EventScript_ParasolLadiesRound2::
	msgbox Route124_Text_LalaPostBattle, MSGBOX_DEFAULT
	applymovement LOCALID_PARASOL2, Route124_Movement_Twirl2
	applymovement LOCALID_PARASOL5, Route124_Movement_Twirl5
	delay 16
	msgbox Route124_Text_LaIntro, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_LA, Route124_Text_LaDefeated, TRAINER_P_SHALALA, Route124_Text_ShalalaDefeated, Route124_EventScript_ParasolLadiesRound3, NO_MUSIC
	goto Route124_EventScript_ParasolLadiesRound3
	end

Route124_Movement_Twirl2:
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	step_end

Route124_Movement_Twirl5:
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	face_down
	step_end

Route124_EventScript_ParasolLadiesRound3::
	msgbox Route124_Text_ShalalaPostBattle, MSGBOX_DEFAULT
	applymovement LOCALID_PARASOL3, Route124_Movement_Twirl2
	applymovement LOCALID_PARASOL4, Route124_Movement_Twirl5
	delay 16
	msgbox Route124_Text_IndaIntro, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_P_INDA, Route124_Text_IndaDefeated, TRAINER_P_MORNING, Route124_Text_MorningDefeated, Route124_EventScript_ParasolLadiesBeaten, NO_MUSIC
	goto Route124_EventScript_ParasolLadiesBeaten
	end

Route124_EventScript_ParasolLadiesBeaten::
	msgbox Route124_Text_IndaPostBattle, MSGBOX_DEFAULT
	applymovement LOCALID_PARASOL1, Route124_Movement_Twirl1
	applymovement LOCALID_PARASOL6, Route124_Movement_Twirl6
	delay 8
	applymovement LOCALID_PARASOL2, Route124_Movement_Twirl2
	applymovement LOCALID_PARASOL5, Route124_Movement_Twirl5
	delay 8
	applymovement LOCALID_PARASOL3, Route124_Movement_Twirl2
	applymovement LOCALID_PARASOL4, Route124_Movement_Twirl5
	delay 8
	setvar VAR_TEMP_4, 1
	setvar VAR_PARASOL_QUEST_STATE, 2
	msgbox Route124_Text_MorningPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_NotStrongEnough::
	msgbox Route124_Text_ScaredOfUmbrellas, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Route124_Movement_RunAway
	waitmovement 0
	release
	end

Route124_Movement_RunAway:
	walk_down
	step_end

Route124_EventScript_Ariel::
    trainerbattle_single TRAINER_P_ARIEL, Route124_Text_ArielIntro, Route124_Text_ArielDefeated
    msgbox Route124_Text_ArielPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Dolly::
    trainerbattle_single TRAINER_P_DOLLY, Route124_Text_DollyIntro, Route124_Text_DollyDefeated
    msgbox Route124_Text_DollyPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Sinjin::
    trainerbattle_single TRAINER_P_SINJIN, Route124_Text_SinjinIntro, Route124_Text_SinjinDefeated
    msgbox Route124_Text_SinjinPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Josuke::
    trainerbattle_single TRAINER_P_JOSUKE, Route124_Text_JosukeIntro, Route124_Text_JosukeDefeated
    msgbox Route124_Text_JosukePostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Arbuckle::
    trainerbattle_single TRAINER_P_ARBUCKLE, Route124_Text_ArbuckleIntro, Route124_Text_ArbuckleDefeated
    msgbox Route124_Text_ArbucklePostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Naomi::
    trainerbattle_single TRAINER_P_NAOMI, Route124_Text_NaomiIntro, Route124_Text_NaomiDefeated
    msgbox Route124_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Betha::
    trainerbattle_single TRAINER_P_BETHA, Route124_Text_BethaIntro, Route124_Text_BethaDefeated
    msgbox Route124_Text_BethaPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Ebb::
    trainerbattle_single TRAINER_P_EBB, Route124_Text_EbbIntro, Route124_Text_EbbDefeated
    msgbox Route124_Text_EbbPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Flo::
    trainerbattle_single TRAINER_P_FLO, Route124_Text_FloIntro, Route124_Text_FloDefeated, Route124_EventScript_EvilTuber2
    msgbox Route124_Text_FloPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Homer::
    trainerbattle_single TRAINER_P_HOMER, Route124_Text_HomerIntro, Route124_Text_HomerDefeated
    msgbox Route124_Text_HomerPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Marge::
    trainerbattle_single TRAINER_P_MARGE, Route124_Text_MargeIntro, Route124_Text_MargeDefeated
    msgbox Route124_Text_MargePostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Shala::
    trainerbattle_single TRAINER_P_SHALA, Route124_Text_ShalaIntro, Route124_Text_ShalaDefeated
    msgbox Route124_Text_ShalaPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Lala::
    trainerbattle_single TRAINER_P_LALA, Route124_Text_LalaIntro, Route124_Text_LalaDefeated
    msgbox Route124_Text_LalaPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_La::
    trainerbattle_single TRAINER_P_LA, Route124_Text_LaIntro, Route124_Text_LaDefeated
    msgbox Route124_Text_LaPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Shalala::
    trainerbattle_single TRAINER_P_SHALALA, Route124_Text_ShalalaIntro, Route124_Text_ShalalaDefeated
    msgbox Route124_Text_ShalalaPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Inda::
    trainerbattle_single TRAINER_P_INDA, Route124_Text_IndaIntro, Route124_Text_IndaDefeated
    msgbox Route124_Text_IndaPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_EventScript_Morning::
    trainerbattle_single TRAINER_P_MORNING, Route124_Text_MorningIntro, Route124_Text_MorningDefeated
    msgbox Route124_Text_MorningPostBattle, MSGBOX_AUTOCLOSE
    end

Route124_Text_WantThoseBrellas:
	.string "gimme your brellas$"

Route124_Text_ScaredOfUmbrellas:
	.string "too scary!$"

Route124_Text_YouSavedMe1:
	.string "you saved me 1$"

Route124_Text_GottaGo1:
	.string "Gotta blast 1$"

Route124_Text_YouSavedMe2:
	.string "you saved me 2$"

Route124_Text_GottaGo2:
	.string "Gotta blast 2$"

Route124_Text_YouSavedMe3:
	.string "you saved me 3$"

Route124_Text_ArielNeedTwoMons:
	.string "need 2 dood$"

Route124_Text_ArielIntro:
	.string "intro$"

Route124_Text_ArielDefeated:
	.string "defeat$"

Route124_Text_ArielPostBattle:
	.string "post$"

Route124_Text_DollyIntro:
	.string "intro$"

Route124_Text_DollyDefeated:
	.string "defeat$"

Route124_Text_DollyPostBattle:
	.string "post$"

Route124_Text_SinjinIntro:
	.string "intro$"

Route124_Text_SinjinDefeated:
	.string "defeat$"

Route124_Text_SinjinPostBattle:
	.string "post$"

Route124_Text_JosukeIntro:
	.string "intro$"

Route124_Text_JosukeDefeated:
	.string "defeat$"

Route124_Text_JosukePostBattle:
	.string "post$"

Route124_Text_TobyIntro:
	.string "intro$"

Route124_Text_TobyDefeated:
	.string "defeat$"

Route124_Text_TobyPostBattle:
	.string "post$"

Route124_Text_ArbuckleIntro:
	.string "intro$"

Route124_Text_ArbuckleDefeated:
	.string "defeat$"

Route124_Text_ArbucklePostBattle:
	.string "post$"

Route124_Text_NaomiIntro:
	.string "intro$"

Route124_Text_NaomiDefeated:
	.string "defeat$"

Route124_Text_NaomiPostBattle:
	.string "post$"

Route124_Text_BethaIntro:
	.string "intro$"

Route124_Text_BethaDefeated:
	.string "defeat$"

Route124_Text_BethaPostBattle:
	.string "post$"

Route124_Text_EbbIntro:
	.string "intro$"

Route124_Text_EbbDefeated:
	.string "defeat$"

Route124_Text_EbbPostBattle:
	.string "post$"

Route124_Text_FloIntro:
	.string "intro$"

Route124_Text_FloDefeated:
	.string "defeat$"

Route124_Text_FloPostBattle:
	.string "post$"

Route124_Text_JulioIntro:
	.string "intro$"

Route124_Text_JulioDefeated:
	.string "defeat$"

Route124_Text_JulioPostBattle:
	.string "post$"

Route124_Text_HomerIntro:
	.string "intro$"

Route124_Text_HomerDefeated:
	.string "defeat$"

Route124_Text_HomerPostBattle:
	.string "post$"

Route124_Text_MargeIntro:
	.string "intro$"

Route124_Text_MargeDefeated:
	.string "defeat$"

Route124_Text_MargePostBattle:
	.string "post$"

Route124_Text_ShalaIntro:
	.string "intro Ä$"

Route124_Text_ShalaDefeated:
	.string "defeat$"

Route124_Text_ShalaPostBattle:
	.string "post$"

Route124_Text_LalaIntro:
	.string "intro$"

Route124_Text_LalaDefeated:
	.string "defeat$"

Route124_Text_LalaPostBattle:
	.string "post$"

Route124_Text_LaIntro:
	.string "intro$"

Route124_Text_LaDefeated:
	.string "defeat$"

Route124_Text_LaPostBattle:
	.string "post$"

Route124_Text_ShalalaIntro:
	.string "intro$"

Route124_Text_ShalalaDefeated:
	.string "defeat$"

Route124_Text_ShalalaPostBattle:
	.string "post$"

Route124_Text_IndaIntro:
	.string "intro$"

Route124_Text_IndaDefeated:
	.string "defeat$"

Route124_Text_IndaPostBattle:
	.string "post$"

Route124_Text_MorningIntro:
	.string "intro$"

Route124_Text_MorningDefeated:
	.string "defeat$"

Route124_Text_MorningPostBattle:
	.string "post$"
