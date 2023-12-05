import os
import re

lastMonAdded = "Happea"
newMon = "Dudunspars"

# with open("../include/constants/species.h", "r+") as speciesHeader:
#     data = speciesHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "#define SPECIES_"+lastMonAdded.upper() in line:
#             speciesNum = int(newLine[2]) + 1 
#             line += "#define SPECIES_" + newMon.upper() + " " + str(speciesNum) + "\n"
#             newData.append(line)
#         elif "#define NEW_MONS_END" in line:
#             line = "#define NEW_MONS_END (SPECIES_"+newMon.upper()+")\n"
#             newData.append(line)
#         elif "#define FORMS_START" in line:
#             line = "#define FORMS_START SPECIES_"+newMon.upper()+"\n"
#             newData.append(line)
#         else:
#             newData.append(line)      
#     #seek and truncate to overwrite file's content
#     speciesHeader.seek(0)
#     speciesHeader.write("".join(newData))
#     speciesHeader.truncate()
    
# with open("../include/graphics.h", "r+") as graphicsHeader:
#     data = graphicsHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "gMonFootprint_"+lastMonAdded in line:
#             line += "extern const u32 gMonFrontPic_"+newMon+"[];\n"
#             line += "extern const u32 gMonPalette_"+newMon+"[];\n"
#             line += "extern const u32 gMonBackPic_"+newMon+"[];\n"
#             line += "extern const u32 gMonShinyPalette_"+newMon+"[];\n"
#             line += "extern const u8 gMonIcon_"+newMon+"[];\n"
#             line += "extern const u8 gMonFootprint_"+newMon+"[];\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     graphicsHeader.seek(0)
#     graphicsHeader.write("".join(newData))
#     graphicsHeader.truncate()
    
# with open("../src/data/graphics/pokemon.h", "r+") as pokemonHeader:
#     data = pokemonHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if m := re.search(r"(\d{1,9})"+lastMonAdded.lower()+r"\/footprint.1bpp", line):
#             fileNumber = int(m.group(1)) + 1
#             line += "const u32 gMonFrontPic_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/front.4bpp.lz\");\n"
#             line += "const u32 gMonPalette_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/normal.gbapal.lz\");\n"
#             line += "const u32 gMonBackPic_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/back.4bpp.lz\");\n"
#             line += "const u32 gMonShinyPalette_"+newMon+"[] = INCBIN_U32(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/shiny.gbapal.lz\");\n"
#             line += "const u8 gMonIcon_"+newMon+"[] = INCBIN_U8(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/icon.4bpp\");\n"
#             line += "const u8 gMonFootprint_"+newMon+"[] = INCBIN_U8(\"graphics/pokemon/" + str(fileNumber) + newMon.lower() + "/footprint.1bpp\");\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     pokemonHeader.seek(0)
#     pokemonHeader.write("".join(newData))
#     pokemonHeader.truncate()
    
# with open("../src/data/pokemon_graphics/front_pic_anims.h", "r+") as frontPicAnimsHeader:
#     data = frontPicAnimsHeader.readlines()
#     newData = []
#     lastMonAnimFound = False
    
#     for line in data:
#         newLine = line.split()
#         if "static const union AnimCmd sAnim_"+lastMonAdded in line:
#             lastMonAnimFound = True
#             newData.append(line)
#         elif lastMonAnimFound and "};" in line:
#             lastMonAnimFound = False
#             line += "\n"
#             line += "static const union AnimCmd sAnim_"+newMon+"_1[] =\n"
#             line += "{\n"
#             line += "    ANIMCMD_FRAME(0, 1),\n"
#             line += "    ANIMCMD_END,\n"
#             line += "};\n"
#             newData.append(line)
#         elif "SINGLE_ANIMATION("+lastMonAdded+");" in line:
#             line += "SINGLE_ANIMATION("+newMon+");\n"
#             newData.append(line)
#         elif "[SPECIES_"+lastMonAdded.upper()+"] = sAnims_"+lastMonAdded in line:
#             line += "    [SPECIES_"+newMon.upper()+"] = sAnims_"+newMon+",\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     frontPicAnimsHeader.seek(0)
#     frontPicAnimsHeader.write("".join(newData))
#     frontPicAnimsHeader.truncate()
    
