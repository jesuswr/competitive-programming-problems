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
map<int,int> mp;
vector<pair<ll,ll>> arr;
ll dp[maxN+5];
int n;
ll ans;

ll getMax( int ind )
{
	if ( ind == 0 ) return arr[ind].first*arr[ind].second;
	if ( ind == -1 ) return 0;

	if ( dp[ind] != -1 ) return dp[ind];

	if ( arr[ind-1].first + 1 == arr[ind].first )
	{
		dp[ind] = max( getMax( ind - 2 ) + arr[ind].first*arr[ind].second , getMax(ind - 1) );
		//printf("con indice %d dio %lld y %lld\n",ind, getMax( ind - 2 ) + arr[ind].first*arr[ind].second,  getMax(ind - 1));
	}
	else
	{
		
		dp[ind] = getMax( ind - 1 ) + arr[ind].first*arr[ind].second;
	}
	return dp[ind];

}


int main()
{
	ri(n);
	int aux;
	for (int i = 0; i < n; ++i)
	{
		ri(aux);
		if ( mp.find(aux) == mp.end() ) mp[aux] = 0;
		mp[aux]++;
	}
	for ( auto p : mp ) arr.push_back( {p.first,p.second} );
	
	for ( int i = 0 ; i <= arr.size() ; i++ ) dp[i] = -1;

	ans = getMax( arr.size() - 1 );

	printf("%lld\n", ans);

	return 0;
}