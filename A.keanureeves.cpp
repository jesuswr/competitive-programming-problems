#include <iostream>

using namespace std;

int numbs[101];

int main()
{
	int n;
	scanf("%d", &n);
	int zeros = 0, ones = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%1d", &numbs[i]);
		if ( numbs[i] ) ones++;
		else zeros++;
	}
	if (zeros!=ones)
	{
		printf("1\n");
		for (int i = 0; i < n; ++i)
		{
			printf("%d", numbs[i]);
		}
		printf("\n");
	}
	else
	{
		printf("2\n");
		printf("%d ", numbs[0]);
		for (int i = 1; i < n; ++i)
		{
			printf("%d",numbs[i] );
		}
		printf("\n");
	}
}
