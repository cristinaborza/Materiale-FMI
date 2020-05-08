s = input ()
vocale = "aeiouAEIOU"
ans = ""

for ch1 in s:
    ok = False
    for ch2 in vocale:
        if ch1 == ch2:
            ok = True
            break
    if ok == True:
        ans = ans + ch1 + "p" + ch1.lower()
    else:
        ans = ans + ch1
print (ans)
