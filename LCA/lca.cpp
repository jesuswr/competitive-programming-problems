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
int n, q, root, t;
pii ETT[MAXN];
bool can_be_root[MAXN];
int frst[MAXN];

// Todos los rangos son semi-abiertos [a,b)
int N;
struct STN {
	int val, mn;
	void merge(STN& L, STN& R) {
		if (L.mn <= R.mn) {
			val = L.val;
			mn = L.mn;
		}
		else {
			val = R.val;
			mn = R.mn;
		}
	}
	void operator=(pii a) {
		val = a.F;
		mn = a.S;
	}
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = ETT[l];
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


void dfs(int u, int d = 0) {
	frst[u] = t;
	ETT[t++] = {u, d};
	for (auto v : G[u]) {
		dfs(v, d + 1);
		ETT[t++] = {u, d};
	}
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
			int v; ri(v); v--;
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
	t = 0;
	dfs(root);
	N = t;
	STB();
	ri(q);
	while (q--) {
		int u, v;
		rii(u, v); u--, v--;
		printf("%d\n", STQ(min(frst[u], frst[v]), max(frst[u], frst[v]) + 1).val + 1);
	}

}

int main() {
	int t;
	ri(t);
	FOR(i, 1, t + 1) {
		printf("Case %d:\n", i);
		solve();
	}

	return 0;
}