def Verif(sala):
    n = len(sala)
    for i in range (n):
        for j in range (i + 1, n):
            aux = sala[i][0].split(":")
            h1_inc = int(aux[0])
            m1_inc = int(aux[1])

            aux = sala[i][1].split(":")
            h1_sf = int(aux[0])
            m1_sf = int(aux[1])

            aux = sala[j][0].split(":")
            h2_inc = int(aux[0])
            m2_inc = int(aux[1])

            aux = sala[j][1].split(":")
            h2_sf = int(aux[0])
            m2_sf = int(aux[1])

            inc1 = h1_inc * 100 + m1_inc
            sf1 = h1_sf * 100 + m1_sf

            inc2 = h2_inc * 100 + m2_inc
            sf2 = h2_sf * 100 + m2_sf

            if inc1 < inc2 and inc2 < sf1:
                return False
            if inc2 < inc1 and inc1 < sf2:
                return False
    return True
def Check():
    if Verif(sala) == True:
        global spmax
        if spmax == -1:
            spmax = len (sala)
        if spmax <= len (sala):
            sala.sort()
            for x in sala:
                print (x[0], "-", x[1], x[2], file = g)
            print ('\n', file = g)

def Bkt(pos):
    n = len (l)
    if pos >= n:
        Check ()
    else:
        sala.append(l[pos])
        Bkt(pos + 1)
        sala.pop()

        Bkt(pos + 1)

f = open ("input.txt", "r")
g = open ("output.txt", "w")

aux = f.read()
aux = aux.split('\n')

l = []
for line in aux:
    line = line.replace("-", " ")
    line = line.split(" ", 2)

    l.append((line[0], line[1], line[2]))


spmax = -1
sala = []
Bkt (0)
