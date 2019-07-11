a=input()
a=a.split()

n=int(a[0])
m=int(a[1])
p=0
r=0

while True:
    if p%2==0 and n!=1 and m!=1:
        p+=1
        n,m=n-1,m-1
        r=1
    if p%2!=0 and n!=1 and m!=1:
        p+=1
        n,m=n-1,m-1
        r=0
    if n==1 or m==1:
        break

if r==0:
    print("Akshat")
else:
    print("Malvika")    
