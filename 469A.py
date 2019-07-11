n=int(input())
a=input()
b=input()
a=a.split()
b=b.split()
a.pop(0)
b.pop(0)
a=[int(i) for i in a]
b=[int(i) for i in b]

d=set(a+b)

if len(d)==n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")