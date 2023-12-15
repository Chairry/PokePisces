import os
import re

#First character capitalized, the rest should be lowercase
prevMon = "Snurrowl"
newMon = "Stolyce"
#Set to True to update all DEX_COUNT defines to newMon
#If False, use FixSpeciesNums.py to update species nums to correct values
newMonIsEndOfList = True
addToPokeDexH = True

with open("../include/constants/species.h", "r+") as speciesHeader:
    data = speciesHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "#define SPECIES_"+prevMon.upper() in line:
            speciesNum = int(newLine[2]) + 1 
            line += "#define SPECIES_" + newMon.upper() + " " + str(speciesNum) + "\n"
            newData.append(line)
        elif newMonIsEndOfList and "#define NEW_MONS_END" in line:
            line = "#define NEW_MONS_END (SPECIES_"+newMon.upper()+")\n"
            newData.append(line)
        elif newMonIsEndOfList and "#define FORMS_START" in line:
            line = "#define FORMS_START SPECIES_"+newMon.upper()+"\n"
            newData.append(line)
        else:
            newData.append(line)      
    #seek and truncate to overwrite file's content
    speciesHeader.seek(0)
    speciesHeader.write("".join(newData))
    speciesHeader.truncate()
    
with open("../include/graphics.h", "r+") as graphicsHeader:
    data = graphicsHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "gMonFootprint_"+prevMon in line:
            line += "extern const u32 gMonFrontPic_"+newMon+"[];\n"
            line += "extern const u32 gMonPalette_"+newMon+"[];\n"
            line += "extern const u32 gMonBackPic_"+newMon+"[];\n"
            line += "extern const u32 gMonShinyPalette_"+newMon+"[];\n"
            line += "extern const u8 gMonIcon_"+newMon+"[];\n"
            line += "extern const u8 gMonFootprint_"+newMon+"[];\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    graphicsHeader.seek(0)
    graphicsHeader.write("".join(newData))
    graphicsHeader.truncate()
    
with open("../src/data/graphics/pokemon.h", "r+") as pokemonHeader:
    data = pokemonHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if m := re.search(r"(\d{1,9})"+prevMon.lower()+r"\/footprint.1bpp", line):
            fileNumber = int(m.group(1)) + 1
            line += "const u32 gMonFrontPic_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/front.4bpp.lz\");\n"
            line += "const u32 gMonPalette_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/normal.gbapal.lz\");\n"
            line += "const u32 gMonBackPic_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/back.4bpp.lz\");\n"
            line += "const u32 gMonShinyPalette_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/shiny.gbapal.lz\");\n"
            line += "const u8 gMonIcon_"+newMon+"[] = INCBIN_U8(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/icon.4bpp\");\n"
            line += "const u8 gMonFootprint_"+newMon+"[] = INCBIN_U8(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/footprint.1bpp\");\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    pokemonHeader.seek(0)
    pokemonHeader.write("".join(newData))
    pokemonHeader.truncate()
    
with open("../src/data/pokemon_graphics/front_pic_anims.h", "r+") as frontPicAnimsHeader:
    data = frontPicAnimsHeader.readlines()
    newData = []
    lastMonAnimFound = False
    
    for line in data:
        newLine = line.split()
        if "static const union AnimCmd sAnim_"+prevMon in line:
            lastMonAnimFound = True
            newData.append(line)
        elif lastMonAnimFound and "};" in line:
            lastMonAnimFound = False
            line += "\n"
            line += "static const union AnimCmd sAnim_"+newMon+"_1[] =\n"
            line += "{\n"
            line += "    ANIMCMD_FRAME(0, 1),\n"
            line += "    ANIMCMD_END,\n"
            line += "};\n"
            newData.append(line)
        elif "SINGLE_ANIMATION("+prevMon+");" in line:
            line += "SINGLE_ANIMATION("+newMon+");\n"
            newData.append(line)
        elif "[SPECIES_"+prevMon.upper()+"] = sAnims_"+prevMon in line:
            line += "    [SPECIES_"+newMon.upper()+"] = sAnims_"+newMon+",\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    frontPicAnimsHeader.seek(0)
    frontPicAnimsHeader.write("".join(newData))
    frontPicAnimsHeader.truncate()
    
