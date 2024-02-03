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
const int MAXN = 21;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll INV[MAXN];
ll binpow(ll b, ll e) {
	ll r = 1;
	while(e) {
		if (e&1) r = (r * b) % MOD;
		e >>= 1;
		b = (b*b) % MOD;
	}
	return r;
}

void pre() {
	FOR(i,1,MAXN) INV[i] = binpow(i,MOD-2);
}

int N;
int G[MAXN][MAXN];

bool is_on(int msk, int b) {
	return (msk >> b) & 1;
}

int DP[1 << MAXN][MAXN];
int ANS[MAXN];
int main(){
	ri(N);
	FOR(i,0,N) FOR(j,0,N) ri(G[i][j]);
	pre();

	DP[1][0] = 1;
	for(int msk = 1; msk < (1 << N); msk++) {
		for(int u = 0; u < N; ++u) if (is_on(msk, u) && DP[msk][u]) {
			int cnt = 0;
			for(int v = 0; v < N; ++v) if (G[u][v] && !is_on(msk, v)) cnt++;
			for(int v = 0; v < N; ++v) if (G[u][v] && !is_on(msk, v)) {
				int new_msk = msk | (1 << v);
				DP[new_msk][v] = (DP[new_msk][v] + 1ll * INV[cnt] * DP[msk][u]) % MOD;
			}
			if (cnt == 0) {
				ANS[u] = (ANS[u] + DP[msk][u]) % MOD;
			}
		}
	}

	FOR(i,0,N) printf("%d ", ANS[i]);
	printf("\n");


	return 0;
}
