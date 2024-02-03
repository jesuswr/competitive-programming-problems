#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
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
const int MAXN = 1e3+5;

void fastIO() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
}

int n;
ll x[MAXN], y[MAXN], w;
int par[MAXN][2];

ll sqdist(int u, int v) {
	if (u == v) return 0;
	if (u > v) swap(u, v);
	if (u >= n) return w*w;
	if (v == n) return x[u]*x[u];
	if (v == n+1) return (w-x[u])*(w-x[u]);
	return (x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]);
}

void dfs(int v, int used, int p, ll sqD) {
	if (par[v][used] != -1) return;
	par[v][used] = p;
	FOR(u,0,n+2) if (u != v) {
		if (sqdist(u, v) <= sqD) dfs(u, used, v, sqD);
		else if (!x && sqdist(u, v) <= 4*sqD) dfs(u, 1, v, sqD);
	}
}

bool check(ll sqD) {
	ms(par, -1);
	dfs(n, 0, n, sqD);
	return par[n+1][0] != -1 || par[n+1][1] != -1;
}

ll BS() {
	ll lo = 0, hi = w*w;
	while (lo < hi) {
		ll mid = lo + (hi - lo)/2;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}

	return hi;
}


int main() {
	// freopen("", "r", stdin);
	// freopen("", "w", stdout);

	lri(w); ri(n);
	FOR(i,0,n) lrii(x[i], y[i]);

	ll ans = BS();
	check(ans);

	if (par[n+1][0] != -1) printf("0.5 0\n");
	else {
		int v = n+1;
		while (sqdist(v, par[v][1]) <= ans) v = par[v][1];

		double ansx = (x[v] + x[par[v][1]]) / 2.0;
		double ansy = (y[v] + y[par[v][1]]) / 2.0;

		printf("%lf %lf", ansx, ansy);
	}

	printf("%lld\n", ans);
	return 0;
}
