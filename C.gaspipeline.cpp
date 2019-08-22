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
int arr[2*maxN + 10];
vii vec;

int main()
{
	int t, n, costoTubo, costoPilar;
	ri(t)
	int aux;
	while ( t-- )
	{
		riii(n, costoTubo, costoPilar);
		arr[0] = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%1d", &aux);
			arr[i] = max(arr[i],aux);
			arr[i+1] = aux;
		}
		int last = 0, sum = 0;
		for (int i = 0; i <= n; ++i)
		{
			if (arr[i]==last) sum++;
			else
			{
				vec.push_back({last,sum});
				last = arr[i];
				sum = 1;
			}
		}
		vec.push_back({last,sum});
		long long ans = (long long)vec[0].second*((long long)costoPilar + costoTubo)-(long long)costoTubo;
		int currenth = 0;
		for (int i = 1; i < vec.size() - 1; ++i)
		{

			if (vec[i].first)
			{
				ans += (long long)vec[i].second*((long long)2*costoPilar + costoTubo);
				if (currenth == 0)
				{
					currenth = 1;
					ans += (long long)costoTubo;
				}
			}

			else
			{
				if ( (long long) vec[i].second*((long long)2*costoPilar + costoTubo) > (long long) vec[i].second*((long long)costoPilar + costoTubo) + (long long)2*costoTubo)
				{
					ans += (long long)vec[i].second*((long long)costoPilar + costoTubo) + (long long)2*costoTubo;
				}
				else
				{
					ans += (long long)vec[i].second*((long long)2*costoPilar + (long long)costoTubo);
				}
			}
		}
		if ( currenth ) ans += (long long)costoTubo;
		if (vec.size()>1)
		{

			ans += (long long)vec[vec.size()-1].second*((long long)costoTubo + (long long)costoPilar);
		}
		vec.clear();
		printf("%lld\n", ans);
	}
	return 0;
}