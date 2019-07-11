#include <iostream>

int parentes[11]={0,1,1,1,2,2,3,3,4,4,5};

void printThatShit(int v, int w){
    if (w!=v){
        printThatShit(v, parentes[w]);
    }
    printf("%d ",w);
}

void printThat(int v){
    for (int i = 1; i < 11; i++)
    {
        if (i!=v){
            printThatShit(v,i);
        }
        printf("\n");
    }
}

///////////////////////////////////////////////
int visited[4], matrix[4][4];
int count;

void dfs(int v, int w){

    visited[v] = 1;

    for (int i = 0; i < 4; i++)
    {
        if (visited[i] == 0 && matrix[v][i]==1){
            dfs(i,w);
        }
    }
    
    visited[v] = 0;

    if (v==w){
        count++;
    }

}


///////////////////////////////////////////////

int main(){
    for (int i = 0; i < 4; i++)
    {
        for (int ii = 0; ii < 4; ii++)
        {
            matrix[i][ii] = 0;
        }
        visited[i] = 0;
    }
    int v =2;
    int w = 3;
    
    int n;
    scanf("%d",&n);
    int x,y;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        matrix[x][y] =1;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int ii = 0; ii < 4; ii++)
        {
            printf("%d ",matrix[i][ii]);
        }
        printf("\n");
    }
    
    count = 0;
    
    dfs (v,w);
    
    printf("%d\n",count);
}