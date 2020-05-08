def comp1 (a, b):
    n = len (a)
    m = len (b)

    if n < m:
        return -1
    if n > m:
        return 1

    for i in range(n):
        if a[i] > b[i]:
            return 1
        if a[i] < b[i]:
            return -1
    return 0
def comp2 (a, b):
    n = len (a)
    m = len (b)

    if n < m:
        return -1
    if n > m:
        return 1

    if dict[a] < dict[b]:
        return -1
    return 1

f = open("input.txt", "r")
g = open("output.txt", "w")

sir = f.read()
sir = sir.split()

l = []
dict = {}
idx = 1
for cuv in sir:
    dict[cuv] = idx
    idx = idx + 1

    l.append(cuv)

l.sort(reverse = True)
print (l, file = g)

from functools import cmp_to_key
l.sort (key = cmp_to_key(comp1))
print (l, file = g)

l.sort (key = cmp_to_key(comp2))
print (l, file = g)
