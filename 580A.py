n=int(input())
a=input()
a=a.split()
a=[int(i) for i in a]
d=[]
cont=1
b=-1

for i in range (0,n-1):
    if a[i]<=a[i+1]:
        cont+=1
    else:
        d.append(cont)
        cont=1

d.append(cont)

d.sort()

print(d[len(d)-1])