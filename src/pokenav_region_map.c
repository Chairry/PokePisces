#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "heal_location.h"
#include "landmark.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokenav.h"
#include "region_map.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "window.h"
#include "constants/heal_locations.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/region_map_sections.h"

#define GFXTAG_CITY_ZOOM 6
#define PALTAG_CITY_ZOOM 11

#define NUM_CITY_MAPS 22

struct Pokenav_RegionMapMenu
{
    u8 unused[12];
    bool32 zoomDisabled;
    u32 (*callback)(struct Pokenav_RegionMapMenu *);
};

struct Pokenav_RegionMapGfx
{
    bool32 (*isTaskActiveCB)(void);
    u32 loopTaskId;
    u16 infoWindowId;
    struct Sprite *cityZoomTextSprites[3];
    u8 ALIGNED(2) tilemapBuffer[BG_SCREEN_SIZE];
    u8 cityZoomPics[NUM_CITY_MAPS][200];
};

struct CityMapEntry
{
    u16 mapSecId;
    u16 index;
    const u32 *tilemap;
};

static u32 HandleRegionMapInput(struct Pokenav_RegionMapMenu *);
static u32 HandleRegionMapInputZoomDisabled(struct Pokenav_RegionMapMenu *);
static u32 GetExitRegionMapMenuId(struct Pokenav_RegionMapMenu *);
static u32 LoopedTask_OpenRegionMap(s32);
static u32 LoopedTask_DecompressCityMaps(s32);
static bool32 GetCurrentLoopedTaskActive(void);
static void FreeCityZoomViewGfx(void);
static void LoadCityZoomViewGfx(void);
static void DecompressCityMaps(void);
static bool32 IsDecompressCityMapsActive(void);
static void LoadPokenavRegionMapGfx(struct Pokenav_RegionMapGfx *);
static bool32 TryFreeTempTileDataBuffers(void);
static void UpdateMapSecInfoWindow(struct Pokenav_RegionMapGfx *);
static bool32 IsDma3ManagerBusyWithBgCopy_(struct Pokenav_RegionMapGfx *);
static void ChangeBgYForZoom(bool32);
static bool32 IsChangeBgYForZoomActive(void);
static void CreateCityZoomTextSprites(void);
static void DrawCityMap(struct Pokenav_RegionMapGfx *, int, int);
static void PrintLandmarkNames(struct Pokenav_RegionMapGfx *, int, int);
static void SetCityZoomTextInvisibility(bool32);
static void Task_ChangeBgYForZoom(u8 taskId);
static void UpdateCityZoomTextPosition(void);
static void SpriteCB_CityZoomText(struct Sprite *sprite);
static u32 LoopedTask_UpdateInfoAfterCursorMove(s32);
static u32 LoopedTask_RegionMapZoomOut(s32);
static u32 LoopedTask_RegionMapZoomIn(s32);
static u32 LoopedTask_ExitRegionMap(s32);

extern const u16 gRegionMapCityZoomTiles_Pal[];
extern const u32 gRegionMapCityZoomText_Gfx[];

static const u16 sMapSecInfoWindow_Pal[] = INCBIN_U16("graphics/pokenav/region_map/info_window.gbapal");
static const u32 sRegionMapCityZoomTiles_Gfx[] = INCBIN_U32("graphics/pokenav/region_map/zoom_tiles.4bpp.lz");

