s = input()
nr = 0; ans = 0
for ch in s:
    if ch >= '0' and ch <= '9':
        aux = ord(ch) - ord('0')
        nr = nr * 10 + aux
    else:
        ans = ans + nr
        nr = 0
print (ans)
