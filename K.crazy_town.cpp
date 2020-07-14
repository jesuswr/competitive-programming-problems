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
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main() {
	ll x1, y1, x2, y2;
	rll(x1, y1), rll(x2, y2);

	int cnt = 0;
	int q;
	ri(q);
	FOR(i, 0, q) {
		ll a, b, c;
		rll(a, b), rl(c);

		ll eval1 = a * x1 + b * y1 + c;
		ll eval2 = a * x2 + b * y2 + c;
		eval1 = ( eval1 > 0 ? 1 : -1 );
		eval2 = ( eval2 > 0 ? 1 : -1 );
		if ( eval1 * eval2 < 0 )
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}