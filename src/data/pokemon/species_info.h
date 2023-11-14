// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

// Macros to allow editing every form at once
#define FLIP    0
#define NO_FLIP 1

#if P_UPDATED_STATS >= GEN_6
    #define PIKACHU_BASE_DEFENSES\
        .baseDefense   = 40,     \
        .baseSpDefense = 50
#else
    #define PIKACHU_BASE_DEFENSES\
        .baseDefense   = 30,     \
        .baseSpDefense = 40
#endif

#define PIKACHU_SPECIES_INFO(gender, flip)                                 \
    {                                                                      \
        .baseHP        = 35,                                               \
        .baseAttack    = 55,                                               \
        .baseSpeed     = 90,                                               \
        .baseSpAttack  = 50,                                               \
        PIKACHU_BASE_DEFENSES,                                             \
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC},                          \
        .catchRate = 190,                                                  \
        .expYield = 112,                                                   \
        .evYield_Speed     = 2,                                            \
        .itemRare = ITEM_LIGHT_BALL,                                       \
        .genderRatio = gender,                                             \
        .eggCycles = 10,                                                   \
        .friendship = STANDARD_FRIENDSHIP,                                 \
        .growthRate = GROWTH_MEDIUM_FAST,                                  \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY},                  \
        .abilities = {ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD},\
        .bodyColor = BODY_COLOR_YELLOW,                                    \
        .noFlip = flip,                                                    \
    }

#define COSPLAY_PIKACHU_SPECIES_INFO(flip) PIKACHU_SPECIES_INFO(MON_FEMALE, flip)
#define CAP_PIKACHU_SPECIES_INFO(flip)     PIKACHU_SPECIES_INFO(MON_MALE, flip)

#define PICHU_SPECIES_INFO(flip)                                           \
    {                                                                      \
        .baseHP        = 20,                                               \
        .baseAttack    = 40,                                               \
        .baseDefense   = 15,                                               \
        .baseSpeed     = 60,                                               \
        .baseSpAttack  = 35,                                               \
        .baseSpDefense = 35,                                               \
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC},                          \
        .catchRate = 190,                                                  \
        .expYield = 41,                                                    \
        .evYield_Speed     = 1,                                            \
        .genderRatio = PERCENT_FEMALE(50),                                 \
        .eggCycles = 10,                                                   \
        .friendship = STANDARD_FRIENDSHIP,                                 \
        .growthRate = GROWTH_MEDIUM_FAST,                                  \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},    \
        .abilities = {ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD},\
        .bodyColor = BODY_COLOR_YELLOW,                                    \
        .noFlip = flip,                                                    \
    }

#define UNOWN_SPECIES_INFO(flip)                      \
    {                                                 \
        .baseHP        = 48,                          \
        .baseAttack    = 72,                          \
        .baseDefense   = 48,                          \
        .baseSpeed     = 48,                          \
        .baseSpAttack  = 72,                          \
        .baseSpDefense = 48,                          \
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},       \
        .catchRate = 225,                             \
        .expYield = 118,                              \
        .evYield_Attack    = 1,                       \
        .evYield_SpAttack  = 1,                       \
        .genderRatio = MON_GENDERLESS,                \
        .eggCycles = 40,                              \
        .friendship = STANDARD_FRIENDSHIP,            \
        .growthRate = GROWTH_MEDIUM_FAST,             \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},          \
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_BLACK,                \
        .noFlip = flip,                               \
    }

#define CASTFORM_SPECIES_INFO(type, color)            \
    {                                                 \
        .baseHP        = 70,                          \
        .baseAttack    = 70,                          \
        .baseDefense   = 70,                          \
        .baseSpeed     = 70,                          \
        .baseSpAttack  = 70,                          \
        .baseSpDefense = 70,                          \
        .types = { type, type },                      \
        .catchRate = 45,                              \
        .expYield = 147,                              \
        .evYield_HP        = 1,                       \
        .itemCommon = ITEM_MYSTIC_WATER,              \
        .itemRare = ITEM_MYSTIC_WATER,                \
        .genderRatio = PERCENT_FEMALE(50),            \
        .eggCycles = 25,                              \
        .friendship = STANDARD_FRIENDSHIP,                             \
        .growthRate = GROWTH_MEDIUM_FAST,             \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS},             \
        .abilities = {ABILITY_FORECAST, ABILITY_NONE},\
        .bodyColor = color,                           \
        .noFlip = FALSE,                              \
    }

#define CHERRIM_SPECIES_INFO(color)                      \
    {                                                    \
        .baseHP        = 70,                             \
        .baseAttack    = 60,                             \
        .baseDefense   = 70,                             \
        .baseSpeed     = 85,                             \
        .baseSpAttack  = 87,                             \
        .baseSpDefense = 78,                             \
        .types = { TYPE_GRASS, TYPE_GRASS},              \
        .catchRate = 75,                                 \
        .expYield = 158,                                 \
        .evYield_SpAttack  = 2,                          \
        .itemRare = ITEM_MIRACLE_SEED,                   \
        .genderRatio = PERCENT_FEMALE(50),               \
        .eggCycles = 20,                                 \
        .friendship = STANDARD_FRIENDSHIP,                                \
        .growthRate = GROWTH_MEDIUM_FAST,                \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_GRASS},                    \
        .abilities = {ABILITY_FLOWER_GIFT, ABILITY_NONE},\
        .bodyColor = color,                              \
        .noFlip = FALSE,                                 \
    }

#define SHELLOS_SPECIES_INFO(color)                                                 \
    {                                                                               \
        .baseHP        = 76,                                                        \
        .baseAttack    = 48,                                                        \
        .baseDefense   = 48,                                                        \
        .baseSpeed     = 34,                                                        \
        .baseSpAttack  = 57,                                                        \
        .baseSpDefense = 62,                                                        \
        .types = { TYPE_WATER, TYPE_WATER},                                         \
        .catchRate = 190,                                                           \
        .expYield = 65,                                                             \
        .evYield_HP        = 1,                                                     \
        .genderRatio = PERCENT_FEMALE(50),                                          \
        .eggCycles = 20,                                                            \
        .friendship = STANDARD_FRIENDSHIP,                                                           \
        .growthRate = GROWTH_MEDIUM_FAST,                                           \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS},                                           \
        .abilities = {ABILITY_STICKY_HOLD, ABILITY_STORM_DRAIN, ABILITY_SAND_FORCE},\
        .bodyColor = color,                                                         \
        .noFlip = FALSE,                                                            \
    }

#define GASTRODON_SPECIES_INFO(color)                                               \
    {                                                                               \
        .baseHP        = 111,                                                       \
        .baseAttack    = 83,                                                        \
        .baseDefense   = 68,                                                        \
        .baseSpeed     = 39,                                                        \
        .baseSpAttack  = 92,                                                        \
        .baseSpDefense = 82,                                                        \
        .types = { TYPE_WATER, TYPE_GROUND},                                        \
        .catchRate = 75,                                                            \
        .expYield = 166,                                                            \
        .evYield_HP        = 2,                                                     \
        .genderRatio = PERCENT_FEMALE(50),                                          \
        .eggCycles = 20,                                                            \
        .friendship = STANDARD_FRIENDSHIP,                                                           \
        .growthRate = GROWTH_MEDIUM_FAST,                                           \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS},                                           \
        .abilities = {ABILITY_STICKY_HOLD, ABILITY_STORM_DRAIN, ABILITY_SAND_FORCE},\
        .bodyColor = color,                                                         \
        .noFlip = FALSE,                                                            \
    }

#define ROTOM_FORM_SPECIES_INFO(type, flip)           \
    {                                                 \
        .baseHP        = 50,                          \
        .baseAttack    = 65,                          \
        .baseDefense   = 107,                         \
        .baseSpeed     = 86,                          \
        .baseSpAttack  = 105,                         \
        .baseSpDefense = 107,                         \
        .types = { TYPE_ELECTRIC, type },             \
        .catchRate = 45,                              \
        .expYield = 182,                              \
        .evYield_Speed     = 1,                       \
        .evYield_SpAttack  = 1,                       \
        .genderRatio = MON_GENDERLESS,                \
        .eggCycles = 20,                              \
        .friendship = STANDARD_FRIENDSHIP,                             \
        .growthRate = GROWTH_MEDIUM_FAST,             \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},             \
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_RED,                  \
        .noFlip = flip,                               \
    }

#define ARCEUS_SPECIES_INFO(type)                      \
    {                                                  \
        .baseHP        = 120,                          \
        .baseAttack    = 120,                          \
        .baseDefense   = 120,                          \
        .baseSpeed     = 120,                          \
        .baseSpAttack  = 120,                          \
        .baseSpDefense = 120,                          \
        .types = { type, type },                       \
        .catchRate = 3,                                \
        .expYield = 324,                               \
        .evYield_HP        = 3,                        \
        .genderRatio = MON_GENDERLESS,                 \
        .eggCycles = 120,                              \
        .friendship = 0,                               \
        .growthRate = GROWTH_SLOW,                     \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},           \
        .abilities = {ABILITY_MULTITYPE, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_WHITE,                 \
        .noFlip = FALSE,                               \
        .flags = SPECIES_FLAG_MYTHICAL,                \
    }

#define DEERLING_SPECIES_INFO(color)                                                 \
    {                                                                                \
        .baseHP        = 60,                                                         \
        .baseAttack    = 60,                                                         \
        .baseDefense   = 50,                                                         \
        .baseSpeed     = 75,                                                         \
        .baseSpAttack  = 40,                                                         \
        .baseSpDefense = 50,                                                         \
        .types = { TYPE_NORMAL, TYPE_GRASS},                                         \
        .catchRate = 190,                                                            \
        .expYield = 67,                                                              \
        .evYield_Speed     = 1,                                                      \
        .genderRatio = PERCENT_FEMALE(50),                                           \
        .eggCycles = 20,                                                             \
        .friendship = STANDARD_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_MEDIUM_FAST,                                            \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},                                                \
        .abilities = {ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE},\
        .bodyColor = color,                                                          \
        .noFlip = FALSE,                                                             \
    }

#define SAWSBUCK_SPECIES_INFO                                                        \
    {                                                                                \
        .baseHP        = 80,                                                         \
        .baseAttack    = 100,                                                        \
        .baseDefense   = 70,                                                         \
        .baseSpeed     = 95,                                                         \
        .baseSpAttack  = 60,                                                         \
        .baseSpDefense = 70,                                                         \
        .types = { TYPE_NORMAL, TYPE_GRASS},                                         \
        .catchRate = 75,                                                             \
        .expYield = 166,                                                             \
        .evYield_Attack    = 2,                                                      \
        .genderRatio = PERCENT_FEMALE(50),                                           \
        .eggCycles = 20,                                                             \
        .friendship = STANDARD_FRIENDSHIP,                                                            \
        .growthRate = GROWTH_MEDIUM_FAST,                                            \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},                                                \
        .abilities = {ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE},\
        .bodyColor = BODY_COLOR_BROWN,                                               \
        .noFlip = FALSE,                                                             \
    }

#define GENESECT_SPECIES_INFO                         \
    {                                                 \
        .baseHP        = 71,                          \
        .baseAttack    = 120,                         \
        .baseDefense   = 95,                          \
        .baseSpeed     = 99,                          \
        .baseSpAttack  = 120,                         \
        .baseSpDefense = 95,                          \
        .types = { TYPE_BUG, TYPE_STEEL},             \
        .catchRate = 3,                               \
        .expYield = 270,                              \
        .evYield_Attack    = 1,                       \
        .evYield_Speed     = 1,                       \
        .evYield_SpAttack  = 1,                       \
        .genderRatio = MON_GENDERLESS,                \
        .eggCycles = 120,                             \
        .friendship = 0,                              \
        .growthRate = GROWTH_SLOW,                    \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},          \
        .abilities = {ABILITY_DOWNLOAD, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_PURPLE,               \
        .noFlip = FALSE,                              \
        .flags = SPECIES_FLAG_MYTHICAL,               \
    }

#define VIVILLON_SPECIES_INFO(color)                                                    \
    {                                                                                   \
        .baseHP        = 80,                                                            \
        .baseAttack    = 52,                                                            \
        .baseDefense   = 50,                                                            \
        .baseSpeed     = 89,                                                            \
        .baseSpAttack  = 90,                                                            \
        .baseSpDefense = 50,                                                            \
        .types = { TYPE_BUG, TYPE_FLYING},                                              \
        .catchRate = 45,                                                                \
        .expYield = 185,                                                                \
        .evYield_HP        = 1,                                                         \
        .evYield_Speed     = 1,                                                         \
        .evYield_SpAttack  = 1,                                                         \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 15,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                                               \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},                                                     \
        .abilities = {ABILITY_SHIELD_DUST, ABILITY_COMPOUND_EYES, ABILITY_FRIEND_GUARD},\
        .bodyColor = color,                                                             \
        .noFlip = FALSE,                                                                \
    }

#define FLABEBE_SPECIES_INFO                                                \
    {                                                                       \
        .baseHP        = 44,                                                \
        .baseAttack    = 38,                                                \
        .baseDefense   = 39,                                                \
        .baseSpeed     = 42,                                                \
        .baseSpAttack  = 61,                                                \
        .baseSpDefense = 79,                                                \
        .types = { TYPE_FAIRY, TYPE_FAIRY},                                 \
        .catchRate = 225,                                                   \
        .expYield = 61,                                                     \
        .evYield_SpDefense = 1,                                             \
        .genderRatio = MON_FEMALE,                                          \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                   \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY},                                       \
        .abilities = {ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS},\
        .bodyColor = BODY_COLOR_WHITE,                                      \
        .noFlip = FALSE,                                                    \
    }

#define FLOETTE_SPECIES_INFO                                                \
    {                                                                       \
        .baseHP        = 54,                                                \
        .baseAttack    = 45,                                                \
        .baseDefense   = 47,                                                \
        .baseSpeed     = 52,                                                \
        .baseSpAttack  = 75,                                                \
        .baseSpDefense = 98,                                                \
        .types = { TYPE_FAIRY, TYPE_FAIRY},                                 \
        .catchRate = 120,                                                   \
        .expYield = 130,                                                    \
        .evYield_SpDefense = 2,                                             \
        .genderRatio = MON_FEMALE,                                          \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                   \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY},                                       \
        .abilities = {ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS},\
        .bodyColor = BODY_COLOR_WHITE,                                      \
        .noFlip = FALSE,                                                    \
    }

#define FLORGES_SPECIES_INFO                                                \
    {                                                                       \
        .baseHP        = 78,                                                \
        .baseAttack    = 65,                                                \
        .baseDefense   = 68,                                                \
        .baseSpeed     = 75,                                                \
        .baseSpAttack  = 112,                                               \
        .baseSpDefense = 154,                                               \
        .types = { TYPE_FAIRY, TYPE_FAIRY},                                 \
        .catchRate = 45,                                                    \
        .expYield = 248,                                                    \
        .evYield_SpDefense = 3,                                             \
        .genderRatio = MON_FEMALE,                                          \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                   \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY},                                       \
        .abilities = {ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS},\
        .bodyColor = BODY_COLOR_WHITE,                                      \
        .noFlip = FALSE,                                                    \
    }

#define FURFROU_SPECIES_INFO(flip)                    \
    {                                                 \
        .baseHP        = 75,                          \
        .baseAttack    = 80,                          \
        .baseDefense   = 60,                          \
        .baseSpeed     = 102,                         \
        .baseSpAttack  = 65,                          \
        .baseSpDefense = 90,                          \
        .types = { TYPE_NORMAL, TYPE_NORMAL},         \
        .catchRate = 160,                             \
        .expYield = 165,                              \
        .evYield_Speed     = 1,                       \
        .genderRatio = PERCENT_FEMALE(50),            \
        .eggCycles = 20,                              \
        .friendship = STANDARD_FRIENDSHIP,                             \
        .growthRate = GROWTH_MEDIUM_FAST,             \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},                 \
        .abilities = {ABILITY_FUR_COAT, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_WHITE,                \
        .noFlip = flip,                               \
    }

#define PUMKPABOO_MISC_INFO                                            \
        .types = { TYPE_GHOST, TYPE_GRASS},                            \
        .catchRate = 120,                                              \
        .expYield = 67,                                                \
        .evYield_Defense   = 1,                                        \
        .genderRatio = PERCENT_FEMALE(50),                             \
        .eggCycles = 20,                                               \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                              \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},                              \
        .abilities = {ABILITY_PICKUP, ABILITY_FRISK, ABILITY_INSOMNIA},\
        .bodyColor = BODY_COLOR_BROWN,                                 \
        .noFlip = FALSE

#define GOURGEIST_MISC_INFO                                            \
        .types = { TYPE_GHOST, TYPE_GRASS},                            \
        .catchRate = 60,                                               \
        .expYield = 173,                                               \
        .evYield_Defense   = 2,                                        \
        .genderRatio = PERCENT_FEMALE(50),                             \
        .eggCycles = 20,                                               \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                              \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},                              \
        .abilities = {ABILITY_PICKUP, ABILITY_FRISK, ABILITY_INSOMNIA},\
        .bodyColor = BODY_COLOR_BROWN,                                 \
        .noFlip = FALSE

#define XERNEAS_SPECIES_INFO                            \
    {                                                   \
        .baseHP        = 126,                           \
        .baseAttack    = 131,                           \
        .baseDefense   = 95,                            \
        .baseSpeed     = 99,                            \
        .baseSpAttack  = 131,                           \
        .baseSpDefense = 98,                            \
        .types = { TYPE_FAIRY, TYPE_FAIRY},             \
        .catchRate = 45,                                \
        .expYield = 306,                                \
        .evYield_HP        = 3,                         \
        .genderRatio = MON_GENDERLESS,                  \
        .eggCycles = 120,                               \
        .friendship = 0,                                \
        .growthRate = GROWTH_SLOW,                      \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},            \
        .abilities = {ABILITY_FAIRY_AURA, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_BLUE,                   \
        .noFlip = FALSE,                                \
        .flags = SPECIES_FLAG_LEGENDARY,                \
    }

