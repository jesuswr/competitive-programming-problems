n=int(input())
d=[]

for i in range (0,n):
    a=input()
    a=a.split()
    A=[int(i) for i in a]
    d=d+A

pas,max=0,0

for i in range (0,n-1):
    pas=pas-d[2*i]
    pas=pas+d[2*i+1]

    if pas>max:
        max=pas
    else:
        pass

print(max)
