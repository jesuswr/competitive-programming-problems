a=input()
a=a.split()

prec1b=int(a[0])
dine=int(a[1])
ban=int(a[2])

prectotal=sum(i*prec1b for i in range (1,ban+1))

if prectotal>dine:
    print(prectotal-dine)
else:
    print(0)
