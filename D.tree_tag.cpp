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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
vi G[MAXN];
int dist[MAXN];

void dfs_diam(int x, int f = -1) {
	for (auto y : G[x]) {
		if (y == f)
			continue;
		dist[y] = dist[x] + 1;
		dfs_diam(y, x);
	}
}

void solve() {
	int v, a, b, da, db;
	riii(v, a, b), rii(da, db); a--, b--;
	FOR(i, 1, v) {
		int x, y;
		rii(x, y); x--, y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	FOR(i, 0, v) {
		if (G[i].size() == 1) {
			dist[i] = 0;
			dfs_diam(i);
			break;
		}
	}
	int mx = 0;
	FOR(i, 0, v) {
		mx = max(mx, dist[i]);
	}
	FOR(i, 0, v) {
		if (mx == dist[i]) {
			dist[i] = 0;
			dfs_diam(i);
			break;
		}
	}
	FOR(i, 0, v) {
		mx = max(mx, dist[i]);
	}
	dist[a] = 0;
	dfs_diam(a);
	if (db <= 2 * da)
		printf("Alice\n");
	else if (mx <= 2 * da)
		printf("Alice\n");
	else if (dist[b] <= da)
		printf("Alice\n");
	else
		printf("Bob\n");


	FOR(i, 0, v) {
		G[i].clear();
	}
}




int main() {
	int t;
	ri(t);
	while (t--)
		solve();

	return 0;
}