a=input()
may=0
min=0

for i in a:
    if i==i.lower():
        min+=1
    else:
        may+=1

if min>=may:
    print(a.lower())
else:
    print(a.upper())