with open("../src/pokemon.c", "r+") as pokemonCFile:
    data = pokemonCFile.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "SPECIES_TO_HOENN("+prevMon.upper() in line:
            line += "    SPECIES_TO_HOENN("+newMon.upper()+"),\n"
            newData.append(line)
        elif "SPECIES_TO_NATIONAL("+prevMon.upper() in line:
            line += "    SPECIES_TO_NATIONAL("+newMon.upper()+"),\n"
            newData.append(line)
        elif "HOENN_TO_NATIONAL("+prevMon.upper() in line:
            line += "    HOENN_TO_NATIONAL("+newMon.upper()+"),\n"
            newData.append(line)
        elif  m := re.search(r"(\s+\[SPECIES_"+prevMon.upper()+r" - 1\]\s+)", line):
            speciesNameLength = len(m.group(1))
            line += ("    [SPECIES_"+newMon.upper()+" - 1]").ljust(speciesNameLength, ' ') + "= ANIM_V_SQUISH_AND_BOUNCE,\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    pokemonCFile.seek(0)
    pokemonCFile.write("".join(newData))
    pokemonCFile.truncate()
    
with open("../src/data/pokemon_graphics/front_pic_table.h", "r+") as fPicTableHeader:
    data = fPicTableHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "SPECIES_SPRITE("+prevMon.upper() in line:
            line += "    SPECIES_SPRITE("+newMon.upper()+", gMonFrontPic_"+newMon+"),\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    fPicTableHeader.seek(0)
    fPicTableHeader.write("".join(newData))
    fPicTableHeader.truncate()
    
with open("../src/data/pokemon_graphics/front_pic_coordinates.h", "r+") as fPicCoordsHeader:
    data = fPicCoordsHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if m := re.search(r"(\s+\[SPECIES_"+prevMon.upper()+r"\]\s+)", line):
            coordsNameLength = len(m.group(1))
            line += ("    [SPECIES_"+newMon.upper()+"]").ljust(coordsNameLength, ' ') + "= { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    fPicCoordsHeader.seek(0)
    fPicCoordsHeader.write("".join(newData))
    fPicCoordsHeader.truncate()    
    
with open("../src/data/pokemon_graphics/back_pic_table.h", "r+") as bPicTableHeader:
    data = bPicTableHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "SPECIES_SPRITE("+prevMon.upper() in line:
            line += "    SPECIES_SPRITE("+newMon.upper()+", gMonBackPic_"+newMon+"),\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    bPicTableHeader.seek(0)
    bPicTableHeader.write("".join(newData))
    bPicTableHeader.truncate()
    
with open("../src/data/pokemon_graphics/back_pic_coordinates.h", "r+") as bPicCoordsHeader:
    data = bPicCoordsHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if m := re.search(r"(\s+\[SPECIES_"+prevMon.upper()+r"\]\s+)", line):
            coordsNameLength = len(m.group(1))
            line += ("    [SPECIES_"+newMon.upper()+"]").ljust(coordsNameLength, ' ') + "= { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    bPicCoordsHeader.seek(0)
    bPicCoordsHeader.write("".join(newData))
    bPicCoordsHeader.truncate()
    
with open("../src/data/pokemon_graphics/footprint_table.h", "r+") as footPrintTableHeader:
    data = footPrintTableHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "[SPECIES_"+prevMon.upper() in line:
            line += "    [SPECIES_"+newMon.upper()+"] = gMonFootprint_"+newMon+",\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    footPrintTableHeader.seek(0)
    footPrintTableHeader.write("".join(newData))
    footPrintTableHeader.truncate()
    
with open("../src/data/pokemon_graphics/palette_table.h", "r+") as paletteTableHeader:
    data = paletteTableHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "SPECIES_PAL("+prevMon.upper() in line:
            line += "    SPECIES_PAL("+newMon.upper()+", gMonPalette_"+newMon+"),\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    paletteTableHeader.seek(0)
    paletteTableHeader.write("".join(newData))
    paletteTableHeader.truncate()
    
with open("../src/data/pokemon_graphics/shiny_palette_table.h", "r+") as shinyPaletteTableHeader:
    data = shinyPaletteTableHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "    SPECIES_SHINY_PAL("+prevMon.upper() in line:
            line += "    SPECIES_SHINY_PAL("+newMon.upper()+", gMonShinyPalette_"+newMon+"),\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    shinyPaletteTableHeader.seek(0)
    shinyPaletteTableHeader.write("".join(newData))
    shinyPaletteTableHeader.truncate()
    
