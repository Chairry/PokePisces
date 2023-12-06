import os

with open("ability_desc.txt", "r") as infile:
    data = infile.readlines()

with open("fixed/ability_desc_fix.txt", "w") as outfile:
    newData = []
    startAt = 301
    names = []
    descriptions = []
    defineToDesc = []
    defines = []
    for line in data:
        name, description = line.split(", ")
        description = description.replace("\n", "")
        name = name.replace("'", "")
        name = name.replace("-", "")
        define = name.replace(" ", "_").upper()
        defines.append("#define ABILITY_{} {}\n".format(define, startAt))
        names.append('[ABILITY_{}] = _("{}"),\n'.format(define, name))
        descriptionVar = "s{}Description".format(name.replace(" ", ""))
        descriptions.append('static const u8 {}[] = _("{}");\n'.format(descriptionVar, description))
        defineToDesc.append('[ABILITY_{}] = {},\n'.format(define, descriptionVar))
        startAt += 1
    newData.append("Defines\n")
    for thing in defines:
        newData.append(thing)
    newData.append("\nNames\n")
    for thing in names:
        newData.append(thing)
    newData.append("\nDescriptions\n")
    for thing in descriptions:
        newData.append(thing)
    newData.append("\nDefToDesc\n")
    for thing in defineToDesc:
        newData.append(thing)
    outfile.write("".join(newData))