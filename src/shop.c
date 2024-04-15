#include "global.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "decoration.h"
#include "decoration_inventory.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "list_menu.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "money.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "text_window.h"
#include "tv.h"
#include "grid_menu.h"
#include "event_data.h"
#include "constants/decorations.h"
#include "constants/items.h"
#include "constants/metatile_behaviors.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/event_objects.h"

#define TAG_SCROLL_ARROW   2100
#define TAG_ITEM_ICON_BASE 2110
#define GFXTAG_CURSOR 0x2000
#define PALTAG_CURSOR 0x2100

#define GFXTAG_ITEM 0x2200
#define PALTAG_ITEM 0x2300

#define CURSOR_START_X 100 + 32
#define CURSOR_START_Y 4 + 32

#define MAX_ITEMS_SHOWN sShopData->gridItems->numItems

enum {
    WIN_BUY_SELL_QUIT,
    WIN_BUY_QUIT,
};

enum {
    WIN_MONEY,
    WIN_MULTI,
    WIN_ITEM_DESCRIPTION,
    WIN_QUANTITY_PRICE,
    WIN_MUGSHOT,
};

enum {
    COLORID_NORMAL,      // Item descriptions, quantity in bag, and quantity/price
    COLORID_BLACK,       // The text in the item list, and the cursor normally
    COLORID_GRAY_CURSOR, // When the cursor has selected an item to purchase
};

enum {
    MART_TYPE_NORMAL,
    MART_TYPE_DECOR,
    MART_TYPE_DECOR2,
};

// mugshot id
enum
{
    SELLER_NONE = 0,
    SELLER_TANNER, // OBJ_EVENT_GFX_MART_EMPLOYEE
    SELLER_TEALA, // OBJ_EVENT_GFX_TEALA
    SELLER_PURPLINA, // OBJ_EVENT_GFX_PURPLINA
    SELLER_KODOUGH, // OBJ_EVENT_GFX_WINGULL
    SELLER_COUNT,
};

struct MartInfo
{
    void (*callback)(void);
    const struct MenuAction *menuActions;
    const u16 *itemList;
    u16 itemCount;
    u8 windowId;
    u8 martType;
};

struct ShopData
{
    u16 tilemapBuffers[4][0x400];
    u32 totalCost;
    u16 itemsShowed;
    u16 selectedRow;
    u16 scrollOffset;
    u8 maxQuantity;
    u8 scrollIndicatorsTaskId;
    u8 iconSlot;
    u8 itemSpriteIds[2];
    u8 gfxLoadState;
    u8 cursorSpriteId;
    u16 currentItemId;
    u16 sellerId;
    struct GridMenu *gridItems;
};

struct Seller
{
    // Add more id "param" on the union here
    union {
        u16 gfxId;
    } id;
    const u8 *gfx;
    const u16 *pal;
    // main bg
    const u32 *gfxBg;
    const u32 *palBg;
    const u32 *mapBg;
    // scrolling bg
    const u32 *gfxSBg;
    const u32 *mapSBg;
    // cursor sprite
    const u16 *cursorGfx;
    const u32 *cursorPal; // compressed
};

static EWRAM_DATA struct MartInfo sMartInfo = {0};
static EWRAM_DATA struct ShopData *sShopData = NULL;
static EWRAM_DATA struct ListMenuItem *sListMenuItems = NULL;
static EWRAM_DATA u8 (*sItemNames)[ITEM_NAME_LENGTH + 2] = {0};
static EWRAM_DATA u8 sPurchaseHistoryId = 0;
EWRAM_DATA struct ItemSlot gMartPurchaseHistory[SMARTSHOPPER_NUM_ITEMS] = {0};

static void Task_ShopMenu(u8 taskId);
static void Task_HandleShopMenuQuit(u8 taskId);
static void CB2_InitBuyMenu(void);
static void Task_GoToBuyOrSellMenu(u8 taskId);
static void MapPostLoadHook_ReturnToShopMenu(void);
static void Task_ReturnToShopMenu(u8 taskId);
static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId);
static void BuyMenuDrawGraphics(void);
static void BuyMenuAddScrollIndicatorArrows(void);
static void Task_BuyMenu(u8 taskId);
static void BuyMenuBuildListMenuTemplate(void);
static void BuyMenuInitBgs(void);
static void BuyMenuInitWindows(void);
static void BuyMenuInitGrid(void);
static bool8 BuyMenuInitSprites(void);
static void BuyMenuDecompressBgGraphics(void);
static void BuyMenuSetListEntry(struct ListMenuItem *, u16, u8 *);
static void BuyMenuAddItemIcon(u16, u8);
static void BuyMenuRemoveItemIcon(u16, u8);
static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet, bool32 copy);
static void Task_ExitBuyMenu(u8 taskId);
static void BuyMenuTryMakePurchase(u8 taskId);
static void BuyMenuReturnToItemList(u8 taskId);
static void Task_BuyHowManyDialogueInit(u8 taskId);
static void BuyMenuConfirmPurchase(u8 taskId);
static void BuyMenuPrintItemQuantityAndPrice(u8 taskId);
static void Task_BuyHowManyDialogueHandleInput(u8 taskId);
static void BuyMenuSubtractMoney(u8 taskId);
static void RecordItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterItemPurchase(u8 taskId);
static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId);
static void Task_HandleShopMenuBuy(u8 taskId);
static void Task_HandleShopMenuSell(u8 taskId);
static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list);
static void BuyMenuPrintPriceInList(u8 windowId, u32 itemId, u8 y);
static void PrintMoneyLocal(u8 windowId, u8 y, u32 amount, u8 width, u8 colorIdx, bool32 copy);
static void UpdateItemData(void);

static const u8 sGridPosX[] = { (120 + 16), (160 + 16), (200 + 16) };
static const u8 sGridPosY[] = { (24 + 16), (64 + 16) };

static const u16 sShopInventory_ZeroBadges[] = {
    ITEM_POKE_BALL,
    ITEM_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_REVIVE,
    ITEM_NONE
};

static const u16 sShopInventory_OneBadge[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_REVIVE,
    ITEM_NONE
};

static const u16 sShopInventory_TwoBadges[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_REVIVE,
    ITEM_POKE_DOLL,
    ITEM_NONE
};

static const u16 sShopInventory_ThreeBadges[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_REVIVE,
    ITEM_REPEL,
    ITEM_POKE_DOLL,
    ITEM_NONE
};

static const u16 sShopInventory_FourBadges[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_HYPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_REVIVE,
    ITEM_REPEL,
    ITEM_POKE_DOLL,
    ITEM_NONE
};

static const u16 sShopInventory_FiveBadges[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_HYPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_REVIVE,
    ITEM_REPEL,
    ITEM_SUPER_REPEL,
    ITEM_POKE_DOLL,
    ITEM_NONE
};

static const u16 sShopInventory_SixBadges[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_HYPER_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_FULL_HEAL,
    ITEM_REVIVE,
    ITEM_REPEL,
    ITEM_SUPER_REPEL,
    ITEM_POKE_DOLL,
    ITEM_NONE
};

static const u16 sShopInventory_SevenBadges[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_HYPER_POTION,
    ITEM_MAX_POTION,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_FULL_HEAL,
    ITEM_REVIVE,
    ITEM_REPEL,
    ITEM_SUPER_REPEL,
    ITEM_MAX_REPEL,
    ITEM_POKE_DOLL,
    ITEM_NONE
};

static const u16 sShopInventory_EightBadges[] = {
    ITEM_POKE_BALL,
    ITEM_GREAT_BALL,
    ITEM_ULTRA_BALL,
    ITEM_POTION,
    ITEM_SUPER_POTION,
    ITEM_HYPER_POTION,
    ITEM_MAX_POTION,
    ITEM_FULL_RESTORE,
    ITEM_ANTIDOTE,
    ITEM_BURN_HEAL,
    ITEM_ICE_HEAL,
    ITEM_AWAKENING,
    ITEM_PARALYZE_HEAL,
    ITEM_FULL_HEAL,
    ITEM_REVIVE,
    ITEM_REPEL,
    ITEM_SUPER_REPEL,
    ITEM_MAX_REPEL,
    ITEM_POKE_DOLL,
    ITEM_NONE
};

