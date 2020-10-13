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
const ll MOD = 1e9 + 7;

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];
struct STN {
	ll mx, suf, pre, tot;
	void merge(STN& L, STN& R) {
		mx  = max(max(L.mx, R.mx), L.suf + R.pre);
		pre = max(L.pre, L.tot + R.pre);
		suf = max(R.suf, R.tot + L.suf);
		tot = L.tot + R.tot;
	}
	void operator=(ll a) {
		mx = suf = pre = max(a, 0ll);
		tot = a;
	}
};
STN ST[4 * MAXN];
ll lzy[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
	lzy[id] = -1e10;
	if (r - l < 2) {
		ST[id] = 0;
		return;
	}
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
// Actualiza el nodo y guarda en lazy
void upd(int id, int l, int r, ll x) {
	lzy[id] = x;
	ST[id] = (r - l) * x;
}
// Propaga el update en lazy
void shift(int id, int l, int r) {
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	upd(L, l, m, lzy[id]);
	upd(R, m, r, lzy[id]);
	lzy[id] = -1e10;
}
void STU(int x, int y, int v, int id = 1, int l = 0, int r = N) {
	if (x >= r || y <= l) return;
	if (x <= l && y >= r) {
		upd(id, l, r, v);
		return;
	}
	if (lzy[id] != -1e10)
		shift(id, l, r);
	int m = (l + r) >> 1, L = id << 1, R = L | 1;
	STU(x, y, v, L, l, m);
	STU(x, y, v, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}



int main() {
	int m;
	rii(N, m);
	STB();
	FOR(_, 0, m) {
		int l, r, v; riii(l, r, v);
		STU(l, r, v);
		printf("%lld\n", ST[1].mx);
	}
	return 0;
}