f = open("input.txt", "r")
s = f.read()
s = s.split('\n')

magazin = {}

for line in s:
    line = line.split()
    n = len (line)
    if magazin.get(line[0]) == None:
        magazin[line[0]] = []
    for i in range (1, n):
        x = int(line[i])
        magazin[line[0]].append(x)

reuninune = {}
nrmag = 0

for mag in magazin:
    nrmag = nrmag + 1
    for cod in magazin[mag]:
        if reuninune.get(cod) == None:
            reuninune[cod] = 1
        else:
            reuninune[cod] = reuninune[cod] + 1

intersectie = []
for cod in reuninune:
    if reuninune[cod] == nrmag:
        intersectie.append(cod)

for cod in intersectie:
    print (cod)

print ('\n')
for cod in reuninune.keys():
    print (cod)

print ('\n')
for mag in magazin:
    used = 0
    for cod in magazin[mag]:
        if reuninune[cod] == 1:
            if used == 0:
                print (mag)
            print (cod)
            used = 1
    if used == 1:
        print ('\n')
