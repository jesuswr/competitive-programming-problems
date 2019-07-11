#include <iostream>

int n;
int weights[200];

int getMin(int ind, int groups[]){
    if (ind!=n){
        
        int min;

        groups[ind]=1;

        min = getMin(ind+1,groups);

        groups[ind]=2;

        min = std::min(min,getMin(ind+1,groups));

        return min;
    }
    else
    {
        int cond1 = 0;
        int cond2 = 0;
        for(int i = 0; i < ind; i++)
        {
            if (groups[i]==1) {
                cond1++;
            }
            if (groups[i]==2) {
                cond2++;
            }
        }

        if (cond1==cond2 || cond1 == cond2 +1 || cond1+1==cond2){
            cond1 = 0;
            cond2 = 0;
            
            for(int i = 0; i < ind; i++)
            {
                if (groups[i]==1) {
                    cond1 = cond1 + weights[i];
                }
                if (groups[i]==2) {
                    cond2 = cond2 + weights[i];
                }
                
            }
            
            int ans;
            if (cond1>cond2) {
                ans = cond1 - cond2;
            }
            else{
                ans = cond2 - cond1;
            }
            
            
            return ans;
        }
        else
        {
            return 999999;
        }
        
        
    }
    
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&weights[i]);
    }
   
    int nose[200];
    for(int i = 0; i < n; i++)
    {
        nose[i] = 0;
    }
    
    int ans = getMin(0,nose);
    printf("%d\n",ans);
    
}