# with open("../src/pokemon.c", "r+") as pokemonCFile:
#     data = pokemonCFile.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "SPECIES_TO_HOENN("+lastMonAdded.upper() in line:
#             line += "    SPECIES_TO_HOENN("+newMon.upper()+"),\n"
#             newData.append(line)
#         elif "SPECIES_TO_NATIONAL("+lastMonAdded.upper() in line:
#             line += "    SPECIES_TO_NATIONAL("+newMon.upper()+"),\n"
#             newData.append(line)
#         elif "HOENN_TO_NATIONAL("+lastMonAdded.upper() in line:
#             line += "    HOENN_TO_NATIONAL("+newMon.upper()+"),\n"
#             newData.append(line)
#         elif  m := re.search(r"(\s+\[SPECIES_"+lastMonAdded.upper()+r" - 1\]\s+)", line):
#             speciesNameLength = len(m.group(1))
#             line += ("    [SPECIES_"+newMon.upper()+" - 1]").ljust(speciesNameLength, ' ') + "= ANIM_V_SQUISH_AND_BOUNCE,\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     pokemonCFile.seek(0)
#     pokemonCFile.write("".join(newData))
#     pokemonCFile.truncate()
    
# with open("../src/data/pokemon_graphics/front_pic_table.h", "r+") as fPicTableHeader:
#     data = fPicTableHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "SPECIES_SPRITE("+lastMonAdded.upper() in line:
#             line += "    SPECIES_SPRITE("+newMon.upper()+", gMonFrontPic_"+newMon+"),\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     fPicTableHeader.seek(0)
#     fPicTableHeader.write("".join(newData))
#     fPicTableHeader.truncate()
    
# with open("../src/data/pokemon_graphics/front_pic_coordinates.h", "r+") as fPicCoordsHeader:
#     data = fPicCoordsHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if m := re.search(r"(\s+\[SPECIES_"+lastMonAdded.upper()+r"\]\s+)", line):
#             coordsNameLength = len(m.group(1))
#             line += ("    [SPECIES_"+newMon.upper()+"]").ljust(coordsNameLength, ' ') + "= { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     fPicCoordsHeader.seek(0)
#     fPicCoordsHeader.write("".join(newData))
#     fPicCoordsHeader.truncate()    
    
# with open("../src/data/pokemon_graphics/back_pic_table.h", "r+") as bPicTableHeader:
#     data = bPicTableHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "SPECIES_SPRITE("+lastMonAdded.upper() in line:
#             line += "    SPECIES_SPRITE("+newMon.upper()+", gMonBackPic_"+newMon+"),\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     bPicTableHeader.seek(0)
#     bPicTableHeader.write("".join(newData))
#     bPicTableHeader.truncate()
    
# with open("../src/data/pokemon_graphics/back_pic_coordinates.h", "r+") as bPicCoordsHeader:
#     data = bPicCoordsHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if m := re.search(r"(\s+\[SPECIES_"+lastMonAdded.upper()+r"\]\s+)", line):
#             coordsNameLength = len(m.group(1))
#             line += ("    [SPECIES_"+newMon.upper()+"]").ljust(coordsNameLength, ' ') + "= { .size = MON_COORDS_SIZE(64, 64), .y_offset =  0 },\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     bPicCoordsHeader.seek(0)
#     bPicCoordsHeader.write("".join(newData))
#     bPicCoordsHeader.truncate()
    
# with open("../src/data/pokemon_graphics/footprint_table.h", "r+") as footPrintTableHeader:
#     data = footPrintTableHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "[SPECIES_"+lastMonAdded.upper() in line:
#             line += "    [SPECIES_"+newMon.upper()+"] = gMonFootprint_"+newMon.upper()+",\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     footPrintTableHeader.seek(0)
#     footPrintTableHeader.write("".join(newData))
#     footPrintTableHeader.truncate()
    
