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
const int MAXN = 510+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll inv(ll v){
	if (v<=1)
		return v;
	return inv(MOD%v)*(MOD-MOD/v)%MOD;
}

ll F[MAXN], IF[MAXN];
void pre() {
	F[0] = 1;
	FOR(i,1,MAXN) F[i] = (F[i-1] * i) % MOD;
	FOR(i,0,MAXN) IF[i] = inv(F[i]);
}

int N;
vi G[MAXN];

int TOT[MAXN], SZ[MAXN];
ll dfs_pre(int u, int f = -1) {
	SZ[u] = 1;
	ll ret = 1;
	for(int v : G[u]) if (f != v) {
		TOT[u]++;
		ret = ret * dfs_pre(v, u) % MOD;
		SZ[u] += SZ[v];
	}
	ret = ret * F[TOT[u]] % MOD;
	return ret;
}

ll DP[MAXN][MAXN]; // node, k


void dfs(int u, int f = -1) {
	vector< vector< ll > > ss(TOT[u] + 1, vector<ll>(SZ[u] + 1, 0));
	ss[0][0] = 1;
	for(int v : G[u]) if (v != f) {
		for(int i = TOT[u]; i >= 1; --i) {
			for(int j = SZ[u]; j >= SZ[v]; --j) {
				ss[i][j] += ss[i - 1][j - SZ[v]];
				ss[i][j] %= MOD;
			}
		}
	}

	// cout << u << endl;
	// for(int i = 0; i <= TOT[u]; ++i) {
	// 	for(int j = 0; j <= SZ[u]; ++j) {
	// 		cout << ss[i][j] << " " ;
	// 	}
	// 	cout << endl;
	// }


	for(int v : G[u]) if (v != f) {
		for(int i = 1; i <= TOT[u]; ++i) {
			for(int j = SZ[v]; j <= SZ[u]; ++j) {
				ss[i][j] -= ss[i - 1][j - SZ[v]];
				ss[i][j] += MOD;
				ss[i][j] %= MOD;
			}
		}
		
		vector<ll> f(N+1);
		for(int i = 0; i <= TOT[u] - 1; ++i) {
			for(int j = 0; j <= SZ[u] - SZ[v]; ++j) {
				f[j+1] += ss[i][j] * (F[i] * F[TOT[u] - 1 - i] % MOD);
				f[j+1] %= MOD;
			}
		}

		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j + i <= N && j <= SZ[u] - SZ[v] + 1; ++j) {
				DP[v][i + j] += (DP[u][i] * f[j] % MOD) * IF[TOT[u]];
				DP[v][i + j] %= MOD;
			}
		}
	
		for(int i = TOT[u]; i >= 1; --i) {
			for(int j = SZ[u]; j >= SZ[v]; --j) {
				ss[i][j] += ss[i - 1][j - SZ[v]];
				ss[i][j] %= MOD;
			}
		}
	}
	for(int v : G[u]) if (v != f) dfs(v, u);
}

int main(){
	pre();
	ri(N);
	FOR(_,1,N) {
		int a,b; rii(a,b);
		--a;--b;
		G[a].pb(b);
		G[b].pb(a);
	}

	DP[0][1] = dfs_pre(0);
	dfs(0);

	FOR(i,0,N) {
		FOR(j,1,N+1) printf("%lld ", DP[i][j]);
		printf("\n");
	}
	return 0;
}