static const u8 sMapHealLocations[][3] =
{
    [MAPSEC_LITTLEROOT_TOWN] = {MAP_GROUP(LITTLEROOT_TOWN), MAP_NUM(LITTLEROOT_TOWN), HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F},
    [MAPSEC_OLDALE_TOWN] = {MAP_GROUP(OLDALE_TOWN), MAP_NUM(OLDALE_TOWN), HEAL_LOCATION_OLDALE_TOWN},
    [MAPSEC_DEWFORD_TOWN] = {MAP_GROUP(DEWFORD_TOWN), MAP_NUM(DEWFORD_TOWN), HEAL_LOCATION_DEWFORD_TOWN},
    [MAPSEC_LAVARIDGE_TOWN] = {MAP_GROUP(LAVARIDGE_TOWN), MAP_NUM(LAVARIDGE_TOWN), HEAL_LOCATION_LAVARIDGE_TOWN},
    [MAPSEC_FALLARBOR_TOWN] = {MAP_GROUP(FALLARBOR_TOWN), MAP_NUM(FALLARBOR_TOWN), HEAL_LOCATION_FALLARBOR_TOWN},
    [MAPSEC_VERDANTURF_TOWN] = {MAP_GROUP(VERDANTURF_TOWN), MAP_NUM(VERDANTURF_TOWN), HEAL_LOCATION_VERDANTURF_TOWN},
    [MAPSEC_PACIFIDLOG_TOWN] = {MAP_GROUP(PACIFIDLOG_TOWN), MAP_NUM(PACIFIDLOG_TOWN), HEAL_LOCATION_PACIFIDLOG_TOWN},
    [MAPSEC_PETALBURG_CITY] = {MAP_GROUP(PETALBURG_CITY), MAP_NUM(PETALBURG_CITY), HEAL_LOCATION_PETALBURG_CITY},
    [MAPSEC_SLATEPORT_CITY] = {MAP_GROUP(SLATEPORT_CITY), MAP_NUM(SLATEPORT_CITY), HEAL_LOCATION_SLATEPORT_CITY},
    [MAPSEC_MAUVILLE_CITY] = {MAP_GROUP(MAUVILLE_CITY), MAP_NUM(MAUVILLE_CITY), HEAL_LOCATION_MAUVILLE_CITY},
    [MAPSEC_RUSTBORO_CITY] = {MAP_GROUP(RUSTBORO_CITY), MAP_NUM(RUSTBORO_CITY), HEAL_LOCATION_RUSTBORO_CITY},
    [MAPSEC_FORTREE_CITY] = {MAP_GROUP(FORTREE_CITY), MAP_NUM(FORTREE_CITY), HEAL_LOCATION_FORTREE_CITY},
    [MAPSEC_LILYCOVE_CITY] = {MAP_GROUP(LILYCOVE_CITY), MAP_NUM(LILYCOVE_CITY), HEAL_LOCATION_LILYCOVE_CITY},
    [MAPSEC_MOSSDEEP_CITY] = {MAP_GROUP(MOSSDEEP_CITY), MAP_NUM(MOSSDEEP_CITY), HEAL_LOCATION_MOSSDEEP_CITY},
    [MAPSEC_SOOTOPOLIS_CITY] = {MAP_GROUP(SOOTOPOLIS_CITY), MAP_NUM(SOOTOPOLIS_CITY), HEAL_LOCATION_SOOTOPOLIS_CITY},
    [MAPSEC_EVER_GRANDE_CITY] = {MAP_GROUP(EVER_GRANDE_CITY), MAP_NUM(EVER_GRANDE_CITY), HEAL_LOCATION_EVER_GRANDE_CITY},
    [MAPSEC_ROUTE_101] = {MAP_GROUP(ROUTE101), MAP_NUM(ROUTE101), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_102] = {MAP_GROUP(ROUTE102), MAP_NUM(ROUTE102), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_103] = {MAP_GROUP(ROUTE103), MAP_NUM(ROUTE103), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_104] = {MAP_GROUP(ROUTE104), MAP_NUM(ROUTE104), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_105] = {MAP_GROUP(ROUTE105), MAP_NUM(ROUTE105), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_106] = {MAP_GROUP(ROUTE106), MAP_NUM(ROUTE106), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_107] = {MAP_GROUP(ROUTE107), MAP_NUM(ROUTE107), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_108] = {MAP_GROUP(ROUTE108), MAP_NUM(ROUTE108), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_109] = {MAP_GROUP(ROUTE109), MAP_NUM(ROUTE109), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_110] = {MAP_GROUP(ROUTE110), MAP_NUM(ROUTE110), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_111] = {MAP_GROUP(ROUTE111), MAP_NUM(ROUTE111), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_112] = {MAP_GROUP(ROUTE112), MAP_NUM(ROUTE112), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_113] = {MAP_GROUP(ROUTE113), MAP_NUM(ROUTE113), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_114] = {MAP_GROUP(ROUTE114), MAP_NUM(ROUTE114), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_115] = {MAP_GROUP(ROUTE115), MAP_NUM(ROUTE115), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_116] = {MAP_GROUP(ROUTE116), MAP_NUM(ROUTE116), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_117] = {MAP_GROUP(ROUTE117), MAP_NUM(ROUTE117), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_118] = {MAP_GROUP(ROUTE118), MAP_NUM(ROUTE118), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_119] = {MAP_GROUP(ROUTE119), MAP_NUM(ROUTE119), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_120] = {MAP_GROUP(ROUTE120), MAP_NUM(ROUTE120), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_121] = {MAP_GROUP(ROUTE121), MAP_NUM(ROUTE121), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_122] = {MAP_GROUP(ROUTE122), MAP_NUM(ROUTE122), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_123] = {MAP_GROUP(ROUTE123), MAP_NUM(ROUTE123), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_124] = {MAP_GROUP(ROUTE124), MAP_NUM(ROUTE124), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_125] = {MAP_GROUP(ROUTE125), MAP_NUM(ROUTE125), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_126] = {MAP_GROUP(ROUTE126), MAP_NUM(ROUTE126), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_127] = {MAP_GROUP(ROUTE127), MAP_NUM(ROUTE127), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_128] = {MAP_GROUP(ROUTE128), MAP_NUM(ROUTE128), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_129] = {MAP_GROUP(ROUTE129), MAP_NUM(ROUTE129), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_130] = {MAP_GROUP(ROUTE130), MAP_NUM(ROUTE130), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_131] = {MAP_GROUP(ROUTE131), MAP_NUM(ROUTE131), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_132] = {MAP_GROUP(ROUTE132), MAP_NUM(ROUTE132), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_133] = {MAP_GROUP(ROUTE133), MAP_NUM(ROUTE133), HEAL_LOCATION_NONE},
    [MAPSEC_ROUTE_134] = {MAP_GROUP(ROUTE134), MAP_NUM(ROUTE134), HEAL_LOCATION_NONE},
};

