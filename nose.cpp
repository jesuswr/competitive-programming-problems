#include <iostream>

using namespace std;
int k, n, b, a;
int dp[1000000001];


int getMax(int ind, int life){
	if (dp[ind]!=-1000000001){
		return dp[ind];
	}
	if (life<=0){
		return -1;
	}
	if (ind == n){
		return 0;
	}
	dp[ind] = max(getMax(ind + 1, life - b),getMax(ind+1,life+b)+1);
	return dp[ind];
}


int main(){
	int q;
	scanf("%d",&q);
	
	for (int p = 0; p < q; p++)
	{
		//scanf("%d %d %d %d",&k,&n,&a,&b);
		for (int i = 0; i < n; i++)
		{
			dp[i] = 1000000001;
		}

		//printf("%d\n",getMax(0,k));
	}
	return 0;
}