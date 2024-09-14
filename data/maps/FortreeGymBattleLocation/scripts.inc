.set LOCALID_WINONA, 1
.set LOCALID_AARUNE, 2

FortreeGymBattleLocation_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FortreeGymBattleLocation_OnFrame
	.byte 0

FortreeGymBattleLocation_OnFrame:
	map_script_2 VAR_TEMP_7, 0, FortreeGymBattleLocation_EventScript_GymBattle
	.2byte 0

FortreeGymBattleLocation_EventScript_GymBattle::
	lock
	speakername FortreeGymBattleLocation_Text_NameWinona
	msgbox FortreeGymBattleLocation_Text_NiceHops, MSGBOX_DEFAULT
	speakername FortreeGymBattleLocation_Text_NameAarune
	msgbox FortreeGymBattleLocation_Text_TimeToBattle, MSGBOX_DEFAULT
	speakername NULL
	trainerbattle_two_trainers TRAINER_P_WINONA, FortreeGymBattleLocation_Text_WinonaDefeat, TRAINER_P_AARUNE, FortreeGymBattleLocation_Text_AaruneDefeat, FortreeGymBattleLocation_EventScript_LeadersDefeated, NO_MUSIC
	goto FortreeGymBattleLocation_EventScript_LeadersDefeated
	release
	end

FortreeGymBattleLocation_EventScript_LeadersDefeated::
	speakername FortreeGymBattleLocation_Text_NameWinona
	msgbox FortreeGymBattleLocation_Text_YouDidIt, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_FORTREE_GYM
	setvar VAR_PISCES_STORY_PROGRESS, 5
	giveitem ITEM_TM_ACROBATICS
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	giveitem ITEM_TM_EARTH_POWER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	speakername NULL
	message FortreeGymBattleLocation_Text_ReceivedHorizonBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	speakername FortreeGymBattleLocation_Text_NameAarune
	msgbox FortreeGymBattleLocation_Text_ByeBye, MSGBOX_DEFAULT
	speakername NULL
	setvar VAR_TEMP_7, 1
	warp MAP_FORTREE_GYM_NEW, 44, 27
	waitstate
	release
	end	

FortreeGymBattleLocation_Text_NameWinona:
	.string "Winona$"

FortreeGymBattleLocation_Text_NameAarune:
	.string "Aarune$"

FortreeGymBattleLocation_Text_WinonaDefeat:
	.string "W defeat$"

FortreeGymBattleLocation_Text_AaruneDefeat:
	.string "A defeat$"

FortreeGymBattleLocation_Text_NiceHops:
	.string "nice hops$"

FortreeGymBattleLocation_Text_TimeToBattle:
	.string "time 2 batturu$"

FortreeGymBattleLocation_Text_YouDidIt:
	.string "good job$"

FortreeGymBattleLocation_Text_ReceivedHorizonBadge:
	.string "{PLAYER} received the\n"
	.string "Horizon Badge\l"
	.string "from Winona and Aarune.$"

FortreeGymBattleLocation_Text_ByeBye:
	.string "Bye-BYe$"
