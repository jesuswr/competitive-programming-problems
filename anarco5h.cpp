#include <iostream>
#include <string>
#include <cstring>

using namespace std;


char number[30];
int ans;
int dp[26][300];

int getMax(int s, int leftsum, int end)
{
    //printf("ENTRO CON INDICE %d CON SUMA %d\n", s, leftsum);
    if (s == end) return 1;
    if (dp[s][leftsum] != -1) return dp[s][leftsum];

    dp[s][leftsum] = 0;
    int sum = 0;
    int c = 0;
    for (int i = s; i < end; i++)
    {
        sum += number[i] - '0';

        if (sum>=leftsum) c += getMax(i+1,sum,end);
    }
    return dp[s][leftsum]=c;
}




int main(){

    scanf("%s",number);
    int q = 0;
    while (number[0]!='b')
    {
        if(!(number[0]>='0' && number[0]<='9')) break;
        q++;
        int nose = int(number[0]) - 48;
        //cout<<number<<endl;
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 300; ++j)
            {
                dp[i][j] = -1;
            }
        }
        int l = strlen(number);

        int res = getMax(0,0,l);
        printf("%d. %d\n",q, res);   
        scanf("%s",number);
    }

    
    
    
}