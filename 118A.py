a=input()
a=a.lower()

lista=["o","e","i","a","u","y"]

a=[a[i] for i in range (0,len(a))]

z=0
o=[]
l=[]

for i in a:
    
    t=True
    
    for j in lista:
        if i==j:
            t=False
        else:
            pass

    if t==True:
        o+=[i]
  
for i in o:
    l+=["."]
    l+=[i]

w=''.join(l)

print(w)