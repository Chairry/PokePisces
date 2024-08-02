import os
import re
import math
import pandas
import shutil

class Move:
    name = ""
    condition = ""
    
def parse_move_name(moveName, commentList, renameDict):
    parsedMoveName = ""
    if moveName in commentList:
        parsedMoveName += "//"
    parsedMoveName += "MOVE"
    splitName = moveName.split()
    for word in splitName:
        parsedMoveName += "_" + word.upper()
        
    if parsedMoveName in renameDict:
        parsedMoveName = renameDict[parsedMoveName]
        
    return parsedMoveName

url = f''
with open("moves_path.txt", "r") as speciesHeader:
    data = speciesHeader.readlines()
    url = data[0]
    

sheetData = pandas.read_csv(url, dtype=str)

columnNames = [];
    
for series_name, series in sheetData.items():
    columnNames.append(series_name)

skipList = ["Spinda", "Ashlands", "Forest", "Plains", "Desert", "Cave", "Mountain"] #Spinda is a little more special than is worth scripting for; manually handle this one
currentNames = []
clearCurrentNames = False
moveSetsDict = {}
moveConditionSetsDict = {}

for name in columnNames:
    if name in skipList:
        continue

    if not name.startswith("Unnamed") and name != " ":
        moveConditionSetsDict[name] = []
        moveSetsDict[name] = []
        currentNames.append(name)
    
    #Some mons moves begin partway down and end before row 30. i is used to match the condition to the moveset, 
    #regardless of the number/location in the sheet.
    i = -1
    for sheetIndex in sheetData.iloc[31:43,].index:

        #We found the column with the egg moves if this is true
        if name.startswith("Unnamed") and isinstance(sheetData[name][sheetIndex], str): #blank values are read as NaN, which is not a string
            i += 1
            clearCurrentNames = True
            for currentName in currentNames:
                move = Move()
                move.condition = moveConditionSetsDict[currentName][i]
                move.name = sheetData[name][sheetIndex].replace("^", "").replace("-", "_").replace("'", "")

                moveSetsDict[currentName].append(move)
            
            
        elif isinstance(sheetData[name][sheetIndex], str) and sheetData[name][sheetIndex] != "": # math.isnan(sheetData[name][sheetIndex])
            moveConditionSetsDict[name].append(sheetData[name][sheetIndex])   
    if clearCurrentNames:     
        clearCurrentNames = False
        currentNames = [] #clear out currentNames after adding moves
        
# If encountered will be commented out since these are not implemented yet
commentList = ["MOVE_SWEET_WHISPERS","MOVE_BLOOD_MOON", "MOVE_SYRUP_BOMB"]