#include "data/region_map/city_map_tilemaps.h"

static const struct BgTemplate sRegionMapBgTemplates[3] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 0x1F,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 0x06,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 0x00,
        .screenSize = 2,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    },
};

static const LoopedTask sRegionMapLoopTaskFuncs[] =
{
    [POKENAV_MAP_FUNC_NONE]         = NULL,
    [POKENAV_MAP_FUNC_CURSOR_MOVED] = LoopedTask_UpdateInfoAfterCursorMove,
    [POKENAV_MAP_FUNC_ZOOM_OUT]     = LoopedTask_RegionMapZoomOut,
    [POKENAV_MAP_FUNC_ZOOM_IN]      = LoopedTask_RegionMapZoomIn,
    [POKENAV_MAP_FUNC_EXIT]         = LoopedTask_ExitRegionMap
};

static const struct CompressedSpriteSheet sCityZoomTextSpriteSheet[1] =
{
    {gRegionMapCityZoomText_Gfx, 0x800, GFXTAG_CITY_ZOOM}
};

static const struct SpritePalette sCityZoomTilesSpritePalette[] =
{
    {gRegionMapCityZoomTiles_Pal, PALTAG_CITY_ZOOM},
    {}
};

static const struct WindowTemplate sMapSecInfoWindowTemplate =
{
    .bg = 1,
    .tilemapLeft = 17,
    .tilemapTop = 4,
    .width = 12,
    .height = 13,
    .paletteNum = 1,
    .baseBlock = 0x4C
};

#include "data/region_map/city_map_entries.h"

static const struct OamData sCityZoomTextSprite_OamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x8),
    .x = 0,
    .size = SPRITE_SIZE(32x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const struct SpriteTemplate sCityZoomTextSpriteTemplate =
{
    .tileTag = GFXTAG_CITY_ZOOM,
    .paletteTag = PALTAG_CITY_ZOOM,
    .oam = &sCityZoomTextSprite_OamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_CityZoomText,
};

u32 PokenavCallback_Init_RegionMap(void)
{
    struct Pokenav_RegionMapMenu *state = AllocSubstruct(POKENAV_SUBSTRUCT_REGION_MAP_STATE, sizeof(struct Pokenav_RegionMapMenu));
    if (!state)
        return FALSE;

    if (!AllocSubstruct(POKENAV_SUBSTRUCT_REGION_MAP, sizeof(struct RegionMap)))
        return FALSE;

    state->zoomDisabled = IsEventIslandMapSecId(gMapHeader.regionMapSectionId);
    if (!state->zoomDisabled)
        state->callback = HandleRegionMapInput;
    else
        state->callback = HandleRegionMapInputZoomDisabled;

    return TRUE;
}

void FreeRegionMapSubstruct1(void)
{
    gSaveBlock2Ptr->regionMapZoom = IsRegionMapZoomed();
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_REGION_MAP);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_REGION_MAP_STATE);
}

