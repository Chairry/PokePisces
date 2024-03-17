SootoRestaurant_MapScripts::
	.byte 0

SootoRestaurant_EventScript_SaltShaker::
	lock
	goto_if_unset FLAG_RECEIVED_SEASHELL_1, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_unset FLAG_RECEIVED_SEASHELL_2, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_unset FLAG_RECEIVED_SEASHELL_3, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_unset FLAG_RECEIVED_SEASHELL_4, SootoRestaurant_EventScript_DontTakeSalt
	goto_if_set FLAG_RECEIVED_SALT, SootoRestaurant_EventScript_DontTakeSalt
	msgbox SootoRestaurant_Text_TakeSalt, MSGBOX_DEFAULT
	giveitem ITEM_SHOAL_SALT
	setflag FLAG_RECEIVED_SALT
	closemessage
	release
	end

SootoRestaurant_EventScript_DontTakeSalt::
	msgbox SootoRestaurant_Text_DontTakeSalt, MSGBOX_AUTOCLOSE
	release
	end

SootoRestaurant_Text_TakeSalt:
	.string "you rob the salt!$"

SootoRestaurant_Text_DontTakeSalt:
	.string "best not to steal$"
