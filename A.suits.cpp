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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main()
{
	int a,b,c,d,e,f;
	riii(a,b,c);
	riii(d,e,f);
	ll ans = 0;
	if ( e >= f ){
		ans += min( a , d )*e;
		a -= ans/e;
		d -= ans/e;
		ans += min( b , min( c , d ) )*f;
	}
	else{
		ans += min( b , min( c , d ) )*f;
		b -= ans/f;
		c -= ans/f;
		d -= ans/f;
		ans += min( a , d )*e;
	}
	printf("%lld\n",ans );
	return 0;
}