u32 GetRegionMapCallback(void)
{
    struct Pokenav_RegionMapMenu *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_STATE);
    return state->callback(state);
}

static u32 HandleRegionMapInput(struct Pokenav_RegionMapMenu *state)
{
    struct RegionMap *regionMap = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP);
    switch (DoRegionMapInputCallback())
    {
    case MAP_INPUT_MOVE_END:
        return POKENAV_MAP_FUNC_CURSOR_MOVED;
    case MAP_INPUT_R_BUTTON:
        if (!IsRegionMapZoomed())
            return POKENAV_MAP_FUNC_ZOOM_IN;
        return POKENAV_MAP_FUNC_ZOOM_OUT;
    case MAP_INPUT_B_BUTTON:
        state->callback = GetExitRegionMapMenuId;
        return POKENAV_MAP_FUNC_EXIT;
    case MAP_INPUT_A_BUTTON:
        if(regionMap->mapSecType == MAPSECTYPE_CITY_CANFLY && FlagGet(FLAG_BADGE04_GET)) {
            switch (regionMap->mapSecId)
            {
            case MAPSEC_SOUTHERN_ISLAND:
                SetWarpDestinationToHealLocation(HEAL_LOCATION_SOUTHERN_ISLAND_EXTERIOR);
                break;
            case MAPSEC_BATTLE_FRONTIER:
                SetWarpDestinationToHealLocation(HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST);
                break;
            case MAPSEC_LITTLEROOT_TOWN:
                SetWarpDestinationToHealLocation(gSaveBlock2Ptr->playerGender == MALE ? HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE : HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE);
                break;
            case MAPSEC_EVER_GRANDE_CITY:
                SetWarpDestinationToHealLocation(FlagGet(FLAG_LANDMARK_POKEMON_LEAGUE) && regionMap->posWithinMapSec == 0 ? HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE : HEAL_LOCATION_EVER_GRANDE_CITY);
                break;
            default:
                if (sMapHealLocations[regionMap->mapSecId][2] != HEAL_LOCATION_NONE)
                    SetWarpDestinationToHealLocation(sMapHealLocations[regionMap->mapSecId][2]);
                else
                    SetWarpDestinationToMapWarp(sMapHealLocations[regionMap->mapSecId][0], sMapHealLocations[regionMap->mapSecId][1], WARP_ID_NONE);
                break;
            }
            ReturnToFieldFromFlyMapSelect();
        }
    }
    return POKENAV_MAP_FUNC_NONE;
}

static u32 HandleRegionMapInputZoomDisabled(struct Pokenav_RegionMapMenu *state)
{
    if (JOY_NEW(B_BUTTON))
    {
        state->callback = GetExitRegionMapMenuId;
        return POKENAV_MAP_FUNC_EXIT;
    }

    return POKENAV_MAP_FUNC_NONE;
}

static u32 GetExitRegionMapMenuId(struct Pokenav_RegionMapMenu *state)
{
    return POKENAV_MAIN_MENU_CURSOR_ON_MAP;
}

bool32 GetZoomDisabled(void)
{
    struct Pokenav_RegionMapMenu *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_STATE);
    return state->zoomDisabled;
}

