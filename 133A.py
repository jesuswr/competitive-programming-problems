a=input()
a=list(a)
h=0

for i in a:
    if i=="H" or i=="Q" or i=="9":
        h=1
        break
    else:
        pass    

if h==1:
    print("YES")
else:
    print("NO")