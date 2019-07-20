#include <iostream>
#include <unordered_map>


using namespace std;

bool checkD(int a, int b, int c)
{
	if (a+b>c && a+c>b && b+c>a) return true;
	return false;
}



int main()
{
	int n;
	scanf("%d", &n);
	int n1, n2, n3;
	long long ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			n1 = i^j;
			
			if (n1>0 && n1<=n)
			{
				n2=0;
				if (i+j<=n1)
				{
					n2++;
				}
				else if (i+n1<=j)
				{
					n2++;
				}
				else if (n1+j<=i)
				{
					n2++;
				}
				if (n2<=0)
				{
					ans++;
				}
			}
			
		}
	}
	ans = ans/6;
	printf("%lld\n", ans);
}
