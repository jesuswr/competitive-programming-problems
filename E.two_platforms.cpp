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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
const int MAXK = 30;

// GJNM
ll n, k;
ll x[MAXN], y[MAXN];
ll max_r[MAXN];
ll max_cov[MAXN];


// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
	ll mx;
	void merge(STN& L, STN& R) {
		mx = max(L.mx, R.mx);
	}
	void operator=(ll a) {
		mx = a;
	}
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = max_cov[l];
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N) {
	if (x == l && y == r) return ST[id];
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m) return STQ(x, y, R, m, r);
	if (y <= m) return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
}

void solve() {
	rll(n, k);
	FOR(i, 0, n) {
		rl(x[i]);
	}
	sort(x, x + n);
	FOR(i, 0, n) {
		rl(y[i]);
	}

	FOR(i, 0, n) {
		ll lo = i, hi = n - 1;
		while (lo < hi) {
			ll mid = lo + (hi - lo + 1) / 2;
			if ( x[mid] - x[i] <= k )
				lo = mid;
			else
				hi = mid - 1;
		}
		max_r[i] = lo;
		max_cov[i] = lo + 1 - i;
	}

	N = n;
	STB();

	ll ans = 0;
	FOR(i, 0, n) {
		ans = max(ans, max_cov[i]);
		if ( max_r[i] + 1 < n ) {
			ans = max(ans, max_cov[i] + STQ(max_r[i] + 1, n).mx);
		}
	}

	printf("%lld\n", ans);
}


int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}