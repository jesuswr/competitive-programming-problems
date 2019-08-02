#include <iostream>
#include <map>

using namespace std;

int moneys[200005];
int pays[200005];

map<int, pair<int,int>> mp;

int main()
{
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", moneys+i);
		mp[i] = {0,moneys[i]};
	}
	int q;
	scanf("%d",&q);
	int type, aux1, aux2;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &type);
		if (type==1)
		{
			scanf("%d %d", &aux1, &aux2);
			mp[aux1] = {i, aux2};
		}
		else
		{
			scanf("%d", &aux1);
			pays[i] = aux1;
		}
	}
	for (int i = q-2; i>=0 ; --i)
	{
		pays[i] = max( pays[i], pays[i+1] );
	}
	for (int i = 1; i <= n; ++i)
	{
		//printf("%d\n", moneys[i]);
		moneys[i] = max( mp[i].second, (pays[mp[i].first]));
		//printf("%d\n", moneys[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", moneys[i]);
	}
	printf("\n");
	
}
