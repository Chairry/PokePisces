const u16 *const gFormSpeciesIdTables[NUM_SPECIES] =
{
    [SPECIES_VENUSAUR] = sVenusaurFormSpeciesIdTable,
    [SPECIES_CHARIZARD] = sCharizardFormSpeciesIdTable,
    [SPECIES_BLASTOISE] = sBlastoiseFormSpeciesIdTable,
    [SPECIES_RATTATA] = sRattataFormSpeciesIdTable,
    [SPECIES_RATICATE] = sRaticateFormSpeciesIdTable,
    [SPECIES_PIKACHU] = sPikachuFormSpeciesIdTable,
    [SPECIES_RAICHU] = sRaichuFormSpeciesIdTable,
    [SPECIES_SANDSHREW] = sSandshrewFormSpeciesIdTable,
    [SPECIES_SANDSLASH] = sSandslashFormSpeciesIdTable,
    [SPECIES_VULPIX] = sVulpixFormSpeciesIdTable,
    [SPECIES_NINETALES] = sNinetalesFormSpeciesIdTable,
    [SPECIES_DIGLETT] = sDiglettFormSpeciesIdTable,
    [SPECIES_DUGTRIO] = sDugtrioFormSpeciesIdTable,
    [SPECIES_MEOWTH] = sMeowthFormSpeciesIdTable,
    [SPECIES_PERSIAN] = sPersianFormSpeciesIdTable,
    [SPECIES_GEODUDE] = sGeodudeFormSpeciesIdTable,
    [SPECIES_GRAVELER] = sGravelerFormSpeciesIdTable,
    [SPECIES_GOLEM] = sGolemFormSpeciesIdTable,
    [SPECIES_PONYTA] = sPonytaFormSpeciesIdTable,
    [SPECIES_RAPIDASH] = sRapidashFormSpeciesIdTable,
    [SPECIES_SLOWPOKE] = sSlowpokeFormSpeciesIdTable,
    [SPECIES_SLOWBRO] = sSlowbroFormSpeciesIdTable,
    [SPECIES_FARFETCHD] = sFarfetchdFormSpeciesIdTable,
    [SPECIES_GRIMER] = sGrimerFormSpeciesIdTable,
    [SPECIES_MUK] = sMukFormSpeciesIdTable,
    [SPECIES_MR_MIME] = sMrMimeFormSpeciesIdTable,
    [SPECIES_ARTICUNO] = sArticunoFormSpeciesIdTable,
    [SPECIES_ZAPDOS] = sZapdosFormSpeciesIdTable,
    [SPECIES_MOLTRES] = sMoltresFormSpeciesIdTable,
    [SPECIES_MEWTWO] = sMewtwoFormSpeciesIdTable,
    [SPECIES_SCEPTILE] = sSceptileFormSpeciesIdTable,
    [SPECIES_BLAZIKEN] = sBlazikenFormSpeciesIdTable,
    [SPECIES_SWAMPERT] = sSwampertFormSpeciesIdTable,
    [SPECIES_LATIAS] = sLatiasFormSpeciesIdTable,
    [SPECIES_LATIOS] = sLatiosFormSpeciesIdTable,
    [SPECIES_KYOGRE] = sKyogreFormSpeciesIdTable,
    [SPECIES_GROUDON] = sGroudonFormSpeciesIdTable,
    [SPECIES_RAYQUAZA] = sRayquazaFormSpeciesIdTable,
    [SPECIES_DEOXYS] = sDeoxysFormSpeciesIdTable,
#if P_GEN_4_POKEMON == TRUE
    [SPECIES_CHERRIM] = sCherrimFormSpeciesIdTable,
    [SPECIES_SHELLOS] = sShellosFormSpeciesIdTable,
    [SPECIES_GASTRODON] = sGastrodonFormSpeciesIdTable,
    [SPECIES_ROTOM] = sRotomFormSpeciesIdTable,
    [SPECIES_DIALGA] = sDialgaFormSpeciesIdTable,
    [SPECIES_PALKIA] = sPalkiaFormSpeciesIdTable,
    [SPECIES_GIRATINA] = sGiratinaFormSpeciesIdTable,
    [SPECIES_SHAYMIN] = sShayminFormSpeciesIdTable,
    [SPECIES_ARCEUS] = sArceusFormSpeciesIdTable,
#endif
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_ZORUA] = sZoruaFormSpeciesIdTable,
    [SPECIES_ZOROARK] = sZoroarkFormSpeciesIdTable,
    [SPECIES_DEERLING] = sDeerlingFormSpeciesIdTable,
    [SPECIES_SAWSBUCK] = sSawsbuckFormSpeciesIdTable,
    [SPECIES_TORNADUS] = sTornadusFormSpeciesIdTable,
    [SPECIES_THUNDURUS] = sThundurusFormSpeciesIdTable,
    [SPECIES_LANDORUS] = sLandorusFormSpeciesIdTable,
    [SPECIES_KYUREM] = sKyuremFormSpeciesIdTable,
    [SPECIES_KELDEO] = sKeldeoFormSpeciesIdTable,
    [SPECIES_MELOETTA] = sMeloettaFormSpeciesIdTable,
    [SPECIES_GENESECT] = sGenesectFormSpeciesIdTable,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_GRENINJA] = sGreninjaFormSpeciesIdTable,
    [SPECIES_VIVILLON] = sVivillonFormSpeciesIdTable,
    [SPECIES_FLABEBE] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLOETTE] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLORGES] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FURFROU] = sFurfrouFormSpeciesIdTable,
    [SPECIES_AEGISLASH] = sAegislashFormSpeciesIdTable,
    [SPECIES_PUMPKABOO] = sPumpkabooFormSpeciesIdTable,
    [SPECIES_GOURGEIST] = sGourgeistFormSpeciesIdTable,
    [SPECIES_AVALUGG] = sAvaluggFormSpeciesIdTable,
    [SPECIES_XERNEAS] = sXerneasFormSpeciesIdTable,
    [SPECIES_ZYGARDE] = sZygardeFormSpeciesIdTable,
    [SPECIES_HOOPA] = sHoopaFormSpeciesIdTable,
