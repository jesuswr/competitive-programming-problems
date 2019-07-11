a=input()
b=input()
cond=1

if len(a)==len(b):
    for i in range (0,len(a)):
        if a[i]!=b[len(a)-1-i]:
            cond=0
            break
else:
    cond=0

if cond==1:
    print("YES")
else:
    print("NO")