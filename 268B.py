n=int(input())

Sum=n

for i in range (1,n):
    Sum+=i*(n-i)

print(Sum)