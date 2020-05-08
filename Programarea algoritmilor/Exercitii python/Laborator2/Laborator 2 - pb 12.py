def Solve (s, t):
    n = len (s)
    m = len (t)

    p1 = n - 1
    p2 = 0

    while p1 >= 0 and p2 < m:
        if s[p1] != t[p2]:
            break
        x = s[p1]
        while p2 < m and t[p2] == x:
            p2 = p2 + 1
        while p1 >= 0 and s[p1] == x:
            p1 = p1 - 1

    return s[0:p1+1] + t[p2:m]

def FindReverse (s):
    str = ''
    for ch in s:
        str = ch + str
    return  str

s = input()
t = input()

print (Solve (s, t))