#endif
#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ORICORIO] = sOricorioFormSpeciesIdTable,
    [SPECIES_ROCKRUFF] = sRockruffFormSpeciesIdTable,
    [SPECIES_LYCANROC] = sLycanrocFormSpeciesIdTable,
    [SPECIES_WISHIWASHI] = sWishiwashiFormSpeciesIdTable,
    [SPECIES_SILVALLY] = sSilvallyFormSpeciesIdTable,
    [SPECIES_MINIOR] = sMiniorFormSpeciesIdTable,
    [SPECIES_MIMIKYU] = sMimikyuFormSpeciesIdTable,
    [SPECIES_NECROZMA] = sNecrozmaFormSpeciesIdTable,
    [SPECIES_MAGEARNA] = sMagearnaFormSpeciesIdTable,
#endif
#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CRAMORANT] = sCramorantFormSpeciesIdTable,
    [SPECIES_TOXTRICITY] = sToxtricityFormSpeciesIdTable,
    [SPECIES_SINISTEA] = sSinisteaFormSpeciesIdTable,
    [SPECIES_POLTEAGEIST] = sPolteageistFormSpeciesIdTable,
    [SPECIES_ALCREMIE] = sAlcremieFormSpeciesIdTable,
    [SPECIES_EISCUE] = sEiscueFormSpeciesIdTable,
    [SPECIES_MORPEKO] = sMorpekoFormSpeciesIdTable,
    [SPECIES_ZACIAN] = sZacianFormSpeciesIdTable,
    [SPECIES_ZAMAZENTA] = sZamazentaFormSpeciesIdTable,
    [SPECIES_ETERNATUS] = sEternatusFormSpeciesIdTable,
    [SPECIES_URSHIFU] = sUrshifuFormSpeciesIdTable,
    [SPECIES_ZARUDE] = sZarudeFormSpeciesIdTable,
    [SPECIES_CALYREX] = sCalyrexFormSpeciesIdTable,
    [SPECIES_ENAMORUS] = sEnamorusFormSpeciesIdTable,
    [SPECIES_BASCULEGION] = sBasculegionFormSpeciesIdTable,
