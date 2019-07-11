n=int(input())
d=[input() for i in range (0,n)]
cont=1

for i in range (0,n-1):
    if d[i]!=d[i+1]:
        cont+=1

print(cont)
        