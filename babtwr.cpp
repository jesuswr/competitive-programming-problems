#include <iostream>

int n;
int coorX[2500], coorZ[2500], coorY[2500];
int dp[2502][2502];

int getMaxHeight(int x, int y){
    if (dp[x][y]!=-1){
        return dp[x][y];
    }
    else
    {
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            if (coorX[i]<x && coorY[i]<y) {
                max = std::max(max, getMaxHeight(coorX[i],coorY[i])+coorZ[i]);
            }
            if (coorY[i]<x && coorX[i]<y) {
                max = std::max(max, getMaxHeight(coorY[i],coorX[i])+coorZ[i]);
            }
            if (coorZ[i]<x && coorY[i]<y) {
                max = std::max(max, getMaxHeight(coorZ[i],coorY[i])+coorX[i]);
            }
            if (coorY[i]<x && coorZ[i]<y) {
                max = std::max(max, getMaxHeight(coorY[i],coorZ[i])+coorX[i]);
            }
            if (coorX[i]<x && coorZ[i]<y) {
                max = std::max(max, getMaxHeight(coorX[i],coorZ[i])+coorY[i]);
            }
            if (coorZ[i]<x && coorX[i]<y) {
                max = std::max(max, getMaxHeight(coorZ[i],coorX[i])+coorY[i]);                
            }
            
        }

        dp[x][y] = max;
        return dp[x][y];
        
    }
    
}


int main(){
    int ans;
    scanf("%d",&n);
    while( n ){

        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d",&coorX[i],&coorY[i],&coorZ[i]);
        }

        for(int i = 0; i <= 2501; i++)
        {
            for(int j = 0; j <= 2501; j++)
            {
                dp[i][j] = -1;
            }
            
        }
        
        ans = getMaxHeight(2501,2501);
        printf("%d\n",ans);
        
        
        
        scanf("%d",&n);
    }
}