def comp(a, b):
    if a[0][0] > b[0][0]:
        return 1
    if a[0][0] < b[0][0]:
        return -1
    if a[0][1] > b[0][1]:
        return 1
    if a[0][1] < b[0][1]:
        return -1
    return 0

def maxim (a, b):
    if a[0] > b[0]:
        return a
    if a[0] < b[0]:
        return b
    if a[1] > b[1]:
        return a
    return b

def baga (spec):
    ok = False
    n = len(sali)
    for i in range(n):
        timp = timp_sala[i]
        if timp[0] < spec[0][0] or (timp[0] == spec[0][0] and timp[1] <= spec[0][1]):
            timp_sala[i] = maxim (timp, spec[1])
            sali[i].append (spec)
            ok = True
            break
    if ok == False:
        aux = [spec]
        sali.append (aux)
        timp_sala.append(spec[1])


f = open ("input.txt", "r")
g = open ("output.txt", "w")

aux = f.read()
aux = aux.split("\n")

l = []
for spec in aux:
    spec = spec.replace("-", " ")
    spec = spec.split()

    spec[0] = spec[0].split(":")
    spec[1] = spec[1].split(":")

    TimpInc = (int(spec[0][0]), int(spec[0][1]))
    TimpSf = (int(spec[1][0]), int(spec[1][1]))

    l.append((TimpInc, TimpSf, spec[2]))

from functools import cmp_to_key
l.sort(key=cmp_to_key(comp))

sali = []; timp_sala = []
for x in l:
    baga (x)

print (len(sali), file = g)
for x in sali:
    print (x, file = g)
