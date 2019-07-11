#include <iostream>

int values[2001];
int bestProfit[2001][2001];

int profit(int year, int start, int end){

    if (bestProfit[start][end]==-1){
        if (start>end){
            return bestProfit[start][end]=0;
        }
        else{
            return  (bestProfit[start][end]=std::max(profit(year+1,start+1,end)+year*values[start],
                            profit(year+1,start,end-1)+year*values[end]));
        }
    }
    else{
        return bestProfit[start][end];
    }
}

int main(){
    int N;
    

    scanf("%d",&N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d",&values[i]);

        for(int j = 0; j < N; j++)
        {
            bestProfit[i][j]=-1;
        }
        
    }

    int answer = profit(1,0,N-1);
    printf("%d\n",answer);
    
    

}