#define ZYGARDE_50_SPECIES_INFO(ability)     \
    {                                        \
        .baseHP        = 108,                \
        .baseAttack    = 100,                \
        .baseDefense   = 121,                \
        .baseSpeed     = 95,                 \
        .baseSpAttack  = 81,                 \
        .baseSpDefense = 95,                 \
        .types = { TYPE_DRAGON, TYPE_GROUND},\
        .catchRate = 3,                      \
        .expYield = 270,                     \
        .evYield_HP        = 3,              \
        .genderRatio = MON_GENDERLESS,       \
        .eggCycles = 120,                    \
        .friendship = 0,                     \
        .growthRate = GROWTH_SLOW,           \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED}, \
        .abilities = {ability, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_GREEN,       \
        .noFlip = TRUE,                      \
        .flags = SPECIES_FLAG_LEGENDARY,     \
    }

#define ZYGARDE_10_SPECIES_INFO(ability)     \
    {                                        \
        .baseHP        = 54,                 \
        .baseAttack    = 100,                \
        .baseDefense   = 71,                 \
        .baseSpeed     = 115,                \
        .baseSpAttack  = 61,                 \
        .baseSpDefense = 85,                 \
        .types = { TYPE_DRAGON, TYPE_GROUND},\
        .catchRate = 3,                      \
        .expYield = 219,                     \
        .evYield_HP        = 3,              \
        .genderRatio = MON_GENDERLESS,       \
        .eggCycles = 120,                    \
        .friendship = 0,                     \
        .growthRate = GROWTH_SLOW,           \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED}, \
        .abilities = {ability, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_BLACK,       \
        .noFlip = TRUE,                      \
        .flags = SPECIES_FLAG_LEGENDARY,     \
    }

#define ORICORIO_SPECIES_INFO(type, color)          \
{                                                   \
        .baseHP        = 75,                        \
        .baseAttack    = 70,                        \
        .baseDefense   = 70,                        \
        .baseSpeed     = 93,                        \
        .baseSpAttack  = 98,                        \
        .baseSpDefense = 70,                        \
        .types = { type, TYPE_FLYING },             \
        .catchRate = 45,                            \
        .expYield = 167,                            \
        .evYield_SpAttack  = 2,                     \
        .itemRare = ITEM_HONEY,                     \
        .genderRatio = PERCENT_FEMALE(75),          \
        .eggCycles = 20,                            \
        .friendship = STANDARD_FRIENDSHIP,                           \
        .growthRate = GROWTH_MEDIUM_FAST,           \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING},              \
        .abilities = {ABILITY_DANCER, ABILITY_NONE},\
        .bodyColor = color,                         \
        .noFlip = FALSE,                            \
    }

#define ROCKRUFF_SPECIES_INFO(ability1, ability2, hiddenAbility)\
    {                                                           \
        .baseHP        = 45,                                    \
        .baseAttack    = 65,                                    \
        .baseDefense   = 40,                                    \
        .baseSpeed     = 60,                                    \
        .baseSpAttack  = 30,                                    \
        .baseSpDefense = 40,                                    \
        .types = { TYPE_ROCK, TYPE_ROCK},                       \
        .catchRate = 190,                                       \
        .expYield = 56,                                         \
        .evYield_Attack    = 1,                                 \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 15,                                        \
        .friendship = STANDARD_FRIENDSHIP,                                       \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},                           \
        .abilities = {ability1, ability2, hiddenAbility},       \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .noFlip = FALSE,                                        \
    }

#define SILVALLY_SPECIES_INFO(type)                     \
    {                                                   \
        .baseHP        = 95,                            \
        .baseAttack    = 95,                            \
        .baseDefense   = 95,                            \
        .baseSpeed     = 95,                            \
        .baseSpAttack  = 95,                            \
        .baseSpDefense = 95,                            \
        .types = { type, type },                        \
        .catchRate = 3,                                 \
        .expYield = 257,                                \
        .evYield_HP        = 3,                         \
        .genderRatio = MON_GENDERLESS,                  \
        .eggCycles = 120,                               \
        .friendship = 0,                                \
        .growthRate = GROWTH_SLOW,                      \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},            \
        .abilities = {ABILITY_RKS_SYSTEM, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_GRAY,                   \
        .noFlip = FALSE,                                \
        .flags = SPECIES_FLAG_LEGENDARY,                \
    }

#define MINIOR_METEOR_ATTRIBUTES\
        .baseHP        = 60,    \
        .baseAttack    = 60,    \
        .baseDefense   = 110,   \
        .baseSpeed     = 60,    \
        .baseSpAttack  = 60,    \
        .baseSpDefense = 110

#define MINIOR_CORE_ATTRIBUTES\
        .baseHP        = 60,  \
        .baseAttack    = 110, \
        .baseDefense   = 60,  \
        .baseSpeed     = 120, \
        .baseSpAttack  = 110, \
        .baseSpDefense = 60

#define MINIOR_MISC_INFO(color)                             \
        .types = { TYPE_ROCK, TYPE_FLYING},                 \
        .catchRate = 30,                                    \
        .expYield = 154,                                    \
        .evYield_Defense   = 1,                             \
        .evYield_SpDefense = 1,                             \
        .itemRare = ITEM_STAR_PIECE,                        \
        .genderRatio = MON_GENDERLESS,                      \
        .eggCycles = 25,                                    \
        .friendship = STANDARD_FRIENDSHIP,                                   \
        .growthRate = GROWTH_MEDIUM_SLOW,                   \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},                     \
        .abilities = {ABILITY_SHIELDS_DOWN, ABILITY_NONE},  \
        .bodyColor = color,                                 \
        .noFlip = TRUE

#define MINIOR_METEOR_SPECIES_INFO          \
    {                                       \
        MINIOR_METEOR_ATTRIBUTES,           \
        MINIOR_MISC_INFO(BODY_COLOR_BROWN), \
    }


#define MINIOR_CORE_SPECIES_INFO(color) \
    {                                   \
        MINIOR_CORE_ATTRIBUTES,         \
        MINIOR_MISC_INFO(color),        \
    }

#define MIMIKYU_SPECIES_INFO                          \
    {                                                 \
        .baseHP        = 55,                          \
        .baseAttack    = 90,                          \
        .baseDefense   = 80,                          \
        .baseSpeed     = 96,                          \
        .baseSpAttack  = 50,                          \
        .baseSpDefense = 105,                         \
        .types = { TYPE_GHOST, TYPE_FAIRY},           \
        .catchRate = 45,                              \
        .expYield = 167,                              \
        .evYield_SpDefense = 2,                       \
        .itemRare = ITEM_CHESTO_BERRY,                \
        .genderRatio = PERCENT_FEMALE(50),            \
        .eggCycles = 20,                              \
        .friendship = STANDARD_FRIENDSHIP,                             \
        .growthRate = GROWTH_MEDIUM_FAST,             \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},             \
        .abilities = {ABILITY_DISGUISE, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_YELLOW,               \
        .noFlip = FALSE,                              \
    }

#define MAGEARNA_SPECIES_INFO(color)                    \
    {                                                   \
        .baseHP        = 80,                            \
        .baseAttack    = 95,                            \
        .baseDefense   = 115,                           \
        .baseSpeed     = 65,                            \
        .baseSpAttack  = 130,                           \
        .baseSpDefense = 115,                           \
        .types = { TYPE_STEEL, TYPE_FAIRY},             \
        .catchRate = 3,                                 \
        .expYield = 270,                                \
        .evYield_SpAttack  = 3,                         \
        .genderRatio = MON_GENDERLESS,                  \
        .eggCycles = 120,                               \
        .friendship = 0,                                \
        .growthRate = GROWTH_SLOW,                      \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},            \
        .abilities = {ABILITY_SOUL_HEART, ABILITY_NONE},\
        .bodyColor = color,                             \
        .noFlip = FALSE,                                \
        .flags = SPECIES_FLAG_MYTHICAL,                 \
    }

#define CRAMORANT_SPECIES_INFO                            \
    {                                                     \
        .baseHP        = 70,                              \
        .baseAttack    = 85,                              \
        .baseDefense   = 55,                              \
        .baseSpeed     = 85,                              \
        .baseSpAttack  = 85,                              \
        .baseSpDefense = 95,                              \
        .types = { TYPE_FLYING, TYPE_WATER},              \
        .catchRate = 45,                                  \
        .expYield = 166,                                  \
        .evYield_SpDefense = 2,                           \
        .genderRatio = PERCENT_FEMALE(50),                \
        .eggCycles = 20,                                  \
        .friendship = STANDARD_FRIENDSHIP,                                 \
        .growthRate = GROWTH_MEDIUM_FAST,                 \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FLYING},                    \
        .abilities = {ABILITY_GULP_MISSILE, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_BLUE,                     \
        .noFlip = FALSE,                                  \
    }

#define TOXTRICITY_SPECIES_INFO(ability2)                              \
    {                                                                  \
        .baseHP        = 75,                                           \
        .baseAttack    = 98,                                           \
        .baseDefense   = 70,                                           \
        .baseSpeed     = 75,                                           \
        .baseSpAttack  = 114,                                          \
        .baseSpDefense = 70,                                           \
        .types = { TYPE_ELECTRIC, TYPE_POISON},                        \
        .catchRate = 45,                                               \
        .expYield = 176,                                               \
        .evYield_SpAttack  = 2,                                        \
        .genderRatio = PERCENT_FEMALE(50),                             \
        .eggCycles = 25,                                               \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_SLOW,                              \
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE},                             \
        .abilities = {ABILITY_PUNK_ROCK, ability2, ABILITY_TECHNICIAN},\
        .bodyColor = BODY_COLOR_PURPLE,                                \
        .noFlip = FALSE,                                               \
    }

#define SINISTEA_SPECIES_INFO                                                \
    {                                                                        \
        .baseHP        = 40,                                                 \
        .baseAttack    = 45,                                                 \
        .baseDefense   = 45,                                                 \
        .baseSpeed     = 50,                                                 \
        .baseSpAttack  = 74,                                                 \
        .baseSpDefense = 54,                                                 \
        .types = { TYPE_GHOST, TYPE_GHOST},                                  \
        .catchRate = 120,                                                    \
        .expYield = 62,                                                      \
        .evYield_SpAttack  = 1,                                              \
        .genderRatio = MON_GENDERLESS,                                       \
        .eggCycles = 20,                                                     \
        .friendship = STANDARD_FRIENDSHIP,                                                    \
        .growthRate = GROWTH_MEDIUM_FAST,                                    \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS},                                    \
        .abilities = {ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY},\
        .bodyColor = BODY_COLOR_PURPLE,                                      \
        .noFlip = FALSE,                                                     \
    }

#define POLTEAGEIST_SPECIES_INFO                                             \
    {                                                                        \
        .baseHP        = 60,                                                 \
        .baseAttack    = 65,                                                 \
        .baseDefense   = 65,                                                 \
        .baseSpeed     = 70,                                                 \
        .baseSpAttack  = 134,                                                \
        .baseSpDefense = 114,                                                \
        .types = { TYPE_GHOST, TYPE_GHOST},                                  \
        .catchRate = 60,                                                     \
        .expYield = 178,                                                     \
        .evYield_SpAttack  = 2,                                              \
        .genderRatio = MON_GENDERLESS,                                       \
        .eggCycles = 20,                                                     \
        .friendship = STANDARD_FRIENDSHIP,                                                    \
        .growthRate = GROWTH_MEDIUM_FAST,                                    \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS},                                    \
        .abilities = {ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY},\
        .bodyColor = BODY_COLOR_PURPLE,                                      \
        .noFlip = FALSE,                                                     \
    }

#define ALCREMIE_SPECIES_INFO(color)                                        \
    {                                                                       \
        .baseHP        = 65,                                                \
        .baseAttack    = 60,                                                \
        .baseDefense   = 75,                                                \
        .baseSpeed     = 64,                                                \
        .baseSpAttack  = 110,                                               \
        .baseSpDefense = 121,                                               \
        .types = { TYPE_FAIRY, TYPE_FAIRY},                                 \
        .catchRate = 100,                                                   \
        .expYield = 173,                                                    \
        .evYield_SpDefense = 2,                                             \
        .genderRatio = MON_FEMALE,                                          \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                   \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS},                                   \
        .abilities = {ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_AROMA_VEIL},\
        .bodyColor = color,                                                 \
        .noFlip = FALSE,                                                    \
    }

#define MORPEKO_SPECIES_INFO                               \
    {                                                      \
        .baseHP        = 58,                               \
        .baseAttack    = 95,                               \
        .baseDefense   = 58,                               \
        .baseSpeed     = 97,                               \
        .baseSpAttack  = 70,                               \
        .baseSpDefense = 58,                               \
        .types = { TYPE_ELECTRIC, TYPE_DARK},              \
        .catchRate = 180,                                  \
        .expYield = 153,                                   \
        .evYield_Speed     = 2,                            \
        .genderRatio = PERCENT_FEMALE(50),                 \
        .eggCycles = 10,                                   \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                  \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY},                      \
        .abilities = {ABILITY_HUNGER_SWITCH, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_YELLOW,                    \
        .noFlip = FALSE,                                   \
    }

#define ZARUDE_SPECIES_INFO                             \
    {                                                   \
        .baseHP        = 105,                           \
        .baseAttack    = 120,                           \
        .baseDefense   = 105,                           \
        .baseSpeed     = 105,                           \
        .baseSpAttack  = 70,                            \
        .baseSpDefense = 95,                            \
        .types = { TYPE_DARK, TYPE_GRASS},              \
        .catchRate = 3,                                 \
        .expYield = 300,                                \
        .evYield_Attack    = 3,                         \
        .genderRatio = MON_GENDERLESS,                  \
        .eggCycles = 120,                               \
        .friendship = 0,                                \
        .growthRate = GROWTH_SLOW,                      \
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},            \
        .abilities = {ABILITY_LEAF_GUARD, ABILITY_NONE},\
        .bodyColor = BODY_COLOR_GREEN,                  \
        .noFlip = FALSE,                                \
        .flags = SPECIES_FLAG_MYTHICAL,                 \
    }

