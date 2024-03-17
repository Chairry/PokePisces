SSTidalExterior_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSTidalExterior_OnFrame
	.byte 0

SSTidalExterior_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, SSTidalExterior_EventScript_AllowedToLeave
	.2byte 0

SSTidalExterior_EventScript_AllowedToLeave::
	lockall
	playse SE_RG_SS_ANNE_HORN
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	setflag FLAG_HIDE_SSTIDAL_SAILOR
	msgbox SSTidalExterior_Text_AllowedToLeave, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

SSTidalExterior_EventScript_TopSailor::
	msgbox SSTidalExterior_Text_TopSailor, MSGBOX_NPC
	end

SSTidalExterior_EventScript_Wayfarer::
	msgbox SSTidalExterior_Text_Wayfarer, MSGBOX_NPC
	end

SSTidalExterior_EventScript_Breadwinner::
	msgbox SSTidalExterior_Text_Breadwinner, MSGBOX_NPC
	end

SSTidalExterior_EventScript_Hardhatter::
	msgbox SSTidalExterior_Text_Hardhatter, MSGBOX_NPC
	end

SSTidalExterior_EventScript_Electrician::
	msgbox SSTidalExterior_Text_Electrician, MSGBOX_DEFAULT
	closemessage
	end

SSTidalExterior_EventScript_Fisher::
	msgbox SSTidalExterior_Text_Fisher, MSGBOX_NPC
	end

SSTidalExterior_EventScript_BlockingSailor1::
	msgbox SSTidalExterior_Text_BlockingSailor1, MSGBOX_NPC
	end

SSTidalExterior_EventScript_BlockingSailor2::
	msgbox SSTidalExterior_Text_BlockingSailor2, MSGBOX_NPC
	end

SSTidalExterior_EventScript_CaptainsQuartersSign::
	msgbox SSTidalExterior_Text_CaptainsQuartersSign, MSGBOX_SIGN
	end

SSTidalExterior_EventScript_VIPCabinSign::
	msgbox SSTidalExterior_Text_VIPCabinSign, MSGBOX_SIGN
	end

SSTidalExterior_EventScript_EconomyCabinSign::
	msgbox SSTidalExterior_Text_EconomyCabinSign, MSGBOX_SIGN
	end

SSTidalExterior_Text_AllowedToLeave:
	.string "you can leave now$"

SSTidalExterior_Text_TopSailor:
	.string "The sea air smells great this\n"
	.string "morning! Fills me with a drive to\l"
	.string "get things done.$"

SSTidalExterior_Text_Wayfarer:
	.string "We aboard the S.S. Tidal hope you\n"
	.string "are enjoying your trip.$"

SSTidalExterior_Text_Breadwinner:
	.string "(There is a man here that\n"
	.string "is frantically checking his watch.)\p"
	.string "Oy vey... odds are, I-I'm going\n"
	.string "to be late for work today.\p"
	.string "Blast it! This is why I never take\n"
	.string "any vacations. Too risky...$"

SSTidalExterior_Text_Hardhatter:
	.string "(He's tightening the bolts\n"
	.string "on the railings.)$"

SSTidalExterior_Text_Electrician:
	.string "My goody gumdrops!! Work,\n"
	.string "you hunk of junk!!!$"

SSTidalExterior_Text_Fisher:
	.string "...Dang sailors took my fishing\n"
	.string "net away. Look, I can't help it\l"
	.string "if the ocean is the best\l"
	.string "place to bulk fish.\p"
	.string "Getting my own boat...\n"
	.string "that's too rich for my blood.$"

SSTidalExterior_Text_BlockingSailor1:
	.string "The trip should be over somewhat\n"
	.string "soon. Please hang tight until then.$"

SSTidalExterior_Text_BlockingSailor2:
	.string "Hey, woah there. Move right along.\n"
	.string "Can't risk passengers goin' down\l"
	.string "here while we're on the water.$"

SSTidalExterior_Text_CaptainsQuartersSign:
	.string "CAPTAIN'S QUARTERS$"

SSTidalExterior_Text_VIPCabinSign:
	.string "VIP CABIN$"

SSTidalExterior_Text_EconomyCabinSign:
	.string "ECONOMY CABINS$"
