import functools
def comp (a, b):
    if a[0] < b[0]:
        return 1
    if a[0] > b[0]:
        return -1
    if a[2] > b[2]:
        return 1
    if a[2] < b[2]:
        return -1
    return 0
s = input ()

NrOrd = 1
v = []

S = set()
dict = {}

while s != '-1':
    s = s.split(" ")
    punctaj = int(s[0])

    elem = (punctaj, )
    S.add(punctaj)

    n = len(s)
    str = ""
    for i in range(1, n):
        str = str + s[i]
        if i != n - 1:
            str = str + " "

    elem = elem + (str, )
    elem = elem + (NrOrd, )
    v.append(elem)

    tuplu = (str, NrOrd)
    if dict.get (punctaj) == None:
        dict[punctaj] = []
        dict[punctaj].append(tuplu)
    else:
        dict[punctaj].append(tuplu)

    s = input()
    NrOrd = NrOrd + 1

print (v)
print (S)
print (dict)

from functools import cmp_to_key
v = sorted(v, key = cmp_to_key(comp))

for x in v:
    print (x[0], x[1])
