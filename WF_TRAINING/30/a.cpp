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
#define lri(a) das=scanf("%lld", &a)
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
vi G[MAXN];

int f(int u) {
	vi sons;
	for(int v : G[u]) sons.pb(f(v));

	int ans = 1;
	sort(all(sons));
	FOR(i,0,sz(sons)) {
		if (i == sz(sons) - 1) ans = max(ans, sons[i]);
		else ans = max(ans, sons[i] + 1); 
	}

	// cout << u << ' ' << ans << endl;
	return ans;
}

void solve(){
	ri(N);
	FOR(i,0,N) {
		int pi; ri(pi);
		if (pi) {
			G[pi].pb(i+1);
		}
	}
	printf("%d\n", f(1));
	FOR(i,1,N+1) G[i].clear();
}

int main() {
	int t; ri(t);
	while(t--) solve();
	return 0;
}