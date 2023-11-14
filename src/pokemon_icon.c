#include "global.h"
#include "graphics.h"
#include "mail.h"
#include "palette.h"
#include "pokemon_debug.h"
#include "pokemon_icon.h"
#include "sprite.h"
#include "data.h"

#define POKE_ICON_BASE_PAL_TAG 56000

#define INVALID_ICON_SPECIES SPECIES_NONE // Oddly specific, used when an icon should be a ?. Any of the 'old unown' would work

struct MonIconSpriteTemplate
{
    const struct OamData *oam;
    const u8 *image;
    const union AnimCmd *const *anims;
    const union AffineAnimCmd *const *affineAnims;
    void (*callback)(struct Sprite *);
    u16 paletteTag;
};

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *, s16, s16, u8);
static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite);

const u8 *const gMonIconTable[NUM_SPECIES + 1] =
{
    [SPECIES_NONE] = gMonIcon_QuestionMark,
    [SPECIES_BULBASAUR] = gMonIcon_Bulbasaur,
    [SPECIES_IVYSAUR] = gMonIcon_Ivysaur,
    [SPECIES_VENUSAUR] = gMonIcon_Venusaur,
    [SPECIES_CHARMANDER] = gMonIcon_Charmander,
    [SPECIES_CHARMELEON] = gMonIcon_Charmeleon,
    [SPECIES_CHARIZARD] = gMonIcon_Charizard,
    [SPECIES_SQUIRTLE] = gMonIcon_Squirtle,
    [SPECIES_WARTORTLE] = gMonIcon_Wartortle,
    [SPECIES_BLASTOISE] = gMonIcon_Blastoise,
    [SPECIES_RATTATA] = gMonIcon_Rattata,
    [SPECIES_RATICATE] = gMonIcon_Raticate,
    [SPECIES_PIKACHU] = gMonIcon_Pikachu,
    [SPECIES_RAICHU] = gMonIcon_Raichu,
    [SPECIES_SANDSHREW] = gMonIcon_Sandshrew,
    [SPECIES_SANDSLASH] = gMonIcon_Sandslash,
    [SPECIES_VULPIX] = gMonIcon_Vulpix,
    [SPECIES_NINETALES] = gMonIcon_Ninetales,
    [SPECIES_DIGLETT] = gMonIcon_Diglett,
    [SPECIES_DUGTRIO] = gMonIcon_Dugtrio,
    [SPECIES_MEOWTH] = gMonIcon_Meowth,
    [SPECIES_PERSIAN] = gMonIcon_Persian,
    [SPECIES_GEODUDE] = gMonIcon_Geodude,
    [SPECIES_GRAVELER] = gMonIcon_Graveler,
    [SPECIES_GOLEM] = gMonIcon_Golem,
    [SPECIES_PONYTA] = gMonIcon_Ponyta,
    [SPECIES_RAPIDASH] = gMonIcon_Rapidash,
    [SPECIES_SLOWPOKE] = gMonIcon_Slowpoke,
    [SPECIES_SLOWBRO] = gMonIcon_Slowbro,
    [SPECIES_FARFETCHD] = gMonIcon_Farfetchd,
    [SPECIES_GRIMER] = gMonIcon_Grimer,
    [SPECIES_MUK] = gMonIcon_Muk,
    [SPECIES_MR_MIME] = gMonIcon_MrMime,
    [SPECIES_DITTO] = gMonIcon_Ditto,
    [SPECIES_ARTICUNO] = gMonIcon_Articuno,
    [SPECIES_ZAPDOS] = gMonIcon_Zapdos,
    [SPECIES_MOLTRES] = gMonIcon_Moltres,
    [SPECIES_MEWTWO] = gMonIcon_Mewtwo,
    [SPECIES_MEW] = gMonIcon_Mew,
    [SPECIES_SHUCKLE] = gMonIcon_Shuckle,
    [SPECIES_RAIKOU] = gMonIcon_Raikou,
    [SPECIES_ENTEI] = gMonIcon_Entei,
    [SPECIES_SUICUNE] = gMonIcon_Suicune,
    [SPECIES_LUGIA] = gMonIcon_Lugia,
    [SPECIES_HO_OH] = gMonIcon_HoOh,
    [SPECIES_CELEBI] = gMonIcon_Celebi,
    [SPECIES_TREECKO] = gMonIcon_Treecko,
    [SPECIES_GROVYLE] = gMonIcon_Grovyle,
    [SPECIES_SCEPTILE] = gMonIcon_Sceptile,
    [SPECIES_TORCHIC] = gMonIcon_Torchic,
    [SPECIES_COMBUSKEN] = gMonIcon_Combusken,
    [SPECIES_BLAZIKEN] = gMonIcon_Blaziken,
    [SPECIES_MUDKIP] = gMonIcon_Mudkip,
    [SPECIES_MARSHTOMP] = gMonIcon_Marshtomp,
    [SPECIES_SWAMPERT] = gMonIcon_Swampert,
    [SPECIES_NINCADA] = gMonIcon_Nincada,
    [SPECIES_NINJASK] = gMonIcon_Ninjask,
    [SPECIES_SHEDINJA] = gMonIcon_Shedinja,
    [SPECIES_REGIROCK] = gMonIcon_Regirock,
    [SPECIES_REGICE] = gMonIcon_Regice,
    [SPECIES_REGISTEEL] = gMonIcon_Registeel,
    [SPECIES_KYOGRE] = gMonIcon_Kyogre,
    [SPECIES_GROUDON] = gMonIcon_Groudon,
    [SPECIES_RAYQUAZA] = gMonIcon_Rayquaza,
    [SPECIES_LATIAS] = gMonIcon_Latias,
    [SPECIES_LATIOS] = gMonIcon_Latios,
    [SPECIES_JIRACHI] = gMonIcon_Jirachi,
    [SPECIES_DEOXYS] = gMonIcon_Deoxys,
#if P_GEN_4_POKEMON == TRUE
    [SPECIES_CHERUBI] = gMonIcon_Cherubi,
    [SPECIES_CHERRIM] = gMonIcon_Cherrim,
    [SPECIES_SHELLOS] = gMonIcon_Shellos,
    [SPECIES_GASTRODON] = gMonIcon_Gastrodon,
    [SPECIES_ROTOM] = gMonIcon_Rotom,
    [SPECIES_UXIE] = gMonIcon_Uxie,
    [SPECIES_MESPRIT] = gMonIcon_Mesprit,
    [SPECIES_AZELF] = gMonIcon_Azelf,
    [SPECIES_DIALGA] = gMonIcon_Dialga,
    [SPECIES_PALKIA] = gMonIcon_Palkia,
    [SPECIES_HEATRAN] = gMonIcon_Heatran,
    [SPECIES_REGIGIGAS] = gMonIcon_Regigigas,
    [SPECIES_GIRATINA] = gMonIcon_Giratina,
    [SPECIES_CRESSELIA] = gMonIcon_Cresselia,
    [SPECIES_PHIONE] = gMonIcon_Phione,
    [SPECIES_MANAPHY] = gMonIcon_Manaphy,
    [SPECIES_DARKRAI] = gMonIcon_Darkrai,
    [SPECIES_SHAYMIN] = gMonIcon_Shaymin,
    [SPECIES_ARCEUS] = gMonIcon_Arceus,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_VICTINI] = gMonIcon_Victini,
    [SPECIES_ZORUA] = gMonIcon_Zorua,
    [SPECIES_ZOROARK] = gMonIcon_Zoroark,
    [SPECIES_DEERLING] = gMonIcon_Deerling,
    [SPECIES_SAWSBUCK] = gMonIcon_Sawsbuck,
    [SPECIES_COBALION] = gMonIcon_Cobalion,
    [SPECIES_TERRAKION] = gMonIcon_Terrakion,
    [SPECIES_VIRIZION] = gMonIcon_Virizion,
    [SPECIES_TORNADUS] = gMonIcon_Tornadus,
    [SPECIES_THUNDURUS] = gMonIcon_Thundurus,
    [SPECIES_RESHIRAM] = gMonIcon_Reshiram,
    [SPECIES_ZEKROM] = gMonIcon_Zekrom,
    [SPECIES_LANDORUS] = gMonIcon_Landorus,
    [SPECIES_KYUREM] = gMonIcon_Kyurem,
    [SPECIES_KELDEO] = gMonIcon_Keldeo,
    [SPECIES_MELOETTA] = gMonIcon_Meloetta,
    [SPECIES_GENESECT] = gMonIcon_Genesect,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_FROAKIE] = gMonIcon_Froakie,
    [SPECIES_FROGADIER] = gMonIcon_Frogadier,
    [SPECIES_GRENINJA] = gMonIcon_Greninja,
    [SPECIES_SCATTERBUG] = gMonIcon_Scatterbug,
    [SPECIES_SPEWPA] = gMonIcon_Spewpa,
    [SPECIES_VIVILLON] = gMonIcon_Vivillon,
    [SPECIES_FLABEBE] = gMonIcon_Flabebe,
    [SPECIES_FLOETTE] = gMonIcon_Floette,
    [SPECIES_FLORGES] = gMonIcon_Florges,
    [SPECIES_FURFROU] = gMonIcon_Furfrou,
    [SPECIES_HONEDGE] = gMonIcon_Honedge,
    [SPECIES_DOUBLADE] = gMonIcon_Doublade,
    [SPECIES_AEGISLASH] = gMonIcon_Aegislash,
    [SPECIES_PUMPKABOO] = gMonIcon_Pumpkaboo,
    [SPECIES_GOURGEIST] = gMonIcon_Gourgeist,
    [SPECIES_BERGMITE] = gMonIcon_Bergmite,
    [SPECIES_AVALUGG] = gMonIcon_Avalugg,
    [SPECIES_XERNEAS] = gMonIcon_Xerneas,
    [SPECIES_YVELTAL] = gMonIcon_Yveltal,
    [SPECIES_ZYGARDE] = gMonIcon_Zygarde,
    [SPECIES_DIANCIE] = gMonIcon_Diancie,
    [SPECIES_HOOPA] = gMonIcon_Hoopa,
    [SPECIES_VOLCANION] = gMonIcon_Volcanion,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ORICORIO] = gMonIcon_Oricorio,
    [SPECIES_ROCKRUFF] = gMonIcon_Rockruff,
    [SPECIES_LYCANROC] = gMonIcon_Lycanroc,
    [SPECIES_WISHIWASHI] = gMonIcon_Wishiwashi,
    [SPECIES_TYPE_NULL] = gMonIcon_TypeNull,
    [SPECIES_SILVALLY] = gMonIcon_Silvally,
    [SPECIES_MINIOR] = gMonIcon_Minior,
    [SPECIES_MIMIKYU] = gMonIcon_Mimikyu,
    [SPECIES_TAPU_KOKO] = gMonIcon_TapuKoko,
    [SPECIES_TAPU_LELE] = gMonIcon_TapuLele,
    [SPECIES_TAPU_BULU] = gMonIcon_TapuBulu,
    [SPECIES_TAPU_FINI] = gMonIcon_TapuFini,
    [SPECIES_COSMOG] = gMonIcon_Cosmog,
    [SPECIES_COSMOEM] = gMonIcon_Cosmoem,
    [SPECIES_SOLGALEO] = gMonIcon_Solgaleo,
    [SPECIES_LUNALA] = gMonIcon_Lunala,
    [SPECIES_NIHILEGO] = gMonIcon_Nihilego,
    [SPECIES_BUZZWOLE] = gMonIcon_Buzzwole,
    [SPECIES_PHEROMOSA] = gMonIcon_Pheromosa,
    [SPECIES_XURKITREE] = gMonIcon_Xurkitree,
    [SPECIES_CELESTEELA] = gMonIcon_Celesteela,
    [SPECIES_KARTANA] = gMonIcon_Kartana,
    [SPECIES_GUZZLORD] = gMonIcon_Guzzlord,
    [SPECIES_NECROZMA] = gMonIcon_Necrozma,
    [SPECIES_MAGEARNA] = gMonIcon_Magearna,
    [SPECIES_MARSHADOW] = gMonIcon_Marshadow,
    [SPECIES_POIPOLE] = gMonIcon_Poipole,
    [SPECIES_NAGANADEL] = gMonIcon_Naganadel,
    [SPECIES_STAKATAKA] = gMonIcon_Stakataka,
    [SPECIES_BLACEPHALON] = gMonIcon_Blacephalon,
    [SPECIES_ZERAORA] = gMonIcon_Zeraora,
    [SPECIES_MELTAN] = gMonIcon_Meltan,
    [SPECIES_MELMETAL] = gMonIcon_Melmetal,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CRAMORANT] = gMonIcon_Cramorant,
    [SPECIES_TOXEL] = gMonIcon_Toxel,
    [SPECIES_TOXTRICITY] = gMonIcon_Toxtricity,
    [SPECIES_SINISTEA] = gMonIcon_Sinistea,
    [SPECIES_POLTEAGEIST] = gMonIcon_Polteageist,
    [SPECIES_OBSTAGOON] = gMonIcon_Obstagoon,
    [SPECIES_PERRSERKER] = gMonIcon_Perrserker,
    [SPECIES_CURSOLA] = gMonIcon_Cursola,
    [SPECIES_SIRFETCHD] = gMonIcon_Sirfetchd,
    [SPECIES_MR_RIME] = gMonIcon_MrRime,
    [SPECIES_RUNERIGUS] = gMonIcon_Runerigus,
    [SPECIES_MILCERY] = gMonIcon_Milcery,
    [SPECIES_ALCREMIE] = gMonIcon_Alcremie,
    [SPECIES_EISCUE] = gMonIcon_Eiscue,
    [SPECIES_MORPEKO] = gMonIcon_Morpeko,
    [SPECIES_ZACIAN] = gMonIcon_Zacian,
    [SPECIES_ZAMAZENTA] = gMonIcon_Zamazenta,
    [SPECIES_ETERNATUS] = gMonIcon_Eternatus,
    [SPECIES_KUBFU] = gMonIcon_Kubfu,
    [SPECIES_URSHIFU] = gMonIcon_Urshifu,
    [SPECIES_ZARUDE] = gMonIcon_Zarude,
    [SPECIES_REGIELEKI] = gMonIcon_Regieleki,
    [SPECIES_REGIDRAGO] = gMonIcon_Regidrago,
    [SPECIES_GLASTRIER] = gMonIcon_Glastrier,
    [SPECIES_SPECTRIER] = gMonIcon_Spectrier,
    [SPECIES_CALYREX] = gMonIcon_Calyrex,
    [SPECIES_WYRDEER] = gMonIcon_Wyrdeer,
    [SPECIES_KLEAVOR] = gMonIcon_Kleavor,
    [SPECIES_URSALUNA] = gMonIcon_Ursaluna,
    [SPECIES_BASCULEGION] = gMonIcon_Basculegion,
    [SPECIES_SNEASLER] = gMonIcon_Sneasler,
    [SPECIES_OVERQWIL] = gMonIcon_Overqwil,
    [SPECIES_ENAMORUS] = gMonIcon_Enamorus,
    [SPECIES_TIDPIT] = gMonIcon_Tidpit,
    [SPECIES_SLIDLOW] = gMonIcon_Slidlow,
    [SPECIES_CARDIOVOR] = gMonIcon_Cardiovor,
    [SPECIES_FIEFREET] = gMonIcon_Fiefreet,
    [SPECIES_BALBYRN] = gMonIcon_Balbyrn,
    [SPECIES_BLAZIZAHAK] = gMonIcon_Blazizahak,
    [SPECIES_PRONGY] = gMonIcon_Prongy,
    [SPECIES_TRIDALIER] = gMonIcon_Tridalier,
    [SPECIES_TRITONAUT] = gMonIcon_Tritonaut,
    [SPECIES_SNELFREND] = gMonIcon_Snelfrend,
    [SPECIES_SYCOPLOD] = gMonIcon_Sycoplod,
    [SPECIES_SYCOSTROM] = gMonIcon_Sycostrom,
    [SPECIES_GUPSPAR] = gMonIcon_Gupspar,
    [SPECIES_VANGAR] = gMonIcon_Vangar,
    [SPECIES_GHAERIAL] = gMonIcon_Ghaerial,
    [SPECIES_MARINAROC] = gMonIcon_Marinaroc,
    [SPECIES_METTATOLL] = gMonIcon_Mettatoll,
    [SPECIES_ICKSQUEEK] = gMonIcon_Icksqueek,
    [SPECIES_KOMORODE] = gMonIcon_Komorode,
    [SPECIES_KYUDI] = gMonIcon_Kyudi,
    [SPECIES_KOMBAKYU] = gMonIcon_Kombakyu,
    [SPECIES_FLUFFSIR] = gMonIcon_Fluffsir,
    [SPECIES_FLUFFREAR] = gMonIcon_Fluffrear,
    [SPECIES_SAINTISOW] = gMonIcon_Saintisow,
    [SPECIES_SANCTISOW] = gMonIcon_Sanctisow,
    [SPECIES_SOWPHIROTH] = gMonIcon_Sowphiroth,
    [SPECIES_TOXEXOT] = gMonIcon_Toxexot,
    [SPECIES_PSEUDRA] = gMonIcon_Pseudra,
    [SPECIES_MANDIMYTE] = gMonIcon_Mandimyte,
    [SPECIES_TERMINYTE] = gMonIcon_Terminyte,
    [SPECIES_SNOTLOUD] = gMonIcon_Snotloud,
    [SPECIES_SICKBEAT] = gMonIcon_Sickbeat,
    [SPECIES_SPRYTE] = gMonIcon_Spryte,
    [SPECIES_GUMONA] = gMonIcon_Gumona,
    [SPECIES_NANGGAL] = gMonIcon_Nanggal,
    [SPECIES_SHEEDRAKE] = gMonIcon_Sheedrake,
    [SPECIES_TRANSERA] = gMonIcon_Transera,
    [SPECIES_BIVAGUE] = gMonIcon_Bivague,
    [SPECIES_LUSCKAW] = gMonIcon_Lusckaw,
    [SPECIES_SADSOD] = gMonIcon_Sadsod,
    [SPECIES_MAERACHOLY] = gMonIcon_Maeracholy,
    [SPECIES_LUMELMO] = gMonIcon_Lumelmo,
    [SPECIES_LUMENDELA] = gMonIcon_Lumendela,
    [SPECIES_STOMAWAY] = gMonIcon_Stomaway,
    [SPECIES_CRAWLAXY] = gMonIcon_Crawlaxy,
    [SPECIES_MAGNALURE] = gMonIcon_Magnalure,
    [SPECIES_MAGNANICOR] = gMonIcon_Magnanicor,
    [SPECIES_CRYPLIN] = gMonIcon_Cryplin,
    [SPECIES_UHEFOE] = gMonIcon_Uhefoe,
    [SPECIES_MYSTOMANIA] = gMonIcon_Mystomania,
    [SPECIES_LYORESA] = gMonIcon_Lyoresa,
    [SPECIES_KODOUGH] = gMonIcon_Kodough,
    [SPECIES_SLICKSLICE] = gMonIcon_Slickslice,
    [SPECIES_LOAFOOF] = gMonIcon_Loafoof,
    [SPECIES_SPIRITOAST] = gMonIcon_Spiritoast,