# with open("../src/data/pokemon_graphics/palette_table.h", "r+") as paletteTableHeader:
#     data = paletteTableHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "SPECIES_PAL("+lastMonAdded.upper() in line:
#             line += "    SPECIES_PAL("+newMon.upper()+", gMonPalette_"+newMon+"),\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     paletteTableHeader.seek(0)
#     paletteTableHeader.write("".join(newData))
#     paletteTableHeader.truncate()
    
# with open("../src/data/pokemon_graphics/shiny_palette_table.h", "r+") as shinyPaletteTableHeader:
#     data = shinyPaletteTableHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "    SPECIES_SHINY_PAL("+lastMonAdded.upper() in line:
#             line += "    SPECIES_SHINY_PAL("+newMon.upper()+", gMonShinyPalette_"+newMon+"),\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     shinyPaletteTableHeader.seek(0)
#     shinyPaletteTableHeader.write("".join(newData))
#     shinyPaletteTableHeader.truncate()
    
# with open("../src/pokemon_icon.c", "r+") as pokemonIconCFile:
#     data = pokemonIconCFile.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "[SPECIES_"+lastMonAdded.upper()+"] = gMonIcon_" in line:
#             line += "    [SPECIES_"+newMon.upper()+"] = gMonIcon_"+newMon.upper()+",\n"
#             newData.append(line)
#         elif m := re.search(r"\[SPECIES_"+lastMonAdded.upper()+r"\] = \d", line): #use regex to prevent matching previous set
#             line += "    [SPECIES_"+newMon.upper()+"] = 0,\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     pokemonIconCFile.seek(0)
#     pokemonIconCFile.write("".join(newData))
#     pokemonIconCFile.truncate()
    
# with open("../src/data/text/species_names.h", "r+") as speciesNamesHeader:
#     data = speciesNamesHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "[SPECIES_"+lastMonAdded.upper() in line:
#             line += "    [SPECIES_"+newMon.upper()+"] = _(\""+newMon+"\"),\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     speciesNamesHeader.seek(0)
#     speciesNamesHeader.write("".join(newData))
#     speciesNamesHeader.truncate()
    
# with open("../include/constants/pokedex.h", "r+") as pokedexHeader:
#     data = pokedexHeader.readlines()
#     newData = []
    
#     for line in data:
#         newLine = line.split()
#         if "    NATIONAL_DEX_"+lastMonAdded.upper() in line:
#             line += "    NATIONAL_DEX_"+newMon.upper()+",\n"
#             newData.append(line)
#         elif "#define NATIONAL_DEX_COUNT  NATIONAL_DEX_"+lastMonAdded.upper() in line:
#             line = "    #define NATIONAL_DEX_COUNT  NATIONAL_DEX_"+newMon.upper()+"\n"
#             newData.append(line)
#         elif "HOENN_DEX_"+lastMonAdded.upper()+"," in line:
#             line += "    HOENN_DEX_"+newMon.upper()+",\n"
#             newData.append(line)
#         elif "#define HOENN_DEX_COUNT" in line:
#             line = "#define HOENN_DEX_COUNT (HOENN_DEX_"+newMon.upper()+" + 1)\n"
#             newData.append(line)
#         else:
#             newData.append(line)
#     #seek and truncate to overwrite file's content
#     pokedexHeader.seek(0)
#     pokedexHeader.write("".join(newData))
#     pokedexHeader.truncate()
    
with open("../src/data/pokemon/pokedex_text.h", "r+", encoding="utf8") as pokedexTextHeader:
    data = pokedexTextHeader.readlines()
    newData = []
    matchFound = False
    
    for line in data:
        newLine = line.split()
        if "const u8 g"+lastMonAdded in line:
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
    
