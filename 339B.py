a=list(map(int,input().split()))
b=list(map(int,input().split()))
n,m=a[0],a[1]
c=1
t=0

for i in b:
    
    if c>i:
        t+=n+i-c
        c=i
    elif c<i:
        t+=i-c
        c=i

print(t)