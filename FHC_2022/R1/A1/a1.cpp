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

vi pf(const vi &s, int m) {
	int n = sz(s);
	vi pi(n);
	FOR(i, 1, n) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) pi[i] = j + 1;
	}

	vi ret;
	FOR(i, 0, n) {
		if (pi[i] == m) {
			ret.pb(i - m - m);
		}
	}
	return ret;
}

ll N, K;
vi A;

void solve() {
	A.clear();
	lrii(N, K);
	vi a(N), b(N);
	for (int &ai : a) ri(ai);
	for (int &bi : b) ri(bi);

	for (int bi : b) A.pb(bi);
	A.pb(-1);
	for (int ai : a) A.pb(ai);
	for (int ai : a) A.pb(ai);
	A.pop_back();

	vi pos = pf(A, N);

	ll mn = K, mx = K * (N - 1);

	for (int p : pos) {
		ll df = max(0ll, mx - p) / N;
		ll new_p = p + df * N;
		if (mn <= new_p && new_p <= mx) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}


int main() {
	int t; ri(t);
	FOR(i, 1, t + 1) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}