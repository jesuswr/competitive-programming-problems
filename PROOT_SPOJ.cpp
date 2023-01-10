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
#define ri(a) dasdas = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas = scanf("%lld", &a)
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

ll P,N;

ll binpow(ll b, ll e){
	ll r = 1;
	while(e){
		if (e & 1) r = (r * b) % P;
		b = (b * b) % P;
		e >>= 1;
	}
	return r;
}

void solve(){
	while(N--){
		ll r; lri(r);
		bool g = true;
		for(ll i = 2; i*i < P; ++i){
			if ( (P-1) % i == 0 ) {

				ll d = i;
				while( d < P-1 && (P-1) % d == 0){
					if (r == binpow(r, d+1)){
						g = false;
					}
					d = d*i;
				}

				if (r == binpow(r, (P-1) / i + 1)){
					g = false;
				}

				if (!g) break;

			}

		}
		if (g) printf("YES\n");
		else printf("NO\n");
	}
}

int main(){
	while(lrii(P,N), P != 0 || N != 0) solve();
	return 0;
}