const struct SpeciesInfo gSpeciesInfo[] =
{
    [SPECIES_NONE] = {0},

    [SPECIES_BULBASAUR] =
    {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 49,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS},
        .abilities = {ABILITY_OVERGROW, ABILITY_CHLOROPHYLL, ABILITY_OVERGROW, ABILITY_CHLOROPHYLL},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_IVYSAUR] =
    {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 63,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 45,
        .expYield = 142,
        .evYield_SpAttack  = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS},
        .abilities = {ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CHLOROPHYLL},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_VENUSAUR] =
    {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 83,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 45,
        .expYield = 236,
        .evYield_SpAttack  = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS},
        .abilities = {ABILITY_OVERGROW, ABILITY_MIASMA, ABILITY_CHLOROPHYLL},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_CHARMANDER] =
    {
        .baseHP        = 39,
        .baseAttack    = 52,
        .baseDefense   = 43,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_CHARMELEON] =
    {
        .baseHP        = 58,
        .baseAttack    = 64,
        .baseDefense   = 58,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 65,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_CHARIZARD] =
    {
        .baseHP        = 78,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = 109,
        .baseSpDefense = 85,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 240,
        .evYield_SpAttack  = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_BLAZE, ABILITY_NONE, ABILITY_SOLAR_POWER},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_SQUIRTLE] =
    {
        .baseHP        = 44,
        .baseAttack    = 48,
        .baseDefense   = 65,
        .baseSpeed     = 43,
        .baseSpAttack  = 50,
        .baseSpDefense = 64,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 63,
        .evYield_Defense   = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_RAIN_DISH},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_WARTORTLE] =
    {
        .baseHP        = 59,
        .baseAttack    = 63,
        .baseDefense   = 80,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = 80,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Defense   = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_RAIN_DISH},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_BLASTOISE] =
    {
        .baseHP        = 79,
        .baseAttack    = 83,
        .baseDefense   = 100,
        .baseSpeed     = 78,
        .baseSpAttack  = 85,
        .baseSpDefense = 105,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 239,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_RAIN_DISH},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },
    [SPECIES_RATTATA] =
    {
        .baseHP        = 30,
        .baseAttack    = 56,
        .baseDefense   = 35,
        .baseSpeed     = 72,
        .baseSpAttack  = 25,
        .baseSpDefense = 35,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 51,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_RUN_AWAY, ABILITY_GUTS, ABILITY_HUSTLE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_RATICATE] =
    {
        .baseHP        = 55,
        .baseAttack    = 81,
        .baseDefense   = 60,
        .baseSpeed     = 97,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 127,
        .expYield = 145,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_RUN_AWAY, ABILITY_GUTS, ABILITY_HUSTLE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_PIKACHU] = PIKACHU_SPECIES_INFO(PERCENT_FEMALE(50), FLIP),

    [SPECIES_RAICHU] =
    {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 55,
        .baseSpAttack  = 90,
        .baseSpDefense = 80,
        #if P_UPDATED_STATS >= GEN_6
            .baseSpeed     = 110,
        #else
            .baseSpeed     = 100,
        #endif
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC},
        .catchRate = 75,
        .expYield = 218,
        .evYield_Speed     = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_STATIC, ABILITY_NONE, ABILITY_LIGHTNING_ROD},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_SANDSHREW] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense   = 1,
        .itemRare = ITEM_GRIP_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_SAND_RUSH},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_SANDSLASH] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 90,
        .expYield = 158,
        .evYield_Defense   = 2,
        .itemRare = ITEM_GRIP_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_SAND_RUSH},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },
    [SPECIES_VULPIX] =
    {
        .baseHP        = 38,
        .baseAttack    = 41,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 60,
        .evYield_Speed     = 1,
        .itemRare = ITEM_CHARCOAL,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_DROUGHT},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_NINETALES] =
    {
        .baseHP        = 73,
        .baseAttack    = 76,
        .baseDefense   = 75,
        .baseSpeed     = 100,
        .baseSpAttack  = 81,
        .baseSpDefense = 100,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 75,
        .expYield = 177,
        .evYield_Speed     = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_CHARCOAL,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_DROUGHT},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_DIGLETT] =
    {
        .baseHP        = 10,
        .baseAttack    = 55,
        .baseDefense   = 25,
        .baseSpeed     = 95,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 255,
        .expYield = 53,
        .evYield_Speed     = 1,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_ARENA_TRAP, ABILITY_SAND_FORCE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_DUGTRIO] =
    {
        .baseHP        = 35,
        .baseDefense   = 50,
        .baseSpeed     = 120,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        #if P_UPDATED_STATS >= GEN_7
            .baseAttack    = 100,
        #else
            .baseAttack    = 80,
        #endif
        .types = { TYPE_GROUND, TYPE_GROUND},
        .catchRate = 50,
        .expYield = 149,
        .evYield_Speed     = 2,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_ARENA_TRAP, ABILITY_SAND_FORCE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_MEOWTH] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 58,
        .evYield_Speed     = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_PICKUP, ABILITY_TECHNICIAN, ABILITY_UNNERVE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_PERSIAN] =
    {
        .baseHP        = 65,
        .baseAttack    = 70,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 90,
        .expYield = 154,
        .evYield_Speed     = 2,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_LIMBER, ABILITY_TECHNICIAN, ABILITY_UNNERVE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },
    [SPECIES_GEODUDE] =
    {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 20,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_ROCK, TYPE_GROUND },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense   = 1,
        .itemRare = ITEM_EVERSTONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SAND_VEIL},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_GRAVELER] =
    {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_GROUND },
        .catchRate = 120,
        .expYield = 137,
        .evYield_Defense   = 2,
        .itemRare = ITEM_EVERSTONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SAND_VEIL},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_GOLEM] =
    {
        .baseHP        = 80,
        .baseDefense   = 130,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        #if P_UPDATED_STATS >= GEN_6
            .baseAttack    = 120,
        #else
            .baseAttack    = 110,
        #endif
        .types = { TYPE_ROCK, TYPE_GROUND},
        .catchRate = 45,
        .expYield = 223,
        .evYield_Defense   = 3,
        .itemRare = ITEM_EVERSTONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_ROCK_HEAD, ABILITY_STURDY, ABILITY_SAND_VEIL},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_PONYTA] =
    {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 82,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_RUN_AWAY, ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_RAPIDASH] =
    {
        .baseHP        = 65,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 105,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 60,
        .expYield = 175,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_RUN_AWAY, ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_SLOWPOKE] =
    {
        .baseHP        = 90,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 15,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_WATER, TYPE_PSYCHIC },
        .catchRate = 190,
        .expYield = 63,
        .evYield_HP        = 1,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_OBLIVIOUS, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },

    [SPECIES_SLOWBRO] =
    {
        .baseHP        = 95,
        .baseAttack    = 75,
        .baseDefense   = 110,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 80,
        .types = { TYPE_WATER, TYPE_PSYCHIC },
        .catchRate = 75,
        .expYield = 172,
        .evYield_Defense   = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_OBLIVIOUS, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },

    [SPECIES_FARFETCHD] =
    {
        .baseHP        = 52,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 58,
        .baseSpDefense = 62,
        #if P_UPDATED_STATS >= GEN_7
            .baseAttack    = 90,
        #else
            .baseAttack    = 65,
        #endif
        .types = { TYPE_NORMAL, TYPE_FLYING},
        .catchRate = 45,
        .expYield = 132,
        .evYield_Attack    = 1,
        .itemRare = ITEM_LEEK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FIELD},
        .abilities = {ABILITY_KEEN_EYE, ABILITY_INNER_FOCUS, ABILITY_DEFIANT},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },
    [SPECIES_GRIMER] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 190,
        .expYield = 65,
        .evYield_HP        = 1,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_STENCH, ABILITY_STICKY_HOLD, ABILITY_POISON_TOUCH},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_MUK] =
    {
        .baseHP        = 105,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 100,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 75,
        .expYield = 175,
        .evYield_HP        = 1,
        .evYield_Attack    = 1,
        .itemCommon = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_STENCH, ABILITY_STICKY_HOLD, ABILITY_POISON_TOUCH},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_MR_MIME] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 65,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 120,
        #if P_UPDATED_TYPES >= GEN_6
            .types = { TYPE_PSYCHIC, TYPE_FAIRY},
        #else
            .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        #endif
        .catchRate = 45,
        .expYield = 161,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE},
        .abilities = {ABILITY_SOUNDPROOF, ABILITY_FILTER, ABILITY_TECHNICIAN},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },
    [SPECIES_DITTO] =
    {
        .baseHP        = 48,
        .baseAttack    = 48,
        .baseDefense   = 48,
        .baseSpeed     = 48,
        .baseSpAttack  = 48,
        .baseSpDefense = 48,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 35,
        .expYield = 101,
        .evYield_HP        = 1,
        .itemCommon = ITEM_QUICK_POWDER,
        .itemRare = ITEM_METAL_POWDER,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_DITTO, EGG_GROUP_DITTO},
        .abilities = {ABILITY_LIMBER, ABILITY_NONE, ABILITY_IMPOSTER},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },
    [SPECIES_ARTICUNO] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 100,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 125,
        .types = { TYPE_ICE, TYPE_FLYING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_SNOW_CLOAK},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ZAPDOS] =
    {
        .baseHP        = 90,
        .baseAttack    = 90,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 125,
        .baseSpDefense = 90,
        .types = { TYPE_ELECTRIC, TYPE_FLYING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        #if P_UPDATED_ABILITIES >= GEN_6
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_STATIC},
        #else
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_LIGHTNING_ROD},
        #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_MOLTRES] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 125,
        .baseSpDefense = 85,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FLAME_BODY},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },
    [SPECIES_MEWTWO] =
    {
        .baseHP        = 106,
        .baseAttack    = 110,
        .baseDefense   = 90,
        .baseSpeed     = 130,
        .baseSpAttack  = 154,
        .baseSpDefense = 90,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_UNNERVE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_MEW] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 270,
        .evYield_HP        = 3,
        .itemCommon = ITEM_LUM_BERRY,
        .itemRare = ITEM_LUM_BERRY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED },
        .abilities = {ABILITY_SYNCHRONIZE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_SHUCKLE] =
    {
        .baseHP        = 20,
        .baseAttack    = 10,
        .baseDefense   = 230,
        .baseSpeed     = 5,
        .baseSpAttack  = 10,
        .baseSpDefense = 230,
        .types = { TYPE_BUG, TYPE_ROCK },
        .catchRate = 190,
        .expYield = 177,
        .evYield_Defense   = 1,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_BERRY_JUICE,
        .itemRare = ITEM_BERRY_JUICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_STURDY, ABILITY_GLUTTONY, ABILITY_CONTRARY},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_RAIKOU] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 115,
        .baseSpAttack  = 115,
        .baseSpDefense = 100,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Speed     = 2,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        #if P_UPDATED_ABILITIES >= GEN_7
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS},
        #else
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_VOLT_ABSORB},
        #endif
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ENTEI] =
    {
        .baseHP        = 115,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 90,
        .baseSpDefense = 75,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 3,
        .expYield = 261,
        .evYield_HP        = 1,
        .evYield_Attack    = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        #if P_UPDATED_ABILITIES >= GEN_7
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS},
        #else
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FLASH_FIRE},
        #endif
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_SUICUNE] =
    {
        .baseHP        = 100,
        .baseAttack    = 75,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 90,
        .baseSpDefense = 115,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense   = 1,
        .evYield_SpDefense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        #if P_UPDATED_ABILITIES >= GEN_7
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INNER_FOCUS},
        #else
            .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_WATER_ABSORB},
        #endif
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_LUGIA] =
    {
        .baseHP        = 106,
        .baseAttack    = 90,
        .baseDefense   = 130,
        .baseSpeed     = 110,
        .baseSpAttack  = 90,
        .baseSpDefense = 154,
        .types = { TYPE_PSYCHIC, TYPE_FLYING },
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_MULTISCALE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_HO_OH] =
    {
        .baseHP        = 106,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 110,
        .baseSpDefense = 154,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpDefense = 3,
        .itemCommon = ITEM_SACRED_ASH,
        .itemRare   = ITEM_SACRED_ASH,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_CELEBI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 270,
        .evYield_HP        = 3,
        .itemCommon = ITEM_LUM_BERRY,
        .itemRare = ITEM_LUM_BERRY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED },
        .abilities = {ABILITY_NATURAL_CURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_TREECKO] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_OVERGROW, ABILITY_NONE, ABILITY_UNBURDEN},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_GROVYLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_OVERGROW, ABILITY_NONE, ABILITY_UNBURDEN},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_SCEPTILE] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 65,
        .baseSpeed     = 120,
        .baseSpAttack  = 105,
        .baseSpDefense = 85,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Speed     = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_OVERGROW, ABILITY_NONE, ABILITY_UNBURDEN},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_TORCHIC] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 45,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_BLAZE, ABILITY_NONE, ABILITY_SPEED_BOOST},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_COMBUSKEN] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 85,
        .baseSpDefense = 60,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Attack    = 1,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_BLAZE, ABILITY_NONE, ABILITY_SPEED_BOOST},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_BLAZIKEN] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 70,
        .baseSpeed     = 80,
        .baseSpAttack  = 110,
        .baseSpDefense = 70,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_BLAZE, ABILITY_NONE, ABILITY_SPEED_BOOST},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_MUDKIP] =
    {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_DAMP},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_MARSHTOMP] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = { TYPE_WATER, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_DAMP},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_SWAMPERT] =
    {
        .baseHP        = 100,
        .baseAttack    = 110,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 90,
        .types = { TYPE_WATER, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 241,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_DAMP},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_NINCADA] =
    {
        .baseHP        = 31,
        .baseAttack    = 45,
        .baseDefense   = 90,
        .baseSpeed     = 40,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_GROUND},
        .catchRate = 255,
        .expYield = 53,
        .evYield_Defense   = 1,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_COMPOUND_EYES, ABILITY_NONE, ABILITY_RUN_AWAY},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_NINJASK] =
    {
        .baseHP        = 61,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 160,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = { TYPE_BUG, TYPE_FLYING},
        .catchRate = 120,
        .expYield = 160,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_SPEED_BOOST, ABILITY_NONE, ABILITY_INFILTRATOR},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_SHEDINJA] =
    {
        .baseHP        = 1,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 40,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_GHOST},
        .catchRate = 45,
        .expYield = 83,
        .evYield_HP        = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_WONDER_GUARD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_REGIROCK] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 200,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 100,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense   = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_REGICE] =
    {
        .baseHP        = 80,
        .baseAttack    = 50,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 100,
        .baseSpDefense = 200,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_ICE_BODY},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_REGISTEEL] =
    {
        .baseHP        = 80,
        .baseAttack    = 75,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 75,
        .baseSpDefense = 150,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense   = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_LIGHT_METAL},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_LATIAS] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 110,
        .baseSpAttack  = 110,
        .baseSpDefense = 130,
        .types = { TYPE_DRAGON, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED },
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_LATIOS] =
    {
        .baseHP        = 80,
        .baseAttack    = 90,
        .baseDefense   = 80,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = 110,
        .types = { TYPE_DRAGON, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED },
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_KYOGRE] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 140,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 3,
        .expYield = 302,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DRIZZLE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_GROUDON] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 140,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 90,
        .types = { TYPE_GROUND, TYPE_GROUND},
        .catchRate = 3,
        .expYield = 302,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DROUGHT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_RAYQUAZA] =
    {
        .baseHP        = 105,
        .baseAttack    = 150,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 150,
        .baseSpDefense = 90,
        .types = { TYPE_DRAGON, TYPE_FLYING},
        .catchRate = 45,
        .expYield = 306,
        .evYield_Attack    = 2,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_AIR_LOCK, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_JIRACHI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_STEEL, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 270,
        .evYield_HP        = 3,
        .itemCommon = ITEM_STAR_PIECE,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED },
        .abilities = {ABILITY_SERENE_GRACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_DEOXYS] =
    {
        .baseHP        = 50,
        .baseAttack    = 150,
        .baseDefense   = 50,
        .baseSpeed     = 150,
        .baseSpAttack  = 150,
        .baseSpDefense = 50,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack    = 1,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED },
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

#if P_GEN_4_POKEMON == TRUE

    [SPECIES_CHERUBI] =
    {
        .baseHP        = 45,
        .baseAttack    = 35,
        .baseDefense   = 45,
        .baseSpeed     = 35,
        .baseSpAttack  = 62,
        .baseSpDefense = 53,
        .types = { TYPE_GRASS, TYPE_GRASS},
        .catchRate = 190,
        .expYield = 55,
        .evYield_SpAttack  = 1,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_GRASS},
        .abilities = {ABILITY_CHLOROPHYLL, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },

    [SPECIES_CHERRIM] = CHERRIM_SPECIES_INFO(BODY_COLOR_PURPLE),

    [SPECIES_SHELLOS] = SHELLOS_SPECIES_INFO(BODY_COLOR_PURPLE),

    [SPECIES_GASTRODON] = GASTRODON_SPECIES_INFO(BODY_COLOR_PURPLE),

    [SPECIES_ROTOM] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 77,
        .baseSpeed     = 91,
        .baseSpAttack  = 95,
        .baseSpDefense = 77,
        .types = { TYPE_ELECTRIC, TYPE_GHOST},
        .catchRate = 45,
        .expYield = 154,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_UXIE] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 130,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense   = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_MESPRIT] =
    {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = 105,
        .baseSpDefense = 105,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack    = 1,
        .evYield_SpAttack  = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_AZELF] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 70,
        .baseSpeed     = 115,
        .baseSpAttack  = 125,
        .baseSpDefense = 70,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack    = 2,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_DIALGA] =
    {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 100,
        .types = { TYPE_STEEL, TYPE_DRAGON},
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_PALKIA] =
    {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .types = { TYPE_WATER, TYPE_DRAGON},
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_HEATRAN] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 106,
        .baseSpeed     = 77,
        .baseSpAttack  = 130,
        .baseSpDefense = 106,
        .types = { TYPE_FIRE, TYPE_STEEL},
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack  = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_FLAME_BODY},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_REGIGIGAS] =
    {
        .baseHP        = 110,
        .baseAttack    = 160,
        .baseDefense   = 110,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 110,
        .types = { TYPE_NORMAL, TYPE_NORMAL},
        .catchRate = 3,
        .expYield = 302,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_SLOW_START, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_GIRATINA] =
    {
        .baseHP        = 150,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 120,
        .types = { TYPE_GHOST, TYPE_DRAGON},
        .catchRate = 3,
        .expYield = 306,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_CRESSELIA] =
    {
        .baseHP        = 120,
        .baseAttack    = 70,
        .baseDefense   = 120,
        .baseSpeed     = 85,
        .baseSpAttack  = 75,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_PHIONE] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 30,
        .expYield = 216,
        .evYield_HP        = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_HYDRATION, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_MANAPHY] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 3,
        .expYield = 270,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_HYDRATION, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_DARKRAI] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 90,
        .baseSpeed     = 125,
        .baseSpAttack  = 135,
        .baseSpDefense = 90,
        .types = { TYPE_DARK, TYPE_DARK},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BAD_DREAMS, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_SHAYMIN] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_GRASS},
        .catchRate = 45,
        .expYield = 270,
        .evYield_HP        = 3,
        .itemCommon = ITEM_LUM_BERRY,
        .itemRare = ITEM_LUM_BERRY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_NATURAL_CURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_ARCEUS] =
    {
        .baseHP        = 120,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 120,
        .baseSpAttack  = 120,
        .baseSpDefense = 120,
        .types = { TYPE_NORMAL, TYPE_NORMAL},
        .catchRate = 3,
        .expYield = 324,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_MULTITYPE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },
#endif

