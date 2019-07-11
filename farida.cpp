#include <iostream>

long maxLong(long a, long b){
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    long coins[10000];
    int n,N;
    long a,b;
    long aux;
    scanf("%d",&N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d",&n);
        

        for(int j = 0; j < n; j++)
        {
            scanf("%ld",&coins[j]);
        }

        if (n==0) {
            printf("Case %d: 0\n",i);
        }
        else if(n==1){
            printf("Case %d: %ld\n",i,coins[0]);
        }
        else{
            a = coins[0];
            b = maxLong(coins[0],coins[1]);

            for(int j = 2; j < n; j++)
            {
                if (b>a+coins[j]) {
                    a=b;
                }
                else{
                    aux = a;
                    a = b;
                    b = aux + coins[j];
                }
            }

            printf("Case %d: %ld\n",i,b);
            


        }
        
        
        

    }
    

    

    return 0;
}