bool32 OpenPokenavRegionMap(void)
{
    struct Pokenav_RegionMapGfx *state = AllocSubstruct(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM, sizeof(struct Pokenav_RegionMapGfx));
    if (!state)
        return FALSE;

    state->loopTaskId = CreateLoopedTask(LoopedTask_OpenRegionMap, 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
    return TRUE;
}

void CreateRegionMapLoopedTask(s32 index)
{
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    state->loopTaskId = CreateLoopedTask(sRegionMapLoopTaskFuncs[index], 1);
    state->isTaskActiveCB = GetCurrentLoopedTaskActive;
}

bool32 IsRegionMapLoopedTaskActive(void)
{
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    return state->isTaskActiveCB();
}

void FreeRegionMapSubstruct2(void)
{
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    FreeRegionMapIconResources();
    FreeCityZoomViewGfx();
    RemoveWindow(state->infoWindowId);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_REGION_MAP);
    FreePokenavSubstruct(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    SetPokenavVBlankCallback();
    SetBgMode(0);
}

static void VBlankCB_RegionMap(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    UpdateRegionMapVideoRegs();
}

static bool32 GetCurrentLoopedTaskActive(void)
{
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    return IsLoopedTaskActive(state->loopTaskId);
}

static bool8 ShouldOpenRegionMapZoomed(void)
{
    if (GetZoomDisabled())
        return FALSE;

    return gSaveBlock2Ptr->regionMapZoom == TRUE;
}

static u32 LoopedTask_OpenRegionMap(s32 taskState)
{
    int menuGfxId;
    struct RegionMap *regionMap;
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    switch (taskState)
    {
    case 0:
        SetVBlankCallback_(NULL);
        HideBg(1);
        HideBg(2);
        HideBg(3);
        SetBgMode(1);
        InitBgTemplates(sRegionMapBgTemplates, ARRAY_COUNT(sRegionMapBgTemplates) - 1);
        regionMap = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP);
        InitRegionMapData(regionMap, &sRegionMapBgTemplates[1], ShouldOpenRegionMapZoomed());
        LoadCityZoomViewGfx();
        return LT_INC_AND_PAUSE;
    case 1:
        if (LoadRegionMapGfx())
            return LT_PAUSE;

        if (!GetZoomDisabled())
        {
            CreateRegionMapPlayerIcon(4, 9);
            CreateRegionMapCursor(5, 10);
            TrySetPlayerIconBlink();
        }
        else
        {
            // Dim the region map when zoom is disabled
            // (when the player is off the map)
            BlendRegionMap(RGB_BLACK, 6);
        }
        return LT_INC_AND_PAUSE;
    case 2:
        DecompressCityMaps();
        return LT_INC_AND_CONTINUE;
    case 3:
        if (IsDecompressCityMapsActive())
            return LT_PAUSE;

        LoadPokenavRegionMapGfx(state);
        return LT_INC_AND_CONTINUE;
    case 4:
        if (TryFreeTempTileDataBuffers())
            return LT_PAUSE;

        UpdateMapSecInfoWindow(state);
        FadeToBlackExceptPrimary();
        return LT_INC_AND_PAUSE;
    case 5:
        if (IsDma3ManagerBusyWithBgCopy_(state))
            return LT_PAUSE;

        ShowBg(1);
        ShowBg(2);
        SetVBlankCallback_(VBlankCB_RegionMap);
        return LT_INC_AND_PAUSE;
    case 6:
        if (!ShouldOpenRegionMapZoomed())
            menuGfxId = POKENAV_GFX_MAP_MENU_ZOOMED_OUT;
        else
            menuGfxId = POKENAV_GFX_MAP_MENU_ZOOMED_IN;

        LoadLeftHeaderGfxForIndex(menuGfxId);
        ShowLeftHeaderGfx(menuGfxId, TRUE, TRUE);
        PokenavFadeScreen(POKENAV_FADE_FROM_BLACK);
        return LT_INC_AND_PAUSE;
    case 7:
        if (IsPaletteFadeActive() || AreLeftHeaderSpritesMoving())
            return LT_PAUSE;
        return LT_INC_AND_CONTINUE;
    default:
        return LT_FINISH;
    }
}

static u32 LoopedTask_UpdateInfoAfterCursorMove(s32 taskState)
{
    struct RegionMap *regionMap = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP);
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    switch (taskState)
    {
    case 0:
        UpdateMapSecInfoWindow(state);        
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy_(state))
            return LT_PAUSE;
        if (regionMap->mapSecType == MAPSECTYPE_CITY_CANFLY && FlagGet(FLAG_BADGE04_GET))
            PrintHelpBarText(HELPBAR_CAN_FLY);
        else
            PrintHelpBarText(HELPBAR_MAP_ZOOMED_OUT);        
        break;
    }

    return LT_FINISH;
}

