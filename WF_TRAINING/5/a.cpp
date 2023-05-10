#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
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

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


vi get_digits(int x) {
	vi r;
	while(x) {
		r.pb(x % 10);
		x /= 10;
	}
	reverse(all(r));
	return r;
}


int main(){
	int n; ri(n);
	vector<int> dp(n+1);
	dp[0] = INF;
	dp[1] = 1;
	FOR(i,2,n+1) {
		dp[i] = INF;
		for(int j = 1; j <= i / 2; ++j) {
			dp[i] = min(dp[i], dp[j] + dp[i-j]);
			if (i % j == 0) {
				dp[i] = min(dp[i], dp[j] + dp[i / j]);
			}
		}

		vi ds = get_digits(i);
		FOR(l,1, sz(ds)) {
			if (ds[l] == 0) continue;
			int a = 0, b = 0;
			FOR(j,0,l) a = 10 * a + ds[j];
			FOR(j,l,sz(ds)) b = 10 * b + ds[j];
			dp[i] = min(dp[i], dp[a] + dp[b]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}
