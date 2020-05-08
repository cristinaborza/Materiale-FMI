def check (pos, s1, s2):
    n = len (s2)
    m = len (s1)

    if pos > 0 and s2[pos - 1] != ' ' and s2[pos - 1] != '.' and s2[pos - 1] != '!' and s2[pos - 1] != ',' and s2[pos - 1] != ',':
        return False
    if pos + m - 1 >= n:
        return False
    if pos + m - 1 < n - 1 and s2[pos + 1] != ' ' and s2[pos + 1] != '.' and s2[pos + 1] != '!' and s2[pos + 1] != ',' and s2[pos + 1] != ',':
        return False
    for i in range (m):
        if s1[i] != s2[pos + i]:
            return False
    return True

sir = input ()
s = input ()
t = input ()

ans = ""
n = len(sir)
m = len (s)

lg = 0
for i in range (n):
    if lg != 0:
        lg = lg - 1
    if lg != 0:
        continue
    if check (i, s, sir) == True:
        ans += t
        lg = m
    else:
        ans += sir[i]

print (ans)
