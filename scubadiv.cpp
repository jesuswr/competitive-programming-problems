#include <iostream>

int oxy[1000],nit[1000],weight[1000];
int minWei[100][200];
int c,n,neededOxy,neededNit,minWeight;

void setMinimuns(int x, int y){

    for(int i = 0; i < n; i++)
    {   
        if(x + oxy[i]<=neededOxy+21 && y + nit[i] <= neededNit+79){
            if (minWei[ x + oxy[i] ][ y + nit[i] ]==-1){
                minWei[ x + oxy[i] ][ y + nit[i] ] = weight[i];
            }
            else if( minWei[ x + oxy[i] ][ y + nit[i] ] > minWei[x][y]+weight[i] ){
                minWei[ x + oxy[i] ][ y + nit[i] ] = minWei[x][y]+weight[i];
            }
            setMinimuns(x+oxy[i],y+nit[i]);
        }
    }
}

void print(){
    for(int i = neededOxy-1; i <= neededOxy+21; i++)
    {
        for(int j = neededNit-1; j <= neededNit+79; j++)
        {
            if(minWei[i][j]==249){
                printf("%d ",minWei[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){

    scanf("%d",&c);

    for(int h = 0; h < c; h++)
    {
        scanf("%d %d",&neededOxy,&neededNit);
        scanf("%d",&n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d",&oxy[i],&nit[i],&weight[i]);
        }

        for(int i = 1; i <= neededOxy+21; i++)
        {
            for(int j = 1; j <= neededNit+79; j++)
            {
                minWei[i][j]=-1;
            }
        }

        minWei[0][0]=0;

        setMinimuns(0,0);
        print();

        
        
    }
    
    
    
}