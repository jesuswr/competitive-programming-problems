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
const ll MOD = 1e9 + 7;
const int MAXN = 500069;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, Q;
ll X[MAXN], Y[MAXN];
ll XSQ[MAXN], YSQ[MAXN];
ll X2[MAXN], Y2[MAXN];

void solve() {
	ri(N);
	FOR(i, 1, N + 1) {
		lrii(X[i], Y[i]);
	}
	sort(X + 1, X + N + 1);
	sort(Y + 1, Y + N + 1);
	FOR(i, 1, N + 1) {
		XSQ[i] = (X[i] * X[i] + XSQ[i - 1]) % MOD;
		YSQ[i] = (Y[i] * Y[i] + YSQ[i - 1]) % MOD;

		X2[i] = (2 * X[i] + X2[i - 1]) % MOD;
		Y2[i] = (2 * Y[i] + Y2[i - 1]) % MOD;
	}
	ri(Q);

	ll sm = 0;
	while (Q--) {
		ll x, y; lrii(x, y);
		ll ansx = (((x * x) % MOD) * N) % MOD;
		ansx = (ansx + XSQ[N] - X2[N] * x) % MOD;
		ansx = (ansx + MOD) % MOD;
		ll ansy = (((y * y) % MOD) * N) % MOD;
		ansy = (ansy + YSQ[N] - Y2[N] * y) % MOD;
		ansy = (ansy + MOD) % MOD;
		sm = (sm + ansx + ansy) % MOD;
	}
	printf("%lld\n", sm);

}



int main() {
	int t; ri(t);
	FOR(i, 1, t + 1) {
		printf("Case #%d: ", i );
		solve();
	}

	return 0;
}