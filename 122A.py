a=int(input())
cont=0
Print=0

for i in range (1,a+1):
    cont=0
    if a%i==0:
        b=list(str(i))

        for i in b:
            if i=="4" or i=="7":
                cont+=1
            else:
                pass
    
    if cont==len(b):
        Print=1
        break

if Print==1:
    print("YES")
else:
    print("NO")