static const u16 *const sShopInventories[] = 
{
    sShopInventory_ZeroBadges, 
    sShopInventory_OneBadge,
    sShopInventory_TwoBadges,
    sShopInventory_ThreeBadges,
    sShopInventory_FourBadges,
    sShopInventory_FiveBadges,
    sShopInventory_SixBadges,
    sShopInventory_SevenBadges,
    sShopInventory_EightBadges
};

static const struct YesNoFuncTable sShopPurchaseYesNoFuncs =
{
    BuyMenuTryMakePurchase,
    BuyMenuReturnToItemList
};

static const struct MenuAction sShopMenuActions_BuySellQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopSell, {.void_u8=Task_HandleShopMenuSell} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct MenuAction sShopMenuActions_BuyQuit[] =
{
    { gText_ShopBuy, {.void_u8=Task_HandleShopMenuBuy} },
    { gText_ShopQuit, {.void_u8=Task_HandleShopMenuQuit} }
};

static const struct WindowTemplate sShopMenuWindowTemplates[] =
{
    [WIN_BUY_SELL_QUIT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    },
    // Separate shop menu window for decorations, which can't be sold
    [WIN_BUY_QUIT] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 9,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x0008,
    }
};

static const struct ListMenuTemplate sShopBuyMenuListTemplate =
{
    .items = NULL,
    .moveCursorFunc = BuyMenuPrintItemDescriptionAndShowItemIcon,
    .itemPrintFunc = BuyMenuPrintPriceInList,
    .totalItems = 0,
    .maxShowed = 0,
    // .windowId = WIN_ITEM_LIST,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 1,
    .fillValue = 0,
    .cursorShadowPal = 2,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NARROW,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct BgTemplate sShopBuyMenuBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct WindowTemplate sShopBuyMenuWindowTemplates[] =
{
    [WIN_MONEY] = {
        .bg = 0,
        .tilemapLeft = 19,
        .tilemapTop = 0,
        .width = 10,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 0x001E,
    },
    [WIN_MULTI] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 10,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0032,
    },
    [WIN_ITEM_DESCRIPTION] = {
        .bg = 0,
        .tilemapLeft = 11,
        .tilemapTop = 13,
        .width = 14,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x0122,
    },
    [WIN_QUANTITY_PRICE] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 14,
        .width = 8,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 0x018E,
    },
    [WIN_MUGSHOT] = {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = 13,
        .height = 12,
        .paletteNum = 1,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sShopBuyMenuYesNoWindowTemplates =
{
    .bg = 0,
    .tilemapLeft = 24,
    .tilemapTop = 14,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x020E,
};

static const u8 sShopBuyMenuTextColors[][3] =
{
    [COLORID_NORMAL]      = {0, 1, 2},
    [COLORID_BLACK]       = {0, 2, 3},
    [COLORID_GRAY_CURSOR] = {0, 1, 2},
};

// default gfx
const u32 sShopMenu_DefaultGfx[] = INCBIN_U32("graphics/shop/menu.4bpp.lz");
const u32 sShopMenu_DefaultTilemap[] = INCBIN_U32("graphics/shop/menu.bin.lz");
const u32 sShopMenu_DefaultPal[] = INCBIN_U32("graphics/shop/menu.gbapal.lz");
const u32 sShopMenu_DefaultScrollGfx[] = INCBIN_U32("graphics/shop/scroll.4bpp.lz");
const u32 sShopMenu_DefaultScrollTilemap[] = INCBIN_U32("graphics/shop/scroll.bin.lz");
const u16 sShopMenu_DefaultCursorGfx[] = INCBIN_U16("graphics/shop/cursor.4bpp");

const u8 sShopMenuSellerGfx_Tanner[] = INCBIN_U8("graphics/shop/sellers/tanner/mugshot.4bpp");
const u16 sShopMenuSellerPal_Tanner[] = INCBIN_U16("graphics/shop/sellers/tanner/mugshot.gbapal");
const u32 sShopMenuSellerGfxBg_Tanner[] = INCBIN_U32("graphics/shop/sellers/tanner/menu.4bpp.lz");
const u32 sShopMenuSellerMapBg_Tanner[] = INCBIN_U32("graphics/shop/sellers/tanner/menu.bin.lz");
const u32 sShopMenuSellerPalBg_Tanner[] = INCBIN_U32("graphics/shop/sellers/tanner/menu.gbapal.lz");
const u32 sShopMenuSellerGfxSBg_Tanner[] = INCBIN_U32("graphics/shop/sellers/tanner/scroll.4bpp.lz");
const u32 sShopMenuSellerMapSBg_Tanner[] = INCBIN_U32("graphics/shop/sellers/tanner/scroll.bin.lz");
const u16 sShopMenuSellerCursorGfx_Tanner[] = INCBIN_U16("graphics/shop/sellers/tanner/cursor.4bpp");
const u32 sShopMenuSellerCursorPal_Tanner[] = INCBIN_U32("graphics/shop/sellers/tanner/cursor.gbapal.lz");

const u8 sShopMenuSellerGfx_Teala[] = INCBIN_U8("graphics/shop/sellers/teala/mugshot.4bpp");
const u16 sShopMenuSellerPal_Teala[] = INCBIN_U16("graphics/shop/sellers/teala/mugshot.gbapal");
const u32 sShopMenuSellerGfxBg_Teala[] = INCBIN_U32("graphics/shop/sellers/teala/menu.4bpp.lz");
const u32 sShopMenuSellerMapBg_Teala[] = INCBIN_U32("graphics/shop/sellers/teala/menu.bin.lz");
const u32 sShopMenuSellerPalBg_Teala[] = INCBIN_U32("graphics/shop/sellers/teala/menu.gbapal.lz");
const u32 sShopMenuSellerGfxSBg_Teala[] = INCBIN_U32("graphics/shop/sellers/teala/scroll.4bpp.lz");
const u32 sShopMenuSellerMapSBg_Teala[] = INCBIN_U32("graphics/shop/sellers/teala/scroll.bin.lz");
const u16 sShopMenuSellerCursorGfx_Teala[] = INCBIN_U16("graphics/shop/sellers/teala/cursor.4bpp");
const u32 sShopMenuSellerCursorPal_Teala[] = INCBIN_U32("graphics/shop/sellers/teala/cursor.gbapal.lz");

const u8 sShopMenuSellerGfx_Purplina[] = INCBIN_U8("graphics/shop/sellers/purplina/mugshot.4bpp");
const u16 sShopMenuSellerPal_Purplina[] = INCBIN_U16("graphics/shop/sellers/purplina/mugshot.gbapal");
const u32 sShopMenuSellerGfxBg_Purplina[] = INCBIN_U32("graphics/shop/sellers/purplina/menu.4bpp.lz");
const u32 sShopMenuSellerMapBg_Purplina[] = INCBIN_U32("graphics/shop/sellers/purplina/menu.bin.lz");
const u32 sShopMenuSellerPalBg_Purplina[] = INCBIN_U32("graphics/shop/sellers/purplina/menu.gbapal.lz");
const u32 sShopMenuSellerGfxSBg_Purplina[] = INCBIN_U32("graphics/shop/sellers/purplina/scroll.4bpp.lz");
const u32 sShopMenuSellerMapSBg_Purplina[] = INCBIN_U32("graphics/shop/sellers/purplina/scroll.bin.lz");
const u16 sShopMenuSellerCursorGfx_Purplina[] = INCBIN_U16("graphics/shop/sellers/purplina/cursor.4bpp");
const u32 sShopMenuSellerCursorPal_Purplina[] = INCBIN_U32("graphics/shop/sellers/purplina/cursor.gbapal.lz");

const u8 sShopMenuSellerGfx_Kodough[] = INCBIN_U8("graphics/shop/sellers/kodough/mugshot.4bpp");
const u16 sShopMenuSellerPal_Kodough[] = INCBIN_U16("graphics/shop/sellers/kodough/mugshot.gbapal");
const u32 sShopMenuSellerGfxBg_Kodough[] = INCBIN_U32("graphics/shop/sellers/kodough/menu.4bpp.lz");
const u32 sShopMenuSellerMapBg_Kodough[] = INCBIN_U32("graphics/shop/sellers/kodough/menu.bin.lz");
const u32 sShopMenuSellerPalBg_Kodough[] = INCBIN_U32("graphics/shop/sellers/kodough/menu.gbapal.lz");
const u32 sShopMenuSellerGfxSBg_Kodough[] = INCBIN_U32("graphics/shop/sellers/kodough/scroll.4bpp.lz");
const u32 sShopMenuSellerMapSBg_Kodough[] = INCBIN_U32("graphics/shop/sellers/kodough/scroll.bin.lz");
const u16 sShopMenuSellerCursorGfx_Kodough[] = INCBIN_U16("graphics/shop/sellers/kodough/cursor.4bpp");
const u32 sShopMenuSellerCursorPal_Kodough[] = INCBIN_U32("graphics/shop/sellers/kodough/cursor.gbapal.lz");

static const struct SpriteSheet sDefaultCursor_SpriteSheet = {
    .data = sShopMenu_DefaultCursorGfx,
    .size = 64*64*2,
    .tag = GFXTAG_CURSOR,
};

static const struct CompressedSpritePalette sDefaultCursor_SpritePalette = {
    .data = sShopMenu_DefaultPal,
    .tag = PALTAG_CURSOR,
};

static const union AnimCmd sCursorAnim[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(64, 30),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sCursorAnims[] = { sCursorAnim };

static const struct OamData sCursor_SpriteOamData = {
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1,
};

static const struct SpriteTemplate sCursor_SpriteTemplate = {
    .tileTag = GFXTAG_CURSOR,
    .paletteTag = PALTAG_CURSOR,
    .callback = SpriteCallbackDummy,
    .anims = sCursorAnims,
    .affineAnims = gDummySpriteAffineAnimTable,
    .images = NULL,
    .oam = &sCursor_SpriteOamData,
};

static const struct Seller sSellers[SELLER_COUNT] = {
    [SELLER_TANNER] = {
        {.gfxId=OBJ_EVENT_GFX_MART_EMPLOYEE},
        .gfx = sShopMenuSellerGfx_Tanner,
        .pal = sShopMenuSellerPal_Tanner,
        .gfxBg = sShopMenuSellerGfxBg_Tanner,
        .mapBg = sShopMenuSellerMapBg_Tanner,
        .palBg = sShopMenuSellerPalBg_Tanner,
        .gfxSBg = sShopMenuSellerGfxSBg_Tanner,
        .mapSBg = sShopMenuSellerMapSBg_Tanner,
        .cursorGfx = sShopMenuSellerCursorGfx_Tanner,
        .cursorPal = sShopMenuSellerCursorPal_Tanner,
    },
    [SELLER_TEALA] = {
        {.gfxId=OBJ_EVENT_GFX_TEALA},
        .gfx=sShopMenuSellerGfx_Teala,
        .pal=sShopMenuSellerPal_Teala,
        .gfxBg = sShopMenuSellerGfxBg_Teala,
        .mapBg = sShopMenuSellerMapBg_Teala,
        .palBg = sShopMenuSellerPalBg_Teala,
        .gfxSBg = sShopMenuSellerGfxSBg_Teala,
        .mapSBg = sShopMenuSellerMapSBg_Teala,
        .cursorGfx = sShopMenuSellerCursorGfx_Teala,
        .cursorPal = sShopMenuSellerCursorPal_Teala,
    },
    [SELLER_PURPLINA] = {
        {.gfxId=OBJ_EVENT_GFX_PURPLINA},
        .gfx=sShopMenuSellerGfx_Purplina,
        .pal=sShopMenuSellerPal_Purplina,
        .gfxBg = sShopMenuSellerGfxBg_Purplina,
        .mapBg = sShopMenuSellerMapBg_Purplina,
        .palBg = sShopMenuSellerPalBg_Purplina,
        .gfxSBg = sShopMenuSellerGfxSBg_Purplina,
        .mapSBg = sShopMenuSellerMapSBg_Purplina,
        .cursorGfx = sShopMenuSellerCursorGfx_Purplina,
        .cursorPal = sShopMenuSellerCursorPal_Purplina,

    },
    [SELLER_KODOUGH] = {
        {.gfxId=OBJ_EVENT_GFX_WINGULL},
        .gfx=sShopMenuSellerGfx_Kodough,
        .pal=sShopMenuSellerPal_Kodough,
        .gfxBg = sShopMenuSellerGfxBg_Kodough,
        .mapBg = sShopMenuSellerMapBg_Kodough,
        .palBg = sShopMenuSellerPalBg_Kodough,
        .gfxSBg = sShopMenuSellerGfxSBg_Kodough,
        .mapSBg = sShopMenuSellerMapSBg_Kodough,
        .cursorGfx = sShopMenuSellerCursorGfx_Kodough,
        .cursorPal = sShopMenuSellerCursorPal_Kodough,
    },
};

static u8 CreateShopMenu(u8 martType)
{
    int numMenuItems;

    LockPlayerFieldControls();
    DebugPrintf("lastTalked: %d", gSpecialVar_LastTalked);
    sMartInfo.martType = martType;

    if (martType == MART_TYPE_NORMAL)
    {
        struct WindowTemplate winTemplate = sShopMenuWindowTemplates[WIN_BUY_SELL_QUIT];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuySellQuit, ARRAY_COUNT(sShopMenuActions_BuySellQuit));
        sMartInfo.windowId = AddWindow(&winTemplate);
        sMartInfo.menuActions = sShopMenuActions_BuySellQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuySellQuit);
    }
    else
    {
        struct WindowTemplate winTemplate = sShopMenuWindowTemplates[WIN_BUY_QUIT];
        winTemplate.width = GetMaxWidthInMenuTable(sShopMenuActions_BuyQuit, ARRAY_COUNT(sShopMenuActions_BuyQuit));
        sMartInfo.windowId = AddWindow(&winTemplate);
        sMartInfo.menuActions = sShopMenuActions_BuyQuit;
        numMenuItems = ARRAY_COUNT(sShopMenuActions_BuyQuit);
    }

    SetStandardWindowBorderStyle(sMartInfo.windowId, FALSE);
    PrintMenuTable(sMartInfo.windowId, numMenuItems, sMartInfo.menuActions);
    InitMenuInUpperLeftCornerNormal(sMartInfo.windowId, numMenuItems, 0);
    PutWindowTilemap(sMartInfo.windowId);
    CopyWindowToVram(sMartInfo.windowId, COPYWIN_MAP);

    return CreateTask(Task_ShopMenu, 8);
}

