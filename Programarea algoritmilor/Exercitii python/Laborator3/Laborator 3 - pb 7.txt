text = input()
f = open(text, "r")
s = f.read()
s = s.split()

nr = -1
ans = 0

for cuv in s:
    if cuv.isdigit() == True:
        if nr == -1:
            nr = int(cuv)
        else:
            aux = int (cuv)
            ans = ans + aux * nr
            nr = -1
    else:
        cuv = cuv.split('.')
        if len(cuv) != 2:
            continue
        if cuv[0].isdigit() == True and cuv[1].isdigit() == True:
            frac = int (cuv[1]) * (10 **(-len(cuv[1])))
            aux = int(cuv[0]) + frac
            if nr == -1:
                nr = aux
            else:
                ans = ans + aux * nr
                nr = -1
print (ans)
