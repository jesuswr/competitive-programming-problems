#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
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
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve() {
	int q; ri(q);
	int l = 1, r = 1e9;
	vi bad;

	while(q--) {
		int t, x; rii(t,x);
		if (t == 1) {
			l = max(l, x);
		}
		else if (t == 2) {
			r = min(r, x);
		}
		else {
			bad.pb(x);
		}
	}

	int ans = r - l + 1;
	ans = max(ans, 0);
	for(int x : bad) if (x >= l && x <= r) ans--;
	cout << ans << endl;
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
