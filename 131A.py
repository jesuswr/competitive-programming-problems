a=input()
cont=0
cont3=0
cont1=0

if a==a.upper():
    cont=1

a=list(a)


if cont==0:
    if a[0]==a[0].lower():
        for i in range (1,len(a)):
            if a[i]==a[i].upper():
                cont1+=1
            else:
                cont1=-3
                break


if cont1==len(a)-1:
    cont=1


if cont==1:
    
    for i in range (0,len(a)):
        if a[i]==a[i].upper():
            a[i]=a[i].lower()
        else:
            a[i]=a[i].upper()
    

a="".join(a)

print(a)