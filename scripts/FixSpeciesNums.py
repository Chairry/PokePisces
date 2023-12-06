import os

with open("../include/constants/species.h", "r") as infile:
    data = infile.readlines()

with open("fixed/species.h", "w") as outfile:
    newData = []
    speciesCount = 0
    formCount = 1
    for line in data:
        newLine = line.split()
        if len(newLine) >= 3 and newLine[2].isnumeric():            
            newLine[2] = str(speciesCount)
            speciesCount += 1
            newLine.append("\n")
            newData.append(" ".join(newLine))
        elif len(newLine) >= 4 and newLine[4].isnumeric():                
            newLine[4] = str(formCount)
            formCount += 1
            newLine.append("\n")
            newData.append(" ".join(newLine))
        else:
            newData.append(line)
    outfile.write("".join(newData))