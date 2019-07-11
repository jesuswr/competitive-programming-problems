a=list(map(int,input().split()))
n=a[0]
m=a[1]
i=0
dias=0
j=1

while True:
    i+=1
    if n>0:
        dias+=1
        n-=1
    
    if i==j*m:
        j+=1
        n+=1

    if n==0:
        break

print(dias)