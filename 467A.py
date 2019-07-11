n=int(input())
d=[]
D=[]

for i in range (0,n):
    d=input()
    d=d.split()
    d=[int(i) for i in d]
    D+=d

numcu=sum(1 for i in range (0,n) if D[2*i+1]-D[2*i]>1 )

print(numcu)