static void SetShopMenuCallback(void (* callback)(void))
{
    sMartInfo.callback = callback;
}

static u8 GetNumberOfBadges(void)
{
    u16 badgeFlag;
    u8 count = 0;
    
    for (badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++)
    {
        if (FlagGet(badgeFlag))
            count++;
    }
    
    return count;
}

static void SetShopItemsForSale(const u16 *items)
{
    u16 i = 0;
    u8 badgeCount = GetNumberOfBadges();

    if (items == NULL)
        sMartInfo.itemList = sShopInventories[badgeCount];
    else
        sMartInfo.itemList = items;

    sMartInfo.itemCount = 0;
    while (sMartInfo.itemList[i])
    {
        sMartInfo.itemCount++;
        i++;
    }
    sMartInfo.itemCount++; // for ITEM_NONE / DECOR_NONE
}

static void Task_ShopMenu(u8 taskId)
{
    s8 inputCode = Menu_ProcessInputNoWrap();
    switch (inputCode)
    {
    case MENU_NOTHING_CHOSEN:
        break;
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        Task_HandleShopMenuQuit(taskId);
        break;
    default:
        sMartInfo.menuActions[inputCode].func.void_u8(taskId);
        break;
    }
}

#define tItemCount  data[1]
#define tListTaskId data[7]
#define tCallbackHi data[8]
#define tCallbackLo data[9]

static void Task_HandleShopMenuBuy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tCallbackHi = (u32)CB2_InitBuyMenu >> 16;
    tCallbackLo = (u32)CB2_InitBuyMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

static void Task_HandleShopMenuSell(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tCallbackHi = (u32)CB2_GoToSellMenu >> 16;
    tCallbackLo = (u32)CB2_GoToSellMenu;
    gTasks[taskId].func = Task_GoToBuyOrSellMenu;
    FadeScreen(FADE_TO_BLACK, 0);
}

void CB2_ExitSellMenu(void)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    SetMainCallback2(CB2_ReturnToField);
}