with open("../src/pokemon_icon.c", "r+") as pokemonIconCFile:
    data = pokemonIconCFile.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "[SPECIES_"+prevMon.upper()+"] = gMonIcon_" in line:
            line += "    [SPECIES_"+newMon.upper()+"] = gMonIcon_"+newMon+",\n"
            newData.append(line)
        elif m := re.search(r"\[SPECIES_"+prevMon.upper()+r"\] = \d", line): #use regex to prevent matching previous set
            line += "    [SPECIES_"+newMon.upper()+"] = 0,\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    pokemonIconCFile.seek(0)
    pokemonIconCFile.write("".join(newData))
    pokemonIconCFile.truncate()
    
with open("../src/data/text/species_names.h", "r+") as speciesNamesHeader:
    data = speciesNamesHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "[SPECIES_"+prevMon.upper() in line:
            line += "    [SPECIES_"+newMon.upper()+"] = _(\""+newMon+"\"),\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    speciesNamesHeader.seek(0)
    speciesNamesHeader.write("".join(newData))
    speciesNamesHeader.truncate()

if addToPokeDexH:
    with open("../include/constants/pokedex.h", "r+") as pokedexHeader:
        data = pokedexHeader.readlines()
        newData = []
        inNationalDexEntries = False
        inHoennDexEntries = False
        nationalDexLocationFound = False
        hoennDexLocationFound = False
        nationalDexEndFound = False
        hoennDexEndFound = False
    
        for line in data:
            newLine = line.split()
            if "NATIONAL_DEX_" in line and "NATIONAL_DEX_COUNT" not in line and "NATIONAL_DEX_"+prevMon.upper() not in line and not inNationalDexEntries:
                inNationalDexEntries = True
                newData.append(line)
            elif "NATIONAL_DEX_"+prevMon.upper() in line:
                nationalDexLocationFound = True
                line += "    NATIONAL_DEX_"+newMon.upper()+",\n"
                newData.append(line)
            #Reached the end of the national dex entries, but never found prevMon entry
            elif inNationalDexEntries and not nationalDexLocationFound and "};" in line:
                nationalDexEndFound = True
                nationalDexLocationFound = True
                line = "    NATIONAL_DEX_"+newMon.upper()+",\n"
                line += "};\n"
                newData.append(line)
            elif "#define NATIONAL_DEX_COUNT  NATIONAL_DEX_"+prevMon.upper() in line:
                line = "    #define NATIONAL_DEX_COUNT  NATIONAL_DEX_"+newMon.upper()+"\n"
                newData.append(line)
            elif nationalDexEndFound and "NATIONAL_DEX_COUNT" in line:
                nationalDexEndFound = False
                line = "    #define NATIONAL_DEX_COUNT  NATIONAL_DEX_"+newMon.upper()+"\n"
                newData.append(line)
            elif "HOENN_DEX_" in line and "HOENN_DEX_COUNT" not in line and "HOENN_DEX_"+prevMon.upper() not in line and not inHoennDexEntries:
                inNationalDexEntries = False
                inHoennDexEntries = True
                newData.append(line)
            elif "HOENN_DEX_"+prevMon.upper() in line:
                hoennDexLocationFound = True
                line += "    HOENN_DEX_"+newMon.upper()+",\n"
                newData.append(line)
            #Reached the end of the hoenn dex entries, but never found prevMon entry
            elif inHoennDexEntries and not hoennDexLocationFound and "};" in line:
                hoennDexEndFound = True
                hoennDexLocationFound = True
                line = "    HOENN_DEX_"+newMon.upper()+",\n"
                line += "};\n"
                newData.append(line)
            elif "#define HOENN_DEX_COUNT  HOENN_DEX_"+prevMon.upper() in line:
                line = "    #define HOENN_DEX_COUNT  (HOENN_DEX_"+newMon.upper()+" + 1)\n"
                newData.append(line)
            elif hoennDexEndFound and "HOENN_DEX_COUNT" in line:
                hoennDexEndFound = False
                line = "    #define HOENN_DEX_COUNT (HOENN_DEX_"+newMon.upper()+" + 1)\n"
                newData.append(line)
            else:
                newData.append(line)
        #seek and truncate to overwrite file's content
        pokedexHeader.seek(0)
        pokedexHeader.write("".join(newData))
        pokedexHeader.truncate()
    
