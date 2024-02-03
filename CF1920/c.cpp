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

int N;
int A[MAXN];

vi get_divs(int x) {
	vi ret;
	for(int d = 1; d * d <= x; d++) {
		if (x % d == 0) {
			ret.pb(d);
			if (d != x / d) ret.pb(x / d);
		}
	}
	return ret;
}

bool go(int d) {
	if (d == 1) return true;
	vi dffs;

	for(int s = 0; s < N / d; s++) {
		vi vec;
		for(int i = s; i < N; i += N / d) vec.pb(A[i]);
	
		// for(int x : vec) cout << x << ' ';
		// cout << endl;
	
		sort(all(vec));
		vec.resize(distance(vec.begin(), unique(all(vec))));

		if (sz(vec) == 1) {
			dffs.pb(0);
			continue;
		}

		int diff = vec[1] - vec[0];
		FOR(i,1,sz(vec)-1) diff = __gcd(diff, vec[i+1] - vec[i]);
		dffs.pb(diff);
	}

	if (sz(dffs) == 0) return false;
	int gcd = dffs[0];
	FOR(i,1,sz(dffs)) gcd = __gcd(gcd, dffs[i]);
	return gcd != 1;
}

void solve() {
	ri(N);
	FOR(i,0,N) ri(A[i]);
	vi divs = get_divs(N);

	int ans = 0;
	for(int d : divs) ans += go(d);
	cout << ans << endl;
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
