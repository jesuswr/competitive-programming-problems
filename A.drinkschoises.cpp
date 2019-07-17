#include <iostream>
#include <algorithm>


using namespace std;

int drinks[1001];	

int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	int aux;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&aux);
		drinks[aux]++;
	}
	int ans = 0;
	sort(drinks, drinks + k+1, greater<int>());
	int setN = n/2;
	if (n%2==1) setN++;
	
	for (int i = 0; i < k && setN>0; ++i)
	{
		if (drinks[i]<2) break;
		
		ans += drinks[i];
		if (drinks[i]%2==1) ans--;
		setN -= drinks[i]/2;
		drinks[i] = drinks[i]%2;
		
	}
	if (setN>0)
	{
		for (int i = 0; i < k && setN>0; ++i)
		{
			if (drinks[i]==1)
			{
				setN --;
				ans++;
			}
		}
	}
	
	printf("%d\n", ans);
}