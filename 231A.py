numerodeproblemas=int(input())

L=[input() for i in range (0,numerodeproblemas)]

h=0

for i in range (0,numerodeproblemas):
    if int(L[i][0])+int(L[i][2])+int(L[i][4])>1:
        h+=1
    else:
        pass

print(h)

