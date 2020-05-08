s = input()
s = s.split()

rime = {}

for cuv in s:
    n = len (cuv)
    str = cuv[n - 2] + cuv[n - 1]
    if rime.get(str) == None:
        rime[str] = []
        rime[str].append(cuv)
    else:
        rime[str].append(cuv)

final = {}
for suf in rime.keys():
    v = rime[suf]
    if len(v) > 1:
        final[suf] = rime[suf]
print (final.items())
