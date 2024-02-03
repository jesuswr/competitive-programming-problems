#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 5e5+5;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void fastIO() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
}

int n, m;
vi G[MAXN];
int low[MAXN], disc[MAXN];
bool vis[MAXN];
int t;

set <ii> bridges;
void dfs(int x, int father = -1) {
	low[x] = disc[x] = t++;
	vis[x] = true;
	int children = 0;
	for (auto y : G[x]) {
		if (!vis[y]) {
			children++;
			dfs(y, x);
			if (low[y] >= disc[x] && father != -1){
				// art
			}
			if (low[y] > disc[x]) {
				bridges.insert({x, y});
				bridges.insert({y, x});
			}
			low[x] = min(low[x], low[y]);
		}
		else if (y != father) {
			low[x] = min(low[x], disc[y]);
		}
	}
	if (father == -1 && children > 1) {
		// art
	}
}

int sz[MAXN];
int cmp[MAXN];
void assign(int v, int root, int p = -1) {
	if (cmp[v] != -1) return;
	cmp[v] = root;
	sz[root]++;
	for (auto u : G[v]) if (u != p && !bridges.count({u, v})) {
		assign(u, root, v);
	}
}

set <ii> ans;
bool vist[MAXN];
int solve(int v, int p = -1) {
	if (vist[v]) return sz[cmp[v]];
	vist[v] = true;
	int mx = sz[cmp[v]];
	vi pos;
	for (auto u : G[v]) if (u != p) {
		int x = solve(u, v);
		if (x <= 1) pos.pb(u);
		mx = max(mx, x);
	}

	if (mx > 1) for (auto u : pos) ans.insert({v, u});

	return mx;
}


int main() {
	ms(cmp, -1);

	rii(n, m);
	FOR(i,0,m) {
		int u, v; rii(u, v); u--, v--;
		G[u].pb(v);
		G[v].pb(u);
	}

	FOR(i,0,n) if (!vis[i]) dfs(i);
	FOR(i,0,n) assign(i,i);

	FOR(i,0,n) if (!vist[i] && sz[i] > 1) solve(i);

	FOR(i,0,n) if (!vist[i] && sz(G[i]) == 1) ans.insert({i, G[i][0]});

	printf("%d\n", sz(ans));
	for (auto [u, v] : ans) {
		printf("%d %d\n", u+1, v+1);
	}



	return 0;
}
