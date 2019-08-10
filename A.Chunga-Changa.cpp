#include <iostream>

using namespace std;

int main()
{
	long long x,y,z;
	scanf("%lld %lld %lld", &x, &y, &z);
	long long ans = (x+y)/z;
	printf("%lld ", ans);
	if ((x%z)+(y%z)>=z)
	{
		ans = min(z - x%z, z - y%z);
		printf("%lld\n", ans);
	}
	else printf("0\n");
	return 0;
}
