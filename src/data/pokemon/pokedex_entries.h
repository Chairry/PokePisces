const struct PokedexEntry gPokedexEntries[] =
{
    [NATIONAL_DEX_NONE] =
    {
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = gDummyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BULBASAUR] =
    {
        .categoryName = _("Seed"),
        .height = 7,
        .weight = 69,
        .description = gBulbasaurPokedexText,
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_IVYSAUR] =
    {
        .categoryName = _("Seed"),
        .height = 10,
        .weight = 130,
        .description = gIvysaurPokedexText,
        .pokemonScale = 335,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VENUSAUR] =
    {
        .categoryName = _("Seed"),
        .height = 20,
        .weight = 1000,
        .description = gVenusaurPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_CHARMANDER] =
    {
        .categoryName = _("Lizard"),
        .height = 6,
        .weight = 85,
        .description = gCharmanderPokedexText,
        .pokemonScale = 444,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHARMELEON] =
    {
        .categoryName = _("Flame"),
        .height = 11,
        .weight = 190,
        .description = gCharmeleonPokedexText,
        .pokemonScale = 302,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHARIZARD] =
    {
        .categoryName = _("Flame"),
        .height = 17,
        .weight = 905,
        .description = gCharizardPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_SQUIRTLE] =
    {
        .categoryName = _("Tiny Turtle"),
        .height = 5,
        .weight = 90,
        .description = gSquirtlePokedexText,
        .pokemonScale = 412,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WARTORTLE] =
    {
        .categoryName = _("Turtle"),
        .height = 10,
        .weight = 225,
        .description = gWartortlePokedexText,
        .pokemonScale = 332,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BLASTOISE] =
    {
        .categoryName = _("Shellfish"),
        .height = 16,
        .weight = 855,
        .description = gBlastoisePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

   
    [NATIONAL_DEX_RATTATA] =
    {
        .categoryName = _("Mouse"),
        .height = 3,
        .weight = 35,
        .description = gRattataPokedexText,
        .pokemonScale = 481,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RATICATE] =
    {
        .categoryName = _("Mouse"),
        .height = 7,
        .weight = 185,
        .description = gRaticatePokedexText,
        .pokemonScale = 459,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },
    [NATIONAL_DEX_PIKACHU] =
    {
        .categoryName = _("Mouse"),
        .height = 4,
        .weight = 60,
        .description = gPikachuPokedexText,
        .pokemonScale = 479,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RAICHU] =
    {
        .categoryName = _("Mouse"),
        .height = 8,
        .weight = 300,
        .description = gRaichuPokedexText,
        .pokemonScale = 426,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SANDSHREW] =
    {
        .categoryName = _("Mouse"),
        .height = 6,
        .weight = 120,
        .description = gSandshrewPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SANDSLASH] =
    {
        .categoryName = _("Mouse"),
        .height = 10,
        .weight = 295,
        .description = gSandslashPokedexText,
        .pokemonScale = 341,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VULPIX] =
    {
        .categoryName = _("Fox"),
        .height = 6,
        .weight = 99,
        .description = gVulpixPokedexText,
        .pokemonScale = 542,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NINETALES] =
    {
        .categoryName = _("Fox"),
        .height = 11,
        .weight = 199,
        .description = gNinetalesPokedexText,
        .pokemonScale = 339,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DIGLETT] =
    {
        .categoryName = _("Mole"),
        .height = 2,
        .weight = 8,
        .description = gDiglettPokedexText,
        .pokemonScale = 833,
        .pokemonOffset = 25,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DUGTRIO] =
    {
        .categoryName = _("Mole"),
        .height = 7,
        .weight = 333,
        .description = gDugtrioPokedexText,
        .pokemonScale = 406,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MEOWTH] =
    {
        .categoryName = _("Scratch Cat"),
        .height = 4,
        .weight = 42,
        .description = gMeowthPokedexText,
        .pokemonScale = 480,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PERSIAN] =
    {
        .categoryName = _("Classy Cat"),
        .height = 10,
        .weight = 320,
        .description = gPersianPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },


    [NATIONAL_DEX_GEODUDE] =
    {
        .categoryName = _("Rock"),
        .height = 4,
        .weight = 200,
        .description = gGeodudePokedexText,
        .pokemonScale = 347,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GRAVELER] =
    {
        .categoryName = _("Rock"),
        .height = 10,
        .weight = 1050,
        .description = gGravelerPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOLEM] =
    {
        .categoryName = _("Megaton"),
        .height = 14,
        .weight = 3000,
        .description = gGolemPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_PONYTA] =
    {
        .categoryName = _("Fire Horse"),
        .height = 10,
        .weight = 300,
        .description = gPonytaPokedexText,
        .pokemonScale = 283,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RAPIDASH] =
    {
        .categoryName = _("Fire Horse"),
        .height = 17,
        .weight = 950,
        .description = gRapidashPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 289,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SLOWPOKE] =
    {
        .categoryName = _("Dopey"),
        .height = 12,
        .weight = 360,
        .description = gSlowpokePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLOWBRO] =
    {
        .categoryName = _("Hermit Crab"),
        .height = 16,
        .weight = 785,
        .description = gSlowbroPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 296,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_FARFETCHD] =
    {
        .categoryName = _("Wild Duck"),
        .height = 8,
        .weight = 150,
        .description = gFarfetchdPokedexText,
        .pokemonScale = 330,
        .pokemonOffset = 2,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_GRIMER] =
    {
        .categoryName = _("Sludge"),
        .height = 9,
        .weight = 300,
        .description = gGrimerPokedexText,
        .pokemonScale = 258,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MUK] =
    {
        .categoryName = _("Sludge"),
        .height = 12,
        .weight = 300,
        .description = gMukPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MR_MIME] =
    {
        .categoryName = _("Barrier"),
        .height = 13,
        .weight = 545,
        .description = gMrMimePokedexText,
        .pokemonScale = 258,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DITTO] =
    {
        .categoryName = _("Transform"),
        .height = 3,
        .weight = 40,
        .description = gDittoPokedexText,
        .pokemonScale = 633,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARTICUNO] =
    {
        .categoryName = _("Freeze"),
        .height = 17,
        .weight = 554,
        .description = gArticunoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_ZAPDOS] =
    {
        .categoryName = _("Electric"),
        .height = 16,
        .weight = 526,
        .description = gZapdosPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 318,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_MOLTRES] =
    {
        .categoryName = _("Flame"),
        .height = 20,
        .weight = 600,
        .description = gMoltresPokedexText,
        .pokemonScale = 270,
        .pokemonOffset = 0,
        .trainerScale = 387,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_MEWTWO] =
    {
        .categoryName = _("Genetic"),
        .height = 20,
        .weight = 1220,
        .description = gMewtwoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 309,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MEW] =
    {
        .categoryName = _("New Species"),
        .height = 4,
        .weight = 40,
        .description = gMewPokedexText,
        .pokemonScale = 457,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHUCKLE] =
    {
        .categoryName = _("Mold"),
        .height = 6,
        .weight = 205,
        .description = gShucklePokedexText,
        .pokemonScale = 485,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RAIKOU] =
    {
        .categoryName = _("Thunder"),
        .height = 19,
        .weight = 1780,
        .description = gRaikouPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_ENTEI] =
    {
        .categoryName = _("Volcano"),
        .height = 21,
        .weight = 1980,
        .description = gEnteiPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_SUICUNE] =
    {
        .categoryName = _("Aurora"),
        .height = 20,
        .weight = 1870,
        .description = gSuicunePokedexText,
        .pokemonScale = 269,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_LUGIA] =
    {
        .categoryName = _("Diving"),
        .height = 52,
        .weight = 2160,
        .description = gLugiaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
    },

    [NATIONAL_DEX_HO_OH] =
    {
        .categoryName = _("Rainbow"),
        .height = 38,
        .weight = 1990,
        .description = gHoOhPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
    },

    [NATIONAL_DEX_CELEBI] =
    {
        .categoryName = _("Time Travel"),
        .height = 6,
        .weight = 50,
        .description = gCelebiPokedexText,
        .pokemonScale = 393,
        .pokemonOffset = -10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TREECKO] =
    {
        .categoryName = _("Wood Gecko"),
        .height = 5,
        .weight = 50,
        .description = gTreeckoPokedexText,
        .pokemonScale = 541,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GROVYLE] =
    {
        .categoryName = _("Wood Gecko"),
        .height = 9,
        .weight = 216,
        .description = gGrovylePokedexText,
        .pokemonScale = 360,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SCEPTILE] =
    {
        .categoryName = _("Forest"),
        .height = 17,
        .weight = 522,
        .description = gSceptilePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 275,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_TORCHIC] =
    {
        .categoryName = _("Chick"),
        .height = 4,
        .weight = 25,
        .description = gTorchicPokedexText,
        .pokemonScale = 566,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_COMBUSKEN] =
    {
        .categoryName = _("Young Fowl"),
        .height = 9,
        .weight = 195,
        .description = gCombuskenPokedexText,
        .pokemonScale = 343,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BLAZIKEN] =
    {
        .categoryName = _("Blaze"),
        .height = 19,
        .weight = 520,
        .description = gBlazikenPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_MUDKIP] =
    {
        .categoryName = _("Mud Fish"),
        .height = 4,
        .weight = 76,
        .description = gMudkipPokedexText,
        .pokemonScale = 535,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MARSHTOMP] =
    {
        .categoryName = _("Mud Fish"),
        .height = 7,
        .weight = 280,
        .description = gMarshtompPokedexText,
        .pokemonScale = 340,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SWAMPERT] =
    {
        .categoryName = _("Mud Fish"),
        .height = 15,
        .weight = 819,
        .description = gSwampertPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NINCADA] =
    {
        .categoryName = _("Trainee"),
        .height = 5,
        .weight = 55,
        .description = gNincadaPokedexText,
        .pokemonScale = 405,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NINJASK] =
    {
        .categoryName = _("Ninja"),
        .height = 8,
        .weight = 120,
        .description = gNinjaskPokedexText,
        .pokemonScale = 383,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHEDINJA] =
    {
        .categoryName = _("Shed"),
        .height = 8,
        .weight = 12,
        .description = gShedinjaPokedexText,
        .pokemonScale = 372,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_REGIROCK] =
    {
        .categoryName = _("Rock Peak"),
        .height = 17,
        .weight = 2300,
        .description = gRegirockPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 309,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_REGICE] =
    {
        .categoryName = _("Iceberg"),
        .height = 18,
        .weight = 1750,
        .description = gRegicePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_REGISTEEL] =
    {
        .categoryName = _("Iron"),
        .height = 19,
        .weight = 2050,
        .description = gRegisteelPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 359,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_LATIAS] =
    {
        .categoryName = _("Eon"),
        .height = 14,
        .weight = 400,
        .description = gLatiasPokedexText,
        .pokemonScale = 304,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LATIOS] =
    {
        .categoryName = _("Eon"),
        .height = 20,
        .weight = 600,
        .description = gLatiosPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 294,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_KYOGRE] =
    {
        .categoryName = _("Sea Basin"),
        .height = 45,
        .weight = 3520,
        .description = gKyogrePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 614,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_GROUDON] =
    {
        .categoryName = _("Continent"),
        .height = 35,
        .weight = 9500,
        .description = gGroudonPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 515,
        .trainerOffset = 14,
    },

    [NATIONAL_DEX_RAYQUAZA] =
    {
        .categoryName = _("Sky High"),
        .height = 70,
        .weight = 2065,
        .description = gRayquazaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 448,
        .trainerOffset = 12,
    },

    [NATIONAL_DEX_JIRACHI] =
    {
        .categoryName = _("Wish"),
        .height = 3,
        .weight = 11,
        .description = gJirachiPokedexText,
        .pokemonScale = 608,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DEOXYS] =
    {
        .categoryName = _("DNA"),
        .height = 17,
        .weight = 608,
        .description = gDeoxysPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
    },

#if P_GEN_4_POKEMON == TRUE
    
    [NATIONAL_DEX_CHERUBI] =
    {
        .categoryName = _("Cherry"),
        .height = 4,
        .weight = 33,
        .description = gCherubiPokedexText,
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CHERRIM] =
    {
        .categoryName = _("Blossom"),
        .height = 5,
        .weight = 93,
        .description = gCherrimPokedexText,
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHELLOS] =
    {
        .categoryName = _("Sea Slug"),
        .height = 3,
        .weight = 63,
        .description = gShellosPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GASTRODON] =
    {
        .categoryName = _("Sea Slug"),
        .height = 9,
        .weight = 299,
        .description = gGastrodonPokedexText,
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ROTOM] =
    {
        .categoryName = _("Plasma"),
        .height = 3,
        .weight = 3,
        .description = gRotomPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_UXIE] =
    {
        .categoryName = _("Knowledge"),
        .height = 3,
        .weight = 3,
        .description = gUxiePokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MESPRIT] =
    {
        .categoryName = _("Emotion"),
        .height = 3,
        .weight = 3,
        .description = gMespritPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AZELF] =
    {
        .categoryName = _("Willpower"),
        .height = 3,
        .weight = 3,
        .description = gAzelfPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DIALGA] =
    {
        .categoryName = _("Temporal"),
        .height = 54,
        .weight = 6830,
        .description = gDialgaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
    },

    [NATIONAL_DEX_PALKIA] =
    {
        .categoryName = _("Spatial"),
        .height = 42,
        .weight = 3360,
        .description = gPalkiaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 650,
        .trainerOffset = 16,
    },

    [NATIONAL_DEX_HEATRAN] =
    {
        .categoryName = _("Lava Dome"),
        .height = 17,
        .weight = 4300,
        .description = gHeatranPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 290,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_REGIGIGAS] =
    {
        .categoryName = _("Colossal"),
        .height = 37,
        .weight = 4200,
        .description = gRegigigasPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 610,
        .trainerOffset = 17,
    },

    [NATIONAL_DEX_GIRATINA] =
    {
        .categoryName = _("Renegade"),
        .height = 45,
        .weight = 7500,
        .description = gGiratinaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 614,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_CRESSELIA] =
    {
        .categoryName = _("Lunar"),
        .height = 15,
        .weight = 856,
        .description = gCresseliaPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PHIONE] =
    {
        .categoryName = _("Sea Drifter"),
        .height = 4,
        .weight = 31,
        .description = gPhionePokedexText,
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MANAPHY] =
    {
        .categoryName = _("Seafaring"),
        .height = 3,
        .weight = 14,
        .description = gManaphyPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DARKRAI] =
    {
        .categoryName = _("Pitch-Black"),
        .height = 15,
        .weight = 505,
        .description = gDarkraiPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHAYMIN] =
    {
        .categoryName = _("Gratitude"),
        .height = 2,
        .weight = 21,
        .description = gShayminPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ARCEUS] =
    {
        .categoryName = _("Alpha"),
        .height = 32,
        .weight = 3200,
        .description = gArceusPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 495,
        .trainerOffset = 10,
    },
#endif

#if P_GEN_5_POKEMON == TRUE
    [NATIONAL_DEX_VICTINI] =
    {
        .categoryName = _("Victory"),
        .height = 4,
        .weight = 40,
        .description = gVictiniPokedexText,
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZORUA] =
    {
        .categoryName = _("Tricky Fox"),
        .height = 7,
        .weight = 125,
        .description = gZoruaPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZOROARK] =
    {
        .categoryName = _("Illusion Fox"),
        .height = 16,
        .weight = 811,
        .description = gZoroarkPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_DEERLING] =
    {
        .categoryName = _("Season"),
        .height = 6,
        .weight = 195,
        .description = gDeerlingPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SAWSBUCK] =
    {
        .categoryName = _("Season"),
        .height = 19,
        .weight = 925,
        .description = gSawsbuckPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_COBALION] =
    {
        .categoryName = _("Iron Will"),
        .height = 21,
        .weight = 2500,
        .description = gCobalionPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_TERRAKION] =
    {
        .categoryName = _("Cavern"),
        .height = 19,
        .weight = 2600,
        .description = gTerrakionPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 336,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_VIRIZION] =
    {
        .categoryName = _("Grassland"),
        .height = 20,
        .weight = 2000,
        .description = gVirizionPokedexText,
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 344,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_TORNADUS] =
    {
        .categoryName = _("Cyclone"),
        .height = 15,
        .weight = 630,
        .description = gTornadusPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_THUNDURUS] =
    {
        .categoryName = _("Bolt Strike"),
        .height = 15,
        .weight = 610,
        .description = gThundurusPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RESHIRAM] =
    {
        .categoryName = _("Vast White"),
        .height = 32,
        .weight = 3300,
        .description = gReshiramPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 445,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_ZEKROM] =
    {
        .categoryName = _("Deep Black"),
        .height = 29,
        .weight = 3450,
        .description = gZekromPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 2,
        .trainerScale = 412,
        .trainerOffset = 10,
    },

    [NATIONAL_DEX_LANDORUS] =
    {
        .categoryName = _("Abundance"),
        .height = 15,
        .weight = 680,
        .description = gLandorusPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KYUREM] =
    {
        .categoryName = _("Boundary"),
        .height = 30,
        .weight = 3250,
        .description = gKyuremPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KELDEO] =
    {
        .categoryName = _("Colt"),
        .height = 14,
        .weight = 485,
        .description = gKeldeoPokedexText,
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MELOETTA] =
    {
        .categoryName = _("Melody"),
        .height = 6,
        .weight = 65,
        .description = gMeloettaPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GENESECT] =
    {
        .categoryName = _("Paleozoic"),
        .height = 15,
        .weight = 825,
        .description = gGenesectPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },
#endif

#if P_GEN_6_POKEMON == TRUE
    [NATIONAL_DEX_FROAKIE] =
    {
        .categoryName = _("Bubble Frog"),
        .height = 3,
        .weight = 70,
        .description = gFroakiePokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FROGADIER] =
    {
        .categoryName = _("Bubble Frog"),
        .height = 6,
        .weight = 109,
        .description = gFrogadierPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GRENINJA] =
    {
        .categoryName = _("Ninja"),
        .height = 15,
        .weight = 400,
        .description = gGreninjaPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SCATTERBUG] =
    {
        .categoryName = _("Scatterdust"),
        .height = 3,
        .weight = 25,
        .description = gScatterbugPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPEWPA] =
    {
        .categoryName = _("Scatterdust"),
        .height = 3,
        .weight = 84,
        .description = gSpewpaPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VIVILLON] =
    {
        .categoryName = _("Scale"),
        .height = 12,
        .weight = 170,
        .description = gVivillonPokedexText,
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLABEBE] =
    {
        .categoryName = _("Single Bloom"),
        .height = 1,
        .weight = 1,
        .description = gFlabebePokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLOETTE] =
    {
        .categoryName = _("Single Bloom"),
        .height = 2,
        .weight = 9,
        .description = gFloettePokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLORGES] =
    {
        .categoryName = _("Garden"),
        .height = 11,
        .weight = 100,
        .description = gFlorgesPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FURFROU] =
    {
        .categoryName = _("Poodle"),
        .height = 12,
        .weight = 280,
        .description = gFurfrouPokedexText,
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HONEDGE] =
    {
        .categoryName = _("Sword"),
        .height = 8,
        .weight = 20,
        .description = gHonedgePokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_DOUBLADE] =
    {
        .categoryName = _("Sword"),
        .height = 8,
        .weight = 45,
        .description = gDoubladePokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AEGISLASH] =
    {
        .categoryName = _("Royal Sword"),
        .height = 17,
        .weight = 530,
        .description = gAegislashPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_PUMPKABOO] =
    {
        .categoryName = _("Pumpkin"),
        .height = 4,
        .weight = 50,
        .description = gPumpkabooPokedexText,
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GOURGEIST] =
    {
        .categoryName = _("Pumpkin"),
        .height = 9,
        .weight = 125,
        .description = gGourgeistPokedexText,
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BERGMITE] =
    {
        .categoryName = _("Ice Chunk"),
        .height = 10,
        .weight = 995,
        .description = gBergmitePokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_AVALUGG] =
    {
        .categoryName = _("Iceberg"),
        .height = 20,
        .weight = 5050,
        .description = gAvaluggPokedexText,
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_XERNEAS] =
    {
        .categoryName = _("Life"),
        .height = 30,
        .weight = 2150,
        .description = gXerneasPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_YVELTAL] =
    {
        .categoryName = _("Destruction"),
        .height = 58,
        .weight = 2030,
        .description = gYveltalPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 360,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_ZYGARDE] =
    {
        .categoryName = _("Order"),
        .height = 50,
        .weight = 3050,
        .description = gZygardePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
    },

    [NATIONAL_DEX_DIANCIE] =
    {
        .categoryName = _("Jewel"),
        .height = 7,
        .weight = 88,
        .description = gDianciePokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_HOOPA] =
    {
        .categoryName = _("Mischief"),
        .height = 5,
        .weight = 90,
        .description = gHoopaPokedexText,
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VOLCANION] =
    {
        .categoryName = _("Steam"),
        .height = 17,
        .weight = 1950,
        .description = gVolcanionPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
    },
#endif

#if P_GEN_7_POKEMON == TRUE
    [NATIONAL_DEX_ORICORIO] =
    {
        .categoryName = _("Dancing"),
        .height = 6,
        .weight = 34,
        .description = gOricorioPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ROCKRUFF] =
    {
        .categoryName = _("Puppy"),
        .height = 5,
        .weight = 92,
        .description = gRockruffPokedexText,
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LYCANROC] =
    {
        .categoryName = _("Wolf"),
        .height = 8,
        .weight = 250,
        .description = gLycanrocPokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WISHIWASHI] =
    {
        .categoryName = _("Small Fry"),
        .height = 2,
        .weight = 3,
        .description = gWishiwashiPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TYPE_NULL] =
    {
        .categoryName = _("Synthetic"),
        .height = 19,
        .weight = 1205,
        .description = gTypeNullPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_SILVALLY] =
    {
        .categoryName = _("Synthetic"),
        .height = 23,
        .weight = 1005,
        .description = gSilvallyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_MINIOR] =
    {
        .categoryName = _("Meteor"),
        .height = 3,
        .weight = 400,
        .description = gMiniorPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MIMIKYU] =
    {
        .categoryName = _("Disguise"),
        .height = 2,
        .weight = 7,
        .description = gMimikyuPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TAPU_KOKO] =
    {
        .categoryName = _("Land Spirit"),
        .height = 18,
        .weight = 205,
        .description = gTapuKokoPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_TAPU_LELE] =
    {
        .categoryName = _("Land Spirit"),
        .height = 12,
        .weight = 186,
        .description = gTapuLelePokedexText,
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TAPU_BULU] =
    {
        .categoryName = _("Land Spirit"),
        .height = 19,
        .weight = 455,
        .description = gTapuBuluPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_TAPU_FINI] =
    {
        .categoryName = _("Land Spirit"),
        .height = 13,
        .weight = 212,
        .description = gTapuFiniPokedexText,
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_COSMOG] =
    {
        .categoryName = _("Nebula"),
        .height = 2,
        .weight = 1,
        .description = gCosmogPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_COSMOEM] =
    {
        .categoryName = _("Protostar"),
        .height = 1,
        .weight = 9999,
        .description = gCosmoemPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SOLGALEO] =
    {
        .categoryName = _("Sunne"),
        .height = 34,
        .weight = 2300,
        .description = gSolgaleoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_LUNALA] =
    {
        .categoryName = _("Moone"),
        .height = 40,
        .weight = 1200,
        .description = gLunalaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 411,
        .trainerOffset = 5,
    },

    [NATIONAL_DEX_NIHILEGO] =
    {
        .categoryName = _("Parasite"),
        .height = 12,
        .weight = 555,
        .description = gNihilegoPokedexText,
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BUZZWOLE] =
    {
        .categoryName = _("Swollen"),
        .height = 24,
        .weight = 3336,
        .description = gBuzzwolePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_PHEROMOSA] =
    {
        .categoryName = _("Lissome"),
        .height = 18,
        .weight = 250,
        .description = gPheromosaPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_XURKITREE] =
    {
        .categoryName = _("Glowing"),
        .height = 38,
        .weight = 1000,
        .description = gXurkitreePokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
    },

    [NATIONAL_DEX_CELESTEELA] =
    {
        .categoryName = _("Launch"),
        .height = 92,
        .weight = 9999,
        .description = gCelesteelaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 516,
        .trainerOffset = 13,
    },

    [NATIONAL_DEX_KARTANA] =
    {
        .categoryName = _("Drawn Sword"),
        .height = 3,
        .weight = 1,
        .description = gKartanaPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GUZZLORD] =
    {
        .categoryName = _("Junkivore"),
        .height = 55,
        .weight = 8880,
        .description = gGuzzlordPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
    },

    [NATIONAL_DEX_NECROZMA] =
    {
        .categoryName = _("Prism"),
        .height = 24,
        .weight = 2300,
        .description = gNecrozmaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_MAGEARNA] =
    {
        .categoryName = _("Artificial"),
        .height = 10,
        .weight = 805,
        .description = gMagearnaPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MARSHADOW] =
    {
        .categoryName = _("Gloomdwellr"),
        .height = 7,
        .weight = 222,
        .description = gMarshadowPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_POIPOLE] =
    {
        .categoryName = _("Poison Pin"),
        .height = 6,
        .weight = 18,
        .description = gPoipolePokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NAGANADEL] =
    {
        .categoryName = _("Poison Pin"),
        .height = 36,
        .weight = 1500,
        .description = gNaganadelPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_STAKATAKA] =
    {
        .categoryName = _("Rampart"),
        .height = 55,
        .weight = 8200,
        .description = gStakatakaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
    },

    [NATIONAL_DEX_BLACEPHALON] =
    {
        .categoryName = _("Fireworks"),
        .height = 18,
        .weight = 130,
        .description = gBlacephalonPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_ZERAORA] =
    {
        .categoryName = _("Thunderclap"),
        .height = 15,
        .weight = 445,
        .description = gZeraoraPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MELTAN] =
    {
        .categoryName = _("Hex Nut"),
        .height = 2,
        .weight = 80,
        .description = gMeltanPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MELMETAL] =
    {
        .categoryName = _("Hex Nut"),
        .height = 25,
        .weight = 800,
        .description = gMelmetalPokedexText,
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
    },
#endif

#if P_GEN_8_POKEMON == TRUE
    [NATIONAL_DEX_CRAMORANT] =
    {
        .categoryName = _("Gulp"),
        .height = 8,
        .weight = 180,
        .description = gCramorantPokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TOXEL] =
    {
        .categoryName = _("Baby"),
        .height = 4,
        .weight = 110,
        .description = gToxelPokedexText,
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TOXTRICITY] =
    {
        .categoryName = _("Punk"),
        .height = 16,
        .weight = 400,
        .description = gToxtricityPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_SINISTEA] =
    {
        .categoryName = _("Black Tea"),
        .height = 1,
        .weight = 2,
        .description = gSinisteaPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_POLTEAGEIST] =
    {
        .categoryName = _("Black Tea"),
        .height = 2,
        .weight = 4,
        .description = gPolteageistPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PERRSERKER] =
    {
        .categoryName = _("Viking"),
        .height = 8,
        .weight = 280,
        .description = gPerrserkerPokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CURSOLA] =
    {
        .categoryName = _("Coral"),
        .height = 10,
        .weight = 4,
        .description = gCursolaPokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SIRFETCHD] =
    {
        .categoryName = _("Wild Duck"),
        .height = 8,
        .weight = 1170,
        .description = gSirfetchdPokedexText,
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MR_RIME] =
    {
        .categoryName = _("Comedian"),
        .height = 15,
        .weight = 582,
        .description = gMrRimePokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_RUNERIGUS] =
    {
        .categoryName = _("Grudge"),
        .height = 16,
        .weight = 666,
        .description = gRunerigusPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_MILCERY] =
    {
        .categoryName = _("Cream"),
        .height = 2,
        .weight = 3,
        .description = gMilceryPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ALCREMIE] =
    {
        .categoryName = _("Cream"),
        .height = 3,
        .weight = 5,
        .description = gAlcremiePokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_EISCUE] =
    {
        .categoryName = _("Penguin"),
        .height = 14,
        .weight = 890,
        .description = gEiscuePokedexText,
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_INDEEDEE] =
    {
        .categoryName = _("Emotion"),
        .height = 9,
        .weight = 280,
        .description = gIndeedeePokedexText,
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MORPEKO] =
    {
        .categoryName = _("Two-Sided"),
        .height = 3,
        .weight = 30,
        .description = gMorpekoPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZACIAN] =
    {
        .categoryName = _("Warrior"),
        .height = 28,
        .weight = 1100,
        .description = gZacianPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ZAMAZENTA] =
    {
        .categoryName = _("Warrior"),
        .height = 29,
        .weight = 2100,
        .description = gZamazentaPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_ETERNATUS] =
    {
        .categoryName = _("Gigantic"),
        .height = 200,
        .weight = 9500,
        .description = gEternatusPokedexText,
        .pokemonScale = 230,
        .pokemonOffset = 0,
        .trainerScale = 4852,
        .trainerOffset = 20,
    },

    [NATIONAL_DEX_KUBFU] =
    {
        .categoryName = _("Wushu"),
        .height = 6,
        .weight = 120,
        .description = gKubfuPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_URSHIFU] =
    {
        .categoryName = _("Wushu"),
        .height = 19,
        .weight = 1050,
        .description = gUrshifuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_ZARUDE] =
    {
        .categoryName = _("Rogue Monkey"),
        .height = 18,
        .weight = 700,
        .description = gZarudePokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_REGIELEKI] =
    {
        .categoryName = _("Electron"),
        .height = 12,
        .weight = 1450,
        .description = gRegielekiPokedexText,
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_REGIDRAGO] =
    {
        .categoryName = _("Dragon Orb"),
        .height = 21,
        .weight = 2000,
        .description = gRegidragoPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_GLASTRIER] =
    {
        .categoryName = _("Wild Horse"),
        .height = 22,
        .weight = 8000,
        .description = gGlastrierPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_SPECTRIER] =
    {
        .categoryName = _("Swift Horse"),
        .height = 20,
        .weight = 445,
        .description = gSpectrierPokedexText,
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_CALYREX] =
    {
        .categoryName = _("King"),
        .height = 11,
        .weight = 77,
        .description = gCalyrexPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_WYRDEER] =
    {
        .categoryName = _("Big Horn"),
        .height = 18,
        .weight = 951,
        .description = gWyrdeerPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_KLEAVOR] =
    {
        .categoryName = _("Axe"),
        .height = 18,
        .weight = 890,
        .description = gKleavorPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_URSALUNA] =
    {
        .categoryName = _("Peat"),
        .height = 24,
        .weight = 2900,
        .description = gUrsalunaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 369,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_BASCULEGION] =
    {
        .categoryName = _("Big Fish"),
        .height = 30,
        .weight = 1100,
        .description = gBasculegionPokedexText,
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SNEASLER] =
    {
        .categoryName = _("Free Climb"),
        .height = 13,
        .weight = 430,
        .description = gSneaslerPokedexText,
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_OVERQWIL] =
    {
        .categoryName = _("Pin Cluster"),
        .height = 25,
        .weight = 605,
        .description = gOverqwilPokedexText,
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_ENAMORUS] =
    {
        .categoryName = _("Love-Hate"),
        .height = 16,
        .weight = 480,
        .description = gEnamorusPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_TIDPIT] =
    {
        .categoryName = _("Seedling"),
        .height = 7,
        .weight = 69,
        .description = gTidpitPokedexText,
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLIDLOW] =
    {
        .categoryName = _("Vine Snake"),
        .height = 10,
        .weight = 130,
        .description = gSlidlowPokedexText,
        .pokemonScale = 335,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CARDIOVOR] =
    {
        .categoryName = _("Carnivore"),
        .height = 20,
        .weight = 1000,
        .description = gCardiovorPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
    },

    [NATIONAL_DEX_FIEFREET] =
    {
        .categoryName = _("Imp"),
        .height = 6,
        .weight = 85,
        .description = gFiefreetPokedexText,
        .pokemonScale = 444,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BALBYRN] =
    {
        .categoryName = _("Dark Flame"),
        .height = 11,
        .weight = 190,
        .description = gBalbyrnPokedexText,
        .pokemonScale = 302,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BLAZIZAHAK] =
    {
        .categoryName = _("Blackfire"),
        .height = 17,
        .weight = 905,
        .description = gBlazizahakPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
    },

    [NATIONAL_DEX_PRONGY] =
    {
        .categoryName = _("Spear"),
        .height = 5,
        .weight = 90,
        .description = gProngyPokedexText,
        .pokemonScale = 412,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TRIDALIER] =
    {
        .categoryName = _("Guardian"),
        .height = 10,
        .weight = 225,
        .description = gTridalierPokedexText,
        .pokemonScale = 332,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TRITONAUT] =
    {
        .categoryName = _("Kingdom"),
        .height = 16,
        .weight = 855,
        .description = gTritonautPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 293,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_SNELFREND] =
    {
        .categoryName = _("Kind Snail"),
        .height = 3,
        .weight = 40,
        .description = gSnelfrendPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SYCOPLOD] =
    {
        .categoryName = _("Dazed Snail"),
        .height = 7,
        .weight = 115,
        .description = gSycoplodPokedexText,
        .pokemonScale = 391,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SYCOSTROM] =
    {
        .categoryName = _("Spiral Being"),
        .height = 17,
        .weight = 608,
        .description = gSycostromPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_GUPSPAR] =
    {
        .categoryName = _("Maw"),
        .height = 5,
        .weight = 10,
        .description = gGupsparPokedexText,
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_VANGAR] =
    {
        .categoryName = _("Jaw"),
        .height = 15,
        .weight = 400,
        .description = gVangarPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GHAERIAL] =
    {
        .categoryName = _("Flying Jaw"),
        .height = 32,
        .weight = 3200,
        .description = gGhaerialPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 495,
        .trainerOffset = 10,
    },

    [NATIONAL_DEX_MARINAROC] =
    {
        .categoryName = _("Submerging"),
        .height = 19,
        .weight = 452,
        .description = gMarinarocPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
    },

    [NATIONAL_DEX_METTATOLL] =
    {
        .categoryName = _("Deep Sea"),
        .height = 34,
        .weight = 2300,
        .description = gMettatollPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
    },

    [NATIONAL_DEX_ICKSQUEEK] =
    {
        .categoryName = _("Infection"),
        .height = 8,
        .weight = 60,
        .description = gIcksqueekPokedexText,
        .pokemonScale = 439,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KOMORODE] =
    {
        .categoryName = _("Patience"),
        .height = 11,
        .weight = 270,
        .description = gKomorodePokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KYUDI] =
    {
        .categoryName = _("Desert Fae"),
        .height = 6,
        .weight = 120,
        .description = gKyudiPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_KOMBAKYU] =
    {
        .categoryName = _("Desert Fae"),
        .height = 14,
        .weight = 620,
        .description = gKombakyuPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLUFFSIR] =
    {
        .categoryName = _("Big Eye"),
        .height = 4,
        .weight = 175,
        .description = gFluffsirPokedexText,
        .pokemonScale = 560,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_FLUFFREAR] =
    {
        .categoryName = _("Rearing"),
        .height = 14,
        .weight = 392,
        .description = gFluffrearPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = -1,
    },

    [NATIONAL_DEX_SAINTISOW] =
    {
        .categoryName = _("Flying Pig"),
        .height = 5,
        .weight = 80,
        .description = gSaintisowPokedexText,
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SANCTISOW] =
    {
        .categoryName = _("Flying Pig"),
        .height = 12,
        .weight = 380,
        .description = gSanctisowPokedexText,
        .pokemonScale = 274,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SOWPHIROTH] =
    {
        .categoryName = _("Serene Pig"),
        .height = 32,
        .weight = 160,
        .description = gSowphirothPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 495,
        .trainerOffset = 10,
    },

    [NATIONAL_DEX_TOXEXOT] =
    {
        .categoryName = _("Distraction"),
        .height = 8,
        .weight = 200,
        .description = gToxexotPokedexText,
        .pokemonScale = 381,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_PSEUDRA] =
    {
        .categoryName = _("Misdirection"),
        .height = 18,
        .weight = 815,
        .description = gPseudraPokedexText,
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_MANDIMYTE] =
    {
        .categoryName = _("Bursting"),
        .height = 1,
        .weight = 6,
        .description = gMandimytePokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_TERMINYTE] =
    {
        .categoryName = _("Volatile"),
        .height = 2,
        .weight = 34,
        .description = gTerminytePokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SNOTLOUD] =
    {
        .categoryName = _("Sickness"),
        .height = 7,
        .weight = 222,
        .description = gSnotloudPokedexText,
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SICKBEAT] =
    {
        .categoryName = _("Sickness"),
        .height = 11,
        .weight = 300,
        .description = gSickbeatPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPRYTE] =
    {
        .categoryName = _("Shatter"),
        .height = 6,
        .weight = 118,
        .description = gSprytePokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_GUMONA] =
    {
        .categoryName = _("Upper"),
        .height = 10,
        .weight = 295,
        .description = gGumonaPokedexText,
        .pokemonScale = 307,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_NANGGAL] =
    {
        .categoryName = _("Middle"),
        .height = 15,
        .weight = 850,
        .description = gNanggalPokedexText,
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SHEEDRAKE] =
    {
        .categoryName = _("Lower"),
        .height = 16,
        .weight = 366,
        .description = gSheedrakePokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
    },

    [NATIONAL_DEX_TRANSERA] =
    {
        .categoryName = _("Eerie Lights"),
        .height = 9,
        .weight = 125,
        .description = gTranseraPokedexText,
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_BIVAGUE] =
    {
        .categoryName = _("Bivalve"),
        .height = 4,
        .weight = 525,
        .description = gBivaguePokedexText,
        .pokemonScale = 691,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUSCKAW] =
    {
        .categoryName = _("Illustrious"),
        .height = 18,
        .weight = 226,
        .description = gLusckawPokedexText,
        .pokemonScale = 278,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SADSOD] =
    {
        .categoryName = _("Sadness"),
        .height = 8,
        .weight = 395,
        .description = gSadsodPokedexText,
        .pokemonScale = 315,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAERACHOLY] =
    {
        .categoryName = _("Melancholy"),
        .height = 42,
        .weight = 3360,
        .description = gMaeracholyPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 650,
        .trainerOffset = 16,
    },

    [NATIONAL_DEX_LUMELMO] =
    {
        .categoryName = _("Faint Wisp"),
        .height = 2,
        .weight = 3,
        .description = gLumelmoPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LUMENDELA] =
    {
        .categoryName = _("Spark Wisp"),
        .height = 6,
        .weight = 34,
        .description = gLumendelaPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_STOMAWAY] =
    {
        .categoryName = _("Foreign"),
        .height = 6,
        .weight = 233,
        .description = gStomawayPokedexText,
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_CRAWLAXY] =
    {
        .categoryName = _("Visitor"),
        .height = 11,
        .weight = 605,
        .description = gCrawlaxyPokedexText,
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGNALURE] =
    {
        .categoryName = _("Magnetism"),
        .height = 4,
        .weight = 42,
        .description = gMagnalurePokedexText,
        .pokemonScale = 515,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MAGNANICOR] =
    {
        .categoryName = _("Magnetron"),
        .height = 21,
        .weight = 805,
        .description = gMagnanicorPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 365,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_CRYPLIN] =
    {
        .categoryName = _("Cryptic"),
        .height = 5,
        .weight = 90,
        .description = gCryplinPokedexText,
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_UHEFOE] =
    {
        .categoryName = _("Bizarre"),
        .height = 10,
        .weight = 345,
        .description = gUhefoePokedexText,
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_MYSTOMANIA] =
    {
        .categoryName = _("Mysterious"),
        .height = 17,
        .weight = 608,
        .description = gMystomaniaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
    },

    [NATIONAL_DEX_LYORESA] =
    {
        .categoryName = _("Sacrosanct"),
        .height = 21,
        .weight = 51,
        .description = gLyoresaPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
    },

    [NATIONAL_DEX_KODOUGH] =
    {
        .categoryName = _("Spirit"),
        .height = 1,
        .weight = 2,
        .description = gKodoughPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SLICKSLICE] =
    {
        .categoryName = _("Spirit"),
        .height = 2,
        .weight = 4,
        .description = gSlickslicePokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_LOAFOOF] =
    {
        .categoryName = _("Aloof"),
        .height = 3,
        .weight = 6,
        .description = gLoafoofPokedexText,
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
    },

    [NATIONAL_DEX_SPIRITOAST] =
    {
        .categoryName = _("Burnt"),
        .height = 2,
        .weight = 4,
        .description = gSpiritoastPokedexText,
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
    },
#endif
};
