s = input()
s = s.split()

dict = {}
for cuv in s:
    if dict.get(cuv) == None:
        dict[cuv] = 1
    else:
        dict[cuv] = dict[cuv] + 1

mx = -1; mn = 100
cmax = ""; cmin = ""

for cuv in s:
    if dict[cuv] > mx:
        mx = dict[cuv]
        cmax = cuv
    elif dict[cuv] == mx and cuv < cmax:
        cmax = cuv

    if dict[cuv] < mn:
        mn = dict[cuv]
        cmin = cuv
    elif dict[cuv] == mn and cuv < cmin:
        cmin = cuv

print (cmin)
print (cmax)
