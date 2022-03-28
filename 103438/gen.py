import random

N = 3000
print(N)
for i in range(N):
    print(random.randint(1,20), end =' ')
print()
for i in range(N-1):
    print(i+1,i+2)