n=int(input())
a=input()
a=a.split()
m=[int(i) for i in a]
k=[]


for i in range (0,len(m)):
    if m[i]%2==0:
        k=k+[m[i]-1]
    else:
        k=k+[m[i]]

o=[str(i) for i in k]

l=" ".join(o)
        
print(l)