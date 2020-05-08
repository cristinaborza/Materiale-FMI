def comp (a, b):
    if a[1] > b[1]:
        return 1
    if a[1] < b[1]:
        return -1
    return 0

f = open ("input.txt", "r")
g = open ("output.txt", "w")

aux = f.read()
aux = aux.split("\n")

l = []
for line in aux:
    line = line.split()
    project = (line[0], int (line[1]), int(line[2]))
    l.append (project)

from functools import cmp_to_key
l.sort(key=cmp_to_key(comp))

n = len(l); pos = n - 1
ans = []; pmax = 0

import heapq
hp = []
heapq.heapify (hp)

while pos >= 0:
    heapq.heappush(hp, (-l[pos][2], l[pos][0]))
    while pos - 1 >= 0 and l[pos - 1][1] == l[pos][1]:
        heapq.heappush(hp, (-l[pos - 1][2], l[pos - 1][0]))
        pos = pos - 1

    vmax = -hp[0][0]
    pr = hp[0][1]
    heapq.heappop(hp)

    ans.append(pr)
    pmax = pmax + vmax
    pos = pos - 1

print (ans, "\n", pmax, file = g)
