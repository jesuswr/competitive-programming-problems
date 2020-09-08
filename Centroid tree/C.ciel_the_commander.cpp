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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int v, q;
vi G[MAXN];
vi CT[MAXN];

int height[MAXN];

void dfs_h(int x, int f = -1) {
	for (auto y : G[x]) {
		if (f == y)
			continue;
		height[y] = height[x] + 1;
		dfs_h(y, x);
	}
}

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
	l = ceil(log2(v));
	dfs(root, root);
}

int get_d(int x, int y) {
	return abs(height[x] + height[y] - 2 * height[lca(x, y)]);
}

bool is_centroid[MAXN];
int sz[MAXN];
int father[MAXN];

int dfs_sz(int x, int f = -1) {
	sz[x] = 1;
	for (auto y : G[x]) {
		if (y == f || is_centroid[y])
			continue;
		sz[x] += dfs_sz(y, x);
	}
	return sz[x];
}

int dfs_cd(int x, int cent_sz, int f = -1) {
	for (auto y : G[x]) {
		if (y == f || is_centroid[y])
			continue;
		if (sz[y] > cent_sz / 2)
			return dfs_cd(y, cent_sz, x);
	}
	return x;
}


void cent_descomp(int x, int f = -1) {
	int cent_sz = dfs_sz(x);
	int centroid = dfs_cd(x, cent_sz);
	is_centroid[centroid] = true;
	father[centroid] = f;
	if (f != -1)
		CT[f].pb(centroid);
	for (auto y : G[centroid]) {
		if (is_centroid[y])
			continue;
		cent_descomp(y, centroid);
	}
}

char ans[MAXN];

void dfs_asg(int x, int h) {
	ans[x] = 'A' + h;
	for (int y : CT[x])
		dfs_asg(y, h + 1);
}


int main() {
	ri(v);
	if (v < 25) {
		FOR(i, 0, v) {
			printf("%c ", 'A' + i);
		}
		printf("\n");
		return 0;
	}
	FOR(i, 1, v) {
		int x, y; rii(x, y); x--, y--;
		G[x].pb(y);
		G[y].pb(x);
	}
	cent_descomp(0);
	FOR(i, 0, v) {
		if (father[i] == -1) {
			dfs_asg(i, 0);
		}
	}
	FOR(i, 0, v) {
		printf("%c ", ans[i]);
	}
	printf("\n");
	return 0;
}