with open("../src/data/pokemon/pokedex_text.h", "r+", encoding="utf8") as pokedexTextHeader:
    data = pokedexTextHeader.readlines()
    newData = []
    matchFound = False
    
    for line in data:
        newLine = line.split()
        if "const u8 g"+prevMon in line:
            matchFound = True
            newData.append(line)
        elif matchFound and "\");" in line:
            matchFound = False
            line += "\n"
            line += "const u8 g"+newMon+"PokedexText[] = _(\n"
            line += "    \"\\n\"\n"
            line += "    \"\\n\"\n"
            line += "    \"\\n\"\n"
            line += "    \"\");\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    pokedexTextHeader.seek(0)
    pokedexTextHeader.write("".join(newData))
    pokedexTextHeader.truncate()
    
with open("../src/data/pokemon/pokedex_entries.h", "r+") as pokedexEntriesHeader:
    data = pokedexEntriesHeader.readlines()
    newData = []
    matchFound = False
    
    for line in data:
        newLine = line.split()
        if "[NATIONAL_DEX_"+prevMon.upper() in line:
            matchFound = True
            newData.append(line)
        elif matchFound and "}," in line:
            matchFound = False
            line += "\n"
            line += "    [NATIONAL_DEX_"+newMon.upper()+"] =\n"
            line += "    {\n"
            line += "        .categoryName = _(\"REPLACE ME\"),\n"
            line += "        .height = 999,\n"
            line += "        .weight = 999,\n"
            line += "        .description = g"+newMon+"PokedexText,\n"
            line += "        .pokemonScale = 999,\n"
            line += "        .pokemonOffset = 0,\n"
            line += "        .trainerScale = 256,\n"
            line += "        .trainerOffset = 0,\n"
            line += "    },\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    pokedexEntriesHeader.seek(0)
    pokedexEntriesHeader.write("".join(newData))
    pokedexEntriesHeader.truncate()
    
with open("../src/data/pokemon/species_info.h", "r+") as speciesInfoHeader:
    data = speciesInfoHeader.readlines()
    newData = []
    matchFound = False
    
    for line in data:
        newLine = line.split()
        if "[SPECIES_"+prevMon.upper() in line:
            matchFound = True
            newData.append(line)
        elif matchFound and "    }," in line:
            matchFound = False
            line += "\n"
            line += "    [SPECIES_"+newMon.upper()+"] =\n"
            line += "    {\n"
            line += "        .baseHP        = 10,\n"
            line += "        .baseAttack    = 10,\n"
            line += "        .baseDefense   = 10,\n"
            line += "        .baseSpeed     = 10,\n"
            line += "        .baseSpAttack  = 10,\n"
            line += "        .baseSpDefense = 10,\n"
            line += "        .types = { TYPE_NORMAL, TYPE_NORMAL },\n"
            line += "        .catchRate = 100,\n"
            line += "        .expYield = 100,\n"
            line += "        .evYield_SpDefense = 2,\n"
            line += "        .genderRatio = PERCENT_FEMALE(50),\n"
            line += "        .eggCycles = 100,\n"
            line += "        .friendship = STANDARD_FRIENDSHIP,\n"
            line += "        .growthRate = GROWTH_MEDIUM_SLOW,\n"
            line += "        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS},\n"
            line += "        .abilities = {ABILITY_NONE},\n"
            line += "        .bodyColor = BODY_COLOR_BLACK,\n"
            line += "        .noFlip = FALSE,\n"
            line += "    },\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    speciesInfoHeader.seek(0)
    speciesInfoHeader.write("".join(newData))
    speciesInfoHeader.truncate()
    
with open("../src/data/pokemon/level_up_learnsets.h", "r+") as levelUpLearnsetsHeader:
    data = levelUpLearnsetsHeader.readlines()
    newData = []
    matchFound = False
    
    for line in data:
        newLine = line.split()
        if "LevelUpMove s"+prevMon in line:
            matchFound = True
            newData.append(line)
        elif matchFound and "};" in line:
            matchFound = False
            line += "\n"
            line += "static const struct LevelUpMove s"+newMon+"LevelUpLearnset[] = {\n"
            line += "    LEVEL_UP_MOVE(1, MOVE_HIDDEN_POWER),\n"
            line += "    LEVEL_UP_END\n"
            line += "};\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    levelUpLearnsetsHeader.seek(0)
    levelUpLearnsetsHeader.write("".join(newData))
    levelUpLearnsetsHeader.truncate()
    