#endif
    [SPECIES_VENUSAUR_MEGA] = gMonIcon_VenusaurMega,
    [SPECIES_CHARIZARD_MEGA_X] = gMonIcon_CharizardMegaX,
    [SPECIES_CHARIZARD_MEGA_Y] = gMonIcon_CharizardMegaY,
    [SPECIES_BLASTOISE_MEGA] = gMonIcon_BlastoiseMega,
    [SPECIES_SLOWBRO_MEGA] = gMonIcon_SlowbroMega,
    [SPECIES_MEWTWO_MEGA_X] = gMonIcon_MewtwoMegaX,
    [SPECIES_MEWTWO_MEGA_Y] = gMonIcon_MewtwoMegaY,
    [SPECIES_SCEPTILE_MEGA] = gMonIcon_SceptileMega,
    [SPECIES_BLAZIKEN_MEGA] = gMonIcon_BlazikenMega,
    [SPECIES_SWAMPERT_MEGA] = gMonIcon_SwampertMega,
    [SPECIES_LATIAS_MEGA] = gMonIcon_LatiasMega,
    [SPECIES_LATIOS_MEGA] = gMonIcon_LatiosMega,
    [SPECIES_RAYQUAZA_MEGA] = gMonIcon_RayquazaMega,
    [SPECIES_KYOGRE_PRIMAL] = gMonIcon_KyogrePrimal,
    [SPECIES_GROUDON_PRIMAL] = gMonIcon_GroudonPrimal,
    [SPECIES_RATTATA_ALOLAN] = gMonIcon_RattataAlolan,
    [SPECIES_RATICATE_ALOLAN] = gMonIcon_RaticateAlolan,
    [SPECIES_RAICHU_ALOLAN] = gMonIcon_RaichuAlolan,
    [SPECIES_SANDSHREW_ALOLAN] = gMonIcon_SandshrewAlolan,
    [SPECIES_SANDSLASH_ALOLAN] = gMonIcon_SandslashAlolan,
    [SPECIES_VULPIX_ALOLAN] = gMonIcon_VulpixAlolan,
    [SPECIES_NINETALES_ALOLAN] = gMonIcon_NinetalesAlolan,
    [SPECIES_DIGLETT_ALOLAN] = gMonIcon_DiglettAlolan,
    [SPECIES_DUGTRIO_ALOLAN] = gMonIcon_DugtrioAlolan,
    [SPECIES_MEOWTH_ALOLAN] = gMonIcon_MeowthAlolan,
    [SPECIES_PERSIAN_ALOLAN] = gMonIcon_PersianAlolan,
    [SPECIES_GEODUDE_ALOLAN] = gMonIcon_GeodudeAlolan,
    [SPECIES_GRAVELER_ALOLAN] = gMonIcon_GravelerAlolan,
    [SPECIES_GOLEM_ALOLAN] = gMonIcon_GolemAlolan,
    [SPECIES_GRIMER_ALOLAN] = gMonIcon_GrimerAlolan,
    [SPECIES_MUK_ALOLAN] = gMonIcon_MukAlolan,
    [SPECIES_MEOWTH_GALARIAN] = gMonIcon_MeowthGalarian,
    [SPECIES_PONYTA_GALARIAN] = gMonIcon_PonytaGalarian,
    [SPECIES_RAPIDASH_GALARIAN] = gMonIcon_RapidashGalarian,
    [SPECIES_SLOWPOKE_GALARIAN] = gMonIcon_SlowpokeGalarian,
    [SPECIES_SLOWBRO_GALARIAN] = gMonIcon_SlowbroGalarian,
    [SPECIES_FARFETCHD_GALARIAN] = gMonIcon_FarfetchdGalarian,
    [SPECIES_MR_MIME_GALARIAN] = gMonIcon_MrMimeGalarian,
    [SPECIES_ARTICUNO_GALARIAN] = gMonIcon_ArticunoGalarian,
    [SPECIES_ZAPDOS_GALARIAN] = gMonIcon_ZapdosGalarian,
    [SPECIES_MOLTRES_GALARIAN] = gMonIcon_MoltresGalarian,
    [SPECIES_CORSOLA_GALARIAN] = gMonIcon_CorsolaGalarian,
    [SPECIES_ZIGZAGOON_GALARIAN] = gMonIcon_ZigzagoonGalarian,
    [SPECIES_LINOONE_GALARIAN] = gMonIcon_LinooneGalarian,
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_DARUMAKA_GALARIAN] = gMonIcon_DarumakaGalarian,
    [SPECIES_DARMANITAN_GALARIAN] = gMonIcon_DarmanitanGalarian,
    [SPECIES_YAMASK_GALARIAN] = gMonIcon_YamaskGalarian,
    [SPECIES_STUNFISK_GALARIAN] = gMonIcon_StunfiskGalarian,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_ZORUA_HISUIAN] = gMonIcon_ZoruaHisuian,
    [SPECIES_ZOROARK_HISUIAN] = gMonIcon_ZoroarkHisuian,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_AVALUGG_HISUIAN] = gMonIcon_AvaluggHisuian,
