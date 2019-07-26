#include <iostream>

using namespace std;

const int maxN = 1e5;

int numbs[maxN+5];

int main()
{
	int n;
	scanf("%d", &n);
	numbs[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &numbs[i]);
		numbs[i] += numbs[i-1];
	}
	
	int m;
	scanf("%d", &m);
	int aux1, aux2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &aux1, &aux2);
		int ans = numbs[aux2]-numbs[aux1-1];
		ans /= 10;
		printf("%d\n", ans);
	}
}
