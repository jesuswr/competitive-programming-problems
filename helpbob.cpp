#include <iostream>
#include <vector>
#include <set>


using namespace std;

struct status
{
	int mask;
	double price;
};

const int INF = 0x7fffffff;
const int maxN = 1<<15;
int n;
int price[15], area[15], nDiscounts[15];
vector<pair<int,int>> disc[15];
double ANS;
double dp[maxN];

int sumA(int mask)
{
	int aux = 0;
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1<<i))
		{
			aux += area[i];	
		}
	}
	return aux;
}



double getMin(int mask)
{
	if (dp[mask] != -1) return dp[mask];
	if (mask==0) return 0;

	double aux = 1e9;
	double p;
	for (int i = 0; i < n; ++i)
	{
		
		if ( mask & (1<<i) )
		{
			
			p = price[i];
			for (auto pii:disc[i])
			{
				if (mask & (1<<pii.first))
				{
					p = p*(double)(100-pii.second)/100;
				}
			}
			
			aux = min( aux , p + getMin(mask - (1<<i)));	
		}
	}
	dp[mask] = aux;
	ANS = min (ANS, (double)dp[mask]/sumA(mask));
	
	return dp[mask];
}






int main()
{
	scanf("%d", &n);
	int n1,n2;
	int sumA;
	while(n!=0) 
	{
		sumA = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d %d", &price[i], &area[i], &nDiscounts[i]);
			sumA += area[i];
			while (nDiscounts[i]--)
			{
				scanf("%d %d", &n1, &n2);
					
				disc[n1-1].push_back({i,n2});
			}
		}

		for (int i = 0; i < 1<<n; ++i) dp[i] = -1;
		dp[0] = 0;
		ANS = 1e9;
		double ans = getMin((1<<n) -1);
		printf("%.4lf\n", ANS);
		
		for (int i = 0; i < n; ++i) disc[i].clear();

		scanf("%d", &n);
	}
}
