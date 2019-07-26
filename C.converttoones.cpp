#include <iostream>

using namespace std;

int main()
{
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	int aux, last, zeros=0, ones=0;
	last = -1;
	for (int i = 0; i < n; ++i)
	{
		scanf("%1d", &aux);
		
		if (aux==last) {last = aux; continue;}
		if (aux) ones++;
		if (!aux) zeros++;
		last = aux;
	}
	if (zeros==0)
	{
		printf("0\n");
		return 0;
	}
	if (zeros==1)
	{
		printf("%d\n",y);
		return 0;
	}
	long long ans = (long long)(zeros-1)*min(x,y);
	ans += y;
	printf("%lld\n", ans);
}
