#include <iostream>

using namespace std;

int main()
{
	long long n, m;
	scanf("%lld %lld", &n, &m);
	if (m>=43) {printf("No\n");return 0;}
	bool cond = true;
	for (int i = 2; i <= m; ++i)
	{
		if ((n+1)%i==0) continue;
		cond = false;
		break;
	}
	if (cond) printf("Yes\n");
	else printf("No\n");
}
