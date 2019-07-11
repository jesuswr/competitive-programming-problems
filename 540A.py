n=int(input())
a=[]
if n>=26:
    a=input()
    a=a.lower()
    a=set(a)
    
if len(a)==26:
    print("YES")
else:
    print("NO")
