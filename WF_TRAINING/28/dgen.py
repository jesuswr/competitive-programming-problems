import random

s = 'se'

N = 1000000

print(N)
for i in range(N):
	print(f'{s[random.randint(0,1)]}{random.randint(1,N)}')

