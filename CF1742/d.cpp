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

vi COP[1010];
void pre() {
	FOR(i, 1, 1001) FOR(j, 1, 1001) {
		if (__gcd(i, j) == 1) COP[i].pb(j);
	}
}

vi INDS[1010];
void solve() {
	int n; ri(n);
	vi a(n);


	FOR(i, 0, n) ri(a[i]);
	FOR(i, 0, n) INDS[a[i]].pb(i);

	int ans = -1;
	FOR(i, 0, n) {
		for (int aj : COP[a[i]]) {
			if (INDS[aj].size() > 0) ans = max(ans, i + INDS[aj].back());
		}
	}

	if (ans > -1) printf("%d\n", ans + 6 - 4);
	else printf("-1\n");
	FOR(i, 1, 1001) INDS[i].clear();
}


int main() {
	pre();
	int t; ri(t);
	while (t--) solve();
	return 0;
}