static void Task_HandleShopMenuQuit(u8 taskId)
{
    ClearStdWindowAndFrameToTransparent(sMartInfo.windowId, COPYWIN_FULL);
    RemoveWindow(sMartInfo.windowId);
    TryPutSmartShopperOnAir();
    UnlockPlayerFieldControls();
    DestroyTask(taskId);

    if (sMartInfo.callback)
        sMartInfo.callback();
}

static void Task_GoToBuyOrSellMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        SetMainCallback2((void *)((u16)tCallbackHi << 16 | (u16)tCallbackLo));
    }
}

static void MapPostLoadHook_ReturnToShopMenu(void)
{
    FadeInFromBlack();
    CreateTask(Task_ReturnToShopMenu, 8);
}

static void Task_ReturnToShopMenu(u8 taskId)
{
    if (IsWeatherNotFadingIn() == TRUE)
    {
        if (sMartInfo.martType == MART_TYPE_DECOR2)
            DisplayItemMessageOnField(taskId, gText_CanIHelpWithAnythingElse, ShowShopMenuAfterExitingBuyOrSellMenu);
        else
            DisplayItemMessageOnField(taskId, gText_AnythingElseICanHelp, ShowShopMenuAfterExitingBuyOrSellMenu);
    }
}

static void ShowShopMenuAfterExitingBuyOrSellMenu(u8 taskId)
{
    CreateShopMenu(sMartInfo.martType);
    DestroyTask(taskId);
}

static void CB2_BuyMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void VBlankCB_BuyMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ChangeBgX(3, 96, BG_COORD_SUB);
}

static void Task_BuyMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_BuyMenu;
}

static void CB2_InitBuyMenu(void)
{
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
        ResetVramOamAndBgCntRegs();
        SetVBlankHBlankCallbacksToNull();
        CpuFastFill(0, (void *)OAM, OAM_SIZE);
        ScanlineEffect_Stop();
        ResetTempTileDataBuffers();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        ClearScheduledBgCopiesToVram();
        sShopData = AllocZeroed(sizeof(struct ShopData));
        sShopData->scrollIndicatorsTaskId = TASK_NONE;
        // BuyMenuBuildListMenuTemplate();
        BuyMenuInitBgs();
        BuyMenuInitGrid();
        BuyMenuInitWindows();
        BuyMenuDecompressBgGraphics();
        gMain.state++;
        break;
    case 1:
        if (BuyMenuInitSprites())
            gMain.state++;
        break;
    case 2:
        if (!FreeTempTileDataBuffersIfPossible())
            gMain.state++;
        break;
    default:
        BuyMenuDrawGraphics();
        CreateTask(Task_BuyMenuWaitFadeIn, 8);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB_BuyMenu);
        SetMainCallback2(CB2_BuyMenu);
        break;
    }
}

static void BuyMenuFreeMemory(void)
{
    GridMenu_Destroy(sShopData->gridItems);
    Free(sShopData);
    // Free(sListMenuItems);
    Free(sItemNames);
    FreeAllWindowBuffers();
}

UNUSED static void BuyMenuBuildListMenuTemplate(void)
{
    u16 i;

    sListMenuItems = Alloc((sMartInfo.itemCount + 1) * sizeof(*sListMenuItems));
    sItemNames = Alloc((sMartInfo.itemCount + 1) * sizeof(*sItemNames));
    for (i = 0; i < sMartInfo.itemCount; i++)
        BuyMenuSetListEntry(&sListMenuItems[i], sMartInfo.itemList[i], sItemNames[i]);

    StringCopy(sItemNames[i], gText_Cancel2);
    sListMenuItems[i].name = sItemNames[i];
    sListMenuItems[i].id = LIST_CANCEL;

    gMultiuseListMenuTemplate = sShopBuyMenuListTemplate;
    gMultiuseListMenuTemplate.items = sListMenuItems;
    gMultiuseListMenuTemplate.totalItems = sMartInfo.itemCount + 1;
    if (gMultiuseListMenuTemplate.totalItems > MAX_ITEMS_SHOWN)
        gMultiuseListMenuTemplate.maxShowed = MAX_ITEMS_SHOWN;
    else
        gMultiuseListMenuTemplate.maxShowed = gMultiuseListMenuTemplate.totalItems;

    sShopData->itemsShowed = gMultiuseListMenuTemplate.maxShowed;
}

static void BuyMenuSetListEntry(struct ListMenuItem *menuItem, u16 item, u8 *name)
{
    if (sMartInfo.martType == MART_TYPE_NORMAL)
        CopyItemName(item, name);
    else
        StringCopy(name, gDecorations[item].name);

    menuItem->name = name;
    menuItem->id = item;
}

static void BuyMenuPrintItemDescriptionAndShowItemIcon(s32 item, bool8 onInit, struct ListMenu *list)
{
    const u8 *description;
    if (onInit != TRUE)
        PlaySE(SE_SELECT);

    sShopData->iconSlot ^= 1;
    if (item != LIST_CANCEL)
    {
        if (sMartInfo.martType == MART_TYPE_NORMAL)
            description = ItemId_GetDescription(item);
        else
            description = gDecorations[item].description;
    }
    else
    {
        description = gText_QuitShopping;
    }

    FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
    BuyMenuPrint(WIN_ITEM_DESCRIPTION, description, 0, 4, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
}

static void BuyMenuPrintPriceInList(u8 windowId, u32 itemId, u8 y)
{
    u8 x;

    if (itemId != LIST_CANCEL)
    {
        if (sMartInfo.martType == MART_TYPE_NORMAL)
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                ItemId_GetPrice(itemId) >> IsPokeNewsActive(POKENEWS_SLATEPORT),
                STR_CONV_MODE_LEFT_ALIGN,
                5);
        }
        else
        {
            ConvertIntToDecimalStringN(
                gStringVar1,
                gDecorations[itemId].price,
                STR_CONV_MODE_LEFT_ALIGN,
                5);
        }

        if (ItemId_GetImportance(itemId) && (CheckBagHasItem(itemId, 1) || CheckPCHasItem(itemId, 1)))
            StringCopy(gStringVar4, gText_SoldOut);
        else
            StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        x = GetStringRightAlignXOffset(FONT_NARROW, gStringVar4, 120);
        AddTextPrinterParameterized4(windowId, FONT_NARROW, x, y, 0, 0, sShopBuyMenuTextColors[COLORID_BLACK], TEXT_SKIP_DRAW, gStringVar4);
    }
}

UNUSED static void BuyMenuAddScrollIndicatorArrows(void)
{
    if (sShopData->scrollIndicatorsTaskId == TASK_NONE && sMartInfo.itemCount + 1 > MAX_ITEMS_SHOWN)
    {
        sShopData->scrollIndicatorsTaskId = AddScrollIndicatorArrowPairParameterized(
            SCROLL_ARROW_UP,
            172,
            12,
            148,
            sMartInfo.itemCount - (MAX_ITEMS_SHOWN - 1),
            TAG_SCROLL_ARROW,
            TAG_SCROLL_ARROW,
            &sShopData->scrollOffset);
    }
}

UNUSED static void BuyMenuRemoveScrollIndicatorArrows(void)
{
    if (sShopData->scrollIndicatorsTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sShopData->scrollIndicatorsTaskId);
        sShopData->scrollIndicatorsTaskId = TASK_NONE;
    }
}

UNUSED static void BuyMenuAddItemIcon(u16 item, u8 iconSlot)
{
    u8 spriteId;
    u8 *spriteIdPtr = &sShopData->itemSpriteIds[iconSlot];
    if (*spriteIdPtr != SPRITE_NONE)
        return;

    if (sMartInfo.martType == MART_TYPE_NORMAL || item == ITEM_LIST_END)
    {
        spriteId = AddItemIconSprite(iconSlot + TAG_ITEM_ICON_BASE, iconSlot + TAG_ITEM_ICON_BASE, item);
        if (spriteId != MAX_SPRITES)
        {
            *spriteIdPtr = spriteId;
            gSprites[spriteId].x2 = 24;
            gSprites[spriteId].y2 = 88;
        }
    }
    else
    {
        spriteId = AddDecorationIconObject(item, 20, 84, 1, iconSlot + TAG_ITEM_ICON_BASE, iconSlot + TAG_ITEM_ICON_BASE);
        if (spriteId != MAX_SPRITES)
            *spriteIdPtr = spriteId;
    }
}

