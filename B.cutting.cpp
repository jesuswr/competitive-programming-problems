#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

int abs(int i)
{
	if (i<0) return -i;
	return i;
}

int numbs[101];
vector<int> cuts;

int main()
{
	int n, b;
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numbs[i]);
	}
	int pares=0, impares=0;
	for (int i = 0; i < n-1; ++i)
	{
		if (numbs[i]%2==0) pares++;
		else impares++;
		if (pares == impares)
		{
			cuts.push_back(abs(numbs[i+1]-numbs[i]) );
		}
	}
	sort(cuts.begin(), cuts.end());
	
	int cost = 0;
	int cont = 0;
	for (int i = 0; i < cuts.size(); ++i)
	{
		if (cost+cuts[i]>b) break;
		cost += cuts[i];
		cont++;
	}
	printf("%d\n", cont);


}
