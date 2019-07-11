n=int(input())

L=[input() for i in range (0,n)]

o=True
m=0

for i in L:

    for j in range (0,3):
        if i[j]=="+":
            o=True
            break
        elif i[j]=="-":
            o=False
            break
        else:
            pass

    if o==True:
        m+=1
    elif o==False:
        m-=1

print(m)