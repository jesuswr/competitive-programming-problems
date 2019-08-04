#include <iostream>
#include <string>
#include <map>


using namespace std;

char ans[1003][1003];
int vals[1003];
int count[30];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", &ans[i][0]);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &vals[i]);
	}
	long long ret = 0;
	int mx = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int ii = 0; ii < 30; ++ii)
		{
			count[ii ]=0;
		}
		mx = 0;
		for (int j = 0; j < n; ++j)
		{
			count[ (int)ans[j][i] - 'A' ] ++;
			mx = max(mx,count[ (int)ans[j][i] - 'A' ] );
		}
		ret = ret + mx*vals[i];
	}
	
	printf("%lld\n", ret);
}
