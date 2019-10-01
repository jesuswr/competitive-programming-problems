#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 100; // CAMBIAR ESTE

int arr[maxN];
unordered_map<int,long long> mp1;


int main()
{
	int n;
	ri(n);
	if (n==0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		ri(arr[i]);
	}

	
	int aux;
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			for (int j = 0; j < n; ++j)
			{
				aux = arr[i]*arr[k] + arr[j];
				if ( mp1.find(aux) != mp1.end() )
				{
					mp1[aux]++;
				}
				else
				{
					mp1[aux] = 1;
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			for (int j = 0; j < n; ++j)
			{
				if ( arr[j] == 0) continue;
				aux = ( arr[i] + arr[k] ) * arr[j];
				if ( mp1.find(aux) != mp1.end()) ans += mp1[aux];
			}
		}
	}
	
	
	printf("%lld\n", ans);
}