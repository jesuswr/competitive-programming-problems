#include <iostream>

using namespace std;

int numbs[int(1e5)+5];

int main()
{
	int n;
	scanf("%d", &n);
	int aux = 0;
	int mn = 1e7;
	int minind;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &aux);
		if (aux >= 0) aux = -aux - 1;
		numbs[i] = aux;
		if (numbs[i] < mn ) 
		{
			mn = numbs[i];
			minind = i;
		}
	}
	if (n%2!=0 || n==1)
	{
		numbs[minind] = -numbs[minind] - 1;
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", numbs[i]);
	}
	printf("\n");
}	
