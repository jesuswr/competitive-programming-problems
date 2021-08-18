s = input().split()

n = int(s[0])
k = int(s[1])

n = n * 10**(2*k)

lo = 0 
hi = n

while(lo < hi):
    mi = lo + (hi-lo+1)//2
    if (mi*mi <= n):
        lo = mi
    else:
        hi = mi-1

print(lo//(10**k), end = '')

dec = str(lo % (10 ** k))
while(len(dec) < k):
    dec = '0' + dec
dec = '.' + dec
print(dec)