renameDict = {"MOVE_STEAM_BURST":"MOVE_STEAM_ERUPTION", "MOVE_SCALE_CLANG":"MOVE_CLANGING_SCALES", "MOVE_CHILL_WATER":"MOVE_CHILLING_WATER", "MOVE_SIDEARM":"MOVE_SHELL_SIDE_ARM", "MOVE_OVERCHARGE":"MOVE_DOUBLE_SHOCK", "MOVE_SPRING_BREEZE":"MOVE_SPRINGTIDE_STORM", "MOVE_ION_WIND":"MOVE_WILDBOLT_STORM", "MOVE_STAR_ASSAULT":"MOVE_METEOR_ASSAULT", "MOVE_POWER_FLIP":"MOVE_TOPSY_TURVY", "MOVE_SKYPIERCER":"MOVE_DRAGON_ASCENT", "MOVE_THUNDER_KICK":"MOVE_THUNDEROUS_KICK", "MOVE_DUST_DEVIL":"MOVE_SANDSEAR_STORM", "MOVE_THE_13_TOLLS":"MOVE_SILENCE", "MOVE_MIXTAPE":"MOVE_CLANGOROUS_SOUL", "MOVE_CLIFF_BLADES":"MOVE_PRECIPICE_BLADES", "MOVE_NATURES_FURY":"MOVE_NATURES_MADNESS", "MOVE_SPACE_FURY":"MOVE_HYPERSPACE_FURY", "MOVE_FERVID_DANCE":"MOVE_REVELATION_DANCE", "MOVE_MASS_DESTRUCT":"MOVE_MASS_DESTRUCTION", "MOVE_FREEZE_GLARE":"MOVE_FREEZING_GLARE", "MOVE_PHANTOM_THIEF":"MOVE_SPECTRAL_THIEF", "MOVE_DOUBLE_BASH":"MOVE_DOUBLE_IRON_BASH", "MOVE_SEA_JAWS":"MOVE_FISHIOUS_REND", "MOVE_RUINA_LIGHT":"MOVE_LIGHT_OF_RUIN", "MOVE_CORROSIVE_CHAIN":"MOVE_MALIGNANT_CHAIN", "MOVE_SEARING_SANDS":"MOVE_SCORCHING_SANDS", "MOVE_PSYCHE_CRASH":"MOVE_LUMINA_CRASH", "MOVE_HORSE_POWER":"MOVE_HIGH_HORSEPOWER", "MOVE_DRACO_CRY":"MOVE_DRAGON_CHEER", "MOVE_BANE_BUNKER":"MOVE_BANEFUL_BUNKER", "MOVE_DRACO_HAMMER":"MOVE_DRAGON_HAMMER", "MOVE_BURNING_ENVY":"MOVE_BURNING_JEALOUSY", "MOVE_PHOTON_FLARE":"MOVE_PHOTON_GEYSER", "MOVE_DOOM_WING":"MOVE_OBLIVION_WING", "MOVE_THUNDERPUNCH":"MOVE_THUNDER_PUNCH", "MOVE_METEOR_STRIKE":"MOVE_SUNSTEEL_STRIKE", "MOVE_DRAIN_KISS":"MOVE_DRAINING_KISS", "MOVE_ECLIPSE_RAY":"MOVE_MOONGEIST_BEAM", "MOVE_SPACE_HOLE":"MOVE_HYPERSPACE_HOLE", "MOVE_HYDRA_BEAM":"MOVE_FICKLE_BEAM", "MOVE_SHELLTER":"MOVE_SHELTER", "MOVE_JUMP_&_POP":"MOVE_JUMP_N_POP", "MOVE_DRACO_ENERGY":"MOVE_DRAGON_ENERGY", "MOVE_TIDAL_CRASH":"MOVE_WAVE_CRASH", "MOVE_PETAL_FLURRY":"MOVE_PETAL_BLIZZARD", "MOVE_RED_GUARD":"MOVE_BURNING_BULWARK", "MOVE_CUTIE_CRY":"MOVE_DISARMING_VOICE", "MOVE_LEAFNADO":"MOVE_LEAF_TORNADO", "MOVE_ANGER_STOMPS":"MOVE_STOMPING_TANTRUM", "MOVE_PSYCHOLARM":"MOVE_PSYCHIC_NOISE", "MOVE_DINE_&_DASH":"MOVE_DINE_N_DASH", "MOVE_LOCKJAW":"MOVE_JAW_LOCK", "MOVE_DARK_LARIAT":"MOVE_DARKEST_LARIAT", "MOVE_BULL_RUSH":"MOVE_HEADLONG_RUSH","MOVE_BARRIER_BASH":"MOVE_PSYSHIELD_BASH","MOVE_DAZZLE_GLEAM":"MOVE_DAZZLING_GLEAM", "MOVE_PHASE_FORCE":"MOVE_PHANTOM_FORCE", "MOVE_EXPAND_FORCE":"MOVE_EXPANDING_FORCE", "MOVE_SOUL_SHACKLE": "MOVE_SPIRIT_SHACKLE", "MOVE_NIGHT_PARADE":"MOVE_INFERNAL_PARADE", "MOVE_BREAK_SWIPE":"MOVE_BREAKING_SWIPE", "MOVE_DRAGONBREATH":"MOVE_DRAGON_BREATH", "MOVE_DOUBLE_WING":"MOVE_DUAL_WINGBEAT", "MOVE_HIT_&_RUN":"MOVE_HIT_N_RUN", "MOVE_NORTH_WIND":"MOVE_BLEAKWIND_STORM","MOVE_FLAME_LASH":"MOVE_FIRE_LASH","MOVE_FLORESCENCE":"MOVE_JUNGLE_HEALING","MOVE_PARACHARGE":"MOVE_PARABOLIC_CHARGE","MOVE_HIGH_VOLTAGE":"MOVE_RISING_VOLTAGE","MOVE_FLOWING_ARIA":"MOVE_SPARKLING_ARIA"}

for name, moveSet in moveSetsDict.items():   
    availableEggMoves = False
    movesFound = False
    for move in moveSet:
        if move.condition == "✓":
            availableEggMoves = True
            continue
            
    if not availableEggMoves:
        continue
    name = name.replace("'", "").replace("-", "")
    #under the hood the species names for these differ from the actual in game name, and need to be changed to match that.
    if name == "Growlid":
        name = "Growlithe"
    if name == "Arcanite":
        name = "Arcanine"
    with open("../src/data/pokemon/egg_moves.h", "r+") as eggMovesHeader:
                data = eggMovesHeader.readlines()
                newData = []
                deleteFollowingLines = False
                
                for line in data:
                    newLine = line.split()
                    if "("+name.upper()+"," in line:
                        movesFound = True
                        for move in moveSet:
                            if move.condition == "X" or move.condition == "x":
                                continue
                            if ("\u2606" in move.name):
                                move.name = move.name.replace("\u2606", "_") #I'm looking at you Bari☆Bari☆Beam☆
                                move.name = move.name[:-1] #Remove final _ from the Bari Bari moves
                            parsedMoveName = parse_move_name(move.name, commentList, renameDict)
                            if parsedMoveName in commentList:
                                continue
                            line += "        " + parsedMoveName + ",\n"    
                            
                        line = line[:-2] #Remove ,\n
                        line += "),\n"
                        deleteFollowingLines = True
                        newData.append(line)
                    elif ")" in line and deleteFollowingLines:
                        deleteFollowingLines = False #We found the end of the moves list; stop deleting lines
                        #newData.append(line)
                    elif "    EGG_MOVES_TERMINATOR" in line and not movesFound:
                        line = "    egg_moves("+name.upper()+",\n"
                        for move in moveSet:
                            if move.condition == "X" or move.condition == "x":
                                continue
                            parsedMoveName = parse_move_name(move.name, commentList, renameDict)
                            if parsedMoveName in commentList:
                                continue
                            line += "        " + parsedMoveName + ",\n"
                        line = line[:-2] #Remove ,\n
                        line += "),\n\n"
                        line += "    EGG_MOVES_TERMINATOR\n"
                        newData.append(line)
                    elif not deleteFollowingLines: #Delete the previous list of moves
                        newData.append(line)
                        
                #seek and truncate to overwrite file's content
                eggMovesHeader.seek(0)
                eggMovesHeader.write("".join(newData))
                eggMovesHeader.truncate()
      

            
    