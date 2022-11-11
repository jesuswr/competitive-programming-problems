#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
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

int N, Q;
int A[MAXN];
ll PS[MAXN], PX[MAXN];
vi INDS;

void pre() {
	PS[0] = PX[0] = A[0];
	FOR(i, 1, N) {
		PS[i] = A[i] + PS[i - 1];
		PX[i] = A[i] ^ PX[i - 1];
	}
	INDS.clear();
	FOR(i, 0, N) if (A[i] > 0) {
		INDS.pb(i);
	}
}
ll qs(int l, int r) {
	return PS[r] - PS[l] + A[l];
}
ll qx(int l, int r) {
	return PX[r] ^ PX[l] ^ A[l];
}
ll f(int l, int r) {
	return qs(l, r) - qx(l, r);
}

void go() {
	int L, R; rii(L, R); --L; --R;
	// printf("%d %d:\n", L + 1, R + 1);
	ll ans = 0; int l = L, r = L;
	auto itl = lower_bound(all(INDS), L), itr = upper_bound(all(INDS), R);
	if (INDS.size() == 0 || itl == INDS.end() || itr == INDS.begin()) {
		printf("%d %d\n", l + 1, l + 1);
		return;
	}

	--itr;
	int au = 31;
	for (auto _l = itl; _l != INDS.end(); _l++) {
		int aux = 31;
		for (auto _r = itr; _r >= _l; _r--) {
			int lL = *_l;
			int rr = *_r;
			ll curr = f(lL, rr);
			if (curr > ans || (curr == ans && (r - l) > (rr - lL) )) {
				ans = curr;
				l = lL;
				r = rr;
			}
			aux--;
			if (aux == 0) break;
		}
		au--;
		if (au == 0) break;
	}
	printf("%d %d\n", l + 1, r + 1);
}


void solve() {
	rii(N, Q);
	FOR(i, 0, N) ri(A[i]);
	pre();

	while (Q--) go();

}


int main() {
	int n; ri(n);
	while (n--) solve();
	return 0;
}