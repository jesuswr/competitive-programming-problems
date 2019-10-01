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
const ll LLINF = 1e11;
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
ll arr[maxN];
ll n , c , t;

ll roof( ll x , ll y)
{
	ll ans = x/y;
	if (x%y!=0)ans++;
	return ans;
}

bool valid ( ll x )
{
	ll current= 0;
	ll m = 1;
	ll i = 0;
	while ( i < n && m <= c)
	{
		current = 0;
		//printf("con %lld agrego: ", m);
		while ( roof(current+arr[i], t) <= x && i < n)
		{
			current += arr[i];
			//printf("%lld ",arr[i] );
			i++;
		}
		//printf("\n");
		if ( i == n ) return true;
		m++;
	}
	return false;
}

int main()
{
	rll(n,c);rl(t);
	FOR(i,0,n)
	{
		rl(arr[i]);
	}
	ll s = 1;
	ll e = LLINF;
	ll ans = 0;
	while ( s <= e )
	{
		ll m = ( s + e ) / 2;
		//printf("%lld\n", m);
		if (valid(m))
		{
			//printf("true\n");
			ans = m;
			e = m - 1;
		}
		else
		{
			//printf("false\n");
			s = m + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}