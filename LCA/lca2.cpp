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
const int MAXN = 1e4; // CAMBIAR ESTE

// GJNM
vi G[MAXN];
int n, q, root;
bool can_be_root[MAXN];
int l;
int timer;
int tin[MAXN], tout[MAXN];
int up[MAXN][25];

void dfs(int v, int p) {
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (int u : G[v]) {
		if (u != p)
			dfs(u, v);
	}

	tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(int root) {
	timer = 0;
	l = ceil(log2(n));
	dfs(root, root);
}

void solve() {
	ri(n);
	FOR(i, 0, n) {
		can_be_root[i] = true;
		G[i].clear();
	}
	FOR(i, 0, n) {
		int m; ri(m);
		FOR(_, 0, m) {
			int v; ri(v);
			G[i].pb(v);
			can_be_root[v] = false;
		}
	}
	FOR(i, 0, n) {
		if (can_be_root[i]) {
			root = i;
			break;
		}
	}
	preprocess(root);

	ri(q);
	while (q--) {
		int u, v;
		rii(u, v);
		printf("%d\n", lca(u, v) );
	}

}

int main() {
	int t;
	t = 1;
	FOR(i, 1, t + 1) {
		solve();
	}

	return 0;
}