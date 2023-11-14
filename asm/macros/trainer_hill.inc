	@ Initialize the Trainer Hill challenge and start the timer
	.macro trainerhill_start	
	special CallTrainerHillFunction
	.endm

	@ 0 if not spoken to yet, 1 if spoken to but not received prize, 2 if received prize
	.macro trainerhill_getownerstate	
	special CallTrainerHillFunction
	.endm

	@ Try to give prize. 0 if given successfully, 1 if no room for prize, 2 if giving prize should be skipped
	.macro trainerhill_giveprize	
	special CallTrainerHillFunction
	.endm

	@ Check the final challenge time. 0 if new record, 1 if not, 2 if time has already been checked
	.macro trainerhill_finaltime	
	special CallTrainerHillFunction
	.endm

	@ Resume the timer. Wont resume if owner has been spoken to or max time has been reached
	.macro trainerhill_resumetimer	
	special CallTrainerHillFunction
	.endm

	@ Set player lost the challenge (trainerHill.hasLost) to TRUE
	.macro trainerhill_lost	
	special CallTrainerHillFunction
	.endm

	@ Get the current challenge status (TRAINER_HILL_PLAYER_STATUS_*)
	.macro trainerhill_getstatus	
	special CallTrainerHillFunction
	.endm

	@ Buffer the current timer to string vars (mins to STR_VAR_1, secs to STR_VAR_2, fraction of sec to STR_VAR_3)
	.macro trainerhill_gettime
	special CallTrainerHillFunction
	.endm

	@ FALSE if fewer than all 4 floors used, TRUE otherwise. Only FALSE in JP-exclusive modes
	.macro trainerhill_allfloorsused
	special CallTrainerHillFunction
	.endm

	@ Unknown, dummied. E-Reader association is assumed. Only side effect is setting VAR_RESULT to 0.
	.macro trainerhill_getusingereader
	special CallTrainerHillFunction
	.endm

	@ TRUE if currently in a Trainer Hill challenge
	.macro trainerhill_inchallenge
	special CallTrainerHillFunction
	.endm

	@ Show the post battle text for the spoken to Trainer Hill trainer
	.macro trainerhill_postbattletext
	special CallTrainerHillFunction
	.endm

	@ Set all Trainer Hill trainers defeated
	.macro trainerhill_settrainerflags
	special CallTrainerHillFunction
	.endm

	@ TRUE if the game has been saved for the challenge, FALSE otherwise
	.macro trainerhill_getsaved	
	special CallTrainerHillFunction
	.endm

	@ Set that the game has been saved for the challenge
	.macro trainerhill_setsaved	
	special CallTrainerHillFunction
	.endm

	@ Clear that the game has been saved for the challenge
	.macro trainerhill_clearsaved	
	special CallTrainerHillFunction
	.endm

	@ FALSE if the Trainer Hill challenge was lost, TRUE otherwise
	.macro trainerhill_getwon	
	special CallTrainerHillFunction
	.endm

	@ Set the challenge mode to HILL_MODE_* (Normal, Variety, Unique, or Expert)
	.macro trainerhill_setmode mode:req	
	copyvar VAR_0x8005, \mode
	special CallTrainerHillFunction
	.endm
