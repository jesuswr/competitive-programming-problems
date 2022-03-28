from fractions import Fraction
import sys

file = open('fygon.in',mode='r')
inp = file.read()
inp = inp.replace("lag", "lag += 1")

Y = []
for n in range(7):
    lag = 0
    exec(inp)
    Y.append(lag)

def mult(p, q):
    n = len(p)
    m = len(q)
    ret = [Fraction(0) for i in range(7)]
    for i in range(n):
        for j in range(m):
            if (i + j < 7):
                ret[i+j] = ret[i+j] + p[i] * q[j]
    return ret

poly = [Fraction(0) for i in range(7)]

for i in range(7):
    curr_poly = [Fraction(0) for iiii in range(7)]
    curr_poly[0] = Fraction(1)

    for j in range(7):
        if (i == j):
            continue
        mult_poly = [Fraction(-j), Fraction(1)]
        curr_poly = mult(curr_poly, mult_poly)
    
    for j in range(7):
        if (i == j):
            continue
        for k in range(7):
            curr_poly[k] /= Fraction(i-j)

    for j in range(7):
        curr_poly[j] *= Fraction(Y[i])

    for j in range(7):
        poly[j] += curr_poly[j]

sys.stdout = open("fygon.out", "w")
for i in range(7):
    if (i > 0):
        print(' + ', end='')
    print('(', poly[i].numerator, '/', poly[i].denominator, ')', end='')
    for j in range(i):
        print('* n ', end='')