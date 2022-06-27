#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

map<int, vi> INDS;
int N, A[MAXN], B[MAXN];
struct STN {
	int pre, suf, bst, tot;
	void merge(STN& L, STN& R) {
		pre = max(L.pre, R.pre + L.tot);
		suf = max(R.suf, R.tot + L.suf);
		tot = L.tot + R.tot;
		bst = max({L.bst, R.bst, L.suf + R.pre});
	}
	void operator=(int a) {
		pre = suf = bst = max(a, 0);
		tot = a;
	}
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = A[l];
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
void STU(int p, int x, int id = 1, int l = 0, int r = N) {
	if (r - l < 2) {
		ST[id] = x;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (p < m) STU(p, x, L, l, m);
	else STU(p, x, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}

void solve() {
	ri(N);
	FOR(i, 0, N) ri(B[i]);
	FOR(i, 0, N) A[i] = -1;
	FOR(i, 0, N) INDS[B[i]].pb(i);
	STB();


	int mx = -1, mxa;
	for (auto &[val, vec] : INDS) {
		for (int i : vec) STU(i, 1);

		if (mx < STQ(0, N).bst) {
			mx = STQ(0, N).bst;
			mxa = val;
		}

		for (int i : vec) STU(i, -1);
	}

	for (int i : INDS[mxa]) STU(i, 1);
	int l = 0, r = N - 1;

	while (l != r) {
		if (STQ(l + 1, r + 1).bst == mx) ++l;
		else if (STQ(l, r).bst == mx) --r;
		else break;
	}

	printf("%d %d %d\n", mxa, l + 1, r + 1);

	INDS.clear();
}


int main() {
	int t; ri(t);
	while (t--) {
		solve();
	}
	return 0;
}