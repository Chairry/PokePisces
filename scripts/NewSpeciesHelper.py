import os
import re

lastMonAdded = "Happea"
newMon = "Dudunspars"

with open("../include/constants/species.h", "r+") as speciesHeader:
    data = speciesHeader.readlines()
    newData = []
    
    for line in data:
        newLine = line.split()
        if "#define SPECIES_"+lastMonAdded.upper() in line:
            speciesNum = int(newLine[2]) + 1 
            line = line + "#define SPECIES_" + newMon.upper() + " " + str(speciesNum) + "\n"
            newData.append(line)
        elif "#define NEW_MONS_END" in line:
            line = "#define NEW_MONS_END (SPECIES_"+newMon.upper()+")\n"
            newData.append(line)
        elif "#define FORMS_START" in line:
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
        if "gMonFootprint_"+lastMonAdded in line:
            line = line + "extern const u32 gMonFrontPic_"+newMon+"[];\n"
            line = line + "extern const u32 gMonPalette_"+newMon+"[];\n"
            line = line + "extern const u32 gMonBackPic_"+newMon+"[];\n"
            line = line + "extern const u32 gMonShinyPalette_"+newMon+"[];\n"
            line = line + "extern const u8 gMonIcon_"+newMon+"[];\n"
            line = line + "extern const u8 gMonFootprint_"+newMon+"[];\n"
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
        if m := re.search(r"(\d{1,9})"+lastMonAdded.lower()+r"\/footprint.1bpp", line):
            fileNumber = int(m.group(1)) + 1
            line = line + "const u32 gMonFrontPic_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/front.4bpp.lz\");\n"
            line = line + "const u32 gMonPalette_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/normal.gbapal.lz\");\n"
            line = line + "const u32 gMonBackPic_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/back.4bpp.lz\");\n"
            line = line + "const u32 gMonShinyPalette_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/shiny.gbapal.lz\");\n"
            line = line + "const u8 gMonIcon_"+newMon+"[] = INCBIN_U8(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/icon.4bpp\");\n"
            line = line + "const u8 gMonFootprint_"+newMon+"[] = INCBIN_U8(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/footprint.1bpp\");\n"
            newData.append(line)
        else:
            newData.append(line)
    #seek and truncate to overwrite file's content
    pokemonHeader.seek(0)
    pokemonHeader.write("".join(newData))
    pokemonHeader.truncate()