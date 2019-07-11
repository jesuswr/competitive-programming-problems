h=input()

h=h.split()

n=int(h[0])
m=int(h[1])
a=int(h[2])

x=n//a
y=m//a

if n%a!=0:
    x+=1
else:
    pass

if m%a!=0:
    y=y+1
else:
    pass

print(x*y)