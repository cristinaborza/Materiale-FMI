n = int(input())
v = []
for i in range (n):
    x = int (input())
    v.append(x)

vmax1 = v[0]
vmax2 = v[1]

if vmax1 == vmax2:
    for i in range(1, n):
        if v[i] != vmax1:
            vmax2 = vmax1
            break

if vmax1 == vmax2:
    print ("Nu exista 2 valori distincte")
else:
    for i in range (n):
        if v[i] > vmax1:
            vmax2 = vmax1
            vmax1 = v[i]
        elif v[i] != vmax1 and v[i] > vmax2:
            vmax2 = v[i]

    print (vmax1)
    print (vmax2)