#endif
    // Megas
    [SPECIES_VENUSAUR_MEGA] = sVenusaurFormSpeciesIdTable,
    [SPECIES_CHARIZARD_MEGA_X] = sCharizardFormSpeciesIdTable,
    [SPECIES_CHARIZARD_MEGA_Y] = sCharizardFormSpeciesIdTable,
    [SPECIES_BLASTOISE_MEGA] = sBlastoiseFormSpeciesIdTable,
    [SPECIES_SLOWBRO_MEGA] = sSlowbroFormSpeciesIdTable,
    [SPECIES_MEWTWO_MEGA_X] = sMewtwoFormSpeciesIdTable,
    [SPECIES_MEWTWO_MEGA_Y] = sMewtwoFormSpeciesIdTable,
    [SPECIES_SCEPTILE_MEGA] = sSceptileFormSpeciesIdTable,
    [SPECIES_BLAZIKEN_MEGA] = sBlazikenFormSpeciesIdTable,
    [SPECIES_SWAMPERT_MEGA] = sSwampertFormSpeciesIdTable,
    [SPECIES_LATIAS_MEGA] = sLatiasFormSpeciesIdTable,
    [SPECIES_LATIOS_MEGA] = sLatiosFormSpeciesIdTable,
    // Special Mega + Primals
    [SPECIES_RAYQUAZA_MEGA] = sRayquazaFormSpeciesIdTable,
    [SPECIES_KYOGRE_PRIMAL] = sKyogreFormSpeciesIdTable,
    [SPECIES_GROUDON_PRIMAL] = sGroudonFormSpeciesIdTable,
    // Alolan Forms
    [SPECIES_RATTATA_ALOLAN] = sRattataFormSpeciesIdTable,
    [SPECIES_RATICATE_ALOLAN] = sRaticateFormSpeciesIdTable,
    [SPECIES_RAICHU_ALOLAN] = sRaichuFormSpeciesIdTable,
    [SPECIES_SANDSHREW_ALOLAN] = sSandshrewFormSpeciesIdTable,
    [SPECIES_SANDSLASH_ALOLAN] = sSandslashFormSpeciesIdTable,
    [SPECIES_VULPIX_ALOLAN] = sVulpixFormSpeciesIdTable,
    [SPECIES_NINETALES_ALOLAN] = sNinetalesFormSpeciesIdTable,
    [SPECIES_DIGLETT_ALOLAN] = sDiglettFormSpeciesIdTable,
    [SPECIES_DUGTRIO_ALOLAN] = sDugtrioFormSpeciesIdTable,
    [SPECIES_MEOWTH_ALOLAN] = sMeowthFormSpeciesIdTable,
    [SPECIES_PERSIAN_ALOLAN] = sPersianFormSpeciesIdTable,
    [SPECIES_GEODUDE_ALOLAN] = sGeodudeFormSpeciesIdTable,
    [SPECIES_GRAVELER_ALOLAN] = sGravelerFormSpeciesIdTable,
    [SPECIES_GOLEM_ALOLAN] = sGolemFormSpeciesIdTable,
    [SPECIES_GRIMER_ALOLAN] = sGrimerFormSpeciesIdTable,
    [SPECIES_MUK_ALOLAN] = sMukFormSpeciesIdTable,
    // Galarian Forms
    [SPECIES_MEOWTH_GALARIAN] = sMeowthFormSpeciesIdTable,
    [SPECIES_PONYTA_GALARIAN] = sPonytaFormSpeciesIdTable,
    [SPECIES_RAPIDASH_GALARIAN] = sRapidashFormSpeciesIdTable,
    [SPECIES_SLOWPOKE_GALARIAN] = sSlowpokeFormSpeciesIdTable,
    [SPECIES_SLOWBRO_GALARIAN] = sSlowbroFormSpeciesIdTable,
    [SPECIES_FARFETCHD_GALARIAN] = sFarfetchdFormSpeciesIdTable,
    [SPECIES_MR_MIME_GALARIAN] = sMrMimeFormSpeciesIdTable,
    [SPECIES_ARTICUNO_GALARIAN] = sArticunoFormSpeciesIdTable,
    [SPECIES_ZAPDOS_GALARIAN] = sZapdosFormSpeciesIdTable,
    [SPECIES_MOLTRES_GALARIAN] = sMoltresFormSpeciesIdTable,
    //Hisuian Forms
#if P_GEN_5_POKEMON == TRUE
    [SPECIES_ZORUA_HISUIAN] = sZoruaFormSpeciesIdTable,
    [SPECIES_ZOROARK_HISUIAN] = sZoroarkFormSpeciesIdTable,
#endif
#if P_GEN_6_POKEMON == TRUE
    [SPECIES_AVALUGG_HISUIAN] = sAvaluggFormSpeciesIdTable,
