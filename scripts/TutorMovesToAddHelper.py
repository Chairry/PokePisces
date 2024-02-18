import os
from pickle import FALSE
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
    
# def add_move_line(move, commentList):
#     line = "    "
#     if move.name in commentList:
#         line += "//"
#     if move.condition == "1/Evo":
#         line += "LEVEL_UP_MOVE(0, " + parse_move_name(move.name) + "),\n"
#         line += "    "
#         if move.name in commentList:
#             line += "//"
#         line += "LEVEL_UP_MOVE(1, " + parse_move_name(move.name) + "),\n"
#     elif move.condition != "X":
#         line += "LEVEL_UP_MOVE(" + move.condition + ", " + parse_move_name(move.name) + "),\n"
#     else:
#         line = ""
    
#     return line

columnNames = []
url = f''
with open("moveset_path.txt", "r") as speciesHeader:
    data = speciesHeader.readlines()
    url = data[0]
    

sheetData = pandas.read_csv(url, dtype=str)


    
for series_name, series in sheetData.items():
    columnNames.append(series_name)

currentNames = []

moveSetsDict = {}
moveConditionSetsDict = {}

tutorMovesDict = {}
tutorMoves = []

    
moveName = ""
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
                    
with open("moves_path.txt", "r") as speciesHeader:
    data = speciesHeader.readlines()
    url = data[0]
    
sheetData = pandas.read_csv(url, dtype=str)

columnNames = []
for series_name, series in sheetData.items():
    columnNames.append(series_name)

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
        

for moveSetName, moveSet in moveSetsDict.items():   
    previousMatchFound = False
    for move in moveSet:
        # print (moveSetName + ":")
        # print (move.name)
        #print (",".join(moveSet))
        #print(moveSet[0])
        for tutorMove in tutorMoves:
            #print (tutorMove)
            if move.condition != "X" and tutorMove == move.name and tutorMove not in tutorMovesDict[moveSetName]:
                tutorMoves[moveSetName].append(move.name)
                if not previousMatchFound:
                    print (moveSetName + ":")
                    previousMatchFound = True
                print("    " + tutorMove)
        
      

            
    