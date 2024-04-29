LilycoveMuseumNew_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LilycoveMuseumNew_OnLoad
	.byte 0

LilycoveMuseumNew_OnLoad:
	call_if_ge VAR_BALL_QUEST_STATE, 1, LilycoveMuseumNew_EventScript_PlacePainting1
	call_if_ge VAR_BALL_QUEST_STATE, 2, LilycoveMuseumNew_EventScript_PlacePainting2
	call_if_ge VAR_BALL_QUEST_STATE, 3, LilycoveMuseumNew_EventScript_PlacePainting3
	call_if_ge VAR_BALL_QUEST_STATE, 4, LilycoveMuseumNew_EventScript_PlacePainting4
	call_if_ge VAR_BALL_QUEST_STATE, 5, LilycoveMuseumNew_EventScript_PlacePainting5
	call_if_ge VAR_BALL_QUEST_STATE, 6, LilycoveMuseumNew_EventScript_PlacePainting6
	call_if_ge VAR_BALL_QUEST_STATE, 7, LilycoveMuseumNew_EventScript_PlacePainting7
	call_if_ge VAR_BALL_QUEST_STATE, 8, LilycoveMuseumNew_EventScript_PlacePainting8
	call_if_ge VAR_BALL_QUEST_STATE, 9, LilycoveMuseumNew_EventScript_PlacePainting9
	call_if_ge VAR_BALL_QUEST_STATE, 10, LilycoveMuseumNew_EventScript_PlacePainting10
	call_if_ge VAR_BALL_QUEST_STATE, 11, LilycoveMuseumNew_EventScript_PlacePainting11
	call_if_ge VAR_BALL_QUEST_STATE, 12, LilycoveMuseumNew_EventScript_PlacePainting12
	call_if_ge VAR_BALL_QUEST_STATE, 13, LilycoveMuseumNew_EventScript_PlacePainting13
	call_if_ge VAR_BALL_QUEST_STATE, 14, LilycoveMuseumNew_EventScript_PlacePainting14
	end

