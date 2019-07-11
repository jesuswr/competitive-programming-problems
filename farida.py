n=int(input())

for j in range (n):
    
    N=int(input())
    a=list(map(int,input().split()))
    f=[0 for i in range(N)]
    for i in range(N):
        if i==0:
            f[i]=a[i]
        elif i==1:
            f[i]=max(a[i],a[i-1])
        else:
            f[i]=max(f[i-1],a[i]+f[i-2])

    if N>0:
        print(str("Case ")+str(j+1)+str(": ")+str(f[N-1]))
    else:
        print(str("Case ")+str(j+1)+str(": ")+str("0"))
        
