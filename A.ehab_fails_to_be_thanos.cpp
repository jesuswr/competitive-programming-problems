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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
unordered_map<int,int> mp;
int arr[2001];

int main()
{
	int n;
	ri(n);
	ll sum1 = 0;
	for (int i = 0; i < n; ++i)
	{
		ri(arr[i]);
		sum1 += arr[i];
	}
	ll sum2 = 0;
	for (int i = 0; i < n; ++i)
	{
		ri(arr[n+i]);
		sum2 += arr[n+i];
	}
	if ( sum1 != sum2 )
	{
		for (int i = 0; i < 2*n; ++i)
		{
			printf("%d ", arr[i]);
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if ( mp.find(arr[i]) != mp.end()) continue;
			mp[arr[i]] = 1;
			for (int j = 0; j < n; ++j)
			{
				if ( arr[i] != arr[n+j] )
				{
					int aux = arr[i];
					arr[i] = arr[n+j];
					arr[n+j] = aux;
					for (int k = 0; k < 2*n; ++k)
					{
						printf("%d ", arr[k]);
					}
					printf("\n");
					return 0;
				}
			}
		}
		printf("-1\n");
	}
	return 0;
}