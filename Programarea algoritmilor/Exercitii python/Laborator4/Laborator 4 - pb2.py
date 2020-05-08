import math

def lungime_are_cerc(r):
    Pi = math.pi
    Lg = 2 * Pi * r
    Arie = Pi * r * r
    return (Lg, Arie)

#f = open("input.txt", "r")
g = open("output.txt", "w")

r = int(input())
print (lungime_are_cerc(r)[0], lungime_are_cerc(r)[1], file = g)
