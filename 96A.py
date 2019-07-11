a=input()

a=list(a)

d=[int(i) for i in a]
c=d[0]
e=0
f="NO"

for i in d:
    if c==i:
        e+=1
    else:
        e=1
        c=i
    
    if e>6:
        f="YES"
        break

print(f)

