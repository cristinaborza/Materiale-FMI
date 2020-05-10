def Bkt (x, sum):
    if sum == n:
        print (x, file = g)
        if c[0] == 0:
            print (x * 10, file = g)
    else:
        if c[0] == 0 and x != 0:
            c[0] = 1
            Bkt (x * 10, sum)
            c[0] = 0
        for i in range(1, n):
            if c[i] == 0 and sum + i <= n:
                c[i] = 1
                Bkt (x * 10 + i, sum + i)
                c[i] = 0

f = open("input.txt", "r")
g = open("output.txt", "w")

n = int(f.readline())
c = [0] * n

Bkt (0, 0)
