n=int(input())
a=input()
a=a.split()
a=[int(i) for i in a]
a.sort()
a=[str(i) for i in a]
print(" ".join(a))