import os
import re
import math
import pandas
import shutil

class Move:
    name = ""
    condition = ""
    
def parse_move_name(moveName, renameDict):
    parsedMoveName = "MOVE"
    splitName = moveName.split()
    for word in splitName:
        parsedMoveName += "_" + word.upper()
        
    if parsedMoveName in renameDict:
        parsedMoveName = renameDict[parsedMoveName]
        
    return parsedMoveName
    
def add_move_line(move, commentList, renameDict):
    line = "    "
    if move.name in commentList:
        line += "//"
    if move.condition == "1/Evo":
        line += "LEVEL_UP_MOVE(0, " + parse_move_name(move.name, renameDict) + "),\n"
        line += "    "
        if move.name in commentList:
            line += "//"
        line += "LEVEL_UP_MOVE(1, " + parse_move_name(move.name, renameDict) + "),\n"
    elif move.condition != "X" and move.condition != "x":
        line += "LEVEL_UP_MOVE(" + move.condition + ", " + parse_move_name(move.name, renameDict) + "),\n"
    else:
        line = ""
    
    return line

url = f''
with open("moves_path.txt", "r") as speciesHeader:
    data = speciesHeader.readlines()
    url = data[0]
    

sheetData = pandas.read_csv(url, dtype=str)

columnNames = [];
    
for series_name, series in sheetData.items():
    columnNames.append(series_name)

currentNames = []

moveSetsDict = {}
moveConditionSetsDict = {}

for name in columnNames:

    if not name.startswith("Unnamed") and name != " ":
        moveConditionSetsDict[name] = []
        moveSetsDict[name] = []
        currentNames.append(name)
    
    #Some mons moves begin partway down and end before row 30. i is used to match the condition to the moveset, 
    #regardless of the number/location in the sheet.
    i = -1
    for sheetIndex in sheetData.iloc[0:30,].index:

        if name.startswith("Unnamed") and isinstance(sheetData[name][sheetIndex], str): #blank values are read as NaN, which is not a string
            i += 1
            for currentName in currentNames:
                move = Move()
                move.condition = moveConditionSetsDict[currentName][i]
                move.name = sheetData[name][sheetIndex].replace("^", "").replace("-", "_").replace("'", "")
                moveSetsDict[currentName].append(move)
            
        elif isinstance(sheetData[name][sheetIndex], str) and sheetData[name][sheetIndex] != "": # math.isnan(sheetData[name][sheetIndex])
            moveConditionSetsDict[name].append(sheetData[name][sheetIndex])      
            
    if name.startswith("Unnamed"):
        currentNames = [] #clear out currentNames after adding moves
        
        
# If encountered will be commented out since these are not implemented yet
commentList = []

