n=int(input())
d=[]
for i in range (0,n):
    a=input()
    a=a.split()
    d+=[int(i) for i in a]
locales=[d[i] for i in range (0,2*n) if i%2==0]
visitantes=[d[i] for i in range (1,2*n) if i%2!=0]
p=0

for i in locales:
    for j in visitantes:
        if i==j:
            p+=1

print(p)