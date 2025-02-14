def comp (a, b):
    if a[0] / a[1] > b[0] / b[1]:
        return -1
    if a[0] / a[1] < b[0] / b[1]:
        return 1
    return 0

f = open ("input.txt", "r")
g = open ("output.txt", "w")

n = int(f.readline())
l = []

for i in range(n):
    aux = f.readline()
    aux = aux.split()
    l.append ((int (aux[0]), int(aux[1])))

TotalWeight = int (f.readline())

from functools import cmp_to_key
l.sort (key = cmp_to_key(comp))

Weight = 0; Value = 0

for obj in l:
    if Weight + obj[1] <= TotalWeight:
        Weight = Weight + obj[1]
        Value = Value + obj[0]

        if Weight == TotalWeight:
            break
    else:
        Value = Value + ((obj[0] * (TotalWeight - Weight)) / obj[1])

print (Value, file = g)