#endif

    // Misc Forms
    // Cosplay Pikachu
    [SPECIES_PIKACHU_COSPLAY] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_ROCK_STAR] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_BELLE] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_POP_STAR] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_PH_D] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_LIBRE] = sPikachuFormSpeciesIdTable,
    // Cap Pikachu
    [SPECIES_PIKACHU_ORIGINAL_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_HOENN_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_SINNOH_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_UNOVA_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_KALOS_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_ALOLA_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_PARTNER_CAP] = sPikachuFormSpeciesIdTable,
    [SPECIES_PIKACHU_WORLD_CAP] = sPikachuFormSpeciesIdTable,

    // Deoxys
    [SPECIES_DEOXYS_ATTACK] = sDeoxysFormSpeciesIdTable,
    [SPECIES_DEOXYS_DEFENSE] = sDeoxysFormSpeciesIdTable,
    [SPECIES_DEOXYS_SPEED] = sDeoxysFormSpeciesIdTable,
#if P_GEN_4_POKEMON == TRUE
    // Cherrim
    [SPECIES_CHERRIM_SUNSHINE] = sCherrimFormSpeciesIdTable,
    // Shellos
    [SPECIES_SHELLOS_EAST_SEA] = sShellosFormSpeciesIdTable,
    // Gastrodon
    [SPECIES_GASTRODON_EAST_SEA] = sGastrodonFormSpeciesIdTable,
    // Rotom
    [SPECIES_ROTOM_HEAT] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_WASH] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_FROST] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_FAN] = sRotomFormSpeciesIdTable,
    [SPECIES_ROTOM_MOW] = sRotomFormSpeciesIdTable,
    // Origin Forme
    [SPECIES_DIALGA_ORIGIN] = sDialgaFormSpeciesIdTable,
    [SPECIES_PALKIA_ORIGIN] = sPalkiaFormSpeciesIdTable,
    [SPECIES_GIRATINA_ORIGIN] = sGiratinaFormSpeciesIdTable,
    // Shaymin
    [SPECIES_SHAYMIN_SKY] = sShayminFormSpeciesIdTable,
    // Arceus
    [SPECIES_ARCEUS_FIGHTING] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_FLYING] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_POISON] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_GROUND] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_ROCK] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_BUG] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_GHOST] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_STEEL] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_FIRE] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_WATER] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_GRASS] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_ELECTRIC] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_PSYCHIC] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_ICE] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_DRAGON] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_DARK] = sArceusFormSpeciesIdTable,
    [SPECIES_ARCEUS_FAIRY] = sArceusFormSpeciesIdTable,
#endif
#if P_GEN_5_POKEMON == TRUE
    // Deerling
    [SPECIES_DEERLING_SUMMER] = sDeerlingFormSpeciesIdTable,
    [SPECIES_DEERLING_AUTUMN] = sDeerlingFormSpeciesIdTable,
    [SPECIES_DEERLING_WINTER] = sDeerlingFormSpeciesIdTable,
    // Sawsbuck
    [SPECIES_SAWSBUCK_SUMMER] = sSawsbuckFormSpeciesIdTable,
    [SPECIES_SAWSBUCK_AUTUMN] = sSawsbuckFormSpeciesIdTable,
    [SPECIES_SAWSBUCK_WINTER] = sSawsbuckFormSpeciesIdTable,
    // Therian Forms
    [SPECIES_TORNADUS_THERIAN] = sTornadusFormSpeciesIdTable,
    [SPECIES_THUNDURUS_THERIAN] = sThundurusFormSpeciesIdTable,
    [SPECIES_LANDORUS_THERIAN] = sLandorusFormSpeciesIdTable,
    // Kyurem
    [SPECIES_KYUREM_WHITE] = sKyuremFormSpeciesIdTable,
    [SPECIES_KYUREM_BLACK] = sKyuremFormSpeciesIdTable,
    // Keldeo
    [SPECIES_KELDEO_RESOLUTE] = sKeldeoFormSpeciesIdTable,
    // Meloetta
    [SPECIES_MELOETTA_PIROUETTE] = sMeloettaFormSpeciesIdTable,
    // Genesect
    [SPECIES_GENESECT_DOUSE_DRIVE] = sGenesectFormSpeciesIdTable,
    [SPECIES_GENESECT_SHOCK_DRIVE] = sGenesectFormSpeciesIdTable,
    [SPECIES_GENESECT_BURN_DRIVE] = sGenesectFormSpeciesIdTable,
    [SPECIES_GENESECT_CHILL_DRIVE] = sGenesectFormSpeciesIdTable,
