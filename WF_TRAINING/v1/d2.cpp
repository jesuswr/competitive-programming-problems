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
const int MOD = 998244353;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll modpow(ll b, ll e) {
	ll r = 1;
	while(e) {
		if (e & 1) r = (r * b) % MOD;
		e >>= 1;
		b = (b*b) % MOD;
	}
	return r;
}

ll FACT[MAXN], P2[MAXN], IFACT[MAXN];

void pre() {
	FACT[0] = P2[0] = 1;
	FOR(i,1,MAXN) {
		FACT[i] = (i * FACT[i-1]) % MOD;
		P2[i] = (2 * P2[i-1]) % MOD;
	}
	FOR(i,0,MAXN) IFACT[i] = modpow(FACT[i], MOD-2);
}

vi get_divs(int x) {
	vi divs;
	for(int d = 1; d * d <= x; ++d) {
		if (x % d == 0) {
			divs.pb(d);
			if (x / d != d) divs.pb(x / d);
		}
	}
	return divs;
}

int N;
ii A[MAXN];
bool MARKED[MAXN];

ll pick(ll n, ll k) {
    
	return FACT[n] / (FACT[k] * FACT[n-k]);
}

int main(){
	pre();
	cin >> N;
	FOR(i,0,N) {
		cin >> A[i].F;
		A[i].S = i+1;
		A[i].F = -A[i].F;
	}
	sort(A, A+N);
	ll goal = P2[N] - 1;
	ll ans = 0;
	int used = 0;
	FOR(i,0,N) {
		int val = -A[i].F, ind = A[i].S;
		vi divs = get_divs(ind);
		int opts = sz(divs);
		for(int d : divs) if (MARKED[d]) opts--;
		int rest = N - opts - used;
		FOR(j,1,opts+1) {
			ll add = ( pick(opts, j) * P2[rest] ) % MOD;
			goal -= add;
			goal %= MOD;
			ans = ( ans + add * val ) % MOD;
		}
		for(int d : divs) if (!MARKED[d]) {
			used++;
			MARKED[d] = 1;
		}
	}
	assert(goal % MOD == 0);
	cout << ans << endl;

	return 0;
}
