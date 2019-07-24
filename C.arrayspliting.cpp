#include <iostream>
#include <algorithm>


using namespace std;

int n, k;
int numbs[int(3e5+5)];
int diff[int(3e5+5)];



int main()
{
	scanf("%d %d", &n, &k);
	if (n==k) {printf("0\n") ; return 0;}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numbs[i]);
	}
	for (int i = 0; i < n-1; ++i)
	{
		diff[i] = numbs[i+1] - numbs[i];
	}
	sort(diff, diff+n-1, greater<int>());
	long long ans = 0;
	for (int i = k-1; i < n-1; ++i)
	{
		ans += diff[i];
	}
	printf("%lld\n", ans);
}
