c=list(map(int,input().split()))
a=c[0]
b=c[1]
h=a

while a>=b:
   
    if a%b!=0:
        h+=a//b
        a=a//b+a%b
    else:
        h+=a/b
        a=a/b

print(int(h))