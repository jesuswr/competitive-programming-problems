n=int(input())
d=[]
D=[]

for i in range (0,n):
    d=input()
    d=d.split()
    d=[int(i) for i in d]
    D+=d

fx=sum(D[i] for i in range (0,3*n) if i%3==0)
fy=sum(D[i] for i in range (0,3*n) if i%3==1)
fz=sum(D[i] for i in range (0,3*n) if i%3==2)

if fx==0 and fy==0 and fz==0:
    print("YES")
else:
    print("NO")