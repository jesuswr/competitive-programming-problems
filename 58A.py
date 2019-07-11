#Marico el que lo lea

a=input()
a=list(a)
cont=0

for i in range (0,len(a)):
    if cont==0:
        if a[i]=="h":
            cont+=1
        else:
            pass
    elif cont==1:
        if a[i]=="e":
            cont+=1
        else:
            pass
    elif cont==2 or cont==3:
        if a[i]=="l":
            cont+=1
        else:
            pass
    elif cont==4:
        if a[i]=="o":
            cont+=1
        else:
            pass

if cont==5:
    print("YES")
else:
    print("NO")
        
    