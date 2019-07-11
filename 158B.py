#Marico el que lo lea

n=int(input())
l=input()
l=l.split()
L=[int(i) for i in l]

cont1,cont2,cont3,cont4=0,0,0,0
contp=0

for i in L:
    if i==1:
        cont1+=1
    elif i==2:
        cont2+=1
    elif i==3:
        cont3+=1
    elif i==4:
        cont4+=1

contp=cont4
cont4=0

contp+=cont2//2
cont2=cont2%2

if cont2==1:
    if cont1==0:
        contp+=1
        cont2-=1
    elif cont1==1:
        contp+=1
        cont1-=1
        cont2-=1
    elif cont1>1:
        contp+=1
        cont1-=2
        cont2-=1

while True:
    if cont3>0:
        if cont1>0:
            contp+=1
            cont3-=1
            cont1-=1
        elif cont1==0:
            contp+=1
            cont3-=1
    elif cont3==0:
        break

contp+=cont1//4

cont1=cont1%4

if cont1!=0:
    contp+=1

print(contp)