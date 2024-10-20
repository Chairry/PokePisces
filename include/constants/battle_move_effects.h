#ifndef GUARD_CONSTANTS_BATTLE_MOVE_EFFECTS_H
#define GUARD_CONSTANTS_BATTLE_MOVE_EFFECTS_H

#define EFFECT_HIT                          0
#define EFFECT_SLEEP                        1
#define EFFECT_POISON_HIT                   2
#define EFFECT_ABSORB                       3
#define EFFECT_BURN_HIT                     4
#define EFFECT_FREEZE_HIT                   5
#define EFFECT_PARALYZE_HIT                 6
#define EFFECT_EXPLOSION                    7
#define EFFECT_DREAM_EATER                  8
#define EFFECT_MIRROR_MOVE                  9
#define EFFECT_ATTACK_UP                    10
#define EFFECT_DEFENSE_UP                   11
#define EFFECT_SPEED_UP                     12
#define EFFECT_SPECIAL_ATTACK_UP            13
#define EFFECT_SPECIAL_DEFENSE_UP           14
#define EFFECT_ACCURACY_UP                  15
#define EFFECT_EVASION_UP                   16
#define EFFECT_SPECIAL_ATTACK_UP_3          17
#define EFFECT_ATTACK_DOWN                  18
#define EFFECT_DEFENSE_DOWN                 19
#define EFFECT_SPEED_DOWN                   20
#define EFFECT_SPECIAL_ATTACK_DOWN          21
#define EFFECT_SPECIAL_DEFENSE_DOWN         22
#define EFFECT_ACCURACY_DOWN                23
#define EFFECT_EVASION_DOWN                 24
#define EFFECT_HAZE                         25 //Changed in Pisces, added in checks for Substitute and Screens to existing EFFECT_HAZE code
#define EFFECT_BIDE                         26 //Changed in Pisces, lowered HP thresholds for preventing use due to defense raises in EFFECT_BIDE code
#define EFFECT_RAMPAGE                      27
#define EFFECT_ROAR                         28
#define EFFECT_MULTI_HIT                    29
#define EFFECT_CONVERSION                   30
#define EFFECT_FLINCH_HIT                   31
#define EFFECT_RESTORE_HP                   32
#define EFFECT_TOXIC                        33
#define EFFECT_PAY_DAY                      34
#define EFFECT_LIGHT_SCREEN                 35
#define EFFECT_TRI_ATTACK                   36 //Added to AI_RISKY
#define EFFECT_REST                         37
#define EFFECT_OHKO                         38
#define EFFECT_FUSION_COMBO                 39
#define EFFECT_SUPER_FANG                   40
#define EFFECT_DRAGON_RAGE                  41 //Changed in Pisces, added a new level-based conditional to the fixed damage calc
#define EFFECT_TRAP                         42
#define EFFECT_HEAL_BLOCK                   43 //Changed in Pisces, added in stuff from EFFECT_MEAN_LOOK to existing EFFECT_HEAL_BLOCK code
#define EFFECT_RECOIL_IF_MISS               44
#define EFFECT_MIST                         45 //Added to SETUP_FIRST_TURN, will need this and FLAG_SCREENER to be used often
#define EFFECT_FOCUS_ENERGY                 46 //Changed in Pisces, added in check for ABILITY_INNER_FOCUS to existing EFFECT_FOCUS_ENERGY code
#define EFFECT_RECOIL_25                    47
#define EFFECT_CONFUSE                      48
#define EFFECT_ATTACK_UP_2                  49
#define EFFECT_DEFENSE_UP_2                 50
#define EFFECT_SPEED_UP_2                   51
#define EFFECT_SPECIAL_ATTACK_UP_2          52
#define EFFECT_SPECIAL_DEFENSE_UP_2         53
#define EFFECT_ACCURACY_UP_2                54
#define EFFECT_EVASION_UP_2                 55
#define EFFECT_TRANSFORM                    56
#define EFFECT_ATTACK_DOWN_2                57
#define EFFECT_DEFENSE_DOWN_2               58
#define EFFECT_SPEED_DOWN_2                 59
#define EFFECT_SPECIAL_ATTACK_DOWN_2        60
#define EFFECT_SPECIAL_DEFENSE_DOWN_2       61
#define EFFECT_ACCURACY_DOWN_2              62
#define EFFECT_EVASION_DOWN_2               63
#define EFFECT_REFLECT                      64
#define EFFECT_POISON                       65
#define EFFECT_PARALYZE                     66
#define EFFECT_ATTACK_DOWN_HIT              67
#define EFFECT_DEFENSE_DOWN_HIT             68
#define EFFECT_SPEED_DOWN_HIT               69
#define EFFECT_SPECIAL_ATTACK_DOWN_HIT      70
#define EFFECT_SPECIAL_DEFENSE_DOWN_HIT     71
#define EFFECT_ACCURACY_DOWN_HIT            72
#define EFFECT_EVASION_DOWN_HIT             73
#define EFFECT_TWO_TURNS_ATTACK             74
#define EFFECT_CONFUSE_HIT                  75
#define EFFECT_VITAL_THROW                  76 //Changed in Pisces, added in stuff from EFFECT_HIT_SWITCH_TARGET to existing EFFECT_VITAL_THROW code
#define EFFECT_SUBSTITUTE                   77
#define EFFECT_RECHARGE                     78
#define EFFECT_RAGE                         79 //Changed in Pisces, though according to EFFECT_REVELATION_DANCE, doesnt need special additional code
#define EFFECT_MIMIC                        80
#define EFFECT_METRONOME                    81
#define EFFECT_LEECH_SEED                   82 //Changed in Pisces, added in stuff from EFFECT_TRAP with a Blooming conditional to existing EFFECT_LEECH_SEED code
#define EFFECT_DO_NOTHING                   83
#define EFFECT_DISABLE                      84
#define EFFECT_LEVEL_DAMAGE                 85
#define EFFECT_PSYWAVE                      86
#define EFFECT_COUNTER                      87
#define EFFECT_ENCORE                       88
#define EFFECT_PAIN_SPLIT                   89
#define EFFECT_SNORE                        90
#define EFFECT_CONVERSION_2                 91
#define EFFECT_LOCK_ON                      92
#define EFFECT_SKETCH                       93
#define EFFECT_HAMMER_ARM                   94
#define EFFECT_SLEEP_TALK                   95
#define EFFECT_DESTINY_BOND                 96
#define EFFECT_FLAIL                        97
#define EFFECT_SPITE                        98
#define EFFECT_FALSE_SWIPE                  99 //Changed in Pisces, though its level varying BP should not necessitate additional code
#define EFFECT_HEAL_BELL                    100
#define EFFECT_ALWAYS_CRIT                  101
#define EFFECT_TRIPLE_KICK                  102 //Added to AI_RISKY
#define EFFECT_THIEF                        103
#define EFFECT_MEAN_LOOK                    104 //Changed in Pisces, added in stuff from EFFECT_FAKE_OUT to existing EFFECT_MEAN_LOOK code
#define EFFECT_NIGHTMARE                    105 //Changed in Pisces, added in stuff from EFFECT_SLEEP and conditionals on whether or not the target is currently asleep to existing EFFECT_NIGHTMARE code
#define EFFECT_MINIMIZE                     106
#define EFFECT_CURSE                        107
#define EFFECT_HEALING_WISH                 108
#define EFFECT_PROTECT                      109
#define EFFECT_SPIKES                       110
#define EFFECT_FORESIGHT                    111
#define EFFECT_PERISH_SONG                  112
#define EFFECT_SANDSTORM                    113
#define EFFECT_ENDURE                       114
#define EFFECT_ROLLOUT                      115
#define EFFECT_SWAGGER                      116
#define EFFECT_FURY_CUTTER                  117
#define EFFECT_ATTRACT                      118
#define EFFECT_RETURN                       119
#define EFFECT_PRESENT                      120
#define EFFECT_FRUSTRATION                  121
#define EFFECT_SAFEGUARD                    122
#define EFFECT_MAGNITUDE                    123
#define EFFECT_BATON_PASS                   124
#define EFFECT_PURSUIT                      125
#define EFFECT_RAPID_SPIN                   126
#define EFFECT_SONICBOOM                    127 //Changed in Pisces, added a new level-based conditional to the fixed damage calc
#define EFFECT_CAPTIVATE                    128                  //This move appears to have no special AI code although I think it needs some. Will come back to
#define EFFECT_MORNING_SUN                  129
#define EFFECT_SYNTHESIS                    130
#define EFFECT_MOONLIGHT                    131
#define EFFECT_HIDDEN_POWER                 132
#define EFFECT_RAIN_DANCE                   133
#define EFFECT_SUNNY_DAY                    134
#define EFFECT_DEFENSE_UP_HIT               135
#define EFFECT_ATTACK_UP_HIT                136
#define EFFECT_ALL_STATS_UP_HIT             137
#define EFFECT_FELL_STINGER                 138
#define EFFECT_BELLY_DRUM                   139
#define EFFECT_PSYCH_UP                     140
#define EFFECT_MIRROR_COAT                  141
#define EFFECT_SKULL_BASH                   142
#define EFFECT_EARTHQUAKE                   143
#define EFFECT_FUTURE_SIGHT                 144 //Added to AI_RISKY
#define EFFECT_GUST                         145
#define EFFECT_SOLAR_BEAM                   146
#define EFFECT_THUNDER                      147
#define EFFECT_TELEPORT                     148
#define EFFECT_BEAT_UP                      149
#define EFFECT_SEMI_INVULNERABLE            150
#define EFFECT_DEFENSE_CURL                 151
#define EFFECT_SOFTBOILED                   152
#define EFFECT_FAKE_OUT                     153
#define EFFECT_UPROAR                       154
#define EFFECT_STOCKPILE                    155
#define EFFECT_SPIT_UP                      156
#define EFFECT_SWALLOW                      157
#define EFFECT_WORRY_SEED                   158 //Changed in Pisces, added in stuff from EFFECT_TERRORIZE to existing EFFECT_WORRY_SEED code
#define EFFECT_HAIL                         159
#define EFFECT_TORMENT                      160
#define EFFECT_FLATTER                      161
#define EFFECT_WILL_O_WISP                  162
#define EFFECT_MEMENTO                      163
#define EFFECT_FACADE                       164
#define EFFECT_FOCUS_PUNCH                  165
#define EFFECT_SMELLINGSALT                 166
#define EFFECT_FOLLOW_ME                    167
#define EFFECT_NATURE_POWER                 168
#define EFFECT_CHARGE                       169 //Changed in Pisces, added in ELECTRIC_TERRAIN conditional to existing EFFECT_CHARGE code
#define EFFECT_TAUNT                        170
#define EFFECT_HELPING_HAND                 171
#define EFFECT_TRICK                        172
#define EFFECT_ROLE_PLAY                    173
#define EFFECT_WISH                         174
#define EFFECT_ASSIST                       175
#define EFFECT_INGRAIN                      176 //Changed in Pisces, added in self-Blooming conditional
#define EFFECT_SUPERPOWER                   177
#define EFFECT_MAGIC_COAT                   178
#define EFFECT_RECYCLE                      179
#define EFFECT_REVENGE                      180
#define EFFECT_BRICK_BREAK                  181
#define EFFECT_YAWN                         182
#define EFFECT_KNOCK_OFF                    183
#define EFFECT_ENDEAVOR                     184
#define EFFECT_ERUPTION                     185
#define EFFECT_SKILL_SWAP                   186
#define EFFECT_IMPRISON                     187                 //Changed in Pisces but requires borrowed code from EFFECT_PURSUIT which is weird rn so saving for later
#define EFFECT_REFRESH                      188
#define EFFECT_GRUDGE                       189
#define EFFECT_SNATCH                       190
#define EFFECT_LOW_KICK                     191 //Changed in Pisces, added in Gravity check
#define EFFECT_SECRET_POWER                 192
#define EFFECT_RECOIL_33                    193
#define EFFECT_TEETER_DANCE                 194
#define EFFECT_HIT_ESCAPE                   195
#define EFFECT_MUD_SPORT                    196
#define EFFECT_POISON_FANG                  197
#define EFFECT_WEATHER_BALL                 198
#define EFFECT_OVERHEAT                     199
#define EFFECT_TICKLE                       200
#define EFFECT_COSMIC_POWER                 201
#define EFFECT_SKY_UPPERCUT                 202
#define EFFECT_BULK_UP                      203
#define EFFECT_PLACEHOLDER                  204
#define EFFECT_WATER_SPORT                  205
#define EFFECT_CALM_MIND                    206
#define EFFECT_DRAGON_DANCE                 207
#define EFFECT_CAMOUFLAGE                   208

