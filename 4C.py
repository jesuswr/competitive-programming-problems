n=int(input())

store={}
ans=[]
for i in range (0,n):
    x=input()
    count=0
    if x not in store.keys():  
        store[x]=count+1
        ans.append('OK')
    else:
        store[x]+=1
        temp= x+ str(store[x]-1)
        ans.append(temp)

for j in range (0,len(ans)):
    print(ans[j])