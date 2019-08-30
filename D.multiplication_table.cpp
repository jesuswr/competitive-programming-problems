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
const ll LLINF = 1e12;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
ll n, m;

bool valid ( ll val , ll goal )
{
	ll count = 0;
	for (int i = 1; i <= n; ++i)
	{
		count += min( m , ( val - 1 ) / i );
	}
	if ( count < goal ) return true;
	return false;
}

int main()
{
	ll k;
	rll(n,m);
	rl(k);
	ll start = 1;
	ll end = LLINF;
	ll ans = LLINF;
	while(start <= end) 
	{
	    ll mid = ( start + end ) / 2;
	    if ( valid( mid , k ) )
	    {
	    	ans = mid;
	    	start = mid + 1;
	    }
	    else
	    {
	    	end = mid - 1;
	    }
	}
	printf("%lld\n",ans );
	return 0;
}