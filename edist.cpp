#include <iostream>
#include <string>

std::string A,B;
int n,nA,nB,ans;
int dp[2001][2001];


int min3(int a, int b, int c){
    if (a<=b && a<=c){
        return a;
    }
    else if(b<=a && b<=c){
        return b;
    }
    else if(c<=a && c<=b){
        return c;
    }
}


int getMin(int a, int b){
    
    if (dp[a][b]!=-1)
    {
        return dp[a][b];
    }
    else
    {
        if (a==nA && b==nB){
            return 0;
        }
        else if (a==nA)
        {
            dp[a][b] = 1+getMin(a,b+1);
            return dp[a][b];
        }
        else if (b==nB)
        {
            dp[a][b] = 1+getMin(a+1,b);
            return dp[a][b];
        }

        if (A[a]==B[b]){
            dp[a][b] = getMin(a+1,b+1);
            return dp[a][b];
        }
        else
        {
            dp[a][b]= 1 + min3( getMin( a+1 , b ) , getMin( a+1 , b+1 ) , getMin( a , b+1 ) );
            return dp[a][b];
        }
    }
}





int main(){

    scanf("%d",&n);

    for (int ii = 0; ii < n; ii++)
    {
        std::cin>>A;
        std::cin>>B;
        nA = A.length();
        nB = B.length();
        
        for (int i = 0; i <= nA; i++)
        {
            for (int j = 0; j <= nB; j++){
                dp[i][j] = -1;
            }
        }
        
        
        ans = getMin(0,0);
        printf("%d\n",ans);

    }
    
    return 0;
}