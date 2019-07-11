n=int(input())
a=input()
A=0
D=0

for i in a:
    if i=="A":
        A+=1
    elif i=="D":
        D+=1

if A>D:
    print("Anton")
elif D>A:
    print("Danik")
elif A==D:
    print("Friendship")