#endif
    [SPECIES_PIKACHU_COSPLAY] = gMonIcon_PikachuCosplay,
    [SPECIES_PIKACHU_ROCK_STAR] = gMonIcon_PikachuRockStar,
    [SPECIES_PIKACHU_BELLE] = gMonIcon_PikachuBelle,
    [SPECIES_PIKACHU_POP_STAR] = gMonIcon_PikachuPopStar,
    [SPECIES_PIKACHU_PH_D] = gMonIcon_PikachuPhD,
    [SPECIES_PIKACHU_LIBRE] = gMonIcon_PikachuLibre,
    [SPECIES_PIKACHU_ORIGINAL_CAP] = gMonIcon_PikachuOriginalCap,
    [SPECIES_PIKACHU_HOENN_CAP] = gMonIcon_PikachuHoennCap,
    [SPECIES_PIKACHU_SINNOH_CAP] = gMonIcon_PikachuSinnohCap,
    [SPECIES_PIKACHU_UNOVA_CAP] = gMonIcon_PikachuUnovaCap,
    [SPECIES_PIKACHU_KALOS_CAP] = gMonIcon_PikachuKalosCap,
    [SPECIES_PIKACHU_ALOLA_CAP] = gMonIcon_PikachuAlolaCap,
    [SPECIES_PIKACHU_PARTNER_CAP] = gMonIcon_PikachuPartnerCap,
    [SPECIES_PIKACHU_WORLD_CAP] = gMonIcon_QuestionMark,
    [SPECIES_PICHU_SPIKY_EARED] = gMonIcon_PichuSpikyEared,
    [SPECIES_UNOWN_B] = gMonIcon_UnownB,
    [SPECIES_UNOWN_C] = gMonIcon_UnownC,
    [SPECIES_UNOWN_D] = gMonIcon_UnownD,
    [SPECIES_UNOWN_E] = gMonIcon_UnownE,
    [SPECIES_UNOWN_F] = gMonIcon_UnownF,
    [SPECIES_UNOWN_G] = gMonIcon_UnownG,
    [SPECIES_UNOWN_H] = gMonIcon_UnownH,
    [SPECIES_UNOWN_I] = gMonIcon_UnownI,
    [SPECIES_UNOWN_J] = gMonIcon_UnownJ,
    [SPECIES_UNOWN_K] = gMonIcon_UnownK,
    [SPECIES_UNOWN_L] = gMonIcon_UnownL,
    [SPECIES_UNOWN_M] = gMonIcon_UnownM,
    [SPECIES_UNOWN_N] = gMonIcon_UnownN,
    [SPECIES_UNOWN_O] = gMonIcon_UnownO,
    [SPECIES_UNOWN_P] = gMonIcon_UnownP,
    [SPECIES_UNOWN_Q] = gMonIcon_UnownQ,
    [SPECIES_UNOWN_R] = gMonIcon_UnownR,
    [SPECIES_UNOWN_S] = gMonIcon_UnownS,
    [SPECIES_UNOWN_T] = gMonIcon_UnownT,
    [SPECIES_UNOWN_U] = gMonIcon_UnownU,
    [SPECIES_UNOWN_V] = gMonIcon_UnownV,
    [SPECIES_UNOWN_W] = gMonIcon_UnownW,
    [SPECIES_UNOWN_X] = gMonIcon_UnownX,
    [SPECIES_UNOWN_Y] = gMonIcon_UnownY,
    [SPECIES_UNOWN_Z] = gMonIcon_UnownZ,
    [SPECIES_UNOWN_EMARK] = gMonIcon_UnownExclamationMark,
    [SPECIES_UNOWN_QMARK] = gMonIcon_UnownQuestionMark,
    [SPECIES_CASTFORM_SUNNY] = gMonIcon_CastformSunny,
    [SPECIES_CASTFORM_RAINY] = gMonIcon_CastformRainy,
    [SPECIES_CASTFORM_SNOWY] = gMonIcon_CastformSnowy,
    [SPECIES_DEOXYS_ATTACK] = gMonIcon_DeoxysAttack,
    [SPECIES_DEOXYS_DEFENSE] = gMonIcon_DeoxysDefense,
    [SPECIES_DEOXYS_SPEED] = gMonIcon_DeoxysSpeed,
