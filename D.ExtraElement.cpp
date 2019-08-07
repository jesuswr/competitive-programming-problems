#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

pair<long long, int> numbs[2*(int)1e5+5];
long long diff[2*(int)1e5+5];


int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &numbs[i].first);
		numbs[i].second = i;
	}
	if (n<=3) {printf("1\n"); return 0;}
	sort(numbs, numbs + n);
	for (int i = 1; i < n-1; ++i)
	{
		diff[i] = numbs[i+1].first - numbs[i].first;
	}
	bool ans = true;
	for (int i = 1; i < n-2; ++i)
	{
		
		if (diff[i] != diff[i+1]) {ans = false; break;}
	}
	if (ans)
	{
		printf("%d\n", numbs[0].second+1);
		return 0;
	}
	diff[1] = numbs[2].first- numbs[0].first;
	for (int i = 3; i < n; ++i)
	{
		diff[i-1] = numbs[i].first - numbs[i-1].first;
	}
	ans = true;
	for (int i = 2; i < n-1; ++i)
	{
		if (diff[i] != diff[i-1]) {ans = false; break;}
	}
	if (ans) {printf("%d\n", numbs[1].second +1);return 0;}
	long long di = numbs[1].first - numbs[0].first;
	int ind = -1;
	for (int i = 2; i < n; ++i)
	{
		if (numbs[i].first-numbs[i-1].first != di)
		{
			if (i==n-1)
			{
				//printf("entroo con %d\n",i );
				if (ind != -1)
				{
					//printf("-1aaaaa\n");
					return 0;
				}
				else
				{
					printf("%d\n", numbs[n-1].second+1);
					return 0;
				}
			}
			else
			{
				//printf("entroa con %d\n",i );
				if (ind != -1)
				{
					
					printf("-1\n");
					return 0;
					
				}
				else
				{
					//printf("%lld %lld %lld\n", numbs[i+1].first, numbs[i].first, di);
					if (numbs[i+1].first-numbs[i-1].first == di)
					{
						ind = i;
						i++;
					}
					else
					{
						printf("-1\n");
						return 0;

					}
				}
			}
		}
	}
	printf("%d\n", numbs[ind].second+1);
}