#if P_GEN_5_POKEMON == TRUE
    [SPECIES_VICTINI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_FIRE},
        .catchRate = 3,
        .expYield = 270,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_VICTORY_STAR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_ZORUA] =
    {
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 80,
        .baseSpDefense = 40,
        .types = { TYPE_DARK, TYPE_DARK},
        .catchRate = 75,
        .expYield = 66,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_ILLUSION, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_ZOROARK] =
    {
        .baseHP        = 60,
        .baseAttack    = 105,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 120,
        .baseSpDefense = 60,
        .types = { TYPE_DARK, TYPE_DARK},
        .catchRate = 45,
        .expYield = 179,
        .evYield_SpAttack  = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_ILLUSION, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_DEERLING] = DEERLING_SPECIES_INFO(BODY_COLOR_PINK),

    [SPECIES_SAWSBUCK] = SAWSBUCK_SPECIES_INFO,

    [SPECIES_COBALION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 129,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 72,
        .types = { TYPE_STEEL, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense   = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_JUSTIFIED, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_TERRAKION] =
    {
        .baseHP        = 91,
        .baseAttack    = 129,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 72,
        .baseSpDefense = 90,
        .types = { TYPE_ROCK, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_JUSTIFIED, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_VIRIZION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 72,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 129,
        .types = { TYPE_GRASS, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_JUSTIFIED, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_TORNADUS] =
    {
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .types = { TYPE_FLYING, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack    = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_THUNDURUS] =
    {
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack    = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_RESHIRAM] =
    {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .types = { TYPE_DRAGON, TYPE_FIRE},
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_TURBOBLAZE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ZEKROM] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        .types = { TYPE_DRAGON, TYPE_ELECTRIC},
        .catchRate = 3,
        .expYield = 306,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_TERAVOLT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_LANDORUS] =
    {
        .baseHP        = 89,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 101,
        .baseSpAttack  = 115,
        .baseSpDefense = 80,
        .types = { TYPE_GROUND, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_SAND_FORCE, ABILITY_NONE, ABILITY_SHEER_FORCE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_KYUREM] =
    {
        .baseHP        = 125,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .types = { TYPE_DRAGON, TYPE_ICE},
        .catchRate = 3,
        .expYield = 297,
        .evYield_HP        = 1,
        .evYield_Attack    = 1,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_KELDEO] =
    {
        .baseHP        = 91,
        .baseAttack    = 72,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 129,
        .baseSpDefense = 90,
        .types = { TYPE_WATER, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_JUSTIFIED, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_MELOETTA] =
    {
        .baseHP        = 100,
        .baseAttack    = 77,
        .baseDefense   = 77,
        .baseSpeed     = 90,
        .baseSpAttack  = 128,
        .baseSpDefense = 128,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 1,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_STAR_PIECE,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_SERENE_GRACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_GENESECT] = GENESECT_SPECIES_INFO,
#endif

#if P_GEN_6_POKEMON == TRUE
    [SPECIES_FROAKIE] =
    {
        .baseHP        = 41,
        .baseAttack    = 56,
        .baseDefense   = 40,
        .baseSpeed     = 71,
        .baseSpAttack  = 62,
        .baseSpDefense = 44,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 45,
        .expYield = 63,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_FROGADIER] =
    {
        .baseHP        = 54,
        .baseAttack    = 63,
        .baseDefense   = 52,
        .baseSpeed     = 97,
        .baseSpAttack  = 83,
        .baseSpDefense = 56,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_GRENINJA] =
    {
        .baseHP        = 72,
        .baseAttack    = 95,
        .baseDefense   = 67,
        .baseSpeed     = 122,
        .baseSpAttack  = 103,
        .baseSpDefense = 71,
        .types = { TYPE_WATER, TYPE_DARK},
        .catchRate = 45,
        .expYield = 239,
        .evYield_Speed     = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
    },

    [SPECIES_SCATTERBUG] =
    {
        .baseHP        = 38,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 27,
        .baseSpDefense = 25,
        .types = { TYPE_BUG, TYPE_BUG},
        .catchRate = 255,
        .expYield = 40,
        .evYield_Defense   = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_SHIELD_DUST, ABILITY_COMPOUND_EYES, ABILITY_FRIEND_GUARD},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
    },

    [SPECIES_SPEWPA] =
    {
        .baseHP        = 45,
        .baseAttack    = 22,
        .baseDefense   = 60,
        .baseSpeed     = 29,
        .baseSpAttack  = 27,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_BUG},
        .catchRate = 120,
        .expYield = 75,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_FRIEND_GUARD},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
    },

    [SPECIES_VIVILLON] = VIVILLON_SPECIES_INFO(BODY_COLOR_WHITE),

    [SPECIES_FLABEBE] = FLABEBE_SPECIES_INFO,

    [SPECIES_FLOETTE] = FLOETTE_SPECIES_INFO,

    [SPECIES_FLORGES] = FLORGES_SPECIES_INFO,

    [SPECIES_FURFROU] = FURFROU_SPECIES_INFO(FLIP),

    [SPECIES_HONEDGE] =
    {
        .baseHP        = 45,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 28,
        .baseSpAttack  = 35,
        .baseSpDefense = 37,
        .types = { TYPE_STEEL, TYPE_GHOST},
        .catchRate = 180,
        .expYield = 65,
        .evYield_Defense   = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_NO_GUARD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_DOUBLADE] =
    {
        .baseHP        = 59,
        .baseAttack    = 110,
        .baseDefense   = 150,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 49,
        .types = { TYPE_STEEL, TYPE_GHOST},
        .catchRate = 90,
        .expYield = 157,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_NO_GUARD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_AEGISLASH] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = 50,
        #if P_UPDATED_STATS >= GEN_8
            .baseDefense   = 140,
            .baseSpDefense = 140,
        #else
            .baseDefense   = 150,
            .baseSpDefense = 150,
        #endif
        .types = { TYPE_STEEL, TYPE_GHOST},
        .catchRate = 45,
        .expYield = 234,
        .evYield_Defense   = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_STANCE_CHANGE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_PUMPKABOO] =
    {
        .baseHP        = 49,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 51,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        PUMKPABOO_MISC_INFO,
    },

    [SPECIES_GOURGEIST] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 122,
        .baseSpeed     = 84,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        GOURGEIST_MISC_INFO,
    },

    [SPECIES_BERGMITE] =
    {
        .baseHP        = 55,
        .baseAttack    = 69,
        .baseDefense   = 85,
        .baseSpeed     = 28,
        .baseSpAttack  = 32,
        .baseSpDefense = 35,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense   = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MINERAL},
        #else
            .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER},
        #endif
        .abilities = {ABILITY_OWN_TEMPO, ABILITY_ICE_BODY, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_AVALUGG] =
    {
        .baseHP        = 95,
        .baseAttack    = 117,
        .baseDefense   = 184,
        .baseSpeed     = 28,
        .baseSpAttack  = 44,
        .baseSpDefense = 46,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 55,
        .expYield = 180,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MINERAL},
        #else
            .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER},
        #endif
        .abilities = {ABILITY_OWN_TEMPO, ABILITY_ICE_BODY, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_XERNEAS] = XERNEAS_SPECIES_INFO,

    [SPECIES_YVELTAL] =
    {
        .baseHP        = 126,
        .baseAttack    = 131,
        .baseDefense   = 95,
        .baseSpeed     = 99,
        .baseSpAttack  = 131,
        .baseSpDefense = 98,
        .types = { TYPE_DARK, TYPE_FLYING},
        .catchRate = 45,
        .expYield = 306,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DARK_AURA, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ZYGARDE] = ZYGARDE_50_SPECIES_INFO(ABILITY_AURA_BREAK),

    [SPECIES_DIANCIE] =
    {
        .baseHP        = 50,
        .baseAttack    = 100,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 100,
        .baseSpDefense = 150,
        .types = { TYPE_ROCK, TYPE_FAIRY},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Defense   = 1,
        .evYield_SpDefense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_CLEAR_BODY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_HOOPA] =
    {
        .baseHP        = 80,
        .baseAttack    = 110,
        .baseDefense   = 60,
        .baseSpeed     = 70,
        .baseSpAttack  = 150,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_GHOST},
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_MAGICIAN, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_VOLCANION] =
    {
        .baseHP        = 80,
        .baseAttack    = 110,
        .baseDefense   = 120,
        .baseSpeed     = 70,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .types = { TYPE_FIRE, TYPE_WATER},
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_WATER_ABSORB, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },
#endif

#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ORICORIO] = ORICORIO_SPECIES_INFO(TYPE_FIRE, BODY_COLOR_RED),

    [SPECIES_ROCKRUFF] = ROCKRUFF_SPECIES_INFO(ABILITY_KEEN_EYE, ABILITY_VITAL_SPIRIT, ABILITY_STEADFAST),

    [SPECIES_LYCANROC] =
    {
        .baseHP        = 75,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 112,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_ROCK, TYPE_ROCK},
        .catchRate = 90,
        .expYield = 170,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_KEEN_EYE, ABILITY_SAND_RUSH, ABILITY_STEADFAST},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_WISHIWASHI] =
    {
        .baseHP        = 45,
        .baseAttack    = 20,
        .baseDefense   = 20,
        .baseSpeed     = 40,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 60,
        .expYield = 61,
        .evYield_HP        = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_HUDDLE_UP, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_TYPE_NULL] =
    {
        .baseHP        = 95,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 59,
        .baseSpAttack  = 95,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_NORMAL},
        .catchRate = 3,
        .expYield = 107,
        .evYield_HP        = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BATTLE_ARMOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_SILVALLY] = SILVALLY_SPECIES_INFO(TYPE_NORMAL),

    [SPECIES_MINIOR] = MINIOR_METEOR_SPECIES_INFO,

    [SPECIES_MIMIKYU] = MIMIKYU_SPECIES_INFO,

    [SPECIES_TAPU_KOKO] =
    {
        .baseHP        = 70,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 130,
        .baseSpAttack  = 95,
        .baseSpDefense = 75,
        .types = { TYPE_ELECTRIC, TYPE_FAIRY},
        .catchRate = 3,
        .expYield = 257,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_ELECTRIC_SURGE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_TAPU_LELE] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 95,
        .baseSpAttack  = 130,
        .baseSpDefense = 115,
        .types = { TYPE_PSYCHIC, TYPE_FAIRY},
        .catchRate = 3,
        .expYield = 257,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PSYCHIC_SURGE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_TAPU_BULU] =
    {
        .baseHP        = 70,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 85,
        .baseSpDefense = 95,
        .types = { TYPE_GRASS, TYPE_FAIRY},
        .catchRate = 3,
        .expYield = 257,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_GRASSY_SURGE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_TAPU_FINI] =
    {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 130,
        .types = { TYPE_WATER, TYPE_FAIRY},
        .catchRate = 3,
        .expYield = 257,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_MISTY_SURGE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_COSMOG] =
    {
        .baseHP        = 43,
        .baseAttack    = 29,
        .baseDefense   = 31,
        .baseSpeed     = 37,
        .baseSpAttack  = 29,
        .baseSpDefense = 31,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 45,
        .expYield = 40,
        .evYield_HP        = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_UNAWARE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_COSMOEM] =
    {
        .baseHP        = 43,
        .baseAttack    = 29,
        .baseDefense   = 131,
        .baseSpeed     = 37,
        .baseSpAttack  = 29,
        .baseSpDefense = 131,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 45,
        .expYield = 140,
        .evYield_Defense   = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_STURDY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_SOLGALEO] =
    {
        .baseHP        = 137,
        .baseAttack    = 137,
        .baseDefense   = 107,
        .baseSpeed     = 97,
        .baseSpAttack  = 113,
        .baseSpDefense = 89,
        .types = { TYPE_PSYCHIC, TYPE_STEEL},
        .catchRate = 45,
        .expYield = 306,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_FULL_METAL_BODY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_LUNALA] =
    {
        .baseHP        = 137,
        .baseAttack    = 113,
        .baseDefense   = 89,
        .baseSpeed     = 97,
        .baseSpAttack  = 137,
        .baseSpDefense = 107,
        .types = { TYPE_PSYCHIC, TYPE_GHOST},
        .catchRate = 45,
        .expYield = 306,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_SHADOW_SHIELD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_NIHILEGO] =
    {
        .baseHP        = 109,
        .baseAttack    = 53,
        .baseDefense   = 47,
        .baseSpeed     = 103,
        .baseSpAttack  = 127,
        .baseSpDefense = 131,
        .types = { TYPE_ROCK, TYPE_POISON},
        .catchRate = 45,
        .expYield = 257,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_BUZZWOLE] =
    {
        .baseHP        = 107,
        .baseAttack    = 139,
        .baseDefense   = 139,
        .baseSpeed     = 79,
        .baseSpAttack  = 53,
        .baseSpDefense = 53,
        .types = { TYPE_BUG, TYPE_FIGHTING},
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack    = 1,
        .evYield_Defense   = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_PHEROMOSA] =
    {
        .baseHP        = 71,
        .baseAttack    = 137,
        .baseDefense   = 37,
        .baseSpeed     = 151,
        .baseSpAttack  = 137,
        .baseSpDefense = 37,
        .types = { TYPE_BUG, TYPE_FIGHTING},
        .catchRate = 45,
        .expYield = 257,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_XURKITREE] =
    {
        .baseHP        = 83,
        .baseAttack    = 89,
        .baseDefense   = 71,
        .baseSpeed     = 83,
        .baseSpAttack  = 173,
        .baseSpDefense = 71,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC},
        .catchRate = 45,
        .expYield = 257,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_CELESTEELA] =
    {
        .baseHP        = 97,
        .baseAttack    = 101,
        .baseDefense   = 103,
        .baseSpeed     = 61,
        .baseSpAttack  = 107,
        .baseSpDefense = 101,
        .types = { TYPE_STEEL, TYPE_FLYING},
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack    = 1,
        .evYield_Defense   = 1,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_KARTANA] =
    {
        .baseHP        = 59,
        .baseAttack    = 181,
        .baseDefense   = 131,
        .baseSpeed     = 109,
        .baseSpAttack  = 59,
        .baseSpDefense = 31,
        .types = { TYPE_GRASS, TYPE_STEEL},
        .catchRate = 45,
        .expYield = 257,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_GUZZLORD] =
    {
        .baseHP        = 223,
        .baseAttack    = 101,
        .baseDefense   = 53,
        .baseSpeed     = 43,
        .baseSpAttack  = 97,
        .baseSpDefense = 53,
        .types = { TYPE_DARK, TYPE_DRAGON},
        .catchRate = 45,
        .expYield = 257,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_NECROZMA] =
    {
        .baseHP        = 97,
        .baseAttack    = 107,
        .baseDefense   = 101,
        .baseSpeed     = 79,
        .baseSpAttack  = 127,
        .baseSpDefense = 89,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 255,
        .expYield = 270,
        .evYield_Attack    = 1,
        .evYield_SpAttack  = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRISM_ARMOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_MAGEARNA] = MAGEARNA_SPECIES_INFO(BODY_COLOR_GRAY),

    [SPECIES_MARSHADOW] =
    {
        .baseHP        = 90,
        .baseAttack    = 125,
        .baseDefense   = 80,
        .baseSpeed     = 125,
        .baseSpAttack  = 90,
        .baseSpDefense = 90,
        .types = { TYPE_FIGHTING, TYPE_GHOST},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack    = 2,
        .evYield_Speed     = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_TECHNICIAN, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_POIPOLE] =
    {
        .baseHP        = 67,
        .baseAttack    = 73,
        .baseDefense   = 67,
        .baseSpeed     = 73,
        .baseSpAttack  = 73,
        .baseSpDefense = 67,
        .types = { TYPE_POISON, TYPE_POISON},
        .catchRate = 45,
        .expYield = 189,
        .evYield_Speed     = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_NAGANADEL] =
    {
        .baseHP        = 73,
        .baseAttack    = 73,
        .baseDefense   = 73,
        .baseSpeed     = 121,
        .baseSpAttack  = 127,
        .baseSpDefense = 73,
        .types = { TYPE_POISON, TYPE_DRAGON},
        .catchRate = 45,
        .expYield = 243,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_STAKATAKA] =
    {
        .baseHP        = 61,
        .baseAttack    = 131,
        .baseDefense   = 211,
        .baseSpeed     = 13,
        .baseSpAttack  = 53,
        .baseSpDefense = 101,
        .types = { TYPE_ROCK, TYPE_STEEL},
        .catchRate = 30,
        .expYield = 257,
        .evYield_Defense   = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_BLACEPHALON] =
    {
        .baseHP        = 53,
        .baseAttack    = 127,
        .baseDefense   = 53,
        .baseSpeed     = 107,
        .baseSpAttack  = 151,
        .baseSpDefense = 79,
        .types = { TYPE_FIRE, TYPE_GHOST},
        .catchRate = 30,
        .expYield = 257,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BEAST_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_ULTRA_BEAST,
    },

    [SPECIES_ZERAORA] =
    {
        .baseHP        = 88,
        .baseAttack    = 112,
        .baseDefense   = 75,
        .baseSpeed     = 143,
        .baseSpAttack  = 102,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_VOLT_ABSORB, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_MELTAN] =
    {
        .baseHP        = 46,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 34,
        .baseSpAttack  = 55,
        .baseSpDefense = 35,
        .types = { TYPE_STEEL, TYPE_STEEL},
        .catchRate = 3,
        .expYield = 135,
        .evYield_Attack    = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_MAGNET_PULL, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_MELMETAL] =
    {
        .baseHP        = 135,
        .baseAttack    = 143,
        .baseDefense   = 143,
        .baseSpeed     = 34,
        .baseSpAttack  = 80,
        .baseSpDefense = 65,
        .types = { TYPE_STEEL, TYPE_STEEL},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_IRON_FIST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },
#endif

