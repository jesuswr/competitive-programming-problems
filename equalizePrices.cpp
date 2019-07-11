#include <iostream>

using namespace std;

int price[101];
int minPrice[101];
int maxPrice[101];
int n, k;

int main(){
	int m;
	scanf("%d",&m);
	int minimun;
	int maximun;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &n, &k);
		maximun=1000000000;
		minimun=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&price[i]);
			minPrice[i] = max(1,price[i]-k);
			maxPrice[i] = price[i] + k;
			minimun = max(minPrice[i],minimun);
			maximun = min(maxPrice[i],maximun);
		}
		if (minimun>maximun)
		{
			printf("-1\n");
		}
		else{
			printf("%d\n", maximun);
		}
	}

}