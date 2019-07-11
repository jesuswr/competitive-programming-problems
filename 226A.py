n=int(input())
a=input()
b=a[0]
cambios=0

for i in range (1,len(a)):
    if a[i]==b:
        cambios+=1
    else:
        b=a[i]

print(cambios)
