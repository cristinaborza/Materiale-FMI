def SolveA (*v):
    ans = 0
    for x in v:
        nr = int (x)
        cmax = 0
        while nr > 0:
            if nr % 10 > cmax:
                cmax = nr % 10
            nr = nr // 10
        ans = ans * 10 + cmax
    return ans
def SolveB (a, b, c):
    ans1 = SolveA(a, b, c)
    ans2 = SolveA(ans1)
    if ans2 == 1 or ans2 == 0:
        return True
    return False

print (SolveB (1001, 17, 100))
