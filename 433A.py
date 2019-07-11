a=input()
a=set(a)

a=[i for i in a if i!="{" and i!="," and i!=" " and i!="}"]

print(len(a))