static u32 LoopedTask_RegionMapZoomOut(s32 taskState)
{   
    struct RegionMap *regionMap = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        ChangeBgYForZoom(FALSE);
        SetRegionMapDataForZoom();
        return LT_INC_AND_PAUSE;
    case 1:
        if (UpdateRegionMapZoom() || IsChangeBgYForZoomActive())
            return LT_PAUSE;
        if (regionMap->mapSecType == MAPSECTYPE_CITY_CANFLY && FlagGet(FLAG_BADGE04_GET))
            PrintHelpBarText(HELPBAR_CAN_FLY);
        else
            PrintHelpBarText(HELPBAR_MAP_ZOOMED_OUT);         
        return LT_INC_AND_PAUSE;
    case 2:
        if (WaitForHelpBar())
            return LT_PAUSE;

        UpdateRegionMapRightHeaderTiles(POKENAV_GFX_MAP_MENU_ZOOMED_OUT);
        break;
    }

    return LT_FINISH;
}

static u32 LoopedTask_RegionMapZoomIn(s32 taskState)
{
    struct RegionMap *regionMap = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP);
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        UpdateMapSecInfoWindow(state);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy_(state))
            return LT_PAUSE;

        ChangeBgYForZoom(TRUE);
        SetRegionMapDataForZoom();
        return LT_INC_AND_PAUSE;
    case 2:
        if (UpdateRegionMapZoom() || IsChangeBgYForZoomActive())
            return LT_PAUSE;
        if (regionMap->mapSecType == MAPSECTYPE_CITY_CANFLY && FlagGet(FLAG_BADGE04_GET))
            PrintHelpBarText(HELPBAR_CAN_FLY);
        else
            PrintHelpBarText(HELPBAR_MAP_ZOOMED_IN);     
        return LT_INC_AND_PAUSE;
    case 3:
        if (WaitForHelpBar())
            return LT_PAUSE;

        UpdateRegionMapRightHeaderTiles(POKENAV_GFX_MAP_MENU_ZOOMED_IN);
        break;
    }

    return LT_FINISH;
}

static u32 LoopedTask_ExitRegionMap(s32 taskState)
{
    switch (taskState)
    {
    case 0:
        PlaySE(SE_SELECT);
        PokenavFadeScreen(POKENAV_FADE_TO_BLACK);
        return LT_INC_AND_PAUSE;
    case 1:
        if (IsPaletteFadeActive())
            return LT_PAUSE;

        SetLeftHeaderSpritesInvisibility();
        SlideMenuHeaderDown();
        return LT_INC_AND_PAUSE;
    case 2:
        if (MainMenuLoopedTaskIsBusy())
            return LT_PAUSE;

        HideBg(1);
        HideBg(2);
        HideBg(3);
        return LT_INC_AND_PAUSE;
    }

    return LT_FINISH;
}

static void LoadCityZoomViewGfx(void)
{
    int i;
    for (i = 0; i < ARRAY_COUNT(sCityZoomTextSpriteSheet); i++)
        LoadCompressedSpriteSheet(&sCityZoomTextSpriteSheet[i]);

    Pokenav_AllocAndLoadPalettes(sCityZoomTilesSpritePalette);
    CreateCityZoomTextSprites();
}

static void FreeCityZoomViewGfx(void)
{
    int i;
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    FreeSpriteTilesByTag(GFXTAG_CITY_ZOOM);
    FreeSpritePaletteByTag(PALTAG_CITY_ZOOM);
    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
        DestroySprite(state->cityZoomTextSprites[i]);
}

