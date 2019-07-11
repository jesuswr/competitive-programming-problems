#include <iostream>

int maxCoins[100][100];

int max3(int a, int b, int c){
    if (a>=b && a>=c){
        return a;
    }
    else if(b>=a && b>=c){
        return b;
    }
    else if(c>=a && c>=b){
        return c;
    }
}

int maxPosCoins(int row, int column){
    
    for(int i = 1; i < row; i++)
    {
        for (int j = 0; j<column;j++){
            if (j==0){
                maxCoins[i][j] += std::max(maxCoins[i-1][j],maxCoins[i-1][j+1]);
            }
            else if(j==column-1){
                maxCoins[i][j] += std::max(maxCoins[i-1][j],maxCoins[i-1][j-1]);
            }
            else{
                maxCoins[i][j] += max3(maxCoins[i-1][j],maxCoins[i-1][j-1],maxCoins[i-1][j+1]);
            }
        }
    }

    int ans =0;
    
    for(int i = 0; i < column; i++)
    {
        if (maxCoins[row-1][i]>ans){
            ans = maxCoins[row-1][i];
        }
    }

    return ans;
    
    


}

int main(){

    int N;
    int rows, columns;
    int ans;
    scanf("%d",&N);
    

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d",&rows,&columns);

        for(int j = 0; j < rows; j++)
        {
            for(int k = 0; k < columns; k++)
            {
                scanf("%d",&maxCoins[j][k]);
                
            }
        }

        if (columns>1){
            ans = maxPosCoins(rows,columns);
            printf("%d\n",ans);
        }
        else{
            ans=0;
            for (int j = 0; j < rows; j++)
            {
                ans += maxCoins[j][columns-1];
                
            }
            printf("%d\n",ans);
            
        }
    }
}