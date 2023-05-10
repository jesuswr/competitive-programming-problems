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
const int MOD = 998244353;
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll FACT[MAXN];
void pre() {
	FACT[0] = 1;
	FOR(i,1,MAXN) FACT[i] = (FACT[i-1] * i) % MOD;
}

ll bp(ll b, ll e) {
	ll r = 1;
	while(e) {
		if (e & 1) r = (r * b) % MOD;
		e >>= 1;
		b = (b*b) % MOD;
	}
	return r;
}

ll pickt(int n, int k) {
	ll d = (FACT[n-k] * FACT[k]) % MOD;
	d = bp(d, MOD-2);
	return (FACT[n] * d) % MOD;
}

int L,R;

int get_mx() {
	int l = L;
	int cnt = 0;
	while(l <= R) {
		cnt++;
		l = l*2;
	}
	return cnt;
}

ll get_2_3(int b, int p2, int p3) {
	ll ret = b;
	while(p2) {
		--p2;
		ret *= 2;
	}
	while(p3) {
		--p3;
		ret *= 3;
	}
	return ret;
}



void solve() {
	rii(L,R);
	ll ans = 0;
	int mx = get_mx();
	--mx;
	for(int p2 = mx; p2 >= 0; --p2) {
		int p3 = mx - p2;
		ll b = get_2_3(L, p2, p3);
		// cout << b << endl;
		if (b > R) continue;
		int lo = L, hi = R;
		while(lo < hi) {
			int mi = lo + (hi - lo + 1) / 2;
			if (get_2_3(mi, p2, p3) <= R)
				lo = mi;
			else
				hi = mi - 1;
		}
		// cout << L << " " << lo << endl;
		// cout << "    " << pickt(mx, p2) << endl;
		ans += (lo - L + 1) * pickt(mx, p2);
		ans %= MOD;
	}	
	cout << mx + 1 << " " << ans << endl;
}




int main(){
	pre();
	int t; ri(t);
	while(t--) solve();
	return 0;
}
