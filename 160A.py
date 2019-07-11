a=int(input())
monedas=input()
monedas=monedas.split()
monedas=[int(i) for i in monedas]
monedas.sort(reverse=True)
dintot=0
dintom=0
nummon=0

for i in monedas:
    dintot+=i

for i in monedas:
    if dintot>=dintom:
        dintom+=i
        dintot-=i
        nummon+=1
    else:
        break

print(nummon)