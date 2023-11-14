	@ Set sRoomType to the next PIKE_ROOM_* id
	.macro pike_setnextroom
	
	special CallBattlePikeFunction
	.endm

	@ Get the value of some PIKE_DATA_*. See GetBattlePikeData for the data types that can be retrieved
	.macro pike_get data:req
	
	setvar VAR_0x8005, \data
	special CallBattlePikeFunction
	.endm

	@ Set some PIKE_DATA_* to val. See SetBattlePikeData for the data types that can be set
	.macro pike_set data:req, val:req
	
	setvar VAR_0x8005, \data
	.if \val >= VARS_START
	copyvar VAR_0x8006, \val
	.else
	setvar VAR_0x8006, \val
	.endif
	special CallBattlePikeFunction
	.endm

	@ TRUE if the next room is the last (15th) room, FALSE otherwise
	.macro pike_isfinalroom
	
	special CallBattlePikeFunction
	.endm

	@ Set the object event gfx for the room being entered
	.macro pike_setroomobjects
	
	special CallBattlePikeFunction
	.endm

	@ Get the current room type (sRoomType)
	.macro pike_getroomtype
	
	special CallBattlePikeFunction
	.endm

	@ Sets a bool that's never read
	.macro pike_inwildmonroom
	
	special CallBattlePikeFunction
	.endm

	@ Clears a bool that's never read
	.macro pike_exitwildmonroom
	
	special CallBattlePikeFunction
	.endm

	@ Save the game and set the challenge status
	.macro pike_save challengeStatus:req
	
	setvar VAR_0x8005, \challengeStatus
	special CallBattlePikeFunction
	.endm

	@ Returns the PIKE_STATUS_* to be afflicted for the status room
	.macro pike_getstatus	
	special CallBattlePikeFunction
	.endm

	@ Returns the PIKE_STATUSMON_* that attacks the player for the status room
	.macro pike_getstatusmon	
	special CallBattlePikeFunction
	.endm

	@ Randomly heals either one or two party mons and returns the number of mons healed
	.macro pike_healonetwomons	
	special CallBattlePikeFunction
	.endm

	@ Buffers a message for the lone NPC in the NPC room to gStringVar4
	.macro pike_getnpcmsg	
	special CallBattlePikeFunction
	.endm

	@ Flashes the screen 3 times for when the Dusclops/Kirlia attacks the player
	.macro pike_flashscreen	
	special CallBattlePikeFunction
	.endm

	@ TRUE if the player is currently in a Battle Pike challenge map
	.macro pike_inchallenge	
	special CallBattlePikeFunction
	.endm

	@ Set which room to give a hint about. TRUE if its the Pike Queens room next
	.macro pike_sethintroom	
	special CallBattlePikeFunction
	.endm

	@ Get PIKE_ROOM_(LEFT/CENTER/RIGHT) for which room to give a hint about
	.macro pike_gethintroomid	
	special CallBattlePikeFunction
	.endm

	@ Get the PIKE_HINT_* to give about the next room
	.macro pike_gethint	
	special CallBattlePikeFunction
	.endm

	@ Reset the frontier trainer ids for the start of the challenge
	.macro pike_cleartrainerids	
	special CallBattlePikeFunction
	.endm

	@ Buffer the opponents battle intro speech to gStringVar4. \trainer 0 for Trainer A, 1 for Trainer B
	.macro pike_gettrainerintro trainer:req	
	setvar VAR_0x8005, \trainer
	special CallBattlePikeFunction
	.endm

	@ Get the status of the Pike Queen (Not ready, Silver/Gold streak before symbols, Silver/Gold streak after symbols)
	.macro pike_getbrainstatus	
	special CallBattlePikeFunction
	.endm

	@ Heal 0-2 party mons depending on which room was chosen for the Pike Queen battle. Return the number healed
	.macro pike_prequeenheal	
	special CallBattlePikeFunction
	.endm

	@ When \set is TRUE, prevent healing rooms from appearing (for 1st room or when party is full health). \set FALSE to re-enable healing rooms
	.macro pike_nohealing set:req	
	setvar VAR_0x8005, \set
	special CallBattlePikeFunction
	.endm

	@ TRUE if the party is full health (full HP, PP, and no status), FALSE otherwise
	.macro pike_ispartyfullhealth	
	special CallBattlePikeFunction
	.endm

	@ Save the party held items in pikeHeldItemsBackup
	.macro pike_savehelditems	
	special CallBattlePikeFunction
	.endm

	@ Restore the party held items from pikeHeldItemsBackup
	.macro pike_resethelditems	
	special CallBattlePikeFunction
	.endm

	@ Initialize the Battle Pike challenge
	.macro pike_init	
	special CallBattlePikeFunction
	.endm
