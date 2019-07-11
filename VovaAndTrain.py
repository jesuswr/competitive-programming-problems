n=int(input())
A=[]
cont=0
for i in range(n):
    a=list(map(int,input().split()))
    A+=a
    

for i in range(0,n):
    
    cont=0
    cont+=A[4*i]//A[4*i+1]
    
    cont-= ( ((A[4*i+3])//A[4*i+1])-((A[4*i+2]-1)//A[4*i+1]))
    

    print(cont)