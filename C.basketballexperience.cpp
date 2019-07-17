#include <iostream>


using namespace std;

const int maxN = 1e5+1;
int n;
int row1[maxN];
int row2[maxN];
long long dp[2][maxN];

long long getMax(int team, int index)
{
	if (index>=n) {return 0;}
	if (dp[team][index]!=-1)
	{
		return dp[team][index];
	}
	long long aux;
	if (team==0)
	{
		aux = (long long)row1[index];
		dp[team][index] = aux + max(getMax(1-team, index+1), getMax(1-team, index+2));
	}
	else
	{
		aux = (long long)row2[index];
		dp[team][index] = aux + max(getMax(1-team, index+1), getMax(1-team, index+2));
	}
	return dp[team][index];

}



int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &row1[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &row2[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		dp[0][i] = -1;
		dp[1][i] = -1;
	}
	long long ans = max ( getMax(0,0), getMax(1,0));
	
	printf("%lld\n", ans);
}
