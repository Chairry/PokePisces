Route125_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route125_OnTransition
	.byte 0

Route125_OnTransition:
	goto_if_unset FLAG_DEFEATED_PANIC_EVENT, Route125_EventScript_SurferBlocking
	end

Route125_EventScript_SurferBlocking::
	setflag FLAG_TEMP_11
	end

Route125_EventScript_LeftRoadblocker::
	lock
	goto_if_set FLAG_DEFEATED_PANIC_EVENT, Route125_EventScript_LeftRoadblockerPost
	msgbox Route125_Text_Left_1, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_LeftRoadblockerPost::
	msgbox Route125_Text_Left_2, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_RightRoadblocker::
	lock
	goto_if_set FLAG_DEFEATED_PANIC_EVENT, Route125_EventScript_RightRoadblockerPost
	msgbox Route125_Text_Right_1, MSGBOX_AUTOCLOSE
	release
	end

Route125_EventScript_RightRoadblockerPost::
	faceplayer
	msgbox Route125_Text_Right_2, MSGBOX_AUTOCLOSE
	release
	end

Route125_Text_Left_1:
	.string "(Two men are locked here in a\n"
	.string "fierce grapple.)\p"
	.string "K-Kushiwara-San…! I WILL NOT…\n"
	.string "FALL… TO YOU…!\p"
	.string "(This seems to be their final battle…)$"

Route125_Text_Right_1:
	.string "(Two men are locked here in a\n"
	.string "fierce grapple.)\p"
	.string "BOKIKOOO…!\p"
	.string "GIVE ME… ALL YOU'VE GOT…!$"
	.string "(This seems to be their final battle…)$"

Route125_Text_Left_2:
	.string "Helloooo…! Up there!\p"
	.string "I won't lose next time…!$"

Route125_Text_Right_2:
	.string "I gave it my all…\n"
	.string "and vanquished my lifelong rival…\p"
	.string "Over… what, you ask?\p"
	.string "He called me a… grrRR…!\n"
	.string "A DOO-DOO HEAD!!$"
