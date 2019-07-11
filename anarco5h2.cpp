#include <iostream>
#include <string>
#include <cstring>

using namespace std;


char number[30];
int ans;
int dp[26][300];
int len;

int solve(int pos,int prevSum){
    printf("ENTRO CON INDICE %d CON SUMA %d\n", pos, prevSum);
    if(pos==len)
      return 1;
      if(dp[pos][prevSum]!=-1)
        return dp[pos][prevSum];
        dp[pos][prevSum]=0;
        int c=0;
        int sum=0;
        
        for (int i = pos; i <len; i++){

             sum+=number[i]-'0';
             if(sum>=prevSum)
               c+=solve(i+1,sum);
        
    }
     return (dp[pos][prevSum]=c);
}



int main(){

    scanf("%s",number);
    int q = 0;
    while (number[0]!='b')
    {
        if(!(number[0]>='0' && number[0]<='9')) break;
        q++;
        int nose = int(number[0]) - 48;
        cout<<number<<endl;
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 300; ++j)
            {
                dp[i][j] = -1;
            }
        }
        len = strlen(number);

        int res = solve(0,0);
        printf("%d. %d\n",q, res);   
        scanf("%s",number);
    }

    
    
    
}