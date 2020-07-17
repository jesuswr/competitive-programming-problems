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
ll n, row, col, c;

ll sum(ll t) {
	ll max_l = col - 1, max_r = n - col;
	ll ans = 0;
	ans += 1 + min(t, max_l) + min(t, max_r);
	ll aux_t = t;
	for (int i = row - 1; i >= 1; i--) {
		aux_t--;
		if ( aux_t < 0 )
			break;
		ans += 1 + min(aux_t, max_l) + min(aux_t, max_r);
	}
	for (int i = row + 1; i <= n; i++) {
		t--;
		if ( t < 0 )
			break;
		ans += 1 + min(t, max_l) + min(t, max_r);
	}
	return ans;
}

int main() {
	rll(n, row), rll(col, c);

	ll lo = 0, hi = 1e6; // creo que 1e6 da xD

	while (lo < hi) {
		ll mi = lo + (hi - lo) / 2;

		if ( sum(mi) >= c )
			hi = mi;
		else
			lo = mi + 1;
	}
	printf("%lld\n", hi);
	return 0;
}