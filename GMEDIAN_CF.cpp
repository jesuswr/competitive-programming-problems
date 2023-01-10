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
const int MAXN = 2e3+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll P[MAXN][MAXN];
void pre() {
	for(int n = 0; n < MAXN; ++n){
		for(int k = 0; k <= n; ++k){
			if (k == n || k == 0) P[n][k] = 1;
			else P[n][k] = (P[n-1][k] + P[n-1][k-1]) % MOD;
		}
	}
}

ll mult(ll a, ll b){
	return a * b % MOD;
}

void solve() {
	int N; ri(N);
	vi cnt(2*N);
	FOR(i,0,N){
		int a; ri(a);
		cnt[a-1]++;
	}

	ll ans = 0;
	for(int i = 1; i <= N; i += 2){
		ans = (ans + P[N][i]);
		if (ans >= MOD) ans -= MOD;
	}

	int lo = 0, hi = N;
	for(int i = 0; i < 2*N; ++i){
		hi -= cnt[i];
		for(int j = 2; j <= cnt[i]; ++j){
			for(int l = 0; l <= lo; ++l){
				for(int r = max(0, l - (j - 2)); r <= min(hi, l + (j - 2)); ++r ){
					if ((r + l + j) & 1) continue;
					ans = (ans + mult( mult( P[ cnt[i] ][ j ] , P[lo][l] ) , P[hi][r] ) );
					if (ans >= MOD) ans -= MOD;
				}
			}
		}
		lo += cnt[i];
	}

	cout << ans << endl;
}

int main(){
	pre();
	int t; ri(t);
	while(t--) solve();
	return 0;
}