static void LoadPokenavRegionMapGfx(struct Pokenav_RegionMapGfx *state)
{
    BgDmaFill(1, PIXEL_FILL(0), 0x40, 1);
    BgDmaFill(1, PIXEL_FILL(1), 0x41, 1);
    CpuFill16(0x1040, state->tilemapBuffer, 0x800);
    SetBgTilemapBuffer(1, state->tilemapBuffer);
    state->infoWindowId = AddWindow(&sMapSecInfoWindowTemplate);
    LoadUserWindowBorderGfx_(state->infoWindowId, 0x42, BG_PLTT_ID(4));
    DrawTextBorderOuter(state->infoWindowId, 0x42, 4);
    DecompressAndCopyTileDataToVram(1, sRegionMapCityZoomTiles_Gfx, 0, 0, 0);
    FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
    PutWindowTilemap(state->infoWindowId);
    CopyWindowToVram(state->infoWindowId, COPYWIN_FULL);
    CopyPaletteIntoBufferUnfaded(sMapSecInfoWindow_Pal, BG_PLTT_ID(1), sizeof(sMapSecInfoWindow_Pal));
    CopyPaletteIntoBufferUnfaded(gRegionMapCityZoomTiles_Pal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
    if (!IsRegionMapZoomed())
        ChangeBgY(1, -0x6000, BG_COORD_SET);
    else
        ChangeBgY(1, 0, BG_COORD_SET);

    ChangeBgX(1, 0, BG_COORD_SET);
}

static bool32 TryFreeTempTileDataBuffers(void)
{
    return FreeTempTileDataBuffersIfPossible();
}

static void UpdateMapSecInfoWindow(struct Pokenav_RegionMapGfx *state)
{
    struct RegionMap *regionMap = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP);
    switch (regionMap->mapSecType)
    {
    case MAPSECTYPE_CITY_CANFLY:        
        FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
        PutWindowRectTilemap(state->infoWindowId, 0, 0, 12, 2);
        AddTextPrinterParameterized(state->infoWindowId, FONT_NARROW, regionMap->mapSecName, 0, 1, TEXT_SKIP_DRAW, NULL);
        DrawCityMap(state, regionMap->mapSecId, regionMap->posWithinMapSec);
        CopyWindowToVram(state->infoWindowId, COPYWIN_FULL);
        SetCityZoomTextInvisibility(FALSE);
        break;
    case MAPSECTYPE_CITY_CANTFLY:
        FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
        PutWindowRectTilemap(state->infoWindowId, 0, 0, 12, 2);
        AddTextPrinterParameterized(state->infoWindowId, FONT_NARROW, regionMap->mapSecName, 0, 1, TEXT_SKIP_DRAW, NULL);
        FillBgTilemapBufferRect(1, 0x1041, 17, 6, 12, 11, 17);
        CopyWindowToVram(state->infoWindowId, COPYWIN_FULL);
        SetCityZoomTextInvisibility(TRUE);
        break;
    case MAPSECTYPE_ROUTE:
    case MAPSECTYPE_BATTLE_FRONTIER:
        FillWindowPixelBuffer(state->infoWindowId, PIXEL_FILL(1));
        PutWindowTilemap(state->infoWindowId);
        AddTextPrinterParameterized(state->infoWindowId, FONT_NARROW, regionMap->mapSecName, 0, 1, TEXT_SKIP_DRAW, NULL);
        PrintLandmarkNames(state, regionMap->mapSecId, regionMap->posWithinMapSec);
        CopyWindowToVram(state->infoWindowId, COPYWIN_FULL);
        SetCityZoomTextInvisibility(TRUE);
        break;
    case MAPSECTYPE_NONE:
        FillBgTilemapBufferRect(1, 0x1041, 17, 4, 12, 13, 17);
        CopyBgTilemapBufferToVram(1);
        SetCityZoomTextInvisibility(TRUE);
        break;
    }
}

static bool32 IsDma3ManagerBusyWithBgCopy_(struct Pokenav_RegionMapGfx *state)
{
    return IsDma3ManagerBusyWithBgCopy();
}

#define tZoomIn data[0]

static void ChangeBgYForZoom(bool32 zoomIn)
{
    u8 taskId = CreateTask(Task_ChangeBgYForZoom, 3);
    gTasks[taskId].tZoomIn = zoomIn;
}

static bool32 IsChangeBgYForZoomActive(void)
{
    return FuncIsActiveTask(Task_ChangeBgYForZoom);
}

static void Task_ChangeBgYForZoom(u8 taskId)
{
    if (gTasks[taskId].tZoomIn)
    {
        if (ChangeBgY(1, 0x480, BG_COORD_ADD) >= 0)
        {
            ChangeBgY(1, 0, BG_COORD_SET);
            DestroyTask(taskId);
        }

        UpdateCityZoomTextPosition();
    }
    else
    {
        if (ChangeBgY(1, 0x480, BG_COORD_SUB) <= -0x6000)
        {
            ChangeBgY(1, -0x6000, BG_COORD_SET);
            DestroyTask(taskId);
        }

        UpdateCityZoomTextPosition();
    }
}

