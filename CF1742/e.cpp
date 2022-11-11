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


void solve() {
	int n, q; rii(n, q);
	vector<ll> a(n + 1), pref(n + 1), mx(n + 1);
	FOR(i, 1, n + 1) {
		lri(a[i]);
		pref[i] = mx[i] = a[i];
	}
	FOR(i, 1, n + 1) {
		pref[i] += pref[i - 1];
		mx[i] = max(mx[i], mx[i - 1]);
	}

	while (q--) {
		int ki; ri(ki);
		int lo = 0, hi = n;
		while (lo < hi) {
			int mi = lo + (hi - lo + 1) / 2;
			if (mx[mi] <= ki) lo = mi;
			else hi = mi - 1;
		}
		printf("%lld ", pref[lo]);
	}
	printf("\n");
}


int main() {
	int t; ri(t);
	while (t--) solve();

	return 0;
}