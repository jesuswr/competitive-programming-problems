n=int(input())
m=n
r=0
h=[]
while True:
    m+=1
    h=list(str(m))
    h.sort()
    r=1
    for i in range (0,3):
        if h[i]==h[i+1]:
            r=0
            break

    if r==1:
        print(m)
        break
        
        


