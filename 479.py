a=int(input())
b=int(input())
c=int(input())
d=[]


d.append(a+b+c)
d.append(a*b*c)
d.append(a+b*c)
d.append(a*b+c)
d.append((a+b)*c)
d.append(a*(b+c))

d.sort()

print(d[5])
