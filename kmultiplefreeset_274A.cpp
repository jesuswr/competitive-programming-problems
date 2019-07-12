#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


unordered_map<long long, int> mp;
int numbs[100002];

int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&numbs[i]);
	}
	sort(numbs, numbs + n);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if ( numbs[i] % k != 0 ) {mp[numbs[i]] = 1;ans++;}
		else
		{
			if (mp[numbs[i]/k]!=1) {mp[numbs[i]] = 1;ans++;}
		}
	}
	printf("%d\n", ans);
}