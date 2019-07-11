a=list(map(int,input().split()))
b=list(map(int,input().split()))
n=a[0]
h=a[1]
resp=0

for i in b:
    if i>h:
        resp+=2
    else:
        resp+=1

print(resp)