#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CRAMORANT] = CRAMORANT_SPECIES_INFO,

    [SPECIES_TOXEL] =
    {
        .baseHP        = 40,
        .baseAttack    = 38,
        .baseDefense   = 35,
        .baseSpeed     = 40,
        .baseSpAttack  = 54,
        .baseSpDefense = 35,
        .types = { TYPE_ELECTRIC, TYPE_POISON},
        .catchRate = 75,
        .expYield = 48,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_RATTLED, ABILITY_STATIC, ABILITY_KLUTZ},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_TOXTRICITY] = TOXTRICITY_SPECIES_INFO(ABILITY_PLUS),

    [SPECIES_SINISTEA] = SINISTEA_SPECIES_INFO,

    [SPECIES_POLTEAGEIST] = POLTEAGEIST_SPECIES_INFO,

    [SPECIES_OBSTAGOON] =
    {
        .baseHP        = 93,
        .baseAttack    = 90,
        .baseDefense   = 101,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 81,
        .types = { TYPE_DARK, TYPE_NORMAL},
        .catchRate = 45,
        .expYield = 260,
        .evYield_Defense   = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_RECKLESS, ABILITY_GUTS, ABILITY_DEFIANT},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_PERRSERKER] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 60,
        .types = { TYPE_STEEL, TYPE_STEEL},
        .catchRate = 90,
        .expYield = 154,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_BATTLE_ARMOR, ABILITY_TOUGH_CLAWS, ABILITY_STEELY_SPIRIT},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_CURSOLA] =
    {
        .baseHP        = 60,
        .baseAttack    = 95,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 145,
        .baseSpDefense = 130,
        .types = { TYPE_GHOST, TYPE_GHOST},
        .catchRate = 30,
        .expYield = 179,
        .evYield_SpAttack  = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3},
        .abilities = {ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_PERISH_BODY},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_SIRFETCHD] =
    {
        .baseHP        = 62,
        .baseAttack    = 135,
        .baseDefense   = 95,
        .baseSpeed     = 65,
        .baseSpAttack  = 68,
        .baseSpDefense = 82,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING},
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack    = 2,
        .itemRare = ITEM_LEEK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FIELD},
        .abilities = {ABILITY_STEADFAST, ABILITY_NONE, ABILITY_SCRAPPY},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_MR_RIME] =
    {
        .baseHP        = 80,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 70,
        .baseSpAttack  = 110,
        .baseSpDefense = 100,
        .types = { TYPE_ICE, TYPE_PSYCHIC},
        .catchRate = 45,
        .expYield = 182,
        .evYield_SpAttack  = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE},
        .abilities = {ABILITY_TANGLED_FEET, ABILITY_SCREEN_CLEANER, ABILITY_ICE_BODY},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_RUNERIGUS] =
    {
        .baseHP        = 58,
        .baseAttack    = 95,
        .baseDefense   = 145,
        .baseSpeed     = 30,
        .baseSpAttack  = 50,
        .baseSpDefense = 105,
        .types = { TYPE_GROUND, TYPE_GHOST},
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_WANDERING_SPIRIT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_MILCERY] =
    {
        .baseHP        = 45,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 34,
        .baseSpAttack  = 50,
        .baseSpDefense = 61,
        .types = { TYPE_FAIRY, TYPE_FAIRY},
        .catchRate = 200,
        .expYield = 54,
        .evYield_SpDefense = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_AROMA_VEIL},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_ALCREMIE] = ALCREMIE_SPECIES_INFO(BODY_COLOR_WHITE),

    [SPECIES_EISCUE] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 90,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 60,
        .expYield = 165,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD},
        .abilities = {ABILITY_ICE_FACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_MORPEKO] = MORPEKO_SPECIES_INFO,

    [SPECIES_ZACIAN] =
    {
        .baseHP        = 92,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 138,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = { TYPE_FAIRY, TYPE_FAIRY},
        .catchRate = 10,
        .expYield = 335,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_INTREPID_SWORD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ZAMAZENTA] =
    {
        .baseHP        = 92,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 138,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING},
        .catchRate = 10,
        .expYield = 335,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DAUNTLESS_SHIELD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ETERNATUS] =
    {
        .baseHP        = 140,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 130,
        .baseSpAttack  = 145,
        .baseSpDefense = 95,
        .types = { TYPE_POISON, TYPE_DRAGON},
        .catchRate = 255,
        .expYield = 345,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_KUBFU] =
    {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 60,
        .baseSpeed     = 72,
        .baseSpAttack  = 53,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 77,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_INNER_FOCUS, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_URSHIFU] =
    {
        .baseHP        = 100,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 97,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = { TYPE_FIGHTING, TYPE_DARK},
        .catchRate = 3,
        .expYield = 275,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_UNSEEN_FIST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ZARUDE] = ZARUDE_SPECIES_INFO,

    [SPECIES_REGIELEKI] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 200,
        .baseSpAttack  = 100,
        .baseSpDefense = 50,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC},
        .catchRate = 3,
        .expYield = 290,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_TRANSISTOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_REGIDRAGO] =
    {
        .baseHP        = 200,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 50,
        .types = { TYPE_DRAGON, TYPE_DRAGON},
        .catchRate = 3,
        .expYield = 290,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DRAGONS_MAW, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_GLASTRIER] =
    {
        .baseHP        = 100,
        .baseAttack    = 145,
        .baseDefense   = 130,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = 110,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 3,
        .expYield = 290,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_CHILLING_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_SPECTRIER] =
    {
        .baseHP        = 100,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 130,
        .baseSpAttack  = 145,
        .baseSpDefense = 80,
        .types = { TYPE_GHOST, TYPE_GHOST},
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_CALYREX] =
    {
        .baseHP        = 100,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_PSYCHIC, TYPE_GRASS},
        .catchRate = 3,
        .expYield = 250,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_UNNERVE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_WYRDEER] =
    {
        .baseHP        = 103,
        .baseAttack    = 105,
        .baseDefense   = 72,
        .baseSpeed     = 65,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_PSYCHIC},
        .catchRate = 45,
        .expYield = 184,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_SAP_SIPPER},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_KLEAVOR] =
    {
        .baseHP        = 70,
        .baseAttack    = 135,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 45,
        .baseSpDefense = 70,
        .types = { TYPE_BUG, TYPE_ROCK},
        .catchRate = 25,
        .expYield = 175,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_SWARM, ABILITY_SHEER_FORCE, ABILITY_SHARPNESS},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_URSALUNA] =
    {
        .baseHP        = 130,
        .baseAttack    = 140,
        .baseDefense   = 105,
        .baseSpeed     = 50,
        .baseSpAttack  = 45,
        .baseSpDefense = 80,
        .types = { TYPE_GROUND, TYPE_NORMAL},
        .catchRate = 75,
        .expYield = 194,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_GUTS, ABILITY_BULLETPROOF, ABILITY_UNNERVE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_BASCULEGION] =
    {
        .baseHP        = 120,
        .baseAttack    = 112,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .types = { TYPE_WATER, TYPE_GHOST},
        .catchRate = 25,
        .expYield = 186,
        .evYield_HP     = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_RATTLED, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_BASCULEGION_FEMALE] =
    {
        .baseHP        = 120,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .types = { TYPE_WATER, TYPE_GHOST},
        .catchRate = 25,
        .expYield = 186,
        .evYield_HP     = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_RATTLED, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_SNEASLER] =
    {
        .baseHP        = 80,
        .baseAttack    = 130,
        .baseDefense   = 60,
        .baseSpeed     = 120,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = { TYPE_FIGHTING, TYPE_POISON},
        .catchRate = 135,
        .expYield = 179,
        .evYield_Attack    = 1,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_PRESSURE, ABILITY_UNBURDEN, ABILITY_POISON_TOUCH},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_OVERQWIL] =
    {
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_DARK, TYPE_POISON},
        .catchRate = 135,
        .expYield = 180,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_POISON_POINT, ABILITY_SWIFT_SWIM, ABILITY_INTIMIDATE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
    },

    [SPECIES_ENAMORUS] =
    {
        .baseHP        = 74,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 106,
        .baseSpAttack  = 135,
        .baseSpDefense = 80,
        .types = { TYPE_FAIRY, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpAttack    = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_HEALER, ABILITY_NONE, ABILITY_CONTRARY},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_TIDPIT] =
    {
        .baseHP        = 35,
        .baseAttack    = 70,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 64,
        .evYield_Attack  = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_GRASS},
        .abilities = {ABILITY_OVERGROW, ABILITY_CHLOROPHYLL, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_SLIDLOW] =
    {
        .baseHP        = 80,
        .baseAttack    = 95,
        .baseDefense   = 75,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Attack  = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_GRASS},
        .abilities = {ABILITY_OVERGROW, ABILITY_STRONG_JAW, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_CARDIOVOR] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 95,
        .baseSpeed     = 55,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_POISON },
        .catchRate = 45,
        .expYield = 236,
        .evYield_Attack  = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_GRASS},
        .abilities = {ABILITY_OVERGROW, ABILITY_STRONG_JAW, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
    },

    [SPECIES_FIEFREET] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_SpDefense     = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_BLAZE, ABILITY_SOLAR_POWER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_BALBYRN] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 55,
        .baseSpeed     = 65,
        .baseSpAttack  = 70,
        .baseSpDefense = 95,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 142,
        .evYield_SpDefense     = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_BLAZE, ABILITY_INTIMIDATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_BLAZIZAHAK] =
    {
        .baseHP        = 80,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 105,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 240,
        .evYield_Attack  = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_BLAZE, ABILITY_INTIMIDATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_PRONGY] =
    {
        .baseHP        = 40,
        .baseAttack    = 60,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 63,
        .evYield_Attack   = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_TORRENT, ABILITY_HYDRATION, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_TRIDALIER] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 90,
        .baseSpeed     = 45,
        .baseSpAttack  = 70,
        .baseSpDefense = 65,
        .types = { TYPE_WATER, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_TORRENT, ABILITY_FILTER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_TRITONAUT] =
    {
        .baseHP        = 100,
        .baseAttack    = 90,
        .baseDefense   = 115,
        .baseSpeed     = 40,
        .baseSpAttack  = 90,
        .baseSpDefense = 95,
        .types = { TYPE_WATER, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_TORRENT, ABILITY_FILTER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_SNELFREND] =
    {
        .baseHP        = 45,
        .baseAttack    = 25,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 50,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 36,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_WATER_ABSORB, ABILITY_SHELL_ARMOR, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_SYCOPLOD] =
    {
        .baseHP        = 85,
        .baseAttack    = 40,
        .baseDefense   = 90,
        .baseSpeed     = 40,
        .baseSpAttack  = 55,
        .baseSpDefense = 90,
        .types = { TYPE_BUG, TYPE_PSYCHIC },
        .catchRate = 120,
        .expYield = 117,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_WATER_ABSORB, ABILITY_GOOEY, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_SYCOSTROM] =
    {
        .baseHP        = 115,
        .baseAttack    = 55,
        .baseDefense   = 120,
        .baseSpeed     = 35,
        .baseSpAttack  = 85,
        .baseSpDefense = 120,
        .types = { TYPE_BUG, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 253,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_WATER_ABSORB, ABILITY_GOOEY, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_GUPSPAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 35,
        .baseSpeed     = 45,
        .baseSpAttack  = 40,
        .baseSpDefense = 35,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 225,
        .expYield = 59,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_DAMP, ABILITY_STRONG_JAW, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_VANGAR] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 154,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_DAMP, ABILITY_STRONG_JAW, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_GHAERIAL] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 75,
        .baseSpDefense = 65,
        .types = { TYPE_WATER, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 243,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_AERILATE, ABILITY_STRONG_JAW, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_MARINAROC] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 90,
        .baseSpeed     = 110,
        .baseSpAttack  = 105,
        .baseSpDefense = 55,
        .types = { TYPE_WATER, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 100,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_WATER_3},
        .abilities = {ABILITY_PROPELLER_TAIL, ABILITY_STORM_DRAIN, ABILITY_NATURAL_CURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },

    [SPECIES_METTATOLL] =
    {
        .baseHP        = 70,
        .baseAttack    = 120,
        .baseDefense   = 130,
        .baseSpeed     = 60,
        .baseSpAttack  = 55,
        .baseSpDefense = 85,
        .types = { TYPE_WATER, TYPE_STEEL },
        .catchRate = 25,
        .expYield = 175,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_WATER_3},
        .abilities = {ABILITY_PROPELLER_TAIL, ABILITY_FILTER, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_ICKSQUEEK] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 35,
        .baseSpeed     = 80,
        .baseSpAttack  = 35,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_POISON },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_FRISK, ABILITY_STAKEOUT, ABILITY_RUN_AWAY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
    },

    [SPECIES_KOMORODE] =
    {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 65,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 55,
        .types = { TYPE_NORMAL, TYPE_POISON },
        .catchRate = 90,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_MONSTER},
        .abilities = {ABILITY_FRISK, ABILITY_STAKEOUT, ABILITY_MERCILESS, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
    },

    [SPECIES_KYUDI] =
    {
        .baseHP        = 49,
        .baseAttack    = 69,
        .baseDefense   = 79,
        .baseSpeed     = 49,
        .baseSpAttack  = 29,
        .baseSpDefense = 59,
        .types = { TYPE_GROUND, TYPE_FAIRY },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_PIXILATE, ABILITY_TOUGH_CLAWS, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_KOMBAKYU] =
    {
        .baseHP        = 79,
        .baseAttack    = 109,
        .baseDefense   = 129,
        .baseSpeed     = 69,
        .baseSpAttack  = 49,
        .baseSpDefense = 79,
        .types = { TYPE_GROUND, TYPE_FAIRY },
        .catchRate = 90,
        .expYield = 158,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_STREAM, ABILITY_PIXILATE, ABILITY_TOUGH_CLAWS, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_FLUFFSIR] =
    {
        .baseHP        = 80,
        .baseAttack    = 55,
        .baseDefense   = 25,
        .baseSpeed     = 75,
        .baseSpAttack  = 55,
        .baseSpDefense = 45,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 59,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_FLUFFY, ABILITY_CUTE_CHARM, ABILITY_FUR_COAT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_FLUFFREAR] =
    {
        .baseHP        = 145,
        .baseAttack    = 75,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 95,
        .baseSpDefense = 70,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 90,
        .expYield = 154,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_FLUFFY, ABILITY_CUTE_CHARM, ABILITY_FUR_COAT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_SAINTISOW] =
    {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 25,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 50,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FIELD},
        .abilities = {ABILITY_THICK_FAT, ABILITY_MAGIC_GUARD, ABILITY_SERENE_GRACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },

    [SPECIES_SANCTISOW] =
    {
        .baseHP        = 80,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 45,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 122,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FIELD},
        .abilities = {ABILITY_THICK_FAT, ABILITY_MAGIC_GUARD, ABILITY_SERENE_GRACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },

    [SPECIES_SOWPHIROTH] =
    {
        .baseHP        = 110,
        .baseAttack    = 60,
        .baseDefense   = 65,
        .baseSpeed     = 75,
        .baseSpAttack  = 110,
        .baseSpDefense = 130,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 216,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FIELD},
        .abilities = {ABILITY_THICK_FAT, ABILITY_MAGIC_GUARD, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
    },

    [SPECIES_TOXEXOT] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 35,
        .baseSpAttack  = 60,
        .baseSpDefense = 55,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 255,
        .expYield = 58,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_OVERCOAT, ABILITY_NEUTRALIZING_GAS, ABILITY_SHEER_FORCE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_PSEUDRA] =
    {
        .baseHP        = 95,
        .baseAttack    = 110,
        .baseDefense   = 85,
        .baseSpeed     = 65,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = { TYPE_POISON, TYPE_DRAGON },
        .catchRate = 90,
        .expYield = 157,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_OVERCOAT, ABILITY_NEUTRALIZING_GAS, ABILITY_SHEER_FORCE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_MANDIMYTE] =
    {
        .baseHP        = 25,
        .baseAttack    = 65,
        .baseDefense   = 30,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 39,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_EARTH_EATER, ABILITY_SWARM, ABILITY_AFTERMATH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_TERMINYTE] =
    {
        .baseHP        = 50,
        .baseAttack    = 90,
        .baseDefense   = 60,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 60,
        .types = { TYPE_BUG, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 134,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG},
        .abilities = {ABILITY_EARTH_EATER, ABILITY_SWARM, ABILITY_AFTERMATH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_SNOTLOUD] =
    {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 80,
        .baseSpAttack  = 70,
        .baseSpDefense = 45,
        .types = { TYPE_POISON, TYPE_POISON },
        .catchRate = 190,
        .expYield = 65,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_LIQUID_OOZE, ABILITY_PUNK_ROCK, ABILITY_STICKY_HOLD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_SICKBEAT] =
    {
        .baseHP        = 70,
        .baseAttack    = 95,
        .baseDefense   = 65,
        .baseSpeed     = 115,
        .baseSpAttack  = 120,
        .baseSpDefense = 65,
        .types = { TYPE_POISON, TYPE_FIGHTING },
        .catchRate = 75,
        .expYield = 175,
        .evYield_SpAttack = 1,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_LIQUID_OOZE, ABILITY_PUNK_ROCK, ABILITY_STICKY_HOLD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_SPRYTE] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 75,
        .expYield = 42,
        .evYield_Attack = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_RUN_AWAY, ABILITY_KLUTZ, ABILITY_WIMP_OUT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_GUMONA] =
    {
        .baseHP        = 75,
        .baseAttack    = 85,
        .baseDefense   = 100,
        .baseSpeed     = 125,
        .baseSpAttack  = 50,
        .baseSpDefense = 95,
        .types = { TYPE_DARK, TYPE_BUG },
        .catchRate = 45,
        .expYield = 159,
        .evYield_Speed = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_TANGLING_HAIR, ABILITY_POISON_HEAL, ABILITY_OVERCOAT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_NANGGAL] =
    {
        .baseHP        = 95,
        .baseAttack    = 120,
        .baseDefense   = 50,
        .baseSpeed     = 85,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 159,
        .evYield_Attack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_CURSED_BODY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_SHEEDRAKE] =
    {
        .baseHP        = 100,
        .baseAttack    = 75,
        .baseDefense   = 95,
        .baseSpeed     = 50,
        .baseSpAttack  = 120,
        .baseSpDefense = 85,
        .types = { TYPE_DARK, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 159,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_EFFECT_SPORE, ABILITY_UNAWARE, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_TRANSERA] =
    {
        .baseHP        = 70,
        .baseAttack    = 65,
        .baseDefense   = 106,
        .baseSpeed     = 46,
        .baseSpAttack  = 122,
        .baseSpDefense = 81,
        .types = { TYPE_GRASS, TYPE_ELECTRIC },
        .catchRate = 45,
        .expYield = 87,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_STICKY_HOLD, ABILITY_ILLUMINATE, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
    },

    [SPECIES_BIVAGUE] =
    {
        .baseHP        = 60,
        .baseAttack    = 30,
        .baseDefense   = 115,
        .baseSpeed     = 30,
        .baseSpAttack  = 62,
        .baseSpDefense = 95,
        .types = { TYPE_ICE, TYPE_DRAGON },
        .catchRate = 255,
        .expYield = 69,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_POISON_POINT, ABILITY_POISON_HEAL, ABILITY_SHELL_ARMOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_LUSCKAW] =
    {
        .baseHP        = 95,
        .baseAttack    = 50,
        .baseDefense   = 65,
        .baseSpeed     = 113,
        .baseSpAttack  = 122,
        .baseSpDefense = 85,
        .types = { TYPE_ICE, TYPE_DRAGON },
        .catchRate = 60,
        .expYield = 170,
        .evYield_SpAttack = 1,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_POISON_POINT, ABILITY_TOXIC_BOOST, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_SADSOD] =
    {
        .baseHP        = 80,
        .baseAttack    = 15,
        .baseDefense   = 55,
        .baseSpeed     = 10,
        .baseSpAttack  = 15,
        .baseSpDefense = 20,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 255,
        .expYield = 40,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = 205,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_MAERACHOLY] =
    {
        .baseHP        = 125,
        .baseAttack    = 95,
        .baseDefense   = 81,
        .baseSpeed     = 60,
        .baseSpAttack  = 100,
        .baseSpDefense = 79,
        .types = { TYPE_WATER, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 189,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_LUMELMO] =
    {
        .baseHP        = 30,
        .baseAttack    = 25,
        .baseDefense   = 35,
        .baseSpeed     = 90,
        .baseSpAttack  = 90,
        .baseSpDefense = 35,
        .types = { TYPE_ELECTRIC, TYPE_FIRE },
        .catchRate = 190,
        .expYield = 66,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_ILLUMINATE, ABILITY_DAZZLING, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_LUMENDELA] =
    {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 130,
        .baseSpAttack  = 130,
        .baseSpDefense = 55,
        .types = { TYPE_ELECTRIC, TYPE_FIRE },
        .catchRate = 75,
        .expYield = 161,
        .evYield_SpAttack = 1,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_ILLUMINATE, ABILITY_DAZZLING, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_STOMAWAY] =
    {
        .baseHP        = 32,
        .baseAttack    = 23,
        .baseDefense   = 68,
        .baseSpeed     = 42,
        .baseSpAttack  = 78,
        .baseSpDefense = 68,
        .types = { TYPE_STEEL, TYPE_PSYCHIC },
        .catchRate = 205,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3},
        .abilities = {ABILITY_TINTED_LENS, ABILITY_LEVITATE, ABILITY_NEUROFORCE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_CRAWLAXY] =
    {
        .baseHP        = 80,
        .baseAttack    = 33,
        .baseDefense   = 100,
        .baseSpeed     = 85,
        .baseSpAttack  = 112,
        .baseSpDefense = 100,
        .types = { TYPE_STEEL, TYPE_PSYCHIC },
        .catchRate = 155,
        .expYield = 164,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3},
        .abilities = {ABILITY_TINTED_LENS, ABILITY_LEVITATE, ABILITY_NEUROFORCE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_MAGNALURE] =
    {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 90,
        .baseSpeed     = 65,
        .baseSpAttack  = 45,
        .baseSpDefense = 60,
        .types = { TYPE_ELECTRIC, TYPE_RELIC },
        .catchRate = 190,
        .expYield = 65,
        .evYield_Defense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_MAGNET_PULL, ABILITY_PLUS, ABILITY_STEELWORKER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_MAGNANICOR] =
    {
        .baseHP        = 80,
        .baseAttack    = 125,
        .baseDefense   = 115,
        .baseSpeed     = 70,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = { TYPE_ELECTRIC, TYPE_RELIC },
        .catchRate = 60,
        .expYield = 163,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_MAGNET_PULL, ABILITY_MINUS, ABILITY_STEELWORKER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_CRYPLIN] =
    {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 90,
        .baseSpDefense = 70,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 255,
        .expYield = 67,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE},
        .abilities = {ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_ANALYTIC, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_UHEFOE] =
    {
        .baseHP        = 65,
        .baseAttack    = 45,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 45,
        .baseSpDefense = 85,
        .types = { TYPE_PSYCHIC, TYPE_STEEL },
        .catchRate = 90,
        .expYield = 170,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE},
        .abilities = {ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
    },

    [SPECIES_MYSTOMANIA] =
    {
        .baseHP        = 100,
        .baseAttack    = 130,
        .baseDefense   = 50,
        .baseSpeed     = 100,
        .baseSpAttack  = 130,
        .baseSpDefense = 50,
        .types = { TYPE_PSYCHIC, TYPE_FIGHTING },
        .catchRate = 30,
        .expYield = 220,
        .evYield_SpAttack = 2,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE},
        .abilities = {ABILITY_INFILTRATOR, ABILITY_GRIM_NEIGH, ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_LYORESA] =
    {
        .baseHP        = 121,
        .baseAttack    = 10,
        .baseDefense   = 90,
        .baseSpeed     = 70,
        .baseSpAttack  = 140,
        .baseSpDefense = 70,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 255,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_GUARD, ABILITY_GRIM_NEIGH, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
    },

    [SPECIES_KODOUGH] =
    {
        .baseHP        = 55,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 25,
        .types = { TYPE_GRASS, TYPE_GHOST },
        .catchRate = 255,
        .expYield = 64,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_GOOEY, ABILITY_WATER_ABSORB, ABILITY_FLARE_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_SLICKSLICE] =
    {
        .baseHP        = 75,
        .baseAttack    = 40,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 65,
        .baseSpDefense = 35,
        .types = { TYPE_GRASS, TYPE_GHOST },
        .catchRate = 120,
        .expYield = 138,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_GOOEY, ABILITY_WATER_ABSORB, ABILITY_FLARE_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_LOAFOOF] =
    {
        .baseHP        = 95,
        .baseAttack    = 64,
        .baseDefense   = 125,
        .baseSpeed     = 70,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = { TYPE_GRASS, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 221,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_GOOEY, ABILITY_WATER_ABSORB, ABILITY_FLARE_BOOST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_SPIRITOAST] =
    {
        .baseHP        = 70,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 95,
        .baseSpAttack  = 54,
        .baseSpDefense = 100,
        .types = { TYPE_FIRE, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 221,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_WELL_BAKED_BODY, ABILITY_ROUGH_SKIN, ABILITY_WEAK_ARMOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
    },
#endif

    [SPECIES_VENUSAUR_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 123,
        .baseSpeed     = 80,
        .baseSpAttack  = 122,
        .baseSpDefense = 120,
        .types = { TYPE_GRASS, TYPE_POISON},
        .catchRate = 45,
        .expYield = 281,
        .evYield_SpAttack  = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS},
        .abilities = {ABILITY_THICK_FAT, ABILITY_THICK_FAT},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_CHARIZARD_MEGA_X] =
    {
        .baseHP        = 78,
        .baseAttack    = 130,
        .baseDefense   = 111,
        .baseSpeed     = 100,
        .baseSpAttack  = 130,
        .baseSpDefense = 85,
        .types = { TYPE_FIRE, TYPE_DRAGON},
        .catchRate = 45,
        .expYield = 285,
        .evYield_SpAttack  = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_TOUGH_CLAWS, ABILITY_TOUGH_CLAWS},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_CHARIZARD_MEGA_Y] =
    {
        .baseHP        = 78,
        .baseAttack    = 104,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = 159,
        .baseSpDefense = 115,
        .types = { TYPE_FIRE, TYPE_FLYING},
        .catchRate = 45,
        .expYield = 285,
        .evYield_SpAttack  = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_DROUGHT, ABILITY_DROUGHT},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_BLASTOISE_MEGA] =
    {
        .baseHP        = 79,
        .baseAttack    = 103,
        .baseDefense   = 120,
        .baseSpeed     = 78,
        .baseSpAttack  = 135,
        .baseSpDefense = 115,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 45,
        .expYield = 284,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_MEGA_LAUNCHER, ABILITY_MEGA_LAUNCHER},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_SLOWBRO_MEGA] =
    {
        .baseHP        = 95,
        .baseAttack    = 75,
        .baseDefense   = 180,
        .baseSpeed     = 30,
        .baseSpAttack  = 130,
        .baseSpDefense = 80,
        .types = { TYPE_WATER, TYPE_PSYCHIC},
        .catchRate = 75,
        .expYield = 207,
        .evYield_Defense   = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_SHELL_ARMOR, ABILITY_SHELL_ARMOR},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_MEWTWO_MEGA_X] =
    {
        .baseHP        = 106,
        .baseAttack    = 190,
        .baseDefense   = 100,
        .baseSpeed     = 130,
        .baseSpAttack  = 154,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 351,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_STEADFAST, ABILITY_STEADFAST},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_MEWTWO_MEGA_Y] =
    {
        .baseHP        = 106,
        .baseAttack    = 150,
        .baseDefense   = 70,
        .baseSpeed     = 140,
        .baseSpAttack  = 194,
        .baseSpDefense = 120,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 351,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_INSOMNIA, ABILITY_INSOMNIA},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_SCEPTILE_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 75,
        .baseSpeed     = 145,
        .baseSpAttack  = 145,
        .baseSpDefense = 85,
        .types = { TYPE_GRASS, TYPE_DRAGON},
        .catchRate = 45,
        .expYield = 284,
        .evYield_Speed     = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON},
        .abilities = {ABILITY_LIGHTNING_ROD, ABILITY_LIGHTNING_ROD},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_BLAZIKEN_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 160,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 130,
        .baseSpDefense = 80,
        .types = { TYPE_FIRE, TYPE_FIGHTING},
        .catchRate = 45,
        .expYield = 284,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SPEED_BOOST, ABILITY_SPEED_BOOST},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_SWAMPERT_MEGA] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 110,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 110,
        .types = { TYPE_WATER, TYPE_GROUND},
        .catchRate = 45,
        .expYield = 286,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_SWIFT_SWIM, ABILITY_SWIFT_SWIM},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_LATIAS_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 110,
        .baseSpAttack  = 140,
        .baseSpDefense = 150,
        .types = { TYPE_DRAGON, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 315,
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_LEVITATE, ABILITY_LEVITATE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_LATIOS_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 110,
        .baseSpAttack  = 160,
        .baseSpDefense = 120,
        .types = { TYPE_DRAGON, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 315,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_LEVITATE, ABILITY_LEVITATE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_RAYQUAZA_MEGA] =
    {
        .baseHP        = 105,
        .baseAttack    = 180,
        .baseDefense   = 100,
        .baseSpeed     = 115,
        .baseSpAttack  = 180,
        .baseSpDefense = 100,
        .types = { TYPE_DRAGON, TYPE_FLYING},
        .catchRate = 45,
        .expYield = 306,
        .evYield_Attack    = 2,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DELTA_STREAM, ABILITY_DELTA_STREAM},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_MEGA_EVOLUTION,
    },

    [SPECIES_KYOGRE_PRIMAL] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 180,
        .baseSpDefense = 160,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 3,
        .expYield = 302,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRIMORDIAL_SEA, ABILITY_PRIMORDIAL_SEA},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_PRIMAL_REVERSION,
    },

    [SPECIES_GROUDON_PRIMAL] =
    {
        .baseHP        = 100,
        .baseAttack    = 180,
        .baseDefense   = 160,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 90,
        .types = { TYPE_GROUND, TYPE_FIRE},
        .catchRate = 3,
        .expYield = 302,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DESOLATE_LAND, ABILITY_DESOLATE_LAND},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_PRIMAL_REVERSION,
    },

    [SPECIES_RATTATA_ALOLAN] =
    {
        .baseHP        = 30,
        .baseAttack    = 56,
        .baseDefense   = 35,
        .baseSpeed     = 72,
        .baseSpAttack  = 25,
        .baseSpDefense = 35,
        .types = { TYPE_DARK, TYPE_NORMAL},
        .catchRate = 255,
        .expYield = 51,
        .evYield_Speed     = 1,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_GLUTTONY, ABILITY_HUSTLE, ABILITY_THICK_FAT},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_RATICATE_ALOLAN] =
    {
        .baseHP        = 75,
        .baseAttack    = 71,
        .baseDefense   = 70,
        .baseSpeed     = 77,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        .types = { TYPE_DARK, TYPE_NORMAL},
        .catchRate = 127,
        .expYield = 145,
        .evYield_Speed     = 2,
        .itemRare = ITEM_PECHA_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_GLUTTONY, ABILITY_HUSTLE, ABILITY_THICK_FAT},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_RAICHU_ALOLAN] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 110,
        .baseSpAttack  = 95,
        .baseSpDefense = 85,
        .types = { TYPE_ELECTRIC, TYPE_PSYCHIC},
        .catchRate = 75,
        .expYield = 218,
        .evYield_Speed     = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY},
        .abilities = {ABILITY_SURGE_SURFER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_SANDSHREW_ALOLAN] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 90,
        .baseSpeed     = 40,
        .baseSpAttack  = 10,
        .baseSpDefense = 35,
        .types = { TYPE_ICE, TYPE_STEEL},
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense   = 1,
        .itemRare = ITEM_GRIP_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SLUSH_RUSH},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_SANDSLASH_ALOLAN] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 65,
        .baseSpAttack  = 25,
        .baseSpDefense = 65,
        .types = { TYPE_ICE, TYPE_STEEL},
        .catchRate = 90,
        .expYield = 158,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SLUSH_RUSH},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_VULPIX_ALOLAN] =
    {
        .baseHP        = 38,
        .baseAttack    = 41,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 190,
        .expYield = 60,
        .evYield_Speed     = 1,
        .itemRare = ITEM_SNOWBALL,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SNOW_WARNING},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_NINETALES_ALOLAN] =
    {
        .baseHP        = 73,
        .baseAttack    = 67,
        .baseDefense   = 75,
        .baseSpeed     = 109,
        .baseSpAttack  = 81,
        .baseSpDefense = 100,
        .types = { TYPE_ICE, TYPE_FAIRY},
        .catchRate = 75,
        .expYield = 177,
        .evYield_Speed     = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SNOW_WARNING},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_DIGLETT_ALOLAN] =
    {
        .baseHP        = 10,
        .baseAttack    = 55,
        .baseDefense   = 30,
        .baseSpeed     = 90,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        .types = { TYPE_GROUND, TYPE_STEEL},
        .catchRate = 255,
        .expYield = 53,
        .evYield_Speed     = 1,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_TANGLING_HAIR, ABILITY_SAND_FORCE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_DUGTRIO_ALOLAN] =
    {
        .baseHP        = 35,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        .types = { TYPE_GROUND, TYPE_STEEL},
        .catchRate = 50,
        .expYield = 149,
        .evYield_Speed     = 2,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SAND_VEIL, ABILITY_TANGLING_HAIR, ABILITY_SAND_FORCE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_MEOWTH_ALOLAN] =
    {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = { TYPE_DARK, TYPE_DARK},
        .catchRate = 255,
        .expYield = 58,
        .evYield_Speed     = 1,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_PICKUP, ABILITY_TECHNICIAN, ABILITY_RATTLED},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_PERSIAN_ALOLAN] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 75,
        .baseSpDefense = 65,
        .types = { TYPE_DARK, TYPE_DARK},
        .catchRate = 90,
        .expYield = 154,
        .evYield_Speed     = 2,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_FUR_COAT, ABILITY_TECHNICIAN, ABILITY_RATTLED},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_GEODUDE_ALOLAN] =
    {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 20,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_ROCK, TYPE_ELECTRIC},
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense   = 1,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_GALVANIZE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_GRAVELER_ALOLAN] =
    {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_ELECTRIC},
        .catchRate = 120,
        .expYield = 137,
        .evYield_Defense   = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_GALVANIZE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_GOLEM_ALOLAN] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 130,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_ROCK, TYPE_ELECTRIC},
        .catchRate = 45,
        .expYield = 223,
        .evYield_Defense   = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_MAGNET_PULL, ABILITY_STURDY, ABILITY_GALVANIZE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_GRIMER_ALOLAN] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_POISON, TYPE_DARK},
        .catchRate = 190,
        .expYield = 65,
        .evYield_HP        = 1,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_POISON_TOUCH, ABILITY_GLUTTONY, ABILITY_POWER_OF_ALCHEMY},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_MUK_ALOLAN] =
    {
        .baseHP        = 105,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 100,
        .types = { TYPE_POISON, TYPE_DARK},
        .catchRate = 75,
        .expYield = 175,
        .evYield_HP        = 1,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_POISON_TOUCH, ABILITY_GLUTTONY, ABILITY_POWER_OF_ALCHEMY},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_ALOLAN_FORM,
    },

    [SPECIES_MEOWTH_GALARIAN] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_STEEL, TYPE_STEEL},
        .catchRate = 255,
        .expYield = 58,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_PICKUP, ABILITY_TOUGH_CLAWS, ABILITY_UNNERVE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_PONYTA_GALARIAN] =
    {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 190,
        .expYield = 82,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_RUN_AWAY, ABILITY_PASTEL_VEIL, ABILITY_ANTICIPATION},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_RAPIDASH_GALARIAN] =
    {
        .baseHP        = 65,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 105,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_PSYCHIC, TYPE_FAIRY},
        .catchRate = 60,
        .expYield = 175,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_RUN_AWAY, ABILITY_PASTEL_VEIL, ABILITY_ANTICIPATION},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_SLOWPOKE_GALARIAN] =
    {
        .baseHP        = 90,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 15,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 190,
        .expYield = 63,
        .evYield_HP        = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_GLUTTONY, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_SLOWBRO_GALARIAN] =
    {
        .baseHP        = 95,
        .baseAttack    = 100,
        .baseDefense   = 95,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 70,
        .types = { TYPE_POISON, TYPE_PSYCHIC},
        .catchRate = 75,
        .expYield = 172,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1},
        .abilities = {ABILITY_QUICK_DRAW, ABILITY_OWN_TEMPO, ABILITY_REGENERATOR},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_FARFETCHD_GALARIAN] =
    {
        .baseHP        = 52,
        .baseAttack    = 95,
        .baseDefense   = 55,
        .baseSpeed     = 55,
        .baseSpAttack  = 58,
        .baseSpDefense = 62,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING},
        .catchRate = 45,
        .expYield = 132,
        .evYield_Attack    = 1,
        .itemCommon = ITEM_LEEK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FIELD},
        .abilities = {ABILITY_STEADFAST, ABILITY_NONE, ABILITY_SCRAPPY},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_MR_MIME_GALARIAN] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 90,
        .baseSpDefense = 90,
        .types = { TYPE_ICE, TYPE_PSYCHIC},
        .catchRate = 45,
        .expYield = 161,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE},
        .abilities = {ABILITY_VITAL_SPIRIT, ABILITY_SCREEN_CLEANER, ABILITY_ICE_BODY},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_ARTICUNO_GALARIAN] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 85,
        .baseSpeed     = 95,
        .baseSpAttack  = 125,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_COMPETITIVE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_ZAPDOS_GALARIAN] =
    {
        .baseHP        = 90,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 100,
        .baseSpAttack  = 85,
        .baseSpDefense = 90,
        .types = { TYPE_FIGHTING, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 290,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DEFIANT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_MOLTRES_GALARIAN] =
    {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 125,
        .types = { TYPE_DARK, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BERSERK, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_CORSOLA_GALARIAN] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 100,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = 100,
        .types = { TYPE_GHOST, TYPE_GHOST},
        .catchRate = 60,
        .expYield = 144,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3},
        .abilities = {ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_ZIGZAGOON_GALARIAN] =
    {
        .baseHP        = 38,
        .baseAttack    = 30,
        .baseDefense   = 41,
        .baseSpeed     = 60,
        .baseSpAttack  = 30,
        .baseSpDefense = 41,
        .types = { TYPE_DARK, TYPE_NORMAL},
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_PICKUP, ABILITY_GLUTTONY, ABILITY_QUICK_FEET},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_LINOONE_GALARIAN] =
    {
        .baseHP        = 78,
        .baseAttack    = 70,
        .baseDefense   = 61,
        .baseSpeed     = 100,
        .baseSpAttack  = 50,
        .baseSpDefense = 61,
        .types = { TYPE_DARK, TYPE_NORMAL},
        .catchRate = 90,
        .expYield = 147,
        .evYield_Speed     = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_PICKUP, ABILITY_GLUTTONY, ABILITY_QUICK_FEET},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