#if P_GEN_4_POKEMON == TRUE
    [SPECIES_CHERRIM_SUNSHINE] = gMonIcon_CherrimSunshine,
    [SPECIES_SHELLOS_EAST_SEA] = gMonIcon_ShellosEastSea,
    [SPECIES_GASTRODON_EAST_SEA] = gMonIcon_GastrodonEastSea,
    [SPECIES_ROTOM_HEAT] = gMonIcon_RotomHeat,
    [SPECIES_ROTOM_WASH] = gMonIcon_RotomWash,
    [SPECIES_ROTOM_FROST] = gMonIcon_RotomFrost,
    [SPECIES_ROTOM_FAN] = gMonIcon_RotomFan,
    [SPECIES_ROTOM_MOW] = gMonIcon_RotomMow,
    [SPECIES_DIALGA_ORIGIN] = gMonIcon_DialgaOrigin,
    [SPECIES_PALKIA_ORIGIN] = gMonIcon_PalkiaOrigin,
    [SPECIES_GIRATINA_ORIGIN] = gMonIcon_GiratinaOrigin,
    [SPECIES_SHAYMIN_SKY] = gMonIcon_ShayminSky,
    [SPECIES_ARCEUS_FIGHTING] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_FLYING] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_POISON] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_GROUND] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_ROCK] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_BUG] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_GHOST] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_STEEL] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_FIRE] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_WATER] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_GRASS] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_ELECTRIC] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_PSYCHIC] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_ICE] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_DRAGON] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_DARK] = gMonIcon_Arceus,
    [SPECIES_ARCEUS_FAIRY] = gMonIcon_Arceus,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_BASCULIN_BLUE_STRIPED] = gMonIcon_BasculinBlueStriped,
    [SPECIES_BASCULIN_WHITE_STRIPED] = gMonIcon_BasculinWhiteStriped,
    [SPECIES_DARMANITAN_ZEN_MODE] = gMonIcon_DarmanitanZenMode,
    [SPECIES_DARMANITAN_ZEN_MODE_GALARIAN] = gMonIcon_DarmanitanZenModeGalarian,
    [SPECIES_DEERLING_SUMMER] = gMonIcon_DeerlingSummer,
    [SPECIES_DEERLING_AUTUMN] = gMonIcon_DeerlingAutumn,
    [SPECIES_DEERLING_WINTER] = gMonIcon_DeerlingWinter,
    [SPECIES_SAWSBUCK_SUMMER] = gMonIcon_SawsbuckSummer,
    [SPECIES_SAWSBUCK_AUTUMN] = gMonIcon_SawsbuckAutumn,
    [SPECIES_SAWSBUCK_WINTER] = gMonIcon_SawsbuckWinter,
    [SPECIES_TORNADUS_THERIAN] = gMonIcon_TornadusTherian,
    [SPECIES_THUNDURUS_THERIAN] = gMonIcon_ThundurusTherian,
    [SPECIES_LANDORUS_THERIAN] = gMonIcon_LandorusTherian,
    [SPECIES_KYUREM_WHITE] = gMonIcon_KyuremWhite,
    [SPECIES_KYUREM_BLACK] = gMonIcon_KyuremBlack,
    [SPECIES_KELDEO_RESOLUTE] = gMonIcon_KeldeoResolute,
    [SPECIES_MELOETTA_PIROUETTE] = gMonIcon_MeloettaPirouette,
    [SPECIES_GENESECT_DOUSE_DRIVE] = gMonIcon_Genesect,
    [SPECIES_GENESECT_SHOCK_DRIVE] = gMonIcon_Genesect,
    [SPECIES_GENESECT_BURN_DRIVE] = gMonIcon_Genesect,
    [SPECIES_GENESECT_CHILL_DRIVE] = gMonIcon_Genesect,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_GRENINJA_BATTLE_BOND] = gMonIcon_Greninja,
    [SPECIES_GRENINJA_ASH] = gMonIcon_GreninjaAsh,
    [SPECIES_VIVILLON_POLAR] = gMonIcon_VivillonPolar,
    [SPECIES_VIVILLON_TUNDRA] = gMonIcon_VivillonTundra,
    [SPECIES_VIVILLON_CONTINENTAL] = gMonIcon_VivillonContinental,
    [SPECIES_VIVILLON_GARDEN] = gMonIcon_VivillonGarden,
    [SPECIES_VIVILLON_ELEGANT] = gMonIcon_VivillonElegant,
    [SPECIES_VIVILLON_MEADOW] = gMonIcon_VivillonMeadow,
    [SPECIES_VIVILLON_MODERN] = gMonIcon_VivillonModern,
    [SPECIES_VIVILLON_MARINE] = gMonIcon_VivillonMarine,
    [SPECIES_VIVILLON_ARCHIPELAGO] = gMonIcon_VivillonArchipelago,
    [SPECIES_VIVILLON_HIGH_PLAINS] = gMonIcon_VivillonHighPlains,
    [SPECIES_VIVILLON_SANDSTORM] = gMonIcon_VivillonSandstorm,
    [SPECIES_VIVILLON_RIVER] = gMonIcon_VivillonRiver,
    [SPECIES_VIVILLON_MONSOON] = gMonIcon_VivillonMonsoon,
    [SPECIES_VIVILLON_SAVANNA] = gMonIcon_VivillonSavanna,
    [SPECIES_VIVILLON_SUN] = gMonIcon_VivillonSun,
    [SPECIES_VIVILLON_OCEAN] = gMonIcon_VivillonOcean,
    [SPECIES_VIVILLON_JUNGLE] = gMonIcon_VivillonJungle,
    [SPECIES_VIVILLON_FANCY] = gMonIcon_VivillonFancy,
    [SPECIES_VIVILLON_POKE_BALL] = gMonIcon_VivillonPokeBall,
    [SPECIES_FLABEBE_YELLOW_FLOWER] = gMonIcon_FlabebeYellowFlower,
    [SPECIES_FLABEBE_ORANGE_FLOWER] = gMonIcon_FlabebeOrangeFlower,
    [SPECIES_FLABEBE_BLUE_FLOWER] = gMonIcon_FlabebeBlueFlower,
    [SPECIES_FLABEBE_WHITE_FLOWER] = gMonIcon_FlabebeWhiteFlower,
    [SPECIES_FLOETTE_YELLOW_FLOWER] = gMonIcon_FloetteYellowFlower,
    [SPECIES_FLOETTE_ORANGE_FLOWER] = gMonIcon_FloetteOrangeFlower,
    [SPECIES_FLOETTE_BLUE_FLOWER] = gMonIcon_FloetteBlueFlower,
    [SPECIES_FLOETTE_WHITE_FLOWER] = gMonIcon_FloetteWhiteFlower,
    [SPECIES_FLOETTE_ETERNAL_FLOWER] = gMonIcon_FloetteEternalFlower,
    [SPECIES_FLORGES_YELLOW_FLOWER] = gMonIcon_FlorgesYellowFlower,
    [SPECIES_FLORGES_ORANGE_FLOWER] = gMonIcon_FlorgesOrangeFlower,
    [SPECIES_FLORGES_BLUE_FLOWER] = gMonIcon_FlorgesBlueFlower,
    [SPECIES_FLORGES_WHITE_FLOWER] = gMonIcon_FlorgesWhiteFlower,
    [SPECIES_FURFROU_HEART_TRIM] = gMonIcon_FurfrouHeartTrim,
    [SPECIES_FURFROU_STAR_TRIM] = gMonIcon_FurfrouStarTrim,
    [SPECIES_FURFROU_DIAMOND_TRIM] = gMonIcon_FurfrouDiamondTrim,
    [SPECIES_FURFROU_DEBUTANTE_TRIM] = gMonIcon_FurfrouDebutanteTrim,
    [SPECIES_FURFROU_MATRON_TRIM] = gMonIcon_FurfrouMatronTrim,
    [SPECIES_FURFROU_DANDY_TRIM] = gMonIcon_FurfrouDandyTrim,
    [SPECIES_FURFROU_LA_REINE_TRIM] = gMonIcon_FurfrouLaReineTrim,
    [SPECIES_FURFROU_KABUKI_TRIM] = gMonIcon_FurfrouKabukiTrim,
    [SPECIES_FURFROU_PHARAOH_TRIM] = gMonIcon_FurfrouPharaohTrim,
    [SPECIES_AEGISLASH_BLADE] = gMonIcon_AegislashBlade,
    [SPECIES_PUMPKABOO_SMALL] = gMonIcon_Pumpkaboo,
    [SPECIES_PUMPKABOO_LARGE] = gMonIcon_Pumpkaboo,
    [SPECIES_PUMPKABOO_SUPER] = gMonIcon_Pumpkaboo,
    [SPECIES_GOURGEIST_SMALL] = gMonIcon_Gourgeist,
    [SPECIES_GOURGEIST_LARGE] = gMonIcon_Gourgeist,
    [SPECIES_GOURGEIST_SUPER] = gMonIcon_Gourgeist,
    [SPECIES_XERNEAS_ACTIVE] = gMonIcon_XerneasActive,
    [SPECIES_ZYGARDE_10] = gMonIcon_Zygarde10,
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = gMonIcon_Zygarde10,
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = gMonIcon_Zygarde,
    [SPECIES_ZYGARDE_COMPLETE] = gMonIcon_ZygardeComplete,
    [SPECIES_HOOPA_UNBOUND] = gMonIcon_HoopaUnbound,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ORICORIO_POM_POM] = gMonIcon_OricorioPomPom,
    [SPECIES_ORICORIO_PAU] = gMonIcon_OricorioPau,
    [SPECIES_ORICORIO_SENSU] = gMonIcon_OricorioSensu,
    [SPECIES_ROCKRUFF_OWN_TEMPO] = gMonIcon_Rockruff,
    [SPECIES_LYCANROC_MIDNIGHT] = gMonIcon_LycanrocMidnight,
    [SPECIES_LYCANROC_DUSK] = gMonIcon_LycanrocDusk,
    [SPECIES_WISHIWASHI_SCHOOL] = gMonIcon_WishiwashiSchool,
    [SPECIES_SILVALLY_FIGHTING] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_FLYING] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_POISON] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_GROUND] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_ROCK] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_BUG] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_GHOST] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_STEEL] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_FIRE] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_WATER] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_GRASS] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_ELECTRIC] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_PSYCHIC] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_ICE] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_DRAGON] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_DARK] = gMonIcon_Silvally,
    [SPECIES_SILVALLY_FAIRY] = gMonIcon_Silvally,
    [SPECIES_MINIOR_METEOR_ORANGE] = gMonIcon_Minior,
    [SPECIES_MINIOR_METEOR_YELLOW] = gMonIcon_Minior,
    [SPECIES_MINIOR_METEOR_GREEN] = gMonIcon_Minior,
    [SPECIES_MINIOR_METEOR_BLUE] = gMonIcon_Minior,
    [SPECIES_MINIOR_METEOR_INDIGO] = gMonIcon_Minior,
    [SPECIES_MINIOR_METEOR_VIOLET] = gMonIcon_Minior,
    [SPECIES_MINIOR_CORE_RED] = gMonIcon_MiniorCoreRed,
    [SPECIES_MINIOR_CORE_ORANGE] = gMonIcon_MiniorCoreOrange,
    [SPECIES_MINIOR_CORE_YELLOW] = gMonIcon_MiniorCoreYellow,
    [SPECIES_MINIOR_CORE_GREEN] = gMonIcon_MiniorCoreGreen,
    [SPECIES_MINIOR_CORE_BLUE] = gMonIcon_MiniorCoreBlue,
    [SPECIES_MINIOR_CORE_INDIGO] = gMonIcon_MiniorCoreIndigo,
    [SPECIES_MINIOR_CORE_VIOLET] = gMonIcon_MiniorCoreViolet,
    [SPECIES_MIMIKYU_BUSTED] = gMonIcon_MimikyuBusted,
    [SPECIES_NECROZMA_DUSK_MANE] = gMonIcon_NecrozmaDuskMane,
    [SPECIES_NECROZMA_DAWN_WINGS] = gMonIcon_NecrozmaDawnWings,
    [SPECIES_NECROZMA_ULTRA] = gMonIcon_NecrozmaUltra,
    [SPECIES_MAGEARNA_ORIGINAL_COLOR] = gMonIcon_MagearnaOriginalColor,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CRAMORANT_GULPING] = gMonIcon_CramorantGulping,
    [SPECIES_CRAMORANT_GORGING] = gMonIcon_CramorantGorging,
    [SPECIES_TOXTRICITY_LOW_KEY] = gMonIcon_ToxtricityLowKey,
    [SPECIES_SINISTEA_ANTIQUE] = gMonIcon_Sinistea,
    [SPECIES_POLTEAGEIST_ANTIQUE] = gMonIcon_Polteageist,
    [SPECIES_ALCREMIE_RUBY_CREAM] = gMonIcon_QuestionMark,//gMonIcon_AlcremieRubyCream,
    [SPECIES_ALCREMIE_MATCHA_CREAM] = gMonIcon_QuestionMark,//gMonIcon_AlcremieMatchaCream,
    [SPECIES_ALCREMIE_MINT_CREAM] = gMonIcon_QuestionMark,//gMonIcon_AlcremieMintCream,
    [SPECIES_ALCREMIE_LEMON_CREAM] = gMonIcon_QuestionMark,//gMonIcon_AlcremieLemonCream,
    [SPECIES_ALCREMIE_SALTED_CREAM] = gMonIcon_QuestionMark,//gMonIcon_AlcremieSaltedCream,
    [SPECIES_ALCREMIE_RUBY_SWIRL] = gMonIcon_QuestionMark,//gMonIcon_AlcremieRubySwirl,
    [SPECIES_ALCREMIE_CARAMEL_SWIRL] = gMonIcon_QuestionMark,//gMonIcon_AlcremieCaramelSwirl,
    [SPECIES_ALCREMIE_RAINBOW_SWIRL] = gMonIcon_QuestionMark,//gMonIcon_AlcremieRainbowSwirl,
    [SPECIES_EISCUE_NOICE_FACE] = gMonIcon_EiscueNoiceFace,
    [SPECIES_MORPEKO_HANGRY] = gMonIcon_MorpekoHangry,
    [SPECIES_ZACIAN_CROWNED_SWORD] = gMonIcon_ZacianCrownedSword,
    [SPECIES_ZAMAZENTA_CROWNED_SHIELD] = gMonIcon_ZamazentaCrownedShield,
    [SPECIES_ETERNATUS_ETERNAMAX] = gMonIcon_EternatusEternamax,
    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE] = gMonIcon_Urshifu,
    [SPECIES_ZARUDE_DADA] = gMonIcon_ZarudeDada,
    [SPECIES_CALYREX_ICE_RIDER] = gMonIcon_CalyrexIceRider,
    [SPECIES_CALYREX_SHADOW_RIDER] = gMonIcon_CalyrexShadowRider,
    [SPECIES_ENAMORUS_THERIAN] = gMonIcon_EnamorusTherian,
    [SPECIES_BASCULEGION_FEMALE] = gMonIcon_BasculegionFemale,
