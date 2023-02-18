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

int N, K, M;
vii G[MAXN];


int DP[82][82][82][2];
int f(int l, int r, int k, int s = 0) {
	int &ret = DP[l][r][k][s];
	if (ret != -1) return ret;
	if (k == 0) return ret = 0;
	
	ret = INF;
	if (s == 0) {
		for(auto [v, c] : G[l]) {
			if (v > l && v <= r) {
				ret = min({
					ret,
					c + f(l + 1, v, k-1, 1),
					c + f(v, r, k-1, 0)
				});
			}
		}
	}
	else {
		for(auto [v, c] : G[r]) {
			if (v >= l && v < r) {
				ret = min({
					ret,
					c + f(l, v, k-1, 1),
					c + f(v, r-1, k-1, 0)
				});
			}
		}
	}
	// FOR(i,0,K - k) printf("  ");
	// printf("%d %d %d %d \t:\t %d\n", l, r, k, s, ret);
	return ret;
}


int main(){
	FOR(i,0,82) FOR(j,0,82) FOR(k,0,82) FOR(l,0,2)
	 DP[i][j][k][l] = -1;
	rii(N,K);
	ri(M);
	FOR(i,0,M) {
		int u, v, c;
		rii(u,v), ri(c);
		if (u == v) continue;
		G[u].pb({v,c});
	}
	FOR(i,0,N) G[0].pb({i+1, 0});
	int ans = f(0, N, K, 0);
	if (ans >= INF) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}
