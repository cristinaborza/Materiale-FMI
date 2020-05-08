def comp1(a, b):
    if a[0] < b[0]:
        return -1
    if a[0] > b[0]:
        return 1
    return 0

def comp2 (a, b):
    v1 = int (a[1])
    v2 = int (b[1])

    if v1 < v2:
        return 1
    if v1 > v2:
        return -1
    if a[0] < b[0]:
        return -1
    if a[0] > b[0]:
        return 1
    return 0

def comp3 (a, b):
    v1 = int (a[1])
    v2 = int (b[1])

    s1 = int (a[2])
    s2 = int (b[2])

    if s1 < s2:
        return 1
    if s1 > s2:
        return -1
    if v1 < v2:
        return -1
    if v1 > v2:
        return 1
    return 0

def SolveA ():
    nume = input()
    gasit = False
    for x in l:
        if x[0] == nume:
            print (x[1:])
            gasit = True
            break
    if gasit == False:
        print ("Nu exista acest angajat!")

def SolveB ():
    smax = -1
    ans = []
    for x in l:
        salar = int(x[2])
        if salar > smax:
            smax = salar
            ans.clear()
            ans.append(x[0])
        elif salar == smax:
            ans.append(x[0])
    print (smax, ans)

def SolveC ():
    sum = 0
    n = len(l)

    for x in l:
        salar = int (x[2])
        sum = sum + salar

    SalarMediu = sum / n
    print (SalarMediu)

def SolveD ():
    g = open ("angajati_nume.txt", "w")
    from functools import cmp_to_key
    l.sort (key = cmp_to_key(comp1))
    print (l, file = g)

def SolveE ():
    g = open("angajati_varsta_nume.txt", "w")
    from functools import cmp_to_key
    l.sort(key=cmp_to_key(comp2))
    print(l, file=g)

def SolveF ():
    g = open("angajati_salariu_varsta.txt", "w")
    from functools import cmp_to_key
    l.sort(key=cmp_to_key(comp3))
    print(l, file=g)

f = open ("input.txt", "r")

l = []
n = int(f.readline())
for i in range(n):
    aux = f.readline()
    aux = aux.replace("\n", "")
    aux = aux.split (', ')

    idx = 0
    angajat = ()
    for cuv in aux:
        angajat = angajat + (cuv, )
    l.append (angajat)

SolveA ()
SolveB ()
SolveC ()
SolveD ()
SolveE ()
SolveF ()