#endif
    [SPECIES_EGG] = gMonIcon_Egg,
};

const u8 gMonIconPaletteIndices[] =
{
    [SPECIES_BULBASAUR] = 4,
    [SPECIES_IVYSAUR] = 4,
    [SPECIES_VENUSAUR] = 4,
    [SPECIES_CHARMANDER] = 0,
    [SPECIES_CHARMELEON] = 0,
    [SPECIES_CHARIZARD] = 0,
    [SPECIES_SQUIRTLE] = 0,
    [SPECIES_WARTORTLE] = 2,
    [SPECIES_BLASTOISE] = 2,
    [SPECIES_RATTATA] = 2,
    [SPECIES_RATICATE] = 2,
    [SPECIES_PIKACHU] = 2,
    [SPECIES_RAICHU] = 0,
    [SPECIES_SANDSHREW] = 2,
    [SPECIES_SANDSLASH] = 2,
    [SPECIES_VULPIX] = 5,
    [SPECIES_NINETALES] = 3,
    [SPECIES_DIGLETT] = 2,
    [SPECIES_DUGTRIO] = 2,
    [SPECIES_MEOWTH] = 1,
    [SPECIES_PERSIAN] = 1,
    [SPECIES_GEODUDE] = 1,
    [SPECIES_GRAVELER] = 1,
    [SPECIES_GOLEM] = 2,
    [SPECIES_PONYTA] = 3,
    [SPECIES_RAPIDASH] = 3,
    [SPECIES_SLOWPOKE] = 0,
    [SPECIES_SLOWBRO] = 0,
    [SPECIES_FARFETCHD] = 1,
    [SPECIES_GRIMER] = 2,
    [SPECIES_MUK] = 2,
    [SPECIES_MR_MIME] = 0,
    [SPECIES_DITTO] = 2,
    [SPECIES_ARTICUNO] = 2,
    [SPECIES_ZAPDOS] = 0,
    [SPECIES_MOLTRES] = 0,
    [SPECIES_MEWTWO] = 2,
    [SPECIES_MEW] = 0,
    [SPECIES_SHUCKLE] = 1,
    [SPECIES_RAIKOU] = 2,
    [SPECIES_ENTEI] = 2,
    [SPECIES_SUICUNE] = 2,
    [SPECIES_LUGIA] = 0,
    [SPECIES_HO_OH] = 1,
    [SPECIES_CELEBI] = 1,
    [SPECIES_TREECKO] = 1,
    [SPECIES_GROVYLE] = 1,
    [SPECIES_SCEPTILE] = 1,
    [SPECIES_TORCHIC] = 0,
    [SPECIES_COMBUSKEN] = 0,
    [SPECIES_BLAZIKEN] = 0,
    [SPECIES_MUDKIP] = 0,
    [SPECIES_MARSHTOMP] = 0,
    [SPECIES_SWAMPERT] = 0,
    [SPECIES_NINCADA] = 1,
    [SPECIES_NINJASK] = 1,
    [SPECIES_SHEDINJA] = 1,
    [SPECIES_REGIROCK] = 2,
    [SPECIES_REGICE] = 0,
    [SPECIES_REGISTEEL] = 2,
    [SPECIES_KYOGRE] = 2,
    [SPECIES_GROUDON] = 0,
    [SPECIES_RAYQUAZA] = 1,
    [SPECIES_LATIAS] = 0,
    [SPECIES_LATIOS] = 0,
    [SPECIES_JIRACHI] = 0,
    [SPECIES_DEOXYS] = 0,
    [SPECIES_CHERUBI] = 1,
    [SPECIES_CHERRIM] = 0,
    [SPECIES_SHELLOS] = 0,
    [SPECIES_GASTRODON] = 0,
    [SPECIES_ROTOM] = 0,
    [SPECIES_UXIE] = 0,
    [SPECIES_MESPRIT] = 0,
    [SPECIES_AZELF] = 0,
    [SPECIES_DIALGA] = 2,
    [SPECIES_PALKIA] = 2,
    [SPECIES_HEATRAN] = 0,
    [SPECIES_REGIGIGAS] = 0,
    [SPECIES_GIRATINA] = 0,
    [SPECIES_CRESSELIA] = 0,
    [SPECIES_PHIONE] = 0,
    [SPECIES_MANAPHY] = 0,
    [SPECIES_DARKRAI] = 0,
    [SPECIES_SHAYMIN] = 1,
    [SPECIES_ARCEUS] = 1,
    [SPECIES_VICTINI] = 0,
    [SPECIES_ZORUA] = 0,
    [SPECIES_ZOROARK] = 0,
    [SPECIES_DEERLING] = 1,
    [SPECIES_SAWSBUCK] = 1,
    [SPECIES_COBALION] = 0,
    [SPECIES_TERRAKION] = 2,
    [SPECIES_VIRIZION] = 1,
    [SPECIES_TORNADUS] = 1,
    [SPECIES_THUNDURUS] = 0,
    [SPECIES_RESHIRAM] = 0,
    [SPECIES_ZEKROM] = 2,
    [SPECIES_LANDORUS] = 0,
    [SPECIES_KYUREM] = 0,
    [SPECIES_KELDEO] = 0,
    [SPECIES_MELOETTA] = 4,
    [SPECIES_GENESECT] = 2,
    [SPECIES_FROAKIE] = 0,
    [SPECIES_FROGADIER] = 0,
    [SPECIES_GRENINJA] = 0,
    [SPECIES_SCATTERBUG] = 1,
    [SPECIES_SPEWPA] = 1,
    [SPECIES_VIVILLON] = 0,
    [SPECIES_FLABEBE] = 1,
    [SPECIES_FLOETTE] = 1,
    [SPECIES_FLORGES] = 0,
    [SPECIES_FURFROU] = 0,
    [SPECIES_HONEDGE] = 2,
    [SPECIES_DOUBLADE] = 2,
    [SPECIES_AEGISLASH] = 2,
    [SPECIES_PUMPKABOO] = 2,
    [SPECIES_GOURGEIST] = 2,
    [SPECIES_BERGMITE] = 0,
    [SPECIES_AVALUGG] = 0,
    [SPECIES_XERNEAS] = 0,
    [SPECIES_YVELTAL] = 0,
    [SPECIES_ZYGARDE] = 1,
    [SPECIES_DIANCIE] = 1,
    [SPECIES_HOOPA] = 0,
    [SPECIES_VOLCANION] = 0,
    [SPECIES_ORICORIO] = 0,
    [SPECIES_ROCKRUFF] = 2,
    [SPECIES_LYCANROC] = 2,
    [SPECIES_WISHIWASHI] = 2,
    [SPECIES_TYPE_NULL] = 0,
    [SPECIES_SILVALLY] = 0,
    [SPECIES_MINIOR] = 2,
    [SPECIES_MIMIKYU] = 1,
    [SPECIES_TAPU_KOKO] = 0,
    [SPECIES_TAPU_LELE] = 0,
    [SPECIES_TAPU_BULU] = 2,
    [SPECIES_TAPU_FINI] = 0,
    [SPECIES_COSMOG] = 2,
    [SPECIES_COSMOEM] = 0,
    [SPECIES_SOLGALEO] = 0,
    [SPECIES_LUNALA] = 2,
    [SPECIES_NIHILEGO] = 0,
    [SPECIES_BUZZWOLE] = 0,
    [SPECIES_PHEROMOSA] = 2,
    [SPECIES_XURKITREE] = 0,
    [SPECIES_CELESTEELA] = 0,
    [SPECIES_KARTANA] = 0,
    [SPECIES_GUZZLORD] = 0,
    [SPECIES_NECROZMA] = 0,
    [SPECIES_MAGEARNA] = 0,
    [SPECIES_MARSHADOW] = 0,
    [SPECIES_POIPOLE] = 0,
    [SPECIES_NAGANADEL] = 0,
    [SPECIES_STAKATAKA] = 0,
    [SPECIES_BLACEPHALON] = 0,
    [SPECIES_ZERAORA] = 0,
    [SPECIES_MELTAN] = 2,
    [SPECIES_MELMETAL] = 2,
    [SPECIES_CRAMORANT] = 0,
    [SPECIES_TOXEL] = 2,
    [SPECIES_TOXTRICITY] = 2,
    [SPECIES_SINISTEA] = 2,
    [SPECIES_POLTEAGEIST] = 2,
    [SPECIES_OBSTAGOON] = 0,
    [SPECIES_PERRSERKER] = 2,
    [SPECIES_CURSOLA] = 0,
    [SPECIES_SIRFETCHD] = 1,
    [SPECIES_MR_RIME] = 0,
    [SPECIES_RUNERIGUS] = 2,
    [SPECIES_MILCERY] = 1,
    [SPECIES_ALCREMIE] = 1,
    [SPECIES_EISCUE] = 0,
    [SPECIES_MORPEKO] = 2,
    [SPECIES_ZACIAN] = 2,
    [SPECIES_ZAMAZENTA] = 2,
    [SPECIES_ETERNATUS] = 0,
    [SPECIES_KUBFU] = 1,
    [SPECIES_URSHIFU] = 2,
    [SPECIES_ZARUDE] = 1,
    [SPECIES_REGIELEKI] = 0,
    [SPECIES_REGIDRAGO] = 0,
    [SPECIES_GLASTRIER] = 0,
    [SPECIES_SPECTRIER] = 0,
    [SPECIES_CALYREX] = 0,
    [SPECIES_WYRDEER] = 2,
    [SPECIES_KLEAVOR] = 2,
    [SPECIES_URSALUNA] = 2,
    [SPECIES_BASCULEGION] = 1,
    [SPECIES_SNEASLER] = 2,
    [SPECIES_OVERQWIL] = 2,
    [SPECIES_ENAMORUS] = 1,
    [SPECIES_TIDPIT] = 1,
    [SPECIES_SLIDLOW] = 5,
    [SPECIES_CARDIOVOR] = 4,
    [SPECIES_FIEFREET] = 3,
    [SPECIES_BALBYRN] = 3,
    [SPECIES_BLAZIZAHAK] = 3,
    [SPECIES_PRONGY] = 4,
    [SPECIES_TRIDALIER] = 4,
    [SPECIES_TRITONAUT] = 3,
    [SPECIES_SNELFREND] = 0,
    [SPECIES_SYCOPLOD] = 2,
    [SPECIES_SYCOSTROM] = 2,
    [SPECIES_GUPSPAR] = 3,
    [SPECIES_VANGAR] = 3,
    [SPECIES_GHAERIAL] = 3,
    [SPECIES_MARINAROC] = 0,
    [SPECIES_METTATOLL] = 3,
    [SPECIES_ICKSQUEEK] = 5,
    [SPECIES_KOMORODE] = 5,
    [SPECIES_KYUDI] = 4,
    [SPECIES_KOMBAKYU] = 4,
    [SPECIES_FLUFFSIR] = 4,
    [SPECIES_FLUFFREAR] = 4,
    [SPECIES_SAINTISOW] = 0,
    [SPECIES_SANCTISOW] = 0,
    [SPECIES_SOWPHIROTH] = 0,
    [SPECIES_TOXEXOT] = 5,
    [SPECIES_PSEUDRA] = 5,
    [SPECIES_MANDIMYTE] = 0,
    [SPECIES_TERMINYTE] = 0,
    [SPECIES_SNOTLOUD] = 5,
    [SPECIES_SICKBEAT] = 5,
    [SPECIES_SPRYTE] = 0,
    [SPECIES_GUMONA] = 0,
    [SPECIES_NANGGAL] = 4,
    [SPECIES_SHEEDRAKE] = 4,
    [SPECIES_TRANSERA] = 2,
    [SPECIES_BIVAGUE] = 3,
    [SPECIES_LUSCKAW] = 3,
    [SPECIES_SADSOD] = 2,
    [SPECIES_MAERACHOLY] = 2,
    [SPECIES_LUMELMO] = 2,
    [SPECIES_LUMENDELA] = 2,
    [SPECIES_STOMAWAY] = 0,
    [SPECIES_CRAWLAXY] = 0,
    [SPECIES_MAGNALURE] = 0,
    [SPECIES_MAGNANICOR] = 0,
    [SPECIES_CRYPLIN] = 2,
    [SPECIES_UHEFOE] = 2,
    [SPECIES_MYSTOMANIA] = 1,
    [SPECIES_LYORESA] = 4,
    [SPECIES_KODOUGH] = 2,
    [SPECIES_SLICKSLICE] = 2,
    [SPECIES_LOAFOOF] = 2,
    [SPECIES_SPIRITOAST] = 2,
    [SPECIES_VENUSAUR_MEGA] = 4,
    [SPECIES_CHARIZARD_MEGA_X] = 0,
    [SPECIES_CHARIZARD_MEGA_Y] = 0,
    [SPECIES_BLASTOISE_MEGA] = 2,
    [SPECIES_SLOWBRO_MEGA] = 0,
    [SPECIES_MEWTWO_MEGA_X] = 2,
    [SPECIES_MEWTWO_MEGA_Y] = 2,
    [SPECIES_SCEPTILE_MEGA] = 1,
    [SPECIES_BLAZIKEN_MEGA] = 0,
    [SPECIES_SWAMPERT_MEGA] = 0,
    [SPECIES_LATIAS_MEGA] = 2,
    [SPECIES_LATIOS_MEGA] = 2,
    [SPECIES_KYOGRE_PRIMAL] = 0,
    [SPECIES_GROUDON_PRIMAL] = 0,
    [SPECIES_RAYQUAZA_MEGA] = 1,
    [SPECIES_RATTATA_ALOLAN] = 2,
    [SPECIES_RATICATE_ALOLAN] = 2,
    [SPECIES_RAICHU_ALOLAN] = 2,
    [SPECIES_SANDSHREW_ALOLAN] = 0,
    [SPECIES_SANDSLASH_ALOLAN] = 0,
    [SPECIES_VULPIX_ALOLAN] = 2,
    [SPECIES_NINETALES_ALOLAN] = 2,
    [SPECIES_DIGLETT_ALOLAN] = 2,
    [SPECIES_DUGTRIO_ALOLAN] = 2,
    [SPECIES_MEOWTH_ALOLAN] = 2,
    [SPECIES_PERSIAN_ALOLAN] = 2,
    [SPECIES_GEODUDE_ALOLAN] = 2,
    [SPECIES_GRAVELER_ALOLAN] = 2,
    [SPECIES_GOLEM_ALOLAN] = 2,
    [SPECIES_GRIMER_ALOLAN] = 1,
    [SPECIES_MUK_ALOLAN] = 0,
    [SPECIES_MEOWTH_GALARIAN] = 0,
    [SPECIES_PONYTA_GALARIAN] = 2,
    [SPECIES_RAPIDASH_GALARIAN] = 2,
    [SPECIES_SLOWPOKE_GALARIAN] = 1,
    [SPECIES_SLOWBRO_GALARIAN] = 0,
    [SPECIES_FARFETCHD_GALARIAN] = 1,
    [SPECIES_MR_MIME_GALARIAN] = 0,
    [SPECIES_ARTICUNO_GALARIAN] = 2,
    [SPECIES_ZAPDOS_GALARIAN] = 0,
    [SPECIES_MOLTRES_GALARIAN] = 0,
    [SPECIES_CORSOLA_GALARIAN] = 0,
    [SPECIES_ZIGZAGOON_GALARIAN] = 0,
    [SPECIES_LINOONE_GALARIAN] = 0,
    [SPECIES_DARUMAKA_GALARIAN] = 0,
    [SPECIES_DARMANITAN_GALARIAN] = 0,
    [SPECIES_YAMASK_GALARIAN] = 2,
    [SPECIES_STUNFISK_GALARIAN] = 1,
    [SPECIES_ZORUA_HISUIAN] = 0,
    [SPECIES_ZOROARK_HISUIAN] = 0,
    [SPECIES_AVALUGG_HISUIAN] = 5,
    [SPECIES_PIKACHU_COSPLAY] = 2,
    [SPECIES_PIKACHU_ROCK_STAR] = 1,
    [SPECIES_PIKACHU_BELLE] = 0,
    [SPECIES_PIKACHU_POP_STAR] = 0,
    [SPECIES_PIKACHU_PH_D] = 1,
    [SPECIES_PIKACHU_LIBRE] = 0,
    [SPECIES_PIKACHU_ORIGINAL_CAP] = 0,
    [SPECIES_PIKACHU_HOENN_CAP] = 0,
    [SPECIES_PIKACHU_SINNOH_CAP] = 0,
    [SPECIES_PIKACHU_UNOVA_CAP] = 0,
    [SPECIES_PIKACHU_KALOS_CAP] = 0,
    [SPECIES_PIKACHU_ALOLA_CAP] = 0,
    [SPECIES_PIKACHU_PARTNER_CAP] = 0,
    [SPECIES_PIKACHU_WORLD_CAP] = 0,
    [SPECIES_PICHU_SPIKY_EARED] = 1,
    [SPECIES_UNOWN_B ... SPECIES_UNOWN_QMARK] = 0,
    [SPECIES_CASTFORM_SUNNY] = 0,
    [SPECIES_CASTFORM_RAINY] = 0,
    [SPECIES_CASTFORM_SNOWY] = 0,
    [SPECIES_DEOXYS_ATTACK] = 0,
    [SPECIES_DEOXYS_DEFENSE] = 0,
    [SPECIES_DEOXYS_SPEED] = 0,
#if P_GEN_4_POKEMON == TRUE
    [SPECIES_CHERRIM_SUNSHINE] = 1,
    [SPECIES_SHELLOS_EAST_SEA] = 0,
    [SPECIES_GASTRODON_EAST_SEA] = 0,
    [SPECIES_ROTOM_HEAT] = 0,
    [SPECIES_ROTOM_WASH] = 0,
    [SPECIES_ROTOM_FROST] = 5,
    [SPECIES_ROTOM_FAN] = 0,
    [SPECIES_ROTOM_MOW] = 0,
    [SPECIES_DIALGA_ORIGIN] = 0,
    [SPECIES_PALKIA_ORIGIN] = 2,
    [SPECIES_GIRATINA_ORIGIN] = 0,
    [SPECIES_SHAYMIN_SKY] = 1,
    [SPECIES_ARCEUS_FIGHTING] = 1,
    [SPECIES_ARCEUS_FLYING] = 1,
    [SPECIES_ARCEUS_POISON] = 1,
    [SPECIES_ARCEUS_GROUND] = 1,
    [SPECIES_ARCEUS_ROCK] = 1,
    [SPECIES_ARCEUS_BUG] = 1,
    [SPECIES_ARCEUS_GHOST] = 1,
    [SPECIES_ARCEUS_STEEL] = 1,
    [SPECIES_ARCEUS_FIRE] = 1,
    [SPECIES_ARCEUS_WATER] = 1,
    [SPECIES_ARCEUS_GRASS] = 1,
    [SPECIES_ARCEUS_ELECTRIC] = 1,
    [SPECIES_ARCEUS_PSYCHIC] = 1,
    [SPECIES_ARCEUS_ICE] = 1,
    [SPECIES_ARCEUS_DRAGON] = 1,
    [SPECIES_ARCEUS_DARK] = 1,
    [SPECIES_ARCEUS_FAIRY] = 1,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_BASCULIN_BLUE_STRIPED] = 0,
    [SPECIES_BASCULIN_WHITE_STRIPED] = 0,
    [SPECIES_DARMANITAN_ZEN_MODE] = 0,
    [SPECIES_DARMANITAN_ZEN_MODE_GALARIAN] = 0,
    [SPECIES_DEERLING_SUMMER] = 1,
    [SPECIES_DEERLING_AUTUMN] = 0,
    [SPECIES_DEERLING_WINTER] = 2,
    [SPECIES_SAWSBUCK_SUMMER] = 1,
    [SPECIES_SAWSBUCK_AUTUMN] = 1,
    [SPECIES_SAWSBUCK_WINTER] = 1,
    [SPECIES_TORNADUS_THERIAN] = 1,
    [SPECIES_THUNDURUS_THERIAN] = 0,
    [SPECIES_LANDORUS_THERIAN] = 0,
    [SPECIES_KYUREM_WHITE] = 0,
    [SPECIES_KYUREM_BLACK] = 0,
    [SPECIES_KELDEO_RESOLUTE] = 0,
    [SPECIES_MELOETTA_PIROUETTE] = 0,
    [SPECIES_GENESECT_DOUSE_DRIVE] = 2,
    [SPECIES_GENESECT_SHOCK_DRIVE] = 2,
    [SPECIES_GENESECT_BURN_DRIVE] = 2,
    [SPECIES_GENESECT_CHILL_DRIVE] = 2,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_GRENINJA_BATTLE_BOND] = 0,
    [SPECIES_GRENINJA_ASH] = 0,
    [SPECIES_VIVILLON_POLAR] = 0,
    [SPECIES_VIVILLON_TUNDRA] = 0,
    [SPECIES_VIVILLON_CONTINENTAL] = 2,
    [SPECIES_VIVILLON_GARDEN] = 1,
    [SPECIES_VIVILLON_ELEGANT] = 0,
    [SPECIES_VIVILLON_MEADOW] = 0,
    [SPECIES_VIVILLON_MODERN] = 2,
    [SPECIES_VIVILLON_MARINE] = 0,
    [SPECIES_VIVILLON_ARCHIPELAGO] = 0,
    [SPECIES_VIVILLON_HIGH_PLAINS] = 0,
    [SPECIES_VIVILLON_SANDSTORM] = 1,
    [SPECIES_VIVILLON_RIVER] = 2,
    [SPECIES_VIVILLON_MONSOON] = 0,
    [SPECIES_VIVILLON_SAVANNA] = 0,
    [SPECIES_VIVILLON_SUN] = 0,
    [SPECIES_VIVILLON_OCEAN] = 0,
    [SPECIES_VIVILLON_JUNGLE] = 0,
    [SPECIES_VIVILLON_FANCY] = 1,
    [SPECIES_VIVILLON_POKE_BALL] = 2,
    [SPECIES_FLABEBE_YELLOW_FLOWER] = 1,
    [SPECIES_FLABEBE_ORANGE_FLOWER] = 0,
    [SPECIES_FLABEBE_BLUE_FLOWER] = 0,
    [SPECIES_FLABEBE_WHITE_FLOWER] = 1,
    [SPECIES_FLOETTE_YELLOW_FLOWER] = 1,
    [SPECIES_FLOETTE_ORANGE_FLOWER] = 0,
    [SPECIES_FLOETTE_BLUE_FLOWER] = 0,
    [SPECIES_FLOETTE_WHITE_FLOWER] = 1,
    [SPECIES_FLOETTE_ETERNAL_FLOWER] = 0,
    [SPECIES_FLORGES_YELLOW_FLOWER] = 1,
    [SPECIES_FLORGES_ORANGE_FLOWER] = 0,
    [SPECIES_FLORGES_BLUE_FLOWER] = 0,
    [SPECIES_FLORGES_WHITE_FLOWER] = 0,
    [SPECIES_FURFROU_HEART_TRIM] = 0,
    [SPECIES_FURFROU_STAR_TRIM] = 0,
    [SPECIES_FURFROU_DIAMOND_TRIM] = 0,
    [SPECIES_FURFROU_DEBUTANTE_TRIM] = 2,
    [SPECIES_FURFROU_MATRON_TRIM] = 2,
    [SPECIES_FURFROU_DANDY_TRIM] = 1,
    [SPECIES_FURFROU_LA_REINE_TRIM] = 0,
    [SPECIES_FURFROU_KABUKI_TRIM] = 0,
    [SPECIES_FURFROU_PHARAOH_TRIM] = 0,
    [SPECIES_AEGISLASH_BLADE] = 2,
    [SPECIES_PUMPKABOO_SMALL] = 2,
    [SPECIES_PUMPKABOO_LARGE] = 2,
    [SPECIES_PUMPKABOO_SUPER] = 2,
    [SPECIES_GOURGEIST_SMALL] = 2,
    [SPECIES_GOURGEIST_LARGE] = 2,
    [SPECIES_GOURGEIST_SUPER] = 2,
    [SPECIES_XERNEAS_ACTIVE] = 0,
    [SPECIES_ZYGARDE_10] = 1,
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = 1,
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = 1,
    [SPECIES_ZYGARDE_COMPLETE] = 1,
    [SPECIES_HOOPA_UNBOUND] = 0,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ORICORIO_POM_POM] = 1,
    [SPECIES_ORICORIO_PAU] = 1,
    [SPECIES_ORICORIO_SENSU] = 0,
    [SPECIES_ROCKRUFF_OWN_TEMPO] = 2,
    [SPECIES_LYCANROC_MIDNIGHT] = 0,
    [SPECIES_LYCANROC_DUSK] = 0,
    [SPECIES_WISHIWASHI_SCHOOL] = 0,
    [SPECIES_SILVALLY_FIGHTING] = 0,
    [SPECIES_SILVALLY_FLYING] = 0,
    [SPECIES_SILVALLY_POISON] = 0,
    [SPECIES_SILVALLY_GROUND] = 0,
    [SPECIES_SILVALLY_ROCK] = 0,
    [SPECIES_SILVALLY_BUG] = 0,
    [SPECIES_SILVALLY_GHOST] = 0,
    [SPECIES_SILVALLY_STEEL] = 0,
    [SPECIES_SILVALLY_FIRE] = 0,
    [SPECIES_SILVALLY_WATER] = 0,
    [SPECIES_SILVALLY_GRASS] = 0,
    [SPECIES_SILVALLY_ELECTRIC] = 0,
    [SPECIES_SILVALLY_PSYCHIC] = 0,
    [SPECIES_SILVALLY_ICE] = 0,
    [SPECIES_SILVALLY_DRAGON] = 0,
    [SPECIES_SILVALLY_DARK] = 0,
    [SPECIES_SILVALLY_FAIRY] = 0,
    [SPECIES_MINIOR_CORE_RED] = 0,
    [SPECIES_MINIOR_CORE_ORANGE] = 0,
    [SPECIES_MINIOR_CORE_YELLOW] = 0,
    [SPECIES_MINIOR_CORE_GREEN] = 1,
    [SPECIES_MINIOR_CORE_BLUE] = 0,
    [SPECIES_MINIOR_CORE_INDIGO] = 0,
    [SPECIES_MINIOR_CORE_VIOLET] = 2,
    [SPECIES_MIMIKYU_BUSTED] = 1,
    [SPECIES_NECROZMA_DUSK_MANE] = 0,
    [SPECIES_NECROZMA_DAWN_WINGS] = 0,
    [SPECIES_NECROZMA_ULTRA] = 2,
    [SPECIES_MAGEARNA_ORIGINAL_COLOR] = 0,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CRAMORANT_GULPING] = 0,
    [SPECIES_CRAMORANT_GORGING] = 0,
    [SPECIES_TOXTRICITY_LOW_KEY] = 2,
    [SPECIES_SINISTEA_ANTIQUE] = 2,
    [SPECIES_POLTEAGEIST_ANTIQUE] = 2,
    [SPECIES_ALCREMIE_RUBY_CREAM] = 0,
    [SPECIES_ALCREMIE_MATCHA_CREAM] = 0,
    [SPECIES_ALCREMIE_MINT_CREAM] = 0,
    [SPECIES_ALCREMIE_LEMON_CREAM] = 0,
    [SPECIES_ALCREMIE_SALTED_CREAM] = 0,
    [SPECIES_ALCREMIE_RUBY_SWIRL] = 0,
    [SPECIES_ALCREMIE_CARAMEL_SWIRL] = 0,
    [SPECIES_ALCREMIE_RAINBOW_SWIRL] = 0,
    [SPECIES_EISCUE_NOICE_FACE] = 0,
    [SPECIES_MORPEKO_HANGRY] = 2,
    [SPECIES_ZACIAN_CROWNED_SWORD] = 2,
    [SPECIES_ZAMAZENTA_CROWNED_SHIELD] = 2,
    [SPECIES_ETERNATUS_ETERNAMAX] = 0,
    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE] = 2,
    [SPECIES_ZARUDE_DADA] = 1,
    [SPECIES_CALYREX_ICE_RIDER] = 0,
    [SPECIES_CALYREX_SHADOW_RIDER] = 0,
    [SPECIES_ENAMORUS_THERIAN] = 1,
    [SPECIES_BASCULEGION_FEMALE] = 0,
