N = 100
M = (N * (N-1)) // 2
print(N,M)
for i in range(N):
    for j in range(N-i-1):
        print(i+1, i+j+2)