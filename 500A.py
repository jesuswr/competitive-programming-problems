a=list(map(int,input().split()))
b=list(map(int,input().split()))
n,t=a[0],a[1]
i=1

while True:
    if i<t:
        i+=b[i-1]
    elif i==t:
        print("YES")
        break
    else:
        print("NO")
        break