// New move effects
#define EFFECT_PLEDGE                       209
#define EFFECT_FLING                        210
#define EFFECT_NATURAL_GIFT                 211
#define EFFECT_WAKE_UP_SLAP                 212
#define EFFECT_WRING_OUT                    213
#define EFFECT_HEX                          214                 //Changed in Pisces but requires borrowed code from EFFECT_SPITE which is weird rn so saving for later
#define EFFECT_ASSURANCE                    215
#define EFFECT_TRUMP_CARD                   216
#define EFFECT_ACROBATICS                   217
#define EFFECT_HEAT_CRASH                   218 //Changed in Pisces, added in Gravity check
#define EFFECT_PUNISHMENT                   219
#define EFFECT_STORED_POWER                 220
#define EFFECT_ELECTRO_BALL                 221
#define EFFECT_GYRO_BALL                    222
#define EFFECT_ECHOED_VOICE                 223
#define EFFECT_PAYBACK                      224
#define EFFECT_ROUND                        225
#define EFFECT_BRINE                        226
#define EFFECT_VENOSHOCK                    227
#define EFFECT_RETALIATE                    228
#define EFFECT_BULLDOZE                     229
#define EFFECT_FOUL_PLAY                    230
#define EFFECT_PSYSHOCK                     231
#define EFFECT_ROOST                        232
#define EFFECT_GRAVITY                      233 //Changed in Pisces, added checks for Gravity-benefitted damaging moves on the user, encouraging use if so
#define EFFECT_MIRACLE_EYE                  234 //Changed completely in Pisces, added checks for positive stat changes on target and upped score accordingly
#define EFFECT_TAILWIND                     235 //Changed in Pisces, added checks for Tailwind-benefitted damaging moves on the user, encouraging use if so
#define EFFECT_EMBARGO                      236
#define EFFECT_AQUA_RING                    237
#define EFFECT_TRICK_ROOM                   238
#define EFFECT_WONDER_ROOM                  239                 //Changed in Pisces but imma be real witcha chief I aint know where to start
#define EFFECT_MAGIC_ROOM                   240
#define EFFECT_MAGNET_RISE                  241 //Changed in Pisces, added in stuff from EFFECT_SPEED_UP to existing EFFECT_MAGNET_RISE code
#define EFFECT_TOXIC_SPIKES                 242
#define EFFECT_GASTRO_ACID                  243
#define EFFECT_STEALTH_ROCK                 244
#define EFFECT_TELEKINESIS                  245 //Changed in Pisces, added in stuff from EFFECT_TRAP to existing EFFECT_TELEKINESIS code
#define EFFECT_POWER_SWAP                   246                 //Following 5 effects are tough to handle so I'm leaving them for now
#define EFFECT_GUARD_SWAP                   247
#define EFFECT_HEART_SWAP                   248
#define EFFECT_POWER_SPLIT                  249
#define EFFECT_GUARD_SPLIT                  250
#define EFFECT_STICKY_WEB                   251
#define EFFECT_METAL_BURST                  252
#define EFFECT_LUCKY_CHANT                  253 //Changed in Pisces, Lucky Chant is just plain better here so I upped the scores and added to SETUP_FIRST_TURN
#define EFFECT_SUCKER_PUNCH                 254
#define EFFECT_SPECIAL_DEFENSE_DOWN_HIT_2   255
#define EFFECT_SIMPLE_BEAM                  256
#define EFFECT_ENTRAINMENT                  257
#define EFFECT_HEAL_PULSE                   258
#define EFFECT_QUASH                        259
#define EFFECT_ION_DELUGE                   260 //Changed in Pisces, effect is more powerful so upped scores and adjusted conditionals some
#define EFFECT_FREEZE_DRY                   261
#define EFFECT_TOPSY_TURVY                  262
#define EFFECT_MISTY_TERRAIN                263
#define EFFECT_GRASSY_TERRAIN               264
#define EFFECT_ELECTRIC_TERRAIN             265
#define EFFECT_PSYCHIC_TERRAIN              266
#define EFFECT_ATTACK_ACCURACY_UP           267
#define EFFECT_ATTACK_SPATK_UP              268
#define EFFECT_HURRICANE                    269
#define EFFECT_TWO_TYPED_MOVE               270
#define EFFECT_ME_FIRST                     271
#define EFFECT_SPEED_UP_HIT                 272
#define EFFECT_QUIVER_DANCE                 273
#define EFFECT_COIL                         274
#define EFFECT_ELECTRIFY                    275
#define EFFECT_REFLECT_TYPE                 276                 //Changed in Pisces but imma be real witcha chief I aint know where to start
#define EFFECT_SOAK                         277
#define EFFECT_GROWTH                       278
#define EFFECT_CLOSE_COMBAT                 279
#define EFFECT_LAST_RESORT                  280
#define EFFECT_RECOIL_33_STATUS             281
#define EFFECT_FLINCH_STATUS                282
#define EFFECT_RECOIL_50                    283
#define EFFECT_SHELL_SMASH                  284
#define EFFECT_SHIFT_GEAR                   285
#define EFFECT_DEFENSE_UP_3                 286
#define EFFECT_NOBLE_ROAR                   287 //Changed completely in Pisces, copied EFFECT_FAKE_OUT
#define EFFECT_VENOM_DRENCH                 288 //Changed in Pisces, effect is more powerful so upped scores and adjusted conditionals some
#define EFFECT_TOXIC_THREAD                 289
#define EFFECT_CLEAR_SMOG                   290
#define EFFECT_HIT_SWITCH_TARGET            291
#define EFFECT_FINAL_GAMBIT                 292
#define EFFECT_CHANGE_TYPE_ON_ITEM          293
#define EFFECT_AUTOTOMIZE                   294
#define EFFECT_COPYCAT                      295
#define EFFECT_DEFOG                        296
#define EFFECT_HIT_ENEMY_HEAL_ALLY          297
#define EFFECT_SMACK_DOWN                   298 //Changed in Pisces, added in Gravity check
#define EFFECT_SYNCHRONOISE                 299
#define EFFECT_PSYCHO_SHIFT                 300
#define EFFECT_POWER_TRICK                  301
#define EFFECT_FLAME_BURST                  302
#define EFFECT_AFTER_YOU                    303
#define EFFECT_BESTOW                       304
#define EFFECT_ROTOTILLER                   305                  //Both this and FLOWER_SHIELD below have similar uncoded effects. Waiting on these
#define EFFECT_FLOWER_SHIELD                306
#define EFFECT_HIT_PREVENT_ESCAPE           307
#define EFFECT_SPEED_SWAP                   308
#define EFFECT_DEFENSE_UP2_HIT              309
#define EFFECT_REVELATION_DANCE             310
#define EFFECT_AURORA_VEIL                  311
#define EFFECT_THIRD_TYPE                   312
#define EFFECT_FEINT                        313
#define EFFECT_SPARKLING_ARIA               314
#define EFFECT_ACUPRESSURE                  315
#define EFFECT_AROMATIC_MIST                316                  //Move is already coded kinda lackluster, will come back to
#define EFFECT_POWDER                       317 //Changed in Pisces, added in code from EFFECT_ACCURACY_DOWN to existing EFFECT_POWDER code
#define EFFECT_SP_ATTACK_UP_HIT             318
#define EFFECT_BELCH                        319
#define EFFECT_PARTING_SHOT                 320
#define EFFECT_SPECTRAL_THIEF               321
#define EFFECT_V_CREATE                     322
#define EFFECT_MAT_BLOCK                    323
#define EFFECT_STOMPING_TANTRUM             324
#define EFFECT_CORE_ENFORCER                325
#define EFFECT_INSTRUCT                     326
#define EFFECT_THROAT_CHOP                  327
#define EFFECT_LASER_FOCUS                  328
#define EFFECT_MAGNETIC_FLUX                329
#define EFFECT_GEAR_UP                      330
#define EFFECT_INCINERATE                   331
#define EFFECT_BUG_BITE                     332
#define EFFECT_STRENGTH_SAP                 333
#define EFFECT_MIND_BLOWN                   334
#define EFFECT_PURIFY                       335
#define EFFECT_BURN_UP                      336
#define EFFECT_SHORE_UP                     337
#define EFFECT_GEOMANCY                     338
#define EFFECT_FAIRY_LOCK                   339
#define EFFECT_ALLY_SWITCH                  340
#define EFFECT_RELIC_SONG                   341
#define EFFECT_ATTACKER_DEFENSE_DOWN_HIT    342
#define EFFECT_BODY_PRESS                   343
#define EFFECT_EERIE_SPELL                  344
#define EFFECT_JUNGLE_HEALING               345
#define EFFECT_COACHING                     346
#define EFFECT_LASH_OUT                     347
#define EFFECT_GRASSY_GLIDE                 348
#define EFFECT_DYNAMAX_DOUBLE_DMG           349
#define EFFECT_DECORATE                     350
#define EFFECT_SNIPE_SHOT                   351
#define EFFECT_RECOIL_HP_25                 352
#define EFFECT_STUFF_CHEEKS                 353
#define EFFECT_GRAV_APPLE                   354 //Changed in Pisces, added in code from EFFECT_FLINCH_HIT under a Blooming conditional to existing EFFECT_GRAV_APPLE code
#define EFFECT_EVASION_UP_HIT               355
#define EFFECT_GLITZY_GLOW                  356
#define EFFECT_BADDY_BAD                    357
#define EFFECT_SAPPY_SEED                   358
#define EFFECT_FREEZY_FROST                 359
#define EFFECT_SPARKLY_SWIRL                360
#define EFFECT_PLASMA_FISTS                 361
#define EFFECT_HYPERSPACE_FURY              362
#define EFFECT_AURA_WHEEL                   363
#define EFFECT_PHOTON_GEYSER                364
#define EFFECT_SHELL_SIDE_ARM               365
#define EFFECT_TERRAIN_PULSE                366
#define EFFECT_JAW_LOCK                     367
#define EFFECT_NO_RETREAT                   368
#define EFFECT_TAR_SHOT                     369
#define EFFECT_POLTERGEIST                  370
#define EFFECT_OCTOLOCK                     371
#define EFFECT_CLANGOROUS_SOUL              372
#define EFFECT_BOLT_BEAK                    373
#define EFFECT_SKY_DROP                     374
#define EFFECT_EXPANDING_FORCE              375
#define EFFECT_METEOR_BEAM                  376
#define EFFECT_RISING_VOLTAGE               377
#define EFFECT_BEAK_BLAST                   378
#define EFFECT_COURT_CHANGE                 379
#define EFFECT_STEEL_BEAM                   380
#define EFFECT_EXTREME_EVOBOOST             381
#define EFFECT_HIT_SET_REMOVE_TERRAIN       382 //Edited for Pisces
#define EFFECT_DARK_VOID                    383
#define EFFECT_SLEEP_HIT                    384
#define EFFECT_DOUBLE_SHOCK                 385
#define EFFECT_SPECIAL_ATTACK_UP_HIT        386
#define EFFECT_VICTORY_DANCE                387
#define EFFECT_TEATIME                      388
#define EFFECT_ATTACK_UP_USER_ALLY          389 // Howl 8th Gen
#define EFFECT_SHELL_TRAP                   390
#define EFFECT_PSYBLADE                     391
#define EFFECT_HYDRO_STEAM                  392
#define EFFECT_HIT_SET_ENTRY_HAZARD         393
#define EFFECT_DIRE_CLAW                    394 //Added to AI_RISKY
#define EFFECT_BARB_BARRAGE                 395
#define EFFECT_REVIVAL_BLESSING             396
#define EFFECT_FROSTBITE_HIT                397
#define EFFECT_SNOWSCAPE                    398
#define EFFECT_TRIPLE_ARROWS                399
#define EFFECT_INFERNAL_PARADE              400
#define EFFECT_TAKE_HEART                   401
#define EFFECT_AXE_KICK                     402
#define EFFECT_COLLISION_COURSE             403
#define EFFECT_SPIN_OUT                     404
#define EFFECT_MAKE_IT_RAIN                 405
#define EFFECT_CORROSIVE_GAS                406
#define EFFECT_POPULATION_BOMB              407
#define EFFECT_MORTAL_SPIN                  408
#define EFFECT_GIGATON_HAMMER               409
#define EFFECT_SALT_CURE                    410 //Below this are effects we added for Pisces, will denote which have AI flags completed
#define EFFECT_GLACIATE                     411 //AI Flags complete
#define EFFECT_CHILLY_AIR                   412 //AI Flags complete
#define EFFECT_LAST_RESPECTS                413 //AI Flags added, used new function CalcRageFistPower (works for this and below), may be some bugs, untested 
#define EFFECT_RAGE_FIST                    414 //AI Flags added, used new function CalcRageFistPower, may be some bugs, untested
#define EFFECT_FILLET_AWAY                  415 //AI Flags complete
#define EFFECT_CHILLY_RECEPTION             416 //AI Flags added, combined stuff from EFFECT_HAIL and EFFECT_TELEPORT, may cause a bug
#define EFFECT_SHED_TAIL                    417 //AI Flags added, combined stuff from EFFECT_SUBSTITUTE and EFFECT_TELEPORT, may cause a bug
#define EFFECT_FICKLE_BEAM                  418 //AI Flags complete
#define EFFECT_DRAGON_CHEER                 419 //AI Flags complete
#define EFFECT_PSYCHIC_NOISE                420 //AI Flags complete (mostly copied what Heal Block already had)
#define EFFECT_SNUFF_OUT                    421 //According to EFFECT_FREEZE_DRY, this doesnt need any special AI code
#define EFFECT_COLD_MEND                    422 //AI Flags complete
#define EFFECT_VIPER_STRIKE                 423 //According to EFFECT_POISON_HIT, this doesnt need any special AI code
#define EFFECT_ALL_STATS_UP_2_HIT           424 //AI Flags complete
#define EFFECT_SPOOK                        425 //AI Flags complete
#define EFFECT_U_TURN                       426 //AI Flags complete
#define EFFECT_SILVER_WIND                  427 //AI Flags complete
#define EFFECT_SIGNAL_BEAM                  428 //AI Flags complete
#define EFFECT_RAGE_POWDER                  429 //AI Flags complete
#define EFFECT_SPIDER_WEB                   430 //AI Flags added, combined stuff from EFFECT_TRAP and stat down effects, may cause a bug
#define EFFECT_RECOIL_50_STATUS             431 //AI Flags complete
#define EFFECT_EERIE_IMPULSE                432 //AI Flags complete
#define EFFECT_FLASH                        433 //AI Flags complete
#define EFFECT_CHARM                        434 //AI Flags added, combined stuff from EFFECT_WAKE_UP_SLAP and stat down effects, may cause a bug
#define EFFECT_BITTER_MALICE                435 //According to EFFECT_FROSTBITE_HIT, this doesnt need any special AI code, but will prob add something for the status condition power raise
#define EFFECT_HEART_STAMP                  436 //AI Flags complete
#define EFFECT_MEDITATE                     437 //AI Flags complete
#define EFFECT_FLIP_TURN                    438 //AI Flags complete
#define EFFECT_MUDDY_WATER                  439 //According to EFFECT_FLYING_PRESS, this doesnt need any special AI code (i did add it under EFFECT_ACCURACY_DOWN_HIT though)
#define EFFECT_DRAGON_RUIN                  440 //AI Flags added, combined stuff from EFFECT_RECHARGE and EFFECT_SKULL_BASH, may cause a bug
#define EFFECT_CINDER_TWIRL                 441 //AI Flags added, may need to add more scoring in in regards to which form would be best. Currently just added it to SetupFirstTurn
#define EFFECT_CINDER_DRILL                 442 //AI Flags added, may need to add more scoring in in regards to which form would be best. Currently just added it to SetupFirstTurn
#define EFFECT_SILENCE                      443 //AI Flags complete
#define EFFECT_TORMENT_HIT                  444 //AI Flags complete
#define EFFECT_DECAY_BEAM                   445 //According to EFFECT_FREEZE_DRY and EFFECT_EERIE_SPELL, this doesnt need any special AI code
#define EFFECT_WARM_WELCOME                 446 //AI Flags complete
#define EFFECT_RADIOACID                    447 //AI Flags complete
#define EFFECT_PARTING_CURRY                448 //AI Flags complete
#define EFFECT_SERPENT_SURGE                449 //AI Flags added, combined stuff from various effects based on the different abilities. Should see if problems are caused
#define EFFECT_TIDY_UP                      450 //AI Flags added in from latest Expansion build
#define EFFECT_DRAINING_KISS                451 //AI Flags complete, should not need a check for infatuation because AI factors in calculated damage increases
#define EFFECT_HULLBREAKER                  452 //AI Flags added, combined stuff from EFFECT_FEINT and EFFECT_BRICK_BREAK, may cause a bug
#define EFFECT_HEART_CARVE_HIT              453 //AI Flags complete
#define EFFECT_DRAGON_POKER                 454 //AI Flags added, kinda just copied Magnitude but it doesnt have much. Added it and Magnitude to AI_Risky
#define EFFECT_WATERFALL                    455 //AI Flags complete (For Waterfall through Whirlpool, EFFECT_RETURN was merged with their regular effects)
#define EFFECT_CUT                          456 //AI Flags complete
#define EFFECT_ROCK_SMASH                   457 //AI Flags complete
#define EFFECT_STRENGTH                     458 //AI Flags complete
#define EFFECT_ROCK_CLIMB                   459 //AI Flags complete
#define EFFECT_SURF                         460 //AI Flags complete
#define EFFECT_DIVE                         461 //AI Flags complete
#define EFFECT_FLY                          462 //AI Flags complete
#define EFFECT_WHIRLPOOL                    463 //AI Flags complete
#define EFFECT_LONE_SHARK                   464 //AI Flags added, currently is encouraged above 60% health to use it but could maybe add more sophisticated check in future
#define EFFECT_HEART_STEAL                  465 //AI Flags complete
#define EFFECT_IGNA_STRIKE                  466 //According to EFFECT_FREEZE_DRY, this doesnt need any special AI code
#define EFFECT_ACCURACY_DEFENSE_DOWN_HIT    467 //AI Flags complete
#define EFFECT_VENOM_DRAIN                  468 //AI Flags added, combined EFFECT_ABSORB with a check for PSN_ANY
#define EFFECT_ALL_STATS_DOWN_HIT           469 //AI Flags added, combined EFFECT_ATTACK_DOWN_HIT with a check for PSN_ANY
#define EFFECT_WILLPOWER                    470 //According to EFFECT_BODY_PRESS, this doesnt need any special AI code 
#define EFFECT_MANEUVER                     471 //AI Flags complete
#define EFFECT_SCORP_FANG                   472 //AI Flags complete
#define EFFECT_RECOIL_50_HAZARD             473 //AI Flags added, combined stuff from EFFECT_RECOIL_50 and EFFECT_HIT_SET_ENTRY_HAZARD, may cause a bug
#define EFFECT_WICKED_WINDS                 474 //According to EFFECT_FROSTBITE_HIT and EFFECT_FLYING_PRESS, this doesnt need any special AI code
#define EFFECT_SAND_TOMB                    475 //AI Flags complete
#define EFFECT_SONIC_BURST                  476 //AI Flags complete
#define EFFECT_SOUL_CUTTER                  477 //According to EFFECT_PSYSHOCK, this doesnt need any special AI code
#define EFFECT_VOID                         478 //AI Flags added, combined stuff from EFFECT_DISABLE and EFFECT_FEINT, may cause a bug
#define EFFECT_KERFUFFLE                    479 //AI Flags added, mostly took from EFFECT_EARTHQUAKE so the AI doesnt kill allies with it. Could add in another check weighing the confusion odds
#define EFFECT_VERGLASTROM                  480 //AI Flags added, combined stuff from EFFECT_TRAP and EFFECT_COLD_MEND, may cause a bug
#define EFFECT_EXORCISM                     481 //According to EFFECT_FREEZE_DRY, this doesnt need any special AI code
#define EFFECT_LOVE_TAP                     482 //AI Flags complete (added a conditional to EFFECT_FAKE_OUT code)
#define EFFECT_SOLAR_FLARE                  483 //According to EFFECT_BURN_HIT and EFFECT_FREEZE_DRY, this doesnt need any special AI code
#define EFFECT_PANIC_HIT                    484 //According to EFFECT_POISON_HIT et al, this doesnt need any special AI code, but may take the liberty to add it
#define EFFECT_BLOOMING_HIT                 485 //According to EFFECT_POISON_HIT et al, this doesnt need any special AI code, but may take the liberty to add it
#define EFFECT_EXPOSED_HIT                  486 //According to EFFECT_POISON_HIT et al, this doesnt need any special AI code, but may take the liberty to add it
#define EFFECT_TEARFUL_LOOK                 487 //AI Flags complete (replaced Noble Roar)
#define EFFECT_BLACK_BUFFET                 488 //AI Flags added, combined stuff from EFFECT_MULTI_HIT and EFFECT_ABSORB, may cause a bug
#define EFFECT_FINISH_OFF                   489 //According to EFFECT_BRINE, this doesnt need any special AI code
#define EFFECT_SEIZE_CHANCE                 490 //AI Flags added, combined stuff from EFFECT_SUCKER_PUNCH and EFFECT_ALWAYS_CRIT, may cause a bug
#define EFFECT_RAZING_SUN                   491 //AI Flags added, combined stuff from EFFECT_RECOIL_33 and EFFECT_FEINT, may cause a bug
#define EFFECT_TERRORIZE                    492 //AI Flags added, made unique code for IncreasePanicScore and its associated functions which was copied from Poison. Needs testing
#define EFFECT_BRUTALIZE                    493 //AI Flags complete
#define EFFECT_ROADBLOCK                    494 //AI Flags complete
#define EFFECT_DEFENSE_DOWN_HIT_2           495 //AI Flags complete
#define EFFECT_EARTH_SHATTER                496 //AI Flags added, new code related to checking if any Terrain is present. Needs testing (also applies to EFFECT_HIT_SET_REMOVE_TERRAIN)
#define EFFECT_PILGRIMAGE                   497 //Should not need special AI code as damage is calculated beforehand into AI move preferences
#define EFFECT_HEAVY_CANNON                 498 //AI Flags complete
#define EFFECT_GIANTS_SPEAR                 499 //AI Flags complete
#define EFFECT_REDLINE                      500 //AI Flags added, new code taken somewhat from EFFECT_CLEAR_SMOG
#define EFFECT_ZAPPER                       501 //AI Flags added, new code taken somewhat from EFFECT_REDLINE above
#define EFFECT_SKY_SPLITTER                 502 //AI Flags added, new code taken somewhat from EFFECT_EARTH_SHATTER above, but for Weather instead of Terrain
#define EFFECT_ALL_STATS_UP_2_HIT_FOE       503 //AI Flags added, tagged on to EFFECT_VITAL_THROW and put in a thing for HP_AWARE that discourages its use when foe is at high HP
#define EFFECT_TICK_TACK                    504 //AI Flags added, tagged on to EFFECT_ABSORB and put in a thing for HP_AWARE that encourages it if the foe is at high HP or the user is at low HP
#define EFFECT_DEEP_GAZE                    505 //AI Flags added, does not need as much as other STATUS1s so just added a general discouragement if the target is statused and encouragement at the start of battle or if the target is not statused
#define EFFECT_ENERVATOR                    506 //AI Flags complete
#define EFFECT_ERODE_FIELD                  507            //No idea how to code this one
#define EFFECT_HEAVY_CELL                   508 //AI Flags added, copied a bunch from EFFECT_COIL. No idea if AI will try and use it consecutively
#define EFFECT_CRITICAL_REPAIR              509 //AI Flags complete
#define EFFECT_REMODEL                      510            //No idea how to code this one
#define EFFECT_BARI_BARI_BEAM               511 //AI Flags added, used new function CalcBariBariBeamPower, may be some bugs, untested
#define EFFECT_BARI_BARI_BASH               512 //According to EFFECT_BRINE, this doesnt need any special AI code
#define EFFECT_SP_ATTACK_ACCURACY_UP        513 //AI Flags complete
#define EFFECT_SUN_BASK                     514 //AI Flags added, copied stuff from EFFECT_COSMIC_POWER and added a B_WEATHER_SUN check
#define EFFECT_HEARTHWARM                   515 //AI Flags complete
#define EFFECT_DUNE_SLICER                  516 //Should not need special AI code as damage is calculated beforehand into AI move preferences
#define EFFECT_POWER_DRAIN                  517 //Copied EFFECT_STRENGTH_SAP, feel like both could use a little more code but I'll leave for now
#define EFFECT_FLORESCENCE                  518 //AI Flags added, made unique code for ShouldBloomSelf and its associated functions which was copied from Poison. Needs testing
#define EFFECT_GRIPPING_NAIL                519 //AI Flags complete, did not feel need for Blooming conditional
#define EFFECT_SNAP_TRAP                    520 //AI Flags complete, did not feel need for Blooming conditional
#define EFFECT_SPEED_DOWN_HIT_2             521                 //lmao this is unused??
#define EFFECT_VIGOR_ROOT                   522 //AI Flags complete. HP_AWARE AI will almost always go for this when at low health.
#define EFFECT_SEED_BOMB                    523 //AI Flags added, Blooming conditional should be tested
#define EFFECT_PETAL_BLIZZARD               524 //No special AI code necessary
#define EFFECT_SPIRIT_AWAY                  525 //AI Flags complete
#define EFFECT_PHANTASM                     526 //AI Flags complete
#define EFFECT_SNAPBLOSSOM                  527 //AI Flags added, combined stuff from EFFECT_ABSORB and EFFECT_FLORESCENCE, may cause a bug
#define EFFECT_GRASS_CANNON                 528 //AI Flags added, Blooming conditional should be tested
#define EFFECT_SPECIAL_DEFENSE_UP_HIT       529 //According to EFFECT_DEFENSE_UP_HIT, this doesnt need any special AI code
#define EFFECT_DEF_SP_DEF_UP_HIT            530 //According to EFFECT_DEFENSE_UP_HIT, this doesnt need any special AI code
#define EFFECT_SAVAGE_WING                  531 //AI Flags complete
#define EFFECT_PLASMA_CUTTER                532 //According to EFFECT_BURN_HIT and EFFECT_FREEZE_DRY, this doesnt need any special AI code
#define EFFECT_BOUNDARY                     533 //Currently just has priority for risky AI. May add something else
#define EFFECT_PARTY_TRICK                  534 //AI Flags complete
#define EFFECT_DANCE_MANIA                  535 //Needs SETUP_FIRST_TURN to function currently
#define EFFECT_BEATBOX                      536 //Should not need special AI code as damage is calculated beforehand into AI move preferences
#define EFFECT_SPEED_UP_USER_ALLY           537 //AI Flags complete
#define EFFECT_IGNITION                     538 //AI Flags complete
#define EFFECT_FAIRY_WIND                   539            //Will come back to this one (have to add Minimizing logic)
#define EFFECT_FLORAL_HEALING               540 //AI Flags complete
#define EFFECT_SHARP_GLIDE                  541 //Should not need special AI code as damage is calculated beforehand into AI move preferences
#define EFFECT_CRASH_LAND                   542 //AI Flags complete
#define EFFECT_AIR_CANNON                   543 //AI Flags added, combined stuff from EFFECT_SOLAR_BEAM with a check for Tailwind timer, may cause a bug
#define EFFECT_FEATHER_DANCE                544 //AI Flags complete
#define EFFECT_BANSHRIEK                    545 //According to EFFECT_CONFUSE_HIT, this doesnt need any special AI code
#define EFFECT_VINE_WHIP                    546 //AI Flags added, Blooming conditional should be tested
#define EFFECT_TRAILBLAZE                   547 //AI Flags added, Blooming conditional should be tested
#define EFFECT_NEEDLE_ARM                   548 //AI Flags added, Blooming conditional should be tested
#define EFFECT_TROP_KICK                    549 //AI Flags added, Blooming conditional should be tested
#define EFFECT_DRUM_BEATING                 550 //AI Flags added, Blooming conditional should be tested
#define EFFECT_WOOD_HAMMER                  551 //AI Flags added, Blooming conditional should be tested
#define EFFECT_APPLE_ACID                   552 //AI Flags added, Blooming conditional should be tested
#define EFFECT_ENERGY_BALL                  553 //Does not need special AI code
#define EFFECT_PETAL_DANCE                  554 //According to EFFECT_RAMPAGE, this doesnt need any special AI code
#define EFFECT_SNOWFADE                     555 //AI Flags added, combined stuff from EFFECT_HIT_ESCAPE with a B_WEATHER_HAIL check, may cause a bug
#define EFFECT_FRENZY_PLANT                 556 //AI Flags complete
#define EFFECT_AROMATHERAPY                 557 //AI Flags added, Blooming conditional should be tested
#define EFFECT_GREEN_GUISE                  558 //AI Flags complete
#define EFFECT_FROST_SHRED                  559 //According to MOVE_DOUBLE_KICK, this doesnt need any special AI code
#define EFFECT_COTTON_SPORE                 560 //AI Flags added, Blooming conditional should be tested
#define EFFECT_SLEEP_POWDER                 561 //Copied EFFECT_SLEEP, didnt feel the need for Blooming conditional
#define EFFECT_PLUNDER                      562 //AI Flags added, combined stuff from EFFECT_THIEF and EFFECT_SPECTRAL_THIEF, may cause a bug
#define EFFECT_STUN_SPORE                   563 //AI Flags added, Blooming conditional should be tested
#define EFFECT_GOLD_PLAINS                  564            //Will come back to this one (Only used in boss battle)
#define EFFECT_DOWNFALL                     565            //Will come back to this one (Only used in boss battle)
#define EFFECT_MT_SPLENDOR                  566            //Will come back to this one (Only used in boss battle)
#define EFFECT_GATTLING_PINS                567 //Just added it to be preferred by AI_RISKY, damage calc should do the rest
#define EFFECT_CONSTRICT                    568 //Copied EFFECT_TRAP, but may need to add more sophisticated code
#define EFFECT_HYPER_DRILL                  569 //AI Flags added, combined stuff from EFFECT_FEINT and EFFECT_BRICK_BREAK, may cause a bug
#define EFFECT_RECHARGE_REDUCE              570 //AI Flags complete
#define EFFECT_PURIFICATION                 571 //AI Flags complete
#define EFFECT_MIND_READER                  572 //AI Flags complete
#define EFFECT_ODOR_SLEUTH                  573 //AI Flags complete
#define EFFECT_SURPRISE_EGG                 574 //AI Flags complete
#define EFFECT_BLOCK                        575 //AI Flags complete
#define EFFECT_CUTIE_CRY                    576 //AI Flags complete
#define EFFECT_FLEUR_CANNON                 577 //AI Flags added, Blooming conditional should be tested
#define EFFECT_UPPER_HAND                   578 //Should not need special AI code as damage is calculated beforehand into AI move preferences
#define EFFECT_WHIRLWIND                    579 //AI Flags added, combined stuff from EFFECT_ROAR with a Tailwind check, may cause a bug
#define EFFECT_GLACIAL_SHIFT                580 //AI Flags added, combined stuff from EFFECT_HIT_ESCAPE with a B_WEATHER_HAIL check, may cause a bug
#define EFFECT_FROST_NOVA                   581 //AI Flags complete
#define EFFECT_POISON_DART                  582 //AI Flags complete
#define EFFECT_SMOG                         583 //According to EFFECT_POISON_HIT, this doesnt need any special AI code
#define EFFECT_GUNK_FUNK                    584 //AI Flags complete
#define EFFECT_POISON_POWDER                585 //AI Flags added, Blooming conditional should be tested
#define EFFECT_GRAVITON_ARM                 586 //AI Flags added, 'tis a boss battle move so may return to make it a bit more complicated
#define EFFECT_MIST_BALL                    587 //AI Flags complete
#define EFFECT_KINESIS                      588 //AI Flags added, combined stuff from various stat changing effects with a PSYCHIC_TERRAIN check, may cause a bug
#define EFFECT_RESERVOIR                    589 //AI Flags added, combined stuff from EFFECT_RESTORE_HP and EFFECT_REFRESH, may cause a bug
#define EFFECT_CANNONADE                    590 //Damage calculation should mostly handle things, though AI_RISKY and HP_AWARE can be utilized to make them use it more often or less often at low health, respectively
#define EFFECT_BURNING_ENVY                 591 //AI Flags added, combined stuff from EFFECT_TOPSY_TURVY with a check for Burn, may cause a bug
#define EFFECT_ACID_ARMOR                   592 //AI Flags complete
#define EFFECT_POWER_SHIFT                  593            //No idea how to code this one
#define EFFECT_MAGIC_POWDER                 594 //AI Flags added, combined stuff from EFFECT_SOAK and EFFECT_YAWN, may cause a bug
#define EFFECT_PSY_SWAP                     595 //AI Flags complete
#define EFFECT_SHIELDS_UP                   596 //AI Flags complete
#define EFFECT_BERRY_BAD_JOKE               597 //AI Flags added, just copied EFFECT_HIT_SWITCH_TARGET, could maybe add more
#define EFFECT_STALAG_BLAST                 598 //AI Flags added, made new code based off EFFECT_BELLY_DRUM. If AI_RISKY and not HP_AWARE, will use recklessly
#define EFFECT_MOON_BEAM                    599 //AI Flags complete
#define EFFECT_HUNKER_DOWN                  600 //AI Flags added, copied stuff from EFFECT_GEOMANCY
#define EFFECT_POISON_GAS                   601            //Purple Haze thing. Waiting to code
#define EFFECT_HIGH_ROLL_HIT                602 //Just added to AI_RISKY, random damage moves are not particularly accounted for by the AI
#define EFFECT_SPINDA_SWING                 603 //AI Flags added, simple check on if the user is Confused or not
#define EFFECT_WILD_CHARGE                  604 //AI Flags complete
#define EFFECT_STORM_CHASE                  605 //According to EFFECT_PARALYZE_HIT, this doesnt need any special AI code
#define EFFECT_STORM_FURY                   606 //According to EFFECT_RAMPAGE, this doesnt need any special AI code
#define EFFECT_SUBMISSION                   607 //AI Flags added, combined stuff from EFFECT_RECOIL_25, EFFECT_SUCKER_PUNCH and EFFECT_QUASH, may cause a bug
#define EFFECT_DRAGON_CLAW                  608 //Just added to AI_RISKY, random damage moves are not particularly accounted for by the AI
#define EFFECT_CHEESE_STEAL                 609            //No idea how to code this one
#define EFFECT_LEAF_TORNADO                 610 //AI Flags added, Blooming conditional should be tested
#define EFFECT_AXEL_HEEL                    611 //AI Flags complete
#define EFFECT_MIND_BREAK                   612 //AI Flags added, checks for Panic or Confusion
#define EFFECT_HAYWIRE                      613 //Should not need special AI code as damage is calculated beforehand into AI move preferences
#define EFFECT_FLYING_PRESS                 614 //Copied EFFECT_RECOIL_25; should not need AI code for minimize damage
#define EFFECT_TRUE_LOVES_KISS              615 //Joke move, does not need special code
#define EFFECT_SABRE_BREAK                  616 //AI Flags added, combined stuff from EFFECT_FLINCH_HIT with a Frostbite/Freeze check, may cause a bug
#define EFFECT_SYRUP_BOMB                   617 //AI Flags added, simply took from EFFECT_SPEED_DOWN and adjusted scores. Could maybe do more
#define EFFECT_OCTAZOOKA                    618 //AI Flags complete

#define NUM_BATTLE_MOVE_EFFECTS             619

#endif  // GUARD_CONSTANTS_BATTLE_MOVE_EFFECTS_H