#if P_GEN_5_POKEMON == TRUE
    [SPECIES_DARUMAKA_GALARIAN] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 15,
        .baseSpDefense = 45,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 120,
        .expYield = 63,
        .evYield_Attack    = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_HUSTLE, ABILITY_NONE, ABILITY_INNER_FOCUS},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_DARMANITAN_GALARIAN] =
    {
        .baseHP        = 105,
        .baseAttack    = 140,
        .baseDefense   = 55,
        .baseSpeed     = 95,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 60,
        .expYield = 168,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_GORILLA_TACTICS, ABILITY_NONE, ABILITY_ZEN_MODE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_YAMASK_GALARIAN] =
    {
        .baseHP        = 38,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        .types = { TYPE_GROUND, TYPE_GHOST},
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense   = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_WANDERING_SPIRIT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_STUNFISK_GALARIAN] =
    {
        .baseHP        = 109,
        .baseAttack    = 81,
        .baseDefense   = 99,
        .baseSpeed     = 32,
        .baseSpAttack  = 66,
        .baseSpDefense = 84,
        .types = { TYPE_GROUND, TYPE_STEEL},
        .catchRate = 75,
        .expYield = 165,
        .evYield_HP        = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS},
        .abilities = {ABILITY_MIMICRY, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },
#endif

