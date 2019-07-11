a=input()
a=a.split()
n=int(a[0])
t=int(a[1])

fila=input()
fila=list(fila)


while t>0:
    camb=[]
    for i in range (0,n-1):
        if fila[i]=="B" and fila[i+1]=="G":
            camb.append(i)


    for i in camb:
        
        fila[i]="G"
        fila[i+1]="B"

    t-=1

print("".join(fila))
