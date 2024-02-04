import os
import re
import math
import pandas
import shutil

class Move:
    name = ""
    condition = ""
    
def parse_move_name(moveName):
    parsedMoveName = "MOVE"
    splitName = moveName.split()
    for word in splitName:
        parsedMoveName += "_" + word.upper()
        
    return parsedMoveName
    
def add_move_line(move, commentList):
    line = "    "
    if move.name in commentList:
        line += "//"
    if move.condition == "1/Evo":
        line += "LEVEL_UP_MOVE(0, " + parse_move_name(move.name) + "),\n"
        line += "    "
        if move.name in commentList:
            line += "//"
        line += "LEVEL_UP_MOVE(1, " + parse_move_name(move.name) + "),\n"
    elif move.condition != "X":
        line += "LEVEL_UP_MOVE(" + move.condition + ", " + parse_move_name(move.name) + "),\n"
    else:
        line = ""
    
    return line

url = f''
with open("moveset_path.txt", "r") as speciesHeader:
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
commentList = ["Giants Spear", "Cinder Drill", "Cinder Twirl", "Flowing Aria", "Cutie Cry", "Sidearm", "Searing Sands", "Psyche Crash", "Bull Rush", "Florescence", "Draco Hammer", "Anger Stomps", "North Wind", "Stellar Fists","Benthic Whip","Tick Tack","Power Drain","Black Buffet","Heart Steal","Finish Off","Lone Shark","Wicked Winds","Savage Wing","Dragon Poker","Plasma Cutter","Love Tap","Dance Mania","Hot Step","Vine Palm Strike","Beatbox","Flare Crush","Igna Strike","Red Eyes","Razing Sun","Bluster","Sonic Burst","Crash Land","Void","Spirit Away","Banshriek","Grip Nail","Blossom Snap","Green Guise","Lily of Life","Vigor Root","Raging Earth","Frost Shred","Frost Nova","Axel Heel","Snowfade","Dine & Dash","Tipsy Step","Real Tears","Poison Dart","Heart Carve","Gunk Funk","Scorp Fang","Graviton Arm","Odd Step","Solar Flare","Chroma Beam","Psy Swap","Power Jam","Smash Shell","Moon Beam","Shields Up","Haywire","Overtake","Heavy Swing","High Roll Hit","Sharpshoot","Torpedoes","Hullbreaker","Plunder","Serpent Surge","Furious Sea","Resevoir","Creepy Crawl","Pester Raid","Seize Chance","Brutalize","Boundary","Dark Tide","Misery Wail","Terrorize","Castle Crash","Draken Guard","Storm Chase","Party Trick","Myth Buster","Penalize","Kerfuffle","Leg Day","Evaporate","Jump & Pop","Glimmer","Hearthwarm","Ignition","Maneuver","Sharp Glide","Air Cannon","Soul Cutter","Final Shriek","Phantasm","Grass Cannon","Sun Bask","Dune Slicer","Wilder Dance","Glacial Shift","Cold Snap","Heat Sink","Verglastrom","Break Lance","Grand Slam","Bass Cannon","Exorcism","Beat Drop","Purification","Venom Drain","Caustic Finale","Venom Gale","Willpower","Mind Break","Gattling Pins","Earth Shatter","Mass Break","Pilgrimage","Heavy Cannon","Giant's Spear","Redline","Zapper","Purge Ray","Diffuse Wave","Sky Splitter","Vaporize","Railgun","Decimation","Deep Gaze","Enervator","Erode Field","Heavy Cell","Reconstruct","Remodel","Stalag Blast","Roadblock","Gem Blaster","Hunker Down","Silver Edge","Razor Beam","Aquascade","Water Wheel","Cool Mist"]

for name, moveSet in moveSetsDict.items():   
    name = name.replace("'", "").replace("-", "")
    with open("../src/data/pokemon/level_up_learnsets.h", "r+") as levelUpLearnsetsHeader:
                data = levelUpLearnsetsHeader.readlines()
                newData = []
                matchFound = False
    
                for line in data:
                    newLine = line.split()
                    if "LevelUpMove s"+name in line:
                        matchFound = True
                        newData.append(line)
                    elif matchFound and "};" in line:
                        matchFound = False
                        newData.append(line)
                    elif matchFound and "HIDDEN_POWER" in line:
                        for move in moveSet:
                            if matchFound: #reuse matchFound bool to determine first line with hidden power
                                matchFound = False
                                line = add_move_line(move, commentList)
                            else:
                                line += add_move_line(move,commentList)    

                        newData.append(line)
                    else:
                        newData.append(line)
                #seek and truncate to overwrite file's content
                levelUpLearnsetsHeader.seek(0)
                levelUpLearnsetsHeader.write("".join(newData))
                levelUpLearnsetsHeader.truncate()
      

            
    