#if P_GEN_5_POKEMON == TRUE
    [SPECIES_ZORUA_HISUIAN] =
    {
        .baseHP        = 35,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 85,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_GHOST},
        .catchRate = 75,
        .expYield = 66,
        .evYield_SpAttack  = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_ILLUSION, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_HISUIAN_FORM,
    },

    [SPECIES_ZOROARK_HISUIAN] =
    {
        .baseHP        = 55,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 125,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_GHOST},
        .catchRate = 45,
        .expYield = 179,
        .evYield_SpAttack  = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_ILLUSION, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_HISUIAN_FORM,
    },
#endif

#if P_GEN_6_POKEMON == TRUE
    [SPECIES_AVALUGG_HISUIAN] =
    {
        .baseHP        = 95,
        .baseAttack    = 127,
        .baseDefense   = 184,
        .baseSpeed     = 38,
        .baseSpAttack  = 34,
        .baseSpDefense = 36,
        .types = { TYPE_ICE, TYPE_ROCK},
        .catchRate = 55,
        .expYield = 180,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_STRONG_JAW, ABILITY_ICE_BODY, ABILITY_STURDY},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_HISUIAN_FORM,
    },
#endif

    [SPECIES_PIKACHU_COSPLAY]   = COSPLAY_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_ROCK_STAR] = COSPLAY_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_BELLE]     = COSPLAY_PIKACHU_SPECIES_INFO(NO_FLIP),
    [SPECIES_PIKACHU_POP_STAR]  = COSPLAY_PIKACHU_SPECIES_INFO(NO_FLIP),
    [SPECIES_PIKACHU_PH_D]      = COSPLAY_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_LIBRE]     = COSPLAY_PIKACHU_SPECIES_INFO(FLIP),

    [SPECIES_PIKACHU_ORIGINAL_CAP] = CAP_PIKACHU_SPECIES_INFO(NO_FLIP),
    [SPECIES_PIKACHU_HOENN_CAP]    = CAP_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_SINNOH_CAP]   = CAP_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_UNOVA_CAP]    = CAP_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_KALOS_CAP]    = CAP_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_ALOLA_CAP]    = CAP_PIKACHU_SPECIES_INFO(FLIP),
    [SPECIES_PIKACHU_PARTNER_CAP]  = CAP_PIKACHU_SPECIES_INFO(NO_FLIP),
    [SPECIES_PIKACHU_WORLD_CAP]    = CAP_PIKACHU_SPECIES_INFO(FLIP),

    [SPECIES_PICHU_SPIKY_EARED] = PICHU_SPECIES_INFO(NO_FLIP),

    [SPECIES_UNOWN_B] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_C] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_D] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_E] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_F] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_G] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_H] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_I] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_J] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_K] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_L] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_M] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_N] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_O] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_P] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_Q] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_R] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_S] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_T] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_U] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_V] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_W] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_X] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_Y] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_Z] = UNOWN_SPECIES_INFO(NO_FLIP),
    [SPECIES_UNOWN_EMARK] = UNOWN_SPECIES_INFO(FLIP),
    [SPECIES_UNOWN_QMARK] = UNOWN_SPECIES_INFO(NO_FLIP),

    [SPECIES_CASTFORM_SUNNY] = CASTFORM_SPECIES_INFO(TYPE_FIRE, BODY_COLOR_RED),
    [SPECIES_CASTFORM_RAINY] = CASTFORM_SPECIES_INFO(TYPE_WATER, BODY_COLOR_BLUE),
    [SPECIES_CASTFORM_SNOWY] = CASTFORM_SPECIES_INFO(TYPE_ICE, BODY_COLOR_WHITE),

    [SPECIES_DEOXYS_ATTACK] =
    {
        .baseHP        = 50,
        .baseAttack    = 180,
        .baseDefense   = 20,
        .baseSpeed     = 150,
        .baseSpAttack  = 180,
        .baseSpDefense = 20,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack    = 2,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_DEOXYS_DEFENSE] =
    {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 160,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 160,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Defense   = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_DEOXYS_SPEED] =
    {
        .baseHP        = 50,
        .baseAttack    = 95,
        .baseDefense   = 90,
        .baseSpeed     = 180,
        .baseSpAttack  = 95,
        .baseSpDefense = 90,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
    },

#if P_GEN_4_POKEMON == TRUE
    [SPECIES_CHERRIM_SUNSHINE] = CHERRIM_SPECIES_INFO(BODY_COLOR_PINK),

    [SPECIES_SHELLOS_EAST_SEA] = SHELLOS_SPECIES_INFO(BODY_COLOR_BLUE),

    [SPECIES_GASTRODON_EAST_SEA] = GASTRODON_SPECIES_INFO(BODY_COLOR_BLUE),

    [SPECIES_ROTOM_HEAT]  = ROTOM_FORM_SPECIES_INFO(TYPE_FIRE, FLIP),
    [SPECIES_ROTOM_WASH]  = ROTOM_FORM_SPECIES_INFO(TYPE_WATER, NO_FLIP),
    [SPECIES_ROTOM_FROST] = ROTOM_FORM_SPECIES_INFO(TYPE_ICE, FLIP),
    [SPECIES_ROTOM_FAN]   = ROTOM_FORM_SPECIES_INFO(TYPE_FLYING, FLIP),
    [SPECIES_ROTOM_MOW]   = ROTOM_FORM_SPECIES_INFO(TYPE_GRASS, FLIP),

    [SPECIES_DIALGA_ORIGIN] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .types = { TYPE_STEEL, TYPE_DRAGON},
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_PALKIA_ORIGIN] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 120,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .types = { TYPE_WATER, TYPE_DRAGON},
        .catchRate = 3,
        .expYield = 306,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_GIRATINA_ORIGIN] =
    {
        .baseHP        = 150,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 90,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        .types = { TYPE_GHOST, TYPE_DRAGON},
        .catchRate = 3,
        .expYield = 306,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_LEVITATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
    },

    [SPECIES_SHAYMIN_SKY] =
    {
        .baseHP        = 100,
        .baseAttack    = 103,
        .baseDefense   = 75,
        .baseSpeed     = 127,
        .baseSpAttack  = 120,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FLYING},
        .catchRate = 45,
        .expYield = 270,
        .evYield_HP        = 3,
        .itemCommon = ITEM_LUM_BERRY,
        .itemRare = ITEM_LUM_BERRY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_SERENE_GRACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
    },

    [SPECIES_ARCEUS_FIGHTING] = ARCEUS_SPECIES_INFO(TYPE_FIGHTING),
    [SPECIES_ARCEUS_FLYING]   = ARCEUS_SPECIES_INFO(TYPE_FLYING),
    [SPECIES_ARCEUS_POISON]   = ARCEUS_SPECIES_INFO(TYPE_POISON),
    [SPECIES_ARCEUS_GROUND]   = ARCEUS_SPECIES_INFO(TYPE_GROUND),
    [SPECIES_ARCEUS_ROCK]     = ARCEUS_SPECIES_INFO(TYPE_ROCK),
    [SPECIES_ARCEUS_BUG]      = ARCEUS_SPECIES_INFO(TYPE_BUG),
    [SPECIES_ARCEUS_GHOST]    = ARCEUS_SPECIES_INFO(TYPE_GHOST),
    [SPECIES_ARCEUS_STEEL]    = ARCEUS_SPECIES_INFO(TYPE_STEEL),
    [SPECIES_ARCEUS_FIRE]     = ARCEUS_SPECIES_INFO(TYPE_FIRE),
    [SPECIES_ARCEUS_WATER]    = ARCEUS_SPECIES_INFO(TYPE_WATER),
    [SPECIES_ARCEUS_GRASS]    = ARCEUS_SPECIES_INFO(TYPE_GRASS),
    [SPECIES_ARCEUS_ELECTRIC] = ARCEUS_SPECIES_INFO(TYPE_ELECTRIC),
    [SPECIES_ARCEUS_PSYCHIC]  = ARCEUS_SPECIES_INFO(TYPE_PSYCHIC),
    [SPECIES_ARCEUS_ICE]      = ARCEUS_SPECIES_INFO(TYPE_ICE),
    [SPECIES_ARCEUS_DRAGON]   = ARCEUS_SPECIES_INFO(TYPE_DRAGON),
    [SPECIES_ARCEUS_DARK]     = ARCEUS_SPECIES_INFO(TYPE_DARK),
    [SPECIES_ARCEUS_FAIRY]    = ARCEUS_SPECIES_INFO(TYPE_FAIRY),
#endif

