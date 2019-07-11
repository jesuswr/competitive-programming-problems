n=int(input())

#resp=0

#resp=sum(((-1)**i)*i for i in range (1,n+1))

'''for i in range(1,n+1):
    if i%2!=0:
        resp+=-i
    else:
        resp+=i'''

if n%2==0:
    print(int(n/2))
else:
    print(int(-(n//2 +1)))


