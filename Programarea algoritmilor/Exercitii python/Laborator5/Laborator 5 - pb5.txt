def comp (a, b):
    if a[1] > b[1]:
        return 1
    if a[1] < b[1]:
        return -1
    return 0

f = open ("input.txt", "r")
g = open ("output.txt", "w")

n = int(f.readline())
l = []

for i in range(n):
    aux = f.readline()
    aux = aux.split()
    l.append ((int(aux[0]), int(aux[1])))

from functools import cmp_to_key
l.sort (key=cmp_to_key(comp))

timp = 0; ans = 0
for x in l:
    asteptare = max (0, timp + x[0] - x[1])
    print ("(", timp, "-->", timp + x[0], ")  ", x[1], " ", asteptare, file = g)

    timp = timp + x[0]
    ans = max (ans, asteptare)
print ("Intarziere maxima: ", ans, file = g)