#if P_GEN_5_POKEMON == TRUE
    [SPECIES_BASCULIN_BLUE_STRIPED] =
    {
        .baseHP        = 70,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 98,
        .baseSpAttack  = 80,
        .baseSpDefense = 55,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 25,
        .expYield = 161,
        .evYield_Speed     = 2,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_ROCK_HEAD, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_BASCULIN_WHITE_STRIPED] =
    {
        .baseHP        = 70,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 98,
        .baseSpAttack  = 80,
        .baseSpDefense = 55,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 25,
        .expYield = 161,
        .evYield_Speed     = 2,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_RATTLED, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
    },

    [SPECIES_DARMANITAN_ZEN_MODE] =
    {
        .baseHP        = 105,
        .baseAttack    = 30,
        .baseDefense   = 105,
        .baseSpeed     = 55,
        .baseSpAttack  = 140,
        .baseSpDefense = 105,
        .types = { TYPE_FIRE, TYPE_PSYCHIC},
        .catchRate = 60,
        .expYield = 189,
        .evYield_SpAttack  = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_ZEN_MODE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_DARMANITAN_ZEN_MODE_GALARIAN] =
    {
        .baseHP        = 105,
        .baseAttack    = 160,
        .baseDefense   = 55,
        .baseSpeed     = 135,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = { TYPE_ICE, TYPE_FIRE},
        .catchRate = 60,
        .expYield = 189,
        .evYield_SpAttack  = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_GORILLA_TACTICS, ABILITY_NONE, ABILITY_ZEN_MODE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_GALARIAN_FORM,
    },

    [SPECIES_DEERLING_SUMMER] = DEERLING_SPECIES_INFO(BODY_COLOR_GREEN),
    [SPECIES_DEERLING_AUTUMN] = DEERLING_SPECIES_INFO(BODY_COLOR_RED),
    [SPECIES_DEERLING_WINTER] = DEERLING_SPECIES_INFO(BODY_COLOR_BROWN),

    [SPECIES_SAWSBUCK_SUMMER] = SAWSBUCK_SPECIES_INFO,
    [SPECIES_SAWSBUCK_AUTUMN] = SAWSBUCK_SPECIES_INFO,
    [SPECIES_SAWSBUCK_WINTER] = SAWSBUCK_SPECIES_INFO,

    [SPECIES_TORNADUS_THERIAN] =
    {
        .baseHP        = 79,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 121,
        .baseSpAttack  = 110,
        .baseSpDefense = 90,
        .types = { TYPE_FLYING, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack    = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_REGENERATOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_THUNDURUS_THERIAN] =
    {
        .baseHP        = 79,
        .baseAttack    = 105,
        .baseDefense   = 70,
        .baseSpeed     = 101,
        .baseSpAttack  = 145,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_VOLT_ABSORB, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_LANDORUS_THERIAN] =
    {
        .baseHP        = 89,
        .baseAttack    = 145,
        .baseDefense   = 90,
        .baseSpeed     = 91,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .types = { TYPE_GROUND, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack  = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_INTIMIDATE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_KYUREM_WHITE] =
    {
        .baseHP        = 125,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 170,
        .baseSpDefense = 100,
        .types = { TYPE_DRAGON, TYPE_ICE},
        .catchRate = 3,
        .expYield = 315,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_TURBOBLAZE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_CANNOT_BE_TRADED,
    },

    [SPECIES_KYUREM_BLACK] =
    {
        .baseHP        = 125,
        .baseAttack    = 170,
        .baseDefense   = 100,
        .baseSpeed     = 95,
        .baseSpAttack  = 120,
        .baseSpDefense = 90,
        .types = { TYPE_DRAGON, TYPE_ICE},
        .catchRate = 3,
        .expYield = 315,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_TERAVOLT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_CANNOT_BE_TRADED,
    },

    [SPECIES_KELDEO_RESOLUTE] =
    {
        .baseHP        = 91,
        .baseAttack    = 72,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 129,
        .baseSpDefense = 90,
        .types = { TYPE_WATER, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 261,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_JUSTIFIED, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_MELOETTA_PIROUETTE] =
    {
        .baseHP        = 100,
        .baseAttack    = 128,
        .baseDefense   = 90,
        .baseSpeed     = 128,
        .baseSpAttack  = 77,
        .baseSpDefense = 77,
        .types = { TYPE_NORMAL, TYPE_FIGHTING},
        .catchRate = 3,
        .expYield = 270,
        .evYield_Attack  = 1,
        .evYield_Defense = 1,
        .evYield_Speed     = 1,
        .itemCommon = ITEM_STAR_PIECE,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_SERENE_GRACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },

    [SPECIES_GENESECT_DOUSE_DRIVE] = GENESECT_SPECIES_INFO,
    [SPECIES_GENESECT_SHOCK_DRIVE] = GENESECT_SPECIES_INFO,
    [SPECIES_GENESECT_BURN_DRIVE] = GENESECT_SPECIES_INFO,
    [SPECIES_GENESECT_CHILL_DRIVE] = GENESECT_SPECIES_INFO,
#endif

#if P_GEN_6_POKEMON == TRUE
    [SPECIES_GRENINJA_BATTLE_BOND] =
    {
        .baseHP        = 72,
        .baseAttack    = 95,
        .baseDefense   = 67,
        .baseSpeed     = 122,
        .baseSpAttack  = 103,
        .baseSpDefense = 71,
        .types = { TYPE_WATER, TYPE_DARK},
        .catchRate = 45,
        .expYield = 239,
        .evYield_Speed     = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BATTLE_BOND, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
    },

    [SPECIES_GRENINJA_ASH] =
    {
        .baseHP        = 72,
        .baseAttack    = 145,
        .baseDefense   = 67,
        .baseSpeed     = 132,
        .baseSpAttack  = 153,
        .baseSpDefense = 71,
        .types = { TYPE_WATER, TYPE_DARK},
        .catchRate = 45,
        .expYield = 288,
        .evYield_Speed     = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_BATTLE_BOND, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
    },

    [SPECIES_VIVILLON_POLAR]       = VIVILLON_SPECIES_INFO(BODY_COLOR_BLUE),
    [SPECIES_VIVILLON_TUNDRA]      = VIVILLON_SPECIES_INFO(BODY_COLOR_BLUE),
    [SPECIES_VIVILLON_CONTINENTAL] = VIVILLON_SPECIES_INFO(BODY_COLOR_YELLOW),
    [SPECIES_VIVILLON_GARDEN]      = VIVILLON_SPECIES_INFO(BODY_COLOR_GREEN),
    [SPECIES_VIVILLON_ELEGANT]     = VIVILLON_SPECIES_INFO(BODY_COLOR_PURPLE),
    [SPECIES_VIVILLON_MEADOW]      = VIVILLON_SPECIES_INFO(BODY_COLOR_PINK),
    [SPECIES_VIVILLON_MODERN]      = VIVILLON_SPECIES_INFO(BODY_COLOR_RED),
    [SPECIES_VIVILLON_MARINE]      = VIVILLON_SPECIES_INFO(BODY_COLOR_BLUE),
    [SPECIES_VIVILLON_ARCHIPELAGO] = VIVILLON_SPECIES_INFO(BODY_COLOR_BROWN),
    [SPECIES_VIVILLON_HIGH_PLAINS] = VIVILLON_SPECIES_INFO(BODY_COLOR_BROWN),
    [SPECIES_VIVILLON_SANDSTORM]   = VIVILLON_SPECIES_INFO(BODY_COLOR_BROWN),
    [SPECIES_VIVILLON_RIVER]       = VIVILLON_SPECIES_INFO(BODY_COLOR_BROWN),
    [SPECIES_VIVILLON_MONSOON]     = VIVILLON_SPECIES_INFO(BODY_COLOR_GRAY),
    [SPECIES_VIVILLON_SAVANNA]     = VIVILLON_SPECIES_INFO(BODY_COLOR_GREEN),
    [SPECIES_VIVILLON_SUN]         = VIVILLON_SPECIES_INFO(BODY_COLOR_RED),
    [SPECIES_VIVILLON_OCEAN]       = VIVILLON_SPECIES_INFO(BODY_COLOR_RED),
    [SPECIES_VIVILLON_JUNGLE]      = VIVILLON_SPECIES_INFO(BODY_COLOR_GREEN),
    [SPECIES_VIVILLON_FANCY]       = VIVILLON_SPECIES_INFO(BODY_COLOR_PINK),
    [SPECIES_VIVILLON_POKE_BALL]   = VIVILLON_SPECIES_INFO(BODY_COLOR_RED),

    [SPECIES_FLABEBE_YELLOW_FLOWER] = FLABEBE_SPECIES_INFO,
    [SPECIES_FLABEBE_ORANGE_FLOWER] = FLABEBE_SPECIES_INFO,
    [SPECIES_FLABEBE_BLUE_FLOWER]   = FLABEBE_SPECIES_INFO,
    [SPECIES_FLABEBE_WHITE_FLOWER]  = FLABEBE_SPECIES_INFO,

    [SPECIES_FLOETTE_YELLOW_FLOWER] = FLOETTE_SPECIES_INFO,
    [SPECIES_FLOETTE_ORANGE_FLOWER] = FLOETTE_SPECIES_INFO,
    [SPECIES_FLOETTE_BLUE_FLOWER]   = FLOETTE_SPECIES_INFO,
    [SPECIES_FLOETTE_WHITE_FLOWER]  = FLOETTE_SPECIES_INFO,

    [SPECIES_FLOETTE_ETERNAL_FLOWER] =
    {
        .baseHP        = 74,
        .baseAttack    = 65,
        .baseDefense   = 67,
        .baseSpeed     = 92,
        .baseSpAttack  = 125,
        .baseSpDefense = 128,
        .types = { TYPE_FAIRY, TYPE_FAIRY},
        .catchRate = 120,
        .expYield = 243,
        .evYield_SpDefense = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
    },

    [SPECIES_FLORGES_YELLOW_FLOWER] = FLORGES_SPECIES_INFO,
    [SPECIES_FLORGES_ORANGE_FLOWER] = FLORGES_SPECIES_INFO,
    [SPECIES_FLORGES_BLUE_FLOWER]   = FLORGES_SPECIES_INFO,
    [SPECIES_FLORGES_WHITE_FLOWER]  = FLORGES_SPECIES_INFO,

    [SPECIES_FURFROU_HEART_TRIM]     = FURFROU_SPECIES_INFO(FLIP),
    [SPECIES_FURFROU_STAR_TRIM]      = FURFROU_SPECIES_INFO(FLIP),
    [SPECIES_FURFROU_DIAMOND_TRIM]   = FURFROU_SPECIES_INFO(FLIP),
    [SPECIES_FURFROU_DEBUTANTE_TRIM] = FURFROU_SPECIES_INFO(NO_FLIP),
    [SPECIES_FURFROU_MATRON_TRIM]    = FURFROU_SPECIES_INFO(FLIP),
    [SPECIES_FURFROU_DANDY_TRIM]     = FURFROU_SPECIES_INFO(FLIP),
    [SPECIES_FURFROU_LA_REINE_TRIM]  = FURFROU_SPECIES_INFO(FLIP),
    [SPECIES_FURFROU_KABUKI_TRIM]    = FURFROU_SPECIES_INFO(FLIP),
    [SPECIES_FURFROU_PHARAOH_TRIM]   = FURFROU_SPECIES_INFO(FLIP),

    [SPECIES_AEGISLASH_BLADE] =
    {
        .baseHP        = 60,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        #if P_UPDATED_STATS >= GEN_8
        .baseAttack    = 140,
        .baseSpAttack  = 140,
        #else
        .baseAttack    = 150,
        .baseSpAttack  = 150,
        #endif
        .baseSpDefense = 50,
        .types = { TYPE_STEEL, TYPE_GHOST},
        .catchRate = 45,
        .expYield = 234,
        .evYield_Defense   = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL},
        .abilities = {ABILITY_STANCE_CHANGE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_PUMPKABOO_SMALL] =
    {
        .baseHP        = 44,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 56,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        PUMKPABOO_MISC_INFO,
    },

    [SPECIES_PUMPKABOO_LARGE] =
    {
        .baseHP        = 54,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 46,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        PUMKPABOO_MISC_INFO,
    },

    [SPECIES_PUMPKABOO_SUPER] =
    {
        .baseHP        = 59,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 41,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .itemCommon = ITEM_MIRACLE_SEED,
        .itemRare = ITEM_MIRACLE_SEED,
        PUMKPABOO_MISC_INFO,
    },

    [SPECIES_GOURGEIST_SMALL] =
    {
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 122,
        .baseSpeed     = 99,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        GOURGEIST_MISC_INFO,
    },

    [SPECIES_GOURGEIST_LARGE] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 122,
        .baseSpeed     = 69,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        GOURGEIST_MISC_INFO,
    },

    [SPECIES_GOURGEIST_SUPER] =
    {
        .baseHP        = 85,
        .baseAttack    = 100,
        .baseDefense   = 122,
        .baseSpeed     = 54,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .itemCommon = ITEM_MIRACLE_SEED,
        .itemRare = ITEM_MIRACLE_SEED,
        GOURGEIST_MISC_INFO,
    },

    [SPECIES_XERNEAS_ACTIVE] = XERNEAS_SPECIES_INFO,

    [SPECIES_ZYGARDE_10] = ZYGARDE_10_SPECIES_INFO(ABILITY_AURA_BREAK),
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = ZYGARDE_50_SPECIES_INFO(ABILITY_POWER_CONSTRUCT),
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = ZYGARDE_50_SPECIES_INFO(ABILITY_POWER_CONSTRUCT),

    [SPECIES_ZYGARDE_COMPLETE] =
    {
        .baseHP        = 216,
        .baseAttack    = 100,
        .baseDefense   = 121,
        .baseSpeed     = 85,
        .baseSpAttack  = 91,
        .baseSpDefense = 95,
        .types = { TYPE_DRAGON, TYPE_GROUND},
        .catchRate = 3,
        .expYield = 319,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_POWER_CONSTRUCT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_HOOPA_UNBOUND] =
    {
        .baseHP        = 80,
        .baseAttack    = 160,
        .baseDefense   = 60,
        .baseSpeed     = 80,
        .baseSpAttack  = 170,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_DARK},
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_MAGICIAN, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_MYTHICAL,
    },
#endif

#if P_GEN_7_POKEMON == TRUE
    [SPECIES_ORICORIO_POM_POM] = ORICORIO_SPECIES_INFO(TYPE_ELECTRIC, BODY_COLOR_YELLOW),
    [SPECIES_ORICORIO_PAU]     = ORICORIO_SPECIES_INFO(TYPE_PSYCHIC, BODY_COLOR_PINK),
    [SPECIES_ORICORIO_SENSU]   = ORICORIO_SPECIES_INFO(TYPE_GHOST, BODY_COLOR_PURPLE),

    [SPECIES_ROCKRUFF_OWN_TEMPO] = ROCKRUFF_SPECIES_INFO(ABILITY_OWN_TEMPO, ABILITY_NONE, ABILITY_NONE),

    [SPECIES_LYCANROC_MIDNIGHT] =
    {
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 75,
        .baseSpeed     = 82,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = { TYPE_ROCK, TYPE_ROCK},
        .catchRate = 90,
        .expYield = 170,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_KEEN_EYE, ABILITY_VITAL_SPIRIT, ABILITY_NO_GUARD},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
    },

    [SPECIES_LYCANROC_DUSK] =
    {
        .baseHP        = 75,
        .baseAttack    = 117,
        .baseDefense   = 65,
        .baseSpeed     = 110,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_ROCK, TYPE_ROCK},
        .catchRate = 90,
        .expYield = 170,
        .evYield_Attack    = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD},
        .abilities = {ABILITY_TOUGH_CLAWS, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = FALSE,
    },

    [SPECIES_WISHIWASHI_SCHOOL] =
    {
        .baseHP        = 45,
        .baseAttack    = 140,
        .baseDefense   = 130,
        .baseSpeed     = 30,
        .baseSpAttack  = 140,
        .baseSpDefense = 135,
        .types = { TYPE_WATER, TYPE_WATER},
        .catchRate = 60,
        .expYield = 61,
        .evYield_HP        = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2},
        .abilities = {ABILITY_HUDDLE_UP, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_SILVALLY_FIGHTING] = SILVALLY_SPECIES_INFO(TYPE_FIGHTING),
    [SPECIES_SILVALLY_FLYING]   = SILVALLY_SPECIES_INFO(TYPE_FLYING),
    [SPECIES_SILVALLY_POISON]   = SILVALLY_SPECIES_INFO(TYPE_POISON),
    [SPECIES_SILVALLY_GROUND]   = SILVALLY_SPECIES_INFO(TYPE_GROUND),
    [SPECIES_SILVALLY_ROCK]     = SILVALLY_SPECIES_INFO(TYPE_ROCK),
    [SPECIES_SILVALLY_BUG]      = SILVALLY_SPECIES_INFO(TYPE_BUG),
    [SPECIES_SILVALLY_GHOST]    = SILVALLY_SPECIES_INFO(TYPE_GHOST),
    [SPECIES_SILVALLY_STEEL]    = SILVALLY_SPECIES_INFO(TYPE_STEEL),
    [SPECIES_SILVALLY_FIRE]     = SILVALLY_SPECIES_INFO(TYPE_FIRE),
    [SPECIES_SILVALLY_WATER]    = SILVALLY_SPECIES_INFO(TYPE_WATER),
    [SPECIES_SILVALLY_GRASS]    = SILVALLY_SPECIES_INFO(TYPE_GRASS),
    [SPECIES_SILVALLY_ELECTRIC] = SILVALLY_SPECIES_INFO(TYPE_ELECTRIC),
    [SPECIES_SILVALLY_PSYCHIC]  = SILVALLY_SPECIES_INFO(TYPE_PSYCHIC),
    [SPECIES_SILVALLY_ICE]      = SILVALLY_SPECIES_INFO(TYPE_ICE),
    [SPECIES_SILVALLY_DRAGON]   = SILVALLY_SPECIES_INFO(TYPE_DRAGON),
    [SPECIES_SILVALLY_DARK]     = SILVALLY_SPECIES_INFO(TYPE_DARK),
    [SPECIES_SILVALLY_FAIRY]    = SILVALLY_SPECIES_INFO(TYPE_FAIRY),

    [SPECIES_MINIOR_METEOR_ORANGE] = MINIOR_METEOR_SPECIES_INFO,
    [SPECIES_MINIOR_METEOR_YELLOW] = MINIOR_METEOR_SPECIES_INFO,
    [SPECIES_MINIOR_METEOR_GREEN]  = MINIOR_METEOR_SPECIES_INFO,
    [SPECIES_MINIOR_METEOR_BLUE]   = MINIOR_METEOR_SPECIES_INFO,
    [SPECIES_MINIOR_METEOR_INDIGO] = MINIOR_METEOR_SPECIES_INFO,
    [SPECIES_MINIOR_METEOR_VIOLET] = MINIOR_METEOR_SPECIES_INFO,

    [SPECIES_MINIOR_CORE_RED]    = MINIOR_CORE_SPECIES_INFO(BODY_COLOR_RED),
    [SPECIES_MINIOR_CORE_ORANGE] = MINIOR_CORE_SPECIES_INFO(BODY_COLOR_RED),
    [SPECIES_MINIOR_CORE_YELLOW] = MINIOR_CORE_SPECIES_INFO(BODY_COLOR_YELLOW),
    [SPECIES_MINIOR_CORE_GREEN]  = MINIOR_CORE_SPECIES_INFO(BODY_COLOR_GREEN),
    [SPECIES_MINIOR_CORE_BLUE]   = MINIOR_CORE_SPECIES_INFO(BODY_COLOR_BLUE),
    [SPECIES_MINIOR_CORE_INDIGO] = MINIOR_CORE_SPECIES_INFO(BODY_COLOR_BLUE),
    [SPECIES_MINIOR_CORE_VIOLET] = MINIOR_CORE_SPECIES_INFO(BODY_COLOR_PURPLE),

    [SPECIES_MIMIKYU_BUSTED] = MIMIKYU_SPECIES_INFO,

    [SPECIES_NECROZMA_DUSK_MANE] =
    {
        .baseHP        = 97,
        .baseAttack    = 157,
        .baseDefense   = 127,
        .baseSpeed     = 77,
        .baseSpAttack  = 113,
        .baseSpDefense = 109,
        .types = { TYPE_PSYCHIC, TYPE_STEEL},
        .catchRate = 255,
        .expYield = 306,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRISM_ARMOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_CANNOT_BE_TRADED,
    },

    [SPECIES_NECROZMA_DAWN_WINGS] =
    {
        .baseHP        = 97,
        .baseAttack    = 113,
        .baseDefense   = 109,
        .baseSpeed     = 77,
        .baseSpAttack  = 157,
        .baseSpDefense = 127,
        .types = { TYPE_PSYCHIC, TYPE_GHOST},
        .catchRate = 255,
        .expYield = 306,
        .evYield_SpAttack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRISM_ARMOR, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_CANNOT_BE_TRADED,
    },

    [SPECIES_NECROZMA_ULTRA] =
    {
        .baseHP        = 97,
        .baseAttack    = 167,
        .baseDefense   = 97,
        .baseSpeed     = 129,
        .baseSpAttack  = 167,
        .baseSpDefense = 97,
        .types = { TYPE_PSYCHIC, TYPE_DRAGON},
        .catchRate = 255,
        .expYield = 339,
        .evYield_Attack    = 1,
        .evYield_Speed     = 1,
        .evYield_SpAttack  = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_NEUROFORCE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_ULTRA_BURST,
    },

    [SPECIES_MAGEARNA_ORIGINAL_COLOR] = MAGEARNA_SPECIES_INFO(BODY_COLOR_RED),
#endif

#if P_GEN_8_POKEMON == TRUE
    [SPECIES_CRAMORANT_GULPING] = CRAMORANT_SPECIES_INFO,
    [SPECIES_CRAMORANT_GORGING] = CRAMORANT_SPECIES_INFO,

    [SPECIES_TOXTRICITY_LOW_KEY] = TOXTRICITY_SPECIES_INFO(ABILITY_MINUS),

    [SPECIES_SINISTEA_ANTIQUE] = SINISTEA_SPECIES_INFO,

    [SPECIES_POLTEAGEIST_ANTIQUE] = POLTEAGEIST_SPECIES_INFO,

    [SPECIES_ALCREMIE_RUBY_CREAM]    = ALCREMIE_SPECIES_INFO(BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_MATCHA_CREAM]  = ALCREMIE_SPECIES_INFO(BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_MINT_CREAM]    = ALCREMIE_SPECIES_INFO(BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_LEMON_CREAM]   = ALCREMIE_SPECIES_INFO(BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_SALTED_CREAM]  = ALCREMIE_SPECIES_INFO(BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_RUBY_SWIRL]    = ALCREMIE_SPECIES_INFO(BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_CARAMEL_SWIRL] = ALCREMIE_SPECIES_INFO(BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_RAINBOW_SWIRL] = ALCREMIE_SPECIES_INFO(BODY_COLOR_YELLOW),

    [SPECIES_EISCUE_NOICE_FACE] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 130,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        .types = { TYPE_ICE, TYPE_ICE},
        .catchRate = 60,
        .expYield = 165,
        .evYield_Defense   = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD},
        .abilities = {ABILITY_ICE_FACE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
    },

    [SPECIES_MORPEKO_HANGRY] = MORPEKO_SPECIES_INFO,

    [SPECIES_ZACIAN_CROWNED_SWORD] =
    {
        .baseHP        = 92,
        .baseAttack    = 170,
        .baseDefense   = 115,
        .baseSpeed     = 148,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = { TYPE_FAIRY, TYPE_STEEL},
        .catchRate = 10,
        .expYield = 360,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_INTREPID_SWORD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ZAMAZENTA_CROWNED_SHIELD] =
    {
        .baseHP        = 92,
        .baseAttack    = 130,
        .baseDefense   = 145,
        .baseSpeed     = 128,
        .baseSpAttack  = 80,
        .baseSpDefense = 145,
        .types = { TYPE_FIGHTING, TYPE_STEEL},
        .catchRate = 10,
        .expYield = 360,
        .evYield_Speed     = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_DAUNTLESS_SHIELD, ABILITY_NONE},
        .bodyColor = BODY_COLOR_RED,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ETERNATUS_ETERNAMAX] =
    {
        .baseHP        = 255,
        .baseAttack    = 115,
        .baseDefense   = 250,
        .baseSpeed     = 130,
        .baseSpAttack  = 125,
        .baseSpDefense = 250,
        .types = { TYPE_POISON, TYPE_DRAGON},
        .catchRate = 255,
        .expYield = 563,
        .evYield_HP        = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_PRESSURE, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE] =
    {
        .baseHP        = 100,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 97,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = { TYPE_FIGHTING, TYPE_WATER},
        .catchRate = 3,
        .expYield = 275,
        .evYield_Attack    = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_UNSEEN_FIST, ABILITY_NONE},
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },

    [SPECIES_ZARUDE_DADA] = ZARUDE_SPECIES_INFO,

    [SPECIES_CALYREX_ICE_RIDER] =
    {
        .baseHP        = 100,
        .baseAttack    = 165,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 85,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_ICE},
        .catchRate = 3,
        .expYield = 340,
        .evYield_Attack    = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_AS_ONE_ICE_RIDER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_CANNOT_BE_TRADED,
    },

    [SPECIES_CALYREX_SHADOW_RIDER] =
    {
        .baseHP        = 100,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 150,
        .baseSpAttack  = 165,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_GHOST},
        .catchRate = 3,
        .expYield = 340,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_AS_ONE_SHADOW_RIDER, ABILITY_NONE},
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY | SPECIES_FLAG_CANNOT_BE_TRADED,
    },

    [SPECIES_ENAMORUS_THERIAN] =
    {
        .baseHP        = 74,
        .baseAttack    = 115,
        .baseDefense   = 110,
        .baseSpeed     = 46,
        .baseSpAttack  = 135,
        .baseSpDefense = 100,
        .types = { TYPE_FAIRY, TYPE_FLYING},
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack  = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_UNDISCOVERED, EGG_GROUP_UNDISCOVERED},
        .abilities = {ABILITY_OVERCOAT, ABILITY_NONE},
        .bodyColor = BODY_COLOR_PINK,
        .noFlip = FALSE,
        .flags = SPECIES_FLAG_LEGENDARY,
    },
#endif
};
