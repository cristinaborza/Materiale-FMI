s = input()
sep = " .,!?-"
dict = {}
for ch1 in s:
    ok = True
    ch1 = ch1.lower()
    for ch2 in sep:
        if ch1 == ch2:
            ok = False
            break
    if ok == True:
        if dict.get(ch1) == None:
            dict[ch1] = 1
        else:
            dict[ch1] = dict[ch1] + 1

for ch in dict.keys():
    print (ch, dict[ch])
