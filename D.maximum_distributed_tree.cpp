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
const int MAXN = 1e5 + 29; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int n, m;
vi G[MAXN];
ll cnt[MAXN];
priority_queue<ll> pq_edge, pq_prime;

ll dfs(int x, int f = -1) {
	cnt[x] = 1;
	for (auto y : G[x]) {
		if ( y == f )
			continue;
		cnt[x] += dfs(y, x);
	}
	for (auto y : G[x]) {
		if ( y == f )
			continue;
		pq_edge.push(cnt[y] * (n - cnt[y]));
	}
	return cnt[x];
}

void solve() {
	ri(n);
	FOR(i, 1, n) {
		int u, v;
		rii(u, v);
		G[u].pb(v);
		G[v].pb(u);
	}

	dfs(1);

	ri(m);
	FOR(i, 0, m) {
		ll aux; rl(aux);
		pq_prime.push(aux);
	}
	while ( m < n - 1 ) {
		pq_prime.push(1);
		m++;
	}
	bool using_max = false;
	ll mx = 1;
	while ( m > n - 1 ) {
		if ( !using_max ) {
			ll p1, p2;
			p1 = pq_prime.top(); pq_prime.pop();
			p2 = pq_prime.top(); pq_prime.pop();
			mx = (mx * p1 * p2 ) % MOD;
			m--;
		}
		else {
			ll p1;
			p1 = pq_prime.top(); pq_prime.pop();
			mx = (mx * p1) % MOD;
			m--;
		}
		using_max = true;
	}
	ll ans = 0;
	FOR(i, 1, n) {
		if ( using_max ) {
			using_max = false;
			ans += (pq_edge.top() * mx) % MOD;
		}
		else {
			ans += (pq_edge.top() * pq_prime.top()) % MOD;
			pq_prime.pop();
		}
		ans = ans % MOD;
		pq_edge.pop();
	}
	printf("%lld\n", ans);






	FOR(i, 1, n + 1) {
		G[i].clear();
	}
}


int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}