n=int(input())
a=4
b=n-4
cond=0

while True:
    cond=0
    for i in range (2,a):
        if a%i==0:
            cond+=1
            break

    for i in range (2,b):
        if b%i==0:
            cond+=1
            break

    if cond==2:
        break
    else:
        a+=1
        b-=1

print(a,b)