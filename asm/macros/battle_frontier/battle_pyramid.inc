	@ Initialize the Battle Pyramid challenge
	.macro pyramid_init	
	special CallBattlePyramidFunction
	.endm

	@ Get the value of some PYRAMID_DATA_*. See GetBattlePyramidData for the data types that can be retrieved
	.macro pyramid_get data:req	
	setvar VAR_0x8005, \data
	special CallBattlePyramidFunction
	.endm

	@ Set some PYRAMID_DATA_* to val. See SetBattlePyramidData for the data types that can be set
	.macro pyramid_set data:req, val:req	
	setvar VAR_0x8005, \data
	setvar VAR_0x8006, \val
	special CallBattlePyramidFunction
	.endm

	@ Save the game and set the challenge status
	.macro pyramid_save challengeStatus:req	
	setvar VAR_0x8005, \challengeStatus
	special CallBattlePyramidFunction
	.endm

	@ Set the prize item to give from one of two lists of possible prizes, depending on streak.
	.macro pyramid_setprize	
	special CallBattlePyramidFunction
	.endm

	@ Unused. Give the set prize item to the player. TRUE if room in Bag for prize, FALSE otherwise
	.macro pyramid_giveprize	
	special CallBattlePyramidFunction
	.endm

	@ Set the random values for the floor (used to determine object positions, e.g.), and clear trainer flags
	.macro pyramid_seedfloor	
	special CallBattlePyramidFunction
	.endm

	@ Set the item to pick up depending on the random seed and quantity (always 1) to the arguments for STD_FIND_ITEM
	.macro pyramid_setitem	
	special CallBattlePyramidFunction
	.endm

	@ Hide the picked-up item (technically it moves the item far offscreen)
	.macro pyramid_hideitem	
	special CallBattlePyramidFunction
	.endm

	@ Set the facility trainers to gBattleFrontierTrainers
	.macro pyramid_settrainers	
	special CallBattlePyramidFunction
	.endm

	@ Show the post-battle hint text
	.macro pyramid_showhint	
	special CallBattlePyramidFunction
	.endm

	@ VAR_RESULT is 1 if player is on a Pyramid floor, 2 if on the Pyramid peak, 0 otherwise
	.macro pyramid_inchallenge	
	special CallBattlePyramidFunction
	.endm

	@ Update the light around the player. 2 different modes, for setting or incrementing light. See PYRAMID_LIGHT_*
	.macro pyramid_updatelight radius:req, mode:req, sound=0xFFFF	
	setvar VAR_0x8005, \radius
	setvar VAR_0x8006, \mode
	.if \sound != 0xFFFF
	setvar VAR_0x8007, \sound
	.endif
	special CallBattlePyramidFunction
	.endm

	@ Reset the held items to what they were at the start of the challenge
	.macro pyramid_clearhelditems	
	special CallBattlePyramidFunction
	.endm

	@ Set the palette depending on current floor number
	.macro pyramid_setfloorpal	
	special CallBattlePyramidFunction
	.endm

	@ Reset sketched moves and update the party order in the saveblock
	.macro pyramid_resetparty	
	special CallBattlePyramidFunction
	.endm
