SkyPillarInteriors_MapScripts::
	.byte 0

SkyPillarInteriors_EventScript_RockTombGuy::
    lock
	faceplayer
	checkitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, TRUE, SkyPillarInteriors_EventScript_GaveRockTomb
	msgbox SkyPillarInteriors_Text_DeltaStones, MSGBOX_DEFAULT
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

SkyPillarInteriors_EventScript_GaveRockTomb::
    msgbox SkyPillarInteriors_Text_BuriedPast, MSGBOX_AUTOCLOSE
    release
    end

SkyPillarInteriors_Text_DeltaStones:
	.string "The Sky Pillar is constructed out\n"
	.string "of the same material as those\l"
	.string "triangular Delta Stones.\p"
	.string "I suppose in a manner of speaking,\n"
	.string "the pillar is one huge Delta Stone!\p"
	.string "Because of this connection, some\n"
	.string "scholars have speculated that\l"
	.string "the Sky Pillar may have been\l"
	.string "built as a way of trapping some\l"
	.string "large being beneath it, its\l"
	.string "titanic weight locking it forever.\p"
	.string "But that's just some old wives tale!\p"
	.string "In the spirit of trapping Pokémon\n"
	.string "with rocks, take this TM.$"

SkyPillarInteriors_Text_BuriedPast:
	.string "In my many years, I have\n"
	.string "often wondered about what may lie\l"
	.string "buried right under our well-\l"
	.string "travelled daily paths.\p"
	.string "Maybe its down there for a reason!$"
