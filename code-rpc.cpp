#include <iostream>

using namespace std;

int days[370];
int diff[370];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &days[i]);
	}
	if (n==1)
	{
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < n-1; ++i)
	{
		diff[i] = days[i+1] - days[i];
	}
	int aux = 0;
	int cont2 = 1;
	int cont = 0;
	for (int i = 0; i < n-1; ++i)
	{
		//cout<<  aux  + cont2*diff[i] << endl;
		if (aux + cont2*diff[i] >= 20) 
		{
			aux = 0;
			cont += 1;
			cont2 = 1;
		}
		else
		{
			aux += cont2*diff[i];
			cont2++;
		}
	}
	cont++;
	printf("%d\n", cont);
}
