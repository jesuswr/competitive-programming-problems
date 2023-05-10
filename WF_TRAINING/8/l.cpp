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
const ll MOD = 1e9+7;
const int MAXN = 1e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll binpow(ll b, int e) {
	ll r = 1;
	while(e) {
		if (e & 1) r = r * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return r;
}

ll FACT[MAXN], PR2[MAXN], INVF[MAXN];
void pre() {
	FACT[0] = PR2[0] = INVF[0] = 1;
	FOR(i,1,MAXN) {
		FACT[i] = FACT[i-1] * i % MOD;
		PR2[i] = (2 * i - 1) * PR2[i-1] % MOD;
		INVF[i] = binpow(FACT[i], MOD-2);
	}
}

ll pick(int n, int k) {
	if (k > n) return 0;
	ll num = FACT[n], den = INVF[k] * INVF[n-k] % MOD;
	return num * den % MOD;
}

void solve() {
	int n,m; rii(n,m);
	ll ans = 0;

	if (m == 0)
		printf("1\n");
	else if (n == m)
		printf("%lld\n", FACT[n-1] * INVF[2]%MOD);
	else if (n < m) 
		printf("0\n");
	else {
		FOR(i,1,n-m+1) {
			if (i > m) break;

			ll meqll = pick(n, i+m);
			meqll = meqll * PR2[i] % MOD;
			meqll = meqll * FACT[m-i] % MOD;
			meqll = meqll * pick(m-1, i-1) % MOD;
			meqll = meqll * pick(m+i, 2*i);
			ans = (ans + meqll) % MOD;
		}
		printf("%lld\n", ans);
	}

}


int main(){
	pre();
	int t; ri(t);
	while(t--) solve();
	return 0;
}
