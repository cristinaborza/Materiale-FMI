vmax = 100000
c = [0] * (vmax + 5)
def ciur(n):
    for i in range (2, n + 1):
        if c[i] == 0:
            for j in range (i * i, n + 1, i):
                c[j] = 1

ciur(vmax)
n = int (input())

for i in range (1, n + 1):
    if c[i] == 0:
        print (i)

number = 0
for i in range (1, vmax + 1):
    if c[i] == 0:
        print (i)
        number = number + 1
        if number == n:
            break
