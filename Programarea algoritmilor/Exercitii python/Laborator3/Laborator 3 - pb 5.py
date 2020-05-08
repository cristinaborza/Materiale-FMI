def check (s, t):
    for ch1 in s:
        ok = False
        for ch2 in t:
            if ch1 == ch2:
                ok = True
                break
        if ok == False:
            return False
    for ch1 in t:
        ok = False
        for ch2 in s:
            if ch1 == ch2:
                ok = True
                break
        if ok == False:
            return False
    return True


s = input()
s = s.replace(",", " ")
s = s.replace("!", " ")
s = s.replace(".", " ")
s = s.replace("?", " ")

s = s.split()
cuv = input()

ans = []

for ch in s:
    if check (ch, cuv) == True:
        ans.append(ch)

if len(ans) == 0:
    print ("Nu exista")
else:
    print (ans)