#undef tZoomIn

static void DecompressCityMaps(void)
{
    CreateLoopedTask(LoopedTask_DecompressCityMaps, 1);
}

static bool32 IsDecompressCityMapsActive(void)
{
    return FuncIsActiveLoopedTask(LoopedTask_DecompressCityMaps);
}

static u32 LoopedTask_DecompressCityMaps(s32 taskState)
{
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    if (taskState < NUM_CITY_MAPS)
    {
        LZ77UnCompWram(sPokenavCityMaps[taskState].tilemap, state->cityZoomPics[taskState]);
        return LT_INC_AND_CONTINUE;
    }

    return LT_FINISH;
}

static void DrawCityMap(struct Pokenav_RegionMapGfx *state, int mapSecId, int pos)
{
    int i;
    for (i = 0; i < NUM_CITY_MAPS && (sPokenavCityMaps[i].mapSecId != mapSecId || sPokenavCityMaps[i].index != pos); i++)
        ;

    if (i == NUM_CITY_MAPS)
        return;

    FillBgTilemapBufferRect_Palette0(1, 0x1041, 17, 6, 12, 11);
    CopyToBgTilemapBufferRect(1, state->cityZoomPics[i], 18, 6, 10, 10);
}

static void PrintLandmarkNames(struct Pokenav_RegionMapGfx *state, int mapSecId, int pos)
{
    int i = 0;
    while (1)
    {
        const u8 *landmarkName = GetLandmarkName(mapSecId, pos, i);
        if (!landmarkName)
            break;

        StringCopyPadded(gStringVar1, landmarkName, CHAR_SPACE, 12);
        AddTextPrinterParameterized(state->infoWindowId, FONT_NARROW, gStringVar1, 0, i * 16 + 17, TEXT_SKIP_DRAW, NULL);
        i++;
    }
}

static void CreateCityZoomTextSprites(void)
{
    int i;
    int y;
    struct Sprite *sprite;
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);

    // When not zoomed in the text is still created but its pushed off screen
    if (!IsRegionMapZoomed())
        y = 228;
    else
        y = 132;

    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
    {
        u8 spriteId = CreateSprite(&sCityZoomTextSpriteTemplate, 152 + i * 32, y, 8);
        sprite = &gSprites[spriteId];
        sprite->data[0] = 0;
        sprite->data[1] = i * 4;
        sprite->data[2] = sprite->oam.tileNum;
        sprite->data[3] = 150;
        sprite->data[4] = i * 4;
        sprite->oam.tileNum += i * 4;
        state->cityZoomTextSprites[i] = sprite;
    }
}

// Slide and cycle through the text key showing what the features on the zoomed city map are
static void SpriteCB_CityZoomText(struct Sprite *sprite)
{
    if (sprite->data[3])
    {
        sprite->data[3]--;
        return;
    }

    if (++sprite->data[0] > 11)
        sprite->data[0] = 0;

    if (++sprite->data[1] > 60)
        sprite->data[1] = 0;

    sprite->oam.tileNum = sprite->data[2] + sprite->data[1];
    if (sprite->data[5] < 4)
    {
        if (sprite->data[0] == 0)
        {
            sprite->data[5]++;
            sprite->data[3] = 120;
        }
    }
    else
    {
        if (sprite->data[1] == sprite->data[4])
        {
            sprite->data[5] = 0;
            sprite->data[0] = 0;
            sprite->data[3] = 120;
        }
    }
}

static void UpdateCityZoomTextPosition(void)
{
    int i;
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    int y = 132 - (GetBgY(1) >> 8);
    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
        state->cityZoomTextSprites[i]->y = y;
}

static void SetCityZoomTextInvisibility(bool32 invisible)
{
    int i;
    struct Pokenav_RegionMapGfx *state = GetSubstructPtr(POKENAV_SUBSTRUCT_REGION_MAP_ZOOM);
    for (i = 0; i < (int)ARRAY_COUNT(state->cityZoomTextSprites); i++)
        state->cityZoomTextSprites[i]->invisible = invisible;
}
