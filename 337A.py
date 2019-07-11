p=input()
p=p.split()

n=int(p[0])
m=int(p[1])

l=input()
l=l.split()
l=[int(i) for i in l]
l.sort()

q=[]

for i in range (0,m-n+1):
    q.append(l[n+i-1]-l[i])

q.sort()

print(q[0])
