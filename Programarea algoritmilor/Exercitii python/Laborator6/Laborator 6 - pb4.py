def Bkt(lst, sum, n):
    if sum == n:
        print (ans,file = g)
    else:
        for i in range (1, n):
            if c[i] == 0 and sum + i <= n:
                ans.append(i)
                c[i] = 1
                Bkt(i, sum + i, n)
                c[i] = 0
                ans.pop()

f = open("input.txt", "r")
g = open("output.txt", "w")

n = int(f.readline())
c = [0] * n; ans = []
Bkt(0, 0, n)
