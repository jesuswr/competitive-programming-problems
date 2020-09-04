#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define rlll(a,b,c) rll(a,b),rl(c)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM

struct STN {
	STN *l = 0, *r = 0;
	ll val = 0ll, lazy = 0ll;
	STN(ll val) : l(0ll), r(0ll), val(val), lazy(0ll) {}
	STN(STN *l, STN *r) : l(l), r(r), val(0ll), lazy(0ll) {
		if (l) val += l->val;
		if (r) val += r->val;
	}

	STN(STN *n, ll len, ll c) {
		l = n->l;
		r = n->r;
		val = n->val + len * c;
		lazy = n->lazy + c;
	}

	STN(STN *n, STN *L, STN *R, ll len) {
		l = L;
		r = R;
		val = 0ll;
		lazy = n->lazy;
		if (l) val += l->val;
		if (r) val += r->val;
		val += lazy * len;
	}


};

ll N, A[MAXN];

STN* STB(ll l = 0ll, ll r = N) {
	if (r - l < 2) return new STN(A[l]);
	ll m = (l + r) >> 1ll;
	return new STN(STB(l, m), STB(m, r));
}
ll STQ(ll x, ll y, STN* v, ll l = 0ll, ll r = N, ll add = 0ll) {
	if (l >= r || x >= y) return 0ll;
	if (x == l && y == r) return v->val + add * (r - l);
	ll m = (l + r) >> 1;
	return STQ(x, min(y, m), v->l, l, m, add + v->lazy)
	       + STQ(max(x, m), y, v->r, m, r, add + v->lazy);
}
STN* STU(ll x, ll y, ll c, STN *v, ll l = 0ll, ll r = N) {
	if (l >= r || x >= y) return v;
	if (x == l && y == r) return new STN(v, r - l, c);
	ll m = (l + r) >> 1ll;
	STN *L = STU(x, min(y, m), c, v->l, l, m);
	STN *R = STU(max(x, m), y, c, v->r, m, r);
	return new STN(v, L, R, r - l);
}

STN *UPD[MAXN];
ll t = 0ll;


int main() {
	ll m; rll(N, m);
	FOR(i, 0, N) {
		rl(A[i]);
	}
	N = 2 * N;
	UPD[0] = STB();
	FOR(i, 0, m) {
		char c;
		char s[3];
		scanf("%s", s);
		c = s[0];
		if (c == 'C') {
			ll l, r, c; rlll(l, r, c); l--;
			t++;
			UPD[t] = STU(l, r, c, UPD[t - 1]);
		}
		else if (c == 'Q') {
			ll l, r; rll(l, r); l--;
			printf("%lld\n", STQ(l, r, UPD[t]));
		}
		else if (c == 'H') {
			ll l, r, bt; rlll(l, r, bt); l--;
			printf("%lld\n", STQ(l, r, UPD[bt]));
		}
		else {
			ll bt; rl(bt);
			t = bt;
		}
	}

	return 0;
}