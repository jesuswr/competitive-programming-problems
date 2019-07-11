#include <iostream>

using namespace std;


int n;
int mixtures[101];
long long dp[101][101];

const long long maxLL = 9223372036854775807;

int mix(int s, int e)
{
    int ret = 0;
    for (int i = s; i <= e; ++i)
    {
        ret = ret + mixtures[i];
        ret = ret%100;
    }
    return ret;
}

long long getMin(int s, int e)
{
    if (s == e) return 0;
    if (dp[s][e]!=-1) return dp[s][e];

    long long ans = 9223372036854775807;
    for (int i = s; i < e; ++i)
    {
        ans = min(ans, getMin(s,i)+getMin(i+1,e)+mix(s,i)*mix(i+1,e));
    }
    return dp[s][e] = ans;
}




int main(){
    int ans;
    while (scanf("%d",&n)==1){
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&mixtures[i]);
        }

        for(int i = 0; i < n; i++)
        {
            for(int ii = 0; ii < n; ii++)
            {
                dp[i][ii] = -1;
            }
            
        }

        ans = getMin(0,n-1);
        
        printf("%d\n",ans);
        
        
    }
}