n=int(input())
a=input()
a=a.split()
a=[int(i) for i in a]

b=[0 for i in range (0,n)]

for i in range (0,n):
    b[a[i]-1]=i

b=[str(i+1) for i in b]

b=" ".join(b)

print(b)