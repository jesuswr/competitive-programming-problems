import random


t = 1
print(t)


for iiii in range(t):
    n = 100000
    m = 100000

    print(n, m)
    
    for i in range(n):
        print(random.randint(1,n), end=' ')

    print()
    for i in range(m):
        print(random.randint(1,n), random.randint(1,n))