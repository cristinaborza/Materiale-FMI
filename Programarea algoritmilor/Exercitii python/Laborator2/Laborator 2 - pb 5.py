s = input()
k = int(input())

ans = ""
for ch in s:
    idx = ord(ch)
    p = 0
    if (ch >= 'a' and ch <= 'z'):
        p = ord('a')
    if (ch >= 'A' and ch <= 'Z'):
        p = ord('A')

    idx = idx - p
    idx = idx - k + 26
    idx = idx % 26
    idx = idx + p

    ans += chr(idx)
print (ans)
