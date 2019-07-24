#include <iostream>
#include <vector>


using namespace std;
int n,q;
int currentS;
vector<long long> soldiers;
long long arrows[200001];



int main()
{
	scanf("%d %d", &n, &q);
	long long aux = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i==0)
		{
			scanf("%lld", &aux);
			soldiers.push_back(aux);
		}
		else
		{
			scanf("%lld", &aux);
			soldiers.push_back(aux);
			soldiers[i] += soldiers[i-1];
		}
	}
	for (int i = 0; i < q; ++i)
	{
		scanf("%lld", &arrows[i]);
	}
	long long currentA = 0;
	int currentI = 0;
	currentS = soldiers[0];
	for (int i = 0; i < q; ++i)
	{
		currentA += arrows[i];
		auto it = lower_bound( soldiers.begin(), soldiers.end() , currentA);
		if (it == soldiers.end())
		{
			currentA = 0;
			printf("%d\n", n);
		}
		else
		{
			int ans = soldiers.end() - it;
			long long nose = *it;
			if ( nose == currentA )
			{
				ans--;
			}
			if (ans == 0)
			{
				currentA = 0;
				printf("%d\n", n);
				continue;
			}
			printf("%d\n", ans);
		}

	}
}