LilycoveMuseumNew_EventScript_PlacePainting1::
	setmetatile 8, 10, METATILE_OldStoneBuildings_Painting1TopLeft, TRUE
	setmetatile 9, 10, METATILE_OldStoneBuildings_Painting1TopRight, TRUE
	setmetatile 8, 11, METATILE_OldStoneBuildings_Painting1BottomLeft, TRUE
	setmetatile 9, 11, METATILE_OldStoneBuildings_Painting1BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting2::
	setmetatile 17, 8, METATILE_OldStoneBuildings_Painting2TopLeft, TRUE
	setmetatile 18, 8, METATILE_OldStoneBuildings_Painting2TopRight, TRUE
	setmetatile 17, 9, METATILE_OldStoneBuildings_Painting2BottomLeft, TRUE
	setmetatile 18, 9, METATILE_OldStoneBuildings_Painting2BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting3::
	setmetatile 4, 0, METATILE_OldStoneBuildings_Painting3TopLeft, TRUE
	setmetatile 5, 0, METATILE_OldStoneBuildings_Painting3TopRight, TRUE
	setmetatile 4, 1, METATILE_OldStoneBuildings_Painting3BottomLeft, TRUE
	setmetatile 5, 1, METATILE_OldStoneBuildings_Painting3BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting4::
	setmetatile 4, 5, METATILE_OldStoneBuildings_Painting4TopLeft, TRUE
	setmetatile 5, 5, METATILE_OldStoneBuildings_Painting4TopRight, TRUE
	setmetatile 4, 6, METATILE_OldStoneBuildings_Painting4BottomLeft, TRUE
	setmetatile 5, 6, METATILE_OldStoneBuildings_Painting4BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting5::
	setmetatile 21, 8, METATILE_OldStoneBuildings_Painting5TopLeft, TRUE
	setmetatile 22, 8, METATILE_OldStoneBuildings_Painting5TopRight, TRUE
	setmetatile 21, 9, METATILE_OldStoneBuildings_Painting5BottomLeft, TRUE
	setmetatile 22, 9, METATILE_OldStoneBuildings_Painting5BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting6::
	setmetatile 17, 3, METATILE_OldStoneBuildings_Painting6TopLeft, TRUE
	setmetatile 18, 3, METATILE_OldStoneBuildings_Painting6TopRight, TRUE
	setmetatile 17, 4, METATILE_OldStoneBuildings_Painting6BottomLeft, TRUE
	setmetatile 18, 4, METATILE_OldStoneBuildings_Painting6BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting7::
	setmetatile 10, 0, METATILE_OldStoneBuildings_Painting7TopLeft, TRUE
	setmetatile 11, 0, METATILE_OldStoneBuildings_Painting7TopRight, TRUE
	setmetatile 10, 1, METATILE_OldStoneBuildings_Painting7BottomLeft, TRUE
	setmetatile 11, 1, METATILE_OldStoneBuildings_Painting7BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting8::
	setmetatile 0, 5, METATILE_OldStoneBuildings_Painting8TopLeft, TRUE
	setmetatile 1, 5, METATILE_OldStoneBuildings_Painting8TopRight, TRUE
	setmetatile 0, 6, METATILE_OldStoneBuildings_Painting8BottomLeft, TRUE
	setmetatile 1, 6, METATILE_OldStoneBuildings_Painting8BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting9::
	setmetatile 4, 10, METATILE_OldStoneBuildings_Painting9TopLeft, TRUE
	setmetatile 5, 10, METATILE_OldStoneBuildings_Painting9TopRight, TRUE
	setmetatile 4, 11, METATILE_OldStoneBuildings_Painting9BottomLeft, TRUE
	setmetatile 5, 11, METATILE_OldStoneBuildings_Painting9BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting10::
	setmetatile 1, 0, METATILE_OldStoneBuildings_Painting10TopLeft, TRUE
	setmetatile 2, 0, METATILE_OldStoneBuildings_Painting10TopRight, TRUE
	setmetatile 1, 1, METATILE_OldStoneBuildings_Painting10BottomLeft, TRUE
	setmetatile 2, 1, METATILE_OldStoneBuildings_Painting10BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting11::
	setmetatile 21, 3, METATILE_OldStoneBuildings_Painting11TopLeft, TRUE
	setmetatile 22, 3, METATILE_OldStoneBuildings_Painting11TopRight, TRUE
	setmetatile 21, 4, METATILE_OldStoneBuildings_Painting11BottomLeft, TRUE
	setmetatile 22, 4, METATILE_OldStoneBuildings_Painting11BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting12::
	setmetatile 8, 5, METATILE_OldStoneBuildings_Painting12TopLeft, TRUE
	setmetatile 9, 5, METATILE_OldStoneBuildings_Painting12TopRight, TRUE
	setmetatile 8, 6, METATILE_OldStoneBuildings_Painting12BottomLeft, TRUE
	setmetatile 9, 6, METATILE_OldStoneBuildings_Painting12BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting13::
	setmetatile 7, 0, METATILE_OldStoneBuildings_Painting13TopLeft, TRUE
	setmetatile 8, 0, METATILE_OldStoneBuildings_Painting13TopRight, TRUE
	setmetatile 7, 1, METATILE_OldStoneBuildings_Painting13BottomLeft, TRUE
	setmetatile 8, 1, METATILE_OldStoneBuildings_Painting13BottomRight, TRUE
	special DrawWholeMapView
	return

LilycoveMuseumNew_EventScript_PlacePainting14::
	setmetatile 0, 10, METATILE_OldStoneBuildings_Painting14TopLeft, TRUE
	setmetatile 1, 10, METATILE_OldStoneBuildings_Painting14TopRight, TRUE
	setmetatile 0, 11, METATILE_OldStoneBuildings_Painting14BottomLeft, TRUE
	setmetatile 1, 11, METATILE_OldStoneBuildings_Painting14BottomRight, TRUE
	special DrawWholeMapView
	return
