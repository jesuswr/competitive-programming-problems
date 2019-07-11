n=int(input())
m=input()
m=m.split()
k=[int(i) for i in m]
p=[k[len(k)-i] for i in range (1,len(k)+1)]
cont=0
a,b=k[0],p[0]
c,d=1,1
resp=0

for i in k:
    cont+=i

cont=cont-a-b

while True and c+d<=len(k):

    if a<b:
        a+=k[c]
        c+=1
    elif b<a:
        b+=p[d]
        d+=1
    elif a==b and c<len(k) and d<len(k):
        resp=a
        a,b=a+k[c],b+p[d]
        c,d=c+1,d+1
    elif c+d>len(k):
        break

print(resp)


    
