def negative_pozitive(v):
    neg = []
    poz = []

    for x in v:
        if x < 0:
            neg.append(x)
        else:
            poz.append(x)

    return (poz, neg)

v = []

str = input()
str = str.split()
for x in str:
    if x.isnumeric() == False:
        x = x.split("-")
        x = int(x[1])
        x = -x
    else:
        x = int(x)

    v.append(int(x))

print(negative_pozitive(v)[0], negative_pozitive(v)[1])
