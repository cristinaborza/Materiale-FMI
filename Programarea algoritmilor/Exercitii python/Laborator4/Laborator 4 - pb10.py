def comp (a, b):
    gr1 = int (a[1])
    gr2 = int (b[1])

    if gr1 < gr2:
        return -1
    if gr1 > gr2:
        return 1

    c1 = int (a[2])
    c2 = int (b[2])

    if c1 > c2:
        return -1
    if c1 < c2:
        return 1
    return 0

def SolveB ():
    from functools import cmp_to_key
    l.sort(key = cmp_to_key(comp))
    for x in l:
        print (x)

f = open ("input.txt", "r")

n = int (f.readline())
l = []

for i in range(n):
    aux = f.readline()
    aux = aux.replace("\n", "")

    aux = aux.split()
    st = ()
    for x in aux:
        st = st + (x, )
    l.append (st)

c = int(input())
for i in range(n):
    NrCredite = int(l[i][2])
    if NrCredite >= c:
        l[i] = l[i] + ("Promovat", )
    else:
        l[i] = l[i] + ("Nepromovat", )
for i in l:
    print (i)

print ('\n')
SolveB ()
