#include <iostream>

using namespace std;

const int maxN = 1e5 + 1;

int numbs[maxN];
int deq[maxN];
int mx[maxN];

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numbs[i]);
	}
	int ax = -1;
	for (int i = 0; i < n; ++i)
	{
		mx[i] = max( numbs[i], ax );
		ax = mx[i];
	}
	ax = numbs[0];
	for (int i = 0; i < n-1; ++i)
	{
		deq[i] = min( ax, numbs[i+1] );
		ax = max( ax, numbs[i+1] );
	}
	long long query;

	for (int i = 0; i < q; ++i)
	{
		scanf("%lld", &query);
		if (query > n-1)
		{
			query--;
			query = query%(n-1);
			printf("%d %d\n", mx[n-1], deq[query]);
		}
		else
		{
			printf("%d %d\n", mx[query-1], numbs[query]);
		}
	}
}
