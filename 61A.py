a=input()
b=input()
d=[]

for i in range (0,len(a)):
    if a[i]==b[i]:
        d.append("0")
    else:
        d.append("1")

d="".join(d)

print(d)