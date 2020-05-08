import math

def ipotenuza(a, b):
    lg = a * a + b * b
    ans = math.sqrt(lg)
    return ans

#f = open("input.txt", "r")
g = open("output.txt", "w")

b = int(input())
for a in range (1, b + 1):
    c = ipotenuza(a, b)
    intreg = math.floor(c)
    if c == intreg:
        print (a, b, intreg, file = g)