renameDict = {"MOVE_STAR_ASSAULT":"MOVE_METEOR_ASSAULT", "MOVE_POWER_FLIP":"MOVE_TOPSY_TURVY", "MOVE_SKYPIERCER":"MOVE_DRAGON_ASCENT", "MOVE_THUNDER_KICK":"MOVE_THUNDEROUS_KICK", "MOVE_DUST_DEVIL":"MOVE_SANDSEAR_STORM", "MOVE_THE_13_TOLLS":"MOVE_SILENCE", "MOVE_MIXTAPE":"MOVE_CLANGOROUS_SOUL", "MOVE_CLIFF_BLADES":"MOVE_PRECIPICE_BLADES", "MOVE_NATURES_FURY":"MOVE_NATURES_MADNESS", "MOVE_SPACE_FURY":"MOVE_HYPERSPACE_FURY", "MOVE_FERVID_DANCE":"MOVE_REVELATION_DANCE", "MOVE_MASS_DESTRUCT":"MOVE_MASS_DESTRUCTION", "MOVE_FREEZE_GLARE":"MOVE_FREEZING_GLARE", "MOVE_PHANTOM_THIEF":"MOVE_SPECTRAL_THIEF", "MOVE_DOUBLE_BASH":"MOVE_DOUBLE_IRON_BASH", "MOVE_SEA_JAWS":"MOVE_FISHIOUS_REND", "MOVE_RUINA_LIGHT":"MOVE_LIGHT_OF_RUIN", "MOVE_CORROSIVE_CHAIN":"MOVE_MALIGNANT_CHAIN", "MOVE_SEARING_SANDS":"MOVE_SCORCHING_SANDS", "MOVE_PSYCHE_CRASH":"MOVE_LUMINA_CRASH", "MOVE_HORSE_POWER":"MOVE_HIGH_HORSEPOWER", "MOVE_DRACO_CRY":"MOVE_DRAGON_CHEER", "MOVE_BANE_BUNKER":"MOVE_BANEFUL_BUNKER", "MOVE_DRACO_HAMMER":"MOVE_DRAGON_HAMMER", "MOVE_BURNING_ENVY":"MOVE_BURNING_JEALOUSY", "MOVE_PHOTON_FLARE":"MOVE_PHOTON_GEYSER", "MOVE_DOOM_WING":"MOVE_OBLIVION_WING", "MOVE_THUNDERPUNCH":"MOVE_THUNDER_PUNCH", "MOVE_METEOR_STRIKE":"MOVE_SUNSTEEL_STRIKE", "MOVE_DRAIN_KISS":"MOVE_DRAINING_KISS", "MOVE_ECLIPSE_RAY":"MOVE_MOONGEIST_BEAM", "MOVE_SPACE_HOLE":"MOVE_HYPERSPACE_HOLE", "MOVE_HYDRA_BEAM":"MOVE_FICKLE_BEAM", "MOVE_SHELLTER":"MOVE_SHELTER", "MOVE_JUMP_&_POP":"MOVE_JUMP_N_POP", "MOVE_DRACO_ENERGY":"MOVE_DRAGON_ENERGY", "MOVE_TIDAL_CRASH":"MOVE_WAVE_CRASH", "MOVE_PETAL_FLURRY":"MOVE_PETAL_BLIZZARD", "MOVE_RED_GUARD":"MOVE_BURNING_BULWARK", "MOVE_CUTIE_CRY":"MOVE_DISARMING_VOICE", "MOVE_LEAFNADO":"MOVE_LEAF_TORNADO", "MOVE_ANGER_STOMPS":"MOVE_STOMPING_TANTRUM", "MOVE_PSYCHOLARM":"MOVE_PSYCHIC_NOISE", "MOVE_DINE_&_DASH":"MOVE_DINE_N_DASH", "MOVE_LOCKJAW":"MOVE_JAW_LOCK", "MOVE_DARK_LARIAT":"MOVE_DARKEST_LARIAT", "MOVE_BULL_RUSH":"MOVE_HEADLONG_RUSH","MOVE_BARRIER_BASH":"MOVE_PSYSHIELD_BASH","MOVE_DAZZLE_GLEAM":"MOVE_DAZZLING_GLEAM", "MOVE_PHASE_FORCE":"MOVE_PHANTOM_FORCE", "MOVE_EXPAND_FORCE":"MOVE_EXPANDING_FORCE", "MOVE_SOUL_SHACKLE": "MOVE_SPIRIT_SHACKLE", "MOVE_NIGHT_PARADE":"MOVE_INFERNAL_PARADE", "MOVE_BREAK_SWIPE":"MOVE_BREAKING_SWIPE", "MOVE_DRAGONBREATH":"MOVE_DRAGON_BREATH", "MOVE_DOUBLE_WING":"MOVE_DUAL_WINGBEAT", "MOVE_HIT_&_RUN":"MOVE_HIT_N_RUN", "MOVE_NORTH_WIND":"MOVE_BLEAKWIND_STORM","MOVE_FLAME_LASH":"MOVE_FIRE_LASH","MOVE_FLORESCENCE":"MOVE_JUNGLE_HEALING","MOVE_PARACHARGE":"MOVE_PARABOLIC_CHARGE","MOVE_HIGH_VOLTAGE":"MOVE_RISING_VOLTAGE","MOVE_FLOWING_ARIA":"MOVE_SPARKLING_ARIA"}

for name, moveSet in moveSetsDict.items():   
    name = name.replace("'", "").replace("-", "")
    with open("../src/data/pokemon/level_up_learnsets.h", "r+") as levelUpLearnsetsHeader:
                data = levelUpLearnsetsHeader.readlines()
                newData = []
                deleteFollowingLines = False
                
                for line in data:
                    newLine = line.split()
                    if "LevelUpMove s"+name in line:
                        #print(currentLevelUpMoves[name])
                        for move in moveSet:
                            if ("\u2606" in move.name):
                                move.name = move.name.replace("\u2606", "_") #I'm looking at you Bari☆Bari☆Beam☆
                                move.name = move.name[:-1] #Remove final _ from the Bari Bari moves

                            line += add_move_line(move,commentList,renameDict)    
                        deleteFollowingLines = True
                        newData.append(line)
                    elif "LEVEL_UP_END" in line:
                        deleteFollowingLines = False #We found the end of the moves list; stop deleting lines
                        newData.append(line)
                    elif not deleteFollowingLines: #Delete the previous list of moves
                        newData.append(line)
                #seek and truncate to overwrite file's content
                levelUpLearnsetsHeader.seek(0)
                levelUpLearnsetsHeader.write("".join(newData))
                levelUpLearnsetsHeader.truncate()

            
    