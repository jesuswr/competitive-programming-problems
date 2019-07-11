n=int(input())
a=input()
a=a.split()
a=[int(i) for i in a]
par=0
imp=0

for i in a:
    if par<2 and imp<2:
        if i%2==0:
            par+=1
        else:
            imp+=1

    else:
        break

for i in range (0,n):
    if par==2:
        if a[i]%2!=0:
            print(i+1)
            break
    if imp==2:
        if a[i]%2==0:
            print(i+1)
            break