static void ForEachCB_PopulateItemIcons(u32 idx, u32 col, u32 row)
{
    u32 i = sShopData->gridItems->topLeftItemIndex + idx;
    if (i >= sMartInfo.itemCount)
        return;

    if (sMartInfo.martType == MART_TYPE_NORMAL)
    {
        if (sMartInfo.itemList[i] == ITEM_NONE)
            sShopData->gridItems->iconSpriteIds[idx] = AddItemIconSprite(GFXTAG_ITEM + idx, PALTAG_ITEM + idx, ITEM_LIST_END);
        else
            sShopData->gridItems->iconSpriteIds[idx] = AddItemIconSprite(GFXTAG_ITEM + idx, PALTAG_ITEM + idx, sMartInfo.itemList[i]);

        gSprites[sShopData->gridItems->iconSpriteIds[idx]].x = ((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0];
        gSprites[sShopData->gridItems->iconSpriteIds[idx]].y = ((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0];
    }
    else
    {
        u32 x, y;

        x = (((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0]) - 4;
        y = (((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0]) - 4;

        if (sMartInfo.itemList[i] == DECOR_NONE) // DECOR_NONE has the same value as ITEM_NONE but this is for clarity
        {
            sShopData->gridItems->iconSpriteIds[idx] = AddItemIconSprite(GFXTAG_ITEM + idx, PALTAG_ITEM + idx, ITEM_LIST_END);
            gSprites[sShopData->gridItems->iconSpriteIds[idx]].x = ((col % 3) < ARRAY_COUNT(sGridPosX)) ? sGridPosX[col] : sGridPosX[0];
            gSprites[sShopData->gridItems->iconSpriteIds[idx]].y = ((row % 2) < ARRAY_COUNT(sGridPosY)) ? sGridPosY[row] : sGridPosY[0];
        }
        else
            sShopData->gridItems->iconSpriteIds[idx] = AddDecorationIconObject(sMartInfo.itemList[i], x, y, 2, GFXTAG_ITEM + idx, PALTAG_ITEM + idx);
    }
}

static void ForAllCB_FreeItemIcons(u32 idx, u32 col, u32 row)
{
    if (sShopData->gridItems->iconSpriteIds[idx] == SPRITE_NONE)
        return;

    if (gSprites[sShopData->gridItems->iconSpriteIds[idx]].inUse)
    {
        FreeSpriteTilesByTag(idx + GFXTAG_ITEM);
        FreeSpritePaletteByTag(idx + PALTAG_ITEM);
        DestroySprite(&gSprites[sShopData->gridItems->iconSpriteIds[idx]]);
    }

    sShopData->gridItems->iconSpriteIds[idx] = SPRITE_NONE;
}

static void InputCB_UpDownScroll(void)
{
    GridMenu_ForAll(sShopData->gridItems, ForAllCB_FreeItemIcons);
    GridMenu_ForEach(sShopData->gridItems, ForEachCB_PopulateItemIcons);
    UpdateItemData();
    if (!IsSEPlaying())
        PlaySE(SE_RG_BAG_CURSOR);
}

static void InputCB_Move(void)
{
    UpdateItemData();
    if (!IsSEPlaying())
        PlaySE(SE_RG_BAG_CURSOR);
}

static void InputCB_Fail(void)
{
    if (!IsSEPlaying())
        PlaySE(SE_BOO);
}

static void BuyMenuInitGrid(void)
{
    sShopData->gridItems = GridMenu_Init(3, 2, sMartInfo.itemCount);
    GridMenu_ForEach(sShopData->gridItems, ForEachCB_PopulateItemIcons);
    // we're doing this so that when the grid menu input function "fails", the item data wont flickers
    // it'll flicker when we call UpdateItemData on the main input task func
    // UPDATE: Not exactly true, it flickers when the printing func always immediately copy to vram
    // for good measure though, i'll keep it.
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_UP, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_DOWN, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_LEFT, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Move, DIRECTION_RIGHT, TYPE_MOVE);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_UP, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_DOWN, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_LEFT, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_Fail, DIRECTION_RIGHT, TYPE_FAIL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_UpDownScroll, DIRECTION_UP, TYPE_SCROLL);
    GridMenu_SetInputCallback(sShopData->gridItems, InputCB_UpDownScroll, DIRECTION_DOWN, TYPE_SCROLL);
}

UNUSED static void BuyMenuRemoveItemIcon(u16 item, u8 iconSlot)
{
    u8 *spriteIdPtr = &sShopData->itemSpriteIds[iconSlot];
    if (*spriteIdPtr == SPRITE_NONE)
        return;

    FreeSpriteTilesByTag(iconSlot + TAG_ITEM_ICON_BASE);
    FreeSpritePaletteByTag(iconSlot + TAG_ITEM_ICON_BASE);
    DestroySprite(&gSprites[*spriteIdPtr]);
    *spriteIdPtr = SPRITE_NONE;
}

static void BuyMenuInitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sShopBuyMenuBgTemplates, ARRAY_COUNT(sShopBuyMenuBgTemplates));
    SetBgTilemapBuffer(2, sShopData->tilemapBuffers[0]);
    SetBgTilemapBuffer(3, sShopData->tilemapBuffers[1]);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
}

