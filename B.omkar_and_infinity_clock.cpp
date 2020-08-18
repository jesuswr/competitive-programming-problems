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
const int maxN = 3e5; // CAMBIAR ESTE

// GJNM
ll a[maxN];
ll n, k;

void prnt() {
	FOR(i, 0, n) {
		printf("%lld ", a[i] );
	}
	printf("\n");
}

void solve() {
	rll(n, k);
	FOR(i, 0, n) {
		rl(a[i]);
	}

	ll mx = -2000000000000ll;
	if ( k >= 2)
		k = 2 + (k & 1);
	FOR(i, 0, k) {
		mx = -1e9 - 1;
		FOR(j, 0, n) {
			mx = max(mx, a[j]);
		}
		FOR(j, 0, n) {
			a[j] = mx - a[j];
		}
	}
	prnt();

}

int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}