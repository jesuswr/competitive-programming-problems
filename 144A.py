n=int(input())
a=input()
a=a.split()
a=[int(i) for i in a]
b=set(a)
b=[i for i in b]
b.sort(reverse=True)
cond=0
posM=0
posm=0
resp=0

if a[0]==b[0] and a[len(a)-1]==b[len(b)-1]:
    cond=1

if cond==0:
    for i in range (0,len(a)):
        if a[i]==b[0]:
            posM=i
            break

    for i in range (0,len(a)):
        if a[n-1-i]==b[len(b)-1]:
            posm=n-1-i
            break

if cond==0:
    resp+=posM
    resp+=n-1-posm

    if posM>posm:
        resp-=1

print(resp)