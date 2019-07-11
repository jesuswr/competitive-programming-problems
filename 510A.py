a=list(map(int,input().split()))
n,m=a[0],a[1]
j=0
l1=["#" for i in range (0,m)]
l2=["." for i in range (0,m-1)]+["#"]
l3=["#"]+["." for i in range (0,m-1)]


for i in range (0,n):
    if j==0:
        print("".join(l1))
        j+=1
    elif j==1:
        print("".join(l2))
        j+=1
    elif j==2:
        print("".join(l1))
        j+=1
    elif j==3:
        print("".join(l3))
        j=0

