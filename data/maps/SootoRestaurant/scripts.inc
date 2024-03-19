SootoRestaurant_MapScripts::
	.byte 0

SootoRestaurant_EventScript_Chef::
	lock
	goto_if_eq VAR_PISCES_STORY_PROGRESS, 0, SootoRestaurant_EventScript_NotServing
	goto_if_unset FLAG_RECEIVED_SALT, SootoRestaurant_EventScript_HaveSomeSalt
	msgbox SootoRestaurant_Text_ChefPostSalt, MSGBOX_AUTOCLOSE
	release
	end

SootoRestaurant_EventScript_NotServing::
	msgbox SootoRestaurant_Text_ChefPreGym, MSGBOX_AUTOCLOSE
	release
	end

SootoRestaurant_EventScript_HaveSomeSalt::
	msgbox SootoRestaurant_Text_ChefPostGym, MSGBOX_AUTOCLOSE
	giveitem ITEM_SHOAL_SALT
	setflag FLAG_RECEIVED_SALT
	closemessage
	release
	end

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

SootoRestaurant_Text_ChefPreGym:
	.string "Terribly sorry, my dear customer.\n"
	.string "I'm afraid we are not selling our\n"
	.string "dishes at the moment.\p"
	.string "The owner is having a dinner party\n"
	.string "right now that we must cater.\p"
	.string "Deepest apologies, but we must request\n"
	.string "you to come back after said party.$"

SootoRestaurant_Text_ChefPostGym:
	.string "Ah, hello there!\n"
	.string "What may I serve you today?\p"
	.string "…\p"
	.string "You just want a plate with salt\n"
	.string "sprinkled on it?\p"
	.string "I can give you that for free.\n"
	.string "Odd, but who am I to judge?$"

SootoRestaurant_Text_ChefPostSalt:
	.string "Oh? Not feeling hungry?\p"
	.string "Well, we are always here if you change\n"
	.string "your mind!$"

SootoRestaurant_Text_TakeSalt:
	.string "…\p"
	.string "(No one's looking right now.)\p"
	.string "(You unscrew the top of the shaker and\n"
	.string "pour a bunch into your hands.)$"

SootoRestaurant_Text_DontTakeSalt:
	.string "(It's a salt shaker.)$"
