#include <iostream>

int main(){
    int N, n, pigMinW, pigMaxW;
    int weights[500];
    int values[500];
    int maxValue[10000];
    int aux;

    scanf("%d",&N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d",&pigMinW,&pigMaxW);

        scanf("%d",&n);

        for(int j = 0; j < n; j++)
        {
            scanf("%d %d",&values[j],&weights[j]);
        }

        for(int j = 0; j < 10000; j++)
        {
            maxValue[j]=-1;
        }

        maxValue[pigMinW]=0;

        aux = pigMinW;

        while (aux<pigMaxW){
            if (maxValue[aux]==-1){
                aux++;
            }
            else
            {
                for(int j = 0; j < n; j++)
                {
                    if (aux+weights[j]<=pigMaxW){
                        if (maxValue[aux+weights[j]]==-1) {
                            maxValue[aux+weights[j]] = maxValue[aux]+values[j];
                        }
                        else if(maxValue[aux+weights[j]]>maxValue[aux]+values[j]){
                            maxValue[aux+weights[j]]=maxValue[aux]+values[j];
                        }
                    }
                }
                aux++;
                
            }

        }

        if (maxValue[pigMaxW]==-1){
            printf("This is impossible.\n");
        }
        else{
            printf("The minimum amount of money in the piggy-bank is %d.\n",maxValue[pigMaxW]);
        }
        
        
        
        
    }
    
}