#endif
#if P_GEN_6_POKEMON == TRUE
    // Greninja
    [SPECIES_GRENINJA_BATTLE_BOND] = sGreninjaFormSpeciesIdTable,
    [SPECIES_GRENINJA_ASH] = sGreninjaFormSpeciesIdTable,
    // Vivillon
    [SPECIES_VIVILLON_POLAR] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_TUNDRA] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_CONTINENTAL] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_GARDEN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_ELEGANT] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MEADOW] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MODERN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MARINE] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_ARCHIPELAGO] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_HIGH_PLAINS] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_SANDSTORM] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_RIVER] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_MONSOON] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_SAVANNA] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_SUN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_OCEAN] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_JUNGLE] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_FANCY] = sVivillonFormSpeciesIdTable,
    [SPECIES_VIVILLON_POKE_BALL] = sVivillonFormSpeciesIdTable,
    // Flabébé
    [SPECIES_FLABEBE_YELLOW_FLOWER] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLABEBE_ORANGE_FLOWER] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLABEBE_BLUE_FLOWER] = sFlabebeFormSpeciesIdTable,
    [SPECIES_FLABEBE_WHITE_FLOWER] = sFlabebeFormSpeciesIdTable,
    // Floette
    [SPECIES_FLOETTE_YELLOW_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_ORANGE_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_BLUE_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_WHITE_FLOWER] = sFloetteFormSpeciesIdTable,
    [SPECIES_FLOETTE_ETERNAL_FLOWER] = sFloetteFormSpeciesIdTable,
    // Florges
    [SPECIES_FLORGES_YELLOW_FLOWER] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FLORGES_ORANGE_FLOWER] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FLORGES_BLUE_FLOWER] = sFlorgesFormSpeciesIdTable,
    [SPECIES_FLORGES_WHITE_FLOWER] = sFlorgesFormSpeciesIdTable,
    //Furfrou
    [SPECIES_FURFROU_HEART_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_STAR_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_DIAMOND_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_DEBUTANTE_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_MATRON_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_DANDY_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_LA_REINE_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_KABUKI_TRIM] = sFurfrouFormSpeciesIdTable,
    [SPECIES_FURFROU_PHARAOH_TRIM] = sFurfrouFormSpeciesIdTable,
    // Aegislash
    [SPECIES_AEGISLASH_BLADE] = sAegislashFormSpeciesIdTable,
    // Pumpkaboo
    [SPECIES_PUMPKABOO_SMALL] = sPumpkabooFormSpeciesIdTable,
    [SPECIES_PUMPKABOO_LARGE] = sPumpkabooFormSpeciesIdTable,
    [SPECIES_PUMPKABOO_SUPER] = sPumpkabooFormSpeciesIdTable,
    // Gourgeist
    [SPECIES_GOURGEIST_SMALL] = sGourgeistFormSpeciesIdTable,
    [SPECIES_GOURGEIST_LARGE] = sGourgeistFormSpeciesIdTable,
    [SPECIES_GOURGEIST_SUPER] = sGourgeistFormSpeciesIdTable,
    // Xerneas
    [SPECIES_XERNEAS_ACTIVE] = sXerneasFormSpeciesIdTable,
    // Zygarde
    [SPECIES_ZYGARDE_10] = sZygardeFormSpeciesIdTable,
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = sZygardeFormSpeciesIdTable,
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = sZygardeFormSpeciesIdTable,
    [SPECIES_ZYGARDE_COMPLETE] = sZygardeFormSpeciesIdTable,
    // Hoopa
    [SPECIES_HOOPA_UNBOUND] = sHoopaFormSpeciesIdTable,
