ZotpyreGym_MapScripts::
	.byte 0

ZotpyreGym_EventScript_ReplaceColumns1::
	lock
	goto_if_gt VAR_TEMP_5, 0, ZotpyreGym_EventScript_DontReplaceColumns
	msgbox ZotpyreGym_Text_IllMoveColumns, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_5, 1
	playse SE_M_COMET_PUNCH
	setmetatile 19, 16, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 19, 17, METATILE_OldStoneBuildings_ColumnShaft, FALSE
	setmetatile 19, 18, METATILE_OldStoneBuildings_ColumnShaft, TRUE
	setmetatile 12, 22, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 23, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 24, METATILE_OldStoneBuildings_ColumnTop, TRUE
	setmetatile 12, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 29, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 30, METATILE_OldStoneBuildings_ColumnTop, TRUE
	setmetatile 7, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 7, 29, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 19, 28, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 19, 29, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 7, 10, METATILE_OldStoneBuildings_RelicFloor, TRUE
	setmetatile 7, 11, METATILE_OldStoneBuildings_ColumnTop, TRUE
	special DrawWholeMapView
	release
	end

ZotpyreGym_EventScript_DontReplaceColumns::
	msgbox ZotpyreGym_Text_AlreadyMovedColumns, MSGBOX_AUTOCLOSE
	release
	end

ZotpyreGym_EventScript_ReplaceColumns2::
	lock
	goto_if_gt VAR_TEMP_6, 0, ZotpyreGym_EventScript_DontReplaceColumns
	msgbox ZotpyreGym_Text_IllMoveColumns, MSGBOX_AUTOCLOSE
	setvar VAR_TEMP_6, 1
	playse SE_M_COMET_PUNCH
	setmetatile 12, 9, METATILE_OldStoneBuildings_BottomWall, TRUE
	setmetatile 12, 10, METATILE_OldStoneBuildings_ColumnTop, FALSE
	setmetatile 12, 16, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 17, METATILE_OldStoneBuildings_RelicFloor, FALSE
	setmetatile 12, 18, METATILE_OldStoneBuildings_ColumnTop, TRUE
	special DrawWholeMapView
	release
	end

ZotpyreGym_EventScript_CheckForVar5::
	lock
	goto_if_eq VAR_TEMP_5, 0, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar6::
	lock
	goto_if_eq VAR_TEMP_6, 0, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar5And6::
	lock
	goto_if_eq VAR_TEMP_5, 0, ZotpyreGym_EventScript_WarpAway
	goto_if_eq VAR_TEMP_6, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckAgainstVar5::
	lock
	goto_if_eq VAR_TEMP_5, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_CheckForVar6And5::
	lock
	goto_if_eq VAR_TEMP_6, 1, ZotpyreGym_EventScript_WarpSafety
	goto_if_eq VAR_TEMP_5, 1, ZotpyreGym_EventScript_WarpAway
	release
	end

ZotpyreGym_EventScript_WarpAway::
	lock
	msgbox ZotpyreGym_Text_TheFogIsComing, MSGBOX_AUTOCLOSE
	warp MAP_ZOTPYRE_GYM, 16, 28
	waitstate
	release
	end

ZotpyreGym_EventScript_WarpSafety::
	release
	end

ZotpyreGym_Text_IllMoveColumns:
	.string "ill move deez columns$"

ZotpyreGym_Text_AlreadyMovedColumns:
	.string "already moved columns$"

ZotpyreGym_Text_TheFogIsComing:
	.string "the fog is coming$"
