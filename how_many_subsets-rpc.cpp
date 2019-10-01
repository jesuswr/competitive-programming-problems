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

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e6+5; // CAMBIAR ESTE

// GJNM
ll arr[maxN];
int n , q;

int bs( int val )
{
	int ans = 0;
	int i = 0, j = n-1;
	while ( i <= j )
	{
		int m = ( i + j )/2;
		if ( arr[m] <= val ) 
		{
			ans = m;
			i = m + 1;
		}
		else
		{
			j = m - 1;
		}
	}
	return ans;
}



ll findans( ll max )
{
	ll ret = 0;
	int i = 0, j = bs(max);
	while ( i <= j )
	{
		if ( arr[i] + arr[j] <= max )
		{
			ret += (ll)j-i;
			i++;
		}
		else
		{
			j--;
		}
	}
	return ret;
	
}

int main()
{
	rii(n,q);
	FOR(i,0,n)
	{
		rl(arr[i]);
	}
	sort(arr,arr+n);
	ll aux;
	FOR(i,0,q)
	{
		//printf("CASO %d\n", i);
		rl(aux);
		ll ans = findans(aux);
		printf("%lld\n", ans);
	}
	return 0;
}