#endif
#if P_GEN_7_POKEMON == TRUE
    // Oricorio
    [SPECIES_ORICORIO_POM_POM] = sOricorioFormSpeciesIdTable,
    [SPECIES_ORICORIO_PAU] = sOricorioFormSpeciesIdTable,
    [SPECIES_ORICORIO_SENSU] = sOricorioFormSpeciesIdTable,
    // Rockruff
    [SPECIES_ROCKRUFF_OWN_TEMPO] = sRockruffFormSpeciesIdTable,
    // Lycanroc
    [SPECIES_LYCANROC_MIDNIGHT] = sLycanrocFormSpeciesIdTable,
    [SPECIES_LYCANROC_DUSK] = sLycanrocFormSpeciesIdTable,
    // Wishiwashi
    [SPECIES_WISHIWASHI_SCHOOL] = sWishiwashiFormSpeciesIdTable,
    // Silvally
    [SPECIES_SILVALLY_FIGHTING] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_FLYING] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_POISON] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_GROUND] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_ROCK] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_BUG] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_GHOST] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_STEEL] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_FIRE] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_WATER] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_GRASS] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_ELECTRIC] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_PSYCHIC] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_ICE] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_DRAGON] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_DARK] = sSilvallyFormSpeciesIdTable,
    [SPECIES_SILVALLY_FAIRY] = sSilvallyFormSpeciesIdTable,
    // Minior
    [SPECIES_MINIOR_METEOR_ORANGE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_YELLOW] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_GREEN] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_BLUE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_INDIGO] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_METEOR_VIOLET] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_RED] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_ORANGE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_YELLOW] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_GREEN] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_BLUE] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_INDIGO] = sMiniorFormSpeciesIdTable,
    [SPECIES_MINIOR_CORE_VIOLET] = sMiniorFormSpeciesIdTable,
    // Mimikyu
    [SPECIES_MIMIKYU_BUSTED] = sMimikyuFormSpeciesIdTable,
    // Necrozma
    [SPECIES_NECROZMA_DUSK_MANE] = sNecrozmaFormSpeciesIdTable,
    [SPECIES_NECROZMA_DAWN_WINGS] = sNecrozmaFormSpeciesIdTable,
    [SPECIES_NECROZMA_ULTRA] = sNecrozmaFormSpeciesIdTable,
    // Magearna
    [SPECIES_MAGEARNA_ORIGINAL_COLOR] = sMagearnaFormSpeciesIdTable,
#endif
#if P_GEN_8_POKEMON == TRUE
    // Cramorant
    [SPECIES_CRAMORANT_GULPING] = sCramorantFormSpeciesIdTable,
    [SPECIES_CRAMORANT_GORGING] = sCramorantFormSpeciesIdTable,
    // Toxtricity
    [SPECIES_TOXTRICITY_LOW_KEY] = sToxtricityFormSpeciesIdTable,
    // Sinistea
    [SPECIES_SINISTEA_ANTIQUE] = sSinisteaFormSpeciesIdTable,
    // Polteageist
    [SPECIES_POLTEAGEIST_ANTIQUE] = sPolteageistFormSpeciesIdTable,
    // Alcremie
    [SPECIES_ALCREMIE_RUBY_CREAM] = sAlcremieFormSpeciesIdTable,
    [SPECIES_ALCREMIE_MATCHA_CREAM] = sAlcremieFormSpeciesIdTable,
    [SPECIES_ALCREMIE_MINT_CREAM] = sAlcremieFormSpeciesIdTable,
    [SPECIES_ALCREMIE_LEMON_CREAM] = sAlcremieFormSpeciesIdTable,
    [SPECIES_ALCREMIE_SALTED_CREAM] = sAlcremieFormSpeciesIdTable,
    [SPECIES_ALCREMIE_RUBY_SWIRL] = sAlcremieFormSpeciesIdTable,
    [SPECIES_ALCREMIE_CARAMEL_SWIRL] = sAlcremieFormSpeciesIdTable,
    [SPECIES_ALCREMIE_RAINBOW_SWIRL] = sAlcremieFormSpeciesIdTable,
    // Eiscue
    [SPECIES_EISCUE_NOICE_FACE] = sEiscueFormSpeciesIdTable,
    // Morpeko
    [SPECIES_MORPEKO_HANGRY] = sMorpekoFormSpeciesIdTable,
    // Zacian
    [SPECIES_ZACIAN_CROWNED_SWORD] = sZacianFormSpeciesIdTable,
    // Zamazenta
    [SPECIES_ZAMAZENTA_CROWNED_SHIELD] = sZamazentaFormSpeciesIdTable,
    // Eternatus
    [SPECIES_ETERNATUS_ETERNAMAX] = sEternatusFormSpeciesIdTable,
    // Urshifu
    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE] = sUrshifuFormSpeciesIdTable,
    // Zarude
    [SPECIES_ZARUDE_DADA] = sZarudeFormSpeciesIdTable,
    // Calyrex
    [SPECIES_CALYREX_ICE_RIDER] = sCalyrexFormSpeciesIdTable,
    [SPECIES_CALYREX_SHADOW_RIDER] = sCalyrexFormSpeciesIdTable,
    // Enamorus
    [SPECIES_ENAMORUS_THERIAN] = sEnamorusFormSpeciesIdTable,
    // Basculegion
    [SPECIES_BASCULEGION_FEMALE] = sBasculegionFormSpeciesIdTable,
#endif
};