#endif
    [SPECIES_EGG] = 1,
};

const struct SpritePalette gMonIconPaletteTable[6] =
{
    { gMonIconPalettes[0], POKE_ICON_BASE_PAL_TAG + 0 },
    { gMonIconPalettes[1], POKE_ICON_BASE_PAL_TAG + 1 },
    { gMonIconPalettes[2], POKE_ICON_BASE_PAL_TAG + 2 },
    { gMonIconPalettes[3], POKE_ICON_BASE_PAL_TAG + 3 },
    { gMonIconPalettes[4], POKE_ICON_BASE_PAL_TAG + 4 },
    { gMonIconPalettes[5], POKE_ICON_BASE_PAL_TAG + 5 },
};

static const struct OamData sMonIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

// fastest to slowest

static const union AnimCmd sAnim_0[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_2[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_3[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sAnim_4[] =
{
    ANIMCMD_FRAME(0, 29),
    ANIMCMD_FRAME(0, 29), // frame 0 is repeated
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sMonIconAnims[] =
{
    sAnim_0,
    sAnim_1,
    sAnim_2,
    sAnim_3,
    sAnim_4,
};

static const union AffineAnimCmd sAffineAnim_0[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 0, 10),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd sAffineAnim_1[] =
{
    AFFINEANIMCMD_FRAME(-2, -2, 0, 122),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sMonIconAffineAnims[] =
{
    sAffineAnim_0,
    sAffineAnim_1,
};

static const u16 sSpriteImageSizes[3][4] =
{
    [ST_OAM_SQUARE] =
    {
        [SPRITE_SIZE(8x8)]   =  8 * 8  / 2,
        [SPRITE_SIZE(16x16)] = 16 * 16 / 2,
        [SPRITE_SIZE(32x32)] = 32 * 32 / 2,
        [SPRITE_SIZE(64x64)] = 64 * 64 / 2,
    },
    [ST_OAM_H_RECTANGLE] =
    {
        [SPRITE_SIZE(16x8)]  = 16 * 8  / 2,
        [SPRITE_SIZE(32x8)]  = 32 * 8  / 2,
        [SPRITE_SIZE(32x16)] = 32 * 16 / 2,
        [SPRITE_SIZE(64x32)] = 64 * 32 / 2,
    },
    [ST_OAM_V_RECTANGLE] =
    {
        [SPRITE_SIZE(8x16)]  =  8 * 16 / 2,
        [SPRITE_SIZE(8x32)]  =  8 * 32 / 2,
        [SPRITE_SIZE(16x32)] = 16 * 32 / 2,
        [SPRITE_SIZE(32x64)] = 32 * 64 / 2,
    },
};

u8 CreateMonIcon(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority, u32 personality)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = GetMonIconPtr(species, personality),
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    if (species > NUM_SPECIES)
        iconTemplate.paletteTag = POKE_ICON_BASE_PAL_TAG;

    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}


u8 CreateMonIconNoPersonality(u16 species, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;
    struct MonIconSpriteTemplate iconTemplate =
    {
        .oam = &sMonIconOamData,
        .image = NULL,
        .anims = sMonIconAnims,
        .affineAnims = sMonIconAffineAnims,
        .callback = callback,
        .paletteTag = POKE_ICON_BASE_PAL_TAG + gMonIconPaletteIndices[species],
    };

    iconTemplate.image = GetMonIconTiles(species, 0);
    spriteId = CreateMonIconSprite(&iconTemplate, x, y, subpriority);

    UpdateMonIconFrame(&gSprites[spriteId]);

    return spriteId;
}

u16 GetIconSpecies(u16 species, u32 personality)
{
    u16 result;

    if (species > NUM_SPECIES)
        result = INVALID_ICON_SPECIES;
    else
        result = species;
    

    return result;
}

u16 GetUnownLetterByPersonality(u32 personality)
{
    if (!personality)
        return 0;
    else
        return GET_UNOWN_LETTER(personality);
}

u16 GetIconSpeciesNoPersonality(u16 species)
{
    u16 value;

    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;

    return GetIconSpecies(species, 0);
    
}

const u8 *GetMonIconPtr(u16 species, u32 personality)
{
    return GetMonIconTiles(GetIconSpecies(species, personality), personality);
}

void FreeAndDestroyMonIconSprite(struct Sprite *sprite)
{
    FreeAndDestroyMonIconSprite_(sprite);
}

void LoadMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        LoadSpritePalette(&gMonIconPaletteTable[i]);
}

// unused
void SafeLoadMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalette(u16 species)
{
    u8 palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void LoadMonIconPalettePersonality(u16 species, u32 personality)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    if (IndexOfSpritePaletteTag(gMonIconPaletteTable[palIndex].tag) == 0xFF)
        LoadSpritePalette(&gMonIconPaletteTable[palIndex]);
}

void FreeMonIconPalettes(void)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(gMonIconPaletteTable); i++)
        FreeSpritePaletteByTag(gMonIconPaletteTable[i].tag);
}

// unused
void SafeFreeMonIconPalette(u16 species)
{
    u8 palIndex;
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void FreeMonIconPalette(u16 species)
{
    u8 palIndex;
    palIndex = gMonIconPaletteIndices[species];
    FreeSpritePaletteByTag(gMonIconPaletteTable[palIndex].tag);
}

void SpriteCB_MonIcon(struct Sprite *sprite)
{
    UpdateMonIconFrame(sprite);
}

const u8 *GetMonIconTiles(u16 species, u32 personality)
{
    const u8 *iconSprite;

    if (species > NUM_SPECIES)
        species = SPECIES_NONE;

    if (gMonIconTable[species] != NULL)
        iconSprite = gMonIconTable[species];
    else
        iconSprite = gMonIconTable[SPECIES_NONE];

    return iconSprite;
}

void TryLoadAllMonIconPalettesAtOffset(u16 offset)
{
    s32 i;
    if (offset <= BG_PLTT_ID(16 - ARRAY_COUNT(gMonIconPaletteTable)))
    {
        for (i = 0; i < (int)ARRAY_COUNT(gMonIconPaletteTable); i++)
        {
            LoadPalette(gMonIconPaletteTable[i].data, offset, PLTT_SIZE_4BPP);
            offset += 16;
        }
    }
}

u8 GetValidMonIconPalIndex(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteIndices[species];
}

u8 GetMonIconPaletteIndexFromSpecies(u16 species)
{
    return gMonIconPaletteIndices[species];
}

const u16 *GetValidMonIconPalettePtr(u16 species)
{
    if (species > NUM_SPECIES)
        species = INVALID_ICON_SPECIES;
    return gMonIconPaletteTable[gMonIconPaletteIndices[species]].data;
}

u8 UpdateMonIconFrame(struct Sprite *sprite)
{
    u8 result = 0;

    if (sprite->animDelayCounter == 0)
    {
        s16 frame = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.imageValue;

        switch (frame)
        {
        case -1:
            break;
        case -2:
            sprite->animCmdIndex = 0;
            break;
        default:
            RequestSpriteCopy(
                // pointer arithmetic is needed to get the correct pointer to perform the sprite copy on.
                // because sprite->images is a struct def, it has to be casted to (u8 *) before any
                // arithmetic can be performed.
                (u8 *)sprite->images + (sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] * frame),
                (u8 *)(OBJ_VRAM0 + sprite->oam.tileNum * TILE_SIZE_4BPP),
                sSpriteImageSizes[sprite->oam.shape][sprite->oam.size]);
            sprite->animDelayCounter = sprite->anims[sprite->animNum][sprite->animCmdIndex].frame.duration & 0xFF;
            sprite->animCmdIndex++;
            result = sprite->animCmdIndex;
            break;
        }
    }
    else
    {
        sprite->animDelayCounter--;
    }
    return result;
}

static u8 CreateMonIconSprite(struct MonIconSpriteTemplate *iconTemplate, s16 x, s16 y, u8 subpriority)
{
    u8 spriteId;

    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[iconTemplate->oam->shape][iconTemplate->oam->size] };

    struct SpriteTemplate spriteTemplate =
    {
        .tileTag = TAG_NONE,
        .paletteTag = iconTemplate->paletteTag,
        .oam = iconTemplate->oam,
        .anims = iconTemplate->anims,
        .images = &image,
        .affineAnims = iconTemplate->affineAnims,
        .callback = iconTemplate->callback,
    };

    spriteId = CreateSprite(&spriteTemplate, x, y, subpriority);
    gSprites[spriteId].animPaused = TRUE;
    gSprites[spriteId].animBeginning = FALSE;
    gSprites[spriteId].images = (const struct SpriteFrameImage *)iconTemplate->image;
    return spriteId;
}

static void FreeAndDestroyMonIconSprite_(struct Sprite *sprite)
{
    struct SpriteFrameImage image = { NULL, sSpriteImageSizes[sprite->oam.shape][sprite->oam.size] };
    sprite->images = &image;
    DestroySprite(sprite);
}

void SetPartyHPBarSprite(struct Sprite *sprite, u8 animNum)
{
    sprite->animNum = animNum;
    sprite->animDelayCounter = 0;
    sprite->animCmdIndex = 0;
}
