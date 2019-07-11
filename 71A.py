n=int(input())
A=[input() for i in range (0,n)]


for i in A:
    if len(i)<=10:
        print(i)
    elif len(i)>10:
        print(i[0] + str(len(i)-2) + i[len(i)-1])