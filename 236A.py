a=input()

a=list(a)

a.sort()

d="="
cont=0

for i in range (0,len(a)):
    if a[i]==d:
        pass
    else:
        d=a[i]
        cont+=1

if cont%2==0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")