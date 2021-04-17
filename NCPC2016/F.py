from math import factorial


inp = input()
inp = [int(s) for s in inp.split(' ')]
n = inp[0]
p = inp[1]

curr = p / (n+1)
ans = curr 

for c in range(2,n+1):
    curr = curr * (c / (c-1)) * ((n - p + c)/(n+c))
    if ans > curr:
        break
    ans = max(ans, curr)

print(ans)