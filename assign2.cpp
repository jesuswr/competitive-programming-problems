#include <iostream>

int stuPref[20][20];
int n;
unsigned long long int count;
unsigned long long int dp [10485767];
long int maxMasc;

unsigned long long int getCount(int stud, int m){

    if (dp[m]!=-1){
        return dp[m];
    }
    else
    {
        if (stud == n && m ==maxMasc){
            dp[m] = 1;
        }
        else
        {
            unsigned long long int count2=0;
            for(int i = 0; i < n; i++)
            {
                if (stuPref[stud][i]==1 && !(m & (1 <<i))) {
                    
                    count2 += getCount(stud+1,(m | (1 <<i)));

                }
                
            }
            dp[m] = count2;
        }
        return dp[m];


    }
    


}







int main(){
    int c;
    
    scanf("%d",&c); 

    for(int ii = 0; ii < c; ii++)
    {
        scanf("%d",&n);

        count = 0;
        maxMasc = 1;

        for(int i = 0; i < n; i++)
        {
            for (int j=0; j<n; j++)
            {
                scanf("%d",&stuPref[i][j]);
            }
            maxMasc = maxMasc*2;
            
        }
        maxMasc = maxMasc -1;
        
        for(int i = 0; i < 1048577; i++)
        {
            dp[i] = -1;
        }
    
        count = getCount(0,0);

        printf("%llu\n",count);
  
    }
}