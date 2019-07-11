#include <iostream>

int items,money;
int itemType[101],itemPrice[101],itemQuality[101];
int dp[7][101][1001]; // item|index|price


int main(){

    scanf("%d %d",&items,&money);

    for(int i = 1; i <= items; i++)
    {
        scanf("%d %d %d",&itemType[i],&itemPrice[i],&itemQuality[i]);
    }

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            for(int k = 0; k < 1001; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }

    //  ##        ##    ############           ############   ###########           
    //  ####      ##    ############           ############   ###########        
    //  ## ##     ##    ##        ##           ###            ## 
    //  ##  ##    ##    ##        ##           ############   #####        
    //  ##   ##   ##    ##        ##           ############   #####         
    //  ##    ##  ##    ##        ##                    ###   ## 
    //  ##     ## ##    ##        ##                    ###   ##  
    //  ##      ####    ############           ############   ###########  ###       
    //  ##        ##    ############           ############   ###########  ###       
}