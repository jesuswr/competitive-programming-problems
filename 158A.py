a=input()
a=a.split()

b=int(a[0])
c=int(a[1])

d=input()
d=d.split()

d=[int(i) for i in d]

e=0

for i in d:
    if i>0:
        if i>=d[c-1]:
            e+=1
        else:
            pass
    else:
        pass

print(e)