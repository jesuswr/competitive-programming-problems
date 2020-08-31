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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
// Todos los rangos son semi-abiertos [a,b)
// Todos los rangos son semi-abiertos [a,b)
ll N, A[MAXN];
struct STN {
	ll val;
	void merge(STN& L, STN& R) {
		val = L.val + R.val;
	}
	void operator=(ll a) {
		val = a;
	}
};
STN ST[4 * MAXN];
pair<ll, ll> lzy[4 * MAXN];
void STB(ll id = 1, ll l = 0, ll r = N) {
	if (r - l < 2) {
		ST[id] = A[l];
		return;
	}
	ll m = (l + r) >> 1, L = id << 1, R = L | 1;
	STB(L, l, m); STB(R, m, r);
	ST[id].merge(ST[L], ST[R]);
}
ll sum(ll a, ll d, ll n) {
	return a * n + d * n * (n - 1) / 2;
}
// Actualiza el nodo y guarda en lazy
void upd(ll id, ll l, ll r, pair<ll, ll> x) {
	lzy[id].F += x.F;
	lzy[id].S += x.S;
	ST[id].val += sum(x.F, x.S, r - l);
}
// Propaga el update en lazy
void shift(ll id, ll l, ll r) {
	ll m = (l + r) >> 1, L = id << 1, R = L | 1;
	upd(L, l, m, lzy[id]);
	pair<ll, ll> r_lzy = lzy[id];
	r_lzy.F = lzy[id].F + lzy[id].S * (m - l);
	upd(R, m, r, r_lzy);
	lzy[id] = {0, 0};
}
STN STQ(ll x, ll y, ll id = 1, ll l = 0, ll r = N) {
	if (x == l && y == r) return ST[id];
	shift(id, l, r);
	ll m = (l + r) >> 1, L = id << 1, R = L | 1;
	if (x >= m) return STQ(x, y, R, m, r);
	if (y <= m) return STQ(x, y, L, l, m);
	STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
	return res.merge(ln, rn), res;
}
void STU(ll x, ll y, pair<ll, ll> v, ll id = 1, ll l = 0, ll r = N) {
	if (x >= r || y <= l) return;
	if (x <= l && y >= r) {
		pair<ll, ll> aux_v = v;
		aux_v.F = v.F + (l - x) * v.S;
		upd(id, l, r, aux_v);
		return;
	}
	shift(id, l, r);
	ll m = (l + r) >> 1, L = id << 1, R = L | 1;
	STU(x, y, v, L, l, m);
	STU(x, y, v, R, m, r);
	ST[id].merge(ST[L], ST[R]);
}

int main() {
	ll m;
	rll(N, m);
	FOR(_, 0, m) {
		ll type; rl(type);
		if (type == 1) {
			ll l, r, a, d; rll(l, r); rll(a, d); l--;
			pair<ll, ll> aux = {a, d};
			STU(l, r, aux);
		}
		else {
			ll pos; rl(pos); pos--;
			printf("%lld\n", STQ(pos, pos + 1).val);
		}
	}

	return 0;
}