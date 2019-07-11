a=input()
a=list(a)
cond=0

for i in a:
    if i=="4" or i=="7":
        cond+=1
    else:
        pass

if cond==4 or cond==7:
    print("YES")
else:
    print("NO")