dict1 = {
    "ana": 3,
    "ala": 7,
    "bala": 1,
    "portocala": 2
}

dict2 = {
    "ana": 2,
    "are": 3,
    "mere": 9,
    "si": 1,
    "portocala": 5
}

ans = {}
for x in dict1.keys():
    ans[x] = dict1[x]
for x in dict2.keys():
    if ans.get(x) == None:
        ans[x] = dict2[x]
    else:
        ans[x] = ans[x] + dict2[x]

print (ans.items())