with open("../src/data/pokemon/level_up_learnset_pointers.h", "r+") as levelUpLearnsetsPHeader:
    data = levelUpLearnsetsPHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "[SPECIES_"+prevMon.upper() in line:
            line += "    [SPECIES_"+newMon.upper()+"] = s"+newMon+"LevelUpLearnset,\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    levelUpLearnsetsPHeader.seek(0)
    levelUpLearnsetsPHeader.write("".join(newData))
    levelUpLearnsetsPHeader.truncate()
    
with open("../src/data/pokemon/teachable_learnsets.h", "r+") as teachableLearnsetsHeader:
    data = teachableLearnsetsHeader.readlines()
    newData = []
    matchFound = False
    
    for line in data:
        newLine = line.split()
        if "u16 s"+prevMon in line:
            matchFound = True
            newData.append(line)
        elif matchFound and "};" in line:
            matchFound = False
            line += "\n"
            line += "static const u16 s"+newMon+"TeachableLearnset[] = {\n"
            line += "    MOVE_UNAVAILABLE,\n"
            line += "};\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    teachableLearnsetsHeader.seek(0)
    teachableLearnsetsHeader.write("".join(newData))
    teachableLearnsetsHeader.truncate()
    
with open("../src/data/pokemon/teachable_learnset_pointers.h", "r+") as teachableLearnsetsPHeader:
    data = teachableLearnsetsPHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "    [SPECIES_"+prevMon.upper() in line:
            line += "    [SPECIES_"+newMon.upper()+"] = s"+newMon+"TeachableLearnset,\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    teachableLearnsetsPHeader.seek(0)
    teachableLearnsetsPHeader.write("".join(newData))
    teachableLearnsetsPHeader.truncate()
    
with open("../sound/direct_sound_data.inc", "r+") as directSoundDataInc:
    data = directSoundDataInc.readlines()
    newData = []
    matchFound = False
    lineAfterMatch = False
    endIfFound = False
    
    for line in data:
        newLine = line.split()
        if "Cry_"+prevMon in line:
            matchFound = True
            newData.append(line)
        elif matchFound:
            lineAfterMatch = True
            matchFound = False
            newData.append(line)
        elif lineAfterMatch:
            lineAfterMatch = False
            if "endif" in line:
                endIfFound = True
            line = "\n"
            line += "	.align 2\n"
            line += "Cry_"+newMon+"::\n"
            line += "	.incbin \"sound/direct_sound_samples/cries/bulbasaur.bin\"\n"
            if endIfFound:
                line += ".endif\n"
            else:
                line += "\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    directSoundDataInc.seek(0)
    directSoundDataInc.write("".join(newData))
    directSoundDataInc.truncate()     
    
with open("../sound/cry_tables.inc", "r+") as cryTablesInc:
    data = cryTablesInc.readlines()
    newData = []
    matchFound = False
    
    for line in data:
        newLine = line.split()
        if "cry Cry_"+prevMon in line:
            line += "	cry Cry_"+newMon+"\n"
            newData.append(line)
        elif "cry_reverse Cry_"+prevMon in line:
            line += "	cry_reverse Cry_"+newMon+"\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    cryTablesInc.seek(0)
    cryTablesInc.write("".join(newData))
    cryTablesInc.truncate()

print("")
print("To do after helper is finished:")
print("-enemy_mon_elevation: Add elevation (if necessary)")
print("-front_pic_coordinates.h: Update with desired size and y_offset")
print("-back_pic_coordinates.h: Update with desired size and y_offset")
print("-pokemon_icon.c: Update Icon Palette Index")
print("-pokedex_text.h: Add Pokedex Text")
print("-pokedex_entries.h: Update Pokedex Info")
print("-species_info.h: Update Pokemon Stats")
print("-level_up_learnsets.h: Add Moves")
print("-teachable_learnsets.h: Add Teachable Moves (if any)")
print("-direct_sound_data.h: Update Cry data")
print("-evolution.h: Add Evolutions (if any)")
print("-\\graphics\\pokemon: Add directory with sprites + palettes")
