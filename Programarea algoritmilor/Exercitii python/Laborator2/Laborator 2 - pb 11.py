s = input()
n = len (s)

ans = []; str = ''
nrprop = 0

for i in range (n):
    if s[i] >= 'A' and s[i] <= 'Z' and (i == 0 or s[i - 1] == '.'):
        if str != '':
            ans.append (str)
        str = s[i]
    else:
        str = str + s[i]

if str != '':
    ans.append(str)
print (ans)
