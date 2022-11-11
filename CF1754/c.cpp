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
	int n; ri(n);
	vi a(n);
	FOR(i, 0, n) ri(a[i]);

	vi inds;
	FOR(i, 0, n) if (a[i]) {
		inds.pb(i);
	}


	if (sz(inds) & 1) {
		printf("-1\n");
		return;
	}

	vii segs;
	int lst = -1;
	FOR(i, 0, sz(inds) >> 1) {
		int l = inds[2 * i], r = inds[2 * i + 1];
		if (l != lst + 1) {
			segs.pb({lst + 1, l - 1});
		}
		lst = r;

		if (l + 1 == r) {
			if (a[l] == a[r]) {
				segs.pb({l, r});
			}
			else {
				segs.pb({l, l});
				segs.pb({r, r});
			}
		}
		else {
			if (a[l] == a[r]) {
				segs.pb({l, r - 2});
				segs.pb({r - 1, r});
			}
			else {
				segs.pb({l, r - 1});
				segs.pb({r, r});
			}
		}

	}
	if (lst != n - 1) {
		segs.pb({lst + 1, n - 1});
	}

	printf("%d\n", sz(segs));
	for (auto [a, b] : segs) {
		printf("%d %d\n", a + 1, b + 1);
	}

}


int main() {
	int t; ri(t);
	while (t--) solve();

	return 0;
}