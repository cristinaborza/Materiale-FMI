f = open ("input.txt", "r")

s = f.read()
s = s.split('\n')

ans = []
for paragraf in s:
    expres = len(paragraf.split('~')) - 1

    paragraf = paragraf.replace('~', ' ')
    paragraf = paragraf.replace(',', ' ')
    paragraf = paragraf.replace(':', ' ')
    paragraf = paragraf.replace('!', ' ')
    paragraf = paragraf.replace('.', ' ')
    paragraf = paragraf.replace('?', ' ')
    paragraf = paragraf.split(' ')

    x = (paragraf[0], )
    for cuv in paragraf:
        if cuv == paragraf[0]:
            expres = expres + 1

    expres = expres - 1
    x = x + (expres, )
    ans.append (x)

print (ans)
