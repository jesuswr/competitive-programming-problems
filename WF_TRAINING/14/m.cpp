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
const int MAXN = 3e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
vii G[MAXN];

pair<ll, int> DP[MAXN][2];
bool V[MAXN][2];
pair<ll, int> f(int u, int e, int ft, ll x) {
	auto &ret = DP[u][e];
	if (V[u][e]) return ret;
	V[u][e] = 1;
	ret = {0,0};
	vector< pair<ll, int> > VALS[2];
	for(auto [v, c] : G[u]) if (v != ft) {
		VALS[0].pb( f(v, 0, u, x) );
		ret.F += VALS[0].back().F;
		ret.S += VALS[0].back().S;

		auto aux = f(v, 1, u, x) ;
		aux.F += c + x;
		aux.S += 1;
		VALS[1].pb( aux );
	}

	if (e == 0) {
		auto tmp = ret;
		FOR(i,0,sz(VALS[0])) {
			auto aux = ret;
			aux.F += VALS[1][i].F - VALS[0][i].F;
			aux.S += VALS[1][i].S - VALS[0][i].S;
			tmp = max(tmp, aux);
		}
		ret = max(tmp, ret);
	}
	return ret;
}


pair<ll,int> go(ll x) {
	FOR(i,0,N) V[i][0] = V[i][1] = 0;
	return f(0, 0, -1, x);
}



int main(){
	rii(N,K);
	FOR(i,1,N) {
		int a,b,c; rii(a,b), ri(c);
		--a, --b;
		G[a].pb({b,c});
		G[b].pb({a,c});
	}
	ll lo = -1e13, hi = 1e13;
	while(lo < hi) {
		ll mi = lo + (hi - lo) / 2;
		// cout << lo << " " << hi << endl;
		if (go(mi).S >= K ) hi = mi;
		else lo = mi + 1;
	}
	if (go(hi).S < K) {
		cout << "Impossible" << endl;
		return 0;
	}

	cout << go(hi).F - K * hi << endl;


	return 0;
}
