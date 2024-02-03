#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
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
const ll MOD = 1e9+7;
const int MAXN = 1e6+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, H, NR;
int K[MAXN];

ll binpow(ll b, ll e) {
	ll r = 1;
	while(e) {
		if (e&1) r = (r*b) % MOD;
		e >>= 1;
		b = (b*b) % MOD;
	}
	return r;
}

ll FACT[MAXN], IFACT[MAXN];
void pre() {
	FACT[0] = 1;
	FOR(i,1,MAXN) FACT[i] = (FACT[i-1] * i) % MOD;
	FOR(i,0,MAXN) IFACT[i] = binpow(FACT[i], MOD-2);
}

ll pick(ll n, ll k) {
	ll num = FACT[n];
	ll den = IFACT[n-k] * IFACT[k] % MOD;
	return num * den % MOD;
}

ll DP[MAXN];
ll f(int p) {
	if (DP[p] != -1) return DP[p];
	if (p + 1 == H) 
		return DP[p] = FACT[K[p]] * FACT[NR] % MOD;
	else {
		ll sm = NR;
		FOR(j,p+1,H) sm += K[j];
		ll all = FACT[K[p]] * FACT[sm] % MOD;
		// cout << p << " " << all << endl;
		sm = K[p];
		FOR(j,p+1,H) {
			ll aux = f(j) * FACT[sm] % MOD;
			sm += K[j];
			sm %= MOD;
			all = (all - aux + MOD) % MOD;
		}
		return DP[p] = all;
	}
}

int main(){
	ms(DP,-1);
	pre();
	cin >> N >> H;
	NR = N;
	FOR(i,0,H) {
		cin >> K[i];
		NR -= K[i];
	}

	if (NR == 0) {
		cout << 0 << endl;
		return 0;
	} 
	if (H == 0) {
		cout << FACT[N] << endl;
		return 0;
	}

	ll ans = f(0);

	ll sm = K[0];
	FOR(i,1,H) {
		sm += K[i];
		sm %= MOD;
		// ans = (ans + pick(sm, K[i]) * f(i)) % MOD;
		ll aux = pick(sm-1, K[i]-1) * f(i) % MOD;
		// cout << "           " << pick(sm, K[i]) << endl;
		// cout << "           " << FACT[sm - K[i]] << endl;
		// cout << "           " << f(i) << endl;
		// cout << "                " << FACT[sm - K[i]] * pick(sm, K[i]) * f(i) << endl;
		aux = aux * FACT[sm - K[i]] % MOD;
		ans = (ans + aux) % MOD;
		// cout << "    " << pick(sm, K[i]) << endl;
	}
	ans = (FACT[N] - ans + MOD) % MOD;
	cout << ans << endl;

	// FOR(i,0,H) cout << i << " " << f(i) << endl;
	return 0;
}
