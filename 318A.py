a=input()
a=a.split()
n=int(a[0])
k=int(a[1])
h=0

if n%2!=0:
    if k>n//2 +1:
        h=(k-n//2-1)*2
        
    else:
        h=2*k-1

else:
    if k>n/2:
        h=(k-n/2)*2

    else:
        h=2*k-1

print(int(h))

