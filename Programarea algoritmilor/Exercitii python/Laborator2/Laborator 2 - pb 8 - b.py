s = input ()
n = len (s)

sep = ' -,!?.'
ans = ""

for i in range(n):
    ans = ans + s[i]
    ok = False
    for ch in sep:
        if ch == s[i]:
            ok = True
            break
    if ok == True:
        continue

    if i == n - 1:
        ans = ans + 'p'
        ans = ans + s[i]
    else:
        ok = False
        for ch in sep:
            if ch == s[i + 1]:
                ok = True
                continue

        if ok == True:
            ans = ans + 'p'
            ans = ans + s[i].lower()

sol = ""
for ch in ans:
    if ch != '-':
        sol += ch

print (ans)
print (sol)
