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
# moveset_path.txt simply contains the path to the csv we want to read in.  Using this to be machine agnostic and not reveal personal stuff on check in.
with open("moveset_path.txt", "r") as speciesHeader:
    data = speciesHeader.readlines()
    url = data[0]
    

sheetData = pandas.read_csv(url, dtype=str)

columnNames = []
    
for series_name, series in sheetData.items():
    columnNames.append(series_name)

tutorMovesDict = {} #Key = pokemon name, Value = array of tutor moves
tutorMoves = []

firstTime = True
for name in columnNames:
    if not name.startswith("Unnamed"):
        tutorMovesDict[name] = []
        # sheetData.iloc[X:Y,] -- X = Beginning row of tutor moves, Y = Ending row of tutor moves.  Doesn't exactly match row number on sheet.
        for sheetIndex in sheetData.iloc[44:391,].index:
            if isinstance(sheetData["Unnamed: 1"][sheetIndex], str):
                if firstTime:
                    tutorMoves.append(sheetData["Unnamed: 1"][sheetIndex].replace("^", "").replace("-", "_").replace("'", ""))
                
                if sheetData[name][sheetIndex] == "✓":           
                    tutorMovesDict[name].append(sheetData["Unnamed: 1"][sheetIndex].replace("^", "").replace("-", "_").replace("'", ""))
        firstTime = False

currentTeachableMoves = {}

for name, moveSet in tutorMovesDict.items():   
    name = name.replace("'", "").replace("-", "")
    currentTeachableMoves[name] = []
    with open("../src/data/pokemon/teachable_learnsets.h", "r+") as teachableLearnsetsHeader:
        data = teachableLearnsetsHeader.readlines()
        newData = [] 
        matchFound = False
        
        for line in data:
            if "u16 s"+name+"TeachableLearnset" in line: 
                matchFound = True 
                newData.append(line)
            elif matchFound and "MOVE_UNAVAILABLE" in line:
                matchFound = False
                newData.append(line)
            elif matchFound:
                if m := re.search(r"([A-Z_])\w+", line):
                    currentTeachableMoves[name].append(m.group(0))
                newData.append(line)
            else:
                newData.append(line) 
        #seek and truncate to overwrite file's content
        teachableLearnsetsHeader.seek(0)
        teachableLearnsetsHeader.write("".join(newData))
        teachableLearnsetsHeader.truncate()
        
# If encountered will be commented out (for example, moves that aren't implemented yet.)
commentList = []
# due to the renames some moves have in the docs, the actual move name needs to be mapped to the internal name, not the final name the player sees.
renameDict = {"MOVE_LOCKJAW":"MOVE_JAW_LOCK", "MOVE_DARK_LARIAT":"MOVE_DARKEST_LARIAT", "MOVE_BULL_RUSH":"MOVE_HEADLONG_RUSH","MOVE_BARRIER_BASH":"MOVE_PSYSHIELD_BASH","MOVE_DAZZLE_GLEAM":"MOVE_DAZZLING_GLEAM", "MOVE_PHASE_FORCE":"MOVE_PHANTOM_FORCE", "MOVE_EXPAND_FORCE":"MOVE_EXPANDING_FORCE", "MOVE_SOUL_SHACKLE": "MOVE_SPIRIT_SHACKLE", "MOVE_NIGHT_PARADE":"MOVE_INFERNAL_PARADE", "MOVE_BREAK_SWIPE":"MOVE_BREAKING_SWIPE", "MOVE_DRAGONBREATH":"MOVE_DRAGON_BREATH", "MOVE_DOUBLE_WING":"MOVE_DUAL_WINGBEAT", "MOVE_HIT_&_RUN":"MOVE_HIT_N_RUN", "MOVE_NORTH_WIND":"MOVE_BLEAKWIND_STORM","MOVE_FLAME_LASH":"MOVE_FIRE_LASH","MOVE_FLORESCENCE":"MOVE_JUNGLE_HEALING","MOVE_PARACHARGE":"MOVE_PARABOLIC_CHARGE","MOVE_HIGH_VOLTAGE":"MOVE_RISING_VOLTAGE","MOVE_FLOWING_ARIA":"MOVE_SPARKLING_ARIA"}

for name, moveSet in tutorMovesDict.items():   
    name = name.replace("'", "").replace("-", "")
    with open("../src/data/pokemon/teachable_learnsets.h", "r+") as teachableLearnsetsHeader:
        data = teachableLearnsetsHeader.readlines()
        newData = []
    
        for line in data:
            if "u16 s"+name+"TeachableLearnset" in line:
                for move in moveSet:
                    parsedMoveName = parse_move_name(move, commentList, renameDict)   
                    if parsedMoveName not in currentTeachableMoves[name]:
                        line += "    " + parsedMoveName + ",\n"  

                newData.append(line)
            else:
                newData.append(line)
        #seek and truncate to overwrite file's content
        teachableLearnsetsHeader.seek(0)
        teachableLearnsetsHeader.write("".join(newData))
        teachableLearnsetsHeader.truncate()
      

            
    