static void BuyMenuDecompressBgGraphics(void)
{
    u32 i = sShopData->sellerId;
    // failsafe
    if (gSpecialVar_LastTalked == 0 || i == SELLER_NONE)
    {
        DecompressAndCopyTileDataToVram(2, sShopMenu_DefaultGfx, 0, 9, 0);
        DecompressAndCopyTileDataToVram(2, sShopMenu_DefaultScrollGfx, 0, 0, 0);
        LZDecompressWram(sShopMenu_DefaultTilemap, sShopData->tilemapBuffers[0]);
        LZDecompressWram(sShopMenu_DefaultScrollTilemap, sShopData->tilemapBuffers[1]);
        LoadCompressedPalette(sShopMenu_DefaultPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        return;
    }

    DecompressAndCopyTileDataToVram(2, sSellers[i].gfxBg ? sSellers[i].gfxBg : sShopMenu_DefaultGfx, 0, 9, 0);
    DecompressAndCopyTileDataToVram(2, sSellers[i].gfxSBg ? sSellers[i].gfxSBg : sShopMenu_DefaultScrollGfx, 0, 0, 0);
    LZDecompressWram(sSellers[i].mapBg ? sSellers[i].mapBg : sShopMenu_DefaultTilemap, sShopData->tilemapBuffers[0]);
    LZDecompressWram(sSellers[i].mapSBg ? sSellers[i].mapSBg : sShopMenu_DefaultScrollTilemap, sShopData->tilemapBuffers[1]);
    LoadCompressedPalette(sSellers[i].palBg ? sSellers[i].palBg : sShopMenu_DefaultPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
}

static inline void SpawnWindow(u8 winId)
{
    FillWindowPixelBuffer(winId, 0);
    PutWindowTilemap(winId);
    CopyWindowToVram(winId, COPYWIN_FULL);
}

static inline const u8 *BuyMenuGetItemName(u32 id)
{
    if (sMartInfo.martType == MART_TYPE_NORMAL)
        return ItemId_GetName(sMartInfo.itemList[id]);
    else
        return gDecorations[sMartInfo.itemList[id]].name;
}

static inline const u8 *BuyMenuGetItemDesc(u32 id)
{
    if (sMartInfo.martType == MART_TYPE_NORMAL)
        return ItemId_GetDescription(sMartInfo.itemList[id]);
    else
        return gDecorations[sMartInfo.itemList[id]].description;
}

static inline u32 BuyMenuGetItemPrice(u32 id)
{
    if (sMartInfo.martType == MART_TYPE_NORMAL)
        return ItemId_GetPrice(sMartInfo.itemList[id]);
    else
        return gDecorations[sMartInfo.itemList[id]].price;
}

static void LoadSellerMugshot(const u8 *gfx, const u16 *pal)
{
    CopyToWindowPixelBuffer(WIN_MUGSHOT, gfx, 4992, 0);
    LoadPalette(pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    PutWindowTilemap(WIN_MUGSHOT);
    CopyWindowToVram(WIN_MUGSHOT, COPYWIN_FULL);
}

static void SetupSellerMugshot(void)
{
    u32 i;
    u32 objId = GetObjectEventIdByLocalIdAndMap(gSpecialVar_LastTalked,
                                                    gSaveBlock1Ptr->location.mapNum,
                                                    gSaveBlock1Ptr->location.mapGroup);
    u32 gfxId = gObjectEvents[objId].graphicsId;

    if (gfxId >= OBJ_EVENT_GFX_VAR_0 && gfxId <= OBJ_EVENT_GFX_VAR_F)
    {
        gfxId = VarGetObjectEventGraphicsId(gfxId);
    }

    if (gSpecialVar_LastTalked == 0) // failsafe
    {
        LoadSellerMugshot(sShopMenuSellerGfx_Tanner, sShopMenuSellerPal_Tanner);
        sShopData->sellerId = SELLER_NONE;
        return;
    }

    // loop over all of the mugshots
    for (i = 0; i < SELLER_COUNT; i++)
    {
        if (gfxId == sSellers[i].id.gfxId)
        {
            
            if (sSellers[i].gfx != NULL || sSellers[i].pal != NULL)
            {
                LoadSellerMugshot(sSellers[i].gfx, sSellers[i].pal);
            }
            else
            {
                LoadSellerMugshot(sShopMenuSellerGfx_Tanner, sShopMenuSellerPal_Tanner);
            }
            sShopData->sellerId = i;
            return;
        }
    }
}

static void ReformatItemDescription(u16 item, u8 *dest)
{
    u8 count = 0;
    u8 numLines = 1;
    u8 maxChars = 14;
    u8 *desc = (u8 *)ItemId_GetDescription(sMartInfo.itemList[item]);

    while (*desc != EOS)
    {
        if (count >= maxChars)
        {
            while (*desc != CHAR_SPACE && *desc != CHAR_NEWLINE)
            {
                *dest = *desc;  //finish word
                dest++;
                desc++;
            }

            *dest = CHAR_NEWLINE;
            count = 0;
            numLines++;
            dest++;
            desc++;
            continue;
        }

        *dest = *desc;
        if (*desc == CHAR_NEWLINE)
        {
            *dest = CHAR_SPACE;
        }

        dest++;
        desc++;
        count++;
    }

    // finish string
    *dest = EOS;
}

static void BuyMenuInitWindows(void)
{
    const u8 *name = BuyMenuGetItemName(0), *desc = BuyMenuGetItemDesc(0);
    u32 price = BuyMenuGetItemPrice(0);

    InitWindows(sShopBuyMenuWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(WIN_MONEY, 1, BG_PLTT_ID(13));
    LoadMessageBoxGfx(WIN_MONEY, 0xA, BG_PLTT_ID(14));

    SpawnWindow(WIN_MONEY);
    SpawnWindow(WIN_MUGSHOT);
    SpawnWindow(WIN_ITEM_DESCRIPTION);

    BuyMenuPrint(WIN_MULTI, name, 0, 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    BuyMenuPrint(WIN_MULTI, COMPOUND_STRING("PRICE"), 0, 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    BuyMenuPrint(WIN_MULTI, COMPOUND_STRING("IN BAG"), 0, 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

    if (sMartInfo.martType == MART_TYPE_NORMAL)
    {
        u32 item = sMartInfo.itemList[0];
        u16 quantity = CountTotalItemQuantityInBag(item);
        if (ItemId_GetPocket(item) == POCKET_TM_HM)
        {
            const u8 *move = gMoveNames[ItemIdToBattleMoveId(item)];
            ReformatItemDescription(0, gStringVar2);
            desc = gStringVar2;
            BuyMenuPrint(WIN_MULTI, move, GetStringRightAlignXOffset(FONT_SMALL, move, 80), 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        }

        if (ItemId_GetImportance(item) && (CheckBagHasItem(item, 1) || CheckPCHasItem(item, 1)))
            BuyMenuPrint(WIN_MULTI, gText_SoldOut, GetStringRightAlignXOffset(FONT_SMALL, gText_SoldOut, 80), 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        else
            PrintMoneyLocal(WIN_MULTI, 2*8, price, 65, COLORID_BLACK, FALSE);

        ConvertIntToDecimalStringN(gStringVar3, quantity, STR_CONV_MODE_RIGHT_ALIGN, 4);
        BuyMenuPrint(WIN_MULTI, gStringVar3, GetStringRightAlignXOffset(FONT_SMALL, gStringVar3, 61), 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    }
    else
    {
        PrintMoneyLocal(WIN_MULTI, 2*8, price, 65, COLORID_BLACK, FALSE);
    }
    CopyWindowToVram(WIN_MULTI, COPYWIN_FULL);
    FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
    BuyMenuPrint(WIN_ITEM_DESCRIPTION, desc, 0, 4, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    SetupSellerMugshot();
}

static bool32 LoadSellerCursor(void)
{
    struct SpriteSheet gfx = {
        .data = sSellers[sShopData->sellerId].cursorGfx ? sSellers[sShopData->sellerId].cursorGfx : sShopMenu_DefaultCursorGfx,
        .size = 64*64*2,
        .tag = GFXTAG_CURSOR,
    };
    struct CompressedSpritePalette pal = {
        .data = sSellers[sShopData->sellerId].cursorPal ? sSellers[sShopData->sellerId].cursorPal : sShopMenu_DefaultPal,
        .tag = PALTAG_CURSOR
    };

    if (gSpecialVar_LastTalked == 0 || sShopData->sellerId == 0)
    {
        LoadSpriteSheet(&sDefaultCursor_SpriteSheet);
        LoadCompressedSpritePalette(&sDefaultCursor_SpritePalette);
        return FALSE;
    }
    LoadSpriteSheet(&gfx);
    LoadCompressedSpritePalette(&pal);
    return TRUE;
}

static bool8 BuyMenuInitSprites(void)
{
    switch (sShopData->gfxLoadState)
    {
    case 0:
        LoadSellerCursor();
        sShopData->gfxLoadState++;
        break;
    case 1:
        sShopData->cursorSpriteId = CreateSprite(&sCursor_SpriteTemplate, CURSOR_START_X, CURSOR_START_Y, 0);
        StartSpriteAnim(&gSprites[sShopData->cursorSpriteId], 0);
        sShopData->gfxLoadState++;
        break;
    case 2:
        sShopData->gfxLoadState = 0;
        return TRUE;
        break;
    }
    return FALSE;
}

static void BuyMenuPrint(u8 windowId, const u8 *text, u8 x, u8 y, s8 speed, u8 colorSet, bool32 copy)
{
    AddTextPrinterParameterized4(windowId, FONT_SMALL, x, y, 0, 0, sShopBuyMenuTextColors[colorSet], speed, text);
    PutWindowTilemap(windowId);
    if (copy)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void PrintMoneyLocal(u8 windowId, u8 y, u32 amount, u8 width, u8 colorIdx, bool32 copy)
{
    u8 *txtPtr;
    s32 strLength;
    s32 x;

    ConvertIntToDecimalStringN(gStringVar1, amount, STR_CONV_MODE_RIGHT_ALIGN, 6);

    strLength = 6 - StringLength(gStringVar1);
    txtPtr = gStringVar4;

    while (strLength-- > 0)
        *(txtPtr++) = CHAR_SPACER;

    StringExpandPlaceholders(txtPtr, gText_PokedollarVar1);
    x = GetStringRightAlignXOffset(FONT_NORMAL, txtPtr, width);
    AddTextPrinterParameterized4(windowId, FONT_SMALL, x, y, 0, 0, sShopBuyMenuTextColors[colorIdx], TEXT_SKIP_DRAW, gStringVar4);
    PutWindowTilemap(windowId);
    if (copy)
        CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void BuyMenuDrawGraphics(void)
{
    PrintMoneyLocal(WIN_MONEY, 0, GetMoney(&gSaveBlock1Ptr->money), 84, COLORID_NORMAL, TRUE);
    ScheduleBgCopyTilemapToVram(0);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
}

static void UpdateItemData(void)
{
    const u8 strip[] = _("-");
    if (GridMenu_SelectedIndex(sShopData->gridItems) >= sMartInfo.itemCount)
        return;

    FillWindowPixelRect(WIN_MULTI, PIXEL_FILL(0), 0, 0, 84, 16);
    FillWindowPixelRect(WIN_MULTI, PIXEL_FILL(0), 34, 1*8, 84, 40);
    if (sMartInfo.itemList[GridMenu_SelectedIndex(sShopData->gridItems)] == ITEM_NONE)
    {
        FillWindowPixelRect(WIN_MULTI, PIXEL_FILL(0), 0, 0, 84, 16);
        BuyMenuPrint(WIN_MULTI, COMPOUND_STRING("Return to Field"), 0, 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        BuyMenuPrint(WIN_MULTI, strip, GetStringRightAlignXOffset(FONT_SMALL, strip, 61), 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

        if (sMartInfo.martType == MART_TYPE_NORMAL)
            BuyMenuPrint(WIN_MULTI, strip, GetStringRightAlignXOffset(FONT_SMALL, strip, 61), 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

        FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
        BuyMenuPrint(WIN_ITEM_DESCRIPTION, gText_QuitShopping, 0, 4, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    }
    else
    {
        u32 i = GridMenu_SelectedIndex(sShopData->gridItems);
        u32 item = sMartInfo.itemList[i];
        const u8 *desc = BuyMenuGetItemDesc(i);
        BuyMenuPrint(WIN_MULTI, BuyMenuGetItemName(i), 0, 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);

        if (sMartInfo.martType == MART_TYPE_NORMAL)
        {
            u16 quantity = CountTotalItemQuantityInBag(item);
            if (ItemId_GetPocket(item) == POCKET_TM_HM && item != ITEM_NONE)
            {
                const u8 *move = gMoveNames[ItemIdToBattleMoveId(item)];
                ReformatItemDescription(i, gStringVar2);
                desc = gStringVar2;
                BuyMenuPrint(WIN_MULTI, move, GetStringRightAlignXOffset(FONT_SMALL, move, 80), 0, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
            }

            if (ItemId_GetImportance(item) && (CheckBagHasItem(item, 1) || CheckPCHasItem(item, 1)))
                BuyMenuPrint(WIN_MULTI, gText_SoldOut, GetStringRightAlignXOffset(FONT_SMALL, gText_SoldOut, 80), 2*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
            else
                PrintMoneyLocal(WIN_MULTI, 2*8, BuyMenuGetItemPrice(i), 65, COLORID_BLACK, FALSE);

            ConvertIntToDecimalStringN(gStringVar3, quantity, STR_CONV_MODE_RIGHT_ALIGN, 4);
            BuyMenuPrint(WIN_MULTI, gStringVar3, GetStringRightAlignXOffset(FONT_SMALL, gStringVar3, 61), 4*8, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
        }
        else
        {
            PrintMoneyLocal(WIN_MULTI, 2*8, BuyMenuGetItemPrice(i), 65, COLORID_BLACK, FALSE);
        }
        FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
        BuyMenuPrint(WIN_ITEM_DESCRIPTION, desc, 0, 4, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    }
    CopyWindowToVram(WIN_MULTI, COPYWIN_FULL);
}

static void UpdateCursorPosition(void)
{
    u32 row = sShopData->gridItems->selectedItem / sShopData->gridItems->maxCols;
    u32 col = sShopData->gridItems->selectedItem % sShopData->gridItems->maxCols;
    // 8 because tile is 8px wide/tall, 5 because gridbox is 4 tiles plus 1 empty space
    u32 x = CURSOR_START_X + (col * (8 * 5));
    u32 y = CURSOR_START_Y + (row * (8 * 5));
    gSprites[sShopData->cursorSpriteId].x = x;
    gSprites[sShopData->cursorSpriteId].y = y;
}

static void Task_WaitMessage(u8 taskId)
{
    if (--gTasks[taskId].data[0] == 0)
    {
        UpdateItemData();
        gTasks[taskId].func = Task_BuyMenu;
    }
}

static void BuyMenuDisplayMessage(u8 taskId, const u8 *str, TaskFunc nextFunc)
{
    StringExpandPlaceholders(gStringVar4, str);
    BuyMenuPrint(WIN_ITEM_DESCRIPTION, gStringVar4, 0, 4, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
    gTasks[taskId].func = nextFunc;
}

static void Task_BuyMenuTryBuyingItem(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (sMartInfo.martType == MART_TYPE_NORMAL)
        sShopData->totalCost = (ItemId_GetPrice(sShopData->currentItemId) >> IsPokeNewsActive(POKENEWS_SLATEPORT));
    else
        sShopData->totalCost = gDecorations[sShopData->currentItemId].price;

    FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));

    if (sMartInfo.martType != MART_TYPE_DECOR || sMartInfo.martType != MART_TYPE_DECOR2)
    {
        if (ItemId_GetImportance(sShopData->currentItemId) && (CheckBagHasItem(sShopData->currentItemId, 1) || CheckPCHasItem(sShopData->currentItemId, 1)))
        {
            PlaySE(SE_BOO);
            gTasks[taskId].data[0] = 70;
            BuyMenuDisplayMessage(taskId, gText_ThatItemIsSoldOut, Task_WaitMessage);
            return;
        }
    }

    if (!IsEnoughMoney(&gSaveBlock1Ptr->money, sShopData->totalCost))
    {
        PlaySE(SE_BOO);
        gTasks[taskId].data[0] = 70;
        BuyMenuDisplayMessage(taskId, gText_YouDontHaveMoney, Task_WaitMessage);
    }
    else
    {
        PlaySE(SE_SELECT);
        if (sMartInfo.martType == MART_TYPE_NORMAL)
        {
            CopyItemName(sShopData->currentItemId, gStringVar1);
            if (ItemId_GetImportance(sShopData->currentItemId))
            {
                ConvertIntToDecimalStringN(gStringVar2, sShopData->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
                tItemCount = 1;
                sShopData->totalCost = (ItemId_GetPrice(sShopData->currentItemId) >> IsPokeNewsActive(POKENEWS_SLATEPORT)) * tItemCount;
                BuyMenuDisplayMessage(taskId, gText_YouWantedVar1ThatllBeVar2, BuyMenuConfirmPurchase);
            }
            else if (ItemId_GetPocket(sShopData->currentItemId) == POCKET_TM_HM)
            {
                BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany2, Task_BuyHowManyDialogueInit);
            }
            else
            {
                BuyMenuDisplayMessage(taskId, gText_Var1CertainlyHowMany, Task_BuyHowManyDialogueInit);
            }
        }
        else
        {
            const u8 *str;
            StringCopy(gStringVar1, gDecorations[sShopData->currentItemId].name);
            ConvertIntToDecimalStringN(gStringVar2, sShopData->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            if (sMartInfo.martType == MART_TYPE_DECOR)
                str = gText_Var1IsItThatllBeVar2;
            else // MART_TYPE_DECOR2
                str = gText_YouWantedVar1ThatllBeVar2;

            BuyMenuDisplayMessage(taskId, str, BuyMenuConfirmPurchase);
        }
    }
}

static inline void ExitBuyMenu(u8 taskId)
{
    gFieldCallback = MapPostLoadHook_ReturnToShopMenu;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_ExitBuyMenu;
}

static void Task_BuyMenu(u8 taskId)
{
    GridMenu_HandleInput(sShopData->gridItems);
    if (JOY_REPEAT(DPAD_ANY))
    {
        DebugPrintf("idx: %d", GridMenu_SelectedIndex(sShopData->gridItems));
    }
    else if (JOY_NEW(B_BUTTON))
    {
        ExitBuyMenu(taskId);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        sShopData->currentItemId = sMartInfo.itemList[GridMenu_SelectedIndex(sShopData->gridItems)];
        if (sShopData->currentItemId == ITEM_NONE)
        {
            ExitBuyMenu(taskId);
        }
        else
        {
            gTasks[taskId].func = Task_BuyMenuTryBuyingItem;
        }
        DebugPrintf("Chosen item: %d", sShopData->currentItemId);

    }
    UpdateCursorPosition();
}

static void Task_BuyHowManyDialogueInit(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 maxQuantity;

    tItemCount = 1;
    BuyMenuPrintItemQuantityAndPrice(taskId);
    ScheduleBgCopyTilemapToVram(0);

    maxQuantity = GetMoney(&gSaveBlock1Ptr->money) / sShopData->totalCost;

    if (maxQuantity > MAX_BAG_ITEM_CAPACITY)
        sShopData->maxQuantity = MAX_BAG_ITEM_CAPACITY;
    else
        sShopData->maxQuantity = maxQuantity;

    gTasks[taskId].func = Task_BuyHowManyDialogueHandleInput;
}

static void Task_BuyHowManyDialogueHandleInput(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (AdjustQuantityAccordingToDPadInput(&tItemCount, sShopData->maxQuantity) == TRUE)
    {
        sShopData->totalCost = (ItemId_GetPrice(sShopData->currentItemId) >> IsPokeNewsActive(POKENEWS_SLATEPORT)) * tItemCount;
        BuyMenuPrintItemQuantityAndPrice(taskId);
    }
    else
    {
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearWindowTilemap(WIN_QUANTITY_PRICE);
            CopyItemName(sShopData->currentItemId, gStringVar1);
            ConvertIntToDecimalStringN(gStringVar2, tItemCount, STR_CONV_MODE_LEFT_ALIGN, BAG_ITEM_CAPACITY_DIGITS);
            ConvertIntToDecimalStringN(gStringVar3, sShopData->totalCost, STR_CONV_MODE_LEFT_ALIGN, 6);
            FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
            if (tItemCount >= 2)
                CopyItemNameHandlePlural(sShopData->currentItemId, gStringVar1, tItemCount);
            else
                CopyItemName(sShopData->currentItemId, gStringVar1);

            BuyMenuDisplayMessage(taskId, gText_Var1AndYouWantedVar2, BuyMenuConfirmPurchase);
        }
        else if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            ClearWindowTilemap(WIN_QUANTITY_PRICE);
            BuyMenuReturnToItemList(taskId);
        }
    }
}

static void BuyMenuConfirmPurchase(u8 taskId)
{
    CreateYesNoMenuWithCallbacks(taskId, &sShopBuyMenuYesNoWindowTemplates, 1, 0, 0, 1, 13, &sShopPurchaseYesNoFuncs);
}

static void BuyMenuTryMakePurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
    if (sMartInfo.martType == MART_TYPE_NORMAL)
    {
        if (AddBagItem(sShopData->currentItemId, tItemCount) == TRUE)
        {
            GetSetItemObtained(sShopData->currentItemId, FLAG_SET_OBTAINED);
            RecordItemPurchase(taskId);
            BuyMenuDisplayMessage(taskId, gText_HereYouGoThankYou, BuyMenuSubtractMoney);
        }
        else
        {
            BuyMenuDisplayMessage(taskId, gText_NoMoreRoomForThis, BuyMenuReturnToItemList);
        }
    }
    else
    {
        if (DecorationAdd(sShopData->currentItemId))
        {
            if (sMartInfo.martType == MART_TYPE_DECOR)
                BuyMenuDisplayMessage(taskId, gText_ThankYouIllSendItHome, BuyMenuSubtractMoney);
            else // MART_TYPE_DECOR2
                BuyMenuDisplayMessage(taskId, gText_ThanksIllSendItHome, BuyMenuSubtractMoney);
        }
        else
        {
            BuyMenuDisplayMessage(taskId, gText_SpaceForVar1Full, BuyMenuReturnToItemList);
        }
    }
}

static void BuyMenuSubtractMoney(u8 taskId)
{
    IncrementGameStat(GAME_STAT_SHOPPED);
    RemoveMoney(&gSaveBlock1Ptr->money, sShopData->totalCost);
    PlaySE(SE_SHOP);
    FillWindowPixelBuffer(WIN_MONEY, PIXEL_FILL(0));
    PrintMoneyLocal(WIN_MONEY, 0, GetMoney(&gSaveBlock1Ptr->money), 84, COLORID_NORMAL, TRUE);

    if (sMartInfo.martType == MART_TYPE_NORMAL)
        gTasks[taskId].func = Task_ReturnToItemListAfterItemPurchase;
    else
        gTasks[taskId].func = Task_ReturnToItemListAfterDecorationPurchase;
}

// This is hacky but this'd do it
static void Task_ReturnToItemListWaitMsg(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        if (JOY_NEW(A_BUTTON | B_BUTTON))
            BuyMenuReturnToItemList(taskId);
    }
    else
        gTasks[taskId].data[0]--;
}

static void Task_ReturnToItemListAfterItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        if (gTasks[taskId].data[0] != 20)
            PlaySE(SE_SELECT);

        // Purchasing 10+ Poke Balls gets the player a Premier Ball
        if (sShopData->currentItemId == ITEM_POKE_BALL && tItemCount < 20 && tItemCount >= 10 && AddBagItem(ITEM_PREMIER_BALL, 1) == TRUE)
        {
            FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
            BuyMenuPrint(WIN_ITEM_DESCRIPTION, gText_ThrowInPremierBall, 0, 4, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
        }
        else if (sShopData->currentItemId == ITEM_POKE_BALL && tItemCount >= 20 && AddBagItem(ITEM_PREMIER_BALL, (tItemCount / 10)) == TRUE)
        {
            FillWindowPixelBuffer(WIN_ITEM_DESCRIPTION, PIXEL_FILL(0));
            BuyMenuPrint(WIN_ITEM_DESCRIPTION, gText_ThrowInSomePremierBalls, 0, 4, TEXT_SKIP_DRAW, COLORID_BLACK, TRUE);
        }
        gTasks[taskId].data[0] = 20;
        gTasks[taskId].func = Task_ReturnToItemListWaitMsg;
    }
}

static void Task_ReturnToItemListAfterDecorationPurchase(u8 taskId)
{
    if (JOY_NEW(A_BUTTON | B_BUTTON))
    {
        PlaySE(SE_SELECT);
        BuyMenuReturnToItemList(taskId);
    }
}

static void BuyMenuReturnToItemList(u8 taskId)
{
    UpdateItemData();
    gTasks[taskId].func = Task_BuyMenu;
}

static void BuyMenuPrintItemQuantityAndPrice(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    FillWindowPixelBuffer(WIN_QUANTITY_PRICE, PIXEL_FILL(0));
    PrintMoneyLocal(WIN_QUANTITY_PRICE, 13, sShopData->totalCost, 51, COLORID_BLACK, FALSE);
    ConvertIntToDecimalStringN(gStringVar1, tItemCount, STR_CONV_MODE_LEADING_ZEROS, BAG_ITEM_CAPACITY_DIGITS);
    StringExpandPlaceholders(gStringVar4, gText_xVar1);
    BuyMenuPrint(WIN_QUANTITY_PRICE, gStringVar4, 29, 3, TEXT_SKIP_DRAW, COLORID_BLACK, FALSE);
    CopyWindowToVram(WIN_QUANTITY_PRICE, COPYWIN_FULL);
}

static void Task_ExitBuyMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        BuyMenuFreeMemory();
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

static void ClearItemPurchases(void)
{
    sPurchaseHistoryId = 0;
    memset(gMartPurchaseHistory, 0, sizeof(gMartPurchaseHistory));
}

static void RecordItemPurchase(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    u16 i;

    for (i = 0; i < ARRAY_COUNT(gMartPurchaseHistory); i++)
    {
        if (gMartPurchaseHistory[i].itemId == sShopData->currentItemId && gMartPurchaseHistory[i].quantity != 0)
        {
            if (gMartPurchaseHistory[i].quantity + tItemCount > 255)
                gMartPurchaseHistory[i].quantity = 255;
            else
                gMartPurchaseHistory[i].quantity += tItemCount;
            return;
        }
    }

    if (sPurchaseHistoryId < ARRAY_COUNT(gMartPurchaseHistory))
    {
        gMartPurchaseHistory[sPurchaseHistoryId].itemId = sShopData->currentItemId;
        gMartPurchaseHistory[sPurchaseHistoryId].quantity = tItemCount;
        sPurchaseHistoryId++;
    }
}

#undef tItemCount
#undef tListTaskId
#undef tCallbackHi
#undef tCallbackLo

void CreatePokemartMenu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_NORMAL);
    SetShopItemsForSale(itemsForSale);
    ClearItemPurchases();
    SetShopMenuCallback(ScriptContext_Enable);
}

void CreateDecorationShop1Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(ScriptContext_Enable);
}

void CreateDecorationShop2Menu(const u16 *itemsForSale)
{
    CreateShopMenu(MART_TYPE_DECOR2);
    SetShopItemsForSale(itemsForSale);
    SetShopMenuCallback(ScriptContext_Enable);
}
