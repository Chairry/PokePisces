OzoneInstitute_MapScripts::
	.byte 0

OzoneInstitute_EventScript_Gale::
    trainerbattle_single TRAINER_P_GALE, OzoneInstitute_Text_GaleIntro, OzoneInstitute_Text_GaleDefeated
    msgbox OzoneInstitute_Text_GalePostBattle, MSGBOX_AUTOCLOSE
    end

OzoneInstitute_EventScript_Smokey::
    trainerbattle_single TRAINER_P_SMOKEY, OzoneInstitute_Text_SmokeyIntro, OzoneInstitute_Text_SmokeyDefeated
    msgbox OzoneInstitute_Text_SmokeyPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneInstitute_EventScript_DessAndEmber::
    trainerbattle_double TRAINER_P_DESS_AND_EMBER, OzoneInstitute_Text_DessAndEmberIntro, OzoneInstitute_Text_DessAndEmberDefeated, OzoneInstitute_Text_DessAndEmberNeedTwoMons
    msgbox OzoneInstitute_Text_DessAndEmberPostBattle, MSGBOX_AUTOCLOSE
    end

OzoneInstitute_Text_GaleIntro:
	.string "intro$"

OzoneInstitute_Text_GaleDefeated:
	.string "defeat$"

OzoneInstitute_Text_GalePostBattle:
	.string "post$"

OzoneInstitute_Text_SmokeyIntro:
	.string "intro$"

OzoneInstitute_Text_SmokeyDefeated:
	.string "defeat$"

OzoneInstitute_Text_SmokeyPostBattle:
	.string "post$"

OzoneInstitute_Text_DessAndEmberIntro:
	.string "intro$"

OzoneInstitute_Text_DessAndEmberDefeated:
	.string "defeat$"

OzoneInstitute_Text_DessAndEmberPostBattle:
	.string "post$"

OzoneInstitute_Text_DessAndEmberNeedTwoMons:
	.string "need 2 dood$"
