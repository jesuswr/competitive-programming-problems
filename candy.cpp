#include <iostream>

int main(){
    int n,count,ans;
    scanf("%d",&n);

    while(n!=-1){
        count = 0;
        ans = 0;
        int candy[n];

        for(int i = 0; i < n; i++)
        {
            scanf("%d",&candy[i]);
            count = count + candy[i];
            
        }
        
        if (count%n!=0){
            printf("-1\n");
        }
        else{
            
            count = count/n;
            for(int i = 0; i < n; i++)
                {
                    if (candy[i]>count){
                        ans = ans + candy[i]-count;
                    
                    }
            }
            printf("%d\n",ans);
        }
        

        scanf("%d",&n);
    }
}