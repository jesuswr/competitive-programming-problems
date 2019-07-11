a=input()
b=input()
c=input()
d=input()
e=input()
a=a.split()
b=b.split()
c=c.split()
d=d.split()
e=e.split()
A=[a,b,c,d,e]
f,g=0,0
resp=0


for i in range (0,5):
    for j in range (0,5):
        if A[i][j]=="1":
            f,g=i,j
            break
        else:
            pass


f,g=int(f),int(g)

if f>2:
    resp+=f-2
elif f<2:
    resp+=2-f

if g>2:
    resp+=g-2
elif g<2:
    resp+=2-g

print(resp)


