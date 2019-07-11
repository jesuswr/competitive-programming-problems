#include <iostream>

int items,money;
int itemType[101],itemPrice[101],itemQuality[101];
int checkTypes[7] = {0,0,0,0,0,0,0};
int cond = 1;
int dp[7][1101];

int getMaxQ(int it, int mon){
    if (dp[it][mon]!=-1 && it>=0 && mon>=0){
        
        return dp[it][mon];
    }
    else{
        if (mon<=0 && it>0){
            
            return 0;
        }
        else if(mon<0){
            
            return 0;
        }
        else if(it==0){
            
            return 999999999;
        }
        else{
            
            int min = -99999999;
            int min2 = 0;
            for(int i = 1; i <= items; i++)
            {
                if (itemType[i]==it){
                    
                    min2 = std::min(itemQuality[i],getMaxQ(it-1,mon-itemPrice[i]));
                    min = std::max(min2,min);
                }
            }
            dp[it][mon] = min;
            
            return dp[it][mon];
            
        }
    }
}

int main(){
    
    scanf("%d %d",&items,&money);
    
    for(int i = 1; i <= items; i++)
    {
        
        scanf("%d %d %d",&itemType[i],&itemPrice[i],&itemQuality[i]);

        if (itemType[i]>0 && itemType[i]<7){
            checkTypes[itemType[i]] = 1;
        }
    }

    for(int i = 1; i < 7; i++)
    {
        if (checkTypes[i]==0){
            cond = 0;
            break;
        }
    }
    
    if (cond==1){
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j <= money; j++)
            {
                dp[i][j] = -1;
            }
            
        }

        int ans = getMaxQ(6,money);
        printf("%d\n",ans);
        

    }
    else{
        printf("0\n");
    }
}