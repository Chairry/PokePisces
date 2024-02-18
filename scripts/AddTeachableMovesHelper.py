import os
import re
import math
import pandas
import shutil

class Move:
    name = ""
    condition = ""
    
def parse_move_name(moveName, commentList):
    parsedMoveName = ""
    if moveName in commentList:
        parsedMoveName += "//"
    parsedMoveName += "MOVE"
    splitName = moveName.split()
    for word in splitName:
        parsedMoveName += "_" + word.upper()
        
    return parsedMoveName

url = f''
with open("moveset_path.txt", "r") as speciesHeader:
    data = speciesHeader.readlines()
    url = data[0]
    

sheetData = pandas.read_csv(url, dtype=str)

columnNames = []
    
for series_name, series in sheetData.items():
    columnNames.append(series_name)

currentNames = []

moveSetsDict = {}
moveConditionSetsDict = {}

tutorMovesDict = {}
tutorMoves = []

firstTime = True
for name in columnNames:
    if not name.startswith("Unnamed"):
        tutorMovesDict[name] = []
        for sheetIndex in sheetData.iloc[0:306,].index:
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
        
# If encountered will be commented out since these are not implemented yet
commentList = ["Giants Spear", "Cinder Drill", "Cinder Twirl", "Stellar Fists","Benthic Whip","Tick Tack","Power Drain","Black Buffet","Heart Steal","Finish Off","Lone Shark","Wicked Winds","Savage Wing","Dragon Poker","Plasma Cutter","Love Tap","Dance Mania","Hot Step","Vine Palm Strike","Beatbox","Flare Crush","Igna Strike","Red Eyes","Razing Sun","Bluster","Sonic Burst","Crash Land","Void","Spirit Away","Banshriek","Grip Nail","Blossom Snap","Green Guise","Lily of Life","Vigor Root","Raging Earth","Frost Shred","Frost Nova","Axel Heel","Snowfade","Dine & Dash","Tipsy Step","Real Tears","Poison Dart","Heart Carve","Gunk Funk","Scorp Fang","Graviton Arm","Odd Step","Solar Flare","Chroma Beam","Psy Swap","Power Jam","Smash Shell","Moon Beam","Shields Up","Haywire","Overtake","Heavy Swing","High Roll Hit","Sharpshoot","Torpedoes","Hullbreaker","Plunder","Serpent Surge","Furious Sea","Resevoir","Creepy Crawl","Pester Raid","Seize Chance","Brutalize","Boundary","Dark Tide","Misery Wail","Terrorize","Castle Crash","Draken Guard","Storm Chase","Party Trick","Myth Buster","Penalize","Kerfuffle","Leg Day","Evaporate","Jump & Pop","Glimmer","Hearthwarm","Ignition","Maneuver","Sharp Glide","Air Cannon","Soul Cutter","Final Shriek","Phantasm","Grass Cannon","Sun Bask","Dune Slicer","Wilder Dance","Glacial Shift","Cold Snap","Heat Sink","Verglastrom","Break Lance","Grand Slam","Bass Cannon","Exorcism","Beat Drop","Purification","Venom Drain","Caustic Finale","Venom Gale","Willpower","Mind Break","Gattling Pins","Earth Shatter","Mass Break","Pilgrimage","Heavy Cannon","Giant's Spear","Redline","Zapper","Purge Ray","Diffuse Wave","Sky Splitter","Vaporize","Railgun","Decimation","Deep Gaze","Enervator","Erode Field","Heavy Cell","Reconstruct","Remodel","Stalag Blast","Roadblock","Gem Blaster","Hunker Down","Silver Edge","Razor Beam","Aquascade","Water Wheel","Cool Mist"]

for name, moveSet in tutorMovesDict.items():   
    name = name.replace("'", "").replace("-", "")
    with open("../src/data/pokemon/teachable_learnsets.h", "r+") as teachableLearnsetsHeader:
        data = teachableLearnsetsHeader.readlines()
        newData = []
    
        for line in data:
            if "u16 s"+name+"TeachableLearnset" in line:
                for move in moveSet:
                    parsedMoveName = parse_move_name(move, commentList)   
                    if parsedMoveName not in currentTeachableMoves[name]:
                        line += "    " + parsedMoveName + ",\n"  

                newData.append(line)
            else:
                newData.append(line)
        #seek and truncate to overwrite file's content
        teachableLearnsetsHeader.seek(0)
        teachableLearnsetsHeader.write("".join(newData))
        teachableLearnsetsHeader.truncate()
      

            
    