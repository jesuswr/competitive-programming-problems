a=list(map(int,input().split()))
n,m=a[0],a[1]
b=list(map(int,input().split()))
b=[i for i in set(b)]
b.sort()
em=0

if m-b[len(b)-1]>b[0]:
    em=m-b[len(b)-1]
else:
    em=b[0]

for i in range (1,len(b)):
    if (b[i]-b[i-1])/2>=em:
        em=(b